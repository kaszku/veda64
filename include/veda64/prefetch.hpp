// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// Prefetch operation identifiers for PRFM/PRFUM instructions
enum class PrefetchOp : uint8_t {
    PLDL1KEEP = 0u,
    PLDL1STRM = 1u,
    PLDL2KEEP = 2u,
    PLDL2STRM = 3u,
    PLDL3KEEP = 4u,
    PLDL3STRM = 5u,
    PLDSLCKEEP = 6u,
    PLDSLCSTRM = 7u,
    PLIL1KEEP = 8u,
    PLIL1STRM = 9u,
    PLIL2KEEP = 10u,
    PLIL2STRM = 11u,
    PLIL3KEEP = 12u,
    PLIL3STRM = 13u,
    PLISLCKEEP = 14u,
    PLISLCSTRM = 15u,
    PSTL1KEEP = 16u,
    PSTL1STRM = 17u,
    PSTL2KEEP = 18u,
    PSTL2STRM = 19u,
    PSTL3KEEP = 20u,
    PSTL3STRM = 21u,
    PSTSLCKEEP = 22u,
    PSTSLCSTRM = 23u,
    UNKNOWN = 255u
};

// Look up PrefetchOp from 5-bit prfop field
PrefetchOp prefetch_from_value(uint32_t prfop);

#ifndef VEDA64_NO_STRINGS
const char* prefetch_to_string(PrefetchOp op);
#endif

} // namespace veda64
