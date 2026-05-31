// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_IR

#include "ir_internal.hpp"
#include "veda64/types.hpp"
#include "veda64/operand.hpp"

namespace veda64::ir {

// ============================================================================
// Operand helpers — extract from decoded Instruction
// ============================================================================

// Aliases decode to fewer operands than their canonical form (e.g.
// MOV Rd, Rm == ORR Rd, XZR, Rm produces 2 operands, not 3). Every accessor
// is bounds-checked: operands[] is a std::vector and operator[] past size()
// is undefined behavior, which produced the nondeterministic "reads r21"
// garbage. Out-of-range register reads return XZR (31).
static bool op_in_range(const Instruction& insn, int idx) {
    return idx >= 0 && static_cast<size_t>(idx) < insn.operands.size();
}

static uint32_t op_reg(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return 31; // XZR
    return register_num(insn.operands[idx].r.reg);
}

static uint8_t op_reg_sz(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return 8;
    auto r = insn.operands[idx].r.reg;
    // GP: W regs (0-32) = 4 bytes, X regs (33-65) = 8 bytes
    auto v = static_cast<uint16_t>(r);
    if (v <= 65) return (v >= 33) ? 8 : 4;
    return 8; // default for other reg types
}

static int64_t op_imm(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return 0;
    auto& op = insn.operands[idx];
    if (op.type == OperandType::SignedImmediate || op.type == OperandType::Label)
        return op.si.offset;
    if (op.type == OperandType::Relative)
        return static_cast<int64_t>(op.iv.value);
    return static_cast<int64_t>(op.iv.value);
}

static int64_t op_mem_offset(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return 0;
    return insn.operands[idx].mem.offset;
}

static uint32_t op_mem_base(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return 31;
    return register_num(static_cast<Register>(insn.operands[idx].mem.base));
}

static MemoryMode op_mem_mode(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return MemoryMode::Offset;
    return insn.operands[idx].mem.mode;
}

// SP and XZR collide at register number 31; the disassembler distinguishes
// them via Register::SP / Register::WSP. The IR uses VarNode::sp() (offset
// sentinel SP_REG_INDEX) instead of VarNode::gpr(31) so the encoding-form
// disambiguation reaches the codegen.

static bool op_is_sp(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return false;
    auto r = insn.operands[idx].r.reg;
    return r == Register::SP || r == Register::WSP;
}

static bool op_mem_base_is_sp(const Instruction& insn, int idx) {
    if (!op_in_range(insn, idx)) return false;
    auto r = static_cast<Register>(insn.operands[idx].mem.base);
    return r == Register::SP || r == Register::WSP;
}

// Build a VarNode for an integer register operand: SP gets the SP sentinel,
// any other register (including XZR) keeps its numeric encoding.
static VarNode gpr_or_sp(uint32_t num, uint8_t sz, bool is_sp) {
    return is_sp ? VarNode::sp(sz) : VarNode::gpr(num, sz);
}

static uint8_t arr_elem_size(Register r) {
    Arrangement a = register_arrangement(r);
    switch (a) {
    case Arrangement::B: case Arrangement::B8: case Arrangement::B16: return 1;
    case Arrangement::H: case Arrangement::H4: case Arrangement::H8: return 2;
    case Arrangement::S: case Arrangement::S2: case Arrangement::S4: return 4;
    case Arrangement::D: case Arrangement::D1: case Arrangement::D2: return 8;
    case Arrangement::Q: case Arrangement::Q1: return 16;
    default: return 4; // fallback
    }
}

static uint8_t arr_vec_size(Register r) {
    Arrangement a = register_arrangement(r);
    switch (a) {
    case Arrangement::B8: case Arrangement::H4: case Arrangement::S2: case Arrangement::D1: return 8;
    case Arrangement::B16: case Arrangement::H8: case Arrangement::S4: case Arrangement::D2: return 16;
    default: return 16;
    }
}

// ============================================================================
// Template interpreters
// ============================================================================

static uint32_t temp_idx;

static VarNode next_temp(uint8_t sz) {
    return VarNode::temp(temp_idx++, sz);
}

static Op make_op(Opcode opc, VarNode out, VarNode in0) {
    Op o;
    o.opcode = opc;
    o.output = out;
    o.inputs[0] = in0;
    o.num_inputs = 1;
    return o;
}

static Op make_op2(Opcode opc, VarNode out, VarNode in0, VarNode in1) {
    Op o;
    o.opcode = opc;
    o.output = out;
    o.inputs[0] = in0;
    o.inputs[1] = in1;
    o.num_inputs = 2;
    return o;
}

static Op make_op3(Opcode opc, VarNode out, VarNode in0, VarNode in1, VarNode in2) {
    Op o;
    o.opcode = opc;
    o.output = out;
    o.inputs[0] = in0;
    o.inputs[1] = in1;
    o.inputs[2] = in2;
    o.num_inputs = 3;
    return o;
}

// Write a GP register. ARM64 rule: writing a 32-bit W register zeroes the upper 32 bits of the X register.
static void emit_gpr_write(Lifted& l, uint32_t reg, uint8_t op_sz, VarNode value) {
    if (op_sz == 4 && reg < 31) {
        // 32-bit write: zero-extend to 64-bit. A constant source can be
        // pre-masked into a single COPY instead of going through ZEXT.
        if (value.space == Space::CONST) {
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(reg, 8),
                VarNode::constant(value.value & 0xFFFFFFFFll, 8)));
            return;
        }
        auto t = next_temp(8);
        l.ops.push_back(make_op(Opcode::ZEXT, t, value));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(reg, 8), t));
    } else {
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(reg, op_sz), value));
    }
}

