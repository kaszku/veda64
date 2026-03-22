#[cxx::bridge(namespace = "veda64_ffi")]
pub mod ffi {
    unsafe extern "C++" {
        include!("veda64_bridge.hpp");

        /// Opaque handle to a decoded instruction
        type DecodedInsn;

        /// Decode a raw 32-bit ARM64 instruction
        fn decode(raw: u32) -> UniquePtr<DecodedInsn>;

        /// Check if the decode result is valid
        fn is_valid(insn: &DecodedInsn) -> bool;

        /// Get mnemonic as u16 (maps to Mnemonic enum)
        fn get_mnemonic(insn: &DecodedInsn) -> u16;

        /// Get condition code (-1 = none, 0-15 = EQ..NV)
        fn get_condition(insn: &DecodedInsn) -> i8;

        /// Get raw instruction value
        fn get_raw_value(insn: &DecodedInsn) -> u32;

        /// Get number of operands
        fn get_num_operands(insn: &DecodedInsn) -> u32;

        /// Get operand type (returns OperandType as u8)
        fn get_operand_type(insn: &DecodedInsn, idx: u32) -> u8;

        /// Get register value (for Register operands)
        fn get_operand_reg(insn: &DecodedInsn, idx: u32) -> u16;

        /// Get immediate value (for Immediate operands)
        fn get_operand_imm(insn: &DecodedInsn, idx: u32) -> u64;

        /// Get signed immediate (for SignedImmediate/Label operands)
        fn get_operand_simm(insn: &DecodedInsn, idx: u32) -> i32;

        /// Get memory base register (for Memory operands)
        fn get_operand_mem_base(insn: &DecodedInsn, idx: u32) -> u16;

        /// Get memory offset (for Memory operands)
        fn get_operand_mem_offset(insn: &DecodedInsn, idx: u32) -> i32;

        /// Get memory addressing mode (for Memory operands)
        fn get_operand_mem_mode(insn: &DecodedInsn, idx: u32) -> u8;

        /// Get shift type (for Shift operands)
        fn get_operand_shift_type(insn: &DecodedInsn, idx: u32) -> u8;

        /// Get shift amount (for Shift operands)
        fn get_operand_shift_amount(insn: &DecodedInsn, idx: u32) -> u8;

        /// Get extend type (for Extend operands)
        fn get_operand_extend_type(insn: &DecodedInsn, idx: u32) -> u8;

        /// Get extend amount (for Extend operands)
        fn get_operand_extend_amount(insn: &DecodedInsn, idx: u32) -> u8;

        /// Format instruction as disassembly string
        fn insn_to_string(insn: &DecodedInsn) -> String;

        /// Format a single operand as string
        fn operand_to_string(insn: &DecodedInsn, idx: u32) -> String;

        /// Get mnemonic name from u16 value
        fn mnemonic_name(m: u16) -> String;
    }
}
