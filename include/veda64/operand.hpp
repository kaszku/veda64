// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <string>
#include "mnemonic.hpp"
#include "types.hpp"
#include "sysreg.hpp"
#include "pstate.hpp"
#include "prefetch.hpp"
#include "barrier.hpp"
#include "pattern.hpp"
#include "sysop.hpp"

namespace veda64 {

// Operand representation
class Operand {
public:
    Operand() = default;

    // Constructor for simple operands (registers, immediates)
    Operand(OperandType t, uint32_t v, bool is_64 = true)
        : type(t), value(v), is_64bit(is_64) {}

    // Constructor for memory operands
    Operand(OperandType t, uint32_t base, int32_t off, uint32_t idx_reg = 0, uint32_t ext = 0, uint32_t amt = 0)
        : type(t), base_reg(base), offset(off), index_reg(idx_reg), extend(ext), amount(amt) {}

    // Static factory methods for memory operands
    static Operand memory_base(uint32_t base) {
        return Operand(OperandType::MemoryBase, base, 0);
    }
    static Operand memory_offset(uint32_t base, int32_t offset) {
        return Operand(OperandType::MemoryOffset, base, offset);
    }
    static Operand memory_pre_index(uint32_t base, int32_t offset) {
        return Operand(OperandType::MemoryPreIndex, base, offset);
    }
    static Operand memory_post_index(uint32_t base, int32_t offset) {
        return Operand(OperandType::MemoryPostIndex, base, offset);
    }
    static Operand memory_reg_offset(uint32_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {
        return Operand(OperandType::MemoryRegOffset, base, 0, index, extend, amount);
    }

    OperandType type = OperandType::Unknown;
    uint32_t value = 0;          // Raw field value for simple operands
    uint64_t imm64 = 0;          // 64-bit immediate value (for logical immediates)
    bool is_64bit = true;        // True for 64-bit registers (X), false for 32-bit (W)
    bool is_sp = false;          // True if reg 31 should be SP/WSP, false for XZR/WZR
    Arrangement arrangement = Arrangement::None;  // Vector arrangement specifier (.16b, .4s, etc.)
    uint32_t index = 0;           // Element index for indexed vector operands (v0.b[3])
    bool has_index = false;       // True if index field is valid
    bool prefer_decimal = false;  // True if immediate should always be formatted as decimal
    SystemRegister sysreg = SystemRegister::UNKNOWN;  // System register for MSR/MRS operands
    PstateField pstate = PstateField::UNKNOWN;        // PSTATE field for MSR (immediate)
    PrefetchOp prefetch = PrefetchOp::UNKNOWN;        // Prefetch operation for PRFM
    BarrierOp barrier = BarrierOp::UNKNOWN;           // Barrier option for DMB/DSB/ISB
    SvePattern pattern = SvePattern::UNKNOWN;         // SVE predicate pattern
    SysOp sysop = SysOp::UNKNOWN;                    // System operation for TLBI/DC/AT/IC/etc.

    // Memory operand fields
    uint32_t base_reg = 0;       // Base register number
    int32_t offset = 0;          // Signed offset
    uint32_t index_reg = 0;      // Index register for reg+reg addressing
    uint32_t extend = 0;         // Extend type for reg+reg addressing
    uint32_t amount = 0;         // Shift/extend amount

#ifndef VEDA64_NO_STRINGS
    // Format operand for disassembly
    std::string to_string() const;
    static const char* arrangement_to_string(Arrangement a);

private:
    // Helper functions for formatting
    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);
    static std::string format_vector_register(uint32_t reg, Arrangement arrangement);
    static Arrangement arr_from_size(uint32_t size);
    static Arrangement arr_narrow_from_size(uint32_t size);
    static Arrangement arr_wide_from_size(uint32_t size);
    static Arrangement vec_arr(uint32_t size, uint32_t q);
#endif
};

#ifndef VEDA64_NO_STRINGS
// Convert mnemonic enum to string
const char* mnemonic_to_string(Mnemonic mnem);

// Determine vector arrangement for MOVI/MVNI based on Q and cmode fields
Arrangement get_movi_arrangement(uint32_t insn);
int get_movi_shift(uint32_t insn);

// Convert condition code to string ("eq", "ne", etc.)
const char* condition_to_string(Condition cond);
#endif

} // namespace veda64
