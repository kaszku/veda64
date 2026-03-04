// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifndef VEDA64_NO_IR

#include "veda64/ir.hpp"
#include <cstdio>
#include <cassert>

using namespace veda64;
using namespace veda64::ir;

static int tests_run = 0;
static int tests_passed = 0;

static void run_tests() {
    // GP register add
    {
        tests_run++;
        printf("  %-40s ", "ADD_X0_X1_X2");
        auto r = lift(0x8B020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::ADD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected ADD\n");
            }
        }
    }
    // GP register sub
    {
        tests_run++;
        printf("  %-40s ", "SUB_X0_X1_X2");
        auto r = lift(0xCB020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SUB) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SUB\n");
            }
        }
    }
    // GP register add with flags
    {
        tests_run++;
        printf("  %-40s ", "ADDS_X0_X1_X2");
        auto r = lift(0xAB020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::ADD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected ADD\n");
            }
        }
    }
    // GP register AND
    {
        tests_run++;
        printf("  %-40s ", "AND_X0_X1_X2");
        auto r = lift(0x8A020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::AND) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected AND\n");
            }
        }
    }
    // GP register ORR
    {
        tests_run++;
        printf("  %-40s ", "ORR_X0_X1_X2");
        auto r = lift(0xAA020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::OR) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected OR\n");
            }
        }
    }
    // GP register EOR
    {
        tests_run++;
        printf("  %-40s ", "EOR_X0_X1_X2");
        auto r = lift(0xCA020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::XOR) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected XOR\n");
            }
        }
    }
    // GP immediate add
    {
        tests_run++;
        printf("  %-40s ", "ADD_X0_X1_imm42");
        auto r = lift(0x91010820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::ADD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected ADD\n");
            }
        }
    }
    // GP immediate sub
    {
        tests_run++;
        printf("  %-40s ", "SUB_X0_X1_imm42");
        auto r = lift(0xD1010820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SUB) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SUB\n");
            }
        }
    }
    // Move wide immediate
    {
        tests_run++;
        printf("  %-40s ", "MOVZ_X0_0x1234");
        auto r = lift(0xD2824680);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::COPY) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected COPY\n");
            }
        }
    }
    // Signed divide
    {
        tests_run++;
        printf("  %-40s ", "SDIV_X0_X1_X2");
        auto r = lift(0x9AC20C20);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SDIV) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SDIV\n");
            }
        }
    }
    // Unsigned divide
    {
        tests_run++;
        printf("  %-40s ", "UDIV_X0_X1_X2");
        auto r = lift(0x9AC20820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::UDIV) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected UDIV\n");
            }
        }
    }
    // Multiply-add
    {
        tests_run++;
        printf("  %-40s ", "MADD_X0_X1_X2_X3");
        auto r = lift(0x9B020C20);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::MUL) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected MUL\n");
            }
        }
    }
    // Load 64-bit unsigned offset
    {
        tests_run++;
        printf("  %-40s ", "LDR_X0_X1_8");
        auto r = lift(0xF9400420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::LOAD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected LOAD\n");
            }
        }
    }
    // Store 64-bit unsigned offset
    {
        tests_run++;
        printf("  %-40s ", "STR_X0_X1_8");
        auto r = lift(0xF9000420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::STORE) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected STORE\n");
            }
        }
    }
    // Unconditional branch
    {
        tests_run++;
        printf("  %-40s ", "B_0x100");
        auto r = lift(0x14000040);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::BRANCH) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected BRANCH\n");
            }
        }
    }
    // Branch with link
    {
        tests_run++;
        printf("  %-40s ", "BL_0x100");
        auto r = lift(0x94000040);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CALL) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected CALL\n");
            }
        }
    }
    // Return
    {
        tests_run++;
        printf("  %-40s ", "RET");
        auto r = lift(0xD65F03C0);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::RET) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected RET\n");
            }
        }
    }
    // Compare and branch zero
    {
        tests_run++;
        printf("  %-40s ", "CBZ_X0");
        auto r = lift(0xB4000080);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CMP_EQ) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected CMP_EQ\n");
            }
        }
    }
    // Compare and branch non-zero
    {
        tests_run++;
        printf("  %-40s ", "CBNZ_X0");
        auto r = lift(0xB5000080);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CMP_NE) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected CMP_NE\n");
            }
        }
    }
    // No operation
    {
        tests_run++;
        printf("  %-40s ", "NOP");
        auto r = lift(0xD503201F);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::NOP) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected NOP\n");
            }
        }
    }
    // 32-bit register add
    {
        tests_run++;
        printf("  %-40s ", "ADD_W0_W1_W2");
        auto r = lift(0x0B020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::ADD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected ADD\n");
            }
        }
    }
    // GP sub with flags
    {
        tests_run++;
        printf("  %-40s ", "SUBS_X0_X1_X2");
        auto r = lift(0xEB020020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SUB) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SUB\n");
            }
        }
    }
    // SIMD ADD V0.4S produces VEXTRACT_ELEM
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_V0_4S");
        auto r = lift(0x4EA28420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected VEXTRACT_ELEM\n");
            }
        }
    }
    // SIMD ADD V0.16B produces VEXTRACT_ELEM
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_V0_16B");
        auto r = lift(0x4E228420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected VEXTRACT_ELEM\n");
            }
        }
    }
    // SIMD SUB V0.4S produces VEXTRACT_ELEM
    {
        tests_run++;
        printf("  %-40s ", "SIMD_SUB_V0_4S");
        auto r = lift(0x6EA28420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected VEXTRACT_ELEM\n");
            }
        }
    }
    // SIMD FNEG V0.4S unary unrolling
    {
        tests_run++;
        printf("  %-40s ", "SIMD_FNEG_V0_4S");
        auto r = lift(0x6EA0F820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected VEXTRACT_ELEM\n");
            }
        }
    }

    // SIMD ADD V0.4S should have exactly 4 VEXTRACT_ELEM ops
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_4S_lane_count");
        auto r = lift(0x4EA28420);  // ADD V0.4S, V1.4S, V2.4S
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            int extract_count = 0;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) extract_count++;
            }
            if (extract_count == 8) {  // 4 lanes x 2 sources
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected 8 VEXTRACT_ELEM, got %d\n", extract_count);
            }
        }
    }

    // SIMD ADD V0.16B should have exactly 16 VEXTRACT_ELEM ops (16 lanes x 2 srcs = 32)
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_16B_lane_count");
        auto r = lift(0x4E228420);  // ADD V0.16B, V1.16B, V2.16B
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            int extract_count = 0;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) extract_count++;
            }
            if (extract_count == 32) {  // 16 lanes x 2 sources
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected 32 VEXTRACT_ELEM, got %d\n", extract_count);
            }
        }
    }

    // SIMD FNEG V0.4S unary should have 4 VEXTRACT_ELEM ops
    {
        tests_run++;
        printf("  %-40s ", "SIMD_FNEG_4S_lane_count");
        auto r = lift(0x6EA0F820);  // FNEG V0.4S, V1.4S
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            int extract_count = 0;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) extract_count++;
            }
            if (extract_count == 4) {  // 4 lanes x 1 source
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected 4 VEXTRACT_ELEM, got %d\n", extract_count);
            }
        }
    }

    // to_string test
    {
        tests_run++;
        printf("  %-40s ", "to_string");
        auto r = lift(0x8B020020);
        if (r.has_value()) {
            auto s = to_string(*r);
            if (!s.empty()) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: empty string\n");
            }
        } else {
            printf("FAIL: lift returned nullopt\n");
        }
    }

    // UDF instruction returns UNDEF opcode
    {
        tests_run++;
        printf("  %-40s ", "UDF_0x00000000");
        auto r = lift(0x00000000);
        if (r.has_value() && r->ops.size() > 0 && r->ops[0].opcode == Opcode::UNDEF) {
            printf("PASS\n");
            tests_passed++;
        } else if (!r.has_value()) {
            printf("PASS\n"); // also acceptable
            tests_passed++;
        } else {
            printf("FAIL: expected UNDEF or nullopt\n");
        }
    }
}

int main() {
    printf("=== IR Lifting Tests ===\n");
    run_tests();
    printf("\n%d/%d tests passed\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}

#else // VEDA64_NO_IR

#include <cstdio>
int main() {
    printf("IR tests skipped (VEDA64_NO_IR)\n");
    return 0;
}

#endif
