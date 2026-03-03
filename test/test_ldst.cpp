// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_cas_c32_comswap() {
    uint32_t insn = 0x88A07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cas_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  cas_c32_comswap: " << result->to_string() << std::endl;
}

void test_casa_c32_comswap() {
    uint32_t insn = 0x88E07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casa_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casa_c32_comswap: " << result->to_string() << std::endl;
}

void test_casal_c32_comswap() {
    uint32_t insn = 0x88E0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casal_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casal_c32_comswap: " << result->to_string() << std::endl;
}

void test_casl_c32_comswap() {
    uint32_t insn = 0x88A0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casl_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casl_c32_comswap: " << result->to_string() << std::endl;
}

void test_cas_c64_comswap() {
    uint32_t insn = 0xC8A07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cas_c64_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  cas_c64_comswap: " << result->to_string() << std::endl;
}

void test_casa_c64_comswap() {
    uint32_t insn = 0xC8E07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casa_c64_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casa_c64_comswap: " << result->to_string() << std::endl;
}

void test_casal_c64_comswap() {
    uint32_t insn = 0xC8E0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casal_c64_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casal_c64_comswap: " << result->to_string() << std::endl;
}

void test_casl_c64_comswap() {
    uint32_t insn = 0xC8A0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casl_c64_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casl_c64_comswap: " << result->to_string() << std::endl;
}

void test_casb_c32_comswap() {
    uint32_t insn = 0x08A07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casb_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casb_c32_comswap: " << result->to_string() << std::endl;
}

void test_casab_c32_comswap() {
    uint32_t insn = 0x08E07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casab_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casab_c32_comswap: " << result->to_string() << std::endl;
}

void test_casalb_c32_comswap() {
    uint32_t insn = 0x08E0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casalb_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casalb_c32_comswap: " << result->to_string() << std::endl;
}

void test_caslb_c32_comswap() {
    uint32_t insn = 0x08A0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caslb_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caslb_c32_comswap: " << result->to_string() << std::endl;
}

void test_cash_c32_comswap() {
    uint32_t insn = 0x48A07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cash_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  cash_c32_comswap: " << result->to_string() << std::endl;
}

void test_casah_c32_comswap() {
    uint32_t insn = 0x48E07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casah_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casah_c32_comswap: " << result->to_string() << std::endl;
}

void test_casalh_c32_comswap() {
    uint32_t insn = 0x48E0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casalh_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casalh_c32_comswap: " << result->to_string() << std::endl;
}

void test_caslh_c32_comswap() {
    uint32_t insn = 0x48A0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caslh_c32_comswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caslh_c32_comswap: " << result->to_string() << std::endl;
}

void test_casp_cp32_comswappr() {
    uint32_t insn = 0x08207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casp_cp32_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casp_cp32_comswappr: " << result->to_string() << std::endl;
}

void test_caspa_cp32_comswappr() {
    uint32_t insn = 0x08607C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspa_cp32_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspa_cp32_comswappr: " << result->to_string() << std::endl;
}

void test_caspal_cp32_comswappr() {
    uint32_t insn = 0x0860FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspal_cp32_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspal_cp32_comswappr: " << result->to_string() << std::endl;
}

void test_caspl_cp32_comswappr() {
    uint32_t insn = 0x0820FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspl_cp32_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspl_cp32_comswappr: " << result->to_string() << std::endl;
}

void test_casp_cp64_comswappr() {
    uint32_t insn = 0x48207C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casp_cp64_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casp_cp64_comswappr: " << result->to_string() << std::endl;
}

void test_caspa_cp64_comswappr() {
    uint32_t insn = 0x48607C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspa_cp64_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspa_cp64_comswappr: " << result->to_string() << std::endl;
}

void test_caspal_cp64_comswappr() {
    uint32_t insn = 0x4860FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspal_cp64_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspal_cp64_comswappr: " << result->to_string() << std::endl;
}

void test_caspl_cp64_comswappr() {
    uint32_t insn = 0x4820FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspl_cp64_comswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspl_cp64_comswappr: " << result->to_string() << std::endl;
}

void test_caspt_cp64_comswappr_unpriv() {
    uint32_t insn = 0x49807C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspt_cp64_comswappr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspt_cp64_comswappr_unpriv: " << result->to_string() << std::endl;
}

void test_caspat_cp64_comswappr_unpriv() {
    uint32_t insn = 0x49C07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspat_cp64_comswappr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspat_cp64_comswappr_unpriv: " << result->to_string() << std::endl;
}

void test_caspalt_cp64_comswappr_unpriv() {
    uint32_t insn = 0x49C0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caspalt_cp64_comswappr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caspalt_cp64_comswappr_unpriv: " << result->to_string() << std::endl;
}

void test_casplt_cp64_comswappr_unpriv() {
    uint32_t insn = 0x4980FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casplt_cp64_comswappr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casplt_cp64_comswappr_unpriv: " << result->to_string() << std::endl;
}

void test_cast_c64_comswap_unpriv() {
    uint32_t insn = 0xC9807C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cast_c64_comswap_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  cast_c64_comswap_unpriv: " << result->to_string() << std::endl;
}

void test_casat_c64_comswap_unpriv() {
    uint32_t insn = 0xC9C07C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casat_c64_comswap_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casat_c64_comswap_unpriv: " << result->to_string() << std::endl;
}

void test_casalt_c64_comswap_unpriv() {
    uint32_t insn = 0xC9C0FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: casalt_c64_comswap_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  casalt_c64_comswap_unpriv: " << result->to_string() << std::endl;
}

void test_caslt_c64_comswap_unpriv() {
    uint32_t insn = 0xC980FC00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: caslt_c64_comswap_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  caslt_c64_comswap_unpriv: " << result->to_string() << std::endl;
}

