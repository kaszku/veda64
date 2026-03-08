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
    void ready();

    /// Bind a label at the current position
    void bind(Label& label);

    // === Data Processing - Immediate ===
    void add(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    void add(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    void sub(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    void sub(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    void adds(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    void adds(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    void subs(XReg rd, XReg rn, uint32_t imm12, bool lsl12 = false);
    void subs(WReg rd, WReg rn, uint32_t imm12, bool lsl12 = false);
    void and_(XReg rd, XReg rn, uint64_t imm);
    void and_(WReg rd, WReg rn, uint64_t imm);
    void orr(XReg rd, XReg rn, uint64_t imm);
    void orr(WReg rd, WReg rn, uint64_t imm);
    void eor(XReg rd, XReg rn, uint64_t imm);
    void eor(WReg rd, WReg rn, uint64_t imm);
    void ands(XReg rd, XReg rn, uint64_t imm);
    void ands(WReg rd, WReg rn, uint64_t imm);
    void movz(XReg rd, uint16_t imm16, uint8_t hw = 0);
    void movz(WReg rd, uint16_t imm16, uint8_t hw = 0);
    void movn(XReg rd, uint16_t imm16, uint8_t hw = 0);
    void movn(WReg rd, uint16_t imm16, uint8_t hw = 0);
    void movk(XReg rd, uint16_t imm16, uint8_t hw = 0);
    void movk(WReg rd, uint16_t imm16, uint8_t hw = 0);
    void adr(XReg rd, Label& label);
    void adrp(XReg rd, int64_t imm);

    // === Data Processing - Register ===
    void add(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void add(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void sub(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void sub(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void add(XReg rd, XReg rn, WReg rm, Extend ext);
    void sub(XReg rd, XReg rn, WReg rm, Extend ext);
    void adds(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void adds(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void subs(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void subs(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void and_(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void and_(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void orr(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void orr(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void eor(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void eor(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void orn(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void orn(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void bic(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void bic(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void ands(XReg rd, XReg rn, XReg rm, Shift sh = {});
    void ands(WReg rd, WReg rn, WReg rm, Shift sh = {});
    void lsl(XReg rd, XReg rn, XReg rm);
    void lsl(WReg rd, WReg rn, WReg rm);
    void lsr(XReg rd, XReg rn, XReg rm);
    void lsr(WReg rd, WReg rn, WReg rm);
    void asr(XReg rd, XReg rn, XReg rm);
    void asr(WReg rd, WReg rn, WReg rm);
    void mul(XReg rd, XReg rn, XReg rm);
    void mul(WReg rd, WReg rn, WReg rm);
    void sdiv(XReg rd, XReg rn, XReg rm);
    void sdiv(WReg rd, WReg rn, WReg rm);
    void udiv(XReg rd, XReg rn, XReg rm);
    void udiv(WReg rd, WReg rn, WReg rm);
    void madd(XReg rd, XReg rn, XReg rm, XReg ra);
    void madd(WReg rd, WReg rn, WReg rm, WReg ra);
    void csel(XReg rd, XReg rn, XReg rm, Condition cc);
    void csel(WReg rd, WReg rn, WReg rm, Condition cc);

    // === Aliases ===
    void cmp(XReg rn, XReg rm, Shift sh = {});
    void cmp(XReg rn, uint32_t imm12, bool lsl12 = false);
    void cmp(WReg rn, WReg rm, Shift sh = {});
    void cmp(WReg rn, uint32_t imm12, bool lsl12 = false);
    void cmn(XReg rn, XReg rm, Shift sh = {});
    void cmn(XReg rn, uint32_t imm12, bool lsl12 = false);
    void cmn(WReg rn, WReg rm, Shift sh = {});
    void cmn(WReg rn, uint32_t imm12, bool lsl12 = false);
    void tst(XReg rn, XReg rm, Shift sh = {});
    void tst(WReg rn, WReg rm, Shift sh = {});
    void neg(XReg rd, XReg rm, Shift sh = {});
    void mvn(XReg rd, XReg rm, Shift sh = {});
    void neg(WReg rd, WReg rm, Shift sh = {});
    void mvn(WReg rd, WReg rm, Shift sh = {});
    void mov(XReg rd, uint64_t imm);
    void mov(WReg rd, uint32_t imm);
    void mov(XReg rd, XReg rm);
    void mov(WReg rd, WReg rm);
    void cset(XReg rd, Condition cc);
    void cset(WReg rd, Condition cc);

    // === Branches ===
    void b(Label& label);
    void b(Condition cc, Label& label);
    void bl(Label& label);
    void br(XReg rn);
    void blr(XReg rn);
    void ret(XReg rn = XReg{30});
    void cbz(XReg rt, Label& label);
    void cbz(WReg rt, Label& label);
    void cbnz(XReg rt, Label& label);
    void cbnz(WReg rt, Label& label);
    void tbz(XReg rt, uint8_t bit, Label& label);
    void tbz(WReg rt, uint8_t bit, Label& label);
    void tbnz(XReg rt, uint8_t bit, Label& label);
    void tbnz(WReg rt, uint8_t bit, Label& label);
    void svc(uint16_t imm);
    void brk(uint16_t imm);
    void nop();

    // === Loads and Stores ===
    void ldr(XReg rt, Mem mem);
    void ldr(WReg rt, Mem mem);
    void str(XReg rt, Mem mem);
    void str(WReg rt, Mem mem);
    void ldr(SReg rt, Mem mem);
    void ldr(DReg rt, Mem mem);
    void ldr(QReg rt, Mem mem);
    void str(SReg rt, Mem mem);
    void str(DReg rt, Mem mem);
    void str(QReg rt, Mem mem);
    void ldrb(WReg rt, Mem mem);
    void ldrh(WReg rt, Mem mem);
    void strb(WReg rt, Mem mem);
    void strh(WReg rt, Mem mem);
    void ldrsb(XReg rt, Mem mem);
    void ldrsb(WReg rt, Mem mem);
    void ldrsh(XReg rt, Mem mem);
    void ldrsh(WReg rt, Mem mem);
    void ldrsw(XReg rt, Mem mem);
    void ldr(XReg rt, Label& label);
    void ldr(WReg rt, Label& label);
    void ldp(XReg rt1, XReg rt2, Mem mem);
    void ldp(WReg rt1, WReg rt2, Mem mem);
    void stp(XReg rt1, XReg rt2, Mem mem);
    void stp(WReg rt1, WReg rt2, Mem mem);

    // === Scalar FP ===
    void fadd(SReg rd, SReg rn, SReg rm);
    void fadd(DReg rd, DReg rn, DReg rm);
    void fsub(SReg rd, SReg rn, SReg rm);
    void fsub(DReg rd, DReg rn, DReg rm);
    void fmul(SReg rd, SReg rn, SReg rm);
    void fmul(DReg rd, DReg rn, DReg rm);
    void fdiv(SReg rd, SReg rn, SReg rm);
    void fdiv(DReg rd, DReg rn, DReg rm);
    void fmov(SReg rd, SReg rn);
    void fmov(DReg rd, DReg rn);
    void fcmp(SReg rn, SReg rm);
    void fcmp(SReg rn);  // compare with 0.0
    void fcmp(DReg rn, DReg rm);
    void fcmp(DReg rn);  // compare with 0.0

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
