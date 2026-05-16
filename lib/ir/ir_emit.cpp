// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski

#if defined(VEDA64_IR) && defined(VEDA64_CODEGEN)

#include "veda64/ir_emit.hpp"
#include <codegen/memory.hpp>
#include <format/control.hpp>

namespace veda64 {
namespace ir {

using codegen::XReg;
using codegen::WReg;

namespace {

// A VarNode is 32-bit (W view) when its size is 1..4 bytes. size == 0 means
// "unspecified" and is treated as the natural 64-bit width.
bool is_w(const VarNode& v) { return v.size != 0 && v.size <= 4; }

WReg w_of(XReg r) { return WReg{r.idx, r.sp}; }

// Resolve a VarNode to a physical X register. Constants are materialized
// via MOV into the supplied scratch register. NOTE: callers that can use an
// immediate instruction form must avoid this for Space::CONST so that the
// scratch register (default x16/x17, frequently live in real code) is not
// clobbered. See Bug B.
XReg to_reg(const VarNode& v, codegen::CodeGenerator& cg,
            const EmitContext& ctx, XReg scratch) {
    if (v.space == Space::CONST) {
        cg.mov(scratch, static_cast<uint64_t>(v.value));
        return scratch;
    }
    return ctx.resolve(v);
}

// True if `value` is encodable as an AArch64 add/sub 12-bit immediate
// (optionally shifted left by 12). On success fills imm12/lsl12 and reports
// via `negate` whether the sign must flip (add<->sub).
bool addsub_imm(int64_t value, uint32_t& imm12, bool& lsl12, bool& negate) {
    negate = value < 0;
    uint64_t u = negate ? static_cast<uint64_t>(-value)
                        : static_cast<uint64_t>(value);
    if (u <= 0xFFF) { imm12 = static_cast<uint32_t>(u); lsl12 = false; return true; }
    if ((u & 0xFFF) == 0 && (u >> 12) <= 0xFFF) {
        imm12 = static_cast<uint32_t>(u >> 12);
        lsl12 = true;
        return true;
    }
    return false;
}

// True if `imm` is encodable as an AArch64 logical (bitmask) immediate.
// Ported verbatim from codegen::encode_logical_imm so behavior matches the
// emitter exactly; we only need the success/failure outcome here.
bool logical_imm_ok(uint64_t imm, bool is64) {
    if (imm == 0 || imm == ~0ULL) return false;
    if (!is64) {
        imm = (imm & 0xFFFFFFFFULL) | ((imm & 0xFFFFFFFFULL) << 32);
    }
    unsigned size = 64;
    uint64_t mask = ~0ULL;
    for (unsigned s = 32; s >= 2; s >>= 1) {
        uint64_t lo = imm & ((1ULL << s) - 1);
        uint64_t hi = (imm >> s) & ((1ULL << s) - 1);
        if (lo == hi) { size = s; mask = (1ULL << s) - 1; }
        else break;
    }
    uint64_t pattern = imm & mask;
    unsigned rotation = 0;
    uint64_t normalized = pattern;
    for (unsigned i = 0; i < size; i++) {
        if ((normalized & 1) == 0) break;
        normalized = ((normalized >> 1) | ((normalized & 1) << (size - 1))) & mask;
        rotation++;
    }
    (void)rotation;
    if (normalized == 0) return false;
    unsigned leading_zeros = 0;
    for (unsigned i = 0; i < size; i++) {
        if ((normalized >> i) & 1) { leading_zeros = i; break; }
    }
    unsigned ones = 0;
    for (unsigned i = leading_zeros; i < size; i++) {
        if ((normalized >> i) & 1) ones++;
        else break;
    }
    uint64_t expected = (((1ULL << ones) - 1) << leading_zeros) & mask;
    return normalized == expected;
}

bool emit_cmp_cset(const Op& op, codegen::CodeGenerator& cg,
                   const EmitContext& ctx, Condition cc) {
    if (op.num_inputs != 2) return false;
    bool w = is_w(op.inputs[0]) || is_w(op.inputs[1]);

    // Prefer the CMP immediate form when the second operand is a constant so
    // the scratch register is left untouched (Bug B).
    const VarNode& rhs = op.inputs[1];
    if (op.inputs[0].space != Space::CONST && rhs.space == Space::CONST) {
        uint32_t imm12; bool lsl12, neg;
        if (addsub_imm(rhs.value, imm12, lsl12, neg) && !neg) {
            XReg a = ctx.resolve(op.inputs[0]);
            if (w) cg.cmp(w_of(a), imm12, lsl12);
            else   cg.cmp(a, imm12, lsl12);
            XReg o = ctx.resolve(op.output);
            if (is_w(op.output)) cg.cset(w_of(o), cc); else cg.cset(o, cc);
            return true;
        }
    }

    XReg a = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
    XReg b = to_reg(op.inputs[1], cg, ctx, ctx.scratch1);
    if (w) cg.cmp(w_of(a), w_of(b)); else cg.cmp(a, b);
    XReg o = ctx.resolve(op.output);
    if (is_w(op.output)) cg.cset(w_of(o), cc); else cg.cset(o, cc);
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

    // Width-aware binary register op: dispatch W/X off the output size.
    auto bin_reg = [&](auto mn) -> bool {
        XReg a{0}, b{0};
        if (!bin_in(a, b)) return false;
        XReg o = ctx.resolve(op.output);
        if (is_w(op.output)) mn(w_of(o), w_of(a), w_of(b));
        else                 mn(o, a, b);
        return true;
    };

    // Width-aware unary register op.
    auto un_reg = [&](auto mn) -> bool {
        if (op.num_inputs != 1) return false;
        XReg s = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
        XReg o = ctx.resolve(op.output);
        if (is_w(op.output)) mn(w_of(o), w_of(s));
        else                 mn(o, s);
        return true;
    };

    // Try an ALU op with a constant RHS via an immediate instruction form so
    // the scratch register is never materialized into (Bug B). Returns true
    // if it emitted the op, false to fall back to the register form.
    auto try_alu_imm = [&](char kind) -> bool {
        if (op.num_inputs != 2) return false;
        if (op.inputs[0].space == Space::CONST) return false;
        if (op.inputs[1].space != Space::CONST) return false;
        bool w = is_w(op.output);
        XReg n = ctx.resolve(op.inputs[0]);
        XReg o = ctx.resolve(op.output);
        int64_t v = op.inputs[1].value;
        if (kind == '+' || kind == '-') {
            uint32_t imm12; bool lsl12, neg;
            if (!addsub_imm(v, imm12, lsl12, neg)) return false;
            bool sub = (kind == '-') ^ neg;
            if (sub) { if (w) cg.sub(w_of(o), w_of(n), imm12, lsl12); else cg.sub(o, n, imm12, lsl12); }
            else     { if (w) cg.add(w_of(o), w_of(n), imm12, lsl12); else cg.add(o, n, imm12, lsl12); }
            return true;
        }
        // Logical: AND/ORR/EOR bitmask immediate.
        uint64_t uimm = static_cast<uint64_t>(v);
        if (!logical_imm_ok(uimm, !w)) return false;
        switch (kind) {
        case '&': if (w) cg.and_(w_of(o), w_of(n), uimm); else cg.and_(o, n, uimm); return true;
        case '|': if (w) cg.orr (w_of(o), w_of(n), uimm); else cg.orr (o, n, uimm); return true;
        case '^': if (w) cg.eor (w_of(o), w_of(n), uimm); else cg.eor (o, n, uimm); return true;
        }
        return false;
    };

    switch (op.opcode) {
    case Opcode::COPY: {
        if (op.num_inputs != 1) return false;
        XReg dst = ctx.resolve(op.output);
        bool w = is_w(op.output);
        if (op.inputs[0].space == Space::CONST) {
            if (w) cg.mov(w_of(dst), static_cast<uint32_t>(op.inputs[0].value));
            else   cg.mov(dst, static_cast<uint64_t>(op.inputs[0].value));
        } else {
            XReg src = ctx.resolve(op.inputs[0]);
            if (w) cg.mov(w_of(dst), w_of(src));
            else   cg.mov(dst, src);
        }
        return true;
    }

    case Opcode::ADD:
        if (try_alu_imm('+')) return true;
        return bin_reg([&](auto d, auto x, auto y){ cg.add(d, x, y); });
    case Opcode::SUB:
        if (try_alu_imm('-')) return true;
        return bin_reg([&](auto d, auto x, auto y){ cg.sub(d, x, y); });
    case Opcode::MUL:
        return bin_reg([&](auto d, auto x, auto y){ cg.mul(d, x, y); });
    case Opcode::SDIV:
        return bin_reg([&](auto d, auto x, auto y){ cg.sdiv(d, x, y); });
    case Opcode::UDIV:
        return bin_reg([&](auto d, auto x, auto y){ cg.udiv(d, x, y); });
    case Opcode::NEG:
        return un_reg([&](auto d, auto x){ cg.neg(d, x); });

    case Opcode::AND:
        if (try_alu_imm('&')) return true;
        return bin_reg([&](auto d, auto x, auto y){ cg.and_(d, x, y); });
    case Opcode::OR:
        if (try_alu_imm('|')) return true;
        return bin_reg([&](auto d, auto x, auto y){ cg.orr(d, x, y); });
    case Opcode::XOR:
        if (try_alu_imm('^')) return true;
        return bin_reg([&](auto d, auto x, auto y){ cg.eor(d, x, y); });
    case Opcode::NOT:
        return un_reg([&](auto d, auto x){ cg.mvn(d, x); });

    case Opcode::SHL:
        return bin_reg([&](auto d, auto x, auto y){ cg.lsl(d, x, y); });
    case Opcode::SHR:
        return bin_reg([&](auto d, auto x, auto y){ cg.lsr(d, x, y); });
    case Opcode::SAR:
        return bin_reg([&](auto d, auto x, auto y){ cg.asr(d, x, y); });
    case Opcode::ROR:
        return bin_reg([&](auto d, auto x, auto y){ cg.ror(d, x, y); });

    case Opcode::CLZ:
        return un_reg([&](auto d, auto x){ cg.clz(d, x); });
    case Opcode::BITREV:
        return un_reg([&](auto d, auto x){ cg.rbit(d, x); });
    case Opcode::POPCNT:
    case Opcode::CTZ:
        // No direct scalar AArch64 instruction.
        return false;

    case Opcode::ZEXT: {
        // Zero-extend 32 -> 64. Writing the W view clears the upper 32 bits.
        if (op.num_inputs != 1) return false;
        XReg dst = ctx.resolve(op.output);
        if (op.inputs[0].space == Space::CONST) {
            cg.mov(WReg{dst.idx},
                   static_cast<uint32_t>(op.inputs[0].value));
        } else {
            XReg src = ctx.resolve(op.inputs[0]);
            cg.mov(WReg{dst.idx}, WReg{src.idx});
        }
        return true;
    }
    case Opcode::SEXT: {
        // Sign-extend 32 -> 64.
        if (op.num_inputs != 1) return false;
        XReg dst = ctx.resolve(op.output);
        if (op.inputs[0].space == Space::CONST) {
            cg.mov(dst, static_cast<uint64_t>(
                static_cast<int64_t>(static_cast<int32_t>(op.inputs[0].value))));
        } else {
            XReg src = ctx.resolve(op.inputs[0]);
            cg.sxtw(dst, WReg{src.idx});
        }
        return true;
    }

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
        codegen::Mem m = codegen::ptr(base, offset);
        XReg dst = ctx.resolve(op.output);
        // Dispatch the load width off the destination size so a 4-byte load
        // emits LDR W (4 bytes read) rather than LDR X (8 bytes read), which
        // would over-read past the operand and fault at a page edge (Bug A).
        switch (op.output.size) {
        case 1: cg.ldrb(w_of(dst), m); break;
        case 2: cg.ldrh(w_of(dst), m); break;
        case 4: cg.ldr (w_of(dst), m); break;
        default: cg.ldr(dst, m); break;
        }
        return true;
    }
    case Opcode::STORE: {
        if (op.num_inputs < 2) return false;
        XReg val = to_reg(op.inputs[0], cg, ctx, ctx.scratch0);
        XReg base = ctx.resolve(op.inputs[1]);
        int32_t offset = (op.num_inputs >= 3 && op.inputs[2].space == Space::CONST)
            ? static_cast<int32_t>(op.inputs[2].value) : 0;
        codegen::Mem m = codegen::ptr(base, offset);
        // Dispatch the store width off the value size so a 4-byte store emits
        // STR W (4 bytes written) rather than STR X (8 bytes) (Bug A).
        switch (op.inputs[0].size) {
        case 1: cg.strb(w_of(val), m); break;
        case 2: cg.strh(w_of(val), m); break;
        case 4: cg.str (w_of(val), m); break;
        default: cg.str(val, m); break;
        }
        return true;
    }

    case Opcode::ADD_CARRY:
        return bin_reg([&](auto d, auto x, auto y){ cg.adcs(d, x, y); });
    case Opcode::SUB_CARRY:
        return bin_reg([&](auto d, auto x, auto y){ cg.sbcs(d, x, y); });
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
