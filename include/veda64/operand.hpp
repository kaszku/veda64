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
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)  // nameless struct/union
#endif
class Operand {
    // Private constructors — use static factory methods instead
    Operand(OperandType t, uint32_t v, bool /*unused*/ = true)
        : type(t), value(v) {}
    Operand(OperandType t, uint32_t base, int32_t off, uint32_t idx_reg = 0, uint32_t ext = 0, uint32_t amt = 0)
        : type(t), extend(static_cast<uint8_t>(ext)), index_reg(static_cast<uint8_t>(idx_reg)), base_reg(base), offset(off), amount(static_cast<uint8_t>(amt)) {}
public:
    Operand() = default;

    // Static factory methods for memory operands
    static Operand memory_base(uint32_t base) {
        Operand op(OperandType::Memory, base, 0);
        op.extend = static_cast<uint8_t>(MemoryMode::Base);
        return op;
    }
    static Operand memory_offset(uint32_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = (offset == 0) ? static_cast<uint8_t>(MemoryMode::Base) : static_cast<uint8_t>(MemoryMode::Offset);
        return op;
    }
    static Operand memory_pre_index(uint32_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::PreIndex);
        return op;
    }
    static Operand memory_post_index(uint32_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::PostIndex);
        return op;
    }
    static Operand memory_mul_vl(uint32_t base, int32_t offset) {
        if (offset == 0) return memory_base(base);
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::MulVL);
        return op;
    }
    static Operand memory_reg_offset(uint32_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {
        return Operand(OperandType::MemoryRegOffset, base, 0, index, extend, amount);
    }

    // ── Register factories ──
    static Operand gp(uint32_t num, bool is_64, bool is_sp = false) {
        return Operand(OperandType::Register, static_cast<uint32_t>(make_gp_reg(num, is_64, is_sp)));
    }
    static Operand scalar(uint32_t num, Arrangement size) {
        return Operand(OperandType::Register, static_cast<uint32_t>(make_scalar_reg(num, size)));
    }
    static Operand vec(uint32_t num, Arrangement arr = Arrangement::None) {
        Operand op(OperandType::Register, static_cast<uint32_t>(make_vec_reg(num)));
        op.arrangement = arr;
        return op;
    }
    static Operand sve(uint32_t num, Arrangement arr = Arrangement::None) {
        Operand op(OperandType::Register, static_cast<uint32_t>(make_sve_reg(num)));
        op.arrangement = arr;
        return op;
    }
    static Operand pred(uint32_t num, uint8_t qualifier = 0) {
        Operand op(OperandType::Register, static_cast<uint32_t>(make_pred_reg(num)));
        op.extend = qualifier;
        return op;
    }
    static Operand predn(uint32_t num) {
        return Operand(OperandType::Register, static_cast<uint32_t>(make_predn_reg(num)));
    }
    static Operand zt0() {
        return Operand(OperandType::Register, static_cast<uint32_t>(Register::ZT0));
    }
    static Operand reg(Register r) {
        return Operand(OperandType::Register, static_cast<uint32_t>(r));
    }

    // ── Immediate factories ──
    static Operand imm(uint64_t val) {
        Operand op(OperandType::Immediate, static_cast<uint32_t>(val));
        op.imm64 = val;
        return op;
    }
    static Operand simm(int64_t val) {
        Operand op(OperandType::SignedImmediate, static_cast<uint32_t>(static_cast<uint64_t>(val)));
        op.imm64 = static_cast<uint64_t>(val);
        return op;
    }
    static Operand label(int64_t off) {
        Operand op(OperandType::Label, 0);
        op.offset = static_cast<int32_t>(off);
        return op;
    }
    static Operand relative(int64_t off) {
        return Operand(OperandType::Relative, static_cast<uint32_t>(static_cast<uint64_t>(off)));
    }
    static Operand float_imm(uint32_t encoded) {
        return Operand(OperandType::FloatImmediate, encoded);
    }

    // ── Misc factories ──
    static Operand shift(uint32_t type, uint32_t amount) {
        return Operand(OperandType::Shift, (type << 8) | amount);
    }
    static Operand extend_op(uint32_t type, uint32_t amount, bool is_64 = false) {
        return Operand(OperandType::Extend, type | (amount << 8) | (is_64 ? 0x800u : 0u));
    }
    static Operand pat(SvePattern p) {
        return Operand(OperandType::Pattern, static_cast<uint32_t>(p));
    }
    static Operand sve_mul(uint32_t val) {
        return Operand(OperandType::SVEMulImm, val);
    }
    static Operand prefetch_op(PrefetchOp p) {
        Operand op(OperandType::Prefetch, 0);
        op.prefetch = p;
        return op;
    }
    static Operand barrier_op(BarrierOp b) {
        Operand op(OperandType::Barrier, 0);
        op.barrier = b;
        return op;
    }
    static Operand sysreg_op(SystemRegister r) {
        Operand op(OperandType::SystemRegister, 0);
        op.sysreg = r;
        return op;
    }
    static Operand pstate_op(PstateField f) {
        Operand op(OperandType::PstateField, 0);
        op.pstate = f;
        return op;
    }
    static Operand sysop_op(SysOp s) {
        Operand op(OperandType::SysOp, 0);
        op.sysop = s;
        return op;
    }
    static Operand fixed_sym(uint32_t idx) {
        return Operand(OperandType::FixedSym, idx);
    }
    static Operand vlx(uint32_t n) {
        return Operand(OperandType::SVEVLxImm, n);
    }
    static Operand sme_tile(uint32_t val) {
        return Operand(OperandType::SMETileRegister, val);
    }
    static Operand memory_val(uint32_t val) {
        return Operand(OperandType::Memory, val);
    }
    static Operand reg_list(uint32_t first_reg) {
        return Operand(OperandType::RegisterList, first_reg);
    }
    static Operand memory_sve_offset(uint32_t base, int32_t offset = 0) {
        return Operand(OperandType::MemorySVEOffset, base, offset);
    }

    // Compact 24-byte layout (8-byte aligned)
    OperandType type = OperandType::Unknown;           // byte 0
    Arrangement arrangement = Arrangement::None;       // byte 1
    uint8_t extend = 0;                                // byte 2: MemoryMode / pred qualifier / extend type
    uint8_t index_reg = 0;                             // byte 3: index register for reg+reg addressing
    union { uint32_t value = 0; uint32_t base_reg; };  // bytes 4-7
    union {                                            // bytes 8-15
        uint64_t imm64 = 0;
        struct { int32_t offset; uint32_t index; };
    };
    union {                                            // bytes 16-17
        SystemRegister sysreg;
        PstateField pstate;
        PrefetchOp prefetch;
        BarrierOp barrier;
        SvePattern pattern;
        SysOp sysop;
        uint16_t enum_val = 0;
    };
    uint8_t amount = 0;                                // byte 18
    bool has_index = false;                            // byte 19
    bool prefer_decimal = false;                       // byte 20

#ifndef VEDA64_NO_STRINGS
    // Format operand for disassembly
    std::string to_string() const;
    static const char* arrangement_to_string(Arrangement a);

private:
    // Helper functions for formatting
    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);
    static std::string format_base_reg(uint32_t reg) {
        if (reg > 31) return register_to_string(static_cast<Register>(reg));
        return format_register(reg, true, true);
    }
    static std::string format_vector_register(uint32_t reg, Arrangement arrangement);
    static Arrangement arr_from_size(uint32_t size);
    static Arrangement arr_narrow_from_size(uint32_t size);
    static Arrangement arr_wide_from_size(uint32_t size);
    static Arrangement vec_arr(uint32_t size, uint32_t q);
#endif
};
static_assert(sizeof(Operand) == 24, "Operand must be 24 bytes");
#ifdef _MSC_VER
#pragma warning(pop)
#endif

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
