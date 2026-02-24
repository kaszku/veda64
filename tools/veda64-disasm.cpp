// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#include "veda64.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace veda64;

// Byte swap for big-endian to little-endian conversion
inline uint32_t bswap32(uint32_t value) {
    return ((value & 0xFF000000u) >> 24) |
           ((value & 0x00FF0000u) >> 8)  |
           ((value & 0x0000FF00u) << 8)  |
           ((value & 0x000000FFu) << 24);
}

// Parse a uint32_t from string
bool parse_instruction(const char* str, uint32_t& value) {
    char* endptr;

    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        value = static_cast<uint32_t>(std::strtoul(str + 2, &endptr, 16));
    } else if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B')) {
        value = static_cast<uint32_t>(std::strtoul(str + 2, &endptr, 2));
    } else {
        value = static_cast<uint32_t>(std::strtoul(str, &endptr, 0));
    }

    return *endptr == '\0';
}

void print_usage(const char* progname) {
    std::cerr << "Usage: " << progname << " [options] <instruction> [instruction...]\n";
    std::cerr << "\n";
    std::cerr << "Disassemble one or more ARM64 instructions.\n";
    std::cerr << "\n";
    std::cerr << "Options:\n";
    std::cerr << "  -b, --big-endian  Input values are in big-endian byte order\n";
    std::cerr << "  -h, --help        Show this help message\n";
    std::cerr << "\n";
    std::cerr << "Arguments:\n";
    std::cerr << "  instruction       32-bit instruction value\n";
    std::cerr << "                    (hex: 0x..., binary: 0b..., or decimal)\n";
    std::cerr << "\n";
    std::cerr << "Examples:\n";
    std::cerr << "  " << progname << " 0xd503237f              # PACIBSP (little-endian)\n";
    std::cerr << "  " << progname << " 0xd65f03c0              # RET (little-endian)\n";
    std::cerr << "  " << progname << " -b 0x7f2303d5           # PACIBSP (big-endian)\n";
    std::cerr << "  " << progname << " -b 0x7f2303d5 0xff2303d5  # Multiple (big-endian)\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    bool big_endian = false;
    int start_idx = 1;

    // Parse options
    while (start_idx < argc && argv[start_idx][0] == '-') {
        if (std::strcmp(argv[start_idx], "-b") == 0 || std::strcmp(argv[start_idx], "--big-endian") == 0) {
            big_endian = true;
            start_idx++;
        } else if (std::strcmp(argv[start_idx], "-h") == 0 || std::strcmp(argv[start_idx], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            std::cerr << "Error: Unknown option: " << argv[start_idx] << "\n\n";
            print_usage(argv[0]);
            return 1;
        }
    }

    if (start_idx >= argc) {
        std::cerr << "Error: No instruction values provided\n\n";
        print_usage(argv[0]);
        return 1;
    }

    int errors = 0;

    for (int i = start_idx; i < argc; i++) {
        uint32_t insn;

        if (!parse_instruction(argv[i], insn)) {
            std::cerr << "Error: Invalid instruction value: " << argv[i] << "\n";
            errors++;
            continue;
        }

        // Convert from big-endian to little-endian if needed
        if (big_endian) {
            insn = bswap32(insn);
        }

        auto result = decode(insn);

        if (result) {
            std::cout << "0x" << std::hex << (big_endian ? bswap32(insn) : insn) << std::dec << ": " << result->to_string() << "\n";
        } else {
            std::cout << "0x" << std::hex << (big_endian ? bswap32(insn) : insn) << std::dec << ": <unknown>\n";
        }
    }

    return errors > 0 ? 1 : 0;
}
