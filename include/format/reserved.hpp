// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once
// ARM64 Decode Group: Reserved
// 1 instruction encodings

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace format {
namespace reserved {

// Encode functions
uint32_t encode_udf_only_perm_undef(uint32_t imm16);

// Decode function
// Decode a reserved instruction from a uint32_t
std::optional<Instruction> decode_reserved(uint32_t insn, bool aliases = false);

// Decode a reserved instruction from 4 bytes in memory (little-endian)
inline std::optional<Instruction> decode_reserved(const uint8_t* bytes, bool aliases = false) {
    return decode_reserved(from_bytes(bytes), aliases);
}

} // namespace reserved
} // namespace format
} // namespace veda64
