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
    CodeGenerator& ror(XReg rd, XReg rn, XReg rm);
    CodeGenerator& ror(WReg rd, WReg rn, WReg rm);
    CodeGenerator& mul(XReg rd, XReg rn, XReg rm);
    CodeGenerator& mul(WReg rd, WReg rn, WReg rm);
    CodeGenerator& sdiv(XReg rd, XReg rn, XReg rm);
    CodeGenerator& sdiv(WReg rd, WReg rn, WReg rm);
    CodeGenerator& udiv(XReg rd, XReg rn, XReg rm);
    CodeGenerator& udiv(WReg rd, WReg rn, WReg rm);
    CodeGenerator& madd(XReg rd, XReg rn, XReg rm, XReg ra);
    CodeGenerator& madd(WReg rd, WReg rn, WReg rm, WReg ra);
    CodeGenerator& msub(XReg rd, XReg rn, XReg rm, XReg ra);
    CodeGenerator& msub(WReg rd, WReg rn, WReg rm, WReg ra);
    CodeGenerator& mneg(XReg rd, XReg rn, XReg rm);
    CodeGenerator& mneg(WReg rd, WReg rn, WReg rm);
    CodeGenerator& smull(XReg rd, WReg rn, WReg rm);
    CodeGenerator& umull(XReg rd, WReg rn, WReg rm);
    CodeGenerator& smulh(XReg rd, XReg rn, XReg rm);
    CodeGenerator& umulh(XReg rd, XReg rn, XReg rm);
    CodeGenerator& adc(XReg rd, XReg rn, XReg rm);
    CodeGenerator& adc(WReg rd, WReg rn, WReg rm);
    CodeGenerator& adcs(XReg rd, XReg rn, XReg rm);
    CodeGenerator& adcs(WReg rd, WReg rn, WReg rm);
    CodeGenerator& sbc(XReg rd, XReg rn, XReg rm);
    CodeGenerator& sbc(WReg rd, WReg rn, WReg rm);
    CodeGenerator& sbcs(XReg rd, XReg rn, XReg rm);
    CodeGenerator& sbcs(WReg rd, WReg rn, WReg rm);
    CodeGenerator& csel(XReg rd, XReg rn, XReg rm, Condition cc);
    CodeGenerator& csel(WReg rd, WReg rn, WReg rm, Condition cc);
    CodeGenerator& csinc(XReg rd, XReg rn, XReg rm, Condition cc);
    CodeGenerator& csinc(WReg rd, WReg rn, WReg rm, Condition cc);
    CodeGenerator& csinv(XReg rd, XReg rn, XReg rm, Condition cc);
    CodeGenerator& csinv(WReg rd, WReg rn, WReg rm, Condition cc);
    CodeGenerator& csneg(XReg rd, XReg rn, XReg rm, Condition cc);
    CodeGenerator& csneg(WReg rd, WReg rn, WReg rm, Condition cc);
    CodeGenerator& ccmp(XReg rn, XReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmp(XReg rn, uint8_t imm5, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmp(WReg rn, WReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmp(WReg rn, uint8_t imm5, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmn(XReg rn, XReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmn(XReg rn, uint8_t imm5, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmn(WReg rn, WReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& ccmn(WReg rn, uint8_t imm5, uint8_t nzcv, Condition cc);
    CodeGenerator& clz(XReg rd, XReg rn);
    CodeGenerator& clz(WReg rd, WReg rn);
    CodeGenerator& cls(XReg rd, XReg rn);
    CodeGenerator& cls(WReg rd, WReg rn);
    CodeGenerator& rbit(XReg rd, XReg rn);
    CodeGenerator& rbit(WReg rd, WReg rn);
    CodeGenerator& rev(XReg rd, XReg rn);
    CodeGenerator& rev(WReg rd, WReg rn);

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
    CodeGenerator& ngc(XReg rd, XReg rm);
    CodeGenerator& neg(WReg rd, WReg rm, Shift sh = {});
    CodeGenerator& mvn(WReg rd, WReg rm, Shift sh = {});
    CodeGenerator& ngc(WReg rd, WReg rm);
    CodeGenerator& mov(XReg rd, uint64_t imm);
    CodeGenerator& mov(WReg rd, uint32_t imm);
    CodeGenerator& mov(XReg rd, XReg rm);
    CodeGenerator& mov(WReg rd, WReg rm);
    CodeGenerator& cset(XReg rd, Condition cc);
    CodeGenerator& cset(WReg rd, Condition cc);
    CodeGenerator& cinc(XReg rd, XReg rn, Condition cc);
    CodeGenerator& cinc(WReg rd, WReg rn, Condition cc);
    CodeGenerator& cinv(XReg rd, XReg rn, Condition cc);
    CodeGenerator& cinv(WReg rd, WReg rn, Condition cc);
    CodeGenerator& cneg(XReg rd, XReg rn, Condition cc);
    CodeGenerator& cneg(WReg rd, WReg rn, Condition cc);
    CodeGenerator& tst(XReg rn, uint64_t imm);
    CodeGenerator& tst(WReg rn, uint64_t imm);
    CodeGenerator& lsl(XReg rd, XReg rn, uint8_t imm);
    CodeGenerator& lsl(WReg rd, WReg rn, uint8_t imm);
    CodeGenerator& lsr(XReg rd, XReg rn, uint8_t imm);
    CodeGenerator& lsr(WReg rd, WReg rn, uint8_t imm);
    CodeGenerator& asr(XReg rd, XReg rn, uint8_t imm);
    CodeGenerator& asr(WReg rd, WReg rn, uint8_t imm);
    CodeGenerator& ror(XReg rd, XReg rn, uint8_t imm);
    CodeGenerator& ror(WReg rd, WReg rn, uint8_t imm);
    CodeGenerator& bfi(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& bfi(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& bfxil(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& bfxil(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& sbfx(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& sbfx(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& ubfx(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& ubfx(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& sbfiz(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& sbfiz(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& ubfiz(XReg rd, XReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& ubfiz(WReg rd, WReg rn, uint8_t lsb, uint8_t width);
    CodeGenerator& extr(XReg rd, XReg rn, XReg rm, uint8_t lsb);
    CodeGenerator& extr(WReg rd, WReg rn, WReg rm, uint8_t lsb);
    CodeGenerator& sxtb(XReg rd, WReg rn);
    CodeGenerator& sxtb(WReg rd, WReg rn);
    CodeGenerator& sxth(XReg rd, WReg rn);
    CodeGenerator& sxth(WReg rd, WReg rn);
    CodeGenerator& sxtw(XReg rd, WReg rn);
    CodeGenerator& uxtb(WReg rd, WReg rn);
    CodeGenerator& uxth(WReg rd, WReg rn);

    // === Branches ===
    CodeGenerator& b(Label& label);
    CodeGenerator& b(Condition cc, Label& label);
    CodeGenerator& bl(Label& label);
    CodeGenerator& br(XReg rn);
    CodeGenerator& blr(XReg rn);
    CodeGenerator& ret(XReg rn = XReg{30});
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

    // === Atomics and Exclusives ===
    CodeGenerator& ldar(XReg rt, XReg rn);
    CodeGenerator& stlr(XReg rt, XReg rn);
    CodeGenerator& ldar(WReg rt, XReg rn);
    CodeGenerator& stlr(WReg rt, XReg rn);
    CodeGenerator& ldarb(WReg rt, XReg rn);
    CodeGenerator& ldarh(WReg rt, XReg rn);
    CodeGenerator& stlrb(WReg rt, XReg rn);
    CodeGenerator& stlrh(WReg rt, XReg rn);
    CodeGenerator& ldxr(XReg rt, XReg rn);
    CodeGenerator& stxr(WReg rs, XReg rt, XReg rn);
    CodeGenerator& ldxr(WReg rt, XReg rn);
    CodeGenerator& stxr(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldxrb(WReg rt, XReg rn);
    CodeGenerator& ldxrh(WReg rt, XReg rn);
    CodeGenerator& stxrb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& stxrh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaxr(XReg rt, XReg rn);
    CodeGenerator& stlxr(WReg rs, XReg rt, XReg rn);
    CodeGenerator& ldaxr(WReg rt, XReg rn);
    CodeGenerator& stlxr(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaxrb(WReg rt, XReg rn);
    CodeGenerator& ldaxrh(WReg rt, XReg rn);
    CodeGenerator& stlxrb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& stlxrh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& cas(XReg rs, XReg rt, XReg rn);
    CodeGenerator& cas(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casa(XReg rs, XReg rt, XReg rn);
    CodeGenerator& casa(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& casl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& casal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& cash(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& caslb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& caslh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& casalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swp(XReg rs, XReg rt, XReg rn);
    CodeGenerator& swp(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpa(XReg rs, XReg rt, XReg rn);
    CodeGenerator& swpa(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& swpl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& swpal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swph(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swplb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swplh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& swpalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldadd(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldadd(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldadda(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldadda(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldaddl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldaddal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldaddalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclr(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldclr(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclra(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldclra(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldclrl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclral(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldclral(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclrlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclralb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldclralh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldset(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldset(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldseta(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldseta(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsetl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsetal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldseth(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsetalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeor(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldeor(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeora(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldeora(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldeorl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeoral(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldeoral(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeorlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeoralb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldeoralh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& stadd(XReg rs, XReg rn);
    CodeGenerator& stadd(WReg rs, XReg rn);
    CodeGenerator& staddl(XReg rs, XReg rn);
    CodeGenerator& staddl(WReg rs, XReg rn);
    CodeGenerator& stclr(XReg rs, XReg rn);
    CodeGenerator& stclr(WReg rs, XReg rn);
    CodeGenerator& stclrl(XReg rs, XReg rn);
    CodeGenerator& stclrl(WReg rs, XReg rn);
    CodeGenerator& stset(XReg rs, XReg rn);
    CodeGenerator& stset(WReg rs, XReg rn);
    CodeGenerator& stsetl(XReg rs, XReg rn);
    CodeGenerator& stsetl(WReg rs, XReg rn);
    CodeGenerator& steor(XReg rs, XReg rn);
    CodeGenerator& steor(WReg rs, XReg rn);
    CodeGenerator& steorl(XReg rs, XReg rn);
    CodeGenerator& steorl(WReg rs, XReg rn);

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

    // === Advanced SIMD (Vector) ===
    CodeGenerator& add(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& mul(VArr vd, VArr vn, VArr vm);
    CodeGenerator& and_(VArr vd, VArr vn, VArr vm);
    CodeGenerator& orr(VArr vd, VArr vn, VArr vm);
    CodeGenerator& eor(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bic(VArr vd, VArr vn, VArr vm);
    CodeGenerator& not_(VArr vd, VArr vn);
    CodeGenerator& mvn(VArr vd, VArr vn);
    CodeGenerator& addp(VArr vd, VArr vn, VArr vm);
    CodeGenerator& abs(VArr vd, VArr vn);
    CodeGenerator& neg(VArr vd, VArr vn);
    CodeGenerator& cnt(VArr vd, VArr vn);
    CodeGenerator& cmeq(VArr vd, VArr vn, VArr vm);
    CodeGenerator& cmge(VArr vd, VArr vn, VArr vm);
    CodeGenerator& cmgt(VArr vd, VArr vn, VArr vm);
    CodeGenerator& cmhi(VArr vd, VArr vn, VArr vm);
    CodeGenerator& cmhs(VArr vd, VArr vn, VArr vm);
    CodeGenerator& cmeq_zero(VArr vd, VArr vn);
    CodeGenerator& cmge_zero(VArr vd, VArr vn);
    CodeGenerator& cmgt_zero(VArr vd, VArr vn);
    CodeGenerator& cmle_zero(VArr vd, VArr vn);
    CodeGenerator& cmlt_zero(VArr vd, VArr vn);
    CodeGenerator& shl(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& sshr(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& ushr(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& dup(VArr vd, XReg rn);  // dup from 64-bit GP
    CodeGenerator& dup(VArr vd, WReg rn);  // dup from 32-bit GP
    CodeGenerator& ins(VArr vd, uint8_t index, XReg rn);
    CodeGenerator& ins(VArr vd, uint8_t index, WReg rn);
    CodeGenerator& umov(XReg rd, VArr vn, uint8_t index);
    CodeGenerator& umov(WReg rd, VArr vn, uint8_t index);
    CodeGenerator& movi(VArr vd, uint8_t imm8);


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
