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

// Operand representation — tagged union layout
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4201)  // nameless struct/union
#endif
#pragma pack(push, 2)
class alignas(8) Operand {
public:
    Operand() = default;


    // Static factory methods for memory operands
    static Operand memory_base(uint16_t base) {
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(base); op.mem.mode = MemoryMode::Base; return op;
    }
    static Operand memory_offset(uint16_t base, int32_t offset) {
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(base); op.mem.offset = offset;
        op.mem.mode = (offset == 0) ? MemoryMode::Base : MemoryMode::Offset; return op;
    }
    static Operand memory_pre_index(uint16_t base, int32_t offset) {
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(base); op.mem.offset = offset;
        op.mem.mode = MemoryMode::PreIndex; return op;
    }
    static Operand memory_post_index(uint16_t base, int32_t offset) {
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(base); op.mem.offset = offset;
        op.mem.mode = MemoryMode::PostIndex; return op;
    }
    static Operand memory_mul_vl(uint16_t base, int32_t offset) {
        if (offset == 0) return memory_base(base);
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(base); op.mem.offset = offset;
        op.mem.mode = MemoryMode::MulVL; return op;
    }
    static Operand memory_reg_offset(uint16_t base, uint32_t index, uint32_t extend = 0, uint32_t amount = 0) {
        Operand op; op.type = OperandType::MemoryRegOffset;
        op.mreg.base = static_cast<Register>(base);
        op.mreg.extend = static_cast<ExtendType>(extend);
        op.mreg.amount = static_cast<uint8_t>(amount);
        op.mreg.index = make_gp_reg(index, !(extend == 2 || extend == 6));
        return op;
    }

