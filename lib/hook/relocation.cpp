// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

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

    // B/BL: 26-bit signed offset * 4
    if (m == Mnemonic::B || m == Mnemonic::BL) {
        int32_t old_off = static_cast<int32_t>(insn << 6) >> 6;  // sign-extend imm26
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off < -0x2000000 || new_off > 0x1FFFFFF) { *out_count = 0; return false; }
        out_insn[0] = (insn & 0xFC000000u) | (static_cast<uint32_t>(new_off) & 0x03FFFFFFu);
        *out_count = 1;
        return true;
    }

    // B.cond/BC/CBZ/CBNZ: 19-bit signed offset * 4 at bits [23:5]
    if (m == Mnemonic::BC || m == Mnemonic::CBZ || m == Mnemonic::CBNZ) {
        int32_t old_off = static_cast<int32_t>(insn << 8) >> 13;  // extract imm19
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off < -0x40000 || new_off > 0x3FFFF) { *out_count = 0; return false; }
        out_insn[0] = (insn & 0xFF00001Fu) | ((static_cast<uint32_t>(new_off) & 0x7FFFFu) << 5);
        *out_count = 1;
        return true;
    }

    // TBZ/TBNZ: 14-bit signed offset * 4 at bits [18:5]
    if (m == Mnemonic::TBZ || m == Mnemonic::TBNZ) {
        int32_t old_off = static_cast<int32_t>(insn << 13) >> 18;  // extract imm14
        int64_t new_off = static_cast<int64_t>(old_off) + (delta >> 2);
        if (new_off < -0x2000 || new_off > 0x1FFF) { *out_count = 0; return false; }
        out_insn[0] = (insn & 0xFFF8001Fu) | ((static_cast<uint32_t>(new_off) & 0x3FFFu) << 5);
        *out_count = 1;
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
