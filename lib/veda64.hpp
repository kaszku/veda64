#ifndef VEDA64_HPP
#define VEDA64_HPP

#include <cstdint>
#include <string>
#include <optional>
#include <vector>

namespace veda64 {

// Register type (ARM64 supports 31 general registers + sp/zr)
using Register = uint8_t;

// ============================================================================
// Opcodes Enum - Represents all instruction mnemonics
// ============================================================================
enum class OpcodeType {
    Add,      // ADD
    Sub,      // SUB
    And,      // AND
    Orr,      // ORR (OR)
    Eor,      // EOR (XOR)
    Mov,      // MOV with wide immediate (MOVZ)
    Movn,     // MOV with wide NOT (MOVN)
    Movk,     // MOV with wide KEEP (MOVK)
    Cmp,      // Compare
    Cmn,      // Compare Negative
    Lsl,      // Logical Shift Left
    Lsr,      // Logical Shift Right
    Asr,      // Arithmetic Shift Right
    Ror,      // Rotate Right
    Mul,      // Multiply
    Sdiv,     // Signed Divide
    Udiv,     // Unsigned Divide
    Ldr,      // LDR (load register)
    Str,      // STR (store register)
    Ldp,      // LDP (load pair)
    Stp,      // STP (store pair)
    Nop,      // No Operation
    Ret,      // Return
    Svc,      // Supervisor Call
    B,        // B (unconditional branch)
    Bl,       // BL (branch with link)
};

// ============================================================================
// Register Names Enum - Symbolic names for ARM64 registers
// ============================================================================
enum class RegisterName : uint8_t {
    // 64-bit X registers and 32-bit W registers (same register, different view)
    X0 = 0,   W0 = 0,
    X1 = 1,   W1 = 1,
    X2 = 2,   W2 = 2,
    X3 = 3,   W3 = 3,
    X4 = 4,   W4 = 4,
    X5 = 5,   W5 = 5,
    X6 = 6,   W6 = 6,
    X7 = 7,   W7 = 7,
    X8 = 8,   W8 = 8,
    X9 = 9,   W9 = 9,
    X10 = 10, W10 = 10,
    X11 = 11, W11 = 11,
    X12 = 12, W12 = 12,
    X13 = 13, W13 = 13,
    X14 = 14, W14 = 14,
    X15 = 15, W15 = 15,
    X16 = 16, W16 = 16,
    X17 = 17, W17 = 17,
    X18 = 18, W18 = 18,
    X19 = 19, W19 = 19,
    X20 = 20, W20 = 20,
    X21 = 21, W21 = 21,
    X22 = 22, W22 = 22,
    X23 = 23, W23 = 23,
    X24 = 24, W24 = 24,
    X25 = 25, W25 = 25,
    X26 = 26, W26 = 26,
    X27 = 27, W27 = 27,
    X28 = 28, W28 = 28,
    X29 = 29, W29 = 29,
    X30 = 30, W30 = 30,
    
    // Special registers
    SP = 31,  // Stack pointer (X31 when used as base)
    ZR = 31,  // Zero register (X31 when used as zero)
    
