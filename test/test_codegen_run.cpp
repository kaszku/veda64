// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#if defined(VEDA64_CODEGEN) && (defined(__aarch64__) || defined(_M_ARM64))

#include <codegen/codegen.hpp>
#include <veda64.hpp>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdint>
#include <cmath>

using namespace veda64;
using namespace veda64::codegen;

static int failures = 0;

#define CHECK(expr, name) do { \
    if (!(expr)) { \
        std::cerr << "  FAIL: " << (name) << " (" #expr ")" << std::endl; \
        failures++; \
    } \
} while(0)

static void test_identity() {
    CodeGenerator cg(4096);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 0, "identity(0)");
    CHECK(fn(123) == 123, "identity(123)");
    CHECK(fn(-1) == -1, "identity(-1)");
    std::cout << "  identity: OK" << std::endl;
}

static void test_add_imm() {
    CodeGenerator cg(4096);
    cg.add(w0, w0, uint32_t(7));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 7, "add_imm(0)");
    CHECK(fn(35) == 42, "add_imm(35)");
    CHECK(fn(-10) == -3, "add_imm(-10)");
    std::cout << "  add_imm: OK" << std::endl;
}

// int sub_reg(int a, int b) { return a - b; }
static void test_sub_reg() {
    CodeGenerator cg(4096);
    cg.sub(w0, w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(10, 3) == 7, "sub_reg(10,3)");
    CHECK(fn(0, 0) == 0, "sub_reg(0,0)");
    CHECK(fn(1, 5) == -4, "sub_reg(1,5)");
    std::cout << "  sub_reg: OK" << std::endl;
}

// int mul(int a, int b) { return a * b; }
static void test_multiply() {
    CodeGenerator cg(4096);
    cg.mul(w0, w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(6, 7) == 42, "mul(6,7)");
    CHECK(fn(0, 999) == 0, "mul(0,999)");
    CHECK(fn(-3, 4) == -12, "mul(-3,4)");
    std::cout << "  multiply: OK" << std::endl;
}

// int64_t mul64(int64_t a, int64_t b) { return a * b; }
static void test_multiply64() {
    CodeGenerator cg(4096);
    cg.mul(x0, x0, x1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int64_t(*)(int64_t, int64_t)>();
    CHECK(fn(100000LL, 100000LL) == 10000000000LL, "mul64 large");
    CHECK(fn(-1LL, 42LL) == -42LL, "mul64 neg");
    std::cout << "  multiply64: OK" << std::endl;
}

// int count_up(int n) { int i=0; while(i<n) i++; return i; }
static void test_count_loop() {
    CodeGenerator cg(4096);
    Label loop;
    cg.mov(w1, uint32_t(0));
    cg.bind(loop);
    cg.add(w1, w1, uint32_t(1));
    cg.cmp(w1, w0);
    cg.b(Condition::LT, loop);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(1) == 1, "count(1)");
    CHECK(fn(10) == 10, "count(10)");
    CHECK(fn(100) == 100, "count(100)");
    std::cout << "  count_loop: OK" << std::endl;
}

// int sum(int n) { int s=0; for(int i=1; i<=n; i++) s+=i; return s; }
static void test_sum() {
    CodeGenerator cg(4096);
    Label loop, done;
    cg.mov(w1, uint32_t(0));       // s = 0
    cg.mov(w2, uint32_t(1));       // i = 1
    cg.bind(loop);
    cg.cmp(w2, w0);
    cg.b(Condition::GT, done);      // if i > n, break
    cg.add(w1, w1, w2);             // s += i
    cg.add(w2, w2, uint32_t(1));    // i++
    cg.b(loop);
    cg.bind(done);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 0, "sum(0)");
    CHECK(fn(1) == 1, "sum(1)");
    CHECK(fn(10) == 55, "sum(10)");
    CHECK(fn(100) == 5050, "sum(100)");
    std::cout << "  sum: OK" << std::endl;
}

// int fact(int n) { int r=1; while(n>1) { r*=n; n--; } return r; }
static void test_factorial() {
    CodeGenerator cg(4096);
    Label loop, done;
    cg.mov(w1, uint32_t(1));       // r = 1
    cg.bind(loop);
    cg.cmp(w0, uint32_t(1));
    cg.b(Condition::LE, done);      // if n <= 1, done
    cg.mul(w1, w1, w0);             // r *= n
    cg.sub(w0, w0, uint32_t(1));    // n--
    cg.b(loop);
    cg.bind(done);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 1, "fact(0)");
    CHECK(fn(1) == 1, "fact(1)");
    CHECK(fn(5) == 120, "fact(5)");
    CHECK(fn(10) == 3628800, "fact(10)");
    std::cout << "  factorial: OK" << std::endl;
}

