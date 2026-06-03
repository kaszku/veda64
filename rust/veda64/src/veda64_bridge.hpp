#pragma once

#ifndef VEDA64_STRINGS
#define VEDA64_STRINGS
#endif
#ifndef VEDA64_IR
#define VEDA64_IR
#endif
#ifndef VEDA64_HOOK
#define VEDA64_HOOK
#endif
#include "veda64.hpp"
#include "veda64/assembler.hpp"
#include "veda64/ir.hpp"
#include "veda64/branch_recognize.hpp"

#include "rust/cxx.h"
#include <memory>

namespace veda64_ffi {

struct DecodedInsn {
    bool valid;
    veda64::Instruction insn;
};

struct LiftedIr {
    bool valid;
    std::vector<veda64::ir::Op> ops;
};

std::unique_ptr<DecodedInsn> decode(uint32_t raw);
std::unique_ptr<DecodedInsn> decode_aliased(uint32_t raw);
uint32_t assemble(rust::Str text);
bool assemble_check(rust::Str text);
bool is_valid(const DecodedInsn& d);
uint16_t get_mnemonic(const DecodedInsn& d);
int8_t get_condition(const DecodedInsn& d);
uint32_t get_raw_value(const DecodedInsn& d);
uint32_t get_num_operands(const DecodedInsn& d);
uint8_t get_operand_type(const DecodedInsn& d, uint32_t idx);
uint16_t get_operand_reg(const DecodedInsn& d, uint32_t idx);
uint64_t get_operand_imm(const DecodedInsn& d, uint32_t idx);
int32_t get_operand_simm(const DecodedInsn& d, uint32_t idx);
uint16_t get_operand_mem_base(const DecodedInsn& d, uint32_t idx);
int32_t get_operand_mem_offset(const DecodedInsn& d, uint32_t idx);
uint8_t get_operand_mem_mode(const DecodedInsn& d, uint32_t idx);
uint8_t get_operand_shift_type(const DecodedInsn& d, uint32_t idx);
uint8_t get_operand_shift_amount(const DecodedInsn& d, uint32_t idx);
uint8_t get_operand_extend_type(const DecodedInsn& d, uint32_t idx);
uint8_t get_operand_extend_amount(const DecodedInsn& d, uint32_t idx);
rust::String insn_to_string(const DecodedInsn& d);
rust::String operand_to_string(const DecodedInsn& d, uint32_t idx);
rust::String mnemonic_name(uint16_t m);

// IR functions
std::unique_ptr<LiftedIr> ir_lift(uint32_t insn);
bool ir_is_valid(const LiftedIr& l);
uint32_t ir_num_ops(const LiftedIr& l);
uint8_t ir_op_opcode(const LiftedIr& l, uint32_t idx);
rust::String ir_op_to_string(const LiftedIr& l, uint32_t idx);
rust::String ir_to_string(const LiftedIr& l);
rust::String ir_opcode_name(uint8_t op);
std::unique_ptr<LiftedIr> ir_simplify(const LiftedIr& l);

// Branch recognizer
struct BranchInfoFfi {
    veda64::BranchInfo info;
};

std::unique_ptr<BranchInfoFfi> branch_recognize(rust::Slice<const uint32_t> insns, uint64_t address);
uint8_t  br_kind(const BranchInfoFfi& b);
uint8_t  br_consumed_bytes(const BranchInfoFfi& b);
bool     br_is_conditional(const BranchInfoFfi& b);
int8_t   br_condition(const BranchInfoFfi& b);
bool     br_destination_known(const BranchInfoFfi& b);
uint64_t br_destination(const BranchInfoFfi& b);
bool     br_has_pointer_load(const BranchInfoFfi& b);
uint64_t br_pointer_load_address(const BranchInfoFfi& b);
uint8_t  br_pointer_load_size(const BranchInfoFfi& b);
uint16_t br_target_register(const BranchInfoFfi& b);
bool     br_pac_authenticated(const BranchInfoFfi& b);
bool     br_has_fallthrough(const BranchInfoFfi& b);
uint64_t br_fallthrough(const BranchInfoFfi& b);
uint16_t br_test_register(const BranchInfoFfi& b);
uint8_t  br_test_bit(const BranchInfoFfi& b);

} // namespace veda64_ffi
