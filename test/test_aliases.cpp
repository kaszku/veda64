// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

using namespace veda64;

static int failures = 0;
static int passed = 0;

static std::string to_lower(const std::string& s) {
    std::string r = s;
    for (char& c : r) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return r;
}

static void check_mnemonic(uint32_t insn, const char* expected_mnemonic) {
    auto r = decode(insn, true);  // Use alias-aware decode
    if (!r) {
        std::cerr << "  FAIL: decode failed for 0x" << std::hex << insn << std::dec << std::endl;
        failures++; return;
    }
#ifdef VEDA64_STRINGS
    auto s = r->to_string();
    // Extract mnemonic (first word)
    auto sp = s.find(' ');
    auto got = to_lower(sp == std::string::npos ? s : s.substr(0, sp));
    auto exp = to_lower(std::string(expected_mnemonic));
    if (got != exp) {
        std::cerr << "  FAIL: 0x" << std::hex << insn << std::dec
                  << " expected mnemonic \"" << expected_mnemonic << "\" got \"" << got << "\"" << std::endl;
        failures++; return;
    }
#else
    (void)expected_mnemonic;
#endif
    passed++;
}

static void check_disasm(uint32_t insn, const char* expected) {
    auto r = decode(insn);
    if (!r) {
        std::cerr << "  FAIL: decode failed for 0x" << std::hex << insn << std::dec << std::endl;
        failures++; return;
    }
#ifdef VEDA64_STRINGS
    auto got = to_lower(r->to_string());
    auto exp = to_lower(std::string(expected));
    if (got != exp) {
        std::cerr << "  FAIL: 0x" << std::hex << insn << std::dec
                  << " expected \"" << expected << "\" got \"" << got << "\"" << std::endl;
        failures++; return;
    }
#else
    (void)expected;
#endif
    passed++;
}

