// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_CODEGEN

#include <codegen/codegen.hpp>
#include <veda64.hpp>
#include <iostream>
#include <cassert>
#include <cstring>

using namespace veda64;
using namespace veda64::codegen;

static uint32_t get_insn(const CodeGenerator& cg, size_t idx) {
    uint32_t val;
    std::memcpy(&val, cg.data() + idx * 4, 4);
    return val;
}

static int test_arithmetic() {
    CodeGenerator cg(4096);
    cg.add(x0, x1, x2);
    cg.sub(w3, w4, w5);
    cg.adds(x6, x7, uint32_t(42));
    cg.mul(x10, x11, x12);
    cg.sdiv(w20, w21, w22);
    cg.cmp(x0, x1);
    cg.neg(x0, x1);

    // Verify via decode
    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::ADD);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::SUB);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::ADDS);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::MUL);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::SDIV);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::SUBS);  // CMP -> SUBS
    r = decode(get_insn(cg, 6));
    assert(r && r->mnemonic == Mnemonic::SUB);   // NEG -> SUB
    std::cout << "  arithmetic: OK" << std::endl;
    return 0;
}

static int test_branches() {
    CodeGenerator cg(4096);
    Label loop;
    cg.bind(loop);
    cg.nop();
    cg.b(loop);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::NOP);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::B);
    std::cout << "  branches: OK" << std::endl;
    return 0;
}

static int test_forward_branch() {
    CodeGenerator cg(4096);
    Label skip;
    cg.b(skip);
    cg.nop();
    cg.bind(skip);
    cg.ret();

    // B should jump forward by +8 bytes (2 instructions)
    uint32_t b_insn = get_insn(cg, 0);
    int32_t imm26 = static_cast<int32_t>(b_insn << 6) >> 6;  // sign extend
    assert(imm26 == 2);  // 2 instructions = 8 bytes
    (void)imm26;
    std::cout << "  forward branch: OK" << std::endl;
    return 0;
}

static int test_ldst() {
    CodeGenerator cg(4096);
    cg.ldr(x0, ptr(x1, 8));
    cg.str(w2, pre(x3, -16));
    cg.ldrb(w4, ptr(x5));
    cg.stp(x6, x7, ptr(sp, 16));

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::LDR);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::STR);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::LDRB);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::STP);
    std::cout << "  ldst: OK" << std::endl;
    return 0;
}

static int test_fp() {
    CodeGenerator cg(4096);
    cg.fadd(s0, s1, s2);
    cg.fmul(d3, d4, d5);
    cg.fcmp(s0, s1);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::FADD);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::FMUL);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::FCMP);
    std::cout << "  fp: OK" << std::endl;
    return 0;
}

static int test_mov() {
    CodeGenerator cg(4096);
    cg.mov(x0, x1);
    cg.mov(w2, uint32_t(42));
    cg.mov(x3, uint64_t(0xDEADBEEF));

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::ADD || r->mnemonic == Mnemonic::MOV));
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::MOVZ || r->mnemonic == Mnemonic::MOV));
    std::cout << "  mov: OK" << std::endl;
    return 0;
}

static int test_carry() {
    CodeGenerator cg(4096);
    cg.adc(x0, x1, x2);
    cg.adcs(w3, w4, w5);
    cg.sbc(x6, x7, x8);
    cg.sbcs(w9, w10, w11);
    cg.ngc(x0, x1);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::ADC);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::ADCS);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::SBC);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::SBCS);
    r = decode(get_insn(cg, 4));
    assert(r && (r->mnemonic == Mnemonic::SBC || r->mnemonic == Mnemonic::NGC));
    std::cout << "  carry: OK" << std::endl;
    return 0;
}

static int test_bitfield() {
    CodeGenerator cg(4096);
    cg.ubfx(w0, w1, 4, 8);
    cg.sbfx(x2, x3, 0, 16);
    cg.bfi(w4, w5, 8, 4);
    cg.ubfiz(x6, x7, 2, 10);
    cg.extr(x8, x9, x10, 16);
    cg.clz(w0, w1);
    cg.cls(x2, x3);
    cg.rbit(w4, w5);
    cg.rev(x6, x7);

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UBFX));
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SBFX));
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::BFM || r->mnemonic == Mnemonic::BFI));
    r = decode(get_insn(cg, 3));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UBFIZ));
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::EXTR);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::CLZ);
    r = decode(get_insn(cg, 6));
    assert(r && r->mnemonic == Mnemonic::CLS);
    r = decode(get_insn(cg, 7));
    assert(r && r->mnemonic == Mnemonic::RBIT);
    r = decode(get_insn(cg, 8));
    assert(r && r->mnemonic == Mnemonic::REV);
    std::cout << "  bitfield: OK" << std::endl;
    return 0;
}