// int fib(int n) { int a=0,b=1; for(int i=0;i<n;i++) { int t=a+b; a=b; b=t; } return a; }
static void test_fibonacci() {
    CodeGenerator cg(4096);
    Label loop, done;
    cg.mov(w1, uint32_t(0));       // a = 0
    cg.mov(w2, uint32_t(1));       // b = 1
    cg.mov(w3, uint32_t(0));       // i = 0
    cg.bind(loop);
    cg.cmp(w3, w0);
    cg.b(Condition::GE, done);      // if i >= n, done
    cg.add(w4, w1, w2);             // t = a + b
    cg.mov(w1, w2);                 // a = b
    cg.mov(w2, w4);                 // b = t
    cg.add(w3, w3, uint32_t(1));    // i++
    cg.b(loop);
    cg.bind(done);
    cg.mov(w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 0, "fib(0)");
    CHECK(fn(1) == 1, "fib(1)");
    CHECK(fn(2) == 1, "fib(2)");
    CHECK(fn(10) == 55, "fib(10)");
    CHECK(fn(20) == 6765, "fib(20)");
    std::cout << "  fibonacci: OK" << std::endl;
}

// int max(int a, int b) { return a > b ? a : b; }
static void test_max_csel() {
    CodeGenerator cg(4096);
    cg.cmp(w0, w1);
    cg.csel(w0, w0, w1, Condition::GT);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(5, 3) == 5, "max(5,3)");
    CHECK(fn(3, 5) == 5, "max(3,5)");
    CHECK(fn(7, 7) == 7, "max(7,7)");
    CHECK(fn(-1, -5) == -1, "max(-1,-5)");
    std::cout << "  max_csel: OK" << std::endl;
}

// int abs(int a) { return a >= 0 ? a : -a; }
static void test_abs() {
    CodeGenerator cg(4096);
    cg.cmp(w0, uint32_t(0));
    cg.neg(w1, w0);
    cg.csel(w0, w0, w1, Condition::GE);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(42) == 42, "abs(42)");
    CHECK(fn(-42) == 42, "abs(-42)");
    CHECK(fn(0) == 0, "abs(0)");
    std::cout << "  abs: OK" << std::endl;
}

// int bitops(int a, int b) { return (a & b) | (~a & 0xFF); }
static void test_logical() {
    CodeGenerator cg(4096);
    cg.and_(w2, w0, w1);           // w2 = a & b
    cg.mvn(w3, w0);                // w3 = ~a
    cg.and_(w3, w3, w1);           // w3 = ~a & b  (approximate)
    cg.orr(w0, w2, w3);            // w0 = (a & b) | (~a & b) = b
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(0xFF, 0x0F) == 0x0F, "logical(0xFF,0x0F)");
    CHECK(fn(0x00, 0xFF) == 0xFF, "logical(0x00,0xFF)");
    CHECK(fn(0xAA, 0x55) == 0x55, "logical identity");
    std::cout << "  logical: OK" << std::endl;
}

// int shl(int a, int b) { return a << b; }
static void test_shifts() {
    CodeGenerator cg(4096);
    cg.lsl(w0, w0, w1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(1, 0) == 1, "shl(1,0)");
    CHECK(fn(1, 4) == 16, "shl(1,4)");
    CHECK(fn(3, 8) == 768, "shl(3,8)");
    std::cout << "  shifts: OK" << std::endl;
}

// int stack_spill(int a, int b) { store a & b to stack, reload, return sum }
static void test_stack_spill() {
    CodeGenerator cg(4096);
    // Allocate 16 bytes on stack
    cg.sub(sp, sp, uint32_t(16));
    cg.str(w0, ptr(sp, 0));         // [sp] = a
    cg.str(w1, ptr(sp, 4));         // [sp+4] = b
    cg.ldr(w2, ptr(sp, 0));         // w2 = a
    cg.ldr(w3, ptr(sp, 4));         // w3 = b
    cg.add(w0, w2, w3);             // return a + b
    cg.add(sp, sp, uint32_t(16));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(10, 20) == 30, "stack(10,20)");
    CHECK(fn(-5, 5) == 0, "stack(-5,5)");
    std::cout << "  stack_spill: OK" << std::endl;
}

