// Auto-generated - do not edit
// Test suite for fpsimd instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_ldapur_b_ldapstl_simd() {
    // Test LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
    uint32_t test_insn = 0x1D400800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDAPUR);

    std::cout << "  ldapur_b_ldapstl_simd: " << result->to_string() << std::endl;
}

void test_ldnp_s_ldstnapair_offs() {
    // Test LDNP: Load pair of SIMD&FP registers, with non-temporal hint
    uint32_t test_insn = 0x2C400000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDNP);

    std::cout << "  ldnp_s_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldp_s_ldstpair_post() {
    // Test LDP: Load pair of SIMD&FP registers
    uint32_t test_insn = 0x2CC00000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDP);

    std::cout << "  ldp_s_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_immpost() {
    // Test LDR: Load SIMD&FP register (immediate offset)
    uint32_t test_insn = 0x3C400400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDR);

    std::cout << "  ldr_b_ldst_immpost: " << result->to_string() << std::endl;
}

void test_ldr_s_loadlit() {
    // Test LDR: Load SIMD&FP register (PC-relative literal)
    uint32_t test_insn = 0x1C000000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDR);

    std::cout << "  ldr_s_loadlit: " << result->to_string() << std::endl;
}

void test_ldr_b_ldst_regoff() {
    // Test LDR: Load SIMD&FP register (register offset)
    uint32_t test_insn = 0x3C600800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDR);

    std::cout << "  ldr_b_ldst_regoff: " << result->to_string() << std::endl;
}

void test_ldtnp_q_ldstnapair_offs() {
    // Test LDTNP: Load unprivileged pair of SIMD&FP registers, with non-temporal hint
    uint32_t test_insn = 0xEC400000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDTNP);

    std::cout << "  ldtnp_q_ldstnapair_offs: " << result->to_string() << std::endl;
}

void test_ldtp_q_ldstpair_post() {
    // Test LDTP: Load unprivileged pair of SIMD&FP registers
    uint32_t test_insn = 0xECC00000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDTP);

    std::cout << "  ldtp_q_ldstpair_post: " << result->to_string() << std::endl;
}

void test_ldur_b_ldst_unscaled() {
    // Test LDUR: Load SIMD&FP register (unscaled offset)
    uint32_t test_insn = 0x3C400000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::LDUR);

    std::cout << "  ldur_b_ldst_unscaled: " << result->to_string() << std::endl;
}

void test_stlur_b_ldapstl_simd() {
    // Test STLUR: Store-release SIMD&FP register (unscaled offset)
    uint32_t test_insn = 0x1D000800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::STLUR);

    std::cout << "  stlur_b_ldapstl_simd: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running fpsimd tests..." << std::endl;

    test_ldapur_b_ldapstl_simd();
    test_ldnp_s_ldstnapair_offs();
    test_ldp_s_ldstpair_post();
    test_ldr_b_ldst_immpost();
    test_ldr_s_loadlit();
    test_ldr_b_ldst_regoff();
    test_ldtnp_q_ldstnapair_offs();
    test_ldtp_q_ldstpair_post();
    test_ldur_b_ldst_unscaled();
    test_stlur_b_ldapstl_simd();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
