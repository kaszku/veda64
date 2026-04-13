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

/// Spec for emit_prolog / emit_epilog
struct PrologSpec {
    // Pairs of callee-saved X regs to save (stored via STP, pre-indexed).
    // Each inner pair consumes 16 bytes on the stack. Example: {{x19,x20},{x21,x22}}.
    struct Pair { XReg a; XReg b; };
    Pair saved_pairs[8] = {};   // fixed-size to avoid pulling in <vector>
    uint8_t num_pairs = 0;
    // Callee-saved SIMD pairs (d8-d15 on AAPCS64). Each pair = 16 bytes.
    struct DPair { DReg a; DReg b; };
    DPair saved_dpairs[4] = {};
    uint8_t num_dpairs = 0;
    // Local frame size (bytes). Must be 16-byte aligned. Subtracted from SP after
    // callee-saves. Supports up to 0xFFF << 12 via optional 12-bit shift.
    uint32_t frame_size = 0;
    // Emit the standard FP/LR chain: STP X29,X30,[SP,#-16]! ; MOV X29,SP
    bool chain_fp_lr = true;
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

    // === Bitfield Move ===
    CodeGenerator& bfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms);
    CodeGenerator& bfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms);
    CodeGenerator& sbfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms);
    CodeGenerator& sbfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms);
    CodeGenerator& ubfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms);
    CodeGenerator& ubfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms);

    // === Function prolog / epilog ===
    CodeGenerator& emit_prolog(const PrologSpec& spec);
    CodeGenerator& emit_epilog(const PrologSpec& spec);

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

    // === System and Barriers ===
    CodeGenerator& hlt(uint16_t imm);
    CodeGenerator& eret();
    CodeGenerator& dmb(uint8_t option);
    CodeGenerator& dsb(uint8_t option);
    CodeGenerator& isb();
    CodeGenerator& clrex();
    CodeGenerator& mrs(XReg rt, uint32_t o0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2);
    CodeGenerator& msr(uint32_t o0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2, XReg rt);

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

    // === Atomic Min/Max ===
    CodeGenerator& ldsmax(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmax(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxa(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmaxa(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmaxl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmaxal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmaxalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmin(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmin(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsmina(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsmina(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsminl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldsminal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldsminalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumax(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumax(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxa(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumaxa(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumaxl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumaxal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumaxalh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumin(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumin(WReg rs, WReg rt, XReg rn);
    CodeGenerator& ldumina(XReg rs, XReg rt, XReg rn);
    CodeGenerator& ldumina(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& lduminl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& lduminal(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminab(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminah(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminlb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminlh(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminalb(WReg rs, WReg rt, XReg rn);
    CodeGenerator& lduminalh(WReg rs, WReg rt, XReg rn);

    // === Store Atomic Min/Max ===
    CodeGenerator& stsmax(XReg rs, XReg rn);
    CodeGenerator& stsmax(WReg rs, XReg rn);
    CodeGenerator& stsmaxl(XReg rs, XReg rn);
    CodeGenerator& stsmaxl(WReg rs, XReg rn);
    CodeGenerator& stsmaxb(WReg rs, XReg rn);
    CodeGenerator& stsmaxlb(WReg rs, XReg rn);
    CodeGenerator& stsmaxh(WReg rs, XReg rn);
    CodeGenerator& stsmaxlh(WReg rs, XReg rn);
    CodeGenerator& stsmin(XReg rs, XReg rn);
    CodeGenerator& stsmin(WReg rs, XReg rn);
    CodeGenerator& stsminl(XReg rs, XReg rn);
    CodeGenerator& stsminl(WReg rs, XReg rn);
    CodeGenerator& stsminb(WReg rs, XReg rn);
    CodeGenerator& stsminlb(WReg rs, XReg rn);
    CodeGenerator& stsminh(WReg rs, XReg rn);
    CodeGenerator& stsminlh(WReg rs, XReg rn);
    CodeGenerator& stumax(XReg rs, XReg rn);
    CodeGenerator& stumax(WReg rs, XReg rn);
    CodeGenerator& stumaxl(XReg rs, XReg rn);
    CodeGenerator& stumaxl(WReg rs, XReg rn);
    CodeGenerator& stumaxb(WReg rs, XReg rn);
    CodeGenerator& stumaxlb(WReg rs, XReg rn);
    CodeGenerator& stumaxh(WReg rs, XReg rn);
    CodeGenerator& stumaxlh(WReg rs, XReg rn);
    CodeGenerator& stumin(XReg rs, XReg rn);
    CodeGenerator& stumin(WReg rs, XReg rn);
    CodeGenerator& stuminl(XReg rs, XReg rn);
    CodeGenerator& stuminl(WReg rs, XReg rn);
    CodeGenerator& stuminb(WReg rs, XReg rn);
    CodeGenerator& stuminlb(WReg rs, XReg rn);
    CodeGenerator& stuminh(WReg rs, XReg rn);
    CodeGenerator& stuminlh(WReg rs, XReg rn);

    // === Load-Acquire RCpc ===
    CodeGenerator& ldapr(XReg rt, XReg rn);
    CodeGenerator& ldapr(WReg rt, XReg rn);
    CodeGenerator& ldaprb(WReg rt, XReg rn);
    CodeGenerator& ldaprh(WReg rt, XReg rn);

    // === Prefetch ===
    CodeGenerator& prfm(uint8_t op, Mem mem);

    // === Exclusive Pairs ===
    CodeGenerator& ldxp(XReg rt1, XReg rt2, XReg rn);
    CodeGenerator& ldxp(WReg rt1, WReg rt2, XReg rn);
    CodeGenerator& stxp(WReg rs, XReg rt1, XReg rt2, XReg rn);
    CodeGenerator& stxp(WReg rs, WReg rt1, WReg rt2, XReg rn);
    CodeGenerator& ldaxp(XReg rt1, XReg rt2, XReg rn);
    CodeGenerator& ldaxp(WReg rt1, WReg rt2, XReg rn);
    CodeGenerator& stlxp(WReg rs, XReg rt1, XReg rt2, XReg rn);
    CodeGenerator& stlxp(WReg rs, WReg rt1, WReg rt2, XReg rn);

    // === Non-Temporal Pairs ===
    CodeGenerator& ldnp(XReg rt1, XReg rt2, Mem mem);
    CodeGenerator& ldnp(WReg rt1, WReg rt2, Mem mem);
    CodeGenerator& stnp(XReg rt1, XReg rt2, Mem mem);
    CodeGenerator& stnp(WReg rt1, WReg rt2, Mem mem);
    CodeGenerator& ldnp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& ldnp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& ldnp(QReg rt1, QReg rt2, Mem mem);
    CodeGenerator& stnp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& stnp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& stnp(QReg rt1, QReg rt2, Mem mem);

    // === Signed Load Pair ===
    CodeGenerator& ldpsw(XReg rt1, XReg rt2, Mem mem);

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
    CodeGenerator& fabs(SReg rd, SReg rn);
    CodeGenerator& fabs(DReg rd, DReg rn);
    CodeGenerator& fneg(SReg rd, SReg rn);
    CodeGenerator& fneg(DReg rd, DReg rn);
    CodeGenerator& fsqrt(SReg rd, SReg rn);
    CodeGenerator& fsqrt(DReg rd, DReg rn);
    CodeGenerator& fmadd(SReg rd, SReg rn, SReg rm, SReg ra);
    CodeGenerator& fmadd(DReg rd, DReg rn, DReg rm, DReg ra);
    CodeGenerator& fmsub(SReg rd, SReg rn, SReg rm, SReg ra);
    CodeGenerator& fmsub(DReg rd, DReg rn, DReg rm, DReg ra);
    CodeGenerator& fnmadd(SReg rd, SReg rn, SReg rm, SReg ra);
    CodeGenerator& fnmadd(DReg rd, DReg rn, DReg rm, DReg ra);
    CodeGenerator& fnmsub(SReg rd, SReg rn, SReg rm, SReg ra);
    CodeGenerator& fnmsub(DReg rd, DReg rn, DReg rm, DReg ra);
    CodeGenerator& fcsel(SReg rd, SReg rn, SReg rm, Condition cc);
    CodeGenerator& fcsel(DReg rd, DReg rn, DReg rm, Condition cc);
    CodeGenerator& fccmp(SReg rn, SReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& fccmp(DReg rn, DReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& scvtf(SReg rd, WReg rn);
    CodeGenerator& scvtf(DReg rd, WReg rn);
    CodeGenerator& scvtf(SReg rd, XReg rn);
    CodeGenerator& scvtf(DReg rd, XReg rn);
    CodeGenerator& ucvtf(SReg rd, WReg rn);
    CodeGenerator& ucvtf(DReg rd, WReg rn);
    CodeGenerator& ucvtf(SReg rd, XReg rn);
    CodeGenerator& ucvtf(DReg rd, XReg rn);
    CodeGenerator& fcvtzs(WReg rd, SReg rn);
    CodeGenerator& fcvtzs(WReg rd, DReg rn);
    CodeGenerator& fcvtzs(XReg rd, SReg rn);
    CodeGenerator& fcvtzs(XReg rd, DReg rn);
    CodeGenerator& fcvtzu(WReg rd, SReg rn);
    CodeGenerator& fcvtzu(WReg rd, DReg rn);
    CodeGenerator& fcvtzu(XReg rd, SReg rn);
    CodeGenerator& fcvtzu(XReg rd, DReg rn);
    CodeGenerator& fcvt(SReg rd, DReg rn);
    CodeGenerator& fcvt(DReg rd, SReg rn);
    CodeGenerator& fmov(XReg rd, DReg rn);
    CodeGenerator& fmov(DReg rd, XReg rn);
    CodeGenerator& fmov(WReg rd, SReg rn);
    CodeGenerator& fmov(SReg rd, WReg rn);
    CodeGenerator& fmax(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fmax(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fmin(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fmin(DReg rd, DReg rn, DReg rm);

    // === Scalar FP Rounding ===
    CodeGenerator& frintn(SReg rd, SReg rn);
    CodeGenerator& frintn(DReg rd, DReg rn);
    CodeGenerator& frintm(SReg rd, SReg rn);
    CodeGenerator& frintm(DReg rd, DReg rn);
    CodeGenerator& frintp(SReg rd, SReg rn);
    CodeGenerator& frintp(DReg rd, DReg rn);
    CodeGenerator& frintz(SReg rd, SReg rn);
    CodeGenerator& frintz(DReg rd, DReg rn);
    CodeGenerator& frinta(SReg rd, SReg rn);
    CodeGenerator& frinta(DReg rd, DReg rn);

    // === Scalar FP Convert (rounding modes) ===
    CodeGenerator& fcvtas(WReg rd, SReg rn);
    CodeGenerator& fcvtas(WReg rd, DReg rn);
    CodeGenerator& fcvtas(XReg rd, SReg rn);
    CodeGenerator& fcvtas(XReg rd, DReg rn);
    CodeGenerator& fcvtau(WReg rd, SReg rn);
    CodeGenerator& fcvtau(WReg rd, DReg rn);
    CodeGenerator& fcvtau(XReg rd, SReg rn);
    CodeGenerator& fcvtau(XReg rd, DReg rn);
    CodeGenerator& fcvtms(WReg rd, SReg rn);
    CodeGenerator& fcvtms(WReg rd, DReg rn);
    CodeGenerator& fcvtms(XReg rd, SReg rn);
    CodeGenerator& fcvtms(XReg rd, DReg rn);
    CodeGenerator& fcvtmu(WReg rd, SReg rn);
    CodeGenerator& fcvtmu(WReg rd, DReg rn);
    CodeGenerator& fcvtmu(XReg rd, SReg rn);
    CodeGenerator& fcvtmu(XReg rd, DReg rn);
    CodeGenerator& fcvtns(WReg rd, SReg rn);
    CodeGenerator& fcvtns(WReg rd, DReg rn);
    CodeGenerator& fcvtns(XReg rd, SReg rn);
    CodeGenerator& fcvtns(XReg rd, DReg rn);
    CodeGenerator& fcvtnu(WReg rd, SReg rn);
    CodeGenerator& fcvtnu(WReg rd, DReg rn);
    CodeGenerator& fcvtnu(XReg rd, SReg rn);
    CodeGenerator& fcvtnu(XReg rd, DReg rn);
    CodeGenerator& fcvtps(WReg rd, SReg rn);
    CodeGenerator& fcvtps(WReg rd, DReg rn);
    CodeGenerator& fcvtps(XReg rd, SReg rn);
    CodeGenerator& fcvtps(XReg rd, DReg rn);
    CodeGenerator& fcvtpu(WReg rd, SReg rn);
    CodeGenerator& fcvtpu(WReg rd, DReg rn);
    CodeGenerator& fcvtpu(XReg rd, SReg rn);
    CodeGenerator& fcvtpu(XReg rd, DReg rn);

    // === Scalar FP frint32/64 ===
    CodeGenerator& frint32z(SReg rd, SReg rn);
    CodeGenerator& frint32z(DReg rd, DReg rn);
    CodeGenerator& frint32x(SReg rd, SReg rn);
    CodeGenerator& frint32x(DReg rd, DReg rn);
    CodeGenerator& frint64z(SReg rd, SReg rn);
    CodeGenerator& frint64z(DReg rd, DReg rn);
    CodeGenerator& frint64x(SReg rd, SReg rn);
    CodeGenerator& frint64x(DReg rd, DReg rn);

    // === FP Vector ===
    CodeGenerator& fadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fsub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fmul(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fdiv(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fabs(VArr vd, VArr vn);
    CodeGenerator& fneg(VArr vd, VArr vn);

    // === Multi-Precision Arithmetic ===
    CodeGenerator& smaddl(XReg rd, WReg rn, WReg rm, XReg ra);
    CodeGenerator& smsubl(XReg rd, WReg rn, WReg rm, XReg ra);
    CodeGenerator& umaddl(XReg rd, WReg rn, WReg rm, XReg ra);
    CodeGenerator& umsubl(XReg rd, WReg rn, WReg rm, XReg ra);
    CodeGenerator& smnegl(XReg rd, WReg rn, WReg rm);
    CodeGenerator& umnegl(XReg rd, WReg rn, WReg rm);

    // === CRC ===
    CodeGenerator& crc32b(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32h(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32w(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32x(WReg rd, WReg rn, XReg rm);
    CodeGenerator& crc32cb(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32ch(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32cw(WReg rd, WReg rn, WReg rm);
    CodeGenerator& crc32cx(WReg rd, WReg rn, XReg rm);

    // === Pointer Authentication ===
    CodeGenerator& pacia(XReg rd, XReg rn);
    CodeGenerator& pacib(XReg rd, XReg rn);
    CodeGenerator& pacda(XReg rd, XReg rn);
    CodeGenerator& pacdb(XReg rd, XReg rn);
    CodeGenerator& autia(XReg rd, XReg rn);
    CodeGenerator& autib(XReg rd, XReg rn);
    CodeGenerator& autda(XReg rd, XReg rn);
    CodeGenerator& autdb(XReg rd, XReg rn);

    // === GP Extra ===
    CodeGenerator& rev16(XReg rd, XReg rn);
    CodeGenerator& rev16(WReg rd, WReg rn);
    CodeGenerator& rev32(XReg rd, XReg rn);
    CodeGenerator& eon(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& eon(WReg rd, WReg rn, WReg rm, Shift sh = {});
    CodeGenerator& bics(XReg rd, XReg rn, XReg rm, Shift sh = {});
    CodeGenerator& bics(WReg rd, WReg rn, WReg rm, Shift sh = {});

    // === Unscaled Load/Store ===
    CodeGenerator& ldur(XReg rt, Mem mem);
    CodeGenerator& ldur(WReg rt, Mem mem);
    CodeGenerator& stur(XReg rt, Mem mem);
    CodeGenerator& stur(WReg rt, Mem mem);
    CodeGenerator& ldur(SReg rt, Mem mem);
    CodeGenerator& ldur(DReg rt, Mem mem);
    CodeGenerator& ldur(QReg rt, Mem mem);
    CodeGenerator& stur(SReg rt, Mem mem);
    CodeGenerator& stur(DReg rt, Mem mem);
    CodeGenerator& stur(QReg rt, Mem mem);

    // === FP Pair Load/Store ===
    CodeGenerator& ldp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& ldp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& ldp(QReg rt1, QReg rt2, Mem mem);
    CodeGenerator& stp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& stp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& stp(QReg rt1, QReg rt2, Mem mem);

    // === SIMD Permute/Extract ===
    CodeGenerator& ext(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& trn1(VArr vd, VArr vn, VArr vm);
    CodeGenerator& trn2(VArr vd, VArr vn, VArr vm);
    CodeGenerator& zip1(VArr vd, VArr vn, VArr vm);
    CodeGenerator& zip2(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uzp1(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uzp2(VArr vd, VArr vn, VArr vm);
    CodeGenerator& tbl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& smov(XReg rd, VArr vn, uint8_t index);
    CodeGenerator& smov(WReg rd, VArr vn, uint8_t index);

    // === SIMD Arithmetic Extra ===
    CodeGenerator& smax(VArr vd, VArr vn, VArr vm);
    CodeGenerator& smin(VArr vd, VArr vn, VArr vm);
    CodeGenerator& umax(VArr vd, VArr vn, VArr vm);
    CodeGenerator& umin(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uqadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqsub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uqsub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& rev64(VArr vd, VArr vn);
    CodeGenerator& rev32(VArr vd, VArr vn);
    CodeGenerator& rev16(VArr vd, VArr vn);
    CodeGenerator& cls(VArr vd, VArr vn);
    CodeGenerator& clz(VArr vd, VArr vn);
    CodeGenerator& orn(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bsl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bit(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bif(VArr vd, VArr vn, VArr vm);

    // === SIMD Multiply-Accumulate ===
    CodeGenerator& mla(VArr vd, VArr vn, VArr vm);
    CodeGenerator& mls(VArr vd, VArr vn, VArr vm);

    // === SIMD Reductions ===
    CodeGenerator& addv(VArr vd, VArr vn);
    CodeGenerator& saddlv(VArr vd, VArr vn);
    CodeGenerator& uaddlv(VArr vd, VArr vn);

    // === SIMD Narrowing/Widening ===
    CodeGenerator& xtn(VArr vd, VArr vn);

    // === FP Vector Multiply-Accumulate ===
    CodeGenerator& fmla(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fmls(VArr vd, VArr vn, VArr vm);

    // === FP Pairwise ===
    CodeGenerator& faddp(VArr vd, VArr vn, VArr vm);

    // === FP Vector Compare ===
    CodeGenerator& fcmeq(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fcmge(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fcmgt(VArr vd, VArr vn, VArr vm);

    // === FP Vector Rounding ===
    CodeGenerator& frintn(VArr vd, VArr vn);
    CodeGenerator& frintm(VArr vd, VArr vn);
    CodeGenerator& frintp(VArr vd, VArr vn);
    CodeGenerator& frintz(VArr vd, VArr vn);
    CodeGenerator& frinta(VArr vd, VArr vn);

    // === FP Vector Estimates ===
    CodeGenerator& frecpe(VArr vd, VArr vn);
    CodeGenerator& frsqrte(VArr vd, VArr vn);

    // === SIMD Vector FP Max/Min ===
    CodeGenerator& fmax(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fmin(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fmaxnm(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fminnm(VArr vd, VArr vn, VArr vm);

    // === SIMD Vector Conversions ===
    CodeGenerator& fcvtzs(VArr vd, VArr vn);
    CodeGenerator& fcvtzu(VArr vd, VArr vn);
    CodeGenerator& scvtf(VArr vd, VArr vn);
    CodeGenerator& ucvtf(VArr vd, VArr vn);

    // === SIMD Widening Multiply ===
    CodeGenerator& smlal(VArr vd, VArr vn, VArr vm);
    CodeGenerator& smlsl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& smull(VArr vd, VArr vn, VArr vm);
    CodeGenerator& umlal(VArr vd, VArr vn, VArr vm);
    CodeGenerator& umlsl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& umull(VArr vd, VArr vn, VArr vm);

    // === SIMD Saturating Multiply High ===
    CodeGenerator& sqdmulh(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqrdmulh(VArr vd, VArr vn, VArr vm);

    // === SIMD Register Shift ===
    CodeGenerator& sshl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& ushl(VArr vd, VArr vn, VArr vm);

    // === SIMD Saturating Narrowing ===
    CodeGenerator& sqxtn(VArr vd, VArr vn);
    CodeGenerator& sqxtun(VArr vd, VArr vn);
    CodeGenerator& uqxtn(VArr vd, VArr vn);

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

    // === Unscaled Load/Store (byte/half/signed) ===
    CodeGenerator& ldurb(WReg rt, Mem mem);
    CodeGenerator& ldurh(WReg rt, Mem mem);
    CodeGenerator& ldursb(XReg rt, Mem mem);
    CodeGenerator& ldursb(WReg rt, Mem mem);
    CodeGenerator& ldursh(XReg rt, Mem mem);
    CodeGenerator& ldursh(WReg rt, Mem mem);
    CodeGenerator& ldursw(XReg rt, Mem mem);
    CodeGenerator& sturb(WReg rt, Mem mem);
    CodeGenerator& sturh(WReg rt, Mem mem);

    // === Load-Acquire / Store-Release Unscaled ===
    CodeGenerator& ldapur(XReg rt, Mem mem);
    CodeGenerator& ldapur(WReg rt, Mem mem);
    CodeGenerator& ldapurb(WReg rt, Mem mem);
    CodeGenerator& ldapurh(WReg rt, Mem mem);
    CodeGenerator& ldapursb(XReg rt, Mem mem);
    CodeGenerator& ldapursb(WReg rt, Mem mem);
    CodeGenerator& ldapursh(XReg rt, Mem mem);
    CodeGenerator& ldapursh(WReg rt, Mem mem);
    CodeGenerator& ldapursw(XReg rt, Mem mem);
    CodeGenerator& stlur(XReg rt, Mem mem);
    CodeGenerator& stlur(WReg rt, Mem mem);
    CodeGenerator& stlurb(WReg rt, Mem mem);
    CodeGenerator& stlurh(WReg rt, Mem mem);

    // === Compare-and-Swap Pair ===
    CodeGenerator& casp(XReg rs, XReg rt, XReg rn);
    CodeGenerator& casp(WReg rs, WReg rt, XReg rn);
    CodeGenerator& caspa(XReg rs, XReg rt, XReg rn);
    CodeGenerator& caspa(WReg rs, WReg rt, XReg rn);
    CodeGenerator& caspl(XReg rs, XReg rt, XReg rn);
    CodeGenerator& caspl(WReg rs, WReg rt, XReg rn);
    CodeGenerator& caspal(XReg rs, XReg rt, XReg rn);
    CodeGenerator& caspal(WReg rs, WReg rt, XReg rn);

    // === GP Min/Max (ARMv9) ===
    CodeGenerator& smax(XReg rd, XReg rn, XReg rm);
    CodeGenerator& smax(WReg rd, WReg rn, WReg rm);
    CodeGenerator& smin(XReg rd, XReg rn, XReg rm);
    CodeGenerator& smin(WReg rd, WReg rn, WReg rm);
    CodeGenerator& umax(XReg rd, XReg rn, XReg rm);
    CodeGenerator& umax(WReg rd, WReg rn, WReg rm);
    CodeGenerator& umin(XReg rd, XReg rn, XReg rm);
    CodeGenerator& umin(WReg rd, WReg rn, WReg rm);

    // === SIMD Widening Add/Sub ===
    CodeGenerator& saddl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& ssubl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uaddl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& usubl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& saddw(VArr vd, VArr vn, VArr vm);
    CodeGenerator& ssubw(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uaddw(VArr vd, VArr vn, VArr vm);
    CodeGenerator& usubw(VArr vd, VArr vn, VArr vm);

    // === SIMD Absolute Difference ===
    CodeGenerator& sabd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uabd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& saba(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uaba(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sabal(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uabal(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sabdl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uabdl(VArr vd, VArr vn, VArr vm);

    // === SIMD Polynomial Multiply ===
    CodeGenerator& pmul(VArr vd, VArr vn, VArr vm);
    CodeGenerator& pmull(VArr vd, VArr vn, VArr vm);

    // === SIMD Rounding Shift ===
    CodeGenerator& srshl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& urshl(VArr vd, VArr vn, VArr vm);

    // === SIMD Halving Arithmetic ===
    CodeGenerator& shadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& shsub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uhadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uhsub(VArr vd, VArr vn, VArr vm);
    CodeGenerator& srhadd(VArr vd, VArr vn, VArr vm);
    CodeGenerator& urhadd(VArr vd, VArr vn, VArr vm);

    // === SIMD Reductions (min/max) ===
    CodeGenerator& smaxv(VArr vd, VArr vn);
    CodeGenerator& sminv(VArr vd, VArr vn);
    CodeGenerator& umaxv(VArr vd, VArr vn);
    CodeGenerator& uminv(VArr vd, VArr vn);

    // === SIMD Float Widen/Narrow ===
    CodeGenerator& fcvtl(VArr vd, VArr vn);
    CodeGenerator& fcvtn(VArr vd, VArr vn);

    // === Hints ===
    CodeGenerator& yield_();
    CodeGenerator& wfe();
    CodeGenerator& wfi();
    CodeGenerator& sev();
    CodeGenerator& sevl();
    CodeGenerator& csdb();

    // === PSTATE ===
    CodeGenerator& cfinv();
    CodeGenerator& xaflag();
    CodeGenerator& axflag();

    // === Scalar FP Compare (Exception) ===
    CodeGenerator& fcmpe(SReg rn, SReg rm);
    CodeGenerator& fcmpe(SReg rn);
    CodeGenerator& fcmpe(DReg rn, DReg rm);
    CodeGenerator& fcmpe(DReg rn);
    CodeGenerator& fccmpe(SReg rn, SReg rm, uint8_t nzcv, Condition cc);
    CodeGenerator& fccmpe(DReg rn, DReg rm, uint8_t nzcv, Condition cc);

    // === SIMD Shift Immediate (Extra) ===
    CodeGenerator& srshr(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& urshr(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& ssra(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& usra(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& sli(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& sri(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& shrn(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& rshrn(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& sshll(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& ushll(VArr vd, VArr vn, uint8_t shift);

    // === SIMD Add/Sub High Narrow ===
    CodeGenerator& addhn(VArr vd, VArr vn, VArr vm);
    CodeGenerator& raddhn(VArr vd, VArr vn, VArr vm);
    CodeGenerator& subhn(VArr vd, VArr vn, VArr vm);
    CodeGenerator& rsubhn(VArr vd, VArr vn, VArr vm);

    // === SIMD Saturating Multiply Long ===
    CodeGenerator& sqdmull(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqdmlal(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqdmlsl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqrdmlah(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sqrdmlsh(VArr vd, VArr vn, VArr vm);

    // === SIMD FP Extended/Step ===
    CodeGenerator& fmulx(VArr vd, VArr vn, VArr vm);
    CodeGenerator& frecps(VArr vd, VArr vn, VArr vm);
    CodeGenerator& frsqrts(VArr vd, VArr vn, VArr vm);

    // === SIMD FP Absolute Compare ===
    CodeGenerator& facge(VArr vd, VArr vn, VArr vm);
    CodeGenerator& facgt(VArr vd, VArr vn, VArr vm);

    // === SIMD FP Pairwise Max/Min ===
    CodeGenerator& fmaxp(VArr vd, VArr vn, VArr vm);
    CodeGenerator& fminp(VArr vd, VArr vn, VArr vm);

    // === SIMD Saturating Shift (Register) ===
    CodeGenerator& sqshl(VArr vd, VArr vn, VArr vm);
    CodeGenerator& uqshl(VArr vd, VArr vn, VArr vm);

    // === SIMD Table Extension ===
    CodeGenerator& tbx(VArr vd, VArr vn, VArr vm);

    // === SIMD Compare (extra) ===
    CodeGenerator& cmtst(VArr vd, VArr vn, VArr vm);

    // === SIMD FP Compare vs Zero ===
    CodeGenerator& fcmeq_zero(VArr vd, VArr vn);
    CodeGenerator& fcmge_zero(VArr vd, VArr vn);
    CodeGenerator& fcmgt_zero(VArr vd, VArr vn);
    CodeGenerator& fcmle_zero(VArr vd, VArr vn);
    CodeGenerator& fcmlt_zero(VArr vd, VArr vn);

    // === SIMD DUP (element) / INS (element from element) ===
    CodeGenerator& dup(VArr vd, VArr vn, uint8_t index);       // dup from element
    CodeGenerator& ins(VArr vd, uint8_t dst_idx, VArr vn, uint8_t src_idx);  // element from element

    // === SIMD MVNI ===
    CodeGenerator& mvni(VArr vd, uint8_t imm8, uint8_t shift = 0);

    // === SIMD Vector FP Conversions (rounding modes) ===
    CodeGenerator& fcvtas(VArr vd, VArr vn);
    CodeGenerator& fcvtau(VArr vd, VArr vn);
    CodeGenerator& fcvtns(VArr vd, VArr vn);
    CodeGenerator& fcvtnu(VArr vd, VArr vn);
    CodeGenerator& fcvtps(VArr vd, VArr vn);
    CodeGenerator& fcvtpu(VArr vd, VArr vn);
    CodeGenerator& fcvtms(VArr vd, VArr vn);
    CodeGenerator& fcvtmu(VArr vd, VArr vn);

    // === Crypto (AES) ===
    CodeGenerator& aesd(VArr vd, VArr vn);
    CodeGenerator& aese(VArr vd, VArr vn);
    CodeGenerator& aesimc(VArr vd, VArr vn);
    CodeGenerator& aesmc(VArr vd, VArr vn);

    // === Crypto (SHA-1) ===
    CodeGenerator& sha1c(QReg rd, SReg rn, VArr vm);
    CodeGenerator& sha1h(SReg rd, SReg rn);
    CodeGenerator& sha1m(QReg rd, SReg rn, VArr vm);
    CodeGenerator& sha1p(QReg rd, SReg rn, VArr vm);
    CodeGenerator& sha1su0(VArr vd, VArr vn, VArr vm);
    CodeGenerator& sha1su1(VArr vd, VArr vn);

    // === Crypto (SHA-256) ===
    CodeGenerator& sha256h(QReg rd, QReg rn, VArr vm);
    CodeGenerator& sha256h2(QReg rd, QReg rn, VArr vm);
    CodeGenerator& sha256su0(VArr vd, VArr vn);
    CodeGenerator& sha256su1(VArr vd, VArr vn, VArr vm);

    // === Crypto (SHA-512) ===
    CodeGenerator& sha512h(QReg rd, QReg rn, VArr vm);
    CodeGenerator& sha512h2(QReg rd, QReg rn, VArr vm);
    CodeGenerator& sha512su0(VArr vd, VArr vn);
    CodeGenerator& sha512su1(VArr vd, VArr vn, VArr vm);

    // === Crypto (SHA3 / misc) ===
    CodeGenerator& bcax(VArr vd, VArr vn, VArr vm, VArr va);
    CodeGenerator& eor3(VArr vd, VArr vn, VArr vm, VArr va);
    CodeGenerator& rax1(VArr vd, VArr vn, VArr vm);
    CodeGenerator& xar(VArr vd, VArr vn, VArr vm, uint8_t imm6);

    // === Scalar FP Reciprocal ===
    CodeGenerator& frecpx(SReg rd, SReg rn);
    CodeGenerator& frecpx(DReg rd, DReg rn);

    // === SIMD FP Dot Product ===
    CodeGenerator& fdot(VArr vd, VArr vn, VArr vm);

    // === SIMD FP Reductions ===
    CodeGenerator& fmaxv(VArr vd, VArr vn);
    CodeGenerator& fminv(VArr vd, VArr vn);
    CodeGenerator& fmaxnmv(VArr vd, VArr vn);
    CodeGenerator& fminnmv(VArr vd, VArr vn);

    // === SIMD Vector Reverse Bits ===
    CodeGenerator& rbit(VArr vd, VArr vn);

    // === Integer Dot Product ===
    CodeGenerator& sdot(VArr vd, VArr vn, VArr vm);
    CodeGenerator& udot(VArr vd, VArr vn, VArr vm);

    // === Matrix Multiply ===
    CodeGenerator& smmla(VArr vd, VArr vn, VArr vm);
    CodeGenerator& ummla(VArr vd, VArr vn, VArr vm);
    CodeGenerator& usmmla(VArr vd, VArr vn, VArr vm);

    // === BFloat16 ===
    CodeGenerator& bfmmla(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bfdot(VArr vd, VArr vn, VArr vm);
    CodeGenerator& bfcvt(SReg rd, SReg rn);
    CodeGenerator& bfcvtn(VArr vd, VArr vn);

    // === GP<->FP Transfer (FMOV) ===
    CodeGenerator& fmov_gp(WReg rd, SReg rn);
    CodeGenerator& fmov_gp(SReg rd, WReg rn);
    CodeGenerator& fmov_gp(XReg rd, DReg rn);
    CodeGenerator& fmov_gp(DReg rd, XReg rn);

    // === GP<->FP Conversion (scalar) ===
    CodeGenerator& scvtf_gp(SReg rd, WReg rn);
    CodeGenerator& scvtf_gp(DReg rd, WReg rn);
    CodeGenerator& scvtf_gp(SReg rd, XReg rn);
    CodeGenerator& scvtf_gp(DReg rd, XReg rn);
    CodeGenerator& ucvtf_gp(SReg rd, WReg rn);
    CodeGenerator& ucvtf_gp(DReg rd, WReg rn);
    CodeGenerator& ucvtf_gp(SReg rd, XReg rn);
    CodeGenerator& ucvtf_gp(DReg rd, XReg rn);
    CodeGenerator& fcvtzs_gp(WReg rd, SReg rn);
    CodeGenerator& fcvtzs_gp(WReg rd, DReg rn);
    CodeGenerator& fcvtzs_gp(XReg rd, SReg rn);
    CodeGenerator& fcvtzs_gp(XReg rd, DReg rn);
    CodeGenerator& fcvtzu_gp(WReg rd, SReg rn);
    CodeGenerator& fcvtzu_gp(WReg rd, DReg rn);
    CodeGenerator& fcvtzu_gp(XReg rd, SReg rn);
    CodeGenerator& fcvtzu_gp(XReg rd, DReg rn);
    CodeGenerator& fjcvtzs(WReg rd, DReg rn);

    // === Crypto (SM3/SM4) ===
    CodeGenerator& sm3ss1(VArr vd, VArr vn, VArr vm, VArr va);
    CodeGenerator& sm3tt1a(VArr vd, VArr vn, VArr vm, uint8_t imm2);
    CodeGenerator& sm3tt1b(VArr vd, VArr vn, VArr vm, uint8_t imm2);
    CodeGenerator& sm3tt2a(VArr vd, VArr vn, VArr vm, uint8_t imm2);
    CodeGenerator& sm3tt2b(VArr vd, VArr vn, VArr vm, uint8_t imm2);
    CodeGenerator& sm4e(VArr vd, VArr vn);
    CodeGenerator& sm4ekey(VArr vd, VArr vn, VArr vm);

    // === SIMD Saturating Misc ===
    CodeGenerator& sqabs(VArr vd, VArr vn);
    CodeGenerator& sqneg(VArr vd, VArr vn);
    CodeGenerator& suqadd(VArr vd, VArr vn);
    CodeGenerator& usqadd(VArr vd, VArr vn);
    CodeGenerator& sqshlu(VArr vd, VArr vn, uint8_t shift);

    // === SIMD Narrowing/Widening Extras ===
    CodeGenerator& sqshrn(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& sqrshrn(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& uqshrn(VArr vd, VArr vn, uint8_t shift);
    CodeGenerator& uqrshrn(VArr vd, VArr vn, uint8_t shift);

    // === Shift Aliases (Immediate) ===
    CodeGenerator& lsl_imm(WReg rd, WReg rn, uint8_t shift);
    CodeGenerator& lsl_imm(XReg rd, XReg rn, uint8_t shift);
    CodeGenerator& lsr_imm(WReg rd, WReg rn, uint8_t shift);
    CodeGenerator& lsr_imm(XReg rd, XReg rn, uint8_t shift);
    CodeGenerator& asr_imm(WReg rd, WReg rn, uint8_t shift);
    CodeGenerator& asr_imm(XReg rd, XReg rn, uint8_t shift);
    CodeGenerator& ror_imm(WReg rd, WReg rn, uint8_t shift);
    CodeGenerator& ror_imm(XReg rd, XReg rn, uint8_t shift);

    // === MOV SP Alias ===
    CodeGenerator& mov_sp(XReg rd, XReg rn);

    // === Misc Scalar FP ===
    CodeGenerator& frintx(SReg rd, SReg rn);
    CodeGenerator& frintx(DReg rd, DReg rn);

    // === SIMD Indexed Element (FP) ===
    CodeGenerator& fmla_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& fmls_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& fmul_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& fmulx_elem(VArr vd, VArr vn, VArr vm, uint8_t index);

    // === SIMD Indexed Element (Integer) ===
    CodeGenerator& mul_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& mla_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& mls_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& sqdmulh_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& sqrdmulh_elem(VArr vd, VArr vn, VArr vm, uint8_t index);

    // === SIMD Widening Indexed Element ===
    CodeGenerator& smlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& smlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& smull_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& umlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& umlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& umull_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& sqdmlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& sqdmlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index);
    CodeGenerator& sqdmull_elem(VArr vd, VArr vn, VArr vm, uint8_t index);

    // === FP Load/Store (unsigned offset) ===
    CodeGenerator& ldr_fp(SReg rt, Mem mem);
    CodeGenerator& ldr_fp(DReg rt, Mem mem);
    CodeGenerator& ldr_fp(QReg rt, Mem mem);
    CodeGenerator& str_fp(SReg rt, Mem mem);
    CodeGenerator& str_fp(DReg rt, Mem mem);
    CodeGenerator& str_fp(QReg rt, Mem mem);

    // === FP Pair Load/Store ===
    CodeGenerator& ldp_fp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& ldp_fp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& ldp_fp(QReg rt1, QReg rt2, Mem mem);
    CodeGenerator& stp_fp(SReg rt1, SReg rt2, Mem mem);
    CodeGenerator& stp_fp(DReg rt1, DReg rt2, Mem mem);
    CodeGenerator& stp_fp(QReg rt1, QReg rt2, Mem mem);

    // === FP Unscaled Load/Store ===
    CodeGenerator& ldur_fp(SReg rt, Mem mem);
    CodeGenerator& ldur_fp(DReg rt, Mem mem);
    CodeGenerator& ldur_fp(QReg rt, Mem mem);
    CodeGenerator& stur_fp(SReg rt, Mem mem);
    CodeGenerator& stur_fp(DReg rt, Mem mem);
    CodeGenerator& stur_fp(QReg rt, Mem mem);

    // === System Instructions ===
    CodeGenerator& hvc(uint16_t imm16);
    CodeGenerator& smc(uint16_t imm16);
    CodeGenerator& dcps1(uint16_t imm16);
    CodeGenerator& dcps2(uint16_t imm16);
    CodeGenerator& dcps3(uint16_t imm16);
    CodeGenerator& hint(uint8_t imm7);
    CodeGenerator& sys(uint8_t op1, uint8_t CRn, uint8_t CRm, uint8_t op2, XReg rt);
    CodeGenerator& prfum(uint8_t prfop, Mem mem);

    // === BFloat16 Multiply-Add ===
    CodeGenerator& bfmlal(VArr vd, VArr vn, VArr vm);

    // === Complex FP ===
    CodeGenerator& fcadd(VArr vd, VArr vn, VArr vm, uint8_t rot);
    CodeGenerator& fcmla(VArr vd, VArr vn, VArr vm, uint8_t rot);

    // === PAC Extras ===
    CodeGenerator& xpacd(XReg rd);
    CodeGenerator& xpaci(XReg rd);
    CodeGenerator& xpaclri();

    // === GP Abs/Count (ARMv9) ===
    CodeGenerator& abs(XReg rd, XReg rn);
    CodeGenerator& abs(WReg rd, WReg rn);
    CodeGenerator& cnt(XReg rd, XReg rn);
    CodeGenerator& cnt(WReg rd, WReg rn);

    // === Flag Manipulation ===
    CodeGenerator& setf8(WReg rn);
    CodeGenerator& setf16(WReg rn);
    CodeGenerator& rmif(XReg rn, uint8_t imm6, uint8_t mask);

    // === FP Immediate ===
    CodeGenerator& fmov(SReg rd, uint8_t imm8);  // FP immediate
    CodeGenerator& fmov(DReg rd, uint8_t imm8);  // FP immediate

    // === Load/Store Register Offset ===
    CodeGenerator& ldr_reg(XReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldr_reg(WReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& str_reg(XReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& str_reg(WReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldrb_reg(WReg rt, XReg rn, XReg rm);
    CodeGenerator& ldrh_reg(WReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& strb_reg(WReg rt, XReg rn, XReg rm);
    CodeGenerator& strh_reg(WReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldrsb_reg(XReg rt, XReg rn, XReg rm);
    CodeGenerator& ldrsb_reg(WReg rt, XReg rn, XReg rm);
    CodeGenerator& ldrsh_reg(XReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldrsh_reg(WReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldrsw_reg(XReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldr_reg(SReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldr_reg(DReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& ldr_reg(QReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& str_reg(SReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& str_reg(DReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& str_reg(QReg rt, XReg rn, XReg rm, bool shift = false);
    CodeGenerator& prfm_reg(uint8_t prfop, XReg rn, XReg rm, bool shift = false);

    // === Scalar SIMD (D register, 64-bit) ===
    CodeGenerator& add_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& sub_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& cmeq_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& cmge_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& cmgt_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& cmhi_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& cmhs_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& abs_d(DReg rd, DReg rn);
    CodeGenerator& neg_d(DReg rd, DReg rn);

    // === Scalar SIMD Saturating ===
    CodeGenerator& sqadd_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& sqsub_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& uqadd_d(DReg rd, DReg rn, DReg rm);
    CodeGenerator& uqsub_d(DReg rd, DReg rn, DReg rm);

    // === FP Scalar Min/Max (NaN) ===
    CodeGenerator& fmaxnm(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fmaxnm(DReg rd, DReg rn, DReg rm);
    CodeGenerator& fminnm(SReg rd, SReg rn, SReg rm);
    CodeGenerator& fminnm(DReg rd, DReg rn, DReg rm);

    // === FP Vector Sqrt ===
    CodeGenerator& fsqrt(VArr vd, VArr vn);

    // === SIMD Across-Lanes FP Pairwise ===
    CodeGenerator& faddp(SReg rd, VArr vn);  // scalar pairwise add

    // === Load/Store PAC ===
    CodeGenerator& ldraa(XReg rt, XReg rn, int32_t imm = 0);
    CodeGenerator& ldrab(XReg rt, XReg rn, int32_t imm = 0);

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
