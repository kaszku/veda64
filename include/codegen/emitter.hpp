// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <cstddef>
#include "registers.hpp"
#include "memory.hpp"
#include "label.hpp"
#include <veda64/types.hpp>

// Windows ARM64 SDK may define ARM intrinsic macros that clash
#ifdef mvn
#undef mvn
#endif

namespace veda64 {
namespace codegen {

/// Shift specifier for register operands
struct Shift {
    ShiftType type = ShiftType::LSL;
    uint8_t amount = 0;
    constexpr Shift() = default;
    constexpr Shift(ShiftType t, uint8_t a) : type(t), amount(a) {}
};

/// Extend specifier for register operands
struct Extend {
    ExtendType type;
    uint8_t amount = 0;
    constexpr Extend(ExtendType t, uint8_t a = 0) : type(t), amount(a) {}
};

/// JIT code generator / assembler
class CodeGenerator {
public:
    explicit CodeGenerator(size_t capacity = 4096);
    CodeGenerator(void* write_ptr, void* exec_ptr, size_t capacity);
    ~CodeGenerator();

    /// Get pointer to generated code (cast to function pointer)
    template<typename T> T get_code() const { return reinterpret_cast<T>(m_exec_ptr); }
    size_t size() const { return m_offset; }
    const uint8_t* data() const { return m_write_ptr; }

    /// Flush I-cache and resolve any pending labels
    CodeGenerator& ready();

    /// Bind a label at the current position
    CodeGenerator& bind(Label& label);

