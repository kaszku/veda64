// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_HOOK

#include <veda64/relocation.hpp>
#include "veda64.hpp"

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

bool relocate_instruction(uint32_t insn, uint64_t old_pc, uint64_t new_pc,
                          uint32_t* out_insn, size_t* out_count) {
    if (!can_relocate(insn)) { *out_count = 0; return false; }
    if (!is_pc_relative(insn)) {
        out_insn[0] = insn;
        *out_count = 1;
        return true;
    }
    // Decode to get mnemonic for dispatch
    auto decoded = decode(insn);
    if (!decoded) { *out_count = 0; return false; }
    auto m = decoded->mnemonic;
    int64_t delta = static_cast<int64_t>(old_pc) - static_cast<int64_t>(new_pc);

    // The decoder maps both unconditional B (0x14...) and B.cond (0x54...) to
    // Mnemonic::B, so we dispatch on the encoding pattern, not the mnemonic.
    bool is_uncond_b = (m == Mnemonic::B && (insn & 0xFC000000u) == 0x14000000u);
    bool is_b_cond   = (m == Mnemonic::B && (insn & 0xFF000010u) == 0x54000000u);

    // B/BL: 26-bit signed offset * 4
    if (is_uncond_b || m == Mnemonic::BL) {
        int32_t old_off = static_cast<int32_t>(insn << 6) >> 6;  // sign-extend imm26
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off < -0x2000000 || new_off > 0x1FFFFFF) { *out_count = 0; return false; }
        out_insn[0] = (insn & 0xFC000000u) | (static_cast<uint32_t>(new_off) & 0x03FFFFFFu);
        *out_count = 1;
        return true;
    }

    // B.cond/BC/CBZ/CBNZ: 19-bit signed offset * 4 at bits [23:5].
    // If the new imm19 is out of range, expand to a 2-insn sequence:
    //   <same-class branch with inverted predicate> +8  ; skip the next insn
    //   B <target>                                       ; imm26, ±128 MiB
    // B.AL/B.NV (cond >= 14) collapse to a single unconditional B.
    // Out of imm26 → return false (future work: 4-insn LDR+BR+literal tail
    // requires growing out_insn buffer beyond 4).
    if (is_b_cond || m == Mnemonic::BC || m == Mnemonic::CBZ || m == Mnemonic::CBNZ) {
        int32_t old_off = static_cast<int32_t>(insn << 8) >> 13;  // extract imm19
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off >= -0x40000 && new_off <= 0x3FFFF) {
            out_insn[0] = (insn & 0xFF00001Fu) | ((static_cast<uint32_t>(new_off) & 0x7FFFFu) << 5);
            *out_count = 1;
            return true;
        }
        // imm19 overflow: compute imm26 from the second word position (new_pc+4)
        int64_t target = static_cast<int64_t>(old_pc) + (static_cast<int64_t>(old_off) << 2);
        int64_t imm26_off = (target - (static_cast<int64_t>(new_pc) + 4)) >> 2;
        if (imm26_off < -0x2000000 || imm26_off > 0x1FFFFFF) { *out_count = 0; return false; }
        uint32_t b_insn = 0x14000000u | (static_cast<uint32_t>(imm26_off) & 0x03FFFFFFu);
        bool is_cond_class = is_b_cond || m == Mnemonic::BC;
        // B.cond/BC with cond=AL(14)/NV(15): inversion would flip AL↔NV. Both
        // behave as "always taken" in ARMv8, so collapse to a single B.
        if (is_cond_class && (insn & 0xFu) >= 14) {
            out_insn[0] = 0x14000000u | (static_cast<uint32_t>(
                (target - static_cast<int64_t>(new_pc)) >> 2) & 0x03FFFFFFu);
            *out_count = 1;
            return true;
        }
        // Insn 1: clear imm19, set imm19 = 2 (skip the B that follows), invert
        // the predicate (cond^1 for B.cond/BC, bit 24 for CBZ/CBNZ).
        uint32_t inv;
        if (is_cond_class) {
            inv = (insn & 0xFF00001Eu) | (2u << 5) | ((insn & 0xFu) ^ 1u);
        } else {
            inv = ((insn & 0xFF00001Fu) ^ (1u << 24)) | (2u << 5);
        }
        out_insn[0] = inv;
        out_insn[1] = b_insn;
        *out_count = 2;
        return true;
    }

    // TBZ/TBNZ: 14-bit signed offset * 4 at bits [18:5]. Same expansion strategy
    // as imm19 branches; predicate is bit 24 (TBZ=0 / TBNZ=1).
    if (m == Mnemonic::TBZ || m == Mnemonic::TBNZ) {
        int32_t old_off = static_cast<int32_t>(insn << 13) >> 18;  // extract imm14
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off >= -0x2000 && new_off <= 0x1FFF) {
            out_insn[0] = (insn & 0xFFF8001Fu) | ((static_cast<uint32_t>(new_off) & 0x3FFFu) << 5);
            *out_count = 1;
            return true;
        }
        int64_t target = static_cast<int64_t>(old_pc) + (static_cast<int64_t>(old_off) << 2);
        int64_t imm26_off = (target - (static_cast<int64_t>(new_pc) + 4)) >> 2;
        if (imm26_off < -0x2000000 || imm26_off > 0x1FFFFFF) { *out_count = 0; return false; }
        // Insn 1: preserve b40 [23:19] and Rt [4:0], clear imm14, set imm14 = 2,
        // flip bit 24 (TBZ ↔ TBNZ).
        uint32_t inv = ((insn & 0xFFF8001Fu) ^ (1u << 24)) | (2u << 5);
        out_insn[0] = inv;
        out_insn[1] = 0x14000000u | (static_cast<uint32_t>(imm26_off) & 0x03FFFFFFu);
        *out_count = 2;
        return true;
    }

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