    // Aliases
    LR = X30,   // Link register (same as X30)
    FP = X29,   // Frame pointer (same as X29)
    IP0 = X16,  // Intra-procedure call temporary 0 (same as X16)
    IP1 = X17,  // Intra-procedure call temporary 1 (same as X17)
};

// ============================================================================
// ARM64 Instruction Encoding Structures (must be defined before Instruction)
// ============================================================================

/// Register-Immediate Arithmetic (ADD, SUB, etc.)
/// Bits: [31]op | [30:29]shift | [28:24]1000.1 | [23:22]opc | [21:16]imm12_hi | [15:10]imm12_lo | [9:5]rn | [4:0]rd
struct ArithmeticImmediate {
    uint32_t m_rd : 5;      // [4:0]   - Destination register
    uint32_t m_rn : 5;      // [9:5]   - First operand register
    uint32_t m_imm12 : 12;  // [21:10] - 12-bit immediate
    uint32_t m_opc : 2;     // [23:22] - Operation code
    uint32_t m_fixed : 5;   // [28:24] - Fixed pattern 10001
    uint32_t m_shift : 2;   // [30:29] - Shift (0=LSL #0, 1=LSL #12)
    uint32_t m_op : 1;      // [31]    - Operation (0=ADD, 1=SUB)
};

/// Register-Register Arithmetic (ADD, SUB, etc.)
/// Bits: [31]op | [30:29]shift | [28:24]01011 | [23:22]opc | [21:16]rm | [15:10]imm6 | [9:5]rn | [4:0]rd
struct ArithmeticRegister {
    uint32_t m_rd : 5;      // [4:0]   - Destination register
    uint32_t m_rn : 5;      // [9:5]   - First operand register
    uint32_t m_imm6 : 6;    // [15:10] - Shift amount
    uint32_t m_rm : 5;      // [20:16] - Second operand register
    uint32_t m_opc : 2;     // [23:22] - Operation code
    uint32_t m_fixed : 5;   // [28:24] - Fixed pattern 01011
    uint32_t m_shift : 2;   // [30:29] - Shift type (00=LSL, 01=LSR, 10=ASR, 11=ROR)
    uint32_t m_op : 1;      // [31]    - Operation (0=ADD, 1=SUB)
};

/// Move (MOV) - Wide Immediate
/// Bits: [31:29]100 | [28:23]1010.0 | [22:21]hw | [20:5]imm16 | [4:0]rd
struct MoveWideImmediate {
    uint32_t m_rd : 5;      // [4:0]   - Destination register
    uint32_t m_imm16 : 16;  // [20:5]  - 16-bit immediate
    uint32_t m_hw : 2;      // [22:21] - Hardware (shift position: 0, 16, 32, 48)
    uint32_t m_fixed : 6;   // [28:23] - Fixed pattern 100101
    uint32_t m_fixed2 : 3;  // [31:29] - Fixed pattern 100
};

/// Load Register (LDR)
/// Bits: [31:30]sz | [29:27]101 | [26]V | [25:24]00 | [23:22]opc | [21:10]imm12 | [9:5]rn | [4:0]rt
struct LoadRegisterUnsignedImmediate {
    uint32_t m_rt : 5;      // [4:0]   - Destination register
    uint32_t m_rn : 5;      // [9:5]   - Base register
    uint32_t m_imm12 : 12;  // [21:10] - 12-bit unsigned offset
    uint32_t m_opc : 2;     // [23:22] - Load variant (00=32-bit, 01=64-bit, 10=32-bit signed, 11=64-bit signed)
    uint32_t m_fixed : 1;   // [24]    - Fixed 0
    uint32_t m_fixed2 : 1;  // [25]    - Fixed 0
    uint32_t m_v : 1;       // [26]    - Vector (0=GPR, 1=Vector)
    uint32_t m_fixed3 : 3;  // [29:27] - Fixed pattern 101
    uint32_t m_size : 2;    // [31:30] - Size (00=8-bit, 01=16-bit, 10=32-bit, 11=64-bit)
};

/// Store Register (STR)
/// Bits: [31:30]sz | [29:27]101 | [26]V | [25:24]00 | [23:22]opc | [21:10]imm12 | [9:5]rn | [4:0]rt
struct StoreRegisterUnsignedImmediate {
    uint32_t m_rt : 5;      // [4:0]   - Source register
    uint32_t m_rn : 5;      // [9:5]   - Base register
    uint32_t m_imm12 : 12;  // [21:10] - 12-bit unsigned offset
    uint32_t m_opc : 2;     // [23:22] - Store variant (00=32-bit, 01=64-bit)
    uint32_t m_fixed : 1;   // [24]    - Fixed 0
    uint32_t m_fixed2 : 1;  // [25]    - Fixed 0
    uint32_t m_v : 1;       // [26]    - Vector (0=GPR, 1=Vector)
    uint32_t m_fixed3 : 3;  // [29:27] - Fixed pattern 101
    uint32_t m_size : 2;    // [31:30] - Size (00=8-bit, 01=16-bit, 10=32-bit, 11=64-bit)
};

/// Branch (B, BL)
/// Bits: [31:26]op | [25:0]imm26
struct Branch {
    int32_t m_imm26 : 26;  // [25:0]  - 26-bit signed immediate (offset in instructions)
    uint32_t m_fixed : 6;  // [31:26] - Fixed pattern (000101=B, 100101=BL)
};

/// Main instruction type with union for all encoding variants
struct Instruction {
    union {
        uint32_t value;
        ArithmeticImmediate arithmetic_immediate;
        ArithmeticRegister arithmetic_register;
        MoveWideImmediate move_wide;
        LoadRegisterUnsignedImmediate load_register;
        StoreRegisterUnsignedImmediate store_register;
        Branch branch;
    };
    
    // Constructors
    Instruction() : value(0) {}
    explicit Instruction(uint32_t v) : value(v) {}
    
    // Implicit conversion to uint32_t for convenience
    operator uint32_t() const { return value; }
    
    // Bitwise operations
    uint32_t operator&(uint32_t mask) const { return value & mask; }
    uint32_t operator|(uint32_t val) const { return value | val; }
};

// ============================================================================
// Instruction Encoding/Decoding API
// ============================================================================

enum class InstructionType {
    Unknown,
    // Arithmetic
    AddImmediate,
    SubImmediate,
    AddRegister,
    SubRegister,
    // Logical Operations
    AndImmediate,
    AndRegister,
    OrrImmediate,
    OrrRegister,
    EorImmediate,
    EorRegister,
    // Move Operations
    MovWide,        // MOVZ
    MovnWide,       // MOVN
    MovkWide,       // MOVK
    // Compare
    Cmp,            // Compare (special case of SUB)
    Cmn,            // Compare Negative (special case of ADD)
    // Shift Operations
    Lsl,            // Logical Shift Left
    Lsr,            // Logical Shift Right
    Asr,            // Arithmetic Shift Right
    Ror,            // Rotate Right
    // Multiply
    Mul,            // Multiply
    Sdiv,           // Signed Divide
    Udiv,           // Unsigned Divide
    // Memory Operations
    LoadRegister,
    StoreRegister,
    LoadPair,       // LDP
    StorePair,      // STP
    // Special
    Nop,            // No Operation
    Ret,            // Return
    Svc,            // Supervisor Call
    // Branch
    Branch,
    BranchWithLink
};

// ============================================================================
// Operand Type and Structure
// ============================================================================

enum class OperandType {
    None,       // No operand
    Register,   // Register operand
    Immediate,  // Immediate value
    Memory      // Memory address [base, offset]
};

struct MemoryOperand {
    Register m_base;      // Base register
    int32_t m_offset;     // Offset from base
};

struct Operand {
    OperandType m_type;
    
