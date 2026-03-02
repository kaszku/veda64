// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_asisdmisc_r() {
    uint32_t insn = 0x5EE0B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ABS);
    std::cout << "  abs_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_abs_asimdmisc_r() {
    uint32_t insn = 0x0E20B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ABS);
    std::cout << "  abs_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_add_asisdsame_only() {
    uint32_t insn = 0x5EE08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_asisdsame_only: " << result->to_string() << std::endl;
}

void test_add_asimdsame_only() {
    uint32_t insn = 0x0E208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_asimdsame_only: " << result->to_string() << std::endl;
}

void test_addhn_asimddiff_n() {
    uint32_t insn = 0x0E204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addhn_asimddiff_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADDHN);
    std::cout << "  addhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_addp_asisdpair_only() {
    uint32_t insn = 0x5EF1B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addp_asisdpair_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADDP);
    std::cout << "  addp_asisdpair_only: " << result->to_string() << std::endl;
}

void test_addp_asimdsame_only() {
    uint32_t insn = 0x0E20BC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADDP);
    std::cout << "  addp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_addv_asimdall_only() {
    uint32_t insn = 0x0E31B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ADDV);
    std::cout << "  addv_asimdall_only: " << result->to_string() << std::endl;
}

void test_aesd_b_cryptoaes() {
    uint32_t insn = 0x4E285800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesd_b_cryptoaes" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::AESD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  aesd_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aese_b_cryptoaes() {
    uint32_t insn = 0x4E284800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aese_b_cryptoaes" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::AESE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  aese_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesimc_b_cryptoaes() {
    uint32_t insn = 0x4E287800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesimc_b_cryptoaes" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::AESIMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  aesimc_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesmc_b_cryptoaes() {
    uint32_t insn = 0x4E286800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesmc_b_cryptoaes" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::AESMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  aesmc_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_and_asimdsame_only() {
    uint32_t insn = 0x0E201C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_asimdsame_only" << std::endl; return; }
    std::cout << "  and_asimdsame_only: " << result->to_string() << std::endl;
}

void test_bcax_vvv16_crypto4() {
    uint32_t insn = 0xCE200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bcax_vvv16_crypto4" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BCAX);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  bcax_vvv16_crypto4: " << result->to_string() << std::endl;
}

void test_bf1cvtl_asimdmisc_v() {
    uint32_t insn = 0x2EA17800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf1cvtl_asimdmisc_v" << std::endl; return; }
    std::cout << "  bf1cvtl_asimdmisc_v: " << result->to_string() << std::endl;
}

void test_bf2cvtl_asimdmisc_v() {
    uint32_t insn = 0x2EE17800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf2cvtl_asimdmisc_v" << std::endl; return; }
    std::cout << "  bf2cvtl_asimdmisc_v: " << result->to_string() << std::endl;
}

void test_bfcvt_bs_floatdp1() {
    uint32_t insn = 0x1E634000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvt_bs_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFCVT);
    std::cout << "  bfcvt_bs_floatdp1: " << result->to_string() << std::endl;
}

void test_bfcvtn_asimdmisc_4s() {
    uint32_t insn = 0x0EA16800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvtn_asimdmisc_4s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFCVTN);
    std::cout << "  bfcvtn_asimdmisc_4s: " << result->to_string() << std::endl;
}

void test_bfdot_asimdelem_e() {
    uint32_t insn = 0x0F40F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfdot_asimdelem_e" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFDOT);
    std::cout << "  bfdot_asimdelem_e: " << result->to_string() << std::endl;
}

void test_bfdot_asimdsame2_d() {
    uint32_t insn = 0x2E40FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfdot_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFDOT);
    std::cout << "  bfdot_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_bfmlal_asimdelem_f() {
    uint32_t insn = 0x0FC0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlal_asimdelem_f" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  bfmlal_asimdelem_f: " << result->to_string() << std::endl;
}

void test_bfmlal_asimdsame2_f_() {
    uint32_t insn = 0x2EC0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlal_asimdsame2_f_" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  bfmlal_asimdsame2_f_: " << result->to_string() << std::endl;
}

void test_bfmmla_asimdsame2_e() {
    uint32_t insn = 0x6E40EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmmla_asimdsame2_e" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BFMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  bfmmla_asimdsame2_e: " << result->to_string() << std::endl;
}

void test_bic_asimdimm_l_hl() {
    uint32_t insn = 0x2F009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_asimdimm_l_hl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BIC);
    std::cout << "  bic_asimdimm_l_hl: " << result->to_string() << std::endl;
}

void test_bic_asimdimm_l_sl() {
    uint32_t insn = 0x2F001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_asimdimm_l_sl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BIC);
    std::cout << "  bic_asimdimm_l_sl: " << result->to_string() << std::endl;
}

void test_bic_asimdsame_only() {
    uint32_t insn = 0x0E601C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BIC);
    std::cout << "  bic_asimdsame_only: " << result->to_string() << std::endl;
}

void test_bif_asimdsame_only() {
    uint32_t insn = 0x2EE01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bif_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BIF);
    std::cout << "  bif_asimdsame_only: " << result->to_string() << std::endl;
}

void test_bit_asimdsame_only() {
    uint32_t insn = 0x2EA01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bit_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BIT);
    std::cout << "  bit_asimdsame_only: " << result->to_string() << std::endl;
}

void test_bsl_asimdsame_only() {
    uint32_t insn = 0x2E601C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bsl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::BSL);
    std::cout << "  bsl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cls_asimdmisc_r() {
    uint32_t insn = 0x0E204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cls_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CLS);
    std::cout << "  cls_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_clz_asimdmisc_r() {
    uint32_t insn = 0x2E204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clz_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CLZ);
    std::cout << "  clz_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_cmeq_asisdsame_only() {
    uint32_t insn = 0x7EE08C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmeq_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMEQ);
    std::cout << "  cmeq_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmeq_asimdsame_only() {
    uint32_t insn = 0x2E208C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmeq_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMEQ);
    std::cout << "  cmeq_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cmeq_asisdmisc_z() {
    uint32_t insn = 0x5EE09800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmeq_asisdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMEQ);
    std::cout << "  cmeq_asisdmisc_z: " << result->to_string() << std::endl;
}

void test_cmeq_asimdmisc_z() {
    uint32_t insn = 0x0E209800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmeq_asimdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMEQ);
    std::cout << "  cmeq_asimdmisc_z: " << result->to_string() << std::endl;
}

void test_cmge_asisdsame_only() {
    uint32_t insn = 0x5EE03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmge_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGE);
    std::cout << "  cmge_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmge_asimdsame_only() {
    uint32_t insn = 0x0E203C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmge_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGE);
    std::cout << "  cmge_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cmge_asisdmisc_z() {
    uint32_t insn = 0x7EE08800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmge_asisdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGE);
    std::cout << "  cmge_asisdmisc_z: " << result->to_string() << std::endl;
}

void test_cmge_asimdmisc_z() {
    uint32_t insn = 0x2E208800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmge_asimdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGE);
    std::cout << "  cmge_asimdmisc_z: " << result->to_string() << std::endl;
}

void test_cmgt_asisdsame_only() {
    uint32_t insn = 0x5EE03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmgt_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGT);
    std::cout << "  cmgt_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmgt_asimdsame_only() {
    uint32_t insn = 0x0E203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmgt_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGT);
    std::cout << "  cmgt_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cmgt_asisdmisc_z() {
    uint32_t insn = 0x5EE08800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmgt_asisdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGT);
    std::cout << "  cmgt_asisdmisc_z: " << result->to_string() << std::endl;
}

void test_cmgt_asimdmisc_z() {
    uint32_t insn = 0x0E208800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmgt_asimdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMGT);
    std::cout << "  cmgt_asimdmisc_z: " << result->to_string() << std::endl;
}

void test_cmhi_asisdsame_only() {
    uint32_t insn = 0x7EE03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmhi_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMHI);
    std::cout << "  cmhi_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmhi_asimdsame_only() {
    uint32_t insn = 0x2E203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmhi_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMHI);
    std::cout << "  cmhi_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cmhs_asisdsame_only() {
    uint32_t insn = 0x7EE03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmhs_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMHS);
    std::cout << "  cmhs_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmhs_asimdsame_only() {
    uint32_t insn = 0x2E203C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmhs_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMHS);
    std::cout << "  cmhs_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cmle_asisdmisc_z() {
    uint32_t insn = 0x7EE09800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmle_asisdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMLE);
    std::cout << "  cmle_asisdmisc_z: " << result->to_string() << std::endl;
}

void test_cmle_asimdmisc_z() {
    uint32_t insn = 0x2E209800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmle_asimdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMLE);
    std::cout << "  cmle_asimdmisc_z: " << result->to_string() << std::endl;
}

void test_cmlt_asisdmisc_z() {
    uint32_t insn = 0x5EE0A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmlt_asisdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMLT);
    std::cout << "  cmlt_asisdmisc_z: " << result->to_string() << std::endl;
}

void test_cmlt_asimdmisc_z() {
    uint32_t insn = 0x0E20A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmlt_asimdmisc_z" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMLT);
    std::cout << "  cmlt_asimdmisc_z: " << result->to_string() << std::endl;
}

void test_cmtst_asisdsame_only() {
    uint32_t insn = 0x5EE08C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmtst_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMTST);
    std::cout << "  cmtst_asisdsame_only: " << result->to_string() << std::endl;
}

void test_cmtst_asimdsame_only() {
    uint32_t insn = 0x0E208C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmtst_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CMTST);
    std::cout << "  cmtst_asimdsame_only: " << result->to_string() << std::endl;
}

void test_cnt_asimdmisc_r() {
    uint32_t insn = 0x0E205800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnt_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::CNT);
    std::cout << "  cnt_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_dup_asisdone_only() {
    uint32_t insn = 0x5E000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_asisdone_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::DUP);
    std::cout << "  dup_asisdone_only: " << result->to_string() << std::endl;
}

void test_dup_asimdins_dv_v() {
    uint32_t insn = 0x0E000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_asimdins_dv_v" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::DUP);
    std::cout << "  dup_asimdins_dv_v: " << result->to_string() << std::endl;
}

void test_dup_asimdins_dr_r() {
    uint32_t insn = 0x0E000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_asimdins_dr_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::DUP);
    std::cout << "  dup_asimdins_dr_r: " << result->to_string() << std::endl;
}

void test_eor3_vvv16_crypto4() {
    uint32_t insn = 0xCE000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor3_vvv16_crypto4" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::EOR3);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  eor3_vvv16_crypto4: " << result->to_string() << std::endl;
}

void test_eor_asimdsame_only() {
    uint32_t insn = 0x2E201C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::EOR);
    std::cout << "  eor_asimdsame_only: " << result->to_string() << std::endl;
}

void test_ext_asimdext_only() {
    uint32_t insn = 0x2E000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ext_asimdext_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::EXT);
    std::cout << "  ext_asimdext_only: " << result->to_string() << std::endl;
}

void test_f1cvtl_asimdmisc_v() {
    uint32_t insn = 0x2E217800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f1cvtl_asimdmisc_v" << std::endl; return; }
    std::cout << "  f1cvtl_asimdmisc_v: " << result->to_string() << std::endl;
}

void test_f2cvtl_asimdmisc_v() {
    uint32_t insn = 0x2E617800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f2cvtl_asimdmisc_v" << std::endl; return; }
    std::cout << "  f2cvtl_asimdmisc_v: " << result->to_string() << std::endl;
}

void test_fabd_asisdsamefp16_only() {
    uint32_t insn = 0x7EC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabd_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABD);
    std::cout << "  fabd_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fabd_asisdsame_only() {
    uint32_t insn = 0x7EA0D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabd_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fabd_asisdsame_only: " << result->to_string() << std::endl;
}

void test_fabd_asimdsamefp16_only() {
    uint32_t insn = 0x2EC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabd_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABD);
    std::cout << "  fabd_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fabd_asimdsame_only() {
    uint32_t insn = 0x2EA0D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABD);
    std::cout << "  fabd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fabs_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF8F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABS);
    std::cout << "  fabs_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fabs_asimdmisc_r() {
    uint32_t insn = 0x0EA0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABS);
    std::cout << "  fabs_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fabs_h_floatdp1() {
    uint32_t insn = 0x1EE0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABS);
    std::cout << "  fabs_h_floatdp1: " << result->to_string() << std::endl;
}

void test_fabs_s_floatdp1() {
    uint32_t insn = 0x1E20C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABS);
    std::cout << "  fabs_s_floatdp1: " << result->to_string() << std::endl;
}

void test_fabs_d_floatdp1() {
    uint32_t insn = 0x1E60C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FABS);
    std::cout << "  fabs_d_floatdp1: " << result->to_string() << std::endl;
}

void test_facge_asisdsamefp16_only() {
    uint32_t insn = 0x7E402C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facge_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGE);
    std::cout << "  facge_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_facge_asisdsame_only() {
    uint32_t insn = 0x7E20EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facge_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  facge_asisdsame_only: " << result->to_string() << std::endl;
}

void test_facge_asimdsamefp16_only() {
    uint32_t insn = 0x2E402C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facge_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGE);
    std::cout << "  facge_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_facge_asimdsame_only() {
    uint32_t insn = 0x2E20EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facge_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGE);
    std::cout << "  facge_asimdsame_only: " << result->to_string() << std::endl;
}

void test_facgt_asisdsamefp16_only() {
    uint32_t insn = 0x7EC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facgt_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGT);
    std::cout << "  facgt_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_facgt_asisdsame_only() {
    uint32_t insn = 0x7EA0EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facgt_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  facgt_asisdsame_only: " << result->to_string() << std::endl;
}

void test_facgt_asimdsamefp16_only() {
    uint32_t insn = 0x2EC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facgt_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGT);
    std::cout << "  facgt_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_facgt_asimdsame_only() {
    uint32_t insn = 0x2EA0EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facgt_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FACGT);
    std::cout << "  facgt_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fadd_asimdsamefp16_only() {
    uint32_t insn = 0x0E401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADD);
    std::cout << "  fadd_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fadd_asimdsame_only() {
    uint32_t insn = 0x0E20D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADD);
    std::cout << "  fadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fadd_h_floatdp2() {
    uint32_t insn = 0x1EE02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADD);
    std::cout << "  fadd_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fadd_s_floatdp2() {
    uint32_t insn = 0x1E202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADD);
    std::cout << "  fadd_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fadd_d_floatdp2() {
    uint32_t insn = 0x1E602800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADD);
    std::cout << "  fadd_d_floatdp2: " << result->to_string() << std::endl;
}

void test_faddp_asisdpair_only_h() {
    uint32_t insn = 0x5E30D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddp_asisdpair_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADDP);
    std::cout << "  faddp_asisdpair_only_h: " << result->to_string() << std::endl;
}

void test_faddp_asisdpair_only_sd() {
    uint32_t insn = 0x7E30D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddp_asisdpair_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADDP);
    std::cout << "  faddp_asisdpair_only_sd: " << result->to_string() << std::endl;
}

void test_faddp_asimdsamefp16_only() {
    uint32_t insn = 0x2E401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddp_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADDP);
    std::cout << "  faddp_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_faddp_asimdsame_only() {
    uint32_t insn = 0x2E20D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FADDP);
    std::cout << "  faddp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_famax_asimdsamefp16_only() {
    uint32_t insn = 0x0EC01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famax_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FAMAX);
    std::cout << "  famax_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_famax_asimdsame_only() {
    uint32_t insn = 0x0EA0DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famax_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FAMAX);
    std::cout << "  famax_asimdsame_only: " << result->to_string() << std::endl;
}

void test_famin_asimdsamefp16_only() {
    uint32_t insn = 0x2EC01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famin_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FAMIN);
    std::cout << "  famin_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_famin_asimdsame_only() {
    uint32_t insn = 0x2EA0DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famin_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FAMIN);
    std::cout << "  famin_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fcadd_asimdsame2_c() {
    uint32_t insn = 0x2E40E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcadd_asimdsame2_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCADD);
    std::cout << "  fcadd_asimdsame2_c: " << result->to_string() << std::endl;
}

void test_fccmp_h_floatccmp() {
    uint32_t insn = 0x1EE00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmp_h_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMP);
    std::cout << "  fccmp_h_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmp_s_floatccmp() {
    uint32_t insn = 0x1E200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmp_s_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMP);
    std::cout << "  fccmp_s_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmp_d_floatccmp() {
    uint32_t insn = 0x1E600400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmp_d_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMP);
    std::cout << "  fccmp_d_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmpe_h_floatccmp() {
    uint32_t insn = 0x1EE00410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmpe_h_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMPE);
    std::cout << "  fccmpe_h_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmpe_s_floatccmp() {
    uint32_t insn = 0x1E200410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmpe_s_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMPE);
    std::cout << "  fccmpe_s_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmpe_d_floatccmp() {
    uint32_t insn = 0x1E600410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fccmpe_d_floatccmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCCMPE);
    std::cout << "  fccmpe_d_floatccmp: " << result->to_string() << std::endl;
}

