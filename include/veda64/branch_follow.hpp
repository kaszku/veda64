// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>
#include <functional>

namespace veda64 {

// Classification of control flow for a single instruction
enum class FlowType : uint8_t {
    Sequential,   // Falls through to next instruction
    Branch,       // Unconditional branch (B, BR)
    Call,         // Subroutine call (BL, BLR)
    ConditionalBranch,  // B.cond, CBZ, CBNZ, TBZ, TBNZ
    Return,       // RET, RETAA, RETAB, ERET
    Exception,    // SVC, HVC, SMC, BRK, HLT
    Unknown       // Undecodable
};

// Result of classifying one instruction's control flow
struct FlowInfo {
    FlowType type = FlowType::Sequential;
    uint64_t address = 0;      // Address of this instruction
    uint64_t target = 0;        // Branch target (0 if indirect or N/A)
    bool is_indirect = false;   // BR/BLR (target unknown statically)
    bool has_fallthrough = true; // Can execution continue to next insn?
};

/// Classify the control flow of a single instruction at the given address.
FlowInfo classify_flow(uint32_t insn, uint64_t address);

/// Result of walking a basic block
struct BasicBlock {
    uint64_t start = 0;          // First instruction address
    uint64_t end = 0;             // Address past last instruction
    std::vector<FlowInfo> instructions;
    std::vector<uint64_t> successors;  // Possible next basic blocks
};

/// Walk a basic block starting at 'start', reading instructions via 'read_insn'.
/// read_insn(address) should return the 32-bit instruction at that address.
/// Stops at the first terminator (branch, return, exception) or after max_insns.
BasicBlock walk_basic_block(
    uint64_t start,
    std::function<uint32_t(uint64_t)> read_insn,
    size_t max_insns = 1024);

/// Walk a full control flow graph starting at 'entry', following branch targets.
/// Returns all discovered basic blocks. Stops at indirect branches and calls.
std::vector<BasicBlock> walk_cfg(
    uint64_t entry,
    std::function<uint32_t(uint64_t)> read_insn,
    size_t max_blocks = 256,
    size_t max_insns_per_block = 1024);

} // namespace veda64
