#!/usr/bin/env python3
"""
_asl_to_cpp.py
==============
Translate ARM ASL (Architecture Specification Language) decode pseudocode
into C++ suitable for use in the veda64 code generator (parse_arm64_xml.py).

Usage
-----
    from _asl_to_cpp import asl_to_cpp, asl_field_ref

    cpp_lines = asl_to_cpp(asl_text, field_widths)
    # field_widths: dict mapping field name -> bit width  (from regdiagram boxes)

The output is a list of C++ statement strings (no trailing newlines).
They are intended to be emitted inside a decode function body where the
encoding struct fields are accessible as plain names (e.g.  Rd, Rn, imm12).

ASL → C++ mapping reference
----------------------------
This file also documents the full mapping so it can be maintained alongside
the generator.

ASL construct                    C++ equivalent
─────────────────────────────────────────────────────────────────────────────
TYPES
  integer / integer{}            int  (or uint32_t for unsigned fields)
  integer{0..N}                  int  (range annotation dropped)
  bits(N)                        uint64_t  (or uint32_t when N<=32)
  boolean                        bool
  ShiftType / ExtendType etc.    keep as-is (enums defined in veda64.hpp)

LITERALS
  '0101...'  (bit string)        0b0101... as uint32_t  (spaces stripped)
  TRUE / FALSE                   true / false

DECLARATIONS
  let x : T = expr;             const auto x = expr;
  var x : T;                    T x;    (or: auto x = T{};)
  var x : T = expr;             auto x = expr;

EXPRESSIONS
  UInt(field)                   static_cast<uint32_t>(field)  [or just field]
  SInt(field)                   static_cast<int32_t>(sign_extend(field, width))
  field[i]                      ((field >> i) & 1u)
  field[hi:lo]                  ((field >> lo) & ((1u << (hi-lo+1)) - 1))
  a::b  (concatenation)         ((a << width_b) | b)
  ZeroExtend{N}(x)              static_cast<uint64_t>(x)  (already zero-ext)
  SignExtend{N}(x)              sign_extend(x, src_width)  -- helper needed
  Zeros{N}                      0u
  Ones{N}                       ((1u << N) - 1)
  Replicate{N}(x)               replicate(x, N)  -- helper
  LSL(x, n)                     (x << n)
  LSR(x, n)                     (x >> n)
  ASR(x, n)                     (static_cast<int32_t>(x) >> n)
  x XOR y   (bitstring)         x ^ y
  x AND y   (bitstring)         x & y
  x OR  y   (bitstring)         x | y
  NOT x     (bitstring)         ~x
  x DIV y                       x / y
  x MOD y                       x % y
  x IN {'..','..'}              (x == val1 || x == val2 ...)
  (a, -) = f(...)               auto [a, _unused] = f(...);  (C++17 bindings)
  (a, b) = f(...)               auto [a, b] = f(...);

CONTROL FLOW
  if cond then stmt; end;       if (cond) { stmt; }
  if cond then s1; else s2; end; if (cond) { s1; } else { s2; }
  case expr of                  switch (expr) {
    when 'bits' => body           case val: { body; break; }
  end;                          }
  for i = lo to hi do           for (int i = lo; i <= hi; ++i) {
    body                            body
  end;                          }

FEATURE CHECKS / DECODE EXITS
  IsFeatureImplemented(FEAT_X)  /* requires FEAT_X */  (emit as comment)
  EndOfDecode(Decode_UNDEF)     return std::nullopt;
  EndOfDecode(Decode_NOP)       return std::nullopt;  // NOP variant

HELPER FUNCTIONS (need C++ implementations in veda64)
  DecodeBitMasks{N}(N,imms,immr,TRUE)  decode_bit_masks(N, imms, immr, true)
  DecodeShift(shift)                   decode_shift(shift)
  DecodeRegExtend(option)              decode_reg_extend(option)
  AdvSIMDExpandImm(op,cmode,imm8)      adv_simd_expand_imm(op, cmode, imm8)
  LOG2_TAG_GRANULE                     4  (constant)
"""