// Spill/reload a pair of 64-bit registers
static void test_pair_ldst() {
    CodeGenerator cg(4096);
    cg.stp(x0, x1, pre(sp, -16));  // push x0, x1
    cg.mov(x0, uint64_t(0));
    cg.mov(x1, uint64_t(0));
    cg.ldp(x0, x1, post(sp, 16));  // pop x0, x1
    cg.add(x0, x0, x1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int64_t(*)(int64_t, int64_t)>();
    CHECK(fn(100, 200) == 300, "pair(100,200)");
    CHECK(fn(-1, 1) == 0, "pair(-1,1)");
    std::cout << "  pair_ldst: OK" << std::endl;
}

// int64_t mov_large() { return 0xDEADBEEFCAFE; }
static void test_mov_large() {
    CodeGenerator cg(4096);
    cg.mov(x0, uint64_t(0xDEADBEEFCAFEULL));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<uint64_t(*)()>();
    CHECK(fn() == 0xDEADBEEFCAFEULL, "mov_large");
    std::cout << "  mov_large: OK" << std::endl;
}

// int clamp(int x, int lo, int hi) { if(x<lo) return lo; if(x>hi) return hi; return x; }
static void test_nested_branches() {
    CodeGenerator cg(4096);
    Label clamp_lo, clamp_hi, done;
    cg.cmp(w0, w1);
    cg.b(Condition::LT, clamp_lo);
    cg.cmp(w0, w2);
    cg.b(Condition::GT, clamp_hi);
    cg.b(done);
    cg.bind(clamp_lo);
    cg.mov(w0, w1);
    cg.b(done);
    cg.bind(clamp_hi);
    cg.mov(w0, w2);
    cg.bind(done);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int, int)>();
    CHECK(fn(5, 0, 10) == 5, "clamp mid");
    CHECK(fn(-5, 0, 10) == 0, "clamp lo");
    CHECK(fn(15, 0, 10) == 10, "clamp hi");
    CHECK(fn(0, 0, 10) == 0, "clamp edge lo");
    CHECK(fn(10, 0, 10) == 10, "clamp edge hi");
    std::cout << "  nested_branches: OK" << std::endl;
}

// int is_zero(int x) { return x == 0 ? 1 : 0; }
static void test_cbz() {
    CodeGenerator cg(4096);
    Label not_zero;
    cg.cbnz(w0, not_zero);
    cg.mov(w0, uint32_t(1));
    cg.ret();
    cg.bind(not_zero);
    cg.mov(w0, uint32_t(0));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 1, "cbz(0)");
    CHECK(fn(1) == 0, "cbz(1)");
    CHECK(fn(-99) == 0, "cbz(-99)");
    std::cout << "  cbz: OK" << std::endl;
}

// int is_odd(int x) { return x & 1; }
static void test_tbz() {
    CodeGenerator cg(4096);
    Label odd;
    cg.tbnz(w0, 0, odd);           // if bit 0 set, jump
    cg.mov(w0, uint32_t(0));        // even
    cg.ret();
    cg.bind(odd);
    cg.mov(w0, uint32_t(1));        // odd
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(0) == 0, "tbz even 0");
    CHECK(fn(1) == 1, "tbz odd 1");
    CHECK(fn(42) == 0, "tbz even 42");
    CHECK(fn(43) == 1, "tbz odd 43");
    std::cout << "  tbz: OK" << std::endl;
}

// double fp_arith(double a, double b) { return (a + b) * (a - b); }
static void test_fp_double() {
    CodeGenerator cg(4096);
    cg.fadd(d2, d0, d1);            // d2 = a + b
    cg.fsub(d3, d0, d1);            // d3 = a - b
    cg.fmul(d0, d2, d3);            // d0 = (a+b)*(a-b)
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<double(*)(double, double)>();
    // (5+3)*(5-3) = 8*2 = 16
    CHECK(fn(5.0, 3.0) == 16.0, "fp_double(5,3)");
    // (10+0)*(10-0) = 100
    CHECK(fn(10.0, 0.0) == 100.0, "fp_double(10,0)");
    // (1+1)*(1-1) = 0
    CHECK(fn(1.0, 1.0) == 0.0, "fp_double(1,1)");
    std::cout << "  fp_double: OK" << std::endl;
}

// float fp_div(float a, float b) { return a / b; }
static void test_fp_single() {
    CodeGenerator cg(4096);
    cg.fdiv(s0, s0, s1);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<float(*)(float, float)>();
    CHECK(fn(10.0f, 2.0f) == 5.0f, "fp_single(10/2)");
    CHECK(fn(7.0f, 2.0f) == 3.5f, "fp_single(7/2)");
    std::cout << "  fp_single: OK" << std::endl;
}

// int madd(int a, int b, int c) { return a + b * c; }
static void test_madd() {
    CodeGenerator cg(4096);
    cg.madd(w0, w1, w2, w0);       // w0 = w0 + w1 * w2
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int, int)>();
    CHECK(fn(10, 3, 4) == 22, "madd(10,3,4)");
    CHECK(fn(0, 5, 6) == 30, "madd(0,5,6)");
    CHECK(fn(100, 0, 99) == 100, "madd(100,0,99)");
    std::cout << "  madd: OK" << std::endl;
}

