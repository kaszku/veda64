#pragma once

#ifndef VEDA64_STRINGS
#define VEDA64_STRINGS
#endif
#ifndef VEDA64_IR
#define VEDA64_IR
#endif
#include "veda64.hpp"
#include "veda64/ir.hpp"

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

} // namespace veda64_ffi
