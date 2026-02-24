// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_apas_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50E7000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  apas_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_at_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5087800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  at_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_autia1716_hi_hints() {
    uint32_t insn = 0xD503219Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autia1716_hi_hints: " << result->to_string() << std::endl;
}

void test_autiasp_hi_hints() {
    uint32_t insn = 0xD50323BFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autiasp_hi_hints: " << result->to_string() << std::endl;
}

void test_autiaz_hi_hints() {
    uint32_t insn = 0xD503239Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autiaz_hi_hints: " << result->to_string() << std::endl;
}

void test_autib1716_hi_hints() {
    uint32_t insn = 0xD50321DFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autib1716_hi_hints: " << result->to_string() << std::endl;
}

void test_autibsp_hi_hints() {
    uint32_t insn = 0xD50323FFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autibsp_hi_hints: " << result->to_string() << std::endl;
}

void test_autibz_hi_hints() {
    uint32_t insn = 0xD50323DFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  autibz_hi_hints: " << result->to_string() << std::endl;
}

void test_axflag_m_pstate() {
    uint32_t insn = 0xD500405Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::AXFLAG);
    std::cout << "  axflag_m_pstate: " << result->to_string() << std::endl;
}

void test_b_only_condbranch() {
    uint32_t insn = 0x54000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::B);
    std::cout << "  b_only_condbranch: " << result->to_string() << std::endl;
}

void test_b_only_branch_imm() {
    uint32_t insn = 0x14000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::B);
    std::cout << "  b_only_branch_imm: " << result->to_string() << std::endl;
}

void test_bc_only_condbranch() {
    uint32_t insn = 0x54000010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BC);
    std::cout << "  bc_only_condbranch: " << result->to_string() << std::endl;
}

void test_bl_only_branch_imm() {
    uint32_t insn = 0x94000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BL);
    std::cout << "  bl_only_branch_imm: " << result->to_string() << std::endl;
}

void test_blr_64_branch_reg() {
    uint32_t insn = 0xD63F0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BLR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  blr_64_branch_reg: " << result->to_string() << std::endl;
}

void test_blraa_64p_branch_reg() {
    uint32_t insn = 0xD73F0800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  blraa_64p_branch_reg: " << result->to_string() << std::endl;
}

void test_blraaz_64_branch_reg() {
    uint32_t insn = 0xD63F081Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  blraaz_64_branch_reg: " << result->to_string() << std::endl;
}

void test_blrab_64p_branch_reg() {
    uint32_t insn = 0xD73F0C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  blrab_64p_branch_reg: " << result->to_string() << std::endl;
}

void test_blrabz_64_branch_reg() {
    uint32_t insn = 0xD63F0C1Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  blrabz_64_branch_reg: " << result->to_string() << std::endl;
}

void test_br_64_branch_reg() {
    uint32_t insn = 0xD61F0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  br_64_branch_reg: " << result->to_string() << std::endl;
}

void test_braa_64p_branch_reg() {
    uint32_t insn = 0xD71F0800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  braa_64p_branch_reg: " << result->to_string() << std::endl;
}

void test_braaz_64_branch_reg() {
    uint32_t insn = 0xD61F081Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  braaz_64_branch_reg: " << result->to_string() << std::endl;
}

void test_brab_64p_branch_reg() {
    uint32_t insn = 0xD71F0C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  brab_64p_branch_reg: " << result->to_string() << std::endl;
}

void test_brabz_64_branch_reg() {
    uint32_t insn = 0xD61F0C1Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  brabz_64_branch_reg: " << result->to_string() << std::endl;
}

void test_brb_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5097200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  brb_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_brk_ex_exception() {
    uint32_t insn = 0xD4200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BRK);
    std::cout << "  brk_ex_exception: " << result->to_string() << std::endl;
}

void test_bti_hb_hints() {
    uint32_t insn = 0xD503241Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BTI);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bti_hb_hints: " << result->to_string() << std::endl;
}

void test_cbbgt_8_regs() {
    uint32_t insn = 0x74008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbgt_8_regs: " << result->to_string() << std::endl;
}

void test_cbbge_8_regs() {
    uint32_t insn = 0x74208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbge_8_regs: " << result->to_string() << std::endl;
}

void test_cbbhi_8_regs() {
    uint32_t insn = 0x74408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbhi_8_regs: " << result->to_string() << std::endl;
}

void test_cbbhs_8_regs() {
    uint32_t insn = 0x74608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbhs_8_regs: " << result->to_string() << std::endl;
}

void test_cbbeq_8_regs() {
    uint32_t insn = 0x74C08000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbeq_8_regs: " << result->to_string() << std::endl;
}

void test_cbbne_8_regs() {
    uint32_t insn = 0x74E08000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbbne_8_regs: " << result->to_string() << std::endl;
}

void test_cbble_cbbge_8_regs() {
    uint32_t insn = 0x74208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBBGE);
    std::cout << "  cbble_cbbge_8_regs: " << result->to_string() << std::endl;
}

void test_cbblo_cbbhi_8_regs() {
    uint32_t insn = 0x74408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBBHI);
    std::cout << "  cbblo_cbbhi_8_regs: " << result->to_string() << std::endl;
}

void test_cbbls_cbbhs_8_regs() {
    uint32_t insn = 0x74608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBBHS);
    std::cout << "  cbbls_cbbhs_8_regs: " << result->to_string() << std::endl;
}

void test_cbblt_cbbgt_8_regs() {
    uint32_t insn = 0x74008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBBGT);
    std::cout << "  cbblt_cbbgt_8_regs: " << result->to_string() << std::endl;
}

void test_cbgt_32_imm() {
    uint32_t insn = 0x75000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbgt_32_imm: " << result->to_string() << std::endl;
}

void test_cblt_32_imm() {
    uint32_t insn = 0x75200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cblt_32_imm: " << result->to_string() << std::endl;
}

void test_cbhi_32_imm() {
    uint32_t insn = 0x75400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhi_32_imm: " << result->to_string() << std::endl;
}

void test_cblo_32_imm() {
    uint32_t insn = 0x75600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cblo_32_imm: " << result->to_string() << std::endl;
}

void test_cbeq_32_imm() {
    uint32_t insn = 0x75C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbeq_32_imm: " << result->to_string() << std::endl;
}

void test_cbne_32_imm() {
    uint32_t insn = 0x75E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbne_32_imm: " << result->to_string() << std::endl;
}

void test_cbgt_64_imm() {
    uint32_t insn = 0xF5000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbgt_64_imm: " << result->to_string() << std::endl;
}

