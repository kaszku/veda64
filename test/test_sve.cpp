// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_z_p_z_m() {
    uint32_t insn = 0x0416A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ABS);
#ifdef VEDA64_STRINGS
    std::cout << "  abs_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_abs_z_p_z_z() {
    uint32_t insn = 0x0406A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: abs_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ABS);
#ifdef VEDA64_STRINGS
    std::cout << "  abs_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_adclb_z_zzz_() {
    uint32_t insn = 0x4500D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adclb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADCLB);
#ifdef VEDA64_STRINGS
    std::cout << "  adclb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_adclt_z_zzz_() {
    uint32_t insn = 0x4500D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adclt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADCLT);
#ifdef VEDA64_STRINGS
    std::cout << "  adclt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_add_z_p_zz_() {
    uint32_t insn = 0x04000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
#ifdef VEDA64_STRINGS
    std::cout << "  add_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_add_z_zi_() {
    uint32_t insn = 0x2520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
#ifdef VEDA64_STRINGS
    std::cout << "  add_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_add_z_zz_() {
    uint32_t insn = 0x04200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: add_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADD);
#ifdef VEDA64_STRINGS
    std::cout << "  add_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addhnb_z_zz_() {
    uint32_t insn = 0x45606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addhnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDHNB);
#ifdef VEDA64_STRINGS
    std::cout << "  addhnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addhnt_z_zz_() {
    uint32_t insn = 0x45606400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addhnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDHNT);
#ifdef VEDA64_STRINGS
    std::cout << "  addhnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addp_z_p_zz_() {
    uint32_t insn = 0x4411A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDP);
#ifdef VEDA64_STRINGS
    std::cout << "  addp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addpl_r_ri_() {
    uint32_t insn = 0x04605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addpl_r_ri_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDPL);
#ifdef VEDA64_STRINGS
    std::cout << "  addpl_r_ri_: " << result->to_string() << std::endl;
#endif
}

void test_addpt_z_p_zz_() {
    uint32_t insn = 0x04C40000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addpt_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDPT);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  addpt_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addpt_z_zz_() {
    uint32_t insn = 0x04E00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addpt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  addpt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addqp_z_zz_() {
    uint32_t insn = 0x04207800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addqp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDQP);
#ifdef VEDA64_STRINGS
    std::cout << "  addqp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addqv_z_p_z_() {
    uint32_t insn = 0x04052000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDQV);
#ifdef VEDA64_STRINGS
    std::cout << "  addqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_addspl_r_ri_() {
    uint32_t insn = 0x04605800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addspl_r_ri_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDSPL);
#ifdef VEDA64_STRINGS
    std::cout << "  addspl_r_ri_: " << result->to_string() << std::endl;
#endif
}

void test_addsubp_z_zz_() {
    uint32_t insn = 0x04207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addsubp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDSUBP);
#ifdef VEDA64_STRINGS
    std::cout << "  addsubp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_addsvl_r_ri_() {
    uint32_t insn = 0x04205800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addsvl_r_ri_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDSVL);
#ifdef VEDA64_STRINGS
    std::cout << "  addsvl_r_ri_: " << result->to_string() << std::endl;
#endif
}

void test_addvl_r_ri_() {
    uint32_t insn = 0x04205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: addvl_r_ri_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADDVL);
#ifdef VEDA64_STRINGS
    std::cout << "  addvl_r_ri_: " << result->to_string() << std::endl;
#endif
}

void test_adr_z_az_sd_same_scaled() {
    uint32_t insn = 0x04A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adr_z_az_sd_same_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADR);
#ifdef VEDA64_STRINGS
    std::cout << "  adr_z_az_sd_same_scaled: " << result->to_string() << std::endl;
#endif
}

void test_adr_z_az_d_s32_scaled() {
    uint32_t insn = 0x0420A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adr_z_az_d_s32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  adr_z_az_d_s32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_adr_z_az_d_u32_scaled() {
    uint32_t insn = 0x0460A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: adr_z_az_d_u32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ADR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  adr_z_az_d_u32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_aesd_mz_zzi_2x1() {
    uint32_t insn = 0x4522EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesd_mz_zzi_2x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesd_mz_zzi_2x1: " << result->to_string() << std::endl;
#endif
}

void test_aesd_mz_zzi_4x1() {
    uint32_t insn = 0x4526EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesd_mz_zzi_4x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesd_mz_zzi_4x1: " << result->to_string() << std::endl;
#endif
}

void test_aesd_z_zz_() {
    uint32_t insn = 0x4522E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_aesdimc_mz_zzi_2x1() {
    uint32_t insn = 0x4523EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesdimc_mz_zzi_2x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESDIMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesdimc_mz_zzi_2x1: " << result->to_string() << std::endl;
#endif
}

void test_aesdimc_mz_zzi_4x1() {
    uint32_t insn = 0x4527EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesdimc_mz_zzi_4x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESDIMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesdimc_mz_zzi_4x1: " << result->to_string() << std::endl;
#endif
}

void test_aese_mz_zzi_2x1() {
    uint32_t insn = 0x4522E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aese_mz_zzi_2x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aese_mz_zzi_2x1: " << result->to_string() << std::endl;
#endif
}

void test_aese_mz_zzi_4x1() {
    uint32_t insn = 0x4526E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aese_mz_zzi_4x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aese_mz_zzi_4x1: " << result->to_string() << std::endl;
#endif
}

void test_aese_z_zz_() {
    uint32_t insn = 0x4522E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aese_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aese_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_aesemc_mz_zzi_2x1() {
    uint32_t insn = 0x4523E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesemc_mz_zzi_2x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESEMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesemc_mz_zzi_2x1: " << result->to_string() << std::endl;
#endif
}

void test_aesemc_mz_zzi_4x1() {
    uint32_t insn = 0x4527E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesemc_mz_zzi_4x1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESEMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesemc_mz_zzi_4x1: " << result->to_string() << std::endl;
#endif
}

void test_aesimc_z_z_() {
    uint32_t insn = 0x4520E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesimc_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESIMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesimc_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_aesmc_z_z_() {
    uint32_t insn = 0x4520E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: aesmc_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::AESMC);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  aesmc_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_and_p_p_pp_z() {
    uint32_t insn = 0x25004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  and_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_and_z_p_zz_() {
    uint32_t insn = 0x041A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  and_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_and_z_zi_() {
    uint32_t insn = 0x05800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  and_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_and_z_zz_() {
    uint32_t insn = 0x04203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: and_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  and_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_andqv_z_p_z_() {
    uint32_t insn = 0x041E2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: andqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ANDQV);
#ifdef VEDA64_STRINGS
    std::cout << "  andqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_ands_p_p_pp_z() {
    uint32_t insn = 0x25404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ands_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  ands_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_andv_r_p_z_() {
    uint32_t insn = 0x041A2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: andv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ANDV);
#ifdef VEDA64_STRINGS
    std::cout << "  andv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_asr_z_p_zi_() {
    uint32_t insn = 0x04008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASR);
#ifdef VEDA64_STRINGS
    std::cout << "  asr_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_asr_z_p_zw_() {
    uint32_t insn = 0x04188000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_z_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASR);
#ifdef VEDA64_STRINGS
    std::cout << "  asr_z_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_asr_z_p_zz_() {
    uint32_t insn = 0x04108000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASR);
#ifdef VEDA64_STRINGS
    std::cout << "  asr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_asr_z_zi_() {
    uint32_t insn = 0x04209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASR);
#ifdef VEDA64_STRINGS
    std::cout << "  asr_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_asr_z_zw_() {
    uint32_t insn = 0x04208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asr_z_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASR);
#ifdef VEDA64_STRINGS
    std::cout << "  asr_z_zw_: " << result->to_string() << std::endl;
#endif
}

void test_asrd_z_p_zi_() {
    uint32_t insn = 0x04048000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asrd_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRD);
#ifdef VEDA64_STRINGS
    std::cout << "  asrd_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_asrr_z_p_zz_() {
    uint32_t insn = 0x04148000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: asrr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ASRR);
#ifdef VEDA64_STRINGS
    std::cout << "  asrr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bcax_z_zzz_() {
    uint32_t insn = 0x04603800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bcax_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BCAX);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bcax_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bdep_z_zz_() {
    uint32_t insn = 0x4500B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bdep_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BDEP);
#ifdef VEDA64_STRINGS
    std::cout << "  bdep_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bext_z_zz_() {
    uint32_t insn = 0x4500B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bext_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BEXT);
#ifdef VEDA64_STRINGS
    std::cout << "  bext_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bf1cvt_z_z8_b2bf() {
    uint32_t insn = 0x65083800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf1cvt_z_z8_b2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bf1cvt_z_z8_b2bf: " << result->to_string() << std::endl;
#endif
}

void test_bf2cvt_z_z8_b2bf() {
    uint32_t insn = 0x65083C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf2cvt_z_z8_b2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bf2cvt_z_z8_b2bf: " << result->to_string() << std::endl;
#endif
}

void test_bf1cvtlt_z_z8_b2bf() {
    uint32_t insn = 0x65093800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf1cvtlt_z_z8_b2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bf1cvtlt_z_z8_b2bf: " << result->to_string() << std::endl;
#endif
}

void test_bf2cvtlt_z_z8_b2bf() {
    uint32_t insn = 0x65093C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bf2cvtlt_z_z8_b2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bf2cvtlt_z_z8_b2bf: " << result->to_string() << std::endl;
#endif
}

