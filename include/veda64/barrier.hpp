// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// Barrier option identifiers for DMB/DSB/ISB instructions
enum class BarrierOp : uint8_t {
    OSHLD = 1u,
    OSHST = 2u,
    OSH = 3u,
    NSHLD = 5u,
    NSHST = 6u,
    NSH = 7u,
    ISHLD = 9u,
    ISHST = 10u,
    ISH = 11u,
    LD = 13u,
    ST = 14u,
    SY = 15u,
    UNKNOWN = 255u
};

// Look up BarrierOp from 4-bit CRm field
BarrierOp barrier_from_value(uint32_t crm);

#ifdef VEDA64_STRINGS
const char* barrier_to_string(BarrierOp op);
#endif

} // namespace veda64