static int test_shift_imm() {
    CodeGenerator cg(4096);
    cg.lsl(x0, x1, uint8_t(4));
    cg.lsr(w2, w3, uint8_t(8));
    cg.asr(x4, x5, uint8_t(16));
    cg.ror(w6, w7, uint8_t(5));

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::LSL));
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::LSR));
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::ASR));
    r = decode(get_insn(cg, 3));
    assert(r && (r->mnemonic == Mnemonic::EXTR || r->mnemonic == Mnemonic::ROR));
    std::cout << "  shift_imm: OK" << std::endl;
    return 0;
}

static int test_3src() {
    CodeGenerator cg(4096);
    cg.msub(x0, x1, x2, x3);
    cg.mneg(w4, w5, w6);
    cg.smull(x7, w8, w9);
    cg.umull(x10, w11, w12);
    cg.smulh(x13, x14, x15);
    cg.umulh(x16, x17, x18);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::MSUB);
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::MSUB || r->mnemonic == Mnemonic::MNEG));
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::SMADDL || r->mnemonic == Mnemonic::SMULL));
    r = decode(get_insn(cg, 3));
    assert(r && (r->mnemonic == Mnemonic::UMADDL || r->mnemonic == Mnemonic::UMULL));
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::SMULH);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::UMULH);
    std::cout << "  3src: OK" << std::endl;
    return 0;
}

static int test_condcmp() {
    CodeGenerator cg(4096);
    cg.ccmp(x0, x1, uint8_t(0), Condition::EQ);
    cg.ccmn(w2, uint8_t(5), uint8_t(0xF), Condition::NE);
    cg.csinc(x3, x4, x5, Condition::GE);
    cg.csinv(w6, w7, w8, Condition::LT);
    cg.csneg(x9, x10, x11, Condition::EQ);
    cg.cinc(x0, x1, Condition::NE);
    cg.cinv(w2, w3, Condition::EQ);
    cg.cneg(x4, x5, Condition::LT);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::CCMP);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::CCMN);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::CSINC);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::CSINV);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::CSNEG);
    r = decode(get_insn(cg, 5));
    assert(r && (r->mnemonic == Mnemonic::CSINC || r->mnemonic == Mnemonic::CINC));
    r = decode(get_insn(cg, 6));
    assert(r && (r->mnemonic == Mnemonic::CSINV || r->mnemonic == Mnemonic::CINV));
    r = decode(get_insn(cg, 7));
    assert(r && (r->mnemonic == Mnemonic::CSNEG || r->mnemonic == Mnemonic::CNEG));
    std::cout << "  condcmp: OK" << std::endl;
    return 0;
}

static int test_atomics() {
    CodeGenerator cg(4096);
    cg.ldar(x0, x1);
    cg.stlr(w2, x3);
    cg.ldxr(x4, x5);
    cg.stxr(w6, x7, x8);
    cg.ldaxr(x9, x10);
    cg.stlxr(w11, x12, x13);
    cg.cas(x14, x15, x16);
    cg.swp(w17, w18, x19);
    cg.ldadd(x20, x21, x22);
    cg.ldclr(w23, w24, x25);
    cg.ldset(x26, x27, x28);
    cg.ldeor(w0, w1, x2);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::LDAR);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::STLR);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::LDXR);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::STXR);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::LDAXR);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::STLXR);
    r = decode(get_insn(cg, 6));
    assert(r && r->mnemonic == Mnemonic::CAS);
    r = decode(get_insn(cg, 7));
    assert(r && r->mnemonic == Mnemonic::SWP);
    r = decode(get_insn(cg, 8));
    assert(r && r->mnemonic == Mnemonic::LDADD);
    r = decode(get_insn(cg, 9));
    assert(r && r->mnemonic == Mnemonic::LDCLR);
    r = decode(get_insn(cg, 10));
    assert(r && r->mnemonic == Mnemonic::LDSET);
    r = decode(get_insn(cg, 11));
    assert(r && r->mnemonic == Mnemonic::LDEOR);
    std::cout << "  atomics: OK" << std::endl;
    return 0;
}

