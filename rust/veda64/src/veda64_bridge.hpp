#pragma once

#define VEDA64_STRINGS
#include "veda64.hpp"

#include "rust/cxx.h"
#include <memory>

namespace veda64_ffi {

struct DecodedInsn {
    bool valid;
    veda64::Instruction insn;
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

} // namespace veda64_ffi