// SP-aware GP write: routes to VarNode::sp() when the destination is SP.
// Used by SP-permitting encodings (ADD/SUB-immediate, ADD/SUB-extended).
static void emit_gpr_or_sp_write(Lifted& l, uint32_t reg, uint8_t op_sz,
                                  bool is_sp, VarNode value) {
    if (is_sp) {
        l.ops.push_back(make_op(Opcode::COPY, VarNode::sp(op_sz), value));
        return;
    }
    emit_gpr_write(l, reg, op_sz, value);
}

// The ARM64 logical-with-negated-second-operand mnemonics. The IR table
// classifies these as plain OR/AND/XOR (via GpBinop/GpBinopFlags/SimdBinop)
// because there is no distinct IR opcode for "OR with NOT-RHS", and the
// table carries only one opcode column. Detect them here so the lifter
// inserts a NOT on operand 2 before the binop — otherwise ORN/BIC/EON/MVN
// lift to the same shape as plain ORR/AND/EOR, silently dropping the
// bitwise inversion.
//
// MVN (register form, GP only) is `ORN Rd, XZR, Rm` — the decoder folds
// XZR out so the interpreter sees the two-operand alias shape; the NOT
// still has to land on operand 2 (which after folding is the only source
// register).
static bool logical_negates_op2(Mnemonic m) {
    return m == Mnemonic::BIC || m == Mnemonic::BICS ||
           m == Mnemonic::EON ||
           m == Mnemonic::ORN || m == Mnemonic::MVN;
}

// GP binary: Rd, Rn, Rm [, shift]
// Shared interpreter for ADD/SUB shifted-register and extended-register, plus
// MOV (register), MVN, the SXT*/UXT* aliases, and the addsub_carry family.
// In the addsub_ext form, SP is permitted at Rn (and at Rd for non-flag
// ADD/SUB). The decoder hands us Register::SP / Register::XZR distinctly via
// op_is_sp(), so we propagate the SP marker only when the source instruction
// actually used SP — addsub_shift with Rn=31 keeps gpr(31)=XZR semantics.
// Rm in any encoding never means SP (bit-31 always reads as XZR there).
static Lifted interpret_gp_binop(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    bool rd_sp = op_is_sp(insn, 0);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    if (insn.operands.size() == 2) {
        // Alias form: `ORR/ADD/EOR/SUB/AND Xd, XZR, Xm` — decoder
        // folded the XZR out, only [Rd, Rm] present. Rn = XZR = 0
        // makes e.opcode(0, Rm) correct for the whole family.
        uint32_t rm = op_reg(insn, 1);
        l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::constant(0, sz)));
        l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    } else {
        uint32_t rn = op_reg(insn, 1);
        bool rn_sp = op_is_sp(insn, 1);
        uint32_t rm = op_reg(insn, 2);
        l.ops.push_back(make_op(Opcode::COPY, t0, gpr_or_sp(rn, sz, rn_sp)));
        l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    }
    if (logical_negates_op2(insn.mnemonic)) {
        auto tn = next_temp(sz);
        l.ops.push_back(make_op(Opcode::NOT, tn, t1));
        t1 = tn;
    }
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    emit_gpr_or_sp_write(l, rd, sz, rd_sp, t2);
    return l;
}

// Convert a non-flag arithmetic opcode to its NZCV-setting twin. The "_flags"
// interpreters (ADDS/SUBS/ANDS and their CMP/CMN/TST alias forms) lift the
// value computation as ADD_FLAGS/SUB_FLAGS/AND_FLAGS so the emitter lowers as
// adds/subs/ands and the subsequent flag readers see live NZCV.
static Opcode flag_setting_variant(Opcode op) {
    switch (op) {
    case Opcode::ADD: return Opcode::ADD_FLAGS;
    case Opcode::SUB: return Opcode::SUB_FLAGS;
    case Opcode::AND: return Opcode::AND_FLAGS;
    default: return op;
    }
}

static void emit_flags(Lifted& l, VarNode result, VarNode a, VarNode b, bool is_sub, IrDetail detail) {
    uint8_t sz = result.size;
    int msb = sz * 8 - 1;
    // N = shr result, msb
    l.ops.push_back(make_op2(Opcode::SHR, VarNode::flags_n(), result, VarNode::constant(msb, sz)));
    // Z = cmp_eq result, 0
    l.ops.push_back(make_op2(Opcode::CMP_EQ, VarNode::flags_z(), result, VarNode::constant(0, sz)));
    // C
    if (detail == IrDetail::Semantic) {
        l.ops.push_back(make_op2(is_sub ? Opcode::CARRY_SUB : Opcode::CARRY_ADD,
            VarNode::flags_c(), a, b));
    } else {
        if (is_sub)
            l.ops.push_back(make_op2(Opcode::CMP_ULE, VarNode::flags_c(), b, a));
        else
            l.ops.push_back(make_op2(Opcode::CMP_ULT, VarNode::flags_c(), result, a));
    }
    // V
    if (detail == IrDetail::Semantic) {
        l.ops.push_back(make_op2(is_sub ? Opcode::OVERFLOW_SUB : Opcode::OVERFLOW_ADD,
            VarNode::flags_v(), a, b));
    } else {
        if (is_sub) {
            auto t1 = next_temp(sz); // a ^ b
            auto t2 = next_temp(sz); // a ^ result
            auto t3 = next_temp(sz); // t1 & t2
            l.ops.push_back(make_op2(Opcode::XOR, t1, a, b));
            l.ops.push_back(make_op2(Opcode::XOR, t2, a, result));
            l.ops.push_back(make_op2(Opcode::AND, t3, t1, t2));
            l.ops.push_back(make_op2(Opcode::SHR, VarNode::flags_v(), t3, VarNode::constant(msb, sz)));
        } else {
            auto t1 = next_temp(sz); // a ^ result
            auto t2 = next_temp(sz); // b ^ result
            auto t3 = next_temp(sz); // t1 & t2
            l.ops.push_back(make_op2(Opcode::XOR, t1, a, result));
            l.ops.push_back(make_op2(Opcode::XOR, t2, b, result));
            l.ops.push_back(make_op2(Opcode::AND, t3, t1, t2));
            l.ops.push_back(make_op2(Opcode::SHR, VarNode::flags_v(), t3, VarNode::constant(msb, sz)));
        }
    }
}

