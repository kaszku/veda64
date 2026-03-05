// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifndef VEDA64_NO_IR

#include "veda64.hpp"
#include "veda64/ir.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace veda64;

static uint64_t parse_hex(const char* s) {
    return strtoull(s, nullptr, 0);
}

static void dump_context(const ir::Context& ctx) {
    for (int i = 0; i < 31; ++i) {
        if (ctx.gpr[i]) printf("  x%-2d = 0x%016llx  (%llu)\n", i, (unsigned long long)ctx.gpr[i], (unsigned long long)ctx.gpr[i]);
    }
    if (ctx.gpr[31]) printf("  sp  = 0x%016llx\n", (unsigned long long)ctx.gpr[31]);
    printf("  pc  = 0x%016llx\n", (unsigned long long)ctx.pc);
    if (ctx.flags[0] || ctx.flags[1] || ctx.flags[2] || ctx.flags[3])
        printf("  flags: N=%d Z=%d C=%d V=%d\n", ctx.flags[0], ctx.flags[1], ctx.flags[2], ctx.flags[3]);
}

int main(int argc, char** argv) {
    ir::Context ctx;
    size_t mem_size = 65536;
    bool dump = false;
    bool step = false;
    std::vector<uint32_t> insns;

    for (int i = 1; i < argc; ++i) {
        if (strncmp(argv[i], "--x", 3) == 0 && strchr(argv[i], '=')) {
            int reg = atoi(argv[i] + 3);
            const char* val = strchr(argv[i], '=') + 1;
            if (reg >= 0 && reg <= 30) ctx.gpr[reg] = parse_hex(val);
        } else if (strncmp(argv[i], "--sp=", 5) == 0) {
            ctx.gpr[31] = parse_hex(argv[i] + 5);
        } else if (strncmp(argv[i], "--pc=", 5) == 0) {
            ctx.pc = parse_hex(argv[i] + 5);
        } else if (strncmp(argv[i], "--mem=", 6) == 0) {
            mem_size = (size_t)parse_hex(argv[i] + 6);
        } else if (strcmp(argv[i], "--dump") == 0) {
            dump = true;
        } else if (strcmp(argv[i], "--step") == 0) {
            step = true;
        } else if (strncmp(argv[i], "0x", 2) == 0 || strncmp(argv[i], "0X", 2) == 0) {
            insns.push_back((uint32_t)strtoul(argv[i], nullptr, 16));
        } else {
            fprintf(stderr, "Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    if (insns.empty()) {
        fprintf(stderr, "Usage: veda64-interp [--x0=VAL] [--sp=VAL] [--pc=VAL] [--mem=SIZE] [--dump] [--step] 0xINSN...\n");
        return 1;
    }

    std::vector<uint8_t> mem(mem_size, 0);
    ctx.memory = mem.data();
    ctx.memory_size = mem_size;

    for (size_t idx = 0; idx < insns.size() && !ctx.halted; ) {
        uint32_t insn = insns[idx];
        if (step) {
#ifndef VEDA64_NO_STRINGS
            auto decoded = decode(insn);
            if (decoded) printf("[0x%llx] %s\n", (unsigned long long)ctx.pc, decoded->to_string().c_str());
#else
            printf("[0x%llx] 0x%08x\n", (unsigned long long)ctx.pc, insn);
#endif
        }
        uint64_t old_pc = ctx.pc;
        ir::execute(ctx, insn);
        if (ctx.pc != old_pc + 4) {
            // Branch taken — currently no memory-based PC fetch, just stop
            break;
        }
        ++idx;
    }

    if (dump) dump_context(ctx);

    return 0;
}

#else // VEDA64_NO_IR

#include <cstdio>
int main() { fprintf(stderr, "IR interpreter disabled (VEDA64_NO_IR)\n"); return 1; }

#endif
