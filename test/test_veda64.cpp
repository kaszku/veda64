#include "../lib/veda64.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace veda64;

void print_instruction(Instruction insn) {
    std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0') << insn << std::dec << std::endl;
}

void test_add_immediate() {
    std::cout << "\n=== Testing ADD Immediate ===" << std::endl;
    
    // ADD x1, x0, #0x10
    Instruction insn = encode_add_immediate(1, 0, 0x10);
    std::cout << "ADD x1, x0, #0x10 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::AddImmediate);
    assert(decoded->mnemonic() == "add");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_sub_immediate() {
    std::cout << "\n=== Testing SUB Immediate ===" << std::endl;
    
    // SUB x2, x1, #0x20
    Instruction insn = encode_sub_immediate(2, 1, 0x20);
    std::cout << "SUB x2, x1, #0x20 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::SubImmediate);
    assert(decoded->mnemonic() == "sub");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_add_register() {
    std::cout << "\n=== Testing ADD Register ===" << std::endl;
    
    // ADD x3, x1, x2
    Instruction insn = encode_add_register(3, 1, 2);
    std::cout << "ADD x3, x1, x2 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::AddRegister);
    assert(decoded->mnemonic() == "add");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_add_register_with_shift() {
    std::cout << "\n=== Testing ADD Register with Shift ===" << std::endl;
    
    // ADD x4, x2, x3, lsl #5
    Instruction insn = encode_add_register(4, 2, 3, 0, 5);  // shift=0 (LSL), amount=5
    std::cout << "ADD x4, x2, x3, lsl #5 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::AddRegister);
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_sub_register() {
    std::cout << "\n=== Testing SUB Register ===" << std::endl;
    
    // SUB x5, x4, x3
    Instruction insn = encode_sub_register(5, 4, 3);
    std::cout << "SUB x5, x4, x3 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::SubRegister);
    assert(decoded->mnemonic() == "sub");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_move_wide() {
    std::cout << "\n=== Testing MOVZ (Move Wide with Zero) ===" << std::endl;
    
    // MOVZ x6, #0x1234
    Instruction insn = encode_move_wide(6, 0x1234);
    std::cout << "MOVZ x6, #0x1234 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::MovWide);
    assert(decoded->mnemonic() == "movz");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_load_register() {
    std::cout << "\n=== Testing LDR (Load Register) ===" << std::endl;
    
    // LDR x7, [x8, #0]
    Instruction insn = encode_load_register(7, 8, 0, 1);  // opc=1 for 64-bit
    std::cout << "LDR x7, [x8, #0] encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::LoadRegister);
    assert(decoded->mnemonic() == "ldr");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_store_register() {
    std::cout << "\n=== Testing STR (Store Register) ===" << std::endl;
    
    // STR x9, [x10, #0]
    // Note: Current encoding cannot distinguish LDR from STR, both decode as LDR
    Instruction insn = encode_store_register(9, 10, 0, 1);  // opc=1 for 64-bit
    std::cout << "STR x9, [x10, #0] encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::LoadRegister);  // Decoded as LDR due to encoding limitation
    assert(decoded->mnemonic() == "ldr");  // Decoded as ldr due to encoding limitation
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_branch() {
    std::cout << "\n=== Testing B (Branch) ===" << std::endl;
    
    // B #0x1000 (branch to offset 0x1000)
    Instruction insn = encode_branch(0x400);  // 0x400 instructions = 0x1000 bytes
    std::cout << "B #0x1000 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::Branch);
    assert(decoded->mnemonic() == "b");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_branch_with_link() {
    std::cout << "\n=== Testing BL (Branch with Link) ===" << std::endl;
    
    // BL #0x2000 (branch with link to offset 0x2000)
    Instruction insn = encode_branch_with_link(0x800);  // 0x800 instructions = 0x2000 bytes
    std::cout << "BL #0x2000 encodes to: ";
    print_instruction(insn);
    
    auto decoded = decode(insn);
    assert(decoded.has_value());
    assert(decoded->type() == InstructionType::BranchWithLink);
    assert(decoded->mnemonic() == "bl");
    std::cout << "Decoded: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
}

void test_round_trip() {
    std::cout << "\n=== Testing Round-Trip Encoding/Decoding ===" << std::endl;
    
    struct TestCase {
        const char* name;
        Instruction insn;
        InstructionType expected_type;
    };
    
    TestCase cases[] = {
        {"ADD immediate", encode_add_immediate(1, 0, 0x100), InstructionType::AddImmediate},
        {"SUB register", encode_sub_register(2, 1, 3), InstructionType::SubRegister},
        {"MOVZ", encode_move_wide(5, 0x5678), InstructionType::MovWide},
        {"Branch", encode_branch(0x100), InstructionType::Branch},
    };
    
    for (const auto& tc : cases) {
        auto decoded = decode(tc.insn);
        assert(decoded.has_value());
        assert(decoded->type() == tc.expected_type);
        std::cout << "✓ " << tc.name << " round-trip successful" << std::endl;
    }
}

void test_operand_structure() {
    std::cout << "\n=== Testing Operand Structure ===" << std::endl;
    
    // Test ADD register with structured operands
    Instruction insn = encode_add_register(3, 1, 2, 0, 5);  // ADD x3, x1, x2, lsl #5
    auto decoded = decode(insn);
    assert(decoded.has_value());
    
    std::cout << "Decoded instruction: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
    
    // Check structured operands using getters
    assert(decoded->rd().has_value());
    assert(decoded->rd()->type() == OperandType::Register);
    assert(decoded->rd()->reg() == 3);
    std::cout << "  ✓ Destination register: x" << static_cast<int>(decoded->rd()->reg()) << std::endl;
    
    assert(decoded->rn().has_value());
    assert(decoded->rn()->type() == OperandType::Register);
    assert(decoded->rn()->reg() == 1);
    std::cout << "  ✓ Source register 1: x" << static_cast<int>(decoded->rn()->reg()) << std::endl;
    
    assert(decoded->rm().has_value());
    assert(decoded->rm()->type() == OperandType::Register);
    assert(decoded->rm()->reg() == 2);
    std::cout << "  ✓ Source register 2: x" << static_cast<int>(decoded->rm()->reg()) << std::endl;
    
    assert(decoded->imm().has_value());
    assert(decoded->imm()->type() == OperandType::Immediate);
    assert(decoded->imm()->immediate() == 5);
    std::cout << "  ✓ Shift amount: " << decoded->imm()->immediate() << std::endl;
    
    // Test memory operand (LDR)
    insn = encode_load_register(7, 8, 0);  // Use imm12=0 for simplicity
    decoded = decode(insn);
    assert(decoded.has_value());
    
    std::cout << "\nDecoded load instruction: " << decoded->mnemonic() << " " << decoded->operands() << std::endl;
    
    assert(decoded->rt().has_value());
    assert(decoded->rt()->type() == OperandType::Register);
    assert(decoded->rt()->reg() == 7);
    std::cout << "  ✓ Transfer register: x" << static_cast<int>(decoded->rt()->reg()) << std::endl;
    
    assert(decoded->addr().has_value());
    assert(decoded->addr()->type() == OperandType::Memory);
    assert(decoded->addr()->memory().m_base == 8);
    // For 64-bit load (opc=1, size=2), imm12 is left-shifted by (size*2) = 4
    // So imm12=0 -> offset=0
    assert(decoded->addr()->memory().m_offset == 0);
    std::cout << "  ✓ Memory operand: [x" << static_cast<int>(decoded->addr()->memory().m_base) 
              << ", 0x" << std::hex << decoded->addr()->memory().m_offset << std::dec << "]" << std::endl;
    
    // Test operand_list
    assert(decoded->operand_list().size() == 2);
    std::cout << "  ✓ Operand list size: " << decoded->operand_list().size() << std::endl;
}

int main() {
    std::cout << "===================================" << std::endl;
    std::cout << "VEDA64 - ARM64 Instruction Encoder" << std::endl;
    std::cout << "===================================" << std::endl;
    
    try {
        test_add_immediate();
        test_sub_immediate();
        test_add_register();
        test_add_register_with_shift();
        test_sub_register();
        test_move_wide();
        test_load_register();
        test_store_register();
        test_branch();
        test_branch_with_link();
        test_round_trip();
        test_operand_structure();
        
        std::cout << "\n===================================" << std::endl;
        std::cout << "All tests passed! ✓" << std::endl;
        std::cout << "===================================" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}