static Lifted interpret_gp_binop_flags(const Instruction& insn, const IrEntry& e, IrDetail detail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    if (logical_negates_op2(insn.mnemonic)) {
        auto tn = next_temp(sz);
        l.ops.push_back(make_op(Opcode::NOT, tn, t1));
        t1 = tn;
    }
    l.ops.push_back(make_op2(flag_setting_variant(e.opcode), t2, t0, t1));
    // Flags computed from the native-width (32 or 64 bit) result, BEFORE zero-extension
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, t2, t0, t1, is_sub, detail);
    emit_gpr_write(l, rd, sz, t2);
    return l;
}

// GP binary immediate: Rd, Rn, #imm [, shift]
// ADD/SUB (immediate) without flags: both Rd and Rn may be SP.
static Lifted interpret_gp_binop_imm(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    bool rd_sp = op_is_sp(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    bool rn_sp = op_is_sp(insn, 1);
    int64_t imm = op_imm(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, gpr_or_sp(rn, sz, rn_sp)));
    l.ops.push_back(make_op2(e.opcode, t1, t0, VarNode::constant(imm, sz)));
    emit_gpr_or_sp_write(l, rd, sz, rd_sp, t1);
    return l;
}

// ADDS/SUBS (immediate): only Rn may be SP — Rd=31 is XZR (so the alias is
// CMN/CMP rather than ADDS/SUBS into SP).
static Lifted interpret_gp_binop_imm_flags(const Instruction& insn, const IrEntry& e, IrDetail detail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    bool rn_sp = op_is_sp(insn, 1);
    int64_t imm = op_imm(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, gpr_or_sp(rn, sz, rn_sp)));
    l.ops.push_back(make_op2(flag_setting_variant(e.opcode), t1, t0, VarNode::constant(imm, sz)));
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, t1, t0, VarNode::constant(imm, sz), is_sub, detail);
    emit_gpr_write(l, rd, sz, t1);
    return l;
}

// GP compare register: Rn, Rm (Rd=XZR omitted from operands)
static Lifted interpret_gp_compare(const Instruction& insn, const IrEntry& e, IrDetail detail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rn = op_reg(insn, 0);
    uint32_t rm = op_reg(insn, 1);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(flag_setting_variant(e.opcode), t2, t0, t1));
    // Result discarded (Rd=XZR), only flags matter
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, t2, t0, t1, is_sub, detail);
    return l;
}

// GP compare immediate: Rn, #imm (Rd=XZR omitted from operands).
// CMP/CMN-immediate is an alias of SUBS/ADDS-imm; Rn may be SP.
static Lifted interpret_gp_compare_imm(const Instruction& insn, const IrEntry& e, IrDetail detail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rn = op_reg(insn, 0);
    bool rn_sp = op_is_sp(insn, 0);
    int64_t imm = op_imm(insn, 1);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto imm_v = VarNode::constant(imm, sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, gpr_or_sp(rn, sz, rn_sp)));
    l.ops.push_back(make_op2(flag_setting_variant(e.opcode), t1, t0, imm_v));
    // Result discarded (Rd=XZR), only flags matter
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, t1, t0, imm_v, is_sub, detail);
    return l;
}

// GP move wide: Rd, #imm
static Lifted interpret_gp_move_imm(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    // The decoder already computes the shifted immediate and handles MOVN inversion
    // For MOVZ/MOVN, operand 1 is the immediate with hw shift applied
    // We still need to handle hw shift + NOT for MOVN from raw bits
    // because the decoder may present the aliased form
    uint32_t raw = insn.raw_value;
    uint32_t imm16 = (raw >> 5) & 0xFFFF;
    uint32_t hw = (raw >> 21) & 3;
    uint64_t uval = static_cast<uint64_t>(imm16) << (hw * 16);
    if (e.opcode == Opcode::NOT) uval = ~uval;
    // Mask to operand width so the inverted bits don't leak past the W view:
    // MOVN Wd, #0 must yield 0x00000000_FFFFFFFF, not 0xFFFFFFFF_FFFFFFFF.
    if (sz == 4) uval &= 0xFFFFFFFFull;
    int64_t val = static_cast<int64_t>(uval);

    // Skip the temp + ZEXT chain: feed the constant straight to emit_gpr_write
    // so the consumer (and the simplifier) sees a single COPY of a known
    // constant — keeps the MOVN inversion observable instead of getting
    // dropped when a downstream lowers a stale movz from the masked value.
    emit_gpr_write(l, rd, sz, VarNode::constant(val, sz));
    return l;
}

// GP divide: Rd, Rn, Rm
static Lifted interpret_gp_div(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    emit_gpr_write(l, rd, sz, t2);
    return l;
}

