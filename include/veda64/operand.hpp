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
    Operand(OperandType t, uint16_t v, bool /*unused*/ = true)
        : type(t), value(v) {}
    Operand(OperandType t, uint16_t base, int32_t off)
        : type(t), value(base) { offset = off; }
public:
    Operand() = default;

    // Static factory methods for memory operands
    static Operand memory_base(uint16_t base) {
        Operand op(OperandType::Memory, base, 0);
        op.extend = static_cast<uint8_t>(MemoryMode::Base);
        return op;
    }
    static Operand memory_offset(uint16_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = (offset == 0) ? static_cast<uint8_t>(MemoryMode::Base) : static_cast<uint8_t>(MemoryMode::Offset);
        return op;
    }
    static Operand memory_pre_index(uint16_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::PreIndex);
        return op;
    }
    static Operand memory_post_index(uint16_t base, int32_t offset) {
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::PostIndex);
        return op;
    }
    static Operand memory_mul_vl(uint16_t base, int32_t offset) {
        if (offset == 0) return memory_base(base);
        Operand op(OperandType::Memory, base, offset);
        op.extend = static_cast<uint8_t>(MemoryMode::MulVL);
        return op;
    }
    static Operand memory_reg_offset(uint16_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {
        Operand op(OperandType::MemoryRegOffset, base, 0);
        op.extend = static_cast<uint8_t>(extend);
        op.amount = static_cast<uint8_t>(amount);
        op.index_reg = make_gp_reg(index, !(extend == 2 || extend == 6));
        return op;
    }

    // ── Register factories ──
    static Operand gp(uint32_t num, bool is_64, bool is_sp = false) {
        return Operand(OperandType::Register, static_cast<uint16_t>(make_gp_reg(num, is_64, is_sp)));
    }
    static Operand scalar(uint32_t num, Arrangement size) {
        return Operand(OperandType::Register, static_cast<uint16_t>(make_scalar_reg(num, size)));
    }
    static Operand vec(uint32_t num, Arrangement arr = Arrangement::None) {
        return Operand(OperandType::Register, static_cast<uint16_t>(make_vec_reg(num, arr)));
    }
    static Operand sve(uint32_t num, Arrangement arr = Arrangement::None) {
        return Operand(OperandType::Register, static_cast<uint16_t>(make_sve_reg(num, arr)));
    }
    static Operand pred(uint32_t num, uint8_t qualifier = 0, Arrangement arr = Arrangement::None) {
        Operand op(OperandType::Register, static_cast<uint16_t>(make_pred_reg(num, arr)));
        op.extend = qualifier;
        return op;
    }
    static Operand predn(uint32_t num, Arrangement arr = Arrangement::None) {
        return Operand(OperandType::Register, static_cast<uint16_t>(make_predn_reg(num, arr)));
    }
    static Operand zt0() {
        return Operand(OperandType::Register, static_cast<uint16_t>(Register::ZT0));
    }
    static Operand reg(Register r) {
        return Operand(OperandType::Register, static_cast<uint16_t>(r));
    }

    // ── Immediate factories ──
    static Operand imm(uint64_t val) {
        Operand op(OperandType::Immediate, 0);
        op.imm64 = val;
        return op;
    }
    static Operand simm(int64_t val) {
        Operand op(OperandType::SignedImmediate, 0);
        op.offset = static_cast<int32_t>(val);
        return op;
    }
    static Operand label(int64_t off) {
        Operand op(OperandType::Label, 0);
        op.offset = static_cast<int32_t>(off);
        return op;
    }
    static Operand relative(int64_t off) {
        Operand op(OperandType::Relative, 0);
        op.imm64 = static_cast<uint64_t>(off);
        return op;
    }
    static Operand float_imm(uint32_t encoded) {
        return Operand(OperandType::FloatImmediate, static_cast<uint16_t>(encoded));
    }

    // ── Misc factories ──
    static Operand shift(uint32_t type, uint32_t amount) {
        return Operand(OperandType::Shift, static_cast<uint16_t>((type << 8) | amount));
    }
    static Operand extend_op(uint32_t type, uint32_t amount, bool is_64 = false) {
        return Operand(OperandType::Extend, static_cast<uint16_t>(type | (amount << 8) | (is_64 ? 0x800u : 0u)));
    }
    static Operand pat(SvePattern p) {
        Operand op(OperandType::Pattern, 0);
        op.pattern = p;
        return op;
    }
    static Operand sve_mul(uint32_t val) {
        return Operand(OperandType::SVEMulImm, static_cast<uint16_t>(val));
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
        return Operand(OperandType::FixedSym, static_cast<uint16_t>(idx));
    }
    static Operand vlx(uint32_t n) {
        return Operand(OperandType::SVEVLxImm, static_cast<uint16_t>(n));
    }
    static Operand sme_tile(uint32_t val, Arrangement arr = Arrangement::None) {
        return Operand(OperandType::SMETileRegister, static_cast<uint16_t>(make_za_reg(val, arr)));
    }
    static Operand memory_val(uint32_t val) {
        return Operand(OperandType::Memory, static_cast<uint16_t>(val));
    }
    static Operand reg_list(uint32_t first_reg) {
        return Operand(OperandType::RegisterList, static_cast<uint16_t>(first_reg));
    }
    static Operand memory_sve_offset(uint16_t base, int32_t offset = 0) {
        return Operand(OperandType::MemorySVEOffset, static_cast<uint16_t>(base), offset);
    }

    // Compact 16-byte layout (8-byte aligned)
    OperandType type = OperandType::Unknown;           // byte 0
    uint8_t extend = 0;                                // byte 1: MemoryMode / pred qualifier / extend type
    struct { bool has_index : 1; bool prefer_decimal : 1; uint8_t _reserved : 6; } flags = {};  // byte 2
    uint8_t amount = 0;                                // byte 3: shift/extend amount
    union { uint16_t value = 0; Register base_reg; };  // bytes 4-5
    Register index_reg = static_cast<Register>(0);     // bytes 6-7
    union {                                            // bytes 8-15
        uint64_t imm64 = 0;
        struct { int32_t offset; uint32_t index; };
        struct {
            union {
                SystemRegister sysreg;
                PstateField pstate;
                PrefetchOp prefetch;
                BarrierOp barrier;
                SvePattern pattern;
                SysOp sysop;
            };
        };
    };

    // Set arrangement on register value (bakes into Register enum)
    void set_arrangement(Arrangement arr) {
        value = static_cast<uint16_t>(set_register_arrangement(static_cast<Register>(value), arr));
    }

#ifndef VEDA64_NO_STRINGS
    // Format operand for disassembly
    std::string to_string() const;

private:
    // Helper functions for formatting
    static std::string format_register(uint32_t reg, bool is_64bit, bool is_sp = false);
    static std::string format_base_reg(Register reg) {
        if (static_cast<uint16_t>(reg) > 31) return register_to_string(reg);
        return format_register(static_cast<uint32_t>(reg), true, true);
    }
    static std::string format_vector_register(uint32_t reg, Arrangement arrangement);
    static Arrangement arr_from_size(uint32_t size);
    static Arrangement arr_narrow_from_size(uint32_t size);
    static Arrangement arr_wide_from_size(uint32_t size);
    static Arrangement vec_arr(uint32_t size, uint32_t q);
#endif
};
static_assert(sizeof(Operand) == 16, "Operand must be 16 bytes");
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
