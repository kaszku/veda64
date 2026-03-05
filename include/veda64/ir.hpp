// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#ifndef VEDA64_NO_IR

#include <cstdint>
#include <string>
#include <vector>
#include <optional>
#include <memory>
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
    CARRY_ADD,
    CARRY_SUB,
    OVERFLOW_ADD,
    OVERFLOW_SUB,

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

// Detail level for IR lifting
enum class IrDetail : uint8_t {
    Semantic,   // Uses semantic opcodes (carry_add, overflow_sub, etc.)
    Expanded,   // Everything in primitives (cmp_ule, xor chains, etc.)
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
    static VarNode flags_n() { return {Space::Flags, 0, 1, 0}; }
    static VarNode flags_z() { return {Space::Flags, 1, 1, 0}; }
    static VarNode flags_c() { return {Space::Flags, 2, 1, 0}; }
    static VarNode flags_v() { return {Space::Flags, 3, 1, 0}; }
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
std::optional<Lifted> lift(uint32_t insn, IrDetail detail = IrDetail::Semantic);

// Lift a decoded instruction to IR
std::optional<Lifted> lift(const Instruction& insn, IrDetail detail = IrDetail::Semantic);

// Simplify IR: copy propagation + output folding + dead temp elimination
Lifted simplify(const Lifted& l);

#ifndef VEDA64_NO_STRINGS
// String formatters
std::string to_string(const VarNode& v);
std::string to_string(const Op& op);
std::string to_string(const Lifted& l);
std::string opcode_name(Opcode op);
#endif

// ============================================================
// AST (Expression Tree) layer on top of flat IR
// ============================================================

// Expression tree node (heap-allocated, shared via shared_ptr)
struct Expr {
    enum class Kind : uint8_t {
        Var,    // Leaf: register, flag, or memory location
        Const,  // Leaf: constant value
        Op,     // Interior: opcode + children
    };

    Kind kind;
    Opcode opcode = Opcode::NOP;
    VarNode var = {};
    std::vector<std::shared_ptr<Expr>> children;
    uint8_t size = 0;

    static std::shared_ptr<Expr> make_var(VarNode v);
    static std::shared_ptr<Expr> make_const(int64_t val, uint8_t sz);
    static std::shared_ptr<Expr> make_op(Opcode opc, uint8_t sz,
        std::vector<std::shared_ptr<Expr>> args);
};

using ExprPtr = std::shared_ptr<Expr>;

// A single effect: writing an expression result to a destination
struct Effect {
    enum class Kind : uint8_t {
        Assign,  // dest <- expr
        Store,   // mem[addr] <- value
        Branch,  // goto expr
        CBranch, // if (cond) goto target
        Call,    // call target
        Nop,
    };

    Kind kind;
    VarNode dest = {};
    ExprPtr expr;
    ExprPtr value;
    uint8_t size = 0;
};

// AST representation of a single instruction
struct Ast {
    std::vector<Effect> effects;
};

// Build AST from flat IR (calls simplify internally)
Ast to_ast(const Lifted& l);

// Convenience: lift + to_ast in one call
std::optional<Ast> lift_ast(uint32_t insn, IrDetail detail = IrDetail::Semantic);
std::optional<Ast> lift_ast(const Instruction& insn, IrDetail detail = IrDetail::Semantic);

#ifndef VEDA64_NO_STRINGS
std::string to_string(const Expr& e);
std::string to_string(const Effect& eff);
std::string to_string(const Ast& ast);
#endif

// ============================================================
// Interpreter: Context + execute
// ============================================================

struct Context {
    uint64_t gpr[32] = {};      // X0-X30, gpr[31] = SP
    uint8_t simd[32][16] = {};   // V0-V31, 128-bit each
    uint8_t flags[4] = {};       // 0=N, 1=Z, 2=C, 3=V
    uint64_t pc = 0;
    uint8_t* memory = nullptr;
    size_t memory_size = 0;
    bool halted = false;

    uint64_t read_gpr(uint16_t reg, uint8_t size) const;
    void write_gpr(uint16_t reg, uint64_t val, uint8_t size);
    uint64_t read_mem(uint64_t addr, uint8_t size) const;
    void write_mem(uint64_t addr, uint64_t val, uint8_t size);
};

uint64_t eval_expr(const Context& ctx, const Expr& e);
void execute_ast(Context& ctx, const Ast& ast);
void execute(Context& ctx, uint32_t insn);

} // namespace veda64::ir

#endif // !VEDA64_NO_IR
