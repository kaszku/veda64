// Auto-generated - do not edit
// Test suite for sve2 instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_adclb_z_zzz_() {
    // Test ADCLB: Add with carry long (bottom)
    uint32_t test_insn = 0x4500D000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADCLB);

    std::cout << "  adclb_z_zzz_: " << result->to_string() << std::endl;
}

void test_adclt_z_zzz_() {
    // Test ADCLT: Add with carry long (top)
    uint32_t test_insn = 0x4500D400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADCLT);

    std::cout << "  adclt_z_zzz_: " << result->to_string() << std::endl;
}

void test_addhnb_z_zz_() {
    // Test ADDHNB: Add narrow high part (bottom)
    uint32_t test_insn = 0x45206000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDHNB);

    std::cout << "  addhnb_z_zz_: " << result->to_string() << std::endl;
}

void test_addhnt_z_zz_() {
    // Test ADDHNT: Add narrow high part (top)
    uint32_t test_insn = 0x45206400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDHNT);

    std::cout << "  addhnt_z_zz_: " << result->to_string() << std::endl;
}

void test_addp_z_p_zz_() {
    // Test ADDP: Add pairwise
    uint32_t test_insn = 0x4411A000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDP);

    std::cout << "  addp_z_p_zz_: " << result->to_string() << std::endl;
}

void test_addpt_z_p_zz_() {
    // Test ADDPT: Add checked pointer vectors (predicated)
    uint32_t test_insn = 0x04C40000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDPT);

    std::cout << "  addpt_z_p_zz_: " << result->to_string() << std::endl;
}

void test_addpt_z_zz_() {
    // Test ADDPT: Add checked pointer vectors (unpredicated)
    uint32_t test_insn = 0x04E00800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDPT);

    std::cout << "  addpt_z_zz_: " << result->to_string() << std::endl;
}

void test_addqp_z_zz_() {
    // Test ADDQP: Add pairwise within quadword vector segments (unpredicated)
    uint32_t test_insn = 0x04207800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDQP);

    std::cout << "  addqp_z_zz_: " << result->to_string() << std::endl;
}

void test_addqv_z_p_z_() {
    // Test ADDQV: Add reduction of quadword vector segments
    uint32_t test_insn = 0x04052000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDQV);

    std::cout << "  addqv_z_p_z_: " << result->to_string() << std::endl;
}

void test_addsubp_z_zz_() {
    // Test ADDSUBP: Add subtract pairwise
    uint32_t test_insn = 0x04207C00u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::ADDSUBP);

    std::cout << "  addsubp_z_zz_: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running sve2 tests..." << std::endl;

    test_adclb_z_zzz_();
    test_adclt_z_zzz_();
    test_addhnb_z_zz_();
    test_addhnt_z_zz_();
    test_addp_z_p_zz_();
    test_addpt_z_p_zz_();
    test_addpt_z_zz_();
    test_addqp_z_zz_();
    test_addqv_z_p_z_();
    test_addsubp_z_zz_();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
