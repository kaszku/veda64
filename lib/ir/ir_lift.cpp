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

static uint32_t op_reg(const Instruction& insn, int idx) {
    return register_num(insn.operands[idx].r.reg);
}

static uint8_t op_reg_sz(const Instruction& insn, int idx) {
    auto r = insn.operands[idx].r.reg;
    // GP: W regs (0-32) = 4 bytes, X regs (33-65) = 8 bytes
    auto v = static_cast<uint16_t>(r);
    if (v <= 65) return (v >= 33) ? 8 : 4;
    return 8; // default for other reg types
}

static int64_t op_imm(const Instruction& insn, int idx) {
    auto& op = insn.operands[idx];
    if (op.type == OperandType::SignedImmediate || op.type == OperandType::Label)
        return op.si.offset;
    if (op.type == OperandType::Relative)
        return static_cast<int64_t>(op.iv.value);
    return static_cast<int64_t>(op.iv.value);
}

static int64_t op_mem_offset(const Instruction& insn, int idx) {
    return insn.operands[idx].mem.offset;
}

static uint32_t op_mem_base(const Instruction& insn, int idx) {
    return register_num(static_cast<Register>(insn.operands[idx].mem.base));
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

static uint16_t temp_idx;

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

// GP binary: Rd, Rn, Rm [, shift]
static Lifted interpret_gp_binop(const Instruction& insn, const IrEntry& e, IrDetail) {
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
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
    return l;
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
    Lifted l = interpret_gp_binop(insn, e, detail);
    // The last op is COPY result -> gpr(rd). The input is the temp holding the result.
    auto result = l.ops.back().inputs[0];
    // a and b are the inputs to the binop (3rd from last op)
    auto& binop = l.ops[l.ops.size() - 2];
    auto a = binop.inputs[0];
    auto b = binop.inputs[1];
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, result, a, b, is_sub, detail);
    return l;
}

// GP binary immediate: Rd, Rn, #imm [, shift]
static Lifted interpret_gp_binop_imm(const Instruction& insn, const IrEntry& e, IrDetail) {
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rd = op_reg(insn, 0);
    uint32_t rn = op_reg(insn, 1);
    int64_t imm = op_imm(insn, 2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op2(e.opcode, t1, t0, VarNode::constant(imm, sz)));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t1));
    return l;
}

static Lifted interpret_gp_binop_imm_flags(const Instruction& insn, const IrEntry& e, IrDetail detail) {
    Lifted l = interpret_gp_binop_imm(insn, e, detail);
    // Last op is COPY result -> gpr(rd). Second-to-last is the binop.
    auto result = l.ops[l.ops.size() - 2].output;
    auto& binop = l.ops[l.ops.size() - 2];
    auto a = binop.inputs[0];
    auto b = binop.inputs[1];
    bool is_sub = (e.opcode == Opcode::SUB);
    emit_flags(l, result, a, b, is_sub, detail);
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
    int64_t val = static_cast<int64_t>(imm16) << (hw * 16);
    if (e.opcode == Opcode::NOT) val = ~val;

    auto t0 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::constant(val, sz)));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t0));
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
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
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
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), tres));
    } else if (e.extra == 1) {
        auto ta = next_temp(sz);
        auto tres = next_temp(sz);
        l.ops.push_back(make_op(Opcode::COPY, ta, VarNode::gpr(ra, sz)));
        l.ops.push_back(make_op2(Opcode::SUB, tres, ta, tmul));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), tres));
    } else {
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), tmul));
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
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
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
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t1));
    return l;
}

