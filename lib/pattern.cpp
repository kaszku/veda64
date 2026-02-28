// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64/pattern.hpp"

namespace veda64 {

SvePattern pattern_from_value(uint32_t pattern) {
    switch (pattern) {
        case 0u: return SvePattern::POW2;
        case 1u: return SvePattern::VL1;
        case 2u: return SvePattern::VL2;
        case 3u: return SvePattern::VL3;
        case 4u: return SvePattern::VL4;
        case 5u: return SvePattern::VL5;
        case 6u: return SvePattern::VL6;
        case 7u: return SvePattern::VL7;
        case 8u: return SvePattern::VL8;
        case 9u: return SvePattern::VL16;
        case 10u: return SvePattern::VL32;
        case 11u: return SvePattern::VL64;
        case 12u: return SvePattern::VL128;
        case 13u: return SvePattern::VL256;
        case 29u: return SvePattern::MUL4;
        case 30u: return SvePattern::MUL3;
        case 31u: return SvePattern::ALL;
        default: return SvePattern::UNKNOWN;
    }
}

#ifndef VEDA64_NO_STRINGS
const char* pattern_to_string(SvePattern pat) {
    switch (pat) {
        case SvePattern::POW2: return "pow2";
        case SvePattern::VL1: return "vl1";
        case SvePattern::VL2: return "vl2";
        case SvePattern::VL3: return "vl3";
        case SvePattern::VL4: return "vl4";
        case SvePattern::VL5: return "vl5";
        case SvePattern::VL6: return "vl6";
        case SvePattern::VL7: return "vl7";
        case SvePattern::VL8: return "vl8";
        case SvePattern::VL16: return "vl16";
        case SvePattern::VL32: return "vl32";
        case SvePattern::VL64: return "vl64";
        case SvePattern::VL128: return "vl128";
        case SvePattern::VL256: return "vl256";
        case SvePattern::MUL4: return "mul4";
        case SvePattern::MUL3: return "mul3";
        case SvePattern::ALL: return "all";
        default: return nullptr;
    }
}
#endif

} // namespace veda64
