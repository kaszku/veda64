// Example: IR lifting, simplification, and interpretation
// Build: cmake -DVEDA64_STRINGS=ON -DVEDA64_IR=ON .. && cmake --build .
// Run:   ./example_ir

#include "veda64.hpp"

#ifdef VEDA64_IR
#include "veda64/ir.hpp"
#include <cstdio>
#include <cstring>

using namespace veda64;

int main() {
    // --- Lift a single instruction to flat IR ---
    printf("=== Flat IR lifting ===\n");
    {
        // ADD X0, X1, X2
        auto lifted = ir::lift(0x8B020020);
        if (lifted) {
            printf("ADD X0, X1, X2:\n");
            auto simplified = ir::simplify(*lifted);
#ifdef VEDA64_STRINGS
            printf("%s\n", ir::to_string(simplified).c_str());
#endif
        }
    }

    {
        // SUBS X0, X1, X2 (sets flags)
        auto lifted = ir::lift(0xEB020020);
        if (lifted) {
            printf("\nSUBS X0, X1, X2:\n");
            auto simplified = ir::simplify(*lifted);
#ifdef VEDA64_STRINGS
            printf("%s\n", ir::to_string(simplified).c_str());
#endif
        }
    }

    {
        // LDR X0, [X1, #8]
        auto lifted = ir::lift(0xF9400420);
        if (lifted) {
            printf("\nLDR X0, [X1, #8]:\n");
            auto simplified = ir::simplify(*lifted);
#ifdef VEDA64_STRINGS
            printf("%s\n", ir::to_string(simplified).c_str());
#endif
        }
    }

    // --- Execute instructions in an interpreter context ---
    printf("\n=== Interpreter execution ===\n");
    {
        ir::Context ctx;
        uint8_t mem[4096] = {};
        ctx.memory = mem;
        ctx.memory_size = sizeof(mem);

        // Set up registers
        ctx.gpr[1] = 100;  // X1 = 100
        ctx.gpr[2] = 42;   // X2 = 42

        // ADD X0, X1, X2
        ir::execute(ctx, 0x8B020020);
        printf("After ADD X0, X1, X2:  X0 = %llu (expected 142)\n",
               (unsigned long long)ctx.gpr[0]);

        // SUB X0, X0, X2 -> 142 - 42 = 100
        ir::execute(ctx, 0xCB020000);
        printf("After SUB X0, X0, X2:  X0 = %llu (expected 100)\n",
               (unsigned long long)ctx.gpr[0]);

        // SUBS X0, X1, X2 -> 100 - 42 = 58, sets flags
        ir::execute(ctx, 0xEB020020);
        printf("After SUBS X0, X1, X2: X0 = %llu, N=%d Z=%d C=%d V=%d\n",
               (unsigned long long)ctx.gpr[0],
               ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]);
    }

    // --- Memory load/store via interpreter ---
    printf("\n=== Memory operations ===\n");
    {
        ir::Context ctx;
        uint8_t mem[4096] = {};
        ctx.memory = mem;
        ctx.memory_size = sizeof(mem);

        ctx.gpr[31] = 0x100;  // SP
        ctx.gpr[1] = 0xDEADBEEF;

        // STR X1, [SP]
        ir::execute(ctx, 0xF90003E1);
        printf("After STR X1, [SP]:    mem[0x100] = ");
        uint64_t val;
        memcpy(&val, &mem[0x100], 8);
        printf("0x%llX\n", (unsigned long long)val);

        // LDR X0, [SP]
        ir::execute(ctx, 0xF94003E0);
        printf("After LDR X0, [SP]:    X0 = 0x%llX (expected 0xDEADBEEF)\n",
               (unsigned long long)ctx.gpr[0]);
    }

    // --- Multi-instruction sequence ---
    printf("\n=== Multi-instruction sequence (compute 5 * 3 + 7) ===\n");
    {
        ir::Context ctx;
        uint8_t mem[4096] = {};
        ctx.memory = mem;
        ctx.memory_size = sizeof(mem);

        ctx.gpr[1] = 5;
        ctx.gpr[2] = 3;
        ctx.gpr[3] = 7;

        // MUL X0, X1, X2      -> X0 = 5 * 3 = 15
        ir::execute(ctx, 0x9B027C20);
        printf("After MUL X0, X1, X2: X0 = %llu\n", (unsigned long long)ctx.gpr[0]);

        // ADD X0, X0, X3      -> X0 = 15 + 7 = 22
        ir::execute(ctx, 0x8B030000);
        printf("After ADD X0, X0, X3: X0 = %llu (expected 22)\n",
               (unsigned long long)ctx.gpr[0]);
    }

    return 0;
}

#else // !VEDA64_IR

#include <cstdio>
int main() {
    printf("IR examples require -DVEDA64_IR=ON\n");
    return 0;
}

#endif
