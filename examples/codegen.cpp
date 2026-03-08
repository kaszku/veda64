// Example: JIT code generation — assemble and execute ARM64 code at runtime
// Build: cmake -DVEDA64_STRINGS=ON -DVEDA64_CODEGEN=ON .. && cmake --build .
// Run:   ./example_codegen
// Note:  Execution tests only run on ARM64 targets

#include "veda64.hpp"

#ifdef VEDA64_CODEGEN
#include <codegen/codegen.hpp>
#include <cstdio>
#include <cstring>

using namespace veda64;
using namespace veda64::codegen;

// Helper: read an instruction word from a CodeGenerator buffer
static uint32_t get_insn(const CodeGenerator& cg, size_t idx) {
    uint32_t val;
    std::memcpy(&val, cg.data() + idx * 4, 4);
    return val;
}

// --- Example 1: Encode and verify via decode ---
static void example_encode_verify() {
    printf("=== Encode + decode roundtrip ===\n");
    CodeGenerator cg(4096);

    cg.add(x0, x1, x2);
    cg.sub(w3, w4, uint32_t(100));
    cg.ldr(x5, ptr(sp, 16));
    cg.stp(x6, x7, pre(sp, -32));
    cg.fadd(d0, d1, d2);
    cg.nop();
    cg.ret();

    printf("  Generated %zu bytes (%zu instructions)\n", cg.size(), cg.size() / 4);
    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
        if (r) {
#ifdef VEDA64_STRINGS
            printf("  [%zu] 0x%08X -> %s\n", i, insn, r->to_string().c_str());
#else
            printf("  [%zu] 0x%08X -> mnemonic=%d\n", i, insn,
                   static_cast<int>(r->mnemonic));
#endif
        }
    }
}

// --- Example 2: Labels and branches ---
static void example_labels() {
    printf("\n=== Labels and branches ===\n");
    CodeGenerator cg(4096);
    Label loop, done;

    cg.mov(w1, uint32_t(0));        // counter = 0
    cg.bind(loop);
    cg.add(w1, w1, uint32_t(1));    // counter++
    cg.cmp(w1, w0);
    cg.b(Condition::LT, loop);      // if counter < n, loop
    cg.mov(w0, w1);
    cg.ret();

    printf("  Generated %zu instructions with backward branch\n", cg.size() / 4);
    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
#ifdef VEDA64_STRINGS
        if (r) printf("  [%zu] %s\n", i, r->to_string().c_str());
#endif
    }

#if defined(__aarch64__) || defined(_M_ARM64)
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    printf("  fn(10) = %d (expected 10)\n", fn(10));
    printf("  fn(50) = %d (expected 50)\n", fn(50));
#endif
}

// --- Example 3: Memory operand modes ---
static void example_memory() {
    printf("\n=== Memory operand modes ===\n");
    CodeGenerator cg(4096);

    cg.ldr(x0, ptr(x1));            // [X1]          offset, no displacement
    cg.ldr(x0, ptr(x1, 64));        // [X1, #64]     offset
    cg.str(x0, pre(x1, -16));       // [X1, #-16]!   pre-index
    cg.ldr(x0, post(x1, 8));        // [X1], #8      post-index
    cg.ldr(x0, ptr(x1, x2, 3));     // [X1, X2, LSL #3]  register offset
    cg.ldp(x0, x1, ptr(sp, 16));    // [SP, #16]     pair offset
    cg.stp(x0, x1, pre(sp, -32));   // [SP, #-32]!   pair pre-index

    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
#ifdef VEDA64_STRINGS
        if (r) printf("  [%zu] %s\n", i, r->to_string().c_str());
#endif
    }
}

// --- Example 4: Floating-point operations ---
static void example_fp() {
    printf("\n=== Scalar floating-point ===\n");
    CodeGenerator cg(4096);

    cg.fadd(d0, d0, d1);    // d0 = d0 + d1
    cg.fmul(d0, d0, d2);    // d0 *= d2
    cg.fsub(s3, s4, s5);    // s3 = s4 - s5
    cg.fdiv(s0, s0, s1);    // s0 /= s1
    cg.fmov(d3, d4);        // d3 = d4
    cg.fcmp(d0, d1);        // compare d0, d1
    cg.fcmp(s0);             // compare s0 with 0.0

    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
#ifdef VEDA64_STRINGS
        if (r) printf("  [%zu] %s\n", i, r->to_string().c_str());
#endif
    }

