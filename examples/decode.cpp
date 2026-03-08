// Example: Decoding ARM64 instructions
// Build: cmake -DVEDA64_STRINGS=ON .. && cmake --build .
// Run:   ./example_decode

#include "veda64.hpp"
#include <cstdio>
#include <cstring>

using namespace veda64;

int main() {
    // --- Decode from a 32-bit integer ---
    printf("=== Decode from uint32_t ===\n");
    uint32_t instructions[] = {
        0x8B020020,  // ADD X0, X1, X2
        0x91002820,  // ADD X0, X1, #0xA
        0xD65F03C0,  // RET
        0xF9400020,  // LDR X0, [X1]
        0x54000060,  // B.EQ #12
        0x1E612000,  // FADD D0, D0, D1
    };

    for (uint32_t insn : instructions) {
        auto result = decode(insn);
        if (result) {
#ifdef VEDA64_STRINGS
            printf("  0x%08X -> %s\n", insn, result->to_string().c_str());
#else
            printf("  0x%08X -> mnemonic=%d, %zu operands\n",
                   insn, static_cast<int>(result->mnemonic),
                   result->operands.size());
#endif
        } else {
            printf("  0x%08X -> (undefined)\n", insn);
        }
    }

    // --- Decode from bytes (little-endian, as stored in memory) ---
    printf("\n=== Decode from bytes ===\n");
    uint8_t bytes[] = {0x20, 0x00, 0x02, 0x8B};  // ADD X0, X1, X2
    auto result = decode(bytes);
    if (result) {
#ifdef VEDA64_STRINGS
        printf("  bytes -> %s\n", result->to_string().c_str());
#else
        printf("  bytes -> mnemonic=%d\n", static_cast<int>(result->mnemonic));
#endif
    }

    // --- Inspect operands ---
    printf("\n=== Operand inspection ===\n");
    result = decode(0x8B020020);  // ADD X0, X1, X2
    if (result) {
        printf("  Mnemonic enum: %d\n", static_cast<int>(result->mnemonic));
        printf("  Raw value: 0x%08X\n", result->raw_value);
        printf("  Operand count: %zu\n", result->operands.size());
        for (size_t i = 0; i < result->operands.size(); i++) {
            const auto& op = result->operands[i];
            printf("    [%zu] type=%d", i, static_cast<int>(op.type));
#ifdef VEDA64_STRINGS
            printf(" -> %s", op.to_string().c_str());
#endif
            printf("\n");
        }
    }

    // --- Decode a stream of instructions (e.g., from a binary) ---
    printf("\n=== Instruction stream ===\n");
    uint32_t code[] = {
        0xD2800020,  // MOV X0, #1
        0xD2800041,  // MOV X1, #2
        0x8B010000,  // ADD X0, X0, X1
        0xD65F03C0,  // RET
    };
    for (size_t i = 0; i < sizeof(code) / sizeof(code[0]); i++) {
        auto r = decode(code[i]);
        if (r) {
#ifdef VEDA64_STRINGS
            printf("  [0x%02zx] %s\n", i * 4, r->to_string().c_str());
#else
            printf("  [0x%02zx] mnemonic=%d\n", i * 4, static_cast<int>(r->mnemonic));
#endif
        }
    }

    return 0;
}