void test_cblt_64_imm() {
    uint32_t insn = 0xF5200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cblt_64_imm: " << result->to_string() << std::endl;
}

void test_cbhi_64_imm() {
    uint32_t insn = 0xF5400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhi_64_imm: " << result->to_string() << std::endl;
}

void test_cblo_64_imm() {
    uint32_t insn = 0xF5600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cblo_64_imm: " << result->to_string() << std::endl;
}

void test_cbeq_64_imm() {
    uint32_t insn = 0xF5C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbeq_64_imm: " << result->to_string() << std::endl;
}

void test_cbne_64_imm() {
    uint32_t insn = 0xF5E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbne_64_imm: " << result->to_string() << std::endl;
}

void test_cbgt_32_regs() {
    uint32_t insn = 0x74000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbgt_32_regs: " << result->to_string() << std::endl;
}

void test_cbge_32_regs() {
    uint32_t insn = 0x74200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbge_32_regs: " << result->to_string() << std::endl;
}

void test_cbhi_32_regs() {
    uint32_t insn = 0x74400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhi_32_regs: " << result->to_string() << std::endl;
}

void test_cbhs_32_regs() {
    uint32_t insn = 0x74600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhs_32_regs: " << result->to_string() << std::endl;
}

void test_cbeq_32_regs() {
    uint32_t insn = 0x74C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbeq_32_regs: " << result->to_string() << std::endl;
}

void test_cbne_32_regs() {
    uint32_t insn = 0x74E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbne_32_regs: " << result->to_string() << std::endl;
}

void test_cbgt_64_regs() {
    uint32_t insn = 0xF4000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbgt_64_regs: " << result->to_string() << std::endl;
}

void test_cbge_64_regs() {
    uint32_t insn = 0xF4200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbge_64_regs: " << result->to_string() << std::endl;
}

void test_cbhi_64_regs() {
    uint32_t insn = 0xF4400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhi_64_regs: " << result->to_string() << std::endl;
}

void test_cbhs_64_regs() {
    uint32_t insn = 0xF4600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhs_64_regs: " << result->to_string() << std::endl;
}

void test_cbeq_64_regs() {
    uint32_t insn = 0xF4C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbeq_64_regs: " << result->to_string() << std::endl;
}

void test_cbne_64_regs() {
    uint32_t insn = 0xF4E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbne_64_regs: " << result->to_string() << std::endl;
}

void test_cbge_cbgt_32_imm() {
    uint32_t insn = 0x75000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGT);
    std::cout << "  cbge_cbgt_32_imm: " << result->to_string() << std::endl;
}

void test_cbge_cbgt_64_imm() {
    uint32_t insn = 0xF5000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGT);
    std::cout << "  cbge_cbgt_64_imm: " << result->to_string() << std::endl;
}

void test_cbhgt_16_regs() {
    uint32_t insn = 0x7400C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhgt_16_regs: " << result->to_string() << std::endl;
}

void test_cbhge_16_regs() {
    uint32_t insn = 0x7420C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhge_16_regs: " << result->to_string() << std::endl;
}

void test_cbhhi_16_regs() {
    uint32_t insn = 0x7440C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhhi_16_regs: " << result->to_string() << std::endl;
}

void test_cbhhs_16_regs() {
    uint32_t insn = 0x7460C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhhs_16_regs: " << result->to_string() << std::endl;
}

void test_cbheq_16_regs() {
    uint32_t insn = 0x74C0C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbheq_16_regs: " << result->to_string() << std::endl;
}

void test_cbhne_16_regs() {
    uint32_t insn = 0x74E0C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cbhne_16_regs: " << result->to_string() << std::endl;
}

void test_cbhle_cbhge_16_regs() {
    uint32_t insn = 0x7420C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHGE);
    std::cout << "  cbhle_cbhge_16_regs: " << result->to_string() << std::endl;
}

void test_cbhlo_cbhhi_16_regs() {
    uint32_t insn = 0x7440C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHHI);
    std::cout << "  cbhlo_cbhhi_16_regs: " << result->to_string() << std::endl;
}

void test_cbhls_cbhhs_16_regs() {
    uint32_t insn = 0x7460C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHHS);
    std::cout << "  cbhls_cbhhs_16_regs: " << result->to_string() << std::endl;
}

void test_cbhlt_cbhgt_16_regs() {
    uint32_t insn = 0x7400C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHGT);
    std::cout << "  cbhlt_cbhgt_16_regs: " << result->to_string() << std::endl;
}

void test_cbhs_cbhi_32_imm() {
    uint32_t insn = 0x75400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHI);
    std::cout << "  cbhs_cbhi_32_imm: " << result->to_string() << std::endl;
}

void test_cbhs_cbhi_64_imm() {
    uint32_t insn = 0xF5400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHI);
    std::cout << "  cbhs_cbhi_64_imm: " << result->to_string() << std::endl;
}

void test_cble_cblt_32_imm() {
    uint32_t insn = 0x75200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBLT);
    std::cout << "  cble_cblt_32_imm: " << result->to_string() << std::endl;
}

void test_cble_cblt_64_imm() {
    uint32_t insn = 0xF5200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBLT);
    std::cout << "  cble_cblt_64_imm: " << result->to_string() << std::endl;
}

void test_cble_cbge_32_regs() {
    uint32_t insn = 0x74200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGE);
    std::cout << "  cble_cbge_32_regs: " << result->to_string() << std::endl;
}

void test_cble_cbge_64_regs() {
    uint32_t insn = 0xF4200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGE);
    std::cout << "  cble_cbge_64_regs: " << result->to_string() << std::endl;
}

void test_cblo_cbhi_32_regs() {
    uint32_t insn = 0x74400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHI);
    std::cout << "  cblo_cbhi_32_regs: " << result->to_string() << std::endl;
}

void test_cblo_cbhi_64_regs() {
    uint32_t insn = 0xF4400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHI);
    std::cout << "  cblo_cbhi_64_regs: " << result->to_string() << std::endl;
}

void test_cbls_cblo_32_imm() {
    uint32_t insn = 0x75600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBLO);
    std::cout << "  cbls_cblo_32_imm: " << result->to_string() << std::endl;
}

void test_cbls_cblo_64_imm() {
    uint32_t insn = 0xF5600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBLO);
    std::cout << "  cbls_cblo_64_imm: " << result->to_string() << std::endl;
}

void test_cbls_cbhs_32_regs() {
    uint32_t insn = 0x74600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHS);
    std::cout << "  cbls_cbhs_32_regs: " << result->to_string() << std::endl;
}