#if defined(__aarch64__) || defined(_M_ARM64)
    // Build and execute: double add_mul(double a, double b, double c) = (a+b)*c
    CodeGenerator cg2(4096);
    cg2.fadd(d0, d0, d1);
    cg2.fmul(d0, d0, d2);
    cg2.ret();
    cg2.ready();
    auto fn = cg2.getCode<double(*)(double, double, double)>();
    printf("  (3.0 + 4.0) * 2.0 = %.1f (expected 14.0)\n", fn(3.0, 4.0, 2.0));
#endif
}

// --- Example 5: MOV large immediates ---
static void example_mov() {
    printf("\n=== MOV convenience (large immediates) ===\n");
    CodeGenerator cg(4096);

    cg.mov(x0, uint64_t(0));                  // MOVZ X0, #0
    cg.mov(x0, uint64_t(42));                 // MOVZ X0, #42
    cg.mov(x0, uint64_t(0xFFFF));             // MOVZ X0, #0xFFFF
    cg.mov(x0, uint64_t(0xDEAD0000));         // MOVZ + shifted
    cg.mov(x0, uint64_t(0xDEADBEEFCAFE));     // MOVZ + 2x MOVK

    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
#ifdef VEDA64_STRINGS
        if (r) printf("  [%zu] %s\n", i, r->to_string().c_str());
#endif
    }

#if defined(__aarch64__) || defined(_M_ARM64)
    CodeGenerator cg2(4096);
    cg2.mov(x0, uint64_t(0xDEADBEEFCAFEULL));
    cg2.ret();
    cg2.ready();
    auto fn = cg2.getCode<uint64_t(*)()>();
    printf("  returned 0x%llX (expected 0xDEADBEEFCAFE)\n",
           (unsigned long long)fn());
#endif
}

// --- Example 6: Complete function — Fibonacci ---
#if defined(__aarch64__) || defined(_M_ARM64)
static void example_fibonacci() {
    printf("\n=== JIT Fibonacci function ===\n");

    // int fib(int n):
    //   a=0, b=1
    //   for i=0..n-1: t=a+b; a=b; b=t
    //   return a
    CodeGenerator cg(4096);
    Label loop, done;

    cg.mov(w1, uint32_t(0));       // a = 0
    cg.mov(w2, uint32_t(1));       // b = 1
    cg.mov(w3, uint32_t(0));       // i = 0
    cg.bind(loop);
    cg.cmp(w3, w0);
    cg.b(Condition::GE, done);
    cg.add(w4, w1, w2);            // t = a + b
    cg.mov(w1, w2);                // a = b
    cg.mov(w2, w4);                // b = t
    cg.add(w3, w3, uint32_t(1));
    cg.b(loop);
    cg.bind(done);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();

    auto fib = cg.getCode<int(*)(int)>();
    for (int n : {0, 1, 2, 5, 10, 20}) {
        printf("  fib(%d) = %d\n", n, fib(n));
    }
}
#endif

// --- Example 7: Shifted/extended register operations ---
static void example_shifted() {
    printf("\n=== Shifted register operations ===\n");
    CodeGenerator cg(4096);

    cg.add(x0, x1, x2, Shift(ShiftType::LSL, 2));   // X0 = X1 + (X2 << 2)
    cg.sub(x0, x1, x2, Shift(ShiftType::LSR, 4));   // X0 = X1 - (X2 >> 4)
    cg.and_(x0, x1, x2, Shift(ShiftType::ASR, 1));  // X0 = X1 & (X2 >>> 1)
    cg.orr(w0, w1, w2, Shift(ShiftType::ROR, 8));   // W0 = W1 | ROR(W2, 8)

    for (size_t i = 0; i < cg.size() / 4; i++) {
        uint32_t insn = get_insn(cg, i);
        auto r = decode(insn);
#ifdef VEDA64_STRINGS
        if (r) printf("  [%zu] %s\n", i, r->to_string().c_str());
#endif
    }

#if defined(__aarch64__) || defined(_M_ARM64)
    // Execute: x + y*4
    CodeGenerator cg2(4096);
    cg2.add(w0, w0, w1, Shift(ShiftType::LSL, 2));
    cg2.ret();
    cg2.ready();
    auto fn = cg2.getCode<int(*)(int, int)>();
    printf("  5 + 3*4 = %d (expected 17)\n", fn(5, 3));
#endif
}

int main() {
    example_encode_verify();
    example_labels();
    example_memory();
    example_fp();
    example_mov();
#if defined(__aarch64__) || defined(_M_ARM64)
    example_fibonacci();
#endif
    example_shifted();
    return 0;
}

#else // !VEDA64_CODEGEN

#include <cstdio>
int main() {
    printf("Codegen examples require -DVEDA64_CODEGEN=ON\n");
    return 0;
}

#endif
