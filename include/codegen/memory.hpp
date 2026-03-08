// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include "registers.hpp"

namespace veda64 {
namespace codegen {

/// Memory operand modes
enum class MemMode : uint8_t { Offset = 0, Pre = 1, Post = 2, RegOffset = 3 };

/// Memory operand for load/store instructions
struct Mem {
    uint8_t base_idx;
    int32_t offset;
    MemMode mode;
    uint8_t index_idx;     // 0xFF = no index register
    uint8_t extend_type;   // ExtendType for reg-offset mode
    uint8_t shift_amount;
};

/// [base, #offset]
inline Mem ptr(XReg base, int32_t off = 0) {
    return {base.idx, off, MemMode::Offset, 0xFF, 0, 0};
}

/// [base, #offset]!
inline Mem pre(XReg base, int32_t off) {
    return {base.idx, off, MemMode::Pre, 0xFF, 0, 0};
}

/// [base], #offset
inline Mem post(XReg base, int32_t off) {
    return {base.idx, off, MemMode::Post, 0xFF, 0, 0};
}

/// [base, Xm{, LSL #shift}]
inline Mem ptr(XReg base, XReg index, uint8_t shift = 0) {
    return {base.idx, 0, MemMode::RegOffset, index.idx, 3 /*UXTX=LSL*/, shift};
}

} // namespace codegen
} // namespace veda64
