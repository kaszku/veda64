// Auto-generated - do not edit
// Test suite for sve instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_z_p_z_m() {
    // Test ABS: Absolute value (predicated)
    uint32_t test_insn = 0x0416A000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ABS);

    std::cout << "  abs_z_p_z_m: " << result->to_string() << std::endl;
}

void test_add_z_p_zz_() {
    // Test ADD: Add (predicated)
    uint32_t test_insn = 0x04000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_p_zz_: " << result->to_string() << std::endl;
}

void test_add_z_zi_() {
    // Test ADD: Add immediate (unpredicated)
    uint32_t test_insn = 0x2520C000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_zi_: " << result->to_string() << std::endl;
}

void test_add_z_zz_() {
    // Test ADD: Add (unpredicated)
    uint32_t test_insn = 0x04200000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_zz_: " << result->to_string() << std::endl;
}

void test_addpl_r_ri_() {
    // Test ADDPL: Add multiple of predicate register size to scalar register
    uint32_t test_insn = 0x04605000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDPL);

    std::cout << "  addpl_r_ri_: " << result->to_string() << std::endl;
}

void test_addvl_r_ri_() {
    // Test ADDVL: Add multiple of vector register size to scalar register
    uint32_t test_insn = 0x04205000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDVL);

    std::cout << "  addvl_r_ri_: " << result->to_string() << std::endl;
}

void test_adr_z_az_sd_same_scaled() {
    // Test ADR: Calculate vector address
    uint32_t test_insn = 0x04A0A000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADR);

    std::cout << "  adr_z_az_sd_same_scaled: " << result->to_string() << std::endl;
}

void test_and_p_p_pp_z() {
    // Test AND: Bitwise AND predicates
    uint32_t test_insn = 0x25004000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AND);

    std::cout << "  and_p_p_pp_z: " << result->to_string() << std::endl;
}

void test_and_z_p_zz_() {
    // Test AND: Bitwise AND (predicated)
    uint32_t test_insn = 0x041A0000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AND);

    std::cout << "  and_z_p_zz_: " << result->to_string() << std::endl;
}

void test_and_z_zi_() {
    // Test AND: Bitwise AND with immediate (unpredicated)
    uint32_t test_insn = 0x05800000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AND);

    std::cout << "  and_z_zi_: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running sve tests..." << std::endl;

    test_abs_z_p_z_m();
    test_add_z_p_zz_();
    test_add_z_zi_();
    test_add_z_zz_();
    test_addpl_r_ri_();
    test_addvl_r_ri_();
    test_adr_z_az_sd_same_scaled();
    test_and_p_p_pp_z();
    test_and_z_p_zz_();
    test_and_z_zi_();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