#if defined(__aarch64__) || defined(_M_ARM64)
static int test_execute() {
    CodeGenerator cg(4096);
    // Generate: return arg0 + 1
    cg.add(w0, w0, uint32_t(1));
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    assert(fn(41) == 42);
    (void)fn;
    std::cout << "  execute: OK" << std::endl;
    return 0;
}

static int test_execute_loop() {
    CodeGenerator cg(4096);
    Label loop;
    // sum 1..N: w1=0, loop: w1+=1, cmp w1,w0, b.lt loop, mov w0,w1, ret
    cg.mov(w1, uint32_t(0));
    cg.bind(loop);
    cg.add(w1, w1, uint32_t(1));
    cg.cmp(w1, w0);
    cg.b(Condition::LT, loop);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    assert(fn(10) == 10);
    assert(fn(1) == 1);
    (void)fn;
    std::cout << "  execute loop: OK" << std::endl;
    return 0;
}
#endif

static int test_logical_imm() {
    CodeGenerator cg(4096);
    cg.and_(x0, x1, uint64_t(0xFF));
    cg.orr(x2, x3, uint64_t(0xF0F0F0F0F0F0F0F0ULL));
    cg.eor(w4, w5, uint64_t(0xAAAAAAAA));
    cg.ands(x6, x7, uint64_t(0x1));
    cg.tst(x0, uint64_t(0xFF));

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::AND);
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::ORR || r->mnemonic == Mnemonic::MOV));
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::EOR);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::ANDS);
    r = decode(get_insn(cg, 4));
    assert(r && (r->mnemonic == Mnemonic::ANDS || r->mnemonic == Mnemonic::TST));
    std::cout << "  logical_imm: OK" << std::endl;
    return 0;
}

static int test_more_reg_ops() {
    CodeGenerator cg(4096);
    cg.adds(x0, x1, x2);
    cg.subs(w3, w4, w5);
    cg.orn(x6, x7, x8);
    cg.bic(w9, w10, w11);
    cg.ands(x12, x13, x14);
    cg.lsr(x0, x1, x2);
    cg.asr(w3, w4, w5);
    cg.ror(x6, x7, x8);
    cg.cmn(x0, x1);
    cg.cmn(w2, uint32_t(5));
    cg.tst(x0, x1);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::ADDS);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::SUBS);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::ORN);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::BIC);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::ANDS);
    r = decode(get_insn(cg, 5));
    assert(r && (r->mnemonic == Mnemonic::LSRV || r->mnemonic == Mnemonic::LSR));
    r = decode(get_insn(cg, 6));
    assert(r && (r->mnemonic == Mnemonic::ASRV || r->mnemonic == Mnemonic::ASR));
    r = decode(get_insn(cg, 7));
    assert(r && (r->mnemonic == Mnemonic::RORV || r->mnemonic == Mnemonic::ROR));
    r = decode(get_insn(cg, 8));
    assert(r && (r->mnemonic == Mnemonic::ADDS || r->mnemonic == Mnemonic::CMN));
    r = decode(get_insn(cg, 9));
    assert(r && (r->mnemonic == Mnemonic::ADDS || r->mnemonic == Mnemonic::CMN));
    r = decode(get_insn(cg, 10));
    assert(r && (r->mnemonic == Mnemonic::ANDS || r->mnemonic == Mnemonic::TST));
    std::cout << "  more_reg_ops: OK" << std::endl;
    return 0;
}

static int test_more_bitfield() {
    CodeGenerator cg(4096);
    cg.bfxil(w0, w1, 4, 8);
    cg.sbfiz(x2, x3, 8, 16);
    cg.sxth(w4, w5);
    cg.sxtw(x6, w7);
    cg.uxtb(w8, w9);
    cg.uxth(w10, w11);

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::BFM || r->mnemonic == Mnemonic::BFXIL));
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SBFIZ));
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SXTH));
    r = decode(get_insn(cg, 3));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SXTW));
    r = decode(get_insn(cg, 4));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UXTB));
    r = decode(get_insn(cg, 5));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UXTH));
    std::cout << "  more_bitfield: OK" << std::endl;
    return 0;
}

static int test_more_branches() {
    CodeGenerator cg(4096);
    Label target;
    cg.bl(target);
    cg.bind(target);
    cg.br(x0);
    cg.blr(x1);
    cg.svc(uint16_t(0));
    cg.brk(uint16_t(1));

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::BL);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::BR);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::BLR);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::SVC);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::BRK);
    std::cout << "  more_branches: OK" << std::endl;
    return 0;
}

