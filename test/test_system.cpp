// Test suite for system instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace veda64::System;
using namespace veda64;

void test_apas_sys_cr_systeminstrs() {
    // Test SYS: Associate physical address space

    // Create test instruction using encode function
    uint32_t test_insn = encode_apas_sys_cr_systeminstrs(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  apas_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_at_sys_cr_systeminstrs() {
    // Test SYS: Address translate

    // Create test instruction using encode function
    uint32_t test_insn = encode_at_sys_cr_systeminstrs(0, 0, 8, 0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  at_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_axflag_m_pstate() {
    // Test AXFLAG: Convert floating-point condition flags from Arm to external format

    // Create test instruction using encode function
    uint32_t test_insn = encode_axflag_m_pstate(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AXFLAG);

    std::cout << "  axflag_m_pstate: " << result->to_string() << std::endl;
}

void test_brb_sys_cr_systeminstrs() {
    // Test SYS: Branch record buffer

    // Create test instruction using encode function
    uint32_t test_insn = encode_brb_sys_cr_systeminstrs(0, 0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  brb_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_brk_ex_exception() {
    // Test BRK: Breakpoint instruction

    // Create test instruction using encode function
    uint32_t test_insn = encode_brk_ex_exception(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::BRK);

    std::cout << "  brk_ex_exception: " << result->to_string() << std::endl;
}

void test_bti_hb_hints() {
    // Test BTI: Branch target identification

    // Create test instruction using encode function
    uint32_t test_insn = encode_bti_hb_hints(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::BTI);

    std::cout << "  bti_hb_hints: " << result->to_string() << std::endl;
}

void test_cfinv_m_pstate() {
    // Test CFINV: Invert carry flag

    // Create test instruction using encode function
    uint32_t test_insn = encode_cfinv_m_pstate(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::CFINV);

    std::cout << "  cfinv_m_pstate: " << result->to_string() << std::endl;
}

void test_cfp_sys_cr_systeminstrs() {
    // Test SYS: Control flow prediction restriction by context

    // Create test instruction using encode function
    uint32_t test_insn = encode_cfp_sys_cr_systeminstrs(0);

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  cfp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_chkfeat_hf_hints() {
    // Test CHKFEAT: Check feature status

    // Create test instruction using encode function
    uint32_t test_insn = encode_chkfeat_hf_hints();

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::CHKFEAT);

    std::cout << "  chkfeat_hf_hints: " << result->to_string() << std::endl;
}

void test_clrbhb_hi_hints() {
    // Test CLRBHB: Clear branch history

    // Create test instruction using encode function
    uint32_t test_insn = encode_clrbhb_hi_hints();

    auto result = decode_system(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::CLRBHB);

    std::cout << "  clrbhb_hi_hints: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running system tests..." << std::endl;

    test_apas_sys_cr_systeminstrs();
    test_at_sys_cr_systeminstrs();
    test_axflag_m_pstate();
    test_brb_sys_cr_systeminstrs();
    test_brk_ex_exception();
    test_bti_hb_hints();
    test_cfinv_m_pstate();
    test_cfp_sys_cr_systeminstrs();
    test_chkfeat_hf_hints();
    test_clrbhb_hi_hints();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
