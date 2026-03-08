// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>
#include <vector>

namespace veda64 {
namespace codegen {

/// Patch types for label resolution
enum class PatchType : uint8_t {
    Imm26 = 0,  // B/BL: bits [25:0], offset >>2
    Imm19 = 1,  // B.cond/CBZ/CBNZ: bits [23:5], offset >>2
    Imm14 = 2,  // TBZ/TBNZ: bits [18:5], offset >>2
    Adr21 = 3,  // ADR: immhi:immlo split
};

/// Label for forward/backward branch references
class Label {
    friend class CodeGenerator;
    struct Patch { size_t insn_offset; PatchType type; };
    size_t bound_offset_ = SIZE_MAX;
    std::vector<Patch> patches_;
public:
    Label() = default;
    bool is_bound() const { return bound_offset_ != SIZE_MAX; }
};

} // namespace codegen
} // namespace veda64