    // ── Register factories ──
    static Operand gp(uint32_t num, bool is_64, bool is_sp = false) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_gp_reg(num, is_64, is_sp); return op;
    }
    static Operand scalar(uint32_t num, Arrangement size) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_scalar_reg(num, size); return op;
    }
    static Operand vec(uint32_t num, Arrangement arr = Arrangement::None) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_vec_reg(num, arr); return op;
    }
    static Operand sve(uint32_t num, Arrangement arr = Arrangement::None) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_sve_reg(num, arr); return op;
    }
    static Operand pred(uint32_t num, PredQual qualifier = PredQual::None, Arrangement arr = Arrangement::None) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_pred_reg(num, arr); op.r.qual = qualifier; return op;
    }
    static Operand predn(uint32_t num, Arrangement arr = Arrangement::None) {
        Operand op; op.type = OperandType::Register; op.r.reg = make_predn_reg(num, arr); return op;
    }
    static Operand zt0() {
        Operand op; op.type = OperandType::Register; op.r.reg = Register::ZT0; return op;
    }
    static Operand reg(Register rv) {
        Operand op; op.type = OperandType::Register; op.r.reg = rv; return op;
    }

    // ── Immediate factories ──
    static Operand imm(uint64_t val) {
        Operand op; op.type = OperandType::Immediate; op.iv.value = val; return op;
    }
    static Operand simm(int64_t val) {
        Operand op; op.type = OperandType::SignedImmediate; op.si.offset = static_cast<int32_t>(val); return op;
    }
    static Operand label(int64_t off) {
        Operand op; op.type = OperandType::Label; op.si.offset = static_cast<int32_t>(off); return op;
    }
    static Operand relative(int64_t off) {
        Operand op; op.type = OperandType::Relative; op.iv.value = static_cast<uint64_t>(off); return op;
    }
    static Operand float_imm(uint32_t encoded) {
        Operand op; op.type = OperandType::FloatImmediate; op.sv.val = static_cast<uint16_t>(encoded); return op;
    }

    // ── Shift/Extend factories (typed enums) ──
    static Operand shift(ShiftType stype, uint32_t amt) {
        Operand op; op.type = OperandType::Shift; op.sh.shift_type = stype; op.sh.amount = static_cast<uint8_t>(amt); return op;
    }
    static Operand extend_op(ExtendType etype, uint32_t amt, bool is_64 = false) {
        Operand op; op.type = OperandType::Extend; op.ext.ext_type = etype; op.ext.amount = static_cast<uint8_t>(amt);
        if (is_64) op.type = OperandType::Extend64; return op;
    }

    // ── Misc factories ──
    static Operand pat(SvePattern p) {
        Operand op; op.type = OperandType::Pattern; op.e.pattern = p; return op;
    }
    static Operand sve_mul(uint32_t val) {
        Operand op; op.type = OperandType::SVEMulImm; op.sv.val = static_cast<uint16_t>(val); return op;
    }
    static Operand prefetch_op(PrefetchOp p) {
        Operand op; op.type = OperandType::Prefetch; op.e.prefetch = p; return op;
    }
    static Operand barrier_op(BarrierOp b) {
        Operand op; op.type = OperandType::Barrier; op.e.barrier = b; return op;
    }
    static Operand sysreg_op(SystemRegister rv) {
        Operand op; op.type = OperandType::SystemRegister; op.sys.sysreg = rv; return op;
    }
    static Operand pstate_op(PstateField f) {
        Operand op; op.type = OperandType::PstateField; op.e.pstate = f; return op;
    }
    static Operand sysop_op(SysOp s) {
        Operand op; op.type = OperandType::SysOp; op.e.sysop = s; return op;
    }
    static Operand fixed_sym(uint32_t idx) {
        Operand op; op.type = OperandType::FixedSym; op.sv.val = static_cast<uint16_t>(idx); return op;
    }
    static Operand vlx(uint32_t n) {
        Operand op; op.type = OperandType::SVEVLxImm; op.sv.val = static_cast<uint16_t>(n); return op;
    }
    static Operand sme_tile(uint32_t val, Arrangement arr = Arrangement::None) {
        Operand op; op.type = OperandType::SMETileRegister; op.sme.tile = make_za_reg(val, arr); return op;
    }
    static Operand memory_val(uint32_t val) {
        Operand op; op.type = OperandType::Memory; op.mem.base = static_cast<Register>(val); return op;
    }
    static Operand reg_list(uint32_t first_reg) {
        Operand op; op.type = OperandType::RegisterList; op.rl.first = static_cast<Register>(first_reg); return op;
    }
    static Operand memory_sve_offset(uint16_t base, int32_t offset = 0) {
        Operand op; op.type = OperandType::MemorySVEOffset; op.msve.base = static_cast<Register>(base); op.msve.offset = offset; return op;
    }

    // Tagged union layout (16 bytes)
    OperandType type = OperandType::Unknown;  // byte 0
    uint8_t _pad0 = 0;                        // byte 1 (reserved)
    union {                                   // bytes 2-15 (14 bytes)
        // Register (GP, V, Z, P, PN, ZT0)
        struct { PredQual qual; uint8_t _r0; Register reg; Register idx_reg; uint32_t index; } r;
        // SMETileRegister
        struct { uint8_t mode; uint8_t start; Register tile; uint16_t wv; int32_t detail; } sme;
        // Immediate (unsigned 64-bit)
        struct { uint8_t _i0[6]; uint64_t value; } iv;
        // SignedImmediate / Label
        struct { uint8_t _si0[6]; int32_t offset; } si;
        // Memory [base, #offset]
        struct { MemoryMode mode; uint8_t _m0; Register base; uint16_t _m1; int32_t offset; } mem;
        // MemoryRegOffset [base, Rm, extend #amt]
        struct { ExtendType extend; uint8_t amount; Register base; Register index; } mreg;
        // MemorySVEOffset [Zn.T, #offset]
        struct { uint8_t _msv0[2]; Register base; uint16_t _msv1; int32_t offset; } msve;
        // Shift
        struct { ShiftType shift_type; uint8_t amount; } sh;
        // Extend
        struct { ExtendType ext_type; uint8_t amount; } ext;
        // RegisterList
        struct { uint8_t count; uint8_t stride; Register first; uint8_t elem_index; } rl;
        // SystemRegister
        struct { uint8_t _sys0[6]; SystemRegister sysreg; } sys;
        // Enum-only (Pattern/Prefetch/Barrier/PstateField/SysOp)
        struct { union { SvePattern pattern; PrefetchOp prefetch; BarrierOp barrier; PstateField pstate; }; uint8_t _e0; uint8_t _e1; SysOp sysop; } e;
        // SmallVal (FloatImmediate/Index/SVEMulImm/SVEVLxImm/FixedSym)
        struct { uint16_t val; } sv;
        uint8_t _raw[14] = {};  // zero-init
    };

    // Convenience: read register value as uint16_t
    uint16_t reg_val() const { return static_cast<uint16_t>(r.reg); }

    // Set arrangement on register (works for r.reg, sme.tile, rl.first — all at same offset)
    void set_arrangement(Arrangement arr) {
        r.reg = set_register_arrangement(r.reg, arr);
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
#pragma pack(pop)
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
