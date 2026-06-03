#[cxx::bridge(namespace = "veda64_ffi")]
pub mod ffi {
    unsafe extern "C++" {
        include!("veda64_bridge.hpp");

        /// Opaque handle to a decoded instruction
        type DecodedInsn;

        /// Decode a raw 32-bit ARM64 instruction
        fn decode(raw: u32) -> UniquePtr<DecodedInsn>;

        /// Decode with alias normalization (MOV instead of ADD, CMP instead of SUBS, etc.)
        fn decode_aliased(raw: u32) -> UniquePtr<DecodedInsn>;

        /// Assemble a text instruction to a 32-bit encoding (returns 0 on failure)
        fn assemble(text: &str) -> u32;

        /// Check if a text instruction can be assembled
        fn assemble_check(text: &str) -> bool;

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

        // IR types
        type LiftedIr;

        /// Lift a raw instruction to IR
        fn ir_lift(insn: u32) -> UniquePtr<LiftedIr>;

        /// Check if lifted IR is valid
        fn ir_is_valid(l: &LiftedIr) -> bool;

        /// Get number of IR operations
        fn ir_num_ops(l: &LiftedIr) -> u32;

        /// Get opcode of IR operation (returns Opcode as u8)
        fn ir_op_opcode(l: &LiftedIr, idx: u32) -> u8;

        /// Format a single IR operation as string
        fn ir_op_to_string(l: &LiftedIr, idx: u32) -> String;

        /// Format all IR operations as string
        fn ir_to_string(l: &LiftedIr) -> String;

        /// Get opcode name from u8 value
        fn ir_opcode_name(op: u8) -> String;

        /// Simplify IR (copy propagation + dead code elimination)
        fn ir_simplify(l: &LiftedIr) -> UniquePtr<LiftedIr>;

        // Branch recognizer
        type BranchInfoFfi;

        /// Run recognize_branch over `insns` starting at `address`.
        /// Always returns a non-null BranchInfoFfi; `kind == 0` (None) when
        /// nothing matches.
        fn branch_recognize(insns: &[u32], address: u64) -> UniquePtr<BranchInfoFfi>;

        fn br_kind(b: &BranchInfoFfi) -> u8;
        fn br_consumed_bytes(b: &BranchInfoFfi) -> u8;
        fn br_is_conditional(b: &BranchInfoFfi) -> bool;
        fn br_condition(b: &BranchInfoFfi) -> i8;
        fn br_destination_known(b: &BranchInfoFfi) -> bool;
        fn br_destination(b: &BranchInfoFfi) -> u64;
        fn br_has_pointer_load(b: &BranchInfoFfi) -> bool;
        fn br_pointer_load_address(b: &BranchInfoFfi) -> u64;
        fn br_pointer_load_size(b: &BranchInfoFfi) -> u8;
        fn br_target_register(b: &BranchInfoFfi) -> u16;
        fn br_pac_authenticated(b: &BranchInfoFfi) -> bool;
        fn br_has_fallthrough(b: &BranchInfoFfi) -> bool;
        fn br_fallthrough(b: &BranchInfoFfi) -> u64;
        fn br_test_register(b: &BranchInfoFfi) -> u16;
        fn br_test_bit(b: &BranchInfoFfi) -> u8;
    }
}
