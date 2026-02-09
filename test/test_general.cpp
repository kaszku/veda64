// Auto-generated - do not edit
// Test suite for general instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_32_dp_1src() {
    // Test ABS: Absolute value
    uint32_t test_insn = 0x5AC02000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ABS);

    std::cout << "  abs_32_dp_1src: " << result->to_string() << std::endl;
}

void test_adc_32_addsub_carry() {
    // Test ADC: Add with carry
    uint32_t test_insn = 0x1A000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADC);

    std::cout << "  adc_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_adcs_32_addsub_carry() {
    // Test ADCS: Add with carry, setting flags
    uint32_t test_insn = 0x3A000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADCS);

    std::cout << "  adcs_32_addsub_carry: " << result->to_string() << std::endl;
}

void test_add_32_addsub_ext() {
    // Test ADD: Add extended and scaled register
    uint32_t test_insn = 0x0B200000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_32_addsub_ext: " << result->to_string() << std::endl;
}

void test_add_32_addsub_imm() {
    // Test ADD: Add immediate value
    uint32_t test_insn = 0x11000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_32_addsub_imm: " << result->to_string() << std::endl;
}

void test_add_32_addsub_shift() {
    // Test ADD: Add optionally-shifted register
    uint32_t test_insn = 0x0B000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_32_addsub_shift: " << result->to_string() << std::endl;
}

void test_addg_64_addsub_immtags() {
    // Test ADDG: Add with tag
    uint32_t test_insn = 0x91800000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDG);

    std::cout << "  addg_64_addsub_immtags: " << result->to_string() << std::endl;
}

void test_addpt_64_addsub_pt() {
    // Test ADDPT: Add checked pointer
    uint32_t test_insn = 0x9A002000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDPT);

    std::cout << "  addpt_64_addsub_pt: " << result->to_string() << std::endl;
}

void test_adds_32s_addsub_ext() {
    // Test ADDS: Add extended and scaled register, setting flags
    uint32_t test_insn = 0x2B200000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDS);

    std::cout << "  adds_32s_addsub_ext: " << result->to_string() << std::endl;
}

void test_adds_32s_addsub_imm() {
    // Test ADDS: Add immediate value, setting flags
    uint32_t test_insn = 0x31000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDS);

    std::cout << "  adds_32s_addsub_imm: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running general tests..." << std::endl;

    test_abs_32_dp_1src();
    test_adc_32_addsub_carry();
    test_adcs_32_addsub_carry();
    test_add_32_addsub_ext();
    test_add_32_addsub_imm();
    test_add_32_addsub_shift();
    test_addg_64_addsub_immtags();
    test_addpt_64_addsub_pt();
    test_adds_32s_addsub_ext();
    test_adds_32s_addsub_imm();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