void test_cbls_cbhs_64_regs() {
    uint32_t insn = 0xF4600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBHS);
    std::cout << "  cbls_cbhs_64_regs: " << result->to_string() << std::endl;
}

void test_cblt_cbgt_32_regs() {
    uint32_t insn = 0x74000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGT);
    std::cout << "  cblt_cbgt_32_regs: " << result->to_string() << std::endl;
}

void test_cblt_cbgt_64_regs() {
    uint32_t insn = 0xF4000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBGT);
    std::cout << "  cblt_cbgt_64_regs: " << result->to_string() << std::endl;
}

void test_cbnz_32_compbranch() {
    uint32_t insn = 0x35000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBNZ);
    std::cout << "  cbnz_32_compbranch: " << result->to_string() << std::endl;
}

void test_cbnz_64_compbranch() {
    uint32_t insn = 0xB5000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBNZ);
    std::cout << "  cbnz_64_compbranch: " << result->to_string() << std::endl;
}

void test_cbz_32_compbranch() {
    uint32_t insn = 0x34000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBZ);
    std::cout << "  cbz_32_compbranch: " << result->to_string() << std::endl;
}

void test_cbz_64_compbranch() {
    uint32_t insn = 0xB4000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CBZ);
    std::cout << "  cbz_64_compbranch: " << result->to_string() << std::endl;
}

void test_cfinv_m_pstate() {
    uint32_t insn = 0xD500401Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CFINV);
    std::cout << "  cfinv_m_pstate: " << result->to_string() << std::endl;
}

void test_cfp_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B7380u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cfp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_chkfeat_hf_hints() {
    uint32_t insn = 0xD503251Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CHKFEAT);
    std::cout << "  chkfeat_hf_hints: " << result->to_string() << std::endl;
}

void test_clrbhb_hi_hints() {
    uint32_t insn = 0xD50322DFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CLRBHB);
    std::cout << "  clrbhb_hi_hints: " << result->to_string() << std::endl;
}

void test_clrex_bn_barriers() {
    uint32_t insn = 0xD503305Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CLREX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  clrex_bn_barriers: " << result->to_string() << std::endl;
}

void test_cosp_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B73C0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cosp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_cpp_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B73E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  cpp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_csdb_hi_hints() {
    uint32_t insn = 0xD503229Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::CSDB);
    std::cout << "  csdb_hi_hints: " << result->to_string() << std::endl;
}

void test_dc_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5087000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  dc_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_dcps1_dc_exception() {
    uint32_t insn = 0xD4A00001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DCPS1);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  dcps1_dc_exception: " << result->to_string() << std::endl;
}

void test_dcps2_dc_exception() {
    uint32_t insn = 0xD4A00002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DCPS2);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  dcps2_dc_exception: " << result->to_string() << std::endl;
}

void test_dcps3_dc_exception() {
    uint32_t insn = 0xD4A00003u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DCPS3);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  dcps3_dc_exception: " << result->to_string() << std::endl;
}

void test_dgh_hi_hints() {
    uint32_t insn = 0xD50320DFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DGH);
    std::cout << "  dgh_hi_hints: " << result->to_string() << std::endl;
}

void test_dmb_bo_barriers() {
    uint32_t insn = 0xD50330BFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DMB);
    std::cout << "  dmb_bo_barriers: " << result->to_string() << std::endl;
}

void test_drps_64e_branch_reg() {
    uint32_t insn = 0xD6BF03E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DRPS);
    std::cout << "  drps_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_dsb_bo_barriers() {
    uint32_t insn = 0xD503309Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DSB);
    std::cout << "  dsb_bo_barriers: " << result->to_string() << std::endl;
}

void test_dsb_bon_barriers() {
    uint32_t insn = 0xD503323Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DSB);
    std::cout << "  dsb_bon_barriers: " << result->to_string() << std::endl;
}

void test_dvp_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B73A0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  dvp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_eret_64e_branch_reg() {
    uint32_t insn = 0xD69F03E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ERET);
    std::cout << "  eret_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_eretaa_64e_branch_reg() {
    uint32_t insn = 0xD69F0BFFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  eretaa_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_eretab_64e_branch_reg() {
    uint32_t insn = 0xD69F0FFFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  eretab_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_esb_hi_hints() {
    uint32_t insn = 0xD503221Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ESB);
    std::cout << "  esb_hi_hints: " << result->to_string() << std::endl;
}

void test_gcsb_hd_hints() {
    uint32_t insn = 0xD503227Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::GCSB);
    std::cout << "  gcsb_hd_hints: " << result->to_string() << std::endl;
}

void test_gcspopcx_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50877A0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcspopcx_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcspopm_sysl_rc_systeminstrs() {
    uint32_t insn = 0xD52B7720u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcspopm_sysl_rc_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcspopx_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50877C0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcspopx_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcspushm_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B7700u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcspushm_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcspushx_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5087780u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcspushx_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcsss1_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B7740u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcsss1_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gcsss2_sysl_rc_systeminstrs() {
    uint32_t insn = 0xD52B7760u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gcsss2_sysl_rc_systeminstrs: " << result->to_string() << std::endl;
}

void test_gic_sys_cr_systeminstrs() {
    uint32_t insn = 0xD508C400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gic_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_gicr_sysl_rc_systeminstrs() {
    uint32_t insn = 0xD528C300u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gicr_sysl_rc_systeminstrs: " << result->to_string() << std::endl;
}

void test_gsb_sys_cr_systeminstrs() {
    uint32_t insn = 0xD508C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  gsb_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_hint_hm_hints() {
    uint32_t insn = 0xD503201Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  hint_hm_hints: " << result->to_string() << std::endl;
}

void test_hlt_ex_exception() {
    uint32_t insn = 0xD4400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::HLT);
    std::cout << "  hlt_ex_exception: " << result->to_string() << std::endl;
}

void test_hvc_ex_exception() {
    uint32_t insn = 0xD4000002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::HVC);
    std::cout << "  hvc_ex_exception: " << result->to_string() << std::endl;
}

void test_ic_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5087000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  ic_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_isb_bi_barriers() {
    uint32_t insn = 0xD50330DFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ISB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  isb_bi_barriers: " << result->to_string() << std::endl;
}

void test_mlbi_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50C7080u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  mlbi_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_mrrs_rs_systemmovepr() {
    uint32_t insn = 0xD5700000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MRRS);
    std::cout << "  mrrs_rs_systemmovepr: " << result->to_string() << std::endl;
}