from __future__ import annotations
import re
from typing import Optional


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------

def asl_to_cpp(asl: str, field_widths: Optional[dict] = None) -> list[str]:
    """
    Translate an ASL decode pseudocode block to a list of C++ lines.

    Parameters
    ----------
    asl          : full pseudocode text as extracted from XML
    field_widths : {field_name: bit_width} from the encoding's regdiagram.
                   Used for sign-extension and concatenation width inference.

    Returns
    -------
    list of C++ statement strings (no trailing newline each)
    """
    if field_widths is None:
        field_widths = {}
    ctx = _Context(field_widths)
    lines = asl.splitlines()
    out: list[str] = []
    i = 0
    while i < len(lines):
        raw = lines[i]
        stripped = raw.strip()
        if not stripped or stripped.startswith('//'):
            if stripped.startswith('//'):
                out.append(raw.rstrip())   # keep comments as-is
            i += 1
            continue

        # Collect a logical statement (may span multiple lines ending in ';' or 'end;')
        stmt, consumed = _collect_statement(lines, i)
        cpp = _translate_statement(stmt, ctx)
        out.extend(cpp)
        i += consumed

    return out


def asl_field_ref(field: str, width: int, signed: bool = False) -> str:
    """
    Return the C++ expression to read a bitfield named `field` of `width` bits.
    Used for simple scalar field access in generated decode functions.
    """
    if signed:
        return f"sign_extend({field}, {width})"
    return f"static_cast<uint32_t>({field})"


# ---------------------------------------------------------------------------
# Internal helpers
# ---------------------------------------------------------------------------

class _Context:
    def __init__(self, field_widths: dict):
        self.fw = field_widths      # field name → width in bits
        self.var_types: dict[str, str] = {}   # declared variables → C++ type


def _collect_statement(lines: list[str], start: int) -> tuple[str, int]:
    """
    Collect a complete ASL statement starting at `start`.
    Returns (joined_text, lines_consumed).
    Simple heuristic: a statement ends at a line whose stripped form ends with
    ';' or 'end;', or is a single-line if/let/var.
    """
    text = lines[start].strip()
    i = start + 1
    # Multi-line: keep collecting until balanced end; or terminal ;
    # Detect block-start keywords
    block_starters = re.compile(r'^(if\b|case\b|for\b)')
    if block_starters.match(text):
        depth = 0
        acc = [text]
        for j in range(start, len(lines)):
            s = lines[j].strip()
            if j == start:
                pass
            else:
                acc.append(s)
            opens = len(re.findall(r'\b(if|case|for)\b', s))
            closes = len(re.findall(r'\bend;\s*$', s))
            depth += opens - closes
            if depth <= 0 and j > start:
                return ' '.join(acc), j - start + 1
        return ' '.join(acc), len(lines) - start
    # Simple single-line statement
    return text, 1