void test_fcmeq_asisdsamefp16_only() {
    uint32_t insn = 0x5E402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmeq_asisdsame_only() {
    uint32_t insn = 0x5E20E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fcmeq_asisdsame_only: " << result->to_string() << std::endl;
}

void test_fcmeq_asimdsamefp16_only() {
    uint32_t insn = 0x0E402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmeq_asimdsame_only() {
    uint32_t insn = 0x0E20E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fcmeq_asisdmiscfp16_fz() {
    uint32_t insn = 0x5EF8D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asisdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asisdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmeq_asisdmisc_fz() {
    uint32_t insn = 0x5EA0D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asisdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcmeq_asisdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmeq_asimdmiscfp16_fz() {
    uint32_t insn = 0x0EF8D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asimdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asimdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmeq_asimdmisc_fz() {
    uint32_t insn = 0x0EA0D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_asimdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMEQ);
    std::cout << "  fcmeq_asimdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmge_asisdsamefp16_only() {
    uint32_t insn = 0x7E402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmge_asisdsame_only() {
    uint32_t insn = 0x7E20E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fcmge_asisdsame_only: " << result->to_string() << std::endl;
}

void test_fcmge_asimdsamefp16_only() {
    uint32_t insn = 0x2E402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmge_asimdsame_only() {
    uint32_t insn = 0x2E20E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fcmge_asisdmiscfp16_fz() {
    uint32_t insn = 0x7EF8C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asisdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asisdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmge_asisdmisc_fz() {
    uint32_t insn = 0x7EA0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asisdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcmge_asisdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmge_asimdmiscfp16_fz() {
    uint32_t insn = 0x2EF8C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asimdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asimdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmge_asimdmisc_fz() {
    uint32_t insn = 0x2EA0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_asimdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGE);
    std::cout << "  fcmge_asimdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmgt_asisdsamefp16_only() {
    uint32_t insn = 0x7EC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmgt_asisdsame_only() {
    uint32_t insn = 0x7EA0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fcmgt_asisdsame_only: " << result->to_string() << std::endl;
}

void test_fcmgt_asimdsamefp16_only() {
    uint32_t insn = 0x2EC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fcmgt_asimdsame_only() {
    uint32_t insn = 0x2EA0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fcmgt_asisdmiscfp16_fz() {
    uint32_t insn = 0x5EF8C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asisdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asisdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmgt_asisdmisc_fz() {
    uint32_t insn = 0x5EA0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asisdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcmgt_asisdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmgt_asimdmiscfp16_fz() {
    uint32_t insn = 0x0EF8C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asimdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asimdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmgt_asimdmisc_fz() {
    uint32_t insn = 0x0EA0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_asimdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMGT);
    std::cout << "  fcmgt_asimdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmla_advsimd_elt() {
    uint32_t insn = 0x2F001000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmla_advsimd_elt" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLA);
    std::cout << "  fcmla_advsimd_elt: " << result->to_string() << std::endl;
}

void test_fcmla_asimdsame2_c() {
    uint32_t insn = 0x2E40C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmla_asimdsame2_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLA);
    std::cout << "  fcmla_asimdsame2_c: " << result->to_string() << std::endl;
}

void test_fcmle_asisdmiscfp16_fz() {
    uint32_t insn = 0x7EF8D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_asisdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLE);
    std::cout << "  fcmle_asisdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmle_asisdmisc_fz() {
    uint32_t insn = 0x7EA0D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_asisdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcmle_asisdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmle_asimdmiscfp16_fz() {
    uint32_t insn = 0x2EF8D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_asimdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLE);
    std::cout << "  fcmle_asimdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmle_asimdmisc_fz() {
    uint32_t insn = 0x2EA0D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_asimdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLE);
    std::cout << "  fcmle_asimdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmlt_asisdmiscfp16_fz() {
    uint32_t insn = 0x5EF8E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_asisdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLT);
    std::cout << "  fcmlt_asisdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmlt_asisdmisc_fz() {
    uint32_t insn = 0x5EA0E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_asisdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcmlt_asisdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmlt_asimdmiscfp16_fz() {
    uint32_t insn = 0x0EF8E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_asimdmiscfp16_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLT);
    std::cout << "  fcmlt_asimdmiscfp16_fz: " << result->to_string() << std::endl;
}

void test_fcmlt_asimdmisc_fz() {
    uint32_t insn = 0x0EA0E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_asimdmisc_fz" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMLT);
    std::cout << "  fcmlt_asimdmisc_fz: " << result->to_string() << std::endl;
}

void test_fcmp_h_floatcmp() {
    uint32_t insn = 0x1EE02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_h_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_h_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmp_hz_floatcmp() {
    uint32_t insn = 0x1EE02008u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_hz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_hz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmp_s_floatcmp() {
    uint32_t insn = 0x1E202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_s_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_s_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmp_sz_floatcmp() {
    uint32_t insn = 0x1E202008u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_sz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_sz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmp_d_floatcmp() {
    uint32_t insn = 0x1E602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_d_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_d_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmp_dz_floatcmp() {
    uint32_t insn = 0x1E602008u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmp_dz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMP);
    std::cout << "  fcmp_dz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_h_floatcmp() {
    uint32_t insn = 0x1EE02010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_h_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_h_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_hz_floatcmp() {
    uint32_t insn = 0x1EE02018u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_hz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_hz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_s_floatcmp() {
    uint32_t insn = 0x1E202010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_s_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_s_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_sz_floatcmp() {
    uint32_t insn = 0x1E202018u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_sz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_sz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_d_floatcmp() {
    uint32_t insn = 0x1E602010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_d_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_d_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_dz_floatcmp() {
    uint32_t insn = 0x1E602018u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmpe_dz_floatcmp" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCMPE);
    std::cout << "  fcmpe_dz_floatcmp: " << result->to_string() << std::endl;
}

void test_fcsel_h_floatsel() {
    uint32_t insn = 0x1EE00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcsel_h_floatsel" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCSEL);
    std::cout << "  fcsel_h_floatsel: " << result->to_string() << std::endl;
}

void test_fcsel_s_floatsel() {
    uint32_t insn = 0x1E200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcsel_s_floatsel" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCSEL);
    std::cout << "  fcsel_s_floatsel: " << result->to_string() << std::endl;
}

void test_fcsel_d_floatsel() {
    uint32_t insn = 0x1E600C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcsel_d_floatsel" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCSEL);
    std::cout << "  fcsel_d_floatsel: " << result->to_string() << std::endl;
}

void test_fcvt_sh_floatdp1() {
    uint32_t insn = 0x1EE24000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_sh_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_sh_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvt_dh_floatdp1() {
    uint32_t insn = 0x1EE2C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_dh_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_dh_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvt_hs_floatdp1() {
    uint32_t insn = 0x1E23C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_hs_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_hs_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvt_ds_floatdp1() {
    uint32_t insn = 0x1E22C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_ds_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_ds_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvt_hd_floatdp1() {
    uint32_t insn = 0x1E63C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_hd_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_hd_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvt_sd_floatdp1() {
    uint32_t insn = 0x1E624000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_sd_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVT);
    std::cout << "  fcvt_sd_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvtas_asisdmiscfp16_r() {
    uint32_t insn = 0x5E79C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtas_asisdmisc_r() {
    uint32_t insn = 0x5E21C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtas_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtas_asimdmiscfp16_r() {
    uint32_t insn = 0x0E79C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtas_asimdmisc_r() {
    uint32_t insn = 0x0E21C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtas_32h_float2int() {
    uint32_t insn = 0x1EE40000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_64h_float2int() {
    uint32_t insn = 0x9EE40000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_32s_float2int() {
    uint32_t insn = 0x1E240000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_64s_float2int() {
    uint32_t insn = 0x9E240000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_32d_float2int() {
    uint32_t insn = 0x1E640000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_64d_float2int() {
    uint32_t insn = 0x9E640000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtas_sisd_32h() {
    uint32_t insn = 0x1EFA0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtas_sisd_64h() {
    uint32_t insn = 0x9EFA0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtas_sisd_64s() {
    uint32_t insn = 0x9E3A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtas_sisd_32d() {
    uint32_t insn = 0x1E7A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtas_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAS);
    std::cout << "  fcvtas_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtau_asisdmiscfp16_r() {
    uint32_t insn = 0x7E79C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtau_asisdmisc_r() {
    uint32_t insn = 0x7E21C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtau_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtau_asimdmiscfp16_r() {
    uint32_t insn = 0x2E79C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtau_asimdmisc_r() {
    uint32_t insn = 0x2E21C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtau_32h_float2int() {
    uint32_t insn = 0x1EE50000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_64h_float2int() {
    uint32_t insn = 0x9EE50000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_32s_float2int() {
    uint32_t insn = 0x1E250000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_64s_float2int() {
    uint32_t insn = 0x9E250000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_32d_float2int() {
    uint32_t insn = 0x1E650000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_64d_float2int() {
    uint32_t insn = 0x9E650000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtau_sisd_32h() {
    uint32_t insn = 0x1EFB0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtau_sisd_64h() {
    uint32_t insn = 0x9EFB0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtau_sisd_64s() {
    uint32_t insn = 0x9E3B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtau_sisd_32d() {
    uint32_t insn = 0x1E7B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtau_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTAU);
    std::cout << "  fcvtau_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtl_asimdmisc_l() {
    uint32_t insn = 0x0E217800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtl_asimdmisc_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTL);
    std::cout << "  fcvtl_asimdmisc_l: " << result->to_string() << std::endl;
}

void test_fcvtms_asisdmiscfp16_r() {
    uint32_t insn = 0x5E79B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtms_asisdmisc_r() {
    uint32_t insn = 0x5E21B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtms_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtms_asimdmiscfp16_r() {
    uint32_t insn = 0x0E79B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtms_asimdmisc_r() {
    uint32_t insn = 0x0E21B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtms_32h_float2int() {
    uint32_t insn = 0x1EF00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_64h_float2int() {
    uint32_t insn = 0x9EF00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_32s_float2int() {
    uint32_t insn = 0x1E300000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_64s_float2int() {
    uint32_t insn = 0x9E300000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_32d_float2int() {
    uint32_t insn = 0x1E700000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_64d_float2int() {
    uint32_t insn = 0x9E700000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtms_sisd_32h() {
    uint32_t insn = 0x1EF40000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtms_sisd_64h() {
    uint32_t insn = 0x9EF40000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtms_sisd_64s() {
    uint32_t insn = 0x9E340000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtms_sisd_32d() {
    uint32_t insn = 0x1E740000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtms_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMS);
    std::cout << "  fcvtms_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtmu_asisdmiscfp16_r() {
    uint32_t insn = 0x7E79B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtmu_asisdmisc_r() {
    uint32_t insn = 0x7E21B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtmu_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtmu_asimdmiscfp16_r() {
    uint32_t insn = 0x2E79B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtmu_asimdmisc_r() {
    uint32_t insn = 0x2E21B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtmu_32h_float2int() {
    uint32_t insn = 0x1EF10000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_64h_float2int() {
    uint32_t insn = 0x9EF10000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_32s_float2int() {
    uint32_t insn = 0x1E310000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_64s_float2int() {
    uint32_t insn = 0x9E310000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_32d_float2int() {
    uint32_t insn = 0x1E710000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_64d_float2int() {
    uint32_t insn = 0x9E710000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtmu_sisd_32h() {
    uint32_t insn = 0x1EF50000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtmu_sisd_64h() {
    uint32_t insn = 0x9EF50000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtmu_sisd_64s() {
    uint32_t insn = 0x9E350000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtmu_sisd_32d() {
    uint32_t insn = 0x1E750000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtmu_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTMU);
    std::cout << "  fcvtmu_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtn_asimdmisc_n() {
    uint32_t insn = 0x0E216800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtn_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTN);
    std::cout << "  fcvtn_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_fcvtn_asimdsame2_d() {
    uint32_t insn = 0x0E40F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtn_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTN);
    std::cout << "  fcvtn_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_fcvtn_asimdsame2_h() {
    uint32_t insn = 0x0E00F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtn_asimdsame2_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTN);
    std::cout << "  fcvtn_asimdsame2_h: " << result->to_string() << std::endl;
}

void test_fcvtns_asisdmiscfp16_r() {
    uint32_t insn = 0x5E79A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtns_asisdmisc_r() {
    uint32_t insn = 0x5E21A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtns_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtns_asimdmiscfp16_r() {
    uint32_t insn = 0x0E79A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtns_asimdmisc_r() {
    uint32_t insn = 0x0E21A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtns_32h_float2int() {
    uint32_t insn = 0x1EE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_64h_float2int() {
    uint32_t insn = 0x9EE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_32s_float2int() {
    uint32_t insn = 0x1E200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_64s_float2int() {
    uint32_t insn = 0x9E200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_32d_float2int() {
    uint32_t insn = 0x1E600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_64d_float2int() {
    uint32_t insn = 0x9E600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtns_sisd_32h() {
    uint32_t insn = 0x1EEA0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtns_sisd_64h() {
    uint32_t insn = 0x9EEA0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtns_sisd_64s() {
    uint32_t insn = 0x9E2A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtns_sisd_32d() {
    uint32_t insn = 0x1E6A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtns_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNS);
    std::cout << "  fcvtns_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtnu_asisdmiscfp16_r() {
    uint32_t insn = 0x7E79A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtnu_asisdmisc_r() {
    uint32_t insn = 0x7E21A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtnu_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtnu_asimdmiscfp16_r() {
    uint32_t insn = 0x2E79A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtnu_asimdmisc_r() {
    uint32_t insn = 0x2E21A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtnu_32h_float2int() {
    uint32_t insn = 0x1EE10000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_64h_float2int() {
    uint32_t insn = 0x9EE10000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_32s_float2int() {
    uint32_t insn = 0x1E210000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_64s_float2int() {
    uint32_t insn = 0x9E210000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_32d_float2int() {
    uint32_t insn = 0x1E610000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_64d_float2int() {
    uint32_t insn = 0x9E610000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtnu_sisd_32h() {
    uint32_t insn = 0x1EEB0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtnu_sisd_64h() {
    uint32_t insn = 0x9EEB0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtnu_sisd_64s() {
    uint32_t insn = 0x9E2B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtnu_sisd_32d() {
    uint32_t insn = 0x1E6B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnu_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTNU);
    std::cout << "  fcvtnu_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtps_asisdmiscfp16_r() {
    uint32_t insn = 0x5EF9A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtps_asisdmisc_r() {
    uint32_t insn = 0x5EA1A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtps_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtps_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF9A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtps_asimdmisc_r() {
    uint32_t insn = 0x0EA1A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtps_32h_float2int() {
    uint32_t insn = 0x1EE80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_64h_float2int() {
    uint32_t insn = 0x9EE80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_32s_float2int() {
    uint32_t insn = 0x1E280000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_64s_float2int() {
    uint32_t insn = 0x9E280000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_32d_float2int() {
    uint32_t insn = 0x1E680000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_64d_float2int() {
    uint32_t insn = 0x9E680000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtps_sisd_32h() {
    uint32_t insn = 0x1EF20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtps_sisd_64h() {
    uint32_t insn = 0x9EF20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtps_sisd_64s() {
    uint32_t insn = 0x9E320000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtps_sisd_32d() {
    uint32_t insn = 0x1E720000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtps_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPS);
    std::cout << "  fcvtps_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtpu_asisdmiscfp16_r() {
    uint32_t insn = 0x7EF9A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtpu_asisdmisc_r() {
    uint32_t insn = 0x7EA1A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtpu_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtpu_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF9A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtpu_asimdmisc_r() {
    uint32_t insn = 0x2EA1A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtpu_32h_float2int() {
    uint32_t insn = 0x1EE90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_64h_float2int() {
    uint32_t insn = 0x9EE90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_32s_float2int() {
    uint32_t insn = 0x1E290000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_64s_float2int() {
    uint32_t insn = 0x9E290000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_32d_float2int() {
    uint32_t insn = 0x1E690000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_64d_float2int() {
    uint32_t insn = 0x9E690000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtpu_sisd_32h() {
    uint32_t insn = 0x1EF30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtpu_sisd_64h() {
    uint32_t insn = 0x9EF30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtpu_sisd_64s() {
    uint32_t insn = 0x9E330000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtpu_sisd_32d() {
    uint32_t insn = 0x1E730000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtpu_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTPU);
    std::cout << "  fcvtpu_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtxn_asisdmisc_n() {
    uint32_t insn = 0x7E616800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtxn_asisdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTXN);
    std::cout << "  fcvtxn_asisdmisc_n: " << result->to_string() << std::endl;
}

void test_fcvtxn_asimdmisc_n() {
    uint32_t insn = 0x2E616800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtxn_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTXN);
    std::cout << "  fcvtxn_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_fcvtzs_asisdshf_c() {
    uint32_t insn = 0x5F00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asisdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_asisdshf_c: " << result->to_string() << std::endl;
}

void test_fcvtzs_asimdshf_c() {
    uint32_t insn = 0x0F00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asimdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_asimdshf_c: " << result->to_string() << std::endl;
}

void test_fcvtzs_asisdmiscfp16_r() {
    uint32_t insn = 0x5EF9B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtzs_asisdmisc_r() {
    uint32_t insn = 0x5EA1B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtzs_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtzs_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF9B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtzs_asimdmisc_r() {
    uint32_t insn = 0x0EA1B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtzs_32h_float2fix() {
    uint32_t insn = 0x1ED80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32h_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32h_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_64h_float2fix() {
    uint32_t insn = 0x9ED80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64h_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64h_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_32s_float2fix() {
    uint32_t insn = 0x1E180000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32s_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32s_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_64s_float2fix() {
    uint32_t insn = 0x9E180000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64s_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64s_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_32d_float2fix() {
    uint32_t insn = 0x1E580000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32d_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32d_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_64d_float2fix() {
    uint32_t insn = 0x9E580000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64d_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64d_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzs_32h_float2int() {
    uint32_t insn = 0x1EF80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_64h_float2int() {
    uint32_t insn = 0x9EF80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_32s_float2int() {
    uint32_t insn = 0x1E380000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_64s_float2int() {
    uint32_t insn = 0x9E380000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_32d_float2int() {
    uint32_t insn = 0x1E780000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_64d_float2int() {
    uint32_t insn = 0x9E780000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzs_sisd_32h() {
    uint32_t insn = 0x1EF60000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtzs_sisd_64h() {
    uint32_t insn = 0x9EF60000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtzs_sisd_64s() {
    uint32_t insn = 0x9E360000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtzs_sisd_32d() {
    uint32_t insn = 0x1E760000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    std::cout << "  fcvtzs_sisd_32d: " << result->to_string() << std::endl;
}

void test_fcvtzu_asisdshf_c() {
    uint32_t insn = 0x7F00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asisdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_asisdshf_c: " << result->to_string() << std::endl;
}

void test_fcvtzu_asimdshf_c() {
    uint32_t insn = 0x2F00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asimdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_asimdshf_c: " << result->to_string() << std::endl;
}

void test_fcvtzu_asisdmiscfp16_r() {
    uint32_t insn = 0x7EF9B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtzu_asisdmisc_r() {
    uint32_t insn = 0x7EA1B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fcvtzu_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtzu_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF9B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fcvtzu_asimdmisc_r() {
    uint32_t insn = 0x2EA1B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fcvtzu_32h_float2fix() {
    uint32_t insn = 0x1ED90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32h_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32h_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_64h_float2fix() {
    uint32_t insn = 0x9ED90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64h_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64h_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_32s_float2fix() {
    uint32_t insn = 0x1E190000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32s_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32s_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_64s_float2fix() {
    uint32_t insn = 0x9E190000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64s_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64s_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_32d_float2fix() {
    uint32_t insn = 0x1E590000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32d_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32d_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_64d_float2fix() {
    uint32_t insn = 0x9E590000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64d_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64d_float2fix: " << result->to_string() << std::endl;
}

void test_fcvtzu_32h_float2int() {
    uint32_t insn = 0x1EF90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_64h_float2int() {
    uint32_t insn = 0x9EF90000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64h_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_32s_float2int() {
    uint32_t insn = 0x1E390000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_64s_float2int() {
    uint32_t insn = 0x9E390000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64s_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_32d_float2int() {
    uint32_t insn = 0x1E790000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_32d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_64d_float2int() {
    uint32_t insn = 0x9E790000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_64d_float2int: " << result->to_string() << std::endl;
}

void test_fcvtzu_sisd_32h() {
    uint32_t insn = 0x1EF70000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_sisd_32h: " << result->to_string() << std::endl;
}

void test_fcvtzu_sisd_64h() {
    uint32_t insn = 0x9EF70000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_sisd_64h: " << result->to_string() << std::endl;
}

void test_fcvtzu_sisd_64s() {
    uint32_t insn = 0x9E370000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_sisd_64s: " << result->to_string() << std::endl;
}

void test_fcvtzu_sisd_32d() {
    uint32_t insn = 0x1E770000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    std::cout << "  fcvtzu_sisd_32d: " << result->to_string() << std::endl;
}

void test_fdiv_asimdsamefp16_only() {
    uint32_t insn = 0x2E403C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDIV);
    std::cout << "  fdiv_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fdiv_asimdsame_only() {
    uint32_t insn = 0x2E20FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDIV);
    std::cout << "  fdiv_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fdiv_h_floatdp2() {
    uint32_t insn = 0x1EE01800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDIV);
    std::cout << "  fdiv_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fdiv_s_floatdp2() {
    uint32_t insn = 0x1E201800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDIV);
    std::cout << "  fdiv_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fdiv_d_floatdp2() {
    uint32_t insn = 0x1E601800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDIV);
    std::cout << "  fdiv_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fdot_asimdelem_g() {
    uint32_t insn = 0x0F400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdelem_g" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdelem_g: " << result->to_string() << std::endl;
}

void test_fdot_asimdsame2_d() {
    uint32_t insn = 0x0E40FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_fdot_asimdelem_d() {
    uint32_t insn = 0x0F000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdelem_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdelem_d: " << result->to_string() << std::endl;
}

void test_fdot_asimdsame2_dd() {
    uint32_t insn = 0x0E00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdsame2_dd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdsame2_dd: " << result->to_string() << std::endl;
}

void test_fdot_asimdelem_fp16fp32() {
    uint32_t insn = 0x0F409000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdelem_fp16fp32" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdelem_fp16fp32: " << result->to_string() << std::endl;
}

void test_fdot_asimdsame2_fp16fp32() {
    uint32_t insn = 0x0E80FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_asimdsame2_fp16fp32" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FDOT);
    std::cout << "  fdot_asimdsame2_fp16fp32: " << result->to_string() << std::endl;
}

void test_fjcvtzs_32d_float2int() {
    uint32_t insn = 0x1E7E0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fjcvtzs_32d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FJCVTZS);
    std::cout << "  fjcvtzs_32d_float2int: " << result->to_string() << std::endl;
}

void test_fmadd_h_floatdp3() {
    uint32_t insn = 0x1FC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmadd_h_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMADD);
    std::cout << "  fmadd_h_floatdp3: " << result->to_string() << std::endl;
}

void test_fmadd_s_floatdp3() {
    uint32_t insn = 0x1F000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmadd_s_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMADD);
    std::cout << "  fmadd_s_floatdp3: " << result->to_string() << std::endl;
}

void test_fmadd_d_floatdp3() {
    uint32_t insn = 0x1F400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmadd_d_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMADD);
    std::cout << "  fmadd_d_floatdp3: " << result->to_string() << std::endl;
}

void test_fmax_asimdsamefp16_only() {
    uint32_t insn = 0x0E403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmax_asimdsame_only() {
    uint32_t insn = 0x0E20F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmax_h_floatdp2() {
    uint32_t insn = 0x1EE04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fmax_s_floatdp2() {
    uint32_t insn = 0x1E204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fmax_d_floatdp2() {
    uint32_t insn = 0x1E604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fmaxnm_asimdsamefp16_only() {
    uint32_t insn = 0x0E400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmaxnm_asimdsame_only() {
    uint32_t insn = 0x0E20C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmaxnm_h_floatdp2() {
    uint32_t insn = 0x1EE06800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fmaxnm_s_floatdp2() {
    uint32_t insn = 0x1E206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fmaxnm_d_floatdp2() {
    uint32_t insn = 0x1E606800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fmaxnmp_asisdpair_only_h() {
    uint32_t insn = 0x5E30C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmp_asisdpair_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMP);
    std::cout << "  fmaxnmp_asisdpair_only_h: " << result->to_string() << std::endl;
}

void test_fmaxnmp_asisdpair_only_sd() {
    uint32_t insn = 0x7E30C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmp_asisdpair_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMP);
    std::cout << "  fmaxnmp_asisdpair_only_sd: " << result->to_string() << std::endl;
}

void test_fmaxnmp_asimdsamefp16_only() {
    uint32_t insn = 0x2E400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmp_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMP);
    std::cout << "  fmaxnmp_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmaxnmp_asimdsame_only() {
    uint32_t insn = 0x2E20C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMP);
    std::cout << "  fmaxnmp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmaxnmv_asimdall_only_h() {
    uint32_t insn = 0x0E30C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmv_asimdall_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMV);
    std::cout << "  fmaxnmv_asimdall_only_h: " << result->to_string() << std::endl;
}

void test_fmaxnmv_asimdall_only_sd() {
    uint32_t insn = 0x6E30C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmv_asimdall_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXNMV);
    std::cout << "  fmaxnmv_asimdall_only_sd: " << result->to_string() << std::endl;
}

void test_fmaxp_asisdpair_only_h() {
    uint32_t insn = 0x5E30F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxp_asisdpair_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXP);
    std::cout << "  fmaxp_asisdpair_only_h: " << result->to_string() << std::endl;
}

void test_fmaxp_asisdpair_only_sd() {
    uint32_t insn = 0x7E30F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxp_asisdpair_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXP);
    std::cout << "  fmaxp_asisdpair_only_sd: " << result->to_string() << std::endl;
}

void test_fmaxp_asimdsamefp16_only() {
    uint32_t insn = 0x2E403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxp_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXP);
    std::cout << "  fmaxp_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmaxp_asimdsame_only() {
    uint32_t insn = 0x2E20F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXP);
    std::cout << "  fmaxp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmaxv_asimdall_only_h() {
    uint32_t insn = 0x0E30F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxv_asimdall_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXV);
    std::cout << "  fmaxv_asimdall_only_h: " << result->to_string() << std::endl;
}

void test_fmaxv_asimdall_only_sd() {
    uint32_t insn = 0x6E30F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxv_asimdall_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMAXV);
    std::cout << "  fmaxv_asimdall_only_sd: " << result->to_string() << std::endl;
}

void test_fmin_asimdsamefp16_only() {
    uint32_t insn = 0x0EC03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmin_asimdsame_only() {
    uint32_t insn = 0x0EA0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmin_h_floatdp2() {
    uint32_t insn = 0x1EE05800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fmin_s_floatdp2() {
    uint32_t insn = 0x1E205800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fmin_d_floatdp2() {
    uint32_t insn = 0x1E605800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fminnm_asimdsamefp16_only() {
    uint32_t insn = 0x0EC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fminnm_asimdsame_only() {
    uint32_t insn = 0x0EA0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fminnm_h_floatdp2() {
    uint32_t insn = 0x1EE07800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fminnm_s_floatdp2() {
    uint32_t insn = 0x1E207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fminnm_d_floatdp2() {
    uint32_t insn = 0x1E607800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fminnmp_asisdpair_only_h() {
    uint32_t insn = 0x5EB0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmp_asisdpair_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMP);
    std::cout << "  fminnmp_asisdpair_only_h: " << result->to_string() << std::endl;
}

void test_fminnmp_asisdpair_only_sd() {
    uint32_t insn = 0x7EB0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmp_asisdpair_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMP);
    std::cout << "  fminnmp_asisdpair_only_sd: " << result->to_string() << std::endl;
}

void test_fminnmp_asimdsamefp16_only() {
    uint32_t insn = 0x2EC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmp_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMP);
    std::cout << "  fminnmp_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fminnmp_asimdsame_only() {
    uint32_t insn = 0x2EA0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMP);
    std::cout << "  fminnmp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fminnmv_asimdall_only_h() {
    uint32_t insn = 0x0EB0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmv_asimdall_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMV);
    std::cout << "  fminnmv_asimdall_only_h: " << result->to_string() << std::endl;
}

void test_fminnmv_asimdall_only_sd() {
    uint32_t insn = 0x6EB0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmv_asimdall_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINNMV);
    std::cout << "  fminnmv_asimdall_only_sd: " << result->to_string() << std::endl;
}

void test_fminp_asisdpair_only_h() {
    uint32_t insn = 0x5EB0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminp_asisdpair_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINP);
    std::cout << "  fminp_asisdpair_only_h: " << result->to_string() << std::endl;
}

void test_fminp_asisdpair_only_sd() {
    uint32_t insn = 0x7EB0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminp_asisdpair_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINP);
    std::cout << "  fminp_asisdpair_only_sd: " << result->to_string() << std::endl;
}

void test_fminp_asimdsamefp16_only() {
    uint32_t insn = 0x2EC03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminp_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINP);
    std::cout << "  fminp_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fminp_asimdsame_only() {
    uint32_t insn = 0x2EA0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINP);
    std::cout << "  fminp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fminv_asimdall_only_h() {
    uint32_t insn = 0x0EB0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminv_asimdall_only_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINV);
    std::cout << "  fminv_asimdall_only_h: " << result->to_string() << std::endl;
}

void test_fminv_asimdall_only_sd() {
    uint32_t insn = 0x6EB0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminv_asimdall_only_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMINV);
    std::cout << "  fminv_asimdall_only_sd: " << result->to_string() << std::endl;
}

void test_fmla_asisdelem_rh_h() {
    uint32_t insn = 0x5F001000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asisdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asisdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmla_asisdelem_r_sd() {
    uint32_t insn = 0x5F801000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asisdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asisdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmla_asimdelem_rh_h() {
    uint32_t insn = 0x0F001000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asimdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asimdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmla_asimdelem_r_sd() {
    uint32_t insn = 0x0F801000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asimdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asimdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmla_asimdsamefp16_only() {
    uint32_t insn = 0x0E400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmla_asimdsame_only() {
    uint32_t insn = 0x0E20CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmlal_asimdelem_lh() {
    uint32_t insn = 0x0F800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlal_asimdelem_lh" << std::endl; return; }
    std::cout << "  fmlal_asimdelem_lh: " << result->to_string() << std::endl;
}

void test_fmlal2_asimdelem_lh() {
    uint32_t insn = 0x2F808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlal2_asimdelem_lh" << std::endl; return; }
    std::cout << "  fmlal2_asimdelem_lh: " << result->to_string() << std::endl;
}

void test_fmlal_asimdsame_f() {
    uint32_t insn = 0x0E20EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlal_asimdsame_f" << std::endl; return; }
    std::cout << "  fmlal_asimdsame_f: " << result->to_string() << std::endl;
}

void test_fmlal2_asimdsame_f() {
    uint32_t insn = 0x2E20CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlal2_asimdsame_f" << std::endl; return; }
    std::cout << "  fmlal2_asimdsame_f: " << result->to_string() << std::endl;
}

void test_fmlalb_asimdelem_h() {
    uint32_t insn = 0x0FC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_asimdelem_h" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalb_asimdelem_h: " << result->to_string() << std::endl;
}

void test_fmlalt_asimdelem_h() {
    uint32_t insn = 0x4FC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_asimdelem_h" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalt_asimdelem_h: " << result->to_string() << std::endl;
}

void test_fmlalb_asimdsame2_j() {
    uint32_t insn = 0x0EC0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_asimdsame2_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalb_asimdsame2_j: " << result->to_string() << std::endl;
}

void test_fmlalt_asimdsame2_j() {
    uint32_t insn = 0x4EC0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_asimdsame2_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalt_asimdsame2_j: " << result->to_string() << std::endl;
}

void test_fmlallbb_asimdelem_j() {
    uint32_t insn = 0x2F008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbb_asimdelem_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlallbb_asimdelem_j: " << result->to_string() << std::endl;
}

void test_fmlallbt_asimdelem_j() {
    uint32_t insn = 0x2F408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbt_asimdelem_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlallbt_asimdelem_j: " << result->to_string() << std::endl;
}

void test_fmlalltb_asimdelem_j() {
    uint32_t insn = 0x6F008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltb_asimdelem_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalltb_asimdelem_j: " << result->to_string() << std::endl;
}

void test_fmlalltt_asimdelem_j() {
    uint32_t insn = 0x6F408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltt_asimdelem_j" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalltt_asimdelem_j: " << result->to_string() << std::endl;
}

void test_fmlallbb_asimdsame2_g() {
    uint32_t insn = 0x0E00C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbb_asimdsame2_g" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlallbb_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_fmlallbt_asimdsame2_g() {
    uint32_t insn = 0x0E40C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbt_asimdsame2_g" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlallbt_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_fmlalltb_asimdsame2_g() {
    uint32_t insn = 0x4E00C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltb_asimdsame2_g" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalltb_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_fmlalltt_asimdsame2_g() {
    uint32_t insn = 0x4E40C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltt_asimdsame2_g" << std::endl; return; }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmlalltt_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_fmls_asisdelem_rh_h() {
    uint32_t insn = 0x5F005000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asisdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asisdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmls_asisdelem_r_sd() {
    uint32_t insn = 0x5F805000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asisdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asisdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmls_asimdelem_rh_h() {
    uint32_t insn = 0x0F005000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asimdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asimdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmls_asimdelem_r_sd() {
    uint32_t insn = 0x0F805000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asimdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asimdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmls_asimdsamefp16_only() {
    uint32_t insn = 0x0EC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmls_asimdsame_only() {
    uint32_t insn = 0x0EA0CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmlsl_asimdelem_lh() {
    uint32_t insn = 0x0F804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlsl_asimdelem_lh" << std::endl; return; }
    std::cout << "  fmlsl_asimdelem_lh: " << result->to_string() << std::endl;
}

void test_fmlsl2_asimdelem_lh() {
    uint32_t insn = 0x2F80C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlsl2_asimdelem_lh" << std::endl; return; }
    std::cout << "  fmlsl2_asimdelem_lh: " << result->to_string() << std::endl;
}

void test_fmlsl_asimdsame_f() {
    uint32_t insn = 0x0EA0EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlsl_asimdsame_f" << std::endl; return; }
    std::cout << "  fmlsl_asimdsame_f: " << result->to_string() << std::endl;
}

void test_fmlsl2_asimdsame_f() {
    uint32_t insn = 0x2EA0CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlsl2_asimdsame_f" << std::endl; return; }
    std::cout << "  fmlsl2_asimdsame_f: " << result->to_string() << std::endl;
}

void test_fmmla_asimd_fp16fp16() {
    uint32_t insn = 0x4EC0EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_asimd_fp16fp16" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmmla_asimd_fp16fp16: " << result->to_string() << std::endl;
}

void test_fmmla_asimd_fp16fp32() {
    uint32_t insn = 0x4E40EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_asimd_fp16fp32" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmmla_asimd_fp16fp32: " << result->to_string() << std::endl;
}

void test_fmmla_asimd_fp8fp16() {
    uint32_t insn = 0x6E00EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_asimd_fp8fp16" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmmla_asimd_fp8fp16: " << result->to_string() << std::endl;
}

void test_fmmla_asimd_fp8fp32() {
    uint32_t insn = 0x6E80EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_asimd_fp8fp32" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmmla_asimd_fp8fp32: " << result->to_string() << std::endl;
}

void test_fmov_asimdimm_h_h() {
    uint32_t insn = 0x0F00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_asimdimm_h_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_asimdimm_h_h: " << result->to_string() << std::endl;
}

void test_fmov_asimdimm_s_s() {
    uint32_t insn = 0x4F00F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_asimdimm_s_s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_asimdimm_s_s: " << result->to_string() << std::endl;
}

void test_fmov_asimdimm_d2_d() {
    uint32_t insn = 0x6F00F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_asimdimm_d2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_asimdimm_d2_d: " << result->to_string() << std::endl;
}

void test_fmov_h_floatdp1() {
    uint32_t insn = 0x1EE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_h_floatdp1: " << result->to_string() << std::endl;
}

void test_fmov_s_floatdp1() {
    uint32_t insn = 0x1E204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_s_floatdp1: " << result->to_string() << std::endl;
}

void test_fmov_d_floatdp1() {
    uint32_t insn = 0x1E604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_d_floatdp1: " << result->to_string() << std::endl;
}

void test_fmov_32h_float2int() {
    uint32_t insn = 0x1EE60000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_32h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_32h_float2int: " << result->to_string() << std::endl;
}

void test_fmov_64h_float2int() {
    uint32_t insn = 0x9EE60000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_64h_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_64h_float2int: " << result->to_string() << std::endl;
}

void test_fmov_h32_float2int() {
    uint32_t insn = 0x1EE70000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_h32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_h32_float2int: " << result->to_string() << std::endl;
}

void test_fmov_s32_float2int() {
    uint32_t insn = 0x1E270000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_s32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_s32_float2int: " << result->to_string() << std::endl;
}

void test_fmov_32s_float2int() {
    uint32_t insn = 0x1E260000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_32s_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_32s_float2int: " << result->to_string() << std::endl;
}

void test_fmov_h64_float2int() {
    uint32_t insn = 0x9EE70000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_h64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_h64_float2int: " << result->to_string() << std::endl;
}

void test_fmov_d64_float2int() {
    uint32_t insn = 0x9E670000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_d64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_d64_float2int: " << result->to_string() << std::endl;
}

void test_fmov_v64i_float2int() {
    uint32_t insn = 0x9EAF0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_v64i_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fmov_v64i_float2int: " << result->to_string() << std::endl;
}

void test_fmov_64d_float2int() {
    uint32_t insn = 0x9E660000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_64d_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_64d_float2int: " << result->to_string() << std::endl;
}

void test_fmov_64vx_float2int() {
    uint32_t insn = 0x9EAE0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_64vx_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  fmov_64vx_float2int: " << result->to_string() << std::endl;
}

void test_fmov_h_floatimm() {
    uint32_t insn = 0x1EE01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_h_floatimm" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_h_floatimm: " << result->to_string() << std::endl;
}

void test_fmov_s_floatimm() {
    uint32_t insn = 0x1E201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_s_floatimm" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_s_floatimm: " << result->to_string() << std::endl;
}

void test_fmov_d_floatimm() {
    uint32_t insn = 0x1E601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_d_floatimm" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMOV);
    std::cout << "  fmov_d_floatimm: " << result->to_string() << std::endl;
}

void test_fmsub_h_floatdp3() {
    uint32_t insn = 0x1FC08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmsub_h_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMSUB);
    std::cout << "  fmsub_h_floatdp3: " << result->to_string() << std::endl;
}

void test_fmsub_s_floatdp3() {
    uint32_t insn = 0x1F008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmsub_s_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMSUB);
    std::cout << "  fmsub_s_floatdp3: " << result->to_string() << std::endl;
}

void test_fmsub_d_floatdp3() {
    uint32_t insn = 0x1F408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmsub_d_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMSUB);
    std::cout << "  fmsub_d_floatdp3: " << result->to_string() << std::endl;
}

void test_fmul_asisdelem_rh_h() {
    uint32_t insn = 0x5F009000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asisdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asisdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmul_asisdelem_r_sd() {
    uint32_t insn = 0x5F809000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asisdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asisdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmul_asimdelem_rh_h() {
    uint32_t insn = 0x0F009000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asimdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asimdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmul_asimdelem_r_sd() {
    uint32_t insn = 0x0F809000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asimdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asimdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmul_asimdsamefp16_only() {
    uint32_t insn = 0x2E401C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmul_asimdsame_only() {
    uint32_t insn = 0x2E20DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fmul_h_floatdp2() {
    uint32_t insn = 0x1EE00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fmul_s_floatdp2() {
    uint32_t insn = 0x1E200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fmul_d_floatdp2() {
    uint32_t insn = 0x1E600800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_d_floatdp2: " << result->to_string() << std::endl;
}

void test_fmulx_asisdelem_rh_h() {
    uint32_t insn = 0x7F009000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asisdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asisdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmulx_asisdelem_r_sd() {
    uint32_t insn = 0x7F809000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asisdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asisdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmulx_asimdelem_rh_h() {
    uint32_t insn = 0x2F009000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asimdelem_rh_h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asimdelem_rh_h: " << result->to_string() << std::endl;
}

void test_fmulx_asimdelem_r_sd() {
    uint32_t insn = 0x2F809000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asimdelem_r_sd" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asimdelem_r_sd: " << result->to_string() << std::endl;
}

void test_fmulx_asisdsamefp16_only() {
    uint32_t insn = 0x5E401C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmulx_asisdsame_only() {
    uint32_t insn = 0x5E20DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  fmulx_asisdsame_only: " << result->to_string() << std::endl;
}

void test_fmulx_asimdsamefp16_only() {
    uint32_t insn = 0x0E401C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fmulx_asimdsame_only() {
    uint32_t insn = 0x0E20DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FMULX);
    std::cout << "  fmulx_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fneg_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF8F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNEG);
    std::cout << "  fneg_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fneg_asimdmisc_r() {
    uint32_t insn = 0x2EA0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNEG);
    std::cout << "  fneg_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fneg_h_floatdp1() {
    uint32_t insn = 0x1EE14000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNEG);
    std::cout << "  fneg_h_floatdp1: " << result->to_string() << std::endl;
}

void test_fneg_s_floatdp1() {
    uint32_t insn = 0x1E214000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNEG);
    std::cout << "  fneg_s_floatdp1: " << result->to_string() << std::endl;
}

void test_fneg_d_floatdp1() {
    uint32_t insn = 0x1E614000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNEG);
    std::cout << "  fneg_d_floatdp1: " << result->to_string() << std::endl;
}

void test_fnmadd_h_floatdp3() {
    uint32_t insn = 0x1FE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmadd_h_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMADD);
    std::cout << "  fnmadd_h_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmadd_s_floatdp3() {
    uint32_t insn = 0x1F200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmadd_s_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMADD);
    std::cout << "  fnmadd_s_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmadd_d_floatdp3() {
    uint32_t insn = 0x1F600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmadd_d_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMADD);
    std::cout << "  fnmadd_d_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmsub_h_floatdp3() {
    uint32_t insn = 0x1FE08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmsub_h_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMSUB);
    std::cout << "  fnmsub_h_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmsub_s_floatdp3() {
    uint32_t insn = 0x1F208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmsub_s_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMSUB);
    std::cout << "  fnmsub_s_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmsub_d_floatdp3() {
    uint32_t insn = 0x1F608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmsub_d_floatdp3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMSUB);
    std::cout << "  fnmsub_d_floatdp3: " << result->to_string() << std::endl;
}

void test_fnmul_h_floatdp2() {
    uint32_t insn = 0x1EE08800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmul_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMUL);
    std::cout << "  fnmul_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fnmul_s_floatdp2() {
    uint32_t insn = 0x1E208800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmul_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMUL);
    std::cout << "  fnmul_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fnmul_d_floatdp2() {
    uint32_t insn = 0x1E608800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmul_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FNMUL);
    std::cout << "  fnmul_d_floatdp2: " << result->to_string() << std::endl;
}

void test_frecpe_asisdmiscfp16_r() {
    uint32_t insn = 0x5EF9D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpe_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPE);
    std::cout << "  frecpe_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frecpe_asisdmisc_r() {
    uint32_t insn = 0x5EA1D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpe_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  frecpe_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_frecpe_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF9D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpe_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPE);
    std::cout << "  frecpe_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frecpe_asimdmisc_r() {
    uint32_t insn = 0x0EA1D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpe_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPE);
    std::cout << "  frecpe_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frecps_asisdsamefp16_only() {
    uint32_t insn = 0x5E403C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecps_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPS);
    std::cout << "  frecps_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_frecps_asisdsame_only() {
    uint32_t insn = 0x5E20FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecps_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  frecps_asisdsame_only: " << result->to_string() << std::endl;
}

void test_frecps_asimdsamefp16_only() {
    uint32_t insn = 0x0E403C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecps_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPS);
    std::cout << "  frecps_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_frecps_asimdsame_only() {
    uint32_t insn = 0x0E20FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecps_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPS);
    std::cout << "  frecps_asimdsame_only: " << result->to_string() << std::endl;
}

void test_frecpx_asisdmiscfp16_r() {
    uint32_t insn = 0x5EF9F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpx_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPX);
    std::cout << "  frecpx_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frecpx_asisdmisc_r() {
    uint32_t insn = 0x5EA1F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpx_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRECPX);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  frecpx_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_frint32x_asimdmisc_r() {
    uint32_t insn = 0x2E21E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32x_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32X);
    std::cout << "  frint32x_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frint32x_s_floatdp1() {
    uint32_t insn = 0x1E28C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32x_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32X);
    std::cout << "  frint32x_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frint32x_d_floatdp1() {
    uint32_t insn = 0x1E68C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32x_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32X);
    std::cout << "  frint32x_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frint32z_asimdmisc_r() {
    uint32_t insn = 0x0E21E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32z_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32Z);
    std::cout << "  frint32z_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frint32z_s_floatdp1() {
    uint32_t insn = 0x1E284000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32z_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32Z);
    std::cout << "  frint32z_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frint32z_d_floatdp1() {
    uint32_t insn = 0x1E684000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32z_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT32Z);
    std::cout << "  frint32z_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frint64x_asimdmisc_r() {
    uint32_t insn = 0x2E21F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64x_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64X);
    std::cout << "  frint64x_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frint64x_s_floatdp1() {
    uint32_t insn = 0x1E29C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64x_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64X);
    std::cout << "  frint64x_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frint64x_d_floatdp1() {
    uint32_t insn = 0x1E69C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64x_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64X);
    std::cout << "  frint64x_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frint64z_asimdmisc_r() {
    uint32_t insn = 0x0E21F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64z_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64Z);
    std::cout << "  frint64z_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frint64z_s_floatdp1() {
    uint32_t insn = 0x1E294000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64z_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64Z);
    std::cout << "  frint64z_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frint64z_d_floatdp1() {
    uint32_t insn = 0x1E694000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64z_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINT64Z);
    std::cout << "  frint64z_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frinta_asimdmiscfp16_r() {
    uint32_t insn = 0x2E798800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTA);
    std::cout << "  frinta_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frinta_asimdmisc_r() {
    uint32_t insn = 0x2E218800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTA);
    std::cout << "  frinta_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frinta_h_floatdp1() {
    uint32_t insn = 0x1EE64000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTA);
    std::cout << "  frinta_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frinta_s_floatdp1() {
    uint32_t insn = 0x1E264000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTA);
    std::cout << "  frinta_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frinta_d_floatdp1() {
    uint32_t insn = 0x1E664000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTA);
    std::cout << "  frinta_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frinti_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF99800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTI);
    std::cout << "  frinti_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frinti_asimdmisc_r() {
    uint32_t insn = 0x2EA19800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTI);
    std::cout << "  frinti_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frinti_h_floatdp1() {
    uint32_t insn = 0x1EE7C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTI);
    std::cout << "  frinti_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frinti_s_floatdp1() {
    uint32_t insn = 0x1E27C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTI);
    std::cout << "  frinti_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frinti_d_floatdp1() {
    uint32_t insn = 0x1E67C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTI);
    std::cout << "  frinti_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frintm_asimdmiscfp16_r() {
    uint32_t insn = 0x0E799800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTM);
    std::cout << "  frintm_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frintm_asimdmisc_r() {
    uint32_t insn = 0x0E219800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTM);
    std::cout << "  frintm_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frintm_h_floatdp1() {
    uint32_t insn = 0x1EE54000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTM);
    std::cout << "  frintm_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frintm_s_floatdp1() {
    uint32_t insn = 0x1E254000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTM);
    std::cout << "  frintm_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frintm_d_floatdp1() {
    uint32_t insn = 0x1E654000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTM);
    std::cout << "  frintm_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frintn_asimdmiscfp16_r() {
    uint32_t insn = 0x0E798800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTN);
    std::cout << "  frintn_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frintn_asimdmisc_r() {
    uint32_t insn = 0x0E218800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTN);
    std::cout << "  frintn_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frintn_h_floatdp1() {
    uint32_t insn = 0x1EE44000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTN);
    std::cout << "  frintn_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frintn_s_floatdp1() {
    uint32_t insn = 0x1E244000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTN);
    std::cout << "  frintn_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frintn_d_floatdp1() {
    uint32_t insn = 0x1E644000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTN);
    std::cout << "  frintn_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frintp_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF98800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTP);
    std::cout << "  frintp_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frintp_asimdmisc_r() {
    uint32_t insn = 0x0EA18800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTP);
    std::cout << "  frintp_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frintp_h_floatdp1() {
    uint32_t insn = 0x1EE4C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTP);
    std::cout << "  frintp_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frintp_s_floatdp1() {
    uint32_t insn = 0x1E24C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTP);
    std::cout << "  frintp_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frintp_d_floatdp1() {
    uint32_t insn = 0x1E64C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTP);
    std::cout << "  frintp_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frintx_asimdmiscfp16_r() {
    uint32_t insn = 0x2E799800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTX);
    std::cout << "  frintx_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frintx_asimdmisc_r() {
    uint32_t insn = 0x2E219800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTX);
    std::cout << "  frintx_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frintx_h_floatdp1() {
    uint32_t insn = 0x1EE74000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTX);
    std::cout << "  frintx_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frintx_s_floatdp1() {
    uint32_t insn = 0x1E274000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTX);
    std::cout << "  frintx_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frintx_d_floatdp1() {
    uint32_t insn = 0x1E674000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTX);
    std::cout << "  frintx_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frintz_asimdmiscfp16_r() {
    uint32_t insn = 0x0EF99800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTZ);
    std::cout << "  frintz_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frintz_asimdmisc_r() {
    uint32_t insn = 0x0EA19800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTZ);
    std::cout << "  frintz_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frintz_h_floatdp1() {
    uint32_t insn = 0x1EE5C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTZ);
    std::cout << "  frintz_h_floatdp1: " << result->to_string() << std::endl;
}

void test_frintz_s_floatdp1() {
    uint32_t insn = 0x1E25C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTZ);
    std::cout << "  frintz_s_floatdp1: " << result->to_string() << std::endl;
}

void test_frintz_d_floatdp1() {
    uint32_t insn = 0x1E65C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRINTZ);
    std::cout << "  frintz_d_floatdp1: " << result->to_string() << std::endl;
}

void test_frsqrte_asisdmiscfp16_r() {
    uint32_t insn = 0x7EF9D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrte_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTE);
    std::cout << "  frsqrte_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frsqrte_asisdmisc_r() {
    uint32_t insn = 0x7EA1D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrte_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  frsqrte_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_frsqrte_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF9D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrte_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTE);
    std::cout << "  frsqrte_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_frsqrte_asimdmisc_r() {
    uint32_t insn = 0x2EA1D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrte_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTE);
    std::cout << "  frsqrte_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_frsqrts_asisdsamefp16_only() {
    uint32_t insn = 0x5EC03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrts_asisdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTS);
    std::cout << "  frsqrts_asisdsamefp16_only: " << result->to_string() << std::endl;
}

void test_frsqrts_asisdsame_only() {
    uint32_t insn = 0x5EA0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrts_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  frsqrts_asisdsame_only: " << result->to_string() << std::endl;
}

void test_frsqrts_asimdsamefp16_only() {
    uint32_t insn = 0x0EC03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrts_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTS);
    std::cout << "  frsqrts_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_frsqrts_asimdsame_only() {
    uint32_t insn = 0x0EA0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrts_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FRSQRTS);
    std::cout << "  frsqrts_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fscale_asimdsamefp16_only() {
    uint32_t insn = 0x2EC03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fscale_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSCALE);
    std::cout << "  fscale_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fscale_asimdsame_only() {
    uint32_t insn = 0x2EA0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fscale_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSCALE);
    std::cout << "  fscale_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fsqrt_asimdmiscfp16_r() {
    uint32_t insn = 0x2EF9F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSQRT);
    std::cout << "  fsqrt_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_fsqrt_asimdmisc_r() {
    uint32_t insn = 0x2EA1F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSQRT);
    std::cout << "  fsqrt_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_fsqrt_h_floatdp1() {
    uint32_t insn = 0x1EE1C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_h_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSQRT);
    std::cout << "  fsqrt_h_floatdp1: " << result->to_string() << std::endl;
}

void test_fsqrt_s_floatdp1() {
    uint32_t insn = 0x1E21C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_s_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSQRT);
    std::cout << "  fsqrt_s_floatdp1: " << result->to_string() << std::endl;
}

void test_fsqrt_d_floatdp1() {
    uint32_t insn = 0x1E61C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_d_floatdp1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSQRT);
    std::cout << "  fsqrt_d_floatdp1: " << result->to_string() << std::endl;
}

void test_fsub_asimdsamefp16_only() {
    uint32_t insn = 0x0EC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_asimdsamefp16_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSUB);
    std::cout << "  fsub_asimdsamefp16_only: " << result->to_string() << std::endl;
}

void test_fsub_asimdsame_only() {
    uint32_t insn = 0x0EA0D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSUB);
    std::cout << "  fsub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_fsub_h_floatdp2() {
    uint32_t insn = 0x1EE03800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_h_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSUB);
    std::cout << "  fsub_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fsub_s_floatdp2() {
    uint32_t insn = 0x1E203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_s_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSUB);
    std::cout << "  fsub_s_floatdp2: " << result->to_string() << std::endl;
}

void test_fsub_d_floatdp2() {
    uint32_t insn = 0x1E603800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_d_floatdp2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::FSUB);
    std::cout << "  fsub_d_floatdp2: " << result->to_string() << std::endl;
}

void test_ins_asimdins_iv_v() {
    uint32_t insn = 0x6E000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ins_asimdins_iv_v" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::INS);
    std::cout << "  ins_asimdins_iv_v: " << result->to_string() << std::endl;
}

void test_ins_asimdins_ir_r() {
    uint32_t insn = 0x4E001C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ins_asimdins_ir_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::INS);
    std::cout << "  ins_asimdins_ir_r: " << result->to_string() << std::endl;
}

void test_luti2_asimdtbl_l5() {
    uint32_t insn = 0x4E801000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti2_asimdtbl_l5" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  luti2_asimdtbl_l5: " << result->to_string() << std::endl;
}

void test_luti2_asimdtbl_l6() {
    uint32_t insn = 0x4EC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti2_asimdtbl_l6" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  luti2_asimdtbl_l6: " << result->to_string() << std::endl;
}

void test_luti4_asimdtbl_l5() {
    uint32_t insn = 0x4E402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti4_asimdtbl_l5" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  luti4_asimdtbl_l5: " << result->to_string() << std::endl;
}

void test_luti4_asimdtbl_l7() {
    uint32_t insn = 0x4E401000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti4_asimdtbl_l7" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  luti4_asimdtbl_l7: " << result->to_string() << std::endl;
}

void test_mla_asimdelem_r() {
    uint32_t insn = 0x2F000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MLA);
    std::cout << "  mla_asimdelem_r: " << result->to_string() << std::endl;
}

void test_mla_asimdsame_only() {
    uint32_t insn = 0x0E209400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MLA);
    std::cout << "  mla_asimdsame_only: " << result->to_string() << std::endl;
}

void test_mls_asimdelem_r() {
    uint32_t insn = 0x2F004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MLS);
    std::cout << "  mls_asimdelem_r: " << result->to_string() << std::endl;
}

void test_mls_asimdsame_only() {
    uint32_t insn = 0x2E209400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MLS);
    std::cout << "  mls_asimdsame_only: " << result->to_string() << std::endl;
}

void test_mov_dup_asisdone_only() {
    uint32_t insn = 0x5E000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_dup_asisdone_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::DUP);
    std::cout << "  mov_dup_asisdone_only: " << result->to_string() << std::endl;
}

void test_mov_ins_asimdins_iv_v() {
    uint32_t insn = 0x6E000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_ins_asimdins_iv_v" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::INS);
    std::cout << "  mov_ins_asimdins_iv_v: " << result->to_string() << std::endl;
}

void test_mov_ins_asimdins_ir_r() {
    uint32_t insn = 0x4E001C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_ins_asimdins_ir_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::INS);
    std::cout << "  mov_ins_asimdins_ir_r: " << result->to_string() << std::endl;
}

void test_mov_orr_asimdsame_only() {
    uint32_t insn = 0x0EA01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_orr_asimdsame_only" << std::endl; return; }
    std::cout << "  mov_orr_asimdsame_only: " << result->to_string() << std::endl;
}

void test_mov_umov_asimdins_w_w() {
    uint32_t insn = 0x0E043C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_umov_asimdins_w_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  mov_umov_asimdins_w_w: " << result->to_string() << std::endl;
}

void test_mov_umov_asimdins_x_x() {
    uint32_t insn = 0x4E083C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_umov_asimdins_x_x" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  mov_umov_asimdins_x_x: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_n_b() {
    uint32_t insn = 0x0F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_n_b" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_n_b: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_l_hl() {
    uint32_t insn = 0x0F008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_l_hl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_l_hl: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_l_sl() {
    uint32_t insn = 0x0F000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_l_sl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_l_sl: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_m_sm() {
    uint32_t insn = 0x0F00C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_m_sm" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_m_sm: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_d_ds() {
    uint32_t insn = 0x2F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_d_ds" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_d_ds: " << result->to_string() << std::endl;
}

void test_movi_asimdimm_d2_d() {
    uint32_t insn = 0x6F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movi_asimdimm_d2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MOVI);
    std::cout << "  movi_asimdimm_d2_d: " << result->to_string() << std::endl;
}

void test_mul_asimdelem_r() {
    uint32_t insn = 0x0F008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MUL);
    std::cout << "  mul_asimdelem_r: " << result->to_string() << std::endl;
}

void test_mul_asimdsame_only() {
    uint32_t insn = 0x0E209C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MUL);
    std::cout << "  mul_asimdsame_only: " << result->to_string() << std::endl;
}

void test_mvn_not_asimdmisc_r() {
    uint32_t insn = 0x2E205800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvn_not_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::NOT);
    std::cout << "  mvn_not_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_mvni_asimdimm_l_hl() {
    uint32_t insn = 0x2F008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvni_asimdimm_l_hl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MVNI);
    std::cout << "  mvni_asimdimm_l_hl: " << result->to_string() << std::endl;
}

void test_mvni_asimdimm_l_sl() {
    uint32_t insn = 0x2F000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvni_asimdimm_l_sl" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MVNI);
    std::cout << "  mvni_asimdimm_l_sl: " << result->to_string() << std::endl;
}

void test_mvni_asimdimm_m_sm() {
    uint32_t insn = 0x2F00C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvni_asimdimm_m_sm" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::MVNI);
    std::cout << "  mvni_asimdimm_m_sm: " << result->to_string() << std::endl;
}

void test_neg_asisdmisc_r() {
    uint32_t insn = 0x7EE0B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::NEG);
    std::cout << "  neg_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_neg_asimdmisc_r() {
    uint32_t insn = 0x2E20B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::NEG);
    std::cout << "  neg_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_not_asimdmisc_r() {
    uint32_t insn = 0x2E205800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: not_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::NOT);
    std::cout << "  not_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_orn_asimdsame_only() {
    uint32_t insn = 0x0EE01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orn_asimdsame_only" << std::endl; return; }
    std::cout << "  orn_asimdsame_only: " << result->to_string() << std::endl;
}

void test_orr_asimdimm_l_hl() {
    uint32_t insn = 0x0F009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_asimdimm_l_hl" << std::endl; return; }
    std::cout << "  orr_asimdimm_l_hl: " << result->to_string() << std::endl;
}

void test_orr_asimdimm_l_sl() {
    uint32_t insn = 0x0F001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_asimdimm_l_sl" << std::endl; return; }
    std::cout << "  orr_asimdimm_l_sl: " << result->to_string() << std::endl;
}

void test_orr_asimdsame_only() {
    uint32_t insn = 0x0EA01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_asimdsame_only" << std::endl; return; }
    std::cout << "  orr_asimdsame_only: " << result->to_string() << std::endl;
}

void test_pmul_asimdsame_only() {
    uint32_t insn = 0x2E209C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmul_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::PMUL);
    std::cout << "  pmul_asimdsame_only: " << result->to_string() << std::endl;
}

void test_pmull_asimddiff_l() {
    uint32_t insn = 0x0E20E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmull_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::PMULL);
    std::cout << "  pmull_asimddiff_l: " << result->to_string() << std::endl;
}

void test_raddhn_asimddiff_n() {
    uint32_t insn = 0x2E204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: raddhn_asimddiff_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::RADDHN);
    std::cout << "  raddhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_rax1_vvv2_cryptosha512_3() {
    uint32_t insn = 0xCE608C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rax1_vvv2_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::RAX1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  rax1_vvv2_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_rbit_asimdmisc_r() {
    uint32_t insn = 0x2E605800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rbit_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::RBIT);
    std::cout << "  rbit_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_rev16_asimdmisc_r() {
    uint32_t insn = 0x0E201800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev16_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::REV16);
    std::cout << "  rev16_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_rev32_asimdmisc_r() {
    uint32_t insn = 0x2E200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev32_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::REV32);
    std::cout << "  rev32_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_rev64_asimdmisc_r() {
    uint32_t insn = 0x0E200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev64_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::REV64);
    std::cout << "  rev64_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_rshrn_asimdshf_n() {
    uint32_t insn = 0x0F008C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rshrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::RSHRN);
    std::cout << "  rshrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_rsubhn_asimddiff_n() {
    uint32_t insn = 0x2E206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rsubhn_asimddiff_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::RSUBHN);
    std::cout << "  rsubhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_saba_asimdsame_only() {
    uint32_t insn = 0x0E207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saba_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SABA);
    std::cout << "  saba_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sabal_asimddiff_l() {
    uint32_t insn = 0x0E205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabal_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SABAL);
    std::cout << "  sabal_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sabd_asimdsame_only() {
    uint32_t insn = 0x0E207400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SABD);
    std::cout << "  sabd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sabdl_asimddiff_l() {
    uint32_t insn = 0x0E207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabdl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SABDL);
    std::cout << "  sabdl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sadalp_asimdmisc_p() {
    uint32_t insn = 0x0E206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sadalp_asimdmisc_p" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SADALP);
    std::cout << "  sadalp_asimdmisc_p: " << result->to_string() << std::endl;
}

void test_saddl_asimddiff_l() {
    uint32_t insn = 0x0E200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SADDL);
    std::cout << "  saddl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_saddlp_asimdmisc_p() {
    uint32_t insn = 0x0E202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddlp_asimdmisc_p" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SADDLP);
    std::cout << "  saddlp_asimdmisc_p: " << result->to_string() << std::endl;
}

void test_saddlv_asimdall_only() {
    uint32_t insn = 0x0E303800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddlv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SADDLV);
    std::cout << "  saddlv_asimdall_only: " << result->to_string() << std::endl;
}

void test_saddw_asimddiff_w() {
    uint32_t insn = 0x0E201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddw_asimddiff_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SADDW);
    std::cout << "  saddw_asimddiff_w: " << result->to_string() << std::endl;
}

void test_scvtf_asisdshf_c() {
    uint32_t insn = 0x5F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asisdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_asisdshf_c: " << result->to_string() << std::endl;
}

void test_scvtf_asimdshf_c() {
    uint32_t insn = 0x0F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asimdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_asimdshf_c: " << result->to_string() << std::endl;
}

void test_scvtf_asisdmiscfp16_r() {
    uint32_t insn = 0x5E79D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_scvtf_asisdmisc_r() {
    uint32_t insn = 0x5E21D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  scvtf_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_scvtf_asimdmiscfp16_r() {
    uint32_t insn = 0x0E79D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_scvtf_asimdmisc_r() {
    uint32_t insn = 0x0E21D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_scvtf_h32_float2fix() {
    uint32_t insn = 0x1EC20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_h32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_h32_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_h64_float2fix() {
    uint32_t insn = 0x9EC20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_h64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_h64_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_s32_float2fix() {
    uint32_t insn = 0x1E020000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_s32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_s32_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_s64_float2fix() {
    uint32_t insn = 0x9E020000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_s64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_s64_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_d32_float2fix() {
    uint32_t insn = 0x1E420000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_d32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_d32_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_d64_float2fix() {
    uint32_t insn = 0x9E420000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_d64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_d64_float2fix: " << result->to_string() << std::endl;
}

void test_scvtf_h32_float2int() {
    uint32_t insn = 0x1EE20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_h32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_h32_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_s32_float2int() {
    uint32_t insn = 0x1E220000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_s32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_s32_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_d32_float2int() {
    uint32_t insn = 0x1E620000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_d32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_d32_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_h64_float2int() {
    uint32_t insn = 0x9EE20000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_h64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_h64_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_s64_float2int() {
    uint32_t insn = 0x9E220000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_s64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_s64_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_d64_float2int() {
    uint32_t insn = 0x9E620000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_d64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_d64_float2int: " << result->to_string() << std::endl;
}

void test_scvtf_sisd_32h() {
    uint32_t insn = 0x1EFC0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_sisd_32h: " << result->to_string() << std::endl;
}

void test_scvtf_sisd_32d() {
    uint32_t insn = 0x1E7C0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_sisd_32d: " << result->to_string() << std::endl;
}

void test_scvtf_sisd_64h() {
    uint32_t insn = 0x9EFC0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_sisd_64h: " << result->to_string() << std::endl;
}

void test_scvtf_sisd_64s() {
    uint32_t insn = 0x9E3C0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SCVTF);
    std::cout << "  scvtf_sisd_64s: " << result->to_string() << std::endl;
}

void test_sdot_asimdelem_d() {
    uint32_t insn = 0x0F00E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_asimdelem_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SDOT);
    std::cout << "  sdot_asimdelem_d: " << result->to_string() << std::endl;
}

void test_sdot_asimdsame2_d() {
    uint32_t insn = 0x0E009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SDOT);
    std::cout << "  sdot_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_sha1c_qsv_cryptosha3() {
    uint32_t insn = 0x5E000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1c_qsv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1C);
    std::cout << "  sha1c_qsv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha1h_ss_cryptosha2() {
    uint32_t insn = 0x5E280800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1h_ss_cryptosha2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1H);
    std::cout << "  sha1h_ss_cryptosha2: " << result->to_string() << std::endl;
}

void test_sha1m_qsv_cryptosha3() {
    uint32_t insn = 0x5E002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1m_qsv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1M);
    std::cout << "  sha1m_qsv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha1p_qsv_cryptosha3() {
    uint32_t insn = 0x5E001000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1p_qsv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1P);
    std::cout << "  sha1p_qsv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha1su0_vvv_cryptosha3() {
    uint32_t insn = 0x5E003000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1su0_vvv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1SU0);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sha1su0_vvv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha1su1_vv_cryptosha2() {
    uint32_t insn = 0x5E281800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha1su1_vv_cryptosha2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA1SU1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sha1su1_vv_cryptosha2: " << result->to_string() << std::endl;
}

void test_sha256h2_qqv_cryptosha3() {
    uint32_t insn = 0x5E005000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha256h2_qqv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA256H2);
    std::cout << "  sha256h2_qqv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha256h_qqv_cryptosha3() {
    uint32_t insn = 0x5E004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha256h_qqv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA256H);
    std::cout << "  sha256h_qqv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha256su0_vv_cryptosha2() {
    uint32_t insn = 0x5E282800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha256su0_vv_cryptosha2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA256SU0);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sha256su0_vv_cryptosha2: " << result->to_string() << std::endl;
}

void test_sha256su1_vvv_cryptosha3() {
    uint32_t insn = 0x5E006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha256su1_vvv_cryptosha3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA256SU1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sha256su1_vvv_cryptosha3: " << result->to_string() << std::endl;
}

void test_sha512h2_qqv_cryptosha512_3() {
    uint32_t insn = 0xCE608400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha512h2_qqv_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA512H2);
    std::cout << "  sha512h2_qqv_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_sha512h_qqv_cryptosha512_3() {
    uint32_t insn = 0xCE608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha512h_qqv_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA512H);
    std::cout << "  sha512h_qqv_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_sha512su0_vv2_cryptosha512_2() {
    uint32_t insn = 0xCEC08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha512su0_vv2_cryptosha512_2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA512SU0);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sha512su0_vv2_cryptosha512_2: " << result->to_string() << std::endl;
}

void test_sha512su1_vvv2_cryptosha512_3() {
    uint32_t insn = 0xCE608800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sha512su1_vvv2_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHA512SU1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sha512su1_vvv2_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_shadd_asimdsame_only() {
    uint32_t insn = 0x0E200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHADD);
    std::cout << "  shadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_shl_asisdshf_r() {
    uint32_t insn = 0x5F405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shl_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHL);
    std::cout << "  shl_asisdshf_r: " << result->to_string() << std::endl;
}

void test_shl_asimdshf_r() {
    uint32_t insn = 0x0F005400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shl_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHL);
    std::cout << "  shl_asimdshf_r: " << result->to_string() << std::endl;
}

void test_shll_asimdmisc_s() {
    uint32_t insn = 0x2E213800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shll_asimdmisc_s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHLL);
    std::cout << "  shll_asimdmisc_s: " << result->to_string() << std::endl;
}

void test_shrn_asimdshf_n() {
    uint32_t insn = 0x0F008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHRN);
    std::cout << "  shrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_shsub_asimdsame_only() {
    uint32_t insn = 0x0E202400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shsub_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SHSUB);
    std::cout << "  shsub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sli_asisdshf_r() {
    uint32_t insn = 0x7F405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sli_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SLI);
    std::cout << "  sli_asisdshf_r: " << result->to_string() << std::endl;
}

void test_sli_asimdshf_r() {
    uint32_t insn = 0x2F005400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sli_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SLI);
    std::cout << "  sli_asimdshf_r: " << result->to_string() << std::endl;
}

void test_sm3partw1_vvv4_cryptosha512_3() {
    uint32_t insn = 0xCE60C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3partw1_vvv4_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3PARTW1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3partw1_vvv4_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_sm3partw2_vvv4_cryptosha512_3() {
    uint32_t insn = 0xCE60C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3partw2_vvv4_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3PARTW2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3partw2_vvv4_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_sm3ss1_vvv4_crypto4() {
    uint32_t insn = 0xCE400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3ss1_vvv4_crypto4" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3SS1);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  sm3ss1_vvv4_crypto4: " << result->to_string() << std::endl;
}

void test_sm3tt1a_vvv4_crypto3_imm2() {
    uint32_t insn = 0xCE408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3tt1a_vvv4_crypto3_imm2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3TT1A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3tt1a_vvv4_crypto3_imm2: " << result->to_string() << std::endl;
}

void test_sm3tt1b_vvv4_crypto3_imm2() {
    uint32_t insn = 0xCE408400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3tt1b_vvv4_crypto3_imm2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3TT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3tt1b_vvv4_crypto3_imm2: " << result->to_string() << std::endl;
}

void test_sm3tt2a_vvv4_crypto3_imm2() {
    uint32_t insn = 0xCE408800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3tt2a_vvv4_crypto3_imm2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3TT2A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3tt2a_vvv4_crypto3_imm2: " << result->to_string() << std::endl;
}

void test_sm3tt2b_vvv_crypto3_imm2() {
    uint32_t insn = 0xCE408C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm3tt2b_vvv_crypto3_imm2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM3TT2B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm3tt2b_vvv_crypto3_imm2: " << result->to_string() << std::endl;
}

void test_sm4e_vv4_cryptosha512_2() {
    uint32_t insn = 0xCEC08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm4e_vv4_cryptosha512_2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM4E);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sm4e_vv4_cryptosha512_2: " << result->to_string() << std::endl;
}

void test_sm4ekey_vvv4_cryptosha512_3() {
    uint32_t insn = 0xCE60C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm4ekey_vvv4_cryptosha512_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SM4EKEY);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sm4ekey_vvv4_cryptosha512_3: " << result->to_string() << std::endl;
}

void test_smax_asimdsame_only() {
    uint32_t insn = 0x0E206400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smax_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMAX);
    std::cout << "  smax_asimdsame_only: " << result->to_string() << std::endl;
}

void test_smaxp_asimdsame_only() {
    uint32_t insn = 0x0E20A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaxp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMAXP);
    std::cout << "  smaxp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_smaxv_asimdall_only() {
    uint32_t insn = 0x0E30A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaxv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMAXV);
    std::cout << "  smaxv_asimdall_only: " << result->to_string() << std::endl;
}

void test_smin_asimdsame_only() {
    uint32_t insn = 0x0E206C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smin_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMIN);
    std::cout << "  smin_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sminp_asimdsame_only() {
    uint32_t insn = 0x0E20AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sminp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMINP);
    std::cout << "  sminp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sminv_asimdall_only() {
    uint32_t insn = 0x0E31A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sminv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMINV);
    std::cout << "  sminv_asimdall_only: " << result->to_string() << std::endl;
}

void test_smlal_asimdelem_l() {
    uint32_t insn = 0x0F002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlal_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMLAL);
    std::cout << "  smlal_asimdelem_l: " << result->to_string() << std::endl;
}

void test_smlal_asimddiff_l() {
    uint32_t insn = 0x0E208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlal_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMLAL);
    std::cout << "  smlal_asimddiff_l: " << result->to_string() << std::endl;
}

void test_smlsl_asimdelem_l() {
    uint32_t insn = 0x0F006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlsl_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMLSL);
    std::cout << "  smlsl_asimdelem_l: " << result->to_string() << std::endl;
}

void test_smlsl_asimddiff_l() {
    uint32_t insn = 0x0E20A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlsl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMLSL);
    std::cout << "  smlsl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_smmla_asimdsame2_g() {
    uint32_t insn = 0x4E80A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smmla_asimdsame2_g" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smmla_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_smov_asimdins_w_w() {
    uint32_t insn = 0x0E002C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smov_asimdins_w_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMOV);
    std::cout << "  smov_asimdins_w_w: " << result->to_string() << std::endl;
}

void test_smov_asimdins_x_x() {
    uint32_t insn = 0x4E002C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smov_asimdins_x_x" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMOV);
    std::cout << "  smov_asimdins_x_x: " << result->to_string() << std::endl;
}

void test_smull_asimdelem_l() {
    uint32_t insn = 0x0F00A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smull_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMULL);
    std::cout << "  smull_asimdelem_l: " << result->to_string() << std::endl;
}

void test_smull_asimddiff_l() {
    uint32_t insn = 0x0E20C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smull_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SMULL);
    std::cout << "  smull_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sqabs_asisdmisc_r() {
    uint32_t insn = 0x5E207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqabs_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQABS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sqabs_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_sqabs_asimdmisc_r() {
    uint32_t insn = 0x0E207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqabs_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQABS);
    std::cout << "  sqabs_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_sqadd_asisdsame_only() {
    uint32_t insn = 0x5E200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqadd_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqadd_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqadd_asimdsame_only() {
    uint32_t insn = 0x0E200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQADD);
    std::cout << "  sqadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqdmlal_asisdelem_l() {
    uint32_t insn = 0x5F003000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlal_asisdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLAL);
    std::cout << "  sqdmlal_asisdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmlal_asimdelem_l() {
    uint32_t insn = 0x0F003000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlal_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLAL);
    std::cout << "  sqdmlal_asimdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmlal_asisddiff_only() {
    uint32_t insn = 0x5E209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlal_asisddiff_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLAL);
    std::cout << "  sqdmlal_asisddiff_only: " << result->to_string() << std::endl;
}

void test_sqdmlal_asimddiff_l() {
    uint32_t insn = 0x0E209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlal_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLAL);
    std::cout << "  sqdmlal_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sqdmlsl_asisdelem_l() {
    uint32_t insn = 0x5F007000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlsl_asisdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLSL);
    std::cout << "  sqdmlsl_asisdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmlsl_asimdelem_l() {
    uint32_t insn = 0x0F007000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlsl_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLSL);
    std::cout << "  sqdmlsl_asimdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmlsl_asisddiff_only() {
    uint32_t insn = 0x5E20B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlsl_asisddiff_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLSL);
    std::cout << "  sqdmlsl_asisddiff_only: " << result->to_string() << std::endl;
}

void test_sqdmlsl_asimddiff_l() {
    uint32_t insn = 0x0E20B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlsl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMLSL);
    std::cout << "  sqdmlsl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sqdmulh_asisdelem_r() {
    uint32_t insn = 0x5F00C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_asisdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    std::cout << "  sqdmulh_asisdelem_r: " << result->to_string() << std::endl;
}

void test_sqdmulh_asimdelem_r() {
    uint32_t insn = 0x0F00C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    std::cout << "  sqdmulh_asimdelem_r: " << result->to_string() << std::endl;
}

void test_sqdmulh_asisdsame_only() {
    uint32_t insn = 0x5E20B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqdmulh_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqdmulh_asimdsame_only() {
    uint32_t insn = 0x0E20B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    std::cout << "  sqdmulh_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqdmull_asimdelem_l() {
    uint32_t insn = 0x0F00B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmull_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULL);
    std::cout << "  sqdmull_asimdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmull_asisdelem_l() {
    uint32_t insn = 0x5F00B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmull_asisdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULL);
    std::cout << "  sqdmull_asisdelem_l: " << result->to_string() << std::endl;
}

void test_sqdmull_asisddiff_only() {
    uint32_t insn = 0x5E20D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmull_asisddiff_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULL);
    std::cout << "  sqdmull_asisddiff_only: " << result->to_string() << std::endl;
}

void test_sqdmull_asimddiff_l() {
    uint32_t insn = 0x0E20D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmull_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQDMULL);
    std::cout << "  sqdmull_asimddiff_l: " << result->to_string() << std::endl;
}

void test_sqneg_asisdmisc_r() {
    uint32_t insn = 0x7E207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqneg_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQNEG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  sqneg_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_sqneg_asimdmisc_r() {
    uint32_t insn = 0x2E207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqneg_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQNEG);
    std::cout << "  sqneg_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_sqrdmlah_asisdelem_r() {
    uint32_t insn = 0x7F00D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_asisdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    std::cout << "  sqrdmlah_asisdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmlah_asimdelem_r() {
    uint32_t insn = 0x2F00D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    std::cout << "  sqrdmlah_asimdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmlah_asisdsame2_only() {
    uint32_t insn = 0x7E008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_asisdsame2_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqrdmlah_asisdsame2_only: " << result->to_string() << std::endl;
}

void test_sqrdmlah_asimdsame2_only() {
    uint32_t insn = 0x2E008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_asimdsame2_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    std::cout << "  sqrdmlah_asimdsame2_only: " << result->to_string() << std::endl;
}

void test_sqrdmlsh_asisdelem_r() {
    uint32_t insn = 0x7F00F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_asisdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    std::cout << "  sqrdmlsh_asisdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmlsh_asimdelem_r() {
    uint32_t insn = 0x2F00F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    std::cout << "  sqrdmlsh_asimdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmlsh_asisdsame2_only() {
    uint32_t insn = 0x7E008C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_asisdsame2_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqrdmlsh_asisdsame2_only: " << result->to_string() << std::endl;
}

void test_sqrdmlsh_asimdsame2_only() {
    uint32_t insn = 0x2E008C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_asimdsame2_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    std::cout << "  sqrdmlsh_asimdsame2_only: " << result->to_string() << std::endl;
}

void test_sqrdmulh_asisdelem_r() {
    uint32_t insn = 0x5F00D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_asisdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    std::cout << "  sqrdmulh_asisdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmulh_asimdelem_r() {
    uint32_t insn = 0x0F00D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_asimdelem_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    std::cout << "  sqrdmulh_asimdelem_r: " << result->to_string() << std::endl;
}

void test_sqrdmulh_asisdsame_only() {
    uint32_t insn = 0x7E20B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqrdmulh_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqrdmulh_asimdsame_only() {
    uint32_t insn = 0x2E20B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    std::cout << "  sqrdmulh_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqrshl_asisdsame_only() {
    uint32_t insn = 0x5E205C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqrshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqrshl_asimdsame_only() {
    uint32_t insn = 0x0E205C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHL);
    std::cout << "  sqrshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqrshrn_asisdshf_n() {
    uint32_t insn = 0x5F089C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrn_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHRN);
    std::cout << "  sqrshrn_asisdshf_n: " << result->to_string() << std::endl;
}

void test_sqrshrn_asimdshf_n() {
    uint32_t insn = 0x0F009C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHRN);
    std::cout << "  sqrshrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_sqrshrun_asisdshf_n() {
    uint32_t insn = 0x7F088C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrun_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHRUN);
    std::cout << "  sqrshrun_asisdshf_n: " << result->to_string() << std::endl;
}

void test_sqrshrun_asimdshf_n() {
    uint32_t insn = 0x2F008C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrun_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQRSHRUN);
    std::cout << "  sqrshrun_asimdshf_n: " << result->to_string() << std::endl;
}

void test_sqshl_asisdshf_r() {
    uint32_t insn = 0x5F087400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHL);
    std::cout << "  sqshl_asisdshf_r: " << result->to_string() << std::endl;
}

void test_sqshl_asimdshf_r() {
    uint32_t insn = 0x0F007400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHL);
    std::cout << "  sqshl_asimdshf_r: " << result->to_string() << std::endl;
}

void test_sqshl_asisdsame_only() {
    uint32_t insn = 0x5E204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqshl_asimdsame_only() {
    uint32_t insn = 0x0E204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHL);
    std::cout << "  sqshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqshlu_asisdshf_r() {
    uint32_t insn = 0x7F086400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshlu_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHLU);
    std::cout << "  sqshlu_asisdshf_r: " << result->to_string() << std::endl;
}

void test_sqshlu_asimdshf_r() {
    uint32_t insn = 0x2F006400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshlu_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHLU);
    std::cout << "  sqshlu_asimdshf_r: " << result->to_string() << std::endl;
}

void test_sqshrn_asisdshf_n() {
    uint32_t insn = 0x5F089400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrn_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHRN);
    std::cout << "  sqshrn_asisdshf_n: " << result->to_string() << std::endl;
}

void test_sqshrn_asimdshf_n() {
    uint32_t insn = 0x0F009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHRN);
    std::cout << "  sqshrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_sqshrun_asisdshf_n() {
    uint32_t insn = 0x7F088400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrun_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHRUN);
    std::cout << "  sqshrun_asisdshf_n: " << result->to_string() << std::endl;
}

