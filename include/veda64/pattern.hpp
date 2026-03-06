// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// SVE predicate pattern identifiers
enum class SvePattern : uint8_t {
    POW2 = 0u,
    VL1 = 1u,
    VL2 = 2u,
    VL3 = 3u,
    VL4 = 4u,
    VL5 = 5u,
    VL6 = 6u,
    VL7 = 7u,
    VL8 = 8u,
    VL16 = 9u,
    VL32 = 10u,
    VL64 = 11u,
    VL128 = 12u,
    VL256 = 13u,
    MUL4 = 29u,
    MUL3 = 30u,
    ALL = 31u,
    UNKNOWN = 255u
};

// Look up SvePattern from 5-bit pattern field
SvePattern pattern_from_value(uint32_t pattern);

#ifdef VEDA64_STRINGS
const char* pattern_to_string(SvePattern pat);
#endif

} // namespace veda64
