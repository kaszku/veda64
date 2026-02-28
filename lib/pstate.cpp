// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64/pstate.hpp"

namespace veda64 {

PstateField pstate_from_value(uint32_t packed) {
    uint8_t op1 = (packed >> 7) & 7;
    uint8_t CRm = (packed >> 3) & 0xF;
    uint8_t op2 = packed & 7;
    if (op1 == 0 && op2 == 3) return PstateField::UAO;
    if (op1 == 0 && op2 == 4) return PstateField::PAN;
    if (op1 == 0 && op2 == 5) return PstateField::SPSEL;
    if (op1 == 1 && op2 == 0 && (CRm >> 1) == 0) return PstateField::ALLINT;
    if (op1 == 1 && op2 == 0 && (CRm >> 1) == 1) return PstateField::PM;
    if (op1 == 3 && op2 == 1) return PstateField::SSBS;
    if (op1 == 3 && op2 == 2) return PstateField::DIT;
    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 1) return PstateField::SVCRSM;
    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 2) return PstateField::SVCRZA;
    if (op1 == 3 && op2 == 3 && (CRm >> 1) == 3) return PstateField::SVCRSMZA;
    if (op1 == 3 && op2 == 4) return PstateField::TCO;
    if (op1 == 3 && op2 == 6) return PstateField::DAIFSET;
    if (op1 == 3 && op2 == 7) return PstateField::DAIFCLR;
    return PstateField::UNKNOWN;
}

#ifndef VEDA64_NO_STRINGS
const char* pstate_to_string(PstateField f) {
    switch (f) {
        case PstateField::UAO: return "uao";
        case PstateField::PAN: return "pan";
        case PstateField::SPSEL: return "spsel";
        case PstateField::ALLINT: return "allint";
        case PstateField::PM: return "pm";
        case PstateField::SSBS: return "ssbs";
        case PstateField::DIT: return "dit";
        case PstateField::SVCRSM: return "svcrsm";
        case PstateField::SVCRZA: return "svcrza";
        case PstateField::SVCRSMZA: return "svcrsmza";
        case PstateField::TCO: return "tco";
        case PstateField::DAIFSET: return "daifset";
        case PstateField::DAIFCLR: return "daifclr";
        default: return nullptr;
    }
}
#endif

} // namespace veda64
