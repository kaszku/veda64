// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_IR

#include "veda64/ir.hpp"
#include "veda64.hpp"
#include <sstream>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <cstring>

namespace veda64::ir {

// Forward declaration from ir_lift.cpp
std::optional<Lifted> lift_from_instruction(const Instruction& insn, IrDetail detail);

std::optional<Lifted> lift(uint32_t raw, IrDetail detail) {
    auto decoded = decode(raw);
    if (!decoded) return std::nullopt;
    return lift(*decoded, detail);
}

std::optional<Lifted> lift(const Instruction& insn, IrDetail detail) {
    return lift_from_instruction(insn, detail);
}

static bool is_temp(const VarNode& v) { return v.space == Space::Temp; }

static void replace_input(VarNode& v, const std::unordered_map<uint16_t, VarNode>& subs) {
    if (is_temp(v)) {
        auto it = subs.find(v.offset);
        if (it != subs.end()) v = it->second;
    }
}

Lifted simplify(const Lifted& l) {
    // Pass 1: Copy propagation -- build substitution map for temp = copy X
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

    // Pass 2: Output folding -- if dest = copy temp, and temp defined by exactly
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

#ifdef VEDA64_STRINGS

const char* opcode_names[] = {
    "copy", "load", "store",
    "add", "sub", "mul", "sdiv", "udiv", "neg",
    "and", "or", "xor", "not", "shl", "shr", "sar", "ror",
    "cmp_eq", "cmp_ne", "cmp_slt", "cmp_ult", "cmp_sle", "cmp_ule",
    "zext", "sext", "trunc", "int2float", "float2int", "float2float",
    "fadd", "fsub", "fmul", "fdiv", "fsqrt", "fneg", "fabs",
    "branch", "cbranch", "call", "ret",
    "add_carry", "sub_carry", "carry_add", "carry_sub", "overflow_add", "overflow_sub",
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

std::string to_string(const VarNode& v) {
    if (v.space == Space::Const) {
        auto s = std::to_string(v.value);
        if (v.size > 0) s += ":" + std::to_string(v.size);
        return s;
    }
    switch (v.space) {
    case Space::Temp: {
        auto s = "tmp" + std::to_string(v.offset);
        if (v.size > 0) s += ":" + std::to_string(v.size);
        return s;
    }
    case Space::GPR:
        if (v.offset == 31) return (v.size == 8) ? "sp" : "wsp";
        return (v.size == 8 ? "x" : "w") + std::to_string(v.offset);
    case Space::SIMD:
        if (v.size <= 2) return "h" + std::to_string(v.offset);
        if (v.size == 4) return "s" + std::to_string(v.offset);
        if (v.size == 8) return "d" + std::to_string(v.offset);
        return "v" + std::to_string(v.offset);
    case Space::SVE_Z: return "z" + std::to_string(v.offset);
    case Space::SVE_P: return "p" + std::to_string(v.offset);
    case Space::Flags:
        switch (v.offset) {
        case 0: return "N";
        case 1: return "Z";
        case 2: return "C";
        case 3: return "V";
        default: return "flags";
        }
    case Space::RAM: {
        std::string s = "mem";
        if (v.size > 0) s += ":" + std::to_string(v.size);
        return s;
    }
    default: return "?";
    }
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

#endif // VEDA64_STRINGS

// ============================================================
// AST (Expression Tree) layer
// ============================================================

ExprPtr Expr::make_var(VarNode v) {
    auto e = std::make_shared<Expr>();
    e->kind = Kind::Var;
    e->var = v;
    e->size = v.size;
    return e;
}

ExprPtr Expr::make_const(int64_t val, uint8_t sz) {
    auto e = std::make_shared<Expr>();
    e->kind = Kind::Const;
    e->var = VarNode::constant(val, sz);
    e->size = sz;
    return e;
}

ExprPtr Expr::make_op(Opcode opc, uint8_t sz, std::vector<ExprPtr> args) {
    auto e = std::make_shared<Expr>();
    e->kind = Kind::Op;
    e->opcode = opc;
    e->children = std::move(args);
    e->size = sz;
    return e;
}

Ast to_ast(const Lifted& l) {
    auto sim = simplify(l);

    // Build def map: temp offset -> op index
    std::unordered_map<uint16_t, size_t> temp_def;
    for (size_t i = 0; i < sim.ops.size(); ++i) {
        if (is_temp(sim.ops[i].output))
            temp_def[sim.ops[i].output.offset] = i;
    }

    // Expr cache for shared subexpressions
    std::unordered_map<uint16_t, ExprPtr> expr_cache;

    // Recursive builder
    std::function<ExprPtr(const VarNode&)> build_expr;
    build_expr = [&](const VarNode& v) -> ExprPtr {
        if (v.space == Space::Const)
            return Expr::make_const(v.value, v.size);
        if (v.space != Space::Temp)
            return Expr::make_var(v);
        // Temp: check cache
        auto cit = expr_cache.find(v.offset);
        if (cit != expr_cache.end()) return cit->second;
        auto dit = temp_def.find(v.offset);
        if (dit == temp_def.end())
            return Expr::make_var(v); // undefined temp, shouldn't happen
        auto& op = sim.ops[dit->second];
        std::vector<ExprPtr> children;
        for (uint8_t i = 0; i < op.num_inputs; ++i)
            children.push_back(build_expr(op.inputs[i]));
        auto result = Expr::make_op(op.opcode, op.output.size, std::move(children));
        expr_cache[v.offset] = result;
        return result;
    };

    Ast ast;
    for (auto& op : sim.ops) {
        if (is_temp(op.output)) continue; // temps are inlined

        Effect eff;
        eff.size = op.output.size;

        if (op.opcode == Opcode::STORE) {
            eff.kind = Effect::Kind::Store;
            eff.expr = (op.num_inputs >= 1) ? build_expr(op.inputs[0]) : nullptr;
            eff.value = (op.num_inputs >= 2) ? build_expr(op.inputs[1]) : nullptr;
            eff.size = op.output.size;
        } else if (op.opcode == Opcode::BRANCH) {
            eff.kind = Effect::Kind::Branch;
            eff.expr = (op.num_inputs >= 1) ? build_expr(op.inputs[0]) : nullptr;
        } else if (op.opcode == Opcode::CBRANCH) {
            eff.kind = Effect::Kind::CBranch;
            eff.expr = (op.num_inputs >= 1) ? build_expr(op.inputs[0]) : nullptr;
            eff.value = (op.num_inputs >= 2) ? build_expr(op.inputs[1]) : nullptr;
        } else if (op.opcode == Opcode::CALL) {
            eff.kind = Effect::Kind::Call;
            eff.expr = (op.num_inputs >= 1) ? build_expr(op.inputs[0]) : nullptr;
        } else if (op.opcode == Opcode::NOP || op.opcode == Opcode::BARRIER) {
            eff.kind = Effect::Kind::Nop;
        } else {
            // Assign: build expression from this op's inputs
            eff.kind = Effect::Kind::Assign;
            eff.dest = op.output;
            // For COPY with 3 inputs (CSEL), rewrite as SELECT(cond, true, false)
            if (op.opcode == Opcode::COPY && op.num_inputs == 3) {
                std::vector<ExprPtr> args;
                args.push_back(build_expr(op.inputs[2])); // condition first
                args.push_back(build_expr(op.inputs[0])); // true value
                args.push_back(build_expr(op.inputs[1])); // false value
                eff.expr = Expr::make_op(Opcode::COPY, op.output.size, std::move(args));
            } else if (op.opcode == Opcode::COPY && op.num_inputs == 1) {
                eff.expr = build_expr(op.inputs[0]);
            } else {
                std::vector<ExprPtr> args;
                for (uint8_t i = 0; i < op.num_inputs; ++i)
                    args.push_back(build_expr(op.inputs[i]));
                eff.expr = Expr::make_op(op.opcode, op.output.size, std::move(args));
            }
        }
        ast.effects.push_back(std::move(eff));
    }
    return ast;
}

std::optional<Ast> lift_ast(uint32_t insn, IrDetail detail) {
    auto l = lift(insn, detail);
    if (!l) return std::nullopt;
    return to_ast(*l);
}

std::optional<Ast> lift_ast(const Instruction& insn, IrDetail detail) {
    auto l = lift(insn, detail);
    if (!l) return std::nullopt;
    return to_ast(*l);
}

#ifdef VEDA64_STRINGS

std::string to_string(const Expr& e) {
    switch (e.kind) {
    case Expr::Kind::Var:
        return to_string(e.var);
    case Expr::Kind::Const: {
        return std::to_string(e.var.value);
    }
    case Expr::Kind::Op: {
        std::string s = opcode_name(e.opcode) + "(";
        for (size_t i = 0; i < e.children.size(); ++i) {
            if (i > 0) s += ", ";
            s += to_string(*e.children[i]);
        }
        s += ")";
        return s;
    }
    }
    return "?";
}

std::string to_string(const Effect& eff) {
    switch (eff.kind) {
    case Effect::Kind::Assign:
        return to_string(eff.dest) + " <- " + (eff.expr ? to_string(*eff.expr) : "?");
    case Effect::Kind::Store:
        return "store " + (eff.expr ? to_string(*eff.expr) : "?") + ", " + (eff.value ? to_string(*eff.value) : "?");
    case Effect::Kind::Branch:
        return "branch " + (eff.expr ? to_string(*eff.expr) : "?");
    case Effect::Kind::CBranch:
        return "cbranch " + (eff.expr ? to_string(*eff.expr) : "?") + ", " + (eff.value ? to_string(*eff.value) : "?");
    case Effect::Kind::Call:
        return "call " + (eff.expr ? to_string(*eff.expr) : "?");
    case Effect::Kind::Nop:
        return "nop";
    }
    return "?";
}

std::string to_string(const Ast& ast) {
    std::string s;
    for (size_t i = 0; i < ast.effects.size(); ++i) {
        if (i > 0) s += "\n";
        s += to_string(ast.effects[i]);
    }
    return s;
}

#endif // VEDA64_STRINGS

// ============================================================
// Interpreter implementation
// ============================================================

static uint64_t size_mask(uint8_t size) {
    if (size >= 8) return ~0ULL;
    return (1ULL << (size * 8)) - 1;
}

uint64_t Context::read_gpr(uint16_t reg, uint8_t size) const {
    if (reg == 31) return gpr[31]; // SP or XZR depending on context, use SP here
    if (reg > 31) return 0;
    return gpr[reg] & size_mask(size);
}

void Context::write_gpr(uint16_t reg, uint64_t val, uint8_t size) {
    if (reg > 31) return;
    if (size <= 4) val &= 0xFFFFFFFFULL; // 32-bit write zero-extends
    gpr[reg] = val & size_mask(size);
}

uint64_t Context::read_mem(uint64_t addr, uint8_t size) const {
    if (!memory || addr + size > memory_size) return 0;
    uint64_t val = 0;
    for (uint8_t i = 0; i < size && i < 8; ++i)
        val |= (uint64_t)memory[addr + i] << (i * 8);
    return val;
}

void Context::write_mem(uint64_t addr, uint64_t val, uint8_t size) {
    if (!memory || addr + size > memory_size) return;
    for (uint8_t i = 0; i < size && i < 8; ++i)
        memory[addr + i] = (uint8_t)(val >> (i * 8));
}

static uint64_t sign_extend(uint64_t val, uint8_t from_size) {
    if (from_size >= 8) return val;
    uint64_t sign_bit = 1ULL << (from_size * 8 - 1);
    if (val & sign_bit) return val | ~((1ULL << (from_size * 8)) - 1);
    return val;
}

static uint64_t fp_binop(Opcode opc, uint64_t a, uint64_t b, uint8_t size) {
    if (size == 4) {
        float fa, fb, fr;
        memcpy(&fa, &a, 4); memcpy(&fb, &b, 4);
        switch (opc) {
        case Opcode::FADD: fr = fa + fb; break;
        case Opcode::FSUB: fr = fa - fb; break;
        case Opcode::FMUL: fr = fa * fb; break;
        case Opcode::FDIV: fr = fa / fb; break;
        default: fr = 0; break;
        }
        uint64_t r = 0; memcpy(&r, &fr, 4); return r;
    } else {
        double da, db, dr;
        memcpy(&da, &a, 8); memcpy(&db, &b, 8);
        switch (opc) {
        case Opcode::FADD: dr = da + db; break;
        case Opcode::FSUB: dr = da - db; break;
        case Opcode::FMUL: dr = da * db; break;
        case Opcode::FDIV: dr = da / db; break;
        default: dr = 0; break;
        }
        uint64_t r; memcpy(&r, &dr, 8); return r;
    }
}

static uint64_t fp_unaryop(Opcode opc, uint64_t a, uint8_t size) {
    if (size == 4) {
        float fa, fr;
        memcpy(&fa, &a, 4);
        switch (opc) {
        case Opcode::FNEG: fr = -fa; break;
        case Opcode::FABS: fr = fa < 0 ? -fa : fa; break;
        case Opcode::FSQRT: fr = sqrtf(fa); break;
        default: fr = 0; break;
        }
        uint64_t r = 0; memcpy(&r, &fr, 4); return r;
    } else {
        double da, dr;
        memcpy(&da, &a, 8);
        switch (opc) {
        case Opcode::FNEG: dr = -da; break;
        case Opcode::FABS: dr = da < 0 ? -da : da; break;
        case Opcode::FSQRT: dr = sqrt(da); break;
        default: dr = 0; break;
        }
        uint64_t r; memcpy(&r, &dr, 8); return r;
    }
}

uint64_t eval_expr(const Context& ctx, const Expr& e) {
    switch (e.kind) {
    case Expr::Kind::Const:
        return (uint64_t)e.var.value & size_mask(e.size ? e.size : e.var.size);
    case Expr::Kind::Var:
        switch (e.var.space) {
        case Space::GPR: return ctx.read_gpr(e.var.offset, e.var.size);
        case Space::Flags: return ctx.flags[e.var.offset] ? 1ULL : 0ULL;
        case Space::SIMD: {
            uint64_t v = 0;
            uint8_t sz = e.var.size < 8 ? e.var.size : 8;
            for (uint8_t i = 0; i < sz; ++i) v |= (uint64_t)ctx.simd[e.var.offset][i] << (i*8);
            return v;
        }
        default: return 0;
        }
    case Expr::Kind::Op: break;
    }

    // Op case: evaluate children
    auto nc = e.children.size();
    uint64_t c[3] = {};
    for (size_t i = 0; i < nc && i < 3; ++i)
        c[i] = eval_expr(ctx, *e.children[i]);
    uint64_t mask = size_mask(e.size);
    uint8_t bits = e.size * 8;

    switch (e.opcode) {
    case Opcode::COPY:
        if (nc == 1) return c[0] & mask;
        if (nc == 3) return (c[0] & 1) ? c[1] : c[2]; // CSEL
        return c[0];
    case Opcode::ADD: return (c[0] + c[1]) & mask;
    case Opcode::SUB: return (c[0] - c[1]) & mask;
    case Opcode::MUL: return (c[0] * c[1]) & mask;
    case Opcode::SDIV: {
        int64_t sa = (int64_t)sign_extend(c[0], e.size);
        int64_t sb = (int64_t)sign_extend(c[1], e.size);
        return sb ? ((uint64_t)(sa / sb) & mask) : 0;
    }
    case Opcode::UDIV: return c[1] ? ((c[0] / c[1]) & mask) : 0;
    case Opcode::NEG: return ((~c[0] + 1) & mask);
    case Opcode::AND: return (c[0] & c[1]) & mask;
    case Opcode::OR:  return (c[0] | c[1]) & mask;
    case Opcode::XOR: return (c[0] ^ c[1]) & mask;
    case Opcode::NOT: return (~c[0]) & mask;
    case Opcode::SHL: {
        uint8_t csz = nc > 0 && e.children[0]->size > e.size ? e.children[0]->size : e.size;
        uint8_t cbits = csz * 8;
        return (c[0] << (c[1] % cbits)) & mask;
    }
    case Opcode::SHR: {
        uint8_t csz = nc > 0 && e.children[0]->size > e.size ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        uint8_t cbits = csz * 8;
        return ((c[0] & cmask) >> (c[1] % cbits)) & mask;
    }
    case Opcode::SAR: {
        uint8_t csz = nc > 0 && e.children[0]->size > e.size ? e.children[0]->size : e.size;
        uint8_t cbits = csz * 8;
        int64_t sv = (int64_t)sign_extend(c[0], csz);
        return ((uint64_t)(sv >> (c[1] % cbits))) & mask;
    }
    case Opcode::ROR: {
        uint8_t csz = nc > 0 && e.children[0]->size > e.size ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        uint8_t cbits = csz * 8;
        auto sh = c[1] % cbits;
        auto v = c[0] & cmask;
        return ((v >> sh) | (v << (cbits - sh))) & mask;
    }
    case Opcode::CMP_EQ: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        return (c[0] & cmask) == (c[1] & cmask) ? 1 : 0;
    }
    case Opcode::CMP_NE: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        return (c[0] & cmask) != (c[1] & cmask) ? 1 : 0;
    }
    case Opcode::CMP_SLT: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        return (int64_t)sign_extend(c[0],csz) <  (int64_t)sign_extend(c[1],csz) ? 1 : 0;
    }
    case Opcode::CMP_ULT: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        return (c[0] & cmask) <  (c[1] & cmask) ? 1 : 0;
    }
    case Opcode::CMP_SLE: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        return (int64_t)sign_extend(c[0],csz) <= (int64_t)sign_extend(c[1],csz) ? 1 : 0;
    }
    case Opcode::CMP_ULE: {
        uint8_t csz = nc > 0 ? e.children[0]->size : e.size;
        uint64_t cmask = size_mask(csz);
        return (c[0] & cmask) <= (c[1] & cmask) ? 1 : 0;
    }
    case Opcode::ZEXT: return c[0] & mask;
    case Opcode::SEXT: {
        uint8_t child_sz = e.children[0]->size;
        return sign_extend(c[0], child_sz) & mask;
    }
    case Opcode::TRUNC: return c[0] & mask;
    case Opcode::LOAD: return ctx.read_mem(c[0], e.size);
    case Opcode::FADD: case Opcode::FSUB:
    case Opcode::FMUL: case Opcode::FDIV:
        return fp_binop(e.opcode, c[0], c[1], e.size);
    case Opcode::FNEG: case Opcode::FABS: case Opcode::FSQRT:
        return fp_unaryop(e.opcode, c[0], e.size);
    default: return 0;
    }
}

