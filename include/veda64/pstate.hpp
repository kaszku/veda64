// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// PSTATE field identifiers for MSR (immediate) instructions
enum class PstateField : uint8_t {
    UAO = 0u,
    PAN = 1u,
    SPSEL = 2u,
    ALLINT = 3u,
    PM = 4u,
    SSBS = 5u,
    DIT = 6u,
    SVCRSM = 7u,
    SVCRZA = 8u,
    SVCRSMZA = 9u,
    TCO = 10u,
    DAIFSET = 11u,
    DAIFCLR = 12u,
    UNKNOWN = 255u
};

// Look up PstateField from packed (op1<<7)|(CRm<<3)|op2 value
PstateField pstate_from_value(uint32_t packed);

#ifndef VEDA64_NO_STRINGS
const char* pstate_to_string(PstateField f);
#endif

} // namespace veda64
