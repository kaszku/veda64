// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once
// ARM64 Decode Group Headers
// Auto-generated from encodingindex.xml top-level decode groups
//
// Groups based on op0 (bit 31) and op1 (bits [28:25]):
// | op0 | op1  | Group                                          |
// |-----|------|------------------------------------------------|
// | 0   | 0000 | Reserved                                       |
// | 1   | 0000 | SME encodings                                  |
// | x   | 0010 | SVE encodings                                  |
// | x   | 100x | Data Processing -- Immediate                   |
// | x   | 101x | Branches, Exception Generating and System      |
// | x   | x101 | Data Processing -- Register                    |
// | x   | x111 | Data Processing -- Scalar FP and Advanced SIMD |
// | x   | x1x0 | Loads and Stores                               |

#include "format/control.hpp"
#include "format/dpimm.hpp"
#include "format/dpreg.hpp"
#include "format/ldst.hpp"
#include "format/reserved.hpp"
#include "format/simd_dp.hpp"
#include "format/sme.hpp"
#include "format/sve.hpp"

namespace veda64 {

// Unified decode function that dispatches to appropriate group decoder
// Uses switch/case on 5-bit key = (op0 << 4) | op1 for jump table optimization
inline std::optional<Instruction> decode_format(uint32_t insn) {
    // Combine op0 (bit 31) and op1 (bits [28:25]) into 5-bit dispatch key
    uint32_t key = ((insn >> 27) & 0x10) | ((insn >> 25) & 0xF);

    switch (key) {
    case 0:  // op0=0, op1=0000: Reserved
        return format::reserved::decode_reserved(insn);
    case 16: // op0=1, op1=0000: SME
        return format::sme::decode_sme(insn);
    case 2:  // op0=0, op1=0010: SVE
    case 18: // op0=1, op1=0010: SVE
        return format::sve::decode_sve(insn);
    case 8:  // op0=0, op1=1000: Data Processing - Immediate
    case 9:  // op0=0, op1=1001
    case 24: // op0=1, op1=1000
    case 25: // op0=1, op1=1001
        return format::dpimm::decode_dpimm(insn);
    case 10: // op0=0, op1=1010: Branches, Exception & System
    case 11: // op0=0, op1=1011
    case 26: // op0=1, op1=1010
    case 27: // op0=1, op1=1011
        return format::control::decode_control(insn);
    case 5:  // op0=0, op1=0101: Data Processing - Register
    case 13: // op0=0, op1=1101
    case 21: // op0=1, op1=0101
    case 29: // op0=1, op1=1101
        return format::dpreg::decode_dpreg(insn);
    case 7:  // op0=0, op1=0111: Scalar FP & Advanced SIMD
    case 15: // op0=0, op1=1111
    case 23: // op0=1, op1=0111
    case 31: // op0=1, op1=1111
        return format::simd_dp::decode_simd_dp(insn);
    case 4:  // op0=0, op1=0100: Loads and Stores
    case 6:  // op0=0, op1=0110
    case 12: // op0=0, op1=1100
    case 14: // op0=0, op1=1110
    case 20: // op0=1, op1=0100
    case 22: // op0=1, op1=0110
    case 28: // op0=1, op1=1100
    case 30: // op0=1, op1=1110
        return format::ldst::decode_ldst(insn);
    default: // Unallocated (op1=0001 or op1=0011)
        return std::nullopt;
    }
}

} // namespace veda64
