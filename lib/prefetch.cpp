// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64/prefetch.hpp"

namespace veda64 {

PrefetchOp prefetch_from_value(uint32_t prfop) {
    if (prfop < 24) return static_cast<PrefetchOp>(prfop);
    return PrefetchOp::UNKNOWN;
}

#ifndef VEDA64_NO_STRINGS
const char* prefetch_to_string(PrefetchOp op) {
    switch (op) {
        case PrefetchOp::PLDL1KEEP: return "pldl1keep";
        case PrefetchOp::PLDL1STRM: return "pldl1strm";
        case PrefetchOp::PLDL2KEEP: return "pldl2keep";
        case PrefetchOp::PLDL2STRM: return "pldl2strm";
        case PrefetchOp::PLDL3KEEP: return "pldl3keep";
        case PrefetchOp::PLDL3STRM: return "pldl3strm";
        case PrefetchOp::PLDSLCKEEP: return "pldslckeep";
        case PrefetchOp::PLDSLCSTRM: return "pldslcstrm";
        case PrefetchOp::PLIL1KEEP: return "plil1keep";
        case PrefetchOp::PLIL1STRM: return "plil1strm";
        case PrefetchOp::PLIL2KEEP: return "plil2keep";
        case PrefetchOp::PLIL2STRM: return "plil2strm";
        case PrefetchOp::PLIL3KEEP: return "plil3keep";
        case PrefetchOp::PLIL3STRM: return "plil3strm";
        case PrefetchOp::PLISLCKEEP: return "plislckeep";
        case PrefetchOp::PLISLCSTRM: return "plislcstrm";
        case PrefetchOp::PSTL1KEEP: return "pstl1keep";
        case PrefetchOp::PSTL1STRM: return "pstl1strm";
        case PrefetchOp::PSTL2KEEP: return "pstl2keep";
        case PrefetchOp::PSTL2STRM: return "pstl2strm";
        case PrefetchOp::PSTL3KEEP: return "pstl3keep";
        case PrefetchOp::PSTL3STRM: return "pstl3strm";
        case PrefetchOp::PSTSLCKEEP: return "pstslckeep";
        case PrefetchOp::PSTSLCSTRM: return "pstslcstrm";
        default: return nullptr;
    }
}
#endif

} // namespace veda64