void test_mrs_rs_systemmove() {
    uint32_t insn = 0xD5300000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MRS);
    std::cout << "  mrs_rs_systemmove: " << result->to_string() << std::endl;
}

void test_msr_si_pstate() {
    uint32_t insn = 0xD500401Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MSR);
    std::cout << "  msr_si_pstate: " << result->to_string() << std::endl;
}

void test_msr_sr_systemmove() {
    uint32_t insn = 0xD5100000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MSR);
    std::cout << "  msr_sr_systemmove: " << result->to_string() << std::endl;
}

void test_msrr_sr_systemmovepr() {
    uint32_t insn = 0xD5500000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MSRR);
    std::cout << "  msrr_sr_systemmovepr: " << result->to_string() << std::endl;
}

void test_nop_hi_hints() {
    uint32_t insn = 0xD503201Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::NOP);
    std::cout << "  nop_hi_hints: " << result->to_string() << std::endl;
}

void test_pacia1716_hi_hints() {
    uint32_t insn = 0xD503211Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  pacia1716_hi_hints: " << result->to_string() << std::endl;
}

void test_paciasp_hi_hints() {
    uint32_t insn = 0xD503233Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  paciasp_hi_hints: " << result->to_string() << std::endl;
}

void test_paciaz_hi_hints() {
    uint32_t insn = 0xD503231Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  paciaz_hi_hints: " << result->to_string() << std::endl;
}

void test_pacib1716_hi_hints() {
    uint32_t insn = 0xD503215Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  pacib1716_hi_hints: " << result->to_string() << std::endl;
}

void test_pacibsp_hi_hints() {
    uint32_t insn = 0xD503237Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  pacibsp_hi_hints: " << result->to_string() << std::endl;
}

void test_pacibz_hi_hints() {
    uint32_t insn = 0xD503235Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  pacibz_hi_hints: " << result->to_string() << std::endl;
}

void test_pacm_hi_hints() {
    uint32_t insn = 0xD50324FFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::PACM);
    std::cout << "  pacm_hi_hints: " << result->to_string() << std::endl;
}

void test_psb_hc_hints() {
    uint32_t insn = 0xD503223Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::PSB);
    std::cout << "  psb_hc_hints: " << result->to_string() << std::endl;
}

void test_pssbb_dsb_bo_barriers() {
    uint32_t insn = 0xD503349Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DSB);
    std::cout << "  pssbb_dsb_bo_barriers: " << result->to_string() << std::endl;
}

void test_ret_64r_branch_reg() {
    uint32_t insn = 0xD65F0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::RET);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  ret_64r_branch_reg: " << result->to_string() << std::endl;
}

void test_retaa_64e_branch_reg() {
    uint32_t insn = 0xD65F0BFFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  retaa_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_retab_64e_branch_reg() {
    uint32_t insn = 0xD65F0FFFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  retab_64e_branch_reg: " << result->to_string() << std::endl;
}

void test_retaasppc_only_miscbranch() {
    uint32_t insn = 0x5500001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  retaasppc_only_miscbranch: " << result->to_string() << std::endl;
}

void test_retabsppc_only_miscbranch() {
    uint32_t insn = 0x5520001Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  retabsppc_only_miscbranch: " << result->to_string() << std::endl;
}

void test_retaasppcr_64m_branch_reg() {
    uint32_t insn = 0xD65F0BE0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  retaasppcr_64m_branch_reg: " << result->to_string() << std::endl;
}

void test_retabsppcr_64m_branch_reg() {
    uint32_t insn = 0xD65F0FE0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  retabsppcr_64m_branch_reg: " << result->to_string() << std::endl;
}

void test_sb_only_barriers() {
    uint32_t insn = 0xD50330FFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SB);
    std::cout << "  sb_only_barriers: " << result->to_string() << std::endl;
}

void test_sev_hi_hints() {
    uint32_t insn = 0xD503209Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SEV);
    std::cout << "  sev_hi_hints: " << result->to_string() << std::endl;
}

void test_sevl_hi_hints() {
    uint32_t insn = 0xD50320BFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SEVL);
    std::cout << "  sevl_hi_hints: " << result->to_string() << std::endl;
}

void test_shuh_hi_hints() {
    uint32_t insn = 0xD503265Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SHUH);
    std::cout << "  shuh_hi_hints: " << result->to_string() << std::endl;
}

void test_smc_ex_exception() {
    uint32_t insn = 0xD4000003u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMC);
    std::cout << "  smc_ex_exception: " << result->to_string() << std::endl;
}

void test_smstart_msr_si_pstate() {
    uint32_t insn = 0xD503417Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MSR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smstart_msr_si_pstate: " << result->to_string() << std::endl;
}

void test_smstop_msr_si_pstate() {
    uint32_t insn = 0xD503407Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MSR);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smstop_msr_si_pstate: " << result->to_string() << std::endl;
}

void test_ssbb_dsb_bo_barriers() {
    uint32_t insn = 0xD503309Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::DSB);
    std::cout << "  ssbb_dsb_bo_barriers: " << result->to_string() << std::endl;
}

void test_stcph_hi_hints() {
    uint32_t insn = 0xD503269Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STCPH);
    std::cout << "  stcph_hi_hints: " << result->to_string() << std::endl;
}

void test_stshh_hi_hints() {
    uint32_t insn = 0xD503261Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STSHH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::PredicateRegister);
    std::cout << "  stshh_hi_hints: " << result->to_string() << std::endl;
}

void test_svc_ex_exception() {
    uint32_t insn = 0xD4000001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SVC);
    std::cout << "  svc_ex_exception: " << result->to_string() << std::endl;
}

void test_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5080000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_sysl_rc_systeminstrs() {
    uint32_t insn = 0xD5280000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sysl_rc_systeminstrs: " << result->to_string() << std::endl;
}

void test_sysp_cr_syspairinstrs() {
    uint32_t insn = 0xD5480000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SYSP);
    std::cout << "  sysp_cr_syspairinstrs: " << result->to_string() << std::endl;
}

void test_tbnz_only_testbranch() {
    uint32_t insn = 0x37000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::TBNZ);
    std::cout << "  tbnz_only_testbranch: " << result->to_string() << std::endl;
}

void test_tbz_only_testbranch() {
    uint32_t insn = 0x36000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::TBZ);
    std::cout << "  tbz_only_testbranch: " << result->to_string() << std::endl;
}

