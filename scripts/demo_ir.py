#!/usr/bin/env python3
"""Demo of the veda64 Python API: decode + IR lifting."""

import sys, os

# Add build directory to path
build_dir = os.path.join(os.path.dirname(__file__), '..', '__build_arm64')
sys.path.insert(0, os.path.abspath(build_dir))

import veda64_py as v

# ─--Colors --─────────────────────────────────────────────────────────────────

RESET  = '\033[0m'
BOLD   = '\033[1m'
DIM    = '\033[2m'
RED    = '\033[91m'
GREEN  = '\033[92m'
YELLOW = '\033[93m'
BLUE   = '\033[94m'
CYAN   = '\033[96m'
WHITE  = '\033[97m'

def color_varnode(vn):
    """Colorize a VarNode based on its space."""
    s = repr(vn)
    if vn.space == v.ir.Space.GPR:    return f'{GREEN}{s}{RESET}'
    if vn.space == v.ir.Space.SIMD:   return f'{CYAN}{s}{RESET}'
    if vn.space == v.ir.Space.Temp:   return f'{DIM}{s}{RESET}'
    if vn.space == v.ir.Space.Const:  return f'{YELLOW}{s}{RESET}'
    if vn.space == v.ir.Space.Flags:  return f'{RED}{s}{RESET}'
    if vn.space == v.ir.Space.RAM:    return f'{RED}{s}{RESET}'
    return s

def color_op(op):
    """Pretty-print a single IR op with colors."""
    parts = []
    if op.output.size > 0 or op.output.space != v.ir.Space.Const:
        parts.append(f'{color_varnode(op.output)} {DIM}={RESET} ')
    parts.append(f'{BOLD}{WHITE}{v.ir.opcode_name(op.opcode)}{RESET}')
    for i, inp in enumerate(op.inputs):
        parts.append(f' {color_varnode(inp)}' if i == 0 else f'{DIM},{RESET} {color_varnode(inp)}')
    return ''.join(parts)

# ─--Demo helpers --───────────────────────────────────────────────────────────

def show(insn_hex, title=None):
    """Decode, lift, simplify, and display one instruction."""
    decoded = v.decode(insn_hex)
    asm = decoded.to_string() if decoded else '<unknown>'
    if title:
        print(f'\n{BOLD}--{title} --{RESET}')
    print(f'  {DIM}0x{insn_hex:08x}{RESET}  {BOLD}{asm}{RESET}')

    lifted = v.ir.lift(insn_hex)
    if not lifted:
        print(f'  {RED}(no IR){RESET}')
        return

    simple = v.ir.simplify(lifted)
    for op in simple:
        print(f'    {color_op(op)}')

def section(title):
    print(f'\n{BOLD}{BLUE}{"=" * 60}{RESET}')
    print(f'{BOLD}{BLUE}  {title}{RESET}')
    print(f'{BOLD}{BLUE}{"=" * 60}{RESET}')

# ─--Main --───────────────────────────────────────────────────────────────────

print(f'{BOLD}veda64 v{v.VERSION_MAJOR}.{v.VERSION_MINOR}.{v.VERSION_PATCH} -ARM64 IR Demo{RESET}')

# --- GP Arithmetic ---
section('GP Arithmetic')
show(0x8B020020, 'Register add')
show(0xCB020020, 'Register sub')
show(0x91010820, 'Immediate add')
show(0xD1010820, 'Immediate sub')
show(0x9AC20C20, 'Signed divide')
show(0x9AC20820, 'Unsigned divide')
show(0x9B020C20, 'Multiply-add (MADD)')
show(0x9B028C20, 'Multiply-sub (MSUB)')
show(0xD2824680, 'Move immediate')

# --- Flags ---
section('Flags')
show(0xAB020020, 'ADDS (sets flags)')
show(0xEB020020, 'SUBS (sets flags)')
show(0x9A821020, 'Conditional select (CSEL)')

# --- Branches ---
section('Branches')
show(0x14000040, 'Unconditional branch')
show(0x94000040, 'Branch with link (call)')
show(0xD65F03C0, 'Return')
show(0x54000041, 'Conditional branch (B.NE)')
show(0xB4000080, 'Compare and branch zero')
show(0xB5000080, 'Compare and branch non-zero')
show(0x36100060, 'Test bit and branch zero')

# --- Memory ---
section('Memory')
show(0xF9400420, 'Load 64-bit')
show(0xF9000420, 'Store 64-bit')
show(0xA9407BFD, 'Load pair (LDP)')
show(0xA9007BFD, 'Store pair (STP)')

# --- SIMD (element-unrolled) ---
section('SIMD -Element-Level Unrolling')
show(0x4EA28420, 'Vector ADD .4S (4 × 32-bit)')
show(0x2EA28420, 'Vector SUB .2S (2 × 32-bit, 64-bit lower)')
show(0x6EA0F820, 'Vector FNEG .4S (unary)')
show(0x4E228420, 'Vector ADD .16B (16 × 8-bit)')

# --- Programmatic access ---
section('Programmatic Access')
print(f'\n  {DIM}# Walk the IR for MADD X0, X1, X2, X3{RESET}')
lifted = v.ir.simplify(v.ir.lift(0x9B020C20))
for i, op in enumerate(lifted):
    opc = op.opcode
    out = op.output
    ins = op.inputs
    print(f'  {DIM}op[{i}]:{RESET} opcode={BOLD}{opc}{RESET}'
          f'  out=({out.space}, reg={out.offset}, {out.size}B)'
          f'  in={[(inp.space, inp.offset, inp.size) for inp in ins]}')

# --- Decode + lift pipeline ---
section('Full Pipeline: bytes -> decode -> lift -> simplify')
raw_bytes = b'\x20\x84\xa2\x4e'  # ADD V0.4S, V1.4S, V2.4S (little-endian)
insn_word = v.from_bytes(raw_bytes)
decoded = v.decode(insn_word)
lifted = v.ir.lift(insn_word)
simplified = v.ir.simplify(lifted)

print(f'\n  {DIM}bytes:     {RESET}{raw_bytes.hex(" ")}')
print(f'  {DIM}uint32:    {RESET}0x{insn_word:08x}')
print(f'  {DIM}assembly:  {RESET}{BOLD}{decoded.to_string()}{RESET}')
print(f'  {DIM}mnemonic:  {RESET}{decoded.mnemonic} ({v.mnemonic_to_string(decoded.mnemonic)})')
print(f'  {DIM}operands:  {RESET}{", ".join(repr(op) for op in decoded.operands)}')
print(f'  {DIM}IR ops:    {RESET}{len(lifted)} raw -> {len(simplified)} simplified')
print(f'  {DIM}IR:{RESET}')
for op in simplified:
    print(f'    {color_op(op)}')

print()
