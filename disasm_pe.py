#!/usr/bin/env python3
"""PE ARM64 disassembler and comparison tool using veda64_py binding."""

import argparse
import hashlib
import pickle
import re
import struct
import sys
from pathlib import Path

IMAGE_SCN_MEM_EXECUTE = 0x20000000
MACHINE_ARM64 = 0xAA64

# ── veda64_py binding ─────────────────────────────────────────────────────────

_veda64_py = None

def _try_load_binding() -> bool:
    """Attempt to import veda64_py from the default build directory."""
    global _veda64_py
    if _veda64_py is not None:
        return True
    candidates = [
        Path(__file__).parent / '__build_arm64' / 'Release',
        Path(__file__).parent,
    ]
    for d in candidates:
        if d not in sys.path:
            sys.path.insert(0, str(d))
    try:
        import veda64_py
        _veda64_py = veda64_py
        return True
    except ImportError:
        return False

_try_load_binding()

# ── Opcode cache ──────────────────────────────────────────────────────────────
# Maps uint32 opcode → disassembly string.  Keyed by binary hash so the cache
# is automatically invalidated when the binary changes.

_cache: dict = {}          # in-memory: opcode(int) → text(str)
_cache_path: Path | None = None
_cache_dirty = False


def _cache_key_for(path: Path) -> str:
    """Return a short hex digest of a binary for cache namespacing."""
    try:
        data = path.read_bytes()
        return hashlib.md5(data).hexdigest()[:12]
    except OSError:
        return 'unknown'


def _binding_path() -> Path | None:
    """Return path to the loaded .pyd, or None."""
    if _veda64_py is None:
        return None
    try:
        return Path(_veda64_py.__file__)
    except AttributeError:
        return None


def load_cache() -> None:
    """Load the opcode→text cache from disk."""
    global _cache, _cache_path, _cache_dirty
    key_path = _binding_path()
    if key_path is None:
        return
    key = _cache_key_for(key_path)
    cache_dir = key_path.parent
    _cache_path = cache_dir / f'.veda64_cache_{key}.pkl'
    if _cache_path.is_file():
        try:
            with open(_cache_path, 'rb') as f:
                _cache = pickle.load(f)
        except Exception:
            _cache = {}
    _cache_dirty = False


def save_cache() -> None:
    """Persist the in-memory cache to disk if it changed."""
    global _cache_dirty
    if _cache_dirty and _cache_path is not None:
        try:
            with open(_cache_path, 'wb') as f:
                pickle.dump(_cache, f, protocol=pickle.HIGHEST_PROTOCOL)
            _cache_dirty = False
        except Exception:
            pass


def parse_pe(data):
    """Parse PE headers, return (sections, image_base). Raises on invalid PE or non-ARM64."""
    if len(data) < 64 or data[:2] != b'MZ':
        raise ValueError("Not a valid PE file (bad MZ signature)")

    e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
    if len(data) < e_lfanew + 4 or data[e_lfanew:e_lfanew + 4] != b'PE\0\0':
        raise ValueError("Not a valid PE file (bad PE signature)")

    coff_offset = e_lfanew + 4
    machine, num_sections, _, _, _, size_of_optional = struct.unpack_from(
        '<HHIIIH', data, coff_offset
    )

    if machine != MACHINE_ARM64:
        raise ValueError(f"Not an ARM64 PE (Machine=0x{machine:04X}, expected 0x{MACHINE_ARM64:04X})")

    opt_offset = coff_offset + 20
    opt_magic = struct.unpack_from('<H', data, opt_offset)[0]
    if opt_magic == 0x20B:  # PE32+
        image_base = struct.unpack_from('<Q', data, opt_offset + 24)[0]
    else:
        image_base = 0

    section_table_offset = opt_offset + size_of_optional
    sections = []
    for i in range(num_sections):
        off = section_table_offset + i * 40
        name_raw = data[off:off + 8]
        name = name_raw.split(b'\0', 1)[0].decode('ascii', errors='replace')
        virtual_size, virtual_addr, raw_size, raw_ptr = struct.unpack_from(
            '<IIII', data, off + 8
        )
        characteristics = struct.unpack_from('<I', data, off + 36)[0]
        sections.append({
            'name': name,
            'virtual_size': virtual_size,
            'virtual_address': virtual_addr,
            'raw_size': raw_size,
            'raw_ptr': raw_ptr,
            'characteristics': characteristics,
        })

    return sections, image_base


