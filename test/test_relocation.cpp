// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_HOOK

#include "veda64.hpp"
#include <veda64/relocation.hpp>
#include <iostream>
#include <cassert>
#include <cstdint>

using namespace veda64;

static int failures = 0;
static int passed = 0;

void test_is_pc_relative() {
    std::cout << "Testing is_pc_relative..." << std::endl;
    // B .+0x100 — PC-relative
    if (is_pc_relative(0x14000040)) { passed++; } else { failures++; std::cerr << "  FAIL: B is_pc_relative" << std::endl; }
    // BL .+0x100 — PC-relative
    if (is_pc_relative(0x94000040)) { passed++; } else { failures++; std::cerr << "  FAIL: BL is_pc_relative" << std::endl; }
    // B.EQ .+0x8 — PC-relative
    if (is_pc_relative(0x54000040)) { passed++; } else { failures++; std::cerr << "  FAIL: B.EQ is_pc_relative" << std::endl; }
    // CBZ X0, .+0x8 — PC-relative
    if (is_pc_relative(0xB4000040)) { passed++; } else { failures++; std::cerr << "  FAIL: CBZ is_pc_relative" << std::endl; }
    // ADR X0, .+0x100 — PC-relative
    if (is_pc_relative(0x10000800)) { passed++; } else { failures++; std::cerr << "  FAIL: ADR is_pc_relative" << std::endl; }
    // ADRP X0, ... — PC-relative
    if (is_pc_relative(0x90000000)) { passed++; } else { failures++; std::cerr << "  FAIL: ADRP is_pc_relative" << std::endl; }
    // ADD X0, X1, X2 — NOT PC-relative
    if (!is_pc_relative(0x8B020020)) { passed++; } else { failures++; std::cerr << "  FAIL: ADD !is_pc_relative" << std::endl; }
    // RET — NOT PC-relative
    if (!is_pc_relative(0xD65F03C0)) { passed++; } else { failures++; std::cerr << "  FAIL: RET !is_pc_relative" << std::endl; }
    // LDR X0, [X1] — NOT PC-relative
    if (!is_pc_relative(0xF9400020)) { passed++; } else { failures++; std::cerr << "  FAIL: LDR reg !is_pc_relative" << std::endl; }
    // TBZ W0, #0, .+0x8 — PC-relative
    if (is_pc_relative(0x36000040)) { passed++; } else { failures++; std::cerr << "  FAIL: TBZ is_pc_relative" << std::endl; }
}

void test_can_relocate() {
    std::cout << "Testing can_relocate..." << std::endl;
    // B and BL can always be relocated (imm26 has huge range)
    if (can_relocate(0x14000040)) { passed++; } else { failures++; std::cerr << "  FAIL: B can_relocate" << std::endl; }
    if (can_relocate(0x94000040)) { passed++; } else { failures++; std::cerr << "  FAIL: BL can_relocate" << std::endl; }
    // Non-PC-relative instructions can be relocated trivially
    if (can_relocate(0x8B020020)) { passed++; } else { failures++; std::cerr << "  FAIL: ADD can_relocate" << std::endl; }
    if (can_relocate(0xD65F03C0)) { passed++; } else { failures++; std::cerr << "  FAIL: RET can_relocate" << std::endl; }
}