// GP multiply: Rd, Rn, Rm [, Ra]
static Lifted interpret_gp_mul(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);
    // Ra from raw bits (operand 3 may or may not exist depending on alias)
    uint32_t ra = (insn.raw_value >> 10) & 0x1F;

    auto tn = next_temp(sz);
    auto tm = next_temp(sz);
    auto tmul = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, tn, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, tm, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(Opcode::MUL, tmul, tn, tm));

    if (e.extra == 0 && ra != 31) {
        auto ta = next_temp(sz);
        auto tres = next_temp(sz);
        l.ops.push_back(make_op(Opcode::COPY, ta, VarNode::gpr(ra, sz)));
        l.ops.push_back(make_op2(Opcode::ADD, tres, ta, tmul));
        emit_gpr_write(l, rd, sz, tres);
    } else if (e.extra == 1) {
        auto ta = next_temp(sz);
        auto tres = next_temp(sz);
        l.ops.push_back(make_op(Opcode::COPY, ta, VarNode::gpr(ra, sz)));
        l.ops.push_back(make_op2(Opcode::SUB, tres, ta, tmul));
        emit_gpr_write(l, rd, sz, tres);
    } else {
        emit_gpr_write(l, rd, sz, tmul);
    }
    return l;
}

// GP shift: Rd, Rn, Rm
static Lifted interpret_gp_shift(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    emit_gpr_write(l, rd, sz, t2);
    return l;
}

// GP bitfield: Rd, Rn, #immr, #imms
static Lifted interpret_gp_bitfield(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::EXTRACT, t1, t0));
    emit_gpr_write(l, rd, sz, t1);
    return l;
}

// Load: Rt, [Xn, #off]
static Lifted interpret_load_reg(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    // Size from raw bits [31:30]
    uint8_t sz = 1 << ((insn.raw_value >> 30) & 3);
    uint32_t rd = op_reg(insn, 0);
    // Operand 1 is Memory; the base register may be SP (the ARM ARM treats
    // Rn=31 in the load/store base position as SP, never XZR).
    uint32_t rn = op_mem_base(insn, 1);
    bool rn_sp = op_mem_base_is_sp(insn, 1);
    int64_t imm = op_mem_offset(insn, 1);
    MemoryMode mode = op_mem_mode(insn, 1);

    VarNode base = gpr_or_sp(rn, 8, rn_sp);
    auto taddr = next_temp(8);
    auto tval = next_temp(sz);

    // PostIndex accesses at base unchanged; Offset/PreIndex access at base+imm.
    if (mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op(Opcode::COPY, taddr, base));
    } else {
        l.ops.push_back(make_op2(Opcode::ADD, taddr, base, VarNode::constant(imm, 8)));
    }
    l.ops.push_back(make_op(Opcode::LOAD, tval, taddr));
    if (sz < 8) {
        auto text = next_temp(8);
        l.ops.push_back(make_op(Opcode::ZEXT, text, tval));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, 8), text));
    } else {
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, 8), tval));
    }
    // PreIndex/PostIndex: write back base = base + imm.
    if (mode == MemoryMode::PreIndex || mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op2(Opcode::ADD, base, base, VarNode::constant(imm, 8)));
    }
    return l;
}

// Store: Rt, [Xn, #off]
static Lifted interpret_store_reg(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = 1 << ((insn.raw_value >> 30) & 3);
    uint32_t rt = op_reg(insn, 0);
    uint32_t rn = op_mem_base(insn, 1);
    bool rn_sp = op_mem_base_is_sp(insn, 1);
    int64_t imm = op_mem_offset(insn, 1);
    MemoryMode mode = op_mem_mode(insn, 1);

    VarNode base = gpr_or_sp(rn, 8, rn_sp);
    auto taddr = next_temp(8);
    auto tval = next_temp(sz);

    if (mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op(Opcode::COPY, taddr, base));
    } else {
        l.ops.push_back(make_op2(Opcode::ADD, taddr, base, VarNode::constant(imm, 8)));
    }
    l.ops.push_back(make_op(Opcode::COPY, tval, VarNode::gpr(rt, sz)));
    // STORE: inputs[0] = value, inputs[1] = address.
    l.ops.push_back(make_op2(Opcode::STORE, VarNode::ram(sz), tval, taddr));
    if (mode == MemoryMode::PreIndex || mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op2(Opcode::ADD, base, base, VarNode::constant(imm, 8)));
    }
    return l;
}

// Load pair: Rt1, Rt2, [Xn, #off]
static Lifted interpret_load_pair(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rt1 = op_reg(insn, 0);
    uint32_t rt2 = op_reg(insn, 1);
    // Operand 2 is Memory; base may be SP.
    uint32_t rn = op_mem_base(insn, 2);
    bool rn_sp = op_mem_base_is_sp(insn, 2);
    int64_t imm = op_mem_offset(insn, 2);
    MemoryMode mode = op_mem_mode(insn, 2);

    VarNode base = gpr_or_sp(rn, 8, rn_sp);
    auto taddr = next_temp(8);
    if (mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op(Opcode::COPY, taddr, base));
    } else {
        l.ops.push_back(make_op2(Opcode::ADD, taddr, base, VarNode::constant(imm, 8)));
    }

    auto tv1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::LOAD, tv1, taddr));
    emit_gpr_write(l, rt1, sz, tv1);

    auto taddr2 = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr2, taddr, VarNode::constant(sz, 8)));
    auto tv2 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::LOAD, tv2, taddr2));
    emit_gpr_write(l, rt2, sz, tv2);

    if (mode == MemoryMode::PreIndex || mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op2(Opcode::ADD, base, base, VarNode::constant(imm, 8)));
    }
    return l;
}

