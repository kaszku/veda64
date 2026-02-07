// Test suite for unknown instruction class
#include "veda64.hpp"
#include "class/unknown.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace veda64::Unknown;
using namespace veda64;

void test_autia_64p_dp_1src() {
    // Test : Authenticate instruction address, using key A

    // Create test instruction using encode function
    uint32_t test_insn = encode_autia_64p_dp_1src(0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());

    std::cout << "  autia_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autib_64p_dp_1src() {
    // Test : Authenticate instruction address, using key B

    // Create test instruction using encode function
    uint32_t test_insn = encode_autib_64p_dp_1src(0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());

    std::cout << "  autib_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_fmopa_za_pp_zz_16() {
    // Test FMOPA: Floating-point outer product, accumulating

    // Create test instruction using encode function
    uint32_t test_insn = encode_fmopa_za_pp_zz_16(0, 0, 0, 0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::FMOPA);

    std::cout << "  fmopa_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmops_za_pp_zz_16() {
    // Test FMOPS: Floating-point outer product, subtracting

    // Create test instruction using encode function
    uint32_t test_insn = encode_fmops_za_pp_zz_16(0, 0, 0, 0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::FMOPS);

    std::cout << "  fmops_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_ld1d_z_p_bi_u64() {
    // Test LD1D: Contiguous load unsigned doublewords to vector (immediate index)

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1d_z_p_bi_u64(0, 0, 0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1D);

    std::cout << "  ld1d_z_p_bi_u64: " << result->to_string() << std::endl;
}

void test_ld1d_z_p_br_u64() {
    // Test LD1D: Contiguous load unsigned doublewords to vector (scalar index)

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1d_z_p_br_u64(0, 0, 0, 31);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1D);

    std::cout << "  ld1d_z_p_br_u64: " << result->to_string() << std::endl;
}

void test_ld1w_z_p_bi_u32() {
    // Test LD1W: Contiguous load unsigned words to vector (immediate index)

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1w_z_p_bi_u32(0, 0, 0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1W);

    std::cout << "  ld1w_z_p_bi_u32: " << result->to_string() << std::endl;
}

void test_ld1w_z_p_br_u32() {
    // Test LD1W: Contiguous load unsigned words to vector (scalar index)

    // Create test instruction using encode function
    uint32_t test_insn = encode_ld1w_z_p_br_u32(0, 0, 0, 31);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());
    assert(result->mnemonic == Mnemonic::LD1W);

    std::cout << "  ld1w_z_p_br_u32: " << result->to_string() << std::endl;
}

void test_ldraa_64_ldst_pac() {
    // Test : Load register, with pointer authentication

    // Create test instruction using encode function
    uint32_t test_insn = encode_ldraa_64_ldst_pac(0, 0, 0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());

    std::cout << "  ldraa_64_ldst_pac: " << result->to_string() << std::endl;
}

void test_pacia_64p_dp_1src() {
    // Test : Pointer Authentication Code for instruction address, using key A

    // Create test instruction using encode function
    uint32_t test_insn = encode_pacia_64p_dp_1src(0, 0);

    auto result = decode_unknown(test_insn);
    assert(result.has_value());

    std::cout << "  pacia_64p_dp_1src: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running unknown tests..." << std::endl;

    test_autia_64p_dp_1src();
    test_autib_64p_dp_1src();
    test_fmopa_za_pp_zz_16();
    test_fmops_za_pp_zz_16();
    test_ld1d_z_p_bi_u64();
    test_ld1d_z_p_br_u64();
    test_ld1w_z_p_bi_u32();
    test_ld1w_z_p_br_u32();
    test_ldraa_64_ldst_pac();
    test_pacia_64p_dp_1src();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
