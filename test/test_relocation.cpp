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