void test_tlbi_sys_cr_systeminstrs() {
    uint32_t insn = 0xD5088000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  tlbi_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_tlbip_sysp_cr_syspairinstrs() {
    uint32_t insn = 0xD5488000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SYSP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  tlbip_sysp_cr_syspairinstrs: " << result->to_string() << std::endl;
}

void test_trcit_sys_cr_systeminstrs() {
    uint32_t insn = 0xD50B72E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  trcit_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_tsb_hc_hints() {
    uint32_t insn = 0xD503225Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::TSB);
    std::cout << "  tsb_hc_hints: " << result->to_string() << std::endl;
}

void test_wfe_hi_hints() {
    uint32_t insn = 0xD503205Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::WFE);
    std::cout << "  wfe_hi_hints: " << result->to_string() << std::endl;
}

void test_wfet_only_systeminstrswithreg() {
    uint32_t insn = 0xD5031000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::WFET);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  wfet_only_systeminstrswithreg: " << result->to_string() << std::endl;
}

void test_wfi_hi_hints() {
    uint32_t insn = 0xD503207Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::WFI);
    std::cout << "  wfi_hi_hints: " << result->to_string() << std::endl;
}

void test_wfit_only_systeminstrswithreg() {
    uint32_t insn = 0xD5031020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::WFIT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::Register);
    std::cout << "  wfit_only_systeminstrswithreg: " << result->to_string() << std::endl;
}

void test_xaflag_m_pstate() {
    uint32_t insn = 0xD500403Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::XAFLAG);
    std::cout << "  xaflag_m_pstate: " << result->to_string() << std::endl;
}

void test_xpaclri_hi_hints() {
    uint32_t insn = 0xD50320FFu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  xpaclri_hi_hints: " << result->to_string() << std::endl;
}

