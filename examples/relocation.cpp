// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

// Instruction relocation API example
// Build with: -DVEDA64_STRINGS=ON

#include "veda64.hpp"
#include <veda64/relocation.hpp>
#include <iostream>
#include <cstdint>

using namespace veda64;

int main() {
    std::cout << "=== Relocation API Example ===" << std::endl;

    // Example 1: Check which instructions are PC-relative
    uint32_t instructions[] = {
        0x14000040,  // B .+0x100
        0x94000040,  // BL .+0x100
        0x8B020020,  // ADD X0, X1, X2
        0x54000040,  // B.EQ .+0x8
        0x10000800,  // ADR X0, .+0x100
        0xD65F03C0,  // RET
    };

    for (auto insn : instructions) {
#ifdef VEDA64_STRINGS
        auto d = decode(insn);
        std::cout << "  " << (d ? d->to_string() : "???")
                  << " — PC-relative: " << (is_pc_relative(insn) ? "yes" : "no")
                  << ", relocatable: " << (can_relocate(insn) ? "yes" : "no")
                  << std::endl;
#else
        std::cout << "  0x" << std::hex << insn << std::dec
                  << " — PC-relative: " << (is_pc_relative(insn) ? "yes" : "no")
                  << std::endl;
#endif
    }

    // Example 2: Relocate a B instruction
    uint32_t out[4];
    size_t count;
    uint32_t b_insn = 0x14000040;  // B .+0x100 (at 0x1000)
    if (relocate_instruction(b_insn, 0x1000, 0x5000, out, &count)) {
        std::cout << "  Relocated B from 0x1000 to 0x5000:" << std::endl;
        for (size_t i = 0; i < count; i++) {
#ifdef VEDA64_STRINGS
            auto d = decode(out[i]);
            std::cout << "    " << (d ? d->to_string() : "???") << std::endl;
#else
            std::cout << "    0x" << std::hex << out[i] << std::dec << std::endl;
#endif
        }
    }

    std::cout << "Done!" << std::endl;
    return 0;
}
