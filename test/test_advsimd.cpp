// Test suite for advsimd instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace veda64::Advsimd;
using namespace veda64;

void test_abs_asisdmisc_r() {
    // Test ABS: Absolute value (vector)

    // Create test instruction using encode function
    uint32_t test_insn = encode_abs_asisdmisc_r(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ABS);

    std::cout << "  abs_asisdmisc_r: " << result->to_string() << std::endl;
}

void test_add_asisdsame_only() {
    // Test ADD: Add (vector)

    // Create test instruction using encode function
    uint32_t test_insn = encode_add_asisdsame_only(0, 0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_asisdsame_only: " << result->to_string() << std::endl;
}

void test_addhn_asimddiff_n() {
    // Test ADDHN: Add returning high narrow

    // Create test instruction using encode function
    uint32_t test_insn = encode_addhn_asimddiff_n(0, 0, 0, 0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDHN);

    std::cout << "  addhn_asimddiff_n: " << result->to_string() << std::endl;
}

void test_addp_asisdpair_only() {
    // Test ADDP: Add pair of elements (scalar)

    // Create test instruction using encode function
    uint32_t test_insn = encode_addp_asisdpair_only(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDP);

    std::cout << "  addp_asisdpair_only: " << result->to_string() << std::endl;
}

void test_addp_asimdsame_only() {
    // Test ADDP: Add pairwise (vector)

    // Create test instruction using encode function
    uint32_t test_insn = encode_addp_asimdsame_only(0, 0, 0, 0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDP);

    std::cout << "  addp_asimdsame_only: " << result->to_string() << std::endl;
}

void test_addv_asimdall_only() {
    // Test ADDV: Add across vector

    // Create test instruction using encode function
    uint32_t test_insn = encode_addv_asimdall_only(0, 0, 0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDV);

    std::cout << "  addv_asimdall_only: " << result->to_string() << std::endl;
}

void test_aesd_b_cryptoaes() {
    // Test AESD: AES single round decryption

    // Create test instruction using encode function
    uint32_t test_insn = encode_aesd_b_cryptoaes(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AESD);

    std::cout << "  aesd_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aese_b_cryptoaes() {
    // Test AESE: AES single round encryption

    // Create test instruction using encode function
    uint32_t test_insn = encode_aese_b_cryptoaes(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AESE);

    std::cout << "  aese_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesimc_b_cryptoaes() {
    // Test AESIMC: AES inverse mix columns

    // Create test instruction using encode function
    uint32_t test_insn = encode_aesimc_b_cryptoaes(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::AESIMC);

    std::cout << "  aesimc_b_cryptoaes: " << result->to_string() << std::endl;
}

void test_aesmc_b_cryptoaes() {
    // Test AESMC: AES mix columns

    // Create test instruction using encode function
    uint32_t test_insn = encode_aesmc_b_cryptoaes(0, 0);

    auto result = decode_advsimd(test_insn);
    assert(result.has_value());
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
