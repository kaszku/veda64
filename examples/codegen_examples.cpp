// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

// Codegen API usage examples
// Build with: -DVEDA64_CODEGEN=ON
// These examples demonstrate various codegen features.

#if defined(VEDA64_CODEGEN) && (defined(__aarch64__) || defined(_M_ARM64))

#include <codegen/codegen.hpp>
#include <veda64.hpp>
#include <iostream>
#include <cstdint>
#include <cassert>
#include <cstring>

using namespace veda64::codegen;
using veda64::Condition;

// Example 1: Simple function — add two numbers
void example_add() {
    CodeGenerator cg(4096);
    cg.add(w0, w0, w1);  // w0 = w0 + w1
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int, int)>();
    std::cout << "add(3, 4) = " << fn(3, 4) << std::endl;
    assert(fn(3, 4) == 7);
}

// Example 2: Loop — sum 1 to N
void example_sum() {
    CodeGenerator cg(4096);
    Label loop;

    cg.mov(w1, uint32_t(0));     // sum = 0
    cg.mov(w2, uint32_t(0));     // i = 0
    cg.bind(loop);
    cg.add(w2, w2, uint32_t(1)); // i++
    cg.add(w1, w1, w2);          // sum += i
    cg.cmp(w2, w0);              // if i < n
    cg.b(Condition::LT, loop);   //   goto loop
    cg.mov(w0, w1);              // return sum
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    std::cout << "sum(10) = " << fn(10) << std::endl;
    assert(fn(10) == 55);  // 1+2+...+10 = 55
}

// Example 3: Conditional — absolute value
void example_abs() {
    CodeGenerator cg(4096);
    cg.cmp(w0, uint32_t(0));
    cg.cneg(w0, w0, Condition::LT);  // if (x < 0) x = -x
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    std::cout << "abs(-42) = " << fn(-42) << std::endl;
    assert(fn(-42) == 42);
    assert(fn(7) == 7);
}

// Example 4: Bitfield — extract byte from word
void example_extract_byte() {
    CodeGenerator cg(4096);
    // Extract byte N from input: (x >> (N*8)) & 0xFF
    cg.lsr(w0, w0, w1);      // shift right by w1
    cg.uxtb(w0, w0);          // zero-extend byte
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int, int)>();
    int val = 0x12345678;
    std::cout << "byte0(0x12345678) = 0x" << std::hex << fn(val, 0) << std::dec << std::endl;
    assert(fn(val, 0) == 0x78);
    assert(fn(val, 8) == 0x56);
    assert(fn(val, 16) == 0x34);
    assert(fn(val, 24) == 0x12);
}

// Example 5: 64-bit multiply with large immediate
void example_mul64() {
    CodeGenerator cg(4096);
    cg.mov(x1, uint64_t(1000000));  // synthesizes MOVZ + MOVK
    cg.mul(x0, x0, x1);
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int64_t(*)(int64_t)>();
    std::cout << "mul_million(42) = " << fn(42) << std::endl;
    assert(fn(42) == 42000000LL);
}

// Example 6: Stack frame with STP/LDP
void example_stack_frame() {
    CodeGenerator cg(4096);
    // Save x29, x30 (frame pointer and link register)
    cg.stp(x29, x30, pre(sp, -16));
    cg.mov(x29, sp);
    // ... function body: return x0 + 1
    cg.add(w0, w0, uint32_t(1));
    // Restore and return
    cg.ldp(x29, x30, post(sp, 16));
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    std::cout << "stack_frame(99) = " << fn(99) << std::endl;
    assert(fn(99) == 100);
}

// Example 7: Method chaining (fluent API)
void example_chaining() {
    CodeGenerator cg(4096);
    cg.add(w0, w0, w1)
      .mul(w0, w0, w2)
      .ret()
      .ready();

    auto fn = cg.get_code<int(*)(int, int, int)>();
    std::cout << "chain(2,3,4) = " << fn(2, 3, 4) << std::endl;
    assert(fn(2, 3, 4) == 20);  // (2+3)*4
}

// Example 8: SIMD — zero a vector, fill elements, add
void example_simd() {
    CodeGenerator cg(4096);
    // Clear v0 and v1, then add them (trivial SIMD demo)
    cg.movi(v0.b16(), 0);           // V0 = 0
    cg.dup(v1.s4(), w0);             // V1 = {w0, w0, w0, w0}
    cg.add(v0.s4(), v0.s4(), v1.s4());
    cg.umov(w0, v0.s4(), 0);         // extract lane 0
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    std::cout << "simd_add(42) = " << fn(42) << std::endl;
    assert(fn(42) == 42);
}

// Example 9: Logical immediate — mask and shift
void example_mask() {
    CodeGenerator cg(4096);
    cg.and_(w0, w0, uint64_t(0xFF));  // mask to low byte
    cg.lsl(w0, w0, uint8_t(8));       // shift left by 8
    cg.ret();
    cg.ready();

    auto fn = cg.get_code<int(*)(int)>();
    std::cout << "mask(0x1234) = 0x" << std::hex << fn(0x1234) << std::dec << std::endl;
    assert(fn(0x1234) == 0x3400);  // (0x34) << 8
}

// Example 10: Compare-and-swap pattern
void example_cas() {
    // Just test encoding — CAS requires aligned atomic memory
    CodeGenerator cg(4096);
    cg.cas(x0, x1, x2);    // CAS X0, X1, [X2]
    cg.casa(x3, x4, x5);   // CASA (acquire)
    cg.casal(x6, x7, x8);  // CASAL (acquire+release)
    cg.ret();

    // Verify encoding via decode
    for (size_t i = 0; i < cg.size(); i += 4) {
        uint32_t insn;
        std::memcpy(&insn, cg.data() + i, 4);
        auto d = veda64::decode(insn);
        assert(d);
    }
    std::cout << "cas: encoding OK" << std::endl;
}

int main() {
    std::cout << "=== Codegen API Examples ===" << std::endl;
    example_add();
    example_sum();
    example_abs();
    example_extract_byte();
    example_mul64();
    example_stack_frame();
    example_chaining();
    example_simd();
    example_mask();
    example_cas();
    std::cout << "All examples passed!" << std::endl;
    return 0;
}

#else
#include <cstdio>
int main() { printf("Examples require VEDA64_CODEGEN and ARM64\n"); return 0; }
#endif