void test_yield_hi_hints() {
    uint32_t insn = 0xD503203Fu;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::YIELD);
    std::cout << "  yield_hi_hints: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running control encoding tests (178 encodings)..." << std::endl;
    int failed = 0;

    try { test_apas_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: apas_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_at_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: at_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_autia1716_hi_hints(); } catch (...) { std::cerr << "FAIL: autia1716_hi_hints" << std::endl; failed++; }
    try { test_autiasp_hi_hints(); } catch (...) { std::cerr << "FAIL: autiasp_hi_hints" << std::endl; failed++; }
    try { test_autiaz_hi_hints(); } catch (...) { std::cerr << "FAIL: autiaz_hi_hints" << std::endl; failed++; }
    try { test_autib1716_hi_hints(); } catch (...) { std::cerr << "FAIL: autib1716_hi_hints" << std::endl; failed++; }
    try { test_autibsp_hi_hints(); } catch (...) { std::cerr << "FAIL: autibsp_hi_hints" << std::endl; failed++; }
    try { test_autibz_hi_hints(); } catch (...) { std::cerr << "FAIL: autibz_hi_hints" << std::endl; failed++; }
    try { test_axflag_m_pstate(); } catch (...) { std::cerr << "FAIL: axflag_m_pstate" << std::endl; failed++; }
    try { test_b_only_condbranch(); } catch (...) { std::cerr << "FAIL: b_only_condbranch" << std::endl; failed++; }
    try { test_b_only_branch_imm(); } catch (...) { std::cerr << "FAIL: b_only_branch_imm" << std::endl; failed++; }
    try { test_bc_only_condbranch(); } catch (...) { std::cerr << "FAIL: bc_only_condbranch" << std::endl; failed++; }
    try { test_bl_only_branch_imm(); } catch (...) { std::cerr << "FAIL: bl_only_branch_imm" << std::endl; failed++; }
    try { test_blr_64_branch_reg(); } catch (...) { std::cerr << "FAIL: blr_64_branch_reg" << std::endl; failed++; }
    try { test_blraa_64p_branch_reg(); } catch (...) { std::cerr << "FAIL: blraa_64p_branch_reg" << std::endl; failed++; }
    try { test_blraaz_64_branch_reg(); } catch (...) { std::cerr << "FAIL: blraaz_64_branch_reg" << std::endl; failed++; }
    try { test_blrab_64p_branch_reg(); } catch (...) { std::cerr << "FAIL: blrab_64p_branch_reg" << std::endl; failed++; }
    try { test_blrabz_64_branch_reg(); } catch (...) { std::cerr << "FAIL: blrabz_64_branch_reg" << std::endl; failed++; }
    try { test_br_64_branch_reg(); } catch (...) { std::cerr << "FAIL: br_64_branch_reg" << std::endl; failed++; }
    try { test_braa_64p_branch_reg(); } catch (...) { std::cerr << "FAIL: braa_64p_branch_reg" << std::endl; failed++; }
    try { test_braaz_64_branch_reg(); } catch (...) { std::cerr << "FAIL: braaz_64_branch_reg" << std::endl; failed++; }
    try { test_brab_64p_branch_reg(); } catch (...) { std::cerr << "FAIL: brab_64p_branch_reg" << std::endl; failed++; }
    try { test_brabz_64_branch_reg(); } catch (...) { std::cerr << "FAIL: brabz_64_branch_reg" << std::endl; failed++; }
    try { test_brb_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: brb_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_brk_ex_exception(); } catch (...) { std::cerr << "FAIL: brk_ex_exception" << std::endl; failed++; }
    try { test_bti_hb_hints(); } catch (...) { std::cerr << "FAIL: bti_hb_hints" << std::endl; failed++; }
    try { test_cbbgt_8_regs(); } catch (...) { std::cerr << "FAIL: cbbgt_8_regs" << std::endl; failed++; }
    try { test_cbbge_8_regs(); } catch (...) { std::cerr << "FAIL: cbbge_8_regs" << std::endl; failed++; }
    try { test_cbbhi_8_regs(); } catch (...) { std::cerr << "FAIL: cbbhi_8_regs" << std::endl; failed++; }
    try { test_cbbhs_8_regs(); } catch (...) { std::cerr << "FAIL: cbbhs_8_regs" << std::endl; failed++; }
    try { test_cbbeq_8_regs(); } catch (...) { std::cerr << "FAIL: cbbeq_8_regs" << std::endl; failed++; }
    try { test_cbbne_8_regs(); } catch (...) { std::cerr << "FAIL: cbbne_8_regs" << std::endl; failed++; }
    try { test_cbble_cbbge_8_regs(); } catch (...) { std::cerr << "FAIL: cbble_cbbge_8_regs" << std::endl; failed++; }
    try { test_cbblo_cbbhi_8_regs(); } catch (...) { std::cerr << "FAIL: cbblo_cbbhi_8_regs" << std::endl; failed++; }
    try { test_cbbls_cbbhs_8_regs(); } catch (...) { std::cerr << "FAIL: cbbls_cbbhs_8_regs" << std::endl; failed++; }
    try { test_cbblt_cbbgt_8_regs(); } catch (...) { std::cerr << "FAIL: cbblt_cbbgt_8_regs" << std::endl; failed++; }
    try { test_cbgt_32_imm(); } catch (...) { std::cerr << "FAIL: cbgt_32_imm" << std::endl; failed++; }
    try { test_cblt_32_imm(); } catch (...) { std::cerr << "FAIL: cblt_32_imm" << std::endl; failed++; }
    try { test_cbhi_32_imm(); } catch (...) { std::cerr << "FAIL: cbhi_32_imm" << std::endl; failed++; }
    try { test_cblo_32_imm(); } catch (...) { std::cerr << "FAIL: cblo_32_imm" << std::endl; failed++; }
    try { test_cbeq_32_imm(); } catch (...) { std::cerr << "FAIL: cbeq_32_imm" << std::endl; failed++; }
    try { test_cbne_32_imm(); } catch (...) { std::cerr << "FAIL: cbne_32_imm" << std::endl; failed++; }
    try { test_cbgt_64_imm(); } catch (...) { std::cerr << "FAIL: cbgt_64_imm" << std::endl; failed++; }
    try { test_cblt_64_imm(); } catch (...) { std::cerr << "FAIL: cblt_64_imm" << std::endl; failed++; }
    try { test_cbhi_64_imm(); } catch (...) { std::cerr << "FAIL: cbhi_64_imm" << std::endl; failed++; }
    try { test_cblo_64_imm(); } catch (...) { std::cerr << "FAIL: cblo_64_imm" << std::endl; failed++; }
    try { test_cbeq_64_imm(); } catch (...) { std::cerr << "FAIL: cbeq_64_imm" << std::endl; failed++; }
    try { test_cbne_64_imm(); } catch (...) { std::cerr << "FAIL: cbne_64_imm" << std::endl; failed++; }
    try { test_cbgt_32_regs(); } catch (...) { std::cerr << "FAIL: cbgt_32_regs" << std::endl; failed++; }
    try { test_cbge_32_regs(); } catch (...) { std::cerr << "FAIL: cbge_32_regs" << std::endl; failed++; }
    try { test_cbhi_32_regs(); } catch (...) { std::cerr << "FAIL: cbhi_32_regs" << std::endl; failed++; }
    try { test_cbhs_32_regs(); } catch (...) { std::cerr << "FAIL: cbhs_32_regs" << std::endl; failed++; }
    try { test_cbeq_32_regs(); } catch (...) { std::cerr << "FAIL: cbeq_32_regs" << std::endl; failed++; }
    try { test_cbne_32_regs(); } catch (...) { std::cerr << "FAIL: cbne_32_regs" << std::endl; failed++; }
    try { test_cbgt_64_regs(); } catch (...) { std::cerr << "FAIL: cbgt_64_regs" << std::endl; failed++; }
    try { test_cbge_64_regs(); } catch (...) { std::cerr << "FAIL: cbge_64_regs" << std::endl; failed++; }
    try { test_cbhi_64_regs(); } catch (...) { std::cerr << "FAIL: cbhi_64_regs" << std::endl; failed++; }
    try { test_cbhs_64_regs(); } catch (...) { std::cerr << "FAIL: cbhs_64_regs" << std::endl; failed++; }
    try { test_cbeq_64_regs(); } catch (...) { std::cerr << "FAIL: cbeq_64_regs" << std::endl; failed++; }
    try { test_cbne_64_regs(); } catch (...) { std::cerr << "FAIL: cbne_64_regs" << std::endl; failed++; }
    try { test_cbge_cbgt_32_imm(); } catch (...) { std::cerr << "FAIL: cbge_cbgt_32_imm" << std::endl; failed++; }
    try { test_cbge_cbgt_64_imm(); } catch (...) { std::cerr << "FAIL: cbge_cbgt_64_imm" << std::endl; failed++; }
    try { test_cbhgt_16_regs(); } catch (...) { std::cerr << "FAIL: cbhgt_16_regs" << std::endl; failed++; }
    try { test_cbhge_16_regs(); } catch (...) { std::cerr << "FAIL: cbhge_16_regs" << std::endl; failed++; }
    try { test_cbhhi_16_regs(); } catch (...) { std::cerr << "FAIL: cbhhi_16_regs" << std::endl; failed++; }
    try { test_cbhhs_16_regs(); } catch (...) { std::cerr << "FAIL: cbhhs_16_regs" << std::endl; failed++; }
    try { test_cbheq_16_regs(); } catch (...) { std::cerr << "FAIL: cbheq_16_regs" << std::endl; failed++; }
    try { test_cbhne_16_regs(); } catch (...) { std::cerr << "FAIL: cbhne_16_regs" << std::endl; failed++; }
    try { test_cbhle_cbhge_16_regs(); } catch (...) { std::cerr << "FAIL: cbhle_cbhge_16_regs" << std::endl; failed++; }
    try { test_cbhlo_cbhhi_16_regs(); } catch (...) { std::cerr << "FAIL: cbhlo_cbhhi_16_regs" << std::endl; failed++; }
    try { test_cbhls_cbhhs_16_regs(); } catch (...) { std::cerr << "FAIL: cbhls_cbhhs_16_regs" << std::endl; failed++; }
    try { test_cbhlt_cbhgt_16_regs(); } catch (...) { std::cerr << "FAIL: cbhlt_cbhgt_16_regs" << std::endl; failed++; }
    try { test_cbhs_cbhi_32_imm(); } catch (...) { std::cerr << "FAIL: cbhs_cbhi_32_imm" << std::endl; failed++; }
    try { test_cbhs_cbhi_64_imm(); } catch (...) { std::cerr << "FAIL: cbhs_cbhi_64_imm" << std::endl; failed++; }
    try { test_cble_cblt_32_imm(); } catch (...) { std::cerr << "FAIL: cble_cblt_32_imm" << std::endl; failed++; }
    try { test_cble_cblt_64_imm(); } catch (...) { std::cerr << "FAIL: cble_cblt_64_imm" << std::endl; failed++; }
    try { test_cble_cbge_32_regs(); } catch (...) { std::cerr << "FAIL: cble_cbge_32_regs" << std::endl; failed++; }
    try { test_cble_cbge_64_regs(); } catch (...) { std::cerr << "FAIL: cble_cbge_64_regs" << std::endl; failed++; }
    try { test_cblo_cbhi_32_regs(); } catch (...) { std::cerr << "FAIL: cblo_cbhi_32_regs" << std::endl; failed++; }
    try { test_cblo_cbhi_64_regs(); } catch (...) { std::cerr << "FAIL: cblo_cbhi_64_regs" << std::endl; failed++; }
    try { test_cbls_cblo_32_imm(); } catch (...) { std::cerr << "FAIL: cbls_cblo_32_imm" << std::endl; failed++; }
    try { test_cbls_cblo_64_imm(); } catch (...) { std::cerr << "FAIL: cbls_cblo_64_imm" << std::endl; failed++; }
    try { test_cbls_cbhs_32_regs(); } catch (...) { std::cerr << "FAIL: cbls_cbhs_32_regs" << std::endl; failed++; }
    try { test_cbls_cbhs_64_regs(); } catch (...) { std::cerr << "FAIL: cbls_cbhs_64_regs" << std::endl; failed++; }
    try { test_cblt_cbgt_32_regs(); } catch (...) { std::cerr << "FAIL: cblt_cbgt_32_regs" << std::endl; failed++; }
    try { test_cblt_cbgt_64_regs(); } catch (...) { std::cerr << "FAIL: cblt_cbgt_64_regs" << std::endl; failed++; }
    try { test_cbnz_32_compbranch(); } catch (...) { std::cerr << "FAIL: cbnz_32_compbranch" << std::endl; failed++; }
    try { test_cbnz_64_compbranch(); } catch (...) { std::cerr << "FAIL: cbnz_64_compbranch" << std::endl; failed++; }
    try { test_cbz_32_compbranch(); } catch (...) { std::cerr << "FAIL: cbz_32_compbranch" << std::endl; failed++; }
    try { test_cbz_64_compbranch(); } catch (...) { std::cerr << "FAIL: cbz_64_compbranch" << std::endl; failed++; }
    try { test_cfinv_m_pstate(); } catch (...) { std::cerr << "FAIL: cfinv_m_pstate" << std::endl; failed++; }
    try { test_cfp_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: cfp_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_chkfeat_hf_hints(); } catch (...) { std::cerr << "FAIL: chkfeat_hf_hints" << std::endl; failed++; }
    try { test_clrbhb_hi_hints(); } catch (...) { std::cerr << "FAIL: clrbhb_hi_hints" << std::endl; failed++; }
    try { test_clrex_bn_barriers(); } catch (...) { std::cerr << "FAIL: clrex_bn_barriers" << std::endl; failed++; }
    try { test_cosp_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: cosp_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_cpp_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: cpp_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_csdb_hi_hints(); } catch (...) { std::cerr << "FAIL: csdb_hi_hints" << std::endl; failed++; }
    try { test_dc_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: dc_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_dcps1_dc_exception(); } catch (...) { std::cerr << "FAIL: dcps1_dc_exception" << std::endl; failed++; }
    try { test_dcps2_dc_exception(); } catch (...) { std::cerr << "FAIL: dcps2_dc_exception" << std::endl; failed++; }
    try { test_dcps3_dc_exception(); } catch (...) { std::cerr << "FAIL: dcps3_dc_exception" << std::endl; failed++; }
    try { test_dgh_hi_hints(); } catch (...) { std::cerr << "FAIL: dgh_hi_hints" << std::endl; failed++; }
    try { test_dmb_bo_barriers(); } catch (...) { std::cerr << "FAIL: dmb_bo_barriers" << std::endl; failed++; }
    try { test_drps_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: drps_64e_branch_reg" << std::endl; failed++; }
    try { test_dsb_bo_barriers(); } catch (...) { std::cerr << "FAIL: dsb_bo_barriers" << std::endl; failed++; }
    try { test_dsb_bon_barriers(); } catch (...) { std::cerr << "FAIL: dsb_bon_barriers" << std::endl; failed++; }
    try { test_dvp_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: dvp_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_eret_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: eret_64e_branch_reg" << std::endl; failed++; }
    try { test_eretaa_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: eretaa_64e_branch_reg" << std::endl; failed++; }
    try { test_eretab_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: eretab_64e_branch_reg" << std::endl; failed++; }
    try { test_esb_hi_hints(); } catch (...) { std::cerr << "FAIL: esb_hi_hints" << std::endl; failed++; }
    try { test_gcsb_hd_hints(); } catch (...) { std::cerr << "FAIL: gcsb_hd_hints" << std::endl; failed++; }
    try { test_gcspopcx_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcspopcx_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gcspopm_sysl_rc_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcspopm_sysl_rc_systeminstrs" << std::endl; failed++; }
    try { test_gcspopx_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcspopx_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gcspushm_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcspushm_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gcspushx_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcspushx_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gcsss1_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcsss1_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gcsss2_sysl_rc_systeminstrs(); } catch (...) { std::cerr << "FAIL: gcsss2_sysl_rc_systeminstrs" << std::endl; failed++; }
    try { test_gic_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gic_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_gicr_sysl_rc_systeminstrs(); } catch (...) { std::cerr << "FAIL: gicr_sysl_rc_systeminstrs" << std::endl; failed++; }
    try { test_gsb_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: gsb_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_hint_hm_hints(); } catch (...) { std::cerr << "FAIL: hint_hm_hints" << std::endl; failed++; }
    try { test_hlt_ex_exception(); } catch (...) { std::cerr << "FAIL: hlt_ex_exception" << std::endl; failed++; }
    try { test_hvc_ex_exception(); } catch (...) { std::cerr << "FAIL: hvc_ex_exception" << std::endl; failed++; }
    try { test_ic_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: ic_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_isb_bi_barriers(); } catch (...) { std::cerr << "FAIL: isb_bi_barriers" << std::endl; failed++; }
    try { test_mlbi_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: mlbi_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_mrrs_rs_systemmovepr(); } catch (...) { std::cerr << "FAIL: mrrs_rs_systemmovepr" << std::endl; failed++; }
    try { test_mrs_rs_systemmove(); } catch (...) { std::cerr << "FAIL: mrs_rs_systemmove" << std::endl; failed++; }
    try { test_msr_si_pstate(); } catch (...) { std::cerr << "FAIL: msr_si_pstate" << std::endl; failed++; }
    try { test_msr_sr_systemmove(); } catch (...) { std::cerr << "FAIL: msr_sr_systemmove" << std::endl; failed++; }
    try { test_msrr_sr_systemmovepr(); } catch (...) { std::cerr << "FAIL: msrr_sr_systemmovepr" << std::endl; failed++; }
    try { test_nop_hi_hints(); } catch (...) { std::cerr << "FAIL: nop_hi_hints" << std::endl; failed++; }
    try { test_pacia1716_hi_hints(); } catch (...) { std::cerr << "FAIL: pacia1716_hi_hints" << std::endl; failed++; }
    try { test_paciasp_hi_hints(); } catch (...) { std::cerr << "FAIL: paciasp_hi_hints" << std::endl; failed++; }
    try { test_paciaz_hi_hints(); } catch (...) { std::cerr << "FAIL: paciaz_hi_hints" << std::endl; failed++; }
    try { test_pacib1716_hi_hints(); } catch (...) { std::cerr << "FAIL: pacib1716_hi_hints" << std::endl; failed++; }
    try { test_pacibsp_hi_hints(); } catch (...) { std::cerr << "FAIL: pacibsp_hi_hints" << std::endl; failed++; }
    try { test_pacibz_hi_hints(); } catch (...) { std::cerr << "FAIL: pacibz_hi_hints" << std::endl; failed++; }
    try { test_pacm_hi_hints(); } catch (...) { std::cerr << "FAIL: pacm_hi_hints" << std::endl; failed++; }
    try { test_psb_hc_hints(); } catch (...) { std::cerr << "FAIL: psb_hc_hints" << std::endl; failed++; }
    try { test_pssbb_dsb_bo_barriers(); } catch (...) { std::cerr << "FAIL: pssbb_dsb_bo_barriers" << std::endl; failed++; }
    try { test_ret_64r_branch_reg(); } catch (...) { std::cerr << "FAIL: ret_64r_branch_reg" << std::endl; failed++; }
    try { test_retaa_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: retaa_64e_branch_reg" << std::endl; failed++; }
    try { test_retab_64e_branch_reg(); } catch (...) { std::cerr << "FAIL: retab_64e_branch_reg" << std::endl; failed++; }
    try { test_retaasppc_only_miscbranch(); } catch (...) { std::cerr << "FAIL: retaasppc_only_miscbranch" << std::endl; failed++; }
    try { test_retabsppc_only_miscbranch(); } catch (...) { std::cerr << "FAIL: retabsppc_only_miscbranch" << std::endl; failed++; }
    try { test_retaasppcr_64m_branch_reg(); } catch (...) { std::cerr << "FAIL: retaasppcr_64m_branch_reg" << std::endl; failed++; }
    try { test_retabsppcr_64m_branch_reg(); } catch (...) { std::cerr << "FAIL: retabsppcr_64m_branch_reg" << std::endl; failed++; }
    try { test_sb_only_barriers(); } catch (...) { std::cerr << "FAIL: sb_only_barriers" << std::endl; failed++; }
    try { test_sev_hi_hints(); } catch (...) { std::cerr << "FAIL: sev_hi_hints" << std::endl; failed++; }
    try { test_sevl_hi_hints(); } catch (...) { std::cerr << "FAIL: sevl_hi_hints" << std::endl; failed++; }
    try { test_shuh_hi_hints(); } catch (...) { std::cerr << "FAIL: shuh_hi_hints" << std::endl; failed++; }
    try { test_smc_ex_exception(); } catch (...) { std::cerr << "FAIL: smc_ex_exception" << std::endl; failed++; }
    try { test_smstart_msr_si_pstate(); } catch (...) { std::cerr << "FAIL: smstart_msr_si_pstate" << std::endl; failed++; }
    try { test_smstop_msr_si_pstate(); } catch (...) { std::cerr << "FAIL: smstop_msr_si_pstate" << std::endl; failed++; }
    try { test_ssbb_dsb_bo_barriers(); } catch (...) { std::cerr << "FAIL: ssbb_dsb_bo_barriers" << std::endl; failed++; }
    try { test_stcph_hi_hints(); } catch (...) { std::cerr << "FAIL: stcph_hi_hints" << std::endl; failed++; }
    try { test_stshh_hi_hints(); } catch (...) { std::cerr << "FAIL: stshh_hi_hints" << std::endl; failed++; }
    try { test_svc_ex_exception(); } catch (...) { std::cerr << "FAIL: svc_ex_exception" << std::endl; failed++; }
    try { test_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_sysl_rc_systeminstrs(); } catch (...) { std::cerr << "FAIL: sysl_rc_systeminstrs" << std::endl; failed++; }
    try { test_sysp_cr_syspairinstrs(); } catch (...) { std::cerr << "FAIL: sysp_cr_syspairinstrs" << std::endl; failed++; }
    try { test_tbnz_only_testbranch(); } catch (...) { std::cerr << "FAIL: tbnz_only_testbranch" << std::endl; failed++; }
    try { test_tbz_only_testbranch(); } catch (...) { std::cerr << "FAIL: tbz_only_testbranch" << std::endl; failed++; }
    try { test_tlbi_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: tlbi_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_tlbip_sysp_cr_syspairinstrs(); } catch (...) { std::cerr << "FAIL: tlbip_sysp_cr_syspairinstrs" << std::endl; failed++; }
    try { test_trcit_sys_cr_systeminstrs(); } catch (...) { std::cerr << "FAIL: trcit_sys_cr_systeminstrs" << std::endl; failed++; }
    try { test_tsb_hc_hints(); } catch (...) { std::cerr << "FAIL: tsb_hc_hints" << std::endl; failed++; }
    try { test_wfe_hi_hints(); } catch (...) { std::cerr << "FAIL: wfe_hi_hints" << std::endl; failed++; }
    try { test_wfet_only_systeminstrswithreg(); } catch (...) { std::cerr << "FAIL: wfet_only_systeminstrswithreg" << std::endl; failed++; }
    try { test_wfi_hi_hints(); } catch (...) { std::cerr << "FAIL: wfi_hi_hints" << std::endl; failed++; }
    try { test_wfit_only_systeminstrswithreg(); } catch (...) { std::cerr << "FAIL: wfit_only_systeminstrswithreg" << std::endl; failed++; }
    try { test_xaflag_m_pstate(); } catch (...) { std::cerr << "FAIL: xaflag_m_pstate" << std::endl; failed++; }
    try { test_xpaclri_hi_hints(); } catch (...) { std::cerr << "FAIL: xpaclri_hi_hints" << std::endl; failed++; }
    try { test_yield_hi_hints(); } catch (...) { std::cerr << "FAIL: yield_hi_hints" << std::endl; failed++; }

    std::cout << (178 - failed) << " / 178 passed" << std::endl;
    return failed;
}
