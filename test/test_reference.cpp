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
    if (check_disasm(0x37f800a0, "tbnz w0, #0x1f, .+0x14")) passed++; else failed++;
    if (check_disasm(0x394043a8, "ldrb w8, [fp, #0x10]")) passed++; else failed++;
    if (check_disasm(0x35000068, "cbnz w8, .+0xc")) passed++; else failed++;
    if (check_disasm(0xd43e0000, "brk #0xf000")) passed++; else failed++;
    if (check_disasm(0x14000001, "b .+0x4")) passed++; else failed++;
    if (check_disasm(0xa8c27bfd, "ldp fp, lr, [sp], #0x20")) passed++; else failed++;
    if (check_disasm(0xd50323ff, "autibsp")) passed++; else failed++;
    if (check_disasm(0xd65f03c0, "ret")) passed++; else failed++;

    std::cout << std::endl;
    std::cout << "Passed: " << passed << "/" << (passed + failed) << std::endl;

    if (failed > 0) {
        std::cerr << "FAILED: " << failed << " test(s)" << std::endl;
        return 1;
    }

    std::cout << "All reference tests passed!" << std::endl;
    return 0;
}