void test_sqshrun_asimdshf_n() {
    uint32_t insn = 0x2F008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrun_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSHRUN);
    std::cout << "  sqshrun_asimdshf_n: " << result->to_string() << std::endl;
}

void test_sqsub_asisdsame_only() {
    uint32_t insn = 0x5E202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsub_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSUB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sqsub_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sqsub_asimdsame_only() {
    uint32_t insn = 0x0E202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsub_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQSUB);
    std::cout << "  sqsub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sqxtn_asisdmisc_n() {
    uint32_t insn = 0x5E214800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtn_asisdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQXTN);
    std::cout << "  sqxtn_asisdmisc_n: " << result->to_string() << std::endl;
}

void test_sqxtn_asimdmisc_n() {
    uint32_t insn = 0x0E214800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtn_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQXTN);
    std::cout << "  sqxtn_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_sqxtun_asisdmisc_n() {
    uint32_t insn = 0x7E212800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtun_asisdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQXTUN);
    std::cout << "  sqxtun_asisdmisc_n: " << result->to_string() << std::endl;
}

void test_sqxtun_asimdmisc_n() {
    uint32_t insn = 0x2E212800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtun_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SQXTUN);
    std::cout << "  sqxtun_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_srhadd_asimdsame_only() {
    uint32_t insn = 0x0E201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srhadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRHADD);
    std::cout << "  srhadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sri_asisdshf_r() {
    uint32_t insn = 0x7F404400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sri_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRI);
    std::cout << "  sri_asisdshf_r: " << result->to_string() << std::endl;
}