def _translate_statement(stmt: str, ctx: _Context) -> list[str]:
    """Translate a single (possibly multi-line joined) ASL statement."""
    s = stmt.strip()
    if not s:
        return []

    # ---- let declaration ----
    m = re.match(r'^let\s+(\w+)\s*:\s*([^=]+?)\s*=\s*(.+?)\s*;$', s)
    if m:
        name, typ, expr = m.group(1), m.group(2).strip(), m.group(3).strip()
        cpp_type = _asl_type_to_cpp(typ, ctx)
        cpp_expr = _asl_expr_to_cpp(expr, ctx)
        ctx.var_types[name] = cpp_type
        return [f"const {cpp_type} {name} = {cpp_expr};"]

    # ---- var declaration with init ----
    m = re.match(r'^var\s+(\w+)\s*:\s*([^=]+?)\s*=\s*(.+?)\s*;$', s)
    if m:
        name, typ, expr = m.group(1), m.group(2).strip(), m.group(3).strip()
        cpp_type = _asl_type_to_cpp(typ, ctx)
        cpp_expr = _asl_expr_to_cpp(expr, ctx)
        ctx.var_types[name] = cpp_type
        return [f"{cpp_type} {name} = {cpp_expr};"]

    # ---- var declaration without init ----
    m = re.match(r'^var\s+(\w+)\s*:\s*(.+?)\s*;$', s)
    if m:
        name, typ = m.group(1), m.group(2).strip()
        cpp_type = _asl_type_to_cpp(typ, ctx)
        ctx.var_types[name] = cpp_type
        return [f"{cpp_type} {name}{{}};"]

    # ---- assignment ----
    # tuple: (a, -) = expr; or (a, b) = expr;
    m = re.match(r'^\((.+?)\)\s*=\s*(.+?)\s*;$', s)
    if m:
        lhs_raw, rhs = m.group(1), m.group(2).strip()
        parts = [p.strip() for p in lhs_raw.split(',')]
        cpp_parts = ['_unused' if p == '-' else p for p in parts]
        cpp_rhs = _asl_expr_to_cpp(rhs, ctx)
        if len(cpp_parts) == 2:
            return [f"auto [{cpp_parts[0]}, {cpp_parts[1]}] = {cpp_rhs};"]
        return [f"auto [{', '.join(cpp_parts)}] = {cpp_rhs};"]

    # plain assignment (also handles struct.field = expr)
    m = re.match(r'^([\w.]+)\s*=\s*(.+?)\s*;$', s)
    if m:
        name, expr = m.group(1), m.group(2).strip()
        cpp_expr = _asl_expr_to_cpp(expr, ctx)
        return [f"{name} = {cpp_expr};"]

    # ---- if ... then ... end; (single-line or joined) ----
    m = re.match(r'^if\s+(.+?)\s+then\s+(.+?)\s*(?:else\s+(.+?)\s*)?end;\s*$', s, re.DOTALL)
    if m:
        cond = _asl_expr_to_cpp(m.group(1).strip(), ctx)
        then_body = _translate_statement(m.group(2).strip(), ctx)
        lines_out = [f"if ({cond}) {{"]
        lines_out.extend('    ' + l for l in then_body)
        if m.group(3):
            else_body = _translate_statement(m.group(3).strip(), ctx)
            lines_out.append("} else {")
            lines_out.extend('    ' + l for l in else_body)
        lines_out.append("}")
        return lines_out

    # ---- case ... of ... end; ----
    m = re.match(r'^case\s+(.+?)\s+of\s+(.+?)\s*end;\s*$', s, re.DOTALL)
    if m:
        expr = _asl_expr_to_cpp(m.group(1).strip(), ctx)
        body = m.group(2).strip()
        lines_out = [f"switch ({expr}) {{"]
        # parse when + optional otherwise clauses
        when_pat = re.compile(
            r"(?:when\s+'([^']+)'|otherwise)\s*=>\s*(.*?)(?=when\s+'|otherwise\s*=>|$)",
            re.DOTALL
        )
        for wm in when_pat.finditer(body):
            bits_val = wm.group(1)  # None for 'otherwise'
            body_stmts = wm.group(2).strip()
            if bits_val is not None:
                val = int(bits_val.replace(' ', ''), 2)
                lines_out.append(f"    case {val}: {{")
            else:
                lines_out.append("    default: {")
            for bstmt in body_stmts.split(';'):
                bstmt = bstmt.strip()
                if bstmt and not bstmt.startswith('//'):
                    translated = _translate_statement(bstmt + ';', ctx)
                    lines_out.extend('        ' + l for l in translated)
                elif bstmt.startswith('//'):
                    lines_out.append('        ' + bstmt)
            lines_out.append("        break;")
            lines_out.append("    }")
        lines_out.append("}")
        return lines_out

    # ---- for i = lo to hi do ... end; ----
    m = re.match(r'^for\s+(\w+)\s*=\s*(.+?)\s+to\s+(.+?)\s+do\s+(.+?)\s*end;\s*$', s, re.DOTALL)
    if m:
        var, lo, hi, body = m.group(1), m.group(2).strip(), m.group(3).strip(), m.group(4).strip()
        cpp_lo = _asl_expr_to_cpp(lo, ctx)
        cpp_hi = _asl_expr_to_cpp(hi, ctx)
        body_lines = []
        for bstmt in body.split(';'):
            bstmt = bstmt.strip()
            if bstmt:
                body_lines.extend(_translate_statement(bstmt + ';', ctx))
        lines_out = [f"for (int {var} = {cpp_lo}; {var} <= {cpp_hi}; ++{var}) {{"]
        lines_out.extend('    ' + l for l in body_lines)
        lines_out.append("}")
        return lines_out

    # ---- EndOfDecode ----
    if 'EndOfDecode(Decode_UNDEF)' in s:
        return ["return std::nullopt;  // UNDEFINED"]
    if 'EndOfDecode(Decode_NOP)' in s:
        return ["return std::nullopt;  // NOP"]
    if 'EndOfDecode' in s:
        return ["return std::nullopt;"]

    # ---- IsFeatureImplemented guard (standalone) ----
    m = re.match(r'^if\s+!?IsFeatureImplemented\((\w+)\).*EndOfDecode.*$', s)
    if m:
        feat = m.group(1)
        return [f"// requires {feat}"]

    # ---- generic function call statement (SetBTypeCompatible, etc.) ----
    m = re.match(r'^(\w+)\((.+)\)\s*;$', s)
    if m:
        fn = m.group(1)
        args = _asl_expr_to_cpp(m.group(2), ctx)
        return [f"{fn}({args});  // ASL call"]

    # fallback: emit as comment
    return [f"// TODO: {s}"]