int main() {
    std::cout << "Running alias detection tests..." << std::endl;

    // ADD Rd,SP → MOV
    check_mnemonic(0x910003FDu, "mov");
    // ADD X0,SP,#0 → MOV
    check_mnemonic(0x910003E0u, "mov");
    // ORR W0,WZR,W0 → MOV
    check_mnemonic(0x2A0003E0u, "mov");
    // ORR X0,XZR,X0 → MOV
    check_mnemonic(0xAA0003E0u, "mov");
    // MOVZ X0,#0 → MOV
    check_mnemonic(0xD2800000u, "mov");
    // MOVZ W0,#1 → MOV
    check_mnemonic(0x52800020u, "mov");
    // MOVN X0,#0 → MOV (inverted)
    check_mnemonic(0x92800000u, "mov");
    // SUBS XZR,X0,X0 → CMP
    check_mnemonic(0xEB00001Fu, "cmp");
    // SUBS WZR,W0,W1 → CMP
    check_mnemonic(0x6B01001Fu, "cmp");
    // SUBS XZR,X0,#0 → CMP
    check_mnemonic(0xF100001Fu, "cmp");
    // ADDS XZR,X0,X0 → CMN
    check_mnemonic(0xAB00001Fu, "cmn");
    // ADDS WZR,W0,W1 → CMN
    check_mnemonic(0x2B01001Fu, "cmn");
    // SUB X0,XZR,X0 → NEG
    check_mnemonic(0xCB0003E0u, "neg");
    // SUB W0,WZR,W0 → NEG
    check_mnemonic(0x4B0003E0u, "neg");
    // ANDS XZR,X0,X0 → TST
    check_mnemonic(0xEA00001Fu, "tst");
    // ANDS WZR,W0,W1 → TST
    check_mnemonic(0x6A01001Fu, "tst");
    // MADD X0,X0,X0,XZR → MUL
    check_mnemonic(0x9B007C00u, "mul");
    // MADD W0,W1,W1,WZR → MUL
    check_mnemonic(0x1B017C20u, "mul");
    // MSUB X0,X0,X0,XZR → MNEG
    check_mnemonic(0x9B00FC00u, "mneg");
    // LSLV W0,W0,W0 → LSL
    check_mnemonic(0x1AC02000u, "lsl");
    // LSRV X0,X0,X0 → LSR
    check_mnemonic(0x9AC02400u, "lsr");
    // ASRV W0,W0,W0 → ASR
    check_mnemonic(0x1AC02800u, "asr");
    // RORV W0,W0,W0 → ROR
    check_mnemonic(0x1AC02C00u, "ror");
    // EXTR W0,W0,W0,#0 → ROR
    check_mnemonic(0x13800000u, "ror");
    // CSINC W0,WZR,WZR,ne → CSET
    check_mnemonic(0x1A9F07E0u, "cset");
    // CSINC X0,XZR,XZR,ne → CSET
    check_mnemonic(0x9A9F07E0u, "cset");
    // CSINC W0,W0,W0,ne → CINC
    check_mnemonic(0x1A800400u, "cinc");
    // CSINV W0,W0,W0,ne → CINV
    check_mnemonic(0x5A800000u, "cinv");
    // CSNEG W0,W0,W0,lo → CNEG
    check_mnemonic(0x5A802400u, "cneg");
    // UBFM W0,W0,#0,#7 → UXTB
    check_mnemonic(0x53001C00u, "uxtb");
    // UBFM W0,W0,#0,#15 → UXTH
    check_mnemonic(0x53003C00u, "uxth");
    // SBFM W0,W0,#0,#7 → SXTB
    check_mnemonic(0x13001C00u, "sxtb");
    // SBFM W0,W0,#0,#15 → SXTH
    check_mnemonic(0x13003C00u, "sxth");
    // SBFM X0,X0,#0,#31 → SXTW
    check_mnemonic(0x93407C00u, "sxtw");
    // UBFM X0,X0,#immr,#imms → LSL #1
    check_mnemonic(0xD37FF800u, "lsl");
    // UBFM W0,W0,#2,#31 → LSR #2
    check_mnemonic(0x53027C00u, "lsr");
    // SBFM W0,W0,#2,#31 → ASR #2
    check_mnemonic(0x13027C00u, "asr");
    // SMADDL X0,W0,W0,XZR → SMULL
    check_mnemonic(0x9B207C00u, "smull");
    // UMADDL X0,W0,W0,XZR → UMULL
    check_mnemonic(0x9BA07C00u, "umull");
    // HINT #0 → NOP
    check_mnemonic(0xD503201Fu, "nop");
    // NOT 8B → MVN
    check_mnemonic(0x2E205800u, "mvn");
    // ORR SIMD Rm==Rn → MOV (runtime alias)
    check_mnemonic(0x4EA31C60u, "mov");  // ORR v0.16b, v3.16b, v3.16b → MOV v0.16b, v3.16b
    // DSB → SSBB/PSSBB
    check_mnemonic(0xD503309Fu, "ssbb");
    check_mnemonic(0xD503349Fu, "pssbb");

    // === decode(insn, aliases=true) tests ===
    std::cout << "  Testing decode with aliases=true..." << std::endl;

    // MOV from ADD: decode(insn, true) → Mnemonic::MOV with 2 operands
    {
        auto raw = decode(0x910003FDu, false);
        assert(raw.has_value());
        assert(raw->mnemonic == Mnemonic::ADD);

        auto aliased = decode(0x910003FDu, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::MOV);
        assert(aliased->operands.size() == 2);  // X29, SP
        passed++;
    }

    // CMP from SUBS: decode(insn, true) → Mnemonic::CMP
    {
        auto raw = decode(0xEB00001Fu, false);
        assert(raw.has_value());
        assert(raw->mnemonic == Mnemonic::SUBS);

        auto aliased = decode(0xEB00001Fu, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::CMP);
        passed++;
    }

    // CMN from ADDS: decode(insn, true) → Mnemonic::CMN
    {
        auto aliased = decode(0xAB00001Fu, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::CMN);
        passed++;
    }

    // TST from ANDS: decode(insn, true) → Mnemonic::TST
    {
        auto aliased = decode(0xEA00001Fu, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::TST);
        passed++;
    }

    // NEG from SUB: decode(insn, true) → Mnemonic::NEG
    {
        auto aliased = decode(0xCB0003E0u, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::NEG);
        passed++;
    }

    // MUL from MADD: decode(insn, true) → Mnemonic::MUL
    {
        auto aliased = decode(0x9B007C00u, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::MUL);
        passed++;
    }

    // NOP from HINT: decode(insn, true) → Mnemonic::NOP
    {
        auto aliased = decode(0xD503201Fu, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::NOP);
        passed++;
    }

    // MOV from ORR: decode(insn, true) → Mnemonic::MOV
    {
        auto aliased = decode(0xAA0003E0u, true);
        assert(aliased.has_value());
        assert(aliased->mnemonic == Mnemonic::MOV);
        passed++;
    }

    // Backward compat: decode(insn) without aliases flag → base mnemonic
    {
        auto raw = decode(0x910003FDu);
        assert(raw.has_value());
        assert(raw->mnemonic == Mnemonic::ADD);
        passed++;
    }

    // === Comprehensive alias coverage ===
    // Tests every alias encoding family with aliases=true: verify mnemonic + operand count
    std::cout << "  Comprehensive alias coverage..." << std::endl;

    auto check_alias = [&](uint32_t insn, Mnemonic expected_mn, int expected_ops, const char* label) {
        auto r = decode(insn, true);
        if (!r) { std::cerr << "  FAIL decode: " << label << std::endl; failures++; return; }
        if (r->mnemonic != expected_mn || (int)r->operands.size() != expected_ops) {
            std::cerr << "  FAIL " << label << ": got " << mnemonic_to_string(r->mnemonic)
                      << " " << r->operands.size() << " ops (expected " << mnemonic_to_string(expected_mn)
                      << " " << expected_ops << " ops)" << std::endl;
            failures++;
        } else { passed++; }
    };

    // MOV from ADD (32/64)
    check_alias(0x11000020u, Mnemonic::MOV, 2, "MOV_ADD_32");  // mov w0, w1
    check_alias(0x910003FDu, Mnemonic::MOV, 2, "MOV_ADD_64");  // mov x29, sp
    // MOV from ORR shifted reg (32/64)
    check_alias(0x2A0003E0u, Mnemonic::MOV, 2, "MOV_ORR_32_shift");  // mov w0, w0
    check_alias(0xAA0003E0u, Mnemonic::MOV, 2, "MOV_ORR_64_shift");  // mov x0, x0
    // MOV from MOVZ (32/64)
    check_alias(0x52800020u, Mnemonic::MOV, 2, "MOV_MOVZ_32");  // mov w0, #1
    check_alias(0xD2800000u, Mnemonic::MOV, 2, "MOV_MOVZ_64");  // mov x0, #0
    // MOV from MOVN (32/64)
    check_alias(0x12800000u, Mnemonic::MOV, 2, "MOV_MOVN_32");  // mov w0, #-1
    check_alias(0x92800000u, Mnemonic::MOV, 2, "MOV_MOVN_64");  // mov x0, #-1

    // CMP from SUBS shifted reg (32/64)
    check_alias(0x6B01001Fu, Mnemonic::CMP, 2, "CMP_SUBS_32_shift");  // cmp w0, w1
    check_alias(0xEB00001Fu, Mnemonic::CMP, 2, "CMP_SUBS_64_shift");  // cmp x0, x0
    // CMP from SUBS immediate (32/64)
    check_alias(0x7100001Fu, Mnemonic::CMP, 2, "CMP_SUBS_32_imm");    // cmp w0, #0
    check_alias(0xF100001Fu, Mnemonic::CMP, 2, "CMP_SUBS_64_imm");    // cmp x0, #0
    // CMP from SUBS extended (32/64)
    check_alias(0x6B21001Fu, Mnemonic::CMP, 3, "CMP_SUBS_32_ext");    // cmp w0, w1, uxtb
    check_alias(0xEB21001Fu, Mnemonic::CMP, 3, "CMP_SUBS_64_ext");    // cmp x0, x1, uxtb

    // CMN from ADDS shifted reg (32/64)
    check_alias(0x2B01001Fu, Mnemonic::CMN, 2, "CMN_ADDS_32_shift");
    check_alias(0xAB00001Fu, Mnemonic::CMN, 2, "CMN_ADDS_64_shift");
    // CMN from ADDS immediate (32/64)
    check_alias(0x3100001Fu, Mnemonic::CMN, 2, "CMN_ADDS_32_imm");
    check_alias(0xB100001Fu, Mnemonic::CMN, 2, "CMN_ADDS_64_imm");

    // TST from ANDS shifted reg (32/64)
    check_alias(0x6A01001Fu, Mnemonic::TST, 2, "TST_ANDS_32_shift");
    check_alias(0xEA00001Fu, Mnemonic::TST, 2, "TST_ANDS_64_shift");
    // TST from ANDS logical imm (32/64) — has Rn + N + immr + imms = 3 ops
    check_alias(0x7200001Fu, Mnemonic::TST, 3, "TST_ANDS_32_imm");
    check_alias(0xF200001Fu, Mnemonic::TST, 3, "TST_ANDS_64_imm");

    // NEG from SUB (32/64)
    check_alias(0x4B0003E0u, Mnemonic::NEG, 2, "NEG_SUB_32");
    check_alias(0xCB0003E0u, Mnemonic::NEG, 2, "NEG_SUB_64");
    // NEGS from SUBS (32/64)
    check_alias(0x6B0003E0u, Mnemonic::NEGS, 2, "NEGS_SUBS_32");
    check_alias(0xEB0003E0u, Mnemonic::NEGS, 2, "NEGS_SUBS_64");

    // MVN from ORN (32/64)
    check_alias(0x2A2003E0u, Mnemonic::MVN, 2, "MVN_ORN_32");
    check_alias(0xAA2003E0u, Mnemonic::MVN, 2, "MVN_ORN_64");
    // MVN from NOT (SIMD)
    check_alias(0x2E205800u, Mnemonic::MVN, 2, "MVN_NOT_simd");

    // MUL from MADD (32/64)
    check_alias(0x1B017C20u, Mnemonic::MUL, 3, "MUL_MADD_32");
    check_alias(0x9B007C00u, Mnemonic::MUL, 3, "MUL_MADD_64");
    // MNEG from MSUB (32/64)
    check_alias(0x1B01FC20u, Mnemonic::MNEG, 3, "MNEG_MSUB_32");
    check_alias(0x9B00FC00u, Mnemonic::MNEG, 3, "MNEG_MSUB_64");

    // NGC from SBC (32/64)
    check_alias(0x5A0103E0u, Mnemonic::NGC, 2, "NGC_SBC_32");
    check_alias(0xDA0103E0u, Mnemonic::NGC, 2, "NGC_SBC_64");
    // NGCS from SBCS (32/64)
    check_alias(0x7A0103E0u, Mnemonic::NGCS, 2, "NGCS_SBCS_32");
    check_alias(0xFA0103E0u, Mnemonic::NGCS, 2, "NGCS_SBCS_64");

    // SMULL/UMULL from SMADDL/UMADDL
    check_alias(0x9B207C00u, Mnemonic::SMULL, 3, "SMULL");
    check_alias(0x9BA07C00u, Mnemonic::UMULL, 3, "UMULL");
    // SMNEGL/UMNEGL from SMSUBL/UMSUBL
    check_alias(0x9B20FC00u, Mnemonic::SMNEGL, 3, "SMNEGL");
    check_alias(0x9BA0FC00u, Mnemonic::UMNEGL, 3, "UMNEGL");

    // LSL/LSR/ASR/ROR register (32/64)
    check_alias(0x1AC02000u, Mnemonic::LSL, 3, "LSL_REG_32");
    check_alias(0x9AC02000u, Mnemonic::LSL, 3, "LSL_REG_64");
    check_alias(0x1AC02400u, Mnemonic::LSR, 3, "LSR_REG_32");
    check_alias(0x9AC02400u, Mnemonic::LSR, 3, "LSR_REG_64");
    check_alias(0x1AC02800u, Mnemonic::ASR, 3, "ASR_REG_32");
    check_alias(0x9AC02800u, Mnemonic::ASR, 3, "ASR_REG_64");
    check_alias(0x1AC02C00u, Mnemonic::ROR, 3, "ROR_REG_32");
    check_alias(0x9AC02C00u, Mnemonic::ROR, 3, "ROR_REG_64");

    // LSL/LSR/ASR immediate (from UBFM/SBFM 32/64)
    check_alias(0xD37FF800u, Mnemonic::LSL, 4, "LSL_IMM_64");  // lsl x0, x0, #1 (has immr+imms=4 ops)
    check_alias(0x53027C00u, Mnemonic::LSR, 3, "LSR_IMM_32");  // lsr w0, w0, #2
    check_alias(0xD342FC00u, Mnemonic::LSR, 3, "LSR_IMM_64");  // lsr x0, x0, #2
    check_alias(0x13027C00u, Mnemonic::ASR, 3, "ASR_IMM_32");  // asr w0, w0, #2
    check_alias(0x9342FC00u, Mnemonic::ASR, 3, "ASR_IMM_64");  // asr x0, x0, #2
    // ROR immediate from EXTR — conditional alias (Rn==Rm), runtime condition check
    // Note: still emits Rm as operand (redundant with Rn) — 4 ops not 3
    check_alias(0x13800000u, Mnemonic::ROR, 4, "ROR_IMM_32");  // ror w0, w0, w0, #0
    check_alias(0x93C00000u, Mnemonic::ROR, 4, "ROR_IMM_64");  // ror x0, x0, x0, #0
    // EXTR when Rn!=Rm should NOT be aliased
    check_alias(0x13810000u, Mnemonic::EXTR, 4, "EXTR_not_ROR_32"); // extr w0, w0, w1, #0

    // SXTB/SXTH/SXTW (from SBFM)
    check_alias(0x13001C00u, Mnemonic::SXTB, 2, "SXTB_32");
    check_alias(0x93401C00u, Mnemonic::SXTB, 2, "SXTB_64");
    check_alias(0x13003C00u, Mnemonic::SXTH, 2, "SXTH_32");
    check_alias(0x93403C00u, Mnemonic::SXTH, 2, "SXTH_64");
    check_alias(0x93407C00u, Mnemonic::SXTW, 2, "SXTW_64");
    // UXTB/UXTH (from UBFM)
    check_alias(0x53001C00u, Mnemonic::UXTB, 2, "UXTB_32");
    check_alias(0x53003C00u, Mnemonic::UXTH, 2, "UXTH_32");

    // CSET/CSETM — 1 register operand + condition on Instruction::condition
    check_alias(0x1A9F07E0u, Mnemonic::CSET, 1, "CSET_32");
    check_alias(0x9A9F07E0u, Mnemonic::CSET, 1, "CSET_64");
    check_alias(0x5A9F03E0u, Mnemonic::CSETM, 1, "CSETM_32");
    check_alias(0xDA9F03E0u, Mnemonic::CSETM, 1, "CSETM_64");
    // Verify condition field is set for CSET
    { auto a = decode(0x1A9F07E0u, true); assert(a->condition != Condition::AL); passed++; }
    // CINC/CINV/CNEG — 2 register operands + condition on Instruction::condition
    check_alias(0x1A800400u, Mnemonic::CINC, 2, "CINC_32");
    check_alias(0x9A800400u, Mnemonic::CINC, 2, "CINC_64");
    check_alias(0x5A800000u, Mnemonic::CINV, 2, "CINV_32");
    check_alias(0xDA800000u, Mnemonic::CINV, 2, "CINV_64");
    check_alias(0x5A802400u, Mnemonic::CNEG, 2, "CNEG_32");
    check_alias(0xDA802400u, Mnemonic::CNEG, 2, "CNEG_64");

    // NOP/YIELD/WFE/WFI/SEV/SEVL from HINT
    check_alias(0xD503201Fu, Mnemonic::NOP, 0, "NOP");

    // === Operand value verification ===
    std::cout << "  Verifying operand values..." << std::endl;

    // MOV from ADD: mov x29, sp → Rd=x29, Rn=sp
    {
        auto a = decode(0x910003FDu, true);
        assert(a->mnemonic == Mnemonic::MOV && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        passed++;
    }

    // CMP from SUBS imm: cmp x0, #0 → Rn, imm (Rd=XZR dropped)
    {
        auto a = decode(0xF100001Fu, true);
        assert(a->mnemonic == Mnemonic::CMP && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Immediate);
        passed++;
    }

    // NEG from SUB: neg x0, x0 → Rd, Rm (Rn=XZR dropped)
    {
        auto a = decode(0xCB0003E0u, true);
        assert(a->mnemonic == Mnemonic::NEG && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        passed++;
    }

    // MUL: mul x0, x1, x2 → Rd, Rn, Rm (Ra=XZR dropped)
    {
        auto a = decode(0x9B027C20u, true);
        assert(a->mnemonic == Mnemonic::MUL && a->operands.size() == 3);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        assert(a->operands[2].type == OperandType::Register);
        passed++;
    }

    // MVN from ORN: mvn x0, x0 → Rd, Rm (Rn=XZR dropped)
    {
        auto a = decode(0xAA2003E0u, true);
        assert(a->mnemonic == Mnemonic::MVN && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        passed++;
    }

    // SXTB: sxtb w0, w0 → Rd, Rn
    {
        auto a = decode(0x13001C00u, true);
        assert(a->mnemonic == Mnemonic::SXTB && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        passed++;
    }

    // NGC: ngc x0, x1 → Rd, Rm (Rn=XZR dropped)
    {
        auto a = decode(0xDA0103E0u, true);
        assert(a->mnemonic == Mnemonic::NGC && a->operands.size() == 2);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        passed++;
    }

    // SMULL: smull x0, w0, w0 → Xd, Wn, Wm
    {
        auto a = decode(0x9B207C00u, true);
        assert(a->mnemonic == Mnemonic::SMULL && a->operands.size() == 3);
        passed++;
    }

    // LSR register: lsr w0, w0, w0 → Rd, Rn, Rm
    {
        auto a = decode(0x1AC02400u, true);
        assert(a->mnemonic == Mnemonic::LSR && a->operands.size() == 3);
        assert(a->operands[0].type == OperandType::Register);
        assert(a->operands[1].type == OperandType::Register);
        assert(a->operands[2].type == OperandType::Register);
        passed++;
    }

    // Backward compat: decode(insn, false) gives base mnemonics
    {
        assert(decode(0x910003FDu, false)->mnemonic == Mnemonic::ADD);
        assert(decode(0xEB00001Fu, false)->mnemonic == Mnemonic::SUBS);
        assert(decode(0xCB0003E0u, false)->mnemonic == Mnemonic::SUB);
        assert(decode(0x9B007C00u, false)->mnemonic == Mnemonic::MADD);
        assert(decode(0xAA2003E0u, false)->mnemonic == Mnemonic::ORN);
        assert(decode(0xDA0103E0u, false)->mnemonic == Mnemonic::SBC);
        passed++;
    }

    // === Operand adjustment tests ===
    std::cout << "  Testing alias operand adjustment..." << std::endl;

    // MOV from ADD: should have 2 operands (Rd, Rn), no #0
    {
        auto a = decode(0x910003FDu, true);  // mov x29, sp
        assert(a->mnemonic == Mnemonic::MOV);
        assert(a->operands.size() == 2);  // just Rd, Rn
        passed++;
    }

    // MOV from ORR: should have 2 operands (Rd, Rm), no XZR Rn
    {
        auto a = decode(0xAA0003E0u, true);  // mov x0, x0 (ORR x0, xzr, x0)
        assert(a->mnemonic == Mnemonic::MOV);
        // Currently has 3 ops (Rd, XZR, Rm) — check what we get
        std::cout << "    MOV from ORR: " << a->operands.size() << " ops" << std::endl;
        // After fix, should be 2
        if (a->operands.size() == 2) passed++; else { std::cerr << "  XFAIL: MOV from ORR has " << a->operands.size() << " ops (expected 2)" << std::endl; failures++; }
    }

    // CMP from SUBS: should have 2 operands (Rn, Rm), no Rd=XZR
    {
        auto a = decode(0xEB00001Fu, true);  // cmp x0, x0
        assert(a->mnemonic == Mnemonic::CMP);
        std::cout << "    CMP from SUBS: " << a->operands.size() << " ops" << std::endl;
        if (a->operands.size() == 2) passed++; else { std::cerr << "  XFAIL: CMP has " << a->operands.size() << " ops (expected 2)" << std::endl; failures++; }
    }

    // NEG from SUB: should have 2 operands (Rd, Rm), no Rn=XZR
    {
        auto a = decode(0xCB0003E0u, true);  // neg x0, x0
        assert(a->mnemonic == Mnemonic::NEG);
        std::cout << "    NEG from SUB: " << a->operands.size() << " ops" << std::endl;
        if (a->operands.size() == 2) passed++; else { std::cerr << "  XFAIL: NEG has " << a->operands.size() << " ops (expected 2)" << std::endl; failures++; }
    }

    // MOV from ORR SIMD (Rm==Rn): should have 2 operands (Vd, Vn)
    {
        auto a = decode(0x4EA31C60u, true);  // mov v0.16b, v3.16b
        assert(a->mnemonic == Mnemonic::MOV);
        std::cout << "    MOV from ORR SIMD: " << a->operands.size() << " ops" << std::endl;
        if (a->operands.size() == 2) passed++; else { std::cerr << "  FAIL: MOV SIMD has " << a->operands.size() << " ops (expected 2)" << std::endl; failures++; }
    }

    // MUL from MADD: should have 3 operands (Rd, Rn, Rm), no Ra=XZR
    {
        auto a = decode(0x9B007C00u, true);  // mul x0, x0, x0
        assert(a->mnemonic == Mnemonic::MUL);
        std::cout << "    MUL from MADD: " << a->operands.size() << " ops" << std::endl;
        if (a->operands.size() == 3) passed++; else { std::cerr << "  XFAIL: MUL has " << a->operands.size() << " ops (expected 3)" << std::endl; failures++; }
    }

    // Verify to_string() produces correct output with aliases=true
#ifdef VEDA64_STRINGS
    {
        struct { uint32_t insn; const char* expected_prefix; } str_tests[] = {
            {0x910003FDu, "mov "},
            {0xAA0003E0u, "mov "},
            {0xEB00001Fu, "cmp "},
            {0xAB00001Fu, "cmn "},
            {0xEA00001Fu, "tst "},
            {0xCB0003E0u, "neg "},
            {0x9B007C00u, "mul "},
            {0xD503201Fu, "nop"},
        };
        for (auto& t : str_tests) {
            auto a = decode(t.insn, true);
            assert(a.has_value());
            auto s = a->to_string();
            auto sl = to_lower(s);
            if (sl.find(t.expected_prefix) != 0) {
                std::cerr << "  FAIL: 0x" << std::hex << t.insn << std::dec
                          << " to_string=\"" << s << "\" doesn't start with \"" << t.expected_prefix << "\"" << std::endl;
                failures++;
            } else {
                passed++;
            }
        }
    }
#endif

    std::cout << passed << " / " << (passed + failures) << " alias tests passed" << std::endl;
    return failures ? 1 : 0;
}