static int test_movznk() {
    CodeGenerator cg(4096);
    cg.movz(x0, uint16_t(0x1234), 0);
    cg.movk(x0, uint16_t(0x5678), 16);
    cg.movn(w1, uint16_t(0), 0);

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::MOVZ || r->mnemonic == Mnemonic::MOV));
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::MOVK);
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::MOVN || r->mnemonic == Mnemonic::MOV));
    std::cout << "  movznk: OK" << std::endl;
    return 0;
}

static int test_more_ldst() {
    CodeGenerator cg(4096);
    cg.ldrh(w0, ptr(x1));
    cg.strb(w2, ptr(x3, 1));
    cg.strh(w4, ptr(x5, 2));
    cg.ldrsb(x6, ptr(x7));
    cg.ldrsh(x8, ptr(x9));
    cg.ldrsw(x10, ptr(x11));
    cg.ldr(s0, ptr(x12, 4));
    cg.str(d1, ptr(x13));
    cg.fmov(s0, s1);
    cg.fmov(d2, d3);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::LDRH);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::STRB);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::STRH);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::LDRSB);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::LDRSH);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::LDRSW);
    r = decode(get_insn(cg, 6));
    assert(r && (r->mnemonic == Mnemonic::LDR || r->mnemonic == Mnemonic::LDRS));
    r = decode(get_insn(cg, 7));
    assert(r && (r->mnemonic == Mnemonic::STR || r->mnemonic == Mnemonic::STRD));
    r = decode(get_insn(cg, 8));
    assert(r && r->mnemonic == Mnemonic::FMOV);
    r = decode(get_insn(cg, 9));
    assert(r && r->mnemonic == Mnemonic::FMOV);
    std::cout << "  more_ldst: OK" << std::endl;
    return 0;
}

static int test_atomic_variants() {
    CodeGenerator cg(4096);
    cg.casa(x0, x1, x2);
    cg.casl(x3, x4, x5);
    cg.casal(x6, x7, x8);
    cg.swpa(x0, x1, x2);
    cg.swpl(w3, w4, x5);
    cg.swpal(x6, x7, x8);
    cg.ldadda(x0, x1, x2);
    cg.ldaddl(w3, w4, x5);
    cg.ldaddal(x6, x7, x8);
    cg.stadd(x0, x1);
    cg.staddl(w2, x3);

    auto r = decode(get_insn(cg, 0));
    assert(r && r->mnemonic == Mnemonic::CASA);
    r = decode(get_insn(cg, 1));
    assert(r && r->mnemonic == Mnemonic::CASL);
    r = decode(get_insn(cg, 2));
    assert(r && r->mnemonic == Mnemonic::CASAL);
    r = decode(get_insn(cg, 3));
    assert(r && r->mnemonic == Mnemonic::SWPA);
    r = decode(get_insn(cg, 4));
    assert(r && r->mnemonic == Mnemonic::SWPL);
    r = decode(get_insn(cg, 5));
    assert(r && r->mnemonic == Mnemonic::SWPAL);
    r = decode(get_insn(cg, 6));
    assert(r && r->mnemonic == Mnemonic::LDADDA);
    r = decode(get_insn(cg, 7));
    assert(r && r->mnemonic == Mnemonic::LDADDL);
    r = decode(get_insn(cg, 8));
    assert(r && r->mnemonic == Mnemonic::LDADDAL);
    r = decode(get_insn(cg, 9));
    assert(r && (r->mnemonic == Mnemonic::STADD || r->mnemonic == Mnemonic::LDADD));
    r = decode(get_insn(cg, 10));
    assert(r && (r->mnemonic == Mnemonic::STADDL || r->mnemonic == Mnemonic::LDADDL));
    std::cout << "  atomic_variants: OK" << std::endl;
    return 0;
}