// int is_positive(int x) { return x > 0 ? 1 : 0; }
static void test_cset() {
    CodeGenerator cg(4096);
    cg.cmp(w0, uint32_t(0));
    cg.cset(w0, Condition::GT);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int)>();
    CHECK(fn(5) == 1, "cset(5)");
    CHECK(fn(0) == 0, "cset(0)");
    CHECK(fn(-1) == 0, "cset(-1)");
    std::cout << "  cset: OK" << std::endl;
}

// int shl_add(int a, int b) { return a + (b << 2); }
static void test_shifted_reg() {
    CodeGenerator cg(4096);
    cg.add(w0, w0, w1, Shift(ShiftType::LSL, 2));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(1, 3) == 13, "shl_add(1,3)");     // 1 + 3*4 = 13
    CHECK(fn(0, 1) == 4, "shl_add(0,1)");      // 0 + 1*4 = 4
    CHECK(fn(10, 0) == 10, "shl_add(10,0)");   // 10 + 0 = 10
    std::cout << "  shifted_reg: OK" << std::endl;
}

// int gcd(int a, int b) { while(b) { int t=b; b=a%b; a=t; } return a; }
// ARM64 has no mod instruction, so: a%b = a - (a/b)*b
static void test_gcd() {
    CodeGenerator cg(4096);
    Label loop, done;
    cg.bind(loop);
    cg.cbz(w1, done);               // if b == 0, done
    cg.udiv(w2, w0, w1);            // w2 = a / b
    cg.mul(w2, w2, w1);             // w2 = (a/b) * b
    cg.sub(w2, w0, w2);             // w2 = a - (a/b)*b = a % b
    cg.mov(w0, w1);                 // a = b
    cg.mov(w1, w2);                 // b = a % b
    cg.b(loop);
    cg.bind(done);
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)(int, int)>();
    CHECK(fn(12, 8) == 4, "gcd(12,8)");
    CHECK(fn(100, 75) == 25, "gcd(100,75)");
    CHECK(fn(7, 13) == 1, "gcd(7,13)");
    CHECK(fn(0, 5) == 5, "gcd(0,5)");
    CHECK(fn(42, 42) == 42, "gcd(42,42)");
    std::cout << "  gcd: OK" << std::endl;
}

static void test_multiple_generators() {
    CodeGenerator cg1(4096);
    cg1.add(w0, w0, uint32_t(1));
    cg1.ret();
    cg1.ready();

    CodeGenerator cg2(4096);
    cg2.add(w0, w0, uint32_t(100));
    cg2.ret();
    cg2.ready();

    auto fn1 = cg1.getCode<int(*)(int)>();
    auto fn2 = cg2.getCode<int(*)(int)>();
    CHECK(fn1(0) == 1, "multi gen1");
    CHECK(fn2(0) == 100, "multi gen2");
    CHECK(fn1(fn2(0)) == 101, "multi chain");
    std::cout << "  multiple_generators: OK" << std::endl;
}

static void test_nop_sled() {
    CodeGenerator cg(4096);
    for (int i = 0; i < 100; i++) cg.nop();
    cg.mov(w0, uint32_t(99));
    cg.ret();
    cg.ready();
    auto fn = cg.getCode<int(*)()>();
    CHECK(fn() == 99, "nop_sled");
    CHECK(cg.size() == (100 + 2) * 4, "nop_sled size");
    std::cout << "  nop_sled: OK" << std::endl;
}

int main() {
    std::cout << "Running codegen execution tests..." << std::endl;
    test_identity();
    test_add_imm();
    test_sub_reg();
    test_multiply();
    test_multiply64();
    test_count_loop();
    test_sum();
    test_factorial();
    test_fibonacci();
    test_max_csel();
    test_abs();
    test_logical();
    test_shifts();
    test_stack_spill();
    test_pair_ldst();
    test_mov_large();
    test_nested_branches();
    test_cbz();
    test_tbz();
    test_fp_double();
    test_fp_single();
    test_madd();
    test_cset();
    test_shifted_reg();
    test_gcd();
    test_multiple_generators();
    test_nop_sled();
    if (failures) {
        std::cerr << failures << " test(s) FAILED" << std::endl;
        return 1;
    }
    std::cout << "All codegen execution tests passed! (27 tests)" << std::endl;
    return 0;
}

#else // !VEDA64_CODEGEN || !ARM64

#include <cstdio>
int main() {
    printf("Codegen execution tests skipped (VEDA64_CODEGEN not set or not ARM64)\n");
    return 0;
}

#endif
