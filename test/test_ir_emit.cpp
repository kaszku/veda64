// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski

#if defined(VEDA64_IR) && defined(VEDA64_CODEGEN)

#include <veda64/ir_emit.hpp>
#include <veda64.hpp>
#include <codegen/codegen.hpp>
#include <iostream>
#include <cassert>
#include <cstring>

using namespace veda64;
using namespace veda64::ir;
using namespace veda64::codegen;

static uint32_t insn_at(const CodeGenerator& cg, size_t idx) {
    uint32_t v;
    std::memcpy(&v, cg.data() + idx * 4, 4);
    return v;
}

// Simple identity context: GPR(n) → x(n), Temp(n) → x(9 + n % 7).
// SP sentinel (offset == VarNode::SP_REG_INDEX) maps to codegen::sp.
static EmitContext make_ctx() {
    EmitContext ctx;
    ctx.resolve = [](const VarNode& v) -> XReg {
        if (v.space == Space::TEMP) return XReg{9 + (v.offset % 7)};
        if (v.space == Space::GPR && v.offset == VarNode::SP_REG_INDEX) return codegen::sp;
        return XReg{static_cast<uint8_t>(v.offset)};
    };
    return ctx;
}

static Op mk(Opcode oc, VarNode out) {
    Op o;
    o.opcode = oc;
    o.output = out;
    o.num_inputs = 0;
    return o;
}
static Op mk1(Opcode oc, VarNode out, VarNode a) {
    auto o = mk(oc, out);
    o.inputs[0] = a; o.num_inputs = 1;
    return o;
}
static Op mk2(Opcode oc, VarNode out, VarNode a, VarNode b) {
    auto o = mk1(oc, out, a);
    o.inputs[1] = b; o.num_inputs = 2;
    return o;
}

