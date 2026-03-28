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
    auto r = decode(insn);
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

    std::cout << passed << " / " << (passed + failures) << " alias tests passed" << std::endl;
    return failures ? 1 : 0;
}