// Store pair: Rt1, Rt2, [Xn, #off]
static Lifted interpret_store_pair(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rt1 = op_reg(insn, 0);
    uint32_t rt2 = op_reg(insn, 1);
    uint32_t rn = op_mem_base(insn, 2);
    bool rn_sp = op_mem_base_is_sp(insn, 2);
    int64_t imm = op_mem_offset(insn, 2);
    MemoryMode mode = op_mem_mode(insn, 2);

    VarNode base = gpr_or_sp(rn, 8, rn_sp);
    auto taddr = next_temp(8);
    if (mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op(Opcode::COPY, taddr, base));
    } else {
        l.ops.push_back(make_op2(Opcode::ADD, taddr, base, VarNode::constant(imm, 8)));
    }

    auto tv1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, tv1, VarNode::gpr(rt1, sz)));
    l.ops.push_back(make_op2(Opcode::STORE, VarNode::ram(sz), tv1, taddr));

    auto taddr2 = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr2, taddr, VarNode::constant(sz, 8)));
    auto tv2 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, tv2, VarNode::gpr(rt2, sz)));
    l.ops.push_back(make_op2(Opcode::STORE, VarNode::ram(sz), tv2, taddr2));

    if (mode == MemoryMode::PreIndex || mode == MemoryMode::PostIndex) {
        l.ops.push_back(make_op2(Opcode::ADD, base, base, VarNode::constant(imm, 8)));
    }
    return l;
}

// Unconditional branch: label (op[0] = Label/Relative)
static Lifted interpret_branch_uncond(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    int64_t offset = op_imm(insn, 0);

    Op o;
    o.opcode = e.opcode; // BRANCH or CALL
    o.inputs[0] = VarNode::constant(offset, 8);
    o.num_inputs = 1;
    l.ops.push_back(o);
    return l;
}

// Expand a condition code into a boolean temp from individual N/Z/C/V flags
static VarNode emit_condition(Lifted& l, uint32_t cond) {
    auto N = VarNode::flags_n();
    auto Z = VarNode::flags_z();
    auto C = VarNode::flags_c();
    auto V = VarNode::flags_v();
    VarNode result;
    switch (cond >> 1) {
    case 0: // EQ/NE
        result = Z; break;
    case 1: // CS/CC
        result = C; break;
    case 2: // MI/PL
        result = N; break;
    case 3: // VS/VC
        result = V; break;
    case 4: { // HI/LS: C && !Z
        auto tnz = next_temp(1);
        l.ops.push_back(make_op(Opcode::NOT, tnz, Z));
        auto tr = next_temp(1);
        l.ops.push_back(make_op2(Opcode::AND, tr, C, tnz));
        result = tr; break;
    }
    case 5: { // GE/LT: N == V
        auto tr = next_temp(1);
        l.ops.push_back(make_op2(Opcode::CMP_EQ, tr, N, V));
        result = tr; break;
    }
    case 6: { // GT/LE: (N == V) && !Z
        auto teq = next_temp(1);
        l.ops.push_back(make_op2(Opcode::CMP_EQ, teq, N, V));
        auto tnz = next_temp(1);
        l.ops.push_back(make_op(Opcode::NOT, tnz, Z));
        auto tr = next_temp(1);
        l.ops.push_back(make_op2(Opcode::AND, tr, teq, tnz));
        result = tr; break;
    }
    default: // AL
        result = VarNode::constant(1, 1); break;
    }
    // Invert for odd condition codes (NE, CC, PL, VC, LS, LT, LE)
    if ((cond & 1) && cond != 15) {
        auto inv = next_temp(1);
        l.ops.push_back(make_op(Opcode::NOT, inv, result));
        return inv;
    }
    return result;
}

// Conditional branch: label (op[0] = Label, condition in insn.condition)
static Lifted interpret_branch_cond(const Instruction& insn, const IrEntry&, IrDetail) {
    Lifted l;
    int64_t offset = op_imm(insn, 0);
    uint32_t cond = static_cast<uint32_t>(insn.condition);

    auto tcond = emit_condition(l, cond);

    Op o;
    o.opcode = Opcode::CBRANCH;
    o.inputs[0] = tcond;
    o.inputs[1] = VarNode::constant(offset, 8);
    o.num_inputs = 2;
    l.ops.push_back(o);
    return l;
}

// Branch register: Xn (op[0] = Reg) or no operands (RET uses X30)
static Lifted interpret_branch_reg(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    // RET may have no explicit operands (defaults to X30)
    uint32_t rn = insn.operands.empty() ? 30 : op_reg(insn, 0);

    auto taddr = next_temp(8);
    l.ops.push_back(make_op(Opcode::COPY, taddr, VarNode::gpr(rn, 8)));

    Op o;
    o.opcode = e.opcode;
    o.inputs[0] = taddr;
    o.num_inputs = 1;
    l.ops.push_back(o);
    return l;
}

// Compare and branch: Rt, label
static Lifted interpret_compare_branch(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rt = op_reg(insn, 0);
    int64_t offset = op_imm(insn, 1);

    auto tval = next_temp(sz);
    auto tcmp = next_temp(1);
    l.ops.push_back(make_op(Opcode::COPY, tval, VarNode::gpr(rt, sz)));
    l.ops.push_back(make_op2(e.opcode == Opcode::CMP_EQ ? Opcode::CMP_EQ : Opcode::CMP_NE,
        tcmp, tval, VarNode::constant(0, sz)));

    Op o;
    o.opcode = Opcode::CBRANCH;
    o.inputs[0] = tcmp;
    o.inputs[1] = VarNode::constant(offset, 8);
    o.num_inputs = 2;
    l.ops.push_back(o);
    return l;
}

