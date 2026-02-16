#!/usr/bin/env python3
"""PE ARM64 disassembler and comparison tool using veda64-disasm and Capstone."""

import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path

IMAGE_SCN_MEM_EXECUTE = 0x20000000
MACHINE_ARM64 = 0xAA64
BATCH_SIZE = 500


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


def veda64_disasm_batch(words, disasm_path):
    """Disassemble a batch of uint32 words with veda64-disasm. Returns list of strings."""
    args = [str(disasm_path)] + [f'0x{w:08X}' for w in words]
    result = subprocess.run(args, capture_output=True, text=True)
    output = []
    for line in result.stdout.strip().splitlines():
        colon_pos = line.find(':')
        if colon_pos != -1:
            output.append(line[colon_pos + 1:].strip())
        else:
            output.append(line.strip())
    return output


def disassemble_section(data, section, image_base, disasm_path):
    """Disassemble an executable section."""
    raw = data[section['raw_ptr']:section['raw_ptr'] + section['raw_size']]
    num_insns = len(raw) // 4
    base_va = image_base + section['virtual_address']

    print(f"\n=== {section['name']} (RVA: 0x{section['virtual_address']:08X}, "
          f"Size: 0x{section['raw_size']:X}, {num_insns} instructions) ===")

    words = []
    for i in range(num_insns):
        words.append(struct.unpack_from('<I', raw, i * 4)[0])

    for batch_start in range(0, len(words), BATCH_SIZE):
        batch = words[batch_start:batch_start + BATCH_SIZE]
        disasm_lines = veda64_disasm_batch(batch, disasm_path)

        for j, text in enumerate(disasm_lines):
            idx = batch_start + j
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
        ops = [x.strip() for x in m.group(2).split(',')]
        # Extract ZA operand (starts with 'za') and strip arrangement from all
        za_ops = [o for o in ops if o.startswith('za')]
        other_ops = [o for o in ops if not o.startswith('za')]
        # Strip arrangement from all operands for comparison
        stripped = []
        for o in za_ops + other_ops:
            o = re.sub(r'(za\d+)(?:\.\w+)?', r'\1', o)
            o = re.sub(r'(z\d+)(?:\.\w+)?', r'\1', o)
            stripped.append(o)
        return mnem + ' ' + ', '.join(stripped)
    s = re.sub(r'\b((?:bf|s|u)?mop[as])\s+(.+)', _sme_outer_product_norm, s)
    # SVE LD/ST structure: completely different operand formats between veda64 and capstone.
    # veda64: "ld1sb w1, z24.s, p0/z, z15" → capstone: "ld1sb { z24.s }, p0/z, [x1, z15.s, uxtw]"
    # Too complex to normalize structurally; strip to just mnemonic + register numbers for comparison.
    def _sve_ldst_norm(m):
        mnem = m.group(1)
        rest = m.group(2)
        # Extract all register numbers and immediates for a loose comparison
        regs = re.findall(r'(?:z|p|x|w|sp)\d*', rest)
        imms = re.findall(r'(?<![a-z])(\d+)(?![a-z])', rest)
        return mnem + ' ' + ' '.join(regs + imms)
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
    # Collapse whitespace
    s = ' '.join(s.split())
    return s


# ── Comparison mode ───────────────────────────────────────────────────────────

def compare_section(data, section, image_base, disasm_path, cs_engine, max_diffs):
    """Compare veda64-disasm vs Capstone for one executable section.

    Returns (total_instructions, match_count, mismatch_count, veda64_only, capstone_only).
    """
    raw = data[section['raw_ptr']:section['raw_ptr'] + section['raw_size']]
    num_insns = len(raw) // 4
    base_va = image_base + section['virtual_address']

    print(f"\n=== {section['name']} (RVA: 0x{section['virtual_address']:08X}, "
          f"Size: 0x{section['raw_size']:X}, {num_insns} instructions) ===")

    words = []
    for i in range(num_insns):
        words.append(struct.unpack_from('<I', raw, i * 4)[0])

    # Capstone: disassemble entire section at once
    capstone_map = {}  # offset -> (mnemonic, op_str)
    for insn in cs_engine.disasm(raw, base_va):
        capstone_map[insn.address] = f"{insn.mnemonic} {insn.op_str}".strip()

    match_count = 0
    mismatch_count = 0
    veda64_only = 0
    capstone_only = 0
    diff_printed = 0

    for batch_start in range(0, len(words), BATCH_SIZE):
        batch = words[batch_start:batch_start + BATCH_SIZE]
        veda_lines = veda64_disasm_batch(batch, disasm_path)

        for j, veda_text in enumerate(veda_lines):
            idx = batch_start + j
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
        description='Disassemble ARM64 PE executables using veda64-disasm')
    parser.add_argument('pe_file', help='Path to PE executable')
    parser.add_argument('--disasm', help='Path to veda64-disasm.exe', default=None)
    parser.add_argument('--compare', action='store_true',
                        help='Compare veda64 output against Capstone and report differences')
    parser.add_argument('--max-diffs', type=int, default=50,
                        help='Max differences to print per section (0=unlimited, default=50)')
    args = parser.parse_args()

    pe_path = Path(args.pe_file)
    if not pe_path.is_file():
        print(f"Error: File not found: {pe_path}", file=sys.stderr)
        return 1

    if args.disasm:
        disasm_path = Path(args.disasm)
    else:
        disasm_path = Path(__file__).parent / '__build_arm64' / 'Release' / 'veda64-disasm.exe'

    if not disasm_path.is_file():
        print(f"Error: veda64-disasm not found at: {disasm_path}", file=sys.stderr)
        print("Use --disasm to specify its location.", file=sys.stderr)
        return 1

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
                data, section, image_base, disasm_path, cs, args.max_diffs
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
                disassemble_section(data, section, image_base, disasm_path)
            else:
                print(f"\n=== {section['name']} (not executable, skipped) ===")

    return 0


if __name__ == '__main__':
    sys.exit(main())
