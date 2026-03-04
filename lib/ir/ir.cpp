// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifndef VEDA64_NO_IR

#include "veda64/ir.hpp"
#include <sstream>
#include <unordered_map>

namespace veda64::ir {

// Forward declaration from ir_lift.cpp
std::optional<Lifted> lift_from_table(uint32_t insn);

std::optional<Lifted> lift(uint32_t insn) {
    return lift_from_table(insn);
}

std::optional<Lifted> lift(const Instruction& insn) {
    return lift(insn.raw_value);
}

static bool is_temp(const VarNode& v) { return v.space == Space::Temp; }

static bool varnode_eq(const VarNode& a, const VarNode& b) {
    return a.space == b.space && a.offset == b.offset && a.size == b.size && a.value == b.value;
}

static void replace_input(VarNode& v, const std::unordered_map<uint16_t, VarNode>& subs) {
    if (is_temp(v)) {
        auto it = subs.find(v.offset);
        if (it != subs.end()) v = it->second;
    }
}

Lifted simplify(const Lifted& l) {
    // Pass 1: Copy propagation — build substitution map for temp = copy X
    std::unordered_map<uint16_t, VarNode> subs;
    std::vector<Op> ops;
    ops.reserve(l.ops.size());

    for (auto& op : l.ops) {
        Op o = op;
        // Substitute inputs
        for (uint8_t i = 0; i < o.num_inputs; ++i)
            replace_input(o.inputs[i], subs);

        // If temp = copy single_input, record substitution and skip
        if (o.opcode == Opcode::COPY && is_temp(o.output) && o.num_inputs == 1) {
            subs[o.output.offset] = o.inputs[0];
            continue;
        }
        ops.push_back(o);
    }

    // Pass 2: Output folding — if dest = copy temp, and temp defined by exactly
    // one op with one use, fold the defining op's opcode+inputs into dest
    // Count temp references
    std::unordered_map<uint16_t, int> temp_uses;
    std::unordered_map<uint16_t, size_t> temp_def; // temp -> index in ops
    for (size_t i = 0; i < ops.size(); ++i) {
        auto& o = ops[i];
        if (is_temp(o.output))
            temp_def[o.output.offset] = i;
        for (uint8_t j = 0; j < o.num_inputs; ++j)
            if (is_temp(o.inputs[j]))
                temp_uses[o.inputs[j].offset]++;
    }

    std::vector<bool> dead(ops.size(), false);
    for (size_t i = 0; i < ops.size(); ++i) {
        auto& o = ops[i];
        // dest = copy temp (single input, temp used once)
        if (o.opcode == Opcode::COPY && o.num_inputs == 1 && is_temp(o.inputs[0])) {
            uint16_t tidx = o.inputs[0].offset;
            if (temp_uses[tidx] == 1) {
                auto dit = temp_def.find(tidx);
                if (dit != temp_def.end() && !dead[dit->second]) {
                    auto& def_op = ops[dit->second];
                    // Fold: take the defining op's opcode and inputs, but our output
                    o.opcode = def_op.opcode;
                    o.num_inputs = def_op.num_inputs;
                    for (uint8_t k = 0; k < def_op.num_inputs; ++k)
                        o.inputs[k] = def_op.inputs[k];
                    dead[dit->second] = true;
                }
            }
        }
    }

    // Pass 3: Remove dead ops (folded defining ops and unused temp writes)
    // Recount temp uses after folding
    temp_uses.clear();
    for (size_t i = 0; i < ops.size(); ++i) {
        if (dead[i]) continue;
        auto& o = ops[i];
        for (uint8_t j = 0; j < o.num_inputs; ++j)
            if (is_temp(o.inputs[j]))
                temp_uses[o.inputs[j].offset]++;
    }
    // Mark ops writing to unused temps as dead
    for (size_t i = 0; i < ops.size(); ++i) {
        if (dead[i]) continue;
        auto& o = ops[i];
        if (is_temp(o.output) && temp_uses.find(o.output.offset) == temp_uses.end())
            dead[i] = true;
    }

    Lifted result;
    for (size_t i = 0; i < ops.size(); ++i) {
        if (!dead[i]) result.ops.push_back(ops[i]);
    }
    return result;
}

#ifndef VEDA64_NO_STRINGS

const char* opcode_names[] = {
    "copy", "load", "store",
    "add", "sub", "mul", "sdiv", "udiv", "neg",
    "and", "or", "xor", "not", "shl", "shr", "sar", "ror",
    "cmp_eq", "cmp_ne", "cmp_slt", "cmp_ult", "cmp_sle", "cmp_ule",
    "zext", "sext", "trunc", "int2float", "float2int", "float2float",
    "fadd", "fsub", "fmul", "fdiv", "fsqrt", "fneg", "fabs",
    "branch", "cbranch", "call", "ret",
    "add_carry", "sub_carry", "flag_read", "flag_write",
    "extract", "insert", "concat",
    "vextract_elem", "vinsert_elem", "vbroadcast",
    "barrier", "nop", "undef",
};

std::string opcode_name(Opcode op) {
    auto idx = static_cast<size_t>(op);
    if (idx < sizeof(opcode_names) / sizeof(opcode_names[0]))
        return opcode_names[idx];
    return "???";
}

static const char* space_names[] = {
    "const", "t", "gpr", "simd", "z", "p", "sys", "flags", "ram"
};

std::string to_string(const VarNode& v) {
    std::string s;
    if (v.space == Space::Const) {
        s = std::to_string(v.value);
        if (v.size > 0) s += ":" + std::to_string(v.size);
        return s;
    }
    auto si = static_cast<size_t>(v.space);
    if (si < sizeof(space_names) / sizeof(space_names[0]))
        s = space_names[si];
    else
        s = "?";
    s += "[" + std::to_string(v.offset) + "]";
    if (v.size > 0) s += ":" + std::to_string(v.size);
    return s;
}

std::string to_string(const Op& op) {
    std::string s;
    // Output
    if (op.output.space != Space::Const || op.output.size > 0) {
        s += to_string(op.output) + " = ";
    }
    s += opcode_name(op.opcode);
    for (uint8_t i = 0; i < op.num_inputs; ++i) {
        s += (i == 0) ? " " : ", ";
        s += to_string(op.inputs[i]);
    }
    return s;
}

std::string to_string(const Lifted& l) {
    std::string s;
    for (size_t i = 0; i < l.ops.size(); ++i) {
        if (i > 0) s += "\n";
        s += to_string(l.ops[i]);
    }
    return s;
}

#endif // !VEDA64_NO_STRINGS

} // namespace veda64::ir

#endif // !VEDA64_NO_IR