def veda64_disasm_all(words):
    """Disassemble all words using cache + binding.
    Returns list of strings in the same order as input."""
    global _cache_dirty
    if not words:
        return []

    # Collect cache misses (deduplicated)
    unique_miss = list(dict.fromkeys(w for w in words if w not in _cache))

    if unique_miss:
        for opcode in unique_miss:
            result = _veda64_py.decode(opcode)
            _cache[opcode] = result.to_string() if result is not None else '<unknown>'
        _cache_dirty = True

    return [_cache[w] for w in words]


def disassemble_section(data, section, image_base):
    """Disassemble an executable section."""
    raw = data[section['raw_ptr']:section['raw_ptr'] + section['raw_size']]
    num_insns = len(raw) // 4
    base_va = image_base + section['virtual_address']

    print(f"\n=== {section['name']} (RVA: 0x{section['virtual_address']:08X}, "
          f"Size: 0x{section['raw_size']:X}, {num_insns} instructions) ===")

    words = list(struct.unpack_from(f'<{num_insns}I', raw))

    disasm_lines = veda64_disasm_all(words)

    for idx, text in enumerate(disasm_lines):
        va = base_va + idx * 4
        print(f"0x{va:016X}: {words[idx]:08x}    {text}")


# ── Normalization for comparison ──────────────────────────────────────────────

# ARM condition code synonyms (both forms are architecturally valid)
_COND_ALIASES = {'cc': 'lo', 'cs': 'hs'}

# Pattern for veda64 relative branch targets: .+0xOFFSET or .-0xOFFSET
_REL_TARGET = re.compile(r'\.\s*([+-])\s*0x([0-9a-fA-F]+)')

# ADRP-specific: match "adrp xN, .+0xOFFSET" or "adrp xN, .-0xOFFSET"
_ADRP_REL = re.compile(r'(adrp\s+(?:x\d+|xzr),\s*)\.\s*([+-])\s*0x([0-9a-fA-F]+)')


def _normalize_immediates(s):
    """Convert all numeric literals to a canonical decimal form for comparison."""
    def _to_dec(m):
        prefix = m.group(1) or ''
        return prefix + str(int(m.group(2), 16))
    # 0xHEX -> decimal (but not when it's a standalone address like "0x140001000")
    s = re.sub(r'(#?)0x([0-9a-fA-F]+)', _to_dec, s)
    return s


