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
    uint32_t out[4];
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

    // Beyond imm26 too (delta > 128 MiB) → still fails.
    ok = relocate_instruction(0x54000040, 0x1000, 0x10001000, out, &count);
    if (!ok && count == 0) { passed++; }
    else { failures++; std::cerr << "  FAIL: B.EQ beyond imm26 should fail" << std::endl; }

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

int main() {
    std::cout << "Running relocation tests..." << std::endl;
    test_is_pc_relative();
    test_can_relocate();
    test_relocate_instruction();
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
