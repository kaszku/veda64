// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64/barrier.hpp"

namespace veda64 {

BarrierOp barrier_from_value(uint32_t crm) {
    switch (crm) {
        case 1u: return BarrierOp::OSHLD;
        case 2u: return BarrierOp::OSHST;
        case 3u: return BarrierOp::OSH;
        case 5u: return BarrierOp::NSHLD;
        case 6u: return BarrierOp::NSHST;
        case 7u: return BarrierOp::NSH;
        case 9u: return BarrierOp::ISHLD;
        case 10u: return BarrierOp::ISHST;
        case 11u: return BarrierOp::ISH;
        case 13u: return BarrierOp::LD;
        case 14u: return BarrierOp::ST;
        case 15u: return BarrierOp::SY;
        default: return static_cast<BarrierOp>(crm);
    }
}

#ifdef VEDA64_STRINGS
const char* barrier_to_string(BarrierOp op) {
    switch (op) {
        case BarrierOp::OSHLD: return "oshld";
        case BarrierOp::OSHST: return "oshst";
        case BarrierOp::OSH: return "osh";
        case BarrierOp::NSHLD: return "nshld";
        case BarrierOp::NSHST: return "nshst";
        case BarrierOp::NSH: return "nsh";
        case BarrierOp::ISHLD: return "ishld";
        case BarrierOp::ISHST: return "ishst";
        case BarrierOp::ISH: return "ish";
        case BarrierOp::LD: return "ld";
        case BarrierOp::ST: return "st";
        case BarrierOp::SY: return "sy";
        default: return nullptr;
    }
}
#endif

} // namespace veda64
