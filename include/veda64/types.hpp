// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// ARM64 condition codes
enum class Condition : int8_t {
    None = -1,
    EQ = 0,   // Equal
    NE = 1,   // Not equal
    CS = 2,   // Carry set / unsigned higher or same (HS)
    CC = 3,   // Carry clear / unsigned lower (LO)
    MI = 4,   // Minus / negative
    PL = 5,   // Plus / positive or zero
    VS = 6,   // Overflow
    VC = 7,   // No overflow
    HI = 8,   // Unsigned higher
    LS = 9,   // Unsigned lower or same
    GE = 10,  // Signed greater than or equal
    LT = 11,  // Signed less than
    GT = 12,  // Signed greater than
    LE = 13,  // Signed less than or equal
    AL = 14,  // Always
    NV = 15   // Never (behaves like AL)
};

// Operand type enumeration
enum class OperandType {
    Register,           // General purpose register (Xn, Wn)
    VectorRegister,     // Vector/SIMD register (Vn, Qn, Dn, Sn, Hn, Bn)
    SVERegister,        // SVE scalable vector register (Zn)
    PredicateRegister,  // SVE predicate register (Pn)
    PredicateNRegister, // SVE predicate-as-counter register (PNn, pn8-pn15)
    SMETileRegister,    // SME tile register (ZAn)
    Immediate,          // Immediate value
    SignedImmediate,    // Signed immediate value
    MemoryBase,         // Memory operand [base]
    MemoryOffset,       // Memory operand [base, #offset]
    MemoryPreIndex,     // Memory operand [base, #offset]! (pre-index writeback)
    MemoryPostIndex,    // Memory operand [base], #offset (post-index writeback)
    MemoryRegOffset,    // Memory operand [base, Rm{, extend {#amount}}]
    Label,              // Branch target label/offset
    Relative,          // PC-relative offset for branches
    SystemRegister,     // System register
    Shift,              // Shift specifier (LSL, LSR, ASR, ROR)
    Extend,             // Extend specifier (UXTB, SXTW, etc.)
    Index,              // Element index
    Pattern,            // SVE pattern specifier
    SVEMulImm,          // SVE mul multiplier (MUL #N where N=imm4+1)
    Prefetch,           // Prefetch operation
    Barrier,            // Barrier option
    FloatImmediate,     // Floating-point immediate (#0.0, etc.)
    VectorRegisterList, // Vector register list { Vt.T, Vt+1.T, ... }
    SVERegisterList,    // SVE register list { Zt.T, Zt+1.T, ... }
    MemoryOffsetMulVL,  // SVE memory [base, #offset, mul vl]
    MemorySVEOffset,    // SVE gather memory [Zn.T, #offset]
    SMEZTRegister,      // SME ZT0 lookup table register
    PstateField,        // PSTATE field name for MSR/MRS immediate (SPSel, DAIFSet, etc.)
    FixedSym,           // Fixed symbolic operand (e.g. CSYNC, DSYNC)
    SysOp,              // SYS alias operation name (tlbi vmalle1 etc.)
    SVEVLxImm,          // SVE VL specifier (vlx2 or vlx4) for WHILE* pn_rr
    PredicateRegisterList, // Predicate register list { Pn.T, Pn+1.T, ... }
    Unknown
};

// Vector arrangement specifier
enum class Arrangement : uint8_t {
    None = 0,
    B, H, S, D, Q,           // Scalar element sizes
    B8, H4, S2, D1,           // 64-bit vector
    B16, H8, S4, D2,          // 128-bit vector
    Q1, B2, B4, H2,           // Special
};

} // namespace veda64