void test_sri_asimdshf_r() {
    uint32_t insn = 0x2F004400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sri_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRI);
    std::cout << "  sri_asimdshf_r: " << result->to_string() << std::endl;
}

void test_srshl_asisdsame_only() {
    uint32_t insn = 0x5EE05400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSHL);
    std::cout << "  srshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_srshl_asimdsame_only() {
    uint32_t insn = 0x0E205400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSHL);
    std::cout << "  srshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_srshr_asisdshf_r() {
    uint32_t insn = 0x5F402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshr_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSHR);
    std::cout << "  srshr_asisdshf_r: " << result->to_string() << std::endl;
}

void test_srshr_asimdshf_r() {
    uint32_t insn = 0x0F002400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshr_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSHR);
    std::cout << "  srshr_asimdshf_r: " << result->to_string() << std::endl;
}

void test_srsra_asisdshf_r() {
    uint32_t insn = 0x5F403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srsra_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSRA);
    std::cout << "  srsra_asisdshf_r: " << result->to_string() << std::endl;
}

void test_srsra_asimdshf_r() {
    uint32_t insn = 0x0F003400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srsra_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SRSRA);
    std::cout << "  srsra_asimdshf_r: " << result->to_string() << std::endl;
}

void test_sshl_asisdsame_only() {
    uint32_t insn = 0x5EE04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHL);
    std::cout << "  sshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sshl_asimdsame_only() {
    uint32_t insn = 0x0E204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHL);
    std::cout << "  sshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_sshll_asimdshf_l() {
    uint32_t insn = 0x0F00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshll_asimdshf_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHLL);
    std::cout << "  sshll_asimdshf_l: " << result->to_string() << std::endl;
}

void test_sshr_asisdshf_r() {
    uint32_t insn = 0x5F400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshr_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHR);
    std::cout << "  sshr_asisdshf_r: " << result->to_string() << std::endl;
}

void test_sshr_asimdshf_r() {
    uint32_t insn = 0x0F000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshr_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHR);
    std::cout << "  sshr_asimdshf_r: " << result->to_string() << std::endl;
}

void test_ssra_asisdshf_r() {
    uint32_t insn = 0x5F401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssra_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSRA);
    std::cout << "  ssra_asisdshf_r: " << result->to_string() << std::endl;
}

void test_ssra_asimdshf_r() {
    uint32_t insn = 0x0F001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssra_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSRA);
    std::cout << "  ssra_asimdshf_r: " << result->to_string() << std::endl;
}

void test_ssubl_asimddiff_l() {
    uint32_t insn = 0x0E202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssubl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSUBL);
    std::cout << "  ssubl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_ssubw_asimddiff_w() {
    uint32_t insn = 0x0E203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssubw_asimddiff_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSUBW);
    std::cout << "  ssubw_asimddiff_w: " << result->to_string() << std::endl;
}

void test_sub_asisdsame_only() {
    uint32_t insn = 0x7EE08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_asisdsame_only" << std::endl; return; }
    std::cout << "  sub_asisdsame_only: " << result->to_string() << std::endl;
}

void test_sub_asimdsame_only() {
    uint32_t insn = 0x2E208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_asimdsame_only" << std::endl; return; }
    std::cout << "  sub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_subhn_asimddiff_n() {
    uint32_t insn = 0x0E206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subhn_asimddiff_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SUBHN);
    std::cout << "  subhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_sudot_asimdelem_d() {
    uint32_t insn = 0x0F00F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sudot_asimdelem_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SUDOT);
    std::cout << "  sudot_asimdelem_d: " << result->to_string() << std::endl;
}

void test_suqadd_asisdmisc_r() {
    uint32_t insn = 0x5E203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: suqadd_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SUQADD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  suqadd_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_suqadd_asimdmisc_r() {
    uint32_t insn = 0x0E203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: suqadd_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SUQADD);
    std::cout << "  suqadd_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_sxtl_sshll_asimdshf_l() {
    uint32_t insn = 0x0F00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxtl_sshll_asimdshf_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::SSHLL);
    std::cout << "  sxtl_sshll_asimdshf_l: " << result->to_string() << std::endl;
}

void test_tbl_asimdtbl_l1_1() {
    uint32_t insn = 0x0E000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_asimdtbl_l1_1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBL);
    std::cout << "  tbl_asimdtbl_l1_1: " << result->to_string() << std::endl;
}

void test_tbl_asimdtbl_l2_2() {
    uint32_t insn = 0x0E002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_asimdtbl_l2_2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBL);
    std::cout << "  tbl_asimdtbl_l2_2: " << result->to_string() << std::endl;
}

void test_tbl_asimdtbl_l3_3() {
    uint32_t insn = 0x0E004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_asimdtbl_l3_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBL);
    std::cout << "  tbl_asimdtbl_l3_3: " << result->to_string() << std::endl;
}

void test_tbl_asimdtbl_l4_4() {
    uint32_t insn = 0x0E006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_asimdtbl_l4_4" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBL);
    std::cout << "  tbl_asimdtbl_l4_4: " << result->to_string() << std::endl;
}

void test_tbx_asimdtbl_l1_1() {
    uint32_t insn = 0x0E001000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbx_asimdtbl_l1_1" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBX);
    std::cout << "  tbx_asimdtbl_l1_1: " << result->to_string() << std::endl;
}

void test_tbx_asimdtbl_l2_2() {
    uint32_t insn = 0x0E003000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbx_asimdtbl_l2_2" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBX);
    std::cout << "  tbx_asimdtbl_l2_2: " << result->to_string() << std::endl;
}

void test_tbx_asimdtbl_l3_3() {
    uint32_t insn = 0x0E005000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbx_asimdtbl_l3_3" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBX);
    std::cout << "  tbx_asimdtbl_l3_3: " << result->to_string() << std::endl;
}

void test_tbx_asimdtbl_l4_4() {
    uint32_t insn = 0x0E007000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbx_asimdtbl_l4_4" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TBX);
    std::cout << "  tbx_asimdtbl_l4_4: " << result->to_string() << std::endl;
}

void test_trn1_asimdperm_only() {
    uint32_t insn = 0x0E002800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn1_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TRN1);
    std::cout << "  trn1_asimdperm_only: " << result->to_string() << std::endl;
}

void test_trn2_asimdperm_only() {
    uint32_t insn = 0x0E006800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn2_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::TRN2);
    std::cout << "  trn2_asimdperm_only: " << result->to_string() << std::endl;
}

void test_uaba_asimdsame_only() {
    uint32_t insn = 0x2E207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaba_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UABA);
    std::cout << "  uaba_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uabal_asimddiff_l() {
    uint32_t insn = 0x2E205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabal_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UABAL);
    std::cout << "  uabal_asimddiff_l: " << result->to_string() << std::endl;
}

void test_uabd_asimdsame_only() {
    uint32_t insn = 0x2E207400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UABD);
    std::cout << "  uabd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uabdl_asimddiff_l() {
    uint32_t insn = 0x2E207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabdl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UABDL);
    std::cout << "  uabdl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_uadalp_asimdmisc_p() {
    uint32_t insn = 0x2E206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uadalp_asimdmisc_p" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UADALP);
    std::cout << "  uadalp_asimdmisc_p: " << result->to_string() << std::endl;
}

void test_uaddl_asimddiff_l() {
    uint32_t insn = 0x2E200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UADDL);
    std::cout << "  uaddl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_uaddlp_asimdmisc_p() {
    uint32_t insn = 0x2E202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddlp_asimdmisc_p" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UADDLP);
    std::cout << "  uaddlp_asimdmisc_p: " << result->to_string() << std::endl;
}

