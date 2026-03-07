// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <optional>
#include "mnemonic.hpp"
#include "types.hpp"
#include "operand.hpp"
#include "util.hpp"

namespace veda64 {

// Instruction representation
class Instruction {
public:
    Instruction() = default;
    Instruction(Mnemonic mnem, uint32_t raw, uint16_t enc_id = 0xFFFF)
        : mnemonic(mnem), raw_value(raw), encoding_id(enc_id) {}

    Mnemonic mnemonic = Mnemonic::UNKNOWN;
    Condition condition = Condition::None;
    uint32_t raw_value = 0;
    uint16_t encoding_id = 0xFFFF;  // 0xFFFF = unknown/unclassified
    std::vector<Operand> operands;

#ifdef VEDA64_STRINGS
    // Format as disassembled instruction
    std::string to_string() const;
#endif
};

// Decode a single ARM64 instruction from a uint32_t (native little-endian value)
std::optional<Instruction> decode(uint32_t insn);

// Decode a single ARM64 instruction from 4 bytes in memory (little-endian)
inline std::optional<Instruction> decode(const uint8_t* bytes) {
    return decode(from_bytes(bytes));
}

} // namespace veda64