    // === Data Processing - Immediate ===
    CodeGenerator& add(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& add(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& sub(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& sub(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& adds(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& adds(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& subs(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& subs(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& and_(XReg rd, XReg rn, uint64_t imm);
    CodeGenerator& and_(WReg rd, WReg rn, uint64_t imm);
    CodeGenerator& orr(XReg rd, XReg rn, uint64_t imm);
    CodeGenerator& orr(WReg rd, WReg rn, uint64_t imm);
    CodeGenerator& eor(XReg rd, XReg rn, uint64_t imm);
    CodeGenerator& eor(WReg rd, WReg rn, uint64_t imm);
    CodeGenerator& ands(XReg rd, XReg rn, uint64_t imm);
    CodeGenerator& ands(WReg rd, WReg rn, uint64_t imm);
    CodeGenerator& movz(XReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& movz(WReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& movn(XReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& movn(WReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& movk(XReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& movk(WReg rd, uint16_t imm16, uint8_t hw = 0);
    CodeGenerator& adr(XReg rd, Label& label);
    CodeGenerator& adrp(XReg rd, int64_t imm);

    // === Data Processing - Register ===
    CodeGenerator& add(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& add(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& sub(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& sub(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& add(XReg rd, XReg rn, WReg rm, Extend ext);
    CodeGenerator& sub(XReg rd, XReg rn, WReg rm, Extend ext);
    CodeGenerator& adds(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& adds(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& subs(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& subs(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& and_(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& and_(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& orr(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& orr(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& eor(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& eor(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& orn(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& orn(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& bic(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& bic(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& ands(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& ands(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& lsl(XReg rd, XReg rn, XReg rm);
    CodeGenerator& lsl(WReg rd, WReg rn, WReg rm);
    CodeGenerator& lsr(XReg rd, XReg rn, XReg rm);
    CodeGenerator& lsr(WReg rd, WReg rn, WReg rm);
    CodeGenerator& asr(XReg rd, XReg rn, XReg rm);
    CodeGenerator& asr(WReg rd, WReg rn, WReg rm);
    CodeGenerator& mul(XReg rd, XReg rn, XReg rm);
    CodeGenerator& mul(WReg rd, WReg rn, WReg rm);
    CodeGenerator& sdiv(XReg rd, XReg rn, XReg rm);
    CodeGenerator& sdiv(WReg rd, WReg rn, WReg rm);
    CodeGenerator& udiv(XReg rd, XReg rn, XReg rm);
    CodeGenerator& udiv(WReg rd, WReg rn, WReg rm);
    CodeGenerator& madd(XReg rd, XReg rn, XReg rm, XReg ra);
    CodeGenerator& madd(WReg rd, WReg rn, WReg rm, WReg ra);
    CodeGenerator& csel(XReg rd, XReg rn, XReg rm, Condition cc);
    CodeGenerator& csel(WReg rd, WReg rn, WReg rm, Condition cc);

    // === Aliases ===
    CodeGenerator& cmp(XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& cmp(XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& cmp(WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& cmp(WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& cmn(XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& cmn(XReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& cmn(WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& cmn(WReg rn, uint32_t imm12, bool lsl12 = false);
    CodeGenerator& tst(XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& tst(WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& neg(XReg rd, XReg rm, Shift sh = {});
    CodeGenerator& mvn(XReg rd, XReg rm, Shift sh = {});
    CodeGenerator& neg(WReg rd, WReg rm, Shift sh = {});
    CodeGenerator& mvn(WReg rd, WReg rm, Shift sh = {});
    CodeGenerator& mov(XReg rd, uint64_t imm);
    CodeGenerator& mov(WReg rd, uint32_t imm);
    CodeGenerator& mov(XReg rd, XReg rm);
    CodeGenerator& mov(WReg rd, WReg rm);
    CodeGenerator& cset(XReg rd, Condition cc);
    CodeGenerator& cset(WReg rd, Condition cc);

    // === Branches ===
    CodeGenerator& b(Label& label);
    CodeGenerator& b(Condition cc, Label& label);
    CodeGenerator& bl(Label& label);
    CodeGenerator& br(XReg rn);
    CodeGenerator& blr(XReg rn);
    CodeGenerator& ret(XReg rn = XReg30);
    CodeGenerator& cbz(XReg rt, Label& label);
    CodeGenerator& cbz(WReg rt, Label& label);
    CodeGenerator& cbnz(XReg rt, Label& label);
    CodeGenerator& cbnz(WReg rt, Label& label);
    CodeGenerator& tbz(XReg rt, uint8_t bit, Label& label);
    CodeGenerator& tbz(WReg rt, uint8_t bit, Label& label);
    CodeGenerator& tbnz(XReg rt, uint8_t bit, Label& label);
    CodeGenerator& tbnz(WReg rt, uint8_t bit, Label& label);
    CodeGenerator& svc(uint16_t imm);
    CodeGenerator& brk(uint16_t imm);
    CodeGenerator& nop();

    // === Loads and Stores ===
    CodeGenerator& ldr(XReg rt, Mem mem);
    CodeGenerator& ldr(WReg rt, Mem mem);
    CodeGenerator& str(XReg rt, Mem mem);
    CodeGenerator& str(WReg rt, Mem mem);
    CodeGenerator& ldr(SReg rt, Mem mem);
    CodeGenerator& ldr(DReg rt, Mem mem);
    CodeGenerator& ldr(QReg rt, Mem mem);
    CodeGenerator& str(SReg rt, Mem mem);
    CodeGenerator& str(DReg rt, Mem mem);
    CodeGenerator& str(QReg rt, Mem mem);
    CodeGenerator& ldrb(WReg rt, Mem mem);
    CodeGenerator& ldrh(WReg rt, Mem mem);
    CodeGenerator& strb(WReg rt, Mem mem);
    CodeGenerator& strh(WReg rt, Mem mem);
    CodeGenerator& ldrsb(XReg rt, Mem mem);
    CodeGenerator& ldrsb(WReg rt, Mem mem);
    CodeGenerator& ldrsh(XReg rt, Mem mem);
    CodeGenerator& ldrsh(WReg rt, Mem mem);
    CodeGenerator& ldrsw(XReg rt, Mem mem);
    CodeGenerator& ldr(XReg rt, Label& label);
    CodeGenerator& ldr(WReg rt, Label& label);
    CodeGenerator& ldp(XReg rt1, XReg rt2, Mem mem);
    CodeGenerator& ldp(WReg rt1, WReg rt2, Mem mem);
    CodeGenerator& stp(XReg rt1, XReg rt2, Mem mem);
    CodeGenerator& stp(WReg rt1, WReg rt2, Mem mem);

    // === Scalar FP ===
    CodeGenerator& fadd(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fadd(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fsub(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fsub(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fmul(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fmul(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fdiv(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fdiv(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fmov(SReg rd, SReg rn);
    CodeGenerator& fmov(DReg rd, DReg rn);
    CodeGenerator& fcmp(SReg rn, SReg rm);
    CodeGenerator& fcmp(SReg rn);  // compare with 0.0
    CodeGenerator& fcmp(DReg rn, DReg rm);
    CodeGenerator& fcmp(DReg rn);  // compare with 0.0

private:
    void emit(uint32_t insn);
    void patch(size_t offset, uint32_t insn);
    int32_t label_offset(Label& label, PatchType type);

    uint8_t* m_write_ptr;
    uint8_t* m_exec_ptr;
    size_t m_capacity;
    size_t m_offset;
    bool m_owns_buffer;
};

} // namespace codegen
} // namespace veda64