void test_uaddlv_asimdall_only() {
    uint32_t insn = 0x2E303800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddlv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UADDLV);
    std::cout << "  uaddlv_asimdall_only: " << result->to_string() << std::endl;
}

void test_uaddw_asimddiff_w() {
    uint32_t insn = 0x2E201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddw_asimddiff_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UADDW);
    std::cout << "  uaddw_asimddiff_w: " << result->to_string() << std::endl;
}

void test_ucvtf_asisdshf_c() {
    uint32_t insn = 0x7F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asisdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_asisdshf_c: " << result->to_string() << std::endl;
}

void test_ucvtf_asimdshf_c() {
    uint32_t insn = 0x2F00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asimdshf_c" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_asimdshf_c: " << result->to_string() << std::endl;
}

void test_ucvtf_asisdmiscfp16_r() {
    uint32_t insn = 0x7E79D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asisdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_asisdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_ucvtf_asisdmisc_r() {
    uint32_t insn = 0x7E21D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ucvtf_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_ucvtf_asimdmiscfp16_r() {
    uint32_t insn = 0x2E79D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asimdmiscfp16_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_asimdmiscfp16_r: " << result->to_string() << std::endl;
}

void test_ucvtf_asimdmisc_r() {
    uint32_t insn = 0x2E21D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_ucvtf_h32_float2fix() {
    uint32_t insn = 0x1EC30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_h32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_h32_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_h64_float2fix() {
    uint32_t insn = 0x9EC30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_h64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_h64_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_s32_float2fix() {
    uint32_t insn = 0x1E030000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_s32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_s32_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_s64_float2fix() {
    uint32_t insn = 0x9E030000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_s64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_s64_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_d32_float2fix() {
    uint32_t insn = 0x1E430000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_d32_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_d32_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_d64_float2fix() {
    uint32_t insn = 0x9E430000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_d64_float2fix" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_d64_float2fix: " << result->to_string() << std::endl;
}

void test_ucvtf_h32_float2int() {
    uint32_t insn = 0x1EE30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_h32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_h32_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_s32_float2int() {
    uint32_t insn = 0x1E230000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_s32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_s32_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_d32_float2int() {
    uint32_t insn = 0x1E630000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_d32_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_d32_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_h64_float2int() {
    uint32_t insn = 0x9EE30000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_h64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_h64_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_s64_float2int() {
    uint32_t insn = 0x9E230000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_s64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_s64_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_d64_float2int() {
    uint32_t insn = 0x9E630000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_d64_float2int" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_d64_float2int: " << result->to_string() << std::endl;
}

void test_ucvtf_sisd_32h() {
    uint32_t insn = 0x1EFD0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_sisd_32h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_sisd_32h: " << result->to_string() << std::endl;
}

void test_ucvtf_sisd_32d() {
    uint32_t insn = 0x1E7D0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_sisd_32d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_sisd_32d: " << result->to_string() << std::endl;
}

void test_ucvtf_sisd_64h() {
    uint32_t insn = 0x9EFD0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_sisd_64h" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_sisd_64h: " << result->to_string() << std::endl;
}

void test_ucvtf_sisd_64s() {
    uint32_t insn = 0x9E3D0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_sisd_64s" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UCVTF);
    std::cout << "  ucvtf_sisd_64s: " << result->to_string() << std::endl;
}

void test_udot_asimdelem_d() {
    uint32_t insn = 0x2F00E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_asimdelem_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UDOT);
    std::cout << "  udot_asimdelem_d: " << result->to_string() << std::endl;
}

void test_udot_asimdsame2_d() {
    uint32_t insn = 0x2E009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UDOT);
    std::cout << "  udot_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_uhadd_asimdsame_only() {
    uint32_t insn = 0x2E200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uhadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UHADD);
    std::cout << "  uhadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uhsub_asimdsame_only() {
    uint32_t insn = 0x2E202400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uhsub_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UHSUB);
    std::cout << "  uhsub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_umax_asimdsame_only() {
    uint32_t insn = 0x2E206400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umax_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMAX);
    std::cout << "  umax_asimdsame_only: " << result->to_string() << std::endl;
}

void test_umaxp_asimdsame_only() {
    uint32_t insn = 0x2E20A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaxp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMAXP);
    std::cout << "  umaxp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_umaxv_asimdall_only() {
    uint32_t insn = 0x2E30A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaxv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMAXV);
    std::cout << "  umaxv_asimdall_only: " << result->to_string() << std::endl;
}

void test_umin_asimdsame_only() {
    uint32_t insn = 0x2E206C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umin_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMIN);
    std::cout << "  umin_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uminp_asimdsame_only() {
    uint32_t insn = 0x2E20AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uminp_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMINP);
    std::cout << "  uminp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uminv_asimdall_only() {
    uint32_t insn = 0x2E31A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uminv_asimdall_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMINV);
    std::cout << "  uminv_asimdall_only: " << result->to_string() << std::endl;
}

void test_umlal_asimdelem_l() {
    uint32_t insn = 0x2F002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlal_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMLAL);
    std::cout << "  umlal_asimdelem_l: " << result->to_string() << std::endl;
}

void test_umlal_asimddiff_l() {
    uint32_t insn = 0x2E208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlal_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMLAL);
    std::cout << "  umlal_asimddiff_l: " << result->to_string() << std::endl;
}

void test_umlsl_asimdelem_l() {
    uint32_t insn = 0x2F006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlsl_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMLSL);
    std::cout << "  umlsl_asimdelem_l: " << result->to_string() << std::endl;
}

void test_umlsl_asimddiff_l() {
    uint32_t insn = 0x2E20A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlsl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMLSL);
    std::cout << "  umlsl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_ummla_asimdsame2_g() {
    uint32_t insn = 0x6E80A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ummla_asimdsame2_g" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ummla_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_umov_asimdins_w_w() {
    uint32_t insn = 0x0E003C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umov_asimdins_w_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMOV);
    std::cout << "  umov_asimdins_w_w: " << result->to_string() << std::endl;
}

void test_umov_asimdins_x_x() {
    uint32_t insn = 0x4E083C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umov_asimdins_x_x" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  umov_asimdins_x_x: " << result->to_string() << std::endl;
}

void test_umull_asimdelem_l() {
    uint32_t insn = 0x2F00A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umull_asimdelem_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMULL);
    std::cout << "  umull_asimdelem_l: " << result->to_string() << std::endl;
}

void test_umull_asimddiff_l() {
    uint32_t insn = 0x2E20C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umull_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UMULL);
    std::cout << "  umull_asimddiff_l: " << result->to_string() << std::endl;
}

void test_uqadd_asisdsame_only() {
    uint32_t insn = 0x7E200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqadd_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  uqadd_asisdsame_only: " << result->to_string() << std::endl;
}

void test_uqadd_asimdsame_only() {
    uint32_t insn = 0x2E200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQADD);
    std::cout << "  uqadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uqrshl_asisdsame_only() {
    uint32_t insn = 0x7E205C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQRSHL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  uqrshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_uqrshl_asimdsame_only() {
    uint32_t insn = 0x2E205C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQRSHL);
    std::cout << "  uqrshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uqrshrn_asisdshf_n() {
    uint32_t insn = 0x7F089C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrn_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQRSHRN);
    std::cout << "  uqrshrn_asisdshf_n: " << result->to_string() << std::endl;
}

void test_uqrshrn_asimdshf_n() {
    uint32_t insn = 0x2F009C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQRSHRN);
    std::cout << "  uqrshrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_uqshl_asisdshf_r() {
    uint32_t insn = 0x7F087400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHL);
    std::cout << "  uqshl_asisdshf_r: " << result->to_string() << std::endl;
}

void test_uqshl_asimdshf_r() {
    uint32_t insn = 0x2F007400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHL);
    std::cout << "  uqshl_asimdshf_r: " << result->to_string() << std::endl;
}

void test_uqshl_asisdsame_only() {
    uint32_t insn = 0x7E204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  uqshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_uqshl_asimdsame_only() {
    uint32_t insn = 0x2E204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHL);
    std::cout << "  uqshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uqshrn_asisdshf_n() {
    uint32_t insn = 0x7F089400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshrn_asisdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHRN);
    std::cout << "  uqshrn_asisdshf_n: " << result->to_string() << std::endl;
}

void test_uqshrn_asimdshf_n() {
    uint32_t insn = 0x2F009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshrn_asimdshf_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSHRN);
    std::cout << "  uqshrn_asimdshf_n: " << result->to_string() << std::endl;
}

void test_uqsub_asisdsame_only() {
    uint32_t insn = 0x7E202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsub_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSUB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  uqsub_asisdsame_only: " << result->to_string() << std::endl;
}

void test_uqsub_asimdsame_only() {
    uint32_t insn = 0x2E202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsub_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQSUB);
    std::cout << "  uqsub_asimdsame_only: " << result->to_string() << std::endl;
}

void test_uqxtn_asisdmisc_n() {
    uint32_t insn = 0x7E214800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqxtn_asisdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQXTN);
    std::cout << "  uqxtn_asisdmisc_n: " << result->to_string() << std::endl;
}

void test_uqxtn_asimdmisc_n() {
    uint32_t insn = 0x2E214800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqxtn_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UQXTN);
    std::cout << "  uqxtn_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_urecpe_asimdmisc_r() {
    uint32_t insn = 0x0EA1C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urecpe_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URECPE);
    std::cout << "  urecpe_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_urhadd_asimdsame_only() {
    uint32_t insn = 0x2E201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urhadd_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URHADD);
    std::cout << "  urhadd_asimdsame_only: " << result->to_string() << std::endl;
}

void test_urshl_asisdsame_only() {
    uint32_t insn = 0x7EE05400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSHL);
    std::cout << "  urshl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_urshl_asimdsame_only() {
    uint32_t insn = 0x2E205400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSHL);
    std::cout << "  urshl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_urshr_asisdshf_r() {
    uint32_t insn = 0x7F402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshr_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSHR);
    std::cout << "  urshr_asisdshf_r: " << result->to_string() << std::endl;
}

void test_urshr_asimdshf_r() {
    uint32_t insn = 0x2F002400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshr_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSHR);
    std::cout << "  urshr_asimdshf_r: " << result->to_string() << std::endl;
}

void test_ursqrte_asimdmisc_r() {
    uint32_t insn = 0x2EA1C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursqrte_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSQRTE);
    std::cout << "  ursqrte_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_ursra_asisdshf_r() {
    uint32_t insn = 0x7F403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursra_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSRA);
    std::cout << "  ursra_asisdshf_r: " << result->to_string() << std::endl;
}

void test_ursra_asimdshf_r() {
    uint32_t insn = 0x2F003400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursra_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::URSRA);
    std::cout << "  ursra_asimdshf_r: " << result->to_string() << std::endl;
}

void test_usdot_asimdelem_d() {
    uint32_t insn = 0x0F80F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usdot_asimdelem_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USDOT);
    std::cout << "  usdot_asimdelem_d: " << result->to_string() << std::endl;
}

void test_usdot_asimdsame2_d() {
    uint32_t insn = 0x0E809C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usdot_asimdsame2_d" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USDOT);
    std::cout << "  usdot_asimdsame2_d: " << result->to_string() << std::endl;
}

void test_ushl_asisdsame_only() {
    uint32_t insn = 0x7EE04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushl_asisdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHL);
    std::cout << "  ushl_asisdsame_only: " << result->to_string() << std::endl;
}

void test_ushl_asimdsame_only() {
    uint32_t insn = 0x2E204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushl_asimdsame_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHL);
    std::cout << "  ushl_asimdsame_only: " << result->to_string() << std::endl;
}

void test_ushll_asimdshf_l() {
    uint32_t insn = 0x2F00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushll_asimdshf_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHLL);
    std::cout << "  ushll_asimdshf_l: " << result->to_string() << std::endl;
}

void test_ushr_asisdshf_r() {
    uint32_t insn = 0x7F400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushr_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHR);
    std::cout << "  ushr_asisdshf_r: " << result->to_string() << std::endl;
}

void test_ushr_asimdshf_r() {
    uint32_t insn = 0x2F000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushr_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHR);
    std::cout << "  ushr_asimdshf_r: " << result->to_string() << std::endl;
}

void test_usmmla_asimdsame2_g() {
    uint32_t insn = 0x4E80AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usmmla_asimdsame2_g" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  usmmla_asimdsame2_g: " << result->to_string() << std::endl;
}

void test_usqadd_asisdmisc_r() {
    uint32_t insn = 0x7E203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usqadd_asisdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USQADD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  usqadd_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_usqadd_asimdmisc_r() {
    uint32_t insn = 0x2E203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usqadd_asimdmisc_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USQADD);
    std::cout << "  usqadd_asimdmisc_r: " << result->to_string() << std::endl;
}

void test_usra_asisdshf_r() {
    uint32_t insn = 0x7F401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usra_asisdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USRA);
    std::cout << "  usra_asisdshf_r: " << result->to_string() << std::endl;
}

void test_usra_asimdshf_r() {
    uint32_t insn = 0x2F001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usra_asimdshf_r" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USRA);
    std::cout << "  usra_asimdshf_r: " << result->to_string() << std::endl;
}

void test_usubl_asimddiff_l() {
    uint32_t insn = 0x2E202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usubl_asimddiff_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USUBL);
    std::cout << "  usubl_asimddiff_l: " << result->to_string() << std::endl;
}

void test_usubw_asimddiff_w() {
    uint32_t insn = 0x2E203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usubw_asimddiff_w" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USUBW);
    std::cout << "  usubw_asimddiff_w: " << result->to_string() << std::endl;
}

void test_uxtl_ushll_asimdshf_l() {
    uint32_t insn = 0x2F00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxtl_ushll_asimdshf_l" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::USHLL);
    std::cout << "  uxtl_ushll_asimdshf_l: " << result->to_string() << std::endl;
}

void test_uzp1_asimdperm_only() {
    uint32_t insn = 0x0E001800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp1_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UZP1);
    std::cout << "  uzp1_asimdperm_only: " << result->to_string() << std::endl;
}

void test_uzp2_asimdperm_only() {
    uint32_t insn = 0x0E005800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp2_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::UZP2);
    std::cout << "  uzp2_asimdperm_only: " << result->to_string() << std::endl;
}

void test_xar_vvv2_crypto3_imm6() {
    uint32_t insn = 0xCE800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: xar_vvv2_crypto3_imm6" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::XAR);
    std::cout << "  xar_vvv2_crypto3_imm6: " << result->to_string() << std::endl;
}

void test_xtn_asimdmisc_n() {
    uint32_t insn = 0x0E212800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: xtn_asimdmisc_n" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::XTN);
    std::cout << "  xtn_asimdmisc_n: " << result->to_string() << std::endl;
}

void test_zip1_asimdperm_only() {
    uint32_t insn = 0x0E003800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip1_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ZIP1);
    std::cout << "  zip1_asimdperm_only: " << result->to_string() << std::endl;
}