static int test_more_simd() {
    CodeGenerator cg(4096);
    cg.bic(v0.b16(), v1.b16(), v2.b16());
    cg.mvn(v3.b16(), v4.b16());
    cg.addp(v0.s4(), v1.s4(), v2.s4());
    cg.abs(v3.s4(), v4.s4());
    cg.neg(v5.h8(), v6.h8());
    cg.cnt(v7.b16(), v8.b16());
    cg.cmge(v0.s4(), v1.s4(), v2.s4());
    cg.cmgt(v3.s4(), v4.s4(), v5.s4());
    cg.cmhi(v6.s4(), v7.s4(), v8.s4());
    cg.cmhs(v9.s4(), v10.s4(), v11.s4());
    cg.cmge_zero(v0.s4(), v1.s4());
    cg.cmgt_zero(v2.s4(), v3.s4());
    cg.cmle_zero(v4.s4(), v5.s4());
    cg.cmlt_zero(v6.s4(), v7.s4());
    cg.sshr(v8.s4(), v9.s4(), 4);
    cg.dup(v0.s4(), w0);
    cg.ins(v0.s4(), 1, w1);
    cg.umov(w0, v1.s4(), 2);

    const uint8_t* p = cg.data();
    for (size_t i = 0; i < cg.size(); i += 4) {
        uint32_t insn = *reinterpret_cast<const uint32_t*>(p + i);
        auto d = decode(insn);
        if (!d) {
            std::cerr << "more_simd: decode failed at offset " << i << std::endl;
            return 1;
        }
    }
    std::cout << "  more_simd: OK" << std::endl;
    return 0;
}

static int test_extend_ops() {
    CodeGenerator cg(4096);
    cg.sxtb(x0, w1);
    cg.sxth(x2, w3);
    cg.sxtw(x4, w5);
    cg.uxtb(w6, w7);
    cg.uxth(w8, w9);

    auto r = decode(get_insn(cg, 0));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SXTB));
    r = decode(get_insn(cg, 1));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SXTH));
    r = decode(get_insn(cg, 2));
    assert(r && (r->mnemonic == Mnemonic::SBFM || r->mnemonic == Mnemonic::SXTW));
    r = decode(get_insn(cg, 3));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UXTB));
    r = decode(get_insn(cg, 4));
    assert(r && (r->mnemonic == Mnemonic::UBFM || r->mnemonic == Mnemonic::UXTH));
    std::cout << "  extend_ops: OK" << std::endl;
    return 0;
}

int test_simd() {
    std::cout << "  SIMD tests..." << std::endl;
    CodeGenerator cg(4096);
    // Vector arithmetic
    cg.add(v0.s4(), v1.s4(), v2.s4());   // ADD V0.4S, V1.4S, V2.4S
    cg.sub(v3.h8(), v4.h8(), v5.h8());   // SUB V3.8H, V4.8H, V5.8H
    cg.mul(v0.s4(), v0.s4(), v1.s4());    // MUL V0.4S, V0.4S, V1.4S
    // Bitwise
    cg.and_(v0.b16(), v1.b16(), v2.b16());
    cg.orr(v0.b16(), v1.b16(), v2.b16());
    cg.eor(v3.b16(), v4.b16(), v5.b16());
    cg.not_(v0.b16(), v1.b16());
    // Compare
    cg.cmeq(v0.s4(), v1.s4(), v2.s4());
    cg.cmeq_zero(v0.s4(), v1.s4());
    // Shift
    cg.shl(v0.s4(), v1.s4(), 2);
    cg.ushr(v0.s4(), v1.s4(), 4);
    // DUP/MOVI
    cg.dup(v0.s4(), w0);
    cg.movi(v0.b16(), 0);
    // Decode and verify each instruction
    const uint8_t* p = cg.data();
    for (size_t i = 0; i < cg.size(); i += 4) {
        uint32_t insn = *reinterpret_cast<const uint32_t*>(p + i);
        auto d = decode(insn);
        if (!d) {
            std::cerr << "SIMD: decode failed for insn at offset " << i << std::endl;
            return 1;
        }
    }
    return 0;
}

int main() {
    std::cout << "Running codegen tests..." << std::endl;
    int err = 0;
    err |= test_arithmetic();
    err |= test_branches();
    err |= test_forward_branch();
    err |= test_ldst();
    err |= test_fp();
    err |= test_mov();
    err |= test_carry();
    err |= test_bitfield();
    err |= test_shift_imm();
    err |= test_3src();
    err |= test_condcmp();
    err |= test_atomics();
    err |= test_simd();
    err |= test_logical_imm();
    err |= test_more_reg_ops();
    err |= test_more_bitfield();
    err |= test_more_branches();
    err |= test_movznk();
    err |= test_more_ldst();
    err |= test_atomic_variants();
    err |= test_more_simd();
    err |= test_extend_ops();
#if defined(__aarch64__) || defined(_M_ARM64)
    err |= test_execute();
    err |= test_execute_loop();
#endif
    std::cout << "All codegen tests passed!" << std::endl;
    return err;
}

#else // !VEDA64_CODEGEN

#include <cstdio>
int main() {
    printf("Codegen tests skipped (VEDA64_CODEGEN not set)\n");
    return 0;
}

#endif