static int test_arith() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk2(Opcode::ADD, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    auto r = decode(insn_at(cg, 0));
    assert(r && r->mnemonic == Mnemonic::ADD);

    CodeGenerator cg2(4096);
    assert(emit(mk2(Opcode::SUB, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg2, ctx));
    r = decode(insn_at(cg2, 0));
    assert(r && r->mnemonic == Mnemonic::SUB);

    CodeGenerator cg3(4096);
    assert(emit(mk2(Opcode::MUL, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg3, ctx));
    r = decode(insn_at(cg3, 0));
    assert(r && r->mnemonic == Mnemonic::MUL);

    CodeGenerator cg4(4096);
    assert(emit(mk1(Opcode::NEG, VarNode::gpr(3), VarNode::gpr(1)), cg4, ctx));
    r = decode(insn_at(cg4, 0));
    assert(r && r->mnemonic == Mnemonic::SUB);  // NEG -> SUB
    std::cout << "  arith: OK" << std::endl;
    return 0;
}

static int test_logical() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk2(Opcode::AND, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    assert(emit(mk2(Opcode::OR,  VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    assert(emit(mk2(Opcode::XOR, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    assert(emit(mk1(Opcode::NOT, VarNode::gpr(3), VarNode::gpr(1)), cg, ctx));
    auto a = decode(insn_at(cg, 0)); assert(a && a->mnemonic == Mnemonic::AND);
    auto b = decode(insn_at(cg, 1)); assert(b && b->mnemonic == Mnemonic::ORR);
    auto c = decode(insn_at(cg, 2)); assert(c && c->mnemonic == Mnemonic::EOR);
    auto d = decode(insn_at(cg, 3)); assert(d && (d->mnemonic == Mnemonic::MVN || d->mnemonic == Mnemonic::ORN));
    std::cout << "  logical: OK" << std::endl;
    return 0;
}

static int test_shifts() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk2(Opcode::SHL, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    assert(emit(mk2(Opcode::SAR, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    auto a = decode(insn_at(cg, 0));
    assert(a && (a->mnemonic == Mnemonic::LSLV || a->mnemonic == Mnemonic::LSL));
    auto b = decode(insn_at(cg, 1));
    assert(b && (b->mnemonic == Mnemonic::ASRV || b->mnemonic == Mnemonic::ASR));
    std::cout << "  shifts: OK" << std::endl;
    return 0;
}

static int test_bitops() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk1(Opcode::CLZ,    VarNode::gpr(3), VarNode::gpr(1)), cg, ctx));
    assert(emit(mk1(Opcode::BITREV, VarNode::gpr(3), VarNode::gpr(1)), cg, ctx));
    auto a = decode(insn_at(cg, 0)); assert(a && a->mnemonic == Mnemonic::CLZ);
    auto b = decode(insn_at(cg, 1)); assert(b && b->mnemonic == Mnemonic::RBIT);
    // POPCNT unsupported on scalar AArch64
    assert(!emit(mk1(Opcode::POPCNT, VarNode::gpr(3), VarNode::gpr(1)), cg, ctx));
    std::cout << "  bitops: OK" << std::endl;
    return 0;
}

static int test_cmp() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk2(Opcode::CMP_EQ, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    auto a = decode(insn_at(cg, 0));
    assert(a && a->mnemonic == Mnemonic::SUBS);  // CMP -> SUBS
    auto b = decode(insn_at(cg, 1));
    assert(b && (b->mnemonic == Mnemonic::CSET || b->mnemonic == Mnemonic::CSINC));
    std::cout << "  cmp: OK" << std::endl;
    return 0;
}

static int test_branches() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    // BRANCH offset 16 → B +16
    assert(emit(mk1(Opcode::BRANCH, VarNode{}, VarNode::constant(16, 8)), cg, ctx));
    assert(emit(mk1(Opcode::CALL,   VarNode{}, VarNode::constant(32, 8)), cg, ctx));
    auto cb = mk2(Opcode::CBRANCH, VarNode{}, VarNode::gpr(5), VarNode::constant(8, 8));
    assert(emit(cb, cg, ctx));
    auto r0 = decode(insn_at(cg, 0)); assert(r0 && r0->mnemonic == Mnemonic::B);
    auto r1 = decode(insn_at(cg, 1)); assert(r1 && r1->mnemonic == Mnemonic::BL);
    auto r2 = decode(insn_at(cg, 2)); assert(r2 && r2->mnemonic == Mnemonic::CBNZ);

    CodeGenerator cg2(4096);
    Op ret; ret.opcode = Opcode::RET; ret.num_inputs = 0;
    assert(emit(ret, cg2, ctx));
    auto rr = decode(insn_at(cg2, 0));
    assert(rr && rr->mnemonic == Mnemonic::RET);
    std::cout << "  branches: OK" << std::endl;
    return 0;
}

static int test_ldst() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    // LOAD: X3 = [X1 + 8]
    auto ld = mk2(Opcode::LOAD, VarNode::gpr(3), VarNode::gpr(1), VarNode::constant(8, 8));
    assert(emit(ld, cg, ctx));
    // STORE: [X1 + 16] = X2
    // Convention: inputs[0] = value (X2), inputs[1] = address (X1), inputs[2] = offset.
    auto st = mk(Opcode::STORE, VarNode{});
    st.inputs[0] = VarNode::gpr(2);
    st.inputs[1] = VarNode::gpr(1);
    st.inputs[2] = VarNode::constant(16, 8);
    st.num_inputs = 3;
    assert(emit(st, cg, ctx));
    auto a = decode(insn_at(cg, 0)); assert(a && a->mnemonic == Mnemonic::LDR);
    auto b = decode(insn_at(cg, 1)); assert(b && b->mnemonic == Mnemonic::STR);
    // Verify operand assignment: STR x2, [x1, #16] (NOT STR x1, [x2, #16]).
    // Rt is at bits [4:0] and the base register is at bits [9:5] of the encoding.
    uint32_t str_insn = insn_at(cg, 1);
    assert((str_insn & 0x1Fu) == 2);          // Rt = x2 (value)
    assert(((str_insn >> 5) & 0x1Fu) == 1);   // Rn = x1 (base)
    std::cout << "  ldst: OK" << std::endl;
    return 0;
}

static int test_flags() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    assert(emit(mk2(Opcode::ADD_CARRY, VarNode::gpr(3), VarNode::gpr(1), VarNode::gpr(2)), cg, ctx));
    assert(emit(mk(Opcode::CARRY_ADD,  VarNode::gpr(3)), cg, ctx));
    auto a = decode(insn_at(cg, 0)); assert(a && a->mnemonic == Mnemonic::ADCS);
    auto b = decode(insn_at(cg, 1));
    assert(b && (b->mnemonic == Mnemonic::CSET || b->mnemonic == Mnemonic::CSINC));
    std::cout << "  flags: OK" << std::endl;
    return 0;
}

static int test_const_materialize() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    // ADD x3, x1, #0x1234 — const in input[1] materializes into scratch0 (x16)
    assert(emit(mk2(Opcode::ADD, VarNode::gpr(3), VarNode::gpr(1),
                    VarNode::constant(0x1234, 8)), cg, ctx));
    // First insn is MOV imm (→ MOVZ or similar), second is ADD.
    auto a = decode(insn_at(cg, 0));
    assert(a && (a->mnemonic == Mnemonic::MOVZ || a->mnemonic == Mnemonic::MOV ||
                 a->mnemonic == Mnemonic::ORR));
    // Last instruction should be the ADD. Walk forward until decode returns ADD.
    bool found_add = false;
    for (size_t i = 0; i < 8; ++i) {
        auto r = decode(insn_at(cg, i));
        if (r && r->mnemonic == Mnemonic::ADD) { found_add = true; break; }
    }
    assert(found_add);
    std::cout << "  const_materialize: OK" << std::endl;
    return 0;
}

static int test_unsupported() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    Op o; o.opcode = Opcode::FADD; o.num_inputs = 0;
    size_t before = cg.size();
    assert(!emit(o, cg, ctx));
    assert(cg.size() == before);
    std::cout << "  unsupported: OK" << std::endl;
    return 0;
}

// IR ADD with VarNode::sp() must lower to ADD (extended register), not the
// shifted-register form that reads bit-31 as XZR.
static int test_sp_marker() {
    auto ctx = make_ctx();
    CodeGenerator cg(4096);
    auto add = mk2(Opcode::ADD, VarNode::gpr(0), VarNode::sp(), VarNode::gpr(17));
    assert(emit(add, cg, ctx));
    uint32_t insn = insn_at(cg, 0);
    auto d = decode(insn);
    assert(d && d->mnemonic == Mnemonic::ADD);
    // Extended register form: bits[23:21] = 001
    assert(((insn >> 21) & 0x7u) == 0b001);
    // option = UXTX (011) for X-reg targeting SP
    assert(((insn >> 13) & 0x7u) == 0b011);
    // Rn = 31 (encoded SP)
    assert(((insn >> 5) & 0x1Fu) == 31);
    std::cout << "  sp marker: OK" << std::endl;
    return 0;
}

// ZEXT / SEXT must be emittable, and a lift→emit round-trip of any
// instruction that writes a W register must succeed (it used to bail
// because ZEXT had no emit case).
static int test_zext_sext() {
    auto ctx = make_ctx();

    // Direct ZEXT op (register source): mov Wd, Wn.
    {
        CodeGenerator cg(4096);
        assert(emit(mk1(Opcode::ZEXT, VarNode::gpr(3), VarNode::gpr(4)), cg, ctx));
        auto d = decode(insn_at(cg, 0));
        assert(d);
        // 32-bit form (sf == 0).
        assert(((insn_at(cg, 0) >> 31) & 1u) == 0);
    }
    // Direct ZEXT op (constant source): mov Wd, #imm.
    {
        CodeGenerator cg(4096);
        assert(emit(mk1(Opcode::ZEXT, VarNode::gpr(3),
                        VarNode::constant(0xFFFFFFFFll, 8)), cg, ctx));
        assert(decode(insn_at(cg, 0)).has_value());
    }
    // Direct SEXT op (register source): sxtw Xd, Wn → SBFM.
    {
        CodeGenerator cg(4096);
        assert(emit(mk1(Opcode::SEXT, VarNode::gpr(3), VarNode::gpr(4)), cg, ctx));
        auto d = decode(insn_at(cg, 0));
        assert(d && (d->mnemonic == Mnemonic::SXTW || d->mnemonic == Mnemonic::SBFM));
    }

    // Round-trip: lift then emit must succeed for W-writing instructions.
    for (uint32_t insn : { 0x52800020u /*mov w0,#1*/, 0x0b020020u /*add w0,w1,w2*/,
                           0xb9400260u /*ldr w0,[x19]*/, 0x2a0103e0u /*mov w0,w1*/ }) {
        auto l = lift(insn);
        assert(l.has_value());
        CodeGenerator cg(4096);
        assert(emit(*l, cg, ctx));
    }
    std::cout << "  zext_sext: OK" << std::endl;
    return 0;
}

// Bug A: emit must dispatch the load/store width off the operand size,
// otherwise a 4-byte load becomes LDR X (8-byte read → page-edge fault).
// Bug B: a constant ALU operand must use an immediate instruction form so
// the scratch register (x16/x17, frequently live) is never materialized.
// Bug C: a 2-operand alias (MOV Rd,Rm == ORR Rd,XZR,Rm) must lift+emit
// without reading past the operand vector.
static int test_size_and_scratch() {
    auto ctx = make_ctx();

    // Bug A — width-correct loads.
    CodeGenerator cgw(4096);
    assert(emit(mk1(Opcode::LOAD, VarNode::gpr(0, 4), VarNode::gpr(19)), cgw, ctx));
    CodeGenerator cgx(4096);
    assert(emit(mk1(Opcode::LOAD, VarNode::gpr(0, 8), VarNode::gpr(19)), cgx, ctx));
    // 4-byte and 8-byte loads must encode differently (LDR W vs LDR X).
    assert(insn_at(cgw, 0) != insn_at(cgx, 0));
    auto lw = decode(insn_at(cgw, 0));
    assert(lw && lw->mnemonic == Mnemonic::LDR);

    // Byte/halfword loads/stores.
    CodeGenerator cgb(4096);
    assert(emit(mk1(Opcode::LOAD, VarNode::gpr(0, 1), VarNode::gpr(19)), cgb, ctx));
    auto lb = decode(insn_at(cgb, 0));
    assert(lb && lb->mnemonic == Mnemonic::LDRB);
    CodeGenerator cgsb(4096);
    Op st = mk2(Opcode::STORE, VarNode::ram(1), VarNode::gpr(2, 1), VarNode::gpr(19));
    assert(emit(st, cgsb, ctx));
    auto sb = decode(insn_at(cgsb, 0));
    assert(sb && sb->mnemonic == Mnemonic::STRB);

    // Bug B — ADD with a constant uses ADD immediate (one instruction, no
    // MOV into the scratch register).
    CodeGenerator cgi(4096);
    assert(emit(mk2(Opcode::ADD, VarNode::gpr(0), VarNode::gpr(1),
                    VarNode::constant(0x10)), cgi, ctx));
    assert(cgi.size() == 4);  // exactly one instruction, scratch untouched
    auto ai = decode(insn_at(cgi, 0));
    assert(ai && ai->mnemonic == Mnemonic::ADD);

    // Bug C — 2-operand alias MOV X0,X2 (== ORR X0,XZR,X2). Lift then emit
    // must succeed without out-of-bounds operand reads.
    auto la = lift(0xAA0203E0u /* mov x0, x2 */);
    assert(la.has_value());
    CodeGenerator cga(4096);
    assert(emit(*la, cga, ctx));

    std::cout << "  size_and_scratch: OK" << std::endl;
    return 0;
}

int main() {
    std::cout << "Running ir_emit tests..." << std::endl;
    int err = 0;
    err |= test_arith();
    err |= test_logical();
    err |= test_shifts();
    err |= test_bitops();
    err |= test_cmp();
    err |= test_branches();
    err |= test_ldst();
    err |= test_flags();
    err |= test_const_materialize();
    err |= test_unsupported();
    err |= test_sp_marker();
    err |= test_zext_sext();
    err |= test_size_and_scratch();
    std::cout << "All ir_emit tests passed!" << std::endl;
    return err;
}

#else // !(VEDA64_IR && VEDA64_CODEGEN)

#include <cstdio>
int main() {
    printf("ir_emit tests skipped (VEDA64_IR or VEDA64_CODEGEN not set)\n");
    return 0;
}

#endif
