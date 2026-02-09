// Auto-generated - do not edit
// Test suite for system instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_apas_sys_cr_systeminstrs() {
    // Test SYS: Associate physical address space
    uint32_t test_insn = 0xD50E7000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  apas_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_at_sys_cr_systeminstrs() {
    // Test SYS: Address translate
    uint32_t test_insn = 0xD5087800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  at_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_axflag_m_pstate() {
    // Test AXFLAG: Convert floating-point condition flags from Arm to external format
    uint32_t test_insn = 0xD500405Fu;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AXFLAG);

    std::cout << "  axflag_m_pstate: " << result->to_string() << std::endl;
}

void test_brb_sys_cr_systeminstrs() {
    // Test SYS: Branch record buffer
    uint32_t test_insn = 0xD5097200u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  brb_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_brk_ex_exception() {
    // Test BRK: Breakpoint instruction
    uint32_t test_insn = 0xD4200000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BRK);

    std::cout << "  brk_ex_exception: " << result->to_string() << std::endl;
}

void test_bti_hb_hints() {
    // Test BTI: Branch target identification
    uint32_t test_insn = 0xD503241Fu;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BTI);

    std::cout << "  bti_hb_hints: " << result->to_string() << std::endl;
}

void test_cfinv_m_pstate() {
    // Test CFINV: Invert carry flag
    uint32_t test_insn = 0xD500401Fu;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::CFINV);

    std::cout << "  cfinv_m_pstate: " << result->to_string() << std::endl;
}

void test_cfp_sys_cr_systeminstrs() {
    // Test SYS: Control flow prediction restriction by context
    uint32_t test_insn = 0xD50B7380u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::SYS);

    std::cout << "  cfp_sys_cr_systeminstrs: " << result->to_string() << std::endl;
}

void test_chkfeat_hf_hints() {
    // Test CHKFEAT: Check feature status
    uint32_t test_insn = 0xD503251Fu;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::CHKFEAT);

    std::cout << "  chkfeat_hf_hints: " << result->to_string() << std::endl;
}

void test_clrbhb_hi_hints() {
    // Test CLRBHB: Clear branch history
    uint32_t test_insn = 0xD50322DFu;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
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
