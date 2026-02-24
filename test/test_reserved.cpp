// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_udf_only_perm_undef() {
    uint32_t insn = 0x00000000u;
    auto result = decode(insn);
    assert(result.has_value()); (void)result;
    assert(result->mnemonic == Mnemonic::UDF);
    std::cout << "  udf_only_perm_undef: " << result->to_string() << std::endl;
}

int main() {
    std::cout << "Running reserved encoding tests (1 encodings)..." << std::endl;
    int failed = 0;

    try { test_udf_only_perm_undef(); } catch (...) { std::cerr << "FAIL: udf_only_perm_undef" << std::endl; failed++; }

    std::cout << (1 - failed) << " / 1 passed" << std::endl;
    return failed;
}