void execute_ast(Context& ctx, const Ast& ast) {
    bool branch_taken = false;
    for (auto& eff : ast.effects) {
        switch (eff.kind) {
        case Effect::Kind::Assign: {
            uint64_t val = eff.expr ? eval_expr(ctx, *eff.expr) : 0;
            switch (eff.dest.space) {
            case Space::GPR: ctx.write_gpr(eff.dest.offset, val, eff.dest.size); break;
            case Space::Flags: ctx.flags[eff.dest.offset] = val ? 1 : 0; break;
            case Space::SIMD: {
                uint8_t sz = eff.dest.size < 16 ? eff.dest.size : 8;
                for (uint8_t i = 0; i < sz && i < 8; ++i)
                    ctx.simd[eff.dest.offset][i] = (uint8_t)(val >> (i*8));
                break;
            }
            default: break;
            }
            break;
        }
        case Effect::Kind::Store: {
            uint64_t addr = eff.expr ? eval_expr(ctx, *eff.expr) : 0;
            uint64_t val = eff.value ? eval_expr(ctx, *eff.value) : 0;
            ctx.write_mem(addr, val, eff.size);
            break;
        }
        case Effect::Kind::Branch:
            ctx.pc = eff.expr ? eval_expr(ctx, *eff.expr) : 0;
            branch_taken = true;
            break;
        case Effect::Kind::CBranch:
            if (eff.expr && (eval_expr(ctx, *eff.expr) & 1)) {
                ctx.pc = eff.value ? eval_expr(ctx, *eff.value) : 0;
                branch_taken = true;
            }
            break;
        case Effect::Kind::Call:
            ctx.pc = eff.expr ? eval_expr(ctx, *eff.expr) : 0;
            branch_taken = true;
            break;
        case Effect::Kind::Nop: break;
        }
    }
    (void)branch_taken;
}

void execute(Context& ctx, uint32_t insn) {
    auto ast = lift_ast(insn, IrDetail::Expanded);
    if (!ast) return;
    uint64_t old_pc = ctx.pc;
    execute_ast(ctx, *ast);
    if (ctx.pc == old_pc) ctx.pc += 4;
    else ctx.pc += old_pc; // Branch offsets are PC-relative
}

} // namespace veda64::ir

#endif // VEDA64_IR
