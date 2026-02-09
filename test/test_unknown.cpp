// Auto-generated - do not edit
// Test suite for unknown instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_autia_64p_dp_1src() {
    // Test : Authenticate instruction address, using key A
    uint32_t test_insn = 0xDAC11000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

    std::cout << "  autia_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_autib_64p_dp_1src() {
    // Test : Authenticate instruction address, using key B
    uint32_t test_insn = 0xDAC11400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

    std::cout << "  autib_64p_dp_1src: " << result->to_string() << std::endl;
}

void test_fmopa_za_pp_zz_16() {
    // Test FMOPA: Floating-point outer product, accumulating
    uint32_t test_insn = 0x81800008u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FMOPA);

    std::cout << "  fmopa_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_fmops_za_pp_zz_16() {
    // Test FMOPS: Floating-point outer product, subtracting
    uint32_t test_insn = 0x81800018u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FMOPS);

    std::cout << "  fmops_za_pp_zz_16: " << result->to_string() << std::endl;
}

void test_ld1d_z_p_bi_u64() {
    // Test LD1D: Contiguous load unsigned doublewords to vector (immediate index)
    uint32_t test_insn = 0xA5E0A000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);

    std::cout << "  ld1d_z_p_bi_u64: " << result->to_string() << std::endl;
}

void test_ld1d_z_p_br_u64() {
    // Test LD1D: Contiguous load unsigned doublewords to vector (scalar index)
    uint32_t test_insn = 0xA5FF4000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LD1D);

    std::cout << "  ld1d_z_p_br_u64: " << result->to_string() << std::endl;
}

void test_ld1w_z_p_bi_u32() {
    // Test LD1W: Contiguous load unsigned words to vector (immediate index)
    uint32_t test_insn = 0xA540A000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);

    std::cout << "  ld1w_z_p_bi_u32: " << result->to_string() << std::endl;
}

void test_ld1w_z_p_br_u32() {
    // Test LD1W: Contiguous load unsigned words to vector (scalar index)
    uint32_t test_insn = 0xA55F4000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LD1W);

    std::cout << "  ld1w_z_p_br_u32: " << result->to_string() << std::endl;
}

void test_ldraa_64_ldst_pac() {
    // Test : Load register, with pointer authentication
    uint32_t test_insn = 0xF8200400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

    std::cout << "  ldraa_64_ldst_pac: " << result->to_string() << std::endl;
}

void test_pacia_64p_dp_1src() {
    // Test : Pointer Authentication Code for instruction address, using key A
    uint32_t test_insn = 0xDAC10000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;

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
