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

} // namespace codegen
} // namespace veda64
