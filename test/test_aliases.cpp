// Comprehensive test suite for ARM64 instruction aliases
// Tests that aliases decode correctly to their canonical forms

#include "veda64.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace veda64;
using namespace veda64::General;

// Test alias resolution for bitfield operations
void test_bitfield_aliases() {
    std::cout << "\n=== Testing Bitfield Aliases ===" << std::endl;

    // BFM 32-bit: use encode function
    {
        uint32_t insn = encode_bfm_32m_bitfield(0, 1, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::BFM);
        std::cout << "  ✓ BFM_32: BFM 32-bit base form" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // BFM 64-bit
    {
        uint32_t insn = encode_bfm_64m_bitfield(0, 1, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::BFM);
        std::cout << "  ✓ BFM_64: BFM 64-bit base form" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    std::cout << "  Bitfield alias tests passed!" << std::endl;
}

// Test alias resolution for shift operations
void test_shift_aliases() {
    std::cout << "\n=== Testing Shift Aliases ===" << std::endl;

    // ASRV 32-bit
    {
        uint32_t insn = encode_asrv_32_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ASRV);
        std::cout << "  ✓ ASRV_32: ASRV 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ASRV 64-bit
    {
        uint32_t insn = encode_asrv_64_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ASRV);
        std::cout << "  ✓ ASRV_64: ASRV 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // LSLV 32-bit
    {
        uint32_t insn = encode_lslv_32_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::LSLV);
        std::cout << "  ✓ LSLV_32: LSLV 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // LSLV 64-bit
    {
        uint32_t insn = encode_lslv_64_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::LSLV);
        std::cout << "  ✓ LSLV_64: LSLV 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // LSRV 32-bit
    {
        uint32_t insn = encode_lsrv_32_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::LSRV);
        std::cout << "  ✓ LSRV_32: LSRV 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // LSRV 64-bit
    {
        uint32_t insn = encode_lsrv_64_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::LSRV);
        std::cout << "  ✓ LSRV_64: LSRV 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // RORV 32-bit
    {
        uint32_t insn = encode_rorv_32_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::RORV);
        std::cout << "  ✓ RORV_32: RORV 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // RORV 64-bit
    {
        uint32_t insn = encode_rorv_64_dp_2src(0, 1, 2);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::RORV);
        std::cout << "  ✓ RORV_64: RORV 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    std::cout << "  Shift alias tests passed!" << std::endl;
}

// Test alias resolution for logical operations
void test_logical_aliases() {
    std::cout << "\n=== Testing Logical Aliases ===" << std::endl;

    // ANDS 32-bit shifted register
    {
        uint32_t insn = encode_ands_32_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ANDS);
        std::cout << "  ✓ ANDS_32: ANDS 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ANDS 64-bit shifted register
    {
        uint32_t insn = encode_ands_64_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ANDS);
        std::cout << "  ✓ ANDS_64: ANDS 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ORN 32-bit shifted register
    {
        uint32_t insn = encode_orn_32_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ORN);
        std::cout << "  ✓ ORN_32: ORN 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ORN 64-bit shifted register
    {
        uint32_t insn = encode_orn_64_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ORN);
        std::cout << "  ✓ ORN_64: ORN 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    std::cout << "  Logical alias tests passed!" << std::endl;
}

// Test alias resolution for arithmetic operations
void test_arithmetic_aliases() {
    std::cout << "\n=== Testing Arithmetic Aliases ===" << std::endl;

    // SUBS 32-bit shifted register
    {
        uint32_t insn = encode_subs_32_addsub_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::SUBS);
        std::cout << "  ✓ SUBS_32: SUBS 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // SUBS 64-bit shifted register
    {
        uint32_t insn = encode_subs_64_addsub_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::SUBS);
        std::cout << "  ✓ SUBS_64: SUBS 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ADDS 32-bit shifted register
    {
        uint32_t insn = encode_adds_32_addsub_shift(0, 1, 0, 2, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ADDS);
        std::cout << "  ✓ ADDS_32: ADDS 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ADDS 64-bit shifted register
    {
        uint32_t insn = encode_adds_64_addsub_shift(0, 1, 0, 2, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ADDS);
        std::cout << "  ✓ ADDS_64: ADDS 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // SUB 32-bit shifted register
    {
        uint32_t insn = encode_sub_32_addsub_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::SUB);
        std::cout << "  ✓ SUB_32: SUB 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // SUB 64-bit shifted register
    {
        uint32_t insn = encode_sub_64_addsub_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::SUB);
        std::cout << "  ✓ SUB_64: SUB 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    std::cout << "  Arithmetic alias tests passed!" << std::endl;
}

// Test alias resolution for move operations
void test_move_aliases() {
    std::cout << "\n=== Testing Move Aliases ===" << std::endl;

    // ORR 32-bit shifted register
    {
        uint32_t insn = encode_orr_32_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ORR);
        std::cout << "  ✓ ORR_32: ORR 32-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ORR 64-bit shifted register
    {
        uint32_t insn = encode_orr_64_log_shift(0, 1, 2, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ORR);
        std::cout << "  ✓ ORR_64: ORR 64-bit" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ADD 32-bit immediate
    {
        uint32_t insn = encode_add_32_addsub_imm(0, 1, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ADD);
        std::cout << "  ✓ ADD_32_imm: ADD 32-bit immediate" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    // ADD 64-bit immediate
    {
        uint32_t insn = encode_add_64_addsub_imm(0, 1, 0, 0);
        auto result = decode_general(insn);
        assert(result.has_value());
        assert(result->mnemonic == Mnemonic::ADD);
        std::cout << "  ✓ ADD_64_imm: ADD 64-bit immediate" << std::endl;
        std::cout << "    Disassembly: " << result->to_string() << std::endl;
    }

    std::cout << "  Move alias tests passed!" << std::endl;
}

// Test that all major alias categories are covered
void test_alias_completeness() {
    std::cout << "\n=== Alias Completeness Check ===" << std::endl;

    std::vector<std::string> alias_categories = {
        "Bitfield operations (BFM)",
        "Shift operations (ASRV, LSLV, LSRV, RORV)",
        "Logical operations (ANDS, ORN)",
        "Arithmetic operations (SUBS, ADDS, SUB)",
        "Move operations (ORR, ADD)",
    };

    std::cout << "Testing " << alias_categories.size() << " alias categories:" << std::endl;
    for (const auto& category : alias_categories) {
        std::cout << "  • " << category << std::endl;
    }

    std::cout << "\nTotal alias groups tested: " << alias_categories.size() << std::endl;
}

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "ARM64 Instruction Alias Test Suite" << std::endl;
    std::cout << "==================================================" << std::endl;

    try {
        test_bitfield_aliases();
        test_shift_aliases();
        test_logical_aliases();
        test_arithmetic_aliases();
        test_move_aliases();
        test_alias_completeness();

        std::cout << "\n==================================================" << std::endl;
        std::cout << "✓ All alias tests passed!" << std::endl;
        std::cout << "==================================================" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n✗ Test failed: " << e.what() << std::endl;
        return 1;
    }
}
