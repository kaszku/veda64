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
#ifdef VEDA64_IR
#include "encoding_id.hpp"
#endif

namespace veda64 {

// Instruction representation
class Instruction {
public:
    Instruction() = default;
#ifdef VEDA64_IR
    Instruction(Mnemonic mnem, uint32_t raw, EncodingId enc_id = EncodingId::UNKNOWN)
        : mnemonic(mnem), raw_value(raw), encoding_id(enc_id) {}
#else
    Instruction(Mnemonic mnem, uint32_t raw)
        : mnemonic(mnem), raw_value(raw) {}
#endif

    Mnemonic mnemonic = Mnemonic::UNKNOWN;
    Condition condition = Condition::None;
    uint32_t raw_value = 0;
#ifdef VEDA64_IR
    EncodingId encoding_id = EncodingId::UNKNOWN;
#endif
    std::vector<Operand> operands;

#ifdef VEDA64_STRINGS
    // Format as disassembled instruction
    std::string to_string() const;
#endif
};

// Decode a single ARM64 instruction from a uint32_t (native little-endian value)
// When aliases=true, alias encodings return the alias mnemonic and operands
// (e.g., MOV instead of ADD, CMP instead of SUBS)
std::optional<Instruction> decode(uint32_t insn, bool aliases = false);

// Decode a single ARM64 instruction from 4 bytes in memory (little-endian)
inline std::optional<Instruction> decode(const uint8_t* bytes, bool aliases = false) {
    return decode(from_bytes(bytes), aliases);
}

} // namespace veda64
