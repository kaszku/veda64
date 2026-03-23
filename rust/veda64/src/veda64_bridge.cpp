#include "veda64_bridge.hpp"

namespace veda64_ffi {

std::unique_ptr<DecodedInsn> decode(uint32_t raw) {
    auto result = std::make_unique<DecodedInsn>();
    auto opt = veda64::decode(raw);
    if (opt.has_value()) {
        result->valid = true;
        result->insn = std::move(*opt);
    } else {
        result->valid = false;
    }
    return result;
}

bool is_valid(const DecodedInsn& d) { return d.valid; }

uint16_t get_mnemonic(const DecodedInsn& d) {
    return static_cast<uint16_t>(d.insn.mnemonic);
}

int8_t get_condition(const DecodedInsn& d) {
    return static_cast<int8_t>(d.insn.condition);
}

uint32_t get_raw_value(const DecodedInsn& d) { return d.insn.raw_value; }

uint32_t get_num_operands(const DecodedInsn& d) {
    return static_cast<uint32_t>(d.insn.operands.size());
}

static const veda64::Operand& op_at(const DecodedInsn& d, uint32_t idx) {
    return d.insn.operands[idx];
}

uint8_t get_operand_type(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint8_t>(op_at(d, idx).type);
}

uint16_t get_operand_reg(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint16_t>(op_at(d, idx).r.reg);
}

uint64_t get_operand_imm(const DecodedInsn& d, uint32_t idx) {
    return op_at(d, idx).iv.value;
}

int32_t get_operand_simm(const DecodedInsn& d, uint32_t idx) {
    return op_at(d, idx).si.offset;
}

uint16_t get_operand_mem_base(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint16_t>(op_at(d, idx).mem.base);
}

int32_t get_operand_mem_offset(const DecodedInsn& d, uint32_t idx) {
    return op_at(d, idx).mem.offset;
}

uint8_t get_operand_mem_mode(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint8_t>(op_at(d, idx).mem.mode);
}

uint8_t get_operand_shift_type(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint8_t>(op_at(d, idx).sh.shift_type);
}

uint8_t get_operand_shift_amount(const DecodedInsn& d, uint32_t idx) {
    return op_at(d, idx).sh.amount;
}

uint8_t get_operand_extend_type(const DecodedInsn& d, uint32_t idx) {
    return static_cast<uint8_t>(op_at(d, idx).ext.ext_type);
}

uint8_t get_operand_extend_amount(const DecodedInsn& d, uint32_t idx) {
    return op_at(d, idx).ext.amount;
}

rust::String insn_to_string(const DecodedInsn& d) {
    if (!d.valid) return rust::String();
    return rust::String(d.insn.to_string());
}

rust::String operand_to_string(const DecodedInsn& d, uint32_t idx) {
    if (idx >= d.insn.operands.size()) return rust::String();
    return rust::String(op_at(d, idx).to_string());
}

rust::String mnemonic_name(uint16_t m) {
    return rust::String(veda64::mnemonic_to_string(static_cast<veda64::Mnemonic>(m)));
}

// IR functions
std::unique_ptr<LiftedIr> ir_lift(uint32_t insn) {
    auto result = std::make_unique<LiftedIr>();
    auto opt = veda64::ir::lift(insn);
    if (opt.has_value()) {
        result->valid = true;
        result->ops = std::move(opt->ops);
    } else {
        result->valid = false;
    }
    return result;
}

bool ir_is_valid(const LiftedIr& l) { return l.valid; }

uint32_t ir_num_ops(const LiftedIr& l) {
    return static_cast<uint32_t>(l.ops.size());
}

uint8_t ir_op_opcode(const LiftedIr& l, uint32_t idx) {
    return static_cast<uint8_t>(l.ops[idx].opcode);
}

rust::String ir_op_to_string(const LiftedIr& l, uint32_t idx) {
    if (idx >= l.ops.size()) return rust::String();
    return rust::String(veda64::ir::to_string(l.ops[idx]));
}

rust::String ir_to_string(const LiftedIr& l) {
    if (!l.valid) return rust::String();
    veda64::ir::Lifted lifted;
    lifted.ops = l.ops;
    return rust::String(veda64::ir::to_string(lifted));
}

rust::String ir_opcode_name(uint8_t op) {
    return rust::String(veda64::ir::opcode_name(static_cast<veda64::ir::Opcode>(op)));
}

std::unique_ptr<LiftedIr> ir_simplify(const LiftedIr& l) {
    auto result = std::make_unique<LiftedIr>();
    veda64::ir::Lifted lifted;
    lifted.ops = l.ops;
    auto simplified = veda64::ir::simplify(lifted);
    result->valid = true;
    result->ops = std::move(simplified.ops);
    return result;
}

} // namespace veda64_ffi