    union OperandValue {
        Register m_reg;           // For register operands
        int64_t m_immediate;      // For immediate values (can be signed)
        MemoryOperand m_memory;   // For memory operands
        
        // Default constructor needed for union in struct
        OperandValue() : m_immediate(0) {}
    } m_value;
    
    // Constructors for convenience
    Operand() : m_type(OperandType::None) {}
    
    explicit Operand(Register r) : m_type(OperandType::Register) {
        m_value.m_reg = r;
    }
    
    explicit Operand(int64_t imm) : m_type(OperandType::Immediate) {
        m_value.m_immediate = imm;
    }
    
    Operand(Register base, int32_t offset) : m_type(OperandType::Memory) {
        m_value.m_memory.m_base = base;
        m_value.m_memory.m_offset = offset;
    }
    
    // Getters
    OperandType type() const { return m_type; }
    Register reg() const { return m_value.m_reg; }
    int64_t immediate() const { return m_value.m_immediate; }
    const MemoryOperand& memory() const { return m_value.m_memory; }
    
    // Setters
    void set_type(OperandType t) { m_type = t; }
    void set_reg(Register r) { m_value.m_reg = r; }
    void set_immediate(int64_t imm) { m_value.m_immediate = imm; }
    void set_memory(const MemoryOperand& mem) { m_value.m_memory = mem; }
};

struct DecodedInstruction {
    InstructionType m_type;
    std::string m_mnemonic;
    std::string m_operands;  // Human-readable operands string (for backward compatibility)
    
    // Structured operand information
    std::vector<Operand> m_operand_list;  // All operands in order
    
    // Common operand slots for easy access (std::nullopt if not applicable)
    std::optional<Operand> m_rd;  // Destination register
    std::optional<Operand> m_rn;  // First source register
    std::optional<Operand> m_rm;  // Second source register
    std::optional<Operand> m_rt;  // Transfer register (LDR/STR)
    std::optional<Operand> m_imm; // Immediate value
    std::optional<Operand> m_addr; // Memory address
    
    // Getters
    InstructionType type() const { return m_type; }
    const std::string& mnemonic() const { return m_mnemonic; }
    const std::string& operands() const { return m_operands; }
    const std::vector<Operand>& operand_list() const { return m_operand_list; }
    const std::optional<Operand>& rd() const { return m_rd; }
    const std::optional<Operand>& rn() const { return m_rn; }
    const std::optional<Operand>& rm() const { return m_rm; }
    const std::optional<Operand>& rt() const { return m_rt; }
    const std::optional<Operand>& imm() const { return m_imm; }
    const std::optional<Operand>& addr() const { return m_addr; }
    
    // Setters
    void set_type(InstructionType t) { m_type = t; }
    void set_mnemonic(const std::string& m) { m_mnemonic = m; }
    void set_operands(const std::string& o) { m_operands = o; }
    void set_operand_list(const std::vector<Operand>& l) { m_operand_list = l; }
    void add_operand(const Operand& op) { m_operand_list.push_back(op); }
    void set_rd(const std::optional<Operand>& r) { m_rd = r; }
    void set_rn(const std::optional<Operand>& r) { m_rn = r; }
    void set_rm(const std::optional<Operand>& r) { m_rm = r; }
    void set_rt(const std::optional<Operand>& r) { m_rt = r; }
    void set_imm(const std::optional<Operand>& i) { m_imm = i; }
    void set_addr(const std::optional<Operand>& a) { m_addr = a; }
};

// Encode functions
Instruction encode_add_immediate(Register rd, Register rn, uint16_t imm12, int shift = 0);
Instruction encode_sub_immediate(Register rd, Register rn, uint16_t imm12, int shift = 0);
Instruction encode_add_register(Register rd, Register rn, Register rm, int shift = 0, int shift_amount = 0);
Instruction encode_sub_register(Register rd, Register rn, Register rm, int shift = 0, int shift_amount = 0);
Instruction encode_move_wide(Register rd, uint16_t imm16, int hw = 0);
Instruction encode_load_register(Register rt, Register rn, uint16_t imm12, int opc = 1);
Instruction encode_store_register(Register rt, Register rn, uint16_t imm12, int opc = 1);
Instruction encode_branch(int32_t imm26);
Instruction encode_branch_with_link(int32_t imm26);

// Decode function
std::optional<DecodedInstruction> decode(const Instruction& insn);
std::string format_register(Register reg);
std::string format_immediate(uint32_t imm);

} // namespace veda64

#endif // VEDA64_HPP