void test_bfadd_z_p_zz_() {
    uint32_t insn = 0x65008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFADD);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfadd_z_zz_() {
    uint32_t insn = 0x65000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFADD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfclamp_z_zz_() {
    uint32_t insn = 0x64202400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfclamp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCLAMP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfclamp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfcvt_z_p_z_s2bf() {
    uint32_t insn = 0x658AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvt_z_p_z_s2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfcvt_z_p_z_s2bf: " << result->to_string() << std::endl;
#endif
}

void test_bfcvt_z_p_z_s2bfz() {
    uint32_t insn = 0x649AC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvt_z_p_z_s2bfz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfcvt_z_p_z_s2bfz: " << result->to_string() << std::endl;
#endif
}

void test_bfcvtn_z8_mz2_bf2b() {
    uint32_t insn = 0x650A3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvtn_z8_mz2_bf2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  bfcvtn_z8_mz2_bf2b: " << result->to_string() << std::endl;
#endif
}

void test_bfcvtnt_z_p_z_s2bf() {
    uint32_t insn = 0x648AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvtnt_z_p_z_s2bf" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfcvtnt_z_p_z_s2bf: " << result->to_string() << std::endl;
#endif
}

void test_bfcvtnt_z_p_z_s2bfz() {
    uint32_t insn = 0x6482A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfcvtnt_z_p_z_s2bfz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfcvtnt_z_p_z_s2bfz: " << result->to_string() << std::endl;
#endif
}

void test_bfdot_z_zzz_() {
    uint32_t insn = 0x64608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfdot_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfdot_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfdot_z_zzzi_() {
    uint32_t insn = 0x64604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfdot_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfdot_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_bfmax_z_p_zz_() {
    uint32_t insn = 0x65068000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmax_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMAX);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmax_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmaxnm_z_p_zz_() {
    uint32_t insn = 0x65048000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmaxnm_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMAXNM);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmaxnm_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmin_z_p_zz_() {
    uint32_t insn = 0x65078000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmin_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMIN);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmin_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfminnm_z_p_zz_() {
    uint32_t insn = 0x65058000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfminnm_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMINNM);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfminnm_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmla_z_p_zzz_() {
    uint32_t insn = 0x65200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmla_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmla_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmla_z_zzzi_h() {
    uint32_t insn = 0x64200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmla_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmla_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_bfmlalb_z_zzz_() {
    uint32_t insn = 0x64E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlalb_z_zzzi_() {
    uint32_t insn = 0x64E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlalb_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlalb_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlalt_z_zzz_() {
    uint32_t insn = 0x64E08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlalt_z_zzzi_() {
    uint32_t insn = 0x64E04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlalt_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlalt_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_bfmls_z_p_zzz_() {
    uint32_t insn = 0x65202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmls_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmls_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmls_z_zzzi_h() {
    uint32_t insn = 0x64200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmls_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmls_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_bfmlslb_z_zzz_() {
    uint32_t insn = 0x64E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlslb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlslb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlslb_z_zzzi_() {
    uint32_t insn = 0x64E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlslb_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlslb_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlslt_z_zzz_() {
    uint32_t insn = 0x64E0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlslt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlslt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmlslt_z_zzzi_() {
    uint32_t insn = 0x64E06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmlslt_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmlslt_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_bfmmla_z_zzz_h() {
    uint32_t insn = 0x64E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmmla_z_zzz_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmmla_z_zzz_h: " << result->to_string() << std::endl;
#endif
}

void test_bfmmla_z_zzz_() {
    uint32_t insn = 0x6460E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmmla_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmmla_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmul_z_p_zz_() {
    uint32_t insn = 0x65028000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmul_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmul_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmul_z_zz_() {
    uint32_t insn = 0x65000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmul_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmul_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfmul_z_zzi_h() {
    uint32_t insn = 0x64202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfmul_z_zzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfmul_z_zzi_h: " << result->to_string() << std::endl;
#endif
}

void test_bfscale_z_p_zz_() {
    uint32_t insn = 0x65098000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfscale_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFSCALE);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfscale_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfsub_z_p_zz_() {
    uint32_t insn = 0x65018000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFSUB);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bfsub_z_zz_() {
    uint32_t insn = 0x65000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bfsub_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BFSUB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bfsub_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bgrp_z_zz_() {
    uint32_t insn = 0x4500B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bgrp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BGRP);
#ifdef VEDA64_STRINGS
    std::cout << "  bgrp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bic_z_zi__and_z_zi_() {
    uint32_t insn = 0x05800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_z_zi__and_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  bic_z_zi__and_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_bic_p_p_pp_z() {
    uint32_t insn = 0x25004010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BIC);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bic_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_bic_z_p_zz_() {
    uint32_t insn = 0x041B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BIC);
#ifdef VEDA64_STRINGS
    std::cout << "  bic_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bic_z_zz_() {
    uint32_t insn = 0x04E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bic_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BIC);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bic_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_bics_p_p_pp_z() {
    uint32_t insn = 0x25404010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bics_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BICS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bics_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_brka_p_p_p_() {
    uint32_t insn = 0x25104000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brka_p_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brka_p_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_brkas_p_p_p_z() {
    uint32_t insn = 0x25504000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkas_p_p_p_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKAS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkas_p_p_p_z: " << result->to_string() << std::endl;
#endif
}

void test_brkb_p_p_p_() {
    uint32_t insn = 0x25904000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkb_p_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKB);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkb_p_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_brkbs_p_p_p_z() {
    uint32_t insn = 0x25D04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkbs_p_p_p_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKBS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkbs_p_p_p_z: " << result->to_string() << std::endl;
#endif
}

void test_brkn_p_p_pp_() {
    uint32_t insn = 0x25184000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkn_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKN);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkn_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_brkns_p_p_pp_() {
    uint32_t insn = 0x25584000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkns_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKNS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkns_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_brkpa_p_p_pp_() {
    uint32_t insn = 0x2500C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkpa_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkpa_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_brkpas_p_p_pp_() {
    uint32_t insn = 0x2540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkpas_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKPAS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkpas_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_brkpb_p_p_pp_() {
    uint32_t insn = 0x2500C010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkpb_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKPB);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkpb_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_brkpbs_p_p_pp_() {
    uint32_t insn = 0x2540C010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: brkpbs_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BRKPBS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  brkpbs_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_bsl1n_z_zzz_() {
    uint32_t insn = 0x04603C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bsl1n_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BSL1N);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bsl1n_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bsl2n_z_zzz_() {
    uint32_t insn = 0x04A03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bsl2n_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BSL2N);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bsl2n_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_bsl_z_zzz_() {
    uint32_t insn = 0x04203C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: bsl_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::BSL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  bsl_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_cadd_z_zz_() {
    uint32_t insn = 0x4500D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CADD);
#ifdef VEDA64_STRINGS
    std::cout << "  cadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cdot_z_zzz_() {
    uint32_t insn = 0x44801000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cdot_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CDOT);
#ifdef VEDA64_STRINGS
    std::cout << "  cdot_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_cdot_z_zzzi_s() {
    uint32_t insn = 0x44A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cdot_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CDOT);
#ifdef VEDA64_STRINGS
    std::cout << "  cdot_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_cdot_z_zzzi_d() {
    uint32_t insn = 0x44E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cdot_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CDOT);
#ifdef VEDA64_STRINGS
    std::cout << "  cdot_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_clasta_r_p_z_() {
    uint32_t insn = 0x0530A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clasta_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTA);
#ifdef VEDA64_STRINGS
    std::cout << "  clasta_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_clasta_v_p_z_() {
    uint32_t insn = 0x052A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clasta_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTA);
#ifdef VEDA64_STRINGS
    std::cout << "  clasta_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_clasta_z_p_zz_() {
    uint32_t insn = 0x05288000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clasta_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTA);
#ifdef VEDA64_STRINGS
    std::cout << "  clasta_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_clastb_r_p_z_() {
    uint32_t insn = 0x0531A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clastb_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTB);
#ifdef VEDA64_STRINGS
    std::cout << "  clastb_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_clastb_v_p_z_() {
    uint32_t insn = 0x052B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clastb_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTB);
#ifdef VEDA64_STRINGS
    std::cout << "  clastb_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_clastb_z_p_zz_() {
    uint32_t insn = 0x05298000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clastb_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLASTB);
#ifdef VEDA64_STRINGS
    std::cout << "  clastb_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cls_z_p_z_m() {
    uint32_t insn = 0x0418A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cls_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLS);
#ifdef VEDA64_STRINGS
    std::cout << "  cls_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_cls_z_p_z_z() {
    uint32_t insn = 0x0408A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cls_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLS);
#ifdef VEDA64_STRINGS
    std::cout << "  cls_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_clz_z_p_z_m() {
    uint32_t insn = 0x0419A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clz_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLZ);
#ifdef VEDA64_STRINGS
    std::cout << "  clz_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_clz_z_p_z_z() {
    uint32_t insn = 0x0409A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: clz_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CLZ);
#ifdef VEDA64_STRINGS
    std::cout << "  clz_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_cmla_z_zzz_() {
    uint32_t insn = 0x44002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmla_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  cmla_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_cmla_z_zzzi_h() {
    uint32_t insn = 0x44A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmla_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  cmla_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_cmla_z_zzzi_s() {
    uint32_t insn = 0x44E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmla_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  cmla_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_cmpeq_p_p_zi_() {
    uint32_t insn = 0x25008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpeq_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpeq_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmpgt_p_p_zi_() {
    uint32_t insn = 0x25000010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpgt_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpgt_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmpge_p_p_zi_() {
    uint32_t insn = 0x25000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpge_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpge_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmphi_p_p_zi_() {
    uint32_t insn = 0x24200010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphi_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphi_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmphs_p_p_zi_() {
    uint32_t insn = 0x24200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphs_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphs_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmplt_p_p_zi_() {
    uint32_t insn = 0x25002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplt_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmplt_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmple_p_p_zi_() {
    uint32_t insn = 0x25002010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmple_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmple_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmplo_p_p_zi_() {
    uint32_t insn = 0x24202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplo_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmplo_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmpls_p_p_zi_() {
    uint32_t insn = 0x24202010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpls_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpls_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmpne_p_p_zi_() {
    uint32_t insn = 0x25008010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpne_p_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpne_p_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_cmpeq_p_p_zw_() {
    uint32_t insn = 0x24002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpeq_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpeq_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmpgt_p_p_zw_() {
    uint32_t insn = 0x24004010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpgt_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpgt_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmpge_p_p_zw_() {
    uint32_t insn = 0x24004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpge_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpge_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmphi_p_p_zw_() {
    uint32_t insn = 0x2400C010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphi_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphi_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmphs_p_p_zw_() {
    uint32_t insn = 0x2400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphs_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphs_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmplt_p_p_zw_() {
    uint32_t insn = 0x24006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplt_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmplt_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmple_p_p_zw_() {
    uint32_t insn = 0x24006010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmple_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmple_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmplo_p_p_zw_() {
    uint32_t insn = 0x2400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplo_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmplo_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmpls_p_p_zw_() {
    uint32_t insn = 0x2400E010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpls_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpls_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmpne_p_p_zw_() {
    uint32_t insn = 0x24002010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpne_p_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpne_p_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_cmpeq_p_p_zz_() {
    uint32_t insn = 0x2400A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpeq_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpeq_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmpgt_p_p_zz_() {
    uint32_t insn = 0x24008010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmpge_p_p_zz_() {
    uint32_t insn = 0x24008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmphi_p_p_zz_() {
    uint32_t insn = 0x24000010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphi_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphi_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmphs_p_p_zz_() {
    uint32_t insn = 0x24000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmphs_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmphs_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmpne_p_p_zz_() {
    uint32_t insn = 0x2400A010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpne_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  cmpne_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmple_p_p_zz__cmpge_p_p_zz_() {
    uint32_t insn = 0x24008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmple_p_p_zz__cmpge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMPGE);
#ifdef VEDA64_STRINGS
    std::cout << "  cmple_p_p_zz__cmpge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmplo_p_p_zz__cmphi_p_p_zz_() {
    uint32_t insn = 0x24000010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplo_p_p_zz__cmphi_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMPHI);
#ifdef VEDA64_STRINGS
    std::cout << "  cmplo_p_p_zz__cmphi_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmpls_p_p_zz__cmphs_p_p_zz_() {
    uint32_t insn = 0x24000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmpls_p_p_zz__cmphs_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMPHS);
#ifdef VEDA64_STRINGS
    std::cout << "  cmpls_p_p_zz__cmphs_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cmplt_p_p_zz__cmpgt_p_p_zz_() {
    uint32_t insn = 0x24008010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cmplt_p_p_zz__cmpgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CMPGT);
#ifdef VEDA64_STRINGS
    std::cout << "  cmplt_p_p_zz__cmpgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_cnot_z_p_z_m() {
    uint32_t insn = 0x041BA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnot_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNOT);
#ifdef VEDA64_STRINGS
    std::cout << "  cnot_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_cnot_z_p_z_z() {
    uint32_t insn = 0x040BA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnot_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNOT);
#ifdef VEDA64_STRINGS
    std::cout << "  cnot_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_cnt_z_p_z_m() {
    uint32_t insn = 0x041AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnt_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNT);
#ifdef VEDA64_STRINGS
    std::cout << "  cnt_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_cnt_z_p_z_z() {
    uint32_t insn = 0x040AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnt_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNT);
#ifdef VEDA64_STRINGS
    std::cout << "  cnt_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_cntb_r_s_() {
    uint32_t insn = 0x0420E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cntb_r_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  cntb_r_s_: " << result->to_string() << std::endl;
#endif
}

void test_cntd_r_s_() {
    uint32_t insn = 0x04E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cntd_r_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  cntd_r_s_: " << result->to_string() << std::endl;
#endif
}

void test_cnth_r_s_() {
    uint32_t insn = 0x0460E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cnth_r_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  cnth_r_s_: " << result->to_string() << std::endl;
#endif
}

void test_cntw_r_s_() {
    uint32_t insn = 0x04A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cntw_r_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  cntw_r_s_: " << result->to_string() << std::endl;
#endif
}

void test_cntp_r_p_p_() {
    uint32_t insn = 0x25208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cntp_r_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNTP);
#ifdef VEDA64_STRINGS
    std::cout << "  cntp_r_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_cntp_r_pn_() {
    uint32_t insn = 0x25208200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cntp_r_pn_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CNTP);
#ifdef VEDA64_STRINGS
    std::cout << "  cntp_r_pn_: " << result->to_string() << std::endl;
#endif
}

void test_compact_z_p_z_s() {
    uint32_t insn = 0x05218000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: compact_z_p_z_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::COMPACT);
#ifdef VEDA64_STRINGS
    std::cout << "  compact_z_p_z_s: " << result->to_string() << std::endl;
#endif
}

void test_compact_z_p_z_() {
    uint32_t insn = 0x05A18000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: compact_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::COMPACT);
#ifdef VEDA64_STRINGS
    std::cout << "  compact_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_cpy_z_o_i_() {
    uint32_t insn = 0x05100000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpy_z_o_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  cpy_z_o_i_: " << result->to_string() << std::endl;
#endif
}

void test_cpy_z_p_i_() {
    uint32_t insn = 0x05104000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpy_z_p_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  cpy_z_p_i_: " << result->to_string() << std::endl;
#endif
}

void test_cpy_z_p_r_() {
    uint32_t insn = 0x0528A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpy_z_p_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  cpy_z_p_r_: " << result->to_string() << std::endl;
#endif
}

void test_cpy_z_p_v_() {
    uint32_t insn = 0x05208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpy_z_p_v_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  cpy_z_p_v_: " << result->to_string() << std::endl;
#endif
}

void test_ctermeq_rr_() {
    uint32_t insn = 0x25A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ctermeq_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ctermeq_rr_: " << result->to_string() << std::endl;
#endif
}

void test_ctermne_rr_() {
    uint32_t insn = 0x25A02010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ctermne_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ctermne_rr_: " << result->to_string() << std::endl;
#endif
}

void test_decb_r_rs_() {
    uint32_t insn = 0x0430E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decb_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  decb_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_decd_r_rs_() {
    uint32_t insn = 0x04F0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decd_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  decd_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_dech_r_rs_() {
    uint32_t insn = 0x0470E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dech_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  dech_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_decw_r_rs_() {
    uint32_t insn = 0x04B0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decw_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  decw_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_decd_z_zs_() {
    uint32_t insn = 0x04F0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  decd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_dech_z_zs_() {
    uint32_t insn = 0x0470C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dech_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  dech_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_decw_z_zs_() {
    uint32_t insn = 0x04B0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  decw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_decp_r_p_r_() {
    uint32_t insn = 0x252D8800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decp_r_p_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DECP);
#ifdef VEDA64_STRINGS
    std::cout << "  decp_r_p_r_: " << result->to_string() << std::endl;
#endif
}

void test_decp_z_p_z_() {
    uint32_t insn = 0x256D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: decp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DECP);
#ifdef VEDA64_STRINGS
    std::cout << "  decp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_dup_z_i_() {
    uint32_t insn = 0x2538C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  dup_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_dup_z_r_() {
    uint32_t insn = 0x05203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_z_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  dup_z_r_: " << result->to_string() << std::endl;
#endif
}

void test_dup_z_zi_() {
    uint32_t insn = 0x05212000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dup_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  dup_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_dupm_z_i_() {
    uint32_t insn = 0x05C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dupm_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUPM);
#ifdef VEDA64_STRINGS
    std::cout << "  dupm_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_dupq_z_zi_() {
    uint32_t insn = 0x05212400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: dupq_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUPQ);
#ifdef VEDA64_STRINGS
    std::cout << "  dupq_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_eon_z_zi__eor_z_zi_() {
    uint32_t insn = 0x05400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eon_z_zi__eor_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
#ifdef VEDA64_STRINGS
    std::cout << "  eon_z_zi__eor_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_eor3_z_zzz_() {
    uint32_t insn = 0x04203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor3_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR3);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  eor3_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_eor_p_p_pp_z() {
    uint32_t insn = 0x25004200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  eor_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_eor_z_p_zz_() {
    uint32_t insn = 0x04190000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
#ifdef VEDA64_STRINGS
    std::cout << "  eor_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_eor_z_zi_() {
    uint32_t insn = 0x05400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
#ifdef VEDA64_STRINGS
    std::cout << "  eor_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_eor_z_zz_() {
    uint32_t insn = 0x04A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eor_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  eor_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_eorbt_z_zz_() {
    uint32_t insn = 0x45009000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eorbt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORBT);
#ifdef VEDA64_STRINGS
    std::cout << "  eorbt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_eorqv_z_p_z_() {
    uint32_t insn = 0x041D2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eorqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORQV);
#ifdef VEDA64_STRINGS
    std::cout << "  eorqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_eors_p_p_pp_z() {
    uint32_t insn = 0x25404200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eors_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  eors_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_eortb_z_zz_() {
    uint32_t insn = 0x45009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eortb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORTB);
#ifdef VEDA64_STRINGS
    std::cout << "  eortb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_eorv_r_p_z_() {
    uint32_t insn = 0x04192000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: eorv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORV);
#ifdef VEDA64_STRINGS
    std::cout << "  eorv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_expand_z_p_z_() {
    uint32_t insn = 0x05318000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: expand_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EXPAND);
#ifdef VEDA64_STRINGS
    std::cout << "  expand_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_ext_z_zi_con() {
    uint32_t insn = 0x05600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ext_z_zi_con" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EXT);
#ifdef VEDA64_STRINGS
    std::cout << "  ext_z_zi_con: " << result->to_string() << std::endl;
#endif
}

void test_ext_z_zi_des() {
    uint32_t insn = 0x05200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ext_z_zi_des" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EXT);
#ifdef VEDA64_STRINGS
    std::cout << "  ext_z_zi_des: " << result->to_string() << std::endl;
#endif
}

void test_extq_z_zi_des() {
    uint32_t insn = 0x05602400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: extq_z_zi_des" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EXTQ);
#ifdef VEDA64_STRINGS
    std::cout << "  extq_z_zi_des: " << result->to_string() << std::endl;
#endif
}

void test_f1cvt_z_z8_b2h() {
    uint32_t insn = 0x65083000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f1cvt_z_z8_b2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  f1cvt_z_z8_b2h: " << result->to_string() << std::endl;
#endif
}

void test_f2cvt_z_z8_b2h() {
    uint32_t insn = 0x65083400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f2cvt_z_z8_b2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  f2cvt_z_z8_b2h: " << result->to_string() << std::endl;
#endif
}

void test_f1cvtlt_z_z8_b2h() {
    uint32_t insn = 0x65093000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f1cvtlt_z_z8_b2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  f1cvtlt_z_z8_b2h: " << result->to_string() << std::endl;
#endif
}

void test_f2cvtlt_z_z8_b2h() {
    uint32_t insn = 0x65093400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: f2cvtlt_z_z8_b2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  f2cvtlt_z_z8_b2h: " << result->to_string() << std::endl;
#endif
}

void test_fabd_z_p_zz_() {
    uint32_t insn = 0x65488000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FABD);
#ifdef VEDA64_STRINGS
    std::cout << "  fabd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fabs_z_p_z_m() {
    uint32_t insn = 0x045CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FABS);
#ifdef VEDA64_STRINGS
    std::cout << "  fabs_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_fabs_z_p_z_z() {
    uint32_t insn = 0x044CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fabs_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FABS);
#ifdef VEDA64_STRINGS
    std::cout << "  fabs_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_facgt_p_p_zz_() {
    uint32_t insn = 0x6540E010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  facgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_facge_p_p_zz_() {
    uint32_t insn = 0x6540C010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  facge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_facle_p_p_zz__facge_p_p_zz_() {
    uint32_t insn = 0x6540C010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: facle_p_p_zz__facge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FACGE);
#ifdef VEDA64_STRINGS
    std::cout << "  facle_p_p_zz__facge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_faclt_p_p_zz__facgt_p_p_zz_() {
    uint32_t insn = 0x6540E010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faclt_p_p_zz__facgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FACGT);
#ifdef VEDA64_STRINGS
    std::cout << "  faclt_p_p_zz__facgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fadd_z_p_zs_() {
    uint32_t insn = 0x65588000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADD);
#ifdef VEDA64_STRINGS
    std::cout << "  fadd_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fadd_z_p_zz_() {
    uint32_t insn = 0x65408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADD);
#ifdef VEDA64_STRINGS
    std::cout << "  fadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fadd_z_zz_() {
    uint32_t insn = 0x65400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADD);
#ifdef VEDA64_STRINGS
    std::cout << "  fadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fadda_v_p_z_() {
    uint32_t insn = 0x65582000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fadda_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADDA);
#ifdef VEDA64_STRINGS
    std::cout << "  fadda_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_faddp_z_p_zz_() {
    uint32_t insn = 0x64508000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADDP);
#ifdef VEDA64_STRINGS
    std::cout << "  faddp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_faddqv_z_p_z_() {
    uint32_t insn = 0x6450A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADDQV);
#ifdef VEDA64_STRINGS
    std::cout << "  faddqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_faddv_v_p_z_() {
    uint32_t insn = 0x65402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: faddv_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FADDV);
#ifdef VEDA64_STRINGS
    std::cout << "  faddv_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_famax_z_p_zz_() {
    uint32_t insn = 0x654E8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famax_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FAMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  famax_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_famin_z_p_zz_() {
    uint32_t insn = 0x654F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: famin_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FAMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  famin_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcadd_z_p_zz_() {
    uint32_t insn = 0x64408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCADD);
#ifdef VEDA64_STRINGS
    std::cout << "  fcadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fclamp_z_zz_() {
    uint32_t insn = 0x64602400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fclamp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCLAMP);
#ifdef VEDA64_STRINGS
    std::cout << "  fclamp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmeq_p_p_z0_() {
    uint32_t insn = 0x65522000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmeq_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmgt_p_p_z0_() {
    uint32_t insn = 0x65502010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmgt_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmge_p_p_z0_() {
    uint32_t insn = 0x65502000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmge_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmlt_p_p_z0_() {
    uint32_t insn = 0x65512000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmlt_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmle_p_p_z0_() {
    uint32_t insn = 0x65512010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmle_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmne_p_p_z0_() {
    uint32_t insn = 0x65532000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmne_p_p_z0_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmne_p_p_z0_: " << result->to_string() << std::endl;
#endif
}

void test_fcmeq_p_p_zz_() {
    uint32_t insn = 0x65406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmeq_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmeq_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmgt_p_p_zz_() {
    uint32_t insn = 0x65404010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmge_p_p_zz_() {
    uint32_t insn = 0x65404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmne_p_p_zz_() {
    uint32_t insn = 0x65406010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmne_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmne_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmuo_p_p_zz_() {
    uint32_t insn = 0x6540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmuo_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  fcmuo_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmla_z_p_zzz_() {
    uint32_t insn = 0x64400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmla_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  fcmla_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmla_z_zzzi_h() {
    uint32_t insn = 0x64A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmla_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  fcmla_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_fcmla_z_zzzi_s() {
    uint32_t insn = 0x64E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmla_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  fcmla_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fcmle_p_p_zz__fcmge_p_p_zz_() {
    uint32_t insn = 0x65404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmle_p_p_zz__fcmge_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCMGE);
#ifdef VEDA64_STRINGS
    std::cout << "  fcmle_p_p_zz__fcmge_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcmlt_p_p_zz__fcmgt_p_p_zz_() {
    uint32_t insn = 0x65404010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcmlt_p_p_zz__fcmgt_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCMGT);
#ifdef VEDA64_STRINGS
    std::cout << "  fcmlt_p_p_zz__fcmgt_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fcpy_z_p_i_() {
    uint32_t insn = 0x0550C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcpy_z_p_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCPY);
#ifdef VEDA64_STRINGS
    std::cout << "  fcpy_z_p_i_: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_h2s() {
    uint32_t insn = 0x6589A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_h2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_h2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_h2sz() {
    uint32_t insn = 0x649AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_h2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_h2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_h2d() {
    uint32_t insn = 0x65C9A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_h2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_h2d: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_h2dz() {
    uint32_t insn = 0x64DAA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_h2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_h2dz: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_s2h() {
    uint32_t insn = 0x6588A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_s2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_s2h: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_s2hz() {
    uint32_t insn = 0x649A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_s2hz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_s2hz: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_s2d() {
    uint32_t insn = 0x65CBA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_s2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_s2d: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_s2dz() {
    uint32_t insn = 0x64DAE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_s2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_s2dz: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_d2h() {
    uint32_t insn = 0x65C8A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_d2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_d2h: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_d2hz() {
    uint32_t insn = 0x64DA8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_d2hz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_d2hz: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_d2s() {
    uint32_t insn = 0x65CAA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_d2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_d2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvt_z_p_z_d2sz() {
    uint32_t insn = 0x64DAC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvt_z_p_z_d2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvt_z_p_z_d2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtlt_z_p_z_h2s() {
    uint32_t insn = 0x6489A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtlt_z_p_z_h2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtlt_z_p_z_h2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvtlt_z_p_z_h2sz() {
    uint32_t insn = 0x6481A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtlt_z_p_z_h2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtlt_z_p_z_h2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtlt_z_p_z_s2d() {
    uint32_t insn = 0x64CBA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtlt_z_p_z_s2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtlt_z_p_z_s2d: " << result->to_string() << std::endl;
#endif
}

void test_fcvtlt_z_p_z_s2dz() {
    uint32_t insn = 0x64C3A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtlt_z_p_z_s2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtlt_z_p_z_s2dz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtn_z8_mz2_h2b() {
    uint32_t insn = 0x650A3000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtn_z8_mz2_h2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtn_z8_mz2_h2b: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnb_z8_mz2_s2b() {
    uint32_t insn = 0x650A3400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnb_z8_mz2_s2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnb_z8_mz2_s2b: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnt_z8_mz2_s2b() {
    uint32_t insn = 0x650A3C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnt_z8_mz2_s2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnt_z8_mz2_s2b: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnt_z_p_z_s2h() {
    uint32_t insn = 0x6488A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnt_z_p_z_s2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnt_z_p_z_s2h: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnt_z_p_z_s2hz() {
    uint32_t insn = 0x6480A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnt_z_p_z_s2hz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnt_z_p_z_s2hz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnt_z_p_z_d2s() {
    uint32_t insn = 0x64CAA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnt_z_p_z_d2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnt_z_p_z_d2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvtnt_z_p_z_d2sz() {
    uint32_t insn = 0x64C2A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtnt_z_p_z_d2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtnt_z_p_z_d2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtx_z_p_z_d2s() {
    uint32_t insn = 0x650AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtx_z_p_z_d2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtx_z_p_z_d2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvtx_z_p_z_d2sz() {
    uint32_t insn = 0x641AC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtx_z_p_z_d2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTX);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtx_z_p_z_d2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtxnt_z_p_z_d2s() {
    uint32_t insn = 0x640AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtxnt_z_p_z_d2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTXNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtxnt_z_p_z_d2s: " << result->to_string() << std::endl;
#endif
}

void test_fcvtxnt_z_p_z_d2sz() {
    uint32_t insn = 0x6402A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtxnt_z_p_z_d2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTXNT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtxnt_z_p_z_d2sz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162h() {
    uint32_t insn = 0x655AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162h: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162hz() {
    uint32_t insn = 0x645EC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162hz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162hz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162w() {
    uint32_t insn = 0x655CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162wz() {
    uint32_t insn = 0x645F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162x() {
    uint32_t insn = 0x655EA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_fp162xz() {
    uint32_t insn = 0x645FC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_fp162xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_fp162xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_s2w() {
    uint32_t insn = 0x659CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_s2w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_s2w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_s2wz() {
    uint32_t insn = 0x649F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_s2wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_s2wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_s2x() {
    uint32_t insn = 0x65DCA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_s2x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_s2x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_s2xz() {
    uint32_t insn = 0x64DF8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_s2xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_s2xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_d2w() {
    uint32_t insn = 0x65D8A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_d2w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_d2w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_d2wz() {
    uint32_t insn = 0x64DE8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_d2wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_d2wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_d2x() {
    uint32_t insn = 0x65DEA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_d2x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_d2x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzs_z_p_z_d2xz() {
    uint32_t insn = 0x64DFC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzs_z_p_z_d2xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzs_z_p_z_d2xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzsn_z_mz2_() {
    uint32_t insn = 0x654D3000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzsn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZSN);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzsn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162h() {
    uint32_t insn = 0x655BA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162h: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162hz() {
    uint32_t insn = 0x645EE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162hz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162hz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162w() {
    uint32_t insn = 0x655DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162wz() {
    uint32_t insn = 0x645FA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162x() {
    uint32_t insn = 0x655FA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_fp162xz() {
    uint32_t insn = 0x645FE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_fp162xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_fp162xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_s2w() {
    uint32_t insn = 0x659DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_s2w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_s2w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_s2wz() {
    uint32_t insn = 0x649FA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_s2wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_s2wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_s2x() {
    uint32_t insn = 0x65DDA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_s2x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_s2x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_s2xz() {
    uint32_t insn = 0x64DFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_s2xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_s2xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_d2w() {
    uint32_t insn = 0x65D9A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_d2w" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_d2w: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_d2wz() {
    uint32_t insn = 0x64DEA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_d2wz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_d2wz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_d2x() {
    uint32_t insn = 0x65DFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_d2x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_d2x: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzu_z_p_z_d2xz() {
    uint32_t insn = 0x64DFE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzu_z_p_z_d2xz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzu_z_p_z_d2xz: " << result->to_string() << std::endl;
#endif
}

void test_fcvtzun_z_mz2_() {
    uint32_t insn = 0x654D3400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fcvtzun_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCVTZUN);
#ifdef VEDA64_STRINGS
    std::cout << "  fcvtzun_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_fdiv_z_p_zz_() {
    uint32_t insn = 0x654D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdiv_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDIV);
#ifdef VEDA64_STRINGS
    std::cout << "  fdiv_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fdivr_z_p_zz_() {
    uint32_t insn = 0x654C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdivr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDIVR);
#ifdef VEDA64_STRINGS
    std::cout << "  fdivr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z32_zz8z8_() {
    uint32_t insn = 0x64608400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z32_zz8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z32_zz8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z32_zz8z8i_() {
    uint32_t insn = 0x64604400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z32_zz8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z32_zz8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z_zz8z8_() {
    uint32_t insn = 0x64208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z_zz8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z_zz8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z_zz8z8i_() {
    uint32_t insn = 0x64204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z_zz8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z_zz8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z_zzz_() {
    uint32_t insn = 0x64208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fdot_z_zzzi_() {
    uint32_t insn = 0x64204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdot_z_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fdot_z_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_fdup_z_i_() {
    uint32_t insn = 0x2579C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fdup_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDUP);
#ifdef VEDA64_STRINGS
    std::cout << "  fdup_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_fexpa_z_z_() {
    uint32_t insn = 0x0460B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fexpa_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FEXPA);
#ifdef VEDA64_STRINGS
    std::cout << "  fexpa_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_firstp_r_p_p_() {
    uint32_t insn = 0x25218000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: firstp_r_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FIRSTP);
#ifdef VEDA64_STRINGS
    std::cout << "  firstp_r_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_flogb_z_p_z_m() {
    uint32_t insn = 0x651AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: flogb_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FLOGB);
#ifdef VEDA64_STRINGS
    std::cout << "  flogb_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_flogb_z_p_z_z() {
    uint32_t insn = 0x641EA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: flogb_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FLOGB);
#ifdef VEDA64_STRINGS
    std::cout << "  flogb_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_fmad_z_p_zzz_() {
    uint32_t insn = 0x65608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmad_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAD);
#ifdef VEDA64_STRINGS
    std::cout << "  fmad_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmax_z_p_zs_() {
    uint32_t insn = 0x655E8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  fmax_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fmax_z_p_zz_() {
    uint32_t insn = 0x65468000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmax_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  fmax_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxnm_z_p_zs_() {
    uint32_t insn = 0x655C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXNM);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxnm_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxnm_z_p_zz_() {
    uint32_t insn = 0x65448000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnm_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXNM);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxnm_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxnmp_z_p_zz_() {
    uint32_t insn = 0x64548000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXNMP);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxnmp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxnmqv_z_p_z_() {
    uint32_t insn = 0x6454A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXNMQV);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxnmqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxnmv_v_p_z_() {
    uint32_t insn = 0x65442000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxnmv_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXNMV);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxnmv_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxp_z_p_zz_() {
    uint32_t insn = 0x64568000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXP);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxqv_z_p_z_() {
    uint32_t insn = 0x6456A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXQV);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fmaxv_v_p_z_() {
    uint32_t insn = 0x65462000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmaxv_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMAXV);
#ifdef VEDA64_STRINGS
    std::cout << "  fmaxv_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fmin_z_p_zs_() {
    uint32_t insn = 0x655F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  fmin_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fmin_z_p_zz_() {
    uint32_t insn = 0x65478000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmin_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  fmin_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fminnm_z_p_zs_() {
    uint32_t insn = 0x655D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINNM);
#ifdef VEDA64_STRINGS
    std::cout << "  fminnm_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fminnm_z_p_zz_() {
    uint32_t insn = 0x65458000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnm_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINNM);
#ifdef VEDA64_STRINGS
    std::cout << "  fminnm_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fminnmp_z_p_zz_() {
    uint32_t insn = 0x64558000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINNMP);
#ifdef VEDA64_STRINGS
    std::cout << "  fminnmp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fminnmqv_z_p_z_() {
    uint32_t insn = 0x6455A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINNMQV);
#ifdef VEDA64_STRINGS
    std::cout << "  fminnmqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fminnmv_v_p_z_() {
    uint32_t insn = 0x65452000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminnmv_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINNMV);
#ifdef VEDA64_STRINGS
    std::cout << "  fminnmv_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fminp_z_p_zz_() {
    uint32_t insn = 0x64578000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINP);
#ifdef VEDA64_STRINGS
    std::cout << "  fminp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fminqv_z_p_z_() {
    uint32_t insn = 0x6457A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINQV);
#ifdef VEDA64_STRINGS
    std::cout << "  fminqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fminv_v_p_z_() {
    uint32_t insn = 0x65472000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fminv_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMINV);
#ifdef VEDA64_STRINGS
    std::cout << "  fminv_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_fmla_z_p_zzz_() {
    uint32_t insn = 0x65600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  fmla_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmla_z_zzzi_h() {
    uint32_t insn = 0x64200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmla_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_fmla_z_zzzi_s() {
    uint32_t insn = 0x64A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmla_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmla_z_zzzi_d() {
    uint32_t insn = 0x64E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmla_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmla_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_fmlalb_z_z8z8z8_() {
    uint32_t insn = 0x64A08800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_z_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalb_z_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalb_z_z8z8z8i_() {
    uint32_t insn = 0x64205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_z_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalb_z_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalb_z_zzz_() {
    uint32_t insn = 0x64A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalb_z_zzzi_s() {
    uint32_t insn = 0x64A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmlallbb_z32_z8z8z8_() {
    uint32_t insn = 0x64208800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbb_z32_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLBB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlallbb_z32_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlallbb_z32_z8z8z8i_() {
    uint32_t insn = 0x6420C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbb_z32_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLBB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlallbb_z32_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlallbt_z32_z8z8z8_() {
    uint32_t insn = 0x64209800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbt_z32_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLBT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlallbt_z32_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlallbt_z32_z8z8z8i_() {
    uint32_t insn = 0x6460C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlallbt_z32_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLBT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlallbt_z32_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalltb_z32_z8z8z8_() {
    uint32_t insn = 0x6420A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltb_z32_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLTB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalltb_z32_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalltb_z32_z8z8z8i_() {
    uint32_t insn = 0x64A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltb_z32_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLTB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalltb_z32_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalltt_z32_z8z8z8_() {
    uint32_t insn = 0x6420B800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltt_z32_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLTT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalltt_z32_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalltt_z32_z8z8z8i_() {
    uint32_t insn = 0x64E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalltt_z32_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALLTT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalltt_z32_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalt_z_z8z8z8_() {
    uint32_t insn = 0x64A09800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_z_z8z8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalt_z_z8z8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalt_z_z8z8z8i_() {
    uint32_t insn = 0x64A05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_z_z8z8z8i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalt_z_z8z8z8i_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalt_z_zzz_() {
    uint32_t insn = 0x64A08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmlalt_z_zzzi_s() {
    uint32_t insn = 0x64A04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlalt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlalt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmls_z_p_zzz_() {
    uint32_t insn = 0x65602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLS);
#ifdef VEDA64_STRINGS
    std::cout << "  fmls_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmls_z_zzzi_h() {
    uint32_t insn = 0x64200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmls_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_fmls_z_zzzi_s() {
    uint32_t insn = 0x64A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmls_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmls_z_zzzi_d() {
    uint32_t insn = 0x64E00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmls_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmls_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_fmlslb_z_zzz_() {
    uint32_t insn = 0x64A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlslb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlslb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmlslb_z_zzzi_s() {
    uint32_t insn = 0x64A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlslb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlslb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmlslt_z_zzz_() {
    uint32_t insn = 0x64A0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlslt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlslt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmlslt_z_zzzi_s() {
    uint32_t insn = 0x64A06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmlslt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmlslt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z16_zz8z8_() {
    uint32_t insn = 0x6460E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z16_zz8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z16_zz8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z32_zz8z8_() {
    uint32_t insn = 0x6420E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z32_zz8z8_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z32_zz8z8_: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z32_zzz_h() {
    uint32_t insn = 0x6420E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z32_zzz_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z32_zzz_h: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z_zzz_h() {
    uint32_t insn = 0x64A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z_zzz_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z_zzz_h: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z_zzz_s() {
    uint32_t insn = 0x64A0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z_zzz_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z_zzz_s: " << result->to_string() << std::endl;
#endif
}

void test_fmmla_z_zzz_d() {
    uint32_t insn = 0x64E0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmmla_z_zzz_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmmla_z_zzz_d: " << result->to_string() << std::endl;
#endif
}

void test_fmov_z_p_0__cpy_z_p_i_() {
    uint32_t insn = 0x05504000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_z_p_0__cpy_z_p_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  fmov_z_p_0__cpy_z_p_i_: " << result->to_string() << std::endl;
#endif
}

void test_fmov_z_0__dup_z_i_() {
    uint32_t insn = 0x2578C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_z_0__dup_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  fmov_z_0__dup_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_fmov_z_p_i__fcpy_z_p_i_() {
    uint32_t insn = 0x0550C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_z_p_i__fcpy_z_p_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FCPY);
#ifdef VEDA64_STRINGS
    std::cout << "  fmov_z_p_i__fcpy_z_p_i_: " << result->to_string() << std::endl;
#endif
}

void test_fmov_z_i__fdup_z_i_() {
    uint32_t insn = 0x2579C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmov_z_i__fdup_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FDUP);
#ifdef VEDA64_STRINGS
    std::cout << "  fmov_z_i__fdup_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_fmsb_z_p_zzz_() {
    uint32_t insn = 0x6560A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmsb_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMSB);
#ifdef VEDA64_STRINGS
    std::cout << "  fmsb_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_p_zs_() {
    uint32_t insn = 0x655A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_p_zz_() {
    uint32_t insn = 0x65428000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_zz_() {
    uint32_t insn = 0x65400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_zzi_h() {
    uint32_t insn = 0x64202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_zzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_zzi_h: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_zzi_s() {
    uint32_t insn = 0x64A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_fmul_z_zzi_d() {
    uint32_t insn = 0x64E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmul_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  fmul_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_fmulx_z_p_zz_() {
    uint32_t insn = 0x654A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fmulx_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FMULX);
#ifdef VEDA64_STRINGS
    std::cout << "  fmulx_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fneg_z_p_z_m() {
    uint32_t insn = 0x045DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNEG);
#ifdef VEDA64_STRINGS
    std::cout << "  fneg_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_fneg_z_p_z_z() {
    uint32_t insn = 0x044DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fneg_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNEG);
#ifdef VEDA64_STRINGS
    std::cout << "  fneg_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_fnmad_z_p_zzz_() {
    uint32_t insn = 0x6560C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmad_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNMAD);
#ifdef VEDA64_STRINGS
    std::cout << "  fnmad_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fnmla_z_p_zzz_() {
    uint32_t insn = 0x65604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmla_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNMLA);
#ifdef VEDA64_STRINGS
    std::cout << "  fnmla_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fnmls_z_p_zzz_() {
    uint32_t insn = 0x65606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmls_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNMLS);
#ifdef VEDA64_STRINGS
    std::cout << "  fnmls_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_fnmsb_z_p_zzz_() {
    uint32_t insn = 0x6560E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fnmsb_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FNMSB);
#ifdef VEDA64_STRINGS
    std::cout << "  fnmsb_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_frecpe_z_z_() {
    uint32_t insn = 0x654E3000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpe_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRECPE);
#ifdef VEDA64_STRINGS
    std::cout << "  frecpe_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_frecps_z_zz_() {
    uint32_t insn = 0x65401800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecps_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRECPS);
#ifdef VEDA64_STRINGS
    std::cout << "  frecps_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_frecpx_z_p_z_m() {
    uint32_t insn = 0x654CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpx_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRECPX);
#ifdef VEDA64_STRINGS
    std::cout << "  frecpx_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frecpx_z_p_z_z() {
    uint32_t insn = 0x645B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frecpx_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRECPX);
#ifdef VEDA64_STRINGS
    std::cout << "  frecpx_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frint32x_z_p_z_m() {
    uint32_t insn = 0x6511A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32x_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT32X);
#ifdef VEDA64_STRINGS
    std::cout << "  frint32x_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frint32x_z_p_z_z() {
    uint32_t insn = 0x641CA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32x_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT32X);
#ifdef VEDA64_STRINGS
    std::cout << "  frint32x_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frint32z_z_p_z_m() {
    uint32_t insn = 0x6510A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32z_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT32Z);
#ifdef VEDA64_STRINGS
    std::cout << "  frint32z_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frint32z_z_p_z_z() {
    uint32_t insn = 0x641C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint32z_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT32Z);
#ifdef VEDA64_STRINGS
    std::cout << "  frint32z_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frint64x_z_p_z_m() {
    uint32_t insn = 0x6515A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64x_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT64X);
#ifdef VEDA64_STRINGS
    std::cout << "  frint64x_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frint64x_z_p_z_z() {
    uint32_t insn = 0x641DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64x_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT64X);
#ifdef VEDA64_STRINGS
    std::cout << "  frint64x_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frint64z_z_p_z_m() {
    uint32_t insn = 0x6514A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64z_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT64Z);
#ifdef VEDA64_STRINGS
    std::cout << "  frint64z_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frint64z_z_p_z_z() {
    uint32_t insn = 0x641D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frint64z_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRINT64Z);
#ifdef VEDA64_STRINGS
    std::cout << "  frint64z_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frintx_z_p_z_m() {
    uint32_t insn = 0x6546A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintx_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frintx_z_p_z_z() {
    uint32_t insn = 0x6459C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintx_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintx_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frinti_z_p_z_m() {
    uint32_t insn = 0x6547A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frinti_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frinti_z_p_z_z() {
    uint32_t insn = 0x6459E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinti_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frinti_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frinta_z_p_z_m() {
    uint32_t insn = 0x6544A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frinta_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frinta_z_p_z_z() {
    uint32_t insn = 0x64598000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frinta_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frinta_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frintn_z_p_z_m() {
    uint32_t insn = 0x6540A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintn_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frintn_z_p_z_z() {
    uint32_t insn = 0x64588000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintn_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintn_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frintz_z_p_z_m() {
    uint32_t insn = 0x6543A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintz_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frintz_z_p_z_z() {
    uint32_t insn = 0x6458E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintz_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintz_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frintm_z_p_z_m() {
    uint32_t insn = 0x6542A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintm_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frintm_z_p_z_z() {
    uint32_t insn = 0x6458C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintm_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintm_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frintp_z_p_z_m() {
    uint32_t insn = 0x6541A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintp_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_frintp_z_p_z_z() {
    uint32_t insn = 0x6458A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frintp_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  frintp_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_frsqrte_z_z_() {
    uint32_t insn = 0x654F3000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrte_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRSQRTE);
#ifdef VEDA64_STRINGS
    std::cout << "  frsqrte_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_frsqrts_z_zz_() {
    uint32_t insn = 0x65401C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: frsqrts_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FRSQRTS);
#ifdef VEDA64_STRINGS
    std::cout << "  frsqrts_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fscale_z_p_zz_() {
    uint32_t insn = 0x65498000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fscale_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSCALE);
#ifdef VEDA64_STRINGS
    std::cout << "  fscale_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fsqrt_z_p_z_m() {
    uint32_t insn = 0x654DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSQRT);
#ifdef VEDA64_STRINGS
    std::cout << "  fsqrt_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_fsqrt_z_p_z_z() {
    uint32_t insn = 0x645BA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsqrt_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSQRT);
#ifdef VEDA64_STRINGS
    std::cout << "  fsqrt_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_fsub_z_p_zs_() {
    uint32_t insn = 0x65598000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  fsub_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fsub_z_p_zz_() {
    uint32_t insn = 0x65418000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  fsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fsub_z_zz_() {
    uint32_t insn = 0x65400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsub_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  fsub_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_fsubr_z_p_zs_() {
    uint32_t insn = 0x655B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsubr_z_p_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  fsubr_z_p_zs_: " << result->to_string() << std::endl;
#endif
}

void test_fsubr_z_p_zz_() {
    uint32_t insn = 0x65438000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: fsubr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  fsubr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ftmad_z_zzi_() {
    uint32_t insn = 0x65508000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ftmad_z_zzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FTMAD);
#ifdef VEDA64_STRINGS
    std::cout << "  ftmad_z_zzi_: " << result->to_string() << std::endl;
#endif
}

void test_ftsmul_z_zz_() {
    uint32_t insn = 0x65400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ftsmul_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FTSMUL);
#ifdef VEDA64_STRINGS
    std::cout << "  ftsmul_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ftssel_z_zz_() {
    uint32_t insn = 0x0460B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ftssel_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::FTSSEL);
#ifdef VEDA64_STRINGS
    std::cout << "  ftssel_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_histcnt_z_p_zz_() {
    uint32_t insn = 0x45A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: histcnt_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::HISTCNT);
#ifdef VEDA64_STRINGS
    std::cout << "  histcnt_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_histseg_z_zz_() {
    uint32_t insn = 0x4520A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: histseg_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::HISTSEG);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  histseg_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_incb_r_rs_() {
    uint32_t insn = 0x0430E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incb_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  incb_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_incd_r_rs_() {
    uint32_t insn = 0x04F0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incd_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  incd_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_inch_r_rs_() {
    uint32_t insn = 0x0470E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: inch_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  inch_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_incw_r_rs_() {
    uint32_t insn = 0x04B0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incw_r_rs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  incw_r_rs_: " << result->to_string() << std::endl;
#endif
}

void test_incd_z_zs_() {
    uint32_t insn = 0x04F0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  incd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_inch_z_zs_() {
    uint32_t insn = 0x0470C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: inch_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  inch_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_incw_z_zs_() {
    uint32_t insn = 0x04B0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  incw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_incp_r_p_r_() {
    uint32_t insn = 0x252C8800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incp_r_p_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INCP);
#ifdef VEDA64_STRINGS
    std::cout << "  incp_r_p_r_: " << result->to_string() << std::endl;
#endif
}

void test_incp_z_p_z_() {
    uint32_t insn = 0x256C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: incp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INCP);
#ifdef VEDA64_STRINGS
    std::cout << "  incp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_index_z_ii_() {
    uint32_t insn = 0x04204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: index_z_ii_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INDEX);
#ifdef VEDA64_STRINGS
    std::cout << "  index_z_ii_: " << result->to_string() << std::endl;
#endif
}

void test_index_z_ir_() {
    uint32_t insn = 0x04204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: index_z_ir_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INDEX);
#ifdef VEDA64_STRINGS
    std::cout << "  index_z_ir_: " << result->to_string() << std::endl;
#endif
}

void test_index_z_ri_() {
    uint32_t insn = 0x04204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: index_z_ri_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INDEX);
#ifdef VEDA64_STRINGS
    std::cout << "  index_z_ri_: " << result->to_string() << std::endl;
#endif
}

void test_index_z_rr_() {
    uint32_t insn = 0x04204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: index_z_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INDEX);
#ifdef VEDA64_STRINGS
    std::cout << "  index_z_rr_: " << result->to_string() << std::endl;
#endif
}

void test_insr_z_r_() {
    uint32_t insn = 0x05243800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: insr_z_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INSR);
#ifdef VEDA64_STRINGS
    std::cout << "  insr_z_r_: " << result->to_string() << std::endl;
#endif
}

void test_insr_z_v_() {
    uint32_t insn = 0x05343800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: insr_z_v_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::INSR);
#ifdef VEDA64_STRINGS
    std::cout << "  insr_z_v_: " << result->to_string() << std::endl;
#endif
}

void test_lasta_r_p_z_() {
    uint32_t insn = 0x0520A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lasta_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LASTA);
#ifdef VEDA64_STRINGS
    std::cout << "  lasta_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_lasta_v_p_z_() {
    uint32_t insn = 0x05228000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lasta_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LASTA);
#ifdef VEDA64_STRINGS
    std::cout << "  lasta_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_lastb_r_p_z_() {
    uint32_t insn = 0x0521A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lastb_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LASTB);
#ifdef VEDA64_STRINGS
    std::cout << "  lastb_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_lastb_v_p_z_() {
    uint32_t insn = 0x05238000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lastb_v_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LASTB);
#ifdef VEDA64_STRINGS
    std::cout << "  lastb_v_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_lastp_r_p_p_() {
    uint32_t insn = 0x25228000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lastp_r_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LASTP);
#ifdef VEDA64_STRINGS
    std::cout << "  lastp_r_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_ai_s() {
    uint32_t insn = 0x8420C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_ai_d() {
    uint32_t insn = 0xC420C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bi_u8() {
    uint32_t insn = 0xA400A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bi_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bi_u8: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bi_u16() {
    uint32_t insn = 0xA420A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bi_u32() {
    uint32_t insn = 0xA440A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bi_u64() {
    uint32_t insn = 0xA460A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_br_u8() {
    uint32_t insn = 0xA4004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_br_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_br_u8: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_br_u16() {
    uint32_t insn = 0xA4204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_br_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_br_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_br_u32() {
    uint32_t insn = 0xA4404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_br_u64() {
    uint32_t insn = 0xA4604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1b_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC440C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1b_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1b_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_ai_d() {
    uint32_t insn = 0xC5A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bi_u64() {
    uint32_t insn = 0xA5E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bi_u128() {
    uint32_t insn = 0xA5902000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bi_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bi_u128: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_br_u64() {
    uint32_t insn = 0xA5E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_br_u128() {
    uint32_t insn = 0xA5808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_br_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_br_u128: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC5E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1d_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC5C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1d_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1d_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_ai_s() {
    uint32_t insn = 0x84A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_ai_d() {
    uint32_t insn = 0xC4A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bi_u16() {
    uint32_t insn = 0xA4A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bi_u32() {
    uint32_t insn = 0xA4C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bi_u64() {
    uint32_t insn = 0xA4E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_br_u16() {
    uint32_t insn = 0xA4A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_br_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_br_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_br_u32() {
    uint32_t insn = 0xA4C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_br_u64() {
    uint32_t insn = 0xA4E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC4E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1h_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC4C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1h_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1h_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1q_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC400A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1q_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1q_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1rb_z_p_bi_u8() {
    uint32_t insn = 0x84408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rb_z_p_bi_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rb_z_p_bi_u8: " << result->to_string() << std::endl;
#endif
}

void test_ld1rb_z_p_bi_u16() {
    uint32_t insn = 0x8440A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rb_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rb_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1rb_z_p_bi_u32() {
    uint32_t insn = 0x8440C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rb_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rb_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rb_z_p_bi_u64() {
    uint32_t insn = 0x8440E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rb_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rb_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rd_z_p_bi_u64() {
    uint32_t insn = 0x85C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rd_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rd_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rh_z_p_bi_u16() {
    uint32_t insn = 0x84C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rh_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rh_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1rh_z_p_bi_u32() {
    uint32_t insn = 0x84C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rh_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rh_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rh_z_p_bi_u64() {
    uint32_t insn = 0x84C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rh_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rh_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rob_z_p_bi_u8() {
    uint32_t insn = 0xA4202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rob_z_p_bi_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rob_z_p_bi_u8: " << result->to_string() << std::endl;
#endif
}

void test_ld1rob_z_p_br_contiguous() {
    uint32_t insn = 0xA4200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rob_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rob_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rod_z_p_bi_u64() {
    uint32_t insn = 0xA5A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rod_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rod_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rod_z_p_br_contiguous() {
    uint32_t insn = 0xA5A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rod_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rod_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1roh_z_p_bi_u16() {
    uint32_t insn = 0xA4A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1roh_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1roh_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1roh_z_p_br_contiguous() {
    uint32_t insn = 0xA4A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1roh_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1roh_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1row_z_p_bi_u32() {
    uint32_t insn = 0xA5202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1row_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1row_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1row_z_p_br_contiguous() {
    uint32_t insn = 0xA5200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1row_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1ROW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1row_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqb_z_p_bi_u8() {
    uint32_t insn = 0xA4002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqb_z_p_bi_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqb_z_p_bi_u8: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqb_z_p_br_contiguous() {
    uint32_t insn = 0xA4000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqb_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqb_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqd_z_p_bi_u64() {
    uint32_t insn = 0xA5802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqd_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqd_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqd_z_p_br_contiguous() {
    uint32_t insn = 0xA5800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqd_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqd_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqh_z_p_bi_u16() {
    uint32_t insn = 0xA4802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqh_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqh_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqh_z_p_br_contiguous() {
    uint32_t insn = 0xA4800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqh_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqh_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqw_z_p_bi_u32() {
    uint32_t insn = 0xA5002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqw_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqw_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rqw_z_p_br_contiguous() {
    uint32_t insn = 0xA5000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rqw_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RQW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rqw_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsb_z_p_bi_s16() {
    uint32_t insn = 0x85C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsb_z_p_bi_s16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsb_z_p_bi_s16: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsb_z_p_bi_s32() {
    uint32_t insn = 0x85C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsb_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsb_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsb_z_p_bi_s64() {
    uint32_t insn = 0x85C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsb_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsb_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsh_z_p_bi_s32() {
    uint32_t insn = 0x8540A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsh_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsh_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsh_z_p_bi_s64() {
    uint32_t insn = 0x85408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsh_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsh_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rsw_z_p_bi_s64() {
    uint32_t insn = 0x84C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rsw_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RSW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rsw_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1rw_z_p_bi_u32() {
    uint32_t insn = 0x8540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rw_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rw_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1rw_z_p_bi_u64() {
    uint32_t insn = 0x8540E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1rw_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1RW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1rw_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_ai_s() {
    uint32_t insn = 0x84208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_ai_d() {
    uint32_t insn = 0xC4208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bi_s16() {
    uint32_t insn = 0xA5C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bi_s16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bi_s16: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bi_s32() {
    uint32_t insn = 0xA5A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bi_s64() {
    uint32_t insn = 0xA580A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_br_s16() {
    uint32_t insn = 0xA5C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_br_s16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_br_s16: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_br_s32() {
    uint32_t insn = 0xA5A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_br_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_br_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_br_s64() {
    uint32_t insn = 0xA5804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sb_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC4408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sb_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sb_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_ai_s() {
    uint32_t insn = 0x84A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_ai_d() {
    uint32_t insn = 0xC4A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bi_s32() {
    uint32_t insn = 0xA520A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bi_s64() {
    uint32_t insn = 0xA500A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_br_s32() {
    uint32_t insn = 0xA5204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_br_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_br_s32: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_br_s64() {
    uint32_t insn = 0xA5004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC4E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sh_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC4C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sh_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sh_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_ai_d() {
    uint32_t insn = 0xC5208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_bi_s64() {
    uint32_t insn = 0xA480A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_br_s64() {
    uint32_t insn = 0xA4804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC5608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1sw_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC5408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1sw_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1sw_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_ai_s() {
    uint32_t insn = 0x8520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_ai_d() {
    uint32_t insn = 0xC520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bi_u32() {
    uint32_t insn = 0xA540A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bi_u64() {
    uint32_t insn = 0xA560A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bi_u128() {
    uint32_t insn = 0xA5102000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bi_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bi_u128: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_br_u32() {
    uint32_t insn = 0xA5404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_br_u64() {
    uint32_t insn = 0xA5604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_br_u128() {
    uint32_t insn = 0xA5008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_br_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_br_u128: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x85204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x85004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC560C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ld1w_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1w_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld1w_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ld2b_z_p_bi_contiguous() {
    uint32_t insn = 0xA420E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2b_z_p_br_contiguous() {
    uint32_t insn = 0xA420C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2d_z_p_bi_contiguous() {
    uint32_t insn = 0xA5A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2d_z_p_br_contiguous() {
    uint32_t insn = 0xA5A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2h_z_p_bi_contiguous() {
    uint32_t insn = 0xA4A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2h_z_p_br_contiguous() {
    uint32_t insn = 0xA4A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2q_z_p_bi_contiguous() {
    uint32_t insn = 0xA490E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2q_z_p_br_contiguous() {
    uint32_t insn = 0xA4A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2w_z_p_bi_contiguous() {
    uint32_t insn = 0xA520E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld2w_z_p_br_contiguous() {
    uint32_t insn = 0xA520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld2w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3b_z_p_bi_contiguous() {
    uint32_t insn = 0xA440E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3b_z_p_br_contiguous() {
    uint32_t insn = 0xA440C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3d_z_p_bi_contiguous() {
    uint32_t insn = 0xA5C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3d_z_p_br_contiguous() {
    uint32_t insn = 0xA5C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3h_z_p_bi_contiguous() {
    uint32_t insn = 0xA4C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3h_z_p_br_contiguous() {
    uint32_t insn = 0xA4C0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3q_z_p_bi_contiguous() {
    uint32_t insn = 0xA510E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3q_z_p_br_contiguous() {
    uint32_t insn = 0xA5208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3w_z_p_bi_contiguous() {
    uint32_t insn = 0xA540E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld3w_z_p_br_contiguous() {
    uint32_t insn = 0xA540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld3w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4b_z_p_bi_contiguous() {
    uint32_t insn = 0xA460E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4b_z_p_br_contiguous() {
    uint32_t insn = 0xA460C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4d_z_p_bi_contiguous() {
    uint32_t insn = 0xA5E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4d_z_p_br_contiguous() {
    uint32_t insn = 0xA5E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4h_z_p_bi_contiguous() {
    uint32_t insn = 0xA4E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4h_z_p_br_contiguous() {
    uint32_t insn = 0xA4E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4q_z_p_bi_contiguous() {
    uint32_t insn = 0xA590E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4q_z_p_br_contiguous() {
    uint32_t insn = 0xA5A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4w_z_p_bi_contiguous() {
    uint32_t insn = 0xA560E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ld4w_z_p_br_contiguous() {
    uint32_t insn = 0xA560C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ld4w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_ai_s() {
    uint32_t insn = 0x8420E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_ai_d() {
    uint32_t insn = 0xC420E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_br_u8() {
    uint32_t insn = 0xA4006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_br_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_br_u8: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_br_u16() {
    uint32_t insn = 0xA4206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_br_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_br_u16: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_br_u32() {
    uint32_t insn = 0xA4406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_br_u64() {
    uint32_t insn = 0xA4606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1b_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC440E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1b_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1b_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_ai_d() {
    uint32_t insn = 0xC5A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_br_u64() {
    uint32_t insn = 0xA5E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC5E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1d_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC5C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1d_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1d_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_ai_s() {
    uint32_t insn = 0x84A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_ai_d() {
    uint32_t insn = 0xC4A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_br_u16() {
    uint32_t insn = 0xA4A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_br_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_br_u16: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_br_u32() {
    uint32_t insn = 0xA4C06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_br_u64() {
    uint32_t insn = 0xA4E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC4E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1h_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC4C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1h_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1h_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_ai_s() {
    uint32_t insn = 0x8420A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_ai_d() {
    uint32_t insn = 0xC420A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_br_s16() {
    uint32_t insn = 0xA5C06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_br_s16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_br_s16: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_br_s32() {
    uint32_t insn = 0xA5A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_br_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_br_s32: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_br_s64() {
    uint32_t insn = 0xA5806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sb_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC440A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sb_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sb_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_ai_s() {
    uint32_t insn = 0x84A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_ai_d() {
    uint32_t insn = 0xC4A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_br_s32() {
    uint32_t insn = 0xA5206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_br_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_br_s32: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_br_s64() {
    uint32_t insn = 0xA5006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC4802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x84802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC4E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sh_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC4C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sh_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sh_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_ai_d() {
    uint32_t insn = 0xC520A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_br_s64() {
    uint32_t insn = 0xA4806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_br_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_br_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC560A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1sw_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC540A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1sw_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1sw_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_ai_s() {
    uint32_t insn = 0x8520E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_ai_d() {
    uint32_t insn = 0xC520E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_br_u32() {
    uint32_t insn = 0xA5406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_br_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_br_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_br_u64() {
    uint32_t insn = 0xA5606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_br_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_br_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0x85206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC5206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xC5006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0x85006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xC560E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_ldff1w_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xC540E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldff1w_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDFF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldff1w_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1b_z_p_bi_u8() {
    uint32_t insn = 0xA410A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1b_z_p_bi_u8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1b_z_p_bi_u8: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1b_z_p_bi_u16() {
    uint32_t insn = 0xA430A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1b_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1b_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1b_z_p_bi_u32() {
    uint32_t insn = 0xA450A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1b_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1b_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1b_z_p_bi_u64() {
    uint32_t insn = 0xA470A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1b_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1b_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1d_z_p_bi_u64() {
    uint32_t insn = 0xA5F0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1d_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1d_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1h_z_p_bi_u16() {
    uint32_t insn = 0xA4B0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1h_z_p_bi_u16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1h_z_p_bi_u16: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1h_z_p_bi_u32() {
    uint32_t insn = 0xA4D0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1h_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1h_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1h_z_p_bi_u64() {
    uint32_t insn = 0xA4F0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1h_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1h_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sb_z_p_bi_s16() {
    uint32_t insn = 0xA5D0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sb_z_p_bi_s16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sb_z_p_bi_s16: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sb_z_p_bi_s32() {
    uint32_t insn = 0xA5B0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sb_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sb_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sb_z_p_bi_s64() {
    uint32_t insn = 0xA590A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sb_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sb_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sh_z_p_bi_s32() {
    uint32_t insn = 0xA530A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sh_z_p_bi_s32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sh_z_p_bi_s32: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sh_z_p_bi_s64() {
    uint32_t insn = 0xA510A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sh_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sh_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1sw_z_p_bi_s64() {
    uint32_t insn = 0xA490A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1sw_z_p_bi_s64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1sw_z_p_bi_s64: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1w_z_p_bi_u32() {
    uint32_t insn = 0xA550A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1w_z_p_bi_u32" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1w_z_p_bi_u32: " << result->to_string() << std::endl;
#endif
}

void test_ldnf1w_z_p_bi_u64() {
    uint32_t insn = 0xA570A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnf1w_z_p_bi_u64" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNF1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnf1w_z_p_bi_u64: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1b_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0x8400A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1b_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1b_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1b_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1b_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1b_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1b_z_p_bi_contiguous() {
    uint32_t insn = 0xA400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1b_z_p_br_contiguous() {
    uint32_t insn = 0xA400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1d_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC580C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1d_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1d_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1d_z_p_bi_contiguous() {
    uint32_t insn = 0xA580E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1d_z_p_br_contiguous() {
    uint32_t insn = 0xA580C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1h_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0x8480A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1h_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1h_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1h_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC480C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1h_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1h_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1h_z_p_bi_contiguous() {
    uint32_t insn = 0xA480E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1h_z_p_br_contiguous() {
    uint32_t insn = 0xA480C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1sb_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0x84008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1sb_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1sb_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1sb_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC4008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1sb_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1SB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1sb_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1sh_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0x84808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1sh_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1sh_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1sh_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC4808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1sh_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1SH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1sh_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1sw_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC5008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1sw_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1SW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1sw_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1w_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0x8500A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1w_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1w_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1w_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xC500C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1w_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1w_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1w_z_p_bi_contiguous() {
    uint32_t insn = 0xA500E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldnt1w_z_p_br_contiguous() {
    uint32_t insn = 0xA500C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnt1w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  ldnt1w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_ldr_p_bi_() {
    uint32_t insn = 0x85800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldr_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_ldr_z_bi_() {
    uint32_t insn = 0x85804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_z_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  ldr_z_bi_: " << result->to_string() << std::endl;
#endif
}

void test_lsl_z_p_zi_() {
    uint32_t insn = 0x04038000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSL);
#ifdef VEDA64_STRINGS
    std::cout << "  lsl_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_lsl_z_p_zw_() {
    uint32_t insn = 0x041B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_z_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSL);
#ifdef VEDA64_STRINGS
    std::cout << "  lsl_z_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_lsl_z_p_zz_() {
    uint32_t insn = 0x04138000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSL);
#ifdef VEDA64_STRINGS
    std::cout << "  lsl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_lsl_z_zi_() {
    uint32_t insn = 0x04209C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSL);
#ifdef VEDA64_STRINGS
    std::cout << "  lsl_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_lsl_z_zw_() {
    uint32_t insn = 0x04208C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsl_z_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSL);
#ifdef VEDA64_STRINGS
    std::cout << "  lsl_z_zw_: " << result->to_string() << std::endl;
#endif
}

void test_lslr_z_p_zz_() {
    uint32_t insn = 0x04178000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lslr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSLR);
#ifdef VEDA64_STRINGS
    std::cout << "  lslr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_lsr_z_p_zi_() {
    uint32_t insn = 0x04018000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsr_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_lsr_z_p_zw_() {
    uint32_t insn = 0x04198000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_z_p_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsr_z_p_zw_: " << result->to_string() << std::endl;
#endif
}

void test_lsr_z_p_zz_() {
    uint32_t insn = 0x04118000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_lsr_z_zi_() {
    uint32_t insn = 0x04209400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsr_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_lsr_z_zw_() {
    uint32_t insn = 0x04208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsr_z_zw_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsr_z_zw_: " << result->to_string() << std::endl;
#endif
}

void test_lsrr_z_p_zz_() {
    uint32_t insn = 0x04158000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lsrr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LSRR);
#ifdef VEDA64_STRINGS
    std::cout << "  lsrr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_luti2_z_zz_8() {
    uint32_t insn = 0x4520B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti2_z_zz_8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti2_z_zz_8: " << result->to_string() << std::endl;
#endif
}

void test_luti2_z_zz_16() {
    uint32_t insn = 0x4520A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti2_z_zz_16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti2_z_zz_16: " << result->to_string() << std::endl;
#endif
}

void test_luti4_z_zz_8() {
    uint32_t insn = 0x4560A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti4_z_zz_8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti4_z_zz_8: " << result->to_string() << std::endl;
#endif
}

void test_luti4_z_zz_2x16() {
    uint32_t insn = 0x4520B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti4_z_zz_2x16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti4_z_zz_2x16: " << result->to_string() << std::endl;
#endif
}

void test_luti4_z_zz_1x16() {
    uint32_t insn = 0x4520BC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti4_z_zz_1x16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti4_z_zz_1x16: " << result->to_string() << std::endl;
#endif
}

void test_luti6_z_zzz_16() {
    uint32_t insn = 0x4560AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti6_z_zzz_16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti6_z_zzz_16: " << result->to_string() << std::endl;
#endif
}

void test_luti6_z_zzz_8() {
    uint32_t insn = 0x4520AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: luti6_z_zzz_8" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  luti6_z_zzz_8: " << result->to_string() << std::endl;
#endif
}

void test_mad_z_p_zzz_() {
    uint32_t insn = 0x0400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mad_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MAD);
#ifdef VEDA64_STRINGS
    std::cout << "  mad_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_madpt_z_zzz_() {
    uint32_t insn = 0x44C0D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: madpt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MADPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  madpt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_match_p_p_zz_() {
    uint32_t insn = 0x45208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: match_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MATCH);
#ifdef VEDA64_STRINGS
    std::cout << "  match_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_mla_z_p_zzz_() {
    uint32_t insn = 0x04004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLA);
#ifdef VEDA64_STRINGS
    std::cout << "  mla_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_mla_z_zzzi_h() {
    uint32_t insn = 0x44200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mla_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_mla_z_zzzi_s() {
    uint32_t insn = 0x44A00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mla_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_mla_z_zzzi_d() {
    uint32_t insn = 0x44E00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mla_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mla_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_mlapt_z_zzz_() {
    uint32_t insn = 0x44C0D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mlapt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLAPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mlapt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_mls_z_p_zzz_() {
    uint32_t insn = 0x04006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLS);
#ifdef VEDA64_STRINGS
    std::cout << "  mls_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_mls_z_zzzi_h() {
    uint32_t insn = 0x44200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mls_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_mls_z_zzzi_s() {
    uint32_t insn = 0x44A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mls_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_mls_z_zzzi_d() {
    uint32_t insn = 0x44E00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mls_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MLS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mls_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_movz_p_p_p__and_p_p_pp_z() {
    uint32_t insn = 0x25004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movz_p_p_p__and_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  movz_p_p_p__and_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_o_i__cpy_z_o_i_() {
    uint32_t insn = 0x05100000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_o_i__cpy_z_o_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_o_i__cpy_z_o_i_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_p_i__cpy_z_p_i_() {
    uint32_t insn = 0x05104000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_p_i__cpy_z_p_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_p_i__cpy_z_p_i_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_p_r__cpy_z_p_r_() {
    uint32_t insn = 0x0528A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_p_r__cpy_z_p_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_p_r__cpy_z_p_r_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_p_v__cpy_z_p_v_() {
    uint32_t insn = 0x05208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_p_v__cpy_z_p_v_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::CPY);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_p_v__cpy_z_p_v_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_i__dup_z_i_() {
    uint32_t insn = 0x2538C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_i__dup_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_i__dup_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_r__dup_z_r_() {
    uint32_t insn = 0x05203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_r__dup_z_r_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_r__dup_z_r_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_v__dup_z_zi_() {
    uint32_t insn = 0x05212000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_v__dup_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_v__dup_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_zi__dup_z_zi_() {
    uint32_t insn = 0x05212000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_zi__dup_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUP);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_zi__dup_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_m__dupm_z_i_() {
    uint32_t insn = 0x05C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_m__dupm_z_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::DUPM);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_m__dupm_z_i_: " << result->to_string() << std::endl;
#endif
}

void test_mov_p_p__orr_p_p_pp_z() {
    uint32_t insn = 0x25804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_p_p__orr_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  mov_p_p__orr_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_z__orr_z_zz_() {
    uint32_t insn = 0x04603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_z__orr_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_z__orr_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_movm_p_p_p__sel_p_p_pp_() {
    uint32_t insn = 0x25004210u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movm_p_p_p__sel_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SEL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  movm_p_p_p__sel_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_mov_z_p_z__sel_z_p_zz_() {
    uint32_t insn = 0x0520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mov_z_p_z__sel_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SEL);
#ifdef VEDA64_STRINGS
    std::cout << "  mov_z_p_z__sel_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_movprfx_z_p_z_() {
    uint32_t insn = 0x04102000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movprfx_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MOVPRFX);
#ifdef VEDA64_STRINGS
    std::cout << "  movprfx_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_movprfx_z_z_() {
    uint32_t insn = 0x0420BC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movprfx_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MOVPRFX);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  movprfx_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_movzs_p_p_p__ands_p_p_pp_z() {
    uint32_t insn = 0x25404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movzs_p_p_p__ands_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  movzs_p_p_p__ands_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_movs_p_p__orrs_p_p_pp_z() {
    uint32_t insn = 0x25C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: movs_p_p__orrs_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ORRS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  movs_p_p__orrs_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_msb_z_p_zzz_() {
    uint32_t insn = 0x0400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: msb_z_p_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MSB);
#ifdef VEDA64_STRINGS
    std::cout << "  msb_z_p_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_p_zz_() {
    uint32_t insn = 0x04100000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_zi_() {
    uint32_t insn = 0x2530C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_zz_() {
    uint32_t insn = 0x04206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_zzi_h() {
    uint32_t insn = 0x4420F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_zzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_zzi_h: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_zzi_s() {
    uint32_t insn = 0x44A0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_mul_z_zzi_d() {
    uint32_t insn = 0x44E0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: mul_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::MUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  mul_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_nand_p_p_pp_z() {
    uint32_t insn = 0x25804210u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nand_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NAND);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nand_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_nands_p_p_pp_z() {
    uint32_t insn = 0x25C04210u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nands_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NANDS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nands_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_nbsl_z_zzz_() {
    uint32_t insn = 0x04E03C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nbsl_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NBSL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nbsl_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_neg_z_p_z_m() {
    uint32_t insn = 0x0417A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NEG);
#ifdef VEDA64_STRINGS
    std::cout << "  neg_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_neg_z_p_z_z() {
    uint32_t insn = 0x0407A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: neg_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NEG);
#ifdef VEDA64_STRINGS
    std::cout << "  neg_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_nmatch_p_p_zz_() {
    uint32_t insn = 0x45208010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nmatch_p_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NMATCH);
#ifdef VEDA64_STRINGS
    std::cout << "  nmatch_p_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_nor_p_p_pp_z() {
    uint32_t insn = 0x25804200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nor_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NOR);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nor_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_nors_p_p_pp_z() {
    uint32_t insn = 0x25C04200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nors_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NORS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nors_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_not_p_p_p_z_eor_p_p_pp_z() {
    uint32_t insn = 0x25004200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: not_p_p_p_z_eor_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EOR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  not_p_p_p_z_eor_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_not_z_p_z_m() {
    uint32_t insn = 0x041EA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: not_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NOT);
#ifdef VEDA64_STRINGS
    std::cout << "  not_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_not_z_p_z_z() {
    uint32_t insn = 0x040EA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: not_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::NOT);
#ifdef VEDA64_STRINGS
    std::cout << "  not_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_nots_p_p_p_z_eors_p_p_pp_z() {
    uint32_t insn = 0x25404200u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: nots_p_p_p_z_eors_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::EORS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  nots_p_p_p_z_eors_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_orn_z_zi__orr_z_zi_() {
    uint32_t insn = 0x05000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orn_z_zi__orr_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orn_z_zi__orr_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_orn_p_p_pp_z() {
    uint32_t insn = 0x25804010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orn_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orn_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_orns_p_p_pp_z() {
    uint32_t insn = 0x25C04010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orns_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ORNS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  orns_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_orqv_z_p_z_() {
    uint32_t insn = 0x041C2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ORQV);
#ifdef VEDA64_STRINGS
    std::cout << "  orqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_orr_p_p_pp_z() {
    uint32_t insn = 0x25804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orr_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_orr_z_p_zz_() {
    uint32_t insn = 0x04180000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_orr_z_zi_() {
    uint32_t insn = 0x05000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orr_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_orr_z_zz_() {
    uint32_t insn = 0x04603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orr_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  orr_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_orrs_p_p_pp_z() {
    uint32_t insn = 0x25C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orrs_p_p_pp_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ORRS);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  orrs_p_p_pp_z: " << result->to_string() << std::endl;
#endif
}

void test_orv_r_p_z_() {
    uint32_t insn = 0x04182000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: orv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ORV);
#ifdef VEDA64_STRINGS
    std::cout << "  orv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_pext_pn_rr_() {
    uint32_t insn = 0x25207010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pext_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PEXT);
#ifdef VEDA64_STRINGS
    std::cout << "  pext_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_pext_pp_rr_() {
    uint32_t insn = 0x25207410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pext_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PEXT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pext_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_pfalse_p_() {
    uint32_t insn = 0x2518E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pfalse_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PFALSE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pfalse_p_: " << result->to_string() << std::endl;
#endif
}

void test_pfirst_p_p_p_() {
    uint32_t insn = 0x2558C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pfirst_p_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PFIRST);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pfirst_p_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_pmlal_mz_zzzw_1x2() {
    uint32_t insn = 0x4520FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmlal_mz_zzzw_1x2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMLAL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmlal_mz_zzzw_1x2: " << result->to_string() << std::endl;
#endif
}

void test_pmov_p_zi_b() {
    uint32_t insn = 0x052A3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_p_zi_b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_p_zi_b: " << result->to_string() << std::endl;
#endif
}

void test_pmov_p_zi_d() {
    uint32_t insn = 0x05A83800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_p_zi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::IndexedRegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_p_zi_d: " << result->to_string() << std::endl;
#endif
}

void test_pmov_p_zi_h() {
    uint32_t insn = 0x052C3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_p_zi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::IndexedRegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_p_zi_h: " << result->to_string() << std::endl;
#endif
}

void test_pmov_p_zi_s() {
    uint32_t insn = 0x05683800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_p_zi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::IndexedRegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_p_zi_s: " << result->to_string() << std::endl;
#endif
}

void test_pmov_z_pi_b() {
    uint32_t insn = 0x052B3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_z_pi_b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_z_pi_b: " << result->to_string() << std::endl;
#endif
}

void test_pmov_z_pi_d() {
    uint32_t insn = 0x05A93800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_z_pi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_z_pi_d: " << result->to_string() << std::endl;
#endif
}

void test_pmov_z_pi_h() {
    uint32_t insn = 0x052D3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_z_pi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_z_pi_h: " << result->to_string() << std::endl;
#endif
}

void test_pmov_z_pi_s() {
    uint32_t insn = 0x05693800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmov_z_pi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMOV);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmov_z_pi_s: " << result->to_string() << std::endl;
#endif
}

void test_pmul_z_zz_() {
    uint32_t insn = 0x04206400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmul_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMUL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmul_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_pmull_mz_zzw_1x2() {
    uint32_t insn = 0x4520F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmull_mz_zzw_1x2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMULL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmull_mz_zzw_1x2: " << result->to_string() << std::endl;
#endif
}

void test_pmullb_z_zz_() {
    uint32_t insn = 0x45406800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmullb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMULLB);
#ifdef VEDA64_STRINGS
    std::cout << "  pmullb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_pmullb_z_zz_q() {
    uint32_t insn = 0x45006800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmullb_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmullb_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_pmullt_z_zz_() {
    uint32_t insn = 0x45406C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmullt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMULLT);
#ifdef VEDA64_STRINGS
    std::cout << "  pmullt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_pmullt_z_zz_q() {
    uint32_t insn = 0x45006C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pmullt_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  pmullt_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_pnext_p_p_p_() {
    uint32_t insn = 0x2519C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: pnext_p_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PNEXT);
#ifdef VEDA64_STRINGS
    std::cout << "  pnext_p_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_ai_s() {
    uint32_t insn = 0x8400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_ai_d() {
    uint32_t insn = 0xC400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_bi_s() {
    uint32_t insn = 0x85C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_bi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_bi_s: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_br_s() {
    uint32_t insn = 0x8400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_br_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_br_s: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfb_i_p_bz_d_64_scaled() {
    uint32_t insn = 0xC4608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfb_i_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfb_i_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_ai_s() {
    uint32_t insn = 0x8580E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_ai_d() {
    uint32_t insn = 0xC580E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_bi_s() {
    uint32_t insn = 0x85C06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_bi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_bi_s: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_br_s() {
    uint32_t insn = 0x8580C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_br_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_br_s: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfd_i_p_bz_d_64_scaled() {
    uint32_t insn = 0xC460E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfd_i_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfd_i_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_ai_s() {
    uint32_t insn = 0x8480E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_ai_d() {
    uint32_t insn = 0xC480E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_bi_s() {
    uint32_t insn = 0x85C02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_bi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_bi_s: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_br_s() {
    uint32_t insn = 0x8480C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_br_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_br_s: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfh_i_p_bz_d_64_scaled() {
    uint32_t insn = 0xC460A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfh_i_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfh_i_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_ai_s() {
    uint32_t insn = 0x8500E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_ai_d() {
    uint32_t insn = 0xC500E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_bi_s() {
    uint32_t insn = 0x85C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_bi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_bi_s: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_br_s() {
    uint32_t insn = 0x8500C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_br_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_br_s: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_bz_s_x32_scaled() {
    uint32_t insn = 0x84204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_bz_d_x32_scaled() {
    uint32_t insn = 0xC4204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_prfw_i_p_bz_d_64_scaled() {
    uint32_t insn = 0xC460C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfw_i_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  prfw_i_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_psel_p_ppi_() {
    uint32_t insn = 0x25204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: psel_p_ppi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PSEL);
#ifdef VEDA64_STRINGS
    std::cout << "  psel_p_ppi_: " << result->to_string() << std::endl;
#endif
}

void test_ptest__p_p_() {
    uint32_t insn = 0x2550C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ptest__p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PTEST);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ptest__p_p_: " << result->to_string() << std::endl;
#endif
}

void test_ptrue_p_s_() {
    uint32_t insn = 0x2518E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ptrue_p_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PTRUE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  ptrue_p_s_: " << result->to_string() << std::endl;
#endif
}

void test_ptrue_pn_i_() {
    uint32_t insn = 0x25207810u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ptrue_pn_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PTRUE);
#ifdef VEDA64_STRINGS
    std::cout << "  ptrue_pn_i_: " << result->to_string() << std::endl;
#endif
}

void test_ptrues_p_s_() {
    uint32_t insn = 0x2519E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ptrues_p_s_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PTRUES);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  ptrues_p_s_: " << result->to_string() << std::endl;
#endif
}

void test_punpkhi_p_p_() {
    uint32_t insn = 0x05314000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: punpkhi_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  punpkhi_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_punpklo_p_p_() {
    uint32_t insn = 0x05304000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: punpklo_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  punpklo_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_raddhnb_z_zz_() {
    uint32_t insn = 0x45606800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: raddhnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RADDHNB);
#ifdef VEDA64_STRINGS
    std::cout << "  raddhnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_raddhnt_z_zz_() {
    uint32_t insn = 0x45606C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: raddhnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RADDHNT);
#ifdef VEDA64_STRINGS
    std::cout << "  raddhnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_rax1_z_zz_() {
    uint32_t insn = 0x4520F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rax1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RAX1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  rax1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_rbit_z_p_z_m() {
    uint32_t insn = 0x05278000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rbit_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RBIT);
#ifdef VEDA64_STRINGS
    std::cout << "  rbit_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_rbit_z_p_z_z() {
    uint32_t insn = 0x0527A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rbit_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RBIT);
#ifdef VEDA64_STRINGS
    std::cout << "  rbit_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_rdffr_p_f_() {
    uint32_t insn = 0x2519F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rdffr_p_f_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RDFFR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  rdffr_p_f_: " << result->to_string() << std::endl;
#endif
}

void test_rdffr_p_p_f_() {
    uint32_t insn = 0x2518F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rdffr_p_p_f_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RDFFR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  rdffr_p_p_f_: " << result->to_string() << std::endl;
#endif
}

void test_rdffrs_p_p_f_() {
    uint32_t insn = 0x2558F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rdffrs_p_p_f_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RDFFRS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  rdffrs_p_p_f_: " << result->to_string() << std::endl;
#endif
}

void test_rdsvl_r_i_() {
    uint32_t insn = 0x04BF5800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rdsvl_r_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RDSVL);
#ifdef VEDA64_STRINGS
    std::cout << "  rdsvl_r_i_: " << result->to_string() << std::endl;
#endif
}

void test_rdvl_r_i_() {
    uint32_t insn = 0x04BF5000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rdvl_r_i_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RDVL);
#ifdef VEDA64_STRINGS
    std::cout << "  rdvl_r_i_: " << result->to_string() << std::endl;
#endif
}

void test_rev_p_p_() {
    uint32_t insn = 0x05344000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev_p_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV);
#ifdef VEDA64_STRINGS
    std::cout << "  rev_p_p_: " << result->to_string() << std::endl;
#endif
}

void test_rev_z_z_() {
    uint32_t insn = 0x05383800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rev_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REV);
#ifdef VEDA64_STRINGS
    std::cout << "  rev_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_revb_z_z_m() {
    uint32_t insn = 0x05648000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revb_z_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  revb_z_z_m: " << result->to_string() << std::endl;
#endif
}

void test_revb_z_z_z() {
    uint32_t insn = 0x0564A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revb_z_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  revb_z_z_z: " << result->to_string() << std::endl;
#endif
}

void test_revh_z_z_m() {
    uint32_t insn = 0x05A58000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revh_z_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  revh_z_z_m: " << result->to_string() << std::endl;
#endif
}

void test_revh_z_z_z() {
    uint32_t insn = 0x05A5A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revh_z_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  revh_z_z_z: " << result->to_string() << std::endl;
#endif
}

void test_revw_z_z_m() {
    uint32_t insn = 0x05E68000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revw_z_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  revw_z_z_m: " << result->to_string() << std::endl;
#endif
}

void test_revw_z_z_z() {
    uint32_t insn = 0x05E6A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revw_z_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  revw_z_z_z: " << result->to_string() << std::endl;
#endif
}

void test_revd_z_p_z_m() {
    uint32_t insn = 0x052E8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revd_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REVD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  revd_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_revd_z_p_z_z() {
    uint32_t insn = 0x052EA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: revd_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::REVD);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  revd_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_rshrnb_z_zi_() {
    uint32_t insn = 0x45201800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rshrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RSHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  rshrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_rshrnt_z_zi_() {
    uint32_t insn = 0x45201C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rshrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RSHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  rshrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_rsubhnb_z_zz_() {
    uint32_t insn = 0x45607800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rsubhnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RSUBHNB);
#ifdef VEDA64_STRINGS
    std::cout << "  rsubhnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_rsubhnt_z_zz_() {
    uint32_t insn = 0x45607C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rsubhnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RSUBHNT);
#ifdef VEDA64_STRINGS
    std::cout << "  rsubhnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_saba_z_zzz_() {
    uint32_t insn = 0x4500F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saba_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABA);
#ifdef VEDA64_STRINGS
    std::cout << "  saba_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sabal_z_zz_() {
    uint32_t insn = 0x4440D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabal_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABAL);
#ifdef VEDA64_STRINGS
    std::cout << "  sabal_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sabalb_z_zzz_() {
    uint32_t insn = 0x4540C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABALB);
#ifdef VEDA64_STRINGS
    std::cout << "  sabalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sabalt_z_zzz_() {
    uint32_t insn = 0x4540C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABALT);
#ifdef VEDA64_STRINGS
    std::cout << "  sabalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sabd_z_p_zz_() {
    uint32_t insn = 0x040C0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABD);
#ifdef VEDA64_STRINGS
    std::cout << "  sabd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sabdlb_z_zz_() {
    uint32_t insn = 0x45403000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabdlb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABDLB);
#ifdef VEDA64_STRINGS
    std::cout << "  sabdlb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sabdlt_z_zz_() {
    uint32_t insn = 0x45403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sabdlt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SABDLT);
#ifdef VEDA64_STRINGS
    std::cout << "  sabdlt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sadalp_z_p_z_() {
    uint32_t insn = 0x4444A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sadalp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADALP);
#ifdef VEDA64_STRINGS
    std::cout << "  sadalp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_saddlb_z_zz_() {
    uint32_t insn = 0x45400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddlb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDLB);
#ifdef VEDA64_STRINGS
    std::cout << "  saddlb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_saddlbt_z_zz_() {
    uint32_t insn = 0x45408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddlbt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDLBT);
#ifdef VEDA64_STRINGS
    std::cout << "  saddlbt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_saddlt_z_zz_() {
    uint32_t insn = 0x45400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddlt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDLT);
#ifdef VEDA64_STRINGS
    std::cout << "  saddlt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_saddv_r_p_z_() {
    uint32_t insn = 0x04002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDV);
#ifdef VEDA64_STRINGS
    std::cout << "  saddv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_saddwb_z_zz_() {
    uint32_t insn = 0x45404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddwb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDWB);
#ifdef VEDA64_STRINGS
    std::cout << "  saddwb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_saddwt_z_zz_() {
    uint32_t insn = 0x45404400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: saddwt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SADDWT);
#ifdef VEDA64_STRINGS
    std::cout << "  saddwt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sbclb_z_zzz_() {
    uint32_t insn = 0x4580D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbclb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCLB);
#ifdef VEDA64_STRINGS
    std::cout << "  sbclb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sbclt_z_zzz_() {
    uint32_t insn = 0x4580D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sbclt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SBCLT);
#ifdef VEDA64_STRINGS
    std::cout << "  sbclt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sclamp_z_zz_() {
    uint32_t insn = 0x4400C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sclamp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCLAMP);
#ifdef VEDA64_STRINGS
    std::cout << "  sclamp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_h2fp16() {
    uint32_t insn = 0x6552A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_h2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_h2fp16: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_h2fp16z() {
    uint32_t insn = 0x645CC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_h2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_h2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2fp16() {
    uint32_t insn = 0x6554A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2fp16: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2fp16z() {
    uint32_t insn = 0x645D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2s() {
    uint32_t insn = 0x6594A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2s: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2sz() {
    uint32_t insn = 0x649D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2sz: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2d() {
    uint32_t insn = 0x65D0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2d: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_w2dz() {
    uint32_t insn = 0x64DC8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_w2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_w2dz: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2fp16() {
    uint32_t insn = 0x6556A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2fp16: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2fp16z() {
    uint32_t insn = 0x645DC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2s() {
    uint32_t insn = 0x65D4A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2s: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2sz() {
    uint32_t insn = 0x64DD8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2sz: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2d() {
    uint32_t insn = 0x65D6A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2d: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_p_z_x2dz() {
    uint32_t insn = 0x64DDC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_p_z_x2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_p_z_x2dz: " << result->to_string() << std::endl;
#endif
}

void test_scvtf_z_z_() {
    uint32_t insn = 0x654C3000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtf_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTF);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtf_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_scvtflt_z_z_() {
    uint32_t insn = 0x654C3800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: scvtflt_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SCVTFLT);
#ifdef VEDA64_STRINGS
    std::cout << "  scvtflt_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_sdiv_z_p_zz_() {
    uint32_t insn = 0x04940000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdiv_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDIV);
#ifdef VEDA64_STRINGS
    std::cout << "  sdiv_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sdivr_z_p_zz_() {
    uint32_t insn = 0x04960000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdivr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDIVR);
#ifdef VEDA64_STRINGS
    std::cout << "  sdivr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z16_zzz_h() {
    uint32_t insn = 0x44400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z16_zzz_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z16_zzz_h: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z32_zzz_() {
    uint32_t insn = 0x4400C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z32_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z32_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z16_zzzi_h() {
    uint32_t insn = 0x44200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z16_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z16_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z32_zzzi_() {
    uint32_t insn = 0x4480C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z32_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z32_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z_zzz_() {
    uint32_t insn = 0x44800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z_zzzi_s() {
    uint32_t insn = 0x44A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sdot_z_zzzi_d() {
    uint32_t insn = 0x44E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sdot_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sdot_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sel_p_p_pp_() {
    uint32_t insn = 0x25004210u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sel_p_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SEL);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sel_p_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_sel_z_p_zz_() {
    uint32_t insn = 0x0520C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sel_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SEL);
#ifdef VEDA64_STRINGS
    std::cout << "  sel_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_setffr_f_() {
    uint32_t insn = 0x252C9000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setffr_f_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SETFFR);
#ifdef VEDA64_STRINGS
    std::cout << "  setffr_f_: " << result->to_string() << std::endl;
#endif
}

void test_shadd_z_p_zz_() {
    uint32_t insn = 0x44108000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SHADD);
#ifdef VEDA64_STRINGS
    std::cout << "  shadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_shrnb_z_zi_() {
    uint32_t insn = 0x45201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  shrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_shrnt_z_zi_() {
    uint32_t insn = 0x45201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  shrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_shsub_z_p_zz_() {
    uint32_t insn = 0x44128000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SHSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  shsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_shsubr_z_p_zz_() {
    uint32_t insn = 0x44168000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: shsubr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SHSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  shsubr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sli_z_zzi_() {
    uint32_t insn = 0x4500F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sli_z_zzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SLI);
#ifdef VEDA64_STRINGS
    std::cout << "  sli_z_zzi_: " << result->to_string() << std::endl;
#endif
}

void test_sm4e_z_zz_() {
    uint32_t insn = 0x4523E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm4e_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SM4E);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sm4e_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sm4ekey_z_zz_() {
    uint32_t insn = 0x4520F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sm4ekey_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SM4EKEY);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sm4ekey_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smax_z_p_zz_() {
    uint32_t insn = 0x04080000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smax_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  smax_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smax_z_zi_() {
    uint32_t insn = 0x2528C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smax_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  smax_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_smaxp_z_p_zz_() {
    uint32_t insn = 0x4414A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaxp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAXP);
#ifdef VEDA64_STRINGS
    std::cout << "  smaxp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smaxqv_z_p_z_() {
    uint32_t insn = 0x040C2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaxqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAXQV);
#ifdef VEDA64_STRINGS
    std::cout << "  smaxqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_smaxv_r_p_z_() {
    uint32_t insn = 0x04082000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smaxv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMAXV);
#ifdef VEDA64_STRINGS
    std::cout << "  smaxv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_smin_z_p_zz_() {
    uint32_t insn = 0x040A0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smin_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  smin_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smin_z_zi_() {
    uint32_t insn = 0x252AC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smin_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  smin_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sminp_z_p_zz_() {
    uint32_t insn = 0x4416A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sminp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMINP);
#ifdef VEDA64_STRINGS
    std::cout << "  sminp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sminqv_z_p_z_() {
    uint32_t insn = 0x040E2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sminqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMINQV);
#ifdef VEDA64_STRINGS
    std::cout << "  sminqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_sminv_r_p_z_() {
    uint32_t insn = 0x040A2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sminv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMINV);
#ifdef VEDA64_STRINGS
    std::cout << "  sminv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_smlalb_z_zzz_() {
    uint32_t insn = 0x44404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALB);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_smlalb_z_zzzi_s() {
    uint32_t insn = 0x44A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smlalb_z_zzzi_d() {
    uint32_t insn = 0x44E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_smlalt_z_zzz_() {
    uint32_t insn = 0x44404400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALT);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_smlalt_z_zzzi_s() {
    uint32_t insn = 0x44A08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smlalt_z_zzzi_d() {
    uint32_t insn = 0x44E08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlalt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlalt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_smlslb_z_zzz_() {
    uint32_t insn = 0x44405000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLB);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_smlslb_z_zzzi_s() {
    uint32_t insn = 0x44A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smlslb_z_zzzi_d() {
    uint32_t insn = 0x44E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_smlslt_z_zzz_() {
    uint32_t insn = 0x44405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLT);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_smlslt_z_zzzi_s() {
    uint32_t insn = 0x44A0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smlslt_z_zzzi_d() {
    uint32_t insn = 0x44E0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smlslt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smlslt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_smmla_z_zzz_() {
    uint32_t insn = 0x45009800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smmla_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smmla_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_smulh_z_p_zz_() {
    uint32_t insn = 0x04120000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smulh_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  smulh_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smulh_z_zz_() {
    uint32_t insn = 0x04206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smulh_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  smulh_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smullb_z_zz_() {
    uint32_t insn = 0x45407000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLB);
#ifdef VEDA64_STRINGS
    std::cout << "  smullb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smullb_z_zzi_s() {
    uint32_t insn = 0x44A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullb_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smullb_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smullb_z_zzi_d() {
    uint32_t insn = 0x44E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullb_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smullb_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_smullt_z_zz_() {
    uint32_t insn = 0x45407400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLT);
#ifdef VEDA64_STRINGS
    std::cout << "  smullt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_smullt_z_zzi_s() {
    uint32_t insn = 0x44A0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullt_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smullt_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_smullt_z_zzi_d() {
    uint32_t insn = 0x44E0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: smullt_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  smullt_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_splice_z_p_zz_con() {
    uint32_t insn = 0x052D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: splice_z_p_zz_con" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SPLICE);
#ifdef VEDA64_STRINGS
    std::cout << "  splice_z_p_zz_con: " << result->to_string() << std::endl;
#endif
}

void test_splice_z_p_zz_des() {
    uint32_t insn = 0x052C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: splice_z_p_zz_des" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SPLICE);
#ifdef VEDA64_STRINGS
    std::cout << "  splice_z_p_zz_des: " << result->to_string() << std::endl;
#endif
}

void test_sqabs_z_p_z_m() {
    uint32_t insn = 0x4408A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqabs_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQABS);
#ifdef VEDA64_STRINGS
    std::cout << "  sqabs_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_sqabs_z_p_z_z() {
    uint32_t insn = 0x440AA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqabs_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQABS);
#ifdef VEDA64_STRINGS
    std::cout << "  sqabs_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_sqadd_z_p_zz_() {
    uint32_t insn = 0x44188000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  sqadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqadd_z_zi_() {
    uint32_t insn = 0x2524C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqadd_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  sqadd_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqadd_z_zz_() {
    uint32_t insn = 0x04201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  sqadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqcadd_z_zz_() {
    uint32_t insn = 0x4501D800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqcadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQCADD);
#ifdef VEDA64_STRINGS
    std::cout << "  sqcadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqcvtn_z_mz2_() {
    uint32_t insn = 0x45314000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqcvtn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqcvtn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqcvtun_z_mz2_() {
    uint32_t insn = 0x45315000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqcvtun_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQCVTUN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqcvtun_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqdecb_r_rs_sx() {
    uint32_t insn = 0x0420F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecb_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecb_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqdecb_r_rs_x() {
    uint32_t insn = 0x0430F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecb_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecb_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqdecd_r_rs_sx() {
    uint32_t insn = 0x04E0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecd_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecd_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqdecd_r_rs_x() {
    uint32_t insn = 0x04F0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecd_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecd_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqdecd_z_zs_() {
    uint32_t insn = 0x04E0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqdech_r_rs_sx() {
    uint32_t insn = 0x0460F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdech_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdech_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqdech_r_rs_x() {
    uint32_t insn = 0x0470F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdech_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdech_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqdech_z_zs_() {
    uint32_t insn = 0x0460C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdech_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdech_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqdecp_r_p_r_sx() {
    uint32_t insn = 0x252A8800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecp_r_p_r_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecp_r_p_r_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqdecp_r_p_r_x() {
    uint32_t insn = 0x252A8C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecp_r_p_r_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecp_r_p_r_x: " << result->to_string() << std::endl;
#endif
}

void test_sqdecp_z_p_z_() {
    uint32_t insn = 0x256A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_sqdecw_r_rs_sx() {
    uint32_t insn = 0x04A0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecw_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecw_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqdecw_r_rs_x() {
    uint32_t insn = 0x04B0F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecw_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecw_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqdecw_z_zs_() {
    uint32_t insn = 0x04A0C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdecw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDECW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdecw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalb_z_zzz_() {
    uint32_t insn = 0x44406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalb_z_zzzi_s() {
    uint32_t insn = 0x44A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalb_z_zzzi_d() {
    uint32_t insn = 0x44E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalbt_z_zzz_() {
    uint32_t insn = 0x44400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalbt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALBT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalbt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalt_z_zzz_() {
    uint32_t insn = 0x44406400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalt_z_zzzi_s() {
    uint32_t insn = 0x44A02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlalt_z_zzzi_d() {
    uint32_t insn = 0x44E02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlalt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlalt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslb_z_zzz_() {
    uint32_t insn = 0x44406800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslb_z_zzzi_s() {
    uint32_t insn = 0x44A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslb_z_zzzi_d() {
    uint32_t insn = 0x44E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslbt_z_zzz_() {
    uint32_t insn = 0x44400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslbt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLBT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslbt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslt_z_zzz_() {
    uint32_t insn = 0x44406C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslt_z_zzzi_s() {
    uint32_t insn = 0x44A03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmlslt_z_zzzi_d() {
    uint32_t insn = 0x44E03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmlslt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmlslt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmulh_z_zz_() {
    uint32_t insn = 0x04207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmulh_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmulh_z_zzi_h() {
    uint32_t insn = 0x4420F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_z_zzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmulh_z_zzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sqdmulh_z_zzi_s() {
    uint32_t insn = 0x44A0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmulh_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmulh_z_zzi_d() {
    uint32_t insn = 0x44E0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmulh_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmulh_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullb_z_zz_() {
    uint32_t insn = 0x45406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullb_z_zzi_s() {
    uint32_t insn = 0x44A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullb_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullb_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullb_z_zzi_d() {
    uint32_t insn = 0x44E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullb_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullb_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullt_z_zz_() {
    uint32_t insn = 0x45406400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullt_z_zzi_s() {
    uint32_t insn = 0x44A0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullt_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullt_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqdmullt_z_zzi_d() {
    uint32_t insn = 0x44E0E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqdmullt_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQDMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqdmullt_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqincb_r_rs_sx() {
    uint32_t insn = 0x0420F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincb_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincb_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqincb_r_rs_x() {
    uint32_t insn = 0x0430F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincb_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincb_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqincd_r_rs_sx() {
    uint32_t insn = 0x04E0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincd_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCD);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincd_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqincd_r_rs_x() {
    uint32_t insn = 0x04F0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincd_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincd_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqincd_z_zs_() {
    uint32_t insn = 0x04E0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqinch_r_rs_sx() {
    uint32_t insn = 0x0460F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqinch_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqinch_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqinch_r_rs_x() {
    uint32_t insn = 0x0470F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqinch_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqinch_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqinch_z_zs_() {
    uint32_t insn = 0x0460C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqinch_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqinch_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqincp_r_p_r_sx() {
    uint32_t insn = 0x25288800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincp_r_p_r_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincp_r_p_r_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqincp_r_p_r_x() {
    uint32_t insn = 0x25288C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincp_r_p_r_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincp_r_p_r_x: " << result->to_string() << std::endl;
#endif
}

void test_sqincp_z_p_z_() {
    uint32_t insn = 0x25688000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_sqincw_r_rs_sx() {
    uint32_t insn = 0x04A0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincw_r_rs_sx" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincw_r_rs_sx: " << result->to_string() << std::endl;
#endif
}

void test_sqincw_r_rs_x() {
    uint32_t insn = 0x04B0F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincw_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincw_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_sqincw_z_zs_() {
    uint32_t insn = 0x04A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqincw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQINCW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  sqincw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_sqneg_z_p_z_m() {
    uint32_t insn = 0x4409A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqneg_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQNEG);
#ifdef VEDA64_STRINGS
    std::cout << "  sqneg_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_sqneg_z_p_z_z() {
    uint32_t insn = 0x440BA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqneg_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQNEG);
#ifdef VEDA64_STRINGS
    std::cout << "  sqneg_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_sqrdcmlah_z_zzz_() {
    uint32_t insn = 0x44003000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdcmlah_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDCMLAH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdcmlah_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrdcmlah_z_zzzi_h() {
    uint32_t insn = 0x44A07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdcmlah_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDCMLAH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdcmlah_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sqrdcmlah_z_zzzi_s() {
    uint32_t insn = 0x44E07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdcmlah_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDCMLAH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdcmlah_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlah_z_zzz_() {
    uint32_t insn = 0x44007000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlah_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlah_z_zzzi_h() {
    uint32_t insn = 0x44201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlah_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlah_z_zzzi_s() {
    uint32_t insn = 0x44A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlah_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlah_z_zzzi_d() {
    uint32_t insn = 0x44E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlah_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLAH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlah_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlsh_z_zzz_() {
    uint32_t insn = 0x44007400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlsh_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlsh_z_zzzi_h() {
    uint32_t insn = 0x44201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_z_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlsh_z_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlsh_z_zzzi_s() {
    uint32_t insn = 0x44A01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlsh_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmlsh_z_zzzi_d() {
    uint32_t insn = 0x44E01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmlsh_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMLSH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmlsh_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmulh_z_zz_() {
    uint32_t insn = 0x04207400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmulh_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmulh_z_zzi_h() {
    uint32_t insn = 0x4420F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_z_zzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmulh_z_zzi_h: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmulh_z_zzi_s() {
    uint32_t insn = 0x44A0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmulh_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sqrdmulh_z_zzi_d() {
    uint32_t insn = 0x44E0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrdmulh_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRDMULH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrdmulh_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_sqrshl_z_p_zz_() {
    uint32_t insn = 0x440A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshlr_z_p_zz_() {
    uint32_t insn = 0x440E8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrn_z_mz2_b() {
    uint32_t insn = 0x45A82800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrn_z_mz2_b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrn_z_mz2_b: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrn_z_mz2_() {
    uint32_t insn = 0x45B02800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrnb_z_zi_() {
    uint32_t insn = 0x45202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrnt_z_zi_() {
    uint32_t insn = 0x45202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrun_z_mz2_b() {
    uint32_t insn = 0x45A80800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrun_z_mz2_b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRUN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrun_z_mz2_b: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrun_z_mz2_() {
    uint32_t insn = 0x45B00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrun_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRUN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrun_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrunb_z_zi_() {
    uint32_t insn = 0x45200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrunb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRUNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrunb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqrshrunt_z_zi_() {
    uint32_t insn = 0x45200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqrshrunt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQRSHRUNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqrshrunt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshl_z_p_zi_() {
    uint32_t insn = 0x04068000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshl_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshl_z_p_zz_() {
    uint32_t insn = 0x44088000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqshlr_z_p_zz_() {
    uint32_t insn = 0x440C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqshlu_z_p_zi_() {
    uint32_t insn = 0x040F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshlu_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHLU);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshlu_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrn_z_mz2_() {
    uint32_t insn = 0x45A80000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrnb_z_zi_() {
    uint32_t insn = 0x45202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrnt_z_zi_() {
    uint32_t insn = 0x45202400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrun_z_mz2_() {
    uint32_t insn = 0x45A82000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrun_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRUN);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrun_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrunb_z_zi_() {
    uint32_t insn = 0x45200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrunb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRUNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrunb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqshrunt_z_zi_() {
    uint32_t insn = 0x45200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqshrunt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSHRUNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqshrunt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqsub_z_p_zz_() {
    uint32_t insn = 0x441A8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqsub_z_zi_() {
    uint32_t insn = 0x2526C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsub_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqsub_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sqsub_z_zz_() {
    uint32_t insn = 0x04201800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsub_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqsub_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqsubr_z_p_zz_() {
    uint32_t insn = 0x441E8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqsubr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  sqsubr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqxtnb_z_zz_() {
    uint32_t insn = 0x45204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQXTNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqxtnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqxtnt_z_zz_() {
    uint32_t insn = 0x45204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQXTNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqxtnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqxtunb_z_zz_() {
    uint32_t insn = 0x45205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtunb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQXTUNB);
#ifdef VEDA64_STRINGS
    std::cout << "  sqxtunb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sqxtunt_z_zz_() {
    uint32_t insn = 0x45205400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sqxtunt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SQXTUNT);
#ifdef VEDA64_STRINGS
    std::cout << "  sqxtunt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_srhadd_z_p_zz_() {
    uint32_t insn = 0x44148000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srhadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRHADD);
#ifdef VEDA64_STRINGS
    std::cout << "  srhadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sri_z_zzi_() {
    uint32_t insn = 0x4500F000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sri_z_zzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRI);
#ifdef VEDA64_STRINGS
    std::cout << "  sri_z_zzi_: " << result->to_string() << std::endl;
#endif
}

void test_srshl_z_p_zz_() {
    uint32_t insn = 0x44028000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  srshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_srshlr_z_p_zz_() {
    uint32_t insn = 0x44068000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  srshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_srshr_z_p_zi_() {
    uint32_t insn = 0x040C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srshr_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRSHR);
#ifdef VEDA64_STRINGS
    std::cout << "  srshr_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_srsra_z_zi_() {
    uint32_t insn = 0x4500E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: srsra_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SRSRA);
#ifdef VEDA64_STRINGS
    std::cout << "  srsra_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sshllb_z_zi_() {
    uint32_t insn = 0x4500A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshllb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSHLLB);
#ifdef VEDA64_STRINGS
    std::cout << "  sshllb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sshllt_z_zi_() {
    uint32_t insn = 0x4500A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sshllt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSHLLT);
#ifdef VEDA64_STRINGS
    std::cout << "  sshllt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_ssra_z_zi_() {
    uint32_t insn = 0x4500E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssra_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSRA);
#ifdef VEDA64_STRINGS
    std::cout << "  ssra_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_ssublb_z_zz_() {
    uint32_t insn = 0x45401000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssublb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBLB);
#ifdef VEDA64_STRINGS
    std::cout << "  ssublb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ssublbt_z_zz_() {
    uint32_t insn = 0x45408800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssublbt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBLBT);
#ifdef VEDA64_STRINGS
    std::cout << "  ssublbt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ssublt_z_zz_() {
    uint32_t insn = 0x45401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssublt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBLT);
#ifdef VEDA64_STRINGS
    std::cout << "  ssublt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ssubltb_z_zz_() {
    uint32_t insn = 0x45408C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssubltb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBLTB);
#ifdef VEDA64_STRINGS
    std::cout << "  ssubltb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ssubwb_z_zz_() {
    uint32_t insn = 0x45405000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssubwb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBWB);
#ifdef VEDA64_STRINGS
    std::cout << "  ssubwb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ssubwt_z_zz_() {
    uint32_t insn = 0x45405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ssubwt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SSUBWT);
#ifdef VEDA64_STRINGS
    std::cout << "  ssubwt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_ai_s() {
    uint32_t insn = 0xE460A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_ai_d() {
    uint32_t insn = 0xE440A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_bi_() {
    uint32_t insn = 0xE400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_br_() {
    uint32_t insn = 0xE4004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_br_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_br_: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xE4008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0xE4408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1b_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xE400A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1b_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1b_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_ai_d() {
    uint32_t insn = 0xE5C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bi_() {
    uint32_t insn = 0xE5E0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bi_u128() {
    uint32_t insn = 0xE5C0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bi_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bi_u128: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_br_() {
    uint32_t insn = 0xE5E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_br_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_br_: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_br_u128() {
    uint32_t insn = 0xE5C04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_br_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_br_u128: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xE5A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xE5808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xE5A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1d_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xE580A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1d_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1d_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_ai_s() {
    uint32_t insn = 0xE4E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_ai_d() {
    uint32_t insn = 0xE4C0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bi_() {
    uint32_t insn = 0xE4A0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_br_() {
    uint32_t insn = 0xE4A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_br_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_br_: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0xE4E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xE4A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xE4808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0xE4C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xE4A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1h_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xE480A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1h_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1h_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1q_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xE4202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1q_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1q_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_ai_s() {
    uint32_t insn = 0xE560A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_ai_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_ai_s: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_ai_d() {
    uint32_t insn = 0xE540A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_ai_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_ai_d: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bi_() {
    uint32_t insn = 0xE540E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bi_u128() {
    uint32_t insn = 0xE500E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bi_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bi_u128: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_br_() {
    uint32_t insn = 0xE5404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_br_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_br_: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_br_u128() {
    uint32_t insn = 0xE5004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_br_u128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_br_u128: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_s_x32_scaled() {
    uint32_t insn = 0xE5608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_s_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_s_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_d_x32_scaled() {
    uint32_t insn = 0xE5208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_d_x32_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_d_x32_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_d_x32_unscaled() {
    uint32_t insn = 0xE5008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_d_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_d_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_s_x32_unscaled() {
    uint32_t insn = 0xE5408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_d_64_scaled() {
    uint32_t insn = 0xE520A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_d_64_scaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_d_64_scaled: " << result->to_string() << std::endl;
#endif
}

void test_st1w_z_p_bz_d_64_unscaled() {
    uint32_t insn = 0xE500A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1w_z_p_bz_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st1w_z_p_bz_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_st2b_z_p_bi_contiguous() {
    uint32_t insn = 0xE430E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st2b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2b_z_p_br_contiguous() {
    uint32_t insn = 0xE4206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st2b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2d_z_p_bi_contiguous() {
    uint32_t insn = 0xE5B0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st2d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2d_z_p_br_contiguous() {
    uint32_t insn = 0xE5A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st2d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2h_z_p_bi_contiguous() {
    uint32_t insn = 0xE4B0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st2h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2h_z_p_br_contiguous() {
    uint32_t insn = 0xE4A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st2h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2q_z_p_bi_contiguous() {
    uint32_t insn = 0xE4400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st2q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2q_z_p_br_contiguous() {
    uint32_t insn = 0xE4600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st2q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2w_z_p_bi_contiguous() {
    uint32_t insn = 0xE530E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st2w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st2w_z_p_br_contiguous() {
    uint32_t insn = 0xE5206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st2w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3b_z_p_bi_contiguous() {
    uint32_t insn = 0xE450E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st3b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3b_z_p_br_contiguous() {
    uint32_t insn = 0xE4406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st3b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3d_z_p_bi_contiguous() {
    uint32_t insn = 0xE5D0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st3d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3d_z_p_br_contiguous() {
    uint32_t insn = 0xE5C06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st3d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3h_z_p_bi_contiguous() {
    uint32_t insn = 0xE4D0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st3h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3h_z_p_br_contiguous() {
    uint32_t insn = 0xE4C06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st3h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3q_z_p_bi_contiguous() {
    uint32_t insn = 0xE4800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st3q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3q_z_p_br_contiguous() {
    uint32_t insn = 0xE4A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st3q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3w_z_p_bi_contiguous() {
    uint32_t insn = 0xE550E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st3w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st3w_z_p_br_contiguous() {
    uint32_t insn = 0xE5406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st3w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4b_z_p_bi_contiguous() {
    uint32_t insn = 0xE470E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st4b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4b_z_p_br_contiguous() {
    uint32_t insn = 0xE4606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st4b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4d_z_p_bi_contiguous() {
    uint32_t insn = 0xE5F0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st4d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4d_z_p_br_contiguous() {
    uint32_t insn = 0xE5E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st4d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4h_z_p_bi_contiguous() {
    uint32_t insn = 0xE4F0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st4h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4h_z_p_br_contiguous() {
    uint32_t insn = 0xE4E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st4h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4q_z_p_bi_contiguous() {
    uint32_t insn = 0xE4C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4q_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st4q_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4q_z_p_br_contiguous() {
    uint32_t insn = 0xE4E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4q_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st4q_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4w_z_p_bi_contiguous() {
    uint32_t insn = 0xE570E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  st4w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_st4w_z_p_br_contiguous() {
    uint32_t insn = 0xE5606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  st4w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1b_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0xE4402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1b_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1b_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1b_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xE4002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1b_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1b_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1b_z_p_bi_contiguous() {
    uint32_t insn = 0xE410E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1b_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1b_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1b_z_p_br_contiguous() {
    uint32_t insn = 0xE4006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1b_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1b_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1d_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xE5802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1d_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1d_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1d_z_p_bi_contiguous() {
    uint32_t insn = 0xE590E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1d_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1d_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1d_z_p_br_contiguous() {
    uint32_t insn = 0xE5806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1d_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1d_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1h_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0xE4C02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1h_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1h_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1h_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xE4802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1h_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1h_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1h_z_p_bi_contiguous() {
    uint32_t insn = 0xE490E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1h_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1h_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1h_z_p_br_contiguous() {
    uint32_t insn = 0xE4806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1h_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1h_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1w_z_p_ar_s_x32_unscaled() {
    uint32_t insn = 0xE5402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1w_z_p_ar_s_x32_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1w_z_p_ar_s_x32_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1w_z_p_ar_d_64_unscaled() {
    uint32_t insn = 0xE5002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1w_z_p_ar_d_64_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1w_z_p_ar_d_64_unscaled: " << result->to_string() << std::endl;
#endif
}

void test_stnt1w_z_p_bi_contiguous() {
    uint32_t insn = 0xE510E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1w_z_p_bi_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1w_z_p_bi_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_stnt1w_z_p_br_contiguous() {
    uint32_t insn = 0xE5006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnt1w_z_p_br_contiguous" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
#ifdef VEDA64_STRINGS
    std::cout << "  stnt1w_z_p_br_contiguous: " << result->to_string() << std::endl;
#endif
}

void test_str_p_bi_() {
    uint32_t insn = 0xE5800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_p_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  str_p_bi_: " << result->to_string() << std::endl;
#endif
}

void test_str_z_bi_() {
    uint32_t insn = 0xE5804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_z_bi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
#ifdef VEDA64_STRINGS
    std::cout << "  str_z_bi_: " << result->to_string() << std::endl;
#endif
}

void test_sub_z_p_zz_() {
    uint32_t insn = 0x04010000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sub_z_zi_() {
    uint32_t insn = 0x2521C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sub_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sub_z_zz_() {
    uint32_t insn = 0x04200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sub_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sub_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subhnb_z_zz_() {
    uint32_t insn = 0x45607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subhnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBHNB);
#ifdef VEDA64_STRINGS
    std::cout << "  subhnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subhnt_z_zz_() {
    uint32_t insn = 0x45607400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subhnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBHNT);
#ifdef VEDA64_STRINGS
    std::cout << "  subhnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subp_z_p_zz_() {
    uint32_t insn = 0x4410A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBP);
#ifdef VEDA64_STRINGS
    std::cout << "  subp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subpt_z_p_zz_() {
    uint32_t insn = 0x04C50000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subpt_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBPT);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  subpt_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subpt_z_zz_() {
    uint32_t insn = 0x04E00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subpt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBPT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  subpt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subr_z_p_zz_() {
    uint32_t insn = 0x04030000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  subr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_subr_z_zi_() {
    uint32_t insn = 0x2523C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: subr_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  subr_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_sudot_z_zzzi_s() {
    uint32_t insn = 0x44A01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sudot_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sudot_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_sunpkhi_z_z_() {
    uint32_t insn = 0x05713800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sunpkhi_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sunpkhi_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_sunpklo_z_z_() {
    uint32_t insn = 0x05703800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sunpklo_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sunpklo_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_suqadd_z_p_zz_() {
    uint32_t insn = 0x441C8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: suqadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::SUQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  suqadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_sxtb_z_p_z_m() {
    uint32_t insn = 0x0450A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxtb_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sxtb_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_sxtb_z_p_z_z() {
    uint32_t insn = 0x0440A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxtb_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sxtb_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_sxth_z_p_z_m() {
    uint32_t insn = 0x0492A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxth_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sxth_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_sxth_z_p_z_z() {
    uint32_t insn = 0x0482A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxth_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  sxth_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_sxtw_z_p_z_m() {
    uint32_t insn = 0x04D4A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxtw_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sxtw_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_sxtw_z_p_z_z() {
    uint32_t insn = 0x04C4A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sxtw_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  sxtw_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_tbl_z_zz_1() {
    uint32_t insn = 0x05203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_z_zz_1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::TBL);
#ifdef VEDA64_STRINGS
    std::cout << "  tbl_z_zz_1: " << result->to_string() << std::endl;
#endif
}

void test_tbl_z_zz_2() {
    uint32_t insn = 0x05202800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbl_z_zz_2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::TBL);
#ifdef VEDA64_STRINGS
    std::cout << "  tbl_z_zz_2: " << result->to_string() << std::endl;
#endif
}

void test_tblq_z_zz_() {
    uint32_t insn = 0x4400F800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tblq_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::TBLQ);
#ifdef VEDA64_STRINGS
    std::cout << "  tblq_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_tbx_z_zz_() {
    uint32_t insn = 0x05202C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbx_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::TBX);
#ifdef VEDA64_STRINGS
    std::cout << "  tbx_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_tbxq_z_zz_() {
    uint32_t insn = 0x05203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: tbxq_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::TBXQ);
#ifdef VEDA64_STRINGS
    std::cout << "  tbxq_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_trn1_p_pp_() {
    uint32_t insn = 0x05205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn1_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  trn1_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_trn2_p_pp_() {
    uint32_t insn = 0x05205400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn2_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  trn2_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_trn1_z_zz_() {
    uint32_t insn = 0x05207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  trn1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_trn1_z_zz_q() {
    uint32_t insn = 0x05A01800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn1_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  trn1_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_trn2_z_zz_() {
    uint32_t insn = 0x05207400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn2_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  trn2_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_trn2_z_zz_q() {
    uint32_t insn = 0x05A01C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: trn2_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  trn2_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_uaba_z_zzz_() {
    uint32_t insn = 0x4500FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaba_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABA);
#ifdef VEDA64_STRINGS
    std::cout << "  uaba_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_uabal_z_zz_() {
    uint32_t insn = 0x4440DC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabal_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABAL);
#ifdef VEDA64_STRINGS
    std::cout << "  uabal_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uabalb_z_zzz_() {
    uint32_t insn = 0x4540C800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABALB);
#ifdef VEDA64_STRINGS
    std::cout << "  uabalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_uabalt_z_zzz_() {
    uint32_t insn = 0x4540CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABALT);
#ifdef VEDA64_STRINGS
    std::cout << "  uabalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_uabd_z_p_zz_() {
    uint32_t insn = 0x040D0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABD);
#ifdef VEDA64_STRINGS
    std::cout << "  uabd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uabdlb_z_zz_() {
    uint32_t insn = 0x45403800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabdlb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABDLB);
#ifdef VEDA64_STRINGS
    std::cout << "  uabdlb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uabdlt_z_zz_() {
    uint32_t insn = 0x45403C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uabdlt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UABDLT);
#ifdef VEDA64_STRINGS
    std::cout << "  uabdlt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uadalp_z_p_z_() {
    uint32_t insn = 0x4445A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uadalp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADALP);
#ifdef VEDA64_STRINGS
    std::cout << "  uadalp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_uaddlb_z_zz_() {
    uint32_t insn = 0x45400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddlb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADDLB);
#ifdef VEDA64_STRINGS
    std::cout << "  uaddlb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uaddlt_z_zz_() {
    uint32_t insn = 0x45400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddlt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADDLT);
#ifdef VEDA64_STRINGS
    std::cout << "  uaddlt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uaddv_r_p_z_() {
    uint32_t insn = 0x04012000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADDV);
#ifdef VEDA64_STRINGS
    std::cout << "  uaddv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_uaddwb_z_zz_() {
    uint32_t insn = 0x45404800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddwb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADDWB);
#ifdef VEDA64_STRINGS
    std::cout << "  uaddwb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uaddwt_z_zz_() {
    uint32_t insn = 0x45404C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uaddwt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UADDWT);
#ifdef VEDA64_STRINGS
    std::cout << "  uaddwt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uclamp_z_zz_() {
    uint32_t insn = 0x4400C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uclamp_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCLAMP);
#ifdef VEDA64_STRINGS
    std::cout << "  uclamp_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_h2fp16() {
    uint32_t insn = 0x6553A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_h2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_h2fp16: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_h2fp16z() {
    uint32_t insn = 0x645CE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_h2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_h2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2fp16() {
    uint32_t insn = 0x6555A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2fp16: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2fp16z() {
    uint32_t insn = 0x645DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2s() {
    uint32_t insn = 0x6595A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2s: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2sz() {
    uint32_t insn = 0x649DA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2sz: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2d() {
    uint32_t insn = 0x65D1A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2d: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_w2dz() {
    uint32_t insn = 0x64DCA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_w2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_w2dz: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2fp16() {
    uint32_t insn = 0x6557A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2fp16" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2fp16: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2fp16z() {
    uint32_t insn = 0x645DE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2fp16z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2fp16z: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2s() {
    uint32_t insn = 0x65D5A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2s: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2sz() {
    uint32_t insn = 0x64DDA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2sz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2sz: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2d() {
    uint32_t insn = 0x65D7A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2d: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_p_z_x2dz() {
    uint32_t insn = 0x64DDE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_p_z_x2dz" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_p_z_x2dz: " << result->to_string() << std::endl;
#endif
}

void test_ucvtf_z_z_() {
    uint32_t insn = 0x654C3400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtf_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTF);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtf_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_ucvtflt_z_z_() {
    uint32_t insn = 0x654C3C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ucvtflt_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UCVTFLT);
#ifdef VEDA64_STRINGS
    std::cout << "  ucvtflt_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_udiv_z_p_zz_() {
    uint32_t insn = 0x04950000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udiv_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDIV);
#ifdef VEDA64_STRINGS
    std::cout << "  udiv_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_udivr_z_p_zz_() {
    uint32_t insn = 0x04970000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udivr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDIVR);
#ifdef VEDA64_STRINGS
    std::cout << "  udivr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_udot_z16_zzz_h() {
    uint32_t insn = 0x44400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z16_zzz_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z16_zzz_h: " << result->to_string() << std::endl;
#endif
}

void test_udot_z32_zzz_() {
    uint32_t insn = 0x4400CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z32_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z32_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_udot_z16_zzzi_h() {
    uint32_t insn = 0x44200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z16_zzzi_h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z16_zzzi_h: " << result->to_string() << std::endl;
#endif
}

void test_udot_z32_zzzi_() {
    uint32_t insn = 0x4480CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z32_zzzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z32_zzzi_: " << result->to_string() << std::endl;
#endif
}

void test_udot_z_zzz_() {
    uint32_t insn = 0x44800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_udot_z_zzzi_s() {
    uint32_t insn = 0x44A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_udot_z_zzzi_d() {
    uint32_t insn = 0x44E00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: udot_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  udot_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_uhadd_z_p_zz_() {
    uint32_t insn = 0x44118000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uhadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UHADD);
#ifdef VEDA64_STRINGS
    std::cout << "  uhadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uhsub_z_p_zz_() {
    uint32_t insn = 0x44138000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uhsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UHSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  uhsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uhsubr_z_p_zz_() {
    uint32_t insn = 0x44178000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uhsubr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UHSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  uhsubr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umax_z_p_zz_() {
    uint32_t insn = 0x04090000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umax_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  umax_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umax_z_zi_() {
    uint32_t insn = 0x2529C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umax_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAX);
#ifdef VEDA64_STRINGS
    std::cout << "  umax_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_umaxp_z_p_zz_() {
    uint32_t insn = 0x4415A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaxp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAXP);
#ifdef VEDA64_STRINGS
    std::cout << "  umaxp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umaxqv_z_p_z_() {
    uint32_t insn = 0x040D2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaxqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAXQV);
#ifdef VEDA64_STRINGS
    std::cout << "  umaxqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_umaxv_r_p_z_() {
    uint32_t insn = 0x04092000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umaxv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMAXV);
#ifdef VEDA64_STRINGS
    std::cout << "  umaxv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_umin_z_p_zz_() {
    uint32_t insn = 0x040B0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umin_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  umin_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umin_z_zi_() {
    uint32_t insn = 0x252BC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umin_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMIN);
#ifdef VEDA64_STRINGS
    std::cout << "  umin_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uminp_z_p_zz_() {
    uint32_t insn = 0x4417A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uminp_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMINP);
#ifdef VEDA64_STRINGS
    std::cout << "  uminp_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uminqv_z_p_z_() {
    uint32_t insn = 0x040F2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uminqv_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMINQV);
#ifdef VEDA64_STRINGS
    std::cout << "  uminqv_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_uminv_r_p_z_() {
    uint32_t insn = 0x040B2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uminv_r_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMINV);
#ifdef VEDA64_STRINGS
    std::cout << "  uminv_r_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_umlalb_z_zzz_() {
    uint32_t insn = 0x44404800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALB);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_umlalb_z_zzzi_s() {
    uint32_t insn = 0x44A09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umlalb_z_zzzi_d() {
    uint32_t insn = 0x44E09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_umlalt_z_zzz_() {
    uint32_t insn = 0x44404C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALT);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_umlalt_z_zzzi_s() {
    uint32_t insn = 0x44A09400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umlalt_z_zzzi_d() {
    uint32_t insn = 0x44E09400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlalt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLALT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlalt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_umlslb_z_zzz_() {
    uint32_t insn = 0x44405800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslb_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLB);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslb_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_umlslb_z_zzzi_s() {
    uint32_t insn = 0x44A0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslb_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslb_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umlslb_z_zzzi_d() {
    uint32_t insn = 0x44E0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslb_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslb_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_umlslt_z_zzz_() {
    uint32_t insn = 0x44405C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslt_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLT);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslt_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_umlslt_z_zzzi_s() {
    uint32_t insn = 0x44A0B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslt_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslt_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umlslt_z_zzzi_d() {
    uint32_t insn = 0x44E0B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umlslt_z_zzzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMLSLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umlslt_z_zzzi_d: " << result->to_string() << std::endl;
#endif
}

void test_ummla_z_zzz_() {
    uint32_t insn = 0x45C09800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ummla_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ummla_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_umulh_z_p_zz_() {
    uint32_t insn = 0x04130000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umulh_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  umulh_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umulh_z_zz_() {
    uint32_t insn = 0x04206C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umulh_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULH);
#ifdef VEDA64_STRINGS
    std::cout << "  umulh_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umullb_z_zz_() {
    uint32_t insn = 0x45407800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLB);
#ifdef VEDA64_STRINGS
    std::cout << "  umullb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umullb_z_zzi_s() {
    uint32_t insn = 0x44A0D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullb_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umullb_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umullb_z_zzi_d() {
    uint32_t insn = 0x44E0D000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullb_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umullb_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_umullt_z_zz_() {
    uint32_t insn = 0x45407C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLT);
#ifdef VEDA64_STRINGS
    std::cout << "  umullt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_umullt_z_zzi_s() {
    uint32_t insn = 0x44A0D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullt_z_zzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umullt_z_zzi_s: " << result->to_string() << std::endl;
#endif
}

void test_umullt_z_zzi_d() {
    uint32_t insn = 0x44E0D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: umullt_z_zzi_d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UMULLT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  umullt_z_zzi_d: " << result->to_string() << std::endl;
#endif
}

void test_uqadd_z_p_zz_() {
    uint32_t insn = 0x44198000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  uqadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqadd_z_zi_() {
    uint32_t insn = 0x2525C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqadd_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  uqadd_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqadd_z_zz_() {
    uint32_t insn = 0x04201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqadd_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  uqadd_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqcvtn_z_mz2_() {
    uint32_t insn = 0x45314800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqcvtn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqcvtn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_uqdecb_r_rs_uw() {
    uint32_t insn = 0x0420FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecb_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecb_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqdecb_r_rs_x() {
    uint32_t insn = 0x0430FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecb_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecb_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqdecd_r_rs_uw() {
    uint32_t insn = 0x04E0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecd_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecd_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqdecd_r_rs_x() {
    uint32_t insn = 0x04F0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecd_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecd_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqdecd_z_zs_() {
    uint32_t insn = 0x04E0CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqdech_r_rs_uw() {
    uint32_t insn = 0x0460FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdech_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdech_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqdech_r_rs_x() {
    uint32_t insn = 0x0470FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdech_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdech_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqdech_z_zs_() {
    uint32_t insn = 0x0460CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdech_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdech_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqdecp_r_p_r_uw() {
    uint32_t insn = 0x252B8800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecp_r_p_r_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecp_r_p_r_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqdecp_r_p_r_x() {
    uint32_t insn = 0x252B8C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecp_r_p_r_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecp_r_p_r_x: " << result->to_string() << std::endl;
#endif
}

void test_uqdecp_z_p_z_() {
    uint32_t insn = 0x256B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_uqdecw_r_rs_uw() {
    uint32_t insn = 0x04A0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecw_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecw_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqdecw_r_rs_x() {
    uint32_t insn = 0x04B0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecw_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecw_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqdecw_z_zs_() {
    uint32_t insn = 0x04A0CC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqdecw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQDECW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqdecw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqincb_r_rs_uw() {
    uint32_t insn = 0x0420F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincb_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincb_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqincb_r_rs_x() {
    uint32_t insn = 0x0430F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincb_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincb_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqincd_r_rs_uw() {
    uint32_t insn = 0x04E0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincd_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincd_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqincd_r_rs_x() {
    uint32_t insn = 0x04F0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincd_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincd_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqincd_z_zs_() {
    uint32_t insn = 0x04E0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincd_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincd_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqinch_r_rs_uw() {
    uint32_t insn = 0x0460F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqinch_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqinch_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqinch_r_rs_x() {
    uint32_t insn = 0x0470F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqinch_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqinch_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqinch_z_zs_() {
    uint32_t insn = 0x0460C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqinch_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqinch_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqincp_r_p_r_uw() {
    uint32_t insn = 0x25298800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincp_r_p_r_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincp_r_p_r_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqincp_r_p_r_x() {
    uint32_t insn = 0x25298C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincp_r_p_r_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincp_r_p_r_x: " << result->to_string() << std::endl;
#endif
}

void test_uqincp_z_p_z_() {
    uint32_t insn = 0x25698000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincp_z_p_z_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCP);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincp_z_p_z_: " << result->to_string() << std::endl;
#endif
}

void test_uqincw_r_rs_uw() {
    uint32_t insn = 0x04A0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincw_r_rs_uw" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincw_r_rs_uw: " << result->to_string() << std::endl;
#endif
}

void test_uqincw_r_rs_x() {
    uint32_t insn = 0x04B0F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincw_r_rs_x" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincw_r_rs_x: " << result->to_string() << std::endl;
#endif
}

void test_uqincw_z_zs_() {
    uint32_t insn = 0x04A0C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqincw_z_zs_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQINCW);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::RegisterList);
#ifdef VEDA64_STRINGS
    std::cout << "  uqincw_z_zs_: " << result->to_string() << std::endl;
#endif
}

void test_uqrshl_z_p_zz_() {
    uint32_t insn = 0x440B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqrshlr_z_p_zz_() {
    uint32_t insn = 0x440F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqrshrn_z_mz2_b() {
    uint32_t insn = 0x45A83800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrn_z_mz2_b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshrn_z_mz2_b: " << result->to_string() << std::endl;
#endif
}

void test_uqrshrn_z_mz2_() {
    uint32_t insn = 0x45B03800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshrn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_uqrshrnb_z_zi_() {
    uint32_t insn = 0x45203800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqrshrnt_z_zi_() {
    uint32_t insn = 0x45203C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqrshrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQRSHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  uqrshrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqshl_z_p_zi_() {
    uint32_t insn = 0x04078000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshl_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqshl_z_p_zz_() {
    uint32_t insn = 0x44098000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqshlr_z_p_zz_() {
    uint32_t insn = 0x440D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqshrn_z_mz2_() {
    uint32_t insn = 0x45A81000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshrn_z_mz2_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHRN);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshrn_z_mz2_: " << result->to_string() << std::endl;
#endif
}

void test_uqshrnb_z_zi_() {
    uint32_t insn = 0x45203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshrnb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHRNB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshrnb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqshrnt_z_zi_() {
    uint32_t insn = 0x45203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqshrnt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSHRNT);
#ifdef VEDA64_STRINGS
    std::cout << "  uqshrnt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqsub_z_p_zz_() {
    uint32_t insn = 0x441B8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsub_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqsub_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqsub_z_zi_() {
    uint32_t insn = 0x2527C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsub_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqsub_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_uqsub_z_zz_() {
    uint32_t insn = 0x04201C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsub_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSUB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqsub_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqsubr_z_p_zz_() {
    uint32_t insn = 0x441F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqsubr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQSUBR);
#ifdef VEDA64_STRINGS
    std::cout << "  uqsubr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqxtnb_z_zz_() {
    uint32_t insn = 0x45204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqxtnb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQXTNB);
#ifdef VEDA64_STRINGS
    std::cout << "  uqxtnb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uqxtnt_z_zz_() {
    uint32_t insn = 0x45204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uqxtnt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UQXTNT);
#ifdef VEDA64_STRINGS
    std::cout << "  uqxtnt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_urecpe_z_p_z_m() {
    uint32_t insn = 0x4480A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urecpe_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URECPE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  urecpe_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_urecpe_z_p_z_z() {
    uint32_t insn = 0x4482A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urecpe_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URECPE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  urecpe_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_urhadd_z_p_zz_() {
    uint32_t insn = 0x44158000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urhadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URHADD);
#ifdef VEDA64_STRINGS
    std::cout << "  urhadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_urshl_z_p_zz_() {
    uint32_t insn = 0x44038000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshl_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSHL);
#ifdef VEDA64_STRINGS
    std::cout << "  urshl_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_urshlr_z_p_zz_() {
    uint32_t insn = 0x44078000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshlr_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSHLR);
#ifdef VEDA64_STRINGS
    std::cout << "  urshlr_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_urshr_z_p_zi_() {
    uint32_t insn = 0x040D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: urshr_z_p_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSHR);
#ifdef VEDA64_STRINGS
    std::cout << "  urshr_z_p_zi_: " << result->to_string() << std::endl;
#endif
}

void test_ursqrte_z_p_z_m() {
    uint32_t insn = 0x4481A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursqrte_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSQRTE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ursqrte_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_ursqrte_z_p_z_z() {
    uint32_t insn = 0x4483A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursqrte_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSQRTE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  ursqrte_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_ursra_z_zi_() {
    uint32_t insn = 0x4500EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ursra_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::URSRA);
#ifdef VEDA64_STRINGS
    std::cout << "  ursra_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_usdot_z_zzz_s() {
    uint32_t insn = 0x44807800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usdot_z_zzz_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  usdot_z_zzz_s: " << result->to_string() << std::endl;
#endif
}

void test_usdot_z_zzzi_s() {
    uint32_t insn = 0x44A01800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usdot_z_zzzi_s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  usdot_z_zzzi_s: " << result->to_string() << std::endl;
#endif
}

void test_ushllb_z_zi_() {
    uint32_t insn = 0x4500A800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushllb_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USHLLB);
#ifdef VEDA64_STRINGS
    std::cout << "  ushllb_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_ushllt_z_zi_() {
    uint32_t insn = 0x4500AC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ushllt_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USHLLT);
#ifdef VEDA64_STRINGS
    std::cout << "  ushllt_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_usmmla_z_zzz_() {
    uint32_t insn = 0x45809800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usmmla_z_zzz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USMMLA);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  usmmla_z_zzz_: " << result->to_string() << std::endl;
#endif
}

void test_usqadd_z_p_zz_() {
    uint32_t insn = 0x441D8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usqadd_z_p_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USQADD);
#ifdef VEDA64_STRINGS
    std::cout << "  usqadd_z_p_zz_: " << result->to_string() << std::endl;
#endif
}

void test_usra_z_zi_() {
    uint32_t insn = 0x4500E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usra_z_zi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USRA);
#ifdef VEDA64_STRINGS
    std::cout << "  usra_z_zi_: " << result->to_string() << std::endl;
#endif
}

void test_usublb_z_zz_() {
    uint32_t insn = 0x45401800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usublb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USUBLB);
#ifdef VEDA64_STRINGS
    std::cout << "  usublb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_usublt_z_zz_() {
    uint32_t insn = 0x45401C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usublt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USUBLT);
#ifdef VEDA64_STRINGS
    std::cout << "  usublt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_usubwb_z_zz_() {
    uint32_t insn = 0x45405800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usubwb_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USUBWB);
#ifdef VEDA64_STRINGS
    std::cout << "  usubwb_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_usubwt_z_zz_() {
    uint32_t insn = 0x45405C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: usubwt_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::USUBWT);
#ifdef VEDA64_STRINGS
    std::cout << "  usubwt_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uunpkhi_z_z_() {
    uint32_t insn = 0x05733800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uunpkhi_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uunpkhi_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_uunpklo_z_z_() {
    uint32_t insn = 0x05723800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uunpklo_z_z_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uunpklo_z_z_: " << result->to_string() << std::endl;
#endif
}

void test_uxtb_z_p_z_m() {
    uint32_t insn = 0x0451A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxtb_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uxtb_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_uxtb_z_p_z_z() {
    uint32_t insn = 0x0441A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxtb_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uxtb_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_uxth_z_p_z_m() {
    uint32_t insn = 0x0493A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxth_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uxth_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_uxth_z_p_z_z() {
    uint32_t insn = 0x0483A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxth_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uxth_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_uxtw_z_p_z_m() {
    uint32_t insn = 0x04D5A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxtw_z_p_z_m" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  uxtw_z_p_z_m: " << result->to_string() << std::endl;
#endif
}

void test_uxtw_z_p_z_z() {
    uint32_t insn = 0x04C5A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uxtw_z_p_z_z" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  uxtw_z_p_z_z: " << result->to_string() << std::endl;
#endif
}

void test_uzp1_p_pp_() {
    uint32_t insn = 0x05204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp1_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uzp1_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_uzp2_p_pp_() {
    uint32_t insn = 0x05204C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp2_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uzp2_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_uzp1_z_zz_() {
    uint32_t insn = 0x05206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uzp1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uzp1_z_zz_q() {
    uint32_t insn = 0x05A00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp1_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  uzp1_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_uzp2_z_zz_() {
    uint32_t insn = 0x05206C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp2_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  uzp2_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uzp2_z_zz_q() {
    uint32_t insn = 0x05A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzp2_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  uzp2_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_uzpq1_z_zz_() {
    uint32_t insn = 0x4400E800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzpq1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UZPQ1);
#ifdef VEDA64_STRINGS
    std::cout << "  uzpq1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_uzpq2_z_zz_() {
    uint32_t insn = 0x4400EC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: uzpq2_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::UZPQ2);
#ifdef VEDA64_STRINGS
    std::cout << "  uzpq2_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_whilege_p_p_rr_() {
    uint32_t insn = 0x25200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilege_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGE);
#ifdef VEDA64_STRINGS
    std::cout << "  whilege_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilege_pn_rr_() {
    uint32_t insn = 0x25204010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilege_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGE);
#ifdef VEDA64_STRINGS
    std::cout << "  whilege_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilege_pp_rr_() {
    uint32_t insn = 0x25205010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilege_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilege_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilegt_p_p_rr_() {
    uint32_t insn = 0x25200010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilegt_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGT);
#ifdef VEDA64_STRINGS
    std::cout << "  whilegt_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilegt_pn_rr_() {
    uint32_t insn = 0x25204018u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilegt_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGT);
#ifdef VEDA64_STRINGS
    std::cout << "  whilegt_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilegt_pp_rr_() {
    uint32_t insn = 0x25205011u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilegt_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEGT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilegt_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehi_p_p_rr_() {
    uint32_t insn = 0x25200810u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehi_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHI);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehi_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehi_pn_rr_() {
    uint32_t insn = 0x25204818u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehi_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHI);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehi_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehi_pp_rr_() {
    uint32_t insn = 0x25205811u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehi_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHI);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehi_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehs_p_p_rr_() {
    uint32_t insn = 0x25200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehs_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHS);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehs_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehs_pn_rr_() {
    uint32_t insn = 0x25204810u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehs_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHS);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehs_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilehs_pp_rr_() {
    uint32_t insn = 0x25205810u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilehs_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEHS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilehs_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilele_p_p_rr_() {
    uint32_t insn = 0x25200410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilele_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELE);
#ifdef VEDA64_STRINGS
    std::cout << "  whilele_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilele_pn_rr_() {
    uint32_t insn = 0x25204418u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilele_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELE);
#ifdef VEDA64_STRINGS
    std::cout << "  whilele_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilele_pp_rr_() {
    uint32_t insn = 0x25205411u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilele_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELE);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilele_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelo_p_p_rr_() {
    uint32_t insn = 0x25200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelo_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELO);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelo_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelo_pn_rr_() {
    uint32_t insn = 0x25204C10u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelo_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELO);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelo_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelo_pp_rr_() {
    uint32_t insn = 0x25205C10u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelo_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELO);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelo_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilels_p_p_rr_() {
    uint32_t insn = 0x25200C10u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilels_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELS);
#ifdef VEDA64_STRINGS
    std::cout << "  whilels_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilels_pn_rr_() {
    uint32_t insn = 0x25204C18u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilels_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELS);
#ifdef VEDA64_STRINGS
    std::cout << "  whilels_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilels_pp_rr_() {
    uint32_t insn = 0x25205C11u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilels_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELS);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilels_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelt_p_p_rr_() {
    uint32_t insn = 0x25200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelt_p_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELT);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelt_p_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelt_pn_rr_() {
    uint32_t insn = 0x25204410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelt_pn_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELT);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelt_pn_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilelt_pp_rr_() {
    uint32_t insn = 0x25205410u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilelt_pp_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILELT);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  whilelt_pp_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilerw_p_rr_() {
    uint32_t insn = 0x25203010u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilerw_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILERW);
#ifdef VEDA64_STRINGS
    std::cout << "  whilerw_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_whilewr_p_rr_() {
    uint32_t insn = 0x25203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: whilewr_p_rr_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WHILEWR);
#ifdef VEDA64_STRINGS
    std::cout << "  whilewr_p_rr_: " << result->to_string() << std::endl;
#endif
}

void test_wrffr_f_p_() {
    uint32_t insn = 0x25289000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: wrffr_f_p_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::WRFFR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  wrffr_f_p_: " << result->to_string() << std::endl;
#endif
}

void test_xar_z_zzi_() {
    uint32_t insn = 0x04203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: xar_z_zzi_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::XAR);
#ifdef VEDA64_STRINGS
    std::cout << "  xar_z_zzi_: " << result->to_string() << std::endl;
#endif
}

void test_zip2_p_pp_() {
    uint32_t insn = 0x05204400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip2_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  zip2_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_zip1_p_pp_() {
    uint32_t insn = 0x05204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip1_p_pp_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  zip1_p_pp_: " << result->to_string() << std::endl;
#endif
}

void test_zip2_z_zz_() {
    uint32_t insn = 0x05206400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip2_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  zip2_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_zip2_z_zz_q() {
    uint32_t insn = 0x05A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip2_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  zip2_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_zip1_z_zz_() {
    uint32_t insn = 0x05206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
#ifdef VEDA64_STRINGS
    std::cout << "  zip1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_zip1_z_zz_q() {
    uint32_t insn = 0x05A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zip1_z_zz_q" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
#ifdef VEDA64_STRINGS
    std::cout << "  zip1_z_zz_q: " << result->to_string() << std::endl;
#endif
}

void test_zipq1_z_zz_() {
    uint32_t insn = 0x4400E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zipq1_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ZIPQ1);
#ifdef VEDA64_STRINGS
    std::cout << "  zipq1_z_zz_: " << result->to_string() << std::endl;
#endif
}

void test_zipq2_z_zz_() {
    uint32_t insn = 0x4400E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: zipq2_z_zz_" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ZIPQ2);
#ifdef VEDA64_STRINGS
    std::cout << "  zipq2_z_zz_: " << result->to_string() << std::endl;
#endif
}

int main() {
    std::cout << "Running sve encoding tests (1361 encodings)..." << std::endl;
    int failed = 0;

    try { test_abs_z_p_z_m(); } catch (...) { std::cerr << "FAIL: abs_z_p_z_m" << std::endl; failed++; }
    try { test_abs_z_p_z_z(); } catch (...) { std::cerr << "FAIL: abs_z_p_z_z" << std::endl; failed++; }
    try { test_adclb_z_zzz_(); } catch (...) { std::cerr << "FAIL: adclb_z_zzz_" << std::endl; failed++; }
    try { test_adclt_z_zzz_(); } catch (...) { std::cerr << "FAIL: adclt_z_zzz_" << std::endl; failed++; }
    try { test_add_z_p_zz_(); } catch (...) { std::cerr << "FAIL: add_z_p_zz_" << std::endl; failed++; }
    try { test_add_z_zi_(); } catch (...) { std::cerr << "FAIL: add_z_zi_" << std::endl; failed++; }
    try { test_add_z_zz_(); } catch (...) { std::cerr << "FAIL: add_z_zz_" << std::endl; failed++; }
    try { test_addhnb_z_zz_(); } catch (...) { std::cerr << "FAIL: addhnb_z_zz_" << std::endl; failed++; }
    try { test_addhnt_z_zz_(); } catch (...) { std::cerr << "FAIL: addhnt_z_zz_" << std::endl; failed++; }
    try { test_addp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: addp_z_p_zz_" << std::endl; failed++; }
    try { test_addpl_r_ri_(); } catch (...) { std::cerr << "FAIL: addpl_r_ri_" << std::endl; failed++; }
    try { test_addpt_z_p_zz_(); } catch (...) { std::cerr << "FAIL: addpt_z_p_zz_" << std::endl; failed++; }
    try { test_addpt_z_zz_(); } catch (...) { std::cerr << "FAIL: addpt_z_zz_" << std::endl; failed++; }
    try { test_addqp_z_zz_(); } catch (...) { std::cerr << "FAIL: addqp_z_zz_" << std::endl; failed++; }
    try { test_addqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: addqv_z_p_z_" << std::endl; failed++; }
    try { test_addspl_r_ri_(); } catch (...) { std::cerr << "FAIL: addspl_r_ri_" << std::endl; failed++; }
    try { test_addsubp_z_zz_(); } catch (...) { std::cerr << "FAIL: addsubp_z_zz_" << std::endl; failed++; }
    try { test_addsvl_r_ri_(); } catch (...) { std::cerr << "FAIL: addsvl_r_ri_" << std::endl; failed++; }
    try { test_addvl_r_ri_(); } catch (...) { std::cerr << "FAIL: addvl_r_ri_" << std::endl; failed++; }
    try { test_adr_z_az_sd_same_scaled(); } catch (...) { std::cerr << "FAIL: adr_z_az_sd_same_scaled" << std::endl; failed++; }
    try { test_adr_z_az_d_s32_scaled(); } catch (...) { std::cerr << "FAIL: adr_z_az_d_s32_scaled" << std::endl; failed++; }
    try { test_adr_z_az_d_u32_scaled(); } catch (...) { std::cerr << "FAIL: adr_z_az_d_u32_scaled" << std::endl; failed++; }
    try { test_aesd_mz_zzi_2x1(); } catch (...) { std::cerr << "FAIL: aesd_mz_zzi_2x1" << std::endl; failed++; }
    try { test_aesd_mz_zzi_4x1(); } catch (...) { std::cerr << "FAIL: aesd_mz_zzi_4x1" << std::endl; failed++; }
    try { test_aesd_z_zz_(); } catch (...) { std::cerr << "FAIL: aesd_z_zz_" << std::endl; failed++; }
    try { test_aesdimc_mz_zzi_2x1(); } catch (...) { std::cerr << "FAIL: aesdimc_mz_zzi_2x1" << std::endl; failed++; }
    try { test_aesdimc_mz_zzi_4x1(); } catch (...) { std::cerr << "FAIL: aesdimc_mz_zzi_4x1" << std::endl; failed++; }
    try { test_aese_mz_zzi_2x1(); } catch (...) { std::cerr << "FAIL: aese_mz_zzi_2x1" << std::endl; failed++; }
    try { test_aese_mz_zzi_4x1(); } catch (...) { std::cerr << "FAIL: aese_mz_zzi_4x1" << std::endl; failed++; }
    try { test_aese_z_zz_(); } catch (...) { std::cerr << "FAIL: aese_z_zz_" << std::endl; failed++; }
    try { test_aesemc_mz_zzi_2x1(); } catch (...) { std::cerr << "FAIL: aesemc_mz_zzi_2x1" << std::endl; failed++; }
    try { test_aesemc_mz_zzi_4x1(); } catch (...) { std::cerr << "FAIL: aesemc_mz_zzi_4x1" << std::endl; failed++; }
    try { test_aesimc_z_z_(); } catch (...) { std::cerr << "FAIL: aesimc_z_z_" << std::endl; failed++; }
    try { test_aesmc_z_z_(); } catch (...) { std::cerr << "FAIL: aesmc_z_z_" << std::endl; failed++; }
    try { test_and_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: and_p_p_pp_z" << std::endl; failed++; }
    try { test_and_z_p_zz_(); } catch (...) { std::cerr << "FAIL: and_z_p_zz_" << std::endl; failed++; }
    try { test_and_z_zi_(); } catch (...) { std::cerr << "FAIL: and_z_zi_" << std::endl; failed++; }
    try { test_and_z_zz_(); } catch (...) { std::cerr << "FAIL: and_z_zz_" << std::endl; failed++; }
    try { test_andqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: andqv_z_p_z_" << std::endl; failed++; }
    try { test_ands_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: ands_p_p_pp_z" << std::endl; failed++; }
    try { test_andv_r_p_z_(); } catch (...) { std::cerr << "FAIL: andv_r_p_z_" << std::endl; failed++; }
    try { test_asr_z_p_zi_(); } catch (...) { std::cerr << "FAIL: asr_z_p_zi_" << std::endl; failed++; }
    try { test_asr_z_p_zw_(); } catch (...) { std::cerr << "FAIL: asr_z_p_zw_" << std::endl; failed++; }
    try { test_asr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: asr_z_p_zz_" << std::endl; failed++; }
    try { test_asr_z_zi_(); } catch (...) { std::cerr << "FAIL: asr_z_zi_" << std::endl; failed++; }
    try { test_asr_z_zw_(); } catch (...) { std::cerr << "FAIL: asr_z_zw_" << std::endl; failed++; }
    try { test_asrd_z_p_zi_(); } catch (...) { std::cerr << "FAIL: asrd_z_p_zi_" << std::endl; failed++; }
    try { test_asrr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: asrr_z_p_zz_" << std::endl; failed++; }
    try { test_bcax_z_zzz_(); } catch (...) { std::cerr << "FAIL: bcax_z_zzz_" << std::endl; failed++; }
    try { test_bdep_z_zz_(); } catch (...) { std::cerr << "FAIL: bdep_z_zz_" << std::endl; failed++; }
    try { test_bext_z_zz_(); } catch (...) { std::cerr << "FAIL: bext_z_zz_" << std::endl; failed++; }
    try { test_bf1cvt_z_z8_b2bf(); } catch (...) { std::cerr << "FAIL: bf1cvt_z_z8_b2bf" << std::endl; failed++; }
    try { test_bf2cvt_z_z8_b2bf(); } catch (...) { std::cerr << "FAIL: bf2cvt_z_z8_b2bf" << std::endl; failed++; }
    try { test_bf1cvtlt_z_z8_b2bf(); } catch (...) { std::cerr << "FAIL: bf1cvtlt_z_z8_b2bf" << std::endl; failed++; }
    try { test_bf2cvtlt_z_z8_b2bf(); } catch (...) { std::cerr << "FAIL: bf2cvtlt_z_z8_b2bf" << std::endl; failed++; }
    try { test_bfadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfadd_z_p_zz_" << std::endl; failed++; }
    try { test_bfadd_z_zz_(); } catch (...) { std::cerr << "FAIL: bfadd_z_zz_" << std::endl; failed++; }
    try { test_bfclamp_z_zz_(); } catch (...) { std::cerr << "FAIL: bfclamp_z_zz_" << std::endl; failed++; }
    try { test_bfcvt_z_p_z_s2bf(); } catch (...) { std::cerr << "FAIL: bfcvt_z_p_z_s2bf" << std::endl; failed++; }
    try { test_bfcvt_z_p_z_s2bfz(); } catch (...) { std::cerr << "FAIL: bfcvt_z_p_z_s2bfz" << std::endl; failed++; }
    try { test_bfcvtn_z8_mz2_bf2b(); } catch (...) { std::cerr << "FAIL: bfcvtn_z8_mz2_bf2b" << std::endl; failed++; }
    try { test_bfcvtnt_z_p_z_s2bf(); } catch (...) { std::cerr << "FAIL: bfcvtnt_z_p_z_s2bf" << std::endl; failed++; }
    try { test_bfcvtnt_z_p_z_s2bfz(); } catch (...) { std::cerr << "FAIL: bfcvtnt_z_p_z_s2bfz" << std::endl; failed++; }
    try { test_bfdot_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfdot_z_zzz_" << std::endl; failed++; }
    try { test_bfdot_z_zzzi_(); } catch (...) { std::cerr << "FAIL: bfdot_z_zzzi_" << std::endl; failed++; }
    try { test_bfmax_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfmax_z_p_zz_" << std::endl; failed++; }
    try { test_bfmaxnm_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfmaxnm_z_p_zz_" << std::endl; failed++; }
    try { test_bfmin_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfmin_z_p_zz_" << std::endl; failed++; }
    try { test_bfminnm_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfminnm_z_p_zz_" << std::endl; failed++; }
    try { test_bfmla_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: bfmla_z_p_zzz_" << std::endl; failed++; }
    try { test_bfmla_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: bfmla_z_zzzi_h" << std::endl; failed++; }
    try { test_bfmlalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfmlalb_z_zzz_" << std::endl; failed++; }
    try { test_bfmlalb_z_zzzi_(); } catch (...) { std::cerr << "FAIL: bfmlalb_z_zzzi_" << std::endl; failed++; }
    try { test_bfmlalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfmlalt_z_zzz_" << std::endl; failed++; }
    try { test_bfmlalt_z_zzzi_(); } catch (...) { std::cerr << "FAIL: bfmlalt_z_zzzi_" << std::endl; failed++; }
    try { test_bfmls_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: bfmls_z_p_zzz_" << std::endl; failed++; }
    try { test_bfmls_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: bfmls_z_zzzi_h" << std::endl; failed++; }
    try { test_bfmlslb_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfmlslb_z_zzz_" << std::endl; failed++; }
    try { test_bfmlslb_z_zzzi_(); } catch (...) { std::cerr << "FAIL: bfmlslb_z_zzzi_" << std::endl; failed++; }
    try { test_bfmlslt_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfmlslt_z_zzz_" << std::endl; failed++; }
    try { test_bfmlslt_z_zzzi_(); } catch (...) { std::cerr << "FAIL: bfmlslt_z_zzzi_" << std::endl; failed++; }
    try { test_bfmmla_z_zzz_h(); } catch (...) { std::cerr << "FAIL: bfmmla_z_zzz_h" << std::endl; failed++; }
    try { test_bfmmla_z_zzz_(); } catch (...) { std::cerr << "FAIL: bfmmla_z_zzz_" << std::endl; failed++; }
    try { test_bfmul_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfmul_z_p_zz_" << std::endl; failed++; }
    try { test_bfmul_z_zz_(); } catch (...) { std::cerr << "FAIL: bfmul_z_zz_" << std::endl; failed++; }
    try { test_bfmul_z_zzi_h(); } catch (...) { std::cerr << "FAIL: bfmul_z_zzi_h" << std::endl; failed++; }
    try { test_bfscale_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfscale_z_p_zz_" << std::endl; failed++; }
    try { test_bfsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bfsub_z_p_zz_" << std::endl; failed++; }
    try { test_bfsub_z_zz_(); } catch (...) { std::cerr << "FAIL: bfsub_z_zz_" << std::endl; failed++; }
    try { test_bgrp_z_zz_(); } catch (...) { std::cerr << "FAIL: bgrp_z_zz_" << std::endl; failed++; }
    try { test_bic_z_zi__and_z_zi_(); } catch (...) { std::cerr << "FAIL: bic_z_zi__and_z_zi_" << std::endl; failed++; }
    try { test_bic_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: bic_p_p_pp_z" << std::endl; failed++; }
    try { test_bic_z_p_zz_(); } catch (...) { std::cerr << "FAIL: bic_z_p_zz_" << std::endl; failed++; }
    try { test_bic_z_zz_(); } catch (...) { std::cerr << "FAIL: bic_z_zz_" << std::endl; failed++; }
    try { test_bics_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: bics_p_p_pp_z" << std::endl; failed++; }
    try { test_brka_p_p_p_(); } catch (...) { std::cerr << "FAIL: brka_p_p_p_" << std::endl; failed++; }
    try { test_brkas_p_p_p_z(); } catch (...) { std::cerr << "FAIL: brkas_p_p_p_z" << std::endl; failed++; }
    try { test_brkb_p_p_p_(); } catch (...) { std::cerr << "FAIL: brkb_p_p_p_" << std::endl; failed++; }
    try { test_brkbs_p_p_p_z(); } catch (...) { std::cerr << "FAIL: brkbs_p_p_p_z" << std::endl; failed++; }
    try { test_brkn_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkn_p_p_pp_" << std::endl; failed++; }
    try { test_brkns_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkns_p_p_pp_" << std::endl; failed++; }
    try { test_brkpa_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkpa_p_p_pp_" << std::endl; failed++; }
    try { test_brkpas_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkpas_p_p_pp_" << std::endl; failed++; }
    try { test_brkpb_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkpb_p_p_pp_" << std::endl; failed++; }
    try { test_brkpbs_p_p_pp_(); } catch (...) { std::cerr << "FAIL: brkpbs_p_p_pp_" << std::endl; failed++; }
    try { test_bsl1n_z_zzz_(); } catch (...) { std::cerr << "FAIL: bsl1n_z_zzz_" << std::endl; failed++; }
    try { test_bsl2n_z_zzz_(); } catch (...) { std::cerr << "FAIL: bsl2n_z_zzz_" << std::endl; failed++; }
    try { test_bsl_z_zzz_(); } catch (...) { std::cerr << "FAIL: bsl_z_zzz_" << std::endl; failed++; }
    try { test_cadd_z_zz_(); } catch (...) { std::cerr << "FAIL: cadd_z_zz_" << std::endl; failed++; }
    try { test_cdot_z_zzz_(); } catch (...) { std::cerr << "FAIL: cdot_z_zzz_" << std::endl; failed++; }
    try { test_cdot_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: cdot_z_zzzi_s" << std::endl; failed++; }
    try { test_cdot_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: cdot_z_zzzi_d" << std::endl; failed++; }
    try { test_clasta_r_p_z_(); } catch (...) { std::cerr << "FAIL: clasta_r_p_z_" << std::endl; failed++; }
    try { test_clasta_v_p_z_(); } catch (...) { std::cerr << "FAIL: clasta_v_p_z_" << std::endl; failed++; }
    try { test_clasta_z_p_zz_(); } catch (...) { std::cerr << "FAIL: clasta_z_p_zz_" << std::endl; failed++; }
    try { test_clastb_r_p_z_(); } catch (...) { std::cerr << "FAIL: clastb_r_p_z_" << std::endl; failed++; }
    try { test_clastb_v_p_z_(); } catch (...) { std::cerr << "FAIL: clastb_v_p_z_" << std::endl; failed++; }
    try { test_clastb_z_p_zz_(); } catch (...) { std::cerr << "FAIL: clastb_z_p_zz_" << std::endl; failed++; }
    try { test_cls_z_p_z_m(); } catch (...) { std::cerr << "FAIL: cls_z_p_z_m" << std::endl; failed++; }
    try { test_cls_z_p_z_z(); } catch (...) { std::cerr << "FAIL: cls_z_p_z_z" << std::endl; failed++; }
    try { test_clz_z_p_z_m(); } catch (...) { std::cerr << "FAIL: clz_z_p_z_m" << std::endl; failed++; }
    try { test_clz_z_p_z_z(); } catch (...) { std::cerr << "FAIL: clz_z_p_z_z" << std::endl; failed++; }
    try { test_cmla_z_zzz_(); } catch (...) { std::cerr << "FAIL: cmla_z_zzz_" << std::endl; failed++; }
    try { test_cmla_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: cmla_z_zzzi_h" << std::endl; failed++; }
    try { test_cmla_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: cmla_z_zzzi_s" << std::endl; failed++; }
    try { test_cmpeq_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmpeq_p_p_zi_" << std::endl; failed++; }
    try { test_cmpgt_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmpgt_p_p_zi_" << std::endl; failed++; }
    try { test_cmpge_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmpge_p_p_zi_" << std::endl; failed++; }
    try { test_cmphi_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmphi_p_p_zi_" << std::endl; failed++; }
    try { test_cmphs_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmphs_p_p_zi_" << std::endl; failed++; }
    try { test_cmplt_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmplt_p_p_zi_" << std::endl; failed++; }
    try { test_cmple_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmple_p_p_zi_" << std::endl; failed++; }
    try { test_cmplo_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmplo_p_p_zi_" << std::endl; failed++; }
    try { test_cmpls_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmpls_p_p_zi_" << std::endl; failed++; }
    try { test_cmpne_p_p_zi_(); } catch (...) { std::cerr << "FAIL: cmpne_p_p_zi_" << std::endl; failed++; }
    try { test_cmpeq_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmpeq_p_p_zw_" << std::endl; failed++; }
    try { test_cmpgt_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmpgt_p_p_zw_" << std::endl; failed++; }
    try { test_cmpge_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmpge_p_p_zw_" << std::endl; failed++; }
    try { test_cmphi_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmphi_p_p_zw_" << std::endl; failed++; }
    try { test_cmphs_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmphs_p_p_zw_" << std::endl; failed++; }
    try { test_cmplt_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmplt_p_p_zw_" << std::endl; failed++; }
    try { test_cmple_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmple_p_p_zw_" << std::endl; failed++; }
    try { test_cmplo_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmplo_p_p_zw_" << std::endl; failed++; }
    try { test_cmpls_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmpls_p_p_zw_" << std::endl; failed++; }
    try { test_cmpne_p_p_zw_(); } catch (...) { std::cerr << "FAIL: cmpne_p_p_zw_" << std::endl; failed++; }
    try { test_cmpeq_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmpeq_p_p_zz_" << std::endl; failed++; }
    try { test_cmpgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmpgt_p_p_zz_" << std::endl; failed++; }
    try { test_cmpge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmpge_p_p_zz_" << std::endl; failed++; }
    try { test_cmphi_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmphi_p_p_zz_" << std::endl; failed++; }
    try { test_cmphs_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmphs_p_p_zz_" << std::endl; failed++; }
    try { test_cmpne_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmpne_p_p_zz_" << std::endl; failed++; }
    try { test_cmple_p_p_zz__cmpge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmple_p_p_zz__cmpge_p_p_zz_" << std::endl; failed++; }
    try { test_cmplo_p_p_zz__cmphi_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmplo_p_p_zz__cmphi_p_p_zz_" << std::endl; failed++; }
    try { test_cmpls_p_p_zz__cmphs_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmpls_p_p_zz__cmphs_p_p_zz_" << std::endl; failed++; }
    try { test_cmplt_p_p_zz__cmpgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: cmplt_p_p_zz__cmpgt_p_p_zz_" << std::endl; failed++; }
    try { test_cnot_z_p_z_m(); } catch (...) { std::cerr << "FAIL: cnot_z_p_z_m" << std::endl; failed++; }
    try { test_cnot_z_p_z_z(); } catch (...) { std::cerr << "FAIL: cnot_z_p_z_z" << std::endl; failed++; }
    try { test_cnt_z_p_z_m(); } catch (...) { std::cerr << "FAIL: cnt_z_p_z_m" << std::endl; failed++; }
    try { test_cnt_z_p_z_z(); } catch (...) { std::cerr << "FAIL: cnt_z_p_z_z" << std::endl; failed++; }
    try { test_cntb_r_s_(); } catch (...) { std::cerr << "FAIL: cntb_r_s_" << std::endl; failed++; }
    try { test_cntd_r_s_(); } catch (...) { std::cerr << "FAIL: cntd_r_s_" << std::endl; failed++; }
    try { test_cnth_r_s_(); } catch (...) { std::cerr << "FAIL: cnth_r_s_" << std::endl; failed++; }
    try { test_cntw_r_s_(); } catch (...) { std::cerr << "FAIL: cntw_r_s_" << std::endl; failed++; }
    try { test_cntp_r_p_p_(); } catch (...) { std::cerr << "FAIL: cntp_r_p_p_" << std::endl; failed++; }
    try { test_cntp_r_pn_(); } catch (...) { std::cerr << "FAIL: cntp_r_pn_" << std::endl; failed++; }
    try { test_compact_z_p_z_s(); } catch (...) { std::cerr << "FAIL: compact_z_p_z_s" << std::endl; failed++; }
    try { test_compact_z_p_z_(); } catch (...) { std::cerr << "FAIL: compact_z_p_z_" << std::endl; failed++; }
    try { test_cpy_z_o_i_(); } catch (...) { std::cerr << "FAIL: cpy_z_o_i_" << std::endl; failed++; }
    try { test_cpy_z_p_i_(); } catch (...) { std::cerr << "FAIL: cpy_z_p_i_" << std::endl; failed++; }
    try { test_cpy_z_p_r_(); } catch (...) { std::cerr << "FAIL: cpy_z_p_r_" << std::endl; failed++; }
    try { test_cpy_z_p_v_(); } catch (...) { std::cerr << "FAIL: cpy_z_p_v_" << std::endl; failed++; }
    try { test_ctermeq_rr_(); } catch (...) { std::cerr << "FAIL: ctermeq_rr_" << std::endl; failed++; }
    try { test_ctermne_rr_(); } catch (...) { std::cerr << "FAIL: ctermne_rr_" << std::endl; failed++; }
    try { test_decb_r_rs_(); } catch (...) { std::cerr << "FAIL: decb_r_rs_" << std::endl; failed++; }
    try { test_decd_r_rs_(); } catch (...) { std::cerr << "FAIL: decd_r_rs_" << std::endl; failed++; }
    try { test_dech_r_rs_(); } catch (...) { std::cerr << "FAIL: dech_r_rs_" << std::endl; failed++; }
    try { test_decw_r_rs_(); } catch (...) { std::cerr << "FAIL: decw_r_rs_" << std::endl; failed++; }
    try { test_decd_z_zs_(); } catch (...) { std::cerr << "FAIL: decd_z_zs_" << std::endl; failed++; }
    try { test_dech_z_zs_(); } catch (...) { std::cerr << "FAIL: dech_z_zs_" << std::endl; failed++; }
    try { test_decw_z_zs_(); } catch (...) { std::cerr << "FAIL: decw_z_zs_" << std::endl; failed++; }
    try { test_decp_r_p_r_(); } catch (...) { std::cerr << "FAIL: decp_r_p_r_" << std::endl; failed++; }
    try { test_decp_z_p_z_(); } catch (...) { std::cerr << "FAIL: decp_z_p_z_" << std::endl; failed++; }
    try { test_dup_z_i_(); } catch (...) { std::cerr << "FAIL: dup_z_i_" << std::endl; failed++; }
    try { test_dup_z_r_(); } catch (...) { std::cerr << "FAIL: dup_z_r_" << std::endl; failed++; }
    try { test_dup_z_zi_(); } catch (...) { std::cerr << "FAIL: dup_z_zi_" << std::endl; failed++; }
    try { test_dupm_z_i_(); } catch (...) { std::cerr << "FAIL: dupm_z_i_" << std::endl; failed++; }
    try { test_dupq_z_zi_(); } catch (...) { std::cerr << "FAIL: dupq_z_zi_" << std::endl; failed++; }
    try { test_eon_z_zi__eor_z_zi_(); } catch (...) { std::cerr << "FAIL: eon_z_zi__eor_z_zi_" << std::endl; failed++; }
    try { test_eor3_z_zzz_(); } catch (...) { std::cerr << "FAIL: eor3_z_zzz_" << std::endl; failed++; }
    try { test_eor_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: eor_p_p_pp_z" << std::endl; failed++; }
    try { test_eor_z_p_zz_(); } catch (...) { std::cerr << "FAIL: eor_z_p_zz_" << std::endl; failed++; }
    try { test_eor_z_zi_(); } catch (...) { std::cerr << "FAIL: eor_z_zi_" << std::endl; failed++; }
    try { test_eor_z_zz_(); } catch (...) { std::cerr << "FAIL: eor_z_zz_" << std::endl; failed++; }
    try { test_eorbt_z_zz_(); } catch (...) { std::cerr << "FAIL: eorbt_z_zz_" << std::endl; failed++; }
    try { test_eorqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: eorqv_z_p_z_" << std::endl; failed++; }
    try { test_eors_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: eors_p_p_pp_z" << std::endl; failed++; }
    try { test_eortb_z_zz_(); } catch (...) { std::cerr << "FAIL: eortb_z_zz_" << std::endl; failed++; }
    try { test_eorv_r_p_z_(); } catch (...) { std::cerr << "FAIL: eorv_r_p_z_" << std::endl; failed++; }
    try { test_expand_z_p_z_(); } catch (...) { std::cerr << "FAIL: expand_z_p_z_" << std::endl; failed++; }
    try { test_ext_z_zi_con(); } catch (...) { std::cerr << "FAIL: ext_z_zi_con" << std::endl; failed++; }
    try { test_ext_z_zi_des(); } catch (...) { std::cerr << "FAIL: ext_z_zi_des" << std::endl; failed++; }
    try { test_extq_z_zi_des(); } catch (...) { std::cerr << "FAIL: extq_z_zi_des" << std::endl; failed++; }
    try { test_f1cvt_z_z8_b2h(); } catch (...) { std::cerr << "FAIL: f1cvt_z_z8_b2h" << std::endl; failed++; }
    try { test_f2cvt_z_z8_b2h(); } catch (...) { std::cerr << "FAIL: f2cvt_z_z8_b2h" << std::endl; failed++; }
    try { test_f1cvtlt_z_z8_b2h(); } catch (...) { std::cerr << "FAIL: f1cvtlt_z_z8_b2h" << std::endl; failed++; }
    try { test_f2cvtlt_z_z8_b2h(); } catch (...) { std::cerr << "FAIL: f2cvtlt_z_z8_b2h" << std::endl; failed++; }
    try { test_fabd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fabd_z_p_zz_" << std::endl; failed++; }
    try { test_fabs_z_p_z_m(); } catch (...) { std::cerr << "FAIL: fabs_z_p_z_m" << std::endl; failed++; }
    try { test_fabs_z_p_z_z(); } catch (...) { std::cerr << "FAIL: fabs_z_p_z_z" << std::endl; failed++; }
    try { test_facgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: facgt_p_p_zz_" << std::endl; failed++; }
    try { test_facge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: facge_p_p_zz_" << std::endl; failed++; }
    try { test_facle_p_p_zz__facge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: facle_p_p_zz__facge_p_p_zz_" << std::endl; failed++; }
    try { test_faclt_p_p_zz__facgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: faclt_p_p_zz__facgt_p_p_zz_" << std::endl; failed++; }
    try { test_fadd_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fadd_z_p_zs_" << std::endl; failed++; }
    try { test_fadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fadd_z_p_zz_" << std::endl; failed++; }
    try { test_fadd_z_zz_(); } catch (...) { std::cerr << "FAIL: fadd_z_zz_" << std::endl; failed++; }
    try { test_fadda_v_p_z_(); } catch (...) { std::cerr << "FAIL: fadda_v_p_z_" << std::endl; failed++; }
    try { test_faddp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: faddp_z_p_zz_" << std::endl; failed++; }
    try { test_faddqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: faddqv_z_p_z_" << std::endl; failed++; }
    try { test_faddv_v_p_z_(); } catch (...) { std::cerr << "FAIL: faddv_v_p_z_" << std::endl; failed++; }
    try { test_famax_z_p_zz_(); } catch (...) { std::cerr << "FAIL: famax_z_p_zz_" << std::endl; failed++; }
    try { test_famin_z_p_zz_(); } catch (...) { std::cerr << "FAIL: famin_z_p_zz_" << std::endl; failed++; }
    try { test_fcadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fcadd_z_p_zz_" << std::endl; failed++; }
    try { test_fclamp_z_zz_(); } catch (...) { std::cerr << "FAIL: fclamp_z_zz_" << std::endl; failed++; }
    try { test_fcmeq_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmeq_p_p_z0_" << std::endl; failed++; }
    try { test_fcmgt_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmgt_p_p_z0_" << std::endl; failed++; }
    try { test_fcmge_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmge_p_p_z0_" << std::endl; failed++; }
    try { test_fcmlt_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmlt_p_p_z0_" << std::endl; failed++; }
    try { test_fcmle_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmle_p_p_z0_" << std::endl; failed++; }
    try { test_fcmne_p_p_z0_(); } catch (...) { std::cerr << "FAIL: fcmne_p_p_z0_" << std::endl; failed++; }
    try { test_fcmeq_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmeq_p_p_zz_" << std::endl; failed++; }
    try { test_fcmgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmgt_p_p_zz_" << std::endl; failed++; }
    try { test_fcmge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmge_p_p_zz_" << std::endl; failed++; }
    try { test_fcmne_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmne_p_p_zz_" << std::endl; failed++; }
    try { test_fcmuo_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmuo_p_p_zz_" << std::endl; failed++; }
    try { test_fcmla_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fcmla_z_p_zzz_" << std::endl; failed++; }
    try { test_fcmla_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: fcmla_z_zzzi_h" << std::endl; failed++; }
    try { test_fcmla_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fcmla_z_zzzi_s" << std::endl; failed++; }
    try { test_fcmle_p_p_zz__fcmge_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmle_p_p_zz__fcmge_p_p_zz_" << std::endl; failed++; }
    try { test_fcmlt_p_p_zz__fcmgt_p_p_zz_(); } catch (...) { std::cerr << "FAIL: fcmlt_p_p_zz__fcmgt_p_p_zz_" << std::endl; failed++; }
    try { test_fcpy_z_p_i_(); } catch (...) { std::cerr << "FAIL: fcpy_z_p_i_" << std::endl; failed++; }
    try { test_fcvt_z_p_z_h2s(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_h2s" << std::endl; failed++; }
    try { test_fcvt_z_p_z_h2sz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_h2sz" << std::endl; failed++; }
    try { test_fcvt_z_p_z_h2d(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_h2d" << std::endl; failed++; }
    try { test_fcvt_z_p_z_h2dz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_h2dz" << std::endl; failed++; }
    try { test_fcvt_z_p_z_s2h(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_s2h" << std::endl; failed++; }
    try { test_fcvt_z_p_z_s2hz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_s2hz" << std::endl; failed++; }
    try { test_fcvt_z_p_z_s2d(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_s2d" << std::endl; failed++; }
    try { test_fcvt_z_p_z_s2dz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_s2dz" << std::endl; failed++; }
    try { test_fcvt_z_p_z_d2h(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_d2h" << std::endl; failed++; }
    try { test_fcvt_z_p_z_d2hz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_d2hz" << std::endl; failed++; }
    try { test_fcvt_z_p_z_d2s(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_d2s" << std::endl; failed++; }
    try { test_fcvt_z_p_z_d2sz(); } catch (...) { std::cerr << "FAIL: fcvt_z_p_z_d2sz" << std::endl; failed++; }
    try { test_fcvtlt_z_p_z_h2s(); } catch (...) { std::cerr << "FAIL: fcvtlt_z_p_z_h2s" << std::endl; failed++; }
    try { test_fcvtlt_z_p_z_h2sz(); } catch (...) { std::cerr << "FAIL: fcvtlt_z_p_z_h2sz" << std::endl; failed++; }
    try { test_fcvtlt_z_p_z_s2d(); } catch (...) { std::cerr << "FAIL: fcvtlt_z_p_z_s2d" << std::endl; failed++; }
    try { test_fcvtlt_z_p_z_s2dz(); } catch (...) { std::cerr << "FAIL: fcvtlt_z_p_z_s2dz" << std::endl; failed++; }
    try { test_fcvtn_z8_mz2_h2b(); } catch (...) { std::cerr << "FAIL: fcvtn_z8_mz2_h2b" << std::endl; failed++; }
    try { test_fcvtnb_z8_mz2_s2b(); } catch (...) { std::cerr << "FAIL: fcvtnb_z8_mz2_s2b" << std::endl; failed++; }
    try { test_fcvtnt_z8_mz2_s2b(); } catch (...) { std::cerr << "FAIL: fcvtnt_z8_mz2_s2b" << std::endl; failed++; }
    try { test_fcvtnt_z_p_z_s2h(); } catch (...) { std::cerr << "FAIL: fcvtnt_z_p_z_s2h" << std::endl; failed++; }
    try { test_fcvtnt_z_p_z_s2hz(); } catch (...) { std::cerr << "FAIL: fcvtnt_z_p_z_s2hz" << std::endl; failed++; }
    try { test_fcvtnt_z_p_z_d2s(); } catch (...) { std::cerr << "FAIL: fcvtnt_z_p_z_d2s" << std::endl; failed++; }
    try { test_fcvtnt_z_p_z_d2sz(); } catch (...) { std::cerr << "FAIL: fcvtnt_z_p_z_d2sz" << std::endl; failed++; }
    try { test_fcvtx_z_p_z_d2s(); } catch (...) { std::cerr << "FAIL: fcvtx_z_p_z_d2s" << std::endl; failed++; }
    try { test_fcvtx_z_p_z_d2sz(); } catch (...) { std::cerr << "FAIL: fcvtx_z_p_z_d2sz" << std::endl; failed++; }
    try { test_fcvtxnt_z_p_z_d2s(); } catch (...) { std::cerr << "FAIL: fcvtxnt_z_p_z_d2s" << std::endl; failed++; }
    try { test_fcvtxnt_z_p_z_d2sz(); } catch (...) { std::cerr << "FAIL: fcvtxnt_z_p_z_d2sz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162h(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162h" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162hz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162hz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162w(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162w" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162wz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162wz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162x(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162x" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_fp162xz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_fp162xz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_s2w(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_s2w" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_s2wz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_s2wz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_s2x(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_s2x" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_s2xz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_s2xz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_d2w(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_d2w" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_d2wz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_d2wz" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_d2x(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_d2x" << std::endl; failed++; }
    try { test_fcvtzs_z_p_z_d2xz(); } catch (...) { std::cerr << "FAIL: fcvtzs_z_p_z_d2xz" << std::endl; failed++; }
    try { test_fcvtzsn_z_mz2_(); } catch (...) { std::cerr << "FAIL: fcvtzsn_z_mz2_" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162h(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162h" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162hz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162hz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162w(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162w" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162wz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162wz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162x(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162x" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_fp162xz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_fp162xz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_s2w(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_s2w" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_s2wz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_s2wz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_s2x(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_s2x" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_s2xz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_s2xz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_d2w(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_d2w" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_d2wz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_d2wz" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_d2x(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_d2x" << std::endl; failed++; }
    try { test_fcvtzu_z_p_z_d2xz(); } catch (...) { std::cerr << "FAIL: fcvtzu_z_p_z_d2xz" << std::endl; failed++; }
    try { test_fcvtzun_z_mz2_(); } catch (...) { std::cerr << "FAIL: fcvtzun_z_mz2_" << std::endl; failed++; }
    try { test_fdiv_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fdiv_z_p_zz_" << std::endl; failed++; }
    try { test_fdivr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fdivr_z_p_zz_" << std::endl; failed++; }
    try { test_fdot_z32_zz8z8_(); } catch (...) { std::cerr << "FAIL: fdot_z32_zz8z8_" << std::endl; failed++; }
    try { test_fdot_z32_zz8z8i_(); } catch (...) { std::cerr << "FAIL: fdot_z32_zz8z8i_" << std::endl; failed++; }
    try { test_fdot_z_zz8z8_(); } catch (...) { std::cerr << "FAIL: fdot_z_zz8z8_" << std::endl; failed++; }
    try { test_fdot_z_zz8z8i_(); } catch (...) { std::cerr << "FAIL: fdot_z_zz8z8i_" << std::endl; failed++; }
    try { test_fdot_z_zzz_(); } catch (...) { std::cerr << "FAIL: fdot_z_zzz_" << std::endl; failed++; }
    try { test_fdot_z_zzzi_(); } catch (...) { std::cerr << "FAIL: fdot_z_zzzi_" << std::endl; failed++; }
    try { test_fdup_z_i_(); } catch (...) { std::cerr << "FAIL: fdup_z_i_" << std::endl; failed++; }
    try { test_fexpa_z_z_(); } catch (...) { std::cerr << "FAIL: fexpa_z_z_" << std::endl; failed++; }
    try { test_firstp_r_p_p_(); } catch (...) { std::cerr << "FAIL: firstp_r_p_p_" << std::endl; failed++; }
    try { test_flogb_z_p_z_m(); } catch (...) { std::cerr << "FAIL: flogb_z_p_z_m" << std::endl; failed++; }
    try { test_flogb_z_p_z_z(); } catch (...) { std::cerr << "FAIL: flogb_z_p_z_z" << std::endl; failed++; }
    try { test_fmad_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fmad_z_p_zzz_" << std::endl; failed++; }
    try { test_fmax_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fmax_z_p_zs_" << std::endl; failed++; }
    try { test_fmax_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmax_z_p_zz_" << std::endl; failed++; }
    try { test_fmaxnm_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fmaxnm_z_p_zs_" << std::endl; failed++; }
    try { test_fmaxnm_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmaxnm_z_p_zz_" << std::endl; failed++; }
    try { test_fmaxnmp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmaxnmp_z_p_zz_" << std::endl; failed++; }
    try { test_fmaxnmqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: fmaxnmqv_z_p_z_" << std::endl; failed++; }
    try { test_fmaxnmv_v_p_z_(); } catch (...) { std::cerr << "FAIL: fmaxnmv_v_p_z_" << std::endl; failed++; }
    try { test_fmaxp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmaxp_z_p_zz_" << std::endl; failed++; }
    try { test_fmaxqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: fmaxqv_z_p_z_" << std::endl; failed++; }
    try { test_fmaxv_v_p_z_(); } catch (...) { std::cerr << "FAIL: fmaxv_v_p_z_" << std::endl; failed++; }
    try { test_fmin_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fmin_z_p_zs_" << std::endl; failed++; }
    try { test_fmin_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmin_z_p_zz_" << std::endl; failed++; }
    try { test_fminnm_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fminnm_z_p_zs_" << std::endl; failed++; }
    try { test_fminnm_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fminnm_z_p_zz_" << std::endl; failed++; }
    try { test_fminnmp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fminnmp_z_p_zz_" << std::endl; failed++; }
    try { test_fminnmqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: fminnmqv_z_p_z_" << std::endl; failed++; }
    try { test_fminnmv_v_p_z_(); } catch (...) { std::cerr << "FAIL: fminnmv_v_p_z_" << std::endl; failed++; }
    try { test_fminp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fminp_z_p_zz_" << std::endl; failed++; }
    try { test_fminqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: fminqv_z_p_z_" << std::endl; failed++; }
    try { test_fminv_v_p_z_(); } catch (...) { std::cerr << "FAIL: fminv_v_p_z_" << std::endl; failed++; }
    try { test_fmla_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fmla_z_p_zzz_" << std::endl; failed++; }
    try { test_fmla_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: fmla_z_zzzi_h" << std::endl; failed++; }
    try { test_fmla_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmla_z_zzzi_s" << std::endl; failed++; }
    try { test_fmla_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: fmla_z_zzzi_d" << std::endl; failed++; }
    try { test_fmlalb_z_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlalb_z_z8z8z8_" << std::endl; failed++; }
    try { test_fmlalb_z_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlalb_z_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: fmlalb_z_zzz_" << std::endl; failed++; }
    try { test_fmlalb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmlalb_z_zzzi_s" << std::endl; failed++; }
    try { test_fmlallbb_z32_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlallbb_z32_z8z8z8_" << std::endl; failed++; }
    try { test_fmlallbb_z32_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlallbb_z32_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlallbt_z32_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlallbt_z32_z8z8z8_" << std::endl; failed++; }
    try { test_fmlallbt_z32_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlallbt_z32_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlalltb_z32_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlalltb_z32_z8z8z8_" << std::endl; failed++; }
    try { test_fmlalltb_z32_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlalltb_z32_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlalltt_z32_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlalltt_z32_z8z8z8_" << std::endl; failed++; }
    try { test_fmlalltt_z32_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlalltt_z32_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlalt_z_z8z8z8_(); } catch (...) { std::cerr << "FAIL: fmlalt_z_z8z8z8_" << std::endl; failed++; }
    try { test_fmlalt_z_z8z8z8i_(); } catch (...) { std::cerr << "FAIL: fmlalt_z_z8z8z8i_" << std::endl; failed++; }
    try { test_fmlalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: fmlalt_z_zzz_" << std::endl; failed++; }
    try { test_fmlalt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmlalt_z_zzzi_s" << std::endl; failed++; }
    try { test_fmls_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fmls_z_p_zzz_" << std::endl; failed++; }
    try { test_fmls_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: fmls_z_zzzi_h" << std::endl; failed++; }
    try { test_fmls_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmls_z_zzzi_s" << std::endl; failed++; }
    try { test_fmls_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: fmls_z_zzzi_d" << std::endl; failed++; }
    try { test_fmlslb_z_zzz_(); } catch (...) { std::cerr << "FAIL: fmlslb_z_zzz_" << std::endl; failed++; }
    try { test_fmlslb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmlslb_z_zzzi_s" << std::endl; failed++; }
    try { test_fmlslt_z_zzz_(); } catch (...) { std::cerr << "FAIL: fmlslt_z_zzz_" << std::endl; failed++; }
    try { test_fmlslt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: fmlslt_z_zzzi_s" << std::endl; failed++; }
    try { test_fmmla_z16_zz8z8_(); } catch (...) { std::cerr << "FAIL: fmmla_z16_zz8z8_" << std::endl; failed++; }
    try { test_fmmla_z32_zz8z8_(); } catch (...) { std::cerr << "FAIL: fmmla_z32_zz8z8_" << std::endl; failed++; }
    try { test_fmmla_z32_zzz_h(); } catch (...) { std::cerr << "FAIL: fmmla_z32_zzz_h" << std::endl; failed++; }
    try { test_fmmla_z_zzz_h(); } catch (...) { std::cerr << "FAIL: fmmla_z_zzz_h" << std::endl; failed++; }
    try { test_fmmla_z_zzz_s(); } catch (...) { std::cerr << "FAIL: fmmla_z_zzz_s" << std::endl; failed++; }
    try { test_fmmla_z_zzz_d(); } catch (...) { std::cerr << "FAIL: fmmla_z_zzz_d" << std::endl; failed++; }
    try { test_fmov_z_p_0__cpy_z_p_i_(); } catch (...) { std::cerr << "FAIL: fmov_z_p_0__cpy_z_p_i_" << std::endl; failed++; }
    try { test_fmov_z_0__dup_z_i_(); } catch (...) { std::cerr << "FAIL: fmov_z_0__dup_z_i_" << std::endl; failed++; }
    try { test_fmov_z_p_i__fcpy_z_p_i_(); } catch (...) { std::cerr << "FAIL: fmov_z_p_i__fcpy_z_p_i_" << std::endl; failed++; }
    try { test_fmov_z_i__fdup_z_i_(); } catch (...) { std::cerr << "FAIL: fmov_z_i__fdup_z_i_" << std::endl; failed++; }
    try { test_fmsb_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fmsb_z_p_zzz_" << std::endl; failed++; }
    try { test_fmul_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fmul_z_p_zs_" << std::endl; failed++; }
    try { test_fmul_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmul_z_p_zz_" << std::endl; failed++; }
    try { test_fmul_z_zz_(); } catch (...) { std::cerr << "FAIL: fmul_z_zz_" << std::endl; failed++; }
    try { test_fmul_z_zzi_h(); } catch (...) { std::cerr << "FAIL: fmul_z_zzi_h" << std::endl; failed++; }
    try { test_fmul_z_zzi_s(); } catch (...) { std::cerr << "FAIL: fmul_z_zzi_s" << std::endl; failed++; }
    try { test_fmul_z_zzi_d(); } catch (...) { std::cerr << "FAIL: fmul_z_zzi_d" << std::endl; failed++; }
    try { test_fmulx_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fmulx_z_p_zz_" << std::endl; failed++; }
    try { test_fneg_z_p_z_m(); } catch (...) { std::cerr << "FAIL: fneg_z_p_z_m" << std::endl; failed++; }
    try { test_fneg_z_p_z_z(); } catch (...) { std::cerr << "FAIL: fneg_z_p_z_z" << std::endl; failed++; }
    try { test_fnmad_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fnmad_z_p_zzz_" << std::endl; failed++; }
    try { test_fnmla_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fnmla_z_p_zzz_" << std::endl; failed++; }
    try { test_fnmls_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fnmls_z_p_zzz_" << std::endl; failed++; }
    try { test_fnmsb_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: fnmsb_z_p_zzz_" << std::endl; failed++; }
    try { test_frecpe_z_z_(); } catch (...) { std::cerr << "FAIL: frecpe_z_z_" << std::endl; failed++; }
    try { test_frecps_z_zz_(); } catch (...) { std::cerr << "FAIL: frecps_z_zz_" << std::endl; failed++; }
    try { test_frecpx_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frecpx_z_p_z_m" << std::endl; failed++; }
    try { test_frecpx_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frecpx_z_p_z_z" << std::endl; failed++; }
    try { test_frint32x_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frint32x_z_p_z_m" << std::endl; failed++; }
    try { test_frint32x_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frint32x_z_p_z_z" << std::endl; failed++; }
    try { test_frint32z_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frint32z_z_p_z_m" << std::endl; failed++; }
    try { test_frint32z_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frint32z_z_p_z_z" << std::endl; failed++; }
    try { test_frint64x_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frint64x_z_p_z_m" << std::endl; failed++; }
    try { test_frint64x_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frint64x_z_p_z_z" << std::endl; failed++; }
    try { test_frint64z_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frint64z_z_p_z_m" << std::endl; failed++; }
    try { test_frint64z_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frint64z_z_p_z_z" << std::endl; failed++; }
    try { test_frintx_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frintx_z_p_z_m" << std::endl; failed++; }
    try { test_frintx_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frintx_z_p_z_z" << std::endl; failed++; }
    try { test_frinti_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frinti_z_p_z_m" << std::endl; failed++; }
    try { test_frinti_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frinti_z_p_z_z" << std::endl; failed++; }
    try { test_frinta_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frinta_z_p_z_m" << std::endl; failed++; }
    try { test_frinta_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frinta_z_p_z_z" << std::endl; failed++; }
    try { test_frintn_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frintn_z_p_z_m" << std::endl; failed++; }
    try { test_frintn_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frintn_z_p_z_z" << std::endl; failed++; }
    try { test_frintz_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frintz_z_p_z_m" << std::endl; failed++; }
    try { test_frintz_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frintz_z_p_z_z" << std::endl; failed++; }
    try { test_frintm_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frintm_z_p_z_m" << std::endl; failed++; }
    try { test_frintm_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frintm_z_p_z_z" << std::endl; failed++; }
    try { test_frintp_z_p_z_m(); } catch (...) { std::cerr << "FAIL: frintp_z_p_z_m" << std::endl; failed++; }
    try { test_frintp_z_p_z_z(); } catch (...) { std::cerr << "FAIL: frintp_z_p_z_z" << std::endl; failed++; }
    try { test_frsqrte_z_z_(); } catch (...) { std::cerr << "FAIL: frsqrte_z_z_" << std::endl; failed++; }
    try { test_frsqrts_z_zz_(); } catch (...) { std::cerr << "FAIL: frsqrts_z_zz_" << std::endl; failed++; }
    try { test_fscale_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fscale_z_p_zz_" << std::endl; failed++; }
    try { test_fsqrt_z_p_z_m(); } catch (...) { std::cerr << "FAIL: fsqrt_z_p_z_m" << std::endl; failed++; }
    try { test_fsqrt_z_p_z_z(); } catch (...) { std::cerr << "FAIL: fsqrt_z_p_z_z" << std::endl; failed++; }
    try { test_fsub_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fsub_z_p_zs_" << std::endl; failed++; }
    try { test_fsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fsub_z_p_zz_" << std::endl; failed++; }
    try { test_fsub_z_zz_(); } catch (...) { std::cerr << "FAIL: fsub_z_zz_" << std::endl; failed++; }
    try { test_fsubr_z_p_zs_(); } catch (...) { std::cerr << "FAIL: fsubr_z_p_zs_" << std::endl; failed++; }
    try { test_fsubr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: fsubr_z_p_zz_" << std::endl; failed++; }
    try { test_ftmad_z_zzi_(); } catch (...) { std::cerr << "FAIL: ftmad_z_zzi_" << std::endl; failed++; }
    try { test_ftsmul_z_zz_(); } catch (...) { std::cerr << "FAIL: ftsmul_z_zz_" << std::endl; failed++; }
    try { test_ftssel_z_zz_(); } catch (...) { std::cerr << "FAIL: ftssel_z_zz_" << std::endl; failed++; }
    try { test_histcnt_z_p_zz_(); } catch (...) { std::cerr << "FAIL: histcnt_z_p_zz_" << std::endl; failed++; }
    try { test_histseg_z_zz_(); } catch (...) { std::cerr << "FAIL: histseg_z_zz_" << std::endl; failed++; }
    try { test_incb_r_rs_(); } catch (...) { std::cerr << "FAIL: incb_r_rs_" << std::endl; failed++; }
    try { test_incd_r_rs_(); } catch (...) { std::cerr << "FAIL: incd_r_rs_" << std::endl; failed++; }
    try { test_inch_r_rs_(); } catch (...) { std::cerr << "FAIL: inch_r_rs_" << std::endl; failed++; }
    try { test_incw_r_rs_(); } catch (...) { std::cerr << "FAIL: incw_r_rs_" << std::endl; failed++; }
    try { test_incd_z_zs_(); } catch (...) { std::cerr << "FAIL: incd_z_zs_" << std::endl; failed++; }
    try { test_inch_z_zs_(); } catch (...) { std::cerr << "FAIL: inch_z_zs_" << std::endl; failed++; }
    try { test_incw_z_zs_(); } catch (...) { std::cerr << "FAIL: incw_z_zs_" << std::endl; failed++; }
    try { test_incp_r_p_r_(); } catch (...) { std::cerr << "FAIL: incp_r_p_r_" << std::endl; failed++; }
    try { test_incp_z_p_z_(); } catch (...) { std::cerr << "FAIL: incp_z_p_z_" << std::endl; failed++; }
    try { test_index_z_ii_(); } catch (...) { std::cerr << "FAIL: index_z_ii_" << std::endl; failed++; }
    try { test_index_z_ir_(); } catch (...) { std::cerr << "FAIL: index_z_ir_" << std::endl; failed++; }
    try { test_index_z_ri_(); } catch (...) { std::cerr << "FAIL: index_z_ri_" << std::endl; failed++; }
    try { test_index_z_rr_(); } catch (...) { std::cerr << "FAIL: index_z_rr_" << std::endl; failed++; }
    try { test_insr_z_r_(); } catch (...) { std::cerr << "FAIL: insr_z_r_" << std::endl; failed++; }
    try { test_insr_z_v_(); } catch (...) { std::cerr << "FAIL: insr_z_v_" << std::endl; failed++; }
    try { test_lasta_r_p_z_(); } catch (...) { std::cerr << "FAIL: lasta_r_p_z_" << std::endl; failed++; }
    try { test_lasta_v_p_z_(); } catch (...) { std::cerr << "FAIL: lasta_v_p_z_" << std::endl; failed++; }
    try { test_lastb_r_p_z_(); } catch (...) { std::cerr << "FAIL: lastb_r_p_z_" << std::endl; failed++; }
    try { test_lastb_v_p_z_(); } catch (...) { std::cerr << "FAIL: lastb_v_p_z_" << std::endl; failed++; }
    try { test_lastp_r_p_p_(); } catch (...) { std::cerr << "FAIL: lastp_r_p_p_" << std::endl; failed++; }
    try { test_ld1b_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_ai_s" << std::endl; failed++; }
    try { test_ld1b_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1b_z_p_bi_u8(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bi_u8" << std::endl; failed++; }
    try { test_ld1b_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1b_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1b_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u8(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u8" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u16(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u16" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u32" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u64" << std::endl; failed++; }
    try { test_ld1b_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1b_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ld1b_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1d_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1d_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1d_z_p_bi_u128(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bi_u128" << std::endl; failed++; }
    try { test_ld1d_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_br_u64" << std::endl; failed++; }
    try { test_ld1d_z_p_br_u128(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_br_u128" << std::endl; failed++; }
    try { test_ld1d_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ld1d_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1d_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ld1d_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1h_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_ai_s" << std::endl; failed++; }
    try { test_ld1h_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1h_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1h_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1h_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u16(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u16" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u32" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u64" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ld1h_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1q_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1q_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1rb_z_p_bi_u8(); } catch (...) { std::cerr << "FAIL: ld1rb_z_p_bi_u8" << std::endl; failed++; }
    try { test_ld1rb_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1rb_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1rb_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1rb_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1rb_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rb_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1rd_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rd_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1rh_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1rh_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1rh_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1rh_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1rh_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rh_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1rob_z_p_bi_u8(); } catch (...) { std::cerr << "FAIL: ld1rob_z_p_bi_u8" << std::endl; failed++; }
    try { test_ld1rob_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rob_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rod_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rod_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1rod_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rod_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1roh_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1roh_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1roh_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1roh_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1row_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1row_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1row_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1row_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rqb_z_p_bi_u8(); } catch (...) { std::cerr << "FAIL: ld1rqb_z_p_bi_u8" << std::endl; failed++; }
    try { test_ld1rqb_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rqb_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rqd_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rqd_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1rqd_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rqd_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rqh_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ld1rqh_z_p_bi_u16" << std::endl; failed++; }
    try { test_ld1rqh_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rqh_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rqw_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1rqw_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1rqw_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld1rqw_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld1rsb_z_p_bi_s16(); } catch (...) { std::cerr << "FAIL: ld1rsb_z_p_bi_s16" << std::endl; failed++; }
    try { test_ld1rsb_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ld1rsb_z_p_bi_s32" << std::endl; failed++; }
    try { test_ld1rsb_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1rsb_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1rsh_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ld1rsh_z_p_bi_s32" << std::endl; failed++; }
    try { test_ld1rsh_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1rsh_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1rsw_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1rsw_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1rw_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1rw_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1rw_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1rw_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1sb_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_ai_s" << std::endl; failed++; }
    try { test_ld1sb_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1sb_z_p_bi_s16(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bi_s16" << std::endl; failed++; }
    try { test_ld1sb_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bi_s32" << std::endl; failed++; }
    try { test_ld1sb_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s16(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s16" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s32(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s32" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s64" << std::endl; failed++; }
    try { test_ld1sb_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1sb_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ld1sb_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_ai_s" << std::endl; failed++; }
    try { test_ld1sh_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1sh_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bi_s32" << std::endl; failed++; }
    try { test_ld1sh_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1sh_z_p_br_s32(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_br_s32" << std::endl; failed++; }
    try { test_ld1sh_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_br_s64" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ld1sh_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1sw_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1sw_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_bi_s64" << std::endl; failed++; }
    try { test_ld1sw_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_br_s64" << std::endl; failed++; }
    try { test_ld1sw_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ld1sw_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1sw_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ld1sw_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld1w_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_ai_s" << std::endl; failed++; }
    try { test_ld1w_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_ai_d" << std::endl; failed++; }
    try { test_ld1w_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bi_u32" << std::endl; failed++; }
    try { test_ld1w_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bi_u64" << std::endl; failed++; }
    try { test_ld1w_z_p_bi_u128(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bi_u128" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u32" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u64" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u128(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u128" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ld1w_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ld2b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld2b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld2b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld2b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld2d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld2d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld2d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld2d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld2h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld2h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld2h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld2h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld2q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld2q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld2q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld2q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld2w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld2w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld2w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld2w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld3b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld3b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld3b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld3b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld3d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld3d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld3d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld3d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld3h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld3h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld3h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld3h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld3q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld3q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld3q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld3q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld3w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld3w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld3w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld3w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld4b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld4b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld4b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld4b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld4d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld4d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld4d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld4d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld4h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld4h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld4h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld4h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld4q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld4q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld4q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld4q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ld4w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ld4w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ld4w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ld4w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ldff1b_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_ai_s" << std::endl; failed++; }
    try { test_ldff1b_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1b_z_p_br_u8(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_br_u8" << std::endl; failed++; }
    try { test_ldff1b_z_p_br_u16(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_br_u16" << std::endl; failed++; }
    try { test_ldff1b_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_br_u32" << std::endl; failed++; }
    try { test_ldff1b_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_br_u64" << std::endl; failed++; }
    try { test_ldff1b_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1b_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1b_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1b_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1d_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1d_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_br_u64" << std::endl; failed++; }
    try { test_ldff1d_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ldff1d_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1d_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ldff1d_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1d_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_ai_s" << std::endl; failed++; }
    try { test_ldff1h_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1h_z_p_br_u16(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_br_u16" << std::endl; failed++; }
    try { test_ldff1h_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_br_u32" << std::endl; failed++; }
    try { test_ldff1h_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_br_u64" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ldff1h_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1h_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1sb_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_ai_s" << std::endl; failed++; }
    try { test_ldff1sb_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1sb_z_p_br_s16(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_br_s16" << std::endl; failed++; }
    try { test_ldff1sb_z_p_br_s32(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_br_s32" << std::endl; failed++; }
    try { test_ldff1sb_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_br_s64" << std::endl; failed++; }
    try { test_ldff1sb_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1sb_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1sb_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sb_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_ai_s" << std::endl; failed++; }
    try { test_ldff1sh_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1sh_z_p_br_s32(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_br_s32" << std::endl; failed++; }
    try { test_ldff1sh_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_br_s64" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ldff1sh_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sh_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1sw_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1sw_z_p_br_s64(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_br_s64" << std::endl; failed++; }
    try { test_ldff1sw_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ldff1sw_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1sw_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ldff1sw_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1sw_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_ai_s" << std::endl; failed++; }
    try { test_ldff1w_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_ai_d" << std::endl; failed++; }
    try { test_ldff1w_z_p_br_u32(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_br_u32" << std::endl; failed++; }
    try { test_ldff1w_z_p_br_u64(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_br_u64" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_ldff1w_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldff1w_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnf1b_z_p_bi_u8(); } catch (...) { std::cerr << "FAIL: ldnf1b_z_p_bi_u8" << std::endl; failed++; }
    try { test_ldnf1b_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ldnf1b_z_p_bi_u16" << std::endl; failed++; }
    try { test_ldnf1b_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ldnf1b_z_p_bi_u32" << std::endl; failed++; }
    try { test_ldnf1b_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ldnf1b_z_p_bi_u64" << std::endl; failed++; }
    try { test_ldnf1d_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ldnf1d_z_p_bi_u64" << std::endl; failed++; }
    try { test_ldnf1h_z_p_bi_u16(); } catch (...) { std::cerr << "FAIL: ldnf1h_z_p_bi_u16" << std::endl; failed++; }
    try { test_ldnf1h_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ldnf1h_z_p_bi_u32" << std::endl; failed++; }
    try { test_ldnf1h_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ldnf1h_z_p_bi_u64" << std::endl; failed++; }
    try { test_ldnf1sb_z_p_bi_s16(); } catch (...) { std::cerr << "FAIL: ldnf1sb_z_p_bi_s16" << std::endl; failed++; }
    try { test_ldnf1sb_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ldnf1sb_z_p_bi_s32" << std::endl; failed++; }
    try { test_ldnf1sb_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ldnf1sb_z_p_bi_s64" << std::endl; failed++; }
    try { test_ldnf1sh_z_p_bi_s32(); } catch (...) { std::cerr << "FAIL: ldnf1sh_z_p_bi_s32" << std::endl; failed++; }
    try { test_ldnf1sh_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ldnf1sh_z_p_bi_s64" << std::endl; failed++; }
    try { test_ldnf1sw_z_p_bi_s64(); } catch (...) { std::cerr << "FAIL: ldnf1sw_z_p_bi_s64" << std::endl; failed++; }
    try { test_ldnf1w_z_p_bi_u32(); } catch (...) { std::cerr << "FAIL: ldnf1w_z_p_bi_u32" << std::endl; failed++; }
    try { test_ldnf1w_z_p_bi_u64(); } catch (...) { std::cerr << "FAIL: ldnf1w_z_p_bi_u64" << std::endl; failed++; }
    try { test_ldnt1b_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1b_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldnt1b_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1b_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ldnt1b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ldnt1d_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1d_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ldnt1d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ldnt1h_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1h_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldnt1h_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1h_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ldnt1h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ldnt1sb_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1sb_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldnt1sb_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1sb_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1sh_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1sh_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldnt1sh_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1sh_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1sw_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1sw_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1w_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1w_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_ldnt1w_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: ldnt1w_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_ldnt1w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_ldnt1w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: ldnt1w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_ldr_p_bi_(); } catch (...) { std::cerr << "FAIL: ldr_p_bi_" << std::endl; failed++; }
    try { test_ldr_z_bi_(); } catch (...) { std::cerr << "FAIL: ldr_z_bi_" << std::endl; failed++; }
    try { test_lsl_z_p_zi_(); } catch (...) { std::cerr << "FAIL: lsl_z_p_zi_" << std::endl; failed++; }
    try { test_lsl_z_p_zw_(); } catch (...) { std::cerr << "FAIL: lsl_z_p_zw_" << std::endl; failed++; }
    try { test_lsl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: lsl_z_p_zz_" << std::endl; failed++; }
    try { test_lsl_z_zi_(); } catch (...) { std::cerr << "FAIL: lsl_z_zi_" << std::endl; failed++; }
    try { test_lsl_z_zw_(); } catch (...) { std::cerr << "FAIL: lsl_z_zw_" << std::endl; failed++; }
    try { test_lslr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: lslr_z_p_zz_" << std::endl; failed++; }
    try { test_lsr_z_p_zi_(); } catch (...) { std::cerr << "FAIL: lsr_z_p_zi_" << std::endl; failed++; }
    try { test_lsr_z_p_zw_(); } catch (...) { std::cerr << "FAIL: lsr_z_p_zw_" << std::endl; failed++; }
    try { test_lsr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: lsr_z_p_zz_" << std::endl; failed++; }
    try { test_lsr_z_zi_(); } catch (...) { std::cerr << "FAIL: lsr_z_zi_" << std::endl; failed++; }
    try { test_lsr_z_zw_(); } catch (...) { std::cerr << "FAIL: lsr_z_zw_" << std::endl; failed++; }
    try { test_lsrr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: lsrr_z_p_zz_" << std::endl; failed++; }
    try { test_luti2_z_zz_8(); } catch (...) { std::cerr << "FAIL: luti2_z_zz_8" << std::endl; failed++; }
    try { test_luti2_z_zz_16(); } catch (...) { std::cerr << "FAIL: luti2_z_zz_16" << std::endl; failed++; }
    try { test_luti4_z_zz_8(); } catch (...) { std::cerr << "FAIL: luti4_z_zz_8" << std::endl; failed++; }
    try { test_luti4_z_zz_2x16(); } catch (...) { std::cerr << "FAIL: luti4_z_zz_2x16" << std::endl; failed++; }
    try { test_luti4_z_zz_1x16(); } catch (...) { std::cerr << "FAIL: luti4_z_zz_1x16" << std::endl; failed++; }
    try { test_luti6_z_zzz_16(); } catch (...) { std::cerr << "FAIL: luti6_z_zzz_16" << std::endl; failed++; }
    try { test_luti6_z_zzz_8(); } catch (...) { std::cerr << "FAIL: luti6_z_zzz_8" << std::endl; failed++; }
    try { test_mad_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: mad_z_p_zzz_" << std::endl; failed++; }
    try { test_madpt_z_zzz_(); } catch (...) { std::cerr << "FAIL: madpt_z_zzz_" << std::endl; failed++; }
    try { test_match_p_p_zz_(); } catch (...) { std::cerr << "FAIL: match_p_p_zz_" << std::endl; failed++; }
    try { test_mla_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: mla_z_p_zzz_" << std::endl; failed++; }
    try { test_mla_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: mla_z_zzzi_h" << std::endl; failed++; }
    try { test_mla_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: mla_z_zzzi_s" << std::endl; failed++; }
    try { test_mla_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: mla_z_zzzi_d" << std::endl; failed++; }
    try { test_mlapt_z_zzz_(); } catch (...) { std::cerr << "FAIL: mlapt_z_zzz_" << std::endl; failed++; }
    try { test_mls_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: mls_z_p_zzz_" << std::endl; failed++; }
    try { test_mls_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: mls_z_zzzi_h" << std::endl; failed++; }
    try { test_mls_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: mls_z_zzzi_s" << std::endl; failed++; }
    try { test_mls_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: mls_z_zzzi_d" << std::endl; failed++; }
    try { test_movz_p_p_p__and_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: movz_p_p_p__and_p_p_pp_z" << std::endl; failed++; }
    try { test_mov_z_o_i__cpy_z_o_i_(); } catch (...) { std::cerr << "FAIL: mov_z_o_i__cpy_z_o_i_" << std::endl; failed++; }
    try { test_mov_z_p_i__cpy_z_p_i_(); } catch (...) { std::cerr << "FAIL: mov_z_p_i__cpy_z_p_i_" << std::endl; failed++; }
    try { test_mov_z_p_r__cpy_z_p_r_(); } catch (...) { std::cerr << "FAIL: mov_z_p_r__cpy_z_p_r_" << std::endl; failed++; }
    try { test_mov_z_p_v__cpy_z_p_v_(); } catch (...) { std::cerr << "FAIL: mov_z_p_v__cpy_z_p_v_" << std::endl; failed++; }
    try { test_mov_z_i__dup_z_i_(); } catch (...) { std::cerr << "FAIL: mov_z_i__dup_z_i_" << std::endl; failed++; }
    try { test_mov_z_r__dup_z_r_(); } catch (...) { std::cerr << "FAIL: mov_z_r__dup_z_r_" << std::endl; failed++; }
    try { test_mov_z_v__dup_z_zi_(); } catch (...) { std::cerr << "FAIL: mov_z_v__dup_z_zi_" << std::endl; failed++; }
    try { test_mov_z_zi__dup_z_zi_(); } catch (...) { std::cerr << "FAIL: mov_z_zi__dup_z_zi_" << std::endl; failed++; }
    try { test_mov_z_m__dupm_z_i_(); } catch (...) { std::cerr << "FAIL: mov_z_m__dupm_z_i_" << std::endl; failed++; }
    try { test_mov_p_p__orr_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: mov_p_p__orr_p_p_pp_z" << std::endl; failed++; }
    try { test_mov_z_z__orr_z_zz_(); } catch (...) { std::cerr << "FAIL: mov_z_z__orr_z_zz_" << std::endl; failed++; }
    try { test_movm_p_p_p__sel_p_p_pp_(); } catch (...) { std::cerr << "FAIL: movm_p_p_p__sel_p_p_pp_" << std::endl; failed++; }
    try { test_mov_z_p_z__sel_z_p_zz_(); } catch (...) { std::cerr << "FAIL: mov_z_p_z__sel_z_p_zz_" << std::endl; failed++; }
    try { test_movprfx_z_p_z_(); } catch (...) { std::cerr << "FAIL: movprfx_z_p_z_" << std::endl; failed++; }
    try { test_movprfx_z_z_(); } catch (...) { std::cerr << "FAIL: movprfx_z_z_" << std::endl; failed++; }
    try { test_movzs_p_p_p__ands_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: movzs_p_p_p__ands_p_p_pp_z" << std::endl; failed++; }
    try { test_movs_p_p__orrs_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: movs_p_p__orrs_p_p_pp_z" << std::endl; failed++; }
    try { test_msb_z_p_zzz_(); } catch (...) { std::cerr << "FAIL: msb_z_p_zzz_" << std::endl; failed++; }
    try { test_mul_z_p_zz_(); } catch (...) { std::cerr << "FAIL: mul_z_p_zz_" << std::endl; failed++; }
    try { test_mul_z_zi_(); } catch (...) { std::cerr << "FAIL: mul_z_zi_" << std::endl; failed++; }
    try { test_mul_z_zz_(); } catch (...) { std::cerr << "FAIL: mul_z_zz_" << std::endl; failed++; }
    try { test_mul_z_zzi_h(); } catch (...) { std::cerr << "FAIL: mul_z_zzi_h" << std::endl; failed++; }
    try { test_mul_z_zzi_s(); } catch (...) { std::cerr << "FAIL: mul_z_zzi_s" << std::endl; failed++; }
    try { test_mul_z_zzi_d(); } catch (...) { std::cerr << "FAIL: mul_z_zzi_d" << std::endl; failed++; }
    try { test_nand_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: nand_p_p_pp_z" << std::endl; failed++; }
    try { test_nands_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: nands_p_p_pp_z" << std::endl; failed++; }
    try { test_nbsl_z_zzz_(); } catch (...) { std::cerr << "FAIL: nbsl_z_zzz_" << std::endl; failed++; }
    try { test_neg_z_p_z_m(); } catch (...) { std::cerr << "FAIL: neg_z_p_z_m" << std::endl; failed++; }
    try { test_neg_z_p_z_z(); } catch (...) { std::cerr << "FAIL: neg_z_p_z_z" << std::endl; failed++; }
    try { test_nmatch_p_p_zz_(); } catch (...) { std::cerr << "FAIL: nmatch_p_p_zz_" << std::endl; failed++; }
    try { test_nor_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: nor_p_p_pp_z" << std::endl; failed++; }
    try { test_nors_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: nors_p_p_pp_z" << std::endl; failed++; }
    try { test_not_p_p_p_z_eor_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: not_p_p_p_z_eor_p_p_pp_z" << std::endl; failed++; }
    try { test_not_z_p_z_m(); } catch (...) { std::cerr << "FAIL: not_z_p_z_m" << std::endl; failed++; }
    try { test_not_z_p_z_z(); } catch (...) { std::cerr << "FAIL: not_z_p_z_z" << std::endl; failed++; }
    try { test_nots_p_p_p_z_eors_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: nots_p_p_p_z_eors_p_p_pp_z" << std::endl; failed++; }
    try { test_orn_z_zi__orr_z_zi_(); } catch (...) { std::cerr << "FAIL: orn_z_zi__orr_z_zi_" << std::endl; failed++; }
    try { test_orn_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: orn_p_p_pp_z" << std::endl; failed++; }
    try { test_orns_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: orns_p_p_pp_z" << std::endl; failed++; }
    try { test_orqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: orqv_z_p_z_" << std::endl; failed++; }
    try { test_orr_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: orr_p_p_pp_z" << std::endl; failed++; }
    try { test_orr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: orr_z_p_zz_" << std::endl; failed++; }
    try { test_orr_z_zi_(); } catch (...) { std::cerr << "FAIL: orr_z_zi_" << std::endl; failed++; }
    try { test_orr_z_zz_(); } catch (...) { std::cerr << "FAIL: orr_z_zz_" << std::endl; failed++; }
    try { test_orrs_p_p_pp_z(); } catch (...) { std::cerr << "FAIL: orrs_p_p_pp_z" << std::endl; failed++; }
    try { test_orv_r_p_z_(); } catch (...) { std::cerr << "FAIL: orv_r_p_z_" << std::endl; failed++; }
    try { test_pext_pn_rr_(); } catch (...) { std::cerr << "FAIL: pext_pn_rr_" << std::endl; failed++; }
    try { test_pext_pp_rr_(); } catch (...) { std::cerr << "FAIL: pext_pp_rr_" << std::endl; failed++; }
    try { test_pfalse_p_(); } catch (...) { std::cerr << "FAIL: pfalse_p_" << std::endl; failed++; }
    try { test_pfirst_p_p_p_(); } catch (...) { std::cerr << "FAIL: pfirst_p_p_p_" << std::endl; failed++; }
    try { test_pmlal_mz_zzzw_1x2(); } catch (...) { std::cerr << "FAIL: pmlal_mz_zzzw_1x2" << std::endl; failed++; }
    try { test_pmov_p_zi_b(); } catch (...) { std::cerr << "FAIL: pmov_p_zi_b" << std::endl; failed++; }
    try { test_pmov_p_zi_d(); } catch (...) { std::cerr << "FAIL: pmov_p_zi_d" << std::endl; failed++; }
    try { test_pmov_p_zi_h(); } catch (...) { std::cerr << "FAIL: pmov_p_zi_h" << std::endl; failed++; }
    try { test_pmov_p_zi_s(); } catch (...) { std::cerr << "FAIL: pmov_p_zi_s" << std::endl; failed++; }
    try { test_pmov_z_pi_b(); } catch (...) { std::cerr << "FAIL: pmov_z_pi_b" << std::endl; failed++; }
    try { test_pmov_z_pi_d(); } catch (...) { std::cerr << "FAIL: pmov_z_pi_d" << std::endl; failed++; }
    try { test_pmov_z_pi_h(); } catch (...) { std::cerr << "FAIL: pmov_z_pi_h" << std::endl; failed++; }
    try { test_pmov_z_pi_s(); } catch (...) { std::cerr << "FAIL: pmov_z_pi_s" << std::endl; failed++; }
    try { test_pmul_z_zz_(); } catch (...) { std::cerr << "FAIL: pmul_z_zz_" << std::endl; failed++; }
    try { test_pmull_mz_zzw_1x2(); } catch (...) { std::cerr << "FAIL: pmull_mz_zzw_1x2" << std::endl; failed++; }
    try { test_pmullb_z_zz_(); } catch (...) { std::cerr << "FAIL: pmullb_z_zz_" << std::endl; failed++; }
    try { test_pmullb_z_zz_q(); } catch (...) { std::cerr << "FAIL: pmullb_z_zz_q" << std::endl; failed++; }
    try { test_pmullt_z_zz_(); } catch (...) { std::cerr << "FAIL: pmullt_z_zz_" << std::endl; failed++; }
    try { test_pmullt_z_zz_q(); } catch (...) { std::cerr << "FAIL: pmullt_z_zz_q" << std::endl; failed++; }
    try { test_pnext_p_p_p_(); } catch (...) { std::cerr << "FAIL: pnext_p_p_p_" << std::endl; failed++; }
    try { test_prfb_i_p_ai_s(); } catch (...) { std::cerr << "FAIL: prfb_i_p_ai_s" << std::endl; failed++; }
    try { test_prfb_i_p_ai_d(); } catch (...) { std::cerr << "FAIL: prfb_i_p_ai_d" << std::endl; failed++; }
    try { test_prfb_i_p_bi_s(); } catch (...) { std::cerr << "FAIL: prfb_i_p_bi_s" << std::endl; failed++; }
    try { test_prfb_i_p_br_s(); } catch (...) { std::cerr << "FAIL: prfb_i_p_br_s" << std::endl; failed++; }
    try { test_prfb_i_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfb_i_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_prfb_i_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfb_i_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_prfb_i_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: prfb_i_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_prfd_i_p_ai_s(); } catch (...) { std::cerr << "FAIL: prfd_i_p_ai_s" << std::endl; failed++; }
    try { test_prfd_i_p_ai_d(); } catch (...) { std::cerr << "FAIL: prfd_i_p_ai_d" << std::endl; failed++; }
    try { test_prfd_i_p_bi_s(); } catch (...) { std::cerr << "FAIL: prfd_i_p_bi_s" << std::endl; failed++; }
    try { test_prfd_i_p_br_s(); } catch (...) { std::cerr << "FAIL: prfd_i_p_br_s" << std::endl; failed++; }
    try { test_prfd_i_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfd_i_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_prfd_i_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfd_i_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_prfd_i_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: prfd_i_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_prfh_i_p_ai_s(); } catch (...) { std::cerr << "FAIL: prfh_i_p_ai_s" << std::endl; failed++; }
    try { test_prfh_i_p_ai_d(); } catch (...) { std::cerr << "FAIL: prfh_i_p_ai_d" << std::endl; failed++; }
    try { test_prfh_i_p_bi_s(); } catch (...) { std::cerr << "FAIL: prfh_i_p_bi_s" << std::endl; failed++; }
    try { test_prfh_i_p_br_s(); } catch (...) { std::cerr << "FAIL: prfh_i_p_br_s" << std::endl; failed++; }
    try { test_prfh_i_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfh_i_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_prfh_i_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfh_i_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_prfh_i_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: prfh_i_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_prfw_i_p_ai_s(); } catch (...) { std::cerr << "FAIL: prfw_i_p_ai_s" << std::endl; failed++; }
    try { test_prfw_i_p_ai_d(); } catch (...) { std::cerr << "FAIL: prfw_i_p_ai_d" << std::endl; failed++; }
    try { test_prfw_i_p_bi_s(); } catch (...) { std::cerr << "FAIL: prfw_i_p_bi_s" << std::endl; failed++; }
    try { test_prfw_i_p_br_s(); } catch (...) { std::cerr << "FAIL: prfw_i_p_br_s" << std::endl; failed++; }
    try { test_prfw_i_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfw_i_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_prfw_i_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: prfw_i_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_prfw_i_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: prfw_i_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_psel_p_ppi_(); } catch (...) { std::cerr << "FAIL: psel_p_ppi_" << std::endl; failed++; }
    try { test_ptest__p_p_(); } catch (...) { std::cerr << "FAIL: ptest__p_p_" << std::endl; failed++; }
    try { test_ptrue_p_s_(); } catch (...) { std::cerr << "FAIL: ptrue_p_s_" << std::endl; failed++; }
    try { test_ptrue_pn_i_(); } catch (...) { std::cerr << "FAIL: ptrue_pn_i_" << std::endl; failed++; }
    try { test_ptrues_p_s_(); } catch (...) { std::cerr << "FAIL: ptrues_p_s_" << std::endl; failed++; }
    try { test_punpkhi_p_p_(); } catch (...) { std::cerr << "FAIL: punpkhi_p_p_" << std::endl; failed++; }
    try { test_punpklo_p_p_(); } catch (...) { std::cerr << "FAIL: punpklo_p_p_" << std::endl; failed++; }
    try { test_raddhnb_z_zz_(); } catch (...) { std::cerr << "FAIL: raddhnb_z_zz_" << std::endl; failed++; }
    try { test_raddhnt_z_zz_(); } catch (...) { std::cerr << "FAIL: raddhnt_z_zz_" << std::endl; failed++; }
    try { test_rax1_z_zz_(); } catch (...) { std::cerr << "FAIL: rax1_z_zz_" << std::endl; failed++; }
    try { test_rbit_z_p_z_m(); } catch (...) { std::cerr << "FAIL: rbit_z_p_z_m" << std::endl; failed++; }
    try { test_rbit_z_p_z_z(); } catch (...) { std::cerr << "FAIL: rbit_z_p_z_z" << std::endl; failed++; }
    try { test_rdffr_p_f_(); } catch (...) { std::cerr << "FAIL: rdffr_p_f_" << std::endl; failed++; }
    try { test_rdffr_p_p_f_(); } catch (...) { std::cerr << "FAIL: rdffr_p_p_f_" << std::endl; failed++; }
    try { test_rdffrs_p_p_f_(); } catch (...) { std::cerr << "FAIL: rdffrs_p_p_f_" << std::endl; failed++; }
    try { test_rdsvl_r_i_(); } catch (...) { std::cerr << "FAIL: rdsvl_r_i_" << std::endl; failed++; }
    try { test_rdvl_r_i_(); } catch (...) { std::cerr << "FAIL: rdvl_r_i_" << std::endl; failed++; }
    try { test_rev_p_p_(); } catch (...) { std::cerr << "FAIL: rev_p_p_" << std::endl; failed++; }
    try { test_rev_z_z_(); } catch (...) { std::cerr << "FAIL: rev_z_z_" << std::endl; failed++; }
    try { test_revb_z_z_m(); } catch (...) { std::cerr << "FAIL: revb_z_z_m" << std::endl; failed++; }
    try { test_revb_z_z_z(); } catch (...) { std::cerr << "FAIL: revb_z_z_z" << std::endl; failed++; }
    try { test_revh_z_z_m(); } catch (...) { std::cerr << "FAIL: revh_z_z_m" << std::endl; failed++; }
    try { test_revh_z_z_z(); } catch (...) { std::cerr << "FAIL: revh_z_z_z" << std::endl; failed++; }
    try { test_revw_z_z_m(); } catch (...) { std::cerr << "FAIL: revw_z_z_m" << std::endl; failed++; }
    try { test_revw_z_z_z(); } catch (...) { std::cerr << "FAIL: revw_z_z_z" << std::endl; failed++; }
    try { test_revd_z_p_z_m(); } catch (...) { std::cerr << "FAIL: revd_z_p_z_m" << std::endl; failed++; }
    try { test_revd_z_p_z_z(); } catch (...) { std::cerr << "FAIL: revd_z_p_z_z" << std::endl; failed++; }
    try { test_rshrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: rshrnb_z_zi_" << std::endl; failed++; }
    try { test_rshrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: rshrnt_z_zi_" << std::endl; failed++; }
    try { test_rsubhnb_z_zz_(); } catch (...) { std::cerr << "FAIL: rsubhnb_z_zz_" << std::endl; failed++; }
    try { test_rsubhnt_z_zz_(); } catch (...) { std::cerr << "FAIL: rsubhnt_z_zz_" << std::endl; failed++; }
    try { test_saba_z_zzz_(); } catch (...) { std::cerr << "FAIL: saba_z_zzz_" << std::endl; failed++; }
    try { test_sabal_z_zz_(); } catch (...) { std::cerr << "FAIL: sabal_z_zz_" << std::endl; failed++; }
    try { test_sabalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: sabalb_z_zzz_" << std::endl; failed++; }
    try { test_sabalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sabalt_z_zzz_" << std::endl; failed++; }
    try { test_sabd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sabd_z_p_zz_" << std::endl; failed++; }
    try { test_sabdlb_z_zz_(); } catch (...) { std::cerr << "FAIL: sabdlb_z_zz_" << std::endl; failed++; }
    try { test_sabdlt_z_zz_(); } catch (...) { std::cerr << "FAIL: sabdlt_z_zz_" << std::endl; failed++; }
    try { test_sadalp_z_p_z_(); } catch (...) { std::cerr << "FAIL: sadalp_z_p_z_" << std::endl; failed++; }
    try { test_saddlb_z_zz_(); } catch (...) { std::cerr << "FAIL: saddlb_z_zz_" << std::endl; failed++; }
    try { test_saddlbt_z_zz_(); } catch (...) { std::cerr << "FAIL: saddlbt_z_zz_" << std::endl; failed++; }
    try { test_saddlt_z_zz_(); } catch (...) { std::cerr << "FAIL: saddlt_z_zz_" << std::endl; failed++; }
    try { test_saddv_r_p_z_(); } catch (...) { std::cerr << "FAIL: saddv_r_p_z_" << std::endl; failed++; }
    try { test_saddwb_z_zz_(); } catch (...) { std::cerr << "FAIL: saddwb_z_zz_" << std::endl; failed++; }
    try { test_saddwt_z_zz_(); } catch (...) { std::cerr << "FAIL: saddwt_z_zz_" << std::endl; failed++; }
    try { test_sbclb_z_zzz_(); } catch (...) { std::cerr << "FAIL: sbclb_z_zzz_" << std::endl; failed++; }
    try { test_sbclt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sbclt_z_zzz_" << std::endl; failed++; }
    try { test_sclamp_z_zz_(); } catch (...) { std::cerr << "FAIL: sclamp_z_zz_" << std::endl; failed++; }
    try { test_scvtf_z_p_z_h2fp16(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_h2fp16" << std::endl; failed++; }
    try { test_scvtf_z_p_z_h2fp16z(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_h2fp16z" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2fp16(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2fp16" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2fp16z(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2fp16z" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2s(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2s" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2sz(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2sz" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2d(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2d" << std::endl; failed++; }
    try { test_scvtf_z_p_z_w2dz(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_w2dz" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2fp16(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2fp16" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2fp16z(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2fp16z" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2s(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2s" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2sz(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2sz" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2d(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2d" << std::endl; failed++; }
    try { test_scvtf_z_p_z_x2dz(); } catch (...) { std::cerr << "FAIL: scvtf_z_p_z_x2dz" << std::endl; failed++; }
    try { test_scvtf_z_z_(); } catch (...) { std::cerr << "FAIL: scvtf_z_z_" << std::endl; failed++; }
    try { test_scvtflt_z_z_(); } catch (...) { std::cerr << "FAIL: scvtflt_z_z_" << std::endl; failed++; }
    try { test_sdiv_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sdiv_z_p_zz_" << std::endl; failed++; }
    try { test_sdivr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sdivr_z_p_zz_" << std::endl; failed++; }
    try { test_sdot_z16_zzz_h(); } catch (...) { std::cerr << "FAIL: sdot_z16_zzz_h" << std::endl; failed++; }
    try { test_sdot_z32_zzz_(); } catch (...) { std::cerr << "FAIL: sdot_z32_zzz_" << std::endl; failed++; }
    try { test_sdot_z16_zzzi_h(); } catch (...) { std::cerr << "FAIL: sdot_z16_zzzi_h" << std::endl; failed++; }
    try { test_sdot_z32_zzzi_(); } catch (...) { std::cerr << "FAIL: sdot_z32_zzzi_" << std::endl; failed++; }
    try { test_sdot_z_zzz_(); } catch (...) { std::cerr << "FAIL: sdot_z_zzz_" << std::endl; failed++; }
    try { test_sdot_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sdot_z_zzzi_s" << std::endl; failed++; }
    try { test_sdot_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sdot_z_zzzi_d" << std::endl; failed++; }
    try { test_sel_p_p_pp_(); } catch (...) { std::cerr << "FAIL: sel_p_p_pp_" << std::endl; failed++; }
    try { test_sel_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sel_z_p_zz_" << std::endl; failed++; }
    try { test_setffr_f_(); } catch (...) { std::cerr << "FAIL: setffr_f_" << std::endl; failed++; }
    try { test_shadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: shadd_z_p_zz_" << std::endl; failed++; }
    try { test_shrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: shrnb_z_zi_" << std::endl; failed++; }
    try { test_shrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: shrnt_z_zi_" << std::endl; failed++; }
    try { test_shsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: shsub_z_p_zz_" << std::endl; failed++; }
    try { test_shsubr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: shsubr_z_p_zz_" << std::endl; failed++; }
    try { test_sli_z_zzi_(); } catch (...) { std::cerr << "FAIL: sli_z_zzi_" << std::endl; failed++; }
    try { test_sm4e_z_zz_(); } catch (...) { std::cerr << "FAIL: sm4e_z_zz_" << std::endl; failed++; }
    try { test_sm4ekey_z_zz_(); } catch (...) { std::cerr << "FAIL: sm4ekey_z_zz_" << std::endl; failed++; }
    try { test_smax_z_p_zz_(); } catch (...) { std::cerr << "FAIL: smax_z_p_zz_" << std::endl; failed++; }
    try { test_smax_z_zi_(); } catch (...) { std::cerr << "FAIL: smax_z_zi_" << std::endl; failed++; }
    try { test_smaxp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: smaxp_z_p_zz_" << std::endl; failed++; }
    try { test_smaxqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: smaxqv_z_p_z_" << std::endl; failed++; }
    try { test_smaxv_r_p_z_(); } catch (...) { std::cerr << "FAIL: smaxv_r_p_z_" << std::endl; failed++; }
    try { test_smin_z_p_zz_(); } catch (...) { std::cerr << "FAIL: smin_z_p_zz_" << std::endl; failed++; }
    try { test_smin_z_zi_(); } catch (...) { std::cerr << "FAIL: smin_z_zi_" << std::endl; failed++; }
    try { test_sminp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sminp_z_p_zz_" << std::endl; failed++; }
    try { test_sminqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: sminqv_z_p_z_" << std::endl; failed++; }
    try { test_sminv_r_p_z_(); } catch (...) { std::cerr << "FAIL: sminv_r_p_z_" << std::endl; failed++; }
    try { test_smlalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: smlalb_z_zzz_" << std::endl; failed++; }
    try { test_smlalb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: smlalb_z_zzzi_s" << std::endl; failed++; }
    try { test_smlalb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: smlalb_z_zzzi_d" << std::endl; failed++; }
    try { test_smlalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: smlalt_z_zzz_" << std::endl; failed++; }
    try { test_smlalt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: smlalt_z_zzzi_s" << std::endl; failed++; }
    try { test_smlalt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: smlalt_z_zzzi_d" << std::endl; failed++; }
    try { test_smlslb_z_zzz_(); } catch (...) { std::cerr << "FAIL: smlslb_z_zzz_" << std::endl; failed++; }
    try { test_smlslb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: smlslb_z_zzzi_s" << std::endl; failed++; }
    try { test_smlslb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: smlslb_z_zzzi_d" << std::endl; failed++; }
    try { test_smlslt_z_zzz_(); } catch (...) { std::cerr << "FAIL: smlslt_z_zzz_" << std::endl; failed++; }
    try { test_smlslt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: smlslt_z_zzzi_s" << std::endl; failed++; }
    try { test_smlslt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: smlslt_z_zzzi_d" << std::endl; failed++; }
    try { test_smmla_z_zzz_(); } catch (...) { std::cerr << "FAIL: smmla_z_zzz_" << std::endl; failed++; }
    try { test_smulh_z_p_zz_(); } catch (...) { std::cerr << "FAIL: smulh_z_p_zz_" << std::endl; failed++; }
    try { test_smulh_z_zz_(); } catch (...) { std::cerr << "FAIL: smulh_z_zz_" << std::endl; failed++; }
    try { test_smullb_z_zz_(); } catch (...) { std::cerr << "FAIL: smullb_z_zz_" << std::endl; failed++; }
    try { test_smullb_z_zzi_s(); } catch (...) { std::cerr << "FAIL: smullb_z_zzi_s" << std::endl; failed++; }
    try { test_smullb_z_zzi_d(); } catch (...) { std::cerr << "FAIL: smullb_z_zzi_d" << std::endl; failed++; }
    try { test_smullt_z_zz_(); } catch (...) { std::cerr << "FAIL: smullt_z_zz_" << std::endl; failed++; }
    try { test_smullt_z_zzi_s(); } catch (...) { std::cerr << "FAIL: smullt_z_zzi_s" << std::endl; failed++; }
    try { test_smullt_z_zzi_d(); } catch (...) { std::cerr << "FAIL: smullt_z_zzi_d" << std::endl; failed++; }
    try { test_splice_z_p_zz_con(); } catch (...) { std::cerr << "FAIL: splice_z_p_zz_con" << std::endl; failed++; }
    try { test_splice_z_p_zz_des(); } catch (...) { std::cerr << "FAIL: splice_z_p_zz_des" << std::endl; failed++; }
    try { test_sqabs_z_p_z_m(); } catch (...) { std::cerr << "FAIL: sqabs_z_p_z_m" << std::endl; failed++; }
    try { test_sqabs_z_p_z_z(); } catch (...) { std::cerr << "FAIL: sqabs_z_p_z_z" << std::endl; failed++; }
    try { test_sqadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqadd_z_p_zz_" << std::endl; failed++; }
    try { test_sqadd_z_zi_(); } catch (...) { std::cerr << "FAIL: sqadd_z_zi_" << std::endl; failed++; }
    try { test_sqadd_z_zz_(); } catch (...) { std::cerr << "FAIL: sqadd_z_zz_" << std::endl; failed++; }
    try { test_sqcadd_z_zz_(); } catch (...) { std::cerr << "FAIL: sqcadd_z_zz_" << std::endl; failed++; }
    try { test_sqcvtn_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqcvtn_z_mz2_" << std::endl; failed++; }
    try { test_sqcvtun_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqcvtun_z_mz2_" << std::endl; failed++; }
    try { test_sqdecb_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqdecb_r_rs_sx" << std::endl; failed++; }
    try { test_sqdecb_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqdecb_r_rs_x" << std::endl; failed++; }
    try { test_sqdecd_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqdecd_r_rs_sx" << std::endl; failed++; }
    try { test_sqdecd_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqdecd_r_rs_x" << std::endl; failed++; }
    try { test_sqdecd_z_zs_(); } catch (...) { std::cerr << "FAIL: sqdecd_z_zs_" << std::endl; failed++; }
    try { test_sqdech_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqdech_r_rs_sx" << std::endl; failed++; }
    try { test_sqdech_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqdech_r_rs_x" << std::endl; failed++; }
    try { test_sqdech_z_zs_(); } catch (...) { std::cerr << "FAIL: sqdech_z_zs_" << std::endl; failed++; }
    try { test_sqdecp_r_p_r_sx(); } catch (...) { std::cerr << "FAIL: sqdecp_r_p_r_sx" << std::endl; failed++; }
    try { test_sqdecp_r_p_r_x(); } catch (...) { std::cerr << "FAIL: sqdecp_r_p_r_x" << std::endl; failed++; }
    try { test_sqdecp_z_p_z_(); } catch (...) { std::cerr << "FAIL: sqdecp_z_p_z_" << std::endl; failed++; }
    try { test_sqdecw_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqdecw_r_rs_sx" << std::endl; failed++; }
    try { test_sqdecw_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqdecw_r_rs_x" << std::endl; failed++; }
    try { test_sqdecw_z_zs_(); } catch (...) { std::cerr << "FAIL: sqdecw_z_zs_" << std::endl; failed++; }
    try { test_sqdmlalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlalb_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlalb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqdmlalb_z_zzzi_s" << std::endl; failed++; }
    try { test_sqdmlalb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqdmlalb_z_zzzi_d" << std::endl; failed++; }
    try { test_sqdmlalbt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlalbt_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlalt_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlalt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqdmlalt_z_zzzi_s" << std::endl; failed++; }
    try { test_sqdmlalt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqdmlalt_z_zzzi_d" << std::endl; failed++; }
    try { test_sqdmlslb_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlslb_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlslb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqdmlslb_z_zzzi_s" << std::endl; failed++; }
    try { test_sqdmlslb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqdmlslb_z_zzzi_d" << std::endl; failed++; }
    try { test_sqdmlslbt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlslbt_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlslt_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqdmlslt_z_zzz_" << std::endl; failed++; }
    try { test_sqdmlslt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqdmlslt_z_zzzi_s" << std::endl; failed++; }
    try { test_sqdmlslt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqdmlslt_z_zzzi_d" << std::endl; failed++; }
    try { test_sqdmulh_z_zz_(); } catch (...) { std::cerr << "FAIL: sqdmulh_z_zz_" << std::endl; failed++; }
    try { test_sqdmulh_z_zzi_h(); } catch (...) { std::cerr << "FAIL: sqdmulh_z_zzi_h" << std::endl; failed++; }
    try { test_sqdmulh_z_zzi_s(); } catch (...) { std::cerr << "FAIL: sqdmulh_z_zzi_s" << std::endl; failed++; }
    try { test_sqdmulh_z_zzi_d(); } catch (...) { std::cerr << "FAIL: sqdmulh_z_zzi_d" << std::endl; failed++; }
    try { test_sqdmullb_z_zz_(); } catch (...) { std::cerr << "FAIL: sqdmullb_z_zz_" << std::endl; failed++; }
    try { test_sqdmullb_z_zzi_s(); } catch (...) { std::cerr << "FAIL: sqdmullb_z_zzi_s" << std::endl; failed++; }
    try { test_sqdmullb_z_zzi_d(); } catch (...) { std::cerr << "FAIL: sqdmullb_z_zzi_d" << std::endl; failed++; }
    try { test_sqdmullt_z_zz_(); } catch (...) { std::cerr << "FAIL: sqdmullt_z_zz_" << std::endl; failed++; }
    try { test_sqdmullt_z_zzi_s(); } catch (...) { std::cerr << "FAIL: sqdmullt_z_zzi_s" << std::endl; failed++; }
    try { test_sqdmullt_z_zzi_d(); } catch (...) { std::cerr << "FAIL: sqdmullt_z_zzi_d" << std::endl; failed++; }
    try { test_sqincb_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqincb_r_rs_sx" << std::endl; failed++; }
    try { test_sqincb_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqincb_r_rs_x" << std::endl; failed++; }
    try { test_sqincd_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqincd_r_rs_sx" << std::endl; failed++; }
    try { test_sqincd_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqincd_r_rs_x" << std::endl; failed++; }
    try { test_sqincd_z_zs_(); } catch (...) { std::cerr << "FAIL: sqincd_z_zs_" << std::endl; failed++; }
    try { test_sqinch_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqinch_r_rs_sx" << std::endl; failed++; }
    try { test_sqinch_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqinch_r_rs_x" << std::endl; failed++; }
    try { test_sqinch_z_zs_(); } catch (...) { std::cerr << "FAIL: sqinch_z_zs_" << std::endl; failed++; }
    try { test_sqincp_r_p_r_sx(); } catch (...) { std::cerr << "FAIL: sqincp_r_p_r_sx" << std::endl; failed++; }
    try { test_sqincp_r_p_r_x(); } catch (...) { std::cerr << "FAIL: sqincp_r_p_r_x" << std::endl; failed++; }
    try { test_sqincp_z_p_z_(); } catch (...) { std::cerr << "FAIL: sqincp_z_p_z_" << std::endl; failed++; }
    try { test_sqincw_r_rs_sx(); } catch (...) { std::cerr << "FAIL: sqincw_r_rs_sx" << std::endl; failed++; }
    try { test_sqincw_r_rs_x(); } catch (...) { std::cerr << "FAIL: sqincw_r_rs_x" << std::endl; failed++; }
    try { test_sqincw_z_zs_(); } catch (...) { std::cerr << "FAIL: sqincw_z_zs_" << std::endl; failed++; }
    try { test_sqneg_z_p_z_m(); } catch (...) { std::cerr << "FAIL: sqneg_z_p_z_m" << std::endl; failed++; }
    try { test_sqneg_z_p_z_z(); } catch (...) { std::cerr << "FAIL: sqneg_z_p_z_z" << std::endl; failed++; }
    try { test_sqrdcmlah_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqrdcmlah_z_zzz_" << std::endl; failed++; }
    try { test_sqrdcmlah_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: sqrdcmlah_z_zzzi_h" << std::endl; failed++; }
    try { test_sqrdcmlah_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqrdcmlah_z_zzzi_s" << std::endl; failed++; }
    try { test_sqrdmlah_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqrdmlah_z_zzz_" << std::endl; failed++; }
    try { test_sqrdmlah_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: sqrdmlah_z_zzzi_h" << std::endl; failed++; }
    try { test_sqrdmlah_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqrdmlah_z_zzzi_s" << std::endl; failed++; }
    try { test_sqrdmlah_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqrdmlah_z_zzzi_d" << std::endl; failed++; }
    try { test_sqrdmlsh_z_zzz_(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_z_zzz_" << std::endl; failed++; }
    try { test_sqrdmlsh_z_zzzi_h(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_z_zzzi_h" << std::endl; failed++; }
    try { test_sqrdmlsh_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_z_zzzi_s" << std::endl; failed++; }
    try { test_sqrdmlsh_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: sqrdmlsh_z_zzzi_d" << std::endl; failed++; }
    try { test_sqrdmulh_z_zz_(); } catch (...) { std::cerr << "FAIL: sqrdmulh_z_zz_" << std::endl; failed++; }
    try { test_sqrdmulh_z_zzi_h(); } catch (...) { std::cerr << "FAIL: sqrdmulh_z_zzi_h" << std::endl; failed++; }
    try { test_sqrdmulh_z_zzi_s(); } catch (...) { std::cerr << "FAIL: sqrdmulh_z_zzi_s" << std::endl; failed++; }
    try { test_sqrdmulh_z_zzi_d(); } catch (...) { std::cerr << "FAIL: sqrdmulh_z_zzi_d" << std::endl; failed++; }
    try { test_sqrshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqrshl_z_p_zz_" << std::endl; failed++; }
    try { test_sqrshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqrshlr_z_p_zz_" << std::endl; failed++; }
    try { test_sqrshrn_z_mz2_b(); } catch (...) { std::cerr << "FAIL: sqrshrn_z_mz2_b" << std::endl; failed++; }
    try { test_sqrshrn_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqrshrn_z_mz2_" << std::endl; failed++; }
    try { test_sqrshrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: sqrshrnb_z_zi_" << std::endl; failed++; }
    try { test_sqrshrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: sqrshrnt_z_zi_" << std::endl; failed++; }
    try { test_sqrshrun_z_mz2_b(); } catch (...) { std::cerr << "FAIL: sqrshrun_z_mz2_b" << std::endl; failed++; }
    try { test_sqrshrun_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqrshrun_z_mz2_" << std::endl; failed++; }
    try { test_sqrshrunb_z_zi_(); } catch (...) { std::cerr << "FAIL: sqrshrunb_z_zi_" << std::endl; failed++; }
    try { test_sqrshrunt_z_zi_(); } catch (...) { std::cerr << "FAIL: sqrshrunt_z_zi_" << std::endl; failed++; }
    try { test_sqshl_z_p_zi_(); } catch (...) { std::cerr << "FAIL: sqshl_z_p_zi_" << std::endl; failed++; }
    try { test_sqshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqshl_z_p_zz_" << std::endl; failed++; }
    try { test_sqshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqshlr_z_p_zz_" << std::endl; failed++; }
    try { test_sqshlu_z_p_zi_(); } catch (...) { std::cerr << "FAIL: sqshlu_z_p_zi_" << std::endl; failed++; }
    try { test_sqshrn_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqshrn_z_mz2_" << std::endl; failed++; }
    try { test_sqshrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: sqshrnb_z_zi_" << std::endl; failed++; }
    try { test_sqshrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: sqshrnt_z_zi_" << std::endl; failed++; }
    try { test_sqshrun_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqshrun_z_mz2_" << std::endl; failed++; }
    try { test_sqshrunb_z_zi_(); } catch (...) { std::cerr << "FAIL: sqshrunb_z_zi_" << std::endl; failed++; }
    try { test_sqshrunt_z_zi_(); } catch (...) { std::cerr << "FAIL: sqshrunt_z_zi_" << std::endl; failed++; }
    try { test_sqsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqsub_z_p_zz_" << std::endl; failed++; }
    try { test_sqsub_z_zi_(); } catch (...) { std::cerr << "FAIL: sqsub_z_zi_" << std::endl; failed++; }
    try { test_sqsub_z_zz_(); } catch (...) { std::cerr << "FAIL: sqsub_z_zz_" << std::endl; failed++; }
    try { test_sqsubr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sqsubr_z_p_zz_" << std::endl; failed++; }
    try { test_sqxtnb_z_zz_(); } catch (...) { std::cerr << "FAIL: sqxtnb_z_zz_" << std::endl; failed++; }
    try { test_sqxtnt_z_zz_(); } catch (...) { std::cerr << "FAIL: sqxtnt_z_zz_" << std::endl; failed++; }
    try { test_sqxtunb_z_zz_(); } catch (...) { std::cerr << "FAIL: sqxtunb_z_zz_" << std::endl; failed++; }
    try { test_sqxtunt_z_zz_(); } catch (...) { std::cerr << "FAIL: sqxtunt_z_zz_" << std::endl; failed++; }
    try { test_srhadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: srhadd_z_p_zz_" << std::endl; failed++; }
    try { test_sri_z_zzi_(); } catch (...) { std::cerr << "FAIL: sri_z_zzi_" << std::endl; failed++; }
    try { test_srshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: srshl_z_p_zz_" << std::endl; failed++; }
    try { test_srshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: srshlr_z_p_zz_" << std::endl; failed++; }
    try { test_srshr_z_p_zi_(); } catch (...) { std::cerr << "FAIL: srshr_z_p_zi_" << std::endl; failed++; }
    try { test_srsra_z_zi_(); } catch (...) { std::cerr << "FAIL: srsra_z_zi_" << std::endl; failed++; }
    try { test_sshllb_z_zi_(); } catch (...) { std::cerr << "FAIL: sshllb_z_zi_" << std::endl; failed++; }
    try { test_sshllt_z_zi_(); } catch (...) { std::cerr << "FAIL: sshllt_z_zi_" << std::endl; failed++; }
    try { test_ssra_z_zi_(); } catch (...) { std::cerr << "FAIL: ssra_z_zi_" << std::endl; failed++; }
    try { test_ssublb_z_zz_(); } catch (...) { std::cerr << "FAIL: ssublb_z_zz_" << std::endl; failed++; }
    try { test_ssublbt_z_zz_(); } catch (...) { std::cerr << "FAIL: ssublbt_z_zz_" << std::endl; failed++; }
    try { test_ssublt_z_zz_(); } catch (...) { std::cerr << "FAIL: ssublt_z_zz_" << std::endl; failed++; }
    try { test_ssubltb_z_zz_(); } catch (...) { std::cerr << "FAIL: ssubltb_z_zz_" << std::endl; failed++; }
    try { test_ssubwb_z_zz_(); } catch (...) { std::cerr << "FAIL: ssubwb_z_zz_" << std::endl; failed++; }
    try { test_ssubwt_z_zz_(); } catch (...) { std::cerr << "FAIL: ssubwt_z_zz_" << std::endl; failed++; }
    try { test_st1b_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: st1b_z_p_ai_s" << std::endl; failed++; }
    try { test_st1b_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: st1b_z_p_ai_d" << std::endl; failed++; }
    try { test_st1b_z_p_bi_(); } catch (...) { std::cerr << "FAIL: st1b_z_p_bi_" << std::endl; failed++; }
    try { test_st1b_z_p_br_(); } catch (...) { std::cerr << "FAIL: st1b_z_p_br_" << std::endl; failed++; }
    try { test_st1b_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1b_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_st1b_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1b_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_st1b_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: st1b_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_st1d_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: st1d_z_p_ai_d" << std::endl; failed++; }
    try { test_st1d_z_p_bi_(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bi_" << std::endl; failed++; }
    try { test_st1d_z_p_bi_u128(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bi_u128" << std::endl; failed++; }
    try { test_st1d_z_p_br_(); } catch (...) { std::cerr << "FAIL: st1d_z_p_br_" << std::endl; failed++; }
    try { test_st1d_z_p_br_u128(); } catch (...) { std::cerr << "FAIL: st1d_z_p_br_u128" << std::endl; failed++; }
    try { test_st1d_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_st1d_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_st1d_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_st1d_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: st1d_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_st1h_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: st1h_z_p_ai_s" << std::endl; failed++; }
    try { test_st1h_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: st1h_z_p_ai_d" << std::endl; failed++; }
    try { test_st1h_z_p_bi_(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bi_" << std::endl; failed++; }
    try { test_st1h_z_p_br_(); } catch (...) { std::cerr << "FAIL: st1h_z_p_br_" << std::endl; failed++; }
    try { test_st1h_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_st1h_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_st1h_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_st1h_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_st1h_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_st1h_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_st1q_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: st1q_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_st1w_z_p_ai_s(); } catch (...) { std::cerr << "FAIL: st1w_z_p_ai_s" << std::endl; failed++; }
    try { test_st1w_z_p_ai_d(); } catch (...) { std::cerr << "FAIL: st1w_z_p_ai_d" << std::endl; failed++; }
    try { test_st1w_z_p_bi_(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bi_" << std::endl; failed++; }
    try { test_st1w_z_p_bi_u128(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bi_u128" << std::endl; failed++; }
    try { test_st1w_z_p_br_(); } catch (...) { std::cerr << "FAIL: st1w_z_p_br_" << std::endl; failed++; }
    try { test_st1w_z_p_br_u128(); } catch (...) { std::cerr << "FAIL: st1w_z_p_br_u128" << std::endl; failed++; }
    try { test_st1w_z_p_bz_s_x32_scaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_s_x32_scaled" << std::endl; failed++; }
    try { test_st1w_z_p_bz_d_x32_scaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_d_x32_scaled" << std::endl; failed++; }
    try { test_st1w_z_p_bz_d_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_d_x32_unscaled" << std::endl; failed++; }
    try { test_st1w_z_p_bz_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_s_x32_unscaled" << std::endl; failed++; }
    try { test_st1w_z_p_bz_d_64_scaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_d_64_scaled" << std::endl; failed++; }
    try { test_st1w_z_p_bz_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: st1w_z_p_bz_d_64_unscaled" << std::endl; failed++; }
    try { test_st2b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st2b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st2b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st2b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st2d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st2d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st2d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st2d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st2h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st2h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st2h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st2h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st2q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st2q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st2q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st2q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st2w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st2w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st2w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st2w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st3b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st3b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st3b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st3b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st3d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st3d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st3d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st3d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st3h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st3h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st3h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st3h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st3q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st3q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st3q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st3q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st3w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st3w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st3w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st3w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st4b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st4b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st4b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st4b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st4d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st4d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st4d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st4d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st4h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st4h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st4h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st4h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st4q_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st4q_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st4q_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st4q_z_p_br_contiguous" << std::endl; failed++; }
    try { test_st4w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: st4w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_st4w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: st4w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_stnt1b_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1b_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_stnt1b_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1b_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_stnt1b_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1b_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_stnt1b_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1b_z_p_br_contiguous" << std::endl; failed++; }
    try { test_stnt1d_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1d_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_stnt1d_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1d_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_stnt1d_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1d_z_p_br_contiguous" << std::endl; failed++; }
    try { test_stnt1h_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1h_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_stnt1h_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1h_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_stnt1h_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1h_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_stnt1h_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1h_z_p_br_contiguous" << std::endl; failed++; }
    try { test_stnt1w_z_p_ar_s_x32_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1w_z_p_ar_s_x32_unscaled" << std::endl; failed++; }
    try { test_stnt1w_z_p_ar_d_64_unscaled(); } catch (...) { std::cerr << "FAIL: stnt1w_z_p_ar_d_64_unscaled" << std::endl; failed++; }
    try { test_stnt1w_z_p_bi_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1w_z_p_bi_contiguous" << std::endl; failed++; }
    try { test_stnt1w_z_p_br_contiguous(); } catch (...) { std::cerr << "FAIL: stnt1w_z_p_br_contiguous" << std::endl; failed++; }
    try { test_str_p_bi_(); } catch (...) { std::cerr << "FAIL: str_p_bi_" << std::endl; failed++; }
    try { test_str_z_bi_(); } catch (...) { std::cerr << "FAIL: str_z_bi_" << std::endl; failed++; }
    try { test_sub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: sub_z_p_zz_" << std::endl; failed++; }
    try { test_sub_z_zi_(); } catch (...) { std::cerr << "FAIL: sub_z_zi_" << std::endl; failed++; }
    try { test_sub_z_zz_(); } catch (...) { std::cerr << "FAIL: sub_z_zz_" << std::endl; failed++; }
    try { test_subhnb_z_zz_(); } catch (...) { std::cerr << "FAIL: subhnb_z_zz_" << std::endl; failed++; }
    try { test_subhnt_z_zz_(); } catch (...) { std::cerr << "FAIL: subhnt_z_zz_" << std::endl; failed++; }
    try { test_subp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: subp_z_p_zz_" << std::endl; failed++; }
    try { test_subpt_z_p_zz_(); } catch (...) { std::cerr << "FAIL: subpt_z_p_zz_" << std::endl; failed++; }
    try { test_subpt_z_zz_(); } catch (...) { std::cerr << "FAIL: subpt_z_zz_" << std::endl; failed++; }
    try { test_subr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: subr_z_p_zz_" << std::endl; failed++; }
    try { test_subr_z_zi_(); } catch (...) { std::cerr << "FAIL: subr_z_zi_" << std::endl; failed++; }
    try { test_sudot_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: sudot_z_zzzi_s" << std::endl; failed++; }
    try { test_sunpkhi_z_z_(); } catch (...) { std::cerr << "FAIL: sunpkhi_z_z_" << std::endl; failed++; }
    try { test_sunpklo_z_z_(); } catch (...) { std::cerr << "FAIL: sunpklo_z_z_" << std::endl; failed++; }
    try { test_suqadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: suqadd_z_p_zz_" << std::endl; failed++; }
    try { test_sxtb_z_p_z_m(); } catch (...) { std::cerr << "FAIL: sxtb_z_p_z_m" << std::endl; failed++; }
    try { test_sxtb_z_p_z_z(); } catch (...) { std::cerr << "FAIL: sxtb_z_p_z_z" << std::endl; failed++; }
    try { test_sxth_z_p_z_m(); } catch (...) { std::cerr << "FAIL: sxth_z_p_z_m" << std::endl; failed++; }
    try { test_sxth_z_p_z_z(); } catch (...) { std::cerr << "FAIL: sxth_z_p_z_z" << std::endl; failed++; }
    try { test_sxtw_z_p_z_m(); } catch (...) { std::cerr << "FAIL: sxtw_z_p_z_m" << std::endl; failed++; }
    try { test_sxtw_z_p_z_z(); } catch (...) { std::cerr << "FAIL: sxtw_z_p_z_z" << std::endl; failed++; }
    try { test_tbl_z_zz_1(); } catch (...) { std::cerr << "FAIL: tbl_z_zz_1" << std::endl; failed++; }
    try { test_tbl_z_zz_2(); } catch (...) { std::cerr << "FAIL: tbl_z_zz_2" << std::endl; failed++; }
    try { test_tblq_z_zz_(); } catch (...) { std::cerr << "FAIL: tblq_z_zz_" << std::endl; failed++; }
    try { test_tbx_z_zz_(); } catch (...) { std::cerr << "FAIL: tbx_z_zz_" << std::endl; failed++; }
    try { test_tbxq_z_zz_(); } catch (...) { std::cerr << "FAIL: tbxq_z_zz_" << std::endl; failed++; }
    try { test_trn1_p_pp_(); } catch (...) { std::cerr << "FAIL: trn1_p_pp_" << std::endl; failed++; }
    try { test_trn2_p_pp_(); } catch (...) { std::cerr << "FAIL: trn2_p_pp_" << std::endl; failed++; }
    try { test_trn1_z_zz_(); } catch (...) { std::cerr << "FAIL: trn1_z_zz_" << std::endl; failed++; }
    try { test_trn1_z_zz_q(); } catch (...) { std::cerr << "FAIL: trn1_z_zz_q" << std::endl; failed++; }
    try { test_trn2_z_zz_(); } catch (...) { std::cerr << "FAIL: trn2_z_zz_" << std::endl; failed++; }
    try { test_trn2_z_zz_q(); } catch (...) { std::cerr << "FAIL: trn2_z_zz_q" << std::endl; failed++; }
    try { test_uaba_z_zzz_(); } catch (...) { std::cerr << "FAIL: uaba_z_zzz_" << std::endl; failed++; }
    try { test_uabal_z_zz_(); } catch (...) { std::cerr << "FAIL: uabal_z_zz_" << std::endl; failed++; }
    try { test_uabalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: uabalb_z_zzz_" << std::endl; failed++; }
    try { test_uabalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: uabalt_z_zzz_" << std::endl; failed++; }
    try { test_uabd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uabd_z_p_zz_" << std::endl; failed++; }
    try { test_uabdlb_z_zz_(); } catch (...) { std::cerr << "FAIL: uabdlb_z_zz_" << std::endl; failed++; }
    try { test_uabdlt_z_zz_(); } catch (...) { std::cerr << "FAIL: uabdlt_z_zz_" << std::endl; failed++; }
    try { test_uadalp_z_p_z_(); } catch (...) { std::cerr << "FAIL: uadalp_z_p_z_" << std::endl; failed++; }
    try { test_uaddlb_z_zz_(); } catch (...) { std::cerr << "FAIL: uaddlb_z_zz_" << std::endl; failed++; }
    try { test_uaddlt_z_zz_(); } catch (...) { std::cerr << "FAIL: uaddlt_z_zz_" << std::endl; failed++; }
    try { test_uaddv_r_p_z_(); } catch (...) { std::cerr << "FAIL: uaddv_r_p_z_" << std::endl; failed++; }
    try { test_uaddwb_z_zz_(); } catch (...) { std::cerr << "FAIL: uaddwb_z_zz_" << std::endl; failed++; }
    try { test_uaddwt_z_zz_(); } catch (...) { std::cerr << "FAIL: uaddwt_z_zz_" << std::endl; failed++; }
    try { test_uclamp_z_zz_(); } catch (...) { std::cerr << "FAIL: uclamp_z_zz_" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_h2fp16(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_h2fp16" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_h2fp16z(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_h2fp16z" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2fp16(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2fp16" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2fp16z(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2fp16z" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2s(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2s" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2sz(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2sz" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2d(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2d" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_w2dz(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_w2dz" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2fp16(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2fp16" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2fp16z(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2fp16z" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2s(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2s" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2sz(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2sz" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2d(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2d" << std::endl; failed++; }
    try { test_ucvtf_z_p_z_x2dz(); } catch (...) { std::cerr << "FAIL: ucvtf_z_p_z_x2dz" << std::endl; failed++; }
    try { test_ucvtf_z_z_(); } catch (...) { std::cerr << "FAIL: ucvtf_z_z_" << std::endl; failed++; }
    try { test_ucvtflt_z_z_(); } catch (...) { std::cerr << "FAIL: ucvtflt_z_z_" << std::endl; failed++; }
    try { test_udiv_z_p_zz_(); } catch (...) { std::cerr << "FAIL: udiv_z_p_zz_" << std::endl; failed++; }
    try { test_udivr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: udivr_z_p_zz_" << std::endl; failed++; }
    try { test_udot_z16_zzz_h(); } catch (...) { std::cerr << "FAIL: udot_z16_zzz_h" << std::endl; failed++; }
    try { test_udot_z32_zzz_(); } catch (...) { std::cerr << "FAIL: udot_z32_zzz_" << std::endl; failed++; }
    try { test_udot_z16_zzzi_h(); } catch (...) { std::cerr << "FAIL: udot_z16_zzzi_h" << std::endl; failed++; }
    try { test_udot_z32_zzzi_(); } catch (...) { std::cerr << "FAIL: udot_z32_zzzi_" << std::endl; failed++; }
    try { test_udot_z_zzz_(); } catch (...) { std::cerr << "FAIL: udot_z_zzz_" << std::endl; failed++; }
    try { test_udot_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: udot_z_zzzi_s" << std::endl; failed++; }
    try { test_udot_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: udot_z_zzzi_d" << std::endl; failed++; }
    try { test_uhadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uhadd_z_p_zz_" << std::endl; failed++; }
    try { test_uhsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uhsub_z_p_zz_" << std::endl; failed++; }
    try { test_uhsubr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uhsubr_z_p_zz_" << std::endl; failed++; }
    try { test_umax_z_p_zz_(); } catch (...) { std::cerr << "FAIL: umax_z_p_zz_" << std::endl; failed++; }
    try { test_umax_z_zi_(); } catch (...) { std::cerr << "FAIL: umax_z_zi_" << std::endl; failed++; }
    try { test_umaxp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: umaxp_z_p_zz_" << std::endl; failed++; }
    try { test_umaxqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: umaxqv_z_p_z_" << std::endl; failed++; }
    try { test_umaxv_r_p_z_(); } catch (...) { std::cerr << "FAIL: umaxv_r_p_z_" << std::endl; failed++; }
    try { test_umin_z_p_zz_(); } catch (...) { std::cerr << "FAIL: umin_z_p_zz_" << std::endl; failed++; }
    try { test_umin_z_zi_(); } catch (...) { std::cerr << "FAIL: umin_z_zi_" << std::endl; failed++; }
    try { test_uminp_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uminp_z_p_zz_" << std::endl; failed++; }
    try { test_uminqv_z_p_z_(); } catch (...) { std::cerr << "FAIL: uminqv_z_p_z_" << std::endl; failed++; }
    try { test_uminv_r_p_z_(); } catch (...) { std::cerr << "FAIL: uminv_r_p_z_" << std::endl; failed++; }
    try { test_umlalb_z_zzz_(); } catch (...) { std::cerr << "FAIL: umlalb_z_zzz_" << std::endl; failed++; }
    try { test_umlalb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: umlalb_z_zzzi_s" << std::endl; failed++; }
    try { test_umlalb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: umlalb_z_zzzi_d" << std::endl; failed++; }
    try { test_umlalt_z_zzz_(); } catch (...) { std::cerr << "FAIL: umlalt_z_zzz_" << std::endl; failed++; }
    try { test_umlalt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: umlalt_z_zzzi_s" << std::endl; failed++; }
    try { test_umlalt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: umlalt_z_zzzi_d" << std::endl; failed++; }
    try { test_umlslb_z_zzz_(); } catch (...) { std::cerr << "FAIL: umlslb_z_zzz_" << std::endl; failed++; }
    try { test_umlslb_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: umlslb_z_zzzi_s" << std::endl; failed++; }
    try { test_umlslb_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: umlslb_z_zzzi_d" << std::endl; failed++; }
    try { test_umlslt_z_zzz_(); } catch (...) { std::cerr << "FAIL: umlslt_z_zzz_" << std::endl; failed++; }
    try { test_umlslt_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: umlslt_z_zzzi_s" << std::endl; failed++; }
    try { test_umlslt_z_zzzi_d(); } catch (...) { std::cerr << "FAIL: umlslt_z_zzzi_d" << std::endl; failed++; }
    try { test_ummla_z_zzz_(); } catch (...) { std::cerr << "FAIL: ummla_z_zzz_" << std::endl; failed++; }
    try { test_umulh_z_p_zz_(); } catch (...) { std::cerr << "FAIL: umulh_z_p_zz_" << std::endl; failed++; }
    try { test_umulh_z_zz_(); } catch (...) { std::cerr << "FAIL: umulh_z_zz_" << std::endl; failed++; }
    try { test_umullb_z_zz_(); } catch (...) { std::cerr << "FAIL: umullb_z_zz_" << std::endl; failed++; }
    try { test_umullb_z_zzi_s(); } catch (...) { std::cerr << "FAIL: umullb_z_zzi_s" << std::endl; failed++; }
    try { test_umullb_z_zzi_d(); } catch (...) { std::cerr << "FAIL: umullb_z_zzi_d" << std::endl; failed++; }
    try { test_umullt_z_zz_(); } catch (...) { std::cerr << "FAIL: umullt_z_zz_" << std::endl; failed++; }
    try { test_umullt_z_zzi_s(); } catch (...) { std::cerr << "FAIL: umullt_z_zzi_s" << std::endl; failed++; }
    try { test_umullt_z_zzi_d(); } catch (...) { std::cerr << "FAIL: umullt_z_zzi_d" << std::endl; failed++; }
    try { test_uqadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqadd_z_p_zz_" << std::endl; failed++; }
    try { test_uqadd_z_zi_(); } catch (...) { std::cerr << "FAIL: uqadd_z_zi_" << std::endl; failed++; }
    try { test_uqadd_z_zz_(); } catch (...) { std::cerr << "FAIL: uqadd_z_zz_" << std::endl; failed++; }
    try { test_uqcvtn_z_mz2_(); } catch (...) { std::cerr << "FAIL: uqcvtn_z_mz2_" << std::endl; failed++; }
    try { test_uqdecb_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqdecb_r_rs_uw" << std::endl; failed++; }
    try { test_uqdecb_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqdecb_r_rs_x" << std::endl; failed++; }
    try { test_uqdecd_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqdecd_r_rs_uw" << std::endl; failed++; }
    try { test_uqdecd_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqdecd_r_rs_x" << std::endl; failed++; }
    try { test_uqdecd_z_zs_(); } catch (...) { std::cerr << "FAIL: uqdecd_z_zs_" << std::endl; failed++; }
    try { test_uqdech_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqdech_r_rs_uw" << std::endl; failed++; }
    try { test_uqdech_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqdech_r_rs_x" << std::endl; failed++; }
    try { test_uqdech_z_zs_(); } catch (...) { std::cerr << "FAIL: uqdech_z_zs_" << std::endl; failed++; }
    try { test_uqdecp_r_p_r_uw(); } catch (...) { std::cerr << "FAIL: uqdecp_r_p_r_uw" << std::endl; failed++; }
    try { test_uqdecp_r_p_r_x(); } catch (...) { std::cerr << "FAIL: uqdecp_r_p_r_x" << std::endl; failed++; }
    try { test_uqdecp_z_p_z_(); } catch (...) { std::cerr << "FAIL: uqdecp_z_p_z_" << std::endl; failed++; }
    try { test_uqdecw_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqdecw_r_rs_uw" << std::endl; failed++; }
    try { test_uqdecw_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqdecw_r_rs_x" << std::endl; failed++; }
    try { test_uqdecw_z_zs_(); } catch (...) { std::cerr << "FAIL: uqdecw_z_zs_" << std::endl; failed++; }
    try { test_uqincb_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqincb_r_rs_uw" << std::endl; failed++; }
    try { test_uqincb_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqincb_r_rs_x" << std::endl; failed++; }
    try { test_uqincd_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqincd_r_rs_uw" << std::endl; failed++; }
    try { test_uqincd_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqincd_r_rs_x" << std::endl; failed++; }
    try { test_uqincd_z_zs_(); } catch (...) { std::cerr << "FAIL: uqincd_z_zs_" << std::endl; failed++; }
    try { test_uqinch_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqinch_r_rs_uw" << std::endl; failed++; }
    try { test_uqinch_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqinch_r_rs_x" << std::endl; failed++; }
    try { test_uqinch_z_zs_(); } catch (...) { std::cerr << "FAIL: uqinch_z_zs_" << std::endl; failed++; }
    try { test_uqincp_r_p_r_uw(); } catch (...) { std::cerr << "FAIL: uqincp_r_p_r_uw" << std::endl; failed++; }
    try { test_uqincp_r_p_r_x(); } catch (...) { std::cerr << "FAIL: uqincp_r_p_r_x" << std::endl; failed++; }
    try { test_uqincp_z_p_z_(); } catch (...) { std::cerr << "FAIL: uqincp_z_p_z_" << std::endl; failed++; }
    try { test_uqincw_r_rs_uw(); } catch (...) { std::cerr << "FAIL: uqincw_r_rs_uw" << std::endl; failed++; }
    try { test_uqincw_r_rs_x(); } catch (...) { std::cerr << "FAIL: uqincw_r_rs_x" << std::endl; failed++; }
    try { test_uqincw_z_zs_(); } catch (...) { std::cerr << "FAIL: uqincw_z_zs_" << std::endl; failed++; }
    try { test_uqrshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqrshl_z_p_zz_" << std::endl; failed++; }
    try { test_uqrshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqrshlr_z_p_zz_" << std::endl; failed++; }
    try { test_uqrshrn_z_mz2_b(); } catch (...) { std::cerr << "FAIL: uqrshrn_z_mz2_b" << std::endl; failed++; }
    try { test_uqrshrn_z_mz2_(); } catch (...) { std::cerr << "FAIL: uqrshrn_z_mz2_" << std::endl; failed++; }
    try { test_uqrshrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: uqrshrnb_z_zi_" << std::endl; failed++; }
    try { test_uqrshrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: uqrshrnt_z_zi_" << std::endl; failed++; }
    try { test_uqshl_z_p_zi_(); } catch (...) { std::cerr << "FAIL: uqshl_z_p_zi_" << std::endl; failed++; }
    try { test_uqshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqshl_z_p_zz_" << std::endl; failed++; }
    try { test_uqshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqshlr_z_p_zz_" << std::endl; failed++; }
    try { test_uqshrn_z_mz2_(); } catch (...) { std::cerr << "FAIL: uqshrn_z_mz2_" << std::endl; failed++; }
    try { test_uqshrnb_z_zi_(); } catch (...) { std::cerr << "FAIL: uqshrnb_z_zi_" << std::endl; failed++; }
    try { test_uqshrnt_z_zi_(); } catch (...) { std::cerr << "FAIL: uqshrnt_z_zi_" << std::endl; failed++; }
    try { test_uqsub_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqsub_z_p_zz_" << std::endl; failed++; }
    try { test_uqsub_z_zi_(); } catch (...) { std::cerr << "FAIL: uqsub_z_zi_" << std::endl; failed++; }
    try { test_uqsub_z_zz_(); } catch (...) { std::cerr << "FAIL: uqsub_z_zz_" << std::endl; failed++; }
    try { test_uqsubr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: uqsubr_z_p_zz_" << std::endl; failed++; }
    try { test_uqxtnb_z_zz_(); } catch (...) { std::cerr << "FAIL: uqxtnb_z_zz_" << std::endl; failed++; }
    try { test_uqxtnt_z_zz_(); } catch (...) { std::cerr << "FAIL: uqxtnt_z_zz_" << std::endl; failed++; }
    try { test_urecpe_z_p_z_m(); } catch (...) { std::cerr << "FAIL: urecpe_z_p_z_m" << std::endl; failed++; }
    try { test_urecpe_z_p_z_z(); } catch (...) { std::cerr << "FAIL: urecpe_z_p_z_z" << std::endl; failed++; }
    try { test_urhadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: urhadd_z_p_zz_" << std::endl; failed++; }
    try { test_urshl_z_p_zz_(); } catch (...) { std::cerr << "FAIL: urshl_z_p_zz_" << std::endl; failed++; }
    try { test_urshlr_z_p_zz_(); } catch (...) { std::cerr << "FAIL: urshlr_z_p_zz_" << std::endl; failed++; }
    try { test_urshr_z_p_zi_(); } catch (...) { std::cerr << "FAIL: urshr_z_p_zi_" << std::endl; failed++; }
    try { test_ursqrte_z_p_z_m(); } catch (...) { std::cerr << "FAIL: ursqrte_z_p_z_m" << std::endl; failed++; }
    try { test_ursqrte_z_p_z_z(); } catch (...) { std::cerr << "FAIL: ursqrte_z_p_z_z" << std::endl; failed++; }
    try { test_ursra_z_zi_(); } catch (...) { std::cerr << "FAIL: ursra_z_zi_" << std::endl; failed++; }
    try { test_usdot_z_zzz_s(); } catch (...) { std::cerr << "FAIL: usdot_z_zzz_s" << std::endl; failed++; }
    try { test_usdot_z_zzzi_s(); } catch (...) { std::cerr << "FAIL: usdot_z_zzzi_s" << std::endl; failed++; }
    try { test_ushllb_z_zi_(); } catch (...) { std::cerr << "FAIL: ushllb_z_zi_" << std::endl; failed++; }
    try { test_ushllt_z_zi_(); } catch (...) { std::cerr << "FAIL: ushllt_z_zi_" << std::endl; failed++; }
    try { test_usmmla_z_zzz_(); } catch (...) { std::cerr << "FAIL: usmmla_z_zzz_" << std::endl; failed++; }
    try { test_usqadd_z_p_zz_(); } catch (...) { std::cerr << "FAIL: usqadd_z_p_zz_" << std::endl; failed++; }
    try { test_usra_z_zi_(); } catch (...) { std::cerr << "FAIL: usra_z_zi_" << std::endl; failed++; }
    try { test_usublb_z_zz_(); } catch (...) { std::cerr << "FAIL: usublb_z_zz_" << std::endl; failed++; }
    try { test_usublt_z_zz_(); } catch (...) { std::cerr << "FAIL: usublt_z_zz_" << std::endl; failed++; }
    try { test_usubwb_z_zz_(); } catch (...) { std::cerr << "FAIL: usubwb_z_zz_" << std::endl; failed++; }
    try { test_usubwt_z_zz_(); } catch (...) { std::cerr << "FAIL: usubwt_z_zz_" << std::endl; failed++; }
    try { test_uunpkhi_z_z_(); } catch (...) { std::cerr << "FAIL: uunpkhi_z_z_" << std::endl; failed++; }
    try { test_uunpklo_z_z_(); } catch (...) { std::cerr << "FAIL: uunpklo_z_z_" << std::endl; failed++; }
    try { test_uxtb_z_p_z_m(); } catch (...) { std::cerr << "FAIL: uxtb_z_p_z_m" << std::endl; failed++; }
    try { test_uxtb_z_p_z_z(); } catch (...) { std::cerr << "FAIL: uxtb_z_p_z_z" << std::endl; failed++; }
    try { test_uxth_z_p_z_m(); } catch (...) { std::cerr << "FAIL: uxth_z_p_z_m" << std::endl; failed++; }
    try { test_uxth_z_p_z_z(); } catch (...) { std::cerr << "FAIL: uxth_z_p_z_z" << std::endl; failed++; }
    try { test_uxtw_z_p_z_m(); } catch (...) { std::cerr << "FAIL: uxtw_z_p_z_m" << std::endl; failed++; }
    try { test_uxtw_z_p_z_z(); } catch (...) { std::cerr << "FAIL: uxtw_z_p_z_z" << std::endl; failed++; }
    try { test_uzp1_p_pp_(); } catch (...) { std::cerr << "FAIL: uzp1_p_pp_" << std::endl; failed++; }
    try { test_uzp2_p_pp_(); } catch (...) { std::cerr << "FAIL: uzp2_p_pp_" << std::endl; failed++; }
    try { test_uzp1_z_zz_(); } catch (...) { std::cerr << "FAIL: uzp1_z_zz_" << std::endl; failed++; }
    try { test_uzp1_z_zz_q(); } catch (...) { std::cerr << "FAIL: uzp1_z_zz_q" << std::endl; failed++; }
    try { test_uzp2_z_zz_(); } catch (...) { std::cerr << "FAIL: uzp2_z_zz_" << std::endl; failed++; }
    try { test_uzp2_z_zz_q(); } catch (...) { std::cerr << "FAIL: uzp2_z_zz_q" << std::endl; failed++; }
    try { test_uzpq1_z_zz_(); } catch (...) { std::cerr << "FAIL: uzpq1_z_zz_" << std::endl; failed++; }
    try { test_uzpq2_z_zz_(); } catch (...) { std::cerr << "FAIL: uzpq2_z_zz_" << std::endl; failed++; }
    try { test_whilege_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilege_p_p_rr_" << std::endl; failed++; }
    try { test_whilege_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilege_pn_rr_" << std::endl; failed++; }
    try { test_whilege_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilege_pp_rr_" << std::endl; failed++; }
    try { test_whilegt_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilegt_p_p_rr_" << std::endl; failed++; }
    try { test_whilegt_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilegt_pn_rr_" << std::endl; failed++; }
    try { test_whilegt_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilegt_pp_rr_" << std::endl; failed++; }
    try { test_whilehi_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilehi_p_p_rr_" << std::endl; failed++; }
    try { test_whilehi_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilehi_pn_rr_" << std::endl; failed++; }
    try { test_whilehi_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilehi_pp_rr_" << std::endl; failed++; }
    try { test_whilehs_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilehs_p_p_rr_" << std::endl; failed++; }
    try { test_whilehs_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilehs_pn_rr_" << std::endl; failed++; }
    try { test_whilehs_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilehs_pp_rr_" << std::endl; failed++; }
    try { test_whilele_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilele_p_p_rr_" << std::endl; failed++; }
    try { test_whilele_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilele_pn_rr_" << std::endl; failed++; }
    try { test_whilele_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilele_pp_rr_" << std::endl; failed++; }
    try { test_whilelo_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilelo_p_p_rr_" << std::endl; failed++; }
    try { test_whilelo_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilelo_pn_rr_" << std::endl; failed++; }
    try { test_whilelo_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilelo_pp_rr_" << std::endl; failed++; }
    try { test_whilels_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilels_p_p_rr_" << std::endl; failed++; }
    try { test_whilels_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilels_pn_rr_" << std::endl; failed++; }
    try { test_whilels_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilels_pp_rr_" << std::endl; failed++; }
    try { test_whilelt_p_p_rr_(); } catch (...) { std::cerr << "FAIL: whilelt_p_p_rr_" << std::endl; failed++; }
    try { test_whilelt_pn_rr_(); } catch (...) { std::cerr << "FAIL: whilelt_pn_rr_" << std::endl; failed++; }
    try { test_whilelt_pp_rr_(); } catch (...) { std::cerr << "FAIL: whilelt_pp_rr_" << std::endl; failed++; }
    try { test_whilerw_p_rr_(); } catch (...) { std::cerr << "FAIL: whilerw_p_rr_" << std::endl; failed++; }
    try { test_whilewr_p_rr_(); } catch (...) { std::cerr << "FAIL: whilewr_p_rr_" << std::endl; failed++; }
    try { test_wrffr_f_p_(); } catch (...) { std::cerr << "FAIL: wrffr_f_p_" << std::endl; failed++; }
    try { test_xar_z_zzi_(); } catch (...) { std::cerr << "FAIL: xar_z_zzi_" << std::endl; failed++; }
    try { test_zip2_p_pp_(); } catch (...) { std::cerr << "FAIL: zip2_p_pp_" << std::endl; failed++; }
    try { test_zip1_p_pp_(); } catch (...) { std::cerr << "FAIL: zip1_p_pp_" << std::endl; failed++; }
    try { test_zip2_z_zz_(); } catch (...) { std::cerr << "FAIL: zip2_z_zz_" << std::endl; failed++; }
    try { test_zip2_z_zz_q(); } catch (...) { std::cerr << "FAIL: zip2_z_zz_q" << std::endl; failed++; }
    try { test_zip1_z_zz_(); } catch (...) { std::cerr << "FAIL: zip1_z_zz_" << std::endl; failed++; }
    try { test_zip1_z_zz_q(); } catch (...) { std::cerr << "FAIL: zip1_z_zz_q" << std::endl; failed++; }
    try { test_zipq1_z_zz_(); } catch (...) { std::cerr << "FAIL: zipq1_z_zz_" << std::endl; failed++; }
    try { test_zipq2_z_zz_(); } catch (...) { std::cerr << "FAIL: zipq2_z_zz_" << std::endl; failed++; }

    std::cout << (1361 - failed) << " / 1361 passed" << std::endl;
    return failed;
}
