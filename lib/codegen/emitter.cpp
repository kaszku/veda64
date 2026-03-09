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

CodeGenerator& CodeGenerator::csel(XReg rd, XReg rn, XReg rm, Condition cc) {
    emit(dpreg::encode_csel_64_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
    return *this;
}

CodeGenerator& CodeGenerator::csel(WReg rd, WReg rn, WReg rm, Condition cc) {
    emit(dpreg::encode_csel_32_condsel(rd.idx, rn.idx, static_cast<uint32_t>(cc), rm.idx));
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
    return *this;
}

// === Scalar FP ===
CodeGenerator& CodeGenerator::fadd(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fadd_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fadd(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fadd_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fsub(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fsub_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fsub(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fsub_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fmul(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fmul_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fmul(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fmul_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fdiv(SReg rd, SReg rn, SReg rm) {
    emit(simd_dp::encode_fdiv_s_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
    return *this;
}

CodeGenerator& CodeGenerator::fdiv(DReg rd, DReg rn, DReg rm) {
    emit(simd_dp::encode_fdiv_d_floatdp2(rd.idx, rn.idx, rm.idx));
    return *this;
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

} // namespace codegen
} // namespace veda64
