// Auto-generated - do not edit
// Per-encoding tests for sme format group
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_add_mz_zzv_2x1() {
    uint32_t insn = 0xC120A300u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_add_mz_zzv_4x1() {
    uint32_t insn = 0xC120AB00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_add_za_zw_2x2() {
    uint32_t insn = 0xC1A01C10u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  add_za_zw_2x2: " << result->to_string() << std::endl;
}

void test_add_za_zw_4x4() {
    uint32_t insn = 0xC1A11C10u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  add_za_zw_4x4: " << result->to_string() << std::endl;
}

void test_add_za_zzv_2x1() {
    uint32_t insn = 0xC1201810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_add_za_zzv_4x1() {
    uint32_t insn = 0xC1301810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    std::cout << "  add_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_add_za_zzw_2x2() {
    uint32_t insn = 0xC1A01810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  add_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_add_za_zzw_4x4() {
    uint32_t insn = 0xC1A11810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  add_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_addha_za_pp_z_32() {
    uint32_t insn = 0xC0900000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADDHA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  addha_za_pp_z_32: " << result->to_string() << std::endl;
}

void test_addha_za_pp_z_64() {
    uint32_t insn = 0xC0D00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADDHA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  addha_za_pp_z_64: " << result->to_string() << std::endl;
}

void test_addva_za_pp_z_32() {
    uint32_t insn = 0xC0910000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADDVA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  addva_za_pp_z_32: " << result->to_string() << std::endl;
}

void test_addva_za_pp_z_64() {
    uint32_t insn = 0xC0D10000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ADDVA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  addva_za_pp_z_64: " << result->to_string() << std::endl;
}

void test_bf1cvt_mz2_z8_() {
    uint32_t insn = 0xC166E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bf1cvt_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bf2cvt_mz2_z8_() {
    uint32_t insn = 0xC1E6E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bf2cvt_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bf1cvtl_mz2_z8_() {
    uint32_t insn = 0xC166E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bf1cvtl_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bf2cvtl_mz2_z8_() {
    uint32_t insn = 0xC1E6E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bf2cvtl_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bfadd_za_zw_2x2_16() {
    uint32_t insn = 0xC1E41C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfadd_za_zw_2x2_16: " << result->to_string() << std::endl;
}

void test_bfadd_za_zw_4x4_16() {
    uint32_t insn = 0xC1E51C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfadd_za_zw_4x4_16: " << result->to_string() << std::endl;
}

void test_bfclamp_mz_zz_2() {
    uint32_t insn = 0xC120C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFCLAMP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfclamp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_bfclamp_mz_zz_4() {
    uint32_t insn = 0xC120C800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFCLAMP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfclamp_mz_zz_4: " << result->to_string() << std::endl;
}

void test_bfcvt_z8_mz2_() {
    uint32_t insn = 0xC164E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfcvt_z8_mz2_: " << result->to_string() << std::endl;
}

void test_bfcvt_z_mz2_() {
    uint32_t insn = 0xC160E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfcvt_z_mz2_: " << result->to_string() << std::endl;
}

void test_bfcvtn_z_mz2_() {
    uint32_t insn = 0xC160E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfcvtn_z_mz2_: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzi_2xi() {
    uint32_t insn = 0xC1501018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfdot_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzi_4xi() {
    uint32_t insn = 0xC1509018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfdot_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzv_2x1() {
    uint32_t insn = 0xC1201010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfdot_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzv_4x1() {
    uint32_t insn = 0xC1301010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfdot_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzw_2x2() {
    uint32_t insn = 0xC1A01010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfdot_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfdot_za_zzw_4x4() {
    uint32_t insn = 0xC1A11010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfdot_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmax_mz_zzv_2x1() {
    uint32_t insn = 0xC120A100u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAX);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmax_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmax_mz_zzv_4x1() {
    uint32_t insn = 0xC120A900u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAX);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmax_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmax_mz_zzw_2x2() {
    uint32_t insn = 0xC120B100u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmax_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmax_mz_zzw_4x4() {
    uint32_t insn = 0xC120B900u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmax_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmaxnm_mz_zzv_2x1() {
    uint32_t insn = 0xC120A120u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAXNM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmaxnm_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmaxnm_mz_zzv_4x1() {
    uint32_t insn = 0xC120A920u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAXNM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmaxnm_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmaxnm_mz_zzw_2x2() {
    uint32_t insn = 0xC120B120u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAXNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmaxnm_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmaxnm_mz_zzw_4x4() {
    uint32_t insn = 0xC120B920u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMAXNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmaxnm_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmin_mz_zzv_2x1() {
    uint32_t insn = 0xC120A101u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMIN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmin_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmin_mz_zzv_4x1() {
    uint32_t insn = 0xC120A901u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMIN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmin_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmin_mz_zzw_2x2() {
    uint32_t insn = 0xC120B101u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmin_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmin_mz_zzw_4x4() {
    uint32_t insn = 0xC120B901u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmin_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfminnm_mz_zzv_2x1() {
    uint32_t insn = 0xC120A121u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMINNM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfminnm_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfminnm_mz_zzv_4x1() {
    uint32_t insn = 0xC120A921u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMINNM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfminnm_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfminnm_mz_zzw_2x2() {
    uint32_t insn = 0xC120B121u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMINNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfminnm_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfminnm_mz_zzw_4x4() {
    uint32_t insn = 0xC120B921u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMINNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfminnm_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzi_h2xi() {
    uint32_t insn = 0xC1101020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmla_za_zzi_h2xi: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzi_h4xi() {
    uint32_t insn = 0xC1109020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmla_za_zzi_h4xi: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzv_2x1_16() {
    uint32_t insn = 0xC1601C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmla_za_zzv_2x1_16: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzv_4x1_16() {
    uint32_t insn = 0xC1701C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmla_za_zzv_4x1_16: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzw_2x2_16() {
    uint32_t insn = 0xC1E01008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmla_za_zzw_2x2_16: " << result->to_string() << std::endl;
}

void test_bfmla_za_zzw_4x4_16() {
    uint32_t insn = 0xC1E11008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmla_za_zzw_4x4_16: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzi_1() {
    uint32_t insn = 0xC1801010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    std::cout << "  bfmlal_za_zzi_1: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzi_2xi() {
    uint32_t insn = 0xC1901010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlal_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzi_4xi() {
    uint32_t insn = 0xC1909010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlal_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzv_1() {
    uint32_t insn = 0xC1200C10u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    std::cout << "  bfmlal_za_zzv_1: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzv_2x1() {
    uint32_t insn = 0xC1200810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlal_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzv_4x1() {
    uint32_t insn = 0xC1300810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlal_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzw_2x2() {
    uint32_t insn = 0xC1A00810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmlal_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmlal_za_zzw_4x4() {
    uint32_t insn = 0xC1A10810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmlal_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzi_h2xi() {
    uint32_t insn = 0xC1101030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmls_za_zzi_h2xi: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzi_h4xi() {
    uint32_t insn = 0xC1109030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmls_za_zzi_h4xi: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzv_2x1_16() {
    uint32_t insn = 0xC1601C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmls_za_zzv_2x1_16: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzv_4x1_16() {
    uint32_t insn = 0xC1701C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmls_za_zzv_4x1_16: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzw_2x2_16() {
    uint32_t insn = 0xC1E01018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmls_za_zzw_2x2_16: " << result->to_string() << std::endl;
}

void test_bfmls_za_zzw_4x4_16() {
    uint32_t insn = 0xC1E11018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmls_za_zzw_4x4_16: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzi_1() {
    uint32_t insn = 0xC1801018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    std::cout << "  bfmlsl_za_zzi_1: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzi_2xi() {
    uint32_t insn = 0xC1901018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlsl_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzi_4xi() {
    uint32_t insn = 0xC1909018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlsl_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzv_1() {
    uint32_t insn = 0xC1200C18u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    std::cout << "  bfmlsl_za_zzv_1: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzv_2x1() {
    uint32_t insn = 0xC1200818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlsl_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzv_4x1() {
    uint32_t insn = 0xC1300818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmlsl_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzw_2x2() {
    uint32_t insn = 0xC1A00818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmlsl_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmlsl_za_zzw_4x4() {
    uint32_t insn = 0xC1A10818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfmlsl_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfmop4a_za32_zz_h1x2() {
    uint32_t insn = 0x81100000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4a_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_bfmop4a_za32_zz_h1x1() {
    uint32_t insn = 0x81000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4a_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_bfmop4a_za32_zz_h2x1() {
    uint32_t insn = 0x81000200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4a_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_bfmop4a_za32_zz_h2x2() {
    uint32_t insn = 0x81100200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4a_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_bfmop4a_za_zz_h1x2() {
    uint32_t insn = 0x81300008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_bfmop4a_za_zz_h1x1() {
    uint32_t insn = 0x81200008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_bfmop4a_za_zz_h2x1() {
    uint32_t insn = 0x81200208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_bfmop4a_za_zz_h2x2() {
    uint32_t insn = 0x81300208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_bfmop4s_za32_zz_h1x2() {
    uint32_t insn = 0x81100010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4s_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_bfmop4s_za32_zz_h1x1() {
    uint32_t insn = 0x81000010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4s_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_bfmop4s_za32_zz_h2x1() {
    uint32_t insn = 0x81000210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4s_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_bfmop4s_za32_zz_h2x2() {
    uint32_t insn = 0x81100210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4s_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_bfmop4s_za_zz_h1x2() {
    uint32_t insn = 0x81300018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_bfmop4s_za_zz_h1x1() {
    uint32_t insn = 0x81200018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_bfmop4s_za_zz_h2x1() {
    uint32_t insn = 0x81200218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  bfmop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_bfmop4s_za_zz_h2x2() {
    uint32_t insn = 0x81300218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  bfmop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_bfmopa_za32_pp_zz_() {
    uint32_t insn = 0x81800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bfmopa_za32_pp_zz_: " << result->to_string() << std::endl;
}

void test_bfmopa_za_pp_zz_16() {
    uint32_t insn = 0x81A00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bfmopa_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_bfmops_za32_pp_zz_() {
    uint32_t insn = 0x81800010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bfmops_za32_pp_zz_: " << result->to_string() << std::endl;
}

void test_bfmops_za_pp_zz_16() {
    uint32_t insn = 0x81A00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bfmops_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_bfmul_mz_zzv_2x1() {
    uint32_t insn = 0xC120E800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmul_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfmul_mz_zzv_4x1() {
    uint32_t insn = 0xC121E800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfmul_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfmul_mz_zzw_2x2() {
    uint32_t insn = 0xC120E400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmul_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfmul_mz_zzw_4x4() {
    uint32_t insn = 0xC121E400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFMUL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfmul_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfscale_mz_zzv_2x1() {
    uint32_t insn = 0xC120A180u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSCALE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfscale_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_bfscale_mz_zzv_4x1() {
    uint32_t insn = 0xC120A980u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSCALE);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfscale_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_bfscale_mz_zzw_2x2() {
    uint32_t insn = 0xC120B180u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSCALE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfscale_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bfscale_mz_zzw_4x4() {
    uint32_t insn = 0xC120B980u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSCALE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  bfscale_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_bfsub_za_zw_2x2_16() {
    uint32_t insn = 0xC1E41C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfsub_za_zw_2x2_16: " << result->to_string() << std::endl;
}

void test_bfsub_za_zw_4x4_16() {
    uint32_t insn = 0xC1E51C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  bfsub_za_zw_4x4_16: " << result->to_string() << std::endl;
}

void test_bftmopa_za32_zzzi_h2x1() {
    uint32_t insn = 0x81400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  bftmopa_za32_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_bftmopa_za_zzzi_h2x1() {
    uint32_t insn = 0x81600008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  bftmopa_za_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_bfvdot_za_zzi_2xi() {
    uint32_t insn = 0xC1500018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BFVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  bfvdot_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_bmopa_za_pp_zz_32() {
    uint32_t insn = 0x80800008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bmopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_bmops_za_pp_zz_32() {
    uint32_t insn = 0x80800018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::BMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  bmops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_f1cvt_mz2_z8_() {
    uint32_t insn = 0xC126E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  f1cvt_mz2_z8_: " << result->to_string() << std::endl;
}

void test_f2cvt_mz2_z8_() {
    uint32_t insn = 0xC1A6E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  f2cvt_mz2_z8_: " << result->to_string() << std::endl;
}

void test_f1cvtl_mz2_z8_() {
    uint32_t insn = 0xC126E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  f1cvtl_mz2_z8_: " << result->to_string() << std::endl;
}

void test_f2cvtl_mz2_z8_() {
    uint32_t insn = 0xC1A6E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  f2cvtl_mz2_z8_: " << result->to_string() << std::endl;
}

void test_fadd_za_zw_2x2() {
    uint32_t insn = 0xC1A01C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fadd_za_zw_2x2: " << result->to_string() << std::endl;
}

void test_fadd_za_zw_2x2_16() {
    uint32_t insn = 0xC1A41C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fadd_za_zw_2x2_16: " << result->to_string() << std::endl;
}

void test_fadd_za_zw_4x4() {
    uint32_t insn = 0xC1A11C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fadd_za_zw_4x4: " << result->to_string() << std::endl;
}

void test_fadd_za_zw_4x4_16() {
    uint32_t insn = 0xC1A51C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FADD);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fadd_za_zw_4x4_16: " << result->to_string() << std::endl;
}

void test_famax_mz_zzw_2x2() {
    uint32_t insn = 0xC160B140u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FAMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  famax_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_famax_mz_zzw_4x4() {
    uint32_t insn = 0xC160B940u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FAMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  famax_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_famin_mz_zzw_2x2() {
    uint32_t insn = 0xC160B141u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FAMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  famin_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_famin_mz_zzw_4x4() {
    uint32_t insn = 0xC160B941u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FAMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  famin_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fclamp_mz_zz_2() {
    uint32_t insn = 0xC120C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCLAMP);
    std::cout << "  fclamp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_fclamp_mz_zz_4() {
    uint32_t insn = 0xC120C800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCLAMP);
    std::cout << "  fclamp_mz_zz_4: " << result->to_string() << std::endl;
}

void test_fcvt_mz2_z_() {
    uint32_t insn = 0xC1A0E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fcvt_mz2_z_: " << result->to_string() << std::endl;
}

void test_fcvt_z8_mz2_() {
    uint32_t insn = 0xC124E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fcvt_z8_mz2_: " << result->to_string() << std::endl;
}

void test_fcvt_z8_mz4_() {
    uint32_t insn = 0xC134E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fcvt_z8_mz4_: " << result->to_string() << std::endl;
}

void test_fcvt_z_mz2_() {
    uint32_t insn = 0xC120E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fcvt_z_mz2_: " << result->to_string() << std::endl;
}

void test_fcvtl_mz2_z_() {
    uint32_t insn = 0xC1A0E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fcvtl_mz2_z_: " << result->to_string() << std::endl;
}

void test_fcvtn_z8_mz4_() {
    uint32_t insn = 0xC134E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fcvtn_z8_mz4_: " << result->to_string() << std::endl;
}

void test_fcvtn_z_mz2_() {
    uint32_t insn = 0xC120E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTN);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fcvtn_z_mz2_: " << result->to_string() << std::endl;
}

void test_fcvtzs_mz_z_2() {
    uint32_t insn = 0xC121E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fcvtzs_mz_z_2: " << result->to_string() << std::endl;
}

void test_fcvtzs_mz_z_4() {
    uint32_t insn = 0xC131E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTZS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fcvtzs_mz_z_4: " << result->to_string() << std::endl;
}

void test_fcvtzu_mz_z_2() {
    uint32_t insn = 0xC121E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fcvtzu_mz_z_2: " << result->to_string() << std::endl;
}

void test_fcvtzu_mz_z_4() {
    uint32_t insn = 0xC131E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FCVTZU);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fcvtzu_mz_z_4: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8i_2xi() {
    uint32_t insn = 0xC1500038u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za32_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8i_4xi() {
    uint32_t insn = 0xC1508008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za32_z8z8i_4xi: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8v_2x1() {
    uint32_t insn = 0xC1201018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za32_z8z8v_2x1: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8v_4x1() {
    uint32_t insn = 0xC1301018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za32_z8z8v_4x1: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8w_2x2() {
    uint32_t insn = 0xC1A01030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za32_z8z8w_2x2: " << result->to_string() << std::endl;
}

void test_fdot_za32_z8z8w_4x4() {
    uint32_t insn = 0xC1A11030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za32_z8z8w_4x4: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8i_2xi() {
    uint32_t insn = 0xC1D00020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8i_4xi() {
    uint32_t insn = 0xC1109040u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_z8z8i_4xi: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8v_2x1() {
    uint32_t insn = 0xC1201008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_z8z8v_2x1: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8v_4x1() {
    uint32_t insn = 0xC1301008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_z8z8v_4x1: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8w_2x2() {
    uint32_t insn = 0xC1A01020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za_z8z8w_2x2: " << result->to_string() << std::endl;
}

void test_fdot_za_z8z8w_4x4() {
    uint32_t insn = 0xC1A11020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za_z8z8w_4x4: " << result->to_string() << std::endl;
}

void test_fdot_za_zzi_2xi() {
    uint32_t insn = 0xC1501008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_fdot_za_zzi_4xi() {
    uint32_t insn = 0xC1509008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_fdot_za_zzv_2x1() {
    uint32_t insn = 0xC1201000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fdot_za_zzv_4x1() {
    uint32_t insn = 0xC1301000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fdot_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fdot_za_zzw_2x2() {
    uint32_t insn = 0xC1A01000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fdot_za_zzw_4x4() {
    uint32_t insn = 0xC1A11000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fdot_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmax_mz_zzv_2x1() {
    uint32_t insn = 0xC120A100u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmax_mz_zzv_4x1() {
    uint32_t insn = 0xC120A900u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAX);
    std::cout << "  fmax_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmax_mz_zzw_2x2() {
    uint32_t insn = 0xC120B100u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmax_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmax_mz_zzw_4x4() {
    uint32_t insn = 0xC120B900u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmax_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmaxnm_mz_zzv_2x1() {
    uint32_t insn = 0xC120A120u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmaxnm_mz_zzv_4x1() {
    uint32_t insn = 0xC120A920u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAXNM);
    std::cout << "  fmaxnm_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmaxnm_mz_zzw_2x2() {
    uint32_t insn = 0xC120B120u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAXNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmaxnm_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmaxnm_mz_zzw_4x4() {
    uint32_t insn = 0xC120B920u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMAXNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmaxnm_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmin_mz_zzv_2x1() {
    uint32_t insn = 0xC120A101u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmin_mz_zzv_4x1() {
    uint32_t insn = 0xC120A901u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMIN);
    std::cout << "  fmin_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmin_mz_zzw_2x2() {
    uint32_t insn = 0xC120B101u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmin_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmin_mz_zzw_4x4() {
    uint32_t insn = 0xC120B901u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmin_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fminnm_mz_zzv_2x1() {
    uint32_t insn = 0xC120A121u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fminnm_mz_zzv_4x1() {
    uint32_t insn = 0xC120A921u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMINNM);
    std::cout << "  fminnm_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fminnm_mz_zzw_2x2() {
    uint32_t insn = 0xC120B121u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMINNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fminnm_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fminnm_mz_zzw_4x4() {
    uint32_t insn = 0xC120B921u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMINNM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fminnm_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_h2xi() {
    uint32_t insn = 0xC1101000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_h2xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_s2xi() {
    uint32_t insn = 0xC1500000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_d2xi() {
    uint32_t insn = 0xC1D00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_h4xi() {
    uint32_t insn = 0xC1109000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_h4xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_s4xi() {
    uint32_t insn = 0xC1508000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_fmla_za_zzv_2x1() {
    uint32_t insn = 0xC1201800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmla_za_zzv_2x1_16() {
    uint32_t insn = 0xC1201C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzv_2x1_16: " << result->to_string() << std::endl;
}

void test_fmla_za_zzv_4x1() {
    uint32_t insn = 0xC1301800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    std::cout << "  fmla_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmla_za_zzv_4x1_16() {
    uint32_t insn = 0xC1301C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmla_za_zzv_4x1_16: " << result->to_string() << std::endl;
}

void test_fmla_za_zzw_2x2() {
    uint32_t insn = 0xC1A01800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmla_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmla_za_zzw_2x2_16() {
    uint32_t insn = 0xC1A01008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmla_za_zzw_2x2_16: " << result->to_string() << std::endl;
}

void test_fmla_za_zzw_4x4() {
    uint32_t insn = 0xC1A11800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmla_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmla_za_zzw_4x4_16() {
    uint32_t insn = 0xC1A11008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmla_za_zzw_4x4_16: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8i_1() {
    uint32_t insn = 0xC1C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    std::cout << "  fmlal_za_z8z8i_1: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8i_2xi() {
    uint32_t insn = 0xC1901030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8i_4xi() {
    uint32_t insn = 0xC1909020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_z8z8i_4xi: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8v_1() {
    uint32_t insn = 0xC1300C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    std::cout << "  fmlal_za_z8z8v_1: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8v_2x1() {
    uint32_t insn = 0xC1200804u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_z8z8v_2x1: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8v_4x1() {
    uint32_t insn = 0xC1300804u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_z8z8v_4x1: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8w_2x2() {
    uint32_t insn = 0xC1A00820u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlal_za_z8z8w_2x2: " << result->to_string() << std::endl;
}

void test_fmlal_za_z8z8w_4x4() {
    uint32_t insn = 0xC1A10820u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlal_za_z8z8w_4x4: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzi_1() {
    uint32_t insn = 0xC1801000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    std::cout << "  fmlal_za_zzi_1: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzi_2xi() {
    uint32_t insn = 0xC1901000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzi_4xi() {
    uint32_t insn = 0xC1909000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzv_1() {
    uint32_t insn = 0xC1200C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    std::cout << "  fmlal_za_zzv_1: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzv_2x1() {
    uint32_t insn = 0xC1200800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzv_4x1() {
    uint32_t insn = 0xC1300800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlal_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzw_2x2() {
    uint32_t insn = 0xC1A00800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlal_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmlal_za_zzw_4x4() {
    uint32_t insn = 0xC1A10800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlal_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8i_1() {
    uint32_t insn = 0xC1400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    std::cout << "  fmlall_za32_z8z8i_1: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8i_2xi() {
    uint32_t insn = 0xC1900020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlall_za32_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8i_4xi() {
    uint32_t insn = 0xC1108040u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlall_za32_z8z8i_4xi: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8v_1() {
    uint32_t insn = 0xC1300400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    std::cout << "  fmlall_za32_z8z8v_1: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8v_2x1() {
    uint32_t insn = 0xC1200002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlall_za32_z8z8v_2x1: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8v_4x1() {
    uint32_t insn = 0xC1300002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlall_za32_z8z8v_4x1: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8w_2x2() {
    uint32_t insn = 0xC1A00020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlall_za32_z8z8w_2x2: " << result->to_string() << std::endl;
}

void test_fmlall_za32_z8z8w_4x4() {
    uint32_t insn = 0xC1A10020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlall_za32_z8z8w_4x4: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_h2xi() {
    uint32_t insn = 0xC1101010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_h2xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_s2xi() {
    uint32_t insn = 0xC1500010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_d2xi() {
    uint32_t insn = 0xC1D00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_h4xi() {
    uint32_t insn = 0xC1109010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_h4xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_s4xi() {
    uint32_t insn = 0xC1508010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_fmls_za_zzv_2x1() {
    uint32_t insn = 0xC1201808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmls_za_zzv_2x1_16() {
    uint32_t insn = 0xC1201C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzv_2x1_16: " << result->to_string() << std::endl;
}

void test_fmls_za_zzv_4x1() {
    uint32_t insn = 0xC1301808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    std::cout << "  fmls_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmls_za_zzv_4x1_16() {
    uint32_t insn = 0xC1301C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmls_za_zzv_4x1_16: " << result->to_string() << std::endl;
}

void test_fmls_za_zzw_2x2() {
    uint32_t insn = 0xC1A01808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmls_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmls_za_zzw_2x2_16() {
    uint32_t insn = 0xC1A01018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmls_za_zzw_2x2_16: " << result->to_string() << std::endl;
}

void test_fmls_za_zzw_4x4() {
    uint32_t insn = 0xC1A11808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmls_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmls_za_zzw_4x4_16() {
    uint32_t insn = 0xC1A11018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLS);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmls_za_zzw_4x4_16: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzi_1() {
    uint32_t insn = 0xC1801008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    std::cout << "  fmlsl_za_zzi_1: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzi_2xi() {
    uint32_t insn = 0xC1901008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlsl_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzi_4xi() {
    uint32_t insn = 0xC1909008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlsl_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzv_1() {
    uint32_t insn = 0xC1200C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    std::cout << "  fmlsl_za_zzv_1: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzv_2x1() {
    uint32_t insn = 0xC1200808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlsl_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzv_4x1() {
    uint32_t insn = 0xC1300808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fmlsl_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzw_2x2() {
    uint32_t insn = 0xC1A00808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlsl_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmlsl_za_zzw_4x4() {
    uint32_t insn = 0xC1A10808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fmlsl_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fmop4a_za16_z8z8_b1x2() {
    uint32_t insn = 0x80300008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za16_z8z8_b1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za16_z8z8_b1x1() {
    uint32_t insn = 0x80200008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za16_z8z8_b1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za16_z8z8_b2x1() {
    uint32_t insn = 0x80200208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za16_z8z8_b2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za16_z8z8_b2x2() {
    uint32_t insn = 0x80300208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za16_z8z8_b2x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_z8z8_b1x2() {
    uint32_t insn = 0x80300000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za32_z8z8_b1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_z8z8_b1x1() {
    uint32_t insn = 0x80200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za32_z8z8_b1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_z8z8_b2x1() {
    uint32_t insn = 0x80200200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za32_z8z8_b2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_z8z8_b2x2() {
    uint32_t insn = 0x80300200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za32_z8z8_b2x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_zz_h1x2() {
    uint32_t insn = 0x81300000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_zz_h1x1() {
    uint32_t insn = 0x81200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_zz_h2x1() {
    uint32_t insn = 0x81200200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za32_zz_h2x2() {
    uint32_t insn = 0x81300200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_h1x2() {
    uint32_t insn = 0x81100008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_h1x1() {
    uint32_t insn = 0x81000008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_h2x1() {
    uint32_t insn = 0x81000208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_h2x2() {
    uint32_t insn = 0x81100208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_s1x2() {
    uint32_t insn = 0x80100000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_s1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_s1x1() {
    uint32_t insn = 0x80000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_s1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_s2x1() {
    uint32_t insn = 0x80000200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_s2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_s2x2() {
    uint32_t insn = 0x80100200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_s2x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_d1x2() {
    uint32_t insn = 0x80D00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_d1x2: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_d1x1() {
    uint32_t insn = 0x80C00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_d1x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_d2x1() {
    uint32_t insn = 0x80C00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4a_za_zz_d2x1: " << result->to_string() << std::endl;
}

void test_fmop4a_za_zz_d2x2() {
    uint32_t insn = 0x80D00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4a_za_zz_d2x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za32_zz_h1x2() {
    uint32_t insn = 0x81300010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za32_zz_h1x1() {
    uint32_t insn = 0x81200010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za32_zz_h2x1() {
    uint32_t insn = 0x81200210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za32_zz_h2x2() {
    uint32_t insn = 0x81300210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_h1x2() {
    uint32_t insn = 0x81100018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_h1x1() {
    uint32_t insn = 0x81000018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_h2x1() {
    uint32_t insn = 0x81000218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_h2x2() {
    uint32_t insn = 0x81100218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_s1x2() {
    uint32_t insn = 0x80100010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_s1x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_s1x1() {
    uint32_t insn = 0x80000010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_s1x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_s2x1() {
    uint32_t insn = 0x80000210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_s2x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_s2x2() {
    uint32_t insn = 0x80100210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_s2x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_d1x2() {
    uint32_t insn = 0x80D00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_d1x2: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_d1x1() {
    uint32_t insn = 0x80C00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_d1x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_d2x1() {
    uint32_t insn = 0x80C00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  fmop4s_za_zz_d2x1: " << result->to_string() << std::endl;
}

void test_fmop4s_za_zz_d2x2() {
    uint32_t insn = 0x80D00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  fmop4s_za_zz_d2x2: " << result->to_string() << std::endl;
}

void test_fmopa_za16_pp_z8z8_8() {
    uint32_t insn = 0x80A00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za16_pp_z8z8_8: " << result->to_string() << std::endl;
}

void test_fmopa_za32_pp_z8z8_8() {
    uint32_t insn = 0x80A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za32_pp_z8z8_8: " << result->to_string() << std::endl;
}

void test_fmopa_za32_pp_zz_16() {
    uint32_t insn = 0x81A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmopa_za_pp_zz_16() {
    uint32_t insn = 0x81800008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmopa_za_pp_zz_32() {
    uint32_t insn = 0x80800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_fmopa_za_pp_zz_64() {
    uint32_t insn = 0x80C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmopa_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_fmops_za32_pp_zz_16() {
    uint32_t insn = 0x81A00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmops_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmops_za_pp_zz_16() {
    uint32_t insn = 0x81800018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmops_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmops_za_pp_zz_32() {
    uint32_t insn = 0x80800010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_fmops_za_pp_zz_64() {
    uint32_t insn = 0x80C00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  fmops_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_fmul_mz_zzv_2x1() {
    uint32_t insn = 0xC120E800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fmul_mz_zzv_4x1() {
    uint32_t insn = 0xC121E800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMUL);
    std::cout << "  fmul_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fmul_mz_zzw_2x2() {
    uint32_t insn = 0xC120E400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMUL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmul_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fmul_mz_zzw_4x4() {
    uint32_t insn = 0xC121E400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FMUL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fmul_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_frinta_mz_z_2() {
    uint32_t insn = 0xC1ACE000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frinta_mz_z_2: " << result->to_string() << std::endl;
}

void test_frinta_mz_z_4() {
    uint32_t insn = 0xC1BCE000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frinta_mz_z_4: " << result->to_string() << std::endl;
}

void test_frintm_mz_z_2() {
    uint32_t insn = 0xC1AAE000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintm_mz_z_2: " << result->to_string() << std::endl;
}

void test_frintm_mz_z_4() {
    uint32_t insn = 0xC1BAE000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTM);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintm_mz_z_4: " << result->to_string() << std::endl;
}

void test_frintn_mz_z_2() {
    uint32_t insn = 0xC1A8E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintn_mz_z_2: " << result->to_string() << std::endl;
}

void test_frintn_mz_z_4() {
    uint32_t insn = 0xC1B8E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintn_mz_z_4: " << result->to_string() << std::endl;
}

void test_frintp_mz_z_2() {
    uint32_t insn = 0xC1A9E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintp_mz_z_2: " << result->to_string() << std::endl;
}

void test_frintp_mz_z_4() {
    uint32_t insn = 0xC1B9E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FRINTP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  frintp_mz_z_4: " << result->to_string() << std::endl;
}

void test_fscale_mz_zzv_2x1() {
    uint32_t insn = 0xC120A180u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSCALE);
    std::cout << "  fscale_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_fscale_mz_zzv_4x1() {
    uint32_t insn = 0xC120A980u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSCALE);
    std::cout << "  fscale_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_fscale_mz_zzw_2x2() {
    uint32_t insn = 0xC120B180u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSCALE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fscale_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_fscale_mz_zzw_4x4() {
    uint32_t insn = 0xC120B980u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSCALE);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  fscale_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_fsub_za_zw_2x2() {
    uint32_t insn = 0xC1A01C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fsub_za_zw_2x2: " << result->to_string() << std::endl;
}

void test_fsub_za_zw_2x2_16() {
    uint32_t insn = 0xC1A41C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fsub_za_zw_2x2_16: " << result->to_string() << std::endl;
}

void test_fsub_za_zw_4x4() {
    uint32_t insn = 0xC1A11C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fsub_za_zw_4x4: " << result->to_string() << std::endl;
}

void test_fsub_za_zw_4x4_16() {
    uint32_t insn = 0xC1A51C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FSUB);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  fsub_za_zw_4x4_16: " << result->to_string() << std::endl;
}

void test_ftmopa_za16_z8z8zi_b2x1() {
    uint32_t insn = 0x80600008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ftmopa_za16_z8z8zi_b2x1: " << result->to_string() << std::endl;
}

void test_ftmopa_za32_z8z8zi_b2x1() {
    uint32_t insn = 0x80600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ftmopa_za32_z8z8zi_b2x1: " << result->to_string() << std::endl;
}

void test_ftmopa_za32_zzzi_h2x1() {
    uint32_t insn = 0x81600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ftmopa_za32_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_ftmopa_za_zzzi_h2x1() {
    uint32_t insn = 0x81400008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ftmopa_za_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_ftmopa_za_zzzi_s2x1() {
    uint32_t insn = 0x80400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ftmopa_za_zzzi_s2x1: " << result->to_string() << std::endl;
}

void test_fvdot_za_z8z8i_2xi() {
    uint32_t insn = 0xC1D01020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fvdot_za_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fvdot_za_zzi_2xi() {
    uint32_t insn = 0xC1500008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  fvdot_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_fvdotb_za32_z8z8i_2xi() {
    uint32_t insn = 0xC1D00800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FVDOTB);
    std::cout << "  fvdotb_za32_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_fvdott_za32_z8z8i_2xi() {
    uint32_t insn = 0xC1D00810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::FVDOTT);
    std::cout << "  fvdott_za32_z8z8i_2xi: " << result->to_string() << std::endl;
}

void test_ld1b_mz_p_bi_2() {
    uint32_t insn = 0xA0400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1b_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ld1b_mz_p_bi_4() {
    uint32_t insn = 0xA0408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1b_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ld1b_mz_p_br_2() {
    uint32_t insn = 0xA0000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1b_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ld1b_mz_p_br_4() {
    uint32_t insn = 0xA0008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1b_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ld1b_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1b_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ld1b_mzx_p_bi_4x4() {
    uint32_t insn = 0xA1408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1b_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ld1b_mzx_p_br_2x8() {
    uint32_t insn = 0xA1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1b_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ld1b_mzx_p_br_4x4() {
    uint32_t insn = 0xA1008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1b_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ld1b_za_p_rrr_() {
    uint32_t insn = 0xE0000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1b_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ld1d_mz_p_bi_2() {
    uint32_t insn = 0xA0406000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1d_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ld1d_mz_p_bi_4() {
    uint32_t insn = 0xA040E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1d_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ld1d_mz_p_br_2() {
    uint32_t insn = 0xA0006000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1d_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ld1d_mz_p_br_4() {
    uint32_t insn = 0xA000E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1d_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ld1d_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1406000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1d_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ld1d_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1d_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ld1d_mzx_p_br_2x8() {
    uint32_t insn = 0xA1006000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1d_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ld1d_mzx_p_br_4x4() {
    uint32_t insn = 0xA100E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1d_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ld1d_za_p_rrr_() {
    uint32_t insn = 0xE0C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1d_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ld1h_mz_p_bi_2() {
    uint32_t insn = 0xA0402000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1h_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ld1h_mz_p_bi_4() {
    uint32_t insn = 0xA040A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1h_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ld1h_mz_p_br_2() {
    uint32_t insn = 0xA0002000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1h_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ld1h_mz_p_br_4() {
    uint32_t insn = 0xA000A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1h_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ld1h_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1402000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1h_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ld1h_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1h_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ld1h_mzx_p_br_2x8() {
    uint32_t insn = 0xA1002000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1h_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ld1h_mzx_p_br_4x4() {
    uint32_t insn = 0xA100A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1h_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ld1h_za_p_rrr_() {
    uint32_t insn = 0xE0400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1h_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ld1q_za_p_rrr_() {
    uint32_t insn = 0xE1C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1q_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ld1w_mz_p_bi_2() {
    uint32_t insn = 0xA0404000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1w_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ld1w_mz_p_bi_4() {
    uint32_t insn = 0xA040C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1w_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ld1w_mz_p_br_2() {
    uint32_t insn = 0xA0004000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1w_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ld1w_mz_p_br_4() {
    uint32_t insn = 0xA000C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1w_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ld1w_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1404000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1w_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ld1w_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ld1w_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ld1w_mzx_p_br_2x8() {
    uint32_t insn = 0xA1004000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1w_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ld1w_mzx_p_br_4x4() {
    uint32_t insn = 0xA100C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1w_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ld1w_za_p_rrr_() {
    uint32_t insn = 0xE0800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ld1w_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ldnt1b_mz_p_bi_2() {
    uint32_t insn = 0xA0400001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1b_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ldnt1b_mz_p_bi_4() {
    uint32_t insn = 0xA0408001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1b_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ldnt1b_mz_p_br_2() {
    uint32_t insn = 0xA0000001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1b_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ldnt1b_mz_p_br_4() {
    uint32_t insn = 0xA0008001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1b_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ldnt1b_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1400008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1b_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1b_mzx_p_bi_4x4() {
    uint32_t insn = 0xA1408008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1b_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1b_mzx_p_br_2x8() {
    uint32_t insn = 0xA1000008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1b_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1b_mzx_p_br_4x4() {
    uint32_t insn = 0xA1008008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1b_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1d_mz_p_bi_2() {
    uint32_t insn = 0xA0406001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1d_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ldnt1d_mz_p_bi_4() {
    uint32_t insn = 0xA040E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1d_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ldnt1d_mz_p_br_2() {
    uint32_t insn = 0xA0006001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1d_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ldnt1d_mz_p_br_4() {
    uint32_t insn = 0xA000E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1d_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ldnt1d_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1406008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1d_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1d_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140E008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1d_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1d_mzx_p_br_2x8() {
    uint32_t insn = 0xA1006008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1d_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1d_mzx_p_br_4x4() {
    uint32_t insn = 0xA100E008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1d_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1h_mz_p_bi_2() {
    uint32_t insn = 0xA0402001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1h_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ldnt1h_mz_p_bi_4() {
    uint32_t insn = 0xA040A001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1h_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ldnt1h_mz_p_br_2() {
    uint32_t insn = 0xA0002001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1h_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ldnt1h_mz_p_br_4() {
    uint32_t insn = 0xA000A001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1h_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ldnt1h_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1402008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1h_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1h_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140A008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1h_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1h_mzx_p_br_2x8() {
    uint32_t insn = 0xA1002008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1h_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1h_mzx_p_br_4x4() {
    uint32_t insn = 0xA100A008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1h_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1w_mz_p_bi_2() {
    uint32_t insn = 0xA0404001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1w_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_ldnt1w_mz_p_bi_4() {
    uint32_t insn = 0xA040C001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1w_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_ldnt1w_mz_p_br_2() {
    uint32_t insn = 0xA0004001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1w_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_ldnt1w_mz_p_br_4() {
    uint32_t insn = 0xA000C001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1w_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_ldnt1w_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1404008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1w_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1w_mzx_p_bi_4x4() {
    uint32_t insn = 0xA140C008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  ldnt1w_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_ldnt1w_mzx_p_br_2x8() {
    uint32_t insn = 0xA1004008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1w_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_ldnt1w_mzx_p_br_4x4() {
    uint32_t insn = 0xA100C008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  ldnt1w_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_ldr_za_ri_() {
    uint32_t insn = 0xE1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_za_ri_: " << result->to_string() << std::endl;
}

void test_ldr_zt_br_() {
    uint32_t insn = 0xE11F8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SMEZTRegister);
    assert(result->operands[1].type == OperandType::MemoryBase);
    std::cout << "  ldr_zt_br_: " << result->to_string() << std::endl;
}

void test_luti2_mz2_ztz_1() {
    uint32_t insn = 0xC08C4000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti2_mz2_ztz_1: " << result->to_string() << std::endl;
}

void test_luti2_mz2_ztz_8() {
    uint32_t insn = 0xC09C4000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti2_mz2_ztz_8: " << result->to_string() << std::endl;
}

void test_luti2_mz4_ztz_1() {
    uint32_t insn = 0xC08C8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti2_mz4_ztz_1: " << result->to_string() << std::endl;
}

void test_luti2_mz4_ztz_4() {
    uint32_t insn = 0xC09C8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti2_mz4_ztz_4: " << result->to_string() << std::endl;
}

void test_luti2_z_ztz_() {
    uint32_t insn = 0xC0CC0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI2);
    std::cout << "  luti2_z_ztz_: " << result->to_string() << std::endl;
}

void test_luti4_mz2_ztz_1() {
    uint32_t insn = 0xC08A4000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti4_mz2_ztz_1: " << result->to_string() << std::endl;
}

void test_luti4_mz2_ztz_8() {
    uint32_t insn = 0xC09A4000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti4_mz2_ztz_8: " << result->to_string() << std::endl;
}

void test_luti4_mz4_ztmz2_1() {
    uint32_t insn = 0xC08B0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  luti4_mz4_ztmz2_1: " << result->to_string() << std::endl;
}

void test_luti4_mz4_ztmz2_4() {
    uint32_t insn = 0xC09B0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  luti4_mz4_ztmz2_4: " << result->to_string() << std::endl;
}

void test_luti4_mz4_ztz_1() {
    uint32_t insn = 0xC08A8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti4_mz4_ztz_1: " << result->to_string() << std::endl;
}

void test_luti4_mz4_ztz_4() {
    uint32_t insn = 0xC09A8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti4_mz4_ztz_4: " << result->to_string() << std::endl;
}

void test_luti4_z_ztz_() {
    uint32_t insn = 0xC0CA0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI4);
    std::cout << "  luti4_z_ztz_: " << result->to_string() << std::endl;
}

void test_luti6_mz4_zmz2_1() {
    uint32_t insn = 0xC120F400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  luti6_mz4_zmz2_1: " << result->to_string() << std::endl;
}

void test_luti6_mz4_zmz2_4() {
    uint32_t insn = 0xC120FC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  luti6_mz4_zmz2_4: " << result->to_string() << std::endl;
}

void test_luti6_mz4_ztmz3_1() {
    uint32_t insn = 0xC08A0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  luti6_mz4_ztmz3_1: " << result->to_string() << std::endl;
}

void test_luti6_mz4_ztmz3_4() {
    uint32_t insn = 0xC09A0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  luti6_mz4_ztmz3_4: " << result->to_string() << std::endl;
}

void test_luti6_z_ztz_() {
    uint32_t insn = 0xC0C84000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::LUTI6);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SMEZTRegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  luti6_z_ztz_: " << result->to_string() << std::endl;
}

void test_mov_mz2_za_b1_mova_mz2_za_b1() {
    uint32_t insn = 0xC0060000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz2_za_b1_mova_mz2_za_b1: " << result->to_string() << std::endl;
}

void test_mov_mz2_za_h1_mova_mz2_za_h1() {
    uint32_t insn = 0xC0460000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz2_za_h1_mova_mz2_za_h1: " << result->to_string() << std::endl;
}

void test_mov_mz2_za_w1_mova_mz2_za_w1() {
    uint32_t insn = 0xC0860000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz2_za_w1_mova_mz2_za_w1: " << result->to_string() << std::endl;
}

void test_mov_mz2_za_d1_mova_mz2_za_d1() {
    uint32_t insn = 0xC0C60000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz2_za_d1_mova_mz2_za_d1: " << result->to_string() << std::endl;
}

void test_mov_mz4_za_b1_mova_mz4_za_b1() {
    uint32_t insn = 0xC0060400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz4_za_b1_mova_mz4_za_b1: " << result->to_string() << std::endl;
}

void test_mov_mz4_za_h1_mova_mz4_za_h1() {
    uint32_t insn = 0xC0460400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz4_za_h1_mova_mz4_za_h1: " << result->to_string() << std::endl;
}

void test_mov_mz4_za_w1_mova_mz4_za_w1() {
    uint32_t insn = 0xC0860400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz4_za_w1_mova_mz4_za_w1: " << result->to_string() << std::endl;
}

void test_mov_mz4_za_d1_mova_mz4_za_d1() {
    uint32_t insn = 0xC0C60400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_mz4_za_d1_mova_mz4_za_d1: " << result->to_string() << std::endl;
}

void test_mov_mz_za2_1_mova_mz_za2_1() {
    uint32_t insn = 0xC0060800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  mov_mz_za2_1_mova_mz_za2_1: " << result->to_string() << std::endl;
}

void test_mov_mz_za4_1_mova_mz_za4_1() {
    uint32_t insn = 0xC0060C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  mov_mz_za4_1_mova_mz_za4_1: " << result->to_string() << std::endl;
}

void test_mov_z_p_rza_b_mova_z_p_rza_b() {
    uint32_t insn = 0xC0020000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_z_p_rza_b_mova_z_p_rza_b: " << result->to_string() << std::endl;
}

void test_mov_z_p_rza_h_mova_z_p_rza_h() {
    uint32_t insn = 0xC0420000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_z_p_rza_h_mova_z_p_rza_h: " << result->to_string() << std::endl;
}

void test_mov_z_p_rza_w_mova_z_p_rza_w() {
    uint32_t insn = 0xC0820000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_z_p_rza_w_mova_z_p_rza_w: " << result->to_string() << std::endl;
}

void test_mov_z_p_rza_d_mova_z_p_rza_d() {
    uint32_t insn = 0xC0C20000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_z_p_rza_d_mova_z_p_rza_d: " << result->to_string() << std::endl;
}

void test_mov_z_p_rza_q_mova_z_p_rza_q() {
    uint32_t insn = 0xC0C30000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_z_p_rza_q_mova_z_p_rza_q: " << result->to_string() << std::endl;
}

void test_mov_za2_z_b1_mova_za2_z_b1() {
    uint32_t insn = 0xC0040000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za2_z_b1_mova_za2_z_b1: " << result->to_string() << std::endl;
}

void test_mov_za2_z_h1_mova_za2_z_h1() {
    uint32_t insn = 0xC0440000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za2_z_h1_mova_za2_z_h1: " << result->to_string() << std::endl;
}

void test_mov_za2_z_w1_mova_za2_z_w1() {
    uint32_t insn = 0xC0840000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za2_z_w1_mova_za2_z_w1: " << result->to_string() << std::endl;
}

void test_mov_za2_z_d1_mova_za2_z_d1() {
    uint32_t insn = 0xC0C40000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za2_z_d1_mova_za2_z_d1: " << result->to_string() << std::endl;
}

void test_mov_za4_z_b1_mova_za4_z_b1() {
    uint32_t insn = 0xC0040400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za4_z_b1_mova_za4_z_b1: " << result->to_string() << std::endl;
}

void test_mov_za4_z_h1_mova_za4_z_h1() {
    uint32_t insn = 0xC0440400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za4_z_h1_mova_za4_z_h1: " << result->to_string() << std::endl;
}

void test_mov_za4_z_w1_mova_za4_z_w1() {
    uint32_t insn = 0xC0840400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za4_z_w1_mova_za4_z_w1: " << result->to_string() << std::endl;
}

void test_mov_za4_z_d1_mova_za4_z_d1() {
    uint32_t insn = 0xC0C40400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za4_z_d1_mova_za4_z_d1: " << result->to_string() << std::endl;
}

void test_mov_za_mz2_1_mova_za_mz2_1() {
    uint32_t insn = 0xC0040800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  mov_za_mz2_1_mova_za_mz2_1: " << result->to_string() << std::endl;
}

void test_mov_za_mz4_1_mova_za_mz4_1() {
    uint32_t insn = 0xC0040C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  mov_za_mz4_1_mova_za_mz4_1: " << result->to_string() << std::endl;
}

void test_mov_za_p_rz_b_mova_za_p_rz_b() {
    uint32_t insn = 0xC0000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za_p_rz_b_mova_za_p_rz_b: " << result->to_string() << std::endl;
}

void test_mov_za_p_rz_h_mova_za_p_rz_h() {
    uint32_t insn = 0xC0400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za_p_rz_h_mova_za_p_rz_h: " << result->to_string() << std::endl;
}

void test_mov_za_p_rz_w_mova_za_p_rz_w() {
    uint32_t insn = 0xC0800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za_p_rz_w_mova_za_p_rz_w: " << result->to_string() << std::endl;
}

void test_mov_za_p_rz_d_mova_za_p_rz_d() {
    uint32_t insn = 0xC0C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za_p_rz_d_mova_za_p_rz_d: " << result->to_string() << std::endl;
}

void test_mov_za_p_rz_q_mova_za_p_rz_q() {
    uint32_t insn = 0xC0C10000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mov_za_p_rz_q_mova_za_p_rz_q: " << result->to_string() << std::endl;
}

void test_mova_mz2_za_b1() {
    uint32_t insn = 0xC0060000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz2_za_b1: " << result->to_string() << std::endl;
}

void test_mova_mz2_za_h1() {
    uint32_t insn = 0xC0460000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz2_za_h1: " << result->to_string() << std::endl;
}

void test_mova_mz2_za_w1() {
    uint32_t insn = 0xC0860000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz2_za_w1: " << result->to_string() << std::endl;
}

void test_mova_mz2_za_d1() {
    uint32_t insn = 0xC0C60000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz2_za_d1: " << result->to_string() << std::endl;
}

void test_mova_mz4_za_b1() {
    uint32_t insn = 0xC0060400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz4_za_b1: " << result->to_string() << std::endl;
}

void test_mova_mz4_za_h1() {
    uint32_t insn = 0xC0460400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz4_za_h1: " << result->to_string() << std::endl;
}

void test_mova_mz4_za_w1() {
    uint32_t insn = 0xC0860400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz4_za_w1: " << result->to_string() << std::endl;
}

void test_mova_mz4_za_d1() {
    uint32_t insn = 0xC0C60400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_mz4_za_d1: " << result->to_string() << std::endl;
}

void test_mova_mz_za2_1() {
    uint32_t insn = 0xC0060800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  mova_mz_za2_1: " << result->to_string() << std::endl;
}

void test_mova_mz_za4_1() {
    uint32_t insn = 0xC0060C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  mova_mz_za4_1: " << result->to_string() << std::endl;
}

void test_mova_z_p_rza_b() {
    uint32_t insn = 0xC0020000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_z_p_rza_b: " << result->to_string() << std::endl;
}

void test_mova_z_p_rza_h() {
    uint32_t insn = 0xC0420000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_z_p_rza_h: " << result->to_string() << std::endl;
}

void test_mova_z_p_rza_w() {
    uint32_t insn = 0xC0820000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_z_p_rza_w: " << result->to_string() << std::endl;
}

void test_mova_z_p_rza_d() {
    uint32_t insn = 0xC0C20000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_z_p_rza_d: " << result->to_string() << std::endl;
}

void test_mova_z_p_rza_q() {
    uint32_t insn = 0xC0C30000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_z_p_rza_q: " << result->to_string() << std::endl;
}

void test_mova_za2_z_b1() {
    uint32_t insn = 0xC0040000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za2_z_b1: " << result->to_string() << std::endl;
}

void test_mova_za2_z_h1() {
    uint32_t insn = 0xC0440000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za2_z_h1: " << result->to_string() << std::endl;
}

void test_mova_za2_z_w1() {
    uint32_t insn = 0xC0840000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za2_z_w1: " << result->to_string() << std::endl;
}

void test_mova_za2_z_d1() {
    uint32_t insn = 0xC0C40000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za2_z_d1: " << result->to_string() << std::endl;
}

void test_mova_za4_z_b1() {
    uint32_t insn = 0xC0040400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za4_z_b1: " << result->to_string() << std::endl;
}

void test_mova_za4_z_h1() {
    uint32_t insn = 0xC0440400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za4_z_h1: " << result->to_string() << std::endl;
}

void test_mova_za4_z_w1() {
    uint32_t insn = 0xC0840400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za4_z_w1: " << result->to_string() << std::endl;
}

void test_mova_za4_z_d1() {
    uint32_t insn = 0xC0C40400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za4_z_d1: " << result->to_string() << std::endl;
}

void test_mova_za_mz2_1() {
    uint32_t insn = 0xC0040800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  mova_za_mz2_1: " << result->to_string() << std::endl;
}

void test_mova_za_mz4_1() {
    uint32_t insn = 0xC0040C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  mova_za_mz4_1: " << result->to_string() << std::endl;
}

void test_mova_za_p_rz_b() {
    uint32_t insn = 0xC0000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za_p_rz_b: " << result->to_string() << std::endl;
}

void test_mova_za_p_rz_h() {
    uint32_t insn = 0xC0400000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za_p_rz_h: " << result->to_string() << std::endl;
}

void test_mova_za_p_rz_w() {
    uint32_t insn = 0xC0800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za_p_rz_w: " << result->to_string() << std::endl;
}

void test_mova_za_p_rz_d() {
    uint32_t insn = 0xC0C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za_p_rz_d: " << result->to_string() << std::endl;
}

void test_mova_za_p_rz_q() {
    uint32_t insn = 0xC0C10000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVA);
    std::cout << "  mova_za_p_rz_q: " << result->to_string() << std::endl;
}

void test_movaz_mz2_za_b1() {
    uint32_t insn = 0xC0060200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz2_za_b1: " << result->to_string() << std::endl;
}

void test_movaz_mz2_za_h1() {
    uint32_t insn = 0xC0460200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz2_za_h1: " << result->to_string() << std::endl;
}

void test_movaz_mz2_za_w1() {
    uint32_t insn = 0xC0860200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz2_za_w1: " << result->to_string() << std::endl;
}

void test_movaz_mz2_za_d1() {
    uint32_t insn = 0xC0C60200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz2_za_d1: " << result->to_string() << std::endl;
}

void test_movaz_mz4_za_b1() {
    uint32_t insn = 0xC0060600u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz4_za_b1: " << result->to_string() << std::endl;
}

void test_movaz_mz4_za_h1() {
    uint32_t insn = 0xC0460600u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz4_za_h1: " << result->to_string() << std::endl;
}

void test_movaz_mz4_za_w1() {
    uint32_t insn = 0xC0860600u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz4_za_w1: " << result->to_string() << std::endl;
}

void test_movaz_mz4_za_d1() {
    uint32_t insn = 0xC0C60600u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_mz4_za_d1: " << result->to_string() << std::endl;
}

void test_movaz_mz_za2_1() {
    uint32_t insn = 0xC0060A00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  movaz_mz_za2_1: " << result->to_string() << std::endl;
}

void test_movaz_mz_za4_1() {
    uint32_t insn = 0xC0060E00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  movaz_mz_za4_1: " << result->to_string() << std::endl;
}

void test_movaz_z_rza_b() {
    uint32_t insn = 0xC0020200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_z_rza_b: " << result->to_string() << std::endl;
}

void test_movaz_z_rza_h() {
    uint32_t insn = 0xC0420200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_z_rza_h: " << result->to_string() << std::endl;
}

void test_movaz_z_rza_w() {
    uint32_t insn = 0xC0820200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_z_rza_w: " << result->to_string() << std::endl;
}

void test_movaz_z_rza_d() {
    uint32_t insn = 0xC0C20200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_z_rza_d: " << result->to_string() << std::endl;
}

void test_movaz_z_rza_q() {
    uint32_t insn = 0xC0C30200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVAZ);
    std::cout << "  movaz_z_rza_q: " << result->to_string() << std::endl;
}

void test_movt_r_zt_() {
    uint32_t insn = 0xC04C03E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVT);
    std::cout << "  movt_r_zt_: " << result->to_string() << std::endl;
}

void test_movt_zt_r_() {
    uint32_t insn = 0xC04E03E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVT);
    std::cout << "  movt_zt_r_: " << result->to_string() << std::endl;
}

void test_movt_zt_z_() {
    uint32_t insn = 0xC04F03E0u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::MOVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  movt_zt_z_: " << result->to_string() << std::endl;
}

void test_sclamp_mz_zz_2() {
    uint32_t insn = 0xC120C400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SCLAMP);
    std::cout << "  sclamp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_sclamp_mz_zz_4() {
    uint32_t insn = 0xC120CC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SCLAMP);
    std::cout << "  sclamp_mz_zz_4: " << result->to_string() << std::endl;
}

void test_scvtf_mz_z_2() {
    uint32_t insn = 0xC122E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  scvtf_mz_z_2: " << result->to_string() << std::endl;
}

void test_scvtf_mz_z_4() {
    uint32_t insn = 0xC132E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SCVTF);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  scvtf_mz_z_4: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzi_2xi() {
    uint32_t insn = 0xC1501000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za32_zzi_2xi: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzi_4xi() {
    uint32_t insn = 0xC1509000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za32_zzi_4xi: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzv_2x1() {
    uint32_t insn = 0xC1601408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za32_zzv_2x1: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzv_4x1() {
    uint32_t insn = 0xC1701408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za32_zzv_4x1: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzw_2x2() {
    uint32_t insn = 0xC1E01408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  sdot_za32_zzw_2x2: " << result->to_string() << std::endl;
}

void test_sdot_za32_zzw_4x4() {
    uint32_t insn = 0xC1E11408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  sdot_za32_zzw_4x4: " << result->to_string() << std::endl;
}

void test_sdot_za_zzi_s2xi() {
    uint32_t insn = 0xC1501020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_sdot_za_zzi_d2xi() {
    uint32_t insn = 0xC1D00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_sdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1509020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_sdot_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sdot_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_sdot_za_zzv_2x1() {
    uint32_t insn = 0xC1201400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    std::cout << "  sdot_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_sdot_za_zzv_4x1() {
    uint32_t insn = 0xC1301400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    std::cout << "  sdot_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_sdot_za_zzw_2x2() {
    uint32_t insn = 0xC1A01400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  sdot_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_sdot_za_zzw_4x4() {
    uint32_t insn = 0xC1A11400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  sdot_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_sel_mz_p_zz_2() {
    uint32_t insn = 0xC1208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SEL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sel_mz_p_zz_2: " << result->to_string() << std::endl;
}

void test_sel_mz_p_zz_4() {
    uint32_t insn = 0xC1218000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SEL);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sel_mz_p_zz_4: " << result->to_string() << std::endl;
}

void test_smax_mz_zzv_2x1() {
    uint32_t insn = 0xC120A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    std::cout << "  smax_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smax_mz_zzv_4x1() {
    uint32_t insn = 0xC120A800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    std::cout << "  smax_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smax_mz_zzw_2x2() {
    uint32_t insn = 0xC120B000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  smax_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smax_mz_zzw_4x4() {
    uint32_t insn = 0xC120B800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  smax_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smin_mz_zzv_2x1() {
    uint32_t insn = 0xC120A020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    std::cout << "  smin_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smin_mz_zzv_4x1() {
    uint32_t insn = 0xC120A820u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    std::cout << "  smin_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smin_mz_zzw_2x2() {
    uint32_t insn = 0xC120B020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  smin_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smin_mz_zzw_4x4() {
    uint32_t insn = 0xC120B820u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  smin_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smlal_za_zzi_1() {
    uint32_t insn = 0xC1C01000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    std::cout << "  smlal_za_zzi_1: " << result->to_string() << std::endl;
}

void test_smlal_za_zzi_2xi() {
    uint32_t insn = 0xC1D01000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlal_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_smlal_za_zzi_4xi() {
    uint32_t insn = 0xC1D09000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlal_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_smlal_za_zzv_1() {
    uint32_t insn = 0xC1600C00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    std::cout << "  smlal_za_zzv_1: " << result->to_string() << std::endl;
}

void test_smlal_za_zzv_2x1() {
    uint32_t insn = 0xC1600800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlal_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smlal_za_zzv_4x1() {
    uint32_t insn = 0xC1700800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlal_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smlal_za_zzw_2x2() {
    uint32_t insn = 0xC1E00800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlal_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smlal_za_zzw_4x4() {
    uint32_t insn = 0xC1E10800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlal_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_s() {
    uint32_t insn = 0xC1000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    std::cout << "  smlall_za_zzi_s: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_d() {
    uint32_t insn = 0xC1800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    std::cout << "  smlall_za_zzi_d: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_s2xi() {
    uint32_t insn = 0xC1100000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlall_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_d2xi() {
    uint32_t insn = 0xC1900000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlall_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_s4xi() {
    uint32_t insn = 0xC1108000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlall_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_smlall_za_zzi_d4xi() {
    uint32_t insn = 0xC1908000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlall_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_smlall_za_zzv_1() {
    uint32_t insn = 0xC1200400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    std::cout << "  smlall_za_zzv_1: " << result->to_string() << std::endl;
}

void test_smlall_za_zzv_2x1() {
    uint32_t insn = 0xC1200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    std::cout << "  smlall_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smlall_za_zzv_4x1() {
    uint32_t insn = 0xC1300000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    std::cout << "  smlall_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smlall_za_zzw_2x2() {
    uint32_t insn = 0xC1A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlall_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smlall_za_zzw_4x4() {
    uint32_t insn = 0xC1A10000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlall_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzi_1() {
    uint32_t insn = 0xC1C01008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    std::cout << "  smlsl_za_zzi_1: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzi_2xi() {
    uint32_t insn = 0xC1D01008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsl_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzi_4xi() {
    uint32_t insn = 0xC1D09008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsl_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzv_1() {
    uint32_t insn = 0xC1600C08u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    std::cout << "  smlsl_za_zzv_1: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzv_2x1() {
    uint32_t insn = 0xC1600808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsl_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzv_4x1() {
    uint32_t insn = 0xC1700808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsl_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzw_2x2() {
    uint32_t insn = 0xC1E00808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlsl_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smlsl_za_zzw_4x4() {
    uint32_t insn = 0xC1E10808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlsl_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_s() {
    uint32_t insn = 0xC1000008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    std::cout << "  smlsll_za_zzi_s: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_d() {
    uint32_t insn = 0xC1800008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    std::cout << "  smlsll_za_zzi_d: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_s2xi() {
    uint32_t insn = 0xC1100008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsll_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_d2xi() {
    uint32_t insn = 0xC1900008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsll_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_s4xi() {
    uint32_t insn = 0xC1108008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsll_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzi_d4xi() {
    uint32_t insn = 0xC1908008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  smlsll_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzv_1() {
    uint32_t insn = 0xC1200408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    std::cout << "  smlsll_za_zzv_1: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzv_2x1() {
    uint32_t insn = 0xC1200008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    std::cout << "  smlsll_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzv_4x1() {
    uint32_t insn = 0xC1300008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    std::cout << "  smlsll_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzw_2x2() {
    uint32_t insn = 0xC1A00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlsll_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_smlsll_za_zzw_4x4() {
    uint32_t insn = 0xC1A10008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMLSLL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  smlsll_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_smop4a_za32_zz_h1x2() {
    uint32_t insn = 0x80108008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_smop4a_za32_zz_h1x1() {
    uint32_t insn = 0x80008008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_smop4a_za32_zz_h2x1() {
    uint32_t insn = 0x80008208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_smop4a_za32_zz_h2x2() {
    uint32_t insn = 0x80108208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_b1x2() {
    uint32_t insn = 0x80108000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_b1x1() {
    uint32_t insn = 0x80008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_b2x1() {
    uint32_t insn = 0x80008200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_b2x2() {
    uint32_t insn = 0x80108200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_h1x2() {
    uint32_t insn = 0xA0D00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_h1x1() {
    uint32_t insn = 0xA0C00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_h2x1() {
    uint32_t insn = 0xA0C00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_smop4a_za_zz_h2x2() {
    uint32_t insn = 0xA0D00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_smop4s_za32_zz_h1x2() {
    uint32_t insn = 0x80108018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_smop4s_za32_zz_h1x1() {
    uint32_t insn = 0x80008018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_smop4s_za32_zz_h2x1() {
    uint32_t insn = 0x80008218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_smop4s_za32_zz_h2x2() {
    uint32_t insn = 0x80108218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_b1x2() {
    uint32_t insn = 0x80108010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_b1x1() {
    uint32_t insn = 0x80008010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_b2x1() {
    uint32_t insn = 0x80008210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_b2x2() {
    uint32_t insn = 0x80108210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_h1x2() {
    uint32_t insn = 0xA0D00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_h1x1() {
    uint32_t insn = 0xA0C00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_h2x1() {
    uint32_t insn = 0xA0C00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  smop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_smop4s_za_zz_h2x2() {
    uint32_t insn = 0xA0D00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  smop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_smopa_za32_pp_zz_16() {
    uint32_t insn = 0xA0800008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smopa_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_smopa_za_pp_zz_32() {
    uint32_t insn = 0xA0800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_smopa_za_pp_zz_64() {
    uint32_t insn = 0xA0C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smopa_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_smops_za32_pp_zz_16() {
    uint32_t insn = 0xA0800018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smops_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_smops_za_pp_zz_32() {
    uint32_t insn = 0xA0800010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_smops_za_pp_zz_64() {
    uint32_t insn = 0xA0C00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  smops_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_sqcvt_z_mz2_() {
    uint32_t insn = 0xC123E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sqcvt_z_mz2_: " << result->to_string() << std::endl;
}

void test_sqcvt_z_mz4_() {
    uint32_t insn = 0xC133E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVT);
    std::cout << "  sqcvt_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqcvtn_z_mz4_() {
    uint32_t insn = 0xC133E040u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVTN);
    std::cout << "  sqcvtn_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqcvtu_z_mz2_() {
    uint32_t insn = 0xC163E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVTU);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sqcvtu_z_mz2_: " << result->to_string() << std::endl;
}

void test_sqcvtu_z_mz4_() {
    uint32_t insn = 0xC173E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVTU);
    std::cout << "  sqcvtu_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqcvtun_z_mz4_() {
    uint32_t insn = 0xC173E040u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQCVTUN);
    std::cout << "  sqcvtun_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqdmulh_mz_zzv_2x1() {
    uint32_t insn = 0xC120A400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQDMULH);
    std::cout << "  sqdmulh_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_sqdmulh_mz_zzv_4x1() {
    uint32_t insn = 0xC120AC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQDMULH);
    std::cout << "  sqdmulh_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_sqdmulh_mz_zzw_2x2() {
    uint32_t insn = 0xC120B400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  sqdmulh_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_sqdmulh_mz_zzw_4x4() {
    uint32_t insn = 0xC120BC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQDMULH);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  sqdmulh_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_sqrshr_z_mz2_() {
    uint32_t insn = 0xC1E0D400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHR);
    std::cout << "  sqrshr_z_mz2_: " << result->to_string() << std::endl;
}

void test_sqrshr_z_mz4_() {
    uint32_t insn = 0xC160D800u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHR);
    std::cout << "  sqrshr_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqrshrn_z_mz4_() {
    uint32_t insn = 0xC160DC00u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHRN);
    std::cout << "  sqrshrn_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqrshru_z_mz2_() {
    uint32_t insn = 0xC1F0D400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHRU);
    std::cout << "  sqrshru_z_mz2_: " << result->to_string() << std::endl;
}

void test_sqrshru_z_mz4_() {
    uint32_t insn = 0xC160D840u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHRU);
    std::cout << "  sqrshru_z_mz4_: " << result->to_string() << std::endl;
}

void test_sqrshrun_z_mz4_() {
    uint32_t insn = 0xC160DC40u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SQRSHRUN);
    std::cout << "  sqrshrun_z_mz4_: " << result->to_string() << std::endl;
}

void test_srshl_mz_zzv_2x1() {
    uint32_t insn = 0xC120A220u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SRSHL);
    std::cout << "  srshl_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_srshl_mz_zzv_4x1() {
    uint32_t insn = 0xC120AA20u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SRSHL);
    std::cout << "  srshl_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_srshl_mz_zzw_2x2() {
    uint32_t insn = 0xC120B220u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SRSHL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  srshl_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_srshl_mz_zzw_4x4() {
    uint32_t insn = 0xC120BA20u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SRSHL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  srshl_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_st1b_mz_p_bi_2() {
    uint32_t insn = 0xA0600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1b_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_st1b_mz_p_bi_4() {
    uint32_t insn = 0xA0608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1b_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_st1b_mz_p_br_2() {
    uint32_t insn = 0xA0200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1b_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_st1b_mz_p_br_4() {
    uint32_t insn = 0xA0208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1b_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_st1b_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1b_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_st1b_mzx_p_bi_4x4() {
    uint32_t insn = 0xA1608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1b_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_st1b_mzx_p_br_2x8() {
    uint32_t insn = 0xA1200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1b_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_st1b_mzx_p_br_4x4() {
    uint32_t insn = 0xA1208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1b_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_st1b_za_p_rrr_() {
    uint32_t insn = 0xE0200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1b_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_st1d_mz_p_bi_2() {
    uint32_t insn = 0xA0606000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1d_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_st1d_mz_p_bi_4() {
    uint32_t insn = 0xA060E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1d_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_st1d_mz_p_br_2() {
    uint32_t insn = 0xA0206000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1d_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_st1d_mz_p_br_4() {
    uint32_t insn = 0xA020E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1d_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_st1d_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1606000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1d_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_st1d_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1d_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_st1d_mzx_p_br_2x8() {
    uint32_t insn = 0xA1206000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1d_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_st1d_mzx_p_br_4x4() {
    uint32_t insn = 0xA120E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1d_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_st1d_za_p_rrr_() {
    uint32_t insn = 0xE0E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1d_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_st1h_mz_p_bi_2() {
    uint32_t insn = 0xA0602000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1h_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_st1h_mz_p_bi_4() {
    uint32_t insn = 0xA060A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1h_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_st1h_mz_p_br_2() {
    uint32_t insn = 0xA0202000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1h_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_st1h_mz_p_br_4() {
    uint32_t insn = 0xA020A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1h_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_st1h_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1602000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1h_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_st1h_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1h_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_st1h_mzx_p_br_2x8() {
    uint32_t insn = 0xA1202000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1h_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_st1h_mzx_p_br_4x4() {
    uint32_t insn = 0xA120A000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1h_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_st1h_za_p_rrr_() {
    uint32_t insn = 0xE0600000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1h_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_st1q_za_p_rrr_() {
    uint32_t insn = 0xE1E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1Q);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1q_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_st1w_mz_p_bi_2() {
    uint32_t insn = 0xA0604000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1w_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_st1w_mz_p_bi_4() {
    uint32_t insn = 0xA060C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1w_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_st1w_mz_p_br_2() {
    uint32_t insn = 0xA0204000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1w_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_st1w_mz_p_br_4() {
    uint32_t insn = 0xA020C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1w_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_st1w_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1604000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1w_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_st1w_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  st1w_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_st1w_mzx_p_br_2x8() {
    uint32_t insn = 0xA1204000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1w_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_st1w_mzx_p_br_4x4() {
    uint32_t insn = 0xA120C000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1w_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_st1w_za_p_rrr_() {
    uint32_t insn = 0xE0A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ST1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  st1w_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_stmopa_za32_zzzi_h2x1() {
    uint32_t insn = 0x80408008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  stmopa_za32_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_stmopa_za_zzzi_b2x1() {
    uint32_t insn = 0x80408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  stmopa_za_zzzi_b2x1: " << result->to_string() << std::endl;
}

void test_stnt1b_mz_p_bi_2() {
    uint32_t insn = 0xA0600001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1b_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_stnt1b_mz_p_bi_4() {
    uint32_t insn = 0xA0608001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1b_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_stnt1b_mz_p_br_2() {
    uint32_t insn = 0xA0200001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1b_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_stnt1b_mz_p_br_4() {
    uint32_t insn = 0xA0208001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1b_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_stnt1b_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1600008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1b_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_stnt1b_mzx_p_bi_4x4() {
    uint32_t insn = 0xA1608008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1b_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_stnt1b_mzx_p_br_2x8() {
    uint32_t insn = 0xA1200008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1b_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_stnt1b_mzx_p_br_4x4() {
    uint32_t insn = 0xA1208008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1B);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1b_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_stnt1d_mz_p_bi_2() {
    uint32_t insn = 0xA0606001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1d_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_stnt1d_mz_p_bi_4() {
    uint32_t insn = 0xA060E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1d_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_stnt1d_mz_p_br_2() {
    uint32_t insn = 0xA0206001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1d_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_stnt1d_mz_p_br_4() {
    uint32_t insn = 0xA020E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1d_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_stnt1d_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1606008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1d_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_stnt1d_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160E008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1d_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_stnt1d_mzx_p_br_2x8() {
    uint32_t insn = 0xA1206008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1d_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_stnt1d_mzx_p_br_4x4() {
    uint32_t insn = 0xA120E008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1D);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1d_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_stnt1h_mz_p_bi_2() {
    uint32_t insn = 0xA0602001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1h_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_stnt1h_mz_p_bi_4() {
    uint32_t insn = 0xA060A001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1h_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_stnt1h_mz_p_br_2() {
    uint32_t insn = 0xA0202001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1h_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_stnt1h_mz_p_br_4() {
    uint32_t insn = 0xA020A001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1h_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_stnt1h_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1602008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1h_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_stnt1h_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160A008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1h_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_stnt1h_mzx_p_br_2x8() {
    uint32_t insn = 0xA1202008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1h_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_stnt1h_mzx_p_br_4x4() {
    uint32_t insn = 0xA120A008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1H);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1h_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_stnt1w_mz_p_bi_2() {
    uint32_t insn = 0xA0604001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1w_mz_p_bi_2: " << result->to_string() << std::endl;
}

void test_stnt1w_mz_p_bi_4() {
    uint32_t insn = 0xA060C001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1w_mz_p_bi_4: " << result->to_string() << std::endl;
}

void test_stnt1w_mz_p_br_2() {
    uint32_t insn = 0xA0204001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1w_mz_p_br_2: " << result->to_string() << std::endl;
}

void test_stnt1w_mz_p_br_4() {
    uint32_t insn = 0xA020C001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1w_mz_p_br_4: " << result->to_string() << std::endl;
}

void test_stnt1w_mzx_p_bi_2x8() {
    uint32_t insn = 0xA1604008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1w_mzx_p_bi_2x8: " << result->to_string() << std::endl;
}

void test_stnt1w_mzx_p_bi_4x4() {
    uint32_t insn = 0xA160C008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryOffsetMulVL);
    std::cout << "  stnt1w_mzx_p_bi_4x4: " << result->to_string() << std::endl;
}

void test_stnt1w_mzx_p_br_2x8() {
    uint32_t insn = 0xA1204008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1w_mzx_p_br_2x8: " << result->to_string() << std::endl;
}

void test_stnt1w_mzx_p_br_4x4() {
    uint32_t insn = 0xA120C008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STNT1W);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::PredicateNRegister);
    assert(result->operands[2].type == OperandType::MemoryRegOffset);
    std::cout << "  stnt1w_mzx_p_br_4x4: " << result->to_string() << std::endl;
}

void test_str_za_ri_() {
    uint32_t insn = 0xE1200000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_za_ri_: " << result->to_string() << std::endl;
}

void test_str_zt_br_() {
    uint32_t insn = 0xE13F8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SMEZTRegister);
    assert(result->operands[1].type == OperandType::MemoryBase);
    std::cout << "  str_zt_br_: " << result->to_string() << std::endl;
}

void test_sub_za_zw_2x2() {
    uint32_t insn = 0xC1A01C18u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zw_2x2: " << result->to_string() << std::endl;
}

void test_sub_za_zw_4x4() {
    uint32_t insn = 0xC1A11C18u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zw_4x4: " << result->to_string() << std::endl;
}

void test_sub_za_zzv_2x1() {
    uint32_t insn = 0xC1201818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_sub_za_zzv_4x1() {
    uint32_t insn = 0xC1301818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_sub_za_zzw_2x2() {
    uint32_t insn = 0xC1A01818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_sub_za_zzw_4x4() {
    uint32_t insn = 0xC1A11818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    std::cout << "  sub_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_sudot_za_zzi_s2xi() {
    uint32_t insn = 0xC1501038u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sudot_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_sudot_za_zzi_s4xi() {
    uint32_t insn = 0xC1509038u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sudot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_sudot_za_zzv_s2x1() {
    uint32_t insn = 0xC1201418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sudot_za_zzv_s2x1: " << result->to_string() << std::endl;
}

void test_sudot_za_zzv_s4x1() {
    uint32_t insn = 0xC1301418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sudot_za_zzv_s4x1: " << result->to_string() << std::endl;
}

void test_sumlall_za_zzi_s() {
    uint32_t insn = 0xC1000014u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMLALL);
    std::cout << "  sumlall_za_zzi_s: " << result->to_string() << std::endl;
}

void test_sumlall_za_zzi_s2xi() {
    uint32_t insn = 0xC1100030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sumlall_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_sumlall_za_zzi_s4xi() {
    uint32_t insn = 0xC1108030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sumlall_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_sumlall_za_zzv_s2x1() {
    uint32_t insn = 0xC1200014u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sumlall_za_zzv_s2x1: " << result->to_string() << std::endl;
}

void test_sumlall_za_zzv_s4x1() {
    uint32_t insn = 0xC1300014u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  sumlall_za_zzv_s4x1: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_b1x2() {
    uint32_t insn = 0x80308000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sumop4a_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_b1x1() {
    uint32_t insn = 0x80208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4a_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_b2x1() {
    uint32_t insn = 0x80208200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4a_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_b2x2() {
    uint32_t insn = 0x80308200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sumop4a_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_h1x2() {
    uint32_t insn = 0xA0F00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sumop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_h1x1() {
    uint32_t insn = 0xA0E00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_h2x1() {
    uint32_t insn = 0xA0E00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_sumop4a_za_zz_h2x2() {
    uint32_t insn = 0xA0F00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sumop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_b1x2() {
    uint32_t insn = 0x80308010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sumop4s_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_b1x1() {
    uint32_t insn = 0x80208010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4s_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_b2x1() {
    uint32_t insn = 0x80208210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4s_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_b2x2() {
    uint32_t insn = 0x80308210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sumop4s_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_h1x2() {
    uint32_t insn = 0xA0F00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  sumop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_h1x1() {
    uint32_t insn = 0xA0E00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_h2x1() {
    uint32_t insn = 0xA0E00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  sumop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_sumop4s_za_zz_h2x2() {
    uint32_t insn = 0xA0F00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  sumop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_sumopa_za_pp_zz_32() {
    uint32_t insn = 0xA0A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  sumopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_sumopa_za_pp_zz_64() {
    uint32_t insn = 0xA0E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  sumopa_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_sumops_za_pp_zz_32() {
    uint32_t insn = 0xA0A00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  sumops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_sumops_za_pp_zz_64() {
    uint32_t insn = 0xA0E00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  sumops_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_sunpk_mz_z_2() {
    uint32_t insn = 0xC165E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUNPK);
    std::cout << "  sunpk_mz_z_2: " << result->to_string() << std::endl;
}

void test_sunpk_mz_z_4() {
    uint32_t insn = 0xC175E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUNPK);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  sunpk_mz_z_4: " << result->to_string() << std::endl;
}

void test_sutmopa_za_zzzi_b2x1() {
    uint32_t insn = 0x80608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  sutmopa_za_zzzi_b2x1: " << result->to_string() << std::endl;
}

void test_suvdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1508038u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SUVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  suvdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_svdot_za32_zzi_2xi() {
    uint32_t insn = 0xC1500020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  svdot_za32_zzi_2xi: " << result->to_string() << std::endl;
}

void test_svdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1508020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  svdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_svdot_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08808u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::SVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  svdot_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_uclamp_mz_zz_2() {
    uint32_t insn = 0xC120C401u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UCLAMP);
    std::cout << "  uclamp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_uclamp_mz_zz_4() {
    uint32_t insn = 0xC120CC01u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UCLAMP);
    std::cout << "  uclamp_mz_zz_4: " << result->to_string() << std::endl;
}

void test_ucvtf_mz_z_2() {
    uint32_t insn = 0xC122E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  ucvtf_mz_z_2: " << result->to_string() << std::endl;
}

void test_ucvtf_mz_z_4() {
    uint32_t insn = 0xC132E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UCVTF);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  ucvtf_mz_z_4: " << result->to_string() << std::endl;
}

void test_udot_za32_zzi_2xi() {
    uint32_t insn = 0xC1501010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za32_zzi_2xi: " << result->to_string() << std::endl;
}

void test_udot_za32_zzi_4xi() {
    uint32_t insn = 0xC1509010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za32_zzi_4xi: " << result->to_string() << std::endl;
}

void test_udot_za32_zzv_2x1() {
    uint32_t insn = 0xC1601418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za32_zzv_2x1: " << result->to_string() << std::endl;
}

void test_udot_za32_zzv_4x1() {
    uint32_t insn = 0xC1701418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za32_zzv_4x1: " << result->to_string() << std::endl;
}

void test_udot_za32_zzw_2x2() {
    uint32_t insn = 0xC1E01418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  udot_za32_zzw_2x2: " << result->to_string() << std::endl;
}

void test_udot_za32_zzw_4x4() {
    uint32_t insn = 0xC1E11418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  udot_za32_zzw_4x4: " << result->to_string() << std::endl;
}

void test_udot_za_zzi_s2xi() {
    uint32_t insn = 0xC1501030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_udot_za_zzi_d2xi() {
    uint32_t insn = 0xC1D00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_udot_za_zzi_s4xi() {
    uint32_t insn = 0xC1509030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_udot_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  udot_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_udot_za_zzv_2x1() {
    uint32_t insn = 0xC1201410u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    std::cout << "  udot_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_udot_za_zzv_4x1() {
    uint32_t insn = 0xC1301410u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    std::cout << "  udot_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_udot_za_zzw_2x2() {
    uint32_t insn = 0xC1A01410u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  udot_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_udot_za_zzw_4x4() {
    uint32_t insn = 0xC1A11410u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  udot_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umax_mz_zzv_2x1() {
    uint32_t insn = 0xC120A001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    std::cout << "  umax_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umax_mz_zzv_4x1() {
    uint32_t insn = 0xC120A801u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    std::cout << "  umax_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umax_mz_zzw_2x2() {
    uint32_t insn = 0xC120B001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  umax_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umax_mz_zzw_4x4() {
    uint32_t insn = 0xC120B801u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMAX);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  umax_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umin_mz_zzv_2x1() {
    uint32_t insn = 0xC120A021u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    std::cout << "  umin_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umin_mz_zzv_4x1() {
    uint32_t insn = 0xC120A821u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    std::cout << "  umin_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umin_mz_zzw_2x2() {
    uint32_t insn = 0xC120B021u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  umin_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umin_mz_zzw_4x4() {
    uint32_t insn = 0xC120B821u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMIN);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  umin_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umlal_za_zzi_1() {
    uint32_t insn = 0xC1C01010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    std::cout << "  umlal_za_zzi_1: " << result->to_string() << std::endl;
}

void test_umlal_za_zzi_2xi() {
    uint32_t insn = 0xC1D01010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlal_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_umlal_za_zzi_4xi() {
    uint32_t insn = 0xC1D09010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlal_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_umlal_za_zzv_1() {
    uint32_t insn = 0xC1600C10u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    std::cout << "  umlal_za_zzv_1: " << result->to_string() << std::endl;
}

void test_umlal_za_zzv_2x1() {
    uint32_t insn = 0xC1600810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlal_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umlal_za_zzv_4x1() {
    uint32_t insn = 0xC1700810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlal_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umlal_za_zzw_2x2() {
    uint32_t insn = 0xC1E00810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlal_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umlal_za_zzw_4x4() {
    uint32_t insn = 0xC1E10810u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLAL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlal_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_s() {
    uint32_t insn = 0xC1000010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    std::cout << "  umlall_za_zzi_s: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_d() {
    uint32_t insn = 0xC1800010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    std::cout << "  umlall_za_zzi_d: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_s2xi() {
    uint32_t insn = 0xC1100010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlall_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_d2xi() {
    uint32_t insn = 0xC1900010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlall_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_s4xi() {
    uint32_t insn = 0xC1108010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlall_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_umlall_za_zzi_d4xi() {
    uint32_t insn = 0xC1908010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlall_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_umlall_za_zzv_1() {
    uint32_t insn = 0xC1200410u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    std::cout << "  umlall_za_zzv_1: " << result->to_string() << std::endl;
}

void test_umlall_za_zzv_2x1() {
    uint32_t insn = 0xC1200010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    std::cout << "  umlall_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umlall_za_zzv_4x1() {
    uint32_t insn = 0xC1300010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    std::cout << "  umlall_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umlall_za_zzw_2x2() {
    uint32_t insn = 0xC1A00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlall_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umlall_za_zzw_4x4() {
    uint32_t insn = 0xC1A10010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlall_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzi_1() {
    uint32_t insn = 0xC1C01018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    std::cout << "  umlsl_za_zzi_1: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzi_2xi() {
    uint32_t insn = 0xC1D01018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsl_za_zzi_2xi: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzi_4xi() {
    uint32_t insn = 0xC1D09018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsl_za_zzi_4xi: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzv_1() {
    uint32_t insn = 0xC1600C18u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    std::cout << "  umlsl_za_zzv_1: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzv_2x1() {
    uint32_t insn = 0xC1600818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsl_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzv_4x1() {
    uint32_t insn = 0xC1700818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsl_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzw_2x2() {
    uint32_t insn = 0xC1E00818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlsl_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umlsl_za_zzw_4x4() {
    uint32_t insn = 0xC1E10818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlsl_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_s() {
    uint32_t insn = 0xC1000018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    std::cout << "  umlsll_za_zzi_s: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_d() {
    uint32_t insn = 0xC1800018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    std::cout << "  umlsll_za_zzi_d: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_s2xi() {
    uint32_t insn = 0xC1100018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsll_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_d2xi() {
    uint32_t insn = 0xC1900018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsll_za_zzi_d2xi: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_s4xi() {
    uint32_t insn = 0xC1108018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsll_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzi_d4xi() {
    uint32_t insn = 0xC1908018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  umlsll_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzv_1() {
    uint32_t insn = 0xC1200418u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    std::cout << "  umlsll_za_zzv_1: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzv_2x1() {
    uint32_t insn = 0xC1200018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    std::cout << "  umlsll_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzv_4x1() {
    uint32_t insn = 0xC1300018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    std::cout << "  umlsll_za_zzv_4x1: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzw_2x2() {
    uint32_t insn = 0xC1A00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlsll_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_umlsll_za_zzw_4x4() {
    uint32_t insn = 0xC1A10018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMLSLL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  umlsll_za_zzw_4x4: " << result->to_string() << std::endl;
}

void test_umop4a_za32_zz_h1x2() {
    uint32_t insn = 0x81108008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_umop4a_za32_zz_h1x1() {
    uint32_t insn = 0x81008008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_umop4a_za32_zz_h2x1() {
    uint32_t insn = 0x81008208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_umop4a_za32_zz_h2x2() {
    uint32_t insn = 0x81108208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_b1x2() {
    uint32_t insn = 0x81308000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_b1x1() {
    uint32_t insn = 0x81208000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_b2x1() {
    uint32_t insn = 0x81208200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_b2x2() {
    uint32_t insn = 0x81308200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_h1x2() {
    uint32_t insn = 0xA1F00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_h1x1() {
    uint32_t insn = 0xA1E00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_h2x1() {
    uint32_t insn = 0xA1E00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_umop4a_za_zz_h2x2() {
    uint32_t insn = 0xA1F00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_umop4s_za32_zz_h1x2() {
    uint32_t insn = 0x81108018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za32_zz_h1x2: " << result->to_string() << std::endl;
}

void test_umop4s_za32_zz_h1x1() {
    uint32_t insn = 0x81008018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za32_zz_h1x1: " << result->to_string() << std::endl;
}

void test_umop4s_za32_zz_h2x1() {
    uint32_t insn = 0x81008218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za32_zz_h2x1: " << result->to_string() << std::endl;
}

void test_umop4s_za32_zz_h2x2() {
    uint32_t insn = 0x81108218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za32_zz_h2x2: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_b1x2() {
    uint32_t insn = 0x81308010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_b1x1() {
    uint32_t insn = 0x81208010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_b2x1() {
    uint32_t insn = 0x81208210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_b2x2() {
    uint32_t insn = 0x81308210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_h1x2() {
    uint32_t insn = 0xA1F00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_h1x1() {
    uint32_t insn = 0xA1E00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_h2x1() {
    uint32_t insn = 0xA1E00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  umop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_umop4s_za_zz_h2x2() {
    uint32_t insn = 0xA1F00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  umop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_umopa_za32_pp_zz_16() {
    uint32_t insn = 0xA1800008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umopa_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_umopa_za_pp_zz_32() {
    uint32_t insn = 0xA1A00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_umopa_za_pp_zz_64() {
    uint32_t insn = 0xA1E00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umopa_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_umops_za32_pp_zz_16() {
    uint32_t insn = 0xA1800018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umops_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_umops_za_pp_zz_32() {
    uint32_t insn = 0xA1A00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_umops_za_pp_zz_64() {
    uint32_t insn = 0xA1E00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  umops_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_uqcvt_z_mz2_() {
    uint32_t insn = 0xC123E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQCVT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  uqcvt_z_mz2_: " << result->to_string() << std::endl;
}

void test_uqcvt_z_mz4_() {
    uint32_t insn = 0xC133E020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQCVT);
    std::cout << "  uqcvt_z_mz4_: " << result->to_string() << std::endl;
}

void test_uqcvtn_z_mz4_() {
    uint32_t insn = 0xC133E060u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQCVTN);
    std::cout << "  uqcvtn_z_mz4_: " << result->to_string() << std::endl;
}

void test_uqrshr_z_mz2_() {
    uint32_t insn = 0xC1E0D420u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQRSHR);
    std::cout << "  uqrshr_z_mz2_: " << result->to_string() << std::endl;
}

void test_uqrshr_z_mz4_() {
    uint32_t insn = 0xC160D820u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQRSHR);
    std::cout << "  uqrshr_z_mz4_: " << result->to_string() << std::endl;
}

void test_uqrshrn_z_mz4_() {
    uint32_t insn = 0xC160DC20u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UQRSHRN);
    std::cout << "  uqrshrn_z_mz4_: " << result->to_string() << std::endl;
}

void test_urshl_mz_zzv_2x1() {
    uint32_t insn = 0xC120A221u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::URSHL);
    std::cout << "  urshl_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_urshl_mz_zzv_4x1() {
    uint32_t insn = 0xC120AA21u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::URSHL);
    std::cout << "  urshl_mz_zzv_4x1: " << result->to_string() << std::endl;
}

void test_urshl_mz_zzw_2x2() {
    uint32_t insn = 0xC120B221u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::URSHL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  urshl_mz_zzw_2x2: " << result->to_string() << std::endl;
}

void test_urshl_mz_zzw_4x4() {
    uint32_t insn = 0xC120BA21u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::URSHL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  urshl_mz_zzw_4x4: " << result->to_string() << std::endl;
}

void test_usdot_za_zzi_s2xi() {
    uint32_t insn = 0xC1501028u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usdot_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_usdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1509028u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_usdot_za_zzv_s2x1() {
    uint32_t insn = 0xC1201408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usdot_za_zzv_s2x1: " << result->to_string() << std::endl;
}

void test_usdot_za_zzv_s4x1() {
    uint32_t insn = 0xC1301408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usdot_za_zzv_s4x1: " << result->to_string() << std::endl;
}

void test_usdot_za_zzw_s2x2() {
    uint32_t insn = 0xC1A01408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  usdot_za_zzw_s2x2: " << result->to_string() << std::endl;
}

void test_usdot_za_zzw_s4x4() {
    uint32_t insn = 0xC1A11408u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USDOT);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  usdot_za_zzw_s4x4: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzi_s() {
    uint32_t insn = 0xC1000004u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    std::cout << "  usmlall_za_zzi_s: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzi_s2xi() {
    uint32_t insn = 0xC1100020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usmlall_za_zzi_s2xi: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzi_s4xi() {
    uint32_t insn = 0xC1108020u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usmlall_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzv_s() {
    uint32_t insn = 0xC1200404u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    std::cout << "  usmlall_za_zzv_s: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzv_s2x1() {
    uint32_t insn = 0xC1200004u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usmlall_za_zzv_s2x1: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzv_s4x1() {
    uint32_t insn = 0xC1300004u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usmlall_za_zzv_s4x1: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzw_s2x2() {
    uint32_t insn = 0xC1A00004u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  usmlall_za_zzw_s2x2: " << result->to_string() << std::endl;
}

void test_usmlall_za_zzw_s4x4() {
    uint32_t insn = 0xC1A10004u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMLALL);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  usmlall_za_zzw_s4x4: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_b1x2() {
    uint32_t insn = 0x81108000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  usmop4a_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_b1x1() {
    uint32_t insn = 0x81008000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4a_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_b2x1() {
    uint32_t insn = 0x81008200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4a_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_b2x2() {
    uint32_t insn = 0x81108200u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  usmop4a_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_h1x2() {
    uint32_t insn = 0xA1D00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  usmop4a_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_h1x1() {
    uint32_t insn = 0xA1C00008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4a_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_h2x1() {
    uint32_t insn = 0xA1C00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4a_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_usmop4a_za_zz_h2x2() {
    uint32_t insn = 0xA1D00208u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4A);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  usmop4a_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_b1x2() {
    uint32_t insn = 0x81108010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  usmop4s_za_zz_b1x2: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_b1x1() {
    uint32_t insn = 0x81008010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4s_za_zz_b1x1: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_b2x1() {
    uint32_t insn = 0x81008210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4s_za_zz_b2x1: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_b2x2() {
    uint32_t insn = 0x81108210u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  usmop4s_za_zz_b2x2: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_h1x2() {
    uint32_t insn = 0xA1D00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegisterList);
    std::cout << "  usmop4s_za_zz_h1x2: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_h1x1() {
    uint32_t insn = 0xA1C00018u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4s_za_zz_h1x1: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_h2x1() {
    uint32_t insn = 0xA1C00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  usmop4s_za_zz_h2x1: " << result->to_string() << std::endl;
}

void test_usmop4s_za_zz_h2x2() {
    uint32_t insn = 0xA1D00218u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOP4S);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    std::cout << "  usmop4s_za_zz_h2x2: " << result->to_string() << std::endl;
}

void test_usmopa_za_pp_zz_32() {
    uint32_t insn = 0xA1800000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  usmopa_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_usmopa_za_pp_zz_64() {
    uint32_t insn = 0xA1C00000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOPA);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  usmopa_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_usmops_za_pp_zz_32() {
    uint32_t insn = 0xA1800010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  usmops_za_pp_zz_32: " << result->to_string() << std::endl;
}

void test_usmops_za_pp_zz_64() {
    uint32_t insn = 0xA1C00010u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USMOPS);
    assert(result->operands.size() >= 5);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::PredicateRegister);
    assert(result->operands[2].type == OperandType::PredicateRegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    assert(result->operands[4].type == OperandType::SVERegister);
    std::cout << "  usmops_za_pp_zz_64: " << result->to_string() << std::endl;
}

void test_ustmopa_za_zzzi_b2x1() {
    uint32_t insn = 0x81408000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  ustmopa_za_zzzi_b2x1: " << result->to_string() << std::endl;
}

void test_usvdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1508028u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::USVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  usvdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_utmopa_za32_zzzi_h2x1() {
    uint32_t insn = 0x81408008u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  utmopa_za32_zzzi_h2x1: " << result->to_string() << std::endl;
}

void test_utmopa_za_zzzi_b2x1() {
    uint32_t insn = 0x81608000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UTMOPA);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::SVERegister);
    assert(result->operands[1].type == OperandType::SVERegisterList);
    assert(result->operands[2].type == OperandType::SVERegister);
    assert(result->operands[3].type == OperandType::SVERegister);
    std::cout << "  utmopa_za_zzzi_b2x1: " << result->to_string() << std::endl;
}

void test_uunpk_mz_z_2() {
    uint32_t insn = 0xC165E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UUNPK);
    std::cout << "  uunpk_mz_z_2: " << result->to_string() << std::endl;
}

void test_uunpk_mz_z_4() {
    uint32_t insn = 0xC175E001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UUNPK);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  uunpk_mz_z_4: " << result->to_string() << std::endl;
}

void test_uvdot_za32_zzi_2xi() {
    uint32_t insn = 0xC1500030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  uvdot_za32_zzi_2xi: " << result->to_string() << std::endl;
}

void test_uvdot_za_zzi_s4xi() {
    uint32_t insn = 0xC1508030u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  uvdot_za_zzi_s4xi: " << result->to_string() << std::endl;
}

void test_uvdot_za_zzi_d4xi() {
    uint32_t insn = 0xC1D08818u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UVDOT);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    std::cout << "  uvdot_za_zzi_d4xi: " << result->to_string() << std::endl;
}

void test_uzp_mz_z_4() {
    uint32_t insn = 0xC136E002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UZP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  uzp_mz_z_4: " << result->to_string() << std::endl;
}

void test_uzp_mz_z_4q() {
    uint32_t insn = 0xC137E002u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UZP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  uzp_mz_z_4q: " << result->to_string() << std::endl;
}

void test_uzp_mz_zz_2() {
    uint32_t insn = 0xC120D001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UZP);
    std::cout << "  uzp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_uzp_mz_zz_2q() {
    uint32_t insn = 0xC120D401u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UZP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  uzp_mz_zz_2q: " << result->to_string() << std::endl;
}

void test_zero_za1_ri_2() {
    uint32_t insn = 0xC00C0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za1_ri_2: " << result->to_string() << std::endl;
}

void test_zero_za1_ri_4() {
    uint32_t insn = 0xC00E0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za1_ri_4: " << result->to_string() << std::endl;
}

void test_zero_za2_ri_1() {
    uint32_t insn = 0xC00C8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za2_ri_1: " << result->to_string() << std::endl;
}

void test_zero_za2_ri_2() {
    uint32_t insn = 0xC00D0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za2_ri_2: " << result->to_string() << std::endl;
}

void test_zero_za2_ri_4() {
    uint32_t insn = 0xC00D8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za2_ri_4: " << result->to_string() << std::endl;
}

void test_zero_za4_ri_1() {
    uint32_t insn = 0xC00E8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za4_ri_1: " << result->to_string() << std::endl;
}

void test_zero_za4_ri_2() {
    uint32_t insn = 0xC00F0000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za4_ri_2: " << result->to_string() << std::endl;
}

void test_zero_za4_ri_4() {
    uint32_t insn = 0xC00F8000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    std::cout << "  zero_za4_ri_4: " << result->to_string() << std::endl;
}

void test_zero_za_i_() {
    uint32_t insn = 0xC0080000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::VectorRegisterList);
    std::cout << "  zero_za_i_: " << result->to_string() << std::endl;
}

void test_zero_zt_i_() {
    uint32_t insn = 0xC0480001u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZERO);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SMEZTRegister);
    std::cout << "  zero_zt_i_: " << result->to_string() << std::endl;
}

void test_zip_mz_z_4() {
    uint32_t insn = 0xC136E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZIP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  zip_mz_z_4: " << result->to_string() << std::endl;
}

void test_zip_mz_z_4q() {
    uint32_t insn = 0xC137E000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZIP);
    assert(result->operands.size() >= 1);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    std::cout << "  zip_mz_z_4q: " << result->to_string() << std::endl;
}

void test_zip_mz_zz_2() {
    uint32_t insn = 0xC120D000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZIP);
    std::cout << "  zip_mz_zz_2: " << result->to_string() << std::endl;
}

void test_zip_mz_zz_2q() {
    uint32_t insn = 0xC120D400u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::ZIP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::SVERegisterList);
    assert(result->operands[1].type == OperandType::SVERegister);
    assert(result->operands[2].type == OperandType::SVERegister);
    std::cout << "  zip_mz_zz_2q: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running sme encoding tests (868 encodings)..." << std::endl;
    int failed = 0;

    try { test_add_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: add_mz_zzv_2x1" << std::endl; failed++; }
    try { test_add_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: add_mz_zzv_4x1" << std::endl; failed++; }
    try { test_add_za_zw_2x2(); } catch (...) { std::cerr << "FAIL: add_za_zw_2x2" << std::endl; failed++; }
    try { test_add_za_zw_4x4(); } catch (...) { std::cerr << "FAIL: add_za_zw_4x4" << std::endl; failed++; }
    try { test_add_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: add_za_zzv_2x1" << std::endl; failed++; }
    try { test_add_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: add_za_zzv_4x1" << std::endl; failed++; }
    try { test_add_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: add_za_zzw_2x2" << std::endl; failed++; }
    try { test_add_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: add_za_zzw_4x4" << std::endl; failed++; }
    try { test_addha_za_pp_z_32(); } catch (...) { std::cerr << "FAIL: addha_za_pp_z_32" << std::endl; failed++; }
    try { test_addha_za_pp_z_64(); } catch (...) { std::cerr << "FAIL: addha_za_pp_z_64" << std::endl; failed++; }
    try { test_addva_za_pp_z_32(); } catch (...) { std::cerr << "FAIL: addva_za_pp_z_32" << std::endl; failed++; }
    try { test_addva_za_pp_z_64(); } catch (...) { std::cerr << "FAIL: addva_za_pp_z_64" << std::endl; failed++; }
    try { test_bf1cvt_mz2_z8_(); } catch (...) { std::cerr << "FAIL: bf1cvt_mz2_z8_" << std::endl; failed++; }
    try { test_bf2cvt_mz2_z8_(); } catch (...) { std::cerr << "FAIL: bf2cvt_mz2_z8_" << std::endl; failed++; }
    try { test_bf1cvtl_mz2_z8_(); } catch (...) { std::cerr << "FAIL: bf1cvtl_mz2_z8_" << std::endl; failed++; }
    try { test_bf2cvtl_mz2_z8_(); } catch (...) { std::cerr << "FAIL: bf2cvtl_mz2_z8_" << std::endl; failed++; }
    try { test_bfadd_za_zw_2x2_16(); } catch (...) { std::cerr << "FAIL: bfadd_za_zw_2x2_16" << std::endl; failed++; }
    try { test_bfadd_za_zw_4x4_16(); } catch (...) { std::cerr << "FAIL: bfadd_za_zw_4x4_16" << std::endl; failed++; }
    try { test_bfclamp_mz_zz_2(); } catch (...) { std::cerr << "FAIL: bfclamp_mz_zz_2" << std::endl; failed++; }
    try { test_bfclamp_mz_zz_4(); } catch (...) { std::cerr << "FAIL: bfclamp_mz_zz_4" << std::endl; failed++; }
    try { test_bfcvt_z8_mz2_(); } catch (...) { std::cerr << "FAIL: bfcvt_z8_mz2_" << std::endl; failed++; }
    try { test_bfcvt_z_mz2_(); } catch (...) { std::cerr << "FAIL: bfcvt_z_mz2_" << std::endl; failed++; }
    try { test_bfcvtn_z_mz2_(); } catch (...) { std::cerr << "FAIL: bfcvtn_z_mz2_" << std::endl; failed++; }
    try { test_bfdot_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzi_2xi" << std::endl; failed++; }
    try { test_bfdot_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzi_4xi" << std::endl; failed++; }
    try { test_bfdot_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzv_2x1" << std::endl; failed++; }
    try { test_bfdot_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzv_4x1" << std::endl; failed++; }
    try { test_bfdot_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzw_2x2" << std::endl; failed++; }
    try { test_bfdot_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfdot_za_zzw_4x4" << std::endl; failed++; }
    try { test_bfmax_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmax_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfmax_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmax_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfmax_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmax_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfmax_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmax_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfmaxnm_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmaxnm_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfmaxnm_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmaxnm_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfmaxnm_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmaxnm_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfmaxnm_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmaxnm_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfmin_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmin_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfmin_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmin_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfmin_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmin_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfmin_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmin_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfminnm_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfminnm_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfminnm_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfminnm_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfminnm_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfminnm_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfminnm_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfminnm_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfmla_za_zzi_h2xi(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzi_h2xi" << std::endl; failed++; }
    try { test_bfmla_za_zzi_h4xi(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzi_h4xi" << std::endl; failed++; }
    try { test_bfmla_za_zzv_2x1_16(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzv_2x1_16" << std::endl; failed++; }
    try { test_bfmla_za_zzv_4x1_16(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzv_4x1_16" << std::endl; failed++; }
    try { test_bfmla_za_zzw_2x2_16(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzw_2x2_16" << std::endl; failed++; }
    try { test_bfmla_za_zzw_4x4_16(); } catch (...) { std::cerr << "FAIL: bfmla_za_zzw_4x4_16" << std::endl; failed++; }
    try { test_bfmlal_za_zzi_1(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzi_1" << std::endl; failed++; }
    try { test_bfmlal_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzi_2xi" << std::endl; failed++; }
    try { test_bfmlal_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzi_4xi" << std::endl; failed++; }
    try { test_bfmlal_za_zzv_1(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzv_1" << std::endl; failed++; }
    try { test_bfmlal_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzv_2x1" << std::endl; failed++; }
    try { test_bfmlal_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzv_4x1" << std::endl; failed++; }
    try { test_bfmlal_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzw_2x2" << std::endl; failed++; }
    try { test_bfmlal_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmlal_za_zzw_4x4" << std::endl; failed++; }
    try { test_bfmls_za_zzi_h2xi(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzi_h2xi" << std::endl; failed++; }
    try { test_bfmls_za_zzi_h4xi(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzi_h4xi" << std::endl; failed++; }
    try { test_bfmls_za_zzv_2x1_16(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzv_2x1_16" << std::endl; failed++; }
    try { test_bfmls_za_zzv_4x1_16(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzv_4x1_16" << std::endl; failed++; }
    try { test_bfmls_za_zzw_2x2_16(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzw_2x2_16" << std::endl; failed++; }
    try { test_bfmls_za_zzw_4x4_16(); } catch (...) { std::cerr << "FAIL: bfmls_za_zzw_4x4_16" << std::endl; failed++; }
    try { test_bfmlsl_za_zzi_1(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzi_1" << std::endl; failed++; }
    try { test_bfmlsl_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzi_2xi" << std::endl; failed++; }
    try { test_bfmlsl_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzi_4xi" << std::endl; failed++; }
    try { test_bfmlsl_za_zzv_1(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzv_1" << std::endl; failed++; }
    try { test_bfmlsl_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzv_2x1" << std::endl; failed++; }
    try { test_bfmlsl_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzv_4x1" << std::endl; failed++; }
    try { test_bfmlsl_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzw_2x2" << std::endl; failed++; }
    try { test_bfmlsl_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmlsl_za_zzw_4x4" << std::endl; failed++; }
    try { test_bfmop4a_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: bfmop4a_za32_zz_h1x2" << std::endl; failed++; }
    try { test_bfmop4a_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: bfmop4a_za32_zz_h1x1" << std::endl; failed++; }
    try { test_bfmop4a_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: bfmop4a_za32_zz_h2x1" << std::endl; failed++; }
    try { test_bfmop4a_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: bfmop4a_za32_zz_h2x2" << std::endl; failed++; }
    try { test_bfmop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: bfmop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_bfmop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: bfmop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_bfmop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: bfmop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_bfmop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: bfmop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_bfmop4s_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: bfmop4s_za32_zz_h1x2" << std::endl; failed++; }
    try { test_bfmop4s_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: bfmop4s_za32_zz_h1x1" << std::endl; failed++; }
    try { test_bfmop4s_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: bfmop4s_za32_zz_h2x1" << std::endl; failed++; }
    try { test_bfmop4s_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: bfmop4s_za32_zz_h2x2" << std::endl; failed++; }
    try { test_bfmop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: bfmop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_bfmop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: bfmop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_bfmop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: bfmop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_bfmop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: bfmop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_bfmopa_za32_pp_zz_(); } catch (...) { std::cerr << "FAIL: bfmopa_za32_pp_zz_" << std::endl; failed++; }
    try { test_bfmopa_za_pp_zz_16(); } catch (...) { std::cerr << "FAIL: bfmopa_za_pp_zz_16" << std::endl; failed++; }
    try { test_bfmops_za32_pp_zz_(); } catch (...) { std::cerr << "FAIL: bfmops_za32_pp_zz_" << std::endl; failed++; }
    try { test_bfmops_za_pp_zz_16(); } catch (...) { std::cerr << "FAIL: bfmops_za_pp_zz_16" << std::endl; failed++; }
    try { test_bfmul_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfmul_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfmul_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfmul_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfmul_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfmul_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfmul_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfmul_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfscale_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: bfscale_mz_zzv_2x1" << std::endl; failed++; }
    try { test_bfscale_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: bfscale_mz_zzv_4x1" << std::endl; failed++; }
    try { test_bfscale_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: bfscale_mz_zzw_2x2" << std::endl; failed++; }
    try { test_bfscale_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: bfscale_mz_zzw_4x4" << std::endl; failed++; }
    try { test_bfsub_za_zw_2x2_16(); } catch (...) { std::cerr << "FAIL: bfsub_za_zw_2x2_16" << std::endl; failed++; }
    try { test_bfsub_za_zw_4x4_16(); } catch (...) { std::cerr << "FAIL: bfsub_za_zw_4x4_16" << std::endl; failed++; }
    try { test_bftmopa_za32_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: bftmopa_za32_zzzi_h2x1" << std::endl; failed++; }
    try { test_bftmopa_za_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: bftmopa_za_zzzi_h2x1" << std::endl; failed++; }
    try { test_bfvdot_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: bfvdot_za_zzi_2xi" << std::endl; failed++; }
    try { test_bmopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: bmopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_bmops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: bmops_za_pp_zz_32" << std::endl; failed++; }
    try { test_f1cvt_mz2_z8_(); } catch (...) { std::cerr << "FAIL: f1cvt_mz2_z8_" << std::endl; failed++; }
    try { test_f2cvt_mz2_z8_(); } catch (...) { std::cerr << "FAIL: f2cvt_mz2_z8_" << std::endl; failed++; }
    try { test_f1cvtl_mz2_z8_(); } catch (...) { std::cerr << "FAIL: f1cvtl_mz2_z8_" << std::endl; failed++; }
    try { test_f2cvtl_mz2_z8_(); } catch (...) { std::cerr << "FAIL: f2cvtl_mz2_z8_" << std::endl; failed++; }
    try { test_fadd_za_zw_2x2(); } catch (...) { std::cerr << "FAIL: fadd_za_zw_2x2" << std::endl; failed++; }
    try { test_fadd_za_zw_2x2_16(); } catch (...) { std::cerr << "FAIL: fadd_za_zw_2x2_16" << std::endl; failed++; }
    try { test_fadd_za_zw_4x4(); } catch (...) { std::cerr << "FAIL: fadd_za_zw_4x4" << std::endl; failed++; }
    try { test_fadd_za_zw_4x4_16(); } catch (...) { std::cerr << "FAIL: fadd_za_zw_4x4_16" << std::endl; failed++; }
    try { test_famax_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: famax_mz_zzw_2x2" << std::endl; failed++; }
    try { test_famax_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: famax_mz_zzw_4x4" << std::endl; failed++; }
    try { test_famin_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: famin_mz_zzw_2x2" << std::endl; failed++; }
    try { test_famin_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: famin_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fclamp_mz_zz_2(); } catch (...) { std::cerr << "FAIL: fclamp_mz_zz_2" << std::endl; failed++; }
    try { test_fclamp_mz_zz_4(); } catch (...) { std::cerr << "FAIL: fclamp_mz_zz_4" << std::endl; failed++; }
    try { test_fcvt_mz2_z_(); } catch (...) { std::cerr << "FAIL: fcvt_mz2_z_" << std::endl; failed++; }
    try { test_fcvt_z8_mz2_(); } catch (...) { std::cerr << "FAIL: fcvt_z8_mz2_" << std::endl; failed++; }
    try { test_fcvt_z8_mz4_(); } catch (...) { std::cerr << "FAIL: fcvt_z8_mz4_" << std::endl; failed++; }
    try { test_fcvt_z_mz2_(); } catch (...) { std::cerr << "FAIL: fcvt_z_mz2_" << std::endl; failed++; }
    try { test_fcvtl_mz2_z_(); } catch (...) { std::cerr << "FAIL: fcvtl_mz2_z_" << std::endl; failed++; }
    try { test_fcvtn_z8_mz4_(); } catch (...) { std::cerr << "FAIL: fcvtn_z8_mz4_" << std::endl; failed++; }
    try { test_fcvtn_z_mz2_(); } catch (...) { std::cerr << "FAIL: fcvtn_z_mz2_" << std::endl; failed++; }
    try { test_fcvtzs_mz_z_2(); } catch (...) { std::cerr << "FAIL: fcvtzs_mz_z_2" << std::endl; failed++; }
    try { test_fcvtzs_mz_z_4(); } catch (...) { std::cerr << "FAIL: fcvtzs_mz_z_4" << std::endl; failed++; }
    try { test_fcvtzu_mz_z_2(); } catch (...) { std::cerr << "FAIL: fcvtzu_mz_z_2" << std::endl; failed++; }
    try { test_fcvtzu_mz_z_4(); } catch (...) { std::cerr << "FAIL: fcvtzu_mz_z_4" << std::endl; failed++; }
    try { test_fdot_za32_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8i_2xi" << std::endl; failed++; }
    try { test_fdot_za32_z8z8i_4xi(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8i_4xi" << std::endl; failed++; }
    try { test_fdot_za32_z8z8v_2x1(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8v_2x1" << std::endl; failed++; }
    try { test_fdot_za32_z8z8v_4x1(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8v_4x1" << std::endl; failed++; }
    try { test_fdot_za32_z8z8w_2x2(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8w_2x2" << std::endl; failed++; }
    try { test_fdot_za32_z8z8w_4x4(); } catch (...) { std::cerr << "FAIL: fdot_za32_z8z8w_4x4" << std::endl; failed++; }
    try { test_fdot_za_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8i_2xi" << std::endl; failed++; }
    try { test_fdot_za_z8z8i_4xi(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8i_4xi" << std::endl; failed++; }
    try { test_fdot_za_z8z8v_2x1(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8v_2x1" << std::endl; failed++; }
    try { test_fdot_za_z8z8v_4x1(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8v_4x1" << std::endl; failed++; }
    try { test_fdot_za_z8z8w_2x2(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8w_2x2" << std::endl; failed++; }
    try { test_fdot_za_z8z8w_4x4(); } catch (...) { std::cerr << "FAIL: fdot_za_z8z8w_4x4" << std::endl; failed++; }
    try { test_fdot_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: fdot_za_zzi_2xi" << std::endl; failed++; }
    try { test_fdot_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: fdot_za_zzi_4xi" << std::endl; failed++; }
    try { test_fdot_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fdot_za_zzv_2x1" << std::endl; failed++; }
    try { test_fdot_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fdot_za_zzv_4x1" << std::endl; failed++; }
    try { test_fdot_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fdot_za_zzw_2x2" << std::endl; failed++; }
    try { test_fdot_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fdot_za_zzw_4x4" << std::endl; failed++; }
    try { test_fmax_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmax_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fmax_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmax_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fmax_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmax_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fmax_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmax_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fmaxnm_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmaxnm_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fmaxnm_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmaxnm_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fmaxnm_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmaxnm_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fmaxnm_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmaxnm_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fmin_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmin_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fmin_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmin_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fmin_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmin_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fmin_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmin_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fminnm_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fminnm_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fminnm_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fminnm_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fminnm_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fminnm_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fminnm_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fminnm_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fmla_za_zzi_h2xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_h2xi" << std::endl; failed++; }
    try { test_fmla_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_s2xi" << std::endl; failed++; }
    try { test_fmla_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_d2xi" << std::endl; failed++; }
    try { test_fmla_za_zzi_h4xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_h4xi" << std::endl; failed++; }
    try { test_fmla_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_s4xi" << std::endl; failed++; }
    try { test_fmla_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: fmla_za_zzi_d4xi" << std::endl; failed++; }
    try { test_fmla_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmla_za_zzv_2x1" << std::endl; failed++; }
    try { test_fmla_za_zzv_2x1_16(); } catch (...) { std::cerr << "FAIL: fmla_za_zzv_2x1_16" << std::endl; failed++; }
    try { test_fmla_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmla_za_zzv_4x1" << std::endl; failed++; }
    try { test_fmla_za_zzv_4x1_16(); } catch (...) { std::cerr << "FAIL: fmla_za_zzv_4x1_16" << std::endl; failed++; }
    try { test_fmla_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmla_za_zzw_2x2" << std::endl; failed++; }
    try { test_fmla_za_zzw_2x2_16(); } catch (...) { std::cerr << "FAIL: fmla_za_zzw_2x2_16" << std::endl; failed++; }
    try { test_fmla_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmla_za_zzw_4x4" << std::endl; failed++; }
    try { test_fmla_za_zzw_4x4_16(); } catch (...) { std::cerr << "FAIL: fmla_za_zzw_4x4_16" << std::endl; failed++; }
    try { test_fmlal_za_z8z8i_1(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8i_1" << std::endl; failed++; }
    try { test_fmlal_za_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8i_2xi" << std::endl; failed++; }
    try { test_fmlal_za_z8z8i_4xi(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8i_4xi" << std::endl; failed++; }
    try { test_fmlal_za_z8z8v_1(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8v_1" << std::endl; failed++; }
    try { test_fmlal_za_z8z8v_2x1(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8v_2x1" << std::endl; failed++; }
    try { test_fmlal_za_z8z8v_4x1(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8v_4x1" << std::endl; failed++; }
    try { test_fmlal_za_z8z8w_2x2(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8w_2x2" << std::endl; failed++; }
    try { test_fmlal_za_z8z8w_4x4(); } catch (...) { std::cerr << "FAIL: fmlal_za_z8z8w_4x4" << std::endl; failed++; }
    try { test_fmlal_za_zzi_1(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzi_1" << std::endl; failed++; }
    try { test_fmlal_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzi_2xi" << std::endl; failed++; }
    try { test_fmlal_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzi_4xi" << std::endl; failed++; }
    try { test_fmlal_za_zzv_1(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzv_1" << std::endl; failed++; }
    try { test_fmlal_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzv_2x1" << std::endl; failed++; }
    try { test_fmlal_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzv_4x1" << std::endl; failed++; }
    try { test_fmlal_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzw_2x2" << std::endl; failed++; }
    try { test_fmlal_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmlal_za_zzw_4x4" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8i_1(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8i_1" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8i_2xi" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8i_4xi(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8i_4xi" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8v_1(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8v_1" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8v_2x1(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8v_2x1" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8v_4x1(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8v_4x1" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8w_2x2(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8w_2x2" << std::endl; failed++; }
    try { test_fmlall_za32_z8z8w_4x4(); } catch (...) { std::cerr << "FAIL: fmlall_za32_z8z8w_4x4" << std::endl; failed++; }
    try { test_fmls_za_zzi_h2xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_h2xi" << std::endl; failed++; }
    try { test_fmls_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_s2xi" << std::endl; failed++; }
    try { test_fmls_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_d2xi" << std::endl; failed++; }
    try { test_fmls_za_zzi_h4xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_h4xi" << std::endl; failed++; }
    try { test_fmls_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_s4xi" << std::endl; failed++; }
    try { test_fmls_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: fmls_za_zzi_d4xi" << std::endl; failed++; }
    try { test_fmls_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmls_za_zzv_2x1" << std::endl; failed++; }
    try { test_fmls_za_zzv_2x1_16(); } catch (...) { std::cerr << "FAIL: fmls_za_zzv_2x1_16" << std::endl; failed++; }
    try { test_fmls_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmls_za_zzv_4x1" << std::endl; failed++; }
    try { test_fmls_za_zzv_4x1_16(); } catch (...) { std::cerr << "FAIL: fmls_za_zzv_4x1_16" << std::endl; failed++; }
    try { test_fmls_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmls_za_zzw_2x2" << std::endl; failed++; }
    try { test_fmls_za_zzw_2x2_16(); } catch (...) { std::cerr << "FAIL: fmls_za_zzw_2x2_16" << std::endl; failed++; }
    try { test_fmls_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmls_za_zzw_4x4" << std::endl; failed++; }
    try { test_fmls_za_zzw_4x4_16(); } catch (...) { std::cerr << "FAIL: fmls_za_zzw_4x4_16" << std::endl; failed++; }
    try { test_fmlsl_za_zzi_1(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzi_1" << std::endl; failed++; }
    try { test_fmlsl_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzi_2xi" << std::endl; failed++; }
    try { test_fmlsl_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzi_4xi" << std::endl; failed++; }
    try { test_fmlsl_za_zzv_1(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzv_1" << std::endl; failed++; }
    try { test_fmlsl_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzv_2x1" << std::endl; failed++; }
    try { test_fmlsl_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzv_4x1" << std::endl; failed++; }
    try { test_fmlsl_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzw_2x2" << std::endl; failed++; }
    try { test_fmlsl_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmlsl_za_zzw_4x4" << std::endl; failed++; }
    try { test_fmop4a_za16_z8z8_b1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za16_z8z8_b1x2" << std::endl; failed++; }
    try { test_fmop4a_za16_z8z8_b1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za16_z8z8_b1x1" << std::endl; failed++; }
    try { test_fmop4a_za16_z8z8_b2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za16_z8z8_b2x1" << std::endl; failed++; }
    try { test_fmop4a_za16_z8z8_b2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za16_z8z8_b2x2" << std::endl; failed++; }
    try { test_fmop4a_za32_z8z8_b1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_z8z8_b1x2" << std::endl; failed++; }
    try { test_fmop4a_za32_z8z8_b1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_z8z8_b1x1" << std::endl; failed++; }
    try { test_fmop4a_za32_z8z8_b2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_z8z8_b2x1" << std::endl; failed++; }
    try { test_fmop4a_za32_z8z8_b2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_z8z8_b2x2" << std::endl; failed++; }
    try { test_fmop4a_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_zz_h1x2" << std::endl; failed++; }
    try { test_fmop4a_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_zz_h1x1" << std::endl; failed++; }
    try { test_fmop4a_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_zz_h2x1" << std::endl; failed++; }
    try { test_fmop4a_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za32_zz_h2x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_s1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_s1x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_s1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_s1x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_s2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_s2x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_s2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_s2x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_d1x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_d1x2" << std::endl; failed++; }
    try { test_fmop4a_za_zz_d1x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_d1x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_d2x1(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_d2x1" << std::endl; failed++; }
    try { test_fmop4a_za_zz_d2x2(); } catch (...) { std::cerr << "FAIL: fmop4a_za_zz_d2x2" << std::endl; failed++; }
    try { test_fmop4s_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za32_zz_h1x2" << std::endl; failed++; }
    try { test_fmop4s_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za32_zz_h1x1" << std::endl; failed++; }
    try { test_fmop4s_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za32_zz_h2x1" << std::endl; failed++; }
    try { test_fmop4s_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za32_zz_h2x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_s1x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_s1x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_s1x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_s1x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_s2x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_s2x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_s2x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_s2x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_d1x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_d1x2" << std::endl; failed++; }
    try { test_fmop4s_za_zz_d1x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_d1x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_d2x1(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_d2x1" << std::endl; failed++; }
    try { test_fmop4s_za_zz_d2x2(); } catch (...) { std::cerr << "FAIL: fmop4s_za_zz_d2x2" << std::endl; failed++; }
    try { test_fmopa_za16_pp_z8z8_8(); } catch (...) { std::cerr << "FAIL: fmopa_za16_pp_z8z8_8" << std::endl; failed++; }
    try { test_fmopa_za32_pp_z8z8_8(); } catch (...) { std::cerr << "FAIL: fmopa_za32_pp_z8z8_8" << std::endl; failed++; }
    try { test_fmopa_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: fmopa_za32_pp_zz_16" << std::endl; failed++; }
    try { test_fmopa_za_pp_zz_16(); } catch (...) { std::cerr << "FAIL: fmopa_za_pp_zz_16" << std::endl; failed++; }
    try { test_fmopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: fmopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_fmopa_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: fmopa_za_pp_zz_64" << std::endl; failed++; }
    try { test_fmops_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: fmops_za32_pp_zz_16" << std::endl; failed++; }
    try { test_fmops_za_pp_zz_16(); } catch (...) { std::cerr << "FAIL: fmops_za_pp_zz_16" << std::endl; failed++; }
    try { test_fmops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: fmops_za_pp_zz_32" << std::endl; failed++; }
    try { test_fmops_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: fmops_za_pp_zz_64" << std::endl; failed++; }
    try { test_fmul_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fmul_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fmul_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fmul_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fmul_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fmul_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fmul_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fmul_mz_zzw_4x4" << std::endl; failed++; }
    try { test_frinta_mz_z_2(); } catch (...) { std::cerr << "FAIL: frinta_mz_z_2" << std::endl; failed++; }
    try { test_frinta_mz_z_4(); } catch (...) { std::cerr << "FAIL: frinta_mz_z_4" << std::endl; failed++; }
    try { test_frintm_mz_z_2(); } catch (...) { std::cerr << "FAIL: frintm_mz_z_2" << std::endl; failed++; }
    try { test_frintm_mz_z_4(); } catch (...) { std::cerr << "FAIL: frintm_mz_z_4" << std::endl; failed++; }
    try { test_frintn_mz_z_2(); } catch (...) { std::cerr << "FAIL: frintn_mz_z_2" << std::endl; failed++; }
    try { test_frintn_mz_z_4(); } catch (...) { std::cerr << "FAIL: frintn_mz_z_4" << std::endl; failed++; }
    try { test_frintp_mz_z_2(); } catch (...) { std::cerr << "FAIL: frintp_mz_z_2" << std::endl; failed++; }
    try { test_frintp_mz_z_4(); } catch (...) { std::cerr << "FAIL: frintp_mz_z_4" << std::endl; failed++; }
    try { test_fscale_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: fscale_mz_zzv_2x1" << std::endl; failed++; }
    try { test_fscale_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: fscale_mz_zzv_4x1" << std::endl; failed++; }
    try { test_fscale_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: fscale_mz_zzw_2x2" << std::endl; failed++; }
    try { test_fscale_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: fscale_mz_zzw_4x4" << std::endl; failed++; }
    try { test_fsub_za_zw_2x2(); } catch (...) { std::cerr << "FAIL: fsub_za_zw_2x2" << std::endl; failed++; }
    try { test_fsub_za_zw_2x2_16(); } catch (...) { std::cerr << "FAIL: fsub_za_zw_2x2_16" << std::endl; failed++; }
    try { test_fsub_za_zw_4x4(); } catch (...) { std::cerr << "FAIL: fsub_za_zw_4x4" << std::endl; failed++; }
    try { test_fsub_za_zw_4x4_16(); } catch (...) { std::cerr << "FAIL: fsub_za_zw_4x4_16" << std::endl; failed++; }
    try { test_ftmopa_za16_z8z8zi_b2x1(); } catch (...) { std::cerr << "FAIL: ftmopa_za16_z8z8zi_b2x1" << std::endl; failed++; }
    try { test_ftmopa_za32_z8z8zi_b2x1(); } catch (...) { std::cerr << "FAIL: ftmopa_za32_z8z8zi_b2x1" << std::endl; failed++; }
    try { test_ftmopa_za32_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: ftmopa_za32_zzzi_h2x1" << std::endl; failed++; }
    try { test_ftmopa_za_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: ftmopa_za_zzzi_h2x1" << std::endl; failed++; }
    try { test_ftmopa_za_zzzi_s2x1(); } catch (...) { std::cerr << "FAIL: ftmopa_za_zzzi_s2x1" << std::endl; failed++; }
    try { test_fvdot_za_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fvdot_za_z8z8i_2xi" << std::endl; failed++; }
    try { test_fvdot_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: fvdot_za_zzi_2xi" << std::endl; failed++; }
    try { test_fvdotb_za32_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fvdotb_za32_z8z8i_2xi" << std::endl; failed++; }
    try { test_fvdott_za32_z8z8i_2xi(); } catch (...) { std::cerr << "FAIL: fvdott_za32_z8z8i_2xi" << std::endl; failed++; }
    try { test_ld1b_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ld1b_mz_p_bi_2" << std::endl; failed++; }
    try { test_ld1b_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ld1b_mz_p_bi_4" << std::endl; failed++; }
    try { test_ld1b_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ld1b_mz_p_br_2" << std::endl; failed++; }
    try { test_ld1b_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ld1b_mz_p_br_4" << std::endl; failed++; }
    try { test_ld1b_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ld1b_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ld1b_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ld1b_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ld1b_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ld1b_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ld1b_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ld1b_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ld1b_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: ld1b_za_p_rrr_" << std::endl; failed++; }
    try { test_ld1d_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ld1d_mz_p_bi_2" << std::endl; failed++; }
    try { test_ld1d_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ld1d_mz_p_bi_4" << std::endl; failed++; }
    try { test_ld1d_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ld1d_mz_p_br_2" << std::endl; failed++; }
    try { test_ld1d_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ld1d_mz_p_br_4" << std::endl; failed++; }
    try { test_ld1d_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ld1d_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ld1d_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ld1d_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ld1d_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ld1d_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ld1d_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ld1d_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ld1d_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: ld1d_za_p_rrr_" << std::endl; failed++; }
    try { test_ld1h_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ld1h_mz_p_bi_2" << std::endl; failed++; }
    try { test_ld1h_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ld1h_mz_p_bi_4" << std::endl; failed++; }
    try { test_ld1h_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ld1h_mz_p_br_2" << std::endl; failed++; }
    try { test_ld1h_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ld1h_mz_p_br_4" << std::endl; failed++; }
    try { test_ld1h_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ld1h_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ld1h_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ld1h_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ld1h_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ld1h_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ld1h_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ld1h_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ld1h_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: ld1h_za_p_rrr_" << std::endl; failed++; }
    try { test_ld1q_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: ld1q_za_p_rrr_" << std::endl; failed++; }
    try { test_ld1w_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ld1w_mz_p_bi_2" << std::endl; failed++; }
    try { test_ld1w_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ld1w_mz_p_bi_4" << std::endl; failed++; }
    try { test_ld1w_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ld1w_mz_p_br_2" << std::endl; failed++; }
    try { test_ld1w_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ld1w_mz_p_br_4" << std::endl; failed++; }
    try { test_ld1w_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ld1w_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ld1w_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ld1w_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ld1w_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ld1w_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ld1w_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ld1w_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ld1w_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: ld1w_za_p_rrr_" << std::endl; failed++; }
    try { test_ldnt1b_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ldnt1b_mz_p_bi_2" << std::endl; failed++; }
    try { test_ldnt1b_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ldnt1b_mz_p_bi_4" << std::endl; failed++; }
    try { test_ldnt1b_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ldnt1b_mz_p_br_2" << std::endl; failed++; }
    try { test_ldnt1b_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ldnt1b_mz_p_br_4" << std::endl; failed++; }
    try { test_ldnt1b_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1b_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ldnt1b_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1b_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ldnt1b_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1b_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ldnt1b_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1b_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ldnt1d_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ldnt1d_mz_p_bi_2" << std::endl; failed++; }
    try { test_ldnt1d_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ldnt1d_mz_p_bi_4" << std::endl; failed++; }
    try { test_ldnt1d_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ldnt1d_mz_p_br_2" << std::endl; failed++; }
    try { test_ldnt1d_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ldnt1d_mz_p_br_4" << std::endl; failed++; }
    try { test_ldnt1d_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1d_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ldnt1d_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1d_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ldnt1d_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1d_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ldnt1d_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1d_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ldnt1h_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ldnt1h_mz_p_bi_2" << std::endl; failed++; }
    try { test_ldnt1h_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ldnt1h_mz_p_bi_4" << std::endl; failed++; }
    try { test_ldnt1h_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ldnt1h_mz_p_br_2" << std::endl; failed++; }
    try { test_ldnt1h_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ldnt1h_mz_p_br_4" << std::endl; failed++; }
    try { test_ldnt1h_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1h_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ldnt1h_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1h_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ldnt1h_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1h_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ldnt1h_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1h_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ldnt1w_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: ldnt1w_mz_p_bi_2" << std::endl; failed++; }
    try { test_ldnt1w_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: ldnt1w_mz_p_bi_4" << std::endl; failed++; }
    try { test_ldnt1w_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: ldnt1w_mz_p_br_2" << std::endl; failed++; }
    try { test_ldnt1w_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: ldnt1w_mz_p_br_4" << std::endl; failed++; }
    try { test_ldnt1w_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1w_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_ldnt1w_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1w_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_ldnt1w_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: ldnt1w_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_ldnt1w_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: ldnt1w_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_ldr_za_ri_(); } catch (...) { std::cerr << "FAIL: ldr_za_ri_" << std::endl; failed++; }
    try { test_ldr_zt_br_(); } catch (...) { std::cerr << "FAIL: ldr_zt_br_" << std::endl; failed++; }
    try { test_luti2_mz2_ztz_1(); } catch (...) { std::cerr << "FAIL: luti2_mz2_ztz_1" << std::endl; failed++; }
    try { test_luti2_mz2_ztz_8(); } catch (...) { std::cerr << "FAIL: luti2_mz2_ztz_8" << std::endl; failed++; }
    try { test_luti2_mz4_ztz_1(); } catch (...) { std::cerr << "FAIL: luti2_mz4_ztz_1" << std::endl; failed++; }
    try { test_luti2_mz4_ztz_4(); } catch (...) { std::cerr << "FAIL: luti2_mz4_ztz_4" << std::endl; failed++; }
    try { test_luti2_z_ztz_(); } catch (...) { std::cerr << "FAIL: luti2_z_ztz_" << std::endl; failed++; }
    try { test_luti4_mz2_ztz_1(); } catch (...) { std::cerr << "FAIL: luti4_mz2_ztz_1" << std::endl; failed++; }
    try { test_luti4_mz2_ztz_8(); } catch (...) { std::cerr << "FAIL: luti4_mz2_ztz_8" << std::endl; failed++; }
    try { test_luti4_mz4_ztmz2_1(); } catch (...) { std::cerr << "FAIL: luti4_mz4_ztmz2_1" << std::endl; failed++; }
    try { test_luti4_mz4_ztmz2_4(); } catch (...) { std::cerr << "FAIL: luti4_mz4_ztmz2_4" << std::endl; failed++; }
    try { test_luti4_mz4_ztz_1(); } catch (...) { std::cerr << "FAIL: luti4_mz4_ztz_1" << std::endl; failed++; }
    try { test_luti4_mz4_ztz_4(); } catch (...) { std::cerr << "FAIL: luti4_mz4_ztz_4" << std::endl; failed++; }
    try { test_luti4_z_ztz_(); } catch (...) { std::cerr << "FAIL: luti4_z_ztz_" << std::endl; failed++; }
    try { test_luti6_mz4_zmz2_1(); } catch (...) { std::cerr << "FAIL: luti6_mz4_zmz2_1" << std::endl; failed++; }
    try { test_luti6_mz4_zmz2_4(); } catch (...) { std::cerr << "FAIL: luti6_mz4_zmz2_4" << std::endl; failed++; }
    try { test_luti6_mz4_ztmz3_1(); } catch (...) { std::cerr << "FAIL: luti6_mz4_ztmz3_1" << std::endl; failed++; }
    try { test_luti6_mz4_ztmz3_4(); } catch (...) { std::cerr << "FAIL: luti6_mz4_ztmz3_4" << std::endl; failed++; }
    try { test_luti6_z_ztz_(); } catch (...) { std::cerr << "FAIL: luti6_z_ztz_" << std::endl; failed++; }
    try { test_mov_mz2_za_b1_mova_mz2_za_b1(); } catch (...) { std::cerr << "FAIL: mov_mz2_za_b1_mova_mz2_za_b1" << std::endl; failed++; }
    try { test_mov_mz2_za_h1_mova_mz2_za_h1(); } catch (...) { std::cerr << "FAIL: mov_mz2_za_h1_mova_mz2_za_h1" << std::endl; failed++; }
    try { test_mov_mz2_za_w1_mova_mz2_za_w1(); } catch (...) { std::cerr << "FAIL: mov_mz2_za_w1_mova_mz2_za_w1" << std::endl; failed++; }
    try { test_mov_mz2_za_d1_mova_mz2_za_d1(); } catch (...) { std::cerr << "FAIL: mov_mz2_za_d1_mova_mz2_za_d1" << std::endl; failed++; }
    try { test_mov_mz4_za_b1_mova_mz4_za_b1(); } catch (...) { std::cerr << "FAIL: mov_mz4_za_b1_mova_mz4_za_b1" << std::endl; failed++; }
    try { test_mov_mz4_za_h1_mova_mz4_za_h1(); } catch (...) { std::cerr << "FAIL: mov_mz4_za_h1_mova_mz4_za_h1" << std::endl; failed++; }
    try { test_mov_mz4_za_w1_mova_mz4_za_w1(); } catch (...) { std::cerr << "FAIL: mov_mz4_za_w1_mova_mz4_za_w1" << std::endl; failed++; }
    try { test_mov_mz4_za_d1_mova_mz4_za_d1(); } catch (...) { std::cerr << "FAIL: mov_mz4_za_d1_mova_mz4_za_d1" << std::endl; failed++; }
    try { test_mov_mz_za2_1_mova_mz_za2_1(); } catch (...) { std::cerr << "FAIL: mov_mz_za2_1_mova_mz_za2_1" << std::endl; failed++; }
    try { test_mov_mz_za4_1_mova_mz_za4_1(); } catch (...) { std::cerr << "FAIL: mov_mz_za4_1_mova_mz_za4_1" << std::endl; failed++; }
    try { test_mov_z_p_rza_b_mova_z_p_rza_b(); } catch (...) { std::cerr << "FAIL: mov_z_p_rza_b_mova_z_p_rza_b" << std::endl; failed++; }
    try { test_mov_z_p_rza_h_mova_z_p_rza_h(); } catch (...) { std::cerr << "FAIL: mov_z_p_rza_h_mova_z_p_rza_h" << std::endl; failed++; }
    try { test_mov_z_p_rza_w_mova_z_p_rza_w(); } catch (...) { std::cerr << "FAIL: mov_z_p_rza_w_mova_z_p_rza_w" << std::endl; failed++; }
    try { test_mov_z_p_rza_d_mova_z_p_rza_d(); } catch (...) { std::cerr << "FAIL: mov_z_p_rza_d_mova_z_p_rza_d" << std::endl; failed++; }
    try { test_mov_z_p_rza_q_mova_z_p_rza_q(); } catch (...) { std::cerr << "FAIL: mov_z_p_rza_q_mova_z_p_rza_q" << std::endl; failed++; }
    try { test_mov_za2_z_b1_mova_za2_z_b1(); } catch (...) { std::cerr << "FAIL: mov_za2_z_b1_mova_za2_z_b1" << std::endl; failed++; }
    try { test_mov_za2_z_h1_mova_za2_z_h1(); } catch (...) { std::cerr << "FAIL: mov_za2_z_h1_mova_za2_z_h1" << std::endl; failed++; }
    try { test_mov_za2_z_w1_mova_za2_z_w1(); } catch (...) { std::cerr << "FAIL: mov_za2_z_w1_mova_za2_z_w1" << std::endl; failed++; }
    try { test_mov_za2_z_d1_mova_za2_z_d1(); } catch (...) { std::cerr << "FAIL: mov_za2_z_d1_mova_za2_z_d1" << std::endl; failed++; }
    try { test_mov_za4_z_b1_mova_za4_z_b1(); } catch (...) { std::cerr << "FAIL: mov_za4_z_b1_mova_za4_z_b1" << std::endl; failed++; }
    try { test_mov_za4_z_h1_mova_za4_z_h1(); } catch (...) { std::cerr << "FAIL: mov_za4_z_h1_mova_za4_z_h1" << std::endl; failed++; }
    try { test_mov_za4_z_w1_mova_za4_z_w1(); } catch (...) { std::cerr << "FAIL: mov_za4_z_w1_mova_za4_z_w1" << std::endl; failed++; }
    try { test_mov_za4_z_d1_mova_za4_z_d1(); } catch (...) { std::cerr << "FAIL: mov_za4_z_d1_mova_za4_z_d1" << std::endl; failed++; }
    try { test_mov_za_mz2_1_mova_za_mz2_1(); } catch (...) { std::cerr << "FAIL: mov_za_mz2_1_mova_za_mz2_1" << std::endl; failed++; }
    try { test_mov_za_mz4_1_mova_za_mz4_1(); } catch (...) { std::cerr << "FAIL: mov_za_mz4_1_mova_za_mz4_1" << std::endl; failed++; }
    try { test_mov_za_p_rz_b_mova_za_p_rz_b(); } catch (...) { std::cerr << "FAIL: mov_za_p_rz_b_mova_za_p_rz_b" << std::endl; failed++; }
    try { test_mov_za_p_rz_h_mova_za_p_rz_h(); } catch (...) { std::cerr << "FAIL: mov_za_p_rz_h_mova_za_p_rz_h" << std::endl; failed++; }
    try { test_mov_za_p_rz_w_mova_za_p_rz_w(); } catch (...) { std::cerr << "FAIL: mov_za_p_rz_w_mova_za_p_rz_w" << std::endl; failed++; }
    try { test_mov_za_p_rz_d_mova_za_p_rz_d(); } catch (...) { std::cerr << "FAIL: mov_za_p_rz_d_mova_za_p_rz_d" << std::endl; failed++; }
    try { test_mov_za_p_rz_q_mova_za_p_rz_q(); } catch (...) { std::cerr << "FAIL: mov_za_p_rz_q_mova_za_p_rz_q" << std::endl; failed++; }
    try { test_mova_mz2_za_b1(); } catch (...) { std::cerr << "FAIL: mova_mz2_za_b1" << std::endl; failed++; }
    try { test_mova_mz2_za_h1(); } catch (...) { std::cerr << "FAIL: mova_mz2_za_h1" << std::endl; failed++; }
    try { test_mova_mz2_za_w1(); } catch (...) { std::cerr << "FAIL: mova_mz2_za_w1" << std::endl; failed++; }
    try { test_mova_mz2_za_d1(); } catch (...) { std::cerr << "FAIL: mova_mz2_za_d1" << std::endl; failed++; }
    try { test_mova_mz4_za_b1(); } catch (...) { std::cerr << "FAIL: mova_mz4_za_b1" << std::endl; failed++; }
    try { test_mova_mz4_za_h1(); } catch (...) { std::cerr << "FAIL: mova_mz4_za_h1" << std::endl; failed++; }
    try { test_mova_mz4_za_w1(); } catch (...) { std::cerr << "FAIL: mova_mz4_za_w1" << std::endl; failed++; }
    try { test_mova_mz4_za_d1(); } catch (...) { std::cerr << "FAIL: mova_mz4_za_d1" << std::endl; failed++; }
    try { test_mova_mz_za2_1(); } catch (...) { std::cerr << "FAIL: mova_mz_za2_1" << std::endl; failed++; }
    try { test_mova_mz_za4_1(); } catch (...) { std::cerr << "FAIL: mova_mz_za4_1" << std::endl; failed++; }
    try { test_mova_z_p_rza_b(); } catch (...) { std::cerr << "FAIL: mova_z_p_rza_b" << std::endl; failed++; }
    try { test_mova_z_p_rza_h(); } catch (...) { std::cerr << "FAIL: mova_z_p_rza_h" << std::endl; failed++; }
    try { test_mova_z_p_rza_w(); } catch (...) { std::cerr << "FAIL: mova_z_p_rza_w" << std::endl; failed++; }
    try { test_mova_z_p_rza_d(); } catch (...) { std::cerr << "FAIL: mova_z_p_rza_d" << std::endl; failed++; }
    try { test_mova_z_p_rza_q(); } catch (...) { std::cerr << "FAIL: mova_z_p_rza_q" << std::endl; failed++; }
    try { test_mova_za2_z_b1(); } catch (...) { std::cerr << "FAIL: mova_za2_z_b1" << std::endl; failed++; }
    try { test_mova_za2_z_h1(); } catch (...) { std::cerr << "FAIL: mova_za2_z_h1" << std::endl; failed++; }
    try { test_mova_za2_z_w1(); } catch (...) { std::cerr << "FAIL: mova_za2_z_w1" << std::endl; failed++; }
    try { test_mova_za2_z_d1(); } catch (...) { std::cerr << "FAIL: mova_za2_z_d1" << std::endl; failed++; }
    try { test_mova_za4_z_b1(); } catch (...) { std::cerr << "FAIL: mova_za4_z_b1" << std::endl; failed++; }
    try { test_mova_za4_z_h1(); } catch (...) { std::cerr << "FAIL: mova_za4_z_h1" << std::endl; failed++; }
    try { test_mova_za4_z_w1(); } catch (...) { std::cerr << "FAIL: mova_za4_z_w1" << std::endl; failed++; }
    try { test_mova_za4_z_d1(); } catch (...) { std::cerr << "FAIL: mova_za4_z_d1" << std::endl; failed++; }
    try { test_mova_za_mz2_1(); } catch (...) { std::cerr << "FAIL: mova_za_mz2_1" << std::endl; failed++; }
    try { test_mova_za_mz4_1(); } catch (...) { std::cerr << "FAIL: mova_za_mz4_1" << std::endl; failed++; }
    try { test_mova_za_p_rz_b(); } catch (...) { std::cerr << "FAIL: mova_za_p_rz_b" << std::endl; failed++; }
    try { test_mova_za_p_rz_h(); } catch (...) { std::cerr << "FAIL: mova_za_p_rz_h" << std::endl; failed++; }
    try { test_mova_za_p_rz_w(); } catch (...) { std::cerr << "FAIL: mova_za_p_rz_w" << std::endl; failed++; }
    try { test_mova_za_p_rz_d(); } catch (...) { std::cerr << "FAIL: mova_za_p_rz_d" << std::endl; failed++; }
    try { test_mova_za_p_rz_q(); } catch (...) { std::cerr << "FAIL: mova_za_p_rz_q" << std::endl; failed++; }
    try { test_movaz_mz2_za_b1(); } catch (...) { std::cerr << "FAIL: movaz_mz2_za_b1" << std::endl; failed++; }
    try { test_movaz_mz2_za_h1(); } catch (...) { std::cerr << "FAIL: movaz_mz2_za_h1" << std::endl; failed++; }
    try { test_movaz_mz2_za_w1(); } catch (...) { std::cerr << "FAIL: movaz_mz2_za_w1" << std::endl; failed++; }
    try { test_movaz_mz2_za_d1(); } catch (...) { std::cerr << "FAIL: movaz_mz2_za_d1" << std::endl; failed++; }
    try { test_movaz_mz4_za_b1(); } catch (...) { std::cerr << "FAIL: movaz_mz4_za_b1" << std::endl; failed++; }
    try { test_movaz_mz4_za_h1(); } catch (...) { std::cerr << "FAIL: movaz_mz4_za_h1" << std::endl; failed++; }
    try { test_movaz_mz4_za_w1(); } catch (...) { std::cerr << "FAIL: movaz_mz4_za_w1" << std::endl; failed++; }
    try { test_movaz_mz4_za_d1(); } catch (...) { std::cerr << "FAIL: movaz_mz4_za_d1" << std::endl; failed++; }
    try { test_movaz_mz_za2_1(); } catch (...) { std::cerr << "FAIL: movaz_mz_za2_1" << std::endl; failed++; }
    try { test_movaz_mz_za4_1(); } catch (...) { std::cerr << "FAIL: movaz_mz_za4_1" << std::endl; failed++; }
    try { test_movaz_z_rza_b(); } catch (...) { std::cerr << "FAIL: movaz_z_rza_b" << std::endl; failed++; }
    try { test_movaz_z_rza_h(); } catch (...) { std::cerr << "FAIL: movaz_z_rza_h" << std::endl; failed++; }
    try { test_movaz_z_rza_w(); } catch (...) { std::cerr << "FAIL: movaz_z_rza_w" << std::endl; failed++; }
    try { test_movaz_z_rza_d(); } catch (...) { std::cerr << "FAIL: movaz_z_rza_d" << std::endl; failed++; }
    try { test_movaz_z_rza_q(); } catch (...) { std::cerr << "FAIL: movaz_z_rza_q" << std::endl; failed++; }
    try { test_movt_r_zt_(); } catch (...) { std::cerr << "FAIL: movt_r_zt_" << std::endl; failed++; }
    try { test_movt_zt_r_(); } catch (...) { std::cerr << "FAIL: movt_zt_r_" << std::endl; failed++; }
    try { test_movt_zt_z_(); } catch (...) { std::cerr << "FAIL: movt_zt_z_" << std::endl; failed++; }
    try { test_sclamp_mz_zz_2(); } catch (...) { std::cerr << "FAIL: sclamp_mz_zz_2" << std::endl; failed++; }
    try { test_sclamp_mz_zz_4(); } catch (...) { std::cerr << "FAIL: sclamp_mz_zz_4" << std::endl; failed++; }
    try { test_scvtf_mz_z_2(); } catch (...) { std::cerr << "FAIL: scvtf_mz_z_2" << std::endl; failed++; }
    try { test_scvtf_mz_z_4(); } catch (...) { std::cerr << "FAIL: scvtf_mz_z_4" << std::endl; failed++; }
    try { test_sdot_za32_zzi_2xi(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzi_2xi" << std::endl; failed++; }
    try { test_sdot_za32_zzi_4xi(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzi_4xi" << std::endl; failed++; }
    try { test_sdot_za32_zzv_2x1(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzv_2x1" << std::endl; failed++; }
    try { test_sdot_za32_zzv_4x1(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzv_4x1" << std::endl; failed++; }
    try { test_sdot_za32_zzw_2x2(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzw_2x2" << std::endl; failed++; }
    try { test_sdot_za32_zzw_4x4(); } catch (...) { std::cerr << "FAIL: sdot_za32_zzw_4x4" << std::endl; failed++; }
    try { test_sdot_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: sdot_za_zzi_s2xi" << std::endl; failed++; }
    try { test_sdot_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: sdot_za_zzi_d2xi" << std::endl; failed++; }
    try { test_sdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: sdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_sdot_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: sdot_za_zzi_d4xi" << std::endl; failed++; }
    try { test_sdot_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: sdot_za_zzv_2x1" << std::endl; failed++; }
    try { test_sdot_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: sdot_za_zzv_4x1" << std::endl; failed++; }
    try { test_sdot_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: sdot_za_zzw_2x2" << std::endl; failed++; }
    try { test_sdot_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: sdot_za_zzw_4x4" << std::endl; failed++; }
    try { test_sel_mz_p_zz_2(); } catch (...) { std::cerr << "FAIL: sel_mz_p_zz_2" << std::endl; failed++; }
    try { test_sel_mz_p_zz_4(); } catch (...) { std::cerr << "FAIL: sel_mz_p_zz_4" << std::endl; failed++; }
    try { test_smax_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smax_mz_zzv_2x1" << std::endl; failed++; }
    try { test_smax_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smax_mz_zzv_4x1" << std::endl; failed++; }
    try { test_smax_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smax_mz_zzw_2x2" << std::endl; failed++; }
    try { test_smax_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smax_mz_zzw_4x4" << std::endl; failed++; }
    try { test_smin_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smin_mz_zzv_2x1" << std::endl; failed++; }
    try { test_smin_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smin_mz_zzv_4x1" << std::endl; failed++; }
    try { test_smin_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smin_mz_zzw_2x2" << std::endl; failed++; }
    try { test_smin_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smin_mz_zzw_4x4" << std::endl; failed++; }
    try { test_smlal_za_zzi_1(); } catch (...) { std::cerr << "FAIL: smlal_za_zzi_1" << std::endl; failed++; }
    try { test_smlal_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: smlal_za_zzi_2xi" << std::endl; failed++; }
    try { test_smlal_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: smlal_za_zzi_4xi" << std::endl; failed++; }
    try { test_smlal_za_zzv_1(); } catch (...) { std::cerr << "FAIL: smlal_za_zzv_1" << std::endl; failed++; }
    try { test_smlal_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smlal_za_zzv_2x1" << std::endl; failed++; }
    try { test_smlal_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smlal_za_zzv_4x1" << std::endl; failed++; }
    try { test_smlal_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smlal_za_zzw_2x2" << std::endl; failed++; }
    try { test_smlal_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smlal_za_zzw_4x4" << std::endl; failed++; }
    try { test_smlall_za_zzi_s(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_s" << std::endl; failed++; }
    try { test_smlall_za_zzi_d(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_d" << std::endl; failed++; }
    try { test_smlall_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_s2xi" << std::endl; failed++; }
    try { test_smlall_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_d2xi" << std::endl; failed++; }
    try { test_smlall_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_s4xi" << std::endl; failed++; }
    try { test_smlall_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: smlall_za_zzi_d4xi" << std::endl; failed++; }
    try { test_smlall_za_zzv_1(); } catch (...) { std::cerr << "FAIL: smlall_za_zzv_1" << std::endl; failed++; }
    try { test_smlall_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smlall_za_zzv_2x1" << std::endl; failed++; }
    try { test_smlall_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smlall_za_zzv_4x1" << std::endl; failed++; }
    try { test_smlall_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smlall_za_zzw_2x2" << std::endl; failed++; }
    try { test_smlall_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smlall_za_zzw_4x4" << std::endl; failed++; }
    try { test_smlsl_za_zzi_1(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzi_1" << std::endl; failed++; }
    try { test_smlsl_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzi_2xi" << std::endl; failed++; }
    try { test_smlsl_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzi_4xi" << std::endl; failed++; }
    try { test_smlsl_za_zzv_1(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzv_1" << std::endl; failed++; }
    try { test_smlsl_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzv_2x1" << std::endl; failed++; }
    try { test_smlsl_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzv_4x1" << std::endl; failed++; }
    try { test_smlsl_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzw_2x2" << std::endl; failed++; }
    try { test_smlsl_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smlsl_za_zzw_4x4" << std::endl; failed++; }
    try { test_smlsll_za_zzi_s(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_s" << std::endl; failed++; }
    try { test_smlsll_za_zzi_d(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_d" << std::endl; failed++; }
    try { test_smlsll_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_s2xi" << std::endl; failed++; }
    try { test_smlsll_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_d2xi" << std::endl; failed++; }
    try { test_smlsll_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_s4xi" << std::endl; failed++; }
    try { test_smlsll_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzi_d4xi" << std::endl; failed++; }
    try { test_smlsll_za_zzv_1(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzv_1" << std::endl; failed++; }
    try { test_smlsll_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzv_2x1" << std::endl; failed++; }
    try { test_smlsll_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzv_4x1" << std::endl; failed++; }
    try { test_smlsll_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzw_2x2" << std::endl; failed++; }
    try { test_smlsll_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: smlsll_za_zzw_4x4" << std::endl; failed++; }
    try { test_smop4a_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: smop4a_za32_zz_h1x2" << std::endl; failed++; }
    try { test_smop4a_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: smop4a_za32_zz_h1x1" << std::endl; failed++; }
    try { test_smop4a_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: smop4a_za32_zz_h2x1" << std::endl; failed++; }
    try { test_smop4a_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: smop4a_za32_zz_h2x2" << std::endl; failed++; }
    try { test_smop4a_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_b1x2" << std::endl; failed++; }
    try { test_smop4a_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_b1x1" << std::endl; failed++; }
    try { test_smop4a_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_b2x1" << std::endl; failed++; }
    try { test_smop4a_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_b2x2" << std::endl; failed++; }
    try { test_smop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_smop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_smop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_smop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: smop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_smop4s_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: smop4s_za32_zz_h1x2" << std::endl; failed++; }
    try { test_smop4s_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: smop4s_za32_zz_h1x1" << std::endl; failed++; }
    try { test_smop4s_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: smop4s_za32_zz_h2x1" << std::endl; failed++; }
    try { test_smop4s_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: smop4s_za32_zz_h2x2" << std::endl; failed++; }
    try { test_smop4s_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_b1x2" << std::endl; failed++; }
    try { test_smop4s_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_b1x1" << std::endl; failed++; }
    try { test_smop4s_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_b2x1" << std::endl; failed++; }
    try { test_smop4s_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_b2x2" << std::endl; failed++; }
    try { test_smop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_smop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_smop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_smop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: smop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_smopa_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: smopa_za32_pp_zz_16" << std::endl; failed++; }
    try { test_smopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: smopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_smopa_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: smopa_za_pp_zz_64" << std::endl; failed++; }
    try { test_smops_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: smops_za32_pp_zz_16" << std::endl; failed++; }
    try { test_smops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: smops_za_pp_zz_32" << std::endl; failed++; }
    try { test_smops_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: smops_za_pp_zz_64" << std::endl; failed++; }
    try { test_sqcvt_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqcvt_z_mz2_" << std::endl; failed++; }
    try { test_sqcvt_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqcvt_z_mz4_" << std::endl; failed++; }
    try { test_sqcvtn_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqcvtn_z_mz4_" << std::endl; failed++; }
    try { test_sqcvtu_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqcvtu_z_mz2_" << std::endl; failed++; }
    try { test_sqcvtu_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqcvtu_z_mz4_" << std::endl; failed++; }
    try { test_sqcvtun_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqcvtun_z_mz4_" << std::endl; failed++; }
    try { test_sqdmulh_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: sqdmulh_mz_zzv_2x1" << std::endl; failed++; }
    try { test_sqdmulh_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: sqdmulh_mz_zzv_4x1" << std::endl; failed++; }
    try { test_sqdmulh_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: sqdmulh_mz_zzw_2x2" << std::endl; failed++; }
    try { test_sqdmulh_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: sqdmulh_mz_zzw_4x4" << std::endl; failed++; }
    try { test_sqrshr_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqrshr_z_mz2_" << std::endl; failed++; }
    try { test_sqrshr_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqrshr_z_mz4_" << std::endl; failed++; }
    try { test_sqrshrn_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqrshrn_z_mz4_" << std::endl; failed++; }
    try { test_sqrshru_z_mz2_(); } catch (...) { std::cerr << "FAIL: sqrshru_z_mz2_" << std::endl; failed++; }
    try { test_sqrshru_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqrshru_z_mz4_" << std::endl; failed++; }
    try { test_sqrshrun_z_mz4_(); } catch (...) { std::cerr << "FAIL: sqrshrun_z_mz4_" << std::endl; failed++; }
    try { test_srshl_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: srshl_mz_zzv_2x1" << std::endl; failed++; }
    try { test_srshl_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: srshl_mz_zzv_4x1" << std::endl; failed++; }
    try { test_srshl_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: srshl_mz_zzw_2x2" << std::endl; failed++; }
    try { test_srshl_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: srshl_mz_zzw_4x4" << std::endl; failed++; }
    try { test_st1b_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: st1b_mz_p_bi_2" << std::endl; failed++; }
    try { test_st1b_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: st1b_mz_p_bi_4" << std::endl; failed++; }
    try { test_st1b_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: st1b_mz_p_br_2" << std::endl; failed++; }
    try { test_st1b_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: st1b_mz_p_br_4" << std::endl; failed++; }
    try { test_st1b_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: st1b_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_st1b_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: st1b_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_st1b_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: st1b_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_st1b_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: st1b_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_st1b_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: st1b_za_p_rrr_" << std::endl; failed++; }
    try { test_st1d_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: st1d_mz_p_bi_2" << std::endl; failed++; }
    try { test_st1d_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: st1d_mz_p_bi_4" << std::endl; failed++; }
    try { test_st1d_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: st1d_mz_p_br_2" << std::endl; failed++; }
    try { test_st1d_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: st1d_mz_p_br_4" << std::endl; failed++; }
    try { test_st1d_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: st1d_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_st1d_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: st1d_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_st1d_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: st1d_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_st1d_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: st1d_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_st1d_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: st1d_za_p_rrr_" << std::endl; failed++; }
    try { test_st1h_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: st1h_mz_p_bi_2" << std::endl; failed++; }
    try { test_st1h_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: st1h_mz_p_bi_4" << std::endl; failed++; }
    try { test_st1h_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: st1h_mz_p_br_2" << std::endl; failed++; }
    try { test_st1h_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: st1h_mz_p_br_4" << std::endl; failed++; }
    try { test_st1h_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: st1h_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_st1h_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: st1h_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_st1h_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: st1h_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_st1h_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: st1h_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_st1h_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: st1h_za_p_rrr_" << std::endl; failed++; }
    try { test_st1q_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: st1q_za_p_rrr_" << std::endl; failed++; }
    try { test_st1w_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: st1w_mz_p_bi_2" << std::endl; failed++; }
    try { test_st1w_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: st1w_mz_p_bi_4" << std::endl; failed++; }
    try { test_st1w_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: st1w_mz_p_br_2" << std::endl; failed++; }
    try { test_st1w_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: st1w_mz_p_br_4" << std::endl; failed++; }
    try { test_st1w_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: st1w_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_st1w_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: st1w_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_st1w_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: st1w_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_st1w_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: st1w_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_st1w_za_p_rrr_(); } catch (...) { std::cerr << "FAIL: st1w_za_p_rrr_" << std::endl; failed++; }
    try { test_stmopa_za32_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: stmopa_za32_zzzi_h2x1" << std::endl; failed++; }
    try { test_stmopa_za_zzzi_b2x1(); } catch (...) { std::cerr << "FAIL: stmopa_za_zzzi_b2x1" << std::endl; failed++; }
    try { test_stnt1b_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: stnt1b_mz_p_bi_2" << std::endl; failed++; }
    try { test_stnt1b_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: stnt1b_mz_p_bi_4" << std::endl; failed++; }
    try { test_stnt1b_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: stnt1b_mz_p_br_2" << std::endl; failed++; }
    try { test_stnt1b_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: stnt1b_mz_p_br_4" << std::endl; failed++; }
    try { test_stnt1b_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: stnt1b_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_stnt1b_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: stnt1b_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_stnt1b_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: stnt1b_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_stnt1b_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: stnt1b_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_stnt1d_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: stnt1d_mz_p_bi_2" << std::endl; failed++; }
    try { test_stnt1d_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: stnt1d_mz_p_bi_4" << std::endl; failed++; }
    try { test_stnt1d_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: stnt1d_mz_p_br_2" << std::endl; failed++; }
    try { test_stnt1d_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: stnt1d_mz_p_br_4" << std::endl; failed++; }
    try { test_stnt1d_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: stnt1d_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_stnt1d_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: stnt1d_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_stnt1d_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: stnt1d_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_stnt1d_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: stnt1d_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_stnt1h_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: stnt1h_mz_p_bi_2" << std::endl; failed++; }
    try { test_stnt1h_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: stnt1h_mz_p_bi_4" << std::endl; failed++; }
    try { test_stnt1h_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: stnt1h_mz_p_br_2" << std::endl; failed++; }
    try { test_stnt1h_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: stnt1h_mz_p_br_4" << std::endl; failed++; }
    try { test_stnt1h_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: stnt1h_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_stnt1h_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: stnt1h_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_stnt1h_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: stnt1h_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_stnt1h_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: stnt1h_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_stnt1w_mz_p_bi_2(); } catch (...) { std::cerr << "FAIL: stnt1w_mz_p_bi_2" << std::endl; failed++; }
    try { test_stnt1w_mz_p_bi_4(); } catch (...) { std::cerr << "FAIL: stnt1w_mz_p_bi_4" << std::endl; failed++; }
    try { test_stnt1w_mz_p_br_2(); } catch (...) { std::cerr << "FAIL: stnt1w_mz_p_br_2" << std::endl; failed++; }
    try { test_stnt1w_mz_p_br_4(); } catch (...) { std::cerr << "FAIL: stnt1w_mz_p_br_4" << std::endl; failed++; }
    try { test_stnt1w_mzx_p_bi_2x8(); } catch (...) { std::cerr << "FAIL: stnt1w_mzx_p_bi_2x8" << std::endl; failed++; }
    try { test_stnt1w_mzx_p_bi_4x4(); } catch (...) { std::cerr << "FAIL: stnt1w_mzx_p_bi_4x4" << std::endl; failed++; }
    try { test_stnt1w_mzx_p_br_2x8(); } catch (...) { std::cerr << "FAIL: stnt1w_mzx_p_br_2x8" << std::endl; failed++; }
    try { test_stnt1w_mzx_p_br_4x4(); } catch (...) { std::cerr << "FAIL: stnt1w_mzx_p_br_4x4" << std::endl; failed++; }
    try { test_str_za_ri_(); } catch (...) { std::cerr << "FAIL: str_za_ri_" << std::endl; failed++; }
    try { test_str_zt_br_(); } catch (...) { std::cerr << "FAIL: str_zt_br_" << std::endl; failed++; }
    try { test_sub_za_zw_2x2(); } catch (...) { std::cerr << "FAIL: sub_za_zw_2x2" << std::endl; failed++; }
    try { test_sub_za_zw_4x4(); } catch (...) { std::cerr << "FAIL: sub_za_zw_4x4" << std::endl; failed++; }
    try { test_sub_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: sub_za_zzv_2x1" << std::endl; failed++; }
    try { test_sub_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: sub_za_zzv_4x1" << std::endl; failed++; }
    try { test_sub_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: sub_za_zzw_2x2" << std::endl; failed++; }
    try { test_sub_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: sub_za_zzw_4x4" << std::endl; failed++; }
    try { test_sudot_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: sudot_za_zzi_s2xi" << std::endl; failed++; }
    try { test_sudot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: sudot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_sudot_za_zzv_s2x1(); } catch (...) { std::cerr << "FAIL: sudot_za_zzv_s2x1" << std::endl; failed++; }
    try { test_sudot_za_zzv_s4x1(); } catch (...) { std::cerr << "FAIL: sudot_za_zzv_s4x1" << std::endl; failed++; }
    try { test_sumlall_za_zzi_s(); } catch (...) { std::cerr << "FAIL: sumlall_za_zzi_s" << std::endl; failed++; }
    try { test_sumlall_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: sumlall_za_zzi_s2xi" << std::endl; failed++; }
    try { test_sumlall_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: sumlall_za_zzi_s4xi" << std::endl; failed++; }
    try { test_sumlall_za_zzv_s2x1(); } catch (...) { std::cerr << "FAIL: sumlall_za_zzv_s2x1" << std::endl; failed++; }
    try { test_sumlall_za_zzv_s4x1(); } catch (...) { std::cerr << "FAIL: sumlall_za_zzv_s4x1" << std::endl; failed++; }
    try { test_sumop4a_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_b1x2" << std::endl; failed++; }
    try { test_sumop4a_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_b1x1" << std::endl; failed++; }
    try { test_sumop4a_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_b2x1" << std::endl; failed++; }
    try { test_sumop4a_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_b2x2" << std::endl; failed++; }
    try { test_sumop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_sumop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_sumop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_sumop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: sumop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_sumop4s_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_b1x2" << std::endl; failed++; }
    try { test_sumop4s_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_b1x1" << std::endl; failed++; }
    try { test_sumop4s_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_b2x1" << std::endl; failed++; }
    try { test_sumop4s_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_b2x2" << std::endl; failed++; }
    try { test_sumop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_sumop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_sumop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_sumop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: sumop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_sumopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: sumopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_sumopa_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: sumopa_za_pp_zz_64" << std::endl; failed++; }
    try { test_sumops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: sumops_za_pp_zz_32" << std::endl; failed++; }
    try { test_sumops_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: sumops_za_pp_zz_64" << std::endl; failed++; }
    try { test_sunpk_mz_z_2(); } catch (...) { std::cerr << "FAIL: sunpk_mz_z_2" << std::endl; failed++; }
    try { test_sunpk_mz_z_4(); } catch (...) { std::cerr << "FAIL: sunpk_mz_z_4" << std::endl; failed++; }
    try { test_sutmopa_za_zzzi_b2x1(); } catch (...) { std::cerr << "FAIL: sutmopa_za_zzzi_b2x1" << std::endl; failed++; }
    try { test_suvdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: suvdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_svdot_za32_zzi_2xi(); } catch (...) { std::cerr << "FAIL: svdot_za32_zzi_2xi" << std::endl; failed++; }
    try { test_svdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: svdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_svdot_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: svdot_za_zzi_d4xi" << std::endl; failed++; }
    try { test_uclamp_mz_zz_2(); } catch (...) { std::cerr << "FAIL: uclamp_mz_zz_2" << std::endl; failed++; }
    try { test_uclamp_mz_zz_4(); } catch (...) { std::cerr << "FAIL: uclamp_mz_zz_4" << std::endl; failed++; }
    try { test_ucvtf_mz_z_2(); } catch (...) { std::cerr << "FAIL: ucvtf_mz_z_2" << std::endl; failed++; }
    try { test_ucvtf_mz_z_4(); } catch (...) { std::cerr << "FAIL: ucvtf_mz_z_4" << std::endl; failed++; }
    try { test_udot_za32_zzi_2xi(); } catch (...) { std::cerr << "FAIL: udot_za32_zzi_2xi" << std::endl; failed++; }
    try { test_udot_za32_zzi_4xi(); } catch (...) { std::cerr << "FAIL: udot_za32_zzi_4xi" << std::endl; failed++; }
    try { test_udot_za32_zzv_2x1(); } catch (...) { std::cerr << "FAIL: udot_za32_zzv_2x1" << std::endl; failed++; }
    try { test_udot_za32_zzv_4x1(); } catch (...) { std::cerr << "FAIL: udot_za32_zzv_4x1" << std::endl; failed++; }
    try { test_udot_za32_zzw_2x2(); } catch (...) { std::cerr << "FAIL: udot_za32_zzw_2x2" << std::endl; failed++; }
    try { test_udot_za32_zzw_4x4(); } catch (...) { std::cerr << "FAIL: udot_za32_zzw_4x4" << std::endl; failed++; }
    try { test_udot_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: udot_za_zzi_s2xi" << std::endl; failed++; }
    try { test_udot_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: udot_za_zzi_d2xi" << std::endl; failed++; }
    try { test_udot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: udot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_udot_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: udot_za_zzi_d4xi" << std::endl; failed++; }
    try { test_udot_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: udot_za_zzv_2x1" << std::endl; failed++; }
    try { test_udot_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: udot_za_zzv_4x1" << std::endl; failed++; }
    try { test_udot_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: udot_za_zzw_2x2" << std::endl; failed++; }
    try { test_udot_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: udot_za_zzw_4x4" << std::endl; failed++; }
    try { test_umax_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umax_mz_zzv_2x1" << std::endl; failed++; }
    try { test_umax_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umax_mz_zzv_4x1" << std::endl; failed++; }
    try { test_umax_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umax_mz_zzw_2x2" << std::endl; failed++; }
    try { test_umax_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umax_mz_zzw_4x4" << std::endl; failed++; }
    try { test_umin_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umin_mz_zzv_2x1" << std::endl; failed++; }
    try { test_umin_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umin_mz_zzv_4x1" << std::endl; failed++; }
    try { test_umin_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umin_mz_zzw_2x2" << std::endl; failed++; }
    try { test_umin_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umin_mz_zzw_4x4" << std::endl; failed++; }
    try { test_umlal_za_zzi_1(); } catch (...) { std::cerr << "FAIL: umlal_za_zzi_1" << std::endl; failed++; }
    try { test_umlal_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: umlal_za_zzi_2xi" << std::endl; failed++; }
    try { test_umlal_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: umlal_za_zzi_4xi" << std::endl; failed++; }
    try { test_umlal_za_zzv_1(); } catch (...) { std::cerr << "FAIL: umlal_za_zzv_1" << std::endl; failed++; }
    try { test_umlal_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umlal_za_zzv_2x1" << std::endl; failed++; }
    try { test_umlal_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umlal_za_zzv_4x1" << std::endl; failed++; }
    try { test_umlal_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umlal_za_zzw_2x2" << std::endl; failed++; }
    try { test_umlal_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umlal_za_zzw_4x4" << std::endl; failed++; }
    try { test_umlall_za_zzi_s(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_s" << std::endl; failed++; }
    try { test_umlall_za_zzi_d(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_d" << std::endl; failed++; }
    try { test_umlall_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_s2xi" << std::endl; failed++; }
    try { test_umlall_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_d2xi" << std::endl; failed++; }
    try { test_umlall_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_s4xi" << std::endl; failed++; }
    try { test_umlall_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: umlall_za_zzi_d4xi" << std::endl; failed++; }
    try { test_umlall_za_zzv_1(); } catch (...) { std::cerr << "FAIL: umlall_za_zzv_1" << std::endl; failed++; }
    try { test_umlall_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umlall_za_zzv_2x1" << std::endl; failed++; }
    try { test_umlall_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umlall_za_zzv_4x1" << std::endl; failed++; }
    try { test_umlall_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umlall_za_zzw_2x2" << std::endl; failed++; }
    try { test_umlall_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umlall_za_zzw_4x4" << std::endl; failed++; }
    try { test_umlsl_za_zzi_1(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzi_1" << std::endl; failed++; }
    try { test_umlsl_za_zzi_2xi(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzi_2xi" << std::endl; failed++; }
    try { test_umlsl_za_zzi_4xi(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzi_4xi" << std::endl; failed++; }
    try { test_umlsl_za_zzv_1(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzv_1" << std::endl; failed++; }
    try { test_umlsl_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzv_2x1" << std::endl; failed++; }
    try { test_umlsl_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzv_4x1" << std::endl; failed++; }
    try { test_umlsl_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzw_2x2" << std::endl; failed++; }
    try { test_umlsl_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umlsl_za_zzw_4x4" << std::endl; failed++; }
    try { test_umlsll_za_zzi_s(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_s" << std::endl; failed++; }
    try { test_umlsll_za_zzi_d(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_d" << std::endl; failed++; }
    try { test_umlsll_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_s2xi" << std::endl; failed++; }
    try { test_umlsll_za_zzi_d2xi(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_d2xi" << std::endl; failed++; }
    try { test_umlsll_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_s4xi" << std::endl; failed++; }
    try { test_umlsll_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzi_d4xi" << std::endl; failed++; }
    try { test_umlsll_za_zzv_1(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzv_1" << std::endl; failed++; }
    try { test_umlsll_za_zzv_2x1(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzv_2x1" << std::endl; failed++; }
    try { test_umlsll_za_zzv_4x1(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzv_4x1" << std::endl; failed++; }
    try { test_umlsll_za_zzw_2x2(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzw_2x2" << std::endl; failed++; }
    try { test_umlsll_za_zzw_4x4(); } catch (...) { std::cerr << "FAIL: umlsll_za_zzw_4x4" << std::endl; failed++; }
    try { test_umop4a_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: umop4a_za32_zz_h1x2" << std::endl; failed++; }
    try { test_umop4a_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: umop4a_za32_zz_h1x1" << std::endl; failed++; }
    try { test_umop4a_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: umop4a_za32_zz_h2x1" << std::endl; failed++; }
    try { test_umop4a_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: umop4a_za32_zz_h2x2" << std::endl; failed++; }
    try { test_umop4a_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_b1x2" << std::endl; failed++; }
    try { test_umop4a_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_b1x1" << std::endl; failed++; }
    try { test_umop4a_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_b2x1" << std::endl; failed++; }
    try { test_umop4a_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_b2x2" << std::endl; failed++; }
    try { test_umop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_umop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_umop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_umop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: umop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_umop4s_za32_zz_h1x2(); } catch (...) { std::cerr << "FAIL: umop4s_za32_zz_h1x2" << std::endl; failed++; }
    try { test_umop4s_za32_zz_h1x1(); } catch (...) { std::cerr << "FAIL: umop4s_za32_zz_h1x1" << std::endl; failed++; }
    try { test_umop4s_za32_zz_h2x1(); } catch (...) { std::cerr << "FAIL: umop4s_za32_zz_h2x1" << std::endl; failed++; }
    try { test_umop4s_za32_zz_h2x2(); } catch (...) { std::cerr << "FAIL: umop4s_za32_zz_h2x2" << std::endl; failed++; }
    try { test_umop4s_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_b1x2" << std::endl; failed++; }
    try { test_umop4s_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_b1x1" << std::endl; failed++; }
    try { test_umop4s_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_b2x1" << std::endl; failed++; }
    try { test_umop4s_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_b2x2" << std::endl; failed++; }
    try { test_umop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_umop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_umop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_umop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: umop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_umopa_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: umopa_za32_pp_zz_16" << std::endl; failed++; }
    try { test_umopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: umopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_umopa_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: umopa_za_pp_zz_64" << std::endl; failed++; }
    try { test_umops_za32_pp_zz_16(); } catch (...) { std::cerr << "FAIL: umops_za32_pp_zz_16" << std::endl; failed++; }
    try { test_umops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: umops_za_pp_zz_32" << std::endl; failed++; }
    try { test_umops_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: umops_za_pp_zz_64" << std::endl; failed++; }
    try { test_uqcvt_z_mz2_(); } catch (...) { std::cerr << "FAIL: uqcvt_z_mz2_" << std::endl; failed++; }
    try { test_uqcvt_z_mz4_(); } catch (...) { std::cerr << "FAIL: uqcvt_z_mz4_" << std::endl; failed++; }
    try { test_uqcvtn_z_mz4_(); } catch (...) { std::cerr << "FAIL: uqcvtn_z_mz4_" << std::endl; failed++; }
    try { test_uqrshr_z_mz2_(); } catch (...) { std::cerr << "FAIL: uqrshr_z_mz2_" << std::endl; failed++; }
    try { test_uqrshr_z_mz4_(); } catch (...) { std::cerr << "FAIL: uqrshr_z_mz4_" << std::endl; failed++; }
    try { test_uqrshrn_z_mz4_(); } catch (...) { std::cerr << "FAIL: uqrshrn_z_mz4_" << std::endl; failed++; }
    try { test_urshl_mz_zzv_2x1(); } catch (...) { std::cerr << "FAIL: urshl_mz_zzv_2x1" << std::endl; failed++; }
    try { test_urshl_mz_zzv_4x1(); } catch (...) { std::cerr << "FAIL: urshl_mz_zzv_4x1" << std::endl; failed++; }
    try { test_urshl_mz_zzw_2x2(); } catch (...) { std::cerr << "FAIL: urshl_mz_zzw_2x2" << std::endl; failed++; }
    try { test_urshl_mz_zzw_4x4(); } catch (...) { std::cerr << "FAIL: urshl_mz_zzw_4x4" << std::endl; failed++; }
    try { test_usdot_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: usdot_za_zzi_s2xi" << std::endl; failed++; }
    try { test_usdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: usdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_usdot_za_zzv_s2x1(); } catch (...) { std::cerr << "FAIL: usdot_za_zzv_s2x1" << std::endl; failed++; }
    try { test_usdot_za_zzv_s4x1(); } catch (...) { std::cerr << "FAIL: usdot_za_zzv_s4x1" << std::endl; failed++; }
    try { test_usdot_za_zzw_s2x2(); } catch (...) { std::cerr << "FAIL: usdot_za_zzw_s2x2" << std::endl; failed++; }
    try { test_usdot_za_zzw_s4x4(); } catch (...) { std::cerr << "FAIL: usdot_za_zzw_s4x4" << std::endl; failed++; }
    try { test_usmlall_za_zzi_s(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzi_s" << std::endl; failed++; }
    try { test_usmlall_za_zzi_s2xi(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzi_s2xi" << std::endl; failed++; }
    try { test_usmlall_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzi_s4xi" << std::endl; failed++; }
    try { test_usmlall_za_zzv_s(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzv_s" << std::endl; failed++; }
    try { test_usmlall_za_zzv_s2x1(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzv_s2x1" << std::endl; failed++; }
    try { test_usmlall_za_zzv_s4x1(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzv_s4x1" << std::endl; failed++; }
    try { test_usmlall_za_zzw_s2x2(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzw_s2x2" << std::endl; failed++; }
    try { test_usmlall_za_zzw_s4x4(); } catch (...) { std::cerr << "FAIL: usmlall_za_zzw_s4x4" << std::endl; failed++; }
    try { test_usmop4a_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_b1x2" << std::endl; failed++; }
    try { test_usmop4a_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_b1x1" << std::endl; failed++; }
    try { test_usmop4a_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_b2x1" << std::endl; failed++; }
    try { test_usmop4a_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_b2x2" << std::endl; failed++; }
    try { test_usmop4a_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_h1x2" << std::endl; failed++; }
    try { test_usmop4a_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_h1x1" << std::endl; failed++; }
    try { test_usmop4a_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_h2x1" << std::endl; failed++; }
    try { test_usmop4a_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: usmop4a_za_zz_h2x2" << std::endl; failed++; }
    try { test_usmop4s_za_zz_b1x2(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_b1x2" << std::endl; failed++; }
    try { test_usmop4s_za_zz_b1x1(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_b1x1" << std::endl; failed++; }
    try { test_usmop4s_za_zz_b2x1(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_b2x1" << std::endl; failed++; }
    try { test_usmop4s_za_zz_b2x2(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_b2x2" << std::endl; failed++; }
    try { test_usmop4s_za_zz_h1x2(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_h1x2" << std::endl; failed++; }
    try { test_usmop4s_za_zz_h1x1(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_h1x1" << std::endl; failed++; }
    try { test_usmop4s_za_zz_h2x1(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_h2x1" << std::endl; failed++; }
    try { test_usmop4s_za_zz_h2x2(); } catch (...) { std::cerr << "FAIL: usmop4s_za_zz_h2x2" << std::endl; failed++; }
    try { test_usmopa_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: usmopa_za_pp_zz_32" << std::endl; failed++; }
    try { test_usmopa_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: usmopa_za_pp_zz_64" << std::endl; failed++; }
    try { test_usmops_za_pp_zz_32(); } catch (...) { std::cerr << "FAIL: usmops_za_pp_zz_32" << std::endl; failed++; }
    try { test_usmops_za_pp_zz_64(); } catch (...) { std::cerr << "FAIL: usmops_za_pp_zz_64" << std::endl; failed++; }
    try { test_ustmopa_za_zzzi_b2x1(); } catch (...) { std::cerr << "FAIL: ustmopa_za_zzzi_b2x1" << std::endl; failed++; }
    try { test_usvdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: usvdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_utmopa_za32_zzzi_h2x1(); } catch (...) { std::cerr << "FAIL: utmopa_za32_zzzi_h2x1" << std::endl; failed++; }
    try { test_utmopa_za_zzzi_b2x1(); } catch (...) { std::cerr << "FAIL: utmopa_za_zzzi_b2x1" << std::endl; failed++; }
    try { test_uunpk_mz_z_2(); } catch (...) { std::cerr << "FAIL: uunpk_mz_z_2" << std::endl; failed++; }
    try { test_uunpk_mz_z_4(); } catch (...) { std::cerr << "FAIL: uunpk_mz_z_4" << std::endl; failed++; }
    try { test_uvdot_za32_zzi_2xi(); } catch (...) { std::cerr << "FAIL: uvdot_za32_zzi_2xi" << std::endl; failed++; }
    try { test_uvdot_za_zzi_s4xi(); } catch (...) { std::cerr << "FAIL: uvdot_za_zzi_s4xi" << std::endl; failed++; }
    try { test_uvdot_za_zzi_d4xi(); } catch (...) { std::cerr << "FAIL: uvdot_za_zzi_d4xi" << std::endl; failed++; }
    try { test_uzp_mz_z_4(); } catch (...) { std::cerr << "FAIL: uzp_mz_z_4" << std::endl; failed++; }
    try { test_uzp_mz_z_4q(); } catch (...) { std::cerr << "FAIL: uzp_mz_z_4q" << std::endl; failed++; }
    try { test_uzp_mz_zz_2(); } catch (...) { std::cerr << "FAIL: uzp_mz_zz_2" << std::endl; failed++; }
    try { test_uzp_mz_zz_2q(); } catch (...) { std::cerr << "FAIL: uzp_mz_zz_2q" << std::endl; failed++; }
    try { test_zero_za1_ri_2(); } catch (...) { std::cerr << "FAIL: zero_za1_ri_2" << std::endl; failed++; }
    try { test_zero_za1_ri_4(); } catch (...) { std::cerr << "FAIL: zero_za1_ri_4" << std::endl; failed++; }
    try { test_zero_za2_ri_1(); } catch (...) { std::cerr << "FAIL: zero_za2_ri_1" << std::endl; failed++; }
    try { test_zero_za2_ri_2(); } catch (...) { std::cerr << "FAIL: zero_za2_ri_2" << std::endl; failed++; }
    try { test_zero_za2_ri_4(); } catch (...) { std::cerr << "FAIL: zero_za2_ri_4" << std::endl; failed++; }
    try { test_zero_za4_ri_1(); } catch (...) { std::cerr << "FAIL: zero_za4_ri_1" << std::endl; failed++; }
    try { test_zero_za4_ri_2(); } catch (...) { std::cerr << "FAIL: zero_za4_ri_2" << std::endl; failed++; }
    try { test_zero_za4_ri_4(); } catch (...) { std::cerr << "FAIL: zero_za4_ri_4" << std::endl; failed++; }
    try { test_zero_za_i_(); } catch (...) { std::cerr << "FAIL: zero_za_i_" << std::endl; failed++; }
    try { test_zero_zt_i_(); } catch (...) { std::cerr << "FAIL: zero_zt_i_" << std::endl; failed++; }
    try { test_zip_mz_z_4(); } catch (...) { std::cerr << "FAIL: zip_mz_z_4" << std::endl; failed++; }
    try { test_zip_mz_z_4q(); } catch (...) { std::cerr << "FAIL: zip_mz_z_4q" << std::endl; failed++; }
    try { test_zip_mz_zz_2(); } catch (...) { std::cerr << "FAIL: zip_mz_zz_2" << std::endl; failed++; }
    try { test_zip_mz_zz_2q(); } catch (...) { std::cerr << "FAIL: zip_mz_zz_2q" << std::endl; failed++; }

    std::cout << (868 - failed) << " / 868 passed" << std::endl;
    return failed;
}
