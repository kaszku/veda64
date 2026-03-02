// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_add_32_addsub_imm() {
    uint32_t insn = 0x11000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
    std::cout << "  add_32_addsub_imm: " << result->to_string() << std::endl;
}

void test_add_64_addsub_imm() {
    uint32_t insn = 0x91000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  add_64_addsub_imm: " << result->to_string() << std::endl;
}

void test_addg_64_addsub_immtags() {
    uint32_t insn = 0x91800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADDG);
    std::cout << "  addg_64_addsub_immtags: " << result->to_string() << std::endl;
}

void test_adds_32s_addsub_imm() {
    uint32_t insn = 0x31000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  adds_32s_addsub_imm: " << result->to_string() << std::endl;
}

void test_adds_64s_addsub_imm() {
    uint32_t insn = 0xB1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  adds_64s_addsub_imm: " << result->to_string() << std::endl;
}

void test_adr_only_pcreladdr() {
    uint32_t insn = 0x10000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADR);
    std::cout << "  adr_only_pcreladdr: " << result->to_string() << std::endl;
}

void test_adrp_only_pcreladdr() {
    uint32_t insn = 0x90000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADRP);
    std::cout << "  adrp_only_pcreladdr: " << result->to_string() << std::endl;
}

void test_and_32_log_imm() {
    uint32_t insn = 0x12000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  and_32_log_imm: " << result->to_string() << std::endl;
}

void test_and_64_log_imm() {
    uint32_t insn = 0x92000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  and_64_log_imm: " << result->to_string() << std::endl;
}

void test_ands_32s_log_imm() {
    uint32_t insn = 0x72000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ands_32s_log_imm: " << result->to_string() << std::endl;
}

void test_ands_64s_log_imm() {
    uint32_t insn = 0xF2000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ands_64s_log_imm: " << result->to_string() << std::endl;
}

void test_asr_sbfm_32m_bitfield() {
    uint32_t insn = 0x13007C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  asr_sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_asr_sbfm_64m_bitfield() {
    uint32_t insn = 0x9340FC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  asr_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_autiasppc_only_dp_1src_imm() {
    uint32_t insn = 0xF380001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::AUTIASPPC);
    std::cout << "  autiasppc_only_dp_1src_imm: " << result->to_string() << std::endl;
}

void test_autibsppc_only_dp_1src_imm() {
    uint32_t insn = 0xF3A0001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::AUTIBSPPC);
    std::cout << "  autibsppc_only_dp_1src_imm: " << result->to_string() << std::endl;
}

