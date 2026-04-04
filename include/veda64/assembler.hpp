// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#ifdef VEDA64_ASSEMBLER

#include <cstdint>

namespace veda64 {

struct AsmResult {
    uint32_t insn = 0;
    bool success = false;
    const char* error = nullptr;
};

AsmResult assemble(const char* text);
AsmResult assemble(const char* text, uint64_t pc);

} // namespace veda64

#endif // VEDA64_ASSEMBLER
