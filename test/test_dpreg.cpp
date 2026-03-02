// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_32_dp_1src() {
    uint32_t insn = 0x5AC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ABS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  abs_32_dp_1src: " << result->to_string() << std::endl;
}

void test_abs_64_dp_1src() {
    uint32_t insn = 0xDAC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ABS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  abs_64_dp_1src: " << result->to_string() << std::endl;
}

void test_adc_32_addsub_carry() {
    uint32_t insn = 0x1A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adc_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  adc_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_adc_64_addsub_carry() {
    uint32_t insn = 0x9A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adc_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  adc_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_adcs_32_addsub_carry() {
    uint32_t insn = 0x3A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adcs_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADCS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  adcs_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_adcs_64_addsub_carry() {
    uint32_t insn = 0xBA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adcs_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADCS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  adcs_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_add_32_addsub_ext() {
    uint32_t insn = 0x0B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_32_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
    std::cout << "  add_32_addsub_ext: " << result->to_string() << std::endl;
}

void test_add_64_addsub_ext() {
    uint32_t insn = 0x8B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_64_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  add_64_addsub_ext: " << result->to_string() << std::endl;
}

void test_add_32_addsub_shift() {
    uint32_t insn = 0x0B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  add_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_add_64_addsub_shift() {
    uint32_t insn = 0x8B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  add_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_addpt_64_addsub_pt() {
    uint32_t insn = 0x9A002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addpt_64_addsub_pt" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  addpt_64_addsub_pt: " << result->to_string() << std::endl;
}

void test_adds_32s_addsub_ext() {
    uint32_t insn = 0x2B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adds_32s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  adds_32s_addsub_ext: " << result->to_string() << std::endl;
}

void test_adds_64s_addsub_ext() {
    uint32_t insn = 0xAB200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adds_64s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  adds_64s_addsub_ext: " << result->to_string() << std::endl;
}

void test_adds_32_addsub_shift() {
    uint32_t insn = 0x2B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adds_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  adds_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_adds_64_addsub_shift() {
    uint32_t insn = 0xAB000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adds_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  adds_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_and_32_log_shift() {
    uint32_t insn = 0x0A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  and_32_log_shift: " << result->to_string() << std::endl;
}

void test_and_64_log_shift() {
    uint32_t insn = 0x8A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  and_64_log_shift: " << result->to_string() << std::endl;
}

void test_ands_32_log_shift() {
    uint32_t insn = 0x6A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ands_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ands_32_log_shift: " << result->to_string() << std::endl;
}

void test_ands_64_log_shift() {
    uint32_t insn = 0xEA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ands_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ands_64_log_shift: " << result->to_string() << std::endl;
}

void test_asr_asrv_32_dp_2src() {
    uint32_t insn = 0x1AC02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_asrv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  asr_asrv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_asr_asrv_64_dp_2src() {
    uint32_t insn = 0x9AC02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_asrv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  asr_asrv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_asrv_32_dp_2src() {
    uint32_t insn = 0x1AC02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asrv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  asrv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_asrv_64_dp_2src() {
    uint32_t insn = 0x9AC02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asrv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  asrv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_autda_64p_dp_1src() {
    uint32_t insn = 0xDAC11800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autda_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  autda_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autdza_64z_dp_1src() {
    uint32_t insn = 0xDAC13BE0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autdza_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autdza_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_autdb_64p_dp_1src() {
    uint32_t insn = 0xDAC11C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autdb_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  autdb_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autdzb_64z_dp_1src() {
    uint32_t insn = 0xDAC13FE0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autdzb_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autdzb_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_autia_64p_dp_1src() {
    uint32_t insn = 0xDAC11000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autia_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  autia_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autiza_64z_dp_1src() {
    uint32_t insn = 0xDAC133E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autiza_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autiza_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_autia171615_64lr_dp_1src() {
    uint32_t insn = 0xDAC1BBFEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autia171615_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AUTIA171615);
    std::cout << "  autia171615_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_autiasppcr_64lrr_dp_1src() {
    uint32_t insn = 0xDAC1901Eu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autiasppcr_64lrr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AUTIASPPCR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autiasppcr_64lrr_dp_1src: " << result->to_string() << std::endl;
}

void test_autib_64p_dp_1src() {
    uint32_t insn = 0xDAC11400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autib_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  autib_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autizb_64z_dp_1src() {
    uint32_t insn = 0xDAC137E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autizb_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autizb_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_autib171615_64lr_dp_1src() {
    uint32_t insn = 0xDAC1BFFEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autib171615_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AUTIB171615);
    std::cout << "  autib171615_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_autibsppcr_64lrr_dp_1src() {
    uint32_t insn = 0xDAC1941Eu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: autibsppcr_64lrr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AUTIBSPPCR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  autibsppcr_64lrr_dp_1src: " << result->to_string() << std::endl;
}

void test_bic_32_log_shift() {
    uint32_t insn = 0x0A200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BIC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  bic_32_log_shift: " << result->to_string() << std::endl;
}

void test_bic_64_log_shift() {
    uint32_t insn = 0x8A200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BIC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  bic_64_log_shift: " << result->to_string() << std::endl;
}

void test_bics_32_log_shift() {
    uint32_t insn = 0x6A200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bics_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BICS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  bics_32_log_shift: " << result->to_string() << std::endl;
}

void test_bics_64_log_shift() {
    uint32_t insn = 0xEA200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bics_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BICS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  bics_64_log_shift: " << result->to_string() << std::endl;
}

void test_ccmn_32_condcmp_imm() {
    uint32_t insn = 0x3A400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmn_32_condcmp_imm" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMN);
    std::cout << "  ccmn_32_condcmp_imm: " << result->to_string() << std::endl;
}

void test_ccmn_64_condcmp_imm() {
    uint32_t insn = 0xBA400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmn_64_condcmp_imm" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMN);
    std::cout << "  ccmn_64_condcmp_imm: " << result->to_string() << std::endl;
}

void test_ccmn_32_condcmp_reg() {
    uint32_t insn = 0x3A400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmn_32_condcmp_reg" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMN);
    std::cout << "  ccmn_32_condcmp_reg: " << result->to_string() << std::endl;
}

void test_ccmn_64_condcmp_reg() {
    uint32_t insn = 0xBA400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmn_64_condcmp_reg" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMN);
    std::cout << "  ccmn_64_condcmp_reg: " << result->to_string() << std::endl;
}

void test_ccmp_32_condcmp_imm() {
    uint32_t insn = 0x7A400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmp_32_condcmp_imm" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMP);
    std::cout << "  ccmp_32_condcmp_imm: " << result->to_string() << std::endl;
}

void test_ccmp_64_condcmp_imm() {
    uint32_t insn = 0xFA400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmp_64_condcmp_imm" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMP);
    std::cout << "  ccmp_64_condcmp_imm: " << result->to_string() << std::endl;
}

void test_ccmp_32_condcmp_reg() {
    uint32_t insn = 0x7A400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmp_32_condcmp_reg" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMP);
    std::cout << "  ccmp_32_condcmp_reg: " << result->to_string() << std::endl;
}

void test_ccmp_64_condcmp_reg() {
    uint32_t insn = 0xFA400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ccmp_64_condcmp_reg" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CCMP);
    std::cout << "  ccmp_64_condcmp_reg: " << result->to_string() << std::endl;
}

void test_cinc_csinc_32_condsel() {
    uint32_t insn = 0x1A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cinc_csinc_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cinc_csinc_32_condsel: " << result->to_string() << std::endl;
}

void test_cinc_csinc_64_condsel() {
    uint32_t insn = 0x9A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cinc_csinc_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cinc_csinc_64_condsel: " << result->to_string() << std::endl;
}

void test_cinv_csinv_32_condsel() {
    uint32_t insn = 0x5A800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cinv_csinv_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cinv_csinv_32_condsel: " << result->to_string() << std::endl;
}

void test_cinv_csinv_64_condsel() {
    uint32_t insn = 0xDA800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cinv_csinv_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cinv_csinv_64_condsel: " << result->to_string() << std::endl;
}

void test_cls_32_dp_1src() {
    uint32_t insn = 0x5AC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cls_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cls_32_dp_1src: " << result->to_string() << std::endl;
}

void test_cls_64_dp_1src() {
    uint32_t insn = 0xDAC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cls_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cls_64_dp_1src: " << result->to_string() << std::endl;
}

void test_clz_32_dp_1src() {
    uint32_t insn = 0x5AC01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clz_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLZ);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  clz_32_dp_1src: " << result->to_string() << std::endl;
}

void test_clz_64_dp_1src() {
    uint32_t insn = 0xDAC01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clz_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLZ);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  clz_64_dp_1src: " << result->to_string() << std::endl;
}

void test_cmn_adds_32s_addsub_ext() {
    uint32_t insn = 0x2B20001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmn_adds_32s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmn_adds_32s_addsub_ext: " << result->to_string() << std::endl;
}

void test_cmn_adds_64s_addsub_ext() {
    uint32_t insn = 0xAB20001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmn_adds_64s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmn_adds_64s_addsub_ext: " << result->to_string() << std::endl;
}

void test_cmn_adds_32_addsub_shift() {
    uint32_t insn = 0x2B00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmn_adds_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmn_adds_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_cmn_adds_64_addsub_shift() {
    uint32_t insn = 0xAB00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmn_adds_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmn_adds_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_cmp_subs_32s_addsub_ext() {
    uint32_t insn = 0x6B20001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmp_subs_32s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmp_subs_32s_addsub_ext: " << result->to_string() << std::endl;
}

void test_cmp_subs_64s_addsub_ext() {
    uint32_t insn = 0xEB20001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmp_subs_64s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmp_subs_64s_addsub_ext: " << result->to_string() << std::endl;
}

void test_cmp_subs_32_addsub_shift() {
    uint32_t insn = 0x6B00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmp_subs_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmp_subs_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_cmp_subs_64_addsub_shift() {
    uint32_t insn = 0xEB00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmp_subs_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cmp_subs_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_cmpp_subps_64s_dp_2src() {
    uint32_t insn = 0xBAC0001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpp_subps_64s_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBPS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cmpp_subps_64s_dp_2src: " << result->to_string() << std::endl;
}

void test_cneg_csneg_32_condsel() {
    uint32_t insn = 0x5A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cneg_csneg_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cneg_csneg_32_condsel: " << result->to_string() << std::endl;
}

void test_cneg_csneg_64_condsel() {
    uint32_t insn = 0xDA800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cneg_csneg_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cneg_csneg_64_condsel: " << result->to_string() << std::endl;
}

void test_cnt_32_dp_1src() {
    uint32_t insn = 0x5AC01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnt_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cnt_32_dp_1src: " << result->to_string() << std::endl;
}

void test_cnt_64_dp_1src() {
    uint32_t insn = 0xDAC01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnt_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cnt_64_dp_1src: " << result->to_string() << std::endl;
}

void test_crc32b_32c_dp_2src() {
    uint32_t insn = 0x1AC04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32b_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32b_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32h_32c_dp_2src() {
    uint32_t insn = 0x1AC04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32h_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32h_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32w_32c_dp_2src() {
    uint32_t insn = 0x1AC04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32w_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32w_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32x_64c_dp_2src() {
    uint32_t insn = 0x9AC04C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32x_64c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32x_64c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32cb_32c_dp_2src() {
    uint32_t insn = 0x1AC05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32cb_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32cb_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32ch_32c_dp_2src() {
    uint32_t insn = 0x1AC05400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32ch_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32ch_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32cw_32c_dp_2src() {
    uint32_t insn = 0x1AC05800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32cw_32c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32cw_32c_dp_2src: " << result->to_string() << std::endl;
}

void test_crc32cx_64c_dp_2src() {
    uint32_t insn = 0x9AC05C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: crc32cx_64c_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  crc32cx_64c_dp_2src: " << result->to_string() << std::endl;
}

void test_csel_32_condsel() {
    uint32_t insn = 0x1A800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csel_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CSEL);
    std::cout << "  csel_32_condsel: " << result->to_string() << std::endl;
}

void test_csel_64_condsel() {
    uint32_t insn = 0x9A800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csel_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CSEL);
    std::cout << "  csel_64_condsel: " << result->to_string() << std::endl;
}

void test_cset_csinc_32_condsel() {
    uint32_t insn = 0x1A9F07E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cset_csinc_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cset_csinc_32_condsel: " << result->to_string() << std::endl;
}

void test_cset_csinc_64_condsel() {
    uint32_t insn = 0x9A9F07E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cset_csinc_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  cset_csinc_64_condsel: " << result->to_string() << std::endl;
}

void test_csetm_csinv_32_condsel() {
    uint32_t insn = 0x5A9F03E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csetm_csinv_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csetm_csinv_32_condsel: " << result->to_string() << std::endl;
}

void test_csetm_csinv_64_condsel() {
    uint32_t insn = 0xDA9F03E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csetm_csinv_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csetm_csinv_64_condsel: " << result->to_string() << std::endl;
}

void test_csinc_32_condsel() {
    uint32_t insn = 0x1A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csinc_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csinc_32_condsel: " << result->to_string() << std::endl;
}

void test_csinc_64_condsel() {
    uint32_t insn = 0x9A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csinc_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csinc_64_condsel: " << result->to_string() << std::endl;
}

void test_csinv_32_condsel() {
    uint32_t insn = 0x5A800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csinv_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csinv_32_condsel: " << result->to_string() << std::endl;
}

void test_csinv_64_condsel() {
    uint32_t insn = 0xDA800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csinv_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csinv_64_condsel: " << result->to_string() << std::endl;
}

void test_csneg_32_condsel() {
    uint32_t insn = 0x5A800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csneg_32_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csneg_32_condsel: " << result->to_string() << std::endl;
}

void test_csneg_64_condsel() {
    uint32_t insn = 0xDA800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: csneg_64_condsel" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  csneg_64_condsel: " << result->to_string() << std::endl;
}

void test_ctz_32_dp_1src() {
    uint32_t insn = 0x5AC01800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ctz_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CTZ);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ctz_32_dp_1src: " << result->to_string() << std::endl;
}

void test_ctz_64_dp_1src() {
    uint32_t insn = 0xDAC01800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ctz_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CTZ);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ctz_64_dp_1src: " << result->to_string() << std::endl;
}

void test_eon_32_log_shift() {
    uint32_t insn = 0x4A200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eon_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EON);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  eon_32_log_shift: " << result->to_string() << std::endl;
}

void test_eon_64_log_shift() {
    uint32_t insn = 0xCA200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eon_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EON);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  eon_64_log_shift: " << result->to_string() << std::endl;
}

void test_eor_32_log_shift() {
    uint32_t insn = 0x4A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  eor_32_log_shift: " << result->to_string() << std::endl;
}

void test_eor_64_log_shift() {
    uint32_t insn = 0xCA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  eor_64_log_shift: " << result->to_string() << std::endl;
}

void test_gmi_64g_dp_2src() {
    uint32_t insn = 0x9AC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: gmi_64g_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::GMI);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  gmi_64g_dp_2src: " << result->to_string() << std::endl;
}

void test_irg_64i_dp_2src() {
    uint32_t insn = 0x9AC01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: irg_64i_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::IRG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    std::cout << "  irg_64i_dp_2src: " << result->to_string() << std::endl;
}

void test_lsl_lslv_32_dp_2src() {
    uint32_t insn = 0x1AC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_lslv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSLV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsl_lslv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_lsl_lslv_64_dp_2src() {
    uint32_t insn = 0x9AC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_lslv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSLV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsl_lslv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_lslv_32_dp_2src() {
    uint32_t insn = 0x1AC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lslv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSLV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lslv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_lslv_64_dp_2src() {
    uint32_t insn = 0x9AC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lslv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSLV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lslv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_lsr_lsrv_32_dp_2src() {
    uint32_t insn = 0x1AC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_lsrv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsr_lsrv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_lsr_lsrv_64_dp_2src() {
    uint32_t insn = 0x9AC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_lsrv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsr_lsrv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_lsrv_32_dp_2src() {
    uint32_t insn = 0x1AC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsrv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsrv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_lsrv_64_dp_2src() {
    uint32_t insn = 0x9AC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsrv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSRV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  lsrv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_madd_32a_dp_3src() {
    uint32_t insn = 0x1B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: madd_32a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  madd_32a_dp_3src: " << result->to_string() << std::endl;
}

void test_madd_64a_dp_3src() {
    uint32_t insn = 0x9B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: madd_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  madd_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_maddpt_64a_dp_3src() {
    uint32_t insn = 0x9B600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: maddpt_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MADDPT);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  maddpt_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_mneg_msub_32a_dp_3src() {
    uint32_t insn = 0x1B00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mneg_msub_32a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mneg_msub_32a_dp_3src: " << result->to_string() << std::endl;
}

void test_mneg_msub_64a_dp_3src() {
    uint32_t insn = 0x9B00FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mneg_msub_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mneg_msub_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_mov_orr_32_log_shift() {
    uint32_t insn = 0x2A0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_orr_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mov_orr_32_log_shift: " << result->to_string() << std::endl;
}

void test_mov_orr_64_log_shift() {
    uint32_t insn = 0xAA0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_orr_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mov_orr_64_log_shift: " << result->to_string() << std::endl;
}

void test_msub_32a_dp_3src() {
    uint32_t insn = 0x1B008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: msub_32a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  msub_32a_dp_3src: " << result->to_string() << std::endl;
}

void test_msub_64a_dp_3src() {
    uint32_t insn = 0x9B008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: msub_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  msub_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_msubpt_64a_dp_3src() {
    uint32_t insn = 0x9B608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: msubpt_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MSUBPT);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  msubpt_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_mul_madd_32a_dp_3src() {
    uint32_t insn = 0x1B007C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_madd_32a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mul_madd_32a_dp_3src: " << result->to_string() << std::endl;
}

void test_mul_madd_64a_dp_3src() {
    uint32_t insn = 0x9B007C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_madd_64a_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mul_madd_64a_dp_3src: " << result->to_string() << std::endl;
}

void test_mvn_orn_32_log_shift() {
    uint32_t insn = 0x2A2003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvn_orn_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mvn_orn_32_log_shift: " << result->to_string() << std::endl;
}

void test_mvn_orn_64_log_shift() {
    uint32_t insn = 0xAA2003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mvn_orn_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  mvn_orn_64_log_shift: " << result->to_string() << std::endl;
}

void test_neg_sub_32_addsub_shift() {
    uint32_t insn = 0x4B0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_sub_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  neg_sub_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_neg_sub_64_addsub_shift() {
    uint32_t insn = 0xCB0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_sub_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  neg_sub_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_negs_subs_32_addsub_shift() {
    uint32_t insn = 0x6B0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: negs_subs_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  negs_subs_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_negs_subs_64_addsub_shift() {
    uint32_t insn = 0xEB0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: negs_subs_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  negs_subs_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_ngc_sbc_32_addsub_carry() {
    uint32_t insn = 0x5A0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ngc_sbc_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ngc_sbc_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_ngc_sbc_64_addsub_carry() {
    uint32_t insn = 0xDA0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ngc_sbc_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ngc_sbc_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_ngcs_sbcs_32_addsub_carry() {
    uint32_t insn = 0x7A0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ngcs_sbcs_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ngcs_sbcs_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_ngcs_sbcs_64_addsub_carry() {
    uint32_t insn = 0xFA0003E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ngcs_sbcs_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  ngcs_sbcs_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_orn_32_log_shift() {
    uint32_t insn = 0x2A200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orn_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  orn_32_log_shift: " << result->to_string() << std::endl;
}

void test_orn_64_log_shift() {
    uint32_t insn = 0xAA200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orn_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  orn_64_log_shift: " << result->to_string() << std::endl;
}

void test_orr_32_log_shift() {
    uint32_t insn = 0x2A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  orr_32_log_shift: " << result->to_string() << std::endl;
}

void test_orr_64_log_shift() {
    uint32_t insn = 0xAA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  orr_64_log_shift: " << result->to_string() << std::endl;
}

void test_pacda_64p_dp_1src() {
    uint32_t insn = 0xDAC10800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacda_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  pacda_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_pacdza_64z_dp_1src() {
    uint32_t insn = 0xDAC12BE0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacdza_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  pacdza_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_pacdb_64p_dp_1src() {
    uint32_t insn = 0xDAC10C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacdb_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  pacdb_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_pacdzb_64z_dp_1src() {
    uint32_t insn = 0xDAC12FE0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacdzb_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  pacdzb_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_pacga_64p_dp_2src() {
    uint32_t insn = 0x9AC03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacga_64p_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACGA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  pacga_64p_dp_2src: " << result->to_string() << std::endl;
}

void test_pacia_64p_dp_1src() {
    uint32_t insn = 0xDAC10000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacia_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  pacia_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_paciza_64z_dp_1src() {
    uint32_t insn = 0xDAC123E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: paciza_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  paciza_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_pacia171615_64lr_dp_1src() {
    uint32_t insn = 0xDAC18BFEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacia171615_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACIA171615);
    std::cout << "  pacia171615_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_paciasppc_64lr_dp_1src() {
    uint32_t insn = 0xDAC1A3FEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: paciasppc_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACIASPPC);
    std::cout << "  paciasppc_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_pacib_64p_dp_1src() {
    uint32_t insn = 0xDAC10400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacib_64p_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  pacib_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_pacizb_64z_dp_1src() {
    uint32_t insn = 0xDAC127E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacizb_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  pacizb_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_pacib171615_64lr_dp_1src() {
    uint32_t insn = 0xDAC18FFEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacib171615_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACIB171615);
    std::cout << "  pacib171615_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_pacibsppc_64lr_dp_1src() {
    uint32_t insn = 0xDAC1A7FEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacibsppc_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACIBSPPC);
    std::cout << "  pacibsppc_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_pacnbiasppc_64lr_dp_1src() {
    uint32_t insn = 0xDAC183FEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacnbiasppc_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACNBIASPPC);
    std::cout << "  pacnbiasppc_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_pacnbibsppc_64lr_dp_1src() {
    uint32_t insn = 0xDAC187FEu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pacnbibsppc_64lr_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PACNBIBSPPC);
    std::cout << "  pacnbibsppc_64lr_dp_1src: " << result->to_string() << std::endl;
}

void test_rbit_32_dp_1src() {
    uint32_t insn = 0x5AC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rbit_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RBIT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rbit_32_dp_1src: " << result->to_string() << std::endl;
}

void test_rbit_64_dp_1src() {
    uint32_t insn = 0xDAC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rbit_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RBIT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rbit_64_dp_1src: " << result->to_string() << std::endl;
}

void test_rev_32_dp_1src() {
    uint32_t insn = 0x5AC00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev_32_dp_1src: " << result->to_string() << std::endl;
}

void test_rev_64_dp_1src() {
    uint32_t insn = 0xDAC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev_64_dp_1src: " << result->to_string() << std::endl;
}

void test_rev16_32_dp_1src() {
    uint32_t insn = 0x5AC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev16_32_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV16);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev16_32_dp_1src: " << result->to_string() << std::endl;
}

void test_rev16_64_dp_1src() {
    uint32_t insn = 0xDAC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev16_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV16);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev16_64_dp_1src: " << result->to_string() << std::endl;
}

void test_rev32_64_dp_1src() {
    uint32_t insn = 0xDAC00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev32_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV32);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev32_64_dp_1src: " << result->to_string() << std::endl;
}

void test_rev64_rev_64_dp_1src() {
    uint32_t insn = 0xDAC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev64_rev_64_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  rev64_rev_64_dp_1src: " << result->to_string() << std::endl;
}

void test_rmif_only_rmif() {
    uint32_t insn = 0xBA000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rmif_only_rmif" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RMIF);
    std::cout << "  rmif_only_rmif: " << result->to_string() << std::endl;
}

void test_ror_rorv_32_dp_2src() {
    uint32_t insn = 0x1AC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ror_rorv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RORV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ror_rorv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_ror_rorv_64_dp_2src() {
    uint32_t insn = 0x9AC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ror_rorv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RORV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ror_rorv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_rorv_32_dp_2src() {
    uint32_t insn = 0x1AC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rorv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RORV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  rorv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_rorv_64_dp_2src() {
    uint32_t insn = 0x9AC02C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rorv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RORV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  rorv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_sbc_32_addsub_carry() {
    uint32_t insn = 0x5A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbc_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sbc_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_sbc_64_addsub_carry() {
    uint32_t insn = 0xDA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbc_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sbc_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_sbcs_32_addsub_carry() {
    uint32_t insn = 0x7A000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbcs_32_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sbcs_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_sbcs_64_addsub_carry() {
    uint32_t insn = 0xFA000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbcs_64_addsub_carry" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sbcs_64_addsub_carry: " << result->to_string() << std::endl;
}

void test_sdiv_32_dp_2src() {
    uint32_t insn = 0x1AC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdiv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDIV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sdiv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_sdiv_64_dp_2src() {
    uint32_t insn = 0x9AC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdiv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDIV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sdiv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_setf8_only_setf() {
    uint32_t insn = 0x3A00080Du;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setf8_only_setf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  setf8_only_setf: " << result->to_string() << std::endl;
}

void test_setf16_only_setf() {
    uint32_t insn = 0x3A00480Du;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setf16_only_setf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  setf16_only_setf: " << result->to_string() << std::endl;
}

void test_smaddl_64wa_dp_3src() {
    uint32_t insn = 0x9B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaddl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMADDL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  smaddl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_smax_32_dp_2src() {
    uint32_t insn = 0x1AC06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smax_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smax_32_dp_2src: " << result->to_string() << std::endl;
}

void test_smax_64_dp_2src() {
    uint32_t insn = 0x9AC06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smax_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smax_64_dp_2src: " << result->to_string() << std::endl;
}

void test_smin_32_dp_2src() {
    uint32_t insn = 0x1AC06800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smin_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMIN);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smin_32_dp_2src: " << result->to_string() << std::endl;
}

void test_smin_64_dp_2src() {
    uint32_t insn = 0x9AC06800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smin_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMIN);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smin_64_dp_2src: " << result->to_string() << std::endl;
}

void test_smnegl_smsubl_64wa_dp_3src() {
    uint32_t insn = 0x9B20FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smnegl_smsubl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMSUBL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smnegl_smsubl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_smsubl_64wa_dp_3src() {
    uint32_t insn = 0x9B208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smsubl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMSUBL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  smsubl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_smulh_64_dp_3src() {
    uint32_t insn = 0x9B400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smulh_64_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smulh_64_dp_3src: " << result->to_string() << std::endl;
}

void test_smull_smaddl_64wa_dp_3src() {
    uint32_t insn = 0x9B207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smull_smaddl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMADDL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  smull_smaddl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_sub_32_addsub_ext() {
    uint32_t insn = 0x4B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_32_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  sub_32_addsub_ext: " << result->to_string() << std::endl;
}

void test_sub_64_addsub_ext() {
    uint32_t insn = 0xCB200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_64_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  sub_64_addsub_ext: " << result->to_string() << std::endl;
}

void test_sub_32_addsub_shift() {
    uint32_t insn = 0x4B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  sub_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_sub_64_addsub_shift() {
    uint32_t insn = 0xCB000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  sub_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_subp_64s_dp_2src() {
    uint32_t insn = 0x9AC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subp_64s_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  subp_64s_dp_2src: " << result->to_string() << std::endl;
}

void test_subps_64s_dp_2src() {
    uint32_t insn = 0xBAC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subps_64s_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBPS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  subps_64s_dp_2src: " << result->to_string() << std::endl;
}

void test_subpt_64_addsub_pt() {
    uint32_t insn = 0xDA002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subpt_64_addsub_pt" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::RegisterList);
    std::cout << "  subpt_64_addsub_pt: " << result->to_string() << std::endl;
}

void test_subs_32s_addsub_ext() {
    uint32_t insn = 0x6B200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subs_32s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  subs_32s_addsub_ext: " << result->to_string() << std::endl;
}

void test_subs_64s_addsub_ext() {
    uint32_t insn = 0xEB200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subs_64s_addsub_ext" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  subs_64s_addsub_ext: " << result->to_string() << std::endl;
}

void test_subs_32_addsub_shift() {
    uint32_t insn = 0x6B000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subs_32_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  subs_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_subs_64_addsub_shift() {
    uint32_t insn = 0xEB000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subs_64_addsub_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  subs_64_addsub_shift: " << result->to_string() << std::endl;
}

void test_tst_ands_32_log_shift() {
    uint32_t insn = 0x6A00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tst_ands_32_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  tst_ands_32_log_shift: " << result->to_string() << std::endl;
}

void test_tst_ands_64_log_shift() {
    uint32_t insn = 0xEA00001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tst_ands_64_log_shift" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  tst_ands_64_log_shift: " << result->to_string() << std::endl;
}

void test_udiv_32_dp_2src() {
    uint32_t insn = 0x1AC00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udiv_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDIV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  udiv_32_dp_2src: " << result->to_string() << std::endl;
}

void test_udiv_64_dp_2src() {
    uint32_t insn = 0x9AC00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udiv_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDIV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  udiv_64_dp_2src: " << result->to_string() << std::endl;
}

void test_umaddl_64wa_dp_3src() {
    uint32_t insn = 0x9BA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaddl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMADDL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  umaddl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_umax_32_dp_2src() {
    uint32_t insn = 0x1AC06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umax_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umax_32_dp_2src: " << result->to_string() << std::endl;
}

void test_umax_64_dp_2src() {
    uint32_t insn = 0x9AC06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umax_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umax_64_dp_2src: " << result->to_string() << std::endl;
}

void test_umin_32_dp_2src() {
    uint32_t insn = 0x1AC06C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umin_32_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMIN);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umin_32_dp_2src: " << result->to_string() << std::endl;
}

void test_umin_64_dp_2src() {
    uint32_t insn = 0x9AC06C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umin_64_dp_2src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMIN);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umin_64_dp_2src: " << result->to_string() << std::endl;
}

void test_umnegl_umsubl_64wa_dp_3src() {
    uint32_t insn = 0x9BA0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umnegl_umsubl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMSUBL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umnegl_umsubl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_umsubl_64wa_dp_3src() {
    uint32_t insn = 0x9BA08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umsubl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMSUBL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
    std::cout << "  umsubl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_umulh_64_dp_3src() {
    uint32_t insn = 0x9BC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umulh_64_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umulh_64_dp_3src: " << result->to_string() << std::endl;
}

void test_umull_umaddl_64wa_dp_3src() {
    uint32_t insn = 0x9BA07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umull_umaddl_64wa_dp_3src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMADDL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  umull_umaddl_64wa_dp_3src: " << result->to_string() << std::endl;
}

void test_xpacd_64z_dp_1src() {
    uint32_t insn = 0xDAC147E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: xpacd_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  xpacd_64z_dp_1src: " << result->to_string() << std::endl;
}

void test_xpaci_64z_dp_1src() {
    uint32_t insn = 0xDAC143E0u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: xpaci_64z_dp_1src" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  xpaci_64z_dp_1src: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running dpreg encoding tests (201 encodings)..." << std::endl;
    int failed = 0;

    try { test_abs_32_dp_1src(); } catch (...) { std::cerr << "FAIL: abs_32_dp_1src" << std::endl; failed++; }
    try { test_abs_64_dp_1src(); } catch (...) { std::cerr << "FAIL: abs_64_dp_1src" << std::endl; failed++; }
    try { test_adc_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: adc_32_addsub_carry" << std::endl; failed++; }
    try { test_adc_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: adc_64_addsub_carry" << std::endl; failed++; }
    try { test_adcs_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: adcs_32_addsub_carry" << std::endl; failed++; }
    try { test_adcs_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: adcs_64_addsub_carry" << std::endl; failed++; }
    try { test_add_32_addsub_ext(); } catch (...) { std::cerr << "FAIL: add_32_addsub_ext" << std::endl; failed++; }
    try { test_add_64_addsub_ext(); } catch (...) { std::cerr << "FAIL: add_64_addsub_ext" << std::endl; failed++; }
    try { test_add_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: add_32_addsub_shift" << std::endl; failed++; }
    try { test_add_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: add_64_addsub_shift" << std::endl; failed++; }
    try { test_addpt_64_addsub_pt(); } catch (...) { std::cerr << "FAIL: addpt_64_addsub_pt" << std::endl; failed++; }
    try { test_adds_32s_addsub_ext(); } catch (...) { std::cerr << "FAIL: adds_32s_addsub_ext" << std::endl; failed++; }
    try { test_adds_64s_addsub_ext(); } catch (...) { std::cerr << "FAIL: adds_64s_addsub_ext" << std::endl; failed++; }
    try { test_adds_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: adds_32_addsub_shift" << std::endl; failed++; }
    try { test_adds_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: adds_64_addsub_shift" << std::endl; failed++; }
    try { test_and_32_log_shift(); } catch (...) { std::cerr << "FAIL: and_32_log_shift" << std::endl; failed++; }
    try { test_and_64_log_shift(); } catch (...) { std::cerr << "FAIL: and_64_log_shift" << std::endl; failed++; }
    try { test_ands_32_log_shift(); } catch (...) { std::cerr << "FAIL: ands_32_log_shift" << std::endl; failed++; }
    try { test_ands_64_log_shift(); } catch (...) { std::cerr << "FAIL: ands_64_log_shift" << std::endl; failed++; }
    try { test_asr_asrv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: asr_asrv_32_dp_2src" << std::endl; failed++; }
    try { test_asr_asrv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: asr_asrv_64_dp_2src" << std::endl; failed++; }
    try { test_asrv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: asrv_32_dp_2src" << std::endl; failed++; }
    try { test_asrv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: asrv_64_dp_2src" << std::endl; failed++; }
    try { test_autda_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: autda_64p_dp_1src" << std::endl; failed++; }
    try { test_autdza_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: autdza_64z_dp_1src" << std::endl; failed++; }
    try { test_autdb_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: autdb_64p_dp_1src" << std::endl; failed++; }
    try { test_autdzb_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: autdzb_64z_dp_1src" << std::endl; failed++; }
    try { test_autia_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: autia_64p_dp_1src" << std::endl; failed++; }
    try { test_autiza_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: autiza_64z_dp_1src" << std::endl; failed++; }
    try { test_autia171615_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: autia171615_64lr_dp_1src" << std::endl; failed++; }
    try { test_autiasppcr_64lrr_dp_1src(); } catch (...) { std::cerr << "FAIL: autiasppcr_64lrr_dp_1src" << std::endl; failed++; }
    try { test_autib_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: autib_64p_dp_1src" << std::endl; failed++; }
    try { test_autizb_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: autizb_64z_dp_1src" << std::endl; failed++; }
    try { test_autib171615_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: autib171615_64lr_dp_1src" << std::endl; failed++; }
    try { test_autibsppcr_64lrr_dp_1src(); } catch (...) { std::cerr << "FAIL: autibsppcr_64lrr_dp_1src" << std::endl; failed++; }
    try { test_bic_32_log_shift(); } catch (...) { std::cerr << "FAIL: bic_32_log_shift" << std::endl; failed++; }
    try { test_bic_64_log_shift(); } catch (...) { std::cerr << "FAIL: bic_64_log_shift" << std::endl; failed++; }
    try { test_bics_32_log_shift(); } catch (...) { std::cerr << "FAIL: bics_32_log_shift" << std::endl; failed++; }
    try { test_bics_64_log_shift(); } catch (...) { std::cerr << "FAIL: bics_64_log_shift" << std::endl; failed++; }
    try { test_ccmn_32_condcmp_imm(); } catch (...) { std::cerr << "FAIL: ccmn_32_condcmp_imm" << std::endl; failed++; }
    try { test_ccmn_64_condcmp_imm(); } catch (...) { std::cerr << "FAIL: ccmn_64_condcmp_imm" << std::endl; failed++; }
    try { test_ccmn_32_condcmp_reg(); } catch (...) { std::cerr << "FAIL: ccmn_32_condcmp_reg" << std::endl; failed++; }
    try { test_ccmn_64_condcmp_reg(); } catch (...) { std::cerr << "FAIL: ccmn_64_condcmp_reg" << std::endl; failed++; }
    try { test_ccmp_32_condcmp_imm(); } catch (...) { std::cerr << "FAIL: ccmp_32_condcmp_imm" << std::endl; failed++; }
    try { test_ccmp_64_condcmp_imm(); } catch (...) { std::cerr << "FAIL: ccmp_64_condcmp_imm" << std::endl; failed++; }
    try { test_ccmp_32_condcmp_reg(); } catch (...) { std::cerr << "FAIL: ccmp_32_condcmp_reg" << std::endl; failed++; }
    try { test_ccmp_64_condcmp_reg(); } catch (...) { std::cerr << "FAIL: ccmp_64_condcmp_reg" << std::endl; failed++; }
    try { test_cinc_csinc_32_condsel(); } catch (...) { std::cerr << "FAIL: cinc_csinc_32_condsel" << std::endl; failed++; }
    try { test_cinc_csinc_64_condsel(); } catch (...) { std::cerr << "FAIL: cinc_csinc_64_condsel" << std::endl; failed++; }
    try { test_cinv_csinv_32_condsel(); } catch (...) { std::cerr << "FAIL: cinv_csinv_32_condsel" << std::endl; failed++; }
    try { test_cinv_csinv_64_condsel(); } catch (...) { std::cerr << "FAIL: cinv_csinv_64_condsel" << std::endl; failed++; }
    try { test_cls_32_dp_1src(); } catch (...) { std::cerr << "FAIL: cls_32_dp_1src" << std::endl; failed++; }
    try { test_cls_64_dp_1src(); } catch (...) { std::cerr << "FAIL: cls_64_dp_1src" << std::endl; failed++; }
    try { test_clz_32_dp_1src(); } catch (...) { std::cerr << "FAIL: clz_32_dp_1src" << std::endl; failed++; }
    try { test_clz_64_dp_1src(); } catch (...) { std::cerr << "FAIL: clz_64_dp_1src" << std::endl; failed++; }
    try { test_cmn_adds_32s_addsub_ext(); } catch (...) { std::cerr << "FAIL: cmn_adds_32s_addsub_ext" << std::endl; failed++; }
    try { test_cmn_adds_64s_addsub_ext(); } catch (...) { std::cerr << "FAIL: cmn_adds_64s_addsub_ext" << std::endl; failed++; }
    try { test_cmn_adds_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: cmn_adds_32_addsub_shift" << std::endl; failed++; }
    try { test_cmn_adds_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: cmn_adds_64_addsub_shift" << std::endl; failed++; }
    try { test_cmp_subs_32s_addsub_ext(); } catch (...) { std::cerr << "FAIL: cmp_subs_32s_addsub_ext" << std::endl; failed++; }
    try { test_cmp_subs_64s_addsub_ext(); } catch (...) { std::cerr << "FAIL: cmp_subs_64s_addsub_ext" << std::endl; failed++; }
    try { test_cmp_subs_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: cmp_subs_32_addsub_shift" << std::endl; failed++; }
    try { test_cmp_subs_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: cmp_subs_64_addsub_shift" << std::endl; failed++; }
    try { test_cmpp_subps_64s_dp_2src(); } catch (...) { std::cerr << "FAIL: cmpp_subps_64s_dp_2src" << std::endl; failed++; }
    try { test_cneg_csneg_32_condsel(); } catch (...) { std::cerr << "FAIL: cneg_csneg_32_condsel" << std::endl; failed++; }
    try { test_cneg_csneg_64_condsel(); } catch (...) { std::cerr << "FAIL: cneg_csneg_64_condsel" << std::endl; failed++; }
    try { test_cnt_32_dp_1src(); } catch (...) { std::cerr << "FAIL: cnt_32_dp_1src" << std::endl; failed++; }
    try { test_cnt_64_dp_1src(); } catch (...) { std::cerr << "FAIL: cnt_64_dp_1src" << std::endl; failed++; }
    try { test_crc32b_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32b_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32h_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32h_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32w_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32w_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32x_64c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32x_64c_dp_2src" << std::endl; failed++; }
    try { test_crc32cb_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32cb_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32ch_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32ch_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32cw_32c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32cw_32c_dp_2src" << std::endl; failed++; }
    try { test_crc32cx_64c_dp_2src(); } catch (...) { std::cerr << "FAIL: crc32cx_64c_dp_2src" << std::endl; failed++; }
    try { test_csel_32_condsel(); } catch (...) { std::cerr << "FAIL: csel_32_condsel" << std::endl; failed++; }
    try { test_csel_64_condsel(); } catch (...) { std::cerr << "FAIL: csel_64_condsel" << std::endl; failed++; }
    try { test_cset_csinc_32_condsel(); } catch (...) { std::cerr << "FAIL: cset_csinc_32_condsel" << std::endl; failed++; }
    try { test_cset_csinc_64_condsel(); } catch (...) { std::cerr << "FAIL: cset_csinc_64_condsel" << std::endl; failed++; }
    try { test_csetm_csinv_32_condsel(); } catch (...) { std::cerr << "FAIL: csetm_csinv_32_condsel" << std::endl; failed++; }
    try { test_csetm_csinv_64_condsel(); } catch (...) { std::cerr << "FAIL: csetm_csinv_64_condsel" << std::endl; failed++; }
    try { test_csinc_32_condsel(); } catch (...) { std::cerr << "FAIL: csinc_32_condsel" << std::endl; failed++; }
    try { test_csinc_64_condsel(); } catch (...) { std::cerr << "FAIL: csinc_64_condsel" << std::endl; failed++; }
    try { test_csinv_32_condsel(); } catch (...) { std::cerr << "FAIL: csinv_32_condsel" << std::endl; failed++; }
    try { test_csinv_64_condsel(); } catch (...) { std::cerr << "FAIL: csinv_64_condsel" << std::endl; failed++; }
    try { test_csneg_32_condsel(); } catch (...) { std::cerr << "FAIL: csneg_32_condsel" << std::endl; failed++; }
    try { test_csneg_64_condsel(); } catch (...) { std::cerr << "FAIL: csneg_64_condsel" << std::endl; failed++; }
    try { test_ctz_32_dp_1src(); } catch (...) { std::cerr << "FAIL: ctz_32_dp_1src" << std::endl; failed++; }
    try { test_ctz_64_dp_1src(); } catch (...) { std::cerr << "FAIL: ctz_64_dp_1src" << std::endl; failed++; }
    try { test_eon_32_log_shift(); } catch (...) { std::cerr << "FAIL: eon_32_log_shift" << std::endl; failed++; }
    try { test_eon_64_log_shift(); } catch (...) { std::cerr << "FAIL: eon_64_log_shift" << std::endl; failed++; }
    try { test_eor_32_log_shift(); } catch (...) { std::cerr << "FAIL: eor_32_log_shift" << std::endl; failed++; }
    try { test_eor_64_log_shift(); } catch (...) { std::cerr << "FAIL: eor_64_log_shift" << std::endl; failed++; }
    try { test_gmi_64g_dp_2src(); } catch (...) { std::cerr << "FAIL: gmi_64g_dp_2src" << std::endl; failed++; }
    try { test_irg_64i_dp_2src(); } catch (...) { std::cerr << "FAIL: irg_64i_dp_2src" << std::endl; failed++; }
    try { test_lsl_lslv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: lsl_lslv_32_dp_2src" << std::endl; failed++; }
    try { test_lsl_lslv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: lsl_lslv_64_dp_2src" << std::endl; failed++; }
    try { test_lslv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: lslv_32_dp_2src" << std::endl; failed++; }
    try { test_lslv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: lslv_64_dp_2src" << std::endl; failed++; }
    try { test_lsr_lsrv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: lsr_lsrv_32_dp_2src" << std::endl; failed++; }
    try { test_lsr_lsrv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: lsr_lsrv_64_dp_2src" << std::endl; failed++; }
    try { test_lsrv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: lsrv_32_dp_2src" << std::endl; failed++; }
    try { test_lsrv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: lsrv_64_dp_2src" << std::endl; failed++; }
    try { test_madd_32a_dp_3src(); } catch (...) { std::cerr << "FAIL: madd_32a_dp_3src" << std::endl; failed++; }
    try { test_madd_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: madd_64a_dp_3src" << std::endl; failed++; }
    try { test_maddpt_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: maddpt_64a_dp_3src" << std::endl; failed++; }
    try { test_mneg_msub_32a_dp_3src(); } catch (...) { std::cerr << "FAIL: mneg_msub_32a_dp_3src" << std::endl; failed++; }
    try { test_mneg_msub_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: mneg_msub_64a_dp_3src" << std::endl; failed++; }
    try { test_mov_orr_32_log_shift(); } catch (...) { std::cerr << "FAIL: mov_orr_32_log_shift" << std::endl; failed++; }
    try { test_mov_orr_64_log_shift(); } catch (...) { std::cerr << "FAIL: mov_orr_64_log_shift" << std::endl; failed++; }
    try { test_msub_32a_dp_3src(); } catch (...) { std::cerr << "FAIL: msub_32a_dp_3src" << std::endl; failed++; }
    try { test_msub_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: msub_64a_dp_3src" << std::endl; failed++; }
    try { test_msubpt_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: msubpt_64a_dp_3src" << std::endl; failed++; }
    try { test_mul_madd_32a_dp_3src(); } catch (...) { std::cerr << "FAIL: mul_madd_32a_dp_3src" << std::endl; failed++; }
    try { test_mul_madd_64a_dp_3src(); } catch (...) { std::cerr << "FAIL: mul_madd_64a_dp_3src" << std::endl; failed++; }
    try { test_mvn_orn_32_log_shift(); } catch (...) { std::cerr << "FAIL: mvn_orn_32_log_shift" << std::endl; failed++; }
    try { test_mvn_orn_64_log_shift(); } catch (...) { std::cerr << "FAIL: mvn_orn_64_log_shift" << std::endl; failed++; }
    try { test_neg_sub_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: neg_sub_32_addsub_shift" << std::endl; failed++; }
    try { test_neg_sub_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: neg_sub_64_addsub_shift" << std::endl; failed++; }
    try { test_negs_subs_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: negs_subs_32_addsub_shift" << std::endl; failed++; }
    try { test_negs_subs_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: negs_subs_64_addsub_shift" << std::endl; failed++; }
    try { test_ngc_sbc_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: ngc_sbc_32_addsub_carry" << std::endl; failed++; }
    try { test_ngc_sbc_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: ngc_sbc_64_addsub_carry" << std::endl; failed++; }
    try { test_ngcs_sbcs_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: ngcs_sbcs_32_addsub_carry" << std::endl; failed++; }
    try { test_ngcs_sbcs_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: ngcs_sbcs_64_addsub_carry" << std::endl; failed++; }
    try { test_orn_32_log_shift(); } catch (...) { std::cerr << "FAIL: orn_32_log_shift" << std::endl; failed++; }
    try { test_orn_64_log_shift(); } catch (...) { std::cerr << "FAIL: orn_64_log_shift" << std::endl; failed++; }
    try { test_orr_32_log_shift(); } catch (...) { std::cerr << "FAIL: orr_32_log_shift" << std::endl; failed++; }
    try { test_orr_64_log_shift(); } catch (...) { std::cerr << "FAIL: orr_64_log_shift" << std::endl; failed++; }
    try { test_pacda_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: pacda_64p_dp_1src" << std::endl; failed++; }
    try { test_pacdza_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: pacdza_64z_dp_1src" << std::endl; failed++; }
    try { test_pacdb_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: pacdb_64p_dp_1src" << std::endl; failed++; }
    try { test_pacdzb_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: pacdzb_64z_dp_1src" << std::endl; failed++; }
    try { test_pacga_64p_dp_2src(); } catch (...) { std::cerr << "FAIL: pacga_64p_dp_2src" << std::endl; failed++; }
    try { test_pacia_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: pacia_64p_dp_1src" << std::endl; failed++; }
    try { test_paciza_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: paciza_64z_dp_1src" << std::endl; failed++; }
    try { test_pacia171615_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: pacia171615_64lr_dp_1src" << std::endl; failed++; }
    try { test_paciasppc_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: paciasppc_64lr_dp_1src" << std::endl; failed++; }
    try { test_pacib_64p_dp_1src(); } catch (...) { std::cerr << "FAIL: pacib_64p_dp_1src" << std::endl; failed++; }
    try { test_pacizb_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: pacizb_64z_dp_1src" << std::endl; failed++; }
    try { test_pacib171615_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: pacib171615_64lr_dp_1src" << std::endl; failed++; }
    try { test_pacibsppc_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: pacibsppc_64lr_dp_1src" << std::endl; failed++; }
    try { test_pacnbiasppc_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: pacnbiasppc_64lr_dp_1src" << std::endl; failed++; }
    try { test_pacnbibsppc_64lr_dp_1src(); } catch (...) { std::cerr << "FAIL: pacnbibsppc_64lr_dp_1src" << std::endl; failed++; }
    try { test_rbit_32_dp_1src(); } catch (...) { std::cerr << "FAIL: rbit_32_dp_1src" << std::endl; failed++; }
    try { test_rbit_64_dp_1src(); } catch (...) { std::cerr << "FAIL: rbit_64_dp_1src" << std::endl; failed++; }
    try { test_rev_32_dp_1src(); } catch (...) { std::cerr << "FAIL: rev_32_dp_1src" << std::endl; failed++; }
    try { test_rev_64_dp_1src(); } catch (...) { std::cerr << "FAIL: rev_64_dp_1src" << std::endl; failed++; }
    try { test_rev16_32_dp_1src(); } catch (...) { std::cerr << "FAIL: rev16_32_dp_1src" << std::endl; failed++; }
    try { test_rev16_64_dp_1src(); } catch (...) { std::cerr << "FAIL: rev16_64_dp_1src" << std::endl; failed++; }
    try { test_rev32_64_dp_1src(); } catch (...) { std::cerr << "FAIL: rev32_64_dp_1src" << std::endl; failed++; }
    try { test_rev64_rev_64_dp_1src(); } catch (...) { std::cerr << "FAIL: rev64_rev_64_dp_1src" << std::endl; failed++; }
    try { test_rmif_only_rmif(); } catch (...) { std::cerr << "FAIL: rmif_only_rmif" << std::endl; failed++; }
    try { test_ror_rorv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: ror_rorv_32_dp_2src" << std::endl; failed++; }
    try { test_ror_rorv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: ror_rorv_64_dp_2src" << std::endl; failed++; }
    try { test_rorv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: rorv_32_dp_2src" << std::endl; failed++; }
    try { test_rorv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: rorv_64_dp_2src" << std::endl; failed++; }
    try { test_sbc_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: sbc_32_addsub_carry" << std::endl; failed++; }
    try { test_sbc_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: sbc_64_addsub_carry" << std::endl; failed++; }
    try { test_sbcs_32_addsub_carry(); } catch (...) { std::cerr << "FAIL: sbcs_32_addsub_carry" << std::endl; failed++; }
    try { test_sbcs_64_addsub_carry(); } catch (...) { std::cerr << "FAIL: sbcs_64_addsub_carry" << std::endl; failed++; }
    try { test_sdiv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: sdiv_32_dp_2src" << std::endl; failed++; }
    try { test_sdiv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: sdiv_64_dp_2src" << std::endl; failed++; }
    try { test_setf8_only_setf(); } catch (...) { std::cerr << "FAIL: setf8_only_setf" << std::endl; failed++; }
    try { test_setf16_only_setf(); } catch (...) { std::cerr << "FAIL: setf16_only_setf" << std::endl; failed++; }
    try { test_smaddl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: smaddl_64wa_dp_3src" << std::endl; failed++; }
    try { test_smax_32_dp_2src(); } catch (...) { std::cerr << "FAIL: smax_32_dp_2src" << std::endl; failed++; }
    try { test_smax_64_dp_2src(); } catch (...) { std::cerr << "FAIL: smax_64_dp_2src" << std::endl; failed++; }
    try { test_smin_32_dp_2src(); } catch (...) { std::cerr << "FAIL: smin_32_dp_2src" << std::endl; failed++; }
    try { test_smin_64_dp_2src(); } catch (...) { std::cerr << "FAIL: smin_64_dp_2src" << std::endl; failed++; }
    try { test_smnegl_smsubl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: smnegl_smsubl_64wa_dp_3src" << std::endl; failed++; }
    try { test_smsubl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: smsubl_64wa_dp_3src" << std::endl; failed++; }
    try { test_smulh_64_dp_3src(); } catch (...) { std::cerr << "FAIL: smulh_64_dp_3src" << std::endl; failed++; }
    try { test_smull_smaddl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: smull_smaddl_64wa_dp_3src" << std::endl; failed++; }
    try { test_sub_32_addsub_ext(); } catch (...) { std::cerr << "FAIL: sub_32_addsub_ext" << std::endl; failed++; }
    try { test_sub_64_addsub_ext(); } catch (...) { std::cerr << "FAIL: sub_64_addsub_ext" << std::endl; failed++; }
    try { test_sub_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: sub_32_addsub_shift" << std::endl; failed++; }
    try { test_sub_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: sub_64_addsub_shift" << std::endl; failed++; }
    try { test_subp_64s_dp_2src(); } catch (...) { std::cerr << "FAIL: subp_64s_dp_2src" << std::endl; failed++; }
    try { test_subps_64s_dp_2src(); } catch (...) { std::cerr << "FAIL: subps_64s_dp_2src" << std::endl; failed++; }
    try { test_subpt_64_addsub_pt(); } catch (...) { std::cerr << "FAIL: subpt_64_addsub_pt" << std::endl; failed++; }
    try { test_subs_32s_addsub_ext(); } catch (...) { std::cerr << "FAIL: subs_32s_addsub_ext" << std::endl; failed++; }
    try { test_subs_64s_addsub_ext(); } catch (...) { std::cerr << "FAIL: subs_64s_addsub_ext" << std::endl; failed++; }
    try { test_subs_32_addsub_shift(); } catch (...) { std::cerr << "FAIL: subs_32_addsub_shift" << std::endl; failed++; }
    try { test_subs_64_addsub_shift(); } catch (...) { std::cerr << "FAIL: subs_64_addsub_shift" << std::endl; failed++; }
    try { test_tst_ands_32_log_shift(); } catch (...) { std::cerr << "FAIL: tst_ands_32_log_shift" << std::endl; failed++; }
    try { test_tst_ands_64_log_shift(); } catch (...) { std::cerr << "FAIL: tst_ands_64_log_shift" << std::endl; failed++; }
    try { test_udiv_32_dp_2src(); } catch (...) { std::cerr << "FAIL: udiv_32_dp_2src" << std::endl; failed++; }
    try { test_udiv_64_dp_2src(); } catch (...) { std::cerr << "FAIL: udiv_64_dp_2src" << std::endl; failed++; }
    try { test_umaddl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: umaddl_64wa_dp_3src" << std::endl; failed++; }
    try { test_umax_32_dp_2src(); } catch (...) { std::cerr << "FAIL: umax_32_dp_2src" << std::endl; failed++; }
    try { test_umax_64_dp_2src(); } catch (...) { std::cerr << "FAIL: umax_64_dp_2src" << std::endl; failed++; }
    try { test_umin_32_dp_2src(); } catch (...) { std::cerr << "FAIL: umin_32_dp_2src" << std::endl; failed++; }
    try { test_umin_64_dp_2src(); } catch (...) { std::cerr << "FAIL: umin_64_dp_2src" << std::endl; failed++; }
    try { test_umnegl_umsubl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: umnegl_umsubl_64wa_dp_3src" << std::endl; failed++; }
    try { test_umsubl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: umsubl_64wa_dp_3src" << std::endl; failed++; }
    try { test_umulh_64_dp_3src(); } catch (...) { std::cerr << "FAIL: umulh_64_dp_3src" << std::endl; failed++; }
    try { test_umull_umaddl_64wa_dp_3src(); } catch (...) { std::cerr << "FAIL: umull_umaddl_64wa_dp_3src" << std::endl; failed++; }
    try { test_xpacd_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: xpacd_64z_dp_1src" << std::endl; failed++; }
    try { test_xpaci_64z_dp_1src(); } catch (...) { std::cerr << "FAIL: xpaci_64z_dp_1src" << std::endl; failed++; }

    std::cout << (201 - failed) << " / 201 passed" << std::endl;
    return failed;
}