void test_bfc_bfm_32m_bitfield() {
    uint32_t insn = 0x330003E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfc_bfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_bfc_bfm_64m_bitfield() {
    uint32_t insn = 0xB34003E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfc_bfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_bfi_bfm_32m_bitfield() {
    uint32_t insn = 0x33000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfi_bfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_bfi_bfm_64m_bitfield() {
    uint32_t insn = 0xB3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfi_bfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_bfm_32m_bitfield() {
    uint32_t insn = 0x33000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_bfm_64m_bitfield() {
    uint32_t insn = 0xB3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_bfxil_bfm_32m_bitfield() {
    uint32_t insn = 0x33000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfxil_bfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_bfxil_bfm_64m_bitfield() {
    uint32_t insn = 0xB3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  bfxil_bfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_cmn_adds_32s_addsub_imm() {
    uint32_t insn = 0x3100001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cmn_adds_32s_addsub_imm: " << result->to_string() << std::endl;
}

void test_cmn_adds_64s_addsub_imm() {
    uint32_t insn = 0xB100001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cmn_adds_64s_addsub_imm: " << result->to_string() << std::endl;
}

void test_cmp_subs_32s_addsub_imm() {
    uint32_t insn = 0x7100001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cmp_subs_32s_addsub_imm: " << result->to_string() << std::endl;
}

void test_cmp_subs_64s_addsub_imm() {
    uint32_t insn = 0xF100001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cmp_subs_64s_addsub_imm: " << result->to_string() << std::endl;
}

void test_eor_32_log_imm() {
    uint32_t insn = 0x52000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::EOR);
    std::cout << "  eor_32_log_imm: " << result->to_string() << std::endl;
}

void test_eor_64_log_imm() {
    uint32_t insn = 0xD2000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::EOR);
    std::cout << "  eor_64_log_imm: " << result->to_string() << std::endl;
}

void test_extr_32_extract() {
    uint32_t insn = 0x13800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  extr_32_extract: " << result->to_string() << std::endl;
}

void test_extr_64_extract() {
    uint32_t insn = 0x93C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  extr_64_extract: " << result->to_string() << std::endl;
}

void test_lsl_ubfm_32m_bitfield() {
    uint32_t insn = 0x53000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  lsl_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_lsl_ubfm_64m_bitfield() {
    uint32_t insn = 0xD3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  lsl_ubfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_lsr_ubfm_32m_bitfield() {
    uint32_t insn = 0x53007C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  lsr_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_lsr_ubfm_64m_bitfield() {
    uint32_t insn = 0xD340FC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  lsr_ubfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_mov_add_32_addsub_imm() {
    uint32_t insn = 0x11000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  mov_add_32_addsub_imm: " << result->to_string() << std::endl;
}

void test_mov_add_64_addsub_imm() {
    uint32_t insn = 0x91000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  mov_add_64_addsub_imm: " << result->to_string() << std::endl;
}

void test_mov_movn_32_movewide() {
    uint32_t insn = 0x12800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_movn_32_movewide: " << result->to_string() << std::endl;
}

void test_mov_movn_64_movewide() {
    uint32_t insn = 0x92800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_movn_64_movewide: " << result->to_string() << std::endl;
}

void test_mov_movz_32_movewide() {
    uint32_t insn = 0x52800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_movz_32_movewide: " << result->to_string() << std::endl;
}

void test_mov_movz_64_movewide() {
    uint32_t insn = 0xD2800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_movz_64_movewide: " << result->to_string() << std::endl;
}

void test_mov_orr_32_log_imm() {
    uint32_t insn = 0x320003E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_orr_32_log_imm: " << result->to_string() << std::endl;
}

void test_mov_orr_64_log_imm() {
    uint32_t insn = 0xB20003E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mov_orr_64_log_imm: " << result->to_string() << std::endl;
}

void test_movk_32_movewide() {
    uint32_t insn = 0x72800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVK);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    std::cout << "  movk_32_movewide: " << result->to_string() << std::endl;
}

void test_movk_64_movewide() {
    uint32_t insn = 0xF2800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVK);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    std::cout << "  movk_64_movewide: " << result->to_string() << std::endl;
}

void test_movn_32_movewide() {
    uint32_t insn = 0x12800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  movn_32_movewide: " << result->to_string() << std::endl;
}

void test_movn_64_movewide() {
    uint32_t insn = 0x92800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  movn_64_movewide: " << result->to_string() << std::endl;
}

void test_movz_32_movewide() {
    uint32_t insn = 0x52800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  movz_32_movewide: " << result->to_string() << std::endl;
}

void test_movz_64_movewide() {
    uint32_t insn = 0xD2800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  movz_64_movewide: " << result->to_string() << std::endl;
}

void test_orr_32_log_imm() {
    uint32_t insn = 0x32000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  orr_32_log_imm: " << result->to_string() << std::endl;
}

void test_orr_64_log_imm() {
    uint32_t insn = 0xB2000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  orr_64_log_imm: " << result->to_string() << std::endl;
}

void test_ror_extr_32_extract() {
    uint32_t insn = 0x13800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ror_extr_32_extract: " << result->to_string() << std::endl;
}

void test_ror_extr_64_extract() {
    uint32_t insn = 0x93C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ror_extr_64_extract: " << result->to_string() << std::endl;
}

void test_sbfiz_sbfm_32m_bitfield() {
    uint32_t insn = 0x13000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfiz_sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_sbfiz_sbfm_64m_bitfield() {
    uint32_t insn = 0x93400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfiz_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_sbfm_32m_bitfield() {
    uint32_t insn = 0x13000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_sbfm_64m_bitfield() {
    uint32_t insn = 0x93400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_sbfx_sbfm_32m_bitfield() {
    uint32_t insn = 0x13000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfx_sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_sbfx_sbfm_64m_bitfield() {
    uint32_t insn = 0x93400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sbfx_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_smax_32_minmax_imm() {
    uint32_t insn = 0x11C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    std::cout << "  smax_32_minmax_imm: " << result->to_string() << std::endl;
}

void test_smax_64_minmax_imm() {
    uint32_t insn = 0x91C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    std::cout << "  smax_64_minmax_imm: " << result->to_string() << std::endl;
}

void test_smin_32_minmax_imm() {
    uint32_t insn = 0x11C80000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    std::cout << "  smin_32_minmax_imm: " << result->to_string() << std::endl;
}

void test_smin_64_minmax_imm() {
    uint32_t insn = 0x91C80000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    std::cout << "  smin_64_minmax_imm: " << result->to_string() << std::endl;
}

void test_sub_32_addsub_imm() {
    uint32_t insn = 0x51000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_32_addsub_imm: " << result->to_string() << std::endl;
}

void test_sub_64_addsub_imm() {
    uint32_t insn = 0xD1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_64_addsub_imm: " << result->to_string() << std::endl;
}

void test_subg_64_addsub_immtags() {
    uint32_t insn = 0xD1800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUBG);
    std::cout << "  subg_64_addsub_immtags: " << result->to_string() << std::endl;
}

void test_subs_32s_addsub_imm() {
    uint32_t insn = 0x71000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  subs_32s_addsub_imm: " << result->to_string() << std::endl;
}

void test_subs_64s_addsub_imm() {
    uint32_t insn = 0xF1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  subs_64s_addsub_imm: " << result->to_string() << std::endl;
}

void test_sxtb_sbfm_32m_bitfield() {
    uint32_t insn = 0x13001C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sxtb_sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_sxtb_sbfm_64m_bitfield() {
    uint32_t insn = 0x93401C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sxtb_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_sxth_sbfm_32m_bitfield() {
    uint32_t insn = 0x13003C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sxth_sbfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_sxth_sbfm_64m_bitfield() {
    uint32_t insn = 0x93403C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sxth_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_sxtw_sbfm_64m_bitfield() {
    uint32_t insn = 0x93407C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sxtw_sbfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_tst_ands_32s_log_imm() {
    uint32_t insn = 0x7200001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  tst_ands_32s_log_imm: " << result->to_string() << std::endl;
}

void test_tst_ands_64s_log_imm() {
    uint32_t insn = 0xF200001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  tst_ands_64s_log_imm: " << result->to_string() << std::endl;
}

void test_ubfiz_ubfm_32m_bitfield() {
    uint32_t insn = 0x53000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfiz_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_ubfiz_ubfm_64m_bitfield() {
    uint32_t insn = 0xD3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfiz_ubfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_ubfm_32m_bitfield() {
    uint32_t insn = 0x53000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_ubfm_64m_bitfield() {
    uint32_t insn = 0xD3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_ubfx_ubfm_32m_bitfield() {
    uint32_t insn = 0x53000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfx_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_ubfx_ubfm_64m_bitfield() {
    uint32_t insn = 0xD3400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ubfx_ubfm_64m_bitfield: " << result->to_string() << std::endl;
}

void test_umax_32u_minmax_imm() {
    uint32_t insn = 0x11C40000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    std::cout << "  umax_32u_minmax_imm: " << result->to_string() << std::endl;
}

void test_umax_64u_minmax_imm() {
    uint32_t insn = 0x91C40000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    std::cout << "  umax_64u_minmax_imm: " << result->to_string() << std::endl;
}

void test_umin_32u_minmax_imm() {
    uint32_t insn = 0x11CC0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    std::cout << "  umin_32u_minmax_imm: " << result->to_string() << std::endl;
}

void test_umin_64u_minmax_imm() {
    uint32_t insn = 0x91CC0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    std::cout << "  umin_64u_minmax_imm: " << result->to_string() << std::endl;
}

void test_uxtb_ubfm_32m_bitfield() {
    uint32_t insn = 0x53001C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  uxtb_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

void test_uxth_ubfm_32m_bitfield() {
    uint32_t insn = 0x53003C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  uxth_ubfm_32m_bitfield: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running dpimm encoding tests (87 encodings)..." << std::endl;
    int failed = 0;

    try { test_add_32_addsub_imm(); } catch (...) { std::cerr << "FAIL: add_32_addsub_imm" << std::endl; failed++; }
    try { test_add_64_addsub_imm(); } catch (...) { std::cerr << "FAIL: add_64_addsub_imm" << std::endl; failed++; }
    try { test_addg_64_addsub_immtags(); } catch (...) { std::cerr << "FAIL: addg_64_addsub_immtags" << std::endl; failed++; }
    try { test_adds_32s_addsub_imm(); } catch (...) { std::cerr << "FAIL: adds_32s_addsub_imm" << std::endl; failed++; }
    try { test_adds_64s_addsub_imm(); } catch (...) { std::cerr << "FAIL: adds_64s_addsub_imm" << std::endl; failed++; }
    try { test_adr_only_pcreladdr(); } catch (...) { std::cerr << "FAIL: adr_only_pcreladdr" << std::endl; failed++; }
    try { test_adrp_only_pcreladdr(); } catch (...) { std::cerr << "FAIL: adrp_only_pcreladdr" << std::endl; failed++; }
    try { test_and_32_log_imm(); } catch (...) { std::cerr << "FAIL: and_32_log_imm" << std::endl; failed++; }
    try { test_and_64_log_imm(); } catch (...) { std::cerr << "FAIL: and_64_log_imm" << std::endl; failed++; }
    try { test_ands_32s_log_imm(); } catch (...) { std::cerr << "FAIL: ands_32s_log_imm" << std::endl; failed++; }
    try { test_ands_64s_log_imm(); } catch (...) { std::cerr << "FAIL: ands_64s_log_imm" << std::endl; failed++; }
    try { test_asr_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: asr_sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_asr_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: asr_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_autiasppc_only_dp_1src_imm(); } catch (...) { std::cerr << "FAIL: autiasppc_only_dp_1src_imm" << std::endl; failed++; }
    try { test_autibsppc_only_dp_1src_imm(); } catch (...) { std::cerr << "FAIL: autibsppc_only_dp_1src_imm" << std::endl; failed++; }
    try { test_bfc_bfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: bfc_bfm_32m_bitfield" << std::endl; failed++; }
    try { test_bfc_bfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: bfc_bfm_64m_bitfield" << std::endl; failed++; }
    try { test_bfi_bfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: bfi_bfm_32m_bitfield" << std::endl; failed++; }
    try { test_bfi_bfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: bfi_bfm_64m_bitfield" << std::endl; failed++; }
    try { test_bfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: bfm_32m_bitfield" << std::endl; failed++; }
    try { test_bfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: bfm_64m_bitfield" << std::endl; failed++; }
    try { test_bfxil_bfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: bfxil_bfm_32m_bitfield" << std::endl; failed++; }
    try { test_bfxil_bfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: bfxil_bfm_64m_bitfield" << std::endl; failed++; }
    try { test_cmn_adds_32s_addsub_imm(); } catch (...) { std::cerr << "FAIL: cmn_adds_32s_addsub_imm" << std::endl; failed++; }
    try { test_cmn_adds_64s_addsub_imm(); } catch (...) { std::cerr << "FAIL: cmn_adds_64s_addsub_imm" << std::endl; failed++; }
    try { test_cmp_subs_32s_addsub_imm(); } catch (...) { std::cerr << "FAIL: cmp_subs_32s_addsub_imm" << std::endl; failed++; }
    try { test_cmp_subs_64s_addsub_imm(); } catch (...) { std::cerr << "FAIL: cmp_subs_64s_addsub_imm" << std::endl; failed++; }
    try { test_eor_32_log_imm(); } catch (...) { std::cerr << "FAIL: eor_32_log_imm" << std::endl; failed++; }
    try { test_eor_64_log_imm(); } catch (...) { std::cerr << "FAIL: eor_64_log_imm" << std::endl; failed++; }
    try { test_extr_32_extract(); } catch (...) { std::cerr << "FAIL: extr_32_extract" << std::endl; failed++; }
    try { test_extr_64_extract(); } catch (...) { std::cerr << "FAIL: extr_64_extract" << std::endl; failed++; }
    try { test_lsl_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: lsl_ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_lsl_ubfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: lsl_ubfm_64m_bitfield" << std::endl; failed++; }
    try { test_lsr_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: lsr_ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_lsr_ubfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: lsr_ubfm_64m_bitfield" << std::endl; failed++; }
    try { test_mov_add_32_addsub_imm(); } catch (...) { std::cerr << "FAIL: mov_add_32_addsub_imm" << std::endl; failed++; }
    try { test_mov_add_64_addsub_imm(); } catch (...) { std::cerr << "FAIL: mov_add_64_addsub_imm" << std::endl; failed++; }
    try { test_mov_movn_32_movewide(); } catch (...) { std::cerr << "FAIL: mov_movn_32_movewide" << std::endl; failed++; }
    try { test_mov_movn_64_movewide(); } catch (...) { std::cerr << "FAIL: mov_movn_64_movewide" << std::endl; failed++; }
    try { test_mov_movz_32_movewide(); } catch (...) { std::cerr << "FAIL: mov_movz_32_movewide" << std::endl; failed++; }
    try { test_mov_movz_64_movewide(); } catch (...) { std::cerr << "FAIL: mov_movz_64_movewide" << std::endl; failed++; }
    try { test_mov_orr_32_log_imm(); } catch (...) { std::cerr << "FAIL: mov_orr_32_log_imm" << std::endl; failed++; }
    try { test_mov_orr_64_log_imm(); } catch (...) { std::cerr << "FAIL: mov_orr_64_log_imm" << std::endl; failed++; }
    try { test_movk_32_movewide(); } catch (...) { std::cerr << "FAIL: movk_32_movewide" << std::endl; failed++; }
    try { test_movk_64_movewide(); } catch (...) { std::cerr << "FAIL: movk_64_movewide" << std::endl; failed++; }
    try { test_movn_32_movewide(); } catch (...) { std::cerr << "FAIL: movn_32_movewide" << std::endl; failed++; }
    try { test_movn_64_movewide(); } catch (...) { std::cerr << "FAIL: movn_64_movewide" << std::endl; failed++; }
    try { test_movz_32_movewide(); } catch (...) { std::cerr << "FAIL: movz_32_movewide" << std::endl; failed++; }
    try { test_movz_64_movewide(); } catch (...) { std::cerr << "FAIL: movz_64_movewide" << std::endl; failed++; }
    try { test_orr_32_log_imm(); } catch (...) { std::cerr << "FAIL: orr_32_log_imm" << std::endl; failed++; }
    try { test_orr_64_log_imm(); } catch (...) { std::cerr << "FAIL: orr_64_log_imm" << std::endl; failed++; }
    try { test_ror_extr_32_extract(); } catch (...) { std::cerr << "FAIL: ror_extr_32_extract" << std::endl; failed++; }
    try { test_ror_extr_64_extract(); } catch (...) { std::cerr << "FAIL: ror_extr_64_extract" << std::endl; failed++; }
    try { test_sbfiz_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfiz_sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_sbfiz_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfiz_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_sbfx_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfx_sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_sbfx_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sbfx_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_smax_32_minmax_imm(); } catch (...) { std::cerr << "FAIL: smax_32_minmax_imm" << std::endl; failed++; }
    try { test_smax_64_minmax_imm(); } catch (...) { std::cerr << "FAIL: smax_64_minmax_imm" << std::endl; failed++; }
    try { test_smin_32_minmax_imm(); } catch (...) { std::cerr << "FAIL: smin_32_minmax_imm" << std::endl; failed++; }
    try { test_smin_64_minmax_imm(); } catch (...) { std::cerr << "FAIL: smin_64_minmax_imm" << std::endl; failed++; }
    try { test_sub_32_addsub_imm(); } catch (...) { std::cerr << "FAIL: sub_32_addsub_imm" << std::endl; failed++; }
    try { test_sub_64_addsub_imm(); } catch (...) { std::cerr << "FAIL: sub_64_addsub_imm" << std::endl; failed++; }
    try { test_subg_64_addsub_immtags(); } catch (...) { std::cerr << "FAIL: subg_64_addsub_immtags" << std::endl; failed++; }
    try { test_subs_32s_addsub_imm(); } catch (...) { std::cerr << "FAIL: subs_32s_addsub_imm" << std::endl; failed++; }
    try { test_subs_64s_addsub_imm(); } catch (...) { std::cerr << "FAIL: subs_64s_addsub_imm" << std::endl; failed++; }
    try { test_sxtb_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: sxtb_sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_sxtb_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sxtb_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_sxth_sbfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: sxth_sbfm_32m_bitfield" << std::endl; failed++; }
    try { test_sxth_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sxth_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_sxtw_sbfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: sxtw_sbfm_64m_bitfield" << std::endl; failed++; }
    try { test_tst_ands_32s_log_imm(); } catch (...) { std::cerr << "FAIL: tst_ands_32s_log_imm" << std::endl; failed++; }
    try { test_tst_ands_64s_log_imm(); } catch (...) { std::cerr << "FAIL: tst_ands_64s_log_imm" << std::endl; failed++; }
    try { test_ubfiz_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfiz_ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_ubfiz_ubfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfiz_ubfm_64m_bitfield" << std::endl; failed++; }
    try { test_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_ubfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfm_64m_bitfield" << std::endl; failed++; }
    try { test_ubfx_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfx_ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_ubfx_ubfm_64m_bitfield(); } catch (...) { std::cerr << "FAIL: ubfx_ubfm_64m_bitfield" << std::endl; failed++; }
    try { test_umax_32u_minmax_imm(); } catch (...) { std::cerr << "FAIL: umax_32u_minmax_imm" << std::endl; failed++; }
    try { test_umax_64u_minmax_imm(); } catch (...) { std::cerr << "FAIL: umax_64u_minmax_imm" << std::endl; failed++; }
    try { test_umin_32u_minmax_imm(); } catch (...) { std::cerr << "FAIL: umin_32u_minmax_imm" << std::endl; failed++; }
    try { test_umin_64u_minmax_imm(); } catch (...) { std::cerr << "FAIL: umin_64u_minmax_imm" << std::endl; failed++; }
    try { test_uxtb_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: uxtb_ubfm_32m_bitfield" << std::endl; failed++; }
    try { test_uxth_ubfm_32m_bitfield(); } catch (...) { std::cerr << "FAIL: uxth_ubfm_32m_bitfield" << std::endl; failed++; }

    std::cout << (87 - failed) << " / 87 passed" << std::endl;
    return failed;
}