def _asl_type_to_cpp(asl_type: str, ctx: _Context) -> str:
    t = asl_type.strip()
    # integer variants
    if re.match(r'^integer(\{.*\})?$', t):
        return 'int'
    # bits(N) with literal N
    m = re.match(r'^bits\((\d+)\)$', t)
    if m:
        n = int(m.group(1))
        return 'uint64_t' if n > 32 else 'uint32_t'
    # bits(expr) with variable/expression — use uint64_t conservatively
    if re.match(r'^bits\(.+\)$', t):
        return 'uint64_t'
    # single bit
    if t == 'bit':
        return 'uint32_t'
    if t == 'boolean':
        return 'bool'
    # named types: pass through (ShiftType, ExtendType, CPYParams, etc.)
    return t


def _asl_expr_to_cpp(expr: str, ctx: _Context) -> str:
    """
    Recursively translate an ASL expression to C++.

    Precedence order (highest handled first, so lower-priority ops split last):
      1. ternary: if ... then ... else ...
      2. binary word ops: XOR/EOR/AND/OR/DIV/MOD/IN
      3. concatenation: ::
      4. function calls / atoms
    """
    e = expr.strip()
    # strip range cast annotation early
    e = re.sub(r'\s+as\s+integer\{[^}]*\}', '', e).strip()

    if not e:
        return ''

    # ---- boolean literals ----
    if e == 'TRUE':  return 'true'
    if e == 'FALSE': return 'false'

    # ---- bit string literal '0101...' ----
    m = re.match(r"^'([01 ]+)'$", e)
    if m:
        bits = m.group(1).replace(' ', '')
        return f"0b{bits}u"

    # ---- ternary: if cond then e1 else e2  (highest precedence, parse first) ----
    # Must come before :: so that "if sh == '0' then Zeros{12}::imm12 else imm12::Zeros{12}"
    # is parsed as a ternary whose branches contain ::, not as (if...) :: (imm12...)
    m = re.match(r'^if\s+(.+?)\s+then\s+(.+?)\s+else\s+(.+)$', e, re.DOTALL)
    if m:
        cond  = _asl_expr_to_cpp(m.group(1).strip(), ctx)
        then_ = _asl_expr_to_cpp(m.group(2).strip(), ctx)
        else_ = _asl_expr_to_cpp(m.group(3).strip(), ctx)
        return f"({cond} ? {then_} : {else_})"

    # ---- IN set {'..', '..'} ----
    m = re.match(r"^(.+?)\s+IN\s+\{(.+)\}$", e)
    if m:
        lhs = _asl_expr_to_cpp(m.group(1).strip(), ctx)
        vals = re.findall(r"'([01 ]+)'", m.group(2))
        cpp_vals = [f"0b{v.replace(' ','')}u" for v in vals]
        return '(' + ' || '.join(f"{lhs} == {v}" for v in cpp_vals) + ')'

    # ---- word-level binary ops (split on outermost occurrence) ----
    for asl_op, cpp_op in [(' XOR ', ' ^ '), (' EOR ', ' ^ '),
                            (' AND ', ' & '), (' OR ',  ' | '),
                            (' DIV ', ' / '), (' MOD ', ' % ')]:
        idx = _find_op(e, asl_op)
        if idx >= 0:
            lhs = _asl_expr_to_cpp(e[:idx].strip(), ctx)
            rhs = _asl_expr_to_cpp(e[idx + len(asl_op):].strip(), ctx)
            return f"({lhs}{cpp_op}{rhs})"

    # ---- concatenation a::b  (right-to-left so split on LAST ::) ----
    idx = _rfind_op(e, '::')
    if idx >= 0:
        lhs = e[:idx].strip()
        rhs = e[idx+2:].strip()
        rhs_w = _infer_width(rhs, ctx)
        cpp_lhs = _asl_expr_to_cpp(lhs, ctx)
        cpp_rhs = _asl_expr_to_cpp(rhs, ctx)
        if rhs_w:
            return f"(({cpp_lhs} << {rhs_w}) | {cpp_rhs})"
        return f"concat({cpp_lhs}, {cpp_rhs})"

    # ---- arithmetic / comparison infix ops that are already C++ syntax ----
    # Handle:  a << b,  a >> b,  a + b,  a - b,  a * b,  a == b,  a != b,  a && b,  a || b
    # Use (op_sym, search_str) so we search with spaces but emit without extra spaces.
    for op_sym, op_str in [('<<', ' << '), ('>>', ' >> '), ('+', ' + '), ('-', ' - '),
                            ('*', ' * '), ('==', ' == '), ('!=', ' != '),
                            ('&&', ' && '), ('||', ' || ')]:
        idx = _find_op(e, op_str)
        if idx >= 0:
            lhs = _asl_expr_to_cpp(e[:idx].strip(), ctx)
            rhs = _asl_expr_to_cpp(e[idx + len(op_str):].strip(), ctx)
            return f"({lhs} {op_sym} {rhs})"

    # ---- NOT (bitwise / logical) — prefix keyword or prefix ! ----
    m = re.match(r'^NOT\s+(.+)$', e)
    if m:
        return f"(~{_asl_expr_to_cpp(m.group(1), ctx)})"
    m = re.match(r'^NOT\((.+)\)$', e)   # NOT(x) function-call form
    if m:
        return f"(~{_asl_expr_to_cpp(m.group(1), ctx)})"
    m = re.match(r'^!\s*(.+)$', e)
    if m:
        return f"(!{_asl_expr_to_cpp(m.group(1), ctx)})"

    # ---- ARBITRARY (unspecified value) ----
    if re.match(r'^ARBITRARY\b', e):
        return '0 /* ARBITRARY */'

    # ---- function calls ----

    # UInt(x)
    m = re.match(r'^UInt\((.+)\)$', e)
    if m:
        return f"static_cast<uint32_t>({_asl_expr_to_cpp(m.group(1), ctx)})"

    # SInt(x)
    m = re.match(r'^SInt\((.+)\)$', e)
    if m:
        inner = m.group(1).strip()
        width = ctx.fw.get(inner, 0)
        cpp_inner = _asl_expr_to_cpp(inner, ctx)
        if width:
            return f"sign_extend({cpp_inner}, {width})"
        return f"static_cast<int32_t>({cpp_inner})"

    # ZeroExtend{N}(x)
    m = re.match(r'^ZeroExtend\{(\d+)\}\((.+)\)$', e)
    if m:
        return f"static_cast<uint64_t>({_asl_expr_to_cpp(m.group(2), ctx)})"
    m = re.match(r'^ZeroExtend\((.+),\s*\d+\)$', e)
    if m:
        return f"static_cast<uint64_t>({_asl_expr_to_cpp(m.group(1), ctx)})"

    # SignExtend{N}(x)
    m = re.match(r'^SignExtend\{(\d+)\}\((.+)\)$', e)
    if m:
        inner = m.group(2).strip()
        src_w = _infer_width(inner, ctx)
        cpp_inner = _asl_expr_to_cpp(inner, ctx)
        return f"sign_extend({cpp_inner}, {src_w})" if src_w else f"sign_extend<{m.group(1)}>({cpp_inner})"

    # Zeros{N} / Zeros(N)
    m = re.match(r'^Zeros\{(\d+)\}$', e) or re.match(r'^Zeros\((\d+)\)$', e)
    if m:
        return "0u"

    # Ones{N}
    m = re.match(r'^Ones\{(\d+)\}$', e)
    if m:
        return f"((1u << {m.group(1)}) - 1)"

    # Replicate{N}(x)
    m = re.match(r'^Replicate\{(\d+)\}\((.+)\)$', e)
    if m:
        return f"replicate({_asl_expr_to_cpp(m.group(2), ctx)}, {m.group(1)})"

    # LSL(x, n) / LSR(x, n) / ASR(x, n)  — function-call form
    m = re.match(r'^(LSL|LSR|ASR)\((.+),\s*(.+)\)$', e)
    if m:
        fn, a, b = m.group(1), _asl_expr_to_cpp(m.group(2), ctx), _asl_expr_to_cpp(m.group(3), ctx)
        if fn == 'ASR':
            return f"(static_cast<int32_t>({a}) >> {b})"
        op = '<<' if fn == 'LSL' else '>>'
        return f"({a} {op} {b})"

    # DecodeBitMasks{N}(N, imms, immr, immediate)
    m = re.match(r'^DecodeBitMasks\{[^}]*\}\((.+)\)$', e)
    if m:
        return f"decode_bit_masks({_asl_expr_to_cpp(m.group(1), ctx)})"

    # DecodeShift / DecodeRegExtend
    m = re.match(r'^DecodeShift\((.+)\)$', e)
    if m:
        return f"decode_shift({_asl_expr_to_cpp(m.group(1), ctx)})"
    m = re.match(r'^DecodeRegExtend\((.+)\)$', e)
    if m:
        return f"decode_reg_extend({_asl_expr_to_cpp(m.group(1), ctx)})"

    # AdvSIMDExpandImm
    m = re.match(r'^AdvSIMDExpandImm\((.+)\)$', e)
    if m:
        return f"adv_simd_expand_imm({_asl_expr_to_cpp(m.group(1), ctx)})"

    # IsFeatureImplemented
    m = re.match(r'^IsFeatureImplemented\((\w+)\)$', e)
    if m:
        return f"/* {m.group(1)} */"

    # ---- bit index field[i] ----
    m = re.match(r'^(\w+)\[(\d+)\]$', e)
    if m:
        return f"(({m.group(1)} >> {m.group(2)}) & 1u)"

    # ---- bit slice field[hi:lo] ----
    m = re.match(r'^(\w+)\[(\d+):(\d+)\]$', e)
    if m:
        fld, hi, lo = m.group(1), int(m.group(2)), int(m.group(3))
        mask = (1 << (hi - lo + 1)) - 1
        return f"(({fld} >> {lo}) & 0x{mask:X}u)"

    # ---- bit-string comparisons still using ' ' notation in sub-expressions ----
    e = re.sub(r"==\s*'([01 ]+)'", lambda mo: f"== 0b{mo.group(1).replace(' ','')}u", e)
    e = re.sub(r"!=\s*'([01 ]+)'", lambda mo: f"!= 0b{mo.group(1).replace(' ','')}u", e)

    # pass-through (integer literal, plain identifier, already-C++ fragment)
    return e