// Load: Rt, [Xn, #off]
static Lifted interpret_load_reg(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    // Size from raw bits [31:30]
    uint8_t sz = 1 << ((insn.raw_value >> 30) & 3);
    uint32_t rd = op_reg(insn, 0);
    // Operand 1 is Memory
    uint32_t rn = op_mem_base(insn, 1);
    int64_t imm = op_mem_offset(insn, 1);

    auto taddr = next_temp(8);
    auto tval = next_temp(sz);

    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm, 8)));
    l.ops.push_back(make_op(Opcode::LOAD, tval, taddr));
    if (sz < 8) {
        auto text = next_temp(8);
        l.ops.push_back(make_op(Opcode::ZEXT, text, tval));
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, 8), text));
    } else {
        l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, 8), tval));
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
    int64_t imm = op_mem_offset(insn, 1);

    auto taddr = next_temp(8);
    auto tval = next_temp(sz);

    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm, 8)));
    l.ops.push_back(make_op(Opcode::COPY, tval, VarNode::gpr(rt, sz)));
    l.ops.push_back(make_op(Opcode::STORE, VarNode::ram(sz), taddr));
    l.ops[l.ops.size()-1].inputs[1] = tval;
    l.ops[l.ops.size()-1].num_inputs = 2;
    return l;
}

// Load pair: Rt1, Rt2, [Xn, #off]
static Lifted interpret_load_pair(const Instruction& insn, const IrEntry& e, IrDetail) {
    (void)e;
    Lifted l;
    uint8_t sz = op_reg_sz(insn, 0);
    uint32_t rt1 = op_reg(insn, 0);
    uint32_t rt2 = op_reg(insn, 1);
    // Operand 2 is Memory
    uint32_t rn = op_mem_base(insn, 2);
    int64_t imm = op_mem_offset(insn, 2);

    auto taddr = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm, 8)));

    auto tv1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::LOAD, tv1, taddr));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt1, sz), tv1));

    auto taddr2 = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr2, taddr, VarNode::constant(sz, 8)));
    auto tv2 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::LOAD, tv2, taddr2));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rt2, sz), tv2));
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
    int64_t imm = op_mem_offset(insn, 2);

    auto taddr = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm, 8)));

    auto tv1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, tv1, VarNode::gpr(rt1, sz)));
    l.ops.push_back(make_op(Opcode::STORE, VarNode::ram(sz), taddr));
    l.ops[l.ops.size()-1].inputs[1] = tv1;
    l.ops[l.ops.size()-1].num_inputs = 2;

    auto taddr2 = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr2, taddr, VarNode::constant(sz, 8)));
    auto tv2 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, tv2, VarNode::gpr(rt2, sz)));
    l.ops.push_back(make_op(Opcode::STORE, VarNode::ram(sz), taddr2));
    l.ops[l.ops.size()-1].inputs[1] = tv2;
    l.ops[l.ops.size()-1].num_inputs = 2;
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

    Op o;
    o.opcode = Opcode::COPY;
    o.output = VarNode::gpr(rd, sz);
    o.inputs[0] = VarNode::gpr(rn, sz);
    o.inputs[1] = VarNode::gpr(rm, sz);
    o.inputs[2] = tcond;
    o.num_inputs = 3;
    l.ops.push_back(o);
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
        e.opcode == Opcode::ZEXT || e.opcode == Opcode::FLOAT2FLOAT) {
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

static Lifted interpret_system(const Instruction&, const IrEntry&, IrDetail) {
    Lifted l;
    Op o;
    o.opcode = Opcode::UNDEF;
    o.num_inputs = 0;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_atomic(const Instruction&, const IrEntry&, IrDetail) {
    Lifted l;
    Op o;
    o.opcode = Opcode::UNDEF;
    o.num_inputs = 0;
    l.ops.push_back(o);
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
    }
    return nullptr;
}

std::optional<Lifted> lift_from_instruction(const Instruction& insn, IrDetail detail) {
    temp_idx = 0;

    if (insn.encoding_id == 0xFFFF || insn.encoding_id >= ir_table_size)
        return std::nullopt;

    const auto& e = ir_table[insn.encoding_id];
    if (e.tpl == IrTemplate::None_)
        return std::nullopt;  // unclassified encoding

    auto interp = get_interpreter(e.tpl);
    if (interp) return interp(insn, e, detail);
    return std::nullopt;
}

} // namespace veda64::ir

#endif // VEDA64_IR