void test_cpyfp_cpy_memcms() {
    uint32_t insn = 0x19000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfp_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfp_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfm_cpy_memcms() {
    uint32_t insn = 0x19400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfm_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfm_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfe_cpy_memcms() {
    uint32_t insn = 0x19800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfe_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfe_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpn_cpy_memcms() {
    uint32_t insn = 0x1900C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmn_cpy_memcms() {
    uint32_t insn = 0x1940C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfen_cpy_memcms() {
    uint32_t insn = 0x1980C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfen_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfen_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfprn_cpy_memcms() {
    uint32_t insn = 0x19008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfprn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfprn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmrn_cpy_memcms() {
    uint32_t insn = 0x19408400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfern_cpy_memcms() {
    uint32_t insn = 0x19808400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfern_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfern_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfprt_cpy_memcms() {
    uint32_t insn = 0x19002400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfprt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfprt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmrt_cpy_memcms() {
    uint32_t insn = 0x19402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmrt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmrt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfert_cpy_memcms() {
    uint32_t insn = 0x19802400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfert_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfert_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfprtn_cpy_memcms() {
    uint32_t insn = 0x1900E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfprtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfprtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmrtn_cpy_memcms() {
    uint32_t insn = 0x1940E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmrtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmrtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfertn_cpy_memcms() {
    uint32_t insn = 0x1980E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfertn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfertn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfprtrn_cpy_memcms() {
    uint32_t insn = 0x1900A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfprtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfprtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmrtrn_cpy_memcms() {
    uint32_t insn = 0x1940A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmrtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmrtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfertrn_cpy_memcms() {
    uint32_t insn = 0x1980A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfertrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfertrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfprtwn_cpy_memcms() {
    uint32_t insn = 0x19006400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfprtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfprtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmrtwn_cpy_memcms() {
    uint32_t insn = 0x19406400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmrtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmrtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfertwn_cpy_memcms() {
    uint32_t insn = 0x19806400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfertwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfertwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpt_cpy_memcms() {
    uint32_t insn = 0x19003400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmt_cpy_memcms() {
    uint32_t insn = 0x19403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfet_cpy_memcms() {
    uint32_t insn = 0x19803400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfet_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfet_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfptn_cpy_memcms() {
    uint32_t insn = 0x1900F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfptn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfptn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmtn_cpy_memcms() {
    uint32_t insn = 0x1940F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfetn_cpy_memcms() {
    uint32_t insn = 0x1980F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfetn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfetn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfptrn_cpy_memcms() {
    uint32_t insn = 0x1900B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfptrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfptrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmtrn_cpy_memcms() {
    uint32_t insn = 0x1940B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfetrn_cpy_memcms() {
    uint32_t insn = 0x1980B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfetrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfetrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfptwn_cpy_memcms() {
    uint32_t insn = 0x19007400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfptwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfptwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmtwn_cpy_memcms() {
    uint32_t insn = 0x19407400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfetwn_cpy_memcms() {
    uint32_t insn = 0x19807400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfetwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfetwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpwn_cpy_memcms() {
    uint32_t insn = 0x19004400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmwn_cpy_memcms() {
    uint32_t insn = 0x19404400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfewn_cpy_memcms() {
    uint32_t insn = 0x19804400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfewn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfewn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpwt_cpy_memcms() {
    uint32_t insn = 0x19001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpwt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpwt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmwt_cpy_memcms() {
    uint32_t insn = 0x19401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmwt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmwt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfewt_cpy_memcms() {
    uint32_t insn = 0x19801400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfewt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfewt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpwtn_cpy_memcms() {
    uint32_t insn = 0x1900D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpwtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpwtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmwtn_cpy_memcms() {
    uint32_t insn = 0x1940D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmwtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmwtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfewtn_cpy_memcms() {
    uint32_t insn = 0x1980D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfewtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfewtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpwtrn_cpy_memcms() {
    uint32_t insn = 0x19009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpwtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpwtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmwtrn_cpy_memcms() {
    uint32_t insn = 0x19409400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmwtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmwtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfewtrn_cpy_memcms() {
    uint32_t insn = 0x19809400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfewtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfewtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfpwtwn_cpy_memcms() {
    uint32_t insn = 0x19005400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfpwtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfpwtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfmwtwn_cpy_memcms() {
    uint32_t insn = 0x19405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfmwtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfmwtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyfewtwn_cpy_memcms() {
    uint32_t insn = 0x19805400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyfewtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyfewtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyp_cpy_memcms() {
    uint32_t insn = 0x1D000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyp_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyp_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpym_cpy_memcms() {
    uint32_t insn = 0x1D400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpym_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpym_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpye_cpy_memcms() {
    uint32_t insn = 0x1D800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpye_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpye_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypn_cpy_memcms() {
    uint32_t insn = 0x1D00C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymn_cpy_memcms() {
    uint32_t insn = 0x1D40C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyen_cpy_memcms() {
    uint32_t insn = 0x1D80C400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyen_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyen_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyprn_cpy_memcms() {
    uint32_t insn = 0x1D008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyprn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyprn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymrn_cpy_memcms() {
    uint32_t insn = 0x1D408400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyern_cpy_memcms() {
    uint32_t insn = 0x1D808400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyern_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyern_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyprt_cpy_memcms() {
    uint32_t insn = 0x1D002400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyprt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyprt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymrt_cpy_memcms() {
    uint32_t insn = 0x1D402400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymrt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymrt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyert_cpy_memcms() {
    uint32_t insn = 0x1D802400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyert_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyert_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyprtn_cpy_memcms() {
    uint32_t insn = 0x1D00E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyprtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyprtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymrtn_cpy_memcms() {
    uint32_t insn = 0x1D40E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymrtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymrtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyertn_cpy_memcms() {
    uint32_t insn = 0x1D80E400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyertn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyertn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyprtrn_cpy_memcms() {
    uint32_t insn = 0x1D00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyprtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyprtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymrtrn_cpy_memcms() {
    uint32_t insn = 0x1D40A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymrtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymrtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyertrn_cpy_memcms() {
    uint32_t insn = 0x1D80A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyertrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyertrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyprtwn_cpy_memcms() {
    uint32_t insn = 0x1D006400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyprtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyprtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymrtwn_cpy_memcms() {
    uint32_t insn = 0x1D406400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymrtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymrtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyertwn_cpy_memcms() {
    uint32_t insn = 0x1D806400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyertwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyertwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypt_cpy_memcms() {
    uint32_t insn = 0x1D003400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymt_cpy_memcms() {
    uint32_t insn = 0x1D403400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyet_cpy_memcms() {
    uint32_t insn = 0x1D803400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyet_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyet_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyptn_cpy_memcms() {
    uint32_t insn = 0x1D00F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyptn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyptn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymtn_cpy_memcms() {
    uint32_t insn = 0x1D40F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyetn_cpy_memcms() {
    uint32_t insn = 0x1D80F400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyetn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyetn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyptrn_cpy_memcms() {
    uint32_t insn = 0x1D00B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyptrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyptrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymtrn_cpy_memcms() {
    uint32_t insn = 0x1D40B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyetrn_cpy_memcms() {
    uint32_t insn = 0x1D80B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyetrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyetrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyptwn_cpy_memcms() {
    uint32_t insn = 0x1D007400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyptwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyptwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymtwn_cpy_memcms() {
    uint32_t insn = 0x1D407400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyetwn_cpy_memcms() {
    uint32_t insn = 0x1D807400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyetwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyetwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypwn_cpy_memcms() {
    uint32_t insn = 0x1D004400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymwn_cpy_memcms() {
    uint32_t insn = 0x1D404400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyewn_cpy_memcms() {
    uint32_t insn = 0x1D804400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyewn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyewn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypwt_cpy_memcms() {
    uint32_t insn = 0x1D001400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypwt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypwt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymwt_cpy_memcms() {
    uint32_t insn = 0x1D401400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymwt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymwt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyewt_cpy_memcms() {
    uint32_t insn = 0x1D801400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyewt_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyewt_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypwtn_cpy_memcms() {
    uint32_t insn = 0x1D00D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypwtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypwtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymwtn_cpy_memcms() {
    uint32_t insn = 0x1D40D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymwtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymwtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyewtn_cpy_memcms() {
    uint32_t insn = 0x1D80D400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyewtn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyewtn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypwtrn_cpy_memcms() {
    uint32_t insn = 0x1D009400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypwtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypwtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymwtrn_cpy_memcms() {
    uint32_t insn = 0x1D409400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymwtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymwtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyewtrn_cpy_memcms() {
    uint32_t insn = 0x1D809400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyewtrn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyewtrn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpypwtwn_cpy_memcms() {
    uint32_t insn = 0x1D005400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpypwtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpypwtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpymwtwn_cpy_memcms() {
    uint32_t insn = 0x1D405400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpymwtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpymwtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_cpyewtwn_cpy_memcms() {
    uint32_t insn = 0x1D805400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: cpyewtwn_cpy_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    std::cout << "  cpyewtwn_cpy_memcms: " << result->to_string() << std::endl;
}

void test_gcsstr_64_ldst_gcs() {
    uint32_t insn = 0xD91F0C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: gcsstr_64_ldst_gcs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::GCSSTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  gcsstr_64_ldst_gcs: " << result->to_string() << std::endl;
}

void test_gcssttr_64_ldst_gcs() {
    uint32_t insn = 0xD91F1C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: gcssttr_64_ldst_gcs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::GCSSTTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  gcssttr_64_ldst_gcs: " << result->to_string() << std::endl;
}

void test_ld1_asisdlse_r1_1v() {
    uint32_t insn = 0x0C407000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlse_r1_1v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlse_r1_1v: " << result->to_string() << std::endl;
}

void test_ld1_asisdlse_r2_2v() {
    uint32_t insn = 0x0C40A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlse_r2_2v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlse_r2_2v: " << result->to_string() << std::endl;
}

void test_ld1_asisdlse_r3_3v() {
    uint32_t insn = 0x0C406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlse_r3_3v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlse_r3_3v: " << result->to_string() << std::endl;
}

void test_ld1_asisdlse_r4_4v() {
    uint32_t insn = 0x0C402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlse_r4_4v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlse_r4_4v: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_i1_i1() {
    uint32_t insn = 0x0CDF7000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_i1_i1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    std::cout << "  ld1_asisdlsep_i1_i1: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_r1_r1() {
    uint32_t insn = 0x0CC07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_r1_r1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsep_r1_r1: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_i2_i2() {
    uint32_t insn = 0x0CDFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_i2_i2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    std::cout << "  ld1_asisdlsep_i2_i2: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_r2_r2() {
    uint32_t insn = 0x0CC0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_r2_r2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsep_r2_r2: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_i3_i3() {
    uint32_t insn = 0x0CDF6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_i3_i3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    std::cout << "  ld1_asisdlsep_i3_i3: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_r3_r3() {
    uint32_t insn = 0x0CC06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_r3_r3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsep_r3_r3: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_i4_i4() {
    uint32_t insn = 0x0CDF2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_i4_i4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    std::cout << "  ld1_asisdlsep_i4_i4: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsep_r4_r4() {
    uint32_t insn = 0x0CC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsep_r4_r4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsep_r4_r4: " << result->to_string() << std::endl;
}

void test_ld1_asisdlso_b1_1b() {
    uint32_t insn = 0x0D400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlso_b1_1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlso_b1_1b: " << result->to_string() << std::endl;
}

void test_ld1_asisdlso_h1_1h() {
    uint32_t insn = 0x0D404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlso_h1_1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlso_h1_1h: " << result->to_string() << std::endl;
}

void test_ld1_asisdlso_s1_1s() {
    uint32_t insn = 0x0D408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlso_s1_1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlso_s1_1s: " << result->to_string() << std::endl;
}

void test_ld1_asisdlso_d1_1d() {
    uint32_t insn = 0x0D408400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlso_d1_1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlso_d1_1d: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_b1_i1b() {
    uint32_t insn = 0x0DDF0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_b1_i1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlsop_b1_i1b: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_bx1_r1b() {
    uint32_t insn = 0x0DC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_bx1_r1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsop_bx1_r1b: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_d1_i1d() {
    uint32_t insn = 0x0DDF8400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_d1_i1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlsop_d1_i1d: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_dx1_r1d() {
    uint32_t insn = 0x0DC08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_dx1_r1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsop_dx1_r1d: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_h1_i1h() {
    uint32_t insn = 0x0DDF4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_h1_i1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlsop_h1_i1h: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_hx1_r1h() {
    uint32_t insn = 0x0DC04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_hx1_r1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsop_hx1_r1h: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_s1_i1s() {
    uint32_t insn = 0x0DDF8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_s1_i1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1_asisdlsop_s1_i1s: " << result->to_string() << std::endl;
}

void test_ld1_asisdlsop_sx1_r1s() {
    uint32_t insn = 0x0DC08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1_asisdlsop_sx1_r1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1_asisdlsop_sx1_r1s: " << result->to_string() << std::endl;
}

void test_ld1r_asisdlso_r1() {
    uint32_t insn = 0x0D40C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1r_asisdlso_r1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1R);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld1r_asisdlso_r1: " << result->to_string() << std::endl;
}

void test_ld1r_asisdlsop_r1_i() {
    uint32_t insn = 0x0DDFC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1r_asisdlsop_r1_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1R);
    std::cout << "  ld1r_asisdlsop_r1_i: " << result->to_string() << std::endl;
}

void test_ld1r_asisdlsop_rx1_r() {
    uint32_t insn = 0x0DC0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld1r_asisdlsop_rx1_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD1R);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld1r_asisdlsop_rx1_r: " << result->to_string() << std::endl;
}

void test_ld2_asisdlse_r2() {
    uint32_t insn = 0x0C408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlse_r2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlse_r2: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsep_i2_i() {
    uint32_t insn = 0x0CDF8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsep_i2_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    std::cout << "  ld2_asisdlsep_i2_i: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsep_r2_r() {
    uint32_t insn = 0x0CC08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsep_r2_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2_asisdlsep_r2_r: " << result->to_string() << std::endl;
}

void test_ld2_asisdlso_b2_2b() {
    uint32_t insn = 0x0D600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlso_b2_2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlso_b2_2b: " << result->to_string() << std::endl;
}

void test_ld2_asisdlso_h2_2h() {
    uint32_t insn = 0x0D604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlso_h2_2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlso_h2_2h: " << result->to_string() << std::endl;
}

void test_ld2_asisdlso_s2_2s() {
    uint32_t insn = 0x0D608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlso_s2_2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlso_s2_2s: " << result->to_string() << std::endl;
}

void test_ld2_asisdlso_d2_2d() {
    uint32_t insn = 0x0D608400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlso_d2_2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlso_d2_2d: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_b2_i2b() {
    uint32_t insn = 0x0DFF0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_b2_i2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlsop_b2_i2b: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_bx2_r2b() {
    uint32_t insn = 0x0DE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_bx2_r2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2_asisdlsop_bx2_r2b: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_h2_i2h() {
    uint32_t insn = 0x0DFF4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_h2_i2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlsop_h2_i2h: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_hx2_r2h() {
    uint32_t insn = 0x0DE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_hx2_r2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2_asisdlsop_hx2_r2h: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_s2_i2s() {
    uint32_t insn = 0x0DFF8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_s2_i2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlsop_s2_i2s: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_sx2_r2s() {
    uint32_t insn = 0x0DE08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_sx2_r2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2_asisdlsop_sx2_r2s: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_d2_i2d() {
    uint32_t insn = 0x0DFF8400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_d2_i2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2_asisdlsop_d2_i2d: " << result->to_string() << std::endl;
}

void test_ld2_asisdlsop_dx2_r2d() {
    uint32_t insn = 0x0DE08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2_asisdlsop_dx2_r2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2_asisdlsop_dx2_r2d: " << result->to_string() << std::endl;
}

void test_ld2r_asisdlso_r2() {
    uint32_t insn = 0x0D60C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2r_asisdlso_r2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2R);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld2r_asisdlso_r2: " << result->to_string() << std::endl;
}

void test_ld2r_asisdlsop_r2_i() {
    uint32_t insn = 0x0DFFC000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2r_asisdlsop_r2_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2R);
    std::cout << "  ld2r_asisdlsop_r2_i: " << result->to_string() << std::endl;
}

void test_ld2r_asisdlsop_rx2_r() {
    uint32_t insn = 0x0DE0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld2r_asisdlsop_rx2_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD2R);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld2r_asisdlsop_rx2_r: " << result->to_string() << std::endl;
}

void test_ld3_asisdlse_r3() {
    uint32_t insn = 0x0C404000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlse_r3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlse_r3: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsep_i3_i() {
    uint32_t insn = 0x0CDF4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsep_i3_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    std::cout << "  ld3_asisdlsep_i3_i: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsep_r3_r() {
    uint32_t insn = 0x0CC04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsep_r3_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3_asisdlsep_r3_r: " << result->to_string() << std::endl;
}

void test_ld3_asisdlso_b3_3b() {
    uint32_t insn = 0x0D402000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlso_b3_3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlso_b3_3b: " << result->to_string() << std::endl;
}

void test_ld3_asisdlso_h3_3h() {
    uint32_t insn = 0x0D406000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlso_h3_3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlso_h3_3h: " << result->to_string() << std::endl;
}

void test_ld3_asisdlso_s3_3s() {
    uint32_t insn = 0x0D40A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlso_s3_3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlso_s3_3s: " << result->to_string() << std::endl;
}

void test_ld3_asisdlso_d3_3d() {
    uint32_t insn = 0x0D40A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlso_d3_3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlso_d3_3d: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_b3_i3b() {
    uint32_t insn = 0x0DDF2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_b3_i3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlsop_b3_i3b: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_bx3_r3b() {
    uint32_t insn = 0x0DC02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_bx3_r3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3_asisdlsop_bx3_r3b: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_h3_i3h() {
    uint32_t insn = 0x0DDF6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_h3_i3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlsop_h3_i3h: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_hx3_r3h() {
    uint32_t insn = 0x0DC06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_hx3_r3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3_asisdlsop_hx3_r3h: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_s3_i3s() {
    uint32_t insn = 0x0DDFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_s3_i3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlsop_s3_i3s: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_sx3_r3s() {
    uint32_t insn = 0x0DC0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_sx3_r3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3_asisdlsop_sx3_r3s: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_d3_i3d() {
    uint32_t insn = 0x0DDFA400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_d3_i3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3_asisdlsop_d3_i3d: " << result->to_string() << std::endl;
}

void test_ld3_asisdlsop_dx3_r3d() {
    uint32_t insn = 0x0DC0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3_asisdlsop_dx3_r3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3_asisdlsop_dx3_r3d: " << result->to_string() << std::endl;
}

void test_ld3r_asisdlso_r3() {
    uint32_t insn = 0x0D40E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3r_asisdlso_r3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3R);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld3r_asisdlso_r3: " << result->to_string() << std::endl;
}

void test_ld3r_asisdlsop_r3_i() {
    uint32_t insn = 0x0DDFE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3r_asisdlsop_r3_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3R);
    std::cout << "  ld3r_asisdlsop_r3_i: " << result->to_string() << std::endl;
}

void test_ld3r_asisdlsop_rx3_r() {
    uint32_t insn = 0x0DC0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld3r_asisdlsop_rx3_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD3R);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld3r_asisdlsop_rx3_r: " << result->to_string() << std::endl;
}

void test_ld4_asisdlse_r4() {
    uint32_t insn = 0x0C400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlse_r4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlse_r4: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsep_i4_i() {
    uint32_t insn = 0x0CDF0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsep_i4_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    std::cout << "  ld4_asisdlsep_i4_i: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsep_r4_r() {
    uint32_t insn = 0x0CC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsep_r4_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4_asisdlsep_r4_r: " << result->to_string() << std::endl;
}

void test_ld4_asisdlso_b4_4b() {
    uint32_t insn = 0x0D602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlso_b4_4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlso_b4_4b: " << result->to_string() << std::endl;
}

void test_ld4_asisdlso_h4_4h() {
    uint32_t insn = 0x0D606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlso_h4_4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlso_h4_4h: " << result->to_string() << std::endl;
}

void test_ld4_asisdlso_s4_4s() {
    uint32_t insn = 0x0D60A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlso_s4_4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlso_s4_4s: " << result->to_string() << std::endl;
}

void test_ld4_asisdlso_d4_4d() {
    uint32_t insn = 0x0D60A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlso_d4_4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlso_d4_4d: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_b4_i4b() {
    uint32_t insn = 0x0DFF2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_b4_i4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlsop_b4_i4b: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_bx4_r4b() {
    uint32_t insn = 0x0DE02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_bx4_r4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4_asisdlsop_bx4_r4b: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_h4_i4h() {
    uint32_t insn = 0x0DFF6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_h4_i4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlsop_h4_i4h: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_hx4_r4h() {
    uint32_t insn = 0x0DE06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_hx4_r4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4_asisdlsop_hx4_r4h: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_s4_i4s() {
    uint32_t insn = 0x0DFFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_s4_i4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlsop_s4_i4s: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_sx4_r4s() {
    uint32_t insn = 0x0DE0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_sx4_r4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4_asisdlsop_sx4_r4s: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_d4_i4d() {
    uint32_t insn = 0x0DFFA400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_d4_i4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4_asisdlsop_d4_i4d: " << result->to_string() << std::endl;
}

void test_ld4_asisdlsop_dx4_r4d() {
    uint32_t insn = 0x0DE0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4_asisdlsop_dx4_r4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4_asisdlsop_dx4_r4d: " << result->to_string() << std::endl;
}

void test_ld4r_asisdlso_r4() {
    uint32_t insn = 0x0D60E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4r_asisdlso_r4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4R);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld4r_asisdlso_r4: " << result->to_string() << std::endl;
}

void test_ld4r_asisdlsop_r4_i() {
    uint32_t insn = 0x0DFFE000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4r_asisdlsop_r4_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4R);
    std::cout << "  ld4r_asisdlsop_r4_i: " << result->to_string() << std::endl;
}

void test_ld4r_asisdlsop_rx4_r() {
    uint32_t insn = 0x0DE0E000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld4r_asisdlsop_rx4_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD4R);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  ld4r_asisdlsop_rx4_r: " << result->to_string() << std::endl;
}

void test_ld64b_64l_memop() {
    uint32_t insn = 0xF83FD000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ld64b_64l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LD64B);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ld64b_64l_memop: " << result->to_string() << std::endl;
}

void test_ldadd_32_memop() {
    uint32_t insn = 0xB8200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldadd_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldadd_32_memop: " << result->to_string() << std::endl;
}

void test_ldadda_32_memop() {
    uint32_t insn = 0xB8A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldadda_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldadda_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddal_32_memop() {
    uint32_t insn = 0xB8E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddal_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddl_32_memop() {
    uint32_t insn = 0xB8600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddl_32_memop: " << result->to_string() << std::endl;
}

void test_ldadd_64_memop() {
    uint32_t insn = 0xF8200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldadd_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldadd_64_memop: " << result->to_string() << std::endl;
}

void test_ldadda_64_memop() {
    uint32_t insn = 0xF8A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldadda_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldadda_64_memop: " << result->to_string() << std::endl;
}

void test_ldaddal_64_memop() {
    uint32_t insn = 0xF8E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddal_64_memop: " << result->to_string() << std::endl;
}

void test_ldaddl_64_memop() {
    uint32_t insn = 0xF8600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddl_64_memop: " << result->to_string() << std::endl;
}

void test_ldaddb_32_memop() {
    uint32_t insn = 0x38200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddb_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddab_32_memop() {
    uint32_t insn = 0x38A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddab_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddalb_32_memop() {
    uint32_t insn = 0x38E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddalb_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddlb_32_memop() {
    uint32_t insn = 0x38600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddh_32_memop() {
    uint32_t insn = 0x78200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddh_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddah_32_memop() {
    uint32_t insn = 0x78A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddah_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddalh_32_memop() {
    uint32_t insn = 0x78E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddalh_32_memop: " << result->to_string() << std::endl;
}

void test_ldaddlh_32_memop() {
    uint32_t insn = 0x78600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaddlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaddlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldap1_asisdlso_d1() {
    uint32_t insn = 0x0D418400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldap1_asisdlso_d1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAP1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldap1_asisdlso_d1: " << result->to_string() << std::endl;
}

void test_ldap_64_ldiappstilp() {
    uint32_t insn = 0xD9405800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldap_64_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldap_64_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldapp_64_ldiappstilp() {
    uint32_t insn = 0xD9407800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapp_64_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldapp_64_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldapr_32l_ldapstl_writeback() {
    uint32_t insn = 0x99C00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapr_32l_ldapstl_writeback" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapr_32l_ldapstl_writeback: " << result->to_string() << std::endl;
}

void test_ldapr_64l_ldapstl_writeback() {
    uint32_t insn = 0xD9C00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapr_64l_ldapstl_writeback" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapr_64l_ldapstl_writeback: " << result->to_string() << std::endl;
}

void test_ldapr_32l_memop() {
    uint32_t insn = 0xB8A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapr_32l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapr_32l_memop: " << result->to_string() << std::endl;
}

void test_ldapr_64l_memop() {
    uint32_t insn = 0xF8A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapr_64l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapr_64l_memop: " << result->to_string() << std::endl;
}

void test_ldaprb_32l_memop() {
    uint32_t insn = 0x38A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaprb_32l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaprb_32l_memop: " << result->to_string() << std::endl;
}

void test_ldaprh_32l_memop() {
    uint32_t insn = 0x78A0C000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaprh_32l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaprh_32l_memop: " << result->to_string() << std::endl;
}

void test_ldapur_b_ldapstl_simd() {
    uint32_t insn = 0x1D400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_b_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapur_b_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldapur_h_ldapstl_simd() {
    uint32_t insn = 0x5D400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_h_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    std::cout << "  ldapur_h_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldapur_s_ldapstl_simd() {
    uint32_t insn = 0x9D400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_s_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    std::cout << "  ldapur_s_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldapur_d_ldapstl_simd() {
    uint32_t insn = 0xDD400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_d_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    std::cout << "  ldapur_d_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldapur_q_ldapstl_simd() {
    uint32_t insn = 0x1DC00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_q_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    std::cout << "  ldapur_q_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldapur_32_ldapstl_unscaled() {
    uint32_t insn = 0x99400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapur_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapur_64_ldapstl_unscaled() {
    uint32_t insn = 0xD9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapur_64_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapur_64_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapurb_32_ldapstl_unscaled() {
    uint32_t insn = 0x19400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapurb_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapurb_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapurh_32_ldapstl_unscaled() {
    uint32_t insn = 0x59400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapurh_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapurh_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapursb_32_ldapstl_unscaled() {
    uint32_t insn = 0x19C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapursb_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapursb_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapursb_64_ldapstl_unscaled() {
    uint32_t insn = 0x19800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapursb_64_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapursb_64_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapursh_32_ldapstl_unscaled() {
    uint32_t insn = 0x59C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapursh_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapursh_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapursh_64_ldapstl_unscaled() {
    uint32_t insn = 0x59800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapursh_64_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapursh_64_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldapursw_64_ldapstl_unscaled() {
    uint32_t insn = 0x99800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldapursw_64_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAPURSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldapursw_64_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_ldar_lr32_ldstord() {
    uint32_t insn = 0x88C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldar_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldar_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldar_lr64_ldstord() {
    uint32_t insn = 0xC8C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldar_lr64_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldar_lr64_ldstord: " << result->to_string() << std::endl;
}

void test_ldarb_lr32_ldstord() {
    uint32_t insn = 0x08C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldarb_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDARB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldarb_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldarh_lr32_ldstord() {
    uint32_t insn = 0x48C08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldarh_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDARH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldarh_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldatxr_lr32_ldstexclr_unpriv() {
    uint32_t insn = 0x89408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldatxr_lr32_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDATXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldatxr_lr32_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_ldatxr_lr64_ldstexclr_unpriv() {
    uint32_t insn = 0xC9408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldatxr_lr64_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDATXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldatxr_lr64_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_ldaxp_lp32_ldstexclp() {
    uint32_t insn = 0x88608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxp_lp32_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaxp_lp32_ldstexclp: " << result->to_string() << std::endl;
}

void test_ldaxp_lp64_ldstexclp() {
    uint32_t insn = 0xC8608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxp_lp64_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldaxp_lp64_ldstexclp: " << result->to_string() << std::endl;
}

void test_ldaxr_lr32_ldstexclr() {
    uint32_t insn = 0x88408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxr_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaxr_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldaxr_lr64_ldstexclr() {
    uint32_t insn = 0xC8408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxr_lr64_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaxr_lr64_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldaxrb_lr32_ldstexclr() {
    uint32_t insn = 0x08408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxrb_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaxrb_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldaxrh_lr32_ldstexclr() {
    uint32_t insn = 0x48408000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldaxrh_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDAXRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldaxrh_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldbfadd_16() {
    uint32_t insn = 0x3C200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfadd_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfadd_16: " << result->to_string() << std::endl;
}

void test_ldbfadda_16() {
    uint32_t insn = 0x3CA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfadda_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfadda_16: " << result->to_string() << std::endl;
}

void test_ldbfaddal_16() {
    uint32_t insn = 0x3CE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfaddal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfaddal_16: " << result->to_string() << std::endl;
}

void test_ldbfaddl_16() {
    uint32_t insn = 0x3C600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfaddl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfaddl_16: " << result->to_string() << std::endl;
}

void test_ldbfmax_16() {
    uint32_t insn = 0x3C204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmax_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmax_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxa_16() {
    uint32_t insn = 0x3CA04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxa_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxa_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxal_16() {
    uint32_t insn = 0x3CE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxal_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxl_16() {
    uint32_t insn = 0x3C604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxl_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxnm_16() {
    uint32_t insn = 0x3C206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxnm_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxnma_16() {
    uint32_t insn = 0x3CA06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxnma_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxnma_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxnmal_16() {
    uint32_t insn = 0x3CE06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxnmal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxnmal_16: " << result->to_string() << std::endl;
}

void test_ldbfmaxnml_16() {
    uint32_t insn = 0x3C606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmaxnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmaxnml_16: " << result->to_string() << std::endl;
}

void test_ldbfmin_16() {
    uint32_t insn = 0x3C205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmin_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmin_16: " << result->to_string() << std::endl;
}

void test_ldbfmina_16() {
    uint32_t insn = 0x3CA05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfmina_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfmina_16: " << result->to_string() << std::endl;
}

void test_ldbfminal_16() {
    uint32_t insn = 0x3CE05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminal_16: " << result->to_string() << std::endl;
}

void test_ldbfminl_16() {
    uint32_t insn = 0x3C605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminl_16: " << result->to_string() << std::endl;
}

void test_ldbfminnm_16() {
    uint32_t insn = 0x3C207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminnm_16: " << result->to_string() << std::endl;
}

void test_ldbfminnma_16() {
    uint32_t insn = 0x3CA07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminnma_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminnma_16: " << result->to_string() << std::endl;
}

void test_ldbfminnmal_16() {
    uint32_t insn = 0x3CE07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminnmal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminnmal_16: " << result->to_string() << std::endl;
}

void test_ldbfminnml_16() {
    uint32_t insn = 0x3C607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldbfminnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldbfminnml_16: " << result->to_string() << std::endl;
}

void test_ldclr_32_memop() {
    uint32_t insn = 0xB8201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclr_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclr_32_memop: " << result->to_string() << std::endl;
}

void test_ldclra_32_memop() {
    uint32_t insn = 0xB8A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclra_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclra_32_memop: " << result->to_string() << std::endl;
}

void test_ldclral_32_memop() {
    uint32_t insn = 0xB8E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclral_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclral_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrl_32_memop() {
    uint32_t insn = 0xB8601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrl_32_memop: " << result->to_string() << std::endl;
}

void test_ldclr_64_memop() {
    uint32_t insn = 0xF8201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclr_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclr_64_memop: " << result->to_string() << std::endl;
}

void test_ldclra_64_memop() {
    uint32_t insn = 0xF8A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclra_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclra_64_memop: " << result->to_string() << std::endl;
}

void test_ldclral_64_memop() {
    uint32_t insn = 0xF8E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclral_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclral_64_memop: " << result->to_string() << std::endl;
}

void test_ldclrl_64_memop() {
    uint32_t insn = 0xF8601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrl_64_memop: " << result->to_string() << std::endl;
}

void test_ldclrb_32_memop() {
    uint32_t insn = 0x38201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrb_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrab_32_memop() {
    uint32_t insn = 0x38A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrab_32_memop: " << result->to_string() << std::endl;
}

void test_ldclralb_32_memop() {
    uint32_t insn = 0x38E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclralb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclralb_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrlb_32_memop() {
    uint32_t insn = 0x38601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrh_32_memop() {
    uint32_t insn = 0x78201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrh_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrah_32_memop() {
    uint32_t insn = 0x78A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrah_32_memop: " << result->to_string() << std::endl;
}

void test_ldclralh_32_memop() {
    uint32_t insn = 0x78E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclralh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclralh_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrlh_32_memop() {
    uint32_t insn = 0x78601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldclrp_128_memop_128() {
    uint32_t insn = 0x19201000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrp_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldclrpa_128_memop_128() {
    uint32_t insn = 0x19A01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldclrpal_128_memop_128() {
    uint32_t insn = 0x19E01000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldclrpl_128_memop_128() {
    uint32_t insn = 0x19601000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldclrpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldclrpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldeor_32_memop() {
    uint32_t insn = 0xB8202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeor_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeor_32_memop: " << result->to_string() << std::endl;
}

void test_ldeora_32_memop() {
    uint32_t insn = 0xB8A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeora_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeora_32_memop: " << result->to_string() << std::endl;
}

void test_ldeoral_32_memop() {
    uint32_t insn = 0xB8E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeoral_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeoral_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorl_32_memop() {
    uint32_t insn = 0xB8602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorl_32_memop: " << result->to_string() << std::endl;
}

void test_ldeor_64_memop() {
    uint32_t insn = 0xF8202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeor_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeor_64_memop: " << result->to_string() << std::endl;
}

void test_ldeora_64_memop() {
    uint32_t insn = 0xF8A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeora_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeora_64_memop: " << result->to_string() << std::endl;
}

void test_ldeoral_64_memop() {
    uint32_t insn = 0xF8E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeoral_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeoral_64_memop: " << result->to_string() << std::endl;
}

void test_ldeorl_64_memop() {
    uint32_t insn = 0xF8602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorl_64_memop: " << result->to_string() << std::endl;
}

void test_ldeorb_32_memop() {
    uint32_t insn = 0x38202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorb_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorab_32_memop() {
    uint32_t insn = 0x38A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorab_32_memop: " << result->to_string() << std::endl;
}

void test_ldeoralb_32_memop() {
    uint32_t insn = 0x38E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeoralb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeoralb_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorlb_32_memop() {
    uint32_t insn = 0x38602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorh_32_memop() {
    uint32_t insn = 0x78202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorh_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorah_32_memop() {
    uint32_t insn = 0x78A02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorah_32_memop: " << result->to_string() << std::endl;
}

void test_ldeoralh_32_memop() {
    uint32_t insn = 0x78E02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeoralh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeoralh_32_memop: " << result->to_string() << std::endl;
}

void test_ldeorlh_32_memop() {
    uint32_t insn = 0x78602000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldeorlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldeorlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldfadd_16() {
    uint32_t insn = 0x7C200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadd_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadd_16: " << result->to_string() << std::endl;
}

void test_ldfadda_16() {
    uint32_t insn = 0x7CA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadda_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadda_16: " << result->to_string() << std::endl;
}

void test_ldfaddal_16() {
    uint32_t insn = 0x7CE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddal_16: " << result->to_string() << std::endl;
}

void test_ldfaddl_16() {
    uint32_t insn = 0x7C600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddl_16: " << result->to_string() << std::endl;
}

void test_ldfadd_32() {
    uint32_t insn = 0xBC200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadd_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadd_32: " << result->to_string() << std::endl;
}

void test_ldfadda_32() {
    uint32_t insn = 0xBCA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadda_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadda_32: " << result->to_string() << std::endl;
}

void test_ldfaddal_32() {
    uint32_t insn = 0xBCE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddal_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddal_32: " << result->to_string() << std::endl;
}

void test_ldfaddl_32() {
    uint32_t insn = 0xBC600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddl_32: " << result->to_string() << std::endl;
}

void test_ldfadd_64() {
    uint32_t insn = 0xFC200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadd_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadd_64: " << result->to_string() << std::endl;
}

void test_ldfadda_64() {
    uint32_t insn = 0xFCA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfadda_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfadda_64: " << result->to_string() << std::endl;
}

void test_ldfaddal_64() {
    uint32_t insn = 0xFCE00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddal_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddal_64: " << result->to_string() << std::endl;
}

void test_ldfaddl_64() {
    uint32_t insn = 0xFC600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfaddl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfaddl_64: " << result->to_string() << std::endl;
}

void test_ldfmax_16() {
    uint32_t insn = 0x7C204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmax_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmax_16: " << result->to_string() << std::endl;
}

void test_ldfmaxa_16() {
    uint32_t insn = 0x7CA04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxa_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxa_16: " << result->to_string() << std::endl;
}

void test_ldfmaxal_16() {
    uint32_t insn = 0x7CE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxal_16: " << result->to_string() << std::endl;
}

void test_ldfmaxl_16() {
    uint32_t insn = 0x7C604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxl_16: " << result->to_string() << std::endl;
}

void test_ldfmax_32() {
    uint32_t insn = 0xBC204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmax_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmax_32: " << result->to_string() << std::endl;
}

void test_ldfmaxa_32() {
    uint32_t insn = 0xBCA04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxa_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxa_32: " << result->to_string() << std::endl;
}

void test_ldfmaxal_32() {
    uint32_t insn = 0xBCE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxal_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxal_32: " << result->to_string() << std::endl;
}

void test_ldfmaxl_32() {
    uint32_t insn = 0xBC604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxl_32: " << result->to_string() << std::endl;
}

void test_ldfmax_64() {
    uint32_t insn = 0xFC204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmax_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmax_64: " << result->to_string() << std::endl;
}

void test_ldfmaxa_64() {
    uint32_t insn = 0xFCA04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxa_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxa_64: " << result->to_string() << std::endl;
}

void test_ldfmaxal_64() {
    uint32_t insn = 0xFCE04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxal_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxal_64: " << result->to_string() << std::endl;
}

void test_ldfmaxl_64() {
    uint32_t insn = 0xFC604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxl_64: " << result->to_string() << std::endl;
}

void test_ldfmaxnm_16() {
    uint32_t insn = 0x7C206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnm_16: " << result->to_string() << std::endl;
}

void test_ldfmaxnma_16() {
    uint32_t insn = 0x7CA06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnma_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnma_16: " << result->to_string() << std::endl;
}

void test_ldfmaxnmal_16() {
    uint32_t insn = 0x7CE06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnmal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnmal_16: " << result->to_string() << std::endl;
}

void test_ldfmaxnml_16() {
    uint32_t insn = 0x7C606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnml_16: " << result->to_string() << std::endl;
}

void test_ldfmaxnm_32() {
    uint32_t insn = 0xBC206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnm_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnm_32: " << result->to_string() << std::endl;
}

void test_ldfmaxnma_32() {
    uint32_t insn = 0xBCA06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnma_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnma_32: " << result->to_string() << std::endl;
}

void test_ldfmaxnmal_32() {
    uint32_t insn = 0xBCE06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnmal_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnmal_32: " << result->to_string() << std::endl;
}

void test_ldfmaxnml_32() {
    uint32_t insn = 0xBC606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnml_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnml_32: " << result->to_string() << std::endl;
}

void test_ldfmaxnm_64() {
    uint32_t insn = 0xFC206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnm_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnm_64: " << result->to_string() << std::endl;
}

void test_ldfmaxnma_64() {
    uint32_t insn = 0xFCA06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnma_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnma_64: " << result->to_string() << std::endl;
}

void test_ldfmaxnmal_64() {
    uint32_t insn = 0xFCE06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnmal_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnmal_64: " << result->to_string() << std::endl;
}

void test_ldfmaxnml_64() {
    uint32_t insn = 0xFC606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmaxnml_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmaxnml_64: " << result->to_string() << std::endl;
}

void test_ldfmin_16() {
    uint32_t insn = 0x7C205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmin_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmin_16: " << result->to_string() << std::endl;
}

void test_ldfmina_16() {
    uint32_t insn = 0x7CA05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmina_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmina_16: " << result->to_string() << std::endl;
}

void test_ldfminal_16() {
    uint32_t insn = 0x7CE05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminal_16: " << result->to_string() << std::endl;
}

void test_ldfminl_16() {
    uint32_t insn = 0x7C605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminl_16: " << result->to_string() << std::endl;
}

void test_ldfmin_32() {
    uint32_t insn = 0xBC205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmin_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmin_32: " << result->to_string() << std::endl;
}

void test_ldfmina_32() {
    uint32_t insn = 0xBCA05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmina_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmina_32: " << result->to_string() << std::endl;
}

void test_ldfminal_32() {
    uint32_t insn = 0xBCE05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminal_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminal_32: " << result->to_string() << std::endl;
}

void test_ldfminl_32() {
    uint32_t insn = 0xBC605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminl_32: " << result->to_string() << std::endl;
}

void test_ldfmin_64() {
    uint32_t insn = 0xFC205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmin_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmin_64: " << result->to_string() << std::endl;
}

void test_ldfmina_64() {
    uint32_t insn = 0xFCA05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfmina_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfmina_64: " << result->to_string() << std::endl;
}

void test_ldfminal_64() {
    uint32_t insn = 0xFCE05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminal_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminal_64: " << result->to_string() << std::endl;
}

void test_ldfminl_64() {
    uint32_t insn = 0xFC605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminl_64: " << result->to_string() << std::endl;
}

void test_ldfminnm_16() {
    uint32_t insn = 0x7C207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnm_16: " << result->to_string() << std::endl;
}

void test_ldfminnma_16() {
    uint32_t insn = 0x7CA07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnma_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnma_16: " << result->to_string() << std::endl;
}

void test_ldfminnmal_16() {
    uint32_t insn = 0x7CE07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnmal_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnmal_16: " << result->to_string() << std::endl;
}

void test_ldfminnml_16() {
    uint32_t insn = 0x7C607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnml_16: " << result->to_string() << std::endl;
}

void test_ldfminnm_32() {
    uint32_t insn = 0xBC207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnm_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnm_32: " << result->to_string() << std::endl;
}

void test_ldfminnma_32() {
    uint32_t insn = 0xBCA07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnma_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnma_32: " << result->to_string() << std::endl;
}

void test_ldfminnmal_32() {
    uint32_t insn = 0xBCE07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnmal_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnmal_32: " << result->to_string() << std::endl;
}

void test_ldfminnml_32() {
    uint32_t insn = 0xBC607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnml_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnml_32: " << result->to_string() << std::endl;
}

void test_ldfminnm_64() {
    uint32_t insn = 0xFC207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnm_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnm_64: " << result->to_string() << std::endl;
}

void test_ldfminnma_64() {
    uint32_t insn = 0xFCA07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnma_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnma_64: " << result->to_string() << std::endl;
}

void test_ldfminnmal_64() {
    uint32_t insn = 0xFCE07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnmal_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnmal_64: " << result->to_string() << std::endl;
}

void test_ldfminnml_64() {
    uint32_t insn = 0xFC607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldfminnml_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  ldfminnml_64: " << result->to_string() << std::endl;
}

void test_ldg_64loffset_ldsttags() {
    uint32_t insn = 0xD9600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldg_64loffset_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldg_64loffset_ldsttags: " << result->to_string() << std::endl;
}

void test_ldgm_64bulk_ldsttags() {
    uint32_t insn = 0xD9E00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldgm_64bulk_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDGM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldgm_64bulk_ldsttags: " << result->to_string() << std::endl;
}

void test_ldiapp_32le_ldiappstilp() {
    uint32_t insn = 0x99400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldiapp_32le_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDIAPP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldiapp_32le_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldiapp_32l_ldiappstilp() {
    uint32_t insn = 0x99401800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldiapp_32l_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDIAPP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldiapp_32l_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldiapp_64ls_ldiappstilp() {
    uint32_t insn = 0xD9400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldiapp_64ls_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDIAPP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldiapp_64ls_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldiapp_64l_ldiappstilp() {
    uint32_t insn = 0xD9401800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldiapp_64l_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDIAPP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldiapp_64l_ldiappstilp: " << result->to_string() << std::endl;
}

void test_ldlar_lr32_ldstord() {
    uint32_t insn = 0x88C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldlar_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDLAR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldlar_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldlar_lr64_ldstord() {
    uint32_t insn = 0xC8C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldlar_lr64_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDLAR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldlar_lr64_ldstord: " << result->to_string() << std::endl;
}

void test_ldlarb_lr32_ldstord() {
    uint32_t insn = 0x08C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldlarb_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDLARB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldlarb_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldlarh_lr32_ldstord() {
    uint32_t insn = 0x48C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldlarh_lr32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDLARH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldlarh_lr32_ldstord: " << result->to_string() << std::endl;
}

void test_ldnp_s_ldstnapair_offs() {
    uint32_t insn = 0x2C400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnp_s_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNP);
    std::cout << "  ldnp_s_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldnp_d_ldstnapair_offs() {
    uint32_t insn = 0x6C400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnp_d_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNP);
    std::cout << "  ldnp_d_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldnp_q_ldstnapair_offs() {
    uint32_t insn = 0xAC400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnp_q_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNP);
    std::cout << "  ldnp_q_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldnp_32_ldstnapair_offs() {
    uint32_t insn = 0x28400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnp_32_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldnp_32_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldnp_64_ldstnapair_offs() {
    uint32_t insn = 0xA8400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldnp_64_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldnp_64_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldp_s_ldstpair_post() {
    uint32_t insn = 0x2CC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_s_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_s_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldp_d_ldstpair_post() {
    uint32_t insn = 0x6CC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_d_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_d_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldp_q_ldstpair_post() {
    uint32_t insn = 0xACC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_q_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_q_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldp_s_ldstpair_pre() {
    uint32_t insn = 0x2DC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_s_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_s_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldp_d_ldstpair_pre() {
    uint32_t insn = 0x6DC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_d_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_d_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldp_q_ldstpair_pre() {
    uint32_t insn = 0xADC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_q_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_q_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldp_s_ldstpair_off() {
    uint32_t insn = 0x2D400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_s_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_s_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldp_d_ldstpair_off() {
    uint32_t insn = 0x6D400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_d_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_d_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldp_q_ldstpair_off() {
    uint32_t insn = 0xAD400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_q_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_q_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldp_32_ldstpair_post() {
    uint32_t insn = 0x28C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_32_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_32_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldp_64_ldstpair_post() {
    uint32_t insn = 0xA8C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    std::cout << "  ldp_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldp_32_ldstpair_pre() {
    uint32_t insn = 0x29C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_32_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldp_32_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldp_64_ldstpair_pre() {
    uint32_t insn = 0xA9C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldp_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldp_32_ldstpair_off() {
    uint32_t insn = 0x29400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_32_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldp_32_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldp_64_ldstpair_off() {
    uint32_t insn = 0xA9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldp_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldp_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldpsw_64_ldstpair_post() {
    uint32_t insn = 0x68C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldpsw_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDPSW);
    std::cout << "  ldpsw_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldpsw_64_ldstpair_pre() {
    uint32_t insn = 0x69C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldpsw_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDPSW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldpsw_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldpsw_64_ldstpair_off() {
    uint32_t insn = 0x69400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldpsw_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDPSW);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldpsw_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_immpost() {
    uint32_t insn = 0x3C400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_b_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_b_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_h_ldst_immpost() {
    uint32_t insn = 0x7C400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_h_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_h_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_s_ldst_immpost() {
    uint32_t insn = 0xBC400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_s_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_s_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_d_ldst_immpost() {
    uint32_t insn = 0xFC400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_d_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_d_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_q_ldst_immpost() {
    uint32_t insn = 0x3CC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_q_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_q_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_immpre() {
    uint32_t insn = 0x3C400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_b_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_b_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_h_ldst_immpre() {
    uint32_t insn = 0x7C400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_h_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_h_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_s_ldst_immpre() {
    uint32_t insn = 0xBC400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_s_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_s_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_d_ldst_immpre() {
    uint32_t insn = 0xFC400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_d_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_d_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_q_ldst_immpre() {
    uint32_t insn = 0x3CC00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_q_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_q_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_pos() {
    uint32_t insn = 0x3D400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_b_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_b_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_h_ldst_pos() {
    uint32_t insn = 0x7D400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_h_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_h_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_s_ldst_pos() {
    uint32_t insn = 0xBD400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_s_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_s_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_d_ldst_pos() {
    uint32_t insn = 0xFD400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_d_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_d_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_q_ldst_pos() {
    uint32_t insn = 0x3DC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_q_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_q_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_32_ldst_immpost() {
    uint32_t insn = 0xB8400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_64_ldst_immpost() {
    uint32_t insn = 0xF8400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_64_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_64_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_32_ldst_immpre() {
    uint32_t insn = 0xB8400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_64_ldst_immpre() {
    uint32_t insn = 0xF8400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_64_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_64_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldr_32_ldst_pos() {
    uint32_t insn = 0xB9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_64_ldst_pos() {
    uint32_t insn = 0xF9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_64_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldr_64_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldr_s_loadlit() {
    uint32_t insn = 0x1C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_s_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_s_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_d_loadlit() {
    uint32_t insn = 0x5C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_d_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_d_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_q_loadlit() {
    uint32_t insn = 0x9C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_q_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_q_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_32_loadlit() {
    uint32_t insn = 0x18000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_32_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_32_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_64_loadlit() {
    uint32_t insn = 0x58000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_64_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_64_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_regoff() {
    uint32_t insn = 0x3C604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldr_b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_bl_ldst_regoff() {
    uint32_t insn = 0x3C606800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldr_bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_h_ldst_regoff() {
    uint32_t insn = 0x7C604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_h_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_h_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_s_ldst_regoff() {
    uint32_t insn = 0xBC604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_s_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_s_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_d_ldst_regoff() {
    uint32_t insn = 0xFC604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_d_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_d_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_q_ldst_regoff() {
    uint32_t insn = 0x3CE04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_q_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    std::cout << "  ldr_q_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_32_ldst_regoff() {
    uint32_t insn = 0xB8604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_32_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldr_32_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldr_64_ldst_regoff() {
    uint32_t insn = 0xF8604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldr_64_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldr_64_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldraa_64_ldst_pac() {
    uint32_t insn = 0xF8200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldraa_64_ldst_pac" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldraa_64_ldst_pac: " << result->to_string() << std::endl;
}

void test_ldraa_64w_ldst_pac() {
    uint32_t insn = 0xF8200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldraa_64w_ldst_pac" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldraa_64w_ldst_pac: " << result->to_string() << std::endl;
}

void test_ldrab_64_ldst_pac() {
    uint32_t insn = 0xF8A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrab_64_ldst_pac" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrab_64_ldst_pac: " << result->to_string() << std::endl;
}

void test_ldrab_64w_ldst_pac() {
    uint32_t insn = 0xF8A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrab_64w_ldst_pac" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrab_64w_ldst_pac: " << result->to_string() << std::endl;
}

void test_ldrb_32_ldst_immpost() {
    uint32_t insn = 0x38400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrb_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRB);
    std::cout << "  ldrb_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrb_32_ldst_immpre() {
    uint32_t insn = 0x38400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrb_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrb_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrb_32_ldst_pos() {
    uint32_t insn = 0x39400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrb_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrb_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrb_32b_ldst_regoff() {
    uint32_t insn = 0x38604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrb_32b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrb_32b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrb_32bl_ldst_regoff() {
    uint32_t insn = 0x38606800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrb_32bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrb_32bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrh_32_ldst_immpost() {
    uint32_t insn = 0x78400400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrh_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRH);
    std::cout << "  ldrh_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrh_32_ldst_immpre() {
    uint32_t insn = 0x78400C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrh_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrh_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrh_32_ldst_pos() {
    uint32_t insn = 0x79400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrh_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrh_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrh_32_ldst_regoff() {
    uint32_t insn = 0x78604800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrh_32_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrh_32_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsb_32_ldst_immpost() {
    uint32_t insn = 0x38C00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    std::cout << "  ldrsb_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrsb_64_ldst_immpost() {
    uint32_t insn = 0x38800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_64_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    std::cout << "  ldrsb_64_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrsb_32_ldst_immpre() {
    uint32_t insn = 0x38C00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsb_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrsb_64_ldst_immpre() {
    uint32_t insn = 0x38800C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_64_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsb_64_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrsb_32_ldst_pos() {
    uint32_t insn = 0x39C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsb_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrsb_64_ldst_pos() {
    uint32_t insn = 0x39800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_64_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsb_64_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrsb_32b_ldst_regoff() {
    uint32_t insn = 0x38E04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_32b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsb_32b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsb_32bl_ldst_regoff() {
    uint32_t insn = 0x38E06800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_32bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsb_32bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsb_64b_ldst_regoff() {
    uint32_t insn = 0x38A04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_64b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsb_64b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsb_64bl_ldst_regoff() {
    uint32_t insn = 0x38A06800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsb_64bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsb_64bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsh_32_ldst_immpost() {
    uint32_t insn = 0x78C00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    std::cout << "  ldrsh_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrsh_64_ldst_immpost() {
    uint32_t insn = 0x78800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_64_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    std::cout << "  ldrsh_64_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrsh_32_ldst_immpre() {
    uint32_t insn = 0x78C00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsh_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrsh_64_ldst_immpre() {
    uint32_t insn = 0x78800C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_64_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsh_64_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrsh_32_ldst_pos() {
    uint32_t insn = 0x79C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsh_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrsh_64_ldst_pos() {
    uint32_t insn = 0x79800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_64_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsh_64_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrsh_32_ldst_regoff() {
    uint32_t insn = 0x78E04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_32_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsh_32_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsh_64_ldst_regoff() {
    uint32_t insn = 0x78A04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsh_64_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsh_64_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldrsw_64_ldst_immpost() {
    uint32_t insn = 0xB8800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsw_64_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSW);
    std::cout << "  ldrsw_64_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldrsw_64_ldst_immpre() {
    uint32_t insn = 0xB8800C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsw_64_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsw_64_ldst_immpre: " << result->to_string() << std::endl;
}

void test_ldrsw_64_ldst_pos() {
    uint32_t insn = 0xB9800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsw_64_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldrsw_64_ldst_pos: " << result->to_string() << std::endl;
}

void test_ldrsw_64_loadlit() {
    uint32_t insn = 0x98000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsw_64_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSW);
    std::cout << "  ldrsw_64_loadlit: " << result->to_string() << std::endl;
}

void test_ldrsw_64_ldst_regoff() {
    uint32_t insn = 0xB8A04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldrsw_64_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDRSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  ldrsw_64_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldset_32_memop() {
    uint32_t insn = 0xB8203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldset_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldset_32_memop: " << result->to_string() << std::endl;
}

void test_ldseta_32_memop() {
    uint32_t insn = 0xB8A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldseta_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldseta_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetal_32_memop() {
    uint32_t insn = 0xB8E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetal_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetl_32_memop() {
    uint32_t insn = 0xB8603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetl_32_memop: " << result->to_string() << std::endl;
}

void test_ldset_64_memop() {
    uint32_t insn = 0xF8203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldset_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldset_64_memop: " << result->to_string() << std::endl;
}

void test_ldseta_64_memop() {
    uint32_t insn = 0xF8A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldseta_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldseta_64_memop: " << result->to_string() << std::endl;
}

void test_ldsetal_64_memop() {
    uint32_t insn = 0xF8E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetal_64_memop: " << result->to_string() << std::endl;
}

void test_ldsetl_64_memop() {
    uint32_t insn = 0xF8603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetl_64_memop: " << result->to_string() << std::endl;
}

void test_ldsetb_32_memop() {
    uint32_t insn = 0x38203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetab_32_memop() {
    uint32_t insn = 0x38A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetab_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetalb_32_memop() {
    uint32_t insn = 0x38E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetalb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetlb_32_memop() {
    uint32_t insn = 0x38603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldseth_32_memop() {
    uint32_t insn = 0x78203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldseth_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldseth_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetah_32_memop() {
    uint32_t insn = 0x78A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetah_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetalh_32_memop() {
    uint32_t insn = 0x78E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetalh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetlh_32_memop() {
    uint32_t insn = 0x78603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsetp_128_memop_128() {
    uint32_t insn = 0x19203000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetp_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldsetpa_128_memop_128() {
    uint32_t insn = 0x19A03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldsetpal_128_memop_128() {
    uint32_t insn = 0x19E03000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldsetpl_128_memop_128() {
    uint32_t insn = 0x19603000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsetpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsetpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_ldsmax_32_memop() {
    uint32_t insn = 0xB8204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmax_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmax_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxa_32_memop() {
    uint32_t insn = 0xB8A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxa_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxa_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxal_32_memop() {
    uint32_t insn = 0xB8E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxal_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxl_32_memop() {
    uint32_t insn = 0xB8604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxl_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmax_64_memop() {
    uint32_t insn = 0xF8204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmax_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmax_64_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxa_64_memop() {
    uint32_t insn = 0xF8A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxa_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxa_64_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxal_64_memop() {
    uint32_t insn = 0xF8E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxal_64_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxl_64_memop() {
    uint32_t insn = 0xF8604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxl_64_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxb_32_memop() {
    uint32_t insn = 0x38204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxab_32_memop() {
    uint32_t insn = 0x38A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxab_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxalb_32_memop() {
    uint32_t insn = 0x38E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxalb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxlb_32_memop() {
    uint32_t insn = 0x38604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxh_32_memop() {
    uint32_t insn = 0x78204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxah_32_memop() {
    uint32_t insn = 0x78A04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxah_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxalh_32_memop() {
    uint32_t insn = 0x78E04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxalh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmaxlh_32_memop() {
    uint32_t insn = 0x78604000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmaxlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmaxlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmin_32_memop() {
    uint32_t insn = 0xB8205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmin_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmin_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmina_32_memop() {
    uint32_t insn = 0xB8A05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmina_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmina_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminal_32_memop() {
    uint32_t insn = 0xB8E05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminal_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminl_32_memop() {
    uint32_t insn = 0xB8605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminl_32_memop: " << result->to_string() << std::endl;
}

void test_ldsmin_64_memop() {
    uint32_t insn = 0xF8205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmin_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmin_64_memop: " << result->to_string() << std::endl;
}

void test_ldsmina_64_memop() {
    uint32_t insn = 0xF8A05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsmina_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsmina_64_memop: " << result->to_string() << std::endl;
}

void test_ldsminal_64_memop() {
    uint32_t insn = 0xF8E05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminal_64_memop: " << result->to_string() << std::endl;
}

void test_ldsminl_64_memop() {
    uint32_t insn = 0xF8605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminl_64_memop: " << result->to_string() << std::endl;
}

void test_ldsminb_32_memop() {
    uint32_t insn = 0x38205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminab_32_memop() {
    uint32_t insn = 0x38A05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminab_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminalb_32_memop() {
    uint32_t insn = 0x38E05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminalb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminlb_32_memop() {
    uint32_t insn = 0x38605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminh_32_memop() {
    uint32_t insn = 0x78205000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminah_32_memop() {
    uint32_t insn = 0x78A05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminah_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminalh_32_memop() {
    uint32_t insn = 0x78E05000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminalh_32_memop: " << result->to_string() << std::endl;
}

void test_ldsminlh_32_memop() {
    uint32_t insn = 0x78605000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldsminlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldsminlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldtadd_32_memop_unpriv() {
    uint32_t insn = 0x19200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtadd_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtadd_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtadda_32_memop_unpriv() {
    uint32_t insn = 0x19A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtadda_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtadda_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtaddal_32_memop_unpriv() {
    uint32_t insn = 0x19E00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtaddal_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtaddal_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtaddl_32_memop_unpriv() {
    uint32_t insn = 0x19600400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtaddl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtaddl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtadd_64_memop_unpriv() {
    uint32_t insn = 0x59200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtadd_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtadd_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtadda_64_memop_unpriv() {
    uint32_t insn = 0x59A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtadda_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtadda_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtaddal_64_memop_unpriv() {
    uint32_t insn = 0x59E00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtaddal_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtaddal_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtaddl_64_memop_unpriv() {
    uint32_t insn = 0x59600400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtaddl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtaddl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclr_32_memop_unpriv() {
    uint32_t insn = 0x19201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclr_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclr_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclra_32_memop_unpriv() {
    uint32_t insn = 0x19A01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclra_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclra_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclral_32_memop_unpriv() {
    uint32_t insn = 0x19E01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclral_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclral_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclrl_32_memop_unpriv() {
    uint32_t insn = 0x19601400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclrl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclrl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclr_64_memop_unpriv() {
    uint32_t insn = 0x59201400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclr_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclr_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclra_64_memop_unpriv() {
    uint32_t insn = 0x59A01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclra_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclra_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclral_64_memop_unpriv() {
    uint32_t insn = 0x59E01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclral_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclral_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtclrl_64_memop_unpriv() {
    uint32_t insn = 0x59601400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtclrl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtclrl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtnp_q_ldstnapair_offs() {
    uint32_t insn = 0xEC400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtnp_q_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTNP);
    std::cout << "  ldtnp_q_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldtnp_64_ldstnapair_offs() {
    uint32_t insn = 0xE8400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtnp_64_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtnp_64_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldtp_q_ldstpair_post() {
    uint32_t insn = 0xECC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_q_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    std::cout << "  ldtp_q_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldtp_q_ldstpair_pre() {
    uint32_t insn = 0xEDC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_q_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    std::cout << "  ldtp_q_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldtp_q_ldstpair_off() {
    uint32_t insn = 0xED400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_q_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    std::cout << "  ldtp_q_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldtp_64_ldstpair_post() {
    uint32_t insn = 0xE8C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    std::cout << "  ldtp_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldtp_64_ldstpair_pre() {
    uint32_t insn = 0xE9C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtp_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_ldtp_64_ldstpair_off() {
    uint32_t insn = 0xE9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtp_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtp_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_ldtr_32_ldst_unpriv() {
    uint32_t insn = 0xB8400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtr_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtr_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtr_64_ldst_unpriv() {
    uint32_t insn = 0xF8400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtr_64_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtr_64_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrb_32_ldst_unpriv() {
    uint32_t insn = 0x38400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrb_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrb_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrh_32_ldst_unpriv() {
    uint32_t insn = 0x78400800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrh_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrh_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrsb_32_ldst_unpriv() {
    uint32_t insn = 0x38C00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrsb_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrsb_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrsb_64_ldst_unpriv() {
    uint32_t insn = 0x38800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrsb_64_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrsb_64_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrsh_32_ldst_unpriv() {
    uint32_t insn = 0x78C00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrsh_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrsh_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrsh_64_ldst_unpriv() {
    uint32_t insn = 0x78800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrsh_64_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrsh_64_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtrsw_64_ldst_unpriv() {
    uint32_t insn = 0xB8800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtrsw_64_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTRSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtrsw_64_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_ldtset_32_memop_unpriv() {
    uint32_t insn = 0x19203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtset_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtset_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtseta_32_memop_unpriv() {
    uint32_t insn = 0x19A03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtseta_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtseta_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtsetal_32_memop_unpriv() {
    uint32_t insn = 0x19E03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtsetal_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtsetal_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtsetl_32_memop_unpriv() {
    uint32_t insn = 0x19603400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtsetl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtsetl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtset_64_memop_unpriv() {
    uint32_t insn = 0x59203400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtset_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtset_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtseta_64_memop_unpriv() {
    uint32_t insn = 0x59A03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtseta_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtseta_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtsetal_64_memop_unpriv() {
    uint32_t insn = 0x59E03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtsetal_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtsetal_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtsetl_64_memop_unpriv() {
    uint32_t insn = 0x59603400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtsetl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldtsetl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_ldtxr_lr32_ldstexclr_unpriv() {
    uint32_t insn = 0x89400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtxr_lr32_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtxr_lr32_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_ldtxr_lr64_ldstexclr_unpriv() {
    uint32_t insn = 0xC9400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldtxr_lr64_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDTXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldtxr_lr64_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_ldumax_32_memop() {
    uint32_t insn = 0xB8206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumax_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumax_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxa_32_memop() {
    uint32_t insn = 0xB8A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxa_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxa_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxal_32_memop() {
    uint32_t insn = 0xB8E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxal_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxl_32_memop() {
    uint32_t insn = 0xB8606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxl_32_memop: " << result->to_string() << std::endl;
}

void test_ldumax_64_memop() {
    uint32_t insn = 0xF8206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumax_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumax_64_memop: " << result->to_string() << std::endl;
}

void test_ldumaxa_64_memop() {
    uint32_t insn = 0xF8A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxa_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxa_64_memop: " << result->to_string() << std::endl;
}

void test_ldumaxal_64_memop() {
    uint32_t insn = 0xF8E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxal_64_memop: " << result->to_string() << std::endl;
}

void test_ldumaxl_64_memop() {
    uint32_t insn = 0xF8606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxl_64_memop: " << result->to_string() << std::endl;
}

void test_ldumaxb_32_memop() {
    uint32_t insn = 0x38206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxb_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxab_32_memop() {
    uint32_t insn = 0x38A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxab_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxalb_32_memop() {
    uint32_t insn = 0x38E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxalb_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxlb_32_memop() {
    uint32_t insn = 0x38606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxlb_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxh_32_memop() {
    uint32_t insn = 0x78206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxh_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxah_32_memop() {
    uint32_t insn = 0x78A06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxah_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxalh_32_memop() {
    uint32_t insn = 0x78E06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxalh_32_memop: " << result->to_string() << std::endl;
}

void test_ldumaxlh_32_memop() {
    uint32_t insn = 0x78606000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumaxlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumaxlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldumin_32_memop() {
    uint32_t insn = 0xB8207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumin_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumin_32_memop: " << result->to_string() << std::endl;
}

void test_ldumina_32_memop() {
    uint32_t insn = 0xB8A07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumina_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumina_32_memop: " << result->to_string() << std::endl;
}

void test_lduminal_32_memop() {
    uint32_t insn = 0xB8E07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminal_32_memop: " << result->to_string() << std::endl;
}

void test_lduminl_32_memop() {
    uint32_t insn = 0xB8607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminl_32_memop: " << result->to_string() << std::endl;
}

void test_ldumin_64_memop() {
    uint32_t insn = 0xF8207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumin_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumin_64_memop: " << result->to_string() << std::endl;
}

void test_ldumina_64_memop() {
    uint32_t insn = 0xF8A07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldumina_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldumina_64_memop: " << result->to_string() << std::endl;
}

void test_lduminal_64_memop() {
    uint32_t insn = 0xF8E07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminal_64_memop: " << result->to_string() << std::endl;
}

void test_lduminl_64_memop() {
    uint32_t insn = 0xF8607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminl_64_memop: " << result->to_string() << std::endl;
}

void test_lduminb_32_memop() {
    uint32_t insn = 0x38207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminb_32_memop: " << result->to_string() << std::endl;
}

void test_lduminab_32_memop() {
    uint32_t insn = 0x38A07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminab_32_memop: " << result->to_string() << std::endl;
}

void test_lduminalb_32_memop() {
    uint32_t insn = 0x38E07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminalb_32_memop: " << result->to_string() << std::endl;
}

void test_lduminlb_32_memop() {
    uint32_t insn = 0x38607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminlb_32_memop: " << result->to_string() << std::endl;
}

void test_lduminh_32_memop() {
    uint32_t insn = 0x78207000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminh_32_memop: " << result->to_string() << std::endl;
}

void test_lduminah_32_memop() {
    uint32_t insn = 0x78A07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminah_32_memop: " << result->to_string() << std::endl;
}

void test_lduminalh_32_memop() {
    uint32_t insn = 0x78E07000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminalh_32_memop: " << result->to_string() << std::endl;
}

void test_lduminlh_32_memop() {
    uint32_t insn = 0x78607000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: lduminlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  lduminlh_32_memop: " << result->to_string() << std::endl;
}

void test_ldur_b_ldst_unscaled() {
    uint32_t insn = 0x3C400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_b_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldur_b_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_h_ldst_unscaled() {
    uint32_t insn = 0x7C400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_h_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    std::cout << "  ldur_h_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_s_ldst_unscaled() {
    uint32_t insn = 0xBC400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_s_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    std::cout << "  ldur_s_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_d_ldst_unscaled() {
    uint32_t insn = 0xFC400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_d_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    std::cout << "  ldur_d_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_q_ldst_unscaled() {
    uint32_t insn = 0x3CC00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_q_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    std::cout << "  ldur_q_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_32_ldst_unscaled() {
    uint32_t insn = 0xB8400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldur_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldur_64_ldst_unscaled() {
    uint32_t insn = 0xF8400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldur_64_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldur_64_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldurb_32_ldst_unscaled() {
    uint32_t insn = 0x38400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldurb_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldurb_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldurh_32_ldst_unscaled() {
    uint32_t insn = 0x78400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldurh_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldurh_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldursb_32_ldst_unscaled() {
    uint32_t insn = 0x38C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldursb_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldursb_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldursb_64_ldst_unscaled() {
    uint32_t insn = 0x38800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldursb_64_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURSB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldursb_64_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldursh_32_ldst_unscaled() {
    uint32_t insn = 0x78C00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldursh_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldursh_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldursh_64_ldst_unscaled() {
    uint32_t insn = 0x78800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldursh_64_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURSH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldursh_64_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldursw_64_ldst_unscaled() {
    uint32_t insn = 0xB8800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldursw_64_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDURSW);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldursw_64_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_ldxp_lp32_ldstexclp() {
    uint32_t insn = 0x88600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxp_lp32_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldxp_lp32_ldstexclp: " << result->to_string() << std::endl;
}

void test_ldxp_lp64_ldstexclp() {
    uint32_t insn = 0xC8600000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxp_lp64_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  ldxp_lp64_ldstexclp: " << result->to_string() << std::endl;
}

void test_ldxr_lr32_ldstexclr() {
    uint32_t insn = 0x88400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxr_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldxr_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldxr_lr64_ldstexclr() {
    uint32_t insn = 0xC8400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxr_lr64_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldxr_lr64_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldxrb_lr32_ldstexclr() {
    uint32_t insn = 0x08400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxrb_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldxrb_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_ldxrh_lr32_ldstexclr() {
    uint32_t insn = 0x48400000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: ldxrh_lr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::LDXRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  ldxrh_lr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_prfm_p_ldst_pos() {
    uint32_t insn = 0xF9800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfm_p_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFM);
    std::cout << "  prfm_p_ldst_pos: " << result->to_string() << std::endl;
}

void test_prfm_p_loadlit() {
    uint32_t insn = 0xD8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfm_p_loadlit" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFM);
    std::cout << "  prfm_p_loadlit: " << result->to_string() << std::endl;
}

void test_prfm_p_ldst_regoff() {
    uint32_t insn = 0xF8A04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfm_p_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFM);
    std::cout << "  prfm_p_ldst_regoff: " << result->to_string() << std::endl;
}

void test_prfum_p_ldst_unscaled() {
    uint32_t insn = 0xF8800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: prfum_p_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::PRFUM);
    std::cout << "  prfum_p_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_rcwcas_c64_rcwcomswap() {
    uint32_t insn = 0x19200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcas_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcas_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwcasa_c64_rcwcomswap() {
    uint32_t insn = 0x19A00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcasa_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcasa_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwcasal_c64_rcwcomswap() {
    uint32_t insn = 0x19E00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcasal_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcasal_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwcasl_c64_rcwcomswap() {
    uint32_t insn = 0x19600800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcasl_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcasl_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwcasp_c64_rcwcomswappr() {
    uint32_t insn = 0x19200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcasp_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcasp_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwcaspa_c64_rcwcomswappr() {
    uint32_t insn = 0x19A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcaspa_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcaspa_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwcaspal_c64_rcwcomswappr() {
    uint32_t insn = 0x19E00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcaspal_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcaspal_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwcaspl_c64_rcwcomswappr() {
    uint32_t insn = 0x19600C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwcaspl_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwcaspl_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwclr_64_memop() {
    uint32_t insn = 0x38209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclr_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclr_64_memop: " << result->to_string() << std::endl;
}

void test_rcwclra_64_memop() {
    uint32_t insn = 0x38A09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclra_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclra_64_memop: " << result->to_string() << std::endl;
}

void test_rcwclral_64_memop() {
    uint32_t insn = 0x38E09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclral_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclral_64_memop: " << result->to_string() << std::endl;
}

void test_rcwclrl_64_memop() {
    uint32_t insn = 0x38609000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclrl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclrl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwclrp_128_memop_128() {
    uint32_t insn = 0x19209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclrp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclrp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwclrpa_128_memop_128() {
    uint32_t insn = 0x19A09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclrpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclrpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwclrpal_128_memop_128() {
    uint32_t insn = 0x19E09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclrpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclrpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwclrpl_128_memop_128() {
    uint32_t insn = 0x19609000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwclrpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwclrpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwscas_c64_rcwcomswap() {
    uint32_t insn = 0x59200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscas_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscas_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwscasa_c64_rcwcomswap() {
    uint32_t insn = 0x59A00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscasa_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscasa_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwscasal_c64_rcwcomswap() {
    uint32_t insn = 0x59E00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscasal_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscasal_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwscasl_c64_rcwcomswap() {
    uint32_t insn = 0x59600800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscasl_c64_rcwcomswap" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscasl_c64_rcwcomswap: " << result->to_string() << std::endl;
}

void test_rcwscasp_c64_rcwcomswappr() {
    uint32_t insn = 0x59200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscasp_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscasp_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwscaspa_c64_rcwcomswappr() {
    uint32_t insn = 0x59A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscaspa_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscaspa_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwscaspal_c64_rcwcomswappr() {
    uint32_t insn = 0x59E00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscaspal_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscaspal_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwscaspl_c64_rcwcomswappr() {
    uint32_t insn = 0x59600C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwscaspl_c64_rcwcomswappr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwscaspl_c64_rcwcomswappr: " << result->to_string() << std::endl;
}

void test_rcwsclr_64_memop() {
    uint32_t insn = 0x78209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclr_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclr_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsclra_64_memop() {
    uint32_t insn = 0x78A09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclra_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclra_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsclral_64_memop() {
    uint32_t insn = 0x78E09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclral_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclral_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsclrl_64_memop() {
    uint32_t insn = 0x78609000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclrl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclrl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsclrp_128_memop_128() {
    uint32_t insn = 0x59209000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclrp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclrp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsclrpa_128_memop_128() {
    uint32_t insn = 0x59A09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclrpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclrpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsclrpal_128_memop_128() {
    uint32_t insn = 0x59E09000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclrpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclrpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsclrpl_128_memop_128() {
    uint32_t insn = 0x59609000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsclrpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsclrpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwset_64_memop() {
    uint32_t insn = 0x3820B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwset_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwset_64_memop: " << result->to_string() << std::endl;
}

void test_rcwseta_64_memop() {
    uint32_t insn = 0x38A0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwseta_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwseta_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsetal_64_memop() {
    uint32_t insn = 0x38E0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetal_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsetl_64_memop() {
    uint32_t insn = 0x3860B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsetp_128_memop_128() {
    uint32_t insn = 0x1920B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsetpa_128_memop_128() {
    uint32_t insn = 0x19A0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsetpal_128_memop_128() {
    uint32_t insn = 0x19E0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsetpl_128_memop_128() {
    uint32_t insn = 0x1960B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsetpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsetpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsset_64_memop() {
    uint32_t insn = 0x7820B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsset_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsset_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsseta_64_memop() {
    uint32_t insn = 0x78A0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsseta_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsseta_64_memop: " << result->to_string() << std::endl;
}

void test_rcwssetal_64_memop() {
    uint32_t insn = 0x78E0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetal_64_memop: " << result->to_string() << std::endl;
}

void test_rcwssetl_64_memop() {
    uint32_t insn = 0x7860B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwssetp_128_memop_128() {
    uint32_t insn = 0x5920B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwssetpa_128_memop_128() {
    uint32_t insn = 0x59A0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetpa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetpa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwssetpal_128_memop_128() {
    uint32_t insn = 0x59E0B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetpal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetpal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwssetpl_128_memop_128() {
    uint32_t insn = 0x5960B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwssetpl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwssetpl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsswp_64_memop() {
    uint32_t insn = 0x7820A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswp_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswp_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsswpa_64_memop() {
    uint32_t insn = 0x78A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswpa_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswpa_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsswpal_64_memop() {
    uint32_t insn = 0x78E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswpal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswpal_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsswpl_64_memop() {
    uint32_t insn = 0x7860A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswpl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswpl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwsswpp_128_memop_128() {
    uint32_t insn = 0x5920A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswpp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswpp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsswppa_128_memop_128() {
    uint32_t insn = 0x59A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswppa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswppa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsswppal_128_memop_128() {
    uint32_t insn = 0x59E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswppal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswppal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwsswppl_128_memop_128() {
    uint32_t insn = 0x5960A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwsswppl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwsswppl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwswp_64_memop() {
    uint32_t insn = 0x3820A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswp_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswp_64_memop: " << result->to_string() << std::endl;
}

void test_rcwswpa_64_memop() {
    uint32_t insn = 0x38A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswpa_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswpa_64_memop: " << result->to_string() << std::endl;
}

void test_rcwswpal_64_memop() {
    uint32_t insn = 0x38E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswpal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswpal_64_memop: " << result->to_string() << std::endl;
}

void test_rcwswpl_64_memop() {
    uint32_t insn = 0x3860A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswpl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswpl_64_memop: " << result->to_string() << std::endl;
}

void test_rcwswpp_128_memop_128() {
    uint32_t insn = 0x1920A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswpp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswpp_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwswppa_128_memop_128() {
    uint32_t insn = 0x19A0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswppa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswppa_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwswppal_128_memop_128() {
    uint32_t insn = 0x19E0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswppal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswppal_128_memop_128: " << result->to_string() << std::endl;
}

void test_rcwswppl_128_memop_128() {
    uint32_t insn = 0x1960A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rcwswppl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  rcwswppl_128_memop_128: " << result->to_string() << std::endl;
}

void test_rprfm_r_ldst_regoff() {
    uint32_t insn = 0xF8A04818u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: rprfm_r_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::RPRFM);
    std::cout << "  rprfm_r_ldst_regoff: " << result->to_string() << std::endl;
}

void test_setgp_set_memcms() {
    uint32_t insn = 0x1DC00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgp_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgp_set_memcms: " << result->to_string() << std::endl;
}

void test_setgm_set_memcms() {
    uint32_t insn = 0x1DC04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgm_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgm_set_memcms: " << result->to_string() << std::endl;
}

void test_setge_set_memcms() {
    uint32_t insn = 0x1DC08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setge_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setge_set_memcms: " << result->to_string() << std::endl;
}

void test_setgpn_set_memcms() {
    uint32_t insn = 0x1DC02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgpn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgpn_set_memcms: " << result->to_string() << std::endl;
}

void test_setgmn_set_memcms() {
    uint32_t insn = 0x1DC06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgmn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgmn_set_memcms: " << result->to_string() << std::endl;
}

void test_setgen_set_memcms() {
    uint32_t insn = 0x1DC0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgen_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgen_set_memcms: " << result->to_string() << std::endl;
}

void test_setgpt_set_memcms() {
    uint32_t insn = 0x1DC01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgpt_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgpt_set_memcms: " << result->to_string() << std::endl;
}

void test_setgmt_set_memcms() {
    uint32_t insn = 0x1DC05400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgmt_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgmt_set_memcms: " << result->to_string() << std::endl;
}

void test_setget_set_memcms() {
    uint32_t insn = 0x1DC09400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setget_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setget_set_memcms: " << result->to_string() << std::endl;
}

void test_setgptn_set_memcms() {
    uint32_t insn = 0x1DC03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgptn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgptn_set_memcms: " << result->to_string() << std::endl;
}

void test_setgmtn_set_memcms() {
    uint32_t insn = 0x1DC07400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgmtn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgmtn_set_memcms: " << result->to_string() << std::endl;
}

void test_setgetn_set_memcms() {
    uint32_t insn = 0x1DC0B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setgetn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setgetn_set_memcms: " << result->to_string() << std::endl;
}

void test_setp_set_memcms() {
    uint32_t insn = 0x19C00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setp_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setp_set_memcms: " << result->to_string() << std::endl;
}

void test_setm_set_memcms() {
    uint32_t insn = 0x19C04400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setm_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setm_set_memcms: " << result->to_string() << std::endl;
}

void test_sete_set_memcms() {
    uint32_t insn = 0x19C08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sete_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  sete_set_memcms: " << result->to_string() << std::endl;
}

void test_setpn_set_memcms() {
    uint32_t insn = 0x19C02400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setpn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setpn_set_memcms: " << result->to_string() << std::endl;
}

void test_setmn_set_memcms() {
    uint32_t insn = 0x19C06400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setmn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setmn_set_memcms: " << result->to_string() << std::endl;
}

void test_seten_set_memcms() {
    uint32_t insn = 0x19C0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: seten_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  seten_set_memcms: " << result->to_string() << std::endl;
}

void test_setpt_set_memcms() {
    uint32_t insn = 0x19C01400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setpt_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setpt_set_memcms: " << result->to_string() << std::endl;
}

void test_setmt_set_memcms() {
    uint32_t insn = 0x19C05400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setmt_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setmt_set_memcms: " << result->to_string() << std::endl;
}

void test_setet_set_memcms() {
    uint32_t insn = 0x19C09400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setet_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setet_set_memcms: " << result->to_string() << std::endl;
}

void test_setptn_set_memcms() {
    uint32_t insn = 0x19C03400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setptn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setptn_set_memcms: " << result->to_string() << std::endl;
}

void test_setmtn_set_memcms() {
    uint32_t insn = 0x19C07400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setmtn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setmtn_set_memcms: " << result->to_string() << std::endl;
}

void test_setetn_set_memcms() {
    uint32_t insn = 0x19C0B400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: setetn_set_memcms" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Memory);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  setetn_set_memcms: " << result->to_string() << std::endl;
}

void test_st1_asisdlse_r1_1v() {
    uint32_t insn = 0x0C007000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlse_r1_1v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlse_r1_1v: " << result->to_string() << std::endl;
}

void test_st1_asisdlse_r2_2v() {
    uint32_t insn = 0x0C00A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlse_r2_2v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlse_r2_2v: " << result->to_string() << std::endl;
}

void test_st1_asisdlse_r3_3v() {
    uint32_t insn = 0x0C006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlse_r3_3v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlse_r3_3v: " << result->to_string() << std::endl;
}

void test_st1_asisdlse_r4_4v() {
    uint32_t insn = 0x0C002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlse_r4_4v" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlse_r4_4v: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_i1_i1() {
    uint32_t insn = 0x0C9F7000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_i1_i1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    std::cout << "  st1_asisdlsep_i1_i1: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_r1_r1() {
    uint32_t insn = 0x0C807000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_r1_r1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsep_r1_r1: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_i2_i2() {
    uint32_t insn = 0x0C9FA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_i2_i2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    std::cout << "  st1_asisdlsep_i2_i2: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_r2_r2() {
    uint32_t insn = 0x0C80A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_r2_r2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsep_r2_r2: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_i3_i3() {
    uint32_t insn = 0x0C9F6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_i3_i3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    std::cout << "  st1_asisdlsep_i3_i3: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_r3_r3() {
    uint32_t insn = 0x0C806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_r3_r3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsep_r3_r3: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_i4_i4() {
    uint32_t insn = 0x0C9F2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_i4_i4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    std::cout << "  st1_asisdlsep_i4_i4: " << result->to_string() << std::endl;
}

void test_st1_asisdlsep_r4_r4() {
    uint32_t insn = 0x0C802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsep_r4_r4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsep_r4_r4: " << result->to_string() << std::endl;
}

void test_st1_asisdlso_b1_1b() {
    uint32_t insn = 0x0D000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlso_b1_1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlso_b1_1b: " << result->to_string() << std::endl;
}

void test_st1_asisdlso_h1_1h() {
    uint32_t insn = 0x0D004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlso_h1_1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlso_h1_1h: " << result->to_string() << std::endl;
}

void test_st1_asisdlso_s1_1s() {
    uint32_t insn = 0x0D008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlso_s1_1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlso_s1_1s: " << result->to_string() << std::endl;
}

void test_st1_asisdlso_d1_1d() {
    uint32_t insn = 0x0D008400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlso_d1_1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlso_d1_1d: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_b1_i1b() {
    uint32_t insn = 0x0D9F0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_b1_i1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlsop_b1_i1b: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_bx1_r1b() {
    uint32_t insn = 0x0D800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_bx1_r1b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsop_bx1_r1b: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_h1_i1h() {
    uint32_t insn = 0x0D9F4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_h1_i1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlsop_h1_i1h: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_hx1_r1h() {
    uint32_t insn = 0x0D804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_hx1_r1h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsop_hx1_r1h: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_s1_i1s() {
    uint32_t insn = 0x0D9F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_s1_i1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlsop_s1_i1s: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_sx1_r1s() {
    uint32_t insn = 0x0D808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_sx1_r1s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsop_sx1_r1s: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_d1_i1d() {
    uint32_t insn = 0x0D9F8400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_d1_i1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st1_asisdlsop_d1_i1d: " << result->to_string() << std::endl;
}

void test_st1_asisdlsop_dx1_r1d() {
    uint32_t insn = 0x0D808400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st1_asisdlsop_dx1_r1d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST1);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st1_asisdlsop_dx1_r1d: " << result->to_string() << std::endl;
}

void test_st2_asisdlse_r2() {
    uint32_t insn = 0x0C008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlse_r2" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlse_r2: " << result->to_string() << std::endl;
}

void test_st2_asisdlsep_i2_i() {
    uint32_t insn = 0x0C9F8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsep_i2_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    std::cout << "  st2_asisdlsep_i2_i: " << result->to_string() << std::endl;
}

void test_st2_asisdlsep_r2_r() {
    uint32_t insn = 0x0C808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsep_r2_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st2_asisdlsep_r2_r: " << result->to_string() << std::endl;
}

void test_st2_asisdlso_b2_2b() {
    uint32_t insn = 0x0D200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlso_b2_2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlso_b2_2b: " << result->to_string() << std::endl;
}

void test_st2_asisdlso_h2_2h() {
    uint32_t insn = 0x0D204000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlso_h2_2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlso_h2_2h: " << result->to_string() << std::endl;
}

void test_st2_asisdlso_s2_2s() {
    uint32_t insn = 0x0D208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlso_s2_2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlso_s2_2s: " << result->to_string() << std::endl;
}

void test_st2_asisdlso_d2_2d() {
    uint32_t insn = 0x0D208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlso_d2_2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlso_d2_2d: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_b2_i2b() {
    uint32_t insn = 0x0DBF0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_b2_i2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlsop_b2_i2b: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_bx2_r2b() {
    uint32_t insn = 0x0DA00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_bx2_r2b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st2_asisdlsop_bx2_r2b: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_h2_i2h() {
    uint32_t insn = 0x0DBF4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_h2_i2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlsop_h2_i2h: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_hx2_r2h() {
    uint32_t insn = 0x0DA04000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_hx2_r2h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st2_asisdlsop_hx2_r2h: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_s2_i2s() {
    uint32_t insn = 0x0DBF8000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_s2_i2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlsop_s2_i2s: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_sx2_r2s() {
    uint32_t insn = 0x0DA08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_sx2_r2s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st2_asisdlsop_sx2_r2s: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_d2_i2d() {
    uint32_t insn = 0x0DBF8400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_d2_i2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2_asisdlsop_d2_i2d: " << result->to_string() << std::endl;
}

void test_st2_asisdlsop_dx2_r2d() {
    uint32_t insn = 0x0DA08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2_asisdlsop_dx2_r2d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st2_asisdlsop_dx2_r2d: " << result->to_string() << std::endl;
}

void test_st2g_64spost_ldsttags() {
    uint32_t insn = 0xD9A00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2g_64spost_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2G);
    std::cout << "  st2g_64spost_ldsttags: " << result->to_string() << std::endl;
}

void test_st2g_64spre_ldsttags() {
    uint32_t insn = 0xD9A00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2g_64spre_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2G);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2g_64spre_ldsttags: " << result->to_string() << std::endl;
}

void test_st2g_64soffset_ldsttags() {
    uint32_t insn = 0xD9A00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st2g_64soffset_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST2G);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st2g_64soffset_ldsttags: " << result->to_string() << std::endl;
}

void test_st3_asisdlse_r3() {
    uint32_t insn = 0x0C004000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlse_r3" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlse_r3: " << result->to_string() << std::endl;
}

void test_st3_asisdlsep_i3_i() {
    uint32_t insn = 0x0C9F4000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsep_i3_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    std::cout << "  st3_asisdlsep_i3_i: " << result->to_string() << std::endl;
}

void test_st3_asisdlsep_r3_r() {
    uint32_t insn = 0x0C804000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsep_r3_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st3_asisdlsep_r3_r: " << result->to_string() << std::endl;
}

void test_st3_asisdlso_b3_3b() {
    uint32_t insn = 0x0D002000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlso_b3_3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlso_b3_3b: " << result->to_string() << std::endl;
}

void test_st3_asisdlso_h3_3h() {
    uint32_t insn = 0x0D006000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlso_h3_3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlso_h3_3h: " << result->to_string() << std::endl;
}

void test_st3_asisdlso_s3_3s() {
    uint32_t insn = 0x0D00A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlso_s3_3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlso_s3_3s: " << result->to_string() << std::endl;
}

void test_st3_asisdlso_d3_3d() {
    uint32_t insn = 0x0D00A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlso_d3_3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlso_d3_3d: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_b3_i3b() {
    uint32_t insn = 0x0D9F2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_b3_i3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlsop_b3_i3b: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_bx3_r3b() {
    uint32_t insn = 0x0D802000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_bx3_r3b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st3_asisdlsop_bx3_r3b: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_h3_i3h() {
    uint32_t insn = 0x0D9F6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_h3_i3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlsop_h3_i3h: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_hx3_r3h() {
    uint32_t insn = 0x0D806000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_hx3_r3h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st3_asisdlsop_hx3_r3h: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_s3_i3s() {
    uint32_t insn = 0x0D9FA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_s3_i3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlsop_s3_i3s: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_sx3_r3s() {
    uint32_t insn = 0x0D80A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_sx3_r3s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st3_asisdlsop_sx3_r3s: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_d3_i3d() {
    uint32_t insn = 0x0D9FA400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_d3_i3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st3_asisdlsop_d3_i3d: " << result->to_string() << std::endl;
}

void test_st3_asisdlsop_dx3_r3d() {
    uint32_t insn = 0x0D80A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st3_asisdlsop_dx3_r3d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST3);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st3_asisdlsop_dx3_r3d: " << result->to_string() << std::endl;
}

void test_st4_asisdlse_r4() {
    uint32_t insn = 0x0C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlse_r4" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlse_r4: " << result->to_string() << std::endl;
}

void test_st4_asisdlsep_i4_i() {
    uint32_t insn = 0x0C9F0000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsep_i4_i" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    std::cout << "  st4_asisdlsep_i4_i: " << result->to_string() << std::endl;
}

void test_st4_asisdlsep_r4_r() {
    uint32_t insn = 0x0C800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsep_r4_r" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::RegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st4_asisdlsep_r4_r: " << result->to_string() << std::endl;
}

void test_st4_asisdlso_b4_4b() {
    uint32_t insn = 0x0D202000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlso_b4_4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlso_b4_4b: " << result->to_string() << std::endl;
}

void test_st4_asisdlso_h4_4h() {
    uint32_t insn = 0x0D206000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlso_h4_4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlso_h4_4h: " << result->to_string() << std::endl;
}

void test_st4_asisdlso_s4_4s() {
    uint32_t insn = 0x0D20A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlso_s4_4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlso_s4_4s: " << result->to_string() << std::endl;
}

void test_st4_asisdlso_d4_4d() {
    uint32_t insn = 0x0D20A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlso_d4_4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlso_d4_4d: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_b4_i4b() {
    uint32_t insn = 0x0DBF2000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_b4_i4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlsop_b4_i4b: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_bx4_r4b() {
    uint32_t insn = 0x0DA02000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_bx4_r4b" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st4_asisdlsop_bx4_r4b: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_h4_i4h() {
    uint32_t insn = 0x0DBF6000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_h4_i4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlsop_h4_i4h: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_hx4_r4h() {
    uint32_t insn = 0x0DA06000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_hx4_r4h" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st4_asisdlsop_hx4_r4h: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_s4_i4s() {
    uint32_t insn = 0x0DBFA000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_s4_i4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlsop_s4_i4s: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_sx4_r4s() {
    uint32_t insn = 0x0DA0A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_sx4_r4s" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st4_asisdlsop_sx4_r4s: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_d4_i4d() {
    uint32_t insn = 0x0DBFA400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_d4_i4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st4_asisdlsop_d4_i4d: " << result->to_string() << std::endl;
}

void test_st4_asisdlsop_dx4_r4d() {
    uint32_t insn = 0x0DA0A400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st4_asisdlsop_dx4_r4d" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST4);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    assert(result->operands[2].type == OperandType::Register);
    std::cout << "  st4_asisdlsop_dx4_r4d: " << result->to_string() << std::endl;
}

void test_st64b_64l_memop() {
    uint32_t insn = 0xF83F9000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st64b_64l_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST64B);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  st64b_64l_memop: " << result->to_string() << std::endl;
}

void test_st64bv_64_memop() {
    uint32_t insn = 0xF820B000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st64bv_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST64BV);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  st64bv_64_memop: " << result->to_string() << std::endl;
}

void test_st64bv0_64_memop() {
    uint32_t insn = 0xF820A000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: st64bv0_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::ST64BV0);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  st64bv0_64_memop: " << result->to_string() << std::endl;
}

void test_stadd_ldadd_32_memop() {
    uint32_t insn = 0xB820001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stadd_ldadd_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stadd_ldadd_32_memop: " << result->to_string() << std::endl;
}

void test_staddl_ldaddl_32_memop() {
    uint32_t insn = 0xB860001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddl_ldaddl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddl_ldaddl_32_memop: " << result->to_string() << std::endl;
}

void test_stadd_ldadd_64_memop() {
    uint32_t insn = 0xF820001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stadd_ldadd_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stadd_ldadd_64_memop: " << result->to_string() << std::endl;
}

void test_staddl_ldaddl_64_memop() {
    uint32_t insn = 0xF860001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddl_ldaddl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddl_ldaddl_64_memop: " << result->to_string() << std::endl;
}

void test_staddb_ldaddb_32_memop() {
    uint32_t insn = 0x3820001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddb_ldaddb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddb_ldaddb_32_memop: " << result->to_string() << std::endl;
}

void test_staddlb_ldaddlb_32_memop() {
    uint32_t insn = 0x3860001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddlb_ldaddlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddlb_ldaddlb_32_memop: " << result->to_string() << std::endl;
}

void test_staddh_ldaddh_32_memop() {
    uint32_t insn = 0x7820001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddh_ldaddh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddh_ldaddh_32_memop: " << result->to_string() << std::endl;
}

void test_staddlh_ldaddlh_32_memop() {
    uint32_t insn = 0x7860001Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: staddlh_ldaddlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  staddlh_ldaddlh_32_memop: " << result->to_string() << std::endl;
}

void test_stbfadd_16() {
    uint32_t insn = 0x3C20801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfadd_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfadd_16: " << result->to_string() << std::endl;
}

void test_stbfaddl_16() {
    uint32_t insn = 0x3C60801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfaddl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfaddl_16: " << result->to_string() << std::endl;
}

void test_stbfmax_16() {
    uint32_t insn = 0x3C20C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfmax_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfmax_16: " << result->to_string() << std::endl;
}

void test_stbfmaxl_16() {
    uint32_t insn = 0x3C60C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfmaxl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfmaxl_16: " << result->to_string() << std::endl;
}

void test_stbfmaxnm_16() {
    uint32_t insn = 0x3C20E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfmaxnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfmaxnm_16: " << result->to_string() << std::endl;
}

void test_stbfmaxnml_16() {
    uint32_t insn = 0x3C60E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfmaxnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfmaxnml_16: " << result->to_string() << std::endl;
}

void test_stbfmin_16() {
    uint32_t insn = 0x3C20D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfmin_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfmin_16: " << result->to_string() << std::endl;
}

void test_stbfminl_16() {
    uint32_t insn = 0x3C60D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfminl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfminl_16: " << result->to_string() << std::endl;
}

void test_stbfminnm_16() {
    uint32_t insn = 0x3C20F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfminnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfminnm_16: " << result->to_string() << std::endl;
}

void test_stbfminnml_16() {
    uint32_t insn = 0x3C60F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stbfminnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stbfminnml_16: " << result->to_string() << std::endl;
}

void test_stclr_ldclr_32_memop() {
    uint32_t insn = 0xB820101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclr_ldclr_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclr_ldclr_32_memop: " << result->to_string() << std::endl;
}

void test_stclrl_ldclrl_32_memop() {
    uint32_t insn = 0xB860101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrl_ldclrl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrl_ldclrl_32_memop: " << result->to_string() << std::endl;
}

void test_stclr_ldclr_64_memop() {
    uint32_t insn = 0xF820101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclr_ldclr_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclr_ldclr_64_memop: " << result->to_string() << std::endl;
}

void test_stclrl_ldclrl_64_memop() {
    uint32_t insn = 0xF860101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrl_ldclrl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrl_ldclrl_64_memop: " << result->to_string() << std::endl;
}

void test_stclrb_ldclrb_32_memop() {
    uint32_t insn = 0x3820101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrb_ldclrb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrb_ldclrb_32_memop: " << result->to_string() << std::endl;
}

void test_stclrlb_ldclrlb_32_memop() {
    uint32_t insn = 0x3860101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrlb_ldclrlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrlb_ldclrlb_32_memop: " << result->to_string() << std::endl;
}

void test_stclrh_ldclrh_32_memop() {
    uint32_t insn = 0x7820101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrh_ldclrh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrh_ldclrh_32_memop: " << result->to_string() << std::endl;
}

void test_stclrlh_ldclrlh_32_memop() {
    uint32_t insn = 0x7860101Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stclrlh_ldclrlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stclrlh_ldclrlh_32_memop: " << result->to_string() << std::endl;
}

void test_steor_ldeor_32_memop() {
    uint32_t insn = 0xB820201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steor_ldeor_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steor_ldeor_32_memop: " << result->to_string() << std::endl;
}

void test_steorl_ldeorl_32_memop() {
    uint32_t insn = 0xB860201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorl_ldeorl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorl_ldeorl_32_memop: " << result->to_string() << std::endl;
}

void test_steor_ldeor_64_memop() {
    uint32_t insn = 0xF820201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steor_ldeor_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steor_ldeor_64_memop: " << result->to_string() << std::endl;
}

void test_steorl_ldeorl_64_memop() {
    uint32_t insn = 0xF860201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorl_ldeorl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorl_ldeorl_64_memop: " << result->to_string() << std::endl;
}

void test_steorb_ldeorb_32_memop() {
    uint32_t insn = 0x3820201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorb_ldeorb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorb_ldeorb_32_memop: " << result->to_string() << std::endl;
}

void test_steorlb_ldeorlb_32_memop() {
    uint32_t insn = 0x3860201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorlb_ldeorlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorlb_ldeorlb_32_memop: " << result->to_string() << std::endl;
}

void test_steorh_ldeorh_32_memop() {
    uint32_t insn = 0x7820201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorh_ldeorh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorh_ldeorh_32_memop: " << result->to_string() << std::endl;
}

void test_steorlh_ldeorlh_32_memop() {
    uint32_t insn = 0x7860201Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: steorlh_ldeorlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  steorlh_ldeorlh_32_memop: " << result->to_string() << std::endl;
}

void test_stfadd_16() {
    uint32_t insn = 0x7C20801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfadd_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfadd_16: " << result->to_string() << std::endl;
}

void test_stfaddl_16() {
    uint32_t insn = 0x7C60801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfaddl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfaddl_16: " << result->to_string() << std::endl;
}

void test_stfadd_32() {
    uint32_t insn = 0xBC20801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfadd_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfadd_32: " << result->to_string() << std::endl;
}

void test_stfaddl_32() {
    uint32_t insn = 0xBC60801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfaddl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfaddl_32: " << result->to_string() << std::endl;
}

void test_stfadd_64() {
    uint32_t insn = 0xFC20801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfadd_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfadd_64: " << result->to_string() << std::endl;
}

void test_stfaddl_64() {
    uint32_t insn = 0xFC60801Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfaddl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfaddl_64: " << result->to_string() << std::endl;
}

void test_stfmax_16() {
    uint32_t insn = 0x7C20C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmax_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmax_16: " << result->to_string() << std::endl;
}

void test_stfmaxl_16() {
    uint32_t insn = 0x7C60C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxl_16: " << result->to_string() << std::endl;
}

void test_stfmax_32() {
    uint32_t insn = 0xBC20C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmax_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmax_32: " << result->to_string() << std::endl;
}

void test_stfmaxl_32() {
    uint32_t insn = 0xBC60C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxl_32: " << result->to_string() << std::endl;
}

void test_stfmax_64() {
    uint32_t insn = 0xFC20C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmax_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmax_64: " << result->to_string() << std::endl;
}

void test_stfmaxl_64() {
    uint32_t insn = 0xFC60C01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxl_64: " << result->to_string() << std::endl;
}

void test_stfmaxnm_16() {
    uint32_t insn = 0x7C20E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnm_16: " << result->to_string() << std::endl;
}

void test_stfmaxnml_16() {
    uint32_t insn = 0x7C60E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnml_16: " << result->to_string() << std::endl;
}

void test_stfmaxnm_32() {
    uint32_t insn = 0xBC20E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnm_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnm_32: " << result->to_string() << std::endl;
}

void test_stfmaxnml_32() {
    uint32_t insn = 0xBC60E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnml_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnml_32: " << result->to_string() << std::endl;
}

void test_stfmaxnm_64() {
    uint32_t insn = 0xFC20E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnm_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnm_64: " << result->to_string() << std::endl;
}

void test_stfmaxnml_64() {
    uint32_t insn = 0xFC60E01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmaxnml_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmaxnml_64: " << result->to_string() << std::endl;
}

void test_stfmin_16() {
    uint32_t insn = 0x7C20D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmin_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmin_16: " << result->to_string() << std::endl;
}

void test_stfminl_16() {
    uint32_t insn = 0x7C60D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminl_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminl_16: " << result->to_string() << std::endl;
}

void test_stfmin_32() {
    uint32_t insn = 0xBC20D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmin_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmin_32: " << result->to_string() << std::endl;
}

void test_stfminl_32() {
    uint32_t insn = 0xBC60D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminl_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminl_32: " << result->to_string() << std::endl;
}

void test_stfmin_64() {
    uint32_t insn = 0xFC20D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfmin_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfmin_64: " << result->to_string() << std::endl;
}

void test_stfminl_64() {
    uint32_t insn = 0xFC60D01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminl_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminl_64: " << result->to_string() << std::endl;
}

void test_stfminnm_16() {
    uint32_t insn = 0x7C20F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnm_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnm_16: " << result->to_string() << std::endl;
}

void test_stfminnml_16() {
    uint32_t insn = 0x7C60F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnml_16" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnml_16: " << result->to_string() << std::endl;
}

void test_stfminnm_32() {
    uint32_t insn = 0xBC20F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnm_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnm_32: " << result->to_string() << std::endl;
}

void test_stfminnml_32() {
    uint32_t insn = 0xBC60F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnml_32" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnml_32: " << result->to_string() << std::endl;
}

void test_stfminnm_64() {
    uint32_t insn = 0xFC20F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnm_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnm_64: " << result->to_string() << std::endl;
}

void test_stfminnml_64() {
    uint32_t insn = 0xFC60F01Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stfminnml_64" << std::endl; throw std::runtime_error("decode failed"); }
    std::cout << "  stfminnml_64: " << result->to_string() << std::endl;
}

void test_stg_64spost_ldsttags() {
    uint32_t insn = 0xD9200400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stg_64spost_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STG);
    std::cout << "  stg_64spost_ldsttags: " << result->to_string() << std::endl;
}

void test_stg_64spre_ldsttags() {
    uint32_t insn = 0xD9200C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stg_64spre_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stg_64spre_ldsttags: " << result->to_string() << std::endl;
}

void test_stg_64soffset_ldsttags() {
    uint32_t insn = 0xD9200800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stg_64soffset_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stg_64soffset_ldsttags: " << result->to_string() << std::endl;
}

void test_stgm_64bulk_ldsttags() {
    uint32_t insn = 0xD9A00000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stgm_64bulk_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STGM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stgm_64bulk_ldsttags: " << result->to_string() << std::endl;
}

void test_stgp_64_ldstpair_post() {
    uint32_t insn = 0x68800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stgp_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STGP);
    std::cout << "  stgp_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stgp_64_ldstpair_pre() {
    uint32_t insn = 0x69800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stgp_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STGP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stgp_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stgp_64_ldstpair_off() {
    uint32_t insn = 0x69000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stgp_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STGP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stgp_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_stilp_32se_ldiappstilp() {
    uint32_t insn = 0x99000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stilp_32se_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STILP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stilp_32se_ldiappstilp: " << result->to_string() << std::endl;
}

void test_stilp_32s_ldiappstilp() {
    uint32_t insn = 0x99001800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stilp_32s_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STILP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stilp_32s_ldiappstilp: " << result->to_string() << std::endl;
}

void test_stilp_64ss_ldiappstilp() {
    uint32_t insn = 0xD9000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stilp_64ss_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STILP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stilp_64ss_ldiappstilp: " << result->to_string() << std::endl;
}

void test_stilp_64s_ldiappstilp() {
    uint32_t insn = 0xD9001800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stilp_64s_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STILP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stilp_64s_ldiappstilp: " << result->to_string() << std::endl;
}

void test_stl1_asisdlso_d1() {
    uint32_t insn = 0x0D018400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stl1_asisdlso_d1" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STL1);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::IndexedRegisterList);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stl1_asisdlso_d1: " << result->to_string() << std::endl;
}

void test_stllr_sl32_ldstord() {
    uint32_t insn = 0x88800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stllr_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stllr_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stllr_sl64_ldstord() {
    uint32_t insn = 0xC8800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stllr_sl64_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stllr_sl64_ldstord: " << result->to_string() << std::endl;
}

void test_stllrb_sl32_ldstord() {
    uint32_t insn = 0x08800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stllrb_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLLRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stllrb_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stllrh_sl32_ldstord() {
    uint32_t insn = 0x48800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stllrh_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLLRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stllrh_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stlp_64_ldiappstilp() {
    uint32_t insn = 0xD9005800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlp_64_ldiappstilp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stlp_64_ldiappstilp: " << result->to_string() << std::endl;
}

void test_stlr_sl32_ldstord() {
    uint32_t insn = 0x88808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlr_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlr_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stlr_sl64_ldstord() {
    uint32_t insn = 0xC8808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlr_sl64_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlr_sl64_ldstord: " << result->to_string() << std::endl;
}

void test_stlr_32s_ldapstl_writeback() {
    uint32_t insn = 0x99800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlr_32s_ldapstl_writeback" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlr_32s_ldapstl_writeback: " << result->to_string() << std::endl;
}

void test_stlr_64s_ldapstl_writeback() {
    uint32_t insn = 0xD9800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlr_64s_ldapstl_writeback" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlr_64s_ldapstl_writeback: " << result->to_string() << std::endl;
}

void test_stlrb_sl32_ldstord() {
    uint32_t insn = 0x08808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlrb_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlrb_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stlrh_sl32_ldstord() {
    uint32_t insn = 0x48808000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlrh_sl32_ldstord" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlrh_sl32_ldstord: " << result->to_string() << std::endl;
}

void test_stltxr_sr32_ldstexclr_unpriv() {
    uint32_t insn = 0x89008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stltxr_sr32_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLTXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stltxr_sr32_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_stltxr_sr64_ldstexclr_unpriv() {
    uint32_t insn = 0xC9008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stltxr_sr64_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLTXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stltxr_sr64_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_stlur_b_ldapstl_simd() {
    uint32_t insn = 0x1D000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_b_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlur_b_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_stlur_h_ldapstl_simd() {
    uint32_t insn = 0x5D000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_h_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    std::cout << "  stlur_h_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_stlur_s_ldapstl_simd() {
    uint32_t insn = 0x9D000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_s_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    std::cout << "  stlur_s_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_stlur_d_ldapstl_simd() {
    uint32_t insn = 0xDD000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_d_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    std::cout << "  stlur_d_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_stlur_q_ldapstl_simd() {
    uint32_t insn = 0x1D800800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_q_ldapstl_simd" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    std::cout << "  stlur_q_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_stlur_32_ldapstl_unscaled() {
    uint32_t insn = 0x99000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlur_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_stlur_64_ldapstl_unscaled() {
    uint32_t insn = 0xD9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlur_64_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlur_64_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_stlurb_32_ldapstl_unscaled() {
    uint32_t insn = 0x19000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlurb_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLURB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlurb_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_stlurh_32_ldapstl_unscaled() {
    uint32_t insn = 0x59000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlurh_32_ldapstl_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLURH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stlurh_32_ldapstl_unscaled: " << result->to_string() << std::endl;
}

void test_stlxp_sp32_ldstexclp() {
    uint32_t insn = 0x88208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxp_sp32_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXP);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Memory);
    std::cout << "  stlxp_sp32_ldstexclp: " << result->to_string() << std::endl;
}

void test_stlxp_sp64_ldstexclp() {
    uint32_t insn = 0xC8208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxp_sp64_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXP);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Memory);
    std::cout << "  stlxp_sp64_ldstexclp: " << result->to_string() << std::endl;
}

void test_stlxr_sr32_ldstexclr() {
    uint32_t insn = 0x88008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxr_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stlxr_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stlxr_sr64_ldstexclr() {
    uint32_t insn = 0xC8008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxr_sr64_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stlxr_sr64_ldstexclr: " << result->to_string() << std::endl;
}

void test_stlxrb_sr32_ldstexclr() {
    uint32_t insn = 0x08008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxrb_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXRB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stlxrb_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stlxrh_sr32_ldstexclr() {
    uint32_t insn = 0x48008000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stlxrh_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STLXRH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stlxrh_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stnp_s_ldstnapair_offs() {
    uint32_t insn = 0x2C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnp_s_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNP);
    std::cout << "  stnp_s_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_stnp_d_ldstnapair_offs() {
    uint32_t insn = 0x6C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnp_d_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNP);
    std::cout << "  stnp_d_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_stnp_q_ldstnapair_offs() {
    uint32_t insn = 0xAC000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnp_q_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNP);
    std::cout << "  stnp_q_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_stnp_32_ldstnapair_offs() {
    uint32_t insn = 0x28000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnp_32_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stnp_32_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_stnp_64_ldstnapair_offs() {
    uint32_t insn = 0xA8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stnp_64_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stnp_64_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_stp_s_ldstpair_post() {
    uint32_t insn = 0x2C800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_s_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_s_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stp_d_ldstpair_post() {
    uint32_t insn = 0x6C800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_d_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_d_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stp_q_ldstpair_post() {
    uint32_t insn = 0xAC800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_q_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_q_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stp_s_ldstpair_pre() {
    uint32_t insn = 0x2D800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_s_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_s_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stp_d_ldstpair_pre() {
    uint32_t insn = 0x6D800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_d_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_d_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stp_q_ldstpair_pre() {
    uint32_t insn = 0xAD800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_q_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_q_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stp_s_ldstpair_off() {
    uint32_t insn = 0x2D000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_s_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_s_ldstpair_off: " << result->to_string() << std::endl;
}

void test_stp_d_ldstpair_off() {
    uint32_t insn = 0x6D000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_d_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_d_ldstpair_off: " << result->to_string() << std::endl;
}

void test_stp_q_ldstpair_off() {
    uint32_t insn = 0xAD000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_q_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_q_ldstpair_off: " << result->to_string() << std::endl;
}

void test_stp_32_ldstpair_post() {
    uint32_t insn = 0x28800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_32_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_32_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stp_64_ldstpair_post() {
    uint32_t insn = 0xA8800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    std::cout << "  stp_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_stp_32_ldstpair_pre() {
    uint32_t insn = 0x29800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_32_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stp_32_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stp_64_ldstpair_pre() {
    uint32_t insn = 0xA9800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stp_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_stp_32_ldstpair_off() {
    uint32_t insn = 0x29000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_32_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stp_32_ldstpair_off: " << result->to_string() << std::endl;
}

void test_stp_64_ldstpair_off() {
    uint32_t insn = 0xA9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stp_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stp_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_str_b_ldst_immpost() {
    uint32_t insn = 0x3C000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_b_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_b_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_h_ldst_immpost() {
    uint32_t insn = 0x7C000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_h_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_h_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_s_ldst_immpost() {
    uint32_t insn = 0xBC000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_s_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_s_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_d_ldst_immpost() {
    uint32_t insn = 0xFC000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_d_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_d_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_q_ldst_immpost() {
    uint32_t insn = 0x3C800400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_q_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_q_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_b_ldst_immpre() {
    uint32_t insn = 0x3C000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_b_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_b_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_h_ldst_immpre() {
    uint32_t insn = 0x7C000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_h_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_h_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_s_ldst_immpre() {
    uint32_t insn = 0xBC000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_s_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_s_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_d_ldst_immpre() {
    uint32_t insn = 0xFC000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_d_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_d_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_q_ldst_immpre() {
    uint32_t insn = 0x3C800C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_q_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_q_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_b_ldst_pos() {
    uint32_t insn = 0x3D000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_b_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_b_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_h_ldst_pos() {
    uint32_t insn = 0x7D000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_h_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_h_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_s_ldst_pos() {
    uint32_t insn = 0xBD000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_s_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_s_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_d_ldst_pos() {
    uint32_t insn = 0xFD000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_d_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_d_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_q_ldst_pos() {
    uint32_t insn = 0x3D800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_q_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_q_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_32_ldst_immpost() {
    uint32_t insn = 0xB8000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_64_ldst_immpost() {
    uint32_t insn = 0xF8000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_64_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_64_ldst_immpost: " << result->to_string() << std::endl;
}

void test_str_32_ldst_immpre() {
    uint32_t insn = 0xB8000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_64_ldst_immpre() {
    uint32_t insn = 0xF8000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_64_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_64_ldst_immpre: " << result->to_string() << std::endl;
}

void test_str_32_ldst_pos() {
    uint32_t insn = 0xB9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_64_ldst_pos() {
    uint32_t insn = 0xF9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_64_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  str_64_ldst_pos: " << result->to_string() << std::endl;
}

void test_str_b_ldst_regoff() {
    uint32_t insn = 0x3C204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  str_b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_bl_ldst_regoff() {
    uint32_t insn = 0x3C206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  str_bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_h_ldst_regoff() {
    uint32_t insn = 0x7C204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_h_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_h_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_s_ldst_regoff() {
    uint32_t insn = 0xBC204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_s_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_s_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_d_ldst_regoff() {
    uint32_t insn = 0xFC204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_d_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_d_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_q_ldst_regoff() {
    uint32_t insn = 0x3CA04800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_q_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    std::cout << "  str_q_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_32_ldst_regoff() {
    uint32_t insn = 0xB8204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_32_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  str_32_ldst_regoff: " << result->to_string() << std::endl;
}

void test_str_64_ldst_regoff() {
    uint32_t insn = 0xF8204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: str_64_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  str_64_ldst_regoff: " << result->to_string() << std::endl;
}

void test_strb_32_ldst_immpost() {
    uint32_t insn = 0x38000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strb_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRB);
    std::cout << "  strb_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_strb_32_ldst_immpre() {
    uint32_t insn = 0x38000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strb_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  strb_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_strb_32_ldst_pos() {
    uint32_t insn = 0x39000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strb_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  strb_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_strb_32b_ldst_regoff() {
    uint32_t insn = 0x38204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strb_32b_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  strb_32b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_strb_32bl_ldst_regoff() {
    uint32_t insn = 0x38206800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strb_32bl_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  strb_32bl_ldst_regoff: " << result->to_string() << std::endl;
}

void test_strh_32_ldst_immpost() {
    uint32_t insn = 0x78000400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strh_32_ldst_immpost" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRH);
    std::cout << "  strh_32_ldst_immpost: " << result->to_string() << std::endl;
}

void test_strh_32_ldst_immpre() {
    uint32_t insn = 0x78000C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strh_32_ldst_immpre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  strh_32_ldst_immpre: " << result->to_string() << std::endl;
}

void test_strh_32_ldst_pos() {
    uint32_t insn = 0x79000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strh_32_ldst_pos" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  strh_32_ldst_pos: " << result->to_string() << std::endl;
}

void test_strh_32_ldst_regoff() {
    uint32_t insn = 0x78204800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: strh_32_ldst_regoff" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::MemoryRegOffset);
    std::cout << "  strh_32_ldst_regoff: " << result->to_string() << std::endl;
}

void test_stset_ldset_32_memop() {
    uint32_t insn = 0xB820301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stset_ldset_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stset_ldset_32_memop: " << result->to_string() << std::endl;
}

void test_stsetl_ldsetl_32_memop() {
    uint32_t insn = 0xB860301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsetl_ldsetl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsetl_ldsetl_32_memop: " << result->to_string() << std::endl;
}

void test_stset_ldset_64_memop() {
    uint32_t insn = 0xF820301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stset_ldset_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stset_ldset_64_memop: " << result->to_string() << std::endl;
}

void test_stsetl_ldsetl_64_memop() {
    uint32_t insn = 0xF860301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsetl_ldsetl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsetl_ldsetl_64_memop: " << result->to_string() << std::endl;
}

void test_stsetb_ldsetb_32_memop() {
    uint32_t insn = 0x3820301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsetb_ldsetb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsetb_ldsetb_32_memop: " << result->to_string() << std::endl;
}

void test_stsetlb_ldsetlb_32_memop() {
    uint32_t insn = 0x3860301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsetlb_ldsetlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsetlb_ldsetlb_32_memop: " << result->to_string() << std::endl;
}

void test_stseth_ldseth_32_memop() {
    uint32_t insn = 0x7820301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stseth_ldseth_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stseth_ldseth_32_memop: " << result->to_string() << std::endl;
}

void test_stsetlh_ldsetlh_32_memop() {
    uint32_t insn = 0x7860301Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsetlh_ldsetlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsetlh_ldsetlh_32_memop: " << result->to_string() << std::endl;
}

void test_stsmax_ldsmax_32_memop() {
    uint32_t insn = 0xB820401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmax_ldsmax_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmax_ldsmax_32_memop: " << result->to_string() << std::endl;
}

void test_stsmaxl_ldsmaxl_32_memop() {
    uint32_t insn = 0xB860401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxl_ldsmaxl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxl_ldsmaxl_32_memop: " << result->to_string() << std::endl;
}

void test_stsmax_ldsmax_64_memop() {
    uint32_t insn = 0xF820401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmax_ldsmax_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmax_ldsmax_64_memop: " << result->to_string() << std::endl;
}

void test_stsmaxl_ldsmaxl_64_memop() {
    uint32_t insn = 0xF860401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxl_ldsmaxl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxl_ldsmaxl_64_memop: " << result->to_string() << std::endl;
}

void test_stsmaxb_ldsmaxb_32_memop() {
    uint32_t insn = 0x3820401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxb_ldsmaxb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxb_ldsmaxb_32_memop: " << result->to_string() << std::endl;
}

void test_stsmaxlb_ldsmaxlb_32_memop() {
    uint32_t insn = 0x3860401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxlb_ldsmaxlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxlb_ldsmaxlb_32_memop: " << result->to_string() << std::endl;
}

void test_stsmaxh_ldsmaxh_32_memop() {
    uint32_t insn = 0x7820401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxh_ldsmaxh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxh_ldsmaxh_32_memop: " << result->to_string() << std::endl;
}

void test_stsmaxlh_ldsmaxlh_32_memop() {
    uint32_t insn = 0x7860401Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmaxlh_ldsmaxlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmaxlh_ldsmaxlh_32_memop: " << result->to_string() << std::endl;
}

void test_stsmin_ldsmin_32_memop() {
    uint32_t insn = 0xB820501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmin_ldsmin_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmin_ldsmin_32_memop: " << result->to_string() << std::endl;
}

void test_stsminl_ldsminl_32_memop() {
    uint32_t insn = 0xB860501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminl_ldsminl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminl_ldsminl_32_memop: " << result->to_string() << std::endl;
}

void test_stsmin_ldsmin_64_memop() {
    uint32_t insn = 0xF820501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsmin_ldsmin_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsmin_ldsmin_64_memop: " << result->to_string() << std::endl;
}

void test_stsminl_ldsminl_64_memop() {
    uint32_t insn = 0xF860501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminl_ldsminl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminl_ldsminl_64_memop: " << result->to_string() << std::endl;
}

void test_stsminb_ldsminb_32_memop() {
    uint32_t insn = 0x3820501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminb_ldsminb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminb_ldsminb_32_memop: " << result->to_string() << std::endl;
}

void test_stsminlb_ldsminlb_32_memop() {
    uint32_t insn = 0x3860501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminlb_ldsminlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminlb_ldsminlb_32_memop: " << result->to_string() << std::endl;
}

void test_stsminh_ldsminh_32_memop() {
    uint32_t insn = 0x7820501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminh_ldsminh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminh_ldsminh_32_memop: " << result->to_string() << std::endl;
}

void test_stsminlh_ldsminlh_32_memop() {
    uint32_t insn = 0x7860501Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stsminlh_ldsminlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stsminlh_ldsminlh_32_memop: " << result->to_string() << std::endl;
}

void test_sttadd_ldtadd_32_memop_unpriv() {
    uint32_t insn = 0x1920041Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttadd_ldtadd_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttadd_ldtadd_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttaddl_ldtaddl_32_memop_unpriv() {
    uint32_t insn = 0x1960041Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttaddl_ldtaddl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttaddl_ldtaddl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttadd_ldtadd_64_memop_unpriv() {
    uint32_t insn = 0x5920041Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttadd_ldtadd_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttadd_ldtadd_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttaddl_ldtaddl_64_memop_unpriv() {
    uint32_t insn = 0x5960041Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttaddl_ldtaddl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttaddl_ldtaddl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttclr_ldtclr_32_memop_unpriv() {
    uint32_t insn = 0x1920141Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttclr_ldtclr_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttclr_ldtclr_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttclrl_ldtclrl_32_memop_unpriv() {
    uint32_t insn = 0x1960141Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttclrl_ldtclrl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttclrl_ldtclrl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttclr_ldtclr_64_memop_unpriv() {
    uint32_t insn = 0x5920141Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttclr_ldtclr_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttclr_ldtclr_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttclrl_ldtclrl_64_memop_unpriv() {
    uint32_t insn = 0x5960141Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttclrl_ldtclrl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttclrl_ldtclrl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttnp_q_ldstnapair_offs() {
    uint32_t insn = 0xEC000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttnp_q_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTNP);
    std::cout << "  sttnp_q_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_sttnp_64_ldstnapair_offs() {
    uint32_t insn = 0xE8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttnp_64_ldstnapair_offs" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTNP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  sttnp_64_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_sttp_q_ldstpair_post() {
    uint32_t insn = 0xEC800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_q_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    std::cout << "  sttp_q_ldstpair_post: " << result->to_string() << std::endl;
}

void test_sttp_q_ldstpair_pre() {
    uint32_t insn = 0xED800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_q_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    std::cout << "  sttp_q_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_sttp_q_ldstpair_off() {
    uint32_t insn = 0xED000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_q_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    std::cout << "  sttp_q_ldstpair_off: " << result->to_string() << std::endl;
}

void test_sttp_64_ldstpair_post() {
    uint32_t insn = 0xE8800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_64_ldstpair_post" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    std::cout << "  sttp_64_ldstpair_post: " << result->to_string() << std::endl;
}

void test_sttp_64_ldstpair_pre() {
    uint32_t insn = 0xE9800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_64_ldstpair_pre" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  sttp_64_ldstpair_pre: " << result->to_string() << std::endl;
}

void test_sttp_64_ldstpair_off() {
    uint32_t insn = 0xE9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttp_64_ldstpair_off" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTP);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  sttp_64_ldstpair_off: " << result->to_string() << std::endl;
}

void test_sttr_32_ldst_unpriv() {
    uint32_t insn = 0xB8000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttr_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttr_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_sttr_64_ldst_unpriv() {
    uint32_t insn = 0xF8000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttr_64_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttr_64_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_sttrb_32_ldst_unpriv() {
    uint32_t insn = 0x38000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttrb_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTRB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttrb_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_sttrh_32_ldst_unpriv() {
    uint32_t insn = 0x78000800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttrh_32_ldst_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTRH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttrh_32_ldst_unpriv: " << result->to_string() << std::endl;
}

void test_sttset_ldtset_32_memop_unpriv() {
    uint32_t insn = 0x1920341Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttset_ldtset_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttset_ldtset_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttsetl_ldtsetl_32_memop_unpriv() {
    uint32_t insn = 0x1960341Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttsetl_ldtsetl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttsetl_ldtsetl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttset_ldtset_64_memop_unpriv() {
    uint32_t insn = 0x5920341Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttset_ldtset_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttset_ldtset_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttsetl_ldtsetl_64_memop_unpriv() {
    uint32_t insn = 0x5960341Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttsetl_ldtsetl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sttsetl_ldtsetl_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_sttxr_sr32_ldstexclr_unpriv() {
    uint32_t insn = 0x89000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttxr_sr32_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  sttxr_sr32_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_sttxr_sr64_ldstexclr_unpriv() {
    uint32_t insn = 0xC9000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sttxr_sr64_ldstexclr_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STTXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  sttxr_sr64_ldstexclr_unpriv: " << result->to_string() << std::endl;
}

void test_stumax_ldumax_32_memop() {
    uint32_t insn = 0xB820601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumax_ldumax_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumax_ldumax_32_memop: " << result->to_string() << std::endl;
}

void test_stumaxl_ldumaxl_32_memop() {
    uint32_t insn = 0xB860601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxl_ldumaxl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxl_ldumaxl_32_memop: " << result->to_string() << std::endl;
}

void test_stumax_ldumax_64_memop() {
    uint32_t insn = 0xF820601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumax_ldumax_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumax_ldumax_64_memop: " << result->to_string() << std::endl;
}

void test_stumaxl_ldumaxl_64_memop() {
    uint32_t insn = 0xF860601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxl_ldumaxl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxl_ldumaxl_64_memop: " << result->to_string() << std::endl;
}

void test_stumaxb_ldumaxb_32_memop() {
    uint32_t insn = 0x3820601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxb_ldumaxb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxb_ldumaxb_32_memop: " << result->to_string() << std::endl;
}

void test_stumaxlb_ldumaxlb_32_memop() {
    uint32_t insn = 0x3860601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxlb_ldumaxlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxlb_ldumaxlb_32_memop: " << result->to_string() << std::endl;
}

void test_stumaxh_ldumaxh_32_memop() {
    uint32_t insn = 0x7820601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxh_ldumaxh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxh_ldumaxh_32_memop: " << result->to_string() << std::endl;
}

void test_stumaxlh_ldumaxlh_32_memop() {
    uint32_t insn = 0x7860601Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumaxlh_ldumaxlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumaxlh_ldumaxlh_32_memop: " << result->to_string() << std::endl;
}

void test_stumin_ldumin_32_memop() {
    uint32_t insn = 0xB820701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumin_ldumin_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumin_ldumin_32_memop: " << result->to_string() << std::endl;
}

void test_stuminl_lduminl_32_memop() {
    uint32_t insn = 0xB860701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminl_lduminl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminl_lduminl_32_memop: " << result->to_string() << std::endl;
}

void test_stumin_ldumin_64_memop() {
    uint32_t insn = 0xF820701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stumin_ldumin_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stumin_ldumin_64_memop: " << result->to_string() << std::endl;
}

void test_stuminl_lduminl_64_memop() {
    uint32_t insn = 0xF860701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminl_lduminl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminl_lduminl_64_memop: " << result->to_string() << std::endl;
}

void test_stuminb_lduminb_32_memop() {
    uint32_t insn = 0x3820701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminb_lduminb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminb_lduminb_32_memop: " << result->to_string() << std::endl;
}

void test_stuminlb_lduminlb_32_memop() {
    uint32_t insn = 0x3860701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminlb_lduminlb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminlb_lduminlb_32_memop: " << result->to_string() << std::endl;
}

void test_stuminh_lduminh_32_memop() {
    uint32_t insn = 0x7820701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminh_lduminh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminh_lduminh_32_memop: " << result->to_string() << std::endl;
}

void test_stuminlh_lduminlh_32_memop() {
    uint32_t insn = 0x7860701Fu;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stuminlh_lduminlh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stuminlh_lduminlh_32_memop: " << result->to_string() << std::endl;
}

void test_stur_b_ldst_unscaled() {
    uint32_t insn = 0x3C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_b_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stur_b_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_h_ldst_unscaled() {
    uint32_t insn = 0x7C000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_h_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    std::cout << "  stur_h_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_s_ldst_unscaled() {
    uint32_t insn = 0xBC000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_s_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    std::cout << "  stur_s_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_d_ldst_unscaled() {
    uint32_t insn = 0xFC000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_d_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    std::cout << "  stur_d_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_q_ldst_unscaled() {
    uint32_t insn = 0x3C800000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_q_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    std::cout << "  stur_q_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_32_ldst_unscaled() {
    uint32_t insn = 0xB8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stur_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stur_64_ldst_unscaled() {
    uint32_t insn = 0xF8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stur_64_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STUR);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stur_64_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_sturb_32_ldst_unscaled() {
    uint32_t insn = 0x38000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sturb_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STURB);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sturb_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_sturh_32_ldst_unscaled() {
    uint32_t insn = 0x78000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: sturh_32_ldst_unscaled" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STURH);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  sturh_32_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stxp_sp32_ldstexclp() {
    uint32_t insn = 0x88200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxp_sp32_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXP);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Memory);
    std::cout << "  stxp_sp32_ldstexclp: " << result->to_string() << std::endl;
}

void test_stxp_sp64_ldstexclp() {
    uint32_t insn = 0xC8200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxp_sp64_ldstexclp" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXP);
    assert(result->operands.size() >= 4);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Register);
    assert(result->operands[3].type == OperandType::Memory);
    std::cout << "  stxp_sp64_ldstexclp: " << result->to_string() << std::endl;
}

void test_stxr_sr32_ldstexclr() {
    uint32_t insn = 0x88000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxr_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stxr_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stxr_sr64_ldstexclr() {
    uint32_t insn = 0xC8000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxr_sr64_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXR);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stxr_sr64_ldstexclr: " << result->to_string() << std::endl;
}

void test_stxrb_sr32_ldstexclr() {
    uint32_t insn = 0x08000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxrb_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXRB);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stxrb_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stxrh_sr32_ldstexclr() {
    uint32_t insn = 0x48000000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stxrh_sr32_ldstexclr" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STXRH);
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  stxrh_sr32_ldstexclr: " << result->to_string() << std::endl;
}

void test_stz2g_64spost_ldsttags() {
    uint32_t insn = 0xD9E00400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stz2g_64spost_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZ2G);
    std::cout << "  stz2g_64spost_ldsttags: " << result->to_string() << std::endl;
}

void test_stz2g_64spre_ldsttags() {
    uint32_t insn = 0xD9E00C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stz2g_64spre_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZ2G);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stz2g_64spre_ldsttags: " << result->to_string() << std::endl;
}

void test_stz2g_64soffset_ldsttags() {
    uint32_t insn = 0xD9E00800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stz2g_64soffset_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZ2G);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stz2g_64soffset_ldsttags: " << result->to_string() << std::endl;
}

void test_stzg_64spost_ldsttags() {
    uint32_t insn = 0xD9600400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stzg_64spost_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZG);
    std::cout << "  stzg_64spost_ldsttags: " << result->to_string() << std::endl;
}

void test_stzg_64spre_ldsttags() {
    uint32_t insn = 0xD9600C00u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stzg_64spre_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stzg_64spre_ldsttags: " << result->to_string() << std::endl;
}

void test_stzg_64soffset_ldsttags() {
    uint32_t insn = 0xD9600800u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stzg_64soffset_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZG);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stzg_64soffset_ldsttags: " << result->to_string() << std::endl;
}

void test_stzgm_64bulk_ldsttags() {
    uint32_t insn = 0xD9200000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: stzgm_64bulk_ldsttags" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->mnemonic == Mnemonic::STZGM);
    assert(result->operands.size() >= 2);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Memory);
    std::cout << "  stzgm_64bulk_ldsttags: " << result->to_string() << std::endl;
}

void test_swp_32_memop() {
    uint32_t insn = 0xB8208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swp_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swp_32_memop: " << result->to_string() << std::endl;
}

void test_swpa_32_memop() {
    uint32_t insn = 0xB8A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpa_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpa_32_memop: " << result->to_string() << std::endl;
}

void test_swpal_32_memop() {
    uint32_t insn = 0xB8E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpal_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpal_32_memop: " << result->to_string() << std::endl;
}

void test_swpl_32_memop() {
    uint32_t insn = 0xB8608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpl_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpl_32_memop: " << result->to_string() << std::endl;
}

void test_swp_64_memop() {
    uint32_t insn = 0xF8208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swp_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swp_64_memop: " << result->to_string() << std::endl;
}

void test_swpa_64_memop() {
    uint32_t insn = 0xF8A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpa_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpa_64_memop: " << result->to_string() << std::endl;
}

void test_swpal_64_memop() {
    uint32_t insn = 0xF8E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpal_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpal_64_memop: " << result->to_string() << std::endl;
}

void test_swpl_64_memop() {
    uint32_t insn = 0xF8608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpl_64_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpl_64_memop: " << result->to_string() << std::endl;
}

void test_swpb_32_memop() {
    uint32_t insn = 0x38208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpb_32_memop: " << result->to_string() << std::endl;
}

void test_swpab_32_memop() {
    uint32_t insn = 0x38A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpab_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpab_32_memop: " << result->to_string() << std::endl;
}

void test_swpalb_32_memop() {
    uint32_t insn = 0x38E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpalb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpalb_32_memop: " << result->to_string() << std::endl;
}

void test_swplb_32_memop() {
    uint32_t insn = 0x38608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swplb_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swplb_32_memop: " << result->to_string() << std::endl;
}

void test_swph_32_memop() {
    uint32_t insn = 0x78208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swph_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swph_32_memop: " << result->to_string() << std::endl;
}

void test_swpah_32_memop() {
    uint32_t insn = 0x78A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpah_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpah_32_memop: " << result->to_string() << std::endl;
}

void test_swpalh_32_memop() {
    uint32_t insn = 0x78E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpalh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpalh_32_memop: " << result->to_string() << std::endl;
}

void test_swplh_32_memop() {
    uint32_t insn = 0x78608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swplh_32_memop" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swplh_32_memop: " << result->to_string() << std::endl;
}

void test_swpp_128_memop_128() {
    uint32_t insn = 0x19208000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpp_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpp_128_memop_128: " << result->to_string() << std::endl;
}

void test_swppa_128_memop_128() {
    uint32_t insn = 0x19A08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swppa_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swppa_128_memop_128: " << result->to_string() << std::endl;
}

void test_swppal_128_memop_128() {
    uint32_t insn = 0x19E08000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swppal_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swppal_128_memop_128: " << result->to_string() << std::endl;
}

void test_swppl_128_memop_128() {
    uint32_t insn = 0x19608000u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swppl_128_memop_128" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swppl_128_memop_128: " << result->to_string() << std::endl;
}

void test_swpt_32_memop_unpriv() {
    uint32_t insn = 0x19208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpt_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpt_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swpta_32_memop_unpriv() {
    uint32_t insn = 0x19A08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpta_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpta_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swptal_32_memop_unpriv() {
    uint32_t insn = 0x19E08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swptal_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swptal_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swptl_32_memop_unpriv() {
    uint32_t insn = 0x19608400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swptl_32_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swptl_32_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swpt_64_memop_unpriv() {
    uint32_t insn = 0x59208400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpt_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpt_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swpta_64_memop_unpriv() {
    uint32_t insn = 0x59A08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swpta_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swpta_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swptal_64_memop_unpriv() {
    uint32_t insn = 0x59E08400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swptal_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swptal_64_memop_unpriv: " << result->to_string() << std::endl;
}

void test_swptl_64_memop_unpriv() {
    uint32_t insn = 0x59608400u;
    auto result = decode(insn);
    if (!result.has_value()) { std::cerr << "DECODE FAIL: swptl_64_memop_unpriv" << std::endl; throw std::runtime_error("decode failed"); }
    assert(result->operands.size() >= 3);
    assert(result->operands[0].type == OperandType::Register);
    assert(result->operands[1].type == OperandType::Register);
    assert(result->operands[2].type == OperandType::Memory);
    std::cout << "  swptl_64_memop_unpriv: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running ldst encoding tests (1075 encodings)..." << std::endl;
    int failed = 0;

    try { test_cas_c32_comswap(); } catch (...) { std::cerr << "FAIL: cas_c32_comswap" << std::endl; failed++; }
    try { test_casa_c32_comswap(); } catch (...) { std::cerr << "FAIL: casa_c32_comswap" << std::endl; failed++; }
    try { test_casal_c32_comswap(); } catch (...) { std::cerr << "FAIL: casal_c32_comswap" << std::endl; failed++; }
    try { test_casl_c32_comswap(); } catch (...) { std::cerr << "FAIL: casl_c32_comswap" << std::endl; failed++; }
    try { test_cas_c64_comswap(); } catch (...) { std::cerr << "FAIL: cas_c64_comswap" << std::endl; failed++; }
    try { test_casa_c64_comswap(); } catch (...) { std::cerr << "FAIL: casa_c64_comswap" << std::endl; failed++; }
    try { test_casal_c64_comswap(); } catch (...) { std::cerr << "FAIL: casal_c64_comswap" << std::endl; failed++; }
    try { test_casl_c64_comswap(); } catch (...) { std::cerr << "FAIL: casl_c64_comswap" << std::endl; failed++; }
    try { test_casb_c32_comswap(); } catch (...) { std::cerr << "FAIL: casb_c32_comswap" << std::endl; failed++; }
    try { test_casab_c32_comswap(); } catch (...) { std::cerr << "FAIL: casab_c32_comswap" << std::endl; failed++; }
    try { test_casalb_c32_comswap(); } catch (...) { std::cerr << "FAIL: casalb_c32_comswap" << std::endl; failed++; }
    try { test_caslb_c32_comswap(); } catch (...) { std::cerr << "FAIL: caslb_c32_comswap" << std::endl; failed++; }
    try { test_cash_c32_comswap(); } catch (...) { std::cerr << "FAIL: cash_c32_comswap" << std::endl; failed++; }
    try { test_casah_c32_comswap(); } catch (...) { std::cerr << "FAIL: casah_c32_comswap" << std::endl; failed++; }
    try { test_casalh_c32_comswap(); } catch (...) { std::cerr << "FAIL: casalh_c32_comswap" << std::endl; failed++; }
    try { test_caslh_c32_comswap(); } catch (...) { std::cerr << "FAIL: caslh_c32_comswap" << std::endl; failed++; }
    try { test_casp_cp32_comswappr(); } catch (...) { std::cerr << "FAIL: casp_cp32_comswappr" << std::endl; failed++; }
    try { test_caspa_cp32_comswappr(); } catch (...) { std::cerr << "FAIL: caspa_cp32_comswappr" << std::endl; failed++; }
    try { test_caspal_cp32_comswappr(); } catch (...) { std::cerr << "FAIL: caspal_cp32_comswappr" << std::endl; failed++; }
    try { test_caspl_cp32_comswappr(); } catch (...) { std::cerr << "FAIL: caspl_cp32_comswappr" << std::endl; failed++; }
    try { test_casp_cp64_comswappr(); } catch (...) { std::cerr << "FAIL: casp_cp64_comswappr" << std::endl; failed++; }
    try { test_caspa_cp64_comswappr(); } catch (...) { std::cerr << "FAIL: caspa_cp64_comswappr" << std::endl; failed++; }
    try { test_caspal_cp64_comswappr(); } catch (...) { std::cerr << "FAIL: caspal_cp64_comswappr" << std::endl; failed++; }
    try { test_caspl_cp64_comswappr(); } catch (...) { std::cerr << "FAIL: caspl_cp64_comswappr" << std::endl; failed++; }
    try { test_caspt_cp64_comswappr_unpriv(); } catch (...) { std::cerr << "FAIL: caspt_cp64_comswappr_unpriv" << std::endl; failed++; }
    try { test_caspat_cp64_comswappr_unpriv(); } catch (...) { std::cerr << "FAIL: caspat_cp64_comswappr_unpriv" << std::endl; failed++; }
    try { test_caspalt_cp64_comswappr_unpriv(); } catch (...) { std::cerr << "FAIL: caspalt_cp64_comswappr_unpriv" << std::endl; failed++; }
    try { test_casplt_cp64_comswappr_unpriv(); } catch (...) { std::cerr << "FAIL: casplt_cp64_comswappr_unpriv" << std::endl; failed++; }
    try { test_cast_c64_comswap_unpriv(); } catch (...) { std::cerr << "FAIL: cast_c64_comswap_unpriv" << std::endl; failed++; }
    try { test_casat_c64_comswap_unpriv(); } catch (...) { std::cerr << "FAIL: casat_c64_comswap_unpriv" << std::endl; failed++; }
    try { test_casalt_c64_comswap_unpriv(); } catch (...) { std::cerr << "FAIL: casalt_c64_comswap_unpriv" << std::endl; failed++; }
    try { test_caslt_c64_comswap_unpriv(); } catch (...) { std::cerr << "FAIL: caslt_c64_comswap_unpriv" << std::endl; failed++; }
    try { test_cpyfp_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfp_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfm_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfm_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfe_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfe_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfen_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfen_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfprn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfprn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfern_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfern_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfprt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfprt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmrt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmrt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfert_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfert_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfprtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfprtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmrtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmrtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfertn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfertn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfprtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfprtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmrtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmrtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfertrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfertrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfprtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfprtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmrtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmrtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfertwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfertwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfet_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfet_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfptn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfptn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfetn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfetn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfptrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfptrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfetrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfetrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfptwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfptwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfetwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfetwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfewn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfewn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpwt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpwt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmwt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmwt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfewt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfewt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpwtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpwtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmwtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmwtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfewtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfewtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpwtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpwtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmwtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmwtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfewtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfewtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfpwtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfpwtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfmwtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfmwtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyfewtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyfewtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyp_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyp_cpy_memcms" << std::endl; failed++; }
    try { test_cpym_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpym_cpy_memcms" << std::endl; failed++; }
    try { test_cpye_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpye_cpy_memcms" << std::endl; failed++; }
    try { test_cpypn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyen_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyen_cpy_memcms" << std::endl; failed++; }
    try { test_cpyprn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyprn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyern_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyern_cpy_memcms" << std::endl; failed++; }
    try { test_cpyprt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyprt_cpy_memcms" << std::endl; failed++; }
    try { test_cpymrt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymrt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyert_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyert_cpy_memcms" << std::endl; failed++; }
    try { test_cpyprtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyprtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymrtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymrtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyertn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyertn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyprtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyprtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymrtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymrtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyertrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyertrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyprtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyprtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymrtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymrtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyertwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyertwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpypt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypt_cpy_memcms" << std::endl; failed++; }
    try { test_cpymt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyet_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyet_cpy_memcms" << std::endl; failed++; }
    try { test_cpyptn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyptn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyetn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyetn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyptrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyptrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyetrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyetrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyptwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyptwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyetwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyetwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpypwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyewn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyewn_cpy_memcms" << std::endl; failed++; }
    try { test_cpypwt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypwt_cpy_memcms" << std::endl; failed++; }
    try { test_cpymwt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymwt_cpy_memcms" << std::endl; failed++; }
    try { test_cpyewt_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyewt_cpy_memcms" << std::endl; failed++; }
    try { test_cpypwtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypwtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymwtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymwtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyewtn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyewtn_cpy_memcms" << std::endl; failed++; }
    try { test_cpypwtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypwtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymwtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymwtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyewtrn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyewtrn_cpy_memcms" << std::endl; failed++; }
    try { test_cpypwtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpypwtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpymwtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpymwtwn_cpy_memcms" << std::endl; failed++; }
    try { test_cpyewtwn_cpy_memcms(); } catch (...) { std::cerr << "FAIL: cpyewtwn_cpy_memcms" << std::endl; failed++; }
    try { test_gcsstr_64_ldst_gcs(); } catch (...) { std::cerr << "FAIL: gcsstr_64_ldst_gcs" << std::endl; failed++; }
    try { test_gcssttr_64_ldst_gcs(); } catch (...) { std::cerr << "FAIL: gcssttr_64_ldst_gcs" << std::endl; failed++; }
    try { test_ld1_asisdlse_r1_1v(); } catch (...) { std::cerr << "FAIL: ld1_asisdlse_r1_1v" << std::endl; failed++; }
    try { test_ld1_asisdlse_r2_2v(); } catch (...) { std::cerr << "FAIL: ld1_asisdlse_r2_2v" << std::endl; failed++; }
    try { test_ld1_asisdlse_r3_3v(); } catch (...) { std::cerr << "FAIL: ld1_asisdlse_r3_3v" << std::endl; failed++; }
    try { test_ld1_asisdlse_r4_4v(); } catch (...) { std::cerr << "FAIL: ld1_asisdlse_r4_4v" << std::endl; failed++; }
    try { test_ld1_asisdlsep_i1_i1(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_i1_i1" << std::endl; failed++; }
    try { test_ld1_asisdlsep_r1_r1(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_r1_r1" << std::endl; failed++; }
    try { test_ld1_asisdlsep_i2_i2(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_i2_i2" << std::endl; failed++; }
    try { test_ld1_asisdlsep_r2_r2(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_r2_r2" << std::endl; failed++; }
    try { test_ld1_asisdlsep_i3_i3(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_i3_i3" << std::endl; failed++; }
    try { test_ld1_asisdlsep_r3_r3(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_r3_r3" << std::endl; failed++; }
    try { test_ld1_asisdlsep_i4_i4(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_i4_i4" << std::endl; failed++; }
    try { test_ld1_asisdlsep_r4_r4(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsep_r4_r4" << std::endl; failed++; }
    try { test_ld1_asisdlso_b1_1b(); } catch (...) { std::cerr << "FAIL: ld1_asisdlso_b1_1b" << std::endl; failed++; }
    try { test_ld1_asisdlso_h1_1h(); } catch (...) { std::cerr << "FAIL: ld1_asisdlso_h1_1h" << std::endl; failed++; }
    try { test_ld1_asisdlso_s1_1s(); } catch (...) { std::cerr << "FAIL: ld1_asisdlso_s1_1s" << std::endl; failed++; }
    try { test_ld1_asisdlso_d1_1d(); } catch (...) { std::cerr << "FAIL: ld1_asisdlso_d1_1d" << std::endl; failed++; }
    try { test_ld1_asisdlsop_b1_i1b(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_b1_i1b" << std::endl; failed++; }
    try { test_ld1_asisdlsop_bx1_r1b(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_bx1_r1b" << std::endl; failed++; }
    try { test_ld1_asisdlsop_d1_i1d(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_d1_i1d" << std::endl; failed++; }
    try { test_ld1_asisdlsop_dx1_r1d(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_dx1_r1d" << std::endl; failed++; }
    try { test_ld1_asisdlsop_h1_i1h(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_h1_i1h" << std::endl; failed++; }
    try { test_ld1_asisdlsop_hx1_r1h(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_hx1_r1h" << std::endl; failed++; }
    try { test_ld1_asisdlsop_s1_i1s(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_s1_i1s" << std::endl; failed++; }
    try { test_ld1_asisdlsop_sx1_r1s(); } catch (...) { std::cerr << "FAIL: ld1_asisdlsop_sx1_r1s" << std::endl; failed++; }
    try { test_ld1r_asisdlso_r1(); } catch (...) { std::cerr << "FAIL: ld1r_asisdlso_r1" << std::endl; failed++; }
    try { test_ld1r_asisdlsop_r1_i(); } catch (...) { std::cerr << "FAIL: ld1r_asisdlsop_r1_i" << std::endl; failed++; }
    try { test_ld1r_asisdlsop_rx1_r(); } catch (...) { std::cerr << "FAIL: ld1r_asisdlsop_rx1_r" << std::endl; failed++; }
    try { test_ld2_asisdlse_r2(); } catch (...) { std::cerr << "FAIL: ld2_asisdlse_r2" << std::endl; failed++; }
    try { test_ld2_asisdlsep_i2_i(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsep_i2_i" << std::endl; failed++; }
    try { test_ld2_asisdlsep_r2_r(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsep_r2_r" << std::endl; failed++; }
    try { test_ld2_asisdlso_b2_2b(); } catch (...) { std::cerr << "FAIL: ld2_asisdlso_b2_2b" << std::endl; failed++; }
    try { test_ld2_asisdlso_h2_2h(); } catch (...) { std::cerr << "FAIL: ld2_asisdlso_h2_2h" << std::endl; failed++; }
    try { test_ld2_asisdlso_s2_2s(); } catch (...) { std::cerr << "FAIL: ld2_asisdlso_s2_2s" << std::endl; failed++; }
    try { test_ld2_asisdlso_d2_2d(); } catch (...) { std::cerr << "FAIL: ld2_asisdlso_d2_2d" << std::endl; failed++; }
    try { test_ld2_asisdlsop_b2_i2b(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_b2_i2b" << std::endl; failed++; }
    try { test_ld2_asisdlsop_bx2_r2b(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_bx2_r2b" << std::endl; failed++; }
    try { test_ld2_asisdlsop_h2_i2h(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_h2_i2h" << std::endl; failed++; }
    try { test_ld2_asisdlsop_hx2_r2h(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_hx2_r2h" << std::endl; failed++; }
    try { test_ld2_asisdlsop_s2_i2s(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_s2_i2s" << std::endl; failed++; }
    try { test_ld2_asisdlsop_sx2_r2s(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_sx2_r2s" << std::endl; failed++; }
    try { test_ld2_asisdlsop_d2_i2d(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_d2_i2d" << std::endl; failed++; }
    try { test_ld2_asisdlsop_dx2_r2d(); } catch (...) { std::cerr << "FAIL: ld2_asisdlsop_dx2_r2d" << std::endl; failed++; }
    try { test_ld2r_asisdlso_r2(); } catch (...) { std::cerr << "FAIL: ld2r_asisdlso_r2" << std::endl; failed++; }
    try { test_ld2r_asisdlsop_r2_i(); } catch (...) { std::cerr << "FAIL: ld2r_asisdlsop_r2_i" << std::endl; failed++; }
    try { test_ld2r_asisdlsop_rx2_r(); } catch (...) { std::cerr << "FAIL: ld2r_asisdlsop_rx2_r" << std::endl; failed++; }
    try { test_ld3_asisdlse_r3(); } catch (...) { std::cerr << "FAIL: ld3_asisdlse_r3" << std::endl; failed++; }
    try { test_ld3_asisdlsep_i3_i(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsep_i3_i" << std::endl; failed++; }
    try { test_ld3_asisdlsep_r3_r(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsep_r3_r" << std::endl; failed++; }
    try { test_ld3_asisdlso_b3_3b(); } catch (...) { std::cerr << "FAIL: ld3_asisdlso_b3_3b" << std::endl; failed++; }
    try { test_ld3_asisdlso_h3_3h(); } catch (...) { std::cerr << "FAIL: ld3_asisdlso_h3_3h" << std::endl; failed++; }
    try { test_ld3_asisdlso_s3_3s(); } catch (...) { std::cerr << "FAIL: ld3_asisdlso_s3_3s" << std::endl; failed++; }
    try { test_ld3_asisdlso_d3_3d(); } catch (...) { std::cerr << "FAIL: ld3_asisdlso_d3_3d" << std::endl; failed++; }
    try { test_ld3_asisdlsop_b3_i3b(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_b3_i3b" << std::endl; failed++; }
    try { test_ld3_asisdlsop_bx3_r3b(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_bx3_r3b" << std::endl; failed++; }
    try { test_ld3_asisdlsop_h3_i3h(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_h3_i3h" << std::endl; failed++; }
    try { test_ld3_asisdlsop_hx3_r3h(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_hx3_r3h" << std::endl; failed++; }
    try { test_ld3_asisdlsop_s3_i3s(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_s3_i3s" << std::endl; failed++; }
    try { test_ld3_asisdlsop_sx3_r3s(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_sx3_r3s" << std::endl; failed++; }
    try { test_ld3_asisdlsop_d3_i3d(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_d3_i3d" << std::endl; failed++; }
    try { test_ld3_asisdlsop_dx3_r3d(); } catch (...) { std::cerr << "FAIL: ld3_asisdlsop_dx3_r3d" << std::endl; failed++; }
    try { test_ld3r_asisdlso_r3(); } catch (...) { std::cerr << "FAIL: ld3r_asisdlso_r3" << std::endl; failed++; }
    try { test_ld3r_asisdlsop_r3_i(); } catch (...) { std::cerr << "FAIL: ld3r_asisdlsop_r3_i" << std::endl; failed++; }
    try { test_ld3r_asisdlsop_rx3_r(); } catch (...) { std::cerr << "FAIL: ld3r_asisdlsop_rx3_r" << std::endl; failed++; }
    try { test_ld4_asisdlse_r4(); } catch (...) { std::cerr << "FAIL: ld4_asisdlse_r4" << std::endl; failed++; }
    try { test_ld4_asisdlsep_i4_i(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsep_i4_i" << std::endl; failed++; }
    try { test_ld4_asisdlsep_r4_r(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsep_r4_r" << std::endl; failed++; }
    try { test_ld4_asisdlso_b4_4b(); } catch (...) { std::cerr << "FAIL: ld4_asisdlso_b4_4b" << std::endl; failed++; }
    try { test_ld4_asisdlso_h4_4h(); } catch (...) { std::cerr << "FAIL: ld4_asisdlso_h4_4h" << std::endl; failed++; }
    try { test_ld4_asisdlso_s4_4s(); } catch (...) { std::cerr << "FAIL: ld4_asisdlso_s4_4s" << std::endl; failed++; }
    try { test_ld4_asisdlso_d4_4d(); } catch (...) { std::cerr << "FAIL: ld4_asisdlso_d4_4d" << std::endl; failed++; }
    try { test_ld4_asisdlsop_b4_i4b(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_b4_i4b" << std::endl; failed++; }
    try { test_ld4_asisdlsop_bx4_r4b(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_bx4_r4b" << std::endl; failed++; }
    try { test_ld4_asisdlsop_h4_i4h(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_h4_i4h" << std::endl; failed++; }
    try { test_ld4_asisdlsop_hx4_r4h(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_hx4_r4h" << std::endl; failed++; }
    try { test_ld4_asisdlsop_s4_i4s(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_s4_i4s" << std::endl; failed++; }
    try { test_ld4_asisdlsop_sx4_r4s(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_sx4_r4s" << std::endl; failed++; }
    try { test_ld4_asisdlsop_d4_i4d(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_d4_i4d" << std::endl; failed++; }
    try { test_ld4_asisdlsop_dx4_r4d(); } catch (...) { std::cerr << "FAIL: ld4_asisdlsop_dx4_r4d" << std::endl; failed++; }
    try { test_ld4r_asisdlso_r4(); } catch (...) { std::cerr << "FAIL: ld4r_asisdlso_r4" << std::endl; failed++; }
    try { test_ld4r_asisdlsop_r4_i(); } catch (...) { std::cerr << "FAIL: ld4r_asisdlsop_r4_i" << std::endl; failed++; }
    try { test_ld4r_asisdlsop_rx4_r(); } catch (...) { std::cerr << "FAIL: ld4r_asisdlsop_rx4_r" << std::endl; failed++; }
    try { test_ld64b_64l_memop(); } catch (...) { std::cerr << "FAIL: ld64b_64l_memop" << std::endl; failed++; }
    try { test_ldadd_32_memop(); } catch (...) { std::cerr << "FAIL: ldadd_32_memop" << std::endl; failed++; }
    try { test_ldadda_32_memop(); } catch (...) { std::cerr << "FAIL: ldadda_32_memop" << std::endl; failed++; }
    try { test_ldaddal_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddal_32_memop" << std::endl; failed++; }
    try { test_ldaddl_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddl_32_memop" << std::endl; failed++; }
    try { test_ldadd_64_memop(); } catch (...) { std::cerr << "FAIL: ldadd_64_memop" << std::endl; failed++; }
    try { test_ldadda_64_memop(); } catch (...) { std::cerr << "FAIL: ldadda_64_memop" << std::endl; failed++; }
    try { test_ldaddal_64_memop(); } catch (...) { std::cerr << "FAIL: ldaddal_64_memop" << std::endl; failed++; }
    try { test_ldaddl_64_memop(); } catch (...) { std::cerr << "FAIL: ldaddl_64_memop" << std::endl; failed++; }
    try { test_ldaddb_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddb_32_memop" << std::endl; failed++; }
    try { test_ldaddab_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddab_32_memop" << std::endl; failed++; }
    try { test_ldaddalb_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddalb_32_memop" << std::endl; failed++; }
    try { test_ldaddlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddlb_32_memop" << std::endl; failed++; }
    try { test_ldaddh_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddh_32_memop" << std::endl; failed++; }
    try { test_ldaddah_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddah_32_memop" << std::endl; failed++; }
    try { test_ldaddalh_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddalh_32_memop" << std::endl; failed++; }
    try { test_ldaddlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldaddlh_32_memop" << std::endl; failed++; }
    try { test_ldap1_asisdlso_d1(); } catch (...) { std::cerr << "FAIL: ldap1_asisdlso_d1" << std::endl; failed++; }
    try { test_ldap_64_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldap_64_ldiappstilp" << std::endl; failed++; }
    try { test_ldapp_64_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldapp_64_ldiappstilp" << std::endl; failed++; }
    try { test_ldapr_32l_ldapstl_writeback(); } catch (...) { std::cerr << "FAIL: ldapr_32l_ldapstl_writeback" << std::endl; failed++; }
    try { test_ldapr_64l_ldapstl_writeback(); } catch (...) { std::cerr << "FAIL: ldapr_64l_ldapstl_writeback" << std::endl; failed++; }
    try { test_ldapr_32l_memop(); } catch (...) { std::cerr << "FAIL: ldapr_32l_memop" << std::endl; failed++; }
    try { test_ldapr_64l_memop(); } catch (...) { std::cerr << "FAIL: ldapr_64l_memop" << std::endl; failed++; }
    try { test_ldaprb_32l_memop(); } catch (...) { std::cerr << "FAIL: ldaprb_32l_memop" << std::endl; failed++; }
    try { test_ldaprh_32l_memop(); } catch (...) { std::cerr << "FAIL: ldaprh_32l_memop" << std::endl; failed++; }
    try { test_ldapur_b_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: ldapur_b_ldapstl_simd" << std::endl; failed++; }
    try { test_ldapur_h_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: ldapur_h_ldapstl_simd" << std::endl; failed++; }
    try { test_ldapur_s_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: ldapur_s_ldapstl_simd" << std::endl; failed++; }
    try { test_ldapur_d_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: ldapur_d_ldapstl_simd" << std::endl; failed++; }
    try { test_ldapur_q_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: ldapur_q_ldapstl_simd" << std::endl; failed++; }
    try { test_ldapur_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapur_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapur_64_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapur_64_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapurb_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapurb_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapurh_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapurh_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapursb_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapursb_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapursb_64_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapursb_64_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapursh_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapursh_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapursh_64_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapursh_64_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldapursw_64_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: ldapursw_64_ldapstl_unscaled" << std::endl; failed++; }
    try { test_ldar_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldar_lr32_ldstord" << std::endl; failed++; }
    try { test_ldar_lr64_ldstord(); } catch (...) { std::cerr << "FAIL: ldar_lr64_ldstord" << std::endl; failed++; }
    try { test_ldarb_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldarb_lr32_ldstord" << std::endl; failed++; }
    try { test_ldarh_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldarh_lr32_ldstord" << std::endl; failed++; }
    try { test_ldatxr_lr32_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: ldatxr_lr32_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_ldatxr_lr64_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: ldatxr_lr64_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_ldaxp_lp32_ldstexclp(); } catch (...) { std::cerr << "FAIL: ldaxp_lp32_ldstexclp" << std::endl; failed++; }
    try { test_ldaxp_lp64_ldstexclp(); } catch (...) { std::cerr << "FAIL: ldaxp_lp64_ldstexclp" << std::endl; failed++; }
    try { test_ldaxr_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldaxr_lr32_ldstexclr" << std::endl; failed++; }
    try { test_ldaxr_lr64_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldaxr_lr64_ldstexclr" << std::endl; failed++; }
    try { test_ldaxrb_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldaxrb_lr32_ldstexclr" << std::endl; failed++; }
    try { test_ldaxrh_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldaxrh_lr32_ldstexclr" << std::endl; failed++; }
    try { test_ldbfadd_16(); } catch (...) { std::cerr << "FAIL: ldbfadd_16" << std::endl; failed++; }
    try { test_ldbfadda_16(); } catch (...) { std::cerr << "FAIL: ldbfadda_16" << std::endl; failed++; }
    try { test_ldbfaddal_16(); } catch (...) { std::cerr << "FAIL: ldbfaddal_16" << std::endl; failed++; }
    try { test_ldbfaddl_16(); } catch (...) { std::cerr << "FAIL: ldbfaddl_16" << std::endl; failed++; }
    try { test_ldbfmax_16(); } catch (...) { std::cerr << "FAIL: ldbfmax_16" << std::endl; failed++; }
    try { test_ldbfmaxa_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxa_16" << std::endl; failed++; }
    try { test_ldbfmaxal_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxal_16" << std::endl; failed++; }
    try { test_ldbfmaxl_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxl_16" << std::endl; failed++; }
    try { test_ldbfmaxnm_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxnm_16" << std::endl; failed++; }
    try { test_ldbfmaxnma_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxnma_16" << std::endl; failed++; }
    try { test_ldbfmaxnmal_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxnmal_16" << std::endl; failed++; }
    try { test_ldbfmaxnml_16(); } catch (...) { std::cerr << "FAIL: ldbfmaxnml_16" << std::endl; failed++; }
    try { test_ldbfmin_16(); } catch (...) { std::cerr << "FAIL: ldbfmin_16" << std::endl; failed++; }
    try { test_ldbfmina_16(); } catch (...) { std::cerr << "FAIL: ldbfmina_16" << std::endl; failed++; }
    try { test_ldbfminal_16(); } catch (...) { std::cerr << "FAIL: ldbfminal_16" << std::endl; failed++; }
    try { test_ldbfminl_16(); } catch (...) { std::cerr << "FAIL: ldbfminl_16" << std::endl; failed++; }
    try { test_ldbfminnm_16(); } catch (...) { std::cerr << "FAIL: ldbfminnm_16" << std::endl; failed++; }
    try { test_ldbfminnma_16(); } catch (...) { std::cerr << "FAIL: ldbfminnma_16" << std::endl; failed++; }
    try { test_ldbfminnmal_16(); } catch (...) { std::cerr << "FAIL: ldbfminnmal_16" << std::endl; failed++; }
    try { test_ldbfminnml_16(); } catch (...) { std::cerr << "FAIL: ldbfminnml_16" << std::endl; failed++; }
    try { test_ldclr_32_memop(); } catch (...) { std::cerr << "FAIL: ldclr_32_memop" << std::endl; failed++; }
    try { test_ldclra_32_memop(); } catch (...) { std::cerr << "FAIL: ldclra_32_memop" << std::endl; failed++; }
    try { test_ldclral_32_memop(); } catch (...) { std::cerr << "FAIL: ldclral_32_memop" << std::endl; failed++; }
    try { test_ldclrl_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrl_32_memop" << std::endl; failed++; }
    try { test_ldclr_64_memop(); } catch (...) { std::cerr << "FAIL: ldclr_64_memop" << std::endl; failed++; }
    try { test_ldclra_64_memop(); } catch (...) { std::cerr << "FAIL: ldclra_64_memop" << std::endl; failed++; }
    try { test_ldclral_64_memop(); } catch (...) { std::cerr << "FAIL: ldclral_64_memop" << std::endl; failed++; }
    try { test_ldclrl_64_memop(); } catch (...) { std::cerr << "FAIL: ldclrl_64_memop" << std::endl; failed++; }
    try { test_ldclrb_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrb_32_memop" << std::endl; failed++; }
    try { test_ldclrab_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrab_32_memop" << std::endl; failed++; }
    try { test_ldclralb_32_memop(); } catch (...) { std::cerr << "FAIL: ldclralb_32_memop" << std::endl; failed++; }
    try { test_ldclrlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrlb_32_memop" << std::endl; failed++; }
    try { test_ldclrh_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrh_32_memop" << std::endl; failed++; }
    try { test_ldclrah_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrah_32_memop" << std::endl; failed++; }
    try { test_ldclralh_32_memop(); } catch (...) { std::cerr << "FAIL: ldclralh_32_memop" << std::endl; failed++; }
    try { test_ldclrlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldclrlh_32_memop" << std::endl; failed++; }
    try { test_ldclrp_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldclrp_128_memop_128" << std::endl; failed++; }
    try { test_ldclrpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldclrpa_128_memop_128" << std::endl; failed++; }
    try { test_ldclrpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldclrpal_128_memop_128" << std::endl; failed++; }
    try { test_ldclrpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldclrpl_128_memop_128" << std::endl; failed++; }
    try { test_ldeor_32_memop(); } catch (...) { std::cerr << "FAIL: ldeor_32_memop" << std::endl; failed++; }
    try { test_ldeora_32_memop(); } catch (...) { std::cerr << "FAIL: ldeora_32_memop" << std::endl; failed++; }
    try { test_ldeoral_32_memop(); } catch (...) { std::cerr << "FAIL: ldeoral_32_memop" << std::endl; failed++; }
    try { test_ldeorl_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorl_32_memop" << std::endl; failed++; }
    try { test_ldeor_64_memop(); } catch (...) { std::cerr << "FAIL: ldeor_64_memop" << std::endl; failed++; }
    try { test_ldeora_64_memop(); } catch (...) { std::cerr << "FAIL: ldeora_64_memop" << std::endl; failed++; }
    try { test_ldeoral_64_memop(); } catch (...) { std::cerr << "FAIL: ldeoral_64_memop" << std::endl; failed++; }
    try { test_ldeorl_64_memop(); } catch (...) { std::cerr << "FAIL: ldeorl_64_memop" << std::endl; failed++; }
    try { test_ldeorb_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorb_32_memop" << std::endl; failed++; }
    try { test_ldeorab_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorab_32_memop" << std::endl; failed++; }
    try { test_ldeoralb_32_memop(); } catch (...) { std::cerr << "FAIL: ldeoralb_32_memop" << std::endl; failed++; }
    try { test_ldeorlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorlb_32_memop" << std::endl; failed++; }
    try { test_ldeorh_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorh_32_memop" << std::endl; failed++; }
    try { test_ldeorah_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorah_32_memop" << std::endl; failed++; }
    try { test_ldeoralh_32_memop(); } catch (...) { std::cerr << "FAIL: ldeoralh_32_memop" << std::endl; failed++; }
    try { test_ldeorlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldeorlh_32_memop" << std::endl; failed++; }
    try { test_ldfadd_16(); } catch (...) { std::cerr << "FAIL: ldfadd_16" << std::endl; failed++; }
    try { test_ldfadda_16(); } catch (...) { std::cerr << "FAIL: ldfadda_16" << std::endl; failed++; }
    try { test_ldfaddal_16(); } catch (...) { std::cerr << "FAIL: ldfaddal_16" << std::endl; failed++; }
    try { test_ldfaddl_16(); } catch (...) { std::cerr << "FAIL: ldfaddl_16" << std::endl; failed++; }
    try { test_ldfadd_32(); } catch (...) { std::cerr << "FAIL: ldfadd_32" << std::endl; failed++; }
    try { test_ldfadda_32(); } catch (...) { std::cerr << "FAIL: ldfadda_32" << std::endl; failed++; }
    try { test_ldfaddal_32(); } catch (...) { std::cerr << "FAIL: ldfaddal_32" << std::endl; failed++; }
    try { test_ldfaddl_32(); } catch (...) { std::cerr << "FAIL: ldfaddl_32" << std::endl; failed++; }
    try { test_ldfadd_64(); } catch (...) { std::cerr << "FAIL: ldfadd_64" << std::endl; failed++; }
    try { test_ldfadda_64(); } catch (...) { std::cerr << "FAIL: ldfadda_64" << std::endl; failed++; }
    try { test_ldfaddal_64(); } catch (...) { std::cerr << "FAIL: ldfaddal_64" << std::endl; failed++; }
    try { test_ldfaddl_64(); } catch (...) { std::cerr << "FAIL: ldfaddl_64" << std::endl; failed++; }
    try { test_ldfmax_16(); } catch (...) { std::cerr << "FAIL: ldfmax_16" << std::endl; failed++; }
    try { test_ldfmaxa_16(); } catch (...) { std::cerr << "FAIL: ldfmaxa_16" << std::endl; failed++; }
    try { test_ldfmaxal_16(); } catch (...) { std::cerr << "FAIL: ldfmaxal_16" << std::endl; failed++; }
    try { test_ldfmaxl_16(); } catch (...) { std::cerr << "FAIL: ldfmaxl_16" << std::endl; failed++; }
    try { test_ldfmax_32(); } catch (...) { std::cerr << "FAIL: ldfmax_32" << std::endl; failed++; }
    try { test_ldfmaxa_32(); } catch (...) { std::cerr << "FAIL: ldfmaxa_32" << std::endl; failed++; }
    try { test_ldfmaxal_32(); } catch (...) { std::cerr << "FAIL: ldfmaxal_32" << std::endl; failed++; }
    try { test_ldfmaxl_32(); } catch (...) { std::cerr << "FAIL: ldfmaxl_32" << std::endl; failed++; }
    try { test_ldfmax_64(); } catch (...) { std::cerr << "FAIL: ldfmax_64" << std::endl; failed++; }
    try { test_ldfmaxa_64(); } catch (...) { std::cerr << "FAIL: ldfmaxa_64" << std::endl; failed++; }
    try { test_ldfmaxal_64(); } catch (...) { std::cerr << "FAIL: ldfmaxal_64" << std::endl; failed++; }
    try { test_ldfmaxl_64(); } catch (...) { std::cerr << "FAIL: ldfmaxl_64" << std::endl; failed++; }
    try { test_ldfmaxnm_16(); } catch (...) { std::cerr << "FAIL: ldfmaxnm_16" << std::endl; failed++; }
    try { test_ldfmaxnma_16(); } catch (...) { std::cerr << "FAIL: ldfmaxnma_16" << std::endl; failed++; }
    try { test_ldfmaxnmal_16(); } catch (...) { std::cerr << "FAIL: ldfmaxnmal_16" << std::endl; failed++; }
    try { test_ldfmaxnml_16(); } catch (...) { std::cerr << "FAIL: ldfmaxnml_16" << std::endl; failed++; }
    try { test_ldfmaxnm_32(); } catch (...) { std::cerr << "FAIL: ldfmaxnm_32" << std::endl; failed++; }
    try { test_ldfmaxnma_32(); } catch (...) { std::cerr << "FAIL: ldfmaxnma_32" << std::endl; failed++; }
    try { test_ldfmaxnmal_32(); } catch (...) { std::cerr << "FAIL: ldfmaxnmal_32" << std::endl; failed++; }
    try { test_ldfmaxnml_32(); } catch (...) { std::cerr << "FAIL: ldfmaxnml_32" << std::endl; failed++; }
    try { test_ldfmaxnm_64(); } catch (...) { std::cerr << "FAIL: ldfmaxnm_64" << std::endl; failed++; }
    try { test_ldfmaxnma_64(); } catch (...) { std::cerr << "FAIL: ldfmaxnma_64" << std::endl; failed++; }
    try { test_ldfmaxnmal_64(); } catch (...) { std::cerr << "FAIL: ldfmaxnmal_64" << std::endl; failed++; }
    try { test_ldfmaxnml_64(); } catch (...) { std::cerr << "FAIL: ldfmaxnml_64" << std::endl; failed++; }
    try { test_ldfmin_16(); } catch (...) { std::cerr << "FAIL: ldfmin_16" << std::endl; failed++; }
    try { test_ldfmina_16(); } catch (...) { std::cerr << "FAIL: ldfmina_16" << std::endl; failed++; }
    try { test_ldfminal_16(); } catch (...) { std::cerr << "FAIL: ldfminal_16" << std::endl; failed++; }
    try { test_ldfminl_16(); } catch (...) { std::cerr << "FAIL: ldfminl_16" << std::endl; failed++; }
    try { test_ldfmin_32(); } catch (...) { std::cerr << "FAIL: ldfmin_32" << std::endl; failed++; }
    try { test_ldfmina_32(); } catch (...) { std::cerr << "FAIL: ldfmina_32" << std::endl; failed++; }
    try { test_ldfminal_32(); } catch (...) { std::cerr << "FAIL: ldfminal_32" << std::endl; failed++; }
    try { test_ldfminl_32(); } catch (...) { std::cerr << "FAIL: ldfminl_32" << std::endl; failed++; }
    try { test_ldfmin_64(); } catch (...) { std::cerr << "FAIL: ldfmin_64" << std::endl; failed++; }
    try { test_ldfmina_64(); } catch (...) { std::cerr << "FAIL: ldfmina_64" << std::endl; failed++; }
    try { test_ldfminal_64(); } catch (...) { std::cerr << "FAIL: ldfminal_64" << std::endl; failed++; }
    try { test_ldfminl_64(); } catch (...) { std::cerr << "FAIL: ldfminl_64" << std::endl; failed++; }
    try { test_ldfminnm_16(); } catch (...) { std::cerr << "FAIL: ldfminnm_16" << std::endl; failed++; }
    try { test_ldfminnma_16(); } catch (...) { std::cerr << "FAIL: ldfminnma_16" << std::endl; failed++; }
    try { test_ldfminnmal_16(); } catch (...) { std::cerr << "FAIL: ldfminnmal_16" << std::endl; failed++; }
    try { test_ldfminnml_16(); } catch (...) { std::cerr << "FAIL: ldfminnml_16" << std::endl; failed++; }
    try { test_ldfminnm_32(); } catch (...) { std::cerr << "FAIL: ldfminnm_32" << std::endl; failed++; }
    try { test_ldfminnma_32(); } catch (...) { std::cerr << "FAIL: ldfminnma_32" << std::endl; failed++; }
    try { test_ldfminnmal_32(); } catch (...) { std::cerr << "FAIL: ldfminnmal_32" << std::endl; failed++; }
    try { test_ldfminnml_32(); } catch (...) { std::cerr << "FAIL: ldfminnml_32" << std::endl; failed++; }
    try { test_ldfminnm_64(); } catch (...) { std::cerr << "FAIL: ldfminnm_64" << std::endl; failed++; }
    try { test_ldfminnma_64(); } catch (...) { std::cerr << "FAIL: ldfminnma_64" << std::endl; failed++; }
    try { test_ldfminnmal_64(); } catch (...) { std::cerr << "FAIL: ldfminnmal_64" << std::endl; failed++; }
    try { test_ldfminnml_64(); } catch (...) { std::cerr << "FAIL: ldfminnml_64" << std::endl; failed++; }
    try { test_ldg_64loffset_ldsttags(); } catch (...) { std::cerr << "FAIL: ldg_64loffset_ldsttags" << std::endl; failed++; }
    try { test_ldgm_64bulk_ldsttags(); } catch (...) { std::cerr << "FAIL: ldgm_64bulk_ldsttags" << std::endl; failed++; }
    try { test_ldiapp_32le_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldiapp_32le_ldiappstilp" << std::endl; failed++; }
    try { test_ldiapp_32l_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldiapp_32l_ldiappstilp" << std::endl; failed++; }
    try { test_ldiapp_64ls_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldiapp_64ls_ldiappstilp" << std::endl; failed++; }
    try { test_ldiapp_64l_ldiappstilp(); } catch (...) { std::cerr << "FAIL: ldiapp_64l_ldiappstilp" << std::endl; failed++; }
    try { test_ldlar_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldlar_lr32_ldstord" << std::endl; failed++; }
    try { test_ldlar_lr64_ldstord(); } catch (...) { std::cerr << "FAIL: ldlar_lr64_ldstord" << std::endl; failed++; }
    try { test_ldlarb_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldlarb_lr32_ldstord" << std::endl; failed++; }
    try { test_ldlarh_lr32_ldstord(); } catch (...) { std::cerr << "FAIL: ldlarh_lr32_ldstord" << std::endl; failed++; }
    try { test_ldnp_s_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldnp_s_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldnp_d_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldnp_d_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldnp_q_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldnp_q_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldnp_32_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldnp_32_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldnp_64_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldnp_64_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldp_s_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldp_s_ldstpair_post" << std::endl; failed++; }
    try { test_ldp_d_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldp_d_ldstpair_post" << std::endl; failed++; }
    try { test_ldp_q_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldp_q_ldstpair_post" << std::endl; failed++; }
    try { test_ldp_s_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldp_s_ldstpair_pre" << std::endl; failed++; }
    try { test_ldp_d_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldp_d_ldstpair_pre" << std::endl; failed++; }
    try { test_ldp_q_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldp_q_ldstpair_pre" << std::endl; failed++; }
    try { test_ldp_s_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldp_s_ldstpair_off" << std::endl; failed++; }
    try { test_ldp_d_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldp_d_ldstpair_off" << std::endl; failed++; }
    try { test_ldp_q_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldp_q_ldstpair_off" << std::endl; failed++; }
    try { test_ldp_32_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldp_32_ldstpair_post" << std::endl; failed++; }
    try { test_ldp_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldp_64_ldstpair_post" << std::endl; failed++; }
    try { test_ldp_32_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldp_32_ldstpair_pre" << std::endl; failed++; }
    try { test_ldp_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldp_64_ldstpair_pre" << std::endl; failed++; }
    try { test_ldp_32_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldp_32_ldstpair_off" << std::endl; failed++; }
    try { test_ldp_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldp_64_ldstpair_off" << std::endl; failed++; }
    try { test_ldpsw_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldpsw_64_ldstpair_post" << std::endl; failed++; }
    try { test_ldpsw_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldpsw_64_ldstpair_pre" << std::endl; failed++; }
    try { test_ldpsw_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldpsw_64_ldstpair_off" << std::endl; failed++; }
    try { test_ldr_b_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_b_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_h_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_h_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_s_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_s_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_d_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_d_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_q_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_q_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_b_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_b_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_h_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_h_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_s_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_s_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_d_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_d_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_q_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_q_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_b_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_b_ldst_pos" << std::endl; failed++; }
    try { test_ldr_h_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_h_ldst_pos" << std::endl; failed++; }
    try { test_ldr_s_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_s_ldst_pos" << std::endl; failed++; }
    try { test_ldr_d_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_d_ldst_pos" << std::endl; failed++; }
    try { test_ldr_q_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_q_ldst_pos" << std::endl; failed++; }
    try { test_ldr_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_32_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_64_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldr_64_ldst_immpost" << std::endl; failed++; }
    try { test_ldr_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_32_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_64_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldr_64_ldst_immpre" << std::endl; failed++; }
    try { test_ldr_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_32_ldst_pos" << std::endl; failed++; }
    try { test_ldr_64_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldr_64_ldst_pos" << std::endl; failed++; }
    try { test_ldr_s_loadlit(); } catch (...) { std::cerr << "FAIL: ldr_s_loadlit" << std::endl; failed++; }
    try { test_ldr_d_loadlit(); } catch (...) { std::cerr << "FAIL: ldr_d_loadlit" << std::endl; failed++; }
    try { test_ldr_q_loadlit(); } catch (...) { std::cerr << "FAIL: ldr_q_loadlit" << std::endl; failed++; }
    try { test_ldr_32_loadlit(); } catch (...) { std::cerr << "FAIL: ldr_32_loadlit" << std::endl; failed++; }
    try { test_ldr_64_loadlit(); } catch (...) { std::cerr << "FAIL: ldr_64_loadlit" << std::endl; failed++; }
    try { test_ldr_b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_b_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_bl_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_h_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_h_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_s_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_s_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_d_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_d_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_q_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_q_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_32_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_32_ldst_regoff" << std::endl; failed++; }
    try { test_ldr_64_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldr_64_ldst_regoff" << std::endl; failed++; }
    try { test_ldraa_64_ldst_pac(); } catch (...) { std::cerr << "FAIL: ldraa_64_ldst_pac" << std::endl; failed++; }
    try { test_ldraa_64w_ldst_pac(); } catch (...) { std::cerr << "FAIL: ldraa_64w_ldst_pac" << std::endl; failed++; }
    try { test_ldrab_64_ldst_pac(); } catch (...) { std::cerr << "FAIL: ldrab_64_ldst_pac" << std::endl; failed++; }
    try { test_ldrab_64w_ldst_pac(); } catch (...) { std::cerr << "FAIL: ldrab_64w_ldst_pac" << std::endl; failed++; }
    try { test_ldrb_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrb_32_ldst_immpost" << std::endl; failed++; }
    try { test_ldrb_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrb_32_ldst_immpre" << std::endl; failed++; }
    try { test_ldrb_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrb_32_ldst_pos" << std::endl; failed++; }
    try { test_ldrb_32b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrb_32b_ldst_regoff" << std::endl; failed++; }
    try { test_ldrb_32bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrb_32bl_ldst_regoff" << std::endl; failed++; }
    try { test_ldrh_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrh_32_ldst_immpost" << std::endl; failed++; }
    try { test_ldrh_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrh_32_ldst_immpre" << std::endl; failed++; }
    try { test_ldrh_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrh_32_ldst_pos" << std::endl; failed++; }
    try { test_ldrh_32_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrh_32_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsb_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrsb_32_ldst_immpost" << std::endl; failed++; }
    try { test_ldrsb_64_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrsb_64_ldst_immpost" << std::endl; failed++; }
    try { test_ldrsb_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrsb_32_ldst_immpre" << std::endl; failed++; }
    try { test_ldrsb_64_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrsb_64_ldst_immpre" << std::endl; failed++; }
    try { test_ldrsb_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrsb_32_ldst_pos" << std::endl; failed++; }
    try { test_ldrsb_64_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrsb_64_ldst_pos" << std::endl; failed++; }
    try { test_ldrsb_32b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsb_32b_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsb_32bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsb_32bl_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsb_64b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsb_64b_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsb_64bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsb_64bl_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsh_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrsh_32_ldst_immpost" << std::endl; failed++; }
    try { test_ldrsh_64_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrsh_64_ldst_immpost" << std::endl; failed++; }
    try { test_ldrsh_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrsh_32_ldst_immpre" << std::endl; failed++; }
    try { test_ldrsh_64_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrsh_64_ldst_immpre" << std::endl; failed++; }
    try { test_ldrsh_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrsh_32_ldst_pos" << std::endl; failed++; }
    try { test_ldrsh_64_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrsh_64_ldst_pos" << std::endl; failed++; }
    try { test_ldrsh_32_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsh_32_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsh_64_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsh_64_ldst_regoff" << std::endl; failed++; }
    try { test_ldrsw_64_ldst_immpost(); } catch (...) { std::cerr << "FAIL: ldrsw_64_ldst_immpost" << std::endl; failed++; }
    try { test_ldrsw_64_ldst_immpre(); } catch (...) { std::cerr << "FAIL: ldrsw_64_ldst_immpre" << std::endl; failed++; }
    try { test_ldrsw_64_ldst_pos(); } catch (...) { std::cerr << "FAIL: ldrsw_64_ldst_pos" << std::endl; failed++; }
    try { test_ldrsw_64_loadlit(); } catch (...) { std::cerr << "FAIL: ldrsw_64_loadlit" << std::endl; failed++; }
    try { test_ldrsw_64_ldst_regoff(); } catch (...) { std::cerr << "FAIL: ldrsw_64_ldst_regoff" << std::endl; failed++; }
    try { test_ldset_32_memop(); } catch (...) { std::cerr << "FAIL: ldset_32_memop" << std::endl; failed++; }
    try { test_ldseta_32_memop(); } catch (...) { std::cerr << "FAIL: ldseta_32_memop" << std::endl; failed++; }
    try { test_ldsetal_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetal_32_memop" << std::endl; failed++; }
    try { test_ldsetl_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetl_32_memop" << std::endl; failed++; }
    try { test_ldset_64_memop(); } catch (...) { std::cerr << "FAIL: ldset_64_memop" << std::endl; failed++; }
    try { test_ldseta_64_memop(); } catch (...) { std::cerr << "FAIL: ldseta_64_memop" << std::endl; failed++; }
    try { test_ldsetal_64_memop(); } catch (...) { std::cerr << "FAIL: ldsetal_64_memop" << std::endl; failed++; }
    try { test_ldsetl_64_memop(); } catch (...) { std::cerr << "FAIL: ldsetl_64_memop" << std::endl; failed++; }
    try { test_ldsetb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetb_32_memop" << std::endl; failed++; }
    try { test_ldsetab_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetab_32_memop" << std::endl; failed++; }
    try { test_ldsetalb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetalb_32_memop" << std::endl; failed++; }
    try { test_ldsetlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetlb_32_memop" << std::endl; failed++; }
    try { test_ldseth_32_memop(); } catch (...) { std::cerr << "FAIL: ldseth_32_memop" << std::endl; failed++; }
    try { test_ldsetah_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetah_32_memop" << std::endl; failed++; }
    try { test_ldsetalh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetalh_32_memop" << std::endl; failed++; }
    try { test_ldsetlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsetlh_32_memop" << std::endl; failed++; }
    try { test_ldsetp_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldsetp_128_memop_128" << std::endl; failed++; }
    try { test_ldsetpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldsetpa_128_memop_128" << std::endl; failed++; }
    try { test_ldsetpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldsetpal_128_memop_128" << std::endl; failed++; }
    try { test_ldsetpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: ldsetpl_128_memop_128" << std::endl; failed++; }
    try { test_ldsmax_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmax_32_memop" << std::endl; failed++; }
    try { test_ldsmaxa_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxa_32_memop" << std::endl; failed++; }
    try { test_ldsmaxal_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxal_32_memop" << std::endl; failed++; }
    try { test_ldsmaxl_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxl_32_memop" << std::endl; failed++; }
    try { test_ldsmax_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmax_64_memop" << std::endl; failed++; }
    try { test_ldsmaxa_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxa_64_memop" << std::endl; failed++; }
    try { test_ldsmaxal_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxal_64_memop" << std::endl; failed++; }
    try { test_ldsmaxl_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxl_64_memop" << std::endl; failed++; }
    try { test_ldsmaxb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxb_32_memop" << std::endl; failed++; }
    try { test_ldsmaxab_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxab_32_memop" << std::endl; failed++; }
    try { test_ldsmaxalb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxalb_32_memop" << std::endl; failed++; }
    try { test_ldsmaxlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxlb_32_memop" << std::endl; failed++; }
    try { test_ldsmaxh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxh_32_memop" << std::endl; failed++; }
    try { test_ldsmaxah_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxah_32_memop" << std::endl; failed++; }
    try { test_ldsmaxalh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxalh_32_memop" << std::endl; failed++; }
    try { test_ldsmaxlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmaxlh_32_memop" << std::endl; failed++; }
    try { test_ldsmin_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmin_32_memop" << std::endl; failed++; }
    try { test_ldsmina_32_memop(); } catch (...) { std::cerr << "FAIL: ldsmina_32_memop" << std::endl; failed++; }
    try { test_ldsminal_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminal_32_memop" << std::endl; failed++; }
    try { test_ldsminl_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminl_32_memop" << std::endl; failed++; }
    try { test_ldsmin_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmin_64_memop" << std::endl; failed++; }
    try { test_ldsmina_64_memop(); } catch (...) { std::cerr << "FAIL: ldsmina_64_memop" << std::endl; failed++; }
    try { test_ldsminal_64_memop(); } catch (...) { std::cerr << "FAIL: ldsminal_64_memop" << std::endl; failed++; }
    try { test_ldsminl_64_memop(); } catch (...) { std::cerr << "FAIL: ldsminl_64_memop" << std::endl; failed++; }
    try { test_ldsminb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminb_32_memop" << std::endl; failed++; }
    try { test_ldsminab_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminab_32_memop" << std::endl; failed++; }
    try { test_ldsminalb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminalb_32_memop" << std::endl; failed++; }
    try { test_ldsminlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminlb_32_memop" << std::endl; failed++; }
    try { test_ldsminh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminh_32_memop" << std::endl; failed++; }
    try { test_ldsminah_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminah_32_memop" << std::endl; failed++; }
    try { test_ldsminalh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminalh_32_memop" << std::endl; failed++; }
    try { test_ldsminlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldsminlh_32_memop" << std::endl; failed++; }
    try { test_ldtadd_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtadd_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtadda_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtadda_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtaddal_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtaddal_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtaddl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtaddl_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtadd_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtadd_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtadda_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtadda_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtaddal_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtaddal_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtaddl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtaddl_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclr_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclr_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclra_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclra_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclral_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclral_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclrl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclrl_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclr_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclr_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclra_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclra_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclral_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclral_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtclrl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtclrl_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtnp_q_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldtnp_q_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldtnp_64_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: ldtnp_64_ldstnapair_offs" << std::endl; failed++; }
    try { test_ldtp_q_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldtp_q_ldstpair_post" << std::endl; failed++; }
    try { test_ldtp_q_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldtp_q_ldstpair_pre" << std::endl; failed++; }
    try { test_ldtp_q_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldtp_q_ldstpair_off" << std::endl; failed++; }
    try { test_ldtp_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: ldtp_64_ldstpair_post" << std::endl; failed++; }
    try { test_ldtp_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: ldtp_64_ldstpair_pre" << std::endl; failed++; }
    try { test_ldtp_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: ldtp_64_ldstpair_off" << std::endl; failed++; }
    try { test_ldtr_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtr_32_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtr_64_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtr_64_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrb_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrb_32_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrh_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrh_32_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrsb_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrsb_32_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrsb_64_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrsb_64_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrsh_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrsh_32_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrsh_64_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrsh_64_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtrsw_64_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: ldtrsw_64_ldst_unpriv" << std::endl; failed++; }
    try { test_ldtset_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtset_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtseta_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtseta_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtsetal_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtsetal_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtsetl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtsetl_32_memop_unpriv" << std::endl; failed++; }
    try { test_ldtset_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtset_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtseta_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtseta_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtsetal_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtsetal_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtsetl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: ldtsetl_64_memop_unpriv" << std::endl; failed++; }
    try { test_ldtxr_lr32_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: ldtxr_lr32_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_ldtxr_lr64_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: ldtxr_lr64_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_ldumax_32_memop(); } catch (...) { std::cerr << "FAIL: ldumax_32_memop" << std::endl; failed++; }
    try { test_ldumaxa_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxa_32_memop" << std::endl; failed++; }
    try { test_ldumaxal_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxal_32_memop" << std::endl; failed++; }
    try { test_ldumaxl_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxl_32_memop" << std::endl; failed++; }
    try { test_ldumax_64_memop(); } catch (...) { std::cerr << "FAIL: ldumax_64_memop" << std::endl; failed++; }
    try { test_ldumaxa_64_memop(); } catch (...) { std::cerr << "FAIL: ldumaxa_64_memop" << std::endl; failed++; }
    try { test_ldumaxal_64_memop(); } catch (...) { std::cerr << "FAIL: ldumaxal_64_memop" << std::endl; failed++; }
    try { test_ldumaxl_64_memop(); } catch (...) { std::cerr << "FAIL: ldumaxl_64_memop" << std::endl; failed++; }
    try { test_ldumaxb_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxb_32_memop" << std::endl; failed++; }
    try { test_ldumaxab_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxab_32_memop" << std::endl; failed++; }
    try { test_ldumaxalb_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxalb_32_memop" << std::endl; failed++; }
    try { test_ldumaxlb_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxlb_32_memop" << std::endl; failed++; }
    try { test_ldumaxh_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxh_32_memop" << std::endl; failed++; }
    try { test_ldumaxah_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxah_32_memop" << std::endl; failed++; }
    try { test_ldumaxalh_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxalh_32_memop" << std::endl; failed++; }
    try { test_ldumaxlh_32_memop(); } catch (...) { std::cerr << "FAIL: ldumaxlh_32_memop" << std::endl; failed++; }
    try { test_ldumin_32_memop(); } catch (...) { std::cerr << "FAIL: ldumin_32_memop" << std::endl; failed++; }
    try { test_ldumina_32_memop(); } catch (...) { std::cerr << "FAIL: ldumina_32_memop" << std::endl; failed++; }
    try { test_lduminal_32_memop(); } catch (...) { std::cerr << "FAIL: lduminal_32_memop" << std::endl; failed++; }
    try { test_lduminl_32_memop(); } catch (...) { std::cerr << "FAIL: lduminl_32_memop" << std::endl; failed++; }
    try { test_ldumin_64_memop(); } catch (...) { std::cerr << "FAIL: ldumin_64_memop" << std::endl; failed++; }
    try { test_ldumina_64_memop(); } catch (...) { std::cerr << "FAIL: ldumina_64_memop" << std::endl; failed++; }
    try { test_lduminal_64_memop(); } catch (...) { std::cerr << "FAIL: lduminal_64_memop" << std::endl; failed++; }
    try { test_lduminl_64_memop(); } catch (...) { std::cerr << "FAIL: lduminl_64_memop" << std::endl; failed++; }
    try { test_lduminb_32_memop(); } catch (...) { std::cerr << "FAIL: lduminb_32_memop" << std::endl; failed++; }
    try { test_lduminab_32_memop(); } catch (...) { std::cerr << "FAIL: lduminab_32_memop" << std::endl; failed++; }
    try { test_lduminalb_32_memop(); } catch (...) { std::cerr << "FAIL: lduminalb_32_memop" << std::endl; failed++; }
    try { test_lduminlb_32_memop(); } catch (...) { std::cerr << "FAIL: lduminlb_32_memop" << std::endl; failed++; }
    try { test_lduminh_32_memop(); } catch (...) { std::cerr << "FAIL: lduminh_32_memop" << std::endl; failed++; }
    try { test_lduminah_32_memop(); } catch (...) { std::cerr << "FAIL: lduminah_32_memop" << std::endl; failed++; }
    try { test_lduminalh_32_memop(); } catch (...) { std::cerr << "FAIL: lduminalh_32_memop" << std::endl; failed++; }
    try { test_lduminlh_32_memop(); } catch (...) { std::cerr << "FAIL: lduminlh_32_memop" << std::endl; failed++; }
    try { test_ldur_b_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_b_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_h_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_h_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_s_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_s_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_d_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_d_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_q_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_q_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_32_ldst_unscaled" << std::endl; failed++; }
    try { test_ldur_64_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldur_64_ldst_unscaled" << std::endl; failed++; }
    try { test_ldurb_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldurb_32_ldst_unscaled" << std::endl; failed++; }
    try { test_ldurh_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldurh_32_ldst_unscaled" << std::endl; failed++; }
    try { test_ldursb_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldursb_32_ldst_unscaled" << std::endl; failed++; }
    try { test_ldursb_64_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldursb_64_ldst_unscaled" << std::endl; failed++; }
    try { test_ldursh_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldursh_32_ldst_unscaled" << std::endl; failed++; }
    try { test_ldursh_64_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldursh_64_ldst_unscaled" << std::endl; failed++; }
    try { test_ldursw_64_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: ldursw_64_ldst_unscaled" << std::endl; failed++; }
    try { test_ldxp_lp32_ldstexclp(); } catch (...) { std::cerr << "FAIL: ldxp_lp32_ldstexclp" << std::endl; failed++; }
    try { test_ldxp_lp64_ldstexclp(); } catch (...) { std::cerr << "FAIL: ldxp_lp64_ldstexclp" << std::endl; failed++; }
    try { test_ldxr_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldxr_lr32_ldstexclr" << std::endl; failed++; }
    try { test_ldxr_lr64_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldxr_lr64_ldstexclr" << std::endl; failed++; }
    try { test_ldxrb_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldxrb_lr32_ldstexclr" << std::endl; failed++; }
    try { test_ldxrh_lr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: ldxrh_lr32_ldstexclr" << std::endl; failed++; }
    try { test_prfm_p_ldst_pos(); } catch (...) { std::cerr << "FAIL: prfm_p_ldst_pos" << std::endl; failed++; }
    try { test_prfm_p_loadlit(); } catch (...) { std::cerr << "FAIL: prfm_p_loadlit" << std::endl; failed++; }
    try { test_prfm_p_ldst_regoff(); } catch (...) { std::cerr << "FAIL: prfm_p_ldst_regoff" << std::endl; failed++; }
    try { test_prfum_p_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: prfum_p_ldst_unscaled" << std::endl; failed++; }
    try { test_rcwcas_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwcas_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwcasa_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwcasa_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwcasal_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwcasal_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwcasl_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwcasl_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwcasp_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwcasp_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwcaspa_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwcaspa_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwcaspal_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwcaspal_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwcaspl_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwcaspl_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwclr_64_memop(); } catch (...) { std::cerr << "FAIL: rcwclr_64_memop" << std::endl; failed++; }
    try { test_rcwclra_64_memop(); } catch (...) { std::cerr << "FAIL: rcwclra_64_memop" << std::endl; failed++; }
    try { test_rcwclral_64_memop(); } catch (...) { std::cerr << "FAIL: rcwclral_64_memop" << std::endl; failed++; }
    try { test_rcwclrl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwclrl_64_memop" << std::endl; failed++; }
    try { test_rcwclrp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwclrp_128_memop_128" << std::endl; failed++; }
    try { test_rcwclrpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwclrpa_128_memop_128" << std::endl; failed++; }
    try { test_rcwclrpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwclrpal_128_memop_128" << std::endl; failed++; }
    try { test_rcwclrpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwclrpl_128_memop_128" << std::endl; failed++; }
    try { test_rcwscas_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwscas_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwscasa_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwscasa_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwscasal_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwscasal_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwscasl_c64_rcwcomswap(); } catch (...) { std::cerr << "FAIL: rcwscasl_c64_rcwcomswap" << std::endl; failed++; }
    try { test_rcwscasp_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwscasp_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwscaspa_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwscaspa_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwscaspal_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwscaspal_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwscaspl_c64_rcwcomswappr(); } catch (...) { std::cerr << "FAIL: rcwscaspl_c64_rcwcomswappr" << std::endl; failed++; }
    try { test_rcwsclr_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsclr_64_memop" << std::endl; failed++; }
    try { test_rcwsclra_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsclra_64_memop" << std::endl; failed++; }
    try { test_rcwsclral_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsclral_64_memop" << std::endl; failed++; }
    try { test_rcwsclrl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsclrl_64_memop" << std::endl; failed++; }
    try { test_rcwsclrp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsclrp_128_memop_128" << std::endl; failed++; }
    try { test_rcwsclrpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsclrpa_128_memop_128" << std::endl; failed++; }
    try { test_rcwsclrpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsclrpal_128_memop_128" << std::endl; failed++; }
    try { test_rcwsclrpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsclrpl_128_memop_128" << std::endl; failed++; }
    try { test_rcwset_64_memop(); } catch (...) { std::cerr << "FAIL: rcwset_64_memop" << std::endl; failed++; }
    try { test_rcwseta_64_memop(); } catch (...) { std::cerr << "FAIL: rcwseta_64_memop" << std::endl; failed++; }
    try { test_rcwsetal_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsetal_64_memop" << std::endl; failed++; }
    try { test_rcwsetl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsetl_64_memop" << std::endl; failed++; }
    try { test_rcwsetp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsetp_128_memop_128" << std::endl; failed++; }
    try { test_rcwsetpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsetpa_128_memop_128" << std::endl; failed++; }
    try { test_rcwsetpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsetpal_128_memop_128" << std::endl; failed++; }
    try { test_rcwsetpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsetpl_128_memop_128" << std::endl; failed++; }
    try { test_rcwsset_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsset_64_memop" << std::endl; failed++; }
    try { test_rcwsseta_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsseta_64_memop" << std::endl; failed++; }
    try { test_rcwssetal_64_memop(); } catch (...) { std::cerr << "FAIL: rcwssetal_64_memop" << std::endl; failed++; }
    try { test_rcwssetl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwssetl_64_memop" << std::endl; failed++; }
    try { test_rcwssetp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwssetp_128_memop_128" << std::endl; failed++; }
    try { test_rcwssetpa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwssetpa_128_memop_128" << std::endl; failed++; }
    try { test_rcwssetpal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwssetpal_128_memop_128" << std::endl; failed++; }
    try { test_rcwssetpl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwssetpl_128_memop_128" << std::endl; failed++; }
    try { test_rcwsswp_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsswp_64_memop" << std::endl; failed++; }
    try { test_rcwsswpa_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsswpa_64_memop" << std::endl; failed++; }
    try { test_rcwsswpal_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsswpal_64_memop" << std::endl; failed++; }
    try { test_rcwsswpl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwsswpl_64_memop" << std::endl; failed++; }
    try { test_rcwsswpp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsswpp_128_memop_128" << std::endl; failed++; }
    try { test_rcwsswppa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsswppa_128_memop_128" << std::endl; failed++; }
    try { test_rcwsswppal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsswppal_128_memop_128" << std::endl; failed++; }
    try { test_rcwsswppl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwsswppl_128_memop_128" << std::endl; failed++; }
    try { test_rcwswp_64_memop(); } catch (...) { std::cerr << "FAIL: rcwswp_64_memop" << std::endl; failed++; }
    try { test_rcwswpa_64_memop(); } catch (...) { std::cerr << "FAIL: rcwswpa_64_memop" << std::endl; failed++; }
    try { test_rcwswpal_64_memop(); } catch (...) { std::cerr << "FAIL: rcwswpal_64_memop" << std::endl; failed++; }
    try { test_rcwswpl_64_memop(); } catch (...) { std::cerr << "FAIL: rcwswpl_64_memop" << std::endl; failed++; }
    try { test_rcwswpp_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwswpp_128_memop_128" << std::endl; failed++; }
    try { test_rcwswppa_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwswppa_128_memop_128" << std::endl; failed++; }
    try { test_rcwswppal_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwswppal_128_memop_128" << std::endl; failed++; }
    try { test_rcwswppl_128_memop_128(); } catch (...) { std::cerr << "FAIL: rcwswppl_128_memop_128" << std::endl; failed++; }
    try { test_rprfm_r_ldst_regoff(); } catch (...) { std::cerr << "FAIL: rprfm_r_ldst_regoff" << std::endl; failed++; }
    try { test_setgp_set_memcms(); } catch (...) { std::cerr << "FAIL: setgp_set_memcms" << std::endl; failed++; }
    try { test_setgm_set_memcms(); } catch (...) { std::cerr << "FAIL: setgm_set_memcms" << std::endl; failed++; }
    try { test_setge_set_memcms(); } catch (...) { std::cerr << "FAIL: setge_set_memcms" << std::endl; failed++; }
    try { test_setgpn_set_memcms(); } catch (...) { std::cerr << "FAIL: setgpn_set_memcms" << std::endl; failed++; }
    try { test_setgmn_set_memcms(); } catch (...) { std::cerr << "FAIL: setgmn_set_memcms" << std::endl; failed++; }
    try { test_setgen_set_memcms(); } catch (...) { std::cerr << "FAIL: setgen_set_memcms" << std::endl; failed++; }
    try { test_setgpt_set_memcms(); } catch (...) { std::cerr << "FAIL: setgpt_set_memcms" << std::endl; failed++; }
    try { test_setgmt_set_memcms(); } catch (...) { std::cerr << "FAIL: setgmt_set_memcms" << std::endl; failed++; }
    try { test_setget_set_memcms(); } catch (...) { std::cerr << "FAIL: setget_set_memcms" << std::endl; failed++; }
    try { test_setgptn_set_memcms(); } catch (...) { std::cerr << "FAIL: setgptn_set_memcms" << std::endl; failed++; }
    try { test_setgmtn_set_memcms(); } catch (...) { std::cerr << "FAIL: setgmtn_set_memcms" << std::endl; failed++; }
    try { test_setgetn_set_memcms(); } catch (...) { std::cerr << "FAIL: setgetn_set_memcms" << std::endl; failed++; }
    try { test_setp_set_memcms(); } catch (...) { std::cerr << "FAIL: setp_set_memcms" << std::endl; failed++; }
    try { test_setm_set_memcms(); } catch (...) { std::cerr << "FAIL: setm_set_memcms" << std::endl; failed++; }
    try { test_sete_set_memcms(); } catch (...) { std::cerr << "FAIL: sete_set_memcms" << std::endl; failed++; }
    try { test_setpn_set_memcms(); } catch (...) { std::cerr << "FAIL: setpn_set_memcms" << std::endl; failed++; }
    try { test_setmn_set_memcms(); } catch (...) { std::cerr << "FAIL: setmn_set_memcms" << std::endl; failed++; }
    try { test_seten_set_memcms(); } catch (...) { std::cerr << "FAIL: seten_set_memcms" << std::endl; failed++; }
    try { test_setpt_set_memcms(); } catch (...) { std::cerr << "FAIL: setpt_set_memcms" << std::endl; failed++; }
    try { test_setmt_set_memcms(); } catch (...) { std::cerr << "FAIL: setmt_set_memcms" << std::endl; failed++; }
    try { test_setet_set_memcms(); } catch (...) { std::cerr << "FAIL: setet_set_memcms" << std::endl; failed++; }
    try { test_setptn_set_memcms(); } catch (...) { std::cerr << "FAIL: setptn_set_memcms" << std::endl; failed++; }
    try { test_setmtn_set_memcms(); } catch (...) { std::cerr << "FAIL: setmtn_set_memcms" << std::endl; failed++; }
    try { test_setetn_set_memcms(); } catch (...) { std::cerr << "FAIL: setetn_set_memcms" << std::endl; failed++; }
    try { test_st1_asisdlse_r1_1v(); } catch (...) { std::cerr << "FAIL: st1_asisdlse_r1_1v" << std::endl; failed++; }
    try { test_st1_asisdlse_r2_2v(); } catch (...) { std::cerr << "FAIL: st1_asisdlse_r2_2v" << std::endl; failed++; }
    try { test_st1_asisdlse_r3_3v(); } catch (...) { std::cerr << "FAIL: st1_asisdlse_r3_3v" << std::endl; failed++; }
    try { test_st1_asisdlse_r4_4v(); } catch (...) { std::cerr << "FAIL: st1_asisdlse_r4_4v" << std::endl; failed++; }
    try { test_st1_asisdlsep_i1_i1(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_i1_i1" << std::endl; failed++; }
    try { test_st1_asisdlsep_r1_r1(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_r1_r1" << std::endl; failed++; }
    try { test_st1_asisdlsep_i2_i2(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_i2_i2" << std::endl; failed++; }
    try { test_st1_asisdlsep_r2_r2(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_r2_r2" << std::endl; failed++; }
    try { test_st1_asisdlsep_i3_i3(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_i3_i3" << std::endl; failed++; }
    try { test_st1_asisdlsep_r3_r3(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_r3_r3" << std::endl; failed++; }
    try { test_st1_asisdlsep_i4_i4(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_i4_i4" << std::endl; failed++; }
    try { test_st1_asisdlsep_r4_r4(); } catch (...) { std::cerr << "FAIL: st1_asisdlsep_r4_r4" << std::endl; failed++; }
    try { test_st1_asisdlso_b1_1b(); } catch (...) { std::cerr << "FAIL: st1_asisdlso_b1_1b" << std::endl; failed++; }
    try { test_st1_asisdlso_h1_1h(); } catch (...) { std::cerr << "FAIL: st1_asisdlso_h1_1h" << std::endl; failed++; }
    try { test_st1_asisdlso_s1_1s(); } catch (...) { std::cerr << "FAIL: st1_asisdlso_s1_1s" << std::endl; failed++; }
    try { test_st1_asisdlso_d1_1d(); } catch (...) { std::cerr << "FAIL: st1_asisdlso_d1_1d" << std::endl; failed++; }
    try { test_st1_asisdlsop_b1_i1b(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_b1_i1b" << std::endl; failed++; }
    try { test_st1_asisdlsop_bx1_r1b(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_bx1_r1b" << std::endl; failed++; }
    try { test_st1_asisdlsop_h1_i1h(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_h1_i1h" << std::endl; failed++; }
    try { test_st1_asisdlsop_hx1_r1h(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_hx1_r1h" << std::endl; failed++; }
    try { test_st1_asisdlsop_s1_i1s(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_s1_i1s" << std::endl; failed++; }
    try { test_st1_asisdlsop_sx1_r1s(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_sx1_r1s" << std::endl; failed++; }
    try { test_st1_asisdlsop_d1_i1d(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_d1_i1d" << std::endl; failed++; }
    try { test_st1_asisdlsop_dx1_r1d(); } catch (...) { std::cerr << "FAIL: st1_asisdlsop_dx1_r1d" << std::endl; failed++; }
    try { test_st2_asisdlse_r2(); } catch (...) { std::cerr << "FAIL: st2_asisdlse_r2" << std::endl; failed++; }
    try { test_st2_asisdlsep_i2_i(); } catch (...) { std::cerr << "FAIL: st2_asisdlsep_i2_i" << std::endl; failed++; }
    try { test_st2_asisdlsep_r2_r(); } catch (...) { std::cerr << "FAIL: st2_asisdlsep_r2_r" << std::endl; failed++; }
    try { test_st2_asisdlso_b2_2b(); } catch (...) { std::cerr << "FAIL: st2_asisdlso_b2_2b" << std::endl; failed++; }
    try { test_st2_asisdlso_h2_2h(); } catch (...) { std::cerr << "FAIL: st2_asisdlso_h2_2h" << std::endl; failed++; }
    try { test_st2_asisdlso_s2_2s(); } catch (...) { std::cerr << "FAIL: st2_asisdlso_s2_2s" << std::endl; failed++; }
    try { test_st2_asisdlso_d2_2d(); } catch (...) { std::cerr << "FAIL: st2_asisdlso_d2_2d" << std::endl; failed++; }
    try { test_st2_asisdlsop_b2_i2b(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_b2_i2b" << std::endl; failed++; }
    try { test_st2_asisdlsop_bx2_r2b(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_bx2_r2b" << std::endl; failed++; }
    try { test_st2_asisdlsop_h2_i2h(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_h2_i2h" << std::endl; failed++; }
    try { test_st2_asisdlsop_hx2_r2h(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_hx2_r2h" << std::endl; failed++; }
    try { test_st2_asisdlsop_s2_i2s(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_s2_i2s" << std::endl; failed++; }
    try { test_st2_asisdlsop_sx2_r2s(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_sx2_r2s" << std::endl; failed++; }
    try { test_st2_asisdlsop_d2_i2d(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_d2_i2d" << std::endl; failed++; }
    try { test_st2_asisdlsop_dx2_r2d(); } catch (...) { std::cerr << "FAIL: st2_asisdlsop_dx2_r2d" << std::endl; failed++; }
    try { test_st2g_64spost_ldsttags(); } catch (...) { std::cerr << "FAIL: st2g_64spost_ldsttags" << std::endl; failed++; }
    try { test_st2g_64spre_ldsttags(); } catch (...) { std::cerr << "FAIL: st2g_64spre_ldsttags" << std::endl; failed++; }
    try { test_st2g_64soffset_ldsttags(); } catch (...) { std::cerr << "FAIL: st2g_64soffset_ldsttags" << std::endl; failed++; }
    try { test_st3_asisdlse_r3(); } catch (...) { std::cerr << "FAIL: st3_asisdlse_r3" << std::endl; failed++; }
    try { test_st3_asisdlsep_i3_i(); } catch (...) { std::cerr << "FAIL: st3_asisdlsep_i3_i" << std::endl; failed++; }
    try { test_st3_asisdlsep_r3_r(); } catch (...) { std::cerr << "FAIL: st3_asisdlsep_r3_r" << std::endl; failed++; }
    try { test_st3_asisdlso_b3_3b(); } catch (...) { std::cerr << "FAIL: st3_asisdlso_b3_3b" << std::endl; failed++; }
    try { test_st3_asisdlso_h3_3h(); } catch (...) { std::cerr << "FAIL: st3_asisdlso_h3_3h" << std::endl; failed++; }
    try { test_st3_asisdlso_s3_3s(); } catch (...) { std::cerr << "FAIL: st3_asisdlso_s3_3s" << std::endl; failed++; }
    try { test_st3_asisdlso_d3_3d(); } catch (...) { std::cerr << "FAIL: st3_asisdlso_d3_3d" << std::endl; failed++; }
    try { test_st3_asisdlsop_b3_i3b(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_b3_i3b" << std::endl; failed++; }
    try { test_st3_asisdlsop_bx3_r3b(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_bx3_r3b" << std::endl; failed++; }
    try { test_st3_asisdlsop_h3_i3h(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_h3_i3h" << std::endl; failed++; }
    try { test_st3_asisdlsop_hx3_r3h(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_hx3_r3h" << std::endl; failed++; }
    try { test_st3_asisdlsop_s3_i3s(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_s3_i3s" << std::endl; failed++; }
    try { test_st3_asisdlsop_sx3_r3s(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_sx3_r3s" << std::endl; failed++; }
    try { test_st3_asisdlsop_d3_i3d(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_d3_i3d" << std::endl; failed++; }
    try { test_st3_asisdlsop_dx3_r3d(); } catch (...) { std::cerr << "FAIL: st3_asisdlsop_dx3_r3d" << std::endl; failed++; }
    try { test_st4_asisdlse_r4(); } catch (...) { std::cerr << "FAIL: st4_asisdlse_r4" << std::endl; failed++; }
    try { test_st4_asisdlsep_i4_i(); } catch (...) { std::cerr << "FAIL: st4_asisdlsep_i4_i" << std::endl; failed++; }
    try { test_st4_asisdlsep_r4_r(); } catch (...) { std::cerr << "FAIL: st4_asisdlsep_r4_r" << std::endl; failed++; }
    try { test_st4_asisdlso_b4_4b(); } catch (...) { std::cerr << "FAIL: st4_asisdlso_b4_4b" << std::endl; failed++; }
    try { test_st4_asisdlso_h4_4h(); } catch (...) { std::cerr << "FAIL: st4_asisdlso_h4_4h" << std::endl; failed++; }
    try { test_st4_asisdlso_s4_4s(); } catch (...) { std::cerr << "FAIL: st4_asisdlso_s4_4s" << std::endl; failed++; }
    try { test_st4_asisdlso_d4_4d(); } catch (...) { std::cerr << "FAIL: st4_asisdlso_d4_4d" << std::endl; failed++; }
    try { test_st4_asisdlsop_b4_i4b(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_b4_i4b" << std::endl; failed++; }
    try { test_st4_asisdlsop_bx4_r4b(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_bx4_r4b" << std::endl; failed++; }
    try { test_st4_asisdlsop_h4_i4h(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_h4_i4h" << std::endl; failed++; }
    try { test_st4_asisdlsop_hx4_r4h(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_hx4_r4h" << std::endl; failed++; }
    try { test_st4_asisdlsop_s4_i4s(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_s4_i4s" << std::endl; failed++; }
    try { test_st4_asisdlsop_sx4_r4s(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_sx4_r4s" << std::endl; failed++; }
    try { test_st4_asisdlsop_d4_i4d(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_d4_i4d" << std::endl; failed++; }
    try { test_st4_asisdlsop_dx4_r4d(); } catch (...) { std::cerr << "FAIL: st4_asisdlsop_dx4_r4d" << std::endl; failed++; }
    try { test_st64b_64l_memop(); } catch (...) { std::cerr << "FAIL: st64b_64l_memop" << std::endl; failed++; }
    try { test_st64bv_64_memop(); } catch (...) { std::cerr << "FAIL: st64bv_64_memop" << std::endl; failed++; }
    try { test_st64bv0_64_memop(); } catch (...) { std::cerr << "FAIL: st64bv0_64_memop" << std::endl; failed++; }
    try { test_stadd_ldadd_32_memop(); } catch (...) { std::cerr << "FAIL: stadd_ldadd_32_memop" << std::endl; failed++; }
    try { test_staddl_ldaddl_32_memop(); } catch (...) { std::cerr << "FAIL: staddl_ldaddl_32_memop" << std::endl; failed++; }
    try { test_stadd_ldadd_64_memop(); } catch (...) { std::cerr << "FAIL: stadd_ldadd_64_memop" << std::endl; failed++; }
    try { test_staddl_ldaddl_64_memop(); } catch (...) { std::cerr << "FAIL: staddl_ldaddl_64_memop" << std::endl; failed++; }
    try { test_staddb_ldaddb_32_memop(); } catch (...) { std::cerr << "FAIL: staddb_ldaddb_32_memop" << std::endl; failed++; }
    try { test_staddlb_ldaddlb_32_memop(); } catch (...) { std::cerr << "FAIL: staddlb_ldaddlb_32_memop" << std::endl; failed++; }
    try { test_staddh_ldaddh_32_memop(); } catch (...) { std::cerr << "FAIL: staddh_ldaddh_32_memop" << std::endl; failed++; }
    try { test_staddlh_ldaddlh_32_memop(); } catch (...) { std::cerr << "FAIL: staddlh_ldaddlh_32_memop" << std::endl; failed++; }
    try { test_stbfadd_16(); } catch (...) { std::cerr << "FAIL: stbfadd_16" << std::endl; failed++; }
    try { test_stbfaddl_16(); } catch (...) { std::cerr << "FAIL: stbfaddl_16" << std::endl; failed++; }
    try { test_stbfmax_16(); } catch (...) { std::cerr << "FAIL: stbfmax_16" << std::endl; failed++; }
    try { test_stbfmaxl_16(); } catch (...) { std::cerr << "FAIL: stbfmaxl_16" << std::endl; failed++; }
    try { test_stbfmaxnm_16(); } catch (...) { std::cerr << "FAIL: stbfmaxnm_16" << std::endl; failed++; }
    try { test_stbfmaxnml_16(); } catch (...) { std::cerr << "FAIL: stbfmaxnml_16" << std::endl; failed++; }
    try { test_stbfmin_16(); } catch (...) { std::cerr << "FAIL: stbfmin_16" << std::endl; failed++; }
    try { test_stbfminl_16(); } catch (...) { std::cerr << "FAIL: stbfminl_16" << std::endl; failed++; }
    try { test_stbfminnm_16(); } catch (...) { std::cerr << "FAIL: stbfminnm_16" << std::endl; failed++; }
    try { test_stbfminnml_16(); } catch (...) { std::cerr << "FAIL: stbfminnml_16" << std::endl; failed++; }
    try { test_stclr_ldclr_32_memop(); } catch (...) { std::cerr << "FAIL: stclr_ldclr_32_memop" << std::endl; failed++; }
    try { test_stclrl_ldclrl_32_memop(); } catch (...) { std::cerr << "FAIL: stclrl_ldclrl_32_memop" << std::endl; failed++; }
    try { test_stclr_ldclr_64_memop(); } catch (...) { std::cerr << "FAIL: stclr_ldclr_64_memop" << std::endl; failed++; }
    try { test_stclrl_ldclrl_64_memop(); } catch (...) { std::cerr << "FAIL: stclrl_ldclrl_64_memop" << std::endl; failed++; }
    try { test_stclrb_ldclrb_32_memop(); } catch (...) { std::cerr << "FAIL: stclrb_ldclrb_32_memop" << std::endl; failed++; }
    try { test_stclrlb_ldclrlb_32_memop(); } catch (...) { std::cerr << "FAIL: stclrlb_ldclrlb_32_memop" << std::endl; failed++; }
    try { test_stclrh_ldclrh_32_memop(); } catch (...) { std::cerr << "FAIL: stclrh_ldclrh_32_memop" << std::endl; failed++; }
    try { test_stclrlh_ldclrlh_32_memop(); } catch (...) { std::cerr << "FAIL: stclrlh_ldclrlh_32_memop" << std::endl; failed++; }
    try { test_steor_ldeor_32_memop(); } catch (...) { std::cerr << "FAIL: steor_ldeor_32_memop" << std::endl; failed++; }
    try { test_steorl_ldeorl_32_memop(); } catch (...) { std::cerr << "FAIL: steorl_ldeorl_32_memop" << std::endl; failed++; }
    try { test_steor_ldeor_64_memop(); } catch (...) { std::cerr << "FAIL: steor_ldeor_64_memop" << std::endl; failed++; }
    try { test_steorl_ldeorl_64_memop(); } catch (...) { std::cerr << "FAIL: steorl_ldeorl_64_memop" << std::endl; failed++; }
    try { test_steorb_ldeorb_32_memop(); } catch (...) { std::cerr << "FAIL: steorb_ldeorb_32_memop" << std::endl; failed++; }
    try { test_steorlb_ldeorlb_32_memop(); } catch (...) { std::cerr << "FAIL: steorlb_ldeorlb_32_memop" << std::endl; failed++; }
    try { test_steorh_ldeorh_32_memop(); } catch (...) { std::cerr << "FAIL: steorh_ldeorh_32_memop" << std::endl; failed++; }
    try { test_steorlh_ldeorlh_32_memop(); } catch (...) { std::cerr << "FAIL: steorlh_ldeorlh_32_memop" << std::endl; failed++; }
    try { test_stfadd_16(); } catch (...) { std::cerr << "FAIL: stfadd_16" << std::endl; failed++; }
    try { test_stfaddl_16(); } catch (...) { std::cerr << "FAIL: stfaddl_16" << std::endl; failed++; }
    try { test_stfadd_32(); } catch (...) { std::cerr << "FAIL: stfadd_32" << std::endl; failed++; }
    try { test_stfaddl_32(); } catch (...) { std::cerr << "FAIL: stfaddl_32" << std::endl; failed++; }
    try { test_stfadd_64(); } catch (...) { std::cerr << "FAIL: stfadd_64" << std::endl; failed++; }
    try { test_stfaddl_64(); } catch (...) { std::cerr << "FAIL: stfaddl_64" << std::endl; failed++; }
    try { test_stfmax_16(); } catch (...) { std::cerr << "FAIL: stfmax_16" << std::endl; failed++; }
    try { test_stfmaxl_16(); } catch (...) { std::cerr << "FAIL: stfmaxl_16" << std::endl; failed++; }
    try { test_stfmax_32(); } catch (...) { std::cerr << "FAIL: stfmax_32" << std::endl; failed++; }
    try { test_stfmaxl_32(); } catch (...) { std::cerr << "FAIL: stfmaxl_32" << std::endl; failed++; }
    try { test_stfmax_64(); } catch (...) { std::cerr << "FAIL: stfmax_64" << std::endl; failed++; }
    try { test_stfmaxl_64(); } catch (...) { std::cerr << "FAIL: stfmaxl_64" << std::endl; failed++; }
    try { test_stfmaxnm_16(); } catch (...) { std::cerr << "FAIL: stfmaxnm_16" << std::endl; failed++; }
    try { test_stfmaxnml_16(); } catch (...) { std::cerr << "FAIL: stfmaxnml_16" << std::endl; failed++; }
    try { test_stfmaxnm_32(); } catch (...) { std::cerr << "FAIL: stfmaxnm_32" << std::endl; failed++; }
    try { test_stfmaxnml_32(); } catch (...) { std::cerr << "FAIL: stfmaxnml_32" << std::endl; failed++; }
    try { test_stfmaxnm_64(); } catch (...) { std::cerr << "FAIL: stfmaxnm_64" << std::endl; failed++; }
    try { test_stfmaxnml_64(); } catch (...) { std::cerr << "FAIL: stfmaxnml_64" << std::endl; failed++; }
    try { test_stfmin_16(); } catch (...) { std::cerr << "FAIL: stfmin_16" << std::endl; failed++; }
    try { test_stfminl_16(); } catch (...) { std::cerr << "FAIL: stfminl_16" << std::endl; failed++; }
    try { test_stfmin_32(); } catch (...) { std::cerr << "FAIL: stfmin_32" << std::endl; failed++; }
    try { test_stfminl_32(); } catch (...) { std::cerr << "FAIL: stfminl_32" << std::endl; failed++; }
    try { test_stfmin_64(); } catch (...) { std::cerr << "FAIL: stfmin_64" << std::endl; failed++; }
    try { test_stfminl_64(); } catch (...) { std::cerr << "FAIL: stfminl_64" << std::endl; failed++; }
    try { test_stfminnm_16(); } catch (...) { std::cerr << "FAIL: stfminnm_16" << std::endl; failed++; }
    try { test_stfminnml_16(); } catch (...) { std::cerr << "FAIL: stfminnml_16" << std::endl; failed++; }
    try { test_stfminnm_32(); } catch (...) { std::cerr << "FAIL: stfminnm_32" << std::endl; failed++; }
    try { test_stfminnml_32(); } catch (...) { std::cerr << "FAIL: stfminnml_32" << std::endl; failed++; }
    try { test_stfminnm_64(); } catch (...) { std::cerr << "FAIL: stfminnm_64" << std::endl; failed++; }
    try { test_stfminnml_64(); } catch (...) { std::cerr << "FAIL: stfminnml_64" << std::endl; failed++; }
    try { test_stg_64spost_ldsttags(); } catch (...) { std::cerr << "FAIL: stg_64spost_ldsttags" << std::endl; failed++; }
    try { test_stg_64spre_ldsttags(); } catch (...) { std::cerr << "FAIL: stg_64spre_ldsttags" << std::endl; failed++; }
    try { test_stg_64soffset_ldsttags(); } catch (...) { std::cerr << "FAIL: stg_64soffset_ldsttags" << std::endl; failed++; }
    try { test_stgm_64bulk_ldsttags(); } catch (...) { std::cerr << "FAIL: stgm_64bulk_ldsttags" << std::endl; failed++; }
    try { test_stgp_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stgp_64_ldstpair_post" << std::endl; failed++; }
    try { test_stgp_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stgp_64_ldstpair_pre" << std::endl; failed++; }
    try { test_stgp_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stgp_64_ldstpair_off" << std::endl; failed++; }
    try { test_stilp_32se_ldiappstilp(); } catch (...) { std::cerr << "FAIL: stilp_32se_ldiappstilp" << std::endl; failed++; }
    try { test_stilp_32s_ldiappstilp(); } catch (...) { std::cerr << "FAIL: stilp_32s_ldiappstilp" << std::endl; failed++; }
    try { test_stilp_64ss_ldiappstilp(); } catch (...) { std::cerr << "FAIL: stilp_64ss_ldiappstilp" << std::endl; failed++; }
    try { test_stilp_64s_ldiappstilp(); } catch (...) { std::cerr << "FAIL: stilp_64s_ldiappstilp" << std::endl; failed++; }
    try { test_stl1_asisdlso_d1(); } catch (...) { std::cerr << "FAIL: stl1_asisdlso_d1" << std::endl; failed++; }
    try { test_stllr_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stllr_sl32_ldstord" << std::endl; failed++; }
    try { test_stllr_sl64_ldstord(); } catch (...) { std::cerr << "FAIL: stllr_sl64_ldstord" << std::endl; failed++; }
    try { test_stllrb_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stllrb_sl32_ldstord" << std::endl; failed++; }
    try { test_stllrh_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stllrh_sl32_ldstord" << std::endl; failed++; }
    try { test_stlp_64_ldiappstilp(); } catch (...) { std::cerr << "FAIL: stlp_64_ldiappstilp" << std::endl; failed++; }
    try { test_stlr_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stlr_sl32_ldstord" << std::endl; failed++; }
    try { test_stlr_sl64_ldstord(); } catch (...) { std::cerr << "FAIL: stlr_sl64_ldstord" << std::endl; failed++; }
    try { test_stlr_32s_ldapstl_writeback(); } catch (...) { std::cerr << "FAIL: stlr_32s_ldapstl_writeback" << std::endl; failed++; }
    try { test_stlr_64s_ldapstl_writeback(); } catch (...) { std::cerr << "FAIL: stlr_64s_ldapstl_writeback" << std::endl; failed++; }
    try { test_stlrb_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stlrb_sl32_ldstord" << std::endl; failed++; }
    try { test_stlrh_sl32_ldstord(); } catch (...) { std::cerr << "FAIL: stlrh_sl32_ldstord" << std::endl; failed++; }
    try { test_stltxr_sr32_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: stltxr_sr32_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_stltxr_sr64_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: stltxr_sr64_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_stlur_b_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: stlur_b_ldapstl_simd" << std::endl; failed++; }
    try { test_stlur_h_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: stlur_h_ldapstl_simd" << std::endl; failed++; }
    try { test_stlur_s_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: stlur_s_ldapstl_simd" << std::endl; failed++; }
    try { test_stlur_d_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: stlur_d_ldapstl_simd" << std::endl; failed++; }
    try { test_stlur_q_ldapstl_simd(); } catch (...) { std::cerr << "FAIL: stlur_q_ldapstl_simd" << std::endl; failed++; }
    try { test_stlur_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: stlur_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_stlur_64_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: stlur_64_ldapstl_unscaled" << std::endl; failed++; }
    try { test_stlurb_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: stlurb_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_stlurh_32_ldapstl_unscaled(); } catch (...) { std::cerr << "FAIL: stlurh_32_ldapstl_unscaled" << std::endl; failed++; }
    try { test_stlxp_sp32_ldstexclp(); } catch (...) { std::cerr << "FAIL: stlxp_sp32_ldstexclp" << std::endl; failed++; }
    try { test_stlxp_sp64_ldstexclp(); } catch (...) { std::cerr << "FAIL: stlxp_sp64_ldstexclp" << std::endl; failed++; }
    try { test_stlxr_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stlxr_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stlxr_sr64_ldstexclr(); } catch (...) { std::cerr << "FAIL: stlxr_sr64_ldstexclr" << std::endl; failed++; }
    try { test_stlxrb_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stlxrb_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stlxrh_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stlxrh_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stnp_s_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: stnp_s_ldstnapair_offs" << std::endl; failed++; }
    try { test_stnp_d_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: stnp_d_ldstnapair_offs" << std::endl; failed++; }
    try { test_stnp_q_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: stnp_q_ldstnapair_offs" << std::endl; failed++; }
    try { test_stnp_32_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: stnp_32_ldstnapair_offs" << std::endl; failed++; }
    try { test_stnp_64_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: stnp_64_ldstnapair_offs" << std::endl; failed++; }
    try { test_stp_s_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stp_s_ldstpair_post" << std::endl; failed++; }
    try { test_stp_d_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stp_d_ldstpair_post" << std::endl; failed++; }
    try { test_stp_q_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stp_q_ldstpair_post" << std::endl; failed++; }
    try { test_stp_s_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stp_s_ldstpair_pre" << std::endl; failed++; }
    try { test_stp_d_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stp_d_ldstpair_pre" << std::endl; failed++; }
    try { test_stp_q_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stp_q_ldstpair_pre" << std::endl; failed++; }
    try { test_stp_s_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stp_s_ldstpair_off" << std::endl; failed++; }
    try { test_stp_d_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stp_d_ldstpair_off" << std::endl; failed++; }
    try { test_stp_q_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stp_q_ldstpair_off" << std::endl; failed++; }
    try { test_stp_32_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stp_32_ldstpair_post" << std::endl; failed++; }
    try { test_stp_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: stp_64_ldstpair_post" << std::endl; failed++; }
    try { test_stp_32_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stp_32_ldstpair_pre" << std::endl; failed++; }
    try { test_stp_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: stp_64_ldstpair_pre" << std::endl; failed++; }
    try { test_stp_32_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stp_32_ldstpair_off" << std::endl; failed++; }
    try { test_stp_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: stp_64_ldstpair_off" << std::endl; failed++; }
    try { test_str_b_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_b_ldst_immpost" << std::endl; failed++; }
    try { test_str_h_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_h_ldst_immpost" << std::endl; failed++; }
    try { test_str_s_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_s_ldst_immpost" << std::endl; failed++; }
    try { test_str_d_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_d_ldst_immpost" << std::endl; failed++; }
    try { test_str_q_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_q_ldst_immpost" << std::endl; failed++; }
    try { test_str_b_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_b_ldst_immpre" << std::endl; failed++; }
    try { test_str_h_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_h_ldst_immpre" << std::endl; failed++; }
    try { test_str_s_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_s_ldst_immpre" << std::endl; failed++; }
    try { test_str_d_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_d_ldst_immpre" << std::endl; failed++; }
    try { test_str_q_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_q_ldst_immpre" << std::endl; failed++; }
    try { test_str_b_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_b_ldst_pos" << std::endl; failed++; }
    try { test_str_h_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_h_ldst_pos" << std::endl; failed++; }
    try { test_str_s_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_s_ldst_pos" << std::endl; failed++; }
    try { test_str_d_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_d_ldst_pos" << std::endl; failed++; }
    try { test_str_q_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_q_ldst_pos" << std::endl; failed++; }
    try { test_str_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_32_ldst_immpost" << std::endl; failed++; }
    try { test_str_64_ldst_immpost(); } catch (...) { std::cerr << "FAIL: str_64_ldst_immpost" << std::endl; failed++; }
    try { test_str_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_32_ldst_immpre" << std::endl; failed++; }
    try { test_str_64_ldst_immpre(); } catch (...) { std::cerr << "FAIL: str_64_ldst_immpre" << std::endl; failed++; }
    try { test_str_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_32_ldst_pos" << std::endl; failed++; }
    try { test_str_64_ldst_pos(); } catch (...) { std::cerr << "FAIL: str_64_ldst_pos" << std::endl; failed++; }
    try { test_str_b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_b_ldst_regoff" << std::endl; failed++; }
    try { test_str_bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_bl_ldst_regoff" << std::endl; failed++; }
    try { test_str_h_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_h_ldst_regoff" << std::endl; failed++; }
    try { test_str_s_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_s_ldst_regoff" << std::endl; failed++; }
    try { test_str_d_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_d_ldst_regoff" << std::endl; failed++; }
    try { test_str_q_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_q_ldst_regoff" << std::endl; failed++; }
    try { test_str_32_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_32_ldst_regoff" << std::endl; failed++; }
    try { test_str_64_ldst_regoff(); } catch (...) { std::cerr << "FAIL: str_64_ldst_regoff" << std::endl; failed++; }
    try { test_strb_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: strb_32_ldst_immpost" << std::endl; failed++; }
    try { test_strb_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: strb_32_ldst_immpre" << std::endl; failed++; }
    try { test_strb_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: strb_32_ldst_pos" << std::endl; failed++; }
    try { test_strb_32b_ldst_regoff(); } catch (...) { std::cerr << "FAIL: strb_32b_ldst_regoff" << std::endl; failed++; }
    try { test_strb_32bl_ldst_regoff(); } catch (...) { std::cerr << "FAIL: strb_32bl_ldst_regoff" << std::endl; failed++; }
    try { test_strh_32_ldst_immpost(); } catch (...) { std::cerr << "FAIL: strh_32_ldst_immpost" << std::endl; failed++; }
    try { test_strh_32_ldst_immpre(); } catch (...) { std::cerr << "FAIL: strh_32_ldst_immpre" << std::endl; failed++; }
    try { test_strh_32_ldst_pos(); } catch (...) { std::cerr << "FAIL: strh_32_ldst_pos" << std::endl; failed++; }
    try { test_strh_32_ldst_regoff(); } catch (...) { std::cerr << "FAIL: strh_32_ldst_regoff" << std::endl; failed++; }
    try { test_stset_ldset_32_memop(); } catch (...) { std::cerr << "FAIL: stset_ldset_32_memop" << std::endl; failed++; }
    try { test_stsetl_ldsetl_32_memop(); } catch (...) { std::cerr << "FAIL: stsetl_ldsetl_32_memop" << std::endl; failed++; }
    try { test_stset_ldset_64_memop(); } catch (...) { std::cerr << "FAIL: stset_ldset_64_memop" << std::endl; failed++; }
    try { test_stsetl_ldsetl_64_memop(); } catch (...) { std::cerr << "FAIL: stsetl_ldsetl_64_memop" << std::endl; failed++; }
    try { test_stsetb_ldsetb_32_memop(); } catch (...) { std::cerr << "FAIL: stsetb_ldsetb_32_memop" << std::endl; failed++; }
    try { test_stsetlb_ldsetlb_32_memop(); } catch (...) { std::cerr << "FAIL: stsetlb_ldsetlb_32_memop" << std::endl; failed++; }
    try { test_stseth_ldseth_32_memop(); } catch (...) { std::cerr << "FAIL: stseth_ldseth_32_memop" << std::endl; failed++; }
    try { test_stsetlh_ldsetlh_32_memop(); } catch (...) { std::cerr << "FAIL: stsetlh_ldsetlh_32_memop" << std::endl; failed++; }
    try { test_stsmax_ldsmax_32_memop(); } catch (...) { std::cerr << "FAIL: stsmax_ldsmax_32_memop" << std::endl; failed++; }
    try { test_stsmaxl_ldsmaxl_32_memop(); } catch (...) { std::cerr << "FAIL: stsmaxl_ldsmaxl_32_memop" << std::endl; failed++; }
    try { test_stsmax_ldsmax_64_memop(); } catch (...) { std::cerr << "FAIL: stsmax_ldsmax_64_memop" << std::endl; failed++; }
    try { test_stsmaxl_ldsmaxl_64_memop(); } catch (...) { std::cerr << "FAIL: stsmaxl_ldsmaxl_64_memop" << std::endl; failed++; }
    try { test_stsmaxb_ldsmaxb_32_memop(); } catch (...) { std::cerr << "FAIL: stsmaxb_ldsmaxb_32_memop" << std::endl; failed++; }
    try { test_stsmaxlb_ldsmaxlb_32_memop(); } catch (...) { std::cerr << "FAIL: stsmaxlb_ldsmaxlb_32_memop" << std::endl; failed++; }
    try { test_stsmaxh_ldsmaxh_32_memop(); } catch (...) { std::cerr << "FAIL: stsmaxh_ldsmaxh_32_memop" << std::endl; failed++; }
    try { test_stsmaxlh_ldsmaxlh_32_memop(); } catch (...) { std::cerr << "FAIL: stsmaxlh_ldsmaxlh_32_memop" << std::endl; failed++; }
    try { test_stsmin_ldsmin_32_memop(); } catch (...) { std::cerr << "FAIL: stsmin_ldsmin_32_memop" << std::endl; failed++; }
    try { test_stsminl_ldsminl_32_memop(); } catch (...) { std::cerr << "FAIL: stsminl_ldsminl_32_memop" << std::endl; failed++; }
    try { test_stsmin_ldsmin_64_memop(); } catch (...) { std::cerr << "FAIL: stsmin_ldsmin_64_memop" << std::endl; failed++; }
    try { test_stsminl_ldsminl_64_memop(); } catch (...) { std::cerr << "FAIL: stsminl_ldsminl_64_memop" << std::endl; failed++; }
    try { test_stsminb_ldsminb_32_memop(); } catch (...) { std::cerr << "FAIL: stsminb_ldsminb_32_memop" << std::endl; failed++; }
    try { test_stsminlb_ldsminlb_32_memop(); } catch (...) { std::cerr << "FAIL: stsminlb_ldsminlb_32_memop" << std::endl; failed++; }
    try { test_stsminh_ldsminh_32_memop(); } catch (...) { std::cerr << "FAIL: stsminh_ldsminh_32_memop" << std::endl; failed++; }
    try { test_stsminlh_ldsminlh_32_memop(); } catch (...) { std::cerr << "FAIL: stsminlh_ldsminlh_32_memop" << std::endl; failed++; }
    try { test_sttadd_ldtadd_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttadd_ldtadd_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttaddl_ldtaddl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttaddl_ldtaddl_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttadd_ldtadd_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttadd_ldtadd_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttaddl_ldtaddl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttaddl_ldtaddl_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttclr_ldtclr_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttclr_ldtclr_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttclrl_ldtclrl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttclrl_ldtclrl_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttclr_ldtclr_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttclr_ldtclr_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttclrl_ldtclrl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttclrl_ldtclrl_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttnp_q_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: sttnp_q_ldstnapair_offs" << std::endl; failed++; }
    try { test_sttnp_64_ldstnapair_offs(); } catch (...) { std::cerr << "FAIL: sttnp_64_ldstnapair_offs" << std::endl; failed++; }
    try { test_sttp_q_ldstpair_post(); } catch (...) { std::cerr << "FAIL: sttp_q_ldstpair_post" << std::endl; failed++; }
    try { test_sttp_q_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: sttp_q_ldstpair_pre" << std::endl; failed++; }
    try { test_sttp_q_ldstpair_off(); } catch (...) { std::cerr << "FAIL: sttp_q_ldstpair_off" << std::endl; failed++; }
    try { test_sttp_64_ldstpair_post(); } catch (...) { std::cerr << "FAIL: sttp_64_ldstpair_post" << std::endl; failed++; }
    try { test_sttp_64_ldstpair_pre(); } catch (...) { std::cerr << "FAIL: sttp_64_ldstpair_pre" << std::endl; failed++; }
    try { test_sttp_64_ldstpair_off(); } catch (...) { std::cerr << "FAIL: sttp_64_ldstpair_off" << std::endl; failed++; }
    try { test_sttr_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: sttr_32_ldst_unpriv" << std::endl; failed++; }
    try { test_sttr_64_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: sttr_64_ldst_unpriv" << std::endl; failed++; }
    try { test_sttrb_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: sttrb_32_ldst_unpriv" << std::endl; failed++; }
    try { test_sttrh_32_ldst_unpriv(); } catch (...) { std::cerr << "FAIL: sttrh_32_ldst_unpriv" << std::endl; failed++; }
    try { test_sttset_ldtset_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttset_ldtset_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttsetl_ldtsetl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttsetl_ldtsetl_32_memop_unpriv" << std::endl; failed++; }
    try { test_sttset_ldtset_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttset_ldtset_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttsetl_ldtsetl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: sttsetl_ldtsetl_64_memop_unpriv" << std::endl; failed++; }
    try { test_sttxr_sr32_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: sttxr_sr32_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_sttxr_sr64_ldstexclr_unpriv(); } catch (...) { std::cerr << "FAIL: sttxr_sr64_ldstexclr_unpriv" << std::endl; failed++; }
    try { test_stumax_ldumax_32_memop(); } catch (...) { std::cerr << "FAIL: stumax_ldumax_32_memop" << std::endl; failed++; }
    try { test_stumaxl_ldumaxl_32_memop(); } catch (...) { std::cerr << "FAIL: stumaxl_ldumaxl_32_memop" << std::endl; failed++; }
    try { test_stumax_ldumax_64_memop(); } catch (...) { std::cerr << "FAIL: stumax_ldumax_64_memop" << std::endl; failed++; }
    try { test_stumaxl_ldumaxl_64_memop(); } catch (...) { std::cerr << "FAIL: stumaxl_ldumaxl_64_memop" << std::endl; failed++; }
    try { test_stumaxb_ldumaxb_32_memop(); } catch (...) { std::cerr << "FAIL: stumaxb_ldumaxb_32_memop" << std::endl; failed++; }
    try { test_stumaxlb_ldumaxlb_32_memop(); } catch (...) { std::cerr << "FAIL: stumaxlb_ldumaxlb_32_memop" << std::endl; failed++; }
    try { test_stumaxh_ldumaxh_32_memop(); } catch (...) { std::cerr << "FAIL: stumaxh_ldumaxh_32_memop" << std::endl; failed++; }
    try { test_stumaxlh_ldumaxlh_32_memop(); } catch (...) { std::cerr << "FAIL: stumaxlh_ldumaxlh_32_memop" << std::endl; failed++; }
    try { test_stumin_ldumin_32_memop(); } catch (...) { std::cerr << "FAIL: stumin_ldumin_32_memop" << std::endl; failed++; }
    try { test_stuminl_lduminl_32_memop(); } catch (...) { std::cerr << "FAIL: stuminl_lduminl_32_memop" << std::endl; failed++; }
    try { test_stumin_ldumin_64_memop(); } catch (...) { std::cerr << "FAIL: stumin_ldumin_64_memop" << std::endl; failed++; }
    try { test_stuminl_lduminl_64_memop(); } catch (...) { std::cerr << "FAIL: stuminl_lduminl_64_memop" << std::endl; failed++; }
    try { test_stuminb_lduminb_32_memop(); } catch (...) { std::cerr << "FAIL: stuminb_lduminb_32_memop" << std::endl; failed++; }
    try { test_stuminlb_lduminlb_32_memop(); } catch (...) { std::cerr << "FAIL: stuminlb_lduminlb_32_memop" << std::endl; failed++; }
    try { test_stuminh_lduminh_32_memop(); } catch (...) { std::cerr << "FAIL: stuminh_lduminh_32_memop" << std::endl; failed++; }
    try { test_stuminlh_lduminlh_32_memop(); } catch (...) { std::cerr << "FAIL: stuminlh_lduminlh_32_memop" << std::endl; failed++; }
    try { test_stur_b_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_b_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_h_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_h_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_s_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_s_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_d_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_d_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_q_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_q_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_32_ldst_unscaled" << std::endl; failed++; }
    try { test_stur_64_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: stur_64_ldst_unscaled" << std::endl; failed++; }
    try { test_sturb_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: sturb_32_ldst_unscaled" << std::endl; failed++; }
    try { test_sturh_32_ldst_unscaled(); } catch (...) { std::cerr << "FAIL: sturh_32_ldst_unscaled" << std::endl; failed++; }
    try { test_stxp_sp32_ldstexclp(); } catch (...) { std::cerr << "FAIL: stxp_sp32_ldstexclp" << std::endl; failed++; }
    try { test_stxp_sp64_ldstexclp(); } catch (...) { std::cerr << "FAIL: stxp_sp64_ldstexclp" << std::endl; failed++; }
    try { test_stxr_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stxr_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stxr_sr64_ldstexclr(); } catch (...) { std::cerr << "FAIL: stxr_sr64_ldstexclr" << std::endl; failed++; }
    try { test_stxrb_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stxrb_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stxrh_sr32_ldstexclr(); } catch (...) { std::cerr << "FAIL: stxrh_sr32_ldstexclr" << std::endl; failed++; }
    try { test_stz2g_64spost_ldsttags(); } catch (...) { std::cerr << "FAIL: stz2g_64spost_ldsttags" << std::endl; failed++; }
    try { test_stz2g_64spre_ldsttags(); } catch (...) { std::cerr << "FAIL: stz2g_64spre_ldsttags" << std::endl; failed++; }
    try { test_stz2g_64soffset_ldsttags(); } catch (...) { std::cerr << "FAIL: stz2g_64soffset_ldsttags" << std::endl; failed++; }
    try { test_stzg_64spost_ldsttags(); } catch (...) { std::cerr << "FAIL: stzg_64spost_ldsttags" << std::endl; failed++; }
    try { test_stzg_64spre_ldsttags(); } catch (...) { std::cerr << "FAIL: stzg_64spre_ldsttags" << std::endl; failed++; }
    try { test_stzg_64soffset_ldsttags(); } catch (...) { std::cerr << "FAIL: stzg_64soffset_ldsttags" << std::endl; failed++; }
    try { test_stzgm_64bulk_ldsttags(); } catch (...) { std::cerr << "FAIL: stzgm_64bulk_ldsttags" << std::endl; failed++; }
    try { test_swp_32_memop(); } catch (...) { std::cerr << "FAIL: swp_32_memop" << std::endl; failed++; }
    try { test_swpa_32_memop(); } catch (...) { std::cerr << "FAIL: swpa_32_memop" << std::endl; failed++; }
    try { test_swpal_32_memop(); } catch (...) { std::cerr << "FAIL: swpal_32_memop" << std::endl; failed++; }
    try { test_swpl_32_memop(); } catch (...) { std::cerr << "FAIL: swpl_32_memop" << std::endl; failed++; }
    try { test_swp_64_memop(); } catch (...) { std::cerr << "FAIL: swp_64_memop" << std::endl; failed++; }
    try { test_swpa_64_memop(); } catch (...) { std::cerr << "FAIL: swpa_64_memop" << std::endl; failed++; }
    try { test_swpal_64_memop(); } catch (...) { std::cerr << "FAIL: swpal_64_memop" << std::endl; failed++; }
    try { test_swpl_64_memop(); } catch (...) { std::cerr << "FAIL: swpl_64_memop" << std::endl; failed++; }
    try { test_swpb_32_memop(); } catch (...) { std::cerr << "FAIL: swpb_32_memop" << std::endl; failed++; }
    try { test_swpab_32_memop(); } catch (...) { std::cerr << "FAIL: swpab_32_memop" << std::endl; failed++; }
    try { test_swpalb_32_memop(); } catch (...) { std::cerr << "FAIL: swpalb_32_memop" << std::endl; failed++; }
    try { test_swplb_32_memop(); } catch (...) { std::cerr << "FAIL: swplb_32_memop" << std::endl; failed++; }
    try { test_swph_32_memop(); } catch (...) { std::cerr << "FAIL: swph_32_memop" << std::endl; failed++; }
    try { test_swpah_32_memop(); } catch (...) { std::cerr << "FAIL: swpah_32_memop" << std::endl; failed++; }
    try { test_swpalh_32_memop(); } catch (...) { std::cerr << "FAIL: swpalh_32_memop" << std::endl; failed++; }
    try { test_swplh_32_memop(); } catch (...) { std::cerr << "FAIL: swplh_32_memop" << std::endl; failed++; }
    try { test_swpp_128_memop_128(); } catch (...) { std::cerr << "FAIL: swpp_128_memop_128" << std::endl; failed++; }
    try { test_swppa_128_memop_128(); } catch (...) { std::cerr << "FAIL: swppa_128_memop_128" << std::endl; failed++; }
    try { test_swppal_128_memop_128(); } catch (...) { std::cerr << "FAIL: swppal_128_memop_128" << std::endl; failed++; }
    try { test_swppl_128_memop_128(); } catch (...) { std::cerr << "FAIL: swppl_128_memop_128" << std::endl; failed++; }
    try { test_swpt_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swpt_32_memop_unpriv" << std::endl; failed++; }
    try { test_swpta_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swpta_32_memop_unpriv" << std::endl; failed++; }
    try { test_swptal_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swptal_32_memop_unpriv" << std::endl; failed++; }
    try { test_swptl_32_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swptl_32_memop_unpriv" << std::endl; failed++; }
    try { test_swpt_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swpt_64_memop_unpriv" << std::endl; failed++; }
    try { test_swpta_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swpta_64_memop_unpriv" << std::endl; failed++; }
    try { test_swptal_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swptal_64_memop_unpriv" << std::endl; failed++; }
    try { test_swptl_64_memop_unpriv(); } catch (...) { std::cerr << "FAIL: swptl_64_memop_unpriv" << std::endl; failed++; }

    std::cout << (1075 - failed) << " / 1075 passed" << std::endl;
    return failed;
}
