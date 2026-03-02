// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "format/reserved.hpp"

// Suppress MSVC warning for is_64bit declared but unused in some decode stubs
#ifdef _MSC_VER
#pragma warning(disable: 4189)
#endif

namespace veda64 {
namespace format {
namespace reserved {

// Encoding structures union
union ReservedEncoding {
    uint32_t raw;
    // UDF: Permanently undefined
    // Encoding: UDF_only_perm_undef
    // Template: UDF  #<imm>
    struct UdfOnlyPermUndef {
        uint32_t imm16 : 16;
        uint32_t _unnamed_3 : 9;  // fixed: 0b000000000 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    };

    UdfOnlyPermUndef udf_only_perm_undef;

};
static_assert(sizeof(ReservedEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_udf_only_perm_undef(uint32_t imm16) {
    ReservedEncoding insn = {};
    insn.udf_only_perm_undef.imm16 = imm16;
    insn.udf_only_perm_undef._unnamed_3 = 0b000000000;
    insn.udf_only_perm_undef._unnamed_2 = 0b0000;
    insn.udf_only_perm_undef._unnamed_1 = 0b00;
    insn.udf_only_perm_undef._unnamed_0 = 0b0;
    return insn.raw;
}

// Decode a reserved instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_reserved(uint32_t insn) {
    // Switch for mask 0xFFFF0000u (1 pattern, 1 encoding)
    switch (insn & 0xFFFF0000u) {
        case 0x00000000u: { // UDF_only_perm_undef
                        Instruction result(Mnemonic::UDF, insn);
                        ReservedEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand::imm(enc.udf_only_perm_undef.imm16));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace reserved
} // namespace format
} // namespace veda64
