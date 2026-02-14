// Reference test - validates decode output against known disassembly
// Auto-generated - do not edit
// Tests both mnemonic and operands (case-insensitive)
#include "veda64.hpp"
#include <iostream>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <string>

using namespace veda64;

// Convert string to lowercase
std::string to_lower(const std::string& s) {
    std::string result = s;
    for (char& c : result) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return result;
}

// Normalize disassembly for comparison:
// - Convert to lowercase
// - Normalize register aliases (x29->fp, x30->lr)
// - Normalize hex format
std::string normalize(const std::string& s) {
    std::string result = to_lower(s);

    // Replace register aliases
    size_t pos;
    while ((pos = result.find("x29")) != std::string::npos) {
        result.replace(pos, 3, "fp");
    }
    while ((pos = result.find("x30")) != std::string::npos) {
        result.replace(pos, 3, "lr");
    }

    return result;
}

// Check if disassembly output matches expected (case-insensitive, with normalization)
bool check_disasm(uint32_t insn, const char* expected) {
    auto result = decode(insn);
    if (!result) {
        std::cerr << "FAIL: Failed to decode 0x" << std::hex << insn << std::dec << std::endl;
        std::cerr << "      Expected: " << expected << std::endl;
        return false;
    }

    std::string got = result->to_string();
    std::string norm_got = normalize(got);
    std::string norm_expected = normalize(expected);

    if (norm_got != norm_expected) {
        std::cerr << "FAIL: Mismatch for 0x" << std::hex << insn << std::dec << std::endl;
        std::cerr << "      Expected: " << expected << std::endl;
        std::cerr << "      Got:      " << got << std::endl;
        return false;
    }

    std::cout << "  OK: " << got << std::endl;
    return true;
}