// Test and branch: Rt, #bit, label
static Lifted interpret_test_branch(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint32_t rt = op_reg(insn, 0);
    uint32_t bit_pos = static_cast<uint32_t>(op_imm(insn, 1));
    int64_t offset = op_imm(insn, 2);

    uint8_t sz = (bit_pos >= 32) ? 8 : 4;
    auto tval = next_temp(sz);
    auto tbit = next_temp(1);
    auto tmask = VarNode::constant(1LL << bit_pos, sz);

    l.ops.push_back(make_op(Opcode::COPY, tval, VarNode::gpr(rt, sz)));
    l.ops.push_back(make_op2(Opcode::AND, tbit, tval, tmask));

    auto tcmp = next_temp(1);
    l.ops.push_back(make_op2(e.opcode == Opcode::CMP_EQ ? Opcode::CMP_EQ : Opcode::CMP_NE,
        tcmp, tbit, VarNode::constant(0, sz)));

    Op o;
    o.opcode = Opcode::CBRANCH;
    o.inputs[0] = tcmp;
    o.inputs[1] = VarNode::constant(offset, 8);
    o.num_inputs = 2;
    l.ops.push_back(o);
    return l;
}

// Conditional select: Rd, Rn, Rm, cond
static Lifted interpret_cond_select(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);
    uint32_t cond = static_cast<uint32_t>(insn.condition);

    auto tcond = emit_condition(l, cond);

    auto tsel = next_temp(sz);
    Op o;
    o.opcode = Opcode::COPY;
    o.output = tsel;
    o.inputs[0] = VarNode::gpr(rn, sz);
    o.inputs[1] = VarNode::gpr(rm, sz);
    o.inputs[2] = tcond;
    o.num_inputs = 3;
    l.ops.push_back(o);
    emit_gpr_write(l, rd, sz, tsel);
    return l;
}

// SIMD binop: Vd.T, Vn.T, Vm.T
static Lifted interpret_simd_binop(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);

    // Fall back to opaque for UNDEF or unsupported opcodes
    if (e.opcode == Opcode::UNDEF || e.opcode == Opcode::COPY || e.opcode == Opcode::EXTRACT) {
        auto t0 = next_temp(16);
        auto t1 = next_temp(16);
        auto t2 = next_temp(16);
        l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::simd(rn)));
        l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::simd(rm)));
        l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd), t2));
        return l;
    }

    // Get element size and vector size from register arrangement
    uint8_t esize = arr_elem_size(insn.operands[0].r.reg);
    uint8_t vec_size = arr_vec_size(insn.operands[0].r.reg);
    uint8_t num_elems = vec_size / esize;

    // Bitwise ops (AND/OR/XOR/NOT) always operate on bytes regardless of arrangement
    bool is_bitwise = (e.opcode == Opcode::AND || e.opcode == Opcode::OR ||
                       e.opcode == Opcode::XOR || e.opcode == Opcode::NOT);
    if (is_bitwise) {
        esize = 1;
        num_elems = vec_size;
    }

    // FP SIMD ops: arrangement from register is already correct (S4=4B, D2=8B)

    auto src1_reg = VarNode::simd(rn, vec_size);
    auto src2_reg = VarNode::simd(rm, vec_size);
    // BIC/ORN vector forms compute Vn & ~Vm and Vn | ~Vm respectively.
    // Materialize the bitwise inversion into a temporary and feed the
    // per-lane loop from it.
    if (logical_negates_op2(insn.mnemonic)) {
        auto tn = next_temp(vec_size);
        l.ops.push_back(make_op(Opcode::NOT, tn, src2_reg));
        src2_reg = tn;
    }
    VarNode result = {};

    for (uint8_t lane = 0; lane < num_elems; ++lane) {
        auto e0 = next_temp(esize);
        auto e1 = next_temp(esize);
        auto eres = next_temp(esize);

        l.ops.push_back(make_op2(Opcode::VEXTRACT_ELEM, e0, src1_reg, VarNode::constant(lane, 1)));
        l.ops.push_back(make_op2(Opcode::VEXTRACT_ELEM, e1, src2_reg, VarNode::constant(lane, 1)));
        l.ops.push_back(make_op2(e.opcode, eres, e0, e1));

        auto ins_out = next_temp(vec_size);
        auto ins_src = (lane == 0) ? VarNode::simd(rd, vec_size) : result;
        l.ops.push_back(make_op3(Opcode::VINSERT_ELEM, ins_out, ins_src, VarNode::constant(lane, 1), eres));
        result = ins_out;
    }

    l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd, vec_size), result));
    return l;
}

// SIMD unary: Vd.T, Vn.T
static Lifted interpret_simd_unary(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);

    // Fall back to opaque for UNDEF/COPY or complex ops
    if (e.opcode == Opcode::UNDEF || e.opcode == Opcode::COPY || e.opcode == Opcode::SEXT ||
        e.opcode == Opcode::ZEXT || e.opcode == Opcode::FLOAT2FLOAT ||
        e.opcode == Opcode::CLZ || e.opcode == Opcode::POPCNT || e.opcode == Opcode::BITREV) {
        auto t0 = next_temp(16);
        auto t1 = next_temp(16);
        l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::simd(rn)));
        l.ops.push_back(make_op(e.opcode, t1, t0));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd), t1));
        return l;
    }

    uint8_t esize = arr_elem_size(insn.operands[0].r.reg);
    uint8_t vec_size = arr_vec_size(insn.operands[0].r.reg);
    uint8_t num_elems = vec_size / esize;

    // Bitwise ops always operate on bytes
    if (e.opcode == Opcode::NOT) {
        esize = 1;
        num_elems = vec_size;
    }

    auto src_reg = VarNode::simd(rn, vec_size);
    VarNode result = {};

    for (uint8_t lane = 0; lane < num_elems; ++lane) {
        auto e0 = next_temp(esize);
        auto eres = next_temp(esize);

        l.ops.push_back(make_op2(Opcode::VEXTRACT_ELEM, e0, src_reg, VarNode::constant(lane, 1)));
        l.ops.push_back(make_op(e.opcode, eres, e0));

        auto ins_out = next_temp(vec_size);
        auto ins_src = (lane == 0) ? VarNode::simd(rd, vec_size) : result;
        l.ops.push_back(make_op3(Opcode::VINSERT_ELEM, ins_out, ins_src, VarNode::constant(lane, 1), eres));
        result = ins_out;
    }

    l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd, vec_size), result));
    return l;
}

