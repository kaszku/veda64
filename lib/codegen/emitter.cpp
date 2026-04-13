// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include <codegen/emitter.hpp>
#include <format/format.hpp>

// Windows ARM64 SDK defines 'mvn' as a macro (ARM intrinsic)
#ifdef mvn
#undef mvn
#endif

namespace veda64 {
namespace codegen {

using namespace veda64::format;

namespace {
// Encode a bitmask immediate for logical instructions.
// Returns true on success, filling N/immr/imms.
bool encode_logical_imm(uint64_t imm, bool is64, uint32_t& N, uint32_t& immr, uint32_t& imms) {
    if (imm == 0 || imm == ~0ULL) return false;
    if (!is64) {
        imm = (imm & 0xFFFFFFFFULL) | ((imm & 0xFFFFFFFFULL) << 32);
    }
    // Find the smallest repeating element
    unsigned size = 64;
    uint64_t mask = ~0ULL;
    for (unsigned s = 32; s >= 2; s >>= 1) {
        uint64_t lo = imm & ((1ULL << s) - 1);
        uint64_t hi = (imm >> s) & ((1ULL << s) - 1);
        if (lo == hi) { size = s; mask = (1ULL << s) - 1; }
        else break;
    }
    uint64_t pattern = imm & mask;
    // Pattern must be a rotated run of 1s
    // Rotate until pattern starts with a 0 bit
    unsigned rotation = 0;
    uint64_t normalized = pattern;
    for (unsigned i = 0; i < size; i++) {
        if ((normalized & 1) == 0) break;
        normalized = ((normalized >> 1) | ((normalized & 1) << (size - 1))) & mask;
        rotation++;
    }
    // Count the run of 1s
    unsigned ones = 0;
    // Skip leading zeros
    if (normalized == 0) return false;
    unsigned leading_zeros = 0;
    for (unsigned i = 0; i < size; i++) {
        if ((normalized >> i) & 1) { leading_zeros = i; break; }
    }
    for (unsigned i = leading_zeros; i < size; i++) {
        if ((normalized >> i) & 1) ones++;
        else break;
    }
    // Verify it's a contiguous run
    uint64_t expected = (((1ULL << ones) - 1) << leading_zeros) & mask;
    if (normalized != expected) return false;
    immr = (size - rotation - leading_zeros) % size;
    imms = ((~(size * 2 - 1)) & 0x3F) | (ones - 1);
    N = (size == 64) ? 1 : 0;
    return true;
}
} // anonymous namespace

// === Data Processing - Immediate ===
CodeGenerator& CodeGenerator::add(XReg rd, XReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_add_64_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::add(WReg rd, WReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_add_32_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::sub(XReg rd, XReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_sub_64_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::sub(WReg rd, WReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_sub_32_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::adds(XReg rd, XReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_adds_64s_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::adds(WReg rd, WReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_adds_32s_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::subs(XReg rd, XReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_subs_64s_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::subs(WReg rd, WReg rn, uint32_t imm12, bool lsl12) {
    emit(dpimm::encode_subs_32s_addsub_imm(rd.idx, rn.idx, imm12, lsl12 ? 1 : 0));
    return *this;
}

CodeGenerator& CodeGenerator::and_(XReg rd, XReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, true, N, immr, imms);
    emit(dpimm::encode_and_64_log_imm(rd.idx, rn.idx, imms, immr, N));
    return *this;
}

CodeGenerator& CodeGenerator::and_(WReg rd, WReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, false, N, immr, imms);
    emit(dpimm::encode_and_32_log_imm(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::orr(XReg rd, XReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, true, N, immr, imms);
    emit(dpimm::encode_orr_64_log_imm(rd.idx, rn.idx, imms, immr, N));
    return *this;
}

CodeGenerator& CodeGenerator::orr(WReg rd, WReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, false, N, immr, imms);
    emit(dpimm::encode_orr_32_log_imm(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::eor(XReg rd, XReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, true, N, immr, imms);
    emit(dpimm::encode_eor_64_log_imm(rd.idx, rn.idx, imms, immr, N));
    return *this;
}

CodeGenerator& CodeGenerator::eor(WReg rd, WReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, false, N, immr, imms);
    emit(dpimm::encode_eor_32_log_imm(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::ands(XReg rd, XReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, true, N, immr, imms);
    emit(dpimm::encode_ands_64s_log_imm(rd.idx, rn.idx, imms, immr, N));
    return *this;
}

CodeGenerator& CodeGenerator::ands(WReg rd, WReg rn, uint64_t imm) {
    uint32_t N, immr, imms;
    encode_logical_imm(imm, false, N, immr, imms);
    emit(dpimm::encode_ands_32s_log_imm(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::movz(XReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movz_64_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::movz(WReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movz_32_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::movn(XReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movn_64_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::movn(WReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movn_32_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::movk(XReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movk_64_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::movk(WReg rd, uint16_t imm16, uint8_t hw) {
    emit(dpimm::encode_movk_32_movewide(rd.idx, imm16, hw));
    return *this;
}

CodeGenerator& CodeGenerator::adr(XReg rd, Label& label) {
    int32_t off = label_offset(label, PatchType::Adr21);
    int32_t immhi = (off >> 2) & 0x7FFFF;
    int32_t immlo = off & 0x3;
    emit(dpimm::encode_adr_only_pcreladdr(rd.idx, immhi, immlo));
    return *this;
}

CodeGenerator& CodeGenerator::adrp(XReg rd, int64_t imm) {
    int32_t immhi = static_cast<int32_t>((imm >> 14) & 0x7FFFF);
    int32_t immlo = static_cast<int32_t>((imm >> 12) & 0x3);
    emit(dpimm::encode_adrp_only_pcreladdr(rd.idx, immhi, immlo));
    return *this;
}

// === Data Processing - Register ===
CodeGenerator& CodeGenerator::add(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_add_64_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::add(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_add_32_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::sub(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_sub_64_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::sub(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_sub_32_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::adds(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_adds_64_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::adds(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_adds_32_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::subs(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_subs_64_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::subs(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_subs_32_addsub_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::add(XReg rd, XReg rn, WReg rm, Extend ext) {
    emit(dpreg::encode_add_64_addsub_ext(rd.idx, rn.idx, ext.amount, static_cast<uint32_t>(ext.type), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sub(XReg rd, XReg rn, WReg rm, Extend ext) {
    emit(dpreg::encode_sub_64_addsub_ext(rd.idx, rn.idx, ext.amount, static_cast<uint32_t>(ext.type), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::and_(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_and_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::and_(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_and_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::orr(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_orr_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::orr(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_orr_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::eor(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_eor_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::eor(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_eor_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::orn(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_orn_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::orn(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_orn_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::bic(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_bic_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::bic(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_bic_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::ands(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_ands_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::ands(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_ands_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

CodeGenerator& CodeGenerator::lsl(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_lsl_lslv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::lsl(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_lsl_lslv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::lsr(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_lsr_lsrv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::lsr(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_lsr_lsrv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::asr(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_asr_asrv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::asr(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_asr_asrv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ror(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_ror_rorv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ror(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_ror_rorv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mul(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_mul_madd_64a_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mul(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_mul_madd_32a_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sdiv(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_sdiv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sdiv(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_sdiv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::udiv(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_udiv_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::udiv(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_udiv_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::madd(XReg rd, XReg rn, XReg rm, XReg ra) {
    emit(dpreg::encode_madd_64a_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::madd(WReg rd, WReg rn, WReg rm, WReg ra) {
    emit(dpreg::encode_madd_32a_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::msub(XReg rd, XReg rn, XReg rm, XReg ra) {
    emit(dpreg::encode_msub_64a_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::msub(WReg rd, WReg rn, WReg rm, WReg ra) {
    emit(dpreg::encode_msub_32a_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mneg(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_mneg_msub_64a_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mneg(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_mneg_msub_32a_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::smull(XReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_smull_smaddl_64wa_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::umull(XReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_umull_umaddl_64wa_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::smulh(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_smulh_64_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::umulh(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_umulh_64_dp_3src(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::adc(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_adc_64_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::adc(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_adc_32_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::adcs(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_adcs_64_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::adcs(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_adcs_32_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sbc(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_sbc_64_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sbc(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_sbc_32_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sbcs(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_sbcs_64_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sbcs(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_sbcs_32_addsub_carry(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csel(XReg rd, XReg rn, XReg rm, Condition cc) {
    emit(dpreg::encode_csel_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csel(WReg rd, WReg rn, WReg rm, Condition cc) {
    emit(dpreg::encode_csel_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csinc(XReg rd, XReg rn, XReg rm, Condition cc) {
    emit(dpreg::encode_csinc_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csinc(WReg rd, WReg rn, WReg rm, Condition cc) {
    emit(dpreg::encode_csinc_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csinv(XReg rd, XReg rn, XReg rm, Condition cc) {
    emit(dpreg::encode_csinv_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csinv(WReg rd, WReg rn, WReg rm, Condition cc) {
    emit(dpreg::encode_csinv_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csneg(XReg rd, XReg rn, XReg rm, Condition cc) {
    emit(dpreg::encode_csneg_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csneg(WReg rd, WReg rn, WReg rm, Condition cc) {
    emit(dpreg::encode_csneg_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ccmp(XReg rn, XReg rm, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmp_64_condcmp_reg(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ccmp(XReg rn, uint8_t imm5, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmp_64_condcmp_imm(nzcv, rn.idx, static_cast<uint32_t>(cc), imm5));
    return *this;
}

CodeGenerator& CodeGenerator::ccmp(WReg rn, WReg rm, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmp_32_condcmp_reg(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ccmp(WReg rn, uint8_t imm5, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmp_32_condcmp_imm(nzcv, rn.idx, static_cast<uint32_t>(cc), imm5));
    return *this;
}

CodeGenerator& CodeGenerator::ccmn(XReg rn, XReg rm, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmn_64_condcmp_reg(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ccmn(XReg rn, uint8_t imm5, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmn_64_condcmp_imm(nzcv, rn.idx, static_cast<uint32_t>(cc), imm5));
    return *this;
}

CodeGenerator& CodeGenerator::ccmn(WReg rn, WReg rm, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmn_32_condcmp_reg(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ccmn(WReg rn, uint8_t imm5, uint8_t nzcv, Condition cc) {
    emit(dpreg::encode_ccmn_32_condcmp_imm(nzcv, rn.idx, static_cast<uint32_t>(cc), imm5));
    return *this;
}

CodeGenerator& CodeGenerator::clz(XReg rd, XReg rn) {
    emit(dpreg::encode_clz_64_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::clz(WReg rd, WReg rn) {
    emit(dpreg::encode_clz_32_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cls(XReg rd, XReg rn) {
    emit(dpreg::encode_cls_64_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cls(WReg rd, WReg rn) {
    emit(dpreg::encode_cls_32_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::rbit(XReg rd, XReg rn) {
    emit(dpreg::encode_rbit_64_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::rbit(WReg rd, WReg rn) {
    emit(dpreg::encode_rbit_32_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::rev(XReg rd, XReg rn) {
    emit(dpreg::encode_rev_64_dp_1src(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::rev(WReg rd, WReg rn) {
    emit(dpreg::encode_rev_32_dp_1src(rd.idx, rn.idx));
    return *this;
}

// === Aliases ===
CodeGenerator& CodeGenerator::cmp(XReg rn, XReg rm, Shift sh) { return subs(XReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::cmp(XReg rn, uint32_t imm12, bool lsl12) { return subs(XReg{31}, rn, imm12, lsl12); }
CodeGenerator& CodeGenerator::cmp(WReg rn, WReg rm, Shift sh) { return subs(WReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::cmp(WReg rn, uint32_t imm12, bool lsl12) { return subs(WReg{31}, rn, imm12, lsl12); }
CodeGenerator& CodeGenerator::cmn(XReg rn, XReg rm, Shift sh) { return adds(XReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::cmn(XReg rn, uint32_t imm12, bool lsl12) { return adds(XReg{31}, rn, imm12, lsl12); }
CodeGenerator& CodeGenerator::cmn(WReg rn, WReg rm, Shift sh) { return adds(WReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::cmn(WReg rn, uint32_t imm12, bool lsl12) { return adds(WReg{31}, rn, imm12, lsl12); }
CodeGenerator& CodeGenerator::tst(XReg rn, XReg rm, Shift sh) { return ands(XReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::tst(WReg rn, WReg rm, Shift sh) { return ands(WReg{31}, rn, rm, sh); }
CodeGenerator& CodeGenerator::neg(XReg rd, XReg rm, Shift sh) { return sub(rd, XReg{31}, rm, sh); }
CodeGenerator& CodeGenerator::neg(WReg rd, WReg rm, Shift sh) { return sub(rd, WReg{31}, rm, sh); }
CodeGenerator& CodeGenerator::mvn(XReg rd, XReg rm, Shift sh) { return orn(rd, XReg{31}, rm, sh); }
CodeGenerator& CodeGenerator::mvn(WReg rd, WReg rm, Shift sh) { return orn(rd, WReg{31}, rm, sh); }
CodeGenerator& CodeGenerator::ngc(XReg rd, XReg rm) { return sbc(rd, XReg{31}, rm); }
CodeGenerator& CodeGenerator::ngc(WReg rd, WReg rm) { return sbc(rd, WReg{31}, rm); }

CodeGenerator& CodeGenerator::mov(XReg rd, XReg rm) {
    emit(dpimm::encode_mov_add_64_addsub_imm(rd.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mov(WReg rd, WReg rm) {
    emit(dpimm::encode_mov_add_32_addsub_imm(rd.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::mov(XReg rd, uint64_t imm) {
    if (imm == 0) { movz(rd, 0, 0); return *this; }
    // Try MOVZ/MOVN for simple cases
    bool first = true;
    for (uint8_t hw = 0; hw < 4; hw++) {
        uint16_t chunk = static_cast<uint16_t>((imm >> (hw * 16)) & 0xFFFF);
        if (chunk != 0) {
            if (first) { movz(rd, chunk, hw); first = false; }
            else { movk(rd, chunk, hw); }
        }
    }
    return *this;
}

CodeGenerator& CodeGenerator::mov(WReg rd, uint32_t imm) {
    if (imm == 0) { movz(rd, 0, 0); return *this; }
    bool first = true;
    for (uint8_t hw = 0; hw < 2; hw++) {
        uint16_t chunk = static_cast<uint16_t>((imm >> (hw * 16)) & 0xFFFF);
        if (chunk != 0) {
            if (first) { movz(rd, chunk, hw); first = false; }
            else { movk(rd, chunk, hw); }
        }
    }
    return *this;
}

CodeGenerator& CodeGenerator::cset(XReg rd, Condition cc) {
    emit(dpreg::encode_cset_csinc_64_condsel(rd.idx, static_cast<uint32_t>(cc) ^ 1));
    return *this;
}

CodeGenerator& CodeGenerator::cset(WReg rd, Condition cc) {
    emit(dpreg::encode_cset_csinc_32_condsel(rd.idx, static_cast<uint32_t>(cc) ^ 1));
    return *this;
}

CodeGenerator& CodeGenerator::cinc(XReg rd, XReg rn, Condition cc) {
    emit(dpreg::encode_csinc_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cinc(WReg rd, WReg rn, Condition cc) {
    emit(dpreg::encode_csinc_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cinv(XReg rd, XReg rn, Condition cc) {
    emit(dpreg::encode_csinv_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cinv(WReg rd, WReg rn, Condition cc) {
    emit(dpreg::encode_csinv_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cneg(XReg rd, XReg rn, Condition cc) {
    emit(dpreg::encode_csneg_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cneg(WReg rd, WReg rn, Condition cc) {
    emit(dpreg::encode_csneg_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc) ^ 1, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::tst(XReg rn, uint64_t imm) {
    return ands(XReg{31}, rn, imm);
}

CodeGenerator& CodeGenerator::tst(WReg rn, uint64_t imm) {
    return ands(WReg{31}, rn, imm);
}

CodeGenerator& CodeGenerator::lsl(XReg rd, XReg rn, uint8_t imm) {
    uint8_t immr = (-imm) & 63;
    uint8_t imms = 63 - imm;
    emit(dpimm::encode_ubfm_64m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::lsl(WReg rd, WReg rn, uint8_t imm) {
    uint8_t immr = (-imm) & 31;
    uint8_t imms = 31 - imm;
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}

CodeGenerator& CodeGenerator::lsr(XReg rd, XReg rn, uint8_t imm) {
    emit(dpimm::encode_ubfm_64m_bitfield(rd.idx, rn.idx, 63, imm));
    return *this;
}

CodeGenerator& CodeGenerator::lsr(WReg rd, WReg rn, uint8_t imm) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, 31, imm));
    return *this;
}

CodeGenerator& CodeGenerator::asr(XReg rd, XReg rn, uint8_t imm) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, 63, imm));
    return *this;
}

CodeGenerator& CodeGenerator::asr(WReg rd, WReg rn, uint8_t imm) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, 31, imm));
    return *this;
}

CodeGenerator& CodeGenerator::ror(XReg rd, XReg rn, uint8_t imm) {
    emit(dpimm::encode_extr_64_extract(rd.idx, rn.idx, imm, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ror(WReg rd, WReg rn, uint8_t imm) {
    emit(dpimm::encode_extr_32_extract(rd.idx, rn.idx, imm, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::bfi(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_bfm_64m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 63));
    return *this;
}

CodeGenerator& CodeGenerator::bfi(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_bfm_32m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 31));
    return *this;
}

CodeGenerator& CodeGenerator::bfxil(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_bfm_64m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::bfxil(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_bfm_32m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::sbfx(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::sbfx(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::ubfx(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_ubfm_64m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::ubfx(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, lsb + width - 1, lsb));
    return *this;
}

CodeGenerator& CodeGenerator::sbfiz(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 63));
    return *this;
}

CodeGenerator& CodeGenerator::sbfiz(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 31));
    return *this;
}

CodeGenerator& CodeGenerator::ubfiz(XReg rd, XReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_ubfm_64m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 63));
    return *this;
}

CodeGenerator& CodeGenerator::ubfiz(WReg rd, WReg rn, uint8_t lsb, uint8_t width) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, width - 1, (-lsb) & 31));
    return *this;
}

CodeGenerator& CodeGenerator::extr(XReg rd, XReg rn, XReg rm, uint8_t lsb) {
    emit(dpimm::encode_extr_64_extract(rd.idx, rn.idx, lsb, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::extr(WReg rd, WReg rn, WReg rm, uint8_t lsb) {
    emit(dpimm::encode_extr_32_extract(rd.idx, rn.idx, lsb, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::sxtb(XReg rd, WReg rn) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, 7, 0));
    return *this;
}

CodeGenerator& CodeGenerator::sxtb(WReg rd, WReg rn) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, 7, 0));
    return *this;
}

CodeGenerator& CodeGenerator::sxth(XReg rd, WReg rn) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, 15, 0));
    return *this;
}

CodeGenerator& CodeGenerator::sxth(WReg rd, WReg rn) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, 15, 0));
    return *this;
}

CodeGenerator& CodeGenerator::sxtw(XReg rd, WReg rn) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, 31, 0));
    return *this;
}

CodeGenerator& CodeGenerator::uxtb(WReg rd, WReg rn) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, 7, 0));
    return *this;
}

CodeGenerator& CodeGenerator::uxth(WReg rd, WReg rn) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, 15, 0));
    return *this;
}

// === Branches ===
CodeGenerator& CodeGenerator::b(Label& label) {
    int32_t off = label_offset(label, PatchType::Imm26);
    emit(control::encode_b_only_branch_imm(off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::b(Condition cc, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(control::encode_b_only_condbranch(static_cast<uint32_t>(cc), off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::bl(Label& label) {
    int32_t off = label_offset(label, PatchType::Imm26);
    emit(control::encode_bl_only_branch_imm(off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::br(XReg rn) { emit(control::encode_br_64_branch_reg(rn.idx)); return *this; }
CodeGenerator& CodeGenerator::blr(XReg rn) { emit(control::encode_blr_64_branch_reg(rn.idx)); return *this; }
CodeGenerator& CodeGenerator::ret(XReg rn) { emit(control::encode_ret_64r_branch_reg(rn.idx)); return *this; }

CodeGenerator& CodeGenerator::cbz(XReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(control::encode_cbz_64_compbranch(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::cbz(WReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(control::encode_cbz_32_compbranch(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::cbnz(XReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(control::encode_cbnz_64_compbranch(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::cbnz(WReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(control::encode_cbnz_32_compbranch(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::tbz(XReg rt, uint8_t bit, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm14);
    emit(control::encode_tbz_only_testbranch(rt.idx, off >> 2, bit & 0x1F, (bit >> 5) & 1));
    return *this;
}

CodeGenerator& CodeGenerator::tbz(WReg rt, uint8_t bit, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm14);
    emit(control::encode_tbz_only_testbranch(rt.idx, off >> 2, bit & 0x1F, (bit >> 5) & 1));
    return *this;
}

CodeGenerator& CodeGenerator::tbnz(XReg rt, uint8_t bit, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm14);
    emit(control::encode_tbnz_only_testbranch(rt.idx, off >> 2, bit & 0x1F, (bit >> 5) & 1));
    return *this;
}

CodeGenerator& CodeGenerator::tbnz(WReg rt, uint8_t bit, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm14);
    emit(control::encode_tbnz_only_testbranch(rt.idx, off >> 2, bit & 0x1F, (bit >> 5) & 1));
    return *this;
}

CodeGenerator& CodeGenerator::svc(uint16_t imm) { emit(control::encode_svc_ex_exception(imm)); return *this; }
CodeGenerator& CodeGenerator::brk(uint16_t imm) { emit(control::encode_brk_ex_exception(imm)); return *this; }
CodeGenerator& CodeGenerator::nop() { emit(control::encode_nop_hi_hints()); return *this; }

// === System and Barriers ===
CodeGenerator& CodeGenerator::hlt(uint16_t imm) {
    emit(control::encode_hlt_ex_exception(imm));
    return *this;
}
CodeGenerator& CodeGenerator::eret() {
    emit(control::encode_eret_64e_branch_reg());
    return *this;
}
CodeGenerator& CodeGenerator::dmb(uint8_t option) {
    emit(control::encode_dmb_bo_barriers(option));
    return *this;
}
CodeGenerator& CodeGenerator::dsb(uint8_t option) {
    emit(control::encode_dsb_bo_barriers(option));
    return *this;
}
CodeGenerator& CodeGenerator::isb() {
    emit(control::encode_isb_bi_barriers(15));
    return *this;
}
CodeGenerator& CodeGenerator::clrex() {
    emit(control::encode_clrex_bn_barriers(15));
    return *this;
}
CodeGenerator& CodeGenerator::mrs(XReg rt, uint32_t o0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2) {
    emit(control::encode_mrs_rs_systemmove(rt.idx, op2, CRm, CRn, op1, o0));
    return *this;
}
CodeGenerator& CodeGenerator::msr(uint32_t o0, uint32_t op1, uint32_t CRn, uint32_t CRm, uint32_t op2, XReg rt) {
    emit(control::encode_msr_sr_systemmove(rt.idx, op2, CRm, CRn, op1, o0));
    return *this;
}

// === Loads and Stores ===
CodeGenerator& CodeGenerator::ldr(XReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_64_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_64_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_64_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::RegOffset:
        emit(ldst::encode_ldr_64_ldst_regoff(rt.idx, mem.base_idx, mem.shift_amount ? 1 : 0, mem.extend_type, mem.index_idx));
        break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldr(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::RegOffset:
        emit(ldst::encode_ldr_32_ldst_regoff(rt.idx, mem.base_idx, mem.shift_amount ? 1 : 0, mem.extend_type, mem.index_idx));
        break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::str(XReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_64_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_64_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_64_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::RegOffset:
        emit(ldst::encode_str_64_ldst_regoff(rt.idx, mem.base_idx, mem.shift_amount ? 1 : 0, mem.extend_type, mem.index_idx));
        break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::str(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::RegOffset:
        emit(ldst::encode_str_32_ldst_regoff(rt.idx, mem.base_idx, mem.shift_amount ? 1 : 0, mem.extend_type, mem.index_idx));
        break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldr(SReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_s_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_s_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_s_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldr(DReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_d_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_d_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_d_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldr(QReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_q_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 4));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_q_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_q_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::str(SReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_s_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_s_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_s_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::str(DReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_d_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_d_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_d_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::str(QReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_q_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 4));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_q_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_q_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrb(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrb_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrb_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrb_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrh(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrh_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 1));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrh_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrh_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::strb(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_strb_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_strb_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_strb_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::strh(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_strh_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 1));
        break;
    case MemMode::Pre:
        emit(ldst::encode_strh_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_strh_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrsb(XReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrsb_64_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrsb_64_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrsb_64_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrsb(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrsb_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrsb_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrsb_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrsh(XReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrsh_64_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 1));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrsh_64_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrsh_64_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrsh(WReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrsh_32_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 1));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrsh_32_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrsh_32_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldrsw(XReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldrsw_64_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldrsw_64_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldrsw_64_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldr(XReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(ldst::encode_ldr_64_loadlit(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::ldr(WReg rt, Label& label) {
    int32_t off = label_offset(label, PatchType::Imm19);
    emit(ldst::encode_ldr_32_loadlit(rt.idx, off >> 2));
    return *this;
}

CodeGenerator& CodeGenerator::ldp(XReg rt1, XReg rt2, Mem mem) {
    int32_t imm7 = mem.offset >> 3;
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldp_64_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldp_64_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldp_64_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::ldp(WReg rt1, WReg rt2, Mem mem) {
    int32_t imm7 = mem.offset >> 2;
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldp_32_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldp_32_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldp_32_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::stp(XReg rt1, XReg rt2, Mem mem) {
    int32_t imm7 = mem.offset >> 3;
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_stp_64_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_stp_64_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Post:
        emit(ldst::encode_stp_64_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    default: break;
    }
    return *this;
}

CodeGenerator& CodeGenerator::stp(WReg rt1, WReg rt2, Mem mem) {
    int32_t imm7 = mem.offset >> 2;
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_stp_32_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_stp_32_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Post:
        emit(ldst::encode_stp_32_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    default: break;
    }
    return *this;
}

// === Atomics and Exclusives ===
CodeGenerator& CodeGenerator::ldar(XReg rt, XReg rn) {
    emit(ldst::encode_ldar_lr64_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldar(WReg rt, XReg rn) {
    emit(ldst::encode_ldar_lr32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlr(XReg rt, XReg rn) {
    emit(ldst::encode_stlr_sl64_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlr(WReg rt, XReg rn) {
    emit(ldst::encode_stlr_sl32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldarb(WReg rt, XReg rn) {
    emit(ldst::encode_ldarb_lr32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldarh(WReg rt, XReg rn) {
    emit(ldst::encode_ldarh_lr32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlrb(WReg rt, XReg rn) {
    emit(ldst::encode_stlrb_sl32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlrh(WReg rt, XReg rn) {
    emit(ldst::encode_stlrh_sl32_ldstord(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldxr(XReg rt, XReg rn) {
    emit(ldst::encode_ldxr_lr64_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldxr(WReg rt, XReg rn) {
    emit(ldst::encode_ldxr_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaxr(XReg rt, XReg rn) {
    emit(ldst::encode_ldaxr_lr64_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaxr(WReg rt, XReg rn) {
    emit(ldst::encode_ldaxr_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldxrb(WReg rt, XReg rn) {
    emit(ldst::encode_ldxrb_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldxrh(WReg rt, XReg rn) {
    emit(ldst::encode_ldxrh_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaxrb(WReg rt, XReg rn) {
    emit(ldst::encode_ldaxrb_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaxrh(WReg rt, XReg rn) {
    emit(ldst::encode_ldaxrh_lr32_ldstexclr(rt.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stxr(WReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_stxr_sr64_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stxr(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stxr_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlxr(WReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_stlxr_sr64_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlxr(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stlxr_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stxrb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stxrb_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stxrh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stxrh_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlxrb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stlxrb_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stlxrh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_stlxrh_sr32_ldstexclr(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cas(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_cas_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cas(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_cas_c64_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casa(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casa_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casa(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_casa_c64_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casl_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_casl_c64_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casal_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_casal_c64_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casb_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::cash(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_cash_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casab_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casah_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::caslb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_caslb_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::caslh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_caslh_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casalb_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::casalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casalh_c32_comswap(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swp(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swp_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swp(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_swp_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpa(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpa_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpa(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_swpa_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_swpl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_swpal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swph(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swph_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swplb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swplb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swplh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swplh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::swpalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_swpalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldadd(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldadd_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldadd(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldadd_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldadda(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldadda_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldadda(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldadda_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldaddl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldaddal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldaddalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldaddalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclr(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclr_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclr(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldclr_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclra(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclra_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclra(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldclra_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldclrl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclral(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclral_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclral(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldclral_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclrlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclrlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclralb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclralb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldclralh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldclralh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldset(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldset_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldset(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldset_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldseta(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldseta_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldseta(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldseta_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsetl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsetal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldseth(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldseth_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldsetalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsetalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeor(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeor_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeor(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldeor_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeora(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeora_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeora(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldeora_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldeorl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeoral(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeoral_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeoral(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldeoral_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeorlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeorlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeoralb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeoralb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::ldeoralh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldeoralh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stadd(WReg rs, XReg rn) {
    emit(ldst::encode_ldadd_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stadd(XReg rs, XReg rn) {
    emit(ldst::encode_ldadd_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::staddl(WReg rs, XReg rn) {
    emit(ldst::encode_ldaddl_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::staddl(XReg rs, XReg rn) {
    emit(ldst::encode_ldaddl_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stclr(WReg rs, XReg rn) {
    emit(ldst::encode_ldclr_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stclr(XReg rs, XReg rn) {
    emit(ldst::encode_ldclr_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stclrl(WReg rs, XReg rn) {
    emit(ldst::encode_ldclrl_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stclrl(XReg rs, XReg rn) {
    emit(ldst::encode_ldclrl_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stset(WReg rs, XReg rn) {
    emit(ldst::encode_ldset_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stset(XReg rs, XReg rn) {
    emit(ldst::encode_ldset_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stsetl(WReg rs, XReg rn) {
    emit(ldst::encode_ldsetl_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::stsetl(XReg rs, XReg rn) {
    emit(ldst::encode_ldsetl_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::steor(WReg rs, XReg rn) {
    emit(ldst::encode_ldeor_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::steor(XReg rs, XReg rn) {
    emit(ldst::encode_ldeor_64_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::steorl(WReg rs, XReg rn) {
    emit(ldst::encode_ldeorl_32_memop(31, rn.idx, rs.idx));
    return *this;
}

CodeGenerator& CodeGenerator::steorl(XReg rs, XReg rn) {
    emit(ldst::encode_ldeorl_64_memop(31, rn.idx, rs.idx));
    return *this;
}

// === Atomic Min/Max ===
CodeGenerator& CodeGenerator::ldsmax(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmax_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmax(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmax_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxa(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxa_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxa(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxa_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmaxalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmaxalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmin(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmin_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmin(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmin_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmina(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsmina_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsmina(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsmina_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsminl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldsminal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldsminalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldsminalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumax(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumax_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumax(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumax_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxa(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumaxa_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxa(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxa_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumaxl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumaxal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumaxalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumaxalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumin(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumin_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumin(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumin_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumina(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_ldumina_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldumina(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_ldumina_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_lduminl_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminl_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_lduminal_64_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminal_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminab(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminab_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminah(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminah_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminlb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminlb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminlh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminlh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminalb(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminalb_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::lduminalh(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_lduminalh_32_memop(rt.idx, rn.idx, rs.idx));
    return *this;
}

// === Store Atomic Min/Max ===
CodeGenerator& CodeGenerator::stsmax(XReg rs, XReg rn) {
    emit(ldst::encode_stsmax_ldsmax_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmax(WReg rs, XReg rn) {
    emit(ldst::encode_stsmax_ldsmax_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxl(XReg rs, XReg rn) {
    emit(ldst::encode_stsmaxl_ldsmaxl_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxl(WReg rs, XReg rn) {
    emit(ldst::encode_stsmaxl_ldsmaxl_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxb(WReg rs, XReg rn) {
    emit(ldst::encode_stsmaxb_ldsmaxb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxlb(WReg rs, XReg rn) {
    emit(ldst::encode_stsmaxlb_ldsmaxlb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxh(WReg rs, XReg rn) {
    emit(ldst::encode_stsmaxh_ldsmaxh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmaxlh(WReg rs, XReg rn) {
    emit(ldst::encode_stsmaxlh_ldsmaxlh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmin(XReg rs, XReg rn) {
    emit(ldst::encode_stsmin_ldsmin_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsmin(WReg rs, XReg rn) {
    emit(ldst::encode_stsmin_ldsmin_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminl(XReg rs, XReg rn) {
    emit(ldst::encode_stsminl_ldsminl_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminl(WReg rs, XReg rn) {
    emit(ldst::encode_stsminl_ldsminl_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminb(WReg rs, XReg rn) {
    emit(ldst::encode_stsminb_ldsminb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminlb(WReg rs, XReg rn) {
    emit(ldst::encode_stsminlb_ldsminlb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminh(WReg rs, XReg rn) {
    emit(ldst::encode_stsminh_ldsminh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stsminlh(WReg rs, XReg rn) {
    emit(ldst::encode_stsminlh_ldsminlh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumax(XReg rs, XReg rn) {
    emit(ldst::encode_stumax_ldumax_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumax(WReg rs, XReg rn) {
    emit(ldst::encode_stumax_ldumax_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxl(XReg rs, XReg rn) {
    emit(ldst::encode_stumaxl_ldumaxl_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxl(WReg rs, XReg rn) {
    emit(ldst::encode_stumaxl_ldumaxl_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxb(WReg rs, XReg rn) {
    emit(ldst::encode_stumaxb_ldumaxb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxlb(WReg rs, XReg rn) {
    emit(ldst::encode_stumaxlb_ldumaxlb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxh(WReg rs, XReg rn) {
    emit(ldst::encode_stumaxh_ldumaxh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumaxlh(WReg rs, XReg rn) {
    emit(ldst::encode_stumaxlh_ldumaxlh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumin(XReg rs, XReg rn) {
    emit(ldst::encode_stumin_ldumin_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stumin(WReg rs, XReg rn) {
    emit(ldst::encode_stumin_ldumin_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminl(XReg rs, XReg rn) {
    emit(ldst::encode_stuminl_lduminl_64_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminl(WReg rs, XReg rn) {
    emit(ldst::encode_stuminl_lduminl_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminb(WReg rs, XReg rn) {
    emit(ldst::encode_stuminb_lduminb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminlb(WReg rs, XReg rn) {
    emit(ldst::encode_stuminlb_lduminlb_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminh(WReg rs, XReg rn) {
    emit(ldst::encode_stuminh_lduminh_32_memop(rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stuminlh(WReg rs, XReg rn) {
    emit(ldst::encode_stuminlh_lduminlh_32_memop(rn.idx, rs.idx));
    return *this;
}

// === Load-Acquire RCpc ===
CodeGenerator& CodeGenerator::ldapr(XReg rt, XReg rn) {
    emit(ldst::encode_ldapr_64l_memop(rt.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldapr(WReg rt, XReg rn) {
    emit(ldst::encode_ldapr_32l_memop(rt.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldaprb(WReg rt, XReg rn) {
    emit(ldst::encode_ldaprb_32l_memop(rt.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldaprh(WReg rt, XReg rn) {
    emit(ldst::encode_ldaprh_32l_memop(rt.idx, rn.idx));
    return *this;
}

// === Prefetch ===
CodeGenerator& CodeGenerator::prfm(uint8_t op, Mem mem) {
    emit(ldst::encode_prfm_p_ldst_pos(op, mem.base_idx, (uint32_t)(mem.offset >> 3)));
    return *this;
}

// === Exclusive Pairs ===
CodeGenerator& CodeGenerator::ldxp(XReg rt1, XReg rt2, XReg rn) {
    emit(ldst::encode_ldxp_lp64_ldstexclp(rt1.idx, rn.idx, rt2.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldxp(WReg rt1, WReg rt2, XReg rn) {
    emit(ldst::encode_ldxp_lp32_ldstexclp(rt1.idx, rn.idx, rt2.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stxp(WReg rs, XReg rt1, XReg rt2, XReg rn) {
    emit(ldst::encode_stxp_sp64_ldstexclp(rt1.idx, rn.idx, rt2.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stxp(WReg rs, WReg rt1, WReg rt2, XReg rn) {
    emit(ldst::encode_stxp_sp32_ldstexclp(rt1.idx, rn.idx, rt2.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldaxp(XReg rt1, XReg rt2, XReg rn) {
    emit(ldst::encode_ldaxp_lp64_ldstexclp(rt1.idx, rn.idx, rt2.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldaxp(WReg rt1, WReg rt2, XReg rn) {
    emit(ldst::encode_ldaxp_lp32_ldstexclp(rt1.idx, rn.idx, rt2.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stlxp(WReg rs, XReg rt1, XReg rt2, XReg rn) {
    emit(ldst::encode_stlxp_sp64_ldstexclp(rt1.idx, rn.idx, rt2.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::stlxp(WReg rs, WReg rt1, WReg rt2, XReg rn) {
    emit(ldst::encode_stlxp_sp32_ldstexclp(rt1.idx, rn.idx, rt2.idx, rs.idx));
    return *this;
}

// === Non-Temporal Pairs ===
CodeGenerator& CodeGenerator::ldnp(XReg rt1, XReg rt2, Mem mem) {
    emit(ldst::encode_ldnp_64_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldnp(WReg rt1, WReg rt2, Mem mem) {
    emit(ldst::encode_ldnp_32_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stnp(XReg rt1, XReg rt2, Mem mem) {
    emit(ldst::encode_stnp_64_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stnp(WReg rt1, WReg rt2, Mem mem) {
    emit(ldst::encode_stnp_32_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldnp(SReg rt1, SReg rt2, Mem mem) {
    emit(ldst::encode_ldnp_s_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldnp(DReg rt1, DReg rt2, Mem mem) {
    emit(ldst::encode_ldnp_d_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldnp(QReg rt1, QReg rt2, Mem mem) {
    emit(ldst::encode_ldnp_q_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 4) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stnp(SReg rt1, SReg rt2, Mem mem) {
    emit(ldst::encode_stnp_s_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stnp(DReg rt1, DReg rt2, Mem mem) {
    emit(ldst::encode_stnp_d_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stnp(QReg rt1, QReg rt2, Mem mem) {
    emit(ldst::encode_stnp_q_ldstnapair_offs(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)((int32_t)mem.offset >> 4) & 0x7F));
    return *this;
}

// === Signed Load Pair ===
CodeGenerator& CodeGenerator::ldpsw(XReg rt1, XReg rt2, Mem mem) {
    int32_t imm7 = mem.offset >> 2;
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldpsw_64_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldpsw_64_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldpsw_64_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, static_cast<uint32_t>(imm7)));
        break;
    default: break;
    }
    return *this;
}

// === Scalar FP ===
CodeGenerator& CodeGenerator::fadd(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fadd_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fadd(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fadd_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fsub(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fsub_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fsub(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fsub_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fmul(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fmul_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fmul(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fmul_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fdiv(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fdiv_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fdiv(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fdiv_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fmov(SReg rd, SReg rn) {
    emit(simd_dp::encode_fmov_s_floatdp1(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fmov(DReg rd, DReg rn) {
    emit(simd_dp::encode_fmov_d_floatdp1(rd.idx, rn.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fcmp(SReg rn, SReg rm) {
    emit(simd_dp::encode_fcmp_s_floatcmp(rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fcmp(SReg rn) {
    emit(simd_dp::encode_fcmp_sz_floatcmp(rn.idx, 0));
    return *this;
}

CodeGenerator& CodeGenerator::fcmp(DReg rn, DReg rm) {
    emit(simd_dp::encode_fcmp_d_floatcmp(rn.idx, rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::fcmp(DReg rn) {
    emit(simd_dp::encode_fcmp_dz_floatcmp(rn.idx, 0));
    return *this;
}

// === Advanced SIMD (Vector) ===

CodeGenerator& CodeGenerator::add(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_add_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::sub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::mul(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_mul_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::and_(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_and_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::orr(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_orr_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::eor(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_eor_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::bic(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bic_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::not_(VArr vd, VArr vn) {
    emit(simd_dp::encode_not_asimdmisc_r(vd.idx, vn.idx, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::mvn(VArr vd, VArr vn) {
    return not_(vd, vn);
}

CodeGenerator& CodeGenerator::addp(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_addp_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::abs(VArr vd, VArr vn) {
    emit(simd_dp::encode_abs_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::neg(VArr vd, VArr vn) {
    emit(simd_dp::encode_neg_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cnt(VArr vd, VArr vn) {
    emit(simd_dp::encode_cnt_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmeq(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmeq_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmge(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmge_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmgt(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmgt_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmhi(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmhi_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmhs(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmhs_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmeq_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_cmeq_asimdmisc_z(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmge_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_cmge_asimdmisc_z(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmgt_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_cmgt_asimdmisc_z(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmle_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_cmle_asimdmisc_z(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::cmlt_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_cmlt_asimdmisc_z(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

// Helper: compute immh and immb for shift-by-immediate
static void compute_shift_immhb(uint32_t size, uint8_t shift, bool right,
                                uint32_t& immh, uint32_t& immb) {
    uint32_t esize = 8u << size;  // 8, 16, 32, 64
    uint32_t val = right ? (esize * 2 - shift) : (esize + shift);
    immh = val >> 3;
    immb = val & 7;
}

CodeGenerator& CodeGenerator::shl(VArr vd, VArr vn, uint8_t shift) {
    uint32_t immh, immb;
    compute_shift_immhb(vd.size(), shift, false, immh, immb);
    emit(simd_dp::encode_shl_asimdshf_r(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::sshr(VArr vd, VArr vn, uint8_t shift) {
    uint32_t immh, immb;
    compute_shift_immhb(vd.size(), shift, true, immh, immb);
    emit(simd_dp::encode_sshr_asimdshf_r(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::ushr(VArr vd, VArr vn, uint8_t shift) {
    uint32_t immh, immb;
    compute_shift_immhb(vd.size(), shift, true, immh, immb);
    emit(simd_dp::encode_ushr_asimdshf_r(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::dup(VArr vd, XReg rn) {
    uint32_t imm5 = 1u << vd.size();  // element size selector
    emit(simd_dp::encode_dup_asimdins_dr_r(vd.idx, rn.idx, imm5, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::dup(VArr vd, WReg rn) {
    uint32_t imm5 = 1u << vd.size();
    emit(simd_dp::encode_dup_asimdins_dr_r(vd.idx, rn.idx, imm5, vd.Q()));
    return *this;
}

CodeGenerator& CodeGenerator::ins(VArr vd, uint8_t index, XReg rn) {
    uint32_t imm5 = (index << (vd.size() + 1)) | (1u << vd.size());
    emit(simd_dp::encode_ins_asimdins_ir_r(vd.idx, rn.idx, imm5));
    return *this;
}

CodeGenerator& CodeGenerator::ins(VArr vd, uint8_t index, WReg rn) {
    uint32_t imm5 = (index << (vd.size() + 1)) | (1u << vd.size());
    emit(simd_dp::encode_ins_asimdins_ir_r(vd.idx, rn.idx, imm5));
    return *this;
}

CodeGenerator& CodeGenerator::umov(XReg rd, VArr vn, uint8_t index) {
    uint32_t imm5 = (index << (vn.size() + 1)) | (1u << vn.size());
    emit(simd_dp::encode_umov_asimdins_x_x(rd.idx, vn.idx, imm5));
    return *this;
}

CodeGenerator& CodeGenerator::umov(WReg rd, VArr vn, uint8_t index) {
    uint32_t imm5 = (index << (vn.size() + 1)) | (1u << vn.size());
    emit(simd_dp::encode_umov_asimdins_w_w(rd.idx, vn.idx, imm5));
    return *this;
}

CodeGenerator& CodeGenerator::movi(VArr vd, uint8_t imm8) {
    uint32_t a = (imm8 >> 7) & 1, b = (imm8 >> 6) & 1;
    uint32_t c = (imm8 >> 5) & 1, d = (imm8 >> 4) & 1;
    uint32_t e = (imm8 >> 3) & 1, f = (imm8 >> 2) & 1;
    uint32_t g = (imm8 >> 1) & 1, h = imm8 & 1;
    emit(simd_dp::encode_movi_asimdimm_n_b(vd.idx, h, g, f, e, d, c, b, a, vd.Q()));
    return *this;
}

// === Scalar FP Extra ===
CodeGenerator& CodeGenerator::fabs(SReg rd, SReg rn) {
    emit(simd_dp::encode_fabs_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fabs(DReg rd, DReg rn) {
    emit(simd_dp::encode_fabs_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fneg(SReg rd, SReg rn) {
    emit(simd_dp::encode_fneg_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fneg(DReg rd, DReg rn) {
    emit(simd_dp::encode_fneg_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fsqrt(SReg rd, SReg rn) {
    emit(simd_dp::encode_fsqrt_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fsqrt(DReg rd, DReg rn) {
    emit(simd_dp::encode_fsqrt_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmadd(SReg rd, SReg rn, SReg rm, SReg ra) {
    emit(simd_dp::encode_fmadd_s_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmadd(DReg rd, DReg rn, DReg rm, DReg ra) {
    emit(simd_dp::encode_fmadd_d_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmsub(SReg rd, SReg rn, SReg rm, SReg ra) {
    emit(simd_dp::encode_fmsub_s_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmsub(DReg rd, DReg rn, DReg rm, DReg ra) {
    emit(simd_dp::encode_fmsub_d_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fnmadd(SReg rd, SReg rn, SReg rm, SReg ra) {
    emit(simd_dp::encode_fnmadd_s_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fnmadd(DReg rd, DReg rn, DReg rm, DReg ra) {
    emit(simd_dp::encode_fnmadd_d_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fnmsub(SReg rd, SReg rn, SReg rm, SReg ra) {
    emit(simd_dp::encode_fnmsub_s_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fnmsub(DReg rd, DReg rn, DReg rm, DReg ra) {
    emit(simd_dp::encode_fnmsub_d_floatdp3(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcsel(SReg rd, SReg rn, SReg rm, Condition cc) {
    emit(simd_dp::encode_fcsel_s_floatsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcsel(DReg rd, DReg rn, DReg rm, Condition cc) {
    emit(simd_dp::encode_fcsel_d_floatsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fccmp(SReg rn, SReg rm, uint8_t nzcv, Condition cc) {
    emit(simd_dp::encode_fccmp_s_floatccmp(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fccmp(DReg rn, DReg rm, uint8_t nzcv, Condition cc) {
    emit(simd_dp::encode_fccmp_d_floatccmp(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf(SReg rd, WReg rn) {
    emit(simd_dp::encode_scvtf_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf(DReg rd, WReg rn) {
    emit(simd_dp::encode_scvtf_d32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf(SReg rd, XReg rn) {
    emit(simd_dp::encode_scvtf_s64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf(DReg rd, XReg rn) {
    emit(simd_dp::encode_scvtf_d64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf(SReg rd, WReg rn) {
    emit(simd_dp::encode_ucvtf_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf(DReg rd, WReg rn) {
    emit(simd_dp::encode_ucvtf_d32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf(SReg rd, XReg rn) {
    emit(simd_dp::encode_ucvtf_s64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf(DReg rd, XReg rn) {
    emit(simd_dp::encode_ucvtf_d64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzs_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzs_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzs_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzs_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzu_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzu_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzu_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzu_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvt(SReg rd, DReg rn) {
    emit(simd_dp::encode_fcvt_sd_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvt(DReg rd, SReg rn) {
    emit(simd_dp::encode_fcvt_ds_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov(XReg rd, DReg rn) {
    emit(simd_dp::encode_fmov_d64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov(DReg rd, XReg rn) {
    emit(simd_dp::encode_fmov_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov(WReg rd, SReg rn) {
    emit(simd_dp::encode_fmov_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov(SReg rd, WReg rn) {
    emit(simd_dp::encode_fmov_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmax(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fmax_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmax(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fmax_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmin(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fmin_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmin(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fmin_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

// === Scalar FP Rounding ===
CodeGenerator& CodeGenerator::frintn(SReg rd, SReg rn) {
    emit(simd_dp::encode_frintn_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintn(DReg rd, DReg rn) {
    emit(simd_dp::encode_frintn_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintm(SReg rd, SReg rn) {
    emit(simd_dp::encode_frintm_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintm(DReg rd, DReg rn) {
    emit(simd_dp::encode_frintm_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintp(SReg rd, SReg rn) {
    emit(simd_dp::encode_frintp_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintp(DReg rd, DReg rn) {
    emit(simd_dp::encode_frintp_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintz(SReg rd, SReg rn) {
    emit(simd_dp::encode_frintz_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintz(DReg rd, DReg rn) {
    emit(simd_dp::encode_frintz_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frinta(SReg rd, SReg rn) {
    emit(simd_dp::encode_frinta_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frinta(DReg rd, DReg rn) {
    emit(simd_dp::encode_frinta_d_floatdp1(rd.idx, rn.idx));
    return *this;
}

// === Scalar FP Convert (rounding modes) ===
CodeGenerator& CodeGenerator::fcvtas(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtas_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtas(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtas_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtas(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtas_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtas(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtas_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtau(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtau_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtau(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtau_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtau(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtau_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtau(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtau_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtms(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtms_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtms(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtms_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtms(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtms_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtms(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtms_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtmu(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtmu_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtmu(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtmu_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtmu(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtmu_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtmu(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtmu_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtns(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtns_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtns(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtns_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtns(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtns_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtns(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtns_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtnu(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtnu_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtnu(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtnu_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtnu(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtnu_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtnu(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtnu_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtps(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtps_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtps(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtps_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtps(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtps_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtps(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtps_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtpu(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtpu_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtpu(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtpu_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtpu(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtpu_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtpu(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtpu_64d_float2int(rd.idx, rn.idx));
    return *this;
}

// === Scalar FP frint32/64 ===
CodeGenerator& CodeGenerator::frint32z(SReg rd, SReg rn) {
    emit(simd_dp::encode_frint32z_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint32z(DReg rd, DReg rn) {
    emit(simd_dp::encode_frint32z_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint32x(SReg rd, SReg rn) {
    emit(simd_dp::encode_frint32x_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint32x(DReg rd, DReg rn) {
    emit(simd_dp::encode_frint32x_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint64z(SReg rd, SReg rn) {
    emit(simd_dp::encode_frint64z_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint64z(DReg rd, DReg rn) {
    emit(simd_dp::encode_frint64z_d_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint64x(SReg rd, SReg rn) {
    emit(simd_dp::encode_frint64x_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frint64x(DReg rd, DReg rn) {
    emit(simd_dp::encode_frint64x_d_floatdp1(rd.idx, rn.idx));
    return *this;
}

// === FP Vector ===
CodeGenerator& CodeGenerator::fadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fsub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fsub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmul(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmul_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fdiv(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fdiv_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fabs(VArr vd, VArr vn) {
    emit(simd_dp::encode_fabs_asimdmisc_r(vd.idx, vn.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fneg(VArr vd, VArr vn) {
    emit(simd_dp::encode_fneg_asimdmisc_r(vd.idx, vn.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === GP Extra ===
CodeGenerator& CodeGenerator::rev16(XReg rd, XReg rn) {
    emit(dpreg::encode_rev16_64_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::rev16(WReg rd, WReg rn) {
    emit(dpreg::encode_rev16_32_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::rev32(XReg rd, XReg rn) {
    emit(dpreg::encode_rev32_64_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::eon(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_eon_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}
CodeGenerator& CodeGenerator::eon(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_eon_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}
CodeGenerator& CodeGenerator::bics(XReg rd, XReg rn, XReg rm, Shift sh) {
    emit(dpreg::encode_bics_64_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}
CodeGenerator& CodeGenerator::bics(WReg rd, WReg rn, WReg rm, Shift sh) {
    emit(dpreg::encode_bics_32_log_shift(rd.idx, rn.idx, sh.amount, rm.idx, static_cast<uint32_t>(sh.type)));
    return *this;
}

// === Multi-Precision Arithmetic ===
CodeGenerator& CodeGenerator::smaddl(XReg rd, WReg rn, WReg rm, XReg ra) {
    emit(dpreg::encode_smaddl_64wa_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::smsubl(XReg rd, WReg rn, WReg rm, XReg ra) {
    emit(dpreg::encode_smsubl_64wa_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umaddl(XReg rd, WReg rn, WReg rm, XReg ra) {
    emit(dpreg::encode_umaddl_64wa_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umsubl(XReg rd, WReg rn, WReg rm, XReg ra) {
    emit(dpreg::encode_umsubl_64wa_dp_3src(rd.idx, rn.idx, ra.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::smnegl(XReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_smsubl_64wa_dp_3src(rd.idx, rn.idx, 31, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umnegl(XReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_umsubl_64wa_dp_3src(rd.idx, rn.idx, 31, rm.idx));
    return *this;
}

// === CRC ===
CodeGenerator& CodeGenerator::crc32b(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32b_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32h(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32h_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32w(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32w_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32x(WReg rd, WReg rn, XReg rm) {
    emit(dpreg::encode_crc32x_64c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32cb(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32cb_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32ch(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32ch_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32cw(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_crc32cw_32c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::crc32cx(WReg rd, WReg rn, XReg rm) {
    emit(dpreg::encode_crc32cx_64c_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

// === Pointer Authentication ===
CodeGenerator& CodeGenerator::pacia(XReg rd, XReg rn) {
    emit(dpreg::encode_pacia_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::pacib(XReg rd, XReg rn) {
    emit(dpreg::encode_pacib_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::pacda(XReg rd, XReg rn) {
    emit(dpreg::encode_pacda_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::pacdb(XReg rd, XReg rn) {
    emit(dpreg::encode_pacdb_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::autia(XReg rd, XReg rn) {
    emit(dpreg::encode_autia_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::autib(XReg rd, XReg rn) {
    emit(dpreg::encode_autib_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::autda(XReg rd, XReg rn) {
    emit(dpreg::encode_autda_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::autdb(XReg rd, XReg rn) {
    emit(dpreg::encode_autdb_64p_dp_1src(rd.idx, rn.idx));
    return *this;
}

// === Unscaled Load/Store ===
CodeGenerator& CodeGenerator::ldur(XReg rt, Mem mem) {
    emit(ldst::encode_ldur_64_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur(WReg rt, Mem mem) {
    emit(ldst::encode_ldur_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur(XReg rt, Mem mem) {
    emit(ldst::encode_stur_64_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur(WReg rt, Mem mem) {
    emit(ldst::encode_stur_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur(SReg rt, Mem mem) {
    emit(ldst::encode_ldur_s_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur(DReg rt, Mem mem) {
    emit(ldst::encode_ldur_d_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur(QReg rt, Mem mem) {
    emit(ldst::encode_ldur_q_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur(SReg rt, Mem mem) {
    emit(ldst::encode_stur_s_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur(DReg rt, Mem mem) {
    emit(ldst::encode_stur_d_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur(QReg rt, Mem mem) {
    emit(ldst::encode_stur_q_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}

// === FP Pair Load/Store ===
CodeGenerator& CodeGenerator::ldp(SReg rt1, SReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_s_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_s_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else
        emit(ldst::encode_ldp_s_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldp(DReg rt1, DReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_d_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_d_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else
        emit(ldst::encode_ldp_d_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldp(QReg rt1, QReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_q_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_q_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else
        emit(ldst::encode_ldp_q_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp(SReg rt1, SReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_s_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_s_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else
        emit(ldst::encode_stp_s_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp(DReg rt1, DReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_d_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_d_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else
        emit(ldst::encode_stp_d_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp(QReg rt1, QReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_q_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_q_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else
        emit(ldst::encode_stp_q_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    return *this;
}

// === SIMD Permute/Extract ===
CodeGenerator& CodeGenerator::ext(VArr vd, VArr vn, VArr vm, uint8_t index) {
    emit(simd_dp::encode_ext_asimdext_only(vd.idx, vn.idx, index, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::trn1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_trn1_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::trn2(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_trn2_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::zip1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_zip1_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::zip2(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_zip2_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uzp1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uzp1_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uzp2(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uzp2_asimdperm_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::tbl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_tbl_asimdtbl_l1_1(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smov(XReg rd, VArr vn, uint8_t index) {
    uint32_t imm5 = (index << (vn.size() + 1)) | (1u << vn.size());
    emit(simd_dp::encode_smov_asimdins_x_x(rd.idx, vn.idx, imm5));
    return *this;
}
CodeGenerator& CodeGenerator::smov(WReg rd, VArr vn, uint8_t index) {
    uint32_t imm5 = (index << (vn.size() + 1)) | (1u << vn.size());
    emit(simd_dp::encode_smov_asimdins_w_w(rd.idx, vn.idx, imm5));
    return *this;
}

// === SIMD Arithmetic Extra ===
CodeGenerator& CodeGenerator::smax(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smax_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smin(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smin_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umax(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_umax_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umin(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_umin_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uqadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqsub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqsub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqsub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uqsub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::rev64(VArr vd, VArr vn) {
    emit(simd_dp::encode_rev64_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::rev32(VArr vd, VArr vn) {
    emit(simd_dp::encode_rev32_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::rev16(VArr vd, VArr vn) {
    emit(simd_dp::encode_rev16_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::cls(VArr vd, VArr vn) {
    emit(simd_dp::encode_cls_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::clz(VArr vd, VArr vn) {
    emit(simd_dp::encode_clz_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::orn(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_orn_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::bsl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bsl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::bit(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bit_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::bif(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bif_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

// === SIMD Multiply-Accumulate ===
CodeGenerator& CodeGenerator::mla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_mla_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::mls(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_mls_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Reductions ===
CodeGenerator& CodeGenerator::addv(VArr vd, VArr vn) {
    emit(simd_dp::encode_addv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::saddlv(VArr vd, VArr vn) {
    emit(simd_dp::encode_saddlv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uaddlv(VArr vd, VArr vn) {
    emit(simd_dp::encode_uaddlv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}

// === SIMD Narrowing/Widening ===
CodeGenerator& CodeGenerator::xtn(VArr vd, VArr vn) {
    emit(simd_dp::encode_xtn_asimdmisc_n(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

// === FP Vector Multiply-Accumulate ===
CodeGenerator& CodeGenerator::fmla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmla_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmls(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmls_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === FP Pairwise ===
CodeGenerator& CodeGenerator::faddp(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_faddp_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === FP Vector Compare ===
CodeGenerator& CodeGenerator::fcmeq(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fcmeq_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmge(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fcmge_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmgt(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fcmgt_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === FP Vector Rounding ===
CodeGenerator& CodeGenerator::frintn(VArr vd, VArr vn) {
    emit(simd_dp::encode_frintn_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frintm(VArr vd, VArr vn) {
    emit(simd_dp::encode_frintm_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frintp(VArr vd, VArr vn) {
    emit(simd_dp::encode_frintp_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frintz(VArr vd, VArr vn) {
    emit(simd_dp::encode_frintz_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frinta(VArr vd, VArr vn) {
    emit(simd_dp::encode_frinta_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}

// === FP Vector Estimates ===
CodeGenerator& CodeGenerator::frecpe(VArr vd, VArr vn) {
    emit(simd_dp::encode_frecpe_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frsqrte(VArr vd, VArr vn) {
    emit(simd_dp::encode_frsqrte_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}

// === SIMD Vector FP Max/Min ===
CodeGenerator& CodeGenerator::fmax(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmax_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmin(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmin_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmaxnm(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmaxnm_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fminnm(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fminnm_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === SIMD Vector Conversions ===
CodeGenerator& CodeGenerator::fcvtzs(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtzs_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtzu_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf(VArr vd, VArr vn) {
    emit(simd_dp::encode_scvtf_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf(VArr vd, VArr vn) {
    emit(simd_dp::encode_ucvtf_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}

// === SIMD Widening Multiply ===
CodeGenerator& CodeGenerator::smlal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smlal_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smlsl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smlsl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smull(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smull_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umlal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_umlal_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umlsl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_umlsl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umull(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_umull_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}

// === SIMD Saturating Multiply High ===
CodeGenerator& CodeGenerator::sqdmulh(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqdmulh_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqrdmulh(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqrdmulh_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Register Shift ===
CodeGenerator& CodeGenerator::sshl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sshl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ushl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_ushl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Saturating Narrowing ===
CodeGenerator& CodeGenerator::sqxtn(VArr vd, VArr vn) {
    emit(simd_dp::encode_sqxtn_asimdmisc_n(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqxtun(VArr vd, VArr vn) {
    emit(simd_dp::encode_sqxtun_asimdmisc_n(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqxtn(VArr vd, VArr vn) {
    emit(simd_dp::encode_uqxtn_asimdmisc_n(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}

// === Unscaled Load/Store (byte/half/signed) ===
CodeGenerator& CodeGenerator::ldurb(WReg rt, Mem mem) {
    emit(ldst::encode_ldurb_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldurh(WReg rt, Mem mem) {
    emit(ldst::encode_ldurh_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldursb(XReg rt, Mem mem) {
    emit(ldst::encode_ldursb_64_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldursb(WReg rt, Mem mem) {
    emit(ldst::encode_ldursb_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldursh(XReg rt, Mem mem) {
    emit(ldst::encode_ldursh_64_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldursh(WReg rt, Mem mem) {
    emit(ldst::encode_ldursh_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldursw(XReg rt, Mem mem) {
    emit(ldst::encode_ldursw_64_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::sturb(WReg rt, Mem mem) {
    emit(ldst::encode_sturb_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::sturh(WReg rt, Mem mem) {
    emit(ldst::encode_sturh_32_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}

// === Load-Acquire / Store-Release Unscaled ===
CodeGenerator& CodeGenerator::ldapur(XReg rt, Mem mem) {
    emit(ldst::encode_ldapur_64_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapur(WReg rt, Mem mem) {
    emit(ldst::encode_ldapur_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapurb(WReg rt, Mem mem) {
    emit(ldst::encode_ldapurb_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapurh(WReg rt, Mem mem) {
    emit(ldst::encode_ldapurh_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapursb(XReg rt, Mem mem) {
    emit(ldst::encode_ldapursb_64_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapursb(WReg rt, Mem mem) {
    emit(ldst::encode_ldapursb_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapursh(XReg rt, Mem mem) {
    emit(ldst::encode_ldapursh_64_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapursh(WReg rt, Mem mem) {
    emit(ldst::encode_ldapursh_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldapursw(XReg rt, Mem mem) {
    emit(ldst::encode_ldapursw_64_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stlur(XReg rt, Mem mem) {
    emit(ldst::encode_stlur_64_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stlur(WReg rt, Mem mem) {
    emit(ldst::encode_stlur_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stlurb(WReg rt, Mem mem) {
    emit(ldst::encode_stlurb_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stlurh(WReg rt, Mem mem) {
    emit(ldst::encode_stlurh_32_ldapstl_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}

// === Compare-and-Swap Pair ===
CodeGenerator& CodeGenerator::casp(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_casp_cp64_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::casp(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_casp_cp32_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspa(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_caspa_cp64_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspa(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_caspa_cp32_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspl(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_caspl_cp64_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspl(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_caspl_cp32_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspal(XReg rs, XReg rt, XReg rn) {
    emit(ldst::encode_caspal_cp64_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}
CodeGenerator& CodeGenerator::caspal(WReg rs, WReg rt, XReg rn) {
    emit(ldst::encode_caspal_cp32_comswappr(rt.idx, rn.idx, rs.idx));
    return *this;
}

// === GP Min/Max (ARMv9) ===
CodeGenerator& CodeGenerator::smax(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_smax_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::smax(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_smax_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::smin(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_smin_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::smin(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_smin_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umax(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_umax_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umax(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_umax_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umin(XReg rd, XReg rn, XReg rm) {
    emit(dpreg::encode_umin_64_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::umin(WReg rd, WReg rn, WReg rm) {
    emit(dpreg::encode_umin_32_dp_2src(rd.idx, rn.idx, rm.idx));
    return *this;
}

// === SIMD Widening Add/Sub ===
CodeGenerator& CodeGenerator::saddl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_saddl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ssubl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_ssubl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uaddl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uaddl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::usubl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_usubl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::saddw(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_saddw_asimddiff_w(vd.idx, vn.idx, vm.idx, vm.size(), vm.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ssubw(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_ssubw_asimddiff_w(vd.idx, vn.idx, vm.idx, vm.size(), vm.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uaddw(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uaddw_asimddiff_w(vd.idx, vn.idx, vm.idx, vm.size(), vm.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::usubw(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_usubw_asimddiff_w(vd.idx, vn.idx, vm.idx, vm.size(), vm.Q()));
    return *this;
}

// === SIMD Absolute Difference ===
CodeGenerator& CodeGenerator::sabd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sabd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uabd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uabd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::saba(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_saba_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uaba(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uaba_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sabal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sabal_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uabal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uabal_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sabdl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sabdl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uabdl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uabdl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}

// === SIMD Polynomial Multiply ===
CodeGenerator& CodeGenerator::pmul(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_pmul_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::pmull(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_pmull_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}

// === SIMD Rounding Shift ===
CodeGenerator& CodeGenerator::srshl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_srshl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::urshl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_urshl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Halving Arithmetic ===
CodeGenerator& CodeGenerator::shadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_shadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::shsub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_shsub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uhadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uhadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uhsub(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uhsub_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::srhadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_srhadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::urhadd(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_urhadd_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Reductions (min/max) ===
CodeGenerator& CodeGenerator::smaxv(VArr vd, VArr vn) {
    emit(simd_dp::encode_smaxv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sminv(VArr vd, VArr vn) {
    emit(simd_dp::encode_sminv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umaxv(VArr vd, VArr vn) {
    emit(simd_dp::encode_umaxv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uminv(VArr vd, VArr vn) {
    emit(simd_dp::encode_uminv_asimdall_only(vd.idx, vn.idx, vn.size(), vn.Q()));
    return *this;
}

// === SIMD Float Widen/Narrow ===
CodeGenerator& CodeGenerator::fcvtl(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtl_asimdmisc_l(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtn(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtn_asimdmisc_n(vd.idx, vn.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === Hints ===
CodeGenerator& CodeGenerator::yield_() {
    emit(control::encode_yield_hi_hints());
    return *this;
}
CodeGenerator& CodeGenerator::wfe() {
    emit(control::encode_wfe_hi_hints());
    return *this;
}
CodeGenerator& CodeGenerator::wfi() {
    emit(control::encode_wfi_hi_hints());
    return *this;
}
CodeGenerator& CodeGenerator::sev() {
    emit(control::encode_sev_hi_hints());
    return *this;
}
CodeGenerator& CodeGenerator::sevl() {
    emit(control::encode_sevl_hi_hints());
    return *this;
}
CodeGenerator& CodeGenerator::csdb() {
    emit(control::encode_csdb_hi_hints());
    return *this;
}

// === Bitfield Move ===
CodeGenerator& CodeGenerator::bfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_bfm_64m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}
CodeGenerator& CodeGenerator::bfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_bfm_32m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}
CodeGenerator& CodeGenerator::sbfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_sbfm_64m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}
CodeGenerator& CodeGenerator::sbfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_sbfm_32m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}
CodeGenerator& CodeGenerator::ubfm(XReg rd, XReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_ubfm_64m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}
CodeGenerator& CodeGenerator::ubfm(WReg rd, WReg rn, uint8_t immr, uint8_t imms) {
    emit(dpimm::encode_ubfm_32m_bitfield(rd.idx, rn.idx, imms, immr));
    return *this;
}

// === PSTATE ===
CodeGenerator& CodeGenerator::cfinv() {
    emit(control::encode_cfinv_m_pstate());
    return *this;
}
CodeGenerator& CodeGenerator::xaflag() {
    emit(control::encode_xaflag_m_pstate());
    return *this;
}
CodeGenerator& CodeGenerator::axflag() {
    emit(control::encode_axflag_m_pstate());
    return *this;
}

// === Scalar FP Compare (Exception) ===
CodeGenerator& CodeGenerator::fcmpe(SReg rn, SReg rm) {
    emit(simd_dp::encode_fcmpe_s_floatcmp(rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcmpe(SReg rn) {
    emit(simd_dp::encode_fcmpe_sz_floatcmp(rn.idx, 0));
    return *this;
}
CodeGenerator& CodeGenerator::fcmpe(DReg rn, DReg rm) {
    emit(simd_dp::encode_fcmpe_d_floatcmp(rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcmpe(DReg rn) {
    emit(simd_dp::encode_fcmpe_dz_floatcmp(rn.idx, 0));
    return *this;
}
CodeGenerator& CodeGenerator::fccmpe(SReg rn, SReg rm, uint8_t nzcv, Condition cc) {
    emit(simd_dp::encode_fccmpe_s_floatccmp(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fccmpe(DReg rn, DReg rm, uint8_t nzcv, Condition cc) {
    emit(simd_dp::encode_fccmpe_d_floatccmp(nzcv, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

// === SIMD Shift Immediate (Extra) ===
CodeGenerator& CodeGenerator::srshr(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_srshr_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::urshr(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_urshr_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ssra(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_ssra_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::usra(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_usra_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sli(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = shift + esize;
    emit(simd_dp::encode_sli_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sri(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_sri_asimdshf_r(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::shrn(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_shrn_asimdshf_n(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::rshrn(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t combined = esize * 2 - shift;
    emit(simd_dp::encode_rshrn_asimdshf_n(vd.idx, vn.idx, combined & 7, combined >> 3, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sshll(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vn.size();
    uint32_t combined = shift + esize;
    emit(simd_dp::encode_sshll_asimdshf_l(vd.idx, vn.idx, combined & 7, combined >> 3, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ushll(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vn.size();
    uint32_t combined = shift + esize;
    emit(simd_dp::encode_ushll_asimdshf_l(vd.idx, vn.idx, combined & 7, combined >> 3, vn.Q()));
    return *this;
}

// === SIMD Add/Sub High Narrow ===
CodeGenerator& CodeGenerator::addhn(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_addhn_asimddiff_n(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::raddhn(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_raddhn_asimddiff_n(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::subhn(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_subhn_asimddiff_n(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::rsubhn(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_rsubhn_asimddiff_n(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Saturating Multiply Long ===
CodeGenerator& CodeGenerator::sqdmull(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqdmull_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmlal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqdmlal_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmlsl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqdmlsl_asimddiff_l(vd.idx, vn.idx, vm.idx, vn.size(), vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqrdmlah(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqrdmlah_asimdsame2_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqrdmlsh(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqrdmlsh_asimdsame2_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD FP Extended/Step ===
CodeGenerator& CodeGenerator::fmulx(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmulx_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frecps(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_frecps_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::frsqrts(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_frsqrts_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === SIMD FP Absolute Compare ===
CodeGenerator& CodeGenerator::facge(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_facge_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::facgt(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_facgt_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === SIMD FP Pairwise Max/Min ===
CodeGenerator& CodeGenerator::fmaxp(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fmaxp_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fminp(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fminp_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === SIMD Saturating Shift (Register) ===
CodeGenerator& CodeGenerator::sqshl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sqshl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqshl(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_uqshl_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD Table Extension ===
CodeGenerator& CodeGenerator::tbx(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_tbx_asimdtbl_l1_1(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

// === SIMD Compare (extra) ===
CodeGenerator& CodeGenerator::cmtst(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_cmtst_asimdsame_only(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === SIMD FP Compare vs Zero ===
CodeGenerator& CodeGenerator::fcmeq_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcmeq_asimdmisc_fz(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmge_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcmge_asimdmisc_fz(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmgt_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcmgt_asimdmisc_fz(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmle_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcmle_asimdmisc_fz(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmlt_zero(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcmlt_asimdmisc_fz(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}

// === SIMD DUP (element) / INS (element from element) ===
CodeGenerator& CodeGenerator::dup(VArr vd, VArr vn, uint8_t index) {
    uint32_t imm5 = (index << (vd.size() + 1)) | (1u << vd.size());
    emit(simd_dp::encode_dup_asimdins_dv_v(vd.idx, vn.idx, imm5, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::ins(VArr vd, uint8_t dst_idx, VArr vn, uint8_t src_idx) {
    uint32_t imm5 = (dst_idx << (vd.size() + 1)) | (1u << vd.size());
    uint32_t imm4 = src_idx << vd.size();
    emit(simd_dp::encode_ins_asimdins_iv_v(vd.idx, vn.idx, imm4, imm5));
    return *this;
}

// === SIMD MVNI ===
CodeGenerator& CodeGenerator::mvni(VArr vd, uint8_t imm8, uint8_t shift) {
    uint32_t a = (imm8 >> 7) & 1, b = (imm8 >> 6) & 1;
    uint32_t c = (imm8 >> 5) & 1, d = (imm8 >> 4) & 1;
    uint32_t e = (imm8 >> 3) & 1, f = (imm8 >> 2) & 1;
    uint32_t g = (imm8 >> 1) & 1, h = imm8 & 1;
    uint32_t cmode = 0;
    if (vd.size() == 1) {
        // 16-bit: cmode = 100x
        cmode = 0x8 | ((shift >> 3) & 1);
    } else {
        // 32-bit: cmode = 0xx0
        cmode = (shift >> 3) << 1;
    }
    emit(simd_dp::encode_mvni_asimdimm_l_sl(vd.idx, h, g, f, e, d, cmode, c, b, a, vd.Q()));
    return *this;
}

// === SIMD Vector FP Conversions (rounding modes) ===
CodeGenerator& CodeGenerator::fcvtas(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtas_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtau(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtau_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtns(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtns_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtnu(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtnu_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtps(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtps_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtpu(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtpu_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtms(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtms_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtmu(VArr vd, VArr vn) {
    emit(simd_dp::encode_fcvtmu_asimdmisc_r(vd.idx, vn.idx, vn.size() - 2, vn.Q()));
    return *this;
}

// === Crypto (AES) ===
CodeGenerator& CodeGenerator::aesd(VArr vd, VArr vn) {
    emit(simd_dp::encode_aesd_b_cryptoaes(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::aese(VArr vd, VArr vn) {
    emit(simd_dp::encode_aese_b_cryptoaes(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::aesimc(VArr vd, VArr vn) {
    emit(simd_dp::encode_aesimc_b_cryptoaes(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::aesmc(VArr vd, VArr vn) {
    emit(simd_dp::encode_aesmc_b_cryptoaes(vd.idx, vn.idx));
    return *this;
}

// === Crypto (SHA-1) ===
CodeGenerator& CodeGenerator::sha1c(QReg rd, SReg rn, VArr vm) {
    emit(simd_dp::encode_sha1c_qsv_cryptosha3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha1h(SReg rd, SReg rn) {
    emit(simd_dp::encode_sha1h_ss_cryptosha2(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha1m(QReg rd, SReg rn, VArr vm) {
    emit(simd_dp::encode_sha1m_qsv_cryptosha3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha1p(QReg rd, SReg rn, VArr vm) {
    emit(simd_dp::encode_sha1p_qsv_cryptosha3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha1su0(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sha1su0_vvv_cryptosha3(vd.idx, vn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha1su1(VArr vd, VArr vn) {
    emit(simd_dp::encode_sha1su1_vv_cryptosha2(vd.idx, vn.idx));
    return *this;
}

// === Crypto (SHA-256) ===
CodeGenerator& CodeGenerator::sha256h(QReg rd, QReg rn, VArr vm) {
    emit(simd_dp::encode_sha256h_qqv_cryptosha3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha256h2(QReg rd, QReg rn, VArr vm) {
    emit(simd_dp::encode_sha256h2_qqv_cryptosha3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha256su0(VArr vd, VArr vn) {
    emit(simd_dp::encode_sha256su0_vv_cryptosha2(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha256su1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sha256su1_vvv_cryptosha3(vd.idx, vn.idx, vm.idx));
    return *this;
}

// === Crypto (SHA-512) ===
CodeGenerator& CodeGenerator::sha512h(QReg rd, QReg rn, VArr vm) {
    emit(simd_dp::encode_sha512h_qqv_cryptosha512_3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha512h2(QReg rd, QReg rn, VArr vm) {
    emit(simd_dp::encode_sha512h2_qqv_cryptosha512_3(rd.idx, rn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha512su0(VArr vd, VArr vn) {
    emit(simd_dp::encode_sha512su0_vv2_cryptosha512_2(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sha512su1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sha512su1_vvv2_cryptosha512_3(vd.idx, vn.idx, vm.idx));
    return *this;
}

// === Crypto (SHA3 / misc) ===
CodeGenerator& CodeGenerator::bcax(VArr vd, VArr vn, VArr vm, VArr va) {
    emit(simd_dp::encode_bcax_vvv16_crypto4(vd.idx, vn.idx, va.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::eor3(VArr vd, VArr vn, VArr vm, VArr va) {
    emit(simd_dp::encode_eor3_vvv16_crypto4(vd.idx, vn.idx, va.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::rax1(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_rax1_vvv2_cryptosha512_3(vd.idx, vn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::xar(VArr vd, VArr vn, VArr vm, uint8_t imm6) {
    emit(simd_dp::encode_xar_vvv2_crypto3_imm6(vd.idx, vn.idx, imm6, vm.idx));
    return *this;
}

// === Scalar FP Reciprocal ===
CodeGenerator& CodeGenerator::frecpx(SReg rd, SReg rn) {
    emit(simd_dp::encode_frecpx_asisdmisc_r(rd.idx, rn.idx, 0));
    return *this;
}
CodeGenerator& CodeGenerator::frecpx(DReg rd, DReg rn) {
    emit(simd_dp::encode_frecpx_asisdmisc_r(rd.idx, rn.idx, 1));
    return *this;
}

// === SIMD FP Dot Product ===
CodeGenerator& CodeGenerator::fdot(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_fdot_asimdsame2_d(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

// === SIMD FP Reductions ===
CodeGenerator& CodeGenerator::fmaxv(VArr vd, VArr vn) {
    emit(simd_dp::encode_fmaxv_asimdall_only_sd(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fminv(VArr vd, VArr vn) {
    emit(simd_dp::encode_fminv_asimdall_only_sd(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmaxnmv(VArr vd, VArr vn) {
    emit(simd_dp::encode_fmaxnmv_asimdall_only_sd(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fminnmv(VArr vd, VArr vn) {
    emit(simd_dp::encode_fminnmv_asimdall_only_sd(vd.idx, vn.idx));
    return *this;
}

// === SIMD Vector Reverse Bits ===
CodeGenerator& CodeGenerator::rbit(VArr vd, VArr vn) {
    emit(simd_dp::encode_rbit_asimdmisc_r(vd.idx, vn.idx, vd.Q()));
    return *this;
}

// === Integer Dot Product ===
CodeGenerator& CodeGenerator::sdot(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sdot_asimdsame2_d(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::udot(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_udot_asimdsame2_d(vd.idx, vn.idx, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === Matrix Multiply ===
CodeGenerator& CodeGenerator::smmla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_smmla_asimdsame2_g(vd.idx, vn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ummla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_ummla_asimdsame2_g(vd.idx, vn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::usmmla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_usmmla_asimdsame2_g(vd.idx, vn.idx, vm.idx));
    return *this;
}

// === BFloat16 ===
CodeGenerator& CodeGenerator::bfmmla(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bfmmla_asimdsame2_e(vd.idx, vn.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::bfdot(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bfdot_asimdsame2_d(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::bfcvt(SReg rd, SReg rn) {
    emit(simd_dp::encode_bfcvt_bs_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::bfcvtn(VArr vd, VArr vn) {
    emit(simd_dp::encode_bfcvtn_asimdmisc_4s(vd.idx, vn.idx, vd.Q()));
    return *this;
}

// === GP<->FP Transfer (FMOV) ===
CodeGenerator& CodeGenerator::fmov_gp(WReg rd, SReg rn) {
    emit(simd_dp::encode_fmov_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov_gp(SReg rd, WReg rn) {
    emit(simd_dp::encode_fmov_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov_gp(XReg rd, DReg rn) {
    emit(simd_dp::encode_fmov_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmov_gp(DReg rd, XReg rn) {
    emit(simd_dp::encode_fmov_d64_float2int(rd.idx, rn.idx));
    return *this;
}

// === GP<->FP Conversion (scalar) ===
CodeGenerator& CodeGenerator::scvtf_gp(SReg rd, WReg rn) {
    emit(simd_dp::encode_scvtf_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf_gp(DReg rd, WReg rn) {
    emit(simd_dp::encode_scvtf_d32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf_gp(SReg rd, XReg rn) {
    emit(simd_dp::encode_scvtf_s64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::scvtf_gp(DReg rd, XReg rn) {
    emit(simd_dp::encode_scvtf_d64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf_gp(SReg rd, WReg rn) {
    emit(simd_dp::encode_ucvtf_s32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf_gp(DReg rd, WReg rn) {
    emit(simd_dp::encode_ucvtf_d32_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf_gp(SReg rd, XReg rn) {
    emit(simd_dp::encode_ucvtf_s64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ucvtf_gp(DReg rd, XReg rn) {
    emit(simd_dp::encode_ucvtf_d64_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs_gp(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzs_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs_gp(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzs_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs_gp(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzs_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzs_gp(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzs_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu_gp(WReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzu_32s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu_gp(WReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzu_32d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu_gp(XReg rd, SReg rn) {
    emit(simd_dp::encode_fcvtzu_64s_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fcvtzu_gp(XReg rd, DReg rn) {
    emit(simd_dp::encode_fcvtzu_64d_float2int(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fjcvtzs(WReg rd, DReg rn) {
    emit(simd_dp::encode_fjcvtzs_32d_float2int(rd.idx, rn.idx));
    return *this;
}

// === Crypto (SM3/SM4) ===
CodeGenerator& CodeGenerator::sm3ss1(VArr vd, VArr vn, VArr vm, VArr va) {
    emit(simd_dp::encode_sm3ss1_vvv4_crypto4(vd.idx, vn.idx, va.idx, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm3tt1a(VArr vd, VArr vn, VArr vm, uint8_t imm2) {
    emit(simd_dp::encode_sm3tt1a_vvv4_crypto3_imm2(vd.idx, vn.idx, imm2, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm3tt1b(VArr vd, VArr vn, VArr vm, uint8_t imm2) {
    emit(simd_dp::encode_sm3tt1b_vvv4_crypto3_imm2(vd.idx, vn.idx, imm2, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm3tt2a(VArr vd, VArr vn, VArr vm, uint8_t imm2) {
    emit(simd_dp::encode_sm3tt2a_vvv4_crypto3_imm2(vd.idx, vn.idx, imm2, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm3tt2b(VArr vd, VArr vn, VArr vm, uint8_t imm2) {
    emit(simd_dp::encode_sm3tt2b_vvv_crypto3_imm2(vd.idx, vn.idx, imm2, vm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm4e(VArr vd, VArr vn) {
    emit(simd_dp::encode_sm4e_vv4_cryptosha512_2(vd.idx, vn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sm4ekey(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_sm4ekey_vvv4_cryptosha512_3(vd.idx, vn.idx, vm.idx));
    return *this;
}

// === SIMD Saturating Misc ===
CodeGenerator& CodeGenerator::sqabs(VArr vd, VArr vn) {
    emit(simd_dp::encode_sqabs_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqneg(VArr vd, VArr vn) {
    emit(simd_dp::encode_sqneg_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::suqadd(VArr vd, VArr vn) {
    emit(simd_dp::encode_suqadd_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::usqadd(VArr vd, VArr vn) {
    emit(simd_dp::encode_usqadd_asimdmisc_r(vd.idx, vn.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqshlu(VArr vd, VArr vn, uint8_t shift) {
    // immh:immb encode the shift amount; immh also encodes element size
    // For 8-bit: immh=0001, shift_amount = (8 + shift) => immh=1, immb=shift
    // For 16-bit: immh=001x, shift_amount = (16 + shift) => immh has bit 1 set
    // For 32-bit: immh=01xx, shift_amount = (32 + shift) => immh has bit 2 set
    // For 64-bit: immh=1xxx, shift_amount = (64 + shift) => immh has bit 3 set
    uint32_t esize = 8u << vd.size();
    uint32_t val = esize + shift;
    uint32_t immh = val >> 3;
    uint32_t immb = val & 0x7;
    emit(simd_dp::encode_sqshlu_asimdshf_r(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}

// === SIMD Narrowing/Widening Extras ===
CodeGenerator& CodeGenerator::sqshrn(VArr vd, VArr vn, uint8_t shift) {
    // Right shift: immh:immb = (2*esize - shift), where esize = 8 << vd.size()
    uint32_t esize = 8u << vd.size();
    uint32_t val = 2 * esize - shift;
    uint32_t immh = val >> 3;
    uint32_t immb = val & 0x7;
    emit(simd_dp::encode_sqshrn_asimdshf_n(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqrshrn(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t val = 2 * esize - shift;
    uint32_t immh = val >> 3;
    uint32_t immb = val & 0x7;
    emit(simd_dp::encode_sqrshrn_asimdshf_n(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqshrn(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t val = 2 * esize - shift;
    uint32_t immh = val >> 3;
    uint32_t immb = val & 0x7;
    emit(simd_dp::encode_uqshrn_asimdshf_n(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::uqrshrn(VArr vd, VArr vn, uint8_t shift) {
    uint32_t esize = 8u << vd.size();
    uint32_t val = 2 * esize - shift;
    uint32_t immh = val >> 3;
    uint32_t immb = val & 0x7;
    emit(simd_dp::encode_uqrshrn_asimdshf_n(vd.idx, vn.idx, immb, immh, vd.Q()));
    return *this;
}

// === Shift Aliases (Immediate) ===
CodeGenerator& CodeGenerator::lsl_imm(WReg rd, WReg rn, uint8_t shift) {
    // LSL Wd, Wn, #shift => UBFM Wd, Wn, #(32-shift), #(31-shift)
    emit(dpimm::encode_lsl_ubfm_32m_bitfield(rd.idx, rn.idx, 31 - shift, 32 - shift));
    return *this;
}
CodeGenerator& CodeGenerator::lsl_imm(XReg rd, XReg rn, uint8_t shift) {
    // LSL Xd, Xn, #shift => UBFM Xd, Xn, #(64-shift), #(63-shift)
    emit(dpimm::encode_lsl_ubfm_64m_bitfield(rd.idx, rn.idx, 63 - shift, 64 - shift));
    return *this;
}
CodeGenerator& CodeGenerator::lsr_imm(WReg rd, WReg rn, uint8_t shift) {
    emit(dpimm::encode_lsr_ubfm_32m_bitfield(rd.idx, rn.idx, shift));
    return *this;
}
CodeGenerator& CodeGenerator::lsr_imm(XReg rd, XReg rn, uint8_t shift) {
    emit(dpimm::encode_lsr_ubfm_64m_bitfield(rd.idx, rn.idx, shift));
    return *this;
}
CodeGenerator& CodeGenerator::asr_imm(WReg rd, WReg rn, uint8_t shift) {
    emit(dpimm::encode_asr_sbfm_32m_bitfield(rd.idx, rn.idx, shift));
    return *this;
}
CodeGenerator& CodeGenerator::asr_imm(XReg rd, XReg rn, uint8_t shift) {
    emit(dpimm::encode_asr_sbfm_64m_bitfield(rd.idx, rn.idx, shift));
    return *this;
}
CodeGenerator& CodeGenerator::ror_imm(WReg rd, WReg rn, uint8_t shift) {
    // ROR Wd, Wn, #shift => EXTR Wd, Wn, Wn, #shift
    emit(dpimm::encode_ror_extr_32_extract(rd.idx, rn.idx, shift, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ror_imm(XReg rd, XReg rn, uint8_t shift) {
    emit(dpimm::encode_ror_extr_64_extract(rd.idx, rn.idx, shift, rn.idx));
    return *this;
}

// === MOV SP Alias ===
CodeGenerator& CodeGenerator::mov_sp(XReg rd, XReg rn) {
    emit(dpimm::encode_mov_add_64_addsub_imm(rd.idx, rn.idx));
    return *this;
}

// === Misc Scalar FP ===
CodeGenerator& CodeGenerator::frintx(SReg rd, SReg rn) {
    emit(simd_dp::encode_frintx_s_floatdp1(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::frintx(DReg rd, DReg rn) {
    emit(simd_dp::encode_frintx_d_floatdp1(rd.idx, rn.idx));
    return *this;
}

// === SIMD Indexed Element (FP) ===
// For FP elem (_r_sd): sz=0 → 32-bit(S), sz=1 → 64-bit(D)
// 32-bit: index = H:L (2 bits), M = vm.idx >> 4
// 64-bit: index = H (1 bit), L = vm.idx >> 4, M = 0
CodeGenerator& CodeGenerator::fmla_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t sz = vd.size() - 2; // S=0, D=1
    uint32_t H, L, M;
    if (sz == 0) { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    else { H = index & 1; L = (vm.idx >> 4) & 1; M = 0; }
    emit(simd_dp::encode_fmla_asimdelem_r_sd(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, sz, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmls_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t sz = vd.size() - 2;
    uint32_t H, L, M;
    if (sz == 0) { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    else { H = index & 1; L = (vm.idx >> 4) & 1; M = 0; }
    emit(simd_dp::encode_fmls_asimdelem_r_sd(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, sz, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmul_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t sz = vd.size() - 2;
    uint32_t H, L, M;
    if (sz == 0) { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    else { H = index & 1; L = (vm.idx >> 4) & 1; M = 0; }
    emit(simd_dp::encode_fmul_asimdelem_r_sd(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, sz, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fmulx_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t sz = vd.size() - 2;
    uint32_t H, L, M;
    if (sz == 0) { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    else { H = index & 1; L = (vm.idx >> 4) & 1; M = 0; }
    emit(simd_dp::encode_fmulx_asimdelem_r_sd(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, sz, vd.Q()));
    return *this;
}

// === SIMD Indexed Element (Integer) ===
// Integer elem (_r): size=1 → 16-bit, size=2 → 32-bit
// 16-bit: index = H:L:M (3 bits)
// 32-bit: index = H:L (2 bits), M = vm.idx >> 4
CodeGenerator& CodeGenerator::mul_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_mul_asimdelem_r(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::mla_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_mla_asimdelem_r(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::mls_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_mls_asimdelem_r(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmulh_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_sqdmulh_asimdelem_r(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqrdmulh_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_sqrdmulh_asimdelem_r(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vd.Q()));
    return *this;
}

// === SIMD Widening Indexed Element ===
// Widening elem (_l): source uses vn.size(), same H:L:M decomposition as integer elem
CodeGenerator& CodeGenerator::smlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_smlal_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_smlsl_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::smull_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_smull_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_umlal_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_umlsl_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::umull_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_umull_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmlal_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_sqdmlal_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmlsl_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_sqdmlsl_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::sqdmull_elem(VArr vd, VArr vn, VArr vm, uint8_t index) {
    uint32_t size = vn.size();
    uint32_t H, L, M;
    if (size == 1) { H = (index >> 2) & 1; L = (index >> 1) & 1; M = index & 1; }
    else { H = (index >> 1) & 1; L = index & 1; M = (vm.idx >> 4) & 1; }
    emit(simd_dp::encode_sqdmull_asimdelem_l(vd.idx, vn.idx, H, vm.idx & 0x1F, M, L, size, vn.Q()));
    return *this;
}

// === FP Load/Store (unsigned offset) ===
CodeGenerator& CodeGenerator::ldr_fp(SReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_s_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_s_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_s_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}
CodeGenerator& CodeGenerator::ldr_fp(DReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_d_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_d_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_d_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}
CodeGenerator& CodeGenerator::ldr_fp(QReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_ldr_q_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 4));
        break;
    case MemMode::Pre:
        emit(ldst::encode_ldr_q_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_ldr_q_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}
CodeGenerator& CodeGenerator::str_fp(SReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_s_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 2));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_s_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_s_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}
CodeGenerator& CodeGenerator::str_fp(DReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_d_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 3));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_d_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_d_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}
CodeGenerator& CodeGenerator::str_fp(QReg rt, Mem mem) {
    switch (mem.mode) {
    case MemMode::Offset:
        emit(ldst::encode_str_q_ldst_pos(rt.idx, mem.base_idx, static_cast<uint32_t>(mem.offset) >> 4));
        break;
    case MemMode::Pre:
        emit(ldst::encode_str_q_ldst_immpre(rt.idx, mem.base_idx, mem.offset));
        break;
    case MemMode::Post:
        emit(ldst::encode_str_q_ldst_immpost(rt.idx, mem.base_idx, mem.offset));
        break;
    default: break;
    }
    return *this;
}

// === FP Pair Load/Store ===
CodeGenerator& CodeGenerator::ldp_fp(SReg rt1, SReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_s_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_s_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else
        emit(ldst::encode_ldp_s_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldp_fp(DReg rt1, DReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_d_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_d_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else
        emit(ldst::encode_ldp_d_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::ldp_fp(QReg rt1, QReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_ldp_q_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_ldp_q_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else
        emit(ldst::encode_ldp_q_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp_fp(SReg rt1, SReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_s_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_s_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    else
        emit(ldst::encode_stp_s_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 2) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp_fp(DReg rt1, DReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_d_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_d_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    else
        emit(ldst::encode_stp_d_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 3) & 0x7F));
    return *this;
}
CodeGenerator& CodeGenerator::stp_fp(QReg rt1, QReg rt2, Mem mem) {
    if (mem.mode == MemMode::Pre)
        emit(ldst::encode_stp_q_ldstpair_pre(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else if (mem.mode == MemMode::Post)
        emit(ldst::encode_stp_q_ldstpair_post(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    else
        emit(ldst::encode_stp_q_ldstpair_off(rt1.idx, mem.base_idx, rt2.idx, (uint32_t)(mem.offset >> 4) & 0x7F));
    return *this;
}

// === FP Unscaled Load/Store ===
CodeGenerator& CodeGenerator::ldur_fp(SReg rt, Mem mem) {
    emit(ldst::encode_ldur_s_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur_fp(DReg rt, Mem mem) {
    emit(ldst::encode_ldur_d_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::ldur_fp(QReg rt, Mem mem) {
    emit(ldst::encode_ldur_q_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur_fp(SReg rt, Mem mem) {
    emit(ldst::encode_stur_s_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur_fp(DReg rt, Mem mem) {
    emit(ldst::encode_stur_d_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}
CodeGenerator& CodeGenerator::stur_fp(QReg rt, Mem mem) {
    emit(ldst::encode_stur_q_ldst_unscaled(rt.idx, mem.base_idx, mem.offset));
    return *this;
}

// === System Instructions ===
CodeGenerator& CodeGenerator::hvc(uint16_t imm16) {
    emit(control::encode_hvc_ex_exception(imm16));
    return *this;
}
CodeGenerator& CodeGenerator::smc(uint16_t imm16) {
    emit(control::encode_smc_ex_exception(imm16));
    return *this;
}
CodeGenerator& CodeGenerator::dcps1(uint16_t imm16) {
    emit(control::encode_dcps1_dc_exception(imm16));
    return *this;
}
CodeGenerator& CodeGenerator::dcps2(uint16_t imm16) {
    emit(control::encode_dcps2_dc_exception(imm16));
    return *this;
}
CodeGenerator& CodeGenerator::dcps3(uint16_t imm16) {
    emit(control::encode_dcps3_dc_exception(imm16));
    return *this;
}
CodeGenerator& CodeGenerator::hint(uint8_t imm7) {
    emit(control::encode_hint_hm_hints(imm7 & 0x7, (imm7 >> 3) & 0xF));
    return *this;
}
CodeGenerator& CodeGenerator::sys(uint8_t op1, uint8_t CRn, uint8_t CRm, uint8_t op2, XReg rt) {
    emit(control::encode_sys_cr_systeminstrs(rt.idx, op2, CRm, CRn, op1));
    return *this;
}
CodeGenerator& CodeGenerator::prfum(uint8_t prfop, Mem mem) {
    emit(ldst::encode_prfum_p_ldst_unscaled(prfop, mem.base_idx, mem.offset));
    return *this;
}

// === BFloat16 Multiply-Add ===
CodeGenerator& CodeGenerator::bfmlal(VArr vd, VArr vn, VArr vm) {
    emit(simd_dp::encode_bfmlal_asimdsame2_f_(vd.idx, vn.idx, vm.idx, vd.Q()));
    return *this;
}

// === Complex FP ===
CodeGenerator& CodeGenerator::fcadd(VArr vd, VArr vn, VArr vm, uint8_t rot) {
    emit(simd_dp::encode_fcadd_asimdsame2_c(vd.idx, vn.idx, rot, vm.idx, vd.size(), vd.Q()));
    return *this;
}
CodeGenerator& CodeGenerator::fcmla(VArr vd, VArr vn, VArr vm, uint8_t rot) {
    emit(simd_dp::encode_fcmla_asimdsame2_c(vd.idx, vn.idx, rot, vm.idx, vd.size(), vd.Q()));
    return *this;
}

// === PAC Extras ===
CodeGenerator& CodeGenerator::xpacd(XReg rd) {
    emit(dpreg::encode_xpacd_64z_dp_1src(rd.idx));
    return *this;
}
CodeGenerator& CodeGenerator::xpaci(XReg rd) {
    emit(dpreg::encode_xpaci_64z_dp_1src(rd.idx));
    return *this;
}
CodeGenerator& CodeGenerator::xpaclri() {
    emit(control::encode_xpaclri_hi_hints());
    return *this;
}

// === GP Abs/Count (ARMv9) ===
CodeGenerator& CodeGenerator::abs(XReg rd, XReg rn) {
    emit(dpreg::encode_abs_64_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::abs(WReg rd, WReg rn) {
    emit(dpreg::encode_abs_32_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cnt(XReg rd, XReg rn) {
    emit(dpreg::encode_cnt_64_dp_1src(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cnt(WReg rd, WReg rn) {
    emit(dpreg::encode_cnt_32_dp_1src(rd.idx, rn.idx));
    return *this;
}

// === Flag Manipulation ===
CodeGenerator& CodeGenerator::setf8(WReg rn) {
    emit(dpreg::encode_setf8_only_setf(rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::setf16(WReg rn) {
    emit(dpreg::encode_setf16_only_setf(rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::rmif(XReg rn, uint8_t imm6, uint8_t mask) {
    emit(dpreg::encode_rmif_only_rmif(mask & 0xF, rn.idx, imm6 & 0x3F));
    return *this;
}

// === FP Immediate ===
CodeGenerator& CodeGenerator::fmov(SReg rd, uint8_t imm8) {
    emit(simd_dp::encode_fmov_s_floatimm(rd.idx, imm8));
    return *this;
}
CodeGenerator& CodeGenerator::fmov(DReg rd, uint8_t imm8) {
    emit(simd_dp::encode_fmov_d_floatimm(rd.idx, imm8));
    return *this;
}

// === Load/Store Register Offset ===
// option=0b011 (LSL), S=shift flag
CodeGenerator& CodeGenerator::ldr_reg(XReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldr_64_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldr_reg(WReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldr_32_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::str_reg(XReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_str_64_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::str_reg(WReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_str_32_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrb_reg(WReg rt, XReg rn, XReg rm) {
    emit(ldst::encode_ldrb_32b_ldst_regoff(rt.idx, rn.idx, 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrh_reg(WReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldrh_32_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::strb_reg(WReg rt, XReg rn, XReg rm) {
    emit(ldst::encode_strb_32b_ldst_regoff(rt.idx, rn.idx, 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::strh_reg(WReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_strh_32_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrsb_reg(XReg rt, XReg rn, XReg rm) {
    emit(ldst::encode_ldrsb_64b_ldst_regoff(rt.idx, rn.idx, 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrsb_reg(WReg rt, XReg rn, XReg rm) {
    emit(ldst::encode_ldrsb_32b_ldst_regoff(rt.idx, rn.idx, 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrsh_reg(XReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldrsh_64_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrsh_reg(WReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldrsh_32_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldrsw_reg(XReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldrsw_64_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldr_reg(SReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldr_s_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldr_reg(DReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldr_d_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::ldr_reg(QReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_ldr_q_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::str_reg(SReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_str_s_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::str_reg(DReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_str_d_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::str_reg(QReg rt, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_str_q_ldst_regoff(rt.idx, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::prfm_reg(uint8_t prfop, XReg rn, XReg rm, bool shift) {
    emit(ldst::encode_prfm_p_ldst_regoff(prfop, rn.idx, shift ? 1 : 0, 0b011, rm.idx));
    return *this;
}

// === Scalar SIMD (D register, 64-bit) ===
CodeGenerator& CodeGenerator::add_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_add_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::sub_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_sub_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cmeq_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_cmeq_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cmge_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_cmge_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cmgt_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_cmgt_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cmhi_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_cmhi_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::cmhs_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_cmhs_asisdsame_only(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::abs_d(DReg rd, DReg rn) {
    emit(simd_dp::encode_abs_asisdmisc_r(rd.idx, rn.idx));
    return *this;
}
CodeGenerator& CodeGenerator::neg_d(DReg rd, DReg rn) {
    emit(simd_dp::encode_neg_asisdmisc_r(rd.idx, rn.idx));
    return *this;
}

// === Scalar SIMD Saturating ===
CodeGenerator& CodeGenerator::sqadd_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_sqadd_asisdsame_only(rd.idx, rn.idx, rm.idx, 3));  // size=3 for 64-bit
    return *this;
}
CodeGenerator& CodeGenerator::sqsub_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_sqsub_asisdsame_only(rd.idx, rn.idx, rm.idx, 3));
    return *this;
}
CodeGenerator& CodeGenerator::uqadd_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_uqadd_asisdsame_only(rd.idx, rn.idx, rm.idx, 3));
    return *this;
}
CodeGenerator& CodeGenerator::uqsub_d(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_uqsub_asisdsame_only(rd.idx, rn.idx, rm.idx, 3));
    return *this;
}

// === FP Scalar Min/Max (NaN) ===
CodeGenerator& CodeGenerator::fmaxnm(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fmaxnm_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fmaxnm(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fmaxnm_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fminnm(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fminnm_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}
CodeGenerator& CodeGenerator::fminnm(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fminnm_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
}

// === FP Vector Sqrt ===
CodeGenerator& CodeGenerator::fsqrt(VArr vd, VArr vn) {
    emit(simd_dp::encode_fsqrt_asimdmisc_r(vd.idx, vn.idx, vd.size() - 2, vd.Q()));
    return *this;
}

// === SIMD Across-Lanes FP Pairwise ===
CodeGenerator& CodeGenerator::faddp(SReg rd, VArr vn) {
    emit(simd_dp::encode_faddp_asisdpair_only_sd(rd.idx, vn.idx, 0));  // sz=0 for single
    return *this;
}

// === Load/Store PAC ===
CodeGenerator& CodeGenerator::ldraa(XReg rt, XReg rn, int32_t imm) {
    int32_t simm = imm >> 3;  // scaled by 8
    uint32_t S = (simm < 0) ? 1 : 0;
    emit(ldst::encode_ldraa_64_ldst_pac(rt.idx, rn.idx, simm & 0x1FF, S));
    return *this;
}
CodeGenerator& CodeGenerator::ldrab(XReg rt, XReg rn, int32_t imm) {
    int32_t simm = imm >> 3;
    uint32_t S = (simm < 0) ? 1 : 0;
    emit(ldst::encode_ldrab_64_ldst_pac(rt.idx, rn.idx, simm & 0x1FF, S));
    return *this;
}
CodeGenerator& CodeGenerator::emit_raw(uint32_t insn) {
    emit(insn);
    return *this;
}

// === Function prolog / epilog ===
namespace {
void emit_sp_adjust(CodeGenerator& cg, uint32_t bytes, bool subtract) {
    // AArch64 add/sub imm supports 12-bit imm optionally shifted left by 12.
    // Handle 0 .. 0xFFF (direct) and 0x1000 .. 0xFFF000 (shift) and mixed.
    uint32_t lo = bytes & 0xFFFu;
    uint32_t hi = bytes >> 12;
    if (hi) {
        if (subtract) cg.sub(sp, sp, hi & 0xFFFu, /*lsl12=*/true);
        else          cg.add(sp, sp, hi & 0xFFFu, /*lsl12=*/true);
    }
    if (lo) {
        if (subtract) cg.sub(sp, sp, lo, /*lsl12=*/false);
        else          cg.add(sp, sp, lo, /*lsl12=*/false);
    }
}
} // namespace

CodeGenerator& CodeGenerator::emit_prolog(const PrologSpec& spec) {
    if (spec.chain_fp_lr) {
        stp(XReg{29}, XReg{30}, pre(sp, -16));
        mov(XReg{29}, sp);
    }
    for (uint8_t i = 0; i < spec.num_pairs; ++i) {
        stp(spec.saved_pairs[i].a, spec.saved_pairs[i].b, pre(sp, -16));
    }
    for (uint8_t i = 0; i < spec.num_dpairs; ++i) {
        stp(spec.saved_dpairs[i].a, spec.saved_dpairs[i].b, pre(sp, -16));
    }
    if (spec.frame_size) emit_sp_adjust(*this, spec.frame_size, /*subtract=*/true);
    return *this;
}

CodeGenerator& CodeGenerator::emit_epilog(const PrologSpec& spec) {
    if (spec.frame_size) emit_sp_adjust(*this, spec.frame_size, /*subtract=*/false);
    // Reverse order: SIMD pairs first (pushed last), then X pairs.
    for (int i = static_cast<int>(spec.num_dpairs) - 1; i >= 0; --i) {
        ldp(spec.saved_dpairs[i].a, spec.saved_dpairs[i].b, post(sp, 16));
    }
    for (int i = static_cast<int>(spec.num_pairs) - 1; i >= 0; --i) {
        ldp(spec.saved_pairs[i].a, spec.saved_pairs[i].b, post(sp, 16));
    }
    if (spec.chain_fp_lr) {
        ldp(XReg{29}, XReg{30}, post(sp, 16));
    }
    return *this;
}

} // namespace codegen
} // namespace veda64
