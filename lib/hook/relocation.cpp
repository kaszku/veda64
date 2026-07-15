// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_HOOK

#include <veda64/relocation.hpp>
#include "veda64.hpp"
#include <format/control.hpp>
#include <format/ldst.hpp>

namespace veda64 {

bool is_pc_relative(uint32_t insn) {
    auto decoded = decode(insn);
    if (!decoded) return false;
    auto m = decoded->mnemonic;
    switch (m) {
    case Mnemonic::B: case Mnemonic::BL: case Mnemonic::BC:
    case Mnemonic::CBZ: case Mnemonic::CBNZ:
    case Mnemonic::TBZ: case Mnemonic::TBNZ:
    case Mnemonic::ADR: case Mnemonic::ADRP:
        return true;
    case Mnemonic::LDR: case Mnemonic::LDRSW: case Mnemonic::PRFM: {
        for (size_t i = 0; i < decoded->operands.size(); i++) {
            if (decoded->operands[i].type == OperandType::Relative) return true;
        }
        return false;
    }
    default: return false;
    }
}

bool can_relocate(uint32_t insn) {
    auto decoded = decode(insn);
    if (!decoded) return insn == 0;  // zero-padding is OK
    auto m = decoded->mnemonic;
    // Authenticated returns cannot be relocated (PAC is address-dependent)
    if (m == Mnemonic::RETAA || m == Mnemonic::RETAB ||
        m == Mnemonic::ERETAA || m == Mnemonic::ERETAB) return false;
    return true;
}

namespace {

// Scratch register for the absolute-address veneer: X16 (IP0), the same register
// the hook's own jump stubs use. Clobbered only on the taken path of a far branch.
constexpr uint32_t kVeneerReg = 16;

// Signed range of each branch immediate field, expressed as *word* offsets
// (byte offset >> 2) — the units the format encoders accept.
constexpr int64_t kImm14Min = -0x2000,    kImm14Max = 0x1FFF;
constexpr int64_t kImm19Min = -0x40000,   kImm19Max = 0x3FFFF;
constexpr int64_t kImm26Min = -0x2000000, kImm26Max = 0x1FFFFFF;

// First operand of a given type, or nullptr.
const Operand* find_operand(const Instruction& in, OperandType t) {
    for (const auto& op : in.operands) {
        if (op.type == t) return &op;
    }
    return nullptr;
}

// Invert an ARM condition code (EQ<->NE, CS<->CC, ... — the architecture pairs
// conditions so flipping bit 0 gives the inverse). AL(14)/NV(15) are the
// "always" pair and are handled by the caller, not inverted here.
Condition invert_condition(Condition cond) {
    return static_cast<Condition>(static_cast<int>(cond) ^ 1);
}

// Absolute-address veneer that reaches any 64-bit target without a PC-relative
// range limit: LDR X16,[PC,#8] ; BR X16 ; .quad target. Writes 4 words, returns 4.
// (BR, not BLR — used only for non-linking branches.)
size_t emit_abs_veneer(uint32_t* out, uint64_t target) {
    out[0] = format::ldst::encode_ldr_64_loadlit(kVeneerReg, 2);   // LDR X16, [PC, #8]
    out[1] = format::control::encode_br_64_branch_reg(kVeneerReg); // BR  X16
    out[2] = static_cast<uint32_t>(target & 0xFFFFFFFFu);          // .quad lo
    out[3] = static_cast<uint32_t>(target >> 32);                  // .quad hi
    return 4;
}

} // namespace

bool relocate_instruction(uint32_t insn, uint64_t old_pc, uint64_t new_pc,
                          uint32_t* out_insn, size_t* out_count) {
    if (!can_relocate(insn)) { *out_count = 0; return false; }

    auto decoded = decode(insn);
    if (!decoded) { *out_count = 0; return false; }

    // Non-PC-relative instructions are position-independent: copy verbatim.
    if (!is_pc_relative(insn)) {
        out_insn[0] = insn;
        *out_count = 1;
        return true;
    }

    const Mnemonic m = decoded->mnemonic;
    const Condition cc = decoded->condition;

    // Every branch carries its PC-relative displacement as a signed byte offset in
    // a Relative operand; recover the absolute target from it (no bit masks).
    const Operand* rel = find_operand(*decoded, OperandType::Relative);

    // ---- Unconditional B / BL (imm26, ±128 MiB) ----
    const bool is_uncond_b = (m == Mnemonic::B && cc == Condition::None);
    if (is_uncond_b || m == Mnemonic::BL) {
        if (!rel) { *out_count = 0; return false; }
        const uint64_t target = old_pc + static_cast<uint64_t>(static_cast<int64_t>(rel->iv.value));
        const int64_t off = (static_cast<int64_t>(target) - static_cast<int64_t>(new_pc)) >> 2;
        if (off >= kImm26Min && off <= kImm26Max) {
            out_insn[0] = (m == Mnemonic::BL)
                ? format::control::encode_bl_only_branch_imm(static_cast<int32_t>(off))
                : format::control::encode_b_only_branch_imm(static_cast<int32_t>(off));
            *out_count = 1;
            return true;
        }
        // BL cannot use the veneer: a BLR would push the literal-pool address as the
        // return address. Beyond ±128 MiB, BL relocation is unsupported.
        if (m == Mnemonic::BL) { *out_count = 0; return false; }
        *out_count = emit_abs_veneer(out_insn, target);
        return true;
    }

    // ---- Conditional / compare / test branches ----
    const bool is_condbranch = (m == Mnemonic::B && cc != Condition::None) || m == Mnemonic::BC;
    if (is_condbranch || m == Mnemonic::CBZ || m == Mnemonic::CBNZ ||
        m == Mnemonic::TBZ || m == Mnemonic::TBNZ) {
        if (!rel) { *out_count = 0; return false; }
        const uint64_t target = old_pc + static_cast<uint64_t>(static_cast<int64_t>(rel->iv.value));

        // Operand-derived fields — never bit-extracted from the raw word.
        const Operand* rt = find_operand(*decoded, OperandType::Register);
        const uint32_t Rt = rt ? register_num(rt->r.reg) : 0u;
        const bool is64 = rt && register_is_64bit(rt->r.reg);
        const Operand* bitop = find_operand(*decoded, OperandType::Immediate);
        const uint32_t bit = bitop ? static_cast<uint32_t>(bitop->iv.value) : 0u;
        const uint32_t b40 = bit & 0x1Fu, b5 = (bit >> 5) & 0x1u;

        // Re-encode this branch class at the given word offset, at original polarity
        // or inverted (CBZ<->CBNZ, TBZ<->TBNZ, cc<->!cc) — via the format encoders.
        auto encode_branch = [&](int32_t word_off, bool invert) -> uint32_t {
            switch (m) {
                case Mnemonic::B:
                    return format::control::encode_b_only_condbranch(
                        static_cast<uint32_t>(invert ? invert_condition(cc) : cc), word_off);
                case Mnemonic::BC:
                    return format::control::encode_bc_only_condbranch(
                        static_cast<uint32_t>(invert ? invert_condition(cc) : cc), word_off);
                case Mnemonic::CBZ:
                    return invert
                        ? (is64 ? format::control::encode_cbnz_64_compbranch(Rt, word_off)
                                : format::control::encode_cbnz_32_compbranch(Rt, word_off))
                        : (is64 ? format::control::encode_cbz_64_compbranch(Rt, word_off)
                                : format::control::encode_cbz_32_compbranch(Rt, word_off));
                case Mnemonic::CBNZ:
                    return invert
                        ? (is64 ? format::control::encode_cbz_64_compbranch(Rt, word_off)
                                : format::control::encode_cbz_32_compbranch(Rt, word_off))
                        : (is64 ? format::control::encode_cbnz_64_compbranch(Rt, word_off)
                                : format::control::encode_cbnz_32_compbranch(Rt, word_off));
                case Mnemonic::TBZ:
                    return invert
                        ? format::control::encode_tbnz_only_testbranch(Rt, word_off, b40, b5)
                        : format::control::encode_tbz_only_testbranch(Rt, word_off, b40, b5);
                case Mnemonic::TBNZ:
                    return invert
                        ? format::control::encode_tbz_only_testbranch(Rt, word_off, b40, b5)
                        : format::control::encode_tbnz_only_testbranch(Rt, word_off, b40, b5);
                default:
                    return 0;  // unreachable: guarded by the enclosing mnemonic test
            }
        };

        // Native conditional field range: imm14 for test-branches, imm19 otherwise.
        const bool is_tb = (m == Mnemonic::TBZ || m == Mnemonic::TBNZ);
        const int64_t nat_min = is_tb ? kImm14Min : kImm19Min;
        const int64_t nat_max = is_tb ? kImm14Max : kImm19Max;
        const int64_t nat_off = (static_cast<int64_t>(target) - static_cast<int64_t>(new_pc)) >> 2;

        // Tier 1: still reachable by the native conditional field — one instruction.
        if (nat_off >= nat_min && nat_off <= nat_max) {
            out_insn[0] = encode_branch(static_cast<int32_t>(nat_off), /*invert=*/false);
            *out_count = 1;
            return true;
        }

        // B.cond/BC with cond AL(14)/NV(15) are "always taken"; there is no useful
        // inverse, so reach the target unconditionally (single B, or veneer).
        const bool always = is_condbranch && static_cast<int>(cc) >= 14;
        if (always) {
            if (nat_off >= kImm26Min && nat_off <= kImm26Max) {
                out_insn[0] = format::control::encode_b_only_branch_imm(static_cast<int32_t>(nat_off));
                *out_count = 1;
                return true;
            }
            *out_count = emit_abs_veneer(out_insn, target);
            return true;
        }

        // Tier 2: inverted guard over an unconditional B (imm26, ±128 MiB). The guard
        // skips the B (2 words) when the original condition is not met; the B (placed
        // at new_pc+4) carries the far branch. No register clobber.
        const int64_t b_off = (static_cast<int64_t>(target) - (static_cast<int64_t>(new_pc) + 4)) >> 2;
        if (b_off >= kImm26Min && b_off <= kImm26Max) {
            out_insn[0] = encode_branch(2, /*invert=*/true);
            out_insn[1] = format::control::encode_b_only_branch_imm(static_cast<int32_t>(b_off));
            *out_count = 2;
            return true;
        }

        // Tier 3: inverted guard over an absolute-address veneer — reaches anywhere.
        //   inv-branch +5 ; LDR X16,[PC,#8] ; BR X16 ; .quad target
        out_insn[0] = encode_branch(5, /*invert=*/true);
        emit_abs_veneer(out_insn + 1, target);
        *out_count = 5;
        return true;
    }

    int64_t delta = static_cast<int64_t>(old_pc) - static_cast<int64_t>(new_pc);

    // ADR: 21-bit signed offset (immhi[23:5], immlo[30:29])
    if (m == Mnemonic::ADR) {
        int32_t immlo = static_cast<int32_t>((insn >> 29) & 0x3);
        int32_t immhi = static_cast<int32_t>((insn >> 5) & 0x7FFFF);
        int32_t old_off = (immhi << 2) | immlo;
        if (old_off & 0x100000) old_off |= static_cast<int32_t>(0xFFE00000u);  // sign extend
        int64_t new_off = static_cast<int64_t>(old_off) + delta;
        if (new_off < -0x100000 || new_off > 0xFFFFF) { *out_count = 0; return false; }
        uint32_t nlo = static_cast<uint32_t>(new_off) & 0x3;
        uint32_t nhi = (static_cast<uint32_t>(new_off) >> 2) & 0x7FFFF;
        out_insn[0] = (insn & 0x9F00001Fu) | (nlo << 29) | (nhi << 5);
        *out_count = 1;
        return true;
    }

    // ADRP: 21-bit signed offset * 4096 (page-relative)
    if (m == Mnemonic::ADRP) {
        int32_t immlo = static_cast<int32_t>((insn >> 29) & 0x3);
        int32_t immhi = static_cast<int32_t>((insn >> 5) & 0x7FFFF);
        int32_t imm = (immhi << 2) | immlo;
        if (imm & 0x100000) imm |= static_cast<int32_t>(0xFFE00000u);
        int64_t old_target = (static_cast<int64_t>(old_pc) & ~0xFFFLL) + (static_cast<int64_t>(imm) << 12);
        int64_t new_page_off = old_target - (static_cast<int64_t>(new_pc) & ~0xFFFLL);
        int64_t new_imm = new_page_off >> 12;
        if (new_imm < -0x100000 || new_imm > 0xFFFFF) { *out_count = 0; return false; }
        uint32_t nlo = static_cast<uint32_t>(new_imm) & 0x3;
        uint32_t nhi = (static_cast<uint32_t>(new_imm) >> 2) & 0x7FFFF;
        out_insn[0] = (insn & 0x9F00001Fu) | (nlo << 29) | (nhi << 5);
        *out_count = 1;
        return true;
    }

    // LDR literal / LDRSW literal / PRFM literal: 19-bit signed offset * 4 at bits [23:5]
    {
        int32_t old_off = static_cast<int32_t>(insn << 8) >> 13;
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off < -0x40000 || new_off > 0x3FFFF) { *out_count = 0; return false; }
        out_insn[0] = (insn & 0xFF00001Fu) | ((static_cast<uint32_t>(new_off) & 0x7FFFFu) << 5);
        *out_count = 1;
        return true;
    }
}

} // namespace veda64

#endif // VEDA64_HOOK