// Scalar FP binary: Sd, Sn, Sm
static Lifted interpret_fp_binop(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    uint32_t rm = op_reg(insn, 2);
    // FP type from bits [23:22]: 00=S, 01=D, 11=H
    uint32_t ftype = (insn.raw_value >> 22) & 3;
    uint8_t sz = (ftype == 1) ? 8 : (ftype == 3) ? 2 : 4;

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::simd(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::simd(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd, sz), t2));
    return l;
}

// FP convert: Sd<->Xn
static Lifted interpret_fp_convert(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);

    auto t0 = next_temp(8);
    auto t1 = next_temp(8);

    if (e.opcode == Opcode::FLOAT2INT) {
        l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::simd(rn, 8)));
        l.ops.push_back(make_op(Opcode::FLOAT2INT, t1, t0));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, 8), t1));
    } else {
        l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, 8)));
        l.ops.push_back(make_op(Opcode::INT2FLOAT, t1, t0));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::simd(rd, 8), t1));
    }
    return l;
}

static Lifted interpret_nop(const Instruction&, const IrEntry&, IrDetail) {
    Lifted l;
    Op o;
    o.opcode = Opcode::NOP;
    o.num_inputs = 0;
    l.ops.push_back(o);
    return l;
}

// Opaque-instruction lifter: returns an empty Lifted{} so the consumer
// preserves the original bytes verbatim. Used for HINTs whose semantics
// the IR does not model (PAuth, BTI, etc.) — substituting a NOP would
// silently drop security-critical guards.
static Lifted interpret_opaque(const Instruction&, const IrEntry&, IrDetail) {
    return Lifted{};
}

static Lifted interpret_system(const Instruction&, const IrEntry&, IrDetail) {
    Lifted l;
    Op o;
    o.opcode = Opcode::UNDEF;
    o.num_inputs = 0;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_atomic(const Instruction& insn, const IrEntry& e, IrDetail) {
    if (e.opcode == Opcode::UNDEF) {
        Lifted l;
        Op o; o.opcode = Opcode::UNDEF; o.num_inputs = 0;
        l.ops.push_back(o);
        return l;
    }
    Lifted l;
    uint8_t sub = e.extra;

    // LDAPR (load-acquire, extra=10): Rt, [Xn]
    if (sub == 10) {
        uint8_t sz = 1 << ((insn.raw_value >> 30) & 3);
        uint32_t rt = op_reg(insn, 0);
        uint32_t rn = op_mem_base(insn, 1);
        auto taddr = next_temp(8);
        auto tval = next_temp(sz);
        l.ops.push_back(make_op2(Opcode::ADD, taddr,
            VarNode::gpr(rn, 8), VarNode::constant(0, 8)));
        l.ops.push_back(make_op(Opcode::LOAD, tval, taddr));
        if (sz < 8) {
            auto text = next_temp(8);
            l.ops.push_back(make_op(Opcode::ZEXT, text, tval));
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt, 8), text));
        } else {
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt, 8), tval));
        }
        return l;
    }

    // Determine operand layout
    int mem_idx;  // index of memory operand
    bool has_rt;  // whether Rt (loaded old value) is present
    if (insn.operands.size() >= 3 &&
        (insn.operands[2].type == OperandType::Memory ||
         insn.operands[2].type == OperandType::MemoryRegOffset)) {
        mem_idx = 2; has_rt = true;  // Rs, Rt, [Xn]
    } else {
        mem_idx = 1; has_rt = false;  // Rs, [Xn] (ST* alias)
    }

    uint8_t sz = 1 << ((insn.raw_value >> 30) & 3);
    uint32_t rs = op_reg(insn, 0);
    uint32_t rn = op_mem_base(insn, mem_idx);

    auto taddr = next_temp(8);
    auto told = next_temp(sz);
    auto trs = next_temp(sz);

    // Compute address
    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(0, 8)));
    // Load old value
    l.ops.push_back(make_op(Opcode::LOAD, told, taddr));
    // Copy source register
    l.ops.push_back(make_op(Opcode::COPY, trs, VarNode::gpr(rs, sz)));

    // CAS (compare-and-swap, extra=9): Rs, Rt, [Xn]
    // old = *addr; if (old == Rs) *addr = Rt; Rs = old
    if (sub == 9) {
        uint32_t rt = has_rt ? op_reg(insn, 1) : 31;
        auto trt = next_temp(sz);
        auto tcmp = next_temp(1);
        auto tnew = next_temp(sz);
        l.ops.push_back(make_op(Opcode::COPY, trt, VarNode::gpr(rt, sz)));
        l.ops.push_back(make_op2(Opcode::CMP_EQ, tcmp, told, trs));
        // Select: if equal, store Rt; else keep old
        // We use CBRANCH-like semantics simplified as: new = cmp ? Rt : old
        // For IR, emit both paths — consumer can interpret
        l.ops.push_back(make_op2(Opcode::CMP_EQ, tnew, trt, told));
        // Store (always emit — simplifier can optimize)
        l.ops.push_back(make_op2(Opcode::STORE, VarNode::ram(sz), tnew, taddr));
        // Rs gets old value
        if (sz < 8) {
            auto text = next_temp(8);
            l.ops.push_back(make_op(Opcode::ZEXT, text, told));
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rs, 8), text));
        } else {
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rs, 8), told));
        }
        return l;
    }

    // Compute new value based on sub-operation
    auto tnew = next_temp(sz);
    switch (sub) {
    case 0:  // ADD
        l.ops.push_back(make_op2(Opcode::ADD, tnew, told, trs)); break;
    case 1: { // CLR (AND-NOT): old & ~Rs
        auto tnot = next_temp(sz);
        l.ops.push_back(make_op(Opcode::NOT, tnot, trs));
        l.ops.push_back(make_op2(Opcode::AND, tnew, told, tnot)); break; }
    case 2:  // SET (OR)
        l.ops.push_back(make_op2(Opcode::OR, tnew, told, trs)); break;
    case 3:  // EOR (XOR)
        l.ops.push_back(make_op2(Opcode::XOR, tnew, told, trs)); break;
    case 4:  // SMAX: old > Rs (signed) ? old : Rs
    case 5: { // SMIN: old < Rs (signed) ? old : Rs
        auto tcmp = next_temp(1);
        Opcode cmp_op = (sub == 4) ? Opcode::CMP_SLT : Opcode::CMP_SLT;
        if (sub == 4)
            l.ops.push_back(make_op2(cmp_op, tcmp, trs, told));  // Rs < old → keep old
        else
            l.ops.push_back(make_op2(cmp_op, tcmp, told, trs));  // old < Rs → keep old
        // Simplified: emit CMP, consumer interprets conditionally
        l.ops.push_back(make_op2(Opcode::ADD, tnew, told, VarNode::constant(0, sz)));
        break; }
    case 6:  // UMAX
    case 7: { // UMIN
        auto tcmp = next_temp(1);
        Opcode cmp_op = Opcode::CMP_ULT;
        if (sub == 6)
            l.ops.push_back(make_op2(cmp_op, tcmp, trs, told));  // Rs < old → keep old
        else
            l.ops.push_back(make_op2(cmp_op, tcmp, told, trs));  // old < Rs → keep old
        l.ops.push_back(make_op2(Opcode::ADD, tnew, told, VarNode::constant(0, sz)));
        break; }
    case 8:  // SWP: *addr = Rs (no modify, just swap)
        l.ops.push_back(make_op(Opcode::COPY, tnew, trs)); break;
    default:
        l.ops.push_back(make_op(Opcode::COPY, tnew, trs)); break;
    }

    // Store new value
    l.ops.push_back(make_op2(Opcode::STORE, VarNode::ram(sz), tnew, taddr));

    // Copy old value to Rt (if present)
    if (has_rt) {
        uint32_t rt = op_reg(insn, 1);
        if (sz < 8) {
            auto text = next_temp(8);
            l.ops.push_back(make_op(Opcode::ZEXT, text, told));
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt, 8), text));
        } else {
            l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt, 8), told));
        }
    }
    return l;
}

