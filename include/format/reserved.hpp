#pragma once
// ARM64 Decode Group: Reserved
// 1 instruction encodings

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace Format {
namespace Reserved {

// Encode functions
uint32_t encode_udf_only_perm_undef(uint32_t imm16);

// Decode function
// Decode a reserved instruction
std::optional<Instruction> decode_reserved(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_reserved(const uint8_t* bytes) {
    return decode_reserved(from_bytes(bytes));
}

} // namespace Reserved
} // namespace Format
} // namespace veda64
