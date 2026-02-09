// Auto-generated - do not edit
// Test suite for advsimd instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_abs_asisdmisc_r() {
    // Test ABS: Absolute value (vector)
    uint32_t test_insn = 0x5EE0B800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ABS);

    std::cout << "  abs_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_add_asisdsame_only() {
    // Test ADD: Add (vector)
    uint32_t test_insn = 0x5EE08400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_asisdsame_only: " << result->to_string() << std::endl;
}

void test_addhn_asimddiff_n() {
    // Test ADDHN: Add returning high narrow
    uint32_t test_insn = 0x0E204000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDHN);

    std::cout << "  addhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_addp_asisdpair_only() {
    // Test ADDP: Add pair of elements (scalar)
    uint32_t test_insn = 0x5EF1B800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDP);

    std::cout << "  addp_asisdpair_only: " << result->to_string() << std::endl;
}

void test_addp_asimdsame_only() {
    // Test ADDP: Add pairwise (vector)
    uint32_t test_insn = 0x0E20BC00u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDP);

    std::cout << "  addp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_addv_asimdall_only() {
    // Test ADDV: Add across vector
    uint32_t test_insn = 0x0E31B800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDV);

    std::cout << "  addv_asimdall_only: " << result->to_string() << std::endl;
}

void test_aesd_b_cryptoaes() {
    // Test AESD: AES single round decryption
    uint32_t test_insn = 0x4E285800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AESD);

    std::cout << "  aesd_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aese_b_cryptoaes() {
    // Test AESE: AES single round encryption
    uint32_t test_insn = 0x4E284800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AESE);

    std::cout << "  aese_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesimc_b_cryptoaes() {
    // Test AESIMC: AES inverse mix columns
    uint32_t test_insn = 0x4E287800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AESIMC);

    std::cout << "  aesimc_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesmc_b_cryptoaes() {
    // Test AESMC: AES mix columns
    uint32_t test_insn = 0x4E286800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::AESMC);

    std::cout << "  aesmc_b_cryptoaes: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running advsimd tests..." << std::endl;

    test_abs_asisdmisc_r();
    test_add_asisdsame_only();
    test_addhn_asimddiff_n();
    test_addp_asisdpair_only();
    test_addp_asimdsame_only();
    test_addv_asimdall_only();
    test_aesd_b_cryptoaes();
    test_aese_b_cryptoaes();
    test_aesimc_b_cryptoaes();
    test_aesmc_b_cryptoaes();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
