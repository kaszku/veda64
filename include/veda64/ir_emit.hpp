// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski

#pragma once

#if defined(VEDA64_IR) && defined(VEDA64_CODEGEN)

#include <functional>
#include "ir.hpp"
#include <codegen/emitter.hpp>

namespace veda64 {
namespace ir {

/// Context for lowering IR ops to AArch64 via a CodeGenerator.
///
/// `resolve` maps a VarNode to a physical X register. It is invoked for
/// Space::GPR and Space::TEMP inputs/outputs. For Space::CONST, emit()
/// materializes the value into `scratch0` (or `scratch1` if the same op
/// already consumes `scratch0`). Space::FLAGS inputs are handled
/// internally via condition-flag reads.
struct EmitContext {
    std::function<codegen::XReg(const VarNode&)> resolve;
    /// Scratch registers for const materialization. Default IP0/IP1 (x16/x17).
    codegen::XReg scratch0{16};
    codegen::XReg scratch1{17};
    /// PC of the instruction immediately following a branch. Used only for
    /// BRANCH/CBRANCH/CALL when the offset input is a Const interpreted as an
    /// absolute target. If 0, the Const is treated as a PC-relative offset
    /// from the branch instruction itself.
    uint64_t pc_of_next_insn = 0;
};

/// Emit AArch64 for a single IR op. Returns false if the opcode or operand
/// shapes are unsupported (no bytes are emitted in that case).
bool emit(const Op& op, codegen::CodeGenerator& cg, const EmitContext& ctx);

/// Emit every op in a Lifted sequence. Returns false on the first
/// unsupported op; ops emitted up to that point remain in the code buffer.
bool emit(const Lifted& l, codegen::CodeGenerator& cg, const EmitContext& ctx);

} // namespace ir
} // namespace veda64

#endif // VEDA64_IR && VEDA64_CODEGEN
