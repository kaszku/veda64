// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// Library version
constexpr int VERSION_MAJOR = 0;
constexpr int VERSION_MINOR = 1;
constexpr int VERSION_PATCH = 0;

// Byte-order conversion utilities
// ARM64 stores instructions in little-endian byte order
// These convert between raw memory bytes and the uint32_t used by decode()
// e.g., PACIBSP in memory: {0x7f, 0x23, 0x03, 0xd5} -> 0xd503237f

// Read a little-endian uint32_t from 4 bytes in memory
// {0x7f, 0x23, 0x03, 0xd5} -> 0xd503237f
inline uint32_t from_bytes(const uint8_t* bytes) {
    return static_cast<uint32_t>(bytes[0]) |
           (static_cast<uint32_t>(bytes[1]) << 8) |
           (static_cast<uint32_t>(bytes[2]) << 16) |
           (static_cast<uint32_t>(bytes[3]) << 24);
}

// Write a uint32_t as 4 little-endian bytes to memory
// 0xd503237f -> {0x7f, 0x23, 0x03, 0xd5}
inline void to_bytes(uint32_t insn, uint8_t* bytes) {
    bytes[0] = static_cast<uint8_t>(insn);
    bytes[1] = static_cast<uint8_t>(insn >> 8);
    bytes[2] = static_cast<uint8_t>(insn >> 16);
    bytes[3] = static_cast<uint8_t>(insn >> 24);
}

// ARM64 DecodeBitMasks - decodes N:imms:immr into a bitmask immediate
inline uint64_t decode_bit_masks(uint32_t N, uint32_t imms, uint32_t immr, bool is_64bit) {
    uint32_t len = 0;
    uint32_t combined = (N << 6) | (~imms & 0x3F);
    for (int i = 6; i >= 0; --i) {
        if (combined & (1u << i)) { len = i; break; }
    }
    uint32_t esize = 1u << len;
    uint32_t levels = esize - 1;
    uint32_t S = imms & levels;
    uint32_t R = immr & levels;
    uint64_t welem = (S + 1 == 64) ? ~0ULL : ((1ULL << (S + 1)) - 1);
    uint64_t emask = (esize == 64) ? ~0ULL : ((1ULL << esize) - 1);
    if (R != 0) {
        welem = ((welem >> R) | (welem << (esize - R))) & emask;
    }
    uint64_t result = 0;
    uint32_t regsize = is_64bit ? 64 : 32;
    for (uint32_t i = 0; i < regsize; i += esize) {
        result |= welem << i;
    }
    if (!is_64bit) result &= 0xFFFFFFFFULL;
    return result;
}

} // namespace veda64