void test_relocate_instruction() {
    std::cout << "Testing relocate_instruction..." << std::endl;
    uint32_t out[8];
    size_t count;

    // B .+0x100 at 0x1000, relocate to 0x2000
    // Original target: 0x1100. New offset from 0x2000: -0xF00
    bool ok = relocate_instruction(0x14000040, 0x1000, 0x2000, out, &count);
    if (ok && count == 1) {
        auto d = decode(out[0]);
        if (d && d->mnemonic == Mnemonic::B) { passed++; } else { failures++; std::cerr << "  FAIL: B relocate decode" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B relocate" << std::endl; }

    // Non-PC-relative instruction: should pass through unchanged
    ok = relocate_instruction(0x8B020020, 0x1000, 0x5000, out, &count);
    if (ok && count == 1 && out[0] == 0x8B020020) { passed++; } else { failures++; std::cerr << "  FAIL: ADD passthrough" << std::endl; }

    // BL .+0x40 at 0x1000, relocate to 0x3000
    ok = relocate_instruction(0x94000010, 0x1000, 0x3000, out, &count);
    if (ok && count == 1) {
        auto d = decode(out[0]);
        if (d && d->mnemonic == Mnemonic::BL) { passed++; } else { failures++; std::cerr << "  FAIL: BL relocate decode" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: BL relocate" << std::endl; }

    // ---- Short-branch expansion (out-of-range imm19/imm14) ----

    // B.EQ +8 at 0x1000, target 0x1008. Move to 0x102000 (delta beyond ±1 MiB
    // imm19, inside ±128 MiB imm26). Expect: B.NE +8 ; B 0x1008.
    // Both B.cond and unconditional B decode to Mnemonic::B; distinguish by
    // the top-byte encoding pattern.
    ok = relocate_instruction(0x54000040, 0x1000, 0x102000, out, &count);
    if (ok && count == 2) {
        auto d0 = decode(out[0]);
        auto d1 = decode(out[1]);
        bool cond_ok = d0 && d0->mnemonic == Mnemonic::B
                       && (out[0] & 0xFF000010u) == 0x54000000u
                       && (out[0] & 0xFu) == 1;  // NE
        bool imm_ok  = ((static_cast<int32_t>(out[0] << 8) >> 13) == 2);
        bool b_ok    = d1 && d1->mnemonic == Mnemonic::B
                       && (out[1] & 0xFC000000u) == 0x14000000u;
        int32_t imm26 = static_cast<int32_t>(out[1] << 6) >> 6;
        int64_t target = static_cast<int64_t>(0x102000 + 4) + (static_cast<int64_t>(imm26) << 2);
        if (cond_ok && imm_ok && b_ok && target == 0x1008) { passed++; }
        else { failures++; std::cerr << "  FAIL: B.EQ out-of-range expansion" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B.EQ out-of-range count" << std::endl; }

    // CBZ X0, +8 at 0x1000, target 0x1008. Same delta as above.
    ok = relocate_instruction(0xB4000040, 0x1000, 0x102000, out, &count);
    if (ok && count == 2) {
        auto d0 = decode(out[0]);
        auto d1 = decode(out[1]);
        bool cbnz_ok = d0 && d0->mnemonic == Mnemonic::CBNZ;
        bool imm_ok  = ((static_cast<int32_t>(out[0] << 8) >> 13) == 2);
        bool b_ok    = d1 && d1->mnemonic == Mnemonic::B
                       && (out[1] & 0xFC000000u) == 0x14000000u;
        int32_t imm26 = static_cast<int32_t>(out[1] << 6) >> 6;
        int64_t target = static_cast<int64_t>(0x102000 + 4) + (static_cast<int64_t>(imm26) << 2);
        if (cbnz_ok && imm_ok && b_ok && target == 0x1008) { passed++; }
        else { failures++; std::cerr << "  FAIL: CBZ out-of-range expansion" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: CBZ out-of-range count" << std::endl; }

    // TBZ W0, #0, +8 at 0x1000. Move to 0x11000 (delta beyond ±32 KiB imm14,
    // inside imm26).
    ok = relocate_instruction(0x36000040, 0x1000, 0x11000, out, &count);
    if (ok && count == 2) {
        auto d0 = decode(out[0]);
        auto d1 = decode(out[1]);
        bool tbnz_ok = d0 && d0->mnemonic == Mnemonic::TBNZ;
        bool imm_ok  = ((static_cast<int32_t>(out[0] << 13) >> 18) == 2);
        bool b_ok    = d1 && d1->mnemonic == Mnemonic::B
                       && (out[1] & 0xFC000000u) == 0x14000000u;
        int32_t imm26 = static_cast<int32_t>(out[1] << 6) >> 6;
        int64_t target = static_cast<int64_t>(0x11000 + 4) + (static_cast<int64_t>(imm26) << 2);
        if (tbnz_ok && imm_ok && b_ok && target == 0x1008) { passed++; }
        else { failures++; std::cerr << "  FAIL: TBZ out-of-range expansion" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: TBZ out-of-range count" << std::endl; }

    // Regression: B.EQ within imm19 range still emits a single instruction.
    ok = relocate_instruction(0x54000040, 0x1000, 0x2000, out, &count);
    if (ok && count == 1) {
        auto d = decode(out[0]);
        if (d && d->mnemonic == Mnemonic::B
            && (out[0] & 0xFF000010u) == 0x54000000u
            && (out[0] & 0xFu) == 0) { passed++; }  // still EQ
        else { failures++; std::cerr << "  FAIL: B.EQ in-range single-insn" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B.EQ in-range count" << std::endl; }

    // Beyond imm26 (delta > 128 MiB) → Tier 3: inverted guard + absolute veneer.
    // target for 0x54000040 at 0x1000 is 0x1008.
    ok = relocate_instruction(0x54000040, 0x1000, 0x10001000, out, &count);
    if (ok && count == 5) {
        auto g = decode(out[0]);   // B.NE guard (skips the 5-word veneer)
        auto l = decode(out[1]);   // LDR X16, [PC, #8]
        auto b = decode(out[2]);   // BR X16
        uint64_t tgt = static_cast<uint64_t>(out[3]) | (static_cast<uint64_t>(out[4]) << 32);
        if (g && g->mnemonic == Mnemonic::B && g->condition == Condition::NE
            && l && l->mnemonic == Mnemonic::LDR
            && b && b->mnemonic == Mnemonic::BR
            && tgt == 0x1008) { passed++; }
        else { failures++; std::cerr << "  FAIL: B.EQ beyond imm26 veneer" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B.EQ beyond imm26 count" << std::endl; }

    // B.AL +8 (cond=14): inversion would yield NV; collapse to plain B.
    ok = relocate_instruction(0x5400004E, 0x1000, 0x102000, out, &count);
    if (ok && count == 1) {
        auto d = decode(out[0]);
        bool b_ok = d && d->mnemonic == Mnemonic::B
                    && (out[0] & 0xFC000000u) == 0x14000000u;
        int32_t imm26 = static_cast<int32_t>(out[0] << 6) >> 6;
        int64_t target = static_cast<int64_t>(0x102000) + (static_cast<int64_t>(imm26) << 2);
        if (b_ok && target == 0x1008) { passed++; }
        else { failures++; std::cerr << "  FAIL: B.AL collapse to B" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B.AL collapse count" << std::endl; }
}

// Exercises all three expansion tiers (native field / imm26 guard+B / absolute
// veneer) for every short-branch class, using the real BaseThreadInitThunk CBNZ
// plus its siblings. Verification decodes each emitted word rather than matching
// raw bits.
void test_relocate_expansion_tiers() {
    std::cout << "Testing relocate_instruction expansion tiers..." << std::endl;
    uint32_t out[8];
    size_t count;
    bool ok;

    // Read a branch's PC-relative displacement (bytes) from its decoded operand.
    auto rel_bytes = [](const Instruction& in) -> int64_t {
        for (const auto& op : in.operands)
            if (op.type == OperandType::Relative) return static_cast<int64_t>(op.iv.value);
        return INT64_MIN;
    };

    // --- Real BaseThreadInitThunk CBNZ: 0x35000240 = cbnz w0, +0x48 ---
    const uint64_t bti_pc  = 0x00007ffc94ed870cULL;
    const uint64_t bti_tgt = 0x00007ffc94ed8754ULL;  // bti_pc + 0x48

    // Tier 1: near trampoline — single CBNZ, target preserved.
    ok = relocate_instruction(0x35000240, bti_pc, bti_pc - 0x1000, out, &count);
    if (ok && count == 1) {
        auto d = decode(out[0]);
        uint64_t tgt = d ? (bti_pc - 0x1000) + static_cast<uint64_t>(rel_bytes(*d)) : 0;
        if (d && d->mnemonic == Mnemonic::CBNZ && tgt == bti_tgt) { passed++; }
        else { failures++; std::cerr << "  FAIL: CBNZ tier1" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: CBNZ tier1 count" << std::endl; }

    // Tier 2: 2 MiB away — inverted CBZ guard (skip 8) then B to target.
    ok = relocate_instruction(0x35000240, bti_pc, bti_pc - 0x200000, out, &count);
    if (ok && count == 2) {
        auto g = decode(out[0]); auto b = decode(out[1]);
        uint64_t tgt = b ? (bti_pc - 0x200000 + 4) + static_cast<uint64_t>(rel_bytes(*b)) : 0;
        if (g && g->mnemonic == Mnemonic::CBZ && rel_bytes(*g) == 8
            && b && b->mnemonic == Mnemonic::B && (out[1] & 0xFC000000u) == 0x14000000u
            && tgt == bti_tgt) { passed++; }
        else { failures++; std::cerr << "  FAIL: CBNZ tier2" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: CBNZ tier2 count" << std::endl; }

    // Tier 3: >128 MiB away — inverted CBZ guard (skip 20) then LDR X16/BR X16/.quad.
    ok = relocate_instruction(0x35000240, bti_pc, bti_pc - 0x8001000, out, &count);
    if (ok && count == 5) {
        auto g = decode(out[0]); auto l = decode(out[1]); auto b = decode(out[2]);
        uint64_t tgt = static_cast<uint64_t>(out[3]) | (static_cast<uint64_t>(out[4]) << 32);
        if (g && g->mnemonic == Mnemonic::CBZ && rel_bytes(*g) == 20
            && l && l->mnemonic == Mnemonic::LDR
            && b && b->mnemonic == Mnemonic::BR
            && tgt == bti_tgt) { passed++; }
        else { failures++; std::cerr << "  FAIL: CBNZ tier3" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: CBNZ tier3 count" << std::endl; }

    // --- Sibling coverage: force Tier 3 (old_pc high, new_pc 0) and verify the
    //     inverted guard mnemonic/condition + veneer + reconstructed target. ---
    const uint64_t hi   = 0x10000000ULL;   // old_pc
    const uint64_t tgt8 = hi + 8;          // +8 branch target

    auto check_tier3 = [&](const char* name, uint32_t insn, Mnemonic exp_mn,
                           Condition exp_cond) {
        uint32_t o[8]; size_t c;
        bool k = relocate_instruction(insn, hi, 0, o, &c);
        auto g = decode(o[0]); auto l = decode(o[1]); auto b = decode(o[2]);
        uint64_t tgt = static_cast<uint64_t>(o[3]) | (static_cast<uint64_t>(o[4]) << 32);
        bool good = k && c == 5
            && g && g->mnemonic == exp_mn && rel_bytes(*g) == 20
            && (exp_cond == Condition::None || g->condition == exp_cond)
            && l && l->mnemonic == Mnemonic::LDR
            && b && b->mnemonic == Mnemonic::BR
            && tgt == tgt8;
        if (good) { passed++; }
        else { failures++; std::cerr << "  FAIL: tier3 " << name << std::endl; }
    };

    check_tier3("CBZ->CBNZ",   0x34000040, Mnemonic::CBNZ, Condition::None);  // cbz  w0,+8
    check_tier3("CBNZ->CBZ",   0x35000040, Mnemonic::CBZ,  Condition::None);  // cbnz w0,+8
    check_tier3("B.EQ->B.NE",  0x54000040, Mnemonic::B,    Condition::NE);    // b.eq  +8
    check_tier3("BC.EQ->BC.NE",0x54000050, Mnemonic::BC,   Condition::NE);    // bc.eq +8
    check_tier3("TBZ->TBNZ",   0x36000040, Mnemonic::TBNZ, Condition::None);  // tbz  w0,#0,+8
    check_tier3("TBNZ->TBZ",   0x37000040, Mnemonic::TBZ,  Condition::None);  // tbnz w0,#0,+8

    // Unconditional B beyond imm26 → bare veneer (no guard), 4 words.
    ok = relocate_instruction(0x14000002 /* b +8 */, hi, 0, out, &count);
    if (ok && count == 4) {
        auto l = decode(out[0]); auto b = decode(out[1]);
        uint64_t tgt = static_cast<uint64_t>(out[2]) | (static_cast<uint64_t>(out[3]) << 32);
        if (l && l->mnemonic == Mnemonic::LDR && b && b->mnemonic == Mnemonic::BR
            && tgt == tgt8) { passed++; }
        else { failures++; std::cerr << "  FAIL: B veneer" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B veneer count" << std::endl; }

    // B.AL beyond imm26 → bare veneer (always-taken, no guard), 4 words.
    ok = relocate_instruction(0x5400004E /* b.al +8 */, hi, 0, out, &count);
    if (ok && count == 4) {
        auto l = decode(out[0]); auto b = decode(out[1]);
        uint64_t tgt = static_cast<uint64_t>(out[2]) | (static_cast<uint64_t>(out[3]) << 32);
        if (l && l->mnemonic == Mnemonic::LDR && b && b->mnemonic == Mnemonic::BR
            && tgt == tgt8) { passed++; }
        else { failures++; std::cerr << "  FAIL: B.AL veneer" << std::endl; }
    } else { failures++; std::cerr << "  FAIL: B.AL veneer count" << std::endl; }

    // BL beyond imm26 → unsupported (a veneer would corrupt the link register).
    ok = relocate_instruction(0x94000002 /* bl +8 */, hi, 0, out, &count);
    if (!ok && count == 0) { passed++; }
    else { failures++; std::cerr << "  FAIL: BL beyond imm26 must fail" << std::endl; }
}

int main() {
    std::cout << "Running relocation tests..." << std::endl;
    test_is_pc_relative();
    test_can_relocate();
    test_relocate_instruction();
    test_relocate_expansion_tiers();
    std::cout << passed << " / " << (passed + failures) << " relocation tests passed" << std::endl;
    return failures ? 1 : 0;
}

#else // !VEDA64_HOOK

#include <cstdio>
int main() {
    printf("Relocation tests skipped (VEDA64_HOOK not set)\n");
    return 0;
}

#endif
