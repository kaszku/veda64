// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#if defined(VEDA64_CODEGEN) && (defined(__aarch64__) || defined(_M_ARM64))

#include <codegen/codegen.hpp>
#include <iostream>
#include <cassert>
#include <cstdint>
#include <cstring>

using namespace veda64::codegen;

static int failures = 0;
static int passed = 0;

template<typename T>
void check(const char* name, T got, T expected) {
    if (got == expected) {
        std::cout << "  OK: " << name << std::endl;
        passed++;
    } else {
        std::cerr << "  FAIL: " << name << " expected " << expected << " got " << got << std::endl;
        failures++;
    }
}

void test_clz_functional() {
    CodeGenerator cg(4096);
    cg.clz(w0, w0);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t)>();
    check("clz(0)", fn(0), 32u);
    check("clz(1)", fn(1), 31u);
    check("clz(0x80000000)", fn(0x80000000u), 0u);
    check("clz(0xFF)", fn(0xFF), 24u);
}

void test_rbit_functional() {
    CodeGenerator cg(4096);
    cg.rbit(w0, w0);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t)>();
    check("rbit(1)", fn(1), 0x80000000u);
    check("rbit(0x80000000)", fn(0x80000000u), 1u);
}

void test_rev_functional() {
    CodeGenerator cg(4096);
    cg.rev(w0, w0);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t)>();
    check("rev(0x12345678)", fn(0x12345678u), 0x78563412u);
    check("rev(0xFF000000)", fn(0xFF000000u), 0x000000FFu);
}

void test_bfi_functional() {
    // bfi w0, w1, #4, #8 — insert 8 bits from w1 into w0 starting at bit 4
    CodeGenerator cg(4096);
    cg.bfi(w0, w1, 4, 8);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t, uint32_t)>();
    check("bfi(0, 0xFF, 4, 8)", fn(0, 0xFF), 0xFF0u);
    check("bfi(0xFFFFFFFF, 0, 4, 8)", fn(0xFFFFFFFF, 0), 0xFFFFF00Fu);
}

void test_ubfx_functional() {
    // ubfx w0, w0, #4, #8 — extract 8 bits starting at bit 4
    CodeGenerator cg(4096);
    cg.ubfx(w0, w0, 4, 8);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t)>();
    check("ubfx(0xABCD1234, 4, 8)", fn(0xABCD1234u), 0x23u);
    check("ubfx(0xFF0, 4, 8)", fn(0xFF0u), 0xFFu);
}

void test_sbfx_functional() {
    // sbfx w0, w0, #4, #8 — sign-extend 8 bits starting at bit 4
    CodeGenerator cg(4096);
    cg.sbfx(w0, w0, 4, 8);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<int32_t(*)(uint32_t)>();
    check("sbfx(0x800, 4, 8)", fn(0x800u), static_cast<int32_t>(-128));  // bit 11 set = sign bit
    check("sbfx(0x7F0, 4, 8)", fn(0x7F0u), static_cast<int32_t>(127));
}

void test_adc_functional() {
    // Set carry via adds, then adc
    CodeGenerator cg(4096);
    // w0 = a, w1 = b; adds w2, w0, w0 sets carry if overflow
    // For simplicity: compute a + b + 0 (carry clear)
    cg.adds(w2, w0, w0);  // just to clear/set carry flag
    cg.mov(w2, uint32_t(0));
    cg.adc(w0, w1, w2);  // w0 = w1 + w2 + carry
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t, uint32_t)>();
    // When a=1, adds 1+1=2, no carry for 32-bit, so adc = b + 0 + 0 = b
    check("adc(1, 5)", fn(1, 5), 5u);
    // When a=0xFFFFFFFF, adds sets carry, so adc = b + 0 + 1 = b+1
    check("adc(0xFFFFFFFF, 5)", fn(0xFFFFFFFF, 5), 6u);
}

void test_extr_functional() {
    // extr w0, w0, w1, #16 — extract bits [47:16] from w0:w1
    CodeGenerator cg(4096);
    cg.extr(w0, w0, w1, 16);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t, uint32_t)>();
    check("extr(0x0000AAAA, 0xBBBB0000, 16)", fn(0x0000AAAAu, 0xBBBB0000u), 0xAAAABBBBu);
}

void test_msub_functional() {
    // msub w0, w1, w2, w0 — w0 = w0 - w1*w2
    CodeGenerator cg(4096);
    cg.msub(w0, w1, w2, w0);
    cg.ret();
    cg.ready();
    auto fn = cg.get_code<uint32_t(*)(uint32_t, uint32_t, uint32_t)>();
    check("msub(100, 3, 7)", fn(100, 3, 7), 79u);  // 100 - 3*7 = 79
}

int main() {
    std::cout << "Running functional validation tests..." << std::endl;
    test_clz_functional();
    test_rbit_functional();
    test_rev_functional();
    test_bfi_functional();
    test_ubfx_functional();
    test_sbfx_functional();
    test_adc_functional();
    test_extr_functional();
    test_msub_functional();
    std::cout << passed << " / " << (passed + failures) << " functional tests passed" << std::endl;
    return failures ? 1 : 0;
}

#else
#include <cstdio>
int main() { printf("Functional tests require VEDA64_CODEGEN and ARM64\n"); return 0; }
#endif
