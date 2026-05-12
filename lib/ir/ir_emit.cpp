// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski

#if defined(VEDA64_IR) && defined(VEDA64_CODEGEN)

#include "veda64/ir_emit.hpp"
#include <codegen/memory.hpp>
#include <format/control.hpp>

namespace veda64 {
namespace ir {

using codegen::XReg;

namespace {

// Resolve a VarNode to a physical X register. Constants are materialized
// via MOV into the supplied scratch register.
XReg to_reg(const VarNode& v, codegen::CodeGenerator& cg,
            const EmitContext& ctx, XReg scratch) {
    if (v.space == Space::CONST) {
        cg.mov(scratch, static_cast<uint64_t>(v.value));
        return scratch;
    }
    return ctx.resolve(v);
}

bool emit_cmp_cset(const Op& op, codegen::CodeGenerator& cg,
                   const EmitContext& ctx, Condition cc) {
    if (op.num_inputs != 2) return false;
    XReg a = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
    XReg b = to_reg(op.inputs[1], cg, ctx, ctx.scratch1);
    cg.cmp(a, b);
    cg.cset(ctx.resolve(op.output), cc);
    return true;
}

} // anonymous

bool emit(const Op& op, codegen::CodeGenerator& cg, const EmitContext& ctx) {
    auto bin_in = [&](XReg& a, XReg& b) -> bool {
        if (op.num_inputs != 2) return false;
        a = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
        b = to_reg(op.inputs[1], cg, ctx, ctx.scratch1);
        return true;
    };
    XReg a{0}, b{0};

    switch (op.opcode) {
    case Opcode::COPY: {
        if (op.num_inputs != 1) return false;
        XReg dst = ctx.resolve(op.output);
        if (op.inputs[0].space == Space::CONST)
            cg.mov(dst, static_cast<uint64_t>(op.inputs[0].value));
        else
            cg.mov(dst, ctx.resolve(op.inputs[0]));
        return true;
    }

    case Opcode::ADD:
        if (!bin_in(a, b)) return false;
        cg.add(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::SUB:
        if (!bin_in(a, b)) return false;
        cg.sub(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::MUL:
        if (!bin_in(a, b)) return false;
        cg.mul(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::SDIV:
        if (!bin_in(a, b)) return false;
        cg.sdiv(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::UDIV:
        if (!bin_in(a, b)) return false;
        cg.udiv(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::NEG:
        if (op.num_inputs != 1) return false;
        cg.neg(ctx.resolve(op.output),
               to_reg(op.inputs[0], cg, ctx, ctx.scratch0));
        return true;

    case Opcode::AND:
        if (!bin_in(a, b)) return false;
        cg.and_(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::OR:
        if (!bin_in(a, b)) return false;
        cg.orr(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::XOR:
        if (!bin_in(a, b)) return false;
        cg.eor(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::NOT:
        if (op.num_inputs != 1) return false;
        cg.mvn(ctx.resolve(op.output),
               to_reg(op.inputs[0], cg, ctx, ctx.scratch0));
        return true;

    case Opcode::SHL:
        if (!bin_in(a, b)) return false;
        cg.lsl(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::SHR:
        if (!bin_in(a, b)) return false;
        cg.lsr(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::SAR:
        if (!bin_in(a, b)) return false;
        cg.asr(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::ROR:
        if (!bin_in(a, b)) return false;
        cg.ror(ctx.resolve(op.output), a, b);
        return true;

    case Opcode::CLZ:
        if (op.num_inputs != 1) return false;
        cg.clz(ctx.resolve(op.output),
               to_reg(op.inputs[0], cg, ctx, ctx.scratch0));
        return true;
    case Opcode::BITREV:
        if (op.num_inputs != 1) return false;
        cg.rbit(ctx.resolve(op.output),
                to_reg(op.inputs[0], cg, ctx, ctx.scratch0));
        return true;
    case Opcode::POPCNT:
    case Opcode::CTZ:
        // No direct scalar AArch64 instruction.
        return false;

    case Opcode::CMP_EQ:  return emit_cmp_cset(op, cg, ctx, Condition::EQ);
    case Opcode::CMP_NE:  return emit_cmp_cset(op, cg, ctx, Condition::NE);
    case Opcode::CMP_SLT: return emit_cmp_cset(op, cg, ctx, Condition::LT);
    case Opcode::CMP_ULT: return emit_cmp_cset(op, cg, ctx, Condition::CC);
    case Opcode::CMP_SLE: return emit_cmp_cset(op, cg, ctx, Condition::LE);
    case Opcode::CMP_ULE: return emit_cmp_cset(op, cg, ctx, Condition::LS);

    case Opcode::BRANCH: {
        if (op.num_inputs < 1) return false;
        int32_t imm26 = static_cast<int32_t>(op.inputs[0].value >> 2);
        cg.emit_raw(format::control::encode_b_only_branch_imm(imm26));
        return true;
    }
    case Opcode::CALL: {
        if (op.num_inputs < 1) return false;
        int32_t imm26 = static_cast<int32_t>(op.inputs[0].value >> 2);
        cg.emit_raw(format::control::encode_bl_only_branch_imm(imm26));
        return true;
    }
    case Opcode::CBRANCH: {
        if (op.num_inputs != 2) return false;
        XReg cond = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
        int32_t imm19 = static_cast<int32_t>(op.inputs[1].value >> 2);
        cg.emit_raw(format::control::encode_cbnz_64_compbranch(cond.idx, imm19));
        return true;
    }
    case Opcode::RET:
        cg.ret();
        return true;

    case Opcode::LOAD: {
        if (op.num_inputs < 1) return false;
        XReg base = ctx.resolve(op.inputs[0]);
        int32_t offset = (op.num_inputs >= 2 && op.inputs[1].space == Space::CONST)
            ? static_cast<int32_t>(op.inputs[1].value) : 0;
        cg.ldr(ctx.resolve(op.output), codegen::ptr(base, offset));
        return true;
    }
    case Opcode::STORE: {
        if (op.num_inputs < 2) return false;
        XReg val = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
        XReg base = ctx.resolve(op.inputs[1]);
        int32_t offset = (op.num_inputs >= 3 && op.inputs[2].space == Space::CONST)
            ? static_cast<int32_t>(op.inputs[2].value) : 0;
        cg.str(val, codegen::ptr(base, offset));
        return true;
    }

    case Opcode::ADD_CARRY:
        if (!bin_in(a, b)) return false;
        cg.adcs(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::SUB_CARRY:
        if (!bin_in(a, b)) return false;
        cg.sbcs(ctx.resolve(op.output), a, b);
        return true;
    case Opcode::CARRY_ADD:
        cg.cset(ctx.resolve(op.output), Condition::CS);
        return true;
    case Opcode::CARRY_SUB:
        cg.cset(ctx.resolve(op.output), Condition::CC);
        return true;
    case Opcode::OVERFLOW_ADD:
    case Opcode::OVERFLOW_SUB:
        cg.cset(ctx.resolve(op.output), Condition::VS);
        return true;

    case Opcode::NOP:
        cg.nop();
        return true;

    default:
        return false;
    }
}

bool emit(const Lifted& l, codegen::CodeGenerator& cg, const EmitContext& ctx) {
    for (const auto& op : l.ops) {
        if (!emit(op, cg, ctx)) return false;
    }
    return true;
}

} // namespace ir
} // namespace veda64

#endif // VEDA64_IR && VEDA64_CODEGEN
