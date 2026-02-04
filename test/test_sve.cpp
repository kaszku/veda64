// Test suite for sve instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace veda64::Sve;
using namespace veda64;

void test_abs_z_p_z_m() {
    // Test ABS: Absolute value (predicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_abs_z_p_z_m(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ABS);

    std::cout << "  abs_z_p_z_m: " << result->to_string() << std::endl;
}

void test_add_z_p_zz_() {
    // Test ADD: Add (predicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_add_z_p_zz_(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_p_zz_: " << result->to_string() << std::endl;
}

void test_add_z_zi_() {
    // Test ADD: Add immediate (unpredicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_add_z_zi_(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_zi_: " << result->to_string() << std::endl;
}

void test_add_z_zz_() {
    // Test ADD: Add (unpredicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_add_z_zz_(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_z_zz_: " << result->to_string() << std::endl;
}

void test_addpl_r_ri_() {
    // Test ADDPL: Add multiple of predicate register size to scalar register

    // Create test instruction using encode function
    uint32_t test_insn = encode_addpl_r_ri_(0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDPL);

    std::cout << "  addpl_r_ri_: " << result->to_string() << std::endl;
}

void test_addvl_r_ri_() {
    // Test ADDVL: Add multiple of vector register size to scalar register

    // Create test instruction using encode function
    uint32_t test_insn = encode_addvl_r_ri_(0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDVL);

    std::cout << "  addvl_r_ri_: " << result->to_string() << std::endl;
}

void test_adr_z_az_sd_same_scaled() {
    // Test ADR: Calculate vector address

    // Create test instruction using encode function
    uint32_t test_insn = encode_adr_z_az_sd_same_scaled(0, 0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADR);

    std::cout << "  adr_z_az_sd_same_scaled: " << result->to_string() << std::endl;
}

void test_and_p_p_pp_z() {
    // Test AND: Bitwise AND predicates

    // Create test instruction using encode function
    uint32_t test_insn = encode_and_p_p_pp_z(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AND);

    std::cout << "  and_p_p_pp_z: " << result->to_string() << std::endl;
}

void test_and_z_p_zz_() {
    // Test AND: Bitwise AND (predicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_and_z_p_zz_(0, 0, 0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AND);

    std::cout << "  and_z_p_zz_: " << result->to_string() << std::endl;
}

void test_and_z_zi_() {
    // Test AND: Bitwise AND with immediate (unpredicated)

    // Create test instruction using encode function
    uint32_t test_insn = encode_and_z_zi_(0, 0);

    auto result = decode_sve(test_insn);
    assert(result.has_value());
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