int main() {
    std::cout << "Running reference tests..." << std::endl;
    int passed = 0;
    int failed = 0;

    if (check_disasm(0xd503237f, "pacibsp")) passed++; else failed++;
    if (check_disasm(0xa9be7bfd, "stp fp, lr, [sp, #-0x20]!")) passed++; else failed++;
    if (check_disasm(0x910003fd, "mov fp, sp")) passed++; else failed++;
    if (check_disasm(0x390043bf, "strb wzr, [fp, #0x10]")) passed++; else failed++;
    if (check_disasm(0xd2800004, "mov x4, #0x0")) passed++; else failed++;
    if (check_disasm(0x52800023, "mov w3, #0x1")) passed++; else failed++;
    if (check_disasm(0x910043a2, "add x2, fp, #0x10")) passed++; else failed++;
    if (check_disasm(0x52800221, "mov w1, #0x11")) passed++; else failed++;
    if (check_disasm(0x92800020, "mvn x0, #0x1")) passed++; else failed++;
    if (check_disasm(0x97fa94a3, "bl .-0x15ad74")) passed++; else failed++;
    if (check_disasm(0x37f800a0, "tbnz x0, #0x1f, .+0x14")) passed++; else failed++;
    if (check_disasm(0x394043a8, "ldrb w8, [fp, #0x10]")) passed++; else failed++;
    if (check_disasm(0x35000068, "cbnz w8, .+0xc")) passed++; else failed++;
    if (check_disasm(0xd43e0000, "brk #0xf000")) passed++; else failed++;
    if (check_disasm(0x14000001, "b .+0x4")) passed++; else failed++;
    if (check_disasm(0xa8c27bfd, "ldp fp, lr, [sp], #0x20")) passed++; else failed++;
    if (check_disasm(0xd50323ff, "autibsp")) passed++; else failed++;
    if (check_disasm(0xd65f03c0, "ret")) passed++; else failed++;
    if (check_disasm(0x4f00e407, "movi v7.16b, #0")) passed++; else failed++;
    if (check_disasm(0x3d800fe7, "str q7, [sp, #0x30]")) passed++; else failed++;
    if (check_disasm(0xad021fe7, "stp q7, q7, [sp, #0x40]")) passed++; else failed++;
    if (check_disasm(0x90000008, "adrp x8, .+0x0")) passed++; else failed++;
    if (check_disasm(0x10000020, "adr x0, .+0x4")) passed++; else failed++;
    if (check_disasm(0x54000040, "b.eq .+0x8")) passed++; else failed++;
    if (check_disasm(0x54000061, "b.ne .+0xc")) passed++; else failed++;
    if (check_disasm(0x7a400000, "ccmp w0, w0, #0, eq")) passed++; else failed++;
    if (check_disasm(0x1a800000, "csel w0, w0, w0, eq")) passed++; else failed++;
    if (check_disasm(0xd50335bf, "dmb nshld")) passed++; else failed++;
    if (check_disasm(0xd50333bf, "dmb osh")) passed++; else failed++;
    if (check_disasm(0xd5033fbf, "dmb sy")) passed++; else failed++;
    if (check_disasm(0xa8401c26, "ldnp x6, x7, [x1]")) passed++; else failed++;
    if (check_disasm(0xa87f2488, "ldnp x8, x9, [x4, #-0x10]")) passed++; else failed++;
    if (check_disasm(0x28402026, "ldnp w6, w8, [x1]")) passed++; else failed++;
    if (check_disasm(0x385ff08a, "ldurb w10, [x4, #-1]")) passed++; else failed++;
    if (check_disasm(0xb85fc088, "ldur w8, [x4, #-4]")) passed++; else failed++;
    if (check_disasm(0xb81fc0a8, "stur w8, [x5, #-4]")) passed++; else failed++;
    if (check_disasm(0x386f6828, "ldrb w8, [x1, x15]")) passed++; else failed++;
    if (check_disasm(0xf8606820, "ldr x0, [x1, x0]")) passed++; else failed++;
    if (check_disasm(0xb8606820, "ldr w0, [x1, x0]")) passed++; else failed++;
    if (check_disasm(0xd341fc4f, "lsr x15, x2, #1")) passed++; else failed++;
    if (check_disasm(0x53017c08, "lsr w8, w0, #1")) passed++; else failed++;
    if (check_disasm(0x53001c00, "uxtb w0, w0")) passed++; else failed++;
    if (check_disasm(0x53003c00, "uxth w0, w0")) passed++; else failed++;
    if (check_disasm(0x93401c00, "sxtb x0, w0")) passed++; else failed++;
    if (check_disasm(0x93403c00, "sxth x0, w0")) passed++; else failed++;
    if (check_disasm(0x93407c00, "sxtw x0, w0")) passed++; else failed++;
    if (check_disasm(0x13001c00, "sxtb w0, w0")) passed++; else failed++;
    if (check_disasm(0x33070c00, "bfi w0, w0, #25, #4")) passed++; else failed++;
    if (check_disasm(0xeb2f73f0, "subs x16, sp, x15, lsl #4")) passed++; else failed++;
    if (check_disasm(0x8b2063e0, "add x0, sp, x0")) passed++; else failed++;
    if (check_disasm(0xcb2043e0, "sub x0, sp, w0, uxtw")) passed++; else failed++;
    if (check_disasm(0x9278dc63, "and x3, x3, #0xffffffffffffff00")) passed++; else failed++;
    if (check_disasm(0xf278dc7f, "tst x3, #0xffffffffffffff00")) passed++; else failed++;
    if (check_disasm(0xcb0407e4, "neg x4, x4, lsl #1")) passed++; else failed++;
    if (check_disasm(0x9e660025, "fmov x5, d1")) passed++; else failed++;
    if (check_disasm(0x9e670025, "fmov d5, x1")) passed++; else failed++;
    if (check_disasm(0x1e270000, "fmov s0, w0")) passed++; else failed++;
    if (check_disasm(0x1e260000, "fmov w0, s0")) passed++; else failed++;
    if (check_disasm(0xf2a0ffe5, "movk x5, #0x7ff, lsl #0x10")) passed++; else failed++;
    if (check_disasm(0xf9800c01, "prfm pldl1strm, [x0, #0x18]")) passed++; else failed++;
    if (check_disasm(0x4e209800, "cmeq v0.16b, v0.16b, #0")) passed++; else failed++;
    if (check_disasm(0x4e010c20, "dup v0.16b, w1")) passed++; else failed++;
    if (check_disasm(0x4ea31c60, "orr v0.16b, v3.16b, v3.16b")) passed++; else failed++;
    if (check_disasm(0x4e22bc00, "addp v0.16b, v0.16b, v2.16b")) passed++; else failed++;

    std::cout << std::endl;
    std::cout << "Passed: " << passed << "/" << (passed + failed) << std::endl;

    if (failed > 0) {
        std::cerr << "FAILED: " << failed << " test(s)" << std::endl;
        return 1;
    }

    std::cout << "All reference tests passed!" << std::endl;
    return 0;
}
