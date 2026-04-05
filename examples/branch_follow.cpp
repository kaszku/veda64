// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

// Control flow analysis (branch following) example
// Build with: -DVEDA64_STRINGS=ON -DVEDA64_HOOK=ON

#ifdef VEDA64_HOOK

#include "veda64.hpp"
#include <veda64/branch_follow.hpp>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace veda64;

int main() {
    std::cout << "=== Branch Following Example ===" << std::endl;

    // Example 1: Classify individual instructions
    struct { uint32_t insn; const char* desc; } cases[] = {
        {0x14000040, "B .+0x100"},
        {0x94000040, "BL .+0x100"},
        {0xD61F0000, "BR X0"},
        {0xD65F03C0, "RET"},
        {0x54000040, "B.EQ .+0x8"},
        {0xB4000040, "CBZ X0, .+0x8"},
        {0x8B020020, "ADD X0, X1, X2"},
    };
    const char* flow_names[] = {"Sequential", "Branch", "Call", "ConditionalBranch", "Return", "Exception", "Unknown"};

    for (auto& c : cases) {
        auto fi = classify_flow(c.insn, 0x1000);
        std::cout << "  " << c.desc << " => " << flow_names[static_cast<int>(fi.type)]
                  << (fi.is_indirect ? " (indirect)" : "")
                  << std::endl;
    }

    // Example 2: Walk a basic block
    std::vector<uint32_t> code_buf = {
        0x8B020020,  // add x0, x1, x2
        0xCB030041,  // sub x1, x2, x3
        0x91000800,  // add x0, x0, #2
        0xD65F03C0   // ret
    };
    auto reader = [&](uint64_t addr) -> uint32_t {
        size_t idx = static_cast<size_t>((addr - 0x1000) / 4);
        return idx < code_buf.size() ? code_buf[idx] : 0;
    };
    auto bb = walk_basic_block(0x1000, reader);
    std::cout << "  Basic block: 0x" << std::hex << bb.start
              << " - 0x" << bb.end << std::dec
              << " (" << bb.instructions.size() << " instructions)"
              << std::endl;

    // Example 3: Walk a CFG
    std::vector<uint32_t> cfg_buf = {
        0xF100001F,  // cmp x0, #0
        0x54000040,  // b.eq .+0x8
        0xD65F03C0,  // ret (fallthrough)
        0x91000400,  // add x0, x0, #1
        0xD65F03C0   // ret (branch target)
    };
    auto cfg_reader = [&](uint64_t addr) -> uint32_t {
        size_t idx = static_cast<size_t>((addr - 0x2000) / 4);
        return idx < cfg_buf.size() ? cfg_buf[idx] : 0;
    };
    auto blocks = walk_cfg(0x2000, cfg_reader);
    std::cout << "  CFG: " << blocks.size() << " blocks" << std::endl;
    for (const auto& b : blocks) {
        std::cout << "    [0x" << std::hex << b.start << " - 0x" << b.end << std::dec
                  << "] " << b.instructions.size() << " insns, "
                  << b.successors.size() << " successors" << std::endl;
    }

    std::cout << "Done!" << std::endl;
    return 0;
}

#else // !VEDA64_HOOK

#include <cstdio>
int main() {
    printf("Branch follow example skipped (VEDA64_HOOK not set)\n");
    return 0;
}

#endif
