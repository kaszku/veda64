// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_HOOK

#include "veda64.hpp"
#include <veda64/branch_follow.hpp>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>

using namespace veda64;

static int failures = 0;
static int passed = 0;

void test_classify_flow() {
    std::cout << "Testing classify_flow..." << std::endl;

    // B .+0x100 (unconditional branch)
    auto fi = classify_flow(0x14000040, 0x1000);
    if (fi.type == FlowType::Branch && fi.target == 0x1100 && !fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: B classification" << std::endl; }

    // BL .+0x100 (call)
    fi = classify_flow(0x94000040, 0x1000);
    if (fi.type == FlowType::Call && fi.target == 0x1100 && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: BL classification" << std::endl; }

    // BR X0 (indirect branch)
    fi = classify_flow(0xD61F0000, 0x1000);
    if (fi.type == FlowType::Branch && fi.is_indirect && !fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: BR classification" << std::endl; }

    // RET
    fi = classify_flow(0xD65F03C0, 0x1000);
    if (fi.type == FlowType::Return && !fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: RET classification" << std::endl; }

    // ADD X0, X1, X2 (sequential)
    fi = classify_flow(0x8B020020, 0x1000);
    if (fi.type == FlowType::Sequential && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: ADD classification" << std::endl; }

    // BRK #0
    fi = classify_flow(0xD4200000, 0x1000);
    if (fi.type == FlowType::Exception && !fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: BRK classification" << std::endl; }

    // SVC #0 (exception but falls through)
    fi = classify_flow(0xD4000001, 0x1000);
    if (fi.type == FlowType::Exception && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: SVC classification" << std::endl; }

    // B.EQ .+0x8 (conditional branch)
    fi = classify_flow(0x54000040, 0x1000);
    if (fi.type == FlowType::ConditionalBranch && fi.target == 0x1008 && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: B.EQ classification" << std::endl; }

    // CBZ X0, .+0x10
    fi = classify_flow(0xB4000080, 0x2000);
    if (fi.type == FlowType::ConditionalBranch && fi.target == 0x2010 && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: CBZ classification" << std::endl; }

    // CBNZ W0, .+0x8
    fi = classify_flow(0x35000040, 0x3000);
    if (fi.type == FlowType::ConditionalBranch && fi.target == 0x3008 && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: CBNZ classification" << std::endl; }

    // TBZ W0, #0, .+0x8
    fi = classify_flow(0x36000040, 0x4000);
    if (fi.type == FlowType::ConditionalBranch && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: TBZ classification" << std::endl; }

    // BLR X0 (indirect call)
    fi = classify_flow(0xD63F0000, 0x1000);
    if (fi.type == FlowType::Call && fi.is_indirect && fi.has_fallthrough)
        { passed++; } else { failures++; std::cerr << "  FAIL: BLR classification" << std::endl; }
}

void test_walk_basic_block() {
    std::cout << "Testing walk_basic_block..." << std::endl;

    // Simple block: ADD, SUB, RET
    std::vector<uint32_t> code_buf = {
        0x8B020020,  // add x0, x1, x2
        0xCB030041,  // sub x1, x2, x3
        0xD65F03C0   // ret
    };
    auto reader = [&](uint64_t addr) -> uint32_t {
        size_t idx = static_cast<size_t>((addr - 0x1000) / 4);
        return idx < code_buf.size() ? code_buf[idx] : 0;
    };
    auto bb = walk_basic_block(0x1000, reader);
    if (bb.start == 0x1000 && bb.end == 0x100C && bb.instructions.size() == 3)
        { passed++; } else { failures++; std::cerr << "  FAIL: basic block walk" << std::endl; }
    if (bb.successors.empty())
        { passed++; } else { failures++; std::cerr << "  FAIL: RET has no successors" << std::endl; }
}

void test_walk_cfg() {
    std::cout << "Testing walk_cfg..." << std::endl;

    // Two blocks: B.EQ jumps forward, both paths end in RET
    // 0x1000: CMP X0, #0
    // 0x1004: B.EQ .+0x8  -> 0x100C
    // 0x1008: RET  (fallthrough)
    // 0x100C: RET  (branch target)
    std::vector<uint32_t> code_buf = {
        0xF100001F,  // cmp x0, #0
        0x54000040,  // b.eq .+0x8
        0xD65F03C0,  // ret
        0xD65F03C0   // ret
    };
    auto reader = [&](uint64_t addr) -> uint32_t {
        size_t idx = static_cast<size_t>((addr - 0x1000) / 4);
        return idx < code_buf.size() ? code_buf[idx] : 0;
    };
    auto blocks = walk_cfg(0x1000, reader);
    if (blocks.size() == 3)  // entry block + fallthrough + branch target
        { passed++; } else { failures++; std::cerr << "  FAIL: CFG block count (got " << blocks.size() << ")" << std::endl; }
}

int main() {
    std::cout << "Running branch following tests..." << std::endl;
    test_classify_flow();
    test_walk_basic_block();
    test_walk_cfg();
    std::cout << passed << " / " << (passed + failures) << " branch following tests passed" << std::endl;
    return failures ? 1 : 0;
}

#else // !VEDA64_HOOK

#include <cstdio>
int main() {
    printf("Branch follow tests skipped (VEDA64_HOOK not set)\n");
    return 0;
}

#endif
