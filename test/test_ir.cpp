// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifndef VEDA64_NO_IR

#include "veda64/ir.hpp"
#include "veda64.hpp"
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
    // Variable shift left
    {
        tests_run++;
        printf("  %-40s ", "LSL_X0_X1_X2");
        auto r = lift(0x9AC22020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SHL) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SHL\n");
            }
        }
    }
    // Variable shift right
    {
        tests_run++;
        printf("  %-40s ", "LSR_X0_X1_X2");
        auto r = lift(0x9AC22420);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SHR) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SHR\n");
            }
        }
    }
    // Arithmetic shift right
    {
        tests_run++;
        printf("  %-40s ", "ASR_X0_X1_X2");
        auto r = lift(0x9AC22820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::SAR) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected SAR\n");
            }
        }
    }
    // Unsigned bitfield extract
    {
        tests_run++;
        printf("  %-40s ", "UBFX_X0_X1");
        auto r = lift(0xD3407C20);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::EXTRACT) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected EXTRACT\n");
            }
        }
    }
    // Conditional select expands NE condition
    {
        tests_run++;
        printf("  %-40s ", "CSEL_X0_X1_X2");
        auto r = lift(0x9A821020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::NOT) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected NOT\n");
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
    // Load pair
    {
        tests_run++;
        printf("  %-40s ", "LDP_X29_X30_SP");
        auto r = lift(0xA9407BFD);
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
    // Store pair
    {
        tests_run++;
        printf("  %-40s ", "STP_X29_X30_SP");
        auto r = lift(0xA9007BFD);
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
    // Conditional branch B.NE
    {
        tests_run++;
        printf("  %-40s ", "B_NE");
        auto r = lift(0x54000041);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CBRANCH) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected CBRANCH\n");
            }
        }
    }
    // Test bit and branch zero
    {
        tests_run++;
        printf("  %-40s ", "TBZ_W0_2");
        auto r = lift(0x36100060);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CBRANCH) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected CBRANCH\n");
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
    // DSB barrier maps to NOP
    {
        tests_run++;
        printf("  %-40s ", "DSB_SY");
        auto r = lift(0xD5033F9F);
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
    // Scalar FP add
    {
        tests_run++;
        printf("  %-40s ", "FADD_S0_S1_S2");
        auto r = lift(0x1E222820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::FADD) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected FADD\n");
            }
        }
    }
    // Scalar FP div
    {
        tests_run++;
        printf("  %-40s ", "FDIV_D0_D1_D2");
        auto r = lift(0x1E621820);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::FDIV) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected FDIV\n");
            }
        }
    }
    // Int to float convert
    {
        tests_run++;
        printf("  %-40s ", "SCVTF_S0_X1");
        auto r = lift(0x9E220020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::INT2FLOAT) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected INT2FLOAT\n");
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
    // SIMD MUL V0.4S unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_MUL_4S");
        auto r = lift(0x4EA29C20);
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
    // SIMD AND V0.16B unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_AND_16B");
        auto r = lift(0x4E221C20);
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
    // SIMD ORR V0.16B unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ORR_16B");
        auto r = lift(0x4EA21C20);
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
    // SIMD EOR V0.16B unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_EOR_16B");
        auto r = lift(0x6E221C20);
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
    // SIMD FMUL V0.4S unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_FMUL_4S");
        auto r = lift(0x6E22DC20);
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
    // SIMD NOT V0.16B unrolled
    {
        tests_run++;
        printf("  %-40s ", "SIMD_NOT_16B");
        auto r = lift(0x6E205820);
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
    // Atomic LDADD returns UNDEF
    {
        tests_run++;
        printf("  %-40s ", "LDADD_W0");
        auto r = lift(0xB8200020);
        if (!r.has_value()) {
            printf("FAIL: lift returned nullopt\n");
        } else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::UNDEF) found = true;
            }
            if (found) {
                printf("PASS\n");
                tests_passed++;
            } else {
                printf("FAIL: expected UNDEF\n");
            }
        }
    }

    // SIMD_ADD_4S_lane_count
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_4S_lane_count");
        auto r = lift(0x4EA28420);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            int c = 0;
            for (auto& op : r->ops) if (op.opcode == Opcode::VEXTRACT_ELEM) c++;
            if (c == 8) { printf("PASS\n"); tests_passed++; }
            else printf("FAIL: expected 8, got %d\n", c);
        }
    }

    // SIMD_ADD_16B_lane_count
    {
        tests_run++;
        printf("  %-40s ", "SIMD_ADD_16B_lane_count");
        auto r = lift(0x4E228420);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            int c = 0;
            for (auto& op : r->ops) if (op.opcode == Opcode::VEXTRACT_ELEM) c++;
            if (c == 32) { printf("PASS\n"); tests_passed++; }
            else printf("FAIL: expected 32, got %d\n", c);
        }
    }

    // SIMD_FNEG_4S_lane_count
    {
        tests_run++;
        printf("  %-40s ", "SIMD_FNEG_4S_lane_count");
        auto r = lift(0x6EA0F820);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            int c = 0;
            for (auto& op : r->ops) if (op.opcode == Opcode::VEXTRACT_ELEM) c++;
            if (c == 4) { printf("PASS\n"); tests_passed++; }
            else printf("FAIL: expected 4, got %d\n", c);
        }
    }

    // simplify_ADD_X0_X1_X2
    {
        tests_run++;
        printf("  %-40s ", "simplify_ADD_X0_X1_X2");
        auto raw = lift(0x8B020020);
        if (!raw.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            auto sim = simplify(*raw);
            if (sim.ops.size() == 1 && sim.ops[0].opcode == Opcode::ADD
                && sim.ops[0].output.space == Space::GPR && sim.ops[0].output.offset == 0
                && sim.ops[0].inputs[0].space == Space::GPR && sim.ops[0].inputs[0].offset == 1
                && sim.ops[0].inputs[1].space == Space::GPR && sim.ops[0].inputs[1].offset == 2) {
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: ops=%zu opc=%d out=%d/%d in0=%d/%d in1=%d/%d\n",
                    sim.ops.size(),
                    sim.ops.empty() ? -1 : (int)sim.ops[0].opcode,
                    sim.ops.empty() ? -1 : (int)sim.ops[0].output.space, sim.ops.empty() ? -1 : (int)sim.ops[0].output.offset,
                    sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[0].space, sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[0].offset,
                    sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[1].space, sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[1].offset);
            }
        }
    }

    // simplify_MADD
    {
        tests_run++;
        printf("  %-40s ", "simplify_MADD");
        auto raw = lift(0x9B020C20);
        if (!raw.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            auto sim = simplify(*raw);
            if (sim.ops.size() == 2 && sim.ops[0].opcode == Opcode::MUL && sim.ops[1].opcode == Opcode::ADD) {
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: ops=%zu\n", sim.ops.size());
            }
        }
    }

    // simplify_SDIV
    {
        tests_run++;
        printf("  %-40s ", "simplify_SDIV");
        auto raw = lift(0x9AC20C20);
        if (!raw.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            auto sim = simplify(*raw);
            if (sim.ops.size() == 1 && sim.ops[0].opcode == Opcode::SDIV) {
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: ops=%zu opc=%d\n", sim.ops.size(), sim.ops.empty() ? -1 : (int)sim.ops[0].opcode);
            }
        }
    }

    // simplify_MOVZ_value
    {
        tests_run++;
        printf("  %-40s ", "simplify_MOVZ_value");
        auto raw = lift(0xD2824680);
        if (!raw.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            auto sim = simplify(*raw);
            if (sim.ops.size() == 1 && sim.ops[0].opcode == Opcode::COPY
                && sim.ops[0].output.space == Space::GPR
                && sim.ops[0].inputs[0].value == 0x1234) {
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: ops=%zu val=%lld\n", sim.ops.size(),
                    sim.ops.empty() ? -1LL : (long long)sim.ops[0].inputs[0].value);
            }
        }
    }

    // esize_ADD_4S
    {
        tests_run++;
        printf("  %-40s ", "esize_ADD_4S");
        auto r = lift(0x4EA28420);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size == 4) { found = true; break; }
                    else { printf("FAIL: esize=%d expected 4\n", op.output.size); break; }
                }
            }
            if (found) { printf("PASS\n"); tests_passed++; }
            else if (!found) { printf("FAIL: no VEXTRACT_ELEM found\n"); }
        }
    }

    // esize_SUB_2D
    {
        tests_run++;
        printf("  %-40s ", "esize_SUB_2D");
        auto r = lift(0x6EE28420);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size == 8) { found = true; break; }
                    else { printf("FAIL: esize=%d expected 8\n", op.output.size); break; }
                }
            }
            if (found) { printf("PASS\n"); tests_passed++; }
            else if (!found) { printf("FAIL: no VEXTRACT_ELEM found\n"); }
        }
    }

    // esize_AND_16B
    {
        tests_run++;
        printf("  %-40s ", "esize_AND_16B");
        auto r = lift(0x4E221C20);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size == 1) { found = true; break; }
                    else { printf("FAIL: esize=%d expected 1\n", op.output.size); break; }
                }
            }
            if (found) { printf("PASS\n"); tests_passed++; }
            else if (!found) { printf("FAIL: no VEXTRACT_ELEM found\n"); }
        }
    }

    // esize_FMUL_4S
    {
        tests_run++;
        printf("  %-40s ", "esize_FMUL_4S");
        auto r = lift(0x6E22DC20);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size == 4) { found = true; break; }
                    else { printf("FAIL: esize=%d expected 4\n", op.output.size); break; }
                }
            }
            if (found) { printf("PASS\n"); tests_passed++; }
            else if (!found) { printf("FAIL: no VEXTRACT_ELEM found\n"); }
        }
    }

    // esize_FNEG_4S
    {
        tests_run++;
        printf("  %-40s ", "esize_FNEG_4S");
        auto r = lift(0x6EA0F820);
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool found = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size == 4) { found = true; break; }
                    else { printf("FAIL: esize=%d expected 4\n", op.output.size); break; }
                }
            }
            if (found) { printf("PASS\n"); tests_passed++; }
            else if (!found) { printf("FAIL: no VEXTRACT_ELEM found\n"); }
        }
    }

    // regsize_ADD_X_64bit
    {
        tests_run++;
        printf("  %-40s ", "regsize_ADD_X_64bit");
        auto sim = simplify(*lift(0x8B020020));
        if (sim.ops.size() >= 1 && sim.ops[0].output.size == 8) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: size=%d\n", sim.ops.empty() ? -1 : sim.ops[0].output.size);
        }
    }

    // regsize_ADD_W_32bit
    {
        tests_run++;
        printf("  %-40s ", "regsize_ADD_W_32bit");
        auto sim = simplify(*lift(0x0B020020));
        if (sim.ops.size() >= 1 && sim.ops[0].output.size == 4) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: size=%d\n", sim.ops.empty() ? -1 : sim.ops[0].output.size);
        }
    }

    // regoffset_ADD_X5_X10_X15
    {
        tests_run++;
        printf("  %-40s ", "regoffset_ADD_X5_X10_X15");
        auto sim = simplify(*lift(0x8B0F0145));  // ADD X5, X10, X15
        if (sim.ops.size() >= 1
            && sim.ops[0].output.offset == 5
            && sim.ops[0].inputs[0].offset == 10
            && sim.ops[0].inputs[1].offset == 15) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: out=%d in0=%d in1=%d\n",
                sim.ops.empty() ? -1 : (int)sim.ops[0].output.offset,
                sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[0].offset,
                sim.ops.empty() ? -1 : (int)sim.ops[0].inputs[1].offset);
        }
    }

    // branch_offset_B_256
    {
        tests_run++;
        printf("  %-40s ", "branch_offset_B_256");
        auto sim = simplify(*lift(0x14000040));  // B .+0x100
        if (sim.ops.size() >= 1 && sim.ops[0].inputs[0].value == 256) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: val=%lld\n", sim.ops.empty() ? -1LL : (long long)sim.ops[0].inputs[0].value);
        }
    }

    // cbz_structure
    {
        tests_run++;
        printf("  %-40s ", "cbz_structure");
        auto sim = simplify(*lift(0xB4000080));  // CBZ X0
        if (sim.ops.size() == 2
            && sim.ops[0].opcode == Opcode::CMP_EQ
            && sim.ops[1].opcode == Opcode::CBRANCH) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: ops=%zu\n", sim.ops.size());
        }
    }

    // ldr_offset_8
    {
        tests_run++;
        printf("  %-40s ", "ldr_offset_8");
        auto sim = simplify(*lift(0xF9400420));  // LDR X0, [X1, #8]
        bool found_add_8 = false;
        for (auto& op : sim.ops) {
            if (op.opcode == Opcode::ADD) {
                for (int i = 0; i < 3; i++) {
                    if (op.inputs[i].space == Space::Const && op.inputs[i].value == 8) {
                        found_add_8 = true; break;
                    }
                }
            }
        }
        if (found_add_8) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: no ADD with const 8\n"); }
    }

    // ldp_two_loads
    {
        tests_run++;
        printf("  %-40s ", "ldp_two_loads");
        auto r = lift(0xA9407BFD);  // LDP X29, X30, [SP]
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            int lc = 0;
            for (auto& op : r->ops) if (op.opcode == Opcode::LOAD) lc++;
            if (lc == 2) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: load_count=%d\n", lc); }
        }
    }

    // simd_lower_half_2S
    {
        tests_run++;
        printf("  %-40s ", "simd_lower_half_2S");
        auto r = lift(0x2EA28420);  // SUB V0.2S (Q=0)
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            int extract_count = 0;
            bool esize_ok = true;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::VEXTRACT_ELEM) {
                    if (op.output.size != 4) esize_ok = false;
                    extract_count++;
                }
            }
            if (extract_count == 4 && esize_ok) {  // 2 lanes x 2 sources
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: extracts=%d esize_ok=%d\n", extract_count, esize_ok);
            }
        }
    }

    // to_string
    {
        tests_run++;
        printf("  %-40s ", "to_string");
        auto r = lift(0x8B020020);
        if (r.has_value()) {
            auto s = to_string(*r);
            if (!s.empty()) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: empty string\n"); }
        } else { printf("FAIL: lift nullopt\n"); }
    }

    // UDF_0x00000000
    {
        tests_run++;
        printf("  %-40s ", "UDF_0x00000000");
        auto r = lift(0x00000000);
        if (r.has_value() && r->ops.size() > 0 && r->ops[0].opcode == Opcode::UNDEF) {
            printf("PASS\n"); tests_passed++;
        } else if (!r.has_value()) {
            printf("PASS\n"); tests_passed++;
        } else { printf("FAIL: expected UNDEF or nullopt\n"); }
    }

    // adds_nzcv_semantic
    {
        tests_run++;
        printf("  %-40s ", "adds_nzcv_semantic");
        auto r = lift(0xAB020020);  // ADDS X0, X1, X2
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool has_n = false, has_z = false, has_c = false, has_v = false;
            for (auto& op : r->ops) {
                if (op.output.space == Space::Flags) {
                    if (op.output.offset == 0) has_n = true;
                    if (op.output.offset == 1) has_z = true;
                    if (op.output.offset == 2) has_c = true;
                    if (op.output.offset == 3) has_v = true;
                }
            }
            if (has_n && has_z && has_c && has_v) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: N=%d Z=%d C=%d V=%d\n", has_n, has_z, has_c, has_v); }
        }
    }

    // subs_semantic_opcodes
    {
        tests_run++;
        printf("  %-40s ", "subs_semantic_opcodes");
        auto r = lift(0xEB020020);  // SUBS X0, X1, X2
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool has_carry_sub = false, has_overflow_sub = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CARRY_SUB) has_carry_sub = true;
                if (op.opcode == Opcode::OVERFLOW_SUB) has_overflow_sub = true;
            }
            if (has_carry_sub && has_overflow_sub) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: carry=%d overflow=%d\n", has_carry_sub, has_overflow_sub); }
        }
    }

    // subs_expanded_no_semantic
    {
        tests_run++;
        printf("  %-40s ", "subs_expanded_no_semantic");
        auto r = lift(0xEB020020, IrDetail::Expanded);  // SUBS expanded
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool has_sem = false, has_ule = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CARRY_SUB || op.opcode == Opcode::OVERFLOW_SUB) has_sem = true;
                if (op.opcode == Opcode::CMP_ULE) has_ule = true;
            }
            if (!has_sem && has_ule) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: sem=%d ule=%d\n", has_sem, has_ule); }
        }
    }

    // bne_reads_Z_flag
    {
        tests_run++;
        printf("  %-40s ", "bne_reads_Z_flag");
        auto r = lift(0x54000041);  // B.NE
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool reads_z = false;
            for (auto& op : r->ops) {
                for (uint8_t i = 0; i < op.num_inputs; ++i) {
                    if (op.inputs[i].space == Space::Flags && op.inputs[i].offset == 1)
                        reads_z = true;
                }
            }
            if (reads_z) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: does not read Z flag\n"); }
        }
    }

    // adds_imm_carry_add
    {
        tests_run++;
        printf("  %-40s ", "adds_imm_carry_add");
        auto r = lift(0xB1000800);  // ADDS X0, X0, #2
        if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
        else {
            bool has_carry = false;
            for (auto& op : r->ops) {
                if (op.opcode == Opcode::CARRY_ADD) has_carry = true;
            }
            if (has_carry) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: no CARRY_ADD\n"); }
        }
    }

    // decode_then_lift_ADD
    {
        tests_run++;
        printf("  %-40s ", "decode_then_lift_ADD");
        auto decoded = decode(0x8B020020);
        if (!decoded) { printf("FAIL: decode nullopt\n"); }
        else {
            auto r = lift(*decoded);
            if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
            else {
                auto sim = simplify(*r);
                if (sim.ops.size() == 1 && sim.ops[0].opcode == Opcode::ADD
                    && sim.ops[0].output.space == Space::GPR && sim.ops[0].output.offset == 0
                    && sim.ops[0].inputs[0].offset == 1 && sim.ops[0].inputs[1].offset == 2) {
                    printf("PASS\n"); tests_passed++;
                } else { printf("FAIL: wrong result\n"); }
            }
        }
    }

    // decode_then_lift_LDR
    {
        tests_run++;
        printf("  %-40s ", "decode_then_lift_LDR");
        auto decoded = decode(0xF9400420);
        if (!decoded) { printf("FAIL: decode nullopt\n"); }
        else {
            auto r = lift(*decoded);
            if (!r.has_value()) { printf("FAIL: lift nullopt\n"); }
            else {
                bool found = false;
                for (auto& op : r->ops) if (op.opcode == Opcode::LOAD) found = true;
                if (found) { printf("PASS\n"); tests_passed++; }
                else { printf("FAIL: expected LOAD\n"); }
            }
        }
    }

    // decode_then_lift_B
    {
        tests_run++;
        printf("  %-40s ", "decode_then_lift_B");
        auto decoded = decode(0x14000040);
        if (!decoded) { printf("FAIL: decode nullopt\n"); }
        else {
            auto r = lift(*decoded);
            auto sim = simplify(*r);
            if (sim.ops.size() >= 1 && sim.ops[0].inputs[0].value == 256) {
                printf("PASS\n"); tests_passed++;
            } else { printf("FAIL\n"); }
        }
    }

    // ast_add_single_effect
    {
        tests_run++;
        printf("  %-40s ", "ast_add_single_effect");
        auto ast = lift_ast(0x8B020020);  // ADD X0, X1, X2
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else if (ast->effects.size() == 1
            && ast->effects[0].kind == Effect::Kind::Assign
            && ast->effects[0].dest.space == Space::GPR
            && ast->effects[0].dest.offset == 0
            && ast->effects[0].expr
            && ast->effects[0].expr->kind == Expr::Kind::Op
            && ast->effects[0].expr->opcode == Opcode::ADD) {
            printf("PASS\n"); tests_passed++;
        } else {
            printf("FAIL: effects=%zu\n", ast->effects.size());
        }
    }

    // ast_subs_five_effects
    {
        tests_run++;
        printf("  %-40s ", "ast_subs_five_effects");
        auto ast = lift_ast(0xEB020020);  // SUBS X0, X1, X2
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else {
            int assigns = 0;
            bool has_x0 = false, has_n = false, has_z = false, has_c = false, has_v = false;
            for (auto& e : ast->effects) {
                if (e.kind == Effect::Kind::Assign) {
                    assigns++;
                    if (e.dest.space == Space::GPR && e.dest.offset == 0) has_x0 = true;
                    if (e.dest.space == Space::Flags && e.dest.offset == 0) has_n = true;
                    if (e.dest.space == Space::Flags && e.dest.offset == 1) has_z = true;
                    if (e.dest.space == Space::Flags && e.dest.offset == 2) has_c = true;
                    if (e.dest.space == Space::Flags && e.dest.offset == 3) has_v = true;
                }
            }
            if (assigns == 5 && has_x0 && has_n && has_z && has_c && has_v) {
                printf("PASS\n"); tests_passed++;
            } else {
                printf("FAIL: assigns=%d x0=%d N=%d Z=%d C=%d V=%d\n", assigns, has_x0, has_n, has_z, has_c, has_v);
            }
        }
    }

    // ast_bgt_one_cbranch
    {
        tests_run++;
        printf("  %-40s ", "ast_bgt_one_cbranch");
        auto ast = lift_ast(0x5400004C);  // B.GT .+8
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else {
            int cbs = 0;
            for (auto& e : ast->effects) if (e.kind == Effect::Kind::CBranch) cbs++;
            if (cbs == 1) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: cbranches=%d\n", cbs); }
        }
    }

    // ast_ldr_nested
    {
        tests_run++;
        printf("  %-40s ", "ast_ldr_nested");
        auto ast = lift_ast(0xF9400420);  // LDR X0, [X1, #8]
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else if (ast->effects.size() == 1
            && ast->effects[0].kind == Effect::Kind::Assign
            && ast->effects[0].expr
            && ast->effects[0].expr->kind == Expr::Kind::Op
            && ast->effects[0].expr->opcode == Opcode::LOAD) {
            // Check nested add(x1, 8) inside load
            auto& load = ast->effects[0].expr;
            if (load->children.size() >= 1 && load->children[0]->kind == Expr::Kind::Op
                && load->children[0]->opcode == Opcode::ADD) {
                printf("PASS\n"); tests_passed++;
            } else { printf("FAIL: load child not add\n"); }
        } else {
            printf("FAIL: effects=%zu\n", ast.has_value() ? ast->effects.size() : 0u);
        }
    }

    // ast_str_store_effect
    {
        tests_run++;
        printf("  %-40s ", "ast_str_store_effect");
        auto ast = lift_ast(0xF9000420);  // STR X0, [X1, #8]
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else {
            bool has_store = false;
            for (auto& e : ast->effects) if (e.kind == Effect::Kind::Store) has_store = true;
            if (has_store) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: no store effect\n"); }
        }
    }

    // ast_to_string_nonempty
    {
        tests_run++;
        printf("  %-40s ", "ast_to_string_nonempty");
        auto ast = lift_ast(0x8B020020);
        if (!ast.has_value()) { printf("FAIL: lift_ast nullopt\n"); }
        else {
            auto s = to_string(*ast);
            if (!s.empty()) { printf("PASS\n"); tests_passed++; }
            else { printf("FAIL: empty string\n"); }
        }
    }

    // interp_add
    {
        tests_run++;
        printf("  %-40s ", "interp_add");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 5; ctx.gpr[2] = 3;
        execute(ctx, 0x8B020020);  // ADD X0, X1, X2
        if (ctx.gpr[0] == 8 && ctx.pc == 4) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=%llu pc=%llu\n", (unsigned long long)ctx.gpr[0], (unsigned long long)ctx.pc); }
    }

    // interp_subs_positive
    {
        tests_run++;
        printf("  %-40s ", "interp_subs_positive");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 5; ctx.gpr[2] = 3;
        execute(ctx, 0xEB020020);  // SUBS X0, X1, X2
        // 5-3=2: N=0, Z=0, C=1 (no borrow), V=0
        if (ctx.gpr[0] == 2 && ctx.flags[0] == 0 && ctx.flags[1] == 0 && ctx.flags[2] == 1 && ctx.flags[3] == 0)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=%llu N=%d Z=%d C=%d V=%d\n", (unsigned long long)ctx.gpr[0], ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]); }
    }

    // interp_subs_negative
    {
        tests_run++;
        printf("  %-40s ", "interp_subs_negative");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 3; ctx.gpr[2] = 5;
        execute(ctx, 0xEB020020);  // SUBS X0, X1, X2
        // 3-5 wraps: N=1, Z=0, C=0 (borrow), V=0
        if (ctx.flags[0] == 1 && ctx.flags[1] == 0 && ctx.flags[2] == 0 && ctx.flags[3] == 0)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: N=%d Z=%d C=%d V=%d\n", ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]); }
    }

    // interp_subs_zero
    {
        tests_run++;
        printf("  %-40s ", "interp_subs_zero");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 7; ctx.gpr[2] = 7;
        execute(ctx, 0xEB020020);  // SUBS X0, X1, X2
        // 7-7=0: N=0, Z=1, C=1, V=0
        if (ctx.gpr[0] == 0 && ctx.flags[0] == 0 && ctx.flags[1] == 1 && ctx.flags[2] == 1 && ctx.flags[3] == 0)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=%llu N=%d Z=%d C=%d V=%d\n", (unsigned long long)ctx.gpr[0], ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]); }
    }

    // interp_adds_carry
    {
        tests_run++;
        printf("  %-40s ", "interp_adds_carry");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 0xFFFFFFFFFFFFFFFFULL; ctx.gpr[2] = 1;
        execute(ctx, 0xAB020020);  // ADDS X0, X1, X2
        // MAX+1 wraps to 0: N=0, Z=1, C=1 (carry out), V=0
        if (ctx.gpr[0] == 0 && ctx.flags[0] == 0 && ctx.flags[1] == 1 && ctx.flags[2] == 1 && ctx.flags[3] == 0)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=0x%llx N=%d Z=%d C=%d V=%d\n", (unsigned long long)ctx.gpr[0], ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]); }
    }

    // interp_adds_overflow
    {
        tests_run++;
        printf("  %-40s ", "interp_adds_overflow");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 0x7FFFFFFFFFFFFFFFULL; ctx.gpr[2] = 1;
        execute(ctx, 0xAB020020);  // ADDS X0, X1, X2
        // LLONG_MAX+1 overflows to negative: N=1, Z=0, C=0, V=1
        if (ctx.gpr[0] == 0x8000000000000000ULL && ctx.flags[0] == 1 && ctx.flags[1] == 0 && ctx.flags[2] == 0 && ctx.flags[3] == 1)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=0x%llx N=%d Z=%d C=%d V=%d\n", (unsigned long long)ctx.gpr[0], ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]); }
    }

    // interp_ands_flags
    {
        tests_run++;
        printf("  %-40s ", "interp_ands_flags");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 0xABCD; ctx.gpr[2] = 0xFFFF;
        execute(ctx, 0xEA020020);  // ANDS X0, X1, X2
        // 0xABCD & 0xFFFF = 0xABCD: N=0, Z=0
        if (ctx.gpr[0] == 0xABCD && ctx.flags[0] == 0 && ctx.flags[1] == 0)
            { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=0x%llx N=%d Z=%d\n", (unsigned long long)ctx.gpr[0], ctx.flags[0], ctx.flags[1]); }
    }

    // interp_cmp_bne
    {
        tests_run++;
        printf("  %-40s ", "interp_cmp_bne");
        // CMP X1, X2 (SUBS XZR, X1, X2) then B.NE
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 5; ctx.gpr[2] = 3; ctx.pc = 0x1000;
        execute(ctx, 0xEB02003F);  // CMP X1, X2 (SUBS XZR)
        // Not equal, so Z=0
        execute(ctx, 0x54000041);  // B.NE +8
        // Z=0 means NE taken, pc = 0x1004 + 8 = 0x100C
        if (ctx.pc == 0x100C) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: pc=0x%llx Z=%d\n", (unsigned long long)ctx.pc, ctx.flags[1]); }
    }

    // interp_cmp_beq_not_taken
    {
        tests_run++;
        printf("  %-40s ", "interp_cmp_beq_not_taken");
        // CMP X1, X2 then B.EQ (not taken because 5 != 3)
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[1] = 5; ctx.gpr[2] = 3; ctx.pc = 0x1000;
        execute(ctx, 0xEB02003F);  // CMP X1, X2
        execute(ctx, 0x54000040);  // B.EQ +8
        // Z=0 means EQ not taken, pc = 0x1004 + 4 = 0x1008
        if (ctx.pc == 0x1008) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: pc=0x%llx Z=%d\n", (unsigned long long)ctx.pc, ctx.flags[1]); }
    }

    // interp_mov_imm
    {
        tests_run++;
        printf("  %-40s ", "interp_mov_imm");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        execute(ctx, 0xD2800540);  // MOVZ X0, #42
        if (ctx.gpr[0] == 42) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=%llu\n", (unsigned long long)ctx.gpr[0]); }
    }

    // interp_ldr_str
    {
        tests_run++;
        printf("  %-40s ", "interp_ldr_str");
        Context ctx;
        uint8_t mem[65536] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.gpr[31] = 0x1000; // SP
        ctx.gpr[1] = 0xDEADBEEFCAFEBABEULL;
        execute(ctx, 0xF90003E1);  // STR X1, [SP]
        execute(ctx, 0xF94003E0);  // LDR X0, [SP]
        if (ctx.gpr[0] == 0xDEADBEEFCAFEBABEULL) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: x0=0x%llx\n", (unsigned long long)ctx.gpr[0]); }
    }

    // interp_branch
    {
        tests_run++;
        printf("  %-40s ", "interp_branch");
        Context ctx;
        uint8_t mem[1024] = {};
        ctx.memory = mem; ctx.memory_size = sizeof(mem);
        ctx.pc = 0x100;
        execute(ctx, 0x14000002);  // B +8
        if (ctx.pc == 0x108) { printf("PASS\n"); tests_passed++; }
        else { printf("FAIL: pc=0x%llx\n", (unsigned long long)ctx.pc); }
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