void test_zip2_asimdperm_only() {
    uint32_t insn = 0x0E007800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip2_asimdperm_only" << std::endl; return; }
    assert(result->mnemonic == Mnemonic::ZIP2);
    std::cout << "  zip2_asimdperm_only: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running simd_dp encoding tests (852 encodings)..." << std::endl;
    int failed = 0;

    try { test_abs_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: abs_asisdmisc_r" << std::endl; failed++; }
    try { test_abs_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: abs_asimdmisc_r" << std::endl; failed++; }
    try { test_add_asisdsame_only(); } catch (...) { std::cerr << "FAIL: add_asisdsame_only" << std::endl; failed++; }
    try { test_add_asimdsame_only(); } catch (...) { std::cerr << "FAIL: add_asimdsame_only" << std::endl; failed++; }
    try { test_addhn_asimddiff_n(); } catch (...) { std::cerr << "FAIL: addhn_asimddiff_n" << std::endl; failed++; }
    try { test_addp_asisdpair_only(); } catch (...) { std::cerr << "FAIL: addp_asisdpair_only" << std::endl; failed++; }
    try { test_addp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: addp_asimdsame_only" << std::endl; failed++; }
    try { test_addv_asimdall_only(); } catch (...) { std::cerr << "FAIL: addv_asimdall_only" << std::endl; failed++; }
    try { test_aesd_b_cryptoaes(); } catch (...) { std::cerr << "FAIL: aesd_b_cryptoaes" << std::endl; failed++; }
    try { test_aese_b_cryptoaes(); } catch (...) { std::cerr << "FAIL: aese_b_cryptoaes" << std::endl; failed++; }
    try { test_aesimc_b_cryptoaes(); } catch (...) { std::cerr << "FAIL: aesimc_b_cryptoaes" << std::endl; failed++; }
    try { test_aesmc_b_cryptoaes(); } catch (...) { std::cerr << "FAIL: aesmc_b_cryptoaes" << std::endl; failed++; }
    try { test_and_asimdsame_only(); } catch (...) { std::cerr << "FAIL: and_asimdsame_only" << std::endl; failed++; }
    try { test_bcax_vvv16_crypto4(); } catch (...) { std::cerr << "FAIL: bcax_vvv16_crypto4" << std::endl; failed++; }
    try { test_bf1cvtl_asimdmisc_v(); } catch (...) { std::cerr << "FAIL: bf1cvtl_asimdmisc_v" << std::endl; failed++; }
    try { test_bf2cvtl_asimdmisc_v(); } catch (...) { std::cerr << "FAIL: bf2cvtl_asimdmisc_v" << std::endl; failed++; }
    try { test_bfcvt_bs_floatdp1(); } catch (...) { std::cerr << "FAIL: bfcvt_bs_floatdp1" << std::endl; failed++; }
    try { test_bfcvtn_asimdmisc_4s(); } catch (...) { std::cerr << "FAIL: bfcvtn_asimdmisc_4s" << std::endl; failed++; }
    try { test_bfdot_asimdelem_e(); } catch (...) { std::cerr << "FAIL: bfdot_asimdelem_e" << std::endl; failed++; }
    try { test_bfdot_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: bfdot_asimdsame2_d" << std::endl; failed++; }
    try { test_bfmlal_asimdelem_f(); } catch (...) { std::cerr << "FAIL: bfmlal_asimdelem_f" << std::endl; failed++; }
    try { test_bfmlal_asimdsame2_f_(); } catch (...) { std::cerr << "FAIL: bfmlal_asimdsame2_f_" << std::endl; failed++; }
    try { test_bfmmla_asimdsame2_e(); } catch (...) { std::cerr << "FAIL: bfmmla_asimdsame2_e" << std::endl; failed++; }
    try { test_bic_asimdimm_l_hl(); } catch (...) { std::cerr << "FAIL: bic_asimdimm_l_hl" << std::endl; failed++; }
    try { test_bic_asimdimm_l_sl(); } catch (...) { std::cerr << "FAIL: bic_asimdimm_l_sl" << std::endl; failed++; }
    try { test_bic_asimdsame_only(); } catch (...) { std::cerr << "FAIL: bic_asimdsame_only" << std::endl; failed++; }
    try { test_bif_asimdsame_only(); } catch (...) { std::cerr << "FAIL: bif_asimdsame_only" << std::endl; failed++; }
    try { test_bit_asimdsame_only(); } catch (...) { std::cerr << "FAIL: bit_asimdsame_only" << std::endl; failed++; }
    try { test_bsl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: bsl_asimdsame_only" << std::endl; failed++; }
    try { test_cls_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: cls_asimdmisc_r" << std::endl; failed++; }
    try { test_clz_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: clz_asimdmisc_r" << std::endl; failed++; }
    try { test_cmeq_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmeq_asisdsame_only" << std::endl; failed++; }
    try { test_cmeq_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmeq_asimdsame_only" << std::endl; failed++; }
    try { test_cmeq_asisdmisc_z(); } catch (...) { std::cerr << "FAIL: cmeq_asisdmisc_z" << std::endl; failed++; }
    try { test_cmeq_asimdmisc_z(); } catch (...) { std::cerr << "FAIL: cmeq_asimdmisc_z" << std::endl; failed++; }
    try { test_cmge_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmge_asisdsame_only" << std::endl; failed++; }
    try { test_cmge_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmge_asimdsame_only" << std::endl; failed++; }
    try { test_cmge_asisdmisc_z(); } catch (...) { std::cerr << "FAIL: cmge_asisdmisc_z" << std::endl; failed++; }
    try { test_cmge_asimdmisc_z(); } catch (...) { std::cerr << "FAIL: cmge_asimdmisc_z" << std::endl; failed++; }
    try { test_cmgt_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmgt_asisdsame_only" << std::endl; failed++; }
    try { test_cmgt_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmgt_asimdsame_only" << std::endl; failed++; }
    try { test_cmgt_asisdmisc_z(); } catch (...) { std::cerr << "FAIL: cmgt_asisdmisc_z" << std::endl; failed++; }
    try { test_cmgt_asimdmisc_z(); } catch (...) { std::cerr << "FAIL: cmgt_asimdmisc_z" << std::endl; failed++; }
    try { test_cmhi_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmhi_asisdsame_only" << std::endl; failed++; }
    try { test_cmhi_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmhi_asimdsame_only" << std::endl; failed++; }
    try { test_cmhs_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmhs_asisdsame_only" << std::endl; failed++; }
    try { test_cmhs_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmhs_asimdsame_only" << std::endl; failed++; }
    try { test_cmle_asisdmisc_z(); } catch (...) { std::cerr << "FAIL: cmle_asisdmisc_z" << std::endl; failed++; }
    try { test_cmle_asimdmisc_z(); } catch (...) { std::cerr << "FAIL: cmle_asimdmisc_z" << std::endl; failed++; }
    try { test_cmlt_asisdmisc_z(); } catch (...) { std::cerr << "FAIL: cmlt_asisdmisc_z" << std::endl; failed++; }
    try { test_cmlt_asimdmisc_z(); } catch (...) { std::cerr << "FAIL: cmlt_asimdmisc_z" << std::endl; failed++; }
    try { test_cmtst_asisdsame_only(); } catch (...) { std::cerr << "FAIL: cmtst_asisdsame_only" << std::endl; failed++; }
    try { test_cmtst_asimdsame_only(); } catch (...) { std::cerr << "FAIL: cmtst_asimdsame_only" << std::endl; failed++; }
    try { test_cnt_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: cnt_asimdmisc_r" << std::endl; failed++; }
    try { test_dup_asisdone_only(); } catch (...) { std::cerr << "FAIL: dup_asisdone_only" << std::endl; failed++; }
    try { test_dup_asimdins_dv_v(); } catch (...) { std::cerr << "FAIL: dup_asimdins_dv_v" << std::endl; failed++; }
    try { test_dup_asimdins_dr_r(); } catch (...) { std::cerr << "FAIL: dup_asimdins_dr_r" << std::endl; failed++; }
    try { test_eor3_vvv16_crypto4(); } catch (...) { std::cerr << "FAIL: eor3_vvv16_crypto4" << std::endl; failed++; }
    try { test_eor_asimdsame_only(); } catch (...) { std::cerr << "FAIL: eor_asimdsame_only" << std::endl; failed++; }
    try { test_ext_asimdext_only(); } catch (...) { std::cerr << "FAIL: ext_asimdext_only" << std::endl; failed++; }
    try { test_f1cvtl_asimdmisc_v(); } catch (...) { std::cerr << "FAIL: f1cvtl_asimdmisc_v" << std::endl; failed++; }
    try { test_f2cvtl_asimdmisc_v(); } catch (...) { std::cerr << "FAIL: f2cvtl_asimdmisc_v" << std::endl; failed++; }
    try { test_fabd_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fabd_asisdsamefp16_only" << std::endl; failed++; }
    try { test_fabd_asisdsame_only(); } catch (...) { std::cerr << "FAIL: fabd_asisdsame_only" << std::endl; failed++; }
    try { test_fabd_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fabd_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fabd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fabd_asimdsame_only" << std::endl; failed++; }
    try { test_fabs_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fabs_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fabs_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fabs_asimdmisc_r" << std::endl; failed++; }
    try { test_fabs_h_floatdp1(); } catch (...) { std::cerr << "FAIL: fabs_h_floatdp1" << std::endl; failed++; }
    try { test_fabs_s_floatdp1(); } catch (...) { std::cerr << "FAIL: fabs_s_floatdp1" << std::endl; failed++; }
    try { test_fabs_d_floatdp1(); } catch (...) { std::cerr << "FAIL: fabs_d_floatdp1" << std::endl; failed++; }
    try { test_facge_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: facge_asisdsamefp16_only" << std::endl; failed++; }
    try { test_facge_asisdsame_only(); } catch (...) { std::cerr << "FAIL: facge_asisdsame_only" << std::endl; failed++; }
    try { test_facge_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: facge_asimdsamefp16_only" << std::endl; failed++; }
    try { test_facge_asimdsame_only(); } catch (...) { std::cerr << "FAIL: facge_asimdsame_only" << std::endl; failed++; }
    try { test_facgt_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: facgt_asisdsamefp16_only" << std::endl; failed++; }
    try { test_facgt_asisdsame_only(); } catch (...) { std::cerr << "FAIL: facgt_asisdsame_only" << std::endl; failed++; }
    try { test_facgt_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: facgt_asimdsamefp16_only" << std::endl; failed++; }
    try { test_facgt_asimdsame_only(); } catch (...) { std::cerr << "FAIL: facgt_asimdsame_only" << std::endl; failed++; }
    try { test_fadd_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fadd_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fadd_asimdsame_only" << std::endl; failed++; }
    try { test_fadd_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fadd_h_floatdp2" << std::endl; failed++; }
    try { test_fadd_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fadd_s_floatdp2" << std::endl; failed++; }
    try { test_fadd_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fadd_d_floatdp2" << std::endl; failed++; }
    try { test_faddp_asisdpair_only_h(); } catch (...) { std::cerr << "FAIL: faddp_asisdpair_only_h" << std::endl; failed++; }
    try { test_faddp_asisdpair_only_sd(); } catch (...) { std::cerr << "FAIL: faddp_asisdpair_only_sd" << std::endl; failed++; }
    try { test_faddp_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: faddp_asimdsamefp16_only" << std::endl; failed++; }
    try { test_faddp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: faddp_asimdsame_only" << std::endl; failed++; }
    try { test_famax_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: famax_asimdsamefp16_only" << std::endl; failed++; }
    try { test_famax_asimdsame_only(); } catch (...) { std::cerr << "FAIL: famax_asimdsame_only" << std::endl; failed++; }
    try { test_famin_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: famin_asimdsamefp16_only" << std::endl; failed++; }
    try { test_famin_asimdsame_only(); } catch (...) { std::cerr << "FAIL: famin_asimdsame_only" << std::endl; failed++; }
    try { test_fcadd_asimdsame2_c(); } catch (...) { std::cerr << "FAIL: fcadd_asimdsame2_c" << std::endl; failed++; }
    try { test_fccmp_h_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmp_h_floatccmp" << std::endl; failed++; }
    try { test_fccmp_s_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmp_s_floatccmp" << std::endl; failed++; }
    try { test_fccmp_d_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmp_d_floatccmp" << std::endl; failed++; }
    try { test_fccmpe_h_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmpe_h_floatccmp" << std::endl; failed++; }
    try { test_fccmpe_s_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmpe_s_floatccmp" << std::endl; failed++; }
    try { test_fccmpe_d_floatccmp(); } catch (...) { std::cerr << "FAIL: fccmpe_d_floatccmp" << std::endl; failed++; }
    try { test_fcmeq_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmeq_asisdsamefp16_only" << std::endl; failed++; }
    try { test_fcmeq_asisdsame_only(); } catch (...) { std::cerr << "FAIL: fcmeq_asisdsame_only" << std::endl; failed++; }
    try { test_fcmeq_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmeq_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fcmeq_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fcmeq_asimdsame_only" << std::endl; failed++; }
    try { test_fcmeq_asisdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmeq_asisdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmeq_asisdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmeq_asisdmisc_fz" << std::endl; failed++; }
    try { test_fcmeq_asimdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmeq_asimdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmeq_asimdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmeq_asimdmisc_fz" << std::endl; failed++; }
    try { test_fcmge_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmge_asisdsamefp16_only" << std::endl; failed++; }
    try { test_fcmge_asisdsame_only(); } catch (...) { std::cerr << "FAIL: fcmge_asisdsame_only" << std::endl; failed++; }
    try { test_fcmge_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmge_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fcmge_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fcmge_asimdsame_only" << std::endl; failed++; }
    try { test_fcmge_asisdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmge_asisdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmge_asisdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmge_asisdmisc_fz" << std::endl; failed++; }
    try { test_fcmge_asimdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmge_asimdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmge_asimdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmge_asimdmisc_fz" << std::endl; failed++; }
    try { test_fcmgt_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmgt_asisdsamefp16_only" << std::endl; failed++; }
    try { test_fcmgt_asisdsame_only(); } catch (...) { std::cerr << "FAIL: fcmgt_asisdsame_only" << std::endl; failed++; }
    try { test_fcmgt_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fcmgt_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fcmgt_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fcmgt_asimdsame_only" << std::endl; failed++; }
    try { test_fcmgt_asisdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmgt_asisdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmgt_asisdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmgt_asisdmisc_fz" << std::endl; failed++; }
    try { test_fcmgt_asimdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmgt_asimdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmgt_asimdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmgt_asimdmisc_fz" << std::endl; failed++; }
    try { test_fcmla_advsimd_elt(); } catch (...) { std::cerr << "FAIL: fcmla_advsimd_elt" << std::endl; failed++; }
    try { test_fcmla_asimdsame2_c(); } catch (...) { std::cerr << "FAIL: fcmla_asimdsame2_c" << std::endl; failed++; }
    try { test_fcmle_asisdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmle_asisdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmle_asisdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmle_asisdmisc_fz" << std::endl; failed++; }
    try { test_fcmle_asimdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmle_asimdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmle_asimdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmle_asimdmisc_fz" << std::endl; failed++; }
    try { test_fcmlt_asisdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmlt_asisdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmlt_asisdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmlt_asisdmisc_fz" << std::endl; failed++; }
    try { test_fcmlt_asimdmiscfp16_fz(); } catch (...) { std::cerr << "FAIL: fcmlt_asimdmiscfp16_fz" << std::endl; failed++; }
    try { test_fcmlt_asimdmisc_fz(); } catch (...) { std::cerr << "FAIL: fcmlt_asimdmisc_fz" << std::endl; failed++; }
    try { test_fcmp_h_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_h_floatcmp" << std::endl; failed++; }
    try { test_fcmp_hz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_hz_floatcmp" << std::endl; failed++; }
    try { test_fcmp_s_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_s_floatcmp" << std::endl; failed++; }
    try { test_fcmp_sz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_sz_floatcmp" << std::endl; failed++; }
    try { test_fcmp_d_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_d_floatcmp" << std::endl; failed++; }
    try { test_fcmp_dz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmp_dz_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_h_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_h_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_hz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_hz_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_s_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_s_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_sz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_sz_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_d_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_d_floatcmp" << std::endl; failed++; }
    try { test_fcmpe_dz_floatcmp(); } catch (...) { std::cerr << "FAIL: fcmpe_dz_floatcmp" << std::endl; failed++; }
    try { test_fcsel_h_floatsel(); } catch (...) { std::cerr << "FAIL: fcsel_h_floatsel" << std::endl; failed++; }
    try { test_fcsel_s_floatsel(); } catch (...) { std::cerr << "FAIL: fcsel_s_floatsel" << std::endl; failed++; }
    try { test_fcsel_d_floatsel(); } catch (...) { std::cerr << "FAIL: fcsel_d_floatsel" << std::endl; failed++; }
    try { test_fcvt_sh_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_sh_floatdp1" << std::endl; failed++; }
    try { test_fcvt_dh_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_dh_floatdp1" << std::endl; failed++; }
    try { test_fcvt_hs_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_hs_floatdp1" << std::endl; failed++; }
    try { test_fcvt_ds_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_ds_floatdp1" << std::endl; failed++; }
    try { test_fcvt_hd_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_hd_floatdp1" << std::endl; failed++; }
    try { test_fcvt_sd_floatdp1(); } catch (...) { std::cerr << "FAIL: fcvt_sd_floatdp1" << std::endl; failed++; }
    try { test_fcvtas_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtas_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtas_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtas_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtas_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtas_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtas_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtas_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtas_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_32h_float2int" << std::endl; failed++; }
    try { test_fcvtas_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_64h_float2int" << std::endl; failed++; }
    try { test_fcvtas_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_32s_float2int" << std::endl; failed++; }
    try { test_fcvtas_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_64s_float2int" << std::endl; failed++; }
    try { test_fcvtas_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_32d_float2int" << std::endl; failed++; }
    try { test_fcvtas_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtas_64d_float2int" << std::endl; failed++; }
    try { test_fcvtas_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtas_sisd_32h" << std::endl; failed++; }
    try { test_fcvtas_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtas_sisd_64h" << std::endl; failed++; }
    try { test_fcvtas_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtas_sisd_64s" << std::endl; failed++; }
    try { test_fcvtas_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtas_sisd_32d" << std::endl; failed++; }
    try { test_fcvtau_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtau_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtau_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtau_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtau_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtau_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtau_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtau_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtau_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_32h_float2int" << std::endl; failed++; }
    try { test_fcvtau_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_64h_float2int" << std::endl; failed++; }
    try { test_fcvtau_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_32s_float2int" << std::endl; failed++; }
    try { test_fcvtau_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_64s_float2int" << std::endl; failed++; }
    try { test_fcvtau_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_32d_float2int" << std::endl; failed++; }
    try { test_fcvtau_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtau_64d_float2int" << std::endl; failed++; }
    try { test_fcvtau_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtau_sisd_32h" << std::endl; failed++; }
    try { test_fcvtau_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtau_sisd_64h" << std::endl; failed++; }
    try { test_fcvtau_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtau_sisd_64s" << std::endl; failed++; }
    try { test_fcvtau_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtau_sisd_32d" << std::endl; failed++; }
    try { test_fcvtl_asimdmisc_l(); } catch (...) { std::cerr << "FAIL: fcvtl_asimdmisc_l" << std::endl; failed++; }
    try { test_fcvtms_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtms_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtms_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtms_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtms_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtms_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtms_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtms_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtms_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_32h_float2int" << std::endl; failed++; }
    try { test_fcvtms_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_64h_float2int" << std::endl; failed++; }
    try { test_fcvtms_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_32s_float2int" << std::endl; failed++; }
    try { test_fcvtms_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_64s_float2int" << std::endl; failed++; }
    try { test_fcvtms_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_32d_float2int" << std::endl; failed++; }
    try { test_fcvtms_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtms_64d_float2int" << std::endl; failed++; }
    try { test_fcvtms_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtms_sisd_32h" << std::endl; failed++; }
    try { test_fcvtms_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtms_sisd_64h" << std::endl; failed++; }
    try { test_fcvtms_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtms_sisd_64s" << std::endl; failed++; }
    try { test_fcvtms_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtms_sisd_32d" << std::endl; failed++; }
    try { test_fcvtmu_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtmu_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtmu_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtmu_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtmu_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtmu_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtmu_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtmu_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtmu_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_32h_float2int" << std::endl; failed++; }
    try { test_fcvtmu_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_64h_float2int" << std::endl; failed++; }
    try { test_fcvtmu_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_32s_float2int" << std::endl; failed++; }
    try { test_fcvtmu_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_64s_float2int" << std::endl; failed++; }
    try { test_fcvtmu_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_32d_float2int" << std::endl; failed++; }
    try { test_fcvtmu_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtmu_64d_float2int" << std::endl; failed++; }
    try { test_fcvtmu_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtmu_sisd_32h" << std::endl; failed++; }
    try { test_fcvtmu_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtmu_sisd_64h" << std::endl; failed++; }
    try { test_fcvtmu_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtmu_sisd_64s" << std::endl; failed++; }
    try { test_fcvtmu_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtmu_sisd_32d" << std::endl; failed++; }
    try { test_fcvtn_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: fcvtn_asimdmisc_n" << std::endl; failed++; }
    try { test_fcvtn_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: fcvtn_asimdsame2_d" << std::endl; failed++; }
    try { test_fcvtn_asimdsame2_h(); } catch (...) { std::cerr << "FAIL: fcvtn_asimdsame2_h" << std::endl; failed++; }
    try { test_fcvtns_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtns_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtns_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtns_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtns_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtns_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtns_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtns_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtns_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_32h_float2int" << std::endl; failed++; }
    try { test_fcvtns_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_64h_float2int" << std::endl; failed++; }
    try { test_fcvtns_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_32s_float2int" << std::endl; failed++; }
    try { test_fcvtns_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_64s_float2int" << std::endl; failed++; }
    try { test_fcvtns_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_32d_float2int" << std::endl; failed++; }
    try { test_fcvtns_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtns_64d_float2int" << std::endl; failed++; }
    try { test_fcvtns_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtns_sisd_32h" << std::endl; failed++; }
    try { test_fcvtns_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtns_sisd_64h" << std::endl; failed++; }
    try { test_fcvtns_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtns_sisd_64s" << std::endl; failed++; }
    try { test_fcvtns_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtns_sisd_32d" << std::endl; failed++; }
    try { test_fcvtnu_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtnu_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtnu_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtnu_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtnu_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtnu_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtnu_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtnu_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtnu_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_32h_float2int" << std::endl; failed++; }
    try { test_fcvtnu_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_64h_float2int" << std::endl; failed++; }
    try { test_fcvtnu_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_32s_float2int" << std::endl; failed++; }
    try { test_fcvtnu_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_64s_float2int" << std::endl; failed++; }
    try { test_fcvtnu_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_32d_float2int" << std::endl; failed++; }
    try { test_fcvtnu_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtnu_64d_float2int" << std::endl; failed++; }
    try { test_fcvtnu_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtnu_sisd_32h" << std::endl; failed++; }
    try { test_fcvtnu_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtnu_sisd_64h" << std::endl; failed++; }
    try { test_fcvtnu_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtnu_sisd_64s" << std::endl; failed++; }
    try { test_fcvtnu_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtnu_sisd_32d" << std::endl; failed++; }
    try { test_fcvtps_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtps_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtps_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtps_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtps_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtps_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtps_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtps_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtps_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_32h_float2int" << std::endl; failed++; }
    try { test_fcvtps_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_64h_float2int" << std::endl; failed++; }
    try { test_fcvtps_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_32s_float2int" << std::endl; failed++; }
    try { test_fcvtps_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_64s_float2int" << std::endl; failed++; }
    try { test_fcvtps_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_32d_float2int" << std::endl; failed++; }
    try { test_fcvtps_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtps_64d_float2int" << std::endl; failed++; }
    try { test_fcvtps_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtps_sisd_32h" << std::endl; failed++; }
    try { test_fcvtps_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtps_sisd_64h" << std::endl; failed++; }
    try { test_fcvtps_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtps_sisd_64s" << std::endl; failed++; }
    try { test_fcvtps_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtps_sisd_32d" << std::endl; failed++; }
    try { test_fcvtpu_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtpu_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtpu_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtpu_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtpu_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtpu_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtpu_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtpu_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtpu_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_32h_float2int" << std::endl; failed++; }
    try { test_fcvtpu_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_64h_float2int" << std::endl; failed++; }
    try { test_fcvtpu_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_32s_float2int" << std::endl; failed++; }
    try { test_fcvtpu_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_64s_float2int" << std::endl; failed++; }
    try { test_fcvtpu_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_32d_float2int" << std::endl; failed++; }
    try { test_fcvtpu_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtpu_64d_float2int" << std::endl; failed++; }
    try { test_fcvtpu_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtpu_sisd_32h" << std::endl; failed++; }
    try { test_fcvtpu_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtpu_sisd_64h" << std::endl; failed++; }
    try { test_fcvtpu_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtpu_sisd_64s" << std::endl; failed++; }
    try { test_fcvtpu_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtpu_sisd_32d" << std::endl; failed++; }
    try { test_fcvtxn_asisdmisc_n(); } catch (...) { std::cerr << "FAIL: fcvtxn_asisdmisc_n" << std::endl; failed++; }
    try { test_fcvtxn_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: fcvtxn_asimdmisc_n" << std::endl; failed++; }
    try { test_fcvtzs_asisdshf_c(); } catch (...) { std::cerr << "FAIL: fcvtzs_asisdshf_c" << std::endl; failed++; }
    try { test_fcvtzs_asimdshf_c(); } catch (...) { std::cerr << "FAIL: fcvtzs_asimdshf_c" << std::endl; failed++; }
    try { test_fcvtzs_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtzs_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtzs_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtzs_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtzs_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtzs_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtzs_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtzs_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtzs_32h_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_32h_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_64h_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_64h_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_32s_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_32s_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_64s_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_64s_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_32d_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_32d_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_64d_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzs_64d_float2fix" << std::endl; failed++; }
    try { test_fcvtzs_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_32h_float2int" << std::endl; failed++; }
    try { test_fcvtzs_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_64h_float2int" << std::endl; failed++; }
    try { test_fcvtzs_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_32s_float2int" << std::endl; failed++; }
    try { test_fcvtzs_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_64s_float2int" << std::endl; failed++; }
    try { test_fcvtzs_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_32d_float2int" << std::endl; failed++; }
    try { test_fcvtzs_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzs_64d_float2int" << std::endl; failed++; }
    try { test_fcvtzs_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtzs_sisd_32h" << std::endl; failed++; }
    try { test_fcvtzs_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtzs_sisd_64h" << std::endl; failed++; }
    try { test_fcvtzs_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtzs_sisd_64s" << std::endl; failed++; }
    try { test_fcvtzs_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtzs_sisd_32d" << std::endl; failed++; }
    try { test_fcvtzu_asisdshf_c(); } catch (...) { std::cerr << "FAIL: fcvtzu_asisdshf_c" << std::endl; failed++; }
    try { test_fcvtzu_asimdshf_c(); } catch (...) { std::cerr << "FAIL: fcvtzu_asimdshf_c" << std::endl; failed++; }
    try { test_fcvtzu_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtzu_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtzu_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtzu_asisdmisc_r" << std::endl; failed++; }
    try { test_fcvtzu_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fcvtzu_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fcvtzu_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fcvtzu_asimdmisc_r" << std::endl; failed++; }
    try { test_fcvtzu_32h_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_32h_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_64h_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_64h_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_32s_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_32s_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_64s_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_64s_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_32d_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_32d_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_64d_float2fix(); } catch (...) { std::cerr << "FAIL: fcvtzu_64d_float2fix" << std::endl; failed++; }
    try { test_fcvtzu_32h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_32h_float2int" << std::endl; failed++; }
    try { test_fcvtzu_64h_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_64h_float2int" << std::endl; failed++; }
    try { test_fcvtzu_32s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_32s_float2int" << std::endl; failed++; }
    try { test_fcvtzu_64s_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_64s_float2int" << std::endl; failed++; }
    try { test_fcvtzu_32d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_32d_float2int" << std::endl; failed++; }
    try { test_fcvtzu_64d_float2int(); } catch (...) { std::cerr << "FAIL: fcvtzu_64d_float2int" << std::endl; failed++; }
    try { test_fcvtzu_sisd_32h(); } catch (...) { std::cerr << "FAIL: fcvtzu_sisd_32h" << std::endl; failed++; }
    try { test_fcvtzu_sisd_64h(); } catch (...) { std::cerr << "FAIL: fcvtzu_sisd_64h" << std::endl; failed++; }
    try { test_fcvtzu_sisd_64s(); } catch (...) { std::cerr << "FAIL: fcvtzu_sisd_64s" << std::endl; failed++; }
    try { test_fcvtzu_sisd_32d(); } catch (...) { std::cerr << "FAIL: fcvtzu_sisd_32d" << std::endl; failed++; }
    try { test_fdiv_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fdiv_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fdiv_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fdiv_asimdsame_only" << std::endl; failed++; }
    try { test_fdiv_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fdiv_h_floatdp2" << std::endl; failed++; }
    try { test_fdiv_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fdiv_s_floatdp2" << std::endl; failed++; }
    try { test_fdiv_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fdiv_d_floatdp2" << std::endl; failed++; }
    try { test_fdot_asimdelem_g(); } catch (...) { std::cerr << "FAIL: fdot_asimdelem_g" << std::endl; failed++; }
    try { test_fdot_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: fdot_asimdsame2_d" << std::endl; failed++; }
    try { test_fdot_asimdelem_d(); } catch (...) { std::cerr << "FAIL: fdot_asimdelem_d" << std::endl; failed++; }
    try { test_fdot_asimdsame2_dd(); } catch (...) { std::cerr << "FAIL: fdot_asimdsame2_dd" << std::endl; failed++; }
    try { test_fdot_asimdelem_fp16fp32(); } catch (...) { std::cerr << "FAIL: fdot_asimdelem_fp16fp32" << std::endl; failed++; }
    try { test_fdot_asimdsame2_fp16fp32(); } catch (...) { std::cerr << "FAIL: fdot_asimdsame2_fp16fp32" << std::endl; failed++; }
    try { test_fjcvtzs_32d_float2int(); } catch (...) { std::cerr << "FAIL: fjcvtzs_32d_float2int" << std::endl; failed++; }
    try { test_fmadd_h_floatdp3(); } catch (...) { std::cerr << "FAIL: fmadd_h_floatdp3" << std::endl; failed++; }
    try { test_fmadd_s_floatdp3(); } catch (...) { std::cerr << "FAIL: fmadd_s_floatdp3" << std::endl; failed++; }
    try { test_fmadd_d_floatdp3(); } catch (...) { std::cerr << "FAIL: fmadd_d_floatdp3" << std::endl; failed++; }
    try { test_fmax_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmax_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmax_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmax_asimdsame_only" << std::endl; failed++; }
    try { test_fmax_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fmax_h_floatdp2" << std::endl; failed++; }
    try { test_fmax_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fmax_s_floatdp2" << std::endl; failed++; }
    try { test_fmax_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fmax_d_floatdp2" << std::endl; failed++; }
    try { test_fmaxnm_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmaxnm_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmaxnm_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmaxnm_asimdsame_only" << std::endl; failed++; }
    try { test_fmaxnm_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fmaxnm_h_floatdp2" << std::endl; failed++; }
    try { test_fmaxnm_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fmaxnm_s_floatdp2" << std::endl; failed++; }
    try { test_fmaxnm_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fmaxnm_d_floatdp2" << std::endl; failed++; }
    try { test_fmaxnmp_asisdpair_only_h(); } catch (...) { std::cerr << "FAIL: fmaxnmp_asisdpair_only_h" << std::endl; failed++; }
    try { test_fmaxnmp_asisdpair_only_sd(); } catch (...) { std::cerr << "FAIL: fmaxnmp_asisdpair_only_sd" << std::endl; failed++; }
    try { test_fmaxnmp_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmaxnmp_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmaxnmp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmaxnmp_asimdsame_only" << std::endl; failed++; }
    try { test_fmaxnmv_asimdall_only_h(); } catch (...) { std::cerr << "FAIL: fmaxnmv_asimdall_only_h" << std::endl; failed++; }
    try { test_fmaxnmv_asimdall_only_sd(); } catch (...) { std::cerr << "FAIL: fmaxnmv_asimdall_only_sd" << std::endl; failed++; }
    try { test_fmaxp_asisdpair_only_h(); } catch (...) { std::cerr << "FAIL: fmaxp_asisdpair_only_h" << std::endl; failed++; }
    try { test_fmaxp_asisdpair_only_sd(); } catch (...) { std::cerr << "FAIL: fmaxp_asisdpair_only_sd" << std::endl; failed++; }
    try { test_fmaxp_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmaxp_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmaxp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmaxp_asimdsame_only" << std::endl; failed++; }
    try { test_fmaxv_asimdall_only_h(); } catch (...) { std::cerr << "FAIL: fmaxv_asimdall_only_h" << std::endl; failed++; }
    try { test_fmaxv_asimdall_only_sd(); } catch (...) { std::cerr << "FAIL: fmaxv_asimdall_only_sd" << std::endl; failed++; }
    try { test_fmin_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmin_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmin_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmin_asimdsame_only" << std::endl; failed++; }
    try { test_fmin_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fmin_h_floatdp2" << std::endl; failed++; }
    try { test_fmin_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fmin_s_floatdp2" << std::endl; failed++; }
    try { test_fmin_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fmin_d_floatdp2" << std::endl; failed++; }
    try { test_fminnm_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fminnm_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fminnm_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fminnm_asimdsame_only" << std::endl; failed++; }
    try { test_fminnm_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fminnm_h_floatdp2" << std::endl; failed++; }
    try { test_fminnm_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fminnm_s_floatdp2" << std::endl; failed++; }
    try { test_fminnm_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fminnm_d_floatdp2" << std::endl; failed++; }
    try { test_fminnmp_asisdpair_only_h(); } catch (...) { std::cerr << "FAIL: fminnmp_asisdpair_only_h" << std::endl; failed++; }
    try { test_fminnmp_asisdpair_only_sd(); } catch (...) { std::cerr << "FAIL: fminnmp_asisdpair_only_sd" << std::endl; failed++; }
    try { test_fminnmp_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fminnmp_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fminnmp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fminnmp_asimdsame_only" << std::endl; failed++; }
    try { test_fminnmv_asimdall_only_h(); } catch (...) { std::cerr << "FAIL: fminnmv_asimdall_only_h" << std::endl; failed++; }
    try { test_fminnmv_asimdall_only_sd(); } catch (...) { std::cerr << "FAIL: fminnmv_asimdall_only_sd" << std::endl; failed++; }
    try { test_fminp_asisdpair_only_h(); } catch (...) { std::cerr << "FAIL: fminp_asisdpair_only_h" << std::endl; failed++; }
    try { test_fminp_asisdpair_only_sd(); } catch (...) { std::cerr << "FAIL: fminp_asisdpair_only_sd" << std::endl; failed++; }
    try { test_fminp_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fminp_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fminp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fminp_asimdsame_only" << std::endl; failed++; }
    try { test_fminv_asimdall_only_h(); } catch (...) { std::cerr << "FAIL: fminv_asimdall_only_h" << std::endl; failed++; }
    try { test_fminv_asimdall_only_sd(); } catch (...) { std::cerr << "FAIL: fminv_asimdall_only_sd" << std::endl; failed++; }
    try { test_fmla_asisdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmla_asisdelem_rh_h" << std::endl; failed++; }
    try { test_fmla_asisdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmla_asisdelem_r_sd" << std::endl; failed++; }
    try { test_fmla_asimdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmla_asimdelem_rh_h" << std::endl; failed++; }
    try { test_fmla_asimdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmla_asimdelem_r_sd" << std::endl; failed++; }
    try { test_fmla_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmla_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmla_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmla_asimdsame_only" << std::endl; failed++; }
    try { test_fmlal_asimdelem_lh(); } catch (...) { std::cerr << "FAIL: fmlal_asimdelem_lh" << std::endl; failed++; }
    try { test_fmlal2_asimdelem_lh(); } catch (...) { std::cerr << "FAIL: fmlal2_asimdelem_lh" << std::endl; failed++; }
    try { test_fmlal_asimdsame_f(); } catch (...) { std::cerr << "FAIL: fmlal_asimdsame_f" << std::endl; failed++; }
    try { test_fmlal2_asimdsame_f(); } catch (...) { std::cerr << "FAIL: fmlal2_asimdsame_f" << std::endl; failed++; }
    try { test_fmlalb_asimdelem_h(); } catch (...) { std::cerr << "FAIL: fmlalb_asimdelem_h" << std::endl; failed++; }
    try { test_fmlalt_asimdelem_h(); } catch (...) { std::cerr << "FAIL: fmlalt_asimdelem_h" << std::endl; failed++; }
    try { test_fmlalb_asimdsame2_j(); } catch (...) { std::cerr << "FAIL: fmlalb_asimdsame2_j" << std::endl; failed++; }
    try { test_fmlalt_asimdsame2_j(); } catch (...) { std::cerr << "FAIL: fmlalt_asimdsame2_j" << std::endl; failed++; }
    try { test_fmlallbb_asimdelem_j(); } catch (...) { std::cerr << "FAIL: fmlallbb_asimdelem_j" << std::endl; failed++; }
    try { test_fmlallbt_asimdelem_j(); } catch (...) { std::cerr << "FAIL: fmlallbt_asimdelem_j" << std::endl; failed++; }
    try { test_fmlalltb_asimdelem_j(); } catch (...) { std::cerr << "FAIL: fmlalltb_asimdelem_j" << std::endl; failed++; }
    try { test_fmlalltt_asimdelem_j(); } catch (...) { std::cerr << "FAIL: fmlalltt_asimdelem_j" << std::endl; failed++; }
    try { test_fmlallbb_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: fmlallbb_asimdsame2_g" << std::endl; failed++; }
    try { test_fmlallbt_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: fmlallbt_asimdsame2_g" << std::endl; failed++; }
    try { test_fmlalltb_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: fmlalltb_asimdsame2_g" << std::endl; failed++; }
    try { test_fmlalltt_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: fmlalltt_asimdsame2_g" << std::endl; failed++; }
    try { test_fmls_asisdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmls_asisdelem_rh_h" << std::endl; failed++; }
    try { test_fmls_asisdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmls_asisdelem_r_sd" << std::endl; failed++; }
    try { test_fmls_asimdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmls_asimdelem_rh_h" << std::endl; failed++; }
    try { test_fmls_asimdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmls_asimdelem_r_sd" << std::endl; failed++; }
    try { test_fmls_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmls_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmls_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmls_asimdsame_only" << std::endl; failed++; }
    try { test_fmlsl_asimdelem_lh(); } catch (...) { std::cerr << "FAIL: fmlsl_asimdelem_lh" << std::endl; failed++; }
    try { test_fmlsl2_asimdelem_lh(); } catch (...) { std::cerr << "FAIL: fmlsl2_asimdelem_lh" << std::endl; failed++; }
    try { test_fmlsl_asimdsame_f(); } catch (...) { std::cerr << "FAIL: fmlsl_asimdsame_f" << std::endl; failed++; }
    try { test_fmlsl2_asimdsame_f(); } catch (...) { std::cerr << "FAIL: fmlsl2_asimdsame_f" << std::endl; failed++; }
    try { test_fmmla_asimd_fp16fp16(); } catch (...) { std::cerr << "FAIL: fmmla_asimd_fp16fp16" << std::endl; failed++; }
    try { test_fmmla_asimd_fp16fp32(); } catch (...) { std::cerr << "FAIL: fmmla_asimd_fp16fp32" << std::endl; failed++; }
    try { test_fmmla_asimd_fp8fp16(); } catch (...) { std::cerr << "FAIL: fmmla_asimd_fp8fp16" << std::endl; failed++; }
    try { test_fmmla_asimd_fp8fp32(); } catch (...) { std::cerr << "FAIL: fmmla_asimd_fp8fp32" << std::endl; failed++; }
    try { test_fmov_asimdimm_h_h(); } catch (...) { std::cerr << "FAIL: fmov_asimdimm_h_h" << std::endl; failed++; }
    try { test_fmov_asimdimm_s_s(); } catch (...) { std::cerr << "FAIL: fmov_asimdimm_s_s" << std::endl; failed++; }
    try { test_fmov_asimdimm_d2_d(); } catch (...) { std::cerr << "FAIL: fmov_asimdimm_d2_d" << std::endl; failed++; }
    try { test_fmov_h_floatdp1(); } catch (...) { std::cerr << "FAIL: fmov_h_floatdp1" << std::endl; failed++; }
    try { test_fmov_s_floatdp1(); } catch (...) { std::cerr << "FAIL: fmov_s_floatdp1" << std::endl; failed++; }
    try { test_fmov_d_floatdp1(); } catch (...) { std::cerr << "FAIL: fmov_d_floatdp1" << std::endl; failed++; }
    try { test_fmov_32h_float2int(); } catch (...) { std::cerr << "FAIL: fmov_32h_float2int" << std::endl; failed++; }
    try { test_fmov_64h_float2int(); } catch (...) { std::cerr << "FAIL: fmov_64h_float2int" << std::endl; failed++; }
    try { test_fmov_h32_float2int(); } catch (...) { std::cerr << "FAIL: fmov_h32_float2int" << std::endl; failed++; }
    try { test_fmov_s32_float2int(); } catch (...) { std::cerr << "FAIL: fmov_s32_float2int" << std::endl; failed++; }
    try { test_fmov_32s_float2int(); } catch (...) { std::cerr << "FAIL: fmov_32s_float2int" << std::endl; failed++; }
    try { test_fmov_h64_float2int(); } catch (...) { std::cerr << "FAIL: fmov_h64_float2int" << std::endl; failed++; }
    try { test_fmov_d64_float2int(); } catch (...) { std::cerr << "FAIL: fmov_d64_float2int" << std::endl; failed++; }
    try { test_fmov_v64i_float2int(); } catch (...) { std::cerr << "FAIL: fmov_v64i_float2int" << std::endl; failed++; }
    try { test_fmov_64d_float2int(); } catch (...) { std::cerr << "FAIL: fmov_64d_float2int" << std::endl; failed++; }
    try { test_fmov_64vx_float2int(); } catch (...) { std::cerr << "FAIL: fmov_64vx_float2int" << std::endl; failed++; }
    try { test_fmov_h_floatimm(); } catch (...) { std::cerr << "FAIL: fmov_h_floatimm" << std::endl; failed++; }
    try { test_fmov_s_floatimm(); } catch (...) { std::cerr << "FAIL: fmov_s_floatimm" << std::endl; failed++; }
    try { test_fmov_d_floatimm(); } catch (...) { std::cerr << "FAIL: fmov_d_floatimm" << std::endl; failed++; }
    try { test_fmsub_h_floatdp3(); } catch (...) { std::cerr << "FAIL: fmsub_h_floatdp3" << std::endl; failed++; }
    try { test_fmsub_s_floatdp3(); } catch (...) { std::cerr << "FAIL: fmsub_s_floatdp3" << std::endl; failed++; }
    try { test_fmsub_d_floatdp3(); } catch (...) { std::cerr << "FAIL: fmsub_d_floatdp3" << std::endl; failed++; }
    try { test_fmul_asisdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmul_asisdelem_rh_h" << std::endl; failed++; }
    try { test_fmul_asisdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmul_asisdelem_r_sd" << std::endl; failed++; }
    try { test_fmul_asimdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmul_asimdelem_rh_h" << std::endl; failed++; }
    try { test_fmul_asimdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmul_asimdelem_r_sd" << std::endl; failed++; }
    try { test_fmul_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmul_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmul_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmul_asimdsame_only" << std::endl; failed++; }
    try { test_fmul_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fmul_h_floatdp2" << std::endl; failed++; }
    try { test_fmul_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fmul_s_floatdp2" << std::endl; failed++; }
    try { test_fmul_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fmul_d_floatdp2" << std::endl; failed++; }
    try { test_fmulx_asisdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmulx_asisdelem_rh_h" << std::endl; failed++; }
    try { test_fmulx_asisdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmulx_asisdelem_r_sd" << std::endl; failed++; }
    try { test_fmulx_asimdelem_rh_h(); } catch (...) { std::cerr << "FAIL: fmulx_asimdelem_rh_h" << std::endl; failed++; }
    try { test_fmulx_asimdelem_r_sd(); } catch (...) { std::cerr << "FAIL: fmulx_asimdelem_r_sd" << std::endl; failed++; }
    try { test_fmulx_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmulx_asisdsamefp16_only" << std::endl; failed++; }
    try { test_fmulx_asisdsame_only(); } catch (...) { std::cerr << "FAIL: fmulx_asisdsame_only" << std::endl; failed++; }
    try { test_fmulx_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fmulx_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fmulx_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fmulx_asimdsame_only" << std::endl; failed++; }
    try { test_fneg_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fneg_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fneg_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fneg_asimdmisc_r" << std::endl; failed++; }
    try { test_fneg_h_floatdp1(); } catch (...) { std::cerr << "FAIL: fneg_h_floatdp1" << std::endl; failed++; }
    try { test_fneg_s_floatdp1(); } catch (...) { std::cerr << "FAIL: fneg_s_floatdp1" << std::endl; failed++; }
    try { test_fneg_d_floatdp1(); } catch (...) { std::cerr << "FAIL: fneg_d_floatdp1" << std::endl; failed++; }
    try { test_fnmadd_h_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmadd_h_floatdp3" << std::endl; failed++; }
    try { test_fnmadd_s_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmadd_s_floatdp3" << std::endl; failed++; }
    try { test_fnmadd_d_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmadd_d_floatdp3" << std::endl; failed++; }
    try { test_fnmsub_h_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmsub_h_floatdp3" << std::endl; failed++; }
    try { test_fnmsub_s_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmsub_s_floatdp3" << std::endl; failed++; }
    try { test_fnmsub_d_floatdp3(); } catch (...) { std::cerr << "FAIL: fnmsub_d_floatdp3" << std::endl; failed++; }
    try { test_fnmul_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fnmul_h_floatdp2" << std::endl; failed++; }
    try { test_fnmul_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fnmul_s_floatdp2" << std::endl; failed++; }
    try { test_fnmul_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fnmul_d_floatdp2" << std::endl; failed++; }
    try { test_frecpe_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frecpe_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_frecpe_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: frecpe_asisdmisc_r" << std::endl; failed++; }
    try { test_frecpe_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frecpe_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frecpe_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frecpe_asimdmisc_r" << std::endl; failed++; }
    try { test_frecps_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: frecps_asisdsamefp16_only" << std::endl; failed++; }
    try { test_frecps_asisdsame_only(); } catch (...) { std::cerr << "FAIL: frecps_asisdsame_only" << std::endl; failed++; }
    try { test_frecps_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: frecps_asimdsamefp16_only" << std::endl; failed++; }
    try { test_frecps_asimdsame_only(); } catch (...) { std::cerr << "FAIL: frecps_asimdsame_only" << std::endl; failed++; }
    try { test_frecpx_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frecpx_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_frecpx_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: frecpx_asisdmisc_r" << std::endl; failed++; }
    try { test_frint32x_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frint32x_asimdmisc_r" << std::endl; failed++; }
    try { test_frint32x_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frint32x_s_floatdp1" << std::endl; failed++; }
    try { test_frint32x_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frint32x_d_floatdp1" << std::endl; failed++; }
    try { test_frint32z_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frint32z_asimdmisc_r" << std::endl; failed++; }
    try { test_frint32z_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frint32z_s_floatdp1" << std::endl; failed++; }
    try { test_frint32z_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frint32z_d_floatdp1" << std::endl; failed++; }
    try { test_frint64x_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frint64x_asimdmisc_r" << std::endl; failed++; }
    try { test_frint64x_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frint64x_s_floatdp1" << std::endl; failed++; }
    try { test_frint64x_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frint64x_d_floatdp1" << std::endl; failed++; }
    try { test_frint64z_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frint64z_asimdmisc_r" << std::endl; failed++; }
    try { test_frint64z_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frint64z_s_floatdp1" << std::endl; failed++; }
    try { test_frint64z_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frint64z_d_floatdp1" << std::endl; failed++; }
    try { test_frinta_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frinta_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frinta_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frinta_asimdmisc_r" << std::endl; failed++; }
    try { test_frinta_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frinta_h_floatdp1" << std::endl; failed++; }
    try { test_frinta_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frinta_s_floatdp1" << std::endl; failed++; }
    try { test_frinta_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frinta_d_floatdp1" << std::endl; failed++; }
    try { test_frinti_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frinti_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frinti_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frinti_asimdmisc_r" << std::endl; failed++; }
    try { test_frinti_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frinti_h_floatdp1" << std::endl; failed++; }
    try { test_frinti_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frinti_s_floatdp1" << std::endl; failed++; }
    try { test_frinti_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frinti_d_floatdp1" << std::endl; failed++; }
    try { test_frintm_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frintm_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frintm_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frintm_asimdmisc_r" << std::endl; failed++; }
    try { test_frintm_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frintm_h_floatdp1" << std::endl; failed++; }
    try { test_frintm_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frintm_s_floatdp1" << std::endl; failed++; }
    try { test_frintm_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frintm_d_floatdp1" << std::endl; failed++; }
    try { test_frintn_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frintn_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frintn_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frintn_asimdmisc_r" << std::endl; failed++; }
    try { test_frintn_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frintn_h_floatdp1" << std::endl; failed++; }
    try { test_frintn_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frintn_s_floatdp1" << std::endl; failed++; }
    try { test_frintn_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frintn_d_floatdp1" << std::endl; failed++; }
    try { test_frintp_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frintp_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frintp_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frintp_asimdmisc_r" << std::endl; failed++; }
    try { test_frintp_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frintp_h_floatdp1" << std::endl; failed++; }
    try { test_frintp_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frintp_s_floatdp1" << std::endl; failed++; }
    try { test_frintp_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frintp_d_floatdp1" << std::endl; failed++; }
    try { test_frintx_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frintx_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frintx_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frintx_asimdmisc_r" << std::endl; failed++; }
    try { test_frintx_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frintx_h_floatdp1" << std::endl; failed++; }
    try { test_frintx_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frintx_s_floatdp1" << std::endl; failed++; }
    try { test_frintx_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frintx_d_floatdp1" << std::endl; failed++; }
    try { test_frintz_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frintz_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frintz_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frintz_asimdmisc_r" << std::endl; failed++; }
    try { test_frintz_h_floatdp1(); } catch (...) { std::cerr << "FAIL: frintz_h_floatdp1" << std::endl; failed++; }
    try { test_frintz_s_floatdp1(); } catch (...) { std::cerr << "FAIL: frintz_s_floatdp1" << std::endl; failed++; }
    try { test_frintz_d_floatdp1(); } catch (...) { std::cerr << "FAIL: frintz_d_floatdp1" << std::endl; failed++; }
    try { test_frsqrte_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frsqrte_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_frsqrte_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: frsqrte_asisdmisc_r" << std::endl; failed++; }
    try { test_frsqrte_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: frsqrte_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_frsqrte_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: frsqrte_asimdmisc_r" << std::endl; failed++; }
    try { test_frsqrts_asisdsamefp16_only(); } catch (...) { std::cerr << "FAIL: frsqrts_asisdsamefp16_only" << std::endl; failed++; }
    try { test_frsqrts_asisdsame_only(); } catch (...) { std::cerr << "FAIL: frsqrts_asisdsame_only" << std::endl; failed++; }
    try { test_frsqrts_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: frsqrts_asimdsamefp16_only" << std::endl; failed++; }
    try { test_frsqrts_asimdsame_only(); } catch (...) { std::cerr << "FAIL: frsqrts_asimdsame_only" << std::endl; failed++; }
    try { test_fscale_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fscale_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fscale_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fscale_asimdsame_only" << std::endl; failed++; }
    try { test_fsqrt_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: fsqrt_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_fsqrt_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: fsqrt_asimdmisc_r" << std::endl; failed++; }
    try { test_fsqrt_h_floatdp1(); } catch (...) { std::cerr << "FAIL: fsqrt_h_floatdp1" << std::endl; failed++; }
    try { test_fsqrt_s_floatdp1(); } catch (...) { std::cerr << "FAIL: fsqrt_s_floatdp1" << std::endl; failed++; }
    try { test_fsqrt_d_floatdp1(); } catch (...) { std::cerr << "FAIL: fsqrt_d_floatdp1" << std::endl; failed++; }
    try { test_fsub_asimdsamefp16_only(); } catch (...) { std::cerr << "FAIL: fsub_asimdsamefp16_only" << std::endl; failed++; }
    try { test_fsub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: fsub_asimdsame_only" << std::endl; failed++; }
    try { test_fsub_h_floatdp2(); } catch (...) { std::cerr << "FAIL: fsub_h_floatdp2" << std::endl; failed++; }
    try { test_fsub_s_floatdp2(); } catch (...) { std::cerr << "FAIL: fsub_s_floatdp2" << std::endl; failed++; }
    try { test_fsub_d_floatdp2(); } catch (...) { std::cerr << "FAIL: fsub_d_floatdp2" << std::endl; failed++; }
    try { test_ins_asimdins_iv_v(); } catch (...) { std::cerr << "FAIL: ins_asimdins_iv_v" << std::endl; failed++; }
    try { test_ins_asimdins_ir_r(); } catch (...) { std::cerr << "FAIL: ins_asimdins_ir_r" << std::endl; failed++; }
    try { test_luti2_asimdtbl_l5(); } catch (...) { std::cerr << "FAIL: luti2_asimdtbl_l5" << std::endl; failed++; }
    try { test_luti2_asimdtbl_l6(); } catch (...) { std::cerr << "FAIL: luti2_asimdtbl_l6" << std::endl; failed++; }
    try { test_luti4_asimdtbl_l5(); } catch (...) { std::cerr << "FAIL: luti4_asimdtbl_l5" << std::endl; failed++; }
    try { test_luti4_asimdtbl_l7(); } catch (...) { std::cerr << "FAIL: luti4_asimdtbl_l7" << std::endl; failed++; }
    try { test_mla_asimdelem_r(); } catch (...) { std::cerr << "FAIL: mla_asimdelem_r" << std::endl; failed++; }
    try { test_mla_asimdsame_only(); } catch (...) { std::cerr << "FAIL: mla_asimdsame_only" << std::endl; failed++; }
    try { test_mls_asimdelem_r(); } catch (...) { std::cerr << "FAIL: mls_asimdelem_r" << std::endl; failed++; }
    try { test_mls_asimdsame_only(); } catch (...) { std::cerr << "FAIL: mls_asimdsame_only" << std::endl; failed++; }
    try { test_mov_dup_asisdone_only(); } catch (...) { std::cerr << "FAIL: mov_dup_asisdone_only" << std::endl; failed++; }
    try { test_mov_ins_asimdins_iv_v(); } catch (...) { std::cerr << "FAIL: mov_ins_asimdins_iv_v" << std::endl; failed++; }
    try { test_mov_ins_asimdins_ir_r(); } catch (...) { std::cerr << "FAIL: mov_ins_asimdins_ir_r" << std::endl; failed++; }
    try { test_mov_orr_asimdsame_only(); } catch (...) { std::cerr << "FAIL: mov_orr_asimdsame_only" << std::endl; failed++; }
    try { test_mov_umov_asimdins_w_w(); } catch (...) { std::cerr << "FAIL: mov_umov_asimdins_w_w" << std::endl; failed++; }
    try { test_mov_umov_asimdins_x_x(); } catch (...) { std::cerr << "FAIL: mov_umov_asimdins_x_x" << std::endl; failed++; }
    try { test_movi_asimdimm_n_b(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_n_b" << std::endl; failed++; }
    try { test_movi_asimdimm_l_hl(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_l_hl" << std::endl; failed++; }
    try { test_movi_asimdimm_l_sl(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_l_sl" << std::endl; failed++; }
    try { test_movi_asimdimm_m_sm(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_m_sm" << std::endl; failed++; }
    try { test_movi_asimdimm_d_ds(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_d_ds" << std::endl; failed++; }
    try { test_movi_asimdimm_d2_d(); } catch (...) { std::cerr << "FAIL: movi_asimdimm_d2_d" << std::endl; failed++; }
    try { test_mul_asimdelem_r(); } catch (...) { std::cerr << "FAIL: mul_asimdelem_r" << std::endl; failed++; }
    try { test_mul_asimdsame_only(); } catch (...) { std::cerr << "FAIL: mul_asimdsame_only" << std::endl; failed++; }
    try { test_mvn_not_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: mvn_not_asimdmisc_r" << std::endl; failed++; }
    try { test_mvni_asimdimm_l_hl(); } catch (...) { std::cerr << "FAIL: mvni_asimdimm_l_hl" << std::endl; failed++; }
    try { test_mvni_asimdimm_l_sl(); } catch (...) { std::cerr << "FAIL: mvni_asimdimm_l_sl" << std::endl; failed++; }
    try { test_mvni_asimdimm_m_sm(); } catch (...) { std::cerr << "FAIL: mvni_asimdimm_m_sm" << std::endl; failed++; }
    try { test_neg_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: neg_asisdmisc_r" << std::endl; failed++; }
    try { test_neg_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: neg_asimdmisc_r" << std::endl; failed++; }
    try { test_not_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: not_asimdmisc_r" << std::endl; failed++; }
    try { test_orn_asimdsame_only(); } catch (...) { std::cerr << "FAIL: orn_asimdsame_only" << std::endl; failed++; }
    try { test_orr_asimdimm_l_hl(); } catch (...) { std::cerr << "FAIL: orr_asimdimm_l_hl" << std::endl; failed++; }
    try { test_orr_asimdimm_l_sl(); } catch (...) { std::cerr << "FAIL: orr_asimdimm_l_sl" << std::endl; failed++; }
    try { test_orr_asimdsame_only(); } catch (...) { std::cerr << "FAIL: orr_asimdsame_only" << std::endl; failed++; }
    try { test_pmul_asimdsame_only(); } catch (...) { std::cerr << "FAIL: pmul_asimdsame_only" << std::endl; failed++; }
    try { test_pmull_asimddiff_l(); } catch (...) { std::cerr << "FAIL: pmull_asimddiff_l" << std::endl; failed++; }
    try { test_raddhn_asimddiff_n(); } catch (...) { std::cerr << "FAIL: raddhn_asimddiff_n" << std::endl; failed++; }
    try { test_rax1_vvv2_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: rax1_vvv2_cryptosha512_3" << std::endl; failed++; }
    try { test_rbit_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: rbit_asimdmisc_r" << std::endl; failed++; }
    try { test_rev16_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: rev16_asimdmisc_r" << std::endl; failed++; }
    try { test_rev32_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: rev32_asimdmisc_r" << std::endl; failed++; }
    try { test_rev64_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: rev64_asimdmisc_r" << std::endl; failed++; }
    try { test_rshrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: rshrn_asimdshf_n" << std::endl; failed++; }
    try { test_rsubhn_asimddiff_n(); } catch (...) { std::cerr << "FAIL: rsubhn_asimddiff_n" << std::endl; failed++; }
    try { test_saba_asimdsame_only(); } catch (...) { std::cerr << "FAIL: saba_asimdsame_only" << std::endl; failed++; }
    try { test_sabal_asimddiff_l(); } catch (...) { std::cerr << "FAIL: sabal_asimddiff_l" << std::endl; failed++; }
    try { test_sabd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sabd_asimdsame_only" << std::endl; failed++; }
    try { test_sabdl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: sabdl_asimddiff_l" << std::endl; failed++; }
    try { test_sadalp_asimdmisc_p(); } catch (...) { std::cerr << "FAIL: sadalp_asimdmisc_p" << std::endl; failed++; }
    try { test_saddl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: saddl_asimddiff_l" << std::endl; failed++; }
    try { test_saddlp_asimdmisc_p(); } catch (...) { std::cerr << "FAIL: saddlp_asimdmisc_p" << std::endl; failed++; }
    try { test_saddlv_asimdall_only(); } catch (...) { std::cerr << "FAIL: saddlv_asimdall_only" << std::endl; failed++; }
    try { test_saddw_asimddiff_w(); } catch (...) { std::cerr << "FAIL: saddw_asimddiff_w" << std::endl; failed++; }
    try { test_scvtf_asisdshf_c(); } catch (...) { std::cerr << "FAIL: scvtf_asisdshf_c" << std::endl; failed++; }
    try { test_scvtf_asimdshf_c(); } catch (...) { std::cerr << "FAIL: scvtf_asimdshf_c" << std::endl; failed++; }
    try { test_scvtf_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: scvtf_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_scvtf_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: scvtf_asisdmisc_r" << std::endl; failed++; }
    try { test_scvtf_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: scvtf_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_scvtf_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: scvtf_asimdmisc_r" << std::endl; failed++; }
    try { test_scvtf_h32_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_h32_float2fix" << std::endl; failed++; }
    try { test_scvtf_h64_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_h64_float2fix" << std::endl; failed++; }
    try { test_scvtf_s32_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_s32_float2fix" << std::endl; failed++; }
    try { test_scvtf_s64_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_s64_float2fix" << std::endl; failed++; }
    try { test_scvtf_d32_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_d32_float2fix" << std::endl; failed++; }
    try { test_scvtf_d64_float2fix(); } catch (...) { std::cerr << "FAIL: scvtf_d64_float2fix" << std::endl; failed++; }
    try { test_scvtf_h32_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_h32_float2int" << std::endl; failed++; }
    try { test_scvtf_s32_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_s32_float2int" << std::endl; failed++; }
    try { test_scvtf_d32_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_d32_float2int" << std::endl; failed++; }
    try { test_scvtf_h64_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_h64_float2int" << std::endl; failed++; }
    try { test_scvtf_s64_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_s64_float2int" << std::endl; failed++; }
    try { test_scvtf_d64_float2int(); } catch (...) { std::cerr << "FAIL: scvtf_d64_float2int" << std::endl; failed++; }
    try { test_scvtf_sisd_32h(); } catch (...) { std::cerr << "FAIL: scvtf_sisd_32h" << std::endl; failed++; }
    try { test_scvtf_sisd_32d(); } catch (...) { std::cerr << "FAIL: scvtf_sisd_32d" << std::endl; failed++; }
    try { test_scvtf_sisd_64h(); } catch (...) { std::cerr << "FAIL: scvtf_sisd_64h" << std::endl; failed++; }
    try { test_scvtf_sisd_64s(); } catch (...) { std::cerr << "FAIL: scvtf_sisd_64s" << std::endl; failed++; }
    try { test_sdot_asimdelem_d(); } catch (...) { std::cerr << "FAIL: sdot_asimdelem_d" << std::endl; failed++; }
    try { test_sdot_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: sdot_asimdsame2_d" << std::endl; failed++; }
    try { test_sha1c_qsv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha1c_qsv_cryptosha3" << std::endl; failed++; }
    try { test_sha1h_ss_cryptosha2(); } catch (...) { std::cerr << "FAIL: sha1h_ss_cryptosha2" << std::endl; failed++; }
    try { test_sha1m_qsv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha1m_qsv_cryptosha3" << std::endl; failed++; }
    try { test_sha1p_qsv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha1p_qsv_cryptosha3" << std::endl; failed++; }
    try { test_sha1su0_vvv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha1su0_vvv_cryptosha3" << std::endl; failed++; }
    try { test_sha1su1_vv_cryptosha2(); } catch (...) { std::cerr << "FAIL: sha1su1_vv_cryptosha2" << std::endl; failed++; }
    try { test_sha256h2_qqv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha256h2_qqv_cryptosha3" << std::endl; failed++; }
    try { test_sha256h_qqv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha256h_qqv_cryptosha3" << std::endl; failed++; }
    try { test_sha256su0_vv_cryptosha2(); } catch (...) { std::cerr << "FAIL: sha256su0_vv_cryptosha2" << std::endl; failed++; }
    try { test_sha256su1_vvv_cryptosha3(); } catch (...) { std::cerr << "FAIL: sha256su1_vvv_cryptosha3" << std::endl; failed++; }
    try { test_sha512h2_qqv_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sha512h2_qqv_cryptosha512_3" << std::endl; failed++; }
    try { test_sha512h_qqv_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sha512h_qqv_cryptosha512_3" << std::endl; failed++; }
    try { test_sha512su0_vv2_cryptosha512_2(); } catch (...) { std::cerr << "FAIL: sha512su0_vv2_cryptosha512_2" << std::endl; failed++; }
    try { test_sha512su1_vvv2_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sha512su1_vvv2_cryptosha512_3" << std::endl; failed++; }
    try { test_shadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: shadd_asimdsame_only" << std::endl; failed++; }
    try { test_shl_asisdshf_r(); } catch (...) { std::cerr << "FAIL: shl_asisdshf_r" << std::endl; failed++; }
    try { test_shl_asimdshf_r(); } catch (...) { std::cerr << "FAIL: shl_asimdshf_r" << std::endl; failed++; }
    try { test_shll_asimdmisc_s(); } catch (...) { std::cerr << "FAIL: shll_asimdmisc_s" << std::endl; failed++; }
    try { test_shrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: shrn_asimdshf_n" << std::endl; failed++; }
    try { test_shsub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: shsub_asimdsame_only" << std::endl; failed++; }
    try { test_sli_asisdshf_r(); } catch (...) { std::cerr << "FAIL: sli_asisdshf_r" << std::endl; failed++; }
    try { test_sli_asimdshf_r(); } catch (...) { std::cerr << "FAIL: sli_asimdshf_r" << std::endl; failed++; }
    try { test_sm3partw1_vvv4_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sm3partw1_vvv4_cryptosha512_3" << std::endl; failed++; }
    try { test_sm3partw2_vvv4_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sm3partw2_vvv4_cryptosha512_3" << std::endl; failed++; }
    try { test_sm3ss1_vvv4_crypto4(); } catch (...) { std::cerr << "FAIL: sm3ss1_vvv4_crypto4" << std::endl; failed++; }
    try { test_sm3tt1a_vvv4_crypto3_imm2(); } catch (...) { std::cerr << "FAIL: sm3tt1a_vvv4_crypto3_imm2" << std::endl; failed++; }
    try { test_sm3tt1b_vvv4_crypto3_imm2(); } catch (...) { std::cerr << "FAIL: sm3tt1b_vvv4_crypto3_imm2" << std::endl; failed++; }
    try { test_sm3tt2a_vvv4_crypto3_imm2(); } catch (...) { std::cerr << "FAIL: sm3tt2a_vvv4_crypto3_imm2" << std::endl; failed++; }
    try { test_sm3tt2b_vvv_crypto3_imm2(); } catch (...) { std::cerr << "FAIL: sm3tt2b_vvv_crypto3_imm2" << std::endl; failed++; }
    try { test_sm4e_vv4_cryptosha512_2(); } catch (...) { std::cerr << "FAIL: sm4e_vv4_cryptosha512_2" << std::endl; failed++; }
    try { test_sm4ekey_vvv4_cryptosha512_3(); } catch (...) { std::cerr << "FAIL: sm4ekey_vvv4_cryptosha512_3" << std::endl; failed++; }
    try { test_smax_asimdsame_only(); } catch (...) { std::cerr << "FAIL: smax_asimdsame_only" << std::endl; failed++; }
    try { test_smaxp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: smaxp_asimdsame_only" << std::endl; failed++; }
    try { test_smaxv_asimdall_only(); } catch (...) { std::cerr << "FAIL: smaxv_asimdall_only" << std::endl; failed++; }
    try { test_smin_asimdsame_only(); } catch (...) { std::cerr << "FAIL: smin_asimdsame_only" << std::endl; failed++; }
    try { test_sminp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sminp_asimdsame_only" << std::endl; failed++; }
    try { test_sminv_asimdall_only(); } catch (...) { std::cerr << "FAIL: sminv_asimdall_only" << std::endl; failed++; }
    try { test_smlal_asimdelem_l(); } catch (...) { std::cerr << "FAIL: smlal_asimdelem_l" << std::endl; failed++; }
    try { test_smlal_asimddiff_l(); } catch (...) { std::cerr << "FAIL: smlal_asimddiff_l" << std::endl; failed++; }
    try { test_smlsl_asimdelem_l(); } catch (...) { std::cerr << "FAIL: smlsl_asimdelem_l" << std::endl; failed++; }
    try { test_smlsl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: smlsl_asimddiff_l" << std::endl; failed++; }
    try { test_smmla_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: smmla_asimdsame2_g" << std::endl; failed++; }
    try { test_smov_asimdins_w_w(); } catch (...) { std::cerr << "FAIL: smov_asimdins_w_w" << std::endl; failed++; }
    try { test_smov_asimdins_x_x(); } catch (...) { std::cerr << "FAIL: smov_asimdins_x_x" << std::endl; failed++; }
    try { test_smull_asimdelem_l(); } catch (...) { std::cerr << "FAIL: smull_asimdelem_l" << std::endl; failed++; }
    try { test_smull_asimddiff_l(); } catch (...) { std::cerr << "FAIL: smull_asimddiff_l" << std::endl; failed++; }
    try { test_sqabs_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: sqabs_asisdmisc_r" << std::endl; failed++; }
    try { test_sqabs_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: sqabs_asimdmisc_r" << std::endl; failed++; }
    try { test_sqadd_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqadd_asisdsame_only" << std::endl; failed++; }
    try { test_sqadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqadd_asimdsame_only" << std::endl; failed++; }
    try { test_sqdmlal_asisdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmlal_asisdelem_l" << std::endl; failed++; }
    try { test_sqdmlal_asimdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmlal_asimdelem_l" << std::endl; failed++; }
    try { test_sqdmlal_asisddiff_only(); } catch (...) { std::cerr << "FAIL: sqdmlal_asisddiff_only" << std::endl; failed++; }
    try { test_sqdmlal_asimddiff_l(); } catch (...) { std::cerr << "FAIL: sqdmlal_asimddiff_l" << std::endl; failed++; }
    try { test_sqdmlsl_asisdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmlsl_asisdelem_l" << std::endl; failed++; }
    try { test_sqdmlsl_asimdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmlsl_asimdelem_l" << std::endl; failed++; }
    try { test_sqdmlsl_asisddiff_only(); } catch (...) { std::cerr << "FAIL: sqdmlsl_asisddiff_only" << std::endl; failed++; }
    try { test_sqdmlsl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: sqdmlsl_asimddiff_l" << std::endl; failed++; }
    try { test_sqdmulh_asisdelem_r(); } catch (...) { std::cerr << "FAIL: sqdmulh_asisdelem_r" << std::endl; failed++; }
    try { test_sqdmulh_asimdelem_r(); } catch (...) { std::cerr << "FAIL: sqdmulh_asimdelem_r" << std::endl; failed++; }
    try { test_sqdmulh_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqdmulh_asisdsame_only" << std::endl; failed++; }
    try { test_sqdmulh_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqdmulh_asimdsame_only" << std::endl; failed++; }
    try { test_sqdmull_asimdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmull_asimdelem_l" << std::endl; failed++; }
    try { test_sqdmull_asisdelem_l(); } catch (...) { std::cerr << "FAIL: sqdmull_asisdelem_l" << std::endl; failed++; }
    try { test_sqdmull_asisddiff_only(); } catch (...) { std::cerr << "FAIL: sqdmull_asisddiff_only" << std::endl; failed++; }
    try { test_sqdmull_asimddiff_l(); } catch (...) { std::cerr << "FAIL: sqdmull_asimddiff_l" << std::endl; failed++; }
    try { test_sqneg_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: sqneg_asisdmisc_r" << std::endl; failed++; }
    try { test_sqneg_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: sqneg_asimdmisc_r" << std::endl; failed++; }
    try { test_sqrdmlah_asisdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmlah_asisdelem_r" << std::endl; failed++; }
    try { test_sqrdmlah_asimdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmlah_asimdelem_r" << std::endl; failed++; }
    try { test_sqrdmlah_asisdsame2_only(); } catch (...) { std::cerr << "FAIL: sqrdmlah_asisdsame2_only" << std::endl; failed++; }
    try { test_sqrdmlah_asimdsame2_only(); } catch (...) { std::cerr << "FAIL: sqrdmlah_asimdsame2_only" << std::endl; failed++; }
    try { test_sqrdmlsh_asisdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_asisdelem_r" << std::endl; failed++; }
    try { test_sqrdmlsh_asimdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_asimdelem_r" << std::endl; failed++; }
    try { test_sqrdmlsh_asisdsame2_only(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_asisdsame2_only" << std::endl; failed++; }
    try { test_sqrdmlsh_asimdsame2_only(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_asimdsame2_only" << std::endl; failed++; }
    try { test_sqrdmulh_asisdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmulh_asisdelem_r" << std::endl; failed++; }
    try { test_sqrdmulh_asimdelem_r(); } catch (...) { std::cerr << "FAIL: sqrdmulh_asimdelem_r" << std::endl; failed++; }
    try { test_sqrdmulh_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqrdmulh_asisdsame_only" << std::endl; failed++; }
    try { test_sqrdmulh_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqrdmulh_asimdsame_only" << std::endl; failed++; }
    try { test_sqrshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqrshl_asisdsame_only" << std::endl; failed++; }
    try { test_sqrshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqrshl_asimdsame_only" << std::endl; failed++; }
    try { test_sqrshrn_asisdshf_n(); } catch (...) { std::cerr << "FAIL: sqrshrn_asisdshf_n" << std::endl; failed++; }
    try { test_sqrshrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: sqrshrn_asimdshf_n" << std::endl; failed++; }
    try { test_sqrshrun_asisdshf_n(); } catch (...) { std::cerr << "FAIL: sqrshrun_asisdshf_n" << std::endl; failed++; }
    try { test_sqrshrun_asimdshf_n(); } catch (...) { std::cerr << "FAIL: sqrshrun_asimdshf_n" << std::endl; failed++; }
    try { test_sqshl_asisdshf_r(); } catch (...) { std::cerr << "FAIL: sqshl_asisdshf_r" << std::endl; failed++; }
    try { test_sqshl_asimdshf_r(); } catch (...) { std::cerr << "FAIL: sqshl_asimdshf_r" << std::endl; failed++; }
    try { test_sqshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqshl_asisdsame_only" << std::endl; failed++; }
    try { test_sqshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqshl_asimdsame_only" << std::endl; failed++; }
    try { test_sqshlu_asisdshf_r(); } catch (...) { std::cerr << "FAIL: sqshlu_asisdshf_r" << std::endl; failed++; }
    try { test_sqshlu_asimdshf_r(); } catch (...) { std::cerr << "FAIL: sqshlu_asimdshf_r" << std::endl; failed++; }
    try { test_sqshrn_asisdshf_n(); } catch (...) { std::cerr << "FAIL: sqshrn_asisdshf_n" << std::endl; failed++; }
    try { test_sqshrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: sqshrn_asimdshf_n" << std::endl; failed++; }
    try { test_sqshrun_asisdshf_n(); } catch (...) { std::cerr << "FAIL: sqshrun_asisdshf_n" << std::endl; failed++; }
    try { test_sqshrun_asimdshf_n(); } catch (...) { std::cerr << "FAIL: sqshrun_asimdshf_n" << std::endl; failed++; }
    try { test_sqsub_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sqsub_asisdsame_only" << std::endl; failed++; }
    try { test_sqsub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sqsub_asimdsame_only" << std::endl; failed++; }
    try { test_sqxtn_asisdmisc_n(); } catch (...) { std::cerr << "FAIL: sqxtn_asisdmisc_n" << std::endl; failed++; }
    try { test_sqxtn_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: sqxtn_asimdmisc_n" << std::endl; failed++; }
    try { test_sqxtun_asisdmisc_n(); } catch (...) { std::cerr << "FAIL: sqxtun_asisdmisc_n" << std::endl; failed++; }
    try { test_sqxtun_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: sqxtun_asimdmisc_n" << std::endl; failed++; }
    try { test_srhadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: srhadd_asimdsame_only" << std::endl; failed++; }
    try { test_sri_asisdshf_r(); } catch (...) { std::cerr << "FAIL: sri_asisdshf_r" << std::endl; failed++; }
    try { test_sri_asimdshf_r(); } catch (...) { std::cerr << "FAIL: sri_asimdshf_r" << std::endl; failed++; }
    try { test_srshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: srshl_asisdsame_only" << std::endl; failed++; }
    try { test_srshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: srshl_asimdsame_only" << std::endl; failed++; }
    try { test_srshr_asisdshf_r(); } catch (...) { std::cerr << "FAIL: srshr_asisdshf_r" << std::endl; failed++; }
    try { test_srshr_asimdshf_r(); } catch (...) { std::cerr << "FAIL: srshr_asimdshf_r" << std::endl; failed++; }
    try { test_srsra_asisdshf_r(); } catch (...) { std::cerr << "FAIL: srsra_asisdshf_r" << std::endl; failed++; }
    try { test_srsra_asimdshf_r(); } catch (...) { std::cerr << "FAIL: srsra_asimdshf_r" << std::endl; failed++; }
    try { test_sshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sshl_asisdsame_only" << std::endl; failed++; }
    try { test_sshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sshl_asimdsame_only" << std::endl; failed++; }
    try { test_sshll_asimdshf_l(); } catch (...) { std::cerr << "FAIL: sshll_asimdshf_l" << std::endl; failed++; }
    try { test_sshr_asisdshf_r(); } catch (...) { std::cerr << "FAIL: sshr_asisdshf_r" << std::endl; failed++; }
    try { test_sshr_asimdshf_r(); } catch (...) { std::cerr << "FAIL: sshr_asimdshf_r" << std::endl; failed++; }
    try { test_ssra_asisdshf_r(); } catch (...) { std::cerr << "FAIL: ssra_asisdshf_r" << std::endl; failed++; }
    try { test_ssra_asimdshf_r(); } catch (...) { std::cerr << "FAIL: ssra_asimdshf_r" << std::endl; failed++; }
    try { test_ssubl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: ssubl_asimddiff_l" << std::endl; failed++; }
    try { test_ssubw_asimddiff_w(); } catch (...) { std::cerr << "FAIL: ssubw_asimddiff_w" << std::endl; failed++; }
    try { test_sub_asisdsame_only(); } catch (...) { std::cerr << "FAIL: sub_asisdsame_only" << std::endl; failed++; }
    try { test_sub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: sub_asimdsame_only" << std::endl; failed++; }
    try { test_subhn_asimddiff_n(); } catch (...) { std::cerr << "FAIL: subhn_asimddiff_n" << std::endl; failed++; }
    try { test_sudot_asimdelem_d(); } catch (...) { std::cerr << "FAIL: sudot_asimdelem_d" << std::endl; failed++; }
    try { test_suqadd_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: suqadd_asisdmisc_r" << std::endl; failed++; }
    try { test_suqadd_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: suqadd_asimdmisc_r" << std::endl; failed++; }
    try { test_sxtl_sshll_asimdshf_l(); } catch (...) { std::cerr << "FAIL: sxtl_sshll_asimdshf_l" << std::endl; failed++; }
    try { test_tbl_asimdtbl_l1_1(); } catch (...) { std::cerr << "FAIL: tbl_asimdtbl_l1_1" << std::endl; failed++; }
    try { test_tbl_asimdtbl_l2_2(); } catch (...) { std::cerr << "FAIL: tbl_asimdtbl_l2_2" << std::endl; failed++; }
    try { test_tbl_asimdtbl_l3_3(); } catch (...) { std::cerr << "FAIL: tbl_asimdtbl_l3_3" << std::endl; failed++; }
    try { test_tbl_asimdtbl_l4_4(); } catch (...) { std::cerr << "FAIL: tbl_asimdtbl_l4_4" << std::endl; failed++; }
    try { test_tbx_asimdtbl_l1_1(); } catch (...) { std::cerr << "FAIL: tbx_asimdtbl_l1_1" << std::endl; failed++; }
    try { test_tbx_asimdtbl_l2_2(); } catch (...) { std::cerr << "FAIL: tbx_asimdtbl_l2_2" << std::endl; failed++; }
    try { test_tbx_asimdtbl_l3_3(); } catch (...) { std::cerr << "FAIL: tbx_asimdtbl_l3_3" << std::endl; failed++; }
    try { test_tbx_asimdtbl_l4_4(); } catch (...) { std::cerr << "FAIL: tbx_asimdtbl_l4_4" << std::endl; failed++; }
    try { test_trn1_asimdperm_only(); } catch (...) { std::cerr << "FAIL: trn1_asimdperm_only" << std::endl; failed++; }
    try { test_trn2_asimdperm_only(); } catch (...) { std::cerr << "FAIL: trn2_asimdperm_only" << std::endl; failed++; }
    try { test_uaba_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uaba_asimdsame_only" << std::endl; failed++; }
    try { test_uabal_asimddiff_l(); } catch (...) { std::cerr << "FAIL: uabal_asimddiff_l" << std::endl; failed++; }
    try { test_uabd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uabd_asimdsame_only" << std::endl; failed++; }
    try { test_uabdl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: uabdl_asimddiff_l" << std::endl; failed++; }
    try { test_uadalp_asimdmisc_p(); } catch (...) { std::cerr << "FAIL: uadalp_asimdmisc_p" << std::endl; failed++; }
    try { test_uaddl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: uaddl_asimddiff_l" << std::endl; failed++; }
    try { test_uaddlp_asimdmisc_p(); } catch (...) { std::cerr << "FAIL: uaddlp_asimdmisc_p" << std::endl; failed++; }
    try { test_uaddlv_asimdall_only(); } catch (...) { std::cerr << "FAIL: uaddlv_asimdall_only" << std::endl; failed++; }
    try { test_uaddw_asimddiff_w(); } catch (...) { std::cerr << "FAIL: uaddw_asimddiff_w" << std::endl; failed++; }
    try { test_ucvtf_asisdshf_c(); } catch (...) { std::cerr << "FAIL: ucvtf_asisdshf_c" << std::endl; failed++; }
    try { test_ucvtf_asimdshf_c(); } catch (...) { std::cerr << "FAIL: ucvtf_asimdshf_c" << std::endl; failed++; }
    try { test_ucvtf_asisdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: ucvtf_asisdmiscfp16_r" << std::endl; failed++; }
    try { test_ucvtf_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: ucvtf_asisdmisc_r" << std::endl; failed++; }
    try { test_ucvtf_asimdmiscfp16_r(); } catch (...) { std::cerr << "FAIL: ucvtf_asimdmiscfp16_r" << std::endl; failed++; }
    try { test_ucvtf_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: ucvtf_asimdmisc_r" << std::endl; failed++; }
    try { test_ucvtf_h32_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_h32_float2fix" << std::endl; failed++; }
    try { test_ucvtf_h64_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_h64_float2fix" << std::endl; failed++; }
    try { test_ucvtf_s32_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_s32_float2fix" << std::endl; failed++; }
    try { test_ucvtf_s64_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_s64_float2fix" << std::endl; failed++; }
    try { test_ucvtf_d32_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_d32_float2fix" << std::endl; failed++; }
    try { test_ucvtf_d64_float2fix(); } catch (...) { std::cerr << "FAIL: ucvtf_d64_float2fix" << std::endl; failed++; }
    try { test_ucvtf_h32_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_h32_float2int" << std::endl; failed++; }
    try { test_ucvtf_s32_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_s32_float2int" << std::endl; failed++; }
    try { test_ucvtf_d32_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_d32_float2int" << std::endl; failed++; }
    try { test_ucvtf_h64_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_h64_float2int" << std::endl; failed++; }
    try { test_ucvtf_s64_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_s64_float2int" << std::endl; failed++; }
    try { test_ucvtf_d64_float2int(); } catch (...) { std::cerr << "FAIL: ucvtf_d64_float2int" << std::endl; failed++; }
    try { test_ucvtf_sisd_32h(); } catch (...) { std::cerr << "FAIL: ucvtf_sisd_32h" << std::endl; failed++; }
    try { test_ucvtf_sisd_32d(); } catch (...) { std::cerr << "FAIL: ucvtf_sisd_32d" << std::endl; failed++; }
    try { test_ucvtf_sisd_64h(); } catch (...) { std::cerr << "FAIL: ucvtf_sisd_64h" << std::endl; failed++; }
    try { test_ucvtf_sisd_64s(); } catch (...) { std::cerr << "FAIL: ucvtf_sisd_64s" << std::endl; failed++; }
    try { test_udot_asimdelem_d(); } catch (...) { std::cerr << "FAIL: udot_asimdelem_d" << std::endl; failed++; }
    try { test_udot_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: udot_asimdsame2_d" << std::endl; failed++; }
    try { test_uhadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uhadd_asimdsame_only" << std::endl; failed++; }
    try { test_uhsub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uhsub_asimdsame_only" << std::endl; failed++; }
    try { test_umax_asimdsame_only(); } catch (...) { std::cerr << "FAIL: umax_asimdsame_only" << std::endl; failed++; }
    try { test_umaxp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: umaxp_asimdsame_only" << std::endl; failed++; }
    try { test_umaxv_asimdall_only(); } catch (...) { std::cerr << "FAIL: umaxv_asimdall_only" << std::endl; failed++; }
    try { test_umin_asimdsame_only(); } catch (...) { std::cerr << "FAIL: umin_asimdsame_only" << std::endl; failed++; }
    try { test_uminp_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uminp_asimdsame_only" << std::endl; failed++; }
    try { test_uminv_asimdall_only(); } catch (...) { std::cerr << "FAIL: uminv_asimdall_only" << std::endl; failed++; }
    try { test_umlal_asimdelem_l(); } catch (...) { std::cerr << "FAIL: umlal_asimdelem_l" << std::endl; failed++; }
    try { test_umlal_asimddiff_l(); } catch (...) { std::cerr << "FAIL: umlal_asimddiff_l" << std::endl; failed++; }
    try { test_umlsl_asimdelem_l(); } catch (...) { std::cerr << "FAIL: umlsl_asimdelem_l" << std::endl; failed++; }
    try { test_umlsl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: umlsl_asimddiff_l" << std::endl; failed++; }
    try { test_ummla_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: ummla_asimdsame2_g" << std::endl; failed++; }
    try { test_umov_asimdins_w_w(); } catch (...) { std::cerr << "FAIL: umov_asimdins_w_w" << std::endl; failed++; }
    try { test_umov_asimdins_x_x(); } catch (...) { std::cerr << "FAIL: umov_asimdins_x_x" << std::endl; failed++; }
    try { test_umull_asimdelem_l(); } catch (...) { std::cerr << "FAIL: umull_asimdelem_l" << std::endl; failed++; }
    try { test_umull_asimddiff_l(); } catch (...) { std::cerr << "FAIL: umull_asimddiff_l" << std::endl; failed++; }
    try { test_uqadd_asisdsame_only(); } catch (...) { std::cerr << "FAIL: uqadd_asisdsame_only" << std::endl; failed++; }
    try { test_uqadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uqadd_asimdsame_only" << std::endl; failed++; }
    try { test_uqrshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: uqrshl_asisdsame_only" << std::endl; failed++; }
    try { test_uqrshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uqrshl_asimdsame_only" << std::endl; failed++; }
    try { test_uqrshrn_asisdshf_n(); } catch (...) { std::cerr << "FAIL: uqrshrn_asisdshf_n" << std::endl; failed++; }
    try { test_uqrshrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: uqrshrn_asimdshf_n" << std::endl; failed++; }
    try { test_uqshl_asisdshf_r(); } catch (...) { std::cerr << "FAIL: uqshl_asisdshf_r" << std::endl; failed++; }
    try { test_uqshl_asimdshf_r(); } catch (...) { std::cerr << "FAIL: uqshl_asimdshf_r" << std::endl; failed++; }
    try { test_uqshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: uqshl_asisdsame_only" << std::endl; failed++; }
    try { test_uqshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uqshl_asimdsame_only" << std::endl; failed++; }
    try { test_uqshrn_asisdshf_n(); } catch (...) { std::cerr << "FAIL: uqshrn_asisdshf_n" << std::endl; failed++; }
    try { test_uqshrn_asimdshf_n(); } catch (...) { std::cerr << "FAIL: uqshrn_asimdshf_n" << std::endl; failed++; }
    try { test_uqsub_asisdsame_only(); } catch (...) { std::cerr << "FAIL: uqsub_asisdsame_only" << std::endl; failed++; }
    try { test_uqsub_asimdsame_only(); } catch (...) { std::cerr << "FAIL: uqsub_asimdsame_only" << std::endl; failed++; }
    try { test_uqxtn_asisdmisc_n(); } catch (...) { std::cerr << "FAIL: uqxtn_asisdmisc_n" << std::endl; failed++; }
    try { test_uqxtn_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: uqxtn_asimdmisc_n" << std::endl; failed++; }
    try { test_urecpe_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: urecpe_asimdmisc_r" << std::endl; failed++; }
    try { test_urhadd_asimdsame_only(); } catch (...) { std::cerr << "FAIL: urhadd_asimdsame_only" << std::endl; failed++; }
    try { test_urshl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: urshl_asisdsame_only" << std::endl; failed++; }
    try { test_urshl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: urshl_asimdsame_only" << std::endl; failed++; }
    try { test_urshr_asisdshf_r(); } catch (...) { std::cerr << "FAIL: urshr_asisdshf_r" << std::endl; failed++; }
    try { test_urshr_asimdshf_r(); } catch (...) { std::cerr << "FAIL: urshr_asimdshf_r" << std::endl; failed++; }
    try { test_ursqrte_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: ursqrte_asimdmisc_r" << std::endl; failed++; }
    try { test_ursra_asisdshf_r(); } catch (...) { std::cerr << "FAIL: ursra_asisdshf_r" << std::endl; failed++; }
    try { test_ursra_asimdshf_r(); } catch (...) { std::cerr << "FAIL: ursra_asimdshf_r" << std::endl; failed++; }
    try { test_usdot_asimdelem_d(); } catch (...) { std::cerr << "FAIL: usdot_asimdelem_d" << std::endl; failed++; }
    try { test_usdot_asimdsame2_d(); } catch (...) { std::cerr << "FAIL: usdot_asimdsame2_d" << std::endl; failed++; }
    try { test_ushl_asisdsame_only(); } catch (...) { std::cerr << "FAIL: ushl_asisdsame_only" << std::endl; failed++; }
    try { test_ushl_asimdsame_only(); } catch (...) { std::cerr << "FAIL: ushl_asimdsame_only" << std::endl; failed++; }
    try { test_ushll_asimdshf_l(); } catch (...) { std::cerr << "FAIL: ushll_asimdshf_l" << std::endl; failed++; }
    try { test_ushr_asisdshf_r(); } catch (...) { std::cerr << "FAIL: ushr_asisdshf_r" << std::endl; failed++; }
    try { test_ushr_asimdshf_r(); } catch (...) { std::cerr << "FAIL: ushr_asimdshf_r" << std::endl; failed++; }
    try { test_usmmla_asimdsame2_g(); } catch (...) { std::cerr << "FAIL: usmmla_asimdsame2_g" << std::endl; failed++; }
    try { test_usqadd_asisdmisc_r(); } catch (...) { std::cerr << "FAIL: usqadd_asisdmisc_r" << std::endl; failed++; }
    try { test_usqadd_asimdmisc_r(); } catch (...) { std::cerr << "FAIL: usqadd_asimdmisc_r" << std::endl; failed++; }
    try { test_usra_asisdshf_r(); } catch (...) { std::cerr << "FAIL: usra_asisdshf_r" << std::endl; failed++; }
    try { test_usra_asimdshf_r(); } catch (...) { std::cerr << "FAIL: usra_asimdshf_r" << std::endl; failed++; }
    try { test_usubl_asimddiff_l(); } catch (...) { std::cerr << "FAIL: usubl_asimddiff_l" << std::endl; failed++; }
    try { test_usubw_asimddiff_w(); } catch (...) { std::cerr << "FAIL: usubw_asimddiff_w" << std::endl; failed++; }
    try { test_uxtl_ushll_asimdshf_l(); } catch (...) { std::cerr << "FAIL: uxtl_ushll_asimdshf_l" << std::endl; failed++; }
    try { test_uzp1_asimdperm_only(); } catch (...) { std::cerr << "FAIL: uzp1_asimdperm_only" << std::endl; failed++; }
    try { test_uzp2_asimdperm_only(); } catch (...) { std::cerr << "FAIL: uzp2_asimdperm_only" << std::endl; failed++; }
    try { test_xar_vvv2_crypto3_imm6(); } catch (...) { std::cerr << "FAIL: xar_vvv2_crypto3_imm6" << std::endl; failed++; }
    try { test_xtn_asimdmisc_n(); } catch (...) { std::cerr << "FAIL: xtn_asimdmisc_n" << std::endl; failed++; }
    try { test_zip1_asimdperm_only(); } catch (...) { std::cerr << "FAIL: zip1_asimdperm_only" << std::endl; failed++; }
    try { test_zip2_asimdperm_only(); } catch (...) { std::cerr << "FAIL: zip2_asimdperm_only" << std::endl; failed++; }

    std::cout << (852 - failed) << " / 852 passed" << std::endl;
    return failed;
}
