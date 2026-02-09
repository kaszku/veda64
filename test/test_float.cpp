// Auto-generated - do not edit
// Test suite for float instruction class
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_bfcvt_bs_floatdp1() {
    // Test BFCVT: Single-precision convert to BFloat16 (scalar)
    uint32_t test_insn = 0x1E634000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::BFCVT);

    std::cout << "  bfcvt_bs_floatdp1: " << result->to_string() << std::endl;
}

void test_fabs_h_floatdp1() {
    // Test FABS: Floating-point absolute value (scalar)
    uint32_t test_insn = 0x1EE0C000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FABS);

    std::cout << "  fabs_h_floatdp1: " << result->to_string() << std::endl;
}

void test_fadd_h_floatdp2() {
    // Test FADD: Floating-point add (scalar)
    uint32_t test_insn = 0x1EE02800u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FADD);

    std::cout << "  fadd_h_floatdp2: " << result->to_string() << std::endl;
}

void test_fccmp_h_floatccmp() {
    // Test FCCMP: Floating-point conditional quiet compare (scalar)
    uint32_t test_insn = 0x1EE00400u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCCMP);

    std::cout << "  fccmp_h_floatccmp: " << result->to_string() << std::endl;
}

void test_fccmpe_h_floatccmp() {
    // Test FCCMPE: Floating-point conditional signaling compare (scalar)
    uint32_t test_insn = 0x1EE00410u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCCMPE);

    std::cout << "  fccmpe_h_floatccmp: " << result->to_string() << std::endl;
}

void test_fcmp_h_floatcmp() {
    // Test FCMP: Floating-point quiet compare (scalar)
    uint32_t test_insn = 0x1EE02000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCMP);

    std::cout << "  fcmp_h_floatcmp: " << result->to_string() << std::endl;
}

void test_fcmpe_h_floatcmp() {
    // Test FCMPE: Floating-point signaling compare (scalar)
    uint32_t test_insn = 0x1EE02010u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCMPE);

    std::cout << "  fcmpe_h_floatcmp: " << result->to_string() << std::endl;
}

void test_fcsel_h_floatsel() {
    // Test FCSEL: Floating-point conditional select (scalar)
    uint32_t test_insn = 0x1EE00C00u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCSEL);

    std::cout << "  fcsel_h_floatsel: " << result->to_string() << std::endl;
}

void test_fcvt_sh_floatdp1() {
    // Test FCVT: Floating-point convert precision (scalar)
    uint32_t test_insn = 0x1EE24000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCVT);

    std::cout << "  fcvt_sh_floatdp1: " << result->to_string() << std::endl;
}

void test_fcvtas_32h_float2int() {
    // Test FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
    uint32_t test_insn = 0x1EE40000u;

    auto result = decode(test_insn);
    assert(result.has_value());
    (void)result;
    assert(result->mnemonic == Mnemonic::FCVTAS);

    std::cout << "  fcvtas_32h_float2int: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running float tests..." << std::endl;

    test_bfcvt_bs_floatdp1();
    test_fabs_h_floatdp1();
    test_fadd_h_floatdp2();
    test_fccmp_h_floatccmp();
    test_fccmpe_h_floatccmp();
    test_fcmp_h_floatcmp();
    test_fcmpe_h_floatcmp();
    test_fcsel_h_floatsel();
    test_fcvt_sh_floatdp1();
    test_fcvtas_32h_float2int();

    std::cout << "All 10 tests passed!" << std::endl;
    return 0;
}