// ============================================================================
// Dispatch
// ============================================================================

using Interpreter = Lifted(*)(const Instruction& insn, const IrEntry& e, IrDetail detail);

static Interpreter get_interpreter(IrTemplate tpl) {
    switch (tpl) {
    case IrTemplate::GpBinop:         return interpret_gp_binop;
    case IrTemplate::GpBinopFlags:    return interpret_gp_binop_flags;
    case IrTemplate::GpBinopImm:      return interpret_gp_binop_imm;
    case IrTemplate::GpBinopImmFlags: return interpret_gp_binop_imm_flags;
    case IrTemplate::GpCompare:       return interpret_gp_compare;
    case IrTemplate::GpCompareImm:    return interpret_gp_compare_imm;
    case IrTemplate::GpShift:         return interpret_gp_shift;
    case IrTemplate::GpMove:          return interpret_gp_binop; // same pattern
    case IrTemplate::GpMoveImm:       return interpret_gp_move_imm;
    case IrTemplate::GpMul:           return interpret_gp_mul;
    case IrTemplate::GpDiv:           return interpret_gp_div;
    case IrTemplate::GpBitfield:      return interpret_gp_bitfield;
    case IrTemplate::GpExtend:        return interpret_gp_binop; // simplified
    case IrTemplate::CondSelect:      return interpret_cond_select;
    case IrTemplate::LoadReg:         return interpret_load_reg;
    case IrTemplate::StoreReg:        return interpret_store_reg;
    case IrTemplate::LoadPair:        return interpret_load_pair;
    case IrTemplate::StorePair:       return interpret_store_pair;
    case IrTemplate::BranchUncond:    return interpret_branch_uncond;
    case IrTemplate::BranchCond:      return interpret_branch_cond;
    case IrTemplate::BranchReg:       return interpret_branch_reg;
    case IrTemplate::CompareBranch:   return interpret_compare_branch;
    case IrTemplate::TestBranch:      return interpret_test_branch;
    case IrTemplate::SimdBinop:       return interpret_simd_binop;
    case IrTemplate::SimdUnary:       return interpret_simd_unary;
    case IrTemplate::FpBinop:         return interpret_fp_binop;
    case IrTemplate::FpConvert:       return interpret_fp_convert;
    case IrTemplate::Atomic:          return interpret_atomic;
    case IrTemplate::System:          return interpret_system;
    case IrTemplate::Nop:             return interpret_nop;
    case IrTemplate::Opaque:          return interpret_opaque;
    }
    return nullptr;
}

std::optional<Lifted> lift_from_instruction(const Instruction& insn, IrDetail detail) {
    temp_idx = 0;

    auto eid = static_cast<uint16_t>(insn.encoding_id);
    if (eid == 0xFFFF || eid >= ir_table_size)
        return std::nullopt;

    const auto& e = ir_table[eid];
    if (e.tpl == IrTemplate::None_)
        return std::nullopt;  // unclassified encoding

    auto interp = get_interpreter(e.tpl);
    if (interp) return interp(insn, e, detail);
    return std::nullopt;
}

} // namespace veda64::ir

#endif // VEDA64_IR