def _find_op(e: str, op: str) -> int:
    """
    Find the leftmost occurrence of operator `op` in `e` that is not inside
    parentheses or braces.  Returns index or -1.
    """
    depth = 0
    i = 0
    while i < len(e):
        c = e[i]
        if c in '({':
            depth += 1
        elif c in ')}':
            depth -= 1
        elif depth == 0 and e[i:i+len(op)] == op:
            return i
        i += 1
    return -1


def _rfind_op(e: str, op: str) -> int:
    """Find the rightmost occurrence of `op` outside parentheses/braces."""
    depth = 0
    last = -1
    i = 0
    while i < len(e):
        c = e[i]
        if c in '({':
            depth += 1
        elif c in ')}':
            depth -= 1
        elif depth == 0 and e[i:i+len(op)] == op:
            last = i
        i += 1
    return last


def _infer_width(expr: str, ctx: _Context) -> int:
    """Try to infer the bit width of an ASL expression."""
    expr = expr.strip()
    # Direct field name
    if expr in ctx.fw:
        return ctx.fw[expr]
    # Bit-string literal '0101...' — width = number of non-space chars
    m = re.match(r"^'([01 ]+)'$", expr)
    if m:
        return len(m.group(1).replace(' ', ''))
    # Zeros{N} or Ones{N}
    m = re.match(r'^(?:Zeros|Ones)\{(\d+)\}$', expr)
    if m:
        return int(m.group(1))
    # Concatenation a::b → width(a) + width(b)
    idx = _rfind_op(expr, '::')
    if idx >= 0:
        wa = _infer_width(expr[:idx].strip(), ctx)
        wb = _infer_width(expr[idx+2:].strip(), ctx)
        if wa and wb:
            return wa + wb
    # bits(N) type not directly available here, return 0 (unknown)
    return 0


