// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifndef VEDA64_NO_IR

#include "ir_internal.hpp"

namespace veda64::ir {

// ============================================================================
// Field extractors
// ============================================================================

static uint32_t extract_field(uint32_t insn, FieldId f) {
    switch (f) {
    case FieldId::Rd:    return insn & 0x1F;
    case FieldId::Rn:    return (insn >> 5) & 0x1F;
    case FieldId::Rm:    return (insn >> 16) & 0x1F;
    case FieldId::Ra:    return (insn >> 10) & 0x1F;
    case FieldId::Imm12: return (insn >> 10) & 0xFFF;
    case FieldId::Imm16: return (insn >> 5) & 0xFFFF;
    case FieldId::Imm26: return insn & 0x3FFFFFF;
    case FieldId::Imm19: return (insn >> 5) & 0x7FFFF;
    case FieldId::Imm14: return (insn >> 5) & 0x3FFF;
    case FieldId::Imm9:  return (insn >> 12) & 0x1FF;
    case FieldId::Sf:    return (insn >> 31) & 1;
    case FieldId::Shift: return (insn >> 22) & 3;
    case FieldId::Imm6:  return (insn >> 10) & 0x3F;
    case FieldId::Opc:   return (insn >> 29) & 3;
    case FieldId::Op:    return (insn >> 30) & 1;
    case FieldId::S:     return (insn >> 29) & 1;
    case FieldId::Cond:  return (insn >> 12) & 0xF;
    case FieldId::None:  return 0;
    }
    return 0;
}

static uint8_t reg_size(uint32_t insn) {
    return (insn >> 31) & 1 ? 8 : 4;
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

static Lifted interpret_gp_binop(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    uint32_t rm = extract_field(insn, e.src2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
    return l;
}

static Lifted interpret_gp_binop_flags(uint32_t insn, const IrEntry& e) {
    Lifted l = interpret_gp_binop(insn, e);
    auto result = l.ops.back().inputs[0];
    Op fw;
    fw.opcode = Opcode::FLAG_WRITE;
    fw.output = VarNode::flags();
    fw.inputs[0] = result;
    fw.num_inputs = 1;
    l.ops.push_back(fw);
    return l;
}

static Lifted interpret_gp_binop_imm(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    uint32_t imm = extract_field(insn, FieldId::Imm12);
    uint32_t sh = (insn >> 22) & 1;
    if (sh) imm <<= 12;

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op2(e.opcode, t1, t0, VarNode::constant(imm, sz)));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t1));
    return l;
}

static Lifted interpret_gp_binop_imm_flags(uint32_t insn, const IrEntry& e) {
    Lifted l = interpret_gp_binop_imm(insn, e);
    auto result = l.ops[l.ops.size() - 2].output;
    Op fw;
    fw.opcode = Opcode::FLAG_WRITE;
    fw.output = VarNode::flags();
    fw.inputs[0] = result;
    fw.num_inputs = 1;
    l.ops.push_back(fw);
    return l;
}

static Lifted interpret_gp_move_imm(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t imm16 = extract_field(insn, FieldId::Imm16);
    uint32_t hw = (insn >> 21) & 3;
    int64_t val = static_cast<int64_t>(imm16) << (hw * 16);
    if (e.opcode == Opcode::NOT) val = ~val;

    auto t0 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::constant(val, sz)));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t0));
    return l;
}

static Lifted interpret_gp_div(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    uint32_t rm = extract_field(insn, e.src2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
    return l;
}

static Lifted interpret_gp_mul(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    uint32_t rm = extract_field(insn, e.src2);
    uint32_t ra = extract_field(insn, FieldId::Ra);

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

static Lifted interpret_gp_shift(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    uint32_t rm = extract_field(insn, e.src2);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    auto t2 = next_temp(sz);

    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::COPY, t1, VarNode::gpr(rm, sz)));
    l.ops.push_back(make_op2(e.opcode, t2, t0, t1));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t2));
    return l;
}

static Lifted interpret_gp_bitfield(uint32_t insn, const IrEntry& e) {
    (void)e;
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);

    auto t0 = next_temp(sz);
    auto t1 = next_temp(sz);
    l.ops.push_back(make_op(Opcode::COPY, t0, VarNode::gpr(rn, sz)));
    l.ops.push_back(make_op(Opcode::EXTRACT, t1, t0));
    l.ops.push_back(make_op(Opcode::COPY, VarNode::gpr(rd, sz), t1));
    return l;
}

