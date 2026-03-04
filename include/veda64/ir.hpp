// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#ifndef VEDA64_NO_IR

#include <cstdint>
#include <string>
#include <vector>
#include <optional>
#include "instruction.hpp"

namespace veda64::ir {

// ~40 micro-operations (P-Code style)
enum class Opcode : uint8_t {
    // Data movement
    COPY,
    LOAD,
    STORE,

    // Arithmetic
    ADD,
    SUB,
    MUL,
    SDIV,
    UDIV,
    NEG,

    // Bitwise
    AND,
    OR,
    XOR,
    NOT,
    SHL,
    SHR,
    SAR,
    ROR,

    // Comparison
    CMP_EQ,
    CMP_NE,
    CMP_SLT,
    CMP_ULT,
    CMP_SLE,
    CMP_ULE,

    // Conversion
    ZEXT,
    SEXT,
    TRUNC,
    INT2FLOAT,
    FLOAT2INT,
    FLOAT2FLOAT,

    // Float
    FADD,
    FSUB,
    FMUL,
    FDIV,
    FSQRT,
    FNEG,
    FABS,

    // Control flow
    BRANCH,
    CBRANCH,
    CALL,
    RET,

    // Flags
    ADD_CARRY,
    SUB_CARRY,
    FLAG_READ,
    FLAG_WRITE,

    // Bit manipulation
    EXTRACT,
    INSERT,
    CONCAT,

    // Vector
    VEXTRACT_ELEM,
    VINSERT_ELEM,
    VBROADCAST,

    // Special
    BARRIER,
    NOP,
    UNDEF,
};

// Address space for VarNode
enum class Space : uint8_t {
    Const,      // Constant/immediate value
    Temp,       // Temporary (SSA-like)
    GPR,        // General-purpose registers (X0-X30, SP)
    SIMD,       // SIMD/FP registers (V0-V31)
    SVE_Z,      // SVE Z registers
    SVE_P,      // SVE predicate registers
    SysReg,     // System registers
    Flags,      // NZCV flags (offset: 0=N, 1=Z, 2=C, 3=V)
    RAM,        // Memory
};

// Variable node -- identifies a storage location or constant
struct VarNode {
    Space space = Space::Const;
    uint16_t offset = 0;    // Register number or temp index
    uint8_t size = 0;       // Size in bytes (1,2,4,8,16,32)
    int64_t value = 0;      // Used only when space == Const

    // Factory helpers
    static VarNode gpr(uint16_t reg, uint8_t sz = 8) {
        return {Space::GPR, reg, sz, 0};
    }
    static VarNode simd(uint16_t reg, uint8_t sz = 16) {
        return {Space::SIMD, reg, sz, 0};
    }
    static VarNode temp(uint16_t idx, uint8_t sz = 8) {
        return {Space::Temp, idx, sz, 0};
    }
    static VarNode constant(int64_t val, uint8_t sz = 8) {
        return {Space::Const, 0, sz, val};
    }
    static VarNode flags(uint16_t flag_idx = 0) {
        return {Space::Flags, flag_idx, 1, 0};
    }
    static VarNode ram(uint8_t sz = 8) {
        return {Space::RAM, 0, sz, 0};
    }
};

// Single micro-operation
struct Op {
    Opcode opcode = Opcode::NOP;
    VarNode output;
    VarNode inputs[3] = {};
    uint8_t num_inputs = 0;
};

// Lifted representation of a single ARM64 instruction
struct Lifted {
    std::vector<Op> ops;    // Typically 3-8 ops per instruction
};

// Lift a raw instruction word to IR
std::optional<Lifted> lift(uint32_t insn);

// Lift a decoded instruction to IR
std::optional<Lifted> lift(const Instruction& insn);

// Simplify IR: copy propagation + output folding + dead temp elimination
Lifted simplify(const Lifted& l);

#ifndef VEDA64_NO_STRINGS
// String formatters
std::string to_string(const VarNode& v);
std::string to_string(const Op& op);
std::string to_string(const Lifted& l);
std::string opcode_name(Opcode op);
#endif

} // namespace veda64::ir

#endif // !VEDA64_NO_IR