# ---------------------------------------------------------------------------
# Quick self-test
# ---------------------------------------------------------------------------

def _selftest():
    fw = {'Rd': 5, 'Rn': 5, 'imm12': 12, 'sh': 1, 'sf': 1, 'sf': 1,
          'N': 1, 'immr': 6, 'imms': 6, 'imm6': 6, 'shift': 2, 'b5': 1, 'b40': 5, 'imm14': 14}

    tests = [
        # (asl, expected_cpp_fragment)
        ("let d : integer{} = UInt(Rd);",                       "const int d = static_cast<uint32_t>(Rd);"),
        ("let imm : bits(24) = if sh == '0' then Zeros{12}::imm12 else imm12::Zeros{12};",
                                                                 "const uint32_t imm ="),
        ("if sf == '0' && N != '0' then EndOfDecode(Decode_UNDEF); end;",
                                                                 "return std::nullopt"),
        ("let shift_type : ShiftType = DecodeShift(shift);",    "const ShiftType shift_type = decode_shift"),
        ("(imm, -) = DecodeBitMasks{32}(N, imms, immr, TRUE);", "auto [imm, _unused] = decode_bit_masks"),
    ]

    print("=== _asl_to_cpp self-test ===")
    all_pass = True
    for asl, expected in tests:
        result = asl_to_cpp(asl, fw)
        cpp = ' '.join(result)
        ok = expected in cpp
        status = "PASS" if ok else "FAIL"
        if not ok:
            all_pass = False
        print(f"  [{status}] {asl[:60]}")
        if not ok:
            print(f"         expected: {expected}")
            print(f"         got:      {cpp}")

    print(f"\n{'All tests passed.' if all_pass else 'Some tests FAILED.'}\n")