static Lifted interpret_load_reg(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = 1 << ((insn >> 30) & 3);
    uint32_t rd = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    int32_t imm = static_cast<int32_t>(extract_field(insn, FieldId::Imm12)) * sz;

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

static Lifted interpret_store_reg(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = 1 << ((insn >> 30) & 3);
    uint32_t rt = extract_field(insn, e.dst);
    uint32_t rn = extract_field(insn, e.src1);
    int32_t imm = static_cast<int32_t>(extract_field(insn, FieldId::Imm12)) * sz;

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

static Lifted interpret_load_pair(uint32_t insn, const IrEntry& e) {
    (void)e;
    Lifted l;
    uint8_t sz = ((insn >> 31) & 1) ? 8 : 4;
    uint32_t rt1 = extract_field(insn, FieldId::Rd);
    uint32_t rt2 = extract_field(insn, FieldId::Ra); // Rt2 is at bits [14:10]
    uint32_t rn = extract_field(insn, FieldId::Rn);
    int32_t imm7 = static_cast<int32_t>((insn >> 15) & 0x7F);
    if (imm7 & 0x40) imm7 |= ~0x7F; // sign-extend
    imm7 *= sz;

    auto taddr = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm7, 8)));

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

static Lifted interpret_store_pair(uint32_t insn, const IrEntry& e) {
    (void)e;
    Lifted l;
    uint8_t sz = ((insn >> 31) & 1) ? 8 : 4;
    uint32_t rt1 = extract_field(insn, FieldId::Rd);
    uint32_t rt2 = extract_field(insn, FieldId::Ra);
    uint32_t rn = extract_field(insn, FieldId::Rn);
    int32_t imm7 = static_cast<int32_t>((insn >> 15) & 0x7F);
    if (imm7 & 0x40) imm7 |= ~0x7F;
    imm7 *= sz;

    auto taddr = next_temp(8);
    l.ops.push_back(make_op2(Opcode::ADD, taddr,
        VarNode::gpr(rn, 8), VarNode::constant(imm7, 8)));

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

static Lifted interpret_branch_uncond(uint32_t insn, const IrEntry& e) {
    Lifted l;
    int32_t imm26 = static_cast<int32_t>(extract_field(insn, FieldId::Imm26));
    if (imm26 & (1 << 25)) imm26 |= ~((1 << 26) - 1);
    int64_t offset = static_cast<int64_t>(imm26) << 2;

    Op o;
    o.opcode = e.opcode; // BRANCH or CALL
    o.inputs[0] = VarNode::constant(offset, 8);
    o.num_inputs = 1;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_branch_cond(uint32_t insn, const IrEntry&) {
    Lifted l;
    int32_t imm19 = static_cast<int32_t>(extract_field(insn, FieldId::Imm19));
    if (imm19 & (1 << 18)) imm19 |= ~((1 << 19) - 1);
    int64_t offset = static_cast<int64_t>(imm19) << 2;
    uint32_t cond = insn & 0xF;

    auto tcond = next_temp(1);
    l.ops.push_back(make_op(Opcode::FLAG_READ, tcond, VarNode::constant(cond, 1)));

    Op o;
    o.opcode = Opcode::CBRANCH;
    o.inputs[0] = tcond;
    o.inputs[1] = VarNode::constant(offset, 8);
    o.num_inputs = 2;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_branch_reg(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rn = extract_field(insn, e.src1);

    auto taddr = next_temp(8);
    l.ops.push_back(make_op(Opcode::COPY, taddr, VarNode::gpr(rn, 8)));

    Op o;
    o.opcode = e.opcode;
    o.inputs[0] = taddr;
    o.num_inputs = 1;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_compare_branch(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rt = extract_field(insn, FieldId::Rd);
    int32_t imm19 = static_cast<int32_t>(extract_field(insn, FieldId::Imm19));
    if (imm19 & (1 << 18)) imm19 |= ~((1 << 19) - 1);
    int64_t offset = static_cast<int64_t>(imm19) << 2;

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

static Lifted interpret_test_branch(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rt = extract_field(insn, FieldId::Rd);
    uint32_t b5 = (insn >> 31) & 1;
    uint32_t b40 = (insn >> 19) & 0x1F;
    uint32_t bit_pos = (b5 << 5) | b40;
    int32_t imm14 = static_cast<int32_t>(extract_field(insn, FieldId::Imm14));
    if (imm14 & (1 << 13)) imm14 |= ~((1 << 14) - 1);
    int64_t offset = static_cast<int64_t>(imm14) << 2;

    uint8_t sz = b5 ? 8 : 4;
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

static Lifted interpret_cond_select(uint32_t insn, const IrEntry& e) {
    (void)e;
    Lifted l;
    uint8_t sz = reg_size(insn);
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);
    uint32_t rm = extract_field(insn, FieldId::Rm);
    uint32_t cond = extract_field(insn, FieldId::Cond);

    auto tcond = next_temp(1);
    l.ops.push_back(make_op(Opcode::FLAG_READ, tcond, VarNode::constant(cond, 1)));

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

static void simd_arrangement(uint32_t insn, uint8_t& esize_bytes, uint8_t& num_elems) {
    uint32_t Q = (insn >> 30) & 1;
    uint32_t size = (insn >> 22) & 3;
    esize_bytes = 1 << size;
    num_elems = (Q ? 16 : 8) / esize_bytes;
}

static Lifted interpret_simd_binop(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);
    uint32_t rm = extract_field(insn, FieldId::Rm);

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

    // Element-level loop unrolling
    uint8_t esize = 0, num_elems = 0;
    simd_arrangement(insn, esize, num_elems);
    uint8_t vec_size = ((insn >> 30) & 1) ? 16 : 8;

    // Bitwise ops (AND/OR/XOR/NOT) always operate on bytes regardless of size field
    bool is_bitwise = (e.opcode == Opcode::AND || e.opcode == Opcode::OR ||
                       e.opcode == Opcode::XOR || e.opcode == Opcode::NOT);
    if (is_bitwise) {
        esize = 1;
        num_elems = vec_size;
    }

    // FP SIMD ops use bit 22 as sz (0=single/4B, 1=double/8B), not standard size field
    bool is_float = (e.opcode == Opcode::FADD || e.opcode == Opcode::FSUB ||
                     e.opcode == Opcode::FMUL || e.opcode == Opcode::FDIV);
    if (is_float) {
        esize = ((insn >> 22) & 1) ? 8 : 4;
        num_elems = vec_size / esize;
    }

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

static Lifted interpret_simd_unary(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);

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

    // Element-level loop unrolling
    uint8_t esize = 0, num_elems = 0;
    simd_arrangement(insn, esize, num_elems);
    uint8_t vec_size = ((insn >> 30) & 1) ? 16 : 8;

    // Bitwise ops always operate on bytes regardless of size field
    if (e.opcode == Opcode::NOT) {
        esize = 1;
        num_elems = vec_size;
    }

    // FP SIMD unary ops use bit 22 as sz (0=single/4B, 1=double/8B)
    bool is_float = (e.opcode == Opcode::FNEG || e.opcode == Opcode::FABS ||
                     e.opcode == Opcode::FSQRT);
    if (is_float) {
        esize = ((insn >> 22) & 1) ? 8 : 4;
        num_elems = vec_size / esize;
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

static Lifted interpret_fp_binop(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);
    uint32_t rm = extract_field(insn, FieldId::Rm);
    // FP type from bits [23:22]: 00=S, 01=D, 11=H
    uint32_t ftype = (insn >> 22) & 3;
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

static Lifted interpret_fp_convert(uint32_t insn, const IrEntry& e) {
    Lifted l;
    uint32_t rd = extract_field(insn, FieldId::Rd);
    uint32_t rn = extract_field(insn, FieldId::Rn);

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

static Lifted interpret_nop(uint32_t, const IrEntry&) {
    Lifted l;
    Op o;
    o.opcode = Opcode::NOP;
    o.num_inputs = 0;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_system(uint32_t, const IrEntry&) {
    Lifted l;
    Op o;
    o.opcode = Opcode::UNDEF;
    o.num_inputs = 0;
    l.ops.push_back(o);
    return l;
}

static Lifted interpret_atomic(uint32_t, const IrEntry&) {
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

using Interpreter = Lifted(*)(uint32_t insn, const IrEntry& e);

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

std::optional<Lifted> lift_from_table(uint32_t insn) {
    temp_idx = 0;

    for (size_t i = 0; i < ir_table_size; ++i) {
        const auto& e = ir_table[i];
        if ((insn & e.mask) == e.match) {
            auto interp = get_interpreter(e.tpl);
            if (interp) return interp(insn, e);
            return std::nullopt;
        }
    }
    return std::nullopt;
}

} // namespace veda64::ir

#endif // !VEDA64_NO_IR
