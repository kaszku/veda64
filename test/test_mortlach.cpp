// Test suite for mortlach instruction class
#include "veda64.hpp"
#include "class/mortlach.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace veda64::Mortlach;
using namespace veda64;

void test_addha_za_pp_z_32() {
    // Test ADDHA: Add horizontally vector elements to ZA tile

    // Create test instruction using encode function
    uint32_t test_insn = encode_addha_za_pp_z_32(0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDHA);

    std::cout << "  addha_za_pp_z_32: " << result->to_string() << std::endl;
}

void test_addspl_r_ri_() {
    // Test ADDSPL: Add multiple of Streaming SVE predicate register size to scalar register

    // Create test instruction using encode function
    uint32_t test_insn = encode_addspl_r_ri_(0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDSPL);

    std::cout << "  addspl_r_ri_: " << result->to_string() << std::endl;
}

void test_addsvl_r_ri_() {
    // Test ADDSVL: Add multiple of Streaming SVE vector register size to scalar register

    // Create test instruction using encode function
    uint32_t test_insn = encode_addsvl_r_ri_(0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDSVL);

    std::cout << "  addsvl_r_ri_: " << result->to_string() << std::endl;
}

void test_addva_za_pp_z_32() {
    // Test ADDVA: Add vertically vector elements to ZA tile

    // Create test instruction using encode function
    uint32_t test_insn = encode_addva_za_pp_z_32(0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::ADDVA);

    std::cout << "  addva_za_pp_z_32: " << result->to_string() << std::endl;
}

void test_bfmopa_za32_pp_zz_() {
    // Test BFMOPA: BFloat16 sum of outer products to single-precision, accumulating

    // Create test instruction using encode function
    uint32_t test_insn = encode_bfmopa_za32_pp_zz_(0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::BFMOPA);

    std::cout << "  bfmopa_za32_pp_zz_: " << result->to_string() << std::endl;
}

void test_bfmops_za32_pp_zz_() {
    // Test BFMOPS: BFloat16 sum of outer products to single-precision, subtracting

    // Create test instruction using encode function
    uint32_t test_insn = encode_bfmops_za32_pp_zz_(0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::BFMOPS);

    std::cout << "  bfmops_za32_pp_zz_: " << result->to_string() << std::endl;
}

void test_fmopa_za32_pp_zz_16() {
    // Test FMOPA: Half-precision sum of outer products to single-precision, accumulating

    // Create test instruction using encode function
    uint32_t test_insn = encode_fmopa_za32_pp_zz_16(0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::FMOPA);

    std::cout << "  fmopa_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmops_za32_pp_zz_16() {
    // Test FMOPS: Half-precision sum of outer products to single-precision, subtracting

    // Create test instruction using encode function
    uint32_t test_insn = encode_fmops_za32_pp_zz_16(0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::FMOPS);

    std::cout << "  fmops_za32_pp_zz_16: " << result->to_string() << std::endl;
}

void test_ld1b_za_p_rrr_() {
    // Test LD1B: Contiguous load of bytes to 8-bit element ZA tile slice

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1b_za_p_rrr_(0, 0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1B);

    std::cout << "  ld1b_za_p_rrr_: " << result->to_string() << std::endl;
}

void test_ld1d_za_p_rrr_() {
    // Test LD1D: Contiguous load of doublewords to 64-bit element ZA tile slice

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1d_za_p_rrr_(0, 0, 0, 0, 0, 0, 0);

    auto result = decode_mortlach(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1D);

    std::cout << "  ld1d_za_p_rrr_: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running mortlach tests..." << std::endl;

    test_addha_za_pp_z_32();
    test_addspl_r_ri_();
    test_addsvl_r_ri_();
    test_addva_za_pp_z_32();
    test_bfmopa_za32_pp_zz_();
    test_bfmops_za32_pp_zz_();
    test_fmopa_za32_pp_zz_16();
    test_fmops_za32_pp_zz_16();
    test_ld1b_za_p_rrr_();
    test_ld1d_za_p_rrr_();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