if __name__ == '__main__':
    _selftest()

    # Demo on a real ADD immediate decode block
    print("=== ADD (immediate) decode ===")
    asl = """
let d : integer{} = UInt(Rd);
let n : integer{} = UInt(Rn);
let datasize : integer{} = 32 << UInt(sf);
let imm : bits(24) = if sh == '0' then Zeros{12}::imm12 else imm12::Zeros{12};
"""
    fw = {'Rd': 5, 'Rn': 5, 'sf': 1, 'imm12': 12, 'sh': 1}
    for line in asl_to_cpp(asl.strip(), fw):
        print(line)

    print()
    print("=== AND (immediate) — DecodeBitMasks ===")
    asl2 = """
if sf == '0' && N != '0' then EndOfDecode(Decode_UNDEF); end;
let d : integer{} = UInt(Rd);
let n : integer{} = UInt(Rn);
let datasize : integer{} = 32 << UInt(sf);
var imm : bits(datasize);
(imm, -) = DecodeBitMasks{datasize}(N, imms, immr, TRUE);
"""
    fw2 = {'Rd': 5, 'Rn': 5, 'sf': 1, 'N': 1, 'immr': 6, 'imms': 6}
    for line in asl_to_cpp(asl2.strip(), fw2):
        print(line)

    print()
    print("=== ADD shifted register — bit index guard ===")
    asl3 = """
if shift == '11' then EndOfDecode(Decode_UNDEF); end;
if sf == '0' && imm6[5] == '1' then EndOfDecode(Decode_UNDEF); end;
let d : integer{} = UInt(Rd);
let n : integer{} = UInt(Rn);
let m : integer{} = UInt(Rm);
let datasize : integer{} = 32 << UInt(sf);
let shift_type : ShiftType = DecodeShift(shift);
let shift_amount : integer = UInt(imm6);
"""
    fw3 = {'Rd': 5, 'Rn': 5, 'Rm': 5, 'sf': 1, 'imm6': 6, 'shift': 2}
    for line in asl_to_cpp(asl3.strip(), fw3):
        print(line)

    print()
    print("=== case/when with otherwise ===")
    asl4 = """
var index : integer;
var Rmhi : bit;
case size of
    when '01' => index = UInt(H::L::M); Rmhi = '0';
    when '10' => index = UInt(H::L); Rmhi = M;
    otherwise => EndOfDecode(Decode_UNDEF);
end;
"""
    for line in asl_to_cpp(asl4.strip(), {'H': 1, 'L': 1, 'M': 1}):
        print(line)

    print()
    print("=== struct field assignment + ARBITRARY ===")
    asl5 = """
var memcpy : CPYParams;
memcpy.d = UInt(Rd);
memcpy.s = UInt(Rs);
let m : integer = ARBITRARY : integer;
let merging : boolean = (M == '1');
let vertical : boolean = V == '1';
"""
    for line in asl_to_cpp(asl5.strip(), {'Rd': 5, 'Rs': 5, 'M': 1, 'V': 1}):
        print(line)

    print()
    print("=== concatenation with literals ===")
    asl6 = """
let v : integer = UInt('010'::Rv);
let n : integer = UInt('0'::Zn::'0');
let index : integer = UInt(i3h::i3l);
"""
    for line in asl_to_cpp(asl6.strip(), {'Rv': 3, 'Zn': 5, 'i3h': 2, 'i3l': 1}):
        print(line)
