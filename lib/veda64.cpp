#include "veda64.hpp"
#include <iomanip>
#include <sstream>

namespace veda64 {

// ============================================================================
// Helper Function - Extract bits from instruction
// ============================================================================

/// Extract bits from a value starting at position 'start' with length 'width'
/// @param value The value to extract from
/// @param start The starting bit position (0-indexed from LSB)
/// @param width The number of bits to extract
/// @return The extracted bits as a uint32_t
inline uint32_t extract_bits(uint32_t value, int start, int width) {
    return (value >> start) & ((1U << width) - 1);
}

// ============================================================================
// Encoding Functions
// ============================================================================

Instruction encode_add_immediate(Register rd, Register rn, uint16_t imm12, int shift) {
    Instruction insn;
    insn.arithmetic_immediate.m_rd = rd;
    insn.arithmetic_immediate.m_rn = rn;
    insn.arithmetic_immediate.m_imm12 = imm12;
    insn.arithmetic_immediate.m_opc = 0;      // 00 = ADD
    insn.arithmetic_immediate.m_fixed = 0x11; // 10001
    insn.arithmetic_immediate.m_shift = shift;
    insn.arithmetic_immediate.m_op = 0;       // ADD
    return insn;
}

Instruction encode_sub_immediate(Register rd, Register rn, uint16_t imm12, int shift) {
    Instruction insn;
    insn.arithmetic_immediate.m_rd = rd;
    insn.arithmetic_immediate.m_rn = rn;
    insn.arithmetic_immediate.m_imm12 = imm12;
    insn.arithmetic_immediate.m_opc = 0;      // 00 = SUB
    insn.arithmetic_immediate.m_fixed = 0x11; // 10001
    insn.arithmetic_immediate.m_shift = shift;
    insn.arithmetic_immediate.m_op = 1;       // SUB
    return insn;
}

Instruction encode_add_register(Register rd, Register rn, Register rm, int shift, int shift_amount) {
    Instruction insn;
    insn.arithmetic_register.m_rd = rd;
    insn.arithmetic_register.m_rn = rn;
    insn.arithmetic_register.m_rm = rm;
    insn.arithmetic_register.m_imm6 = shift_amount;
    insn.arithmetic_register.m_opc = 0;      // 00 = ADD
    insn.arithmetic_register.m_fixed = 0x0B; // 01011
    insn.arithmetic_register.m_shift = shift;
    insn.arithmetic_register.m_op = 0;       // ADD
    return insn;
}

Instruction encode_sub_register(Register rd, Register rn, Register rm, int shift, int shift_amount) {
    Instruction insn;
    insn.arithmetic_register.m_rd = rd;
    insn.arithmetic_register.m_rn = rn;
    insn.arithmetic_register.m_rm = rm;
    insn.arithmetic_register.m_imm6 = shift_amount;
    insn.arithmetic_register.m_opc = 0;      // 00 = SUB
    insn.arithmetic_register.m_fixed = 0x0B; // 01011
    insn.arithmetic_register.m_shift = shift;
    insn.arithmetic_register.m_op = 1;       // SUB
    return insn;
}

Instruction encode_move_wide(Register rd, uint16_t imm16, int hw) {
    Instruction insn;
    insn.move_wide.m_rd = rd;
    insn.move_wide.m_imm16 = imm16;
    insn.move_wide.m_hw = hw;
    insn.move_wide.m_fixed = 0x25;  // 100101
    insn.move_wide.m_fixed2 = 0x4;  // 100
    return insn;
}

Instruction encode_load_register(Register rt, Register rn, uint16_t imm12, int opc) {
    Instruction insn;
    insn.load_register.m_rt = rt;
    insn.load_register.m_rn = rn;
    insn.load_register.m_imm12 = imm12;
    insn.load_register.m_opc = opc;
    insn.load_register.m_fixed = 0;
    insn.load_register.m_fixed2 = 0;
    insn.load_register.m_v = 0;
    insn.load_register.m_fixed3 = 0x5;  // 101
    insn.load_register.m_size = 2;      // 64-bit for opc=1
    return insn;
}

Instruction encode_store_register(Register rt, Register rn, uint16_t imm12, int opc) {
    Instruction insn;
    insn.store_register.m_rt = rt;
    insn.store_register.m_rn = rn;
    insn.store_register.m_imm12 = imm12;
    insn.store_register.m_opc = opc;
    insn.store_register.m_fixed = 0;
    insn.store_register.m_fixed2 = 0;
    insn.store_register.m_v = 0;
    insn.store_register.m_fixed3 = 0x5;  // 101
    insn.store_register.m_size = 2;      // 64-bit for opc=1
    return insn;
}

Instruction encode_branch(int32_t imm26) {
    Instruction insn;
    insn.branch.m_imm26 = imm26 & 0x3FFFFFF;
    insn.branch.m_fixed = 0x05;  // 000101
    return insn;
}

Instruction encode_branch_with_link(int32_t imm26) {
    Instruction insn;
    insn.branch.m_imm26 = imm26 & 0x3FFFFFF;
    insn.branch.m_fixed = 0x25;  // 100101
    return insn;
}

// ============================================================================
// Decoding Functions
// ============================================================================

std::string format_register(Register reg) {
    if (reg == 31) return "sp";
    return "x" + std::to_string(reg);
}

std::string format_immediate(uint32_t imm) {
    std::stringstream ss;
    ss << "0x" << std::hex << imm;
    return ss.str();
}

std::optional<DecodedInstruction> decode(const Instruction& insn) {
    DecodedInstruction result;
    uint32_t v = insn.value;
    
    // Pattern matching on full instruction value using switch statements
    
    // ===== Branch Instructions (B, BL): bits[31:26] =====
    switch (v & 0xFC000000) {
        case 0x14000000: {  // Branch (B)
            int32_t offset = v & 0x03FFFFFF;
            if (offset & 0x02000000) offset |= 0xFC000000;  // Sign extend
            result.set_type(InstructionType::Branch);
            result.set_mnemonic("b");
            result.set_operands(format_immediate(offset * 4));
            
            result.set_imm(Operand(static_cast<int64_t>(offset * 4)));
            result.add_operand(result.imm().value());
            return result;
        }
        case 0x94000000: {  // Branch with Link (BL)
            int32_t offset = v & 0x03FFFFFF;
            if (offset & 0x02000000) offset |= 0xFC000000;  // Sign extend
            result.set_type(InstructionType::BranchWithLink);
            result.set_mnemonic("bl");
            result.set_operands(format_immediate(offset * 4));
            
            result.set_imm(Operand(static_cast<int64_t>(offset * 4)));
            result.add_operand(result.imm().value());
            return result;
        }
    }
    
    // ===== ADD/SUB Immediate: bits[28:24] = 0x11 =====
    switch (v & 0x1F000000) {
        case 0x11000000: {
            uint32_t rd_val = extract_bits(v, 0, 5);
            uint32_t rn_val = extract_bits(v, 5, 5);
            uint32_t imm12 = extract_bits(v, 10, 12);
            uint32_t shift = extract_bits(v, 22, 1);
            uint32_t op = extract_bits(v, 31, 1);
            
            result.set_type(op ? InstructionType::SubImmediate : InstructionType::AddImmediate);
            result.set_mnemonic(op ? "sub" : "add");
            result.set_operands(format_register(rd_val) + ", " + format_register(rn_val) + ", " + format_immediate(imm12));
            if (shift > 0) result.set_operands(result.operands() + ", lsl #12");
            
            // Populate structured operands
            result.set_rd(Operand(static_cast<Register>(rd_val)));
            result.set_rn(Operand(static_cast<Register>(rn_val)));
            result.set_imm(Operand(static_cast<int64_t>(imm12)));
            
            result.add_operand(result.rd().value());
            result.add_operand(result.rn().value());
            result.add_operand(result.imm().value());
            return result;
        }
    }
    
    // ===== ADD/SUB Register: bits[27:23] = 0x0B =====
    switch (v & 0x0F800000) {
        case 0x05800000: {
            uint32_t rd_val = extract_bits(v, 0, 5);
            uint32_t rn_val = extract_bits(v, 5, 5);
            uint32_t imm6 = extract_bits(v, 10, 6);
            uint32_t rm_val = extract_bits(v, 16, 5);
            uint32_t shift_type = extract_bits(v, 21, 2);
            uint32_t op = extract_bits(v, 30, 1);
            
            result.set_type(op ? InstructionType::SubRegister : InstructionType::AddRegister);
            result.set_mnemonic(op ? "sub" : "add");
            result.set_operands(format_register(rd_val) + ", " + format_register(rn_val) + ", " + format_register(rm_val));
            if (imm6 > 0) {
                const char* shift_names[] = {"lsl", "lsr", "asr", "ror"};
                result.set_operands(result.operands() + ", " + std::string(shift_names[shift_type]) + " #" + std::to_string(imm6));
            }
            
            // Populate structured operands
            result.set_rd(Operand(static_cast<Register>(rd_val)));
            result.set_rn(Operand(static_cast<Register>(rn_val)));
            result.set_rm(Operand(static_cast<Register>(rm_val)));
            if (imm6 > 0) {
                result.set_imm(Operand(static_cast<int64_t>(imm6)));
            }
            
            result.add_operand(result.rd().value());
            result.add_operand(result.rn().value());
            result.add_operand(result.rm().value());
            if (imm6 > 0) {
                result.add_operand(result.imm().value());
            }
            return result;
        }
    }
    
    // ===== MOVZ (Move Wide): bits[31:29] = 100 =====
    switch (v & 0xE0000000) {
        case 0x80000000: {
            uint32_t rd_val = extract_bits(v, 0, 5);
            uint32_t imm16 = extract_bits(v, 5, 16);
            uint32_t hw = extract_bits(v, 21, 2);
            
            result.set_type(InstructionType::MovWide);
            result.set_mnemonic("movz");
            result.set_operands(format_register(rd_val) + ", " + format_immediate(imm16) + ", lsl #" + std::to_string(hw * 16));
            
            // Populate structured operands
            result.set_rd(Operand(static_cast<Register>(rd_val)));
            result.set_imm(Operand(static_cast<int64_t>(imm16)));
            
            result.add_operand(result.rd().value());
            result.add_operand(result.imm().value());
            return result;
        }
    }
    
    // ===== Load/Store Register Unsigned: bits[29:27] = 101, [25:24] = 00 =====
    switch (v & 0x3B000000) {
        case 0x28000000: {  // LDR/STR (cannot reliably distinguish currently)
            uint32_t rt_val = extract_bits(v, 0, 5);
            uint32_t rn_val = extract_bits(v, 5, 5);
            uint32_t imm12 = extract_bits(v, 10, 12);
            uint32_t size = extract_bits(v, 30, 2);
            
            result.set_type(InstructionType::LoadRegister);
            result.set_mnemonic("ldr");
            uint16_t offset = imm12 << (size * 2);
            result.set_operands(format_register(rt_val) + ", [" + format_register(rn_val) + ", " + format_immediate(offset) + "]");
            
            // Populate structured operands
            result.set_rt(Operand(static_cast<Register>(rt_val)));
            result.set_addr(Operand(static_cast<Register>(rn_val), static_cast<int32_t>(offset)));
            
            result.add_operand(result.rt().value());
            result.add_operand(result.addr().value());
            return result;
        }
    }
    
    return std::nullopt;
}

} // namespace veda64
