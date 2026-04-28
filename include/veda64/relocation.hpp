// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#ifdef VEDA64_HOOK

#include <cstdint>
#include <cstddef>

namespace veda64 {

/// Check if an ARM64 instruction uses PC-relative addressing.
/// Such instructions need relocation when moved to a different address.
bool is_pc_relative(uint32_t insn);

/// Check if an ARM64 instruction can be safely relocated to a different address.
/// Returns false for instructions that depend on their address in non-fixable ways
/// (e.g. authenticated returns like RETAA/RETAB).
bool can_relocate(uint32_t insn);

/// Relocate a single ARM64 instruction from old_pc to new_pc.
/// For PC-relative instructions, the immediate is adjusted to maintain the
/// original target address. Non-PC-relative instructions are copied as-is.
///
/// Short-range conditional branches (B.cond/BC, CBZ, CBNZ, TBZ, TBNZ) expand
/// to a 2-instruction sequence when the new offset overflows their native
/// imm19/imm14 field but is still reachable by an unconditional B (imm26):
///   <inverted-predicate same-class branch> +8 ; B <target>
/// The expansion writes 2 words; *out_count reflects the actual count (1 or 2).
///
/// @param insn       The 32-bit instruction to relocate
/// @param old_pc     The original PC address where the instruction was located
/// @param new_pc     The new PC address where the instruction will be placed
/// @param out_insn   Output buffer for relocated instruction(s) (must hold at least 4 uint32_t)
/// @param out_count  Number of instructions written to out_insn (1 or 2)
/// @return true if relocation succeeded, false if the target is unreachable
///         even after expansion (delta beyond ±128 MiB), or if the instruction
///         cannot be relocated (e.g. authenticated return).
bool relocate_instruction(
    uint32_t insn,
    uint64_t old_pc,
    uint64_t new_pc,
    uint32_t* out_insn,
    size_t* out_count
);

} // namespace veda64

#endif // VEDA64_HOOK
