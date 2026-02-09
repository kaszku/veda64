// Auto-generated - do not edit
// Test suite for mortlach2 instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_add_mz_zzv_2x1() {
    // Test ADD: Multi-vector add by vector to multi-vector
    uint32_t test_insn = 0xC120A300u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_mz_zzv_2x1: " << result->to_string() << std::endl;
}

void test_add_za_zw_2x2() {
    // Test ADD: Multi-vector accumulate to ZA array vectors
    uint32_t test_insn = 0xC1A01C10u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_za_zw_2x2: " << result->to_string() << std::endl;
}

void test_add_za_zzv_2x1() {
    // Test ADD: Multi-vector add by vector to ZA array vectors
    uint32_t test_insn = 0xC1201810u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_za_zzv_2x1: " << result->to_string() << std::endl;
}

void test_add_za_zzw_2x2() {
    // Test ADD: Multi-vector add to ZA array vectors
    uint32_t test_insn = 0xC1A01810u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADD);

    std::cout << "  add_za_zzw_2x2: " << result->to_string() << std::endl;
}

void test_bf1cvt_mz2_z8_() {
    // Test : Multi-vector 8-bit floating-point convert to BFloat16
    uint32_t test_insn = 0xC166E000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

    std::cout << "  bf1cvt_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bf1cvtl_mz2_z8_() {
    // Test : Multi-vector 8-bit floating-point convert to deinterleaved BFloat16
    uint32_t test_insn = 0xC166E001u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

    std::cout << "  bf1cvtl_mz2_z8_: " << result->to_string() << std::endl;
}

void test_bfadd_za_zw_2x2_16() {
    // Test BFADD: Multi-vector BFloat16 accumulate to ZA array vectors
    uint32_t test_insn = 0xC1E41C00u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BFADD);

    std::cout << "  bfadd_za_zw_2x2_16: " << result->to_string() << std::endl;
}

void test_bfclamp_mz_zz_2() {
    // Test BFCLAMP: Multi-vector BFloat16 clamp to minimum/maximum number
    uint32_t test_insn = 0xC120C000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BFCLAMP);

    std::cout << "  bfclamp_mz_zz_2: " << result->to_string() << std::endl;
}

void test_bfcvt_z8_mz2_() {
    // Test BFCVT: Multi-vector BFloat16 convert to 8-bit floating-point
    uint32_t test_insn = 0xC164E000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BFCVT);

    std::cout << "  bfcvt_z8_mz2_: " << result->to_string() << std::endl;
}

void test_bfcvt_z_mz2_() {
    // Test BFCVT: Multi-vector single-precision convert to BFloat16
    uint32_t test_insn = 0xC160E000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BFCVT);

    std::cout << "  bfcvt_z_mz2_: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running mortlach2 tests..." << std::endl;

    test_add_mz_zzv_2x1();
    test_add_za_zw_2x2();
    test_add_za_zzv_2x1();
    test_add_za_zzw_2x2();
    test_bf1cvt_mz2_z8_();
    test_bf1cvtl_mz2_z8_();
    test_bfadd_za_zw_2x2_16();
    test_bfclamp_mz_zz_2();
    test_bfcvt_z8_mz2_();
    test_bfcvt_z_mz2_();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
