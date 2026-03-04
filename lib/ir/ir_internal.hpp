// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit
// Internal header shared between ir_lift.cpp and ir_tables.cpp

#pragma once

#ifndef VEDA64_NO_IR

#include "veda64/ir.hpp"

namespace veda64::ir {

enum class IrTemplate : uint8_t {
    GpBinop,        // ADD, SUB, AND, ORR, EOR, etc. (no flag set)
    GpBinopFlags,   // ADDS, SUBS, ANDS (sets flags)
    GpBinopImm,     // ADD/SUB immediate
    GpBinopImmFlags,// ADDS/SUBS immediate (sets flags)
    GpShift,        // LSL, LSR, ASR, ROR (variable shift)
    GpMove,         // MOV, MVN
    GpMoveImm,      // MOVZ, MOVN, MOVK
    GpMul,          // MUL, MADD, MSUB
    GpDiv,          // SDIV, UDIV
    GpBitfield,     // BFM, SBFM, UBFM
    GpExtend,       // SXTB, UXTB, etc.
    CondSelect,     // CSEL, CSINC, CSINV, CSNEG
    LoadReg,        // LDR (immediate offset)
    StoreReg,       // STR (immediate offset)
    LoadPair,       // LDP
    StorePair,      // STP
    BranchUncond,   // B
    BranchCond,     // B.cond
    BranchReg,      // BR, BLR, RET
    CompareBranch,  // CBZ, CBNZ
    TestBranch,     // TBZ, TBNZ
    SimdBinop,      // SIMD binary ops
    SimdUnary,      // SIMD unary ops
    FpBinop,        // Scalar FP binary ops
    FpConvert,      // FCVT*, SCVTF, UCVTF
    Atomic,         // LDADD, CAS, SWP, etc.
    System,         // MSR, MRS, SYS
    Nop,            // NOP, HINT
};

enum class FieldId : uint8_t {
    Rd, Rn, Rm, Ra,
    Imm12, Imm16, Imm26, Imm19, Imm14, Imm9,
    Sf, Shift, Imm6, Opc, Op, S, Cond,
    None,
};

struct IrEntry {
    uint32_t mask;
    uint32_t match;
    IrTemplate tpl;
    Opcode opcode;
    FieldId dst;
    FieldId src1;
    FieldId src2;
    FieldId size_field;
    uint8_t extra;
};

// Defined in ir_tables.cpp (generated)
extern const IrEntry ir_table[];
extern const size_t ir_table_size;

} // namespace veda64::ir

#endif // !VEDA64_NO_IR