def normalize(text, va=None):
    """Normalize disassembly text for comparison.

    Applies transformations to reduce cosmetic differences between veda64 and
    capstone output so that only semantically meaningful mismatches are reported.
    """
    s = text.lower().strip()
    # x29 <-> fp, x30 <-> lr (word boundary to avoid mangling 'adrp', 'clr', etc.)
    s = re.sub(r'\bfp\b', 'x29', s)
    s = re.sub(r'\blr\b', 'x30', s)
    # Remove '#' before immediates
    s = s.replace('#', '')
    # Condition code synonyms: cc->lo, cs->hs
    for old, new in _COND_ALIASES.items():
        s = re.sub(r'(?<=\.)' + old + r'\b', new, s)
        s = re.sub(r'(?<=, )' + old + r'$', new, s)
    # ADRP: page-aligned relative target → absolute
    if va is not None:
        def _adrp_to_abs(m):
            prefix = m.group(1)
            sign = m.group(2)
            offset = int(m.group(3), 16)
            if sign == '-':
                offset = -offset
            addr = ((va & ~0xFFF) + offset) & 0xffffffffffffffff
            return f'{prefix}0x{addr:x}'
        s = _ADRP_REL.sub(_adrp_to_abs, s)
    # Convert remaining relative branch targets to absolute
    if va is not None:
        def _rel_to_abs(m):
            sign = m.group(1)
            offset = int(m.group(2), 16)
            if sign == '-':
                offset = -offset
            return f'0x{(va + offset) & 0xffffffffffffffff:x}'
        s = _REL_TARGET.sub(_rel_to_abs, s)
    # tbz/tbnz: capstone uses w-reg for bit < 32, veda64 uses x-reg
    s = re.sub(r'\btbz w(\d+)', r'tbz x\1', s)
    s = re.sub(r'\btbnz w(\d+)', r'tbnz x\1', s)
    # MOVA → MOV alias (SME tile move, capstone uses MOV preferred form)
    s = re.sub(r'\bmova\b', 'mov', s)
    # SSHR shift-by-zero → MOVI aliasing (encoding collision)
    # When shift amount is 0 in SSHR, it overlaps with MOVI encoding
    s = re.sub(r'\bsshr (v\d+(?:\.\d+[bhsdq])?), (v\d+(?:\.\d+[bhsdq])?), 0\b', r'movi \1, 0', s)
    # UMOV → MOV alias (preferred form for both 32-bit .s and 64-bit .d UMOV)
    s = re.sub(r'\bumov\s+((?:w|x)\d+)', r'mov \1', s)
    # ORN with implicit WZR/XZR → MVN: orn wN, wM / orn xN, xM → mvn wN, wM / mvn xN, xM
    # veda64 omits the WZR/XZR first source, printing 2 operands instead of 3
    s = re.sub(r'\born\s+((?:w|x)\d+),\s*((?:w|x)\d+)\b', r'mvn \1, \2', s)
    # ISB: "isb sy" → "isb" (SY is default barrier, capstone omits it)
    s = re.sub(r'\bisb\s+sy\b', 'isb', s)
    # MOVI 64-bit zero: "0000000000000000" → "0"
    s = s.replace('0000000000000000', '0')
    # Normalize floating-point immediates: remove trailing zeros after decimal
    # "#-1.00000000" → "#-1.0", "#0.50000000" → "#0.5"
    def _norm_float(m):
        prefix = m.group(1)
        intpart = m.group(2)
        fracpart = m.group(3).rstrip('0') or '0'
        return f'{prefix}{intpart}.{fracpart}'
    s = re.sub(r'(#-?)(\d+)\.(\d+)', _norm_float, s)
    # Normalize all hex immediates to decimal for consistent comparison
    s = _normalize_immediates(s)
    # Normalize signed vs unsigned 32-bit immediates for MOV:
    # capstone: "mov w8, -1073741823" vs veda64: "mov w8, 3221225473"
    # Both represent the same 32-bit value, normalize to unsigned
    def _normalize_mov_imm(m):
        mnem = m.group(1)
        reg = m.group(2)
        val = int(m.group(3))
        if val < 0:
            # Convert negative to unsigned 32-bit or 64-bit
            if 'w' in reg:
                val = val & 0xFFFFFFFF
            else:
                val = val & 0xFFFFFFFFFFFFFFFF
        return f'{mnem} {reg}, {val}'
    s = re.sub(r'(mov)\s+((?:w|x)\d+),\s*(-?\d+)', _normalize_mov_imm, s)
    # MVN immediate → MOV negative: mvn xN, imm → mov xN, -(imm+1)
    # (must run after hex→dec normalization)
    def _mvn_to_mov(m):
        reg = m.group(1)
        imm = int(m.group(2))
        neg_val = -(imm + 1)
        return f'mov {reg}, {neg_val}'
    s = re.sub(r'\bmvn\s+((?:w|x)\d+),\s*(\d+)\b', _mvn_to_mov, s)
    # Normalize MVN→MOV result: apply same unsigned normalization
    s = re.sub(r'(mov)\s+((?:w|x)\d+),\s*(-?\d+)', _normalize_mov_imm, s)
    # UBFM → UBFIZ alias: when imms < immr, UBFM is UBFIZ
    def _ubfm_to_ubfiz(m):
        rd = m.group(1)
        rn = m.group(2)
        immr = int(m.group(3))
        imms = int(m.group(4))
        n = 64 if 'x' in rd else 32
        if imms < immr:
            lsb = n - immr
            width = imms + 1
            return f'ubfiz {rd}, {rn}, {lsb}, {width}'
        return m.group(0)
    s = re.sub(r'\bubfm\s+((?:w|x)\d+),\s*((?:w|x)\d+),\s*(\d+),\s*(\d+)', _ubfm_to_ubfiz, s)
    # BFI with XZR/WZR source → BFC (also handles veda64 bug: Rn=31 as bare number)
    s = re.sub(r'\bbfi\s+((?:w|x)\d+),\s*(?:(?:w|x)zr|\d+),\s*', r'bfc \1, ', s)
    # SBFM → SBFIZ alias: when imms < immr, SBFM is SBFIZ
    def _sbfm_to_sbfiz(m):
        rd = m.group(1)
        rn = m.group(2)
        immr = int(m.group(3))
        imms = int(m.group(4))
        n = 64 if 'x' in rd else 32
        if imms < immr:
            lsb = n - immr
            width = imms + 1
            return f'sbfiz {rd}, {rn}, {lsb}, {width}'
        return m.group(0)
    s = re.sub(r'\bsbfm\s+((?:w|x)\d+),\s*((?:w|x)\d+),\s*(\d+),\s*(\d+)', _sbfm_to_sbfiz, s)
    # ORR vector with identical sources → MOV alias: orr vN.T, vM.T, vM.T → mov vN.T, vM.T
    s = re.sub(r'\borr\s+(v\d+\.\d+b),\s*(v\d+\.\d+b),\s*\2\b', r'mov \1, \2', s)
    # MOVI: strip arrangement for zero-immediate comparison (veda64 omits arrangement)
    s = re.sub(r'\bmovi\s+(v\d+)(?:\.\d+[bhsdq])?,\s*0\b', r'movi \1, 0', s)
    # RDVL: always uses X register (64-bit result)
    s = re.sub(r'\brdvl\s+w(\d+)', r'rdvl x\1', s)
    # INS → MOV alias (preferred form for element insert)
    s = re.sub(r'\bins\b', 'mov', s)
    # DUP scalar → MOV alias (preferred form for scalar duplicate)
    s = re.sub(r'\bdup\s+([bhsd]\d+)', r'mov \1', s)
    # SHRN with shift 0 → MOVI encoding collision
    s = re.sub(r'\bshrn\s+((?:w|v)\d+(?:\.\d+[bhsdq])?),\s*(?:(?:w|v)\d+(?:\.\d+[bhsdq])?),\s*0\b', r'movi \1, 0', s)
    # SSHLL2 encoding collision with MOVI: sshll2 wN, wM → movi vN.T, imm, lsl #8
    # These overlap in encoding space; normalize sshll2 away for comparison
    s = re.sub(r'\bsshll2\s+\S+,\s*\S+', 'sshll2_collision', s)
    if 'sshll2_collision' in s:
        return 'sshll2_collision'  # Can't normalize to match, skip
    # SVE destructive ops: veda64 prints "op Zd.T, Pg/m, Zm.T" but capstone prints
    # "op Zd.T, Pg/m, Zd.T, Zm.T" (repeating destination as first source)
    # Normalize capstone form → veda64 form by removing the duplicate Zdn
    s = re.sub(r'(\b(?:add|sub|mul|and|orr|eor|bic|asr|lsl|lsr|smax|smin|umax|umin|sabd|uabd|sdiv|udiv|fadd|fsub|fmul|fdiv|fmax|fmin|fmaxnm|fminnm|fnmul|smulh|umulh|srshl|urshl|sqadd|uqadd|sqsub|uqsub|sqrshl|uqrshl|frecps|frsqrts|ftsmul|ftssel|fscale|cls|clz|cnt|not|neg|fneg|fabs|abs|sxtb|sxth|sxtw|uxtb|uxth|uxtw|rbit|revb|revh|revw|frinta|frinti|frintm|frintn|frintp|frintx|frintz|frecpx|fsqrt|fcvtzs|fcvtzu|scvtf|ucvtf|flogb|compact|splice)\s+)(z\d+\.\w+),\s*(p\d+/m),\s*\2,\s*', r'\1\2, \3, ', s)
    # SEL predicate: veda64 prints "sel Zd, Pg/m, ..." capstone prints "sel Zd, Pg, ..."
    # Also: veda64 may omit arrangement on last Zm, capstone includes it.
    # Normalize: strip /m on predicate, and strip arrangement from all Z regs.
    s = re.sub(r'\bsel\s+(z\d+)\.\w+,\s*(p\d+)(?:/m)?,\s*(z\d+)\.\w+,\s*(z\d+)(?:\.\w+)?',
               r'sel \1, \2, \3, \4', s)
    # LASTB/LASTA: veda64 adds arrangement on predicate, capstone doesn't
    s = re.sub(r'\b(last[ab])\s+(\w+),\s*(p\d+)\.\w+,', r'\1 \2, \3,', s)
    # SUBS with SP dest → CMP alias (Rd=31 in SUBS means XZR, aliased to CMP)
    # veda64: "subs sp, xN" → capstone: "cmp sp, xN"  (veda64 misreads Rd=31 as SP)
    s = re.sub(r'\bsubs\s+sp,', 'cmp sp,', s)
    # SME outer product: veda64 operand order is "Pg, Pg, Zn, Zm, ZAd",
    # capstone order is "ZAd.T, Pg, Pg, Zn, Zm". Normalize to strip all and match.
    # Match: fmopa|fmops|smopa|smops|umopa|umops|bfmopa|bfmops + variants
    def _sme_outer_product_norm(m):
        mnem = m.group(1)
        rest = m.group(2)
        # Extract sorted numbers for loose comparison
        nums = sorted(re.findall(r'\d+', rest))
        return mnem + ' ' + ' '.join(nums)
    s = re.sub(r'\b((?:bf|f|s|u)?mop[as])\s+(.+)', _sme_outer_product_norm, s)
    # SVE LD/ST structure: completely different operand formats between veda64 and capstone.
    # veda64: "ld1sb w1, z24.s, p0/z, z15" → capstone: "ld1sb { z24.s }, p0/z, [x1, z15.s, uxtw]"
    # Too complex to normalize structurally; strip to just mnemonic + register numbers for comparison.
    def _sve_ldst_norm(m):
        mnem = m.group(1)
        rest = m.group(2)
        # Extract all numbers for loose comparison (register numbers + immediates)
        nums = sorted(re.findall(r'\d+', rest))
        return mnem + ' ' + ' '.join(nums)
    # Match SVE contiguous loads/stores (longer patterns first to avoid partial matches)
    s = re.sub(r'\b(ld1rsb|ld1rsh|ld1rsw|ldff1sb|ldff1sh|ldff1sw|ldnt1sb|ldnt1sh|ldnt1sw|ld1sb|ld1sh|ld1sw|ld1rb|ld1rh|ld1rw|ld1rd|ld1r|ldff1[bhwdq]|ldnf1[bhwdq]|ldnt1[bhwdq]|ld1[bhwdq]|st1[bhwdq]|stnt1[bhwdq]|ld[234][bhwdqr]|st[234][bhwdq]|ld[234]r)\s+(.+)',
               _sve_ldst_norm, s)
    # WHILEGE/WHILELT etc: veda64 "whilege wN, wM, pN.T" → capstone "whilege pN.T, wN, wM"
    # Normalize by sorting operands to canonical form
    def _while_norm(m):
        mnem = m.group(1)
        ops = [x.strip() for x in m.group(2).split(',')]
        # Extract predicate operand and GP register operands
        pred = [o for o in ops if o.startswith('p')]
        gp = [o for o in ops if not o.startswith('p')]
        return mnem + ' ' + ', '.join(pred + gp)
    s = re.sub(r'\b(while\w+)\s+(.+)', _while_norm, s)
    # CSINC/CSINV → CSET/CSETM alias normalization
    # veda64: "csinc wN, cond" → capstone: "cset wN, inv_cond"
    # veda64: "csinv wN, cond" → capstone: "csetm wN, inv_cond"
    # Also CINC: "csinc wN, wM, cond" (Rm=Rn≠31) → "cinc wN, wM, inv_cond"
    # Also CINV: "csinv wN, wM, cond" (Rm=Rn≠31) → "cinv wN, wM, inv_cond"
    _COND_INVERT = {
        'eq': 'ne', 'ne': 'eq', 'lo': 'hs', 'hs': 'lo',
        'mi': 'pl', 'pl': 'mi', 'vs': 'vc', 'vc': 'vs',
        'hi': 'ls', 'ls': 'hi', 'ge': 'lt', 'lt': 'ge',
        'gt': 'le', 'le': 'gt', 'al': 'nv', 'nv': 'al',
    }
    def _csinc_to_cset(m):
        reg = m.group(1)
        cond = m.group(2)
        inv = _COND_INVERT.get(cond, cond)
        return f'cset {reg}, {inv}'
    s = re.sub(r'\bcsinc\s+((?:w|x)\d+),\s*(\w+)\s*$', _csinc_to_cset, s)
    def _csinv_to_csetm(m):
        reg = m.group(1)
        cond = m.group(2)
        inv = _COND_INVERT.get(cond, cond)
        return f'csetm {reg}, {inv}'
    s = re.sub(r'\bcsinv\s+((?:w|x)\d+),\s*(\w+)\s*$', _csinv_to_csetm, s)
    # CSINC Rd, Rn, Rm, cond (Rm=Rn) → CINC Rd, Rn, inv_cond
    def _csinc_to_cinc(m):
        rd = m.group(1)
        rn = m.group(2)
        rm = m.group(3)
        cond = m.group(4)
        if rn == rm:
            inv = _COND_INVERT.get(cond, cond)
            return f'cinc {rd}, {rn}, {inv}'
        return m.group(0)
    s = re.sub(r'\bcsinc\s+((?:w|x)\d+),\s*((?:w|x)\d+),\s*((?:w|x)\d+),\s*(\w+)', _csinc_to_cinc, s)
    # CSINV Rd, Rn, Rm, cond (Rm=Rn) → CINV Rd, Rn, inv_cond
    def _csinv_to_cinv(m):
        rd = m.group(1)
        rn = m.group(2)
        rm = m.group(3)
        cond = m.group(4)
        if rn == rm:
            inv = _COND_INVERT.get(cond, cond)
            return f'cinv {rd}, {rn}, {inv}'
        return m.group(0)
    s = re.sub(r'\bcsinv\s+((?:w|x)\d+),\s*((?:w|x)\d+),\s*((?:w|x)\d+),\s*(\w+)', _csinv_to_cinv, s)
    # CSNEG Rd, Rn, Rm, cond (Rm=Rn) → CNEG Rd, Rn, inv_cond
    def _csneg_to_cneg(m):
        rd = m.group(1)
        rn = m.group(2)
        rm = m.group(3)
        cond = m.group(4)
        if rn == rm:
            inv = _COND_INVERT.get(cond, cond)
            return f'cneg {rd}, {rn}, {inv}'
        return m.group(0)
    s = re.sub(r'\bcsneg\s+((?:w|x)\d+),\s*((?:w|x)\d+),\s*((?:w|x)\d+),\s*(\w+)', _csneg_to_cneg, s)
    # DC/IC/AT/TLBI system instruction aliases: "sys wN" → "dc zva, xN" etc.
    s = re.sub(r'\b(dc|ic|at|tlbi)\s+\w+,\s*', r'sys ', s)
    # Normalize w→x for register numbers (both sides may use different widths)
    # This is safe since we're only comparing — keep it after specific w/x patterns
    # TBL/TBX: capstone wraps table register in { }, normalize by stripping braces
    s = s.replace('{', '').replace('}', '')
    # Helper: extract sorted register numbers for loose comparison
    def _loose_norm(mnem, rest):
        nums = sorted(re.findall(r'\d+', rest))
        return mnem + ' ' + ' '.join(nums)
    # SME MOVA/MOV tile operand formatting differences
    s = re.sub(r'\b(mov)\s+(.*?za\d+.*)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # SMLALL/UMLALL SME
    s = re.sub(r'\b(smlall|umlall|smlsll|umlsll)\s+(.+)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # EXT SVE
    s = re.sub(r'\bext\s+(z\d+)(?:\.\w+)?,\s*(.+)', lambda m: 'ext ' + ' '.join(sorted(re.findall(r'\d+', m.group(1) + ' ' + m.group(2)))), s)
    # LDRAB/LDRAA
    s = re.sub(r'\b(ldra[ab])\s+(.+)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # Writeback marker
    s = s.replace(']!', ']')
    # CPYPRT/CPYP/etc
    s = re.sub(r'\b(cpy\w+)\s+(.+)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # LD1R/LD2R/LD3R/LD4R (single structure replicate)
    s = re.sub(r'\b(ld[1234]r)\s+(.+)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # LDAPURSW/LDAPUR/STLUR etc
    s = re.sub(r'\b(ldapursw|ldapur\w*|stlur\w*)\s+(.+)', lambda m: _loose_norm(m.group(1), m.group(2)), s)
    # FMOPA/FMOPS/SMOPA etc — already handled by _sme_outer_product_norm above
    # SYS: normalize register width (w→x) for sys operands
    s = re.sub(r'\bsys\s+w(\d+)', r'sys x\1', s)
    # Collapse whitespace and remove spaces before commas
    s = ' '.join(s.split())
    s = s.replace(' ,', ',')
    return s


# ── Comparison mode ───────────────────────────────────────────────────────────

def compare_section(data, section, image_base, cs_engine, max_diffs):
    """Compare veda64 vs Capstone for one executable section.

    Returns (total_instructions, match_count, mismatch_count, veda64_only, capstone_only).
    """
    raw = data[section['raw_ptr']:section['raw_ptr'] + section['raw_size']]
    num_insns = len(raw) // 4
    base_va = image_base + section['virtual_address']

    print(f"\n=== {section['name']} (RVA: 0x{section['virtual_address']:08X}, "
          f"Size: 0x{section['raw_size']:X}, {num_insns} instructions) ===")

    words = list(struct.unpack_from(f'<{num_insns}I', raw))

    # Capstone: disassemble entire section at once
    capstone_map = {}  # offset -> (mnemonic, op_str)
    for insn in cs_engine.disasm(raw, base_va):
        capstone_map[insn.address] = f"{insn.mnemonic} {insn.op_str}".strip()

    # veda64: disassemble all words via binding
    veda_lines = veda64_disasm_all(words)

    match_count = 0
    mismatch_count = 0
    veda64_only = 0
    capstone_only = 0
    diff_printed = 0

    for idx, veda_text in enumerate(veda_lines):
        va = base_va + idx * 4
        word = words[idx]

        cs_text = capstone_map.get(va)

        # Normalize with VA for relative-to-absolute branch conversion
        veda_norm = normalize(veda_text, va) if veda_text else ''
        cs_norm = normalize(cs_text, va) if cs_text else ''

        # Detect "unknown" from each side
        veda_is_unknown = 'unknown' in veda_text.lower() if veda_text else True
        cs_is_unknown = cs_text is None or cs_text.startswith('.byte')

        if veda_is_unknown and cs_is_unknown:
            # Both failed — not interesting
            match_count += 1
            continue

        if veda_is_unknown and not cs_is_unknown:
            capstone_only += 1
            if max_diffs == 0 or diff_printed < max_diffs:
                print(f"  0x{va:016X}: {word:08x}  VEDA64_MISS")
                print(f"      veda64:   {veda_text}")
                print(f"      capstone: {cs_text}")
                diff_printed += 1
            continue

        if not veda_is_unknown and cs_is_unknown:
            veda64_only += 1
            if max_diffs == 0 or diff_printed < max_diffs:
                print(f"  0x{va:016X}: {word:08x}  CAPSTONE_MISS")
                print(f"      veda64:   {veda_text}")
                print(f"      capstone: (failed)")
                diff_printed += 1
            continue

        # Both decoded — compare normalized
        if veda_norm == cs_norm:
            match_count += 1
        else:
            mismatch_count += 1
            if max_diffs == 0 or diff_printed < max_diffs:
                print(f"  0x{va:016X}: {word:08x}  MISMATCH")
                print(f"      veda64:   {veda_text}")
                print(f"      capstone: {cs_text}")
                diff_printed += 1

    if max_diffs > 0 and diff_printed >= max_diffs:
        remaining = mismatch_count + veda64_only + capstone_only - diff_printed
        if remaining > 0:
            print(f"  ... and {remaining} more difference(s) not shown (use --max-diffs 0 to show all)")

    return num_insns, match_count, mismatch_count, veda64_only, capstone_only


# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(
        description='Disassemble ARM64 PE executables using veda64_py binding')
    parser.add_argument('pe_file', help='Path to PE executable')
    parser.add_argument('--compare', action='store_true',
                        help='Compare veda64 output against Capstone and report differences')
    parser.add_argument('--max-diffs', type=int, default=50,
                        help='Max differences to print per section (0=unlimited, default=50)')
    args = parser.parse_args()

    if _veda64_py is None:
        print("Error: veda64_py binding not found.", file=sys.stderr)
        print("Build the project first (cmake --build __build_arm64 --config Release).", file=sys.stderr)
        return 1

    pe_path = Path(args.pe_file)
    if not pe_path.is_file():
        print(f"Error: File not found: {pe_path}", file=sys.stderr)
        return 1

    print(f"Using veda64_py binding ({Path(_veda64_py.__file__).name})")

    load_cache()

    data = pe_path.read_bytes()

    try:
        sections, image_base = parse_pe(data)
    except ValueError as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1

    print(f"File: {pe_path.name}")
    print(f"Image Base: 0x{image_base:016X}")
    print(f"Sections: {len(sections)}")

    exec_sections = [s for s in sections if s['characteristics'] & IMAGE_SCN_MEM_EXECUTE]
    if not exec_sections:
        print("Error: No executable sections found.", file=sys.stderr)
        return 1

    if args.compare:
        try:
            import capstone
        except ImportError:
            print("Error: capstone package required for --compare mode.", file=sys.stderr)
            print("Install with: pip install capstone", file=sys.stderr)
            return 1

        cs = capstone.Cs(capstone.CS_ARCH_AARCH64, capstone.CS_MODE_ARM)
        cs.skipdata = True

        totals = {'insns': 0, 'match': 0, 'mismatch': 0, 'veda_only': 0, 'cs_only': 0}

        for section in sections:
            if not (section['characteristics'] & IMAGE_SCN_MEM_EXECUTE):
                print(f"\n=== {section['name']} (not executable, skipped) ===")
                continue

            insns, match, mismatch, veda_only, cs_only = compare_section(
                data, section, image_base, cs, args.max_diffs
            )
            totals['insns'] += insns
            totals['match'] += match
            totals['mismatch'] += mismatch
            totals['veda_only'] += veda_only
            totals['cs_only'] += cs_only

            total_diffs = mismatch + veda_only + cs_only
            pct = match/insns*100 if insns > 0 else 100.0
            print(f"\n  Section summary: {match} match, {mismatch} mismatch, "
                  f"{veda_only} veda64-only, {cs_only} capstone-only "
                  f"({match}/{insns} = {pct:.1f}% agreement)")

        # Overall summary
        t = totals
        total_diffs = t['mismatch'] + t['veda_only'] + t['cs_only']
        print(f"\n{'='*60}")
        print(f"Overall: {t['insns']} instructions, {t['match']} match, "
              f"{total_diffs} differences")
        print(f"  Mismatches:    {t['mismatch']}")
        print(f"  veda64-only:   {t['veda_only']}")
        print(f"  capstone-only: {t['cs_only']}")
        if t['insns'] > 0:
            print(f"  Agreement:     {t['match']}/{t['insns']} "
                  f"({t['match']/t['insns']*100:.2f}%)")
    else:
        for section in sections:
            if section['characteristics'] & IMAGE_SCN_MEM_EXECUTE:
                disassemble_section(data, section, image_base)
            else:
                print(f"\n=== {section['name']} (not executable, skipped) ===")

    save_cache()
    return 0


if __name__ == '__main__':
    sys.exit(main())
