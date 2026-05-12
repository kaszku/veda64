// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
//
// Example: lower a small IR sequence back to AArch64 bytes with ir::emit.
//
// Build requires -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON.

#if defined(VEDA64_IR) && defined(VEDA64_CODEGEN)

#include <veda64.hpp>
#include <veda64/ir_emit.hpp>
#include <codegen/codegen.hpp>
#include <cstdio>
#include <cstring>

using namespace veda64;
using namespace veda64::codegen;
using namespace veda64::ir;

int main() {
    // Build an IR sequence that computes  x3 = (x1 + x2) ^ 0xCAFE  then returns.
    Lifted l;
    auto push = [&](Op o) { l.ops.push_back(o); };

    // t0 = add(x1, x2)
    Op add{};
    add.opcode = Opcode::ADD;
    add.output = VarNode::temp(0);
    add.inputs[0] = VarNode::gpr(1);
    add.inputs[1] = VarNode::gpr(2);
    add.num_inputs = 2;
    push(add);

    // x3 = xor(t0, #0xCAFE) — the const input is auto-materialized into scratch1.
    Op xor_op{};
    xor_op.opcode = Opcode::XOR;
    xor_op.output = VarNode::gpr(3);
    xor_op.inputs[0] = VarNode::temp(0);
    xor_op.inputs[1] = VarNode::constant(0xCAFE, 8);
    xor_op.num_inputs = 2;
    push(xor_op);

    // ret
    Op ret{};
    ret.opcode = Opcode::RET;
    push(ret);

    // Resolve: Temp(n) → x9+n, GPR(n) → xn.
    EmitContext ctx;
    ctx.resolve = [](const VarNode& v) -> XReg {
        return (v.space == Space::TEMP)
            ? XReg{static_cast<uint8_t>(9 + v.offset)}
            : XReg{static_cast<uint8_t>(v.offset)};
    };

    CodeGenerator cg(4096);
    if (!emit(l, cg, ctx)) {
        std::fprintf(stderr, "ir::emit failed on an unsupported op\n");
        return 1;
    }

    // Disassemble what we just produced.
    std::printf("Emitted %zu bytes:\n", cg.size());
    for (size_t i = 0; i * 4 < cg.size(); ++i) {
        uint32_t insn;
        std::memcpy(&insn, cg.data() + i * 4, 4);
        auto decoded = decode(insn);
        std::printf("  0x%08X  ", insn);
        if (decoded) {
            std::printf("%s", mnemonic_to_string(decoded->mnemonic));
        } else {
            std::printf("<undecoded>");
        }
        std::printf("\n");
    }
    return 0;
}

#else

#include <cstdio>
int main() {
    std::printf("ir_emit example requires -DVEDA64_IR=ON -DVEDA64_CODEGEN=ON\n");
    return 0;
}

#endif
