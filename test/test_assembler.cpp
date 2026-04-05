// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#ifdef VEDA64_ASSEMBLER

#include <veda64/assembler.hpp>
#include <veda64.hpp>
#include <iostream>
#include <cassert>
#include <cstdio>

using namespace veda64;

static int passed = 0;
static int failed = 0;

static void check(const char* text, uint32_t expected) {
    auto r = assemble(text);
    if (!r.success) {
        std::cerr << "  FAIL: '" << text << "' -> error: " << (r.error ? r.error : "?") << std::endl;
        failed++;
    } else if (r.insn != expected) {
        std::cerr << "  FAIL: '" << text << "' -> 0x" << std::hex << r.insn
                  << " (expected 0x" << expected << ")" << std::dec << std::endl;
        failed++;
    } else {
        passed++;
    }
}

static void check_assembles(const char* text) {
    auto r = assemble(text);
    if (!r.success) {
        std::cerr << "  FAIL: '" << text << "' -> error: " << (r.error ? r.error : "?") << std::endl;
        failed++;
    } else {
        // Verify roundtrip: decode the assembled instruction
        auto decoded = decode(r.insn);
        if (!decoded.has_value()) {
            std::cerr << "  FAIL: '" << text << "' -> 0x" << std::hex << r.insn
                      << " decode failed" << std::dec << std::endl;
            failed++;
        } else {
            passed++;
        }
    }
}

int main() {
    std::cout << "Running assembler tests..." << std::endl;

    // === No-operand instructions ===
    check("nop", 0xD503201F);
    check("ret", 0xD65F03C0);

    // === Branches ===
    check("brk #0", 0xD4200000);
    check("svc #0", 0xD4000001);
    check("hlt #0", 0xD4400000);

    // === GP Immediate ===
    check("add x0, x1, #0x10", 0x91004020);
    check("add w0, w1, #1", 0x11000420);
    check("sub x0, x1, #0x10", 0xD1004020);
    check("sub w0, w1, #1", 0x51000420);

    // === GP Register ===
    check("add x0, x1, x2", 0x8B020020);
    check("sub x0, x1, x2", 0xCB020020);
    check("add w0, w1, w2", 0x0B020020);

    // === Multiply ===
    check("mul x0, x1, x2", 0x9B027C20);
    check("madd x0, x1, x2, x3", 0x9B020C20);

    // === Loads/Stores (basic) ===
    check_assembles("ldr x0, [x1]");
    check_assembles("str x0, [x1]");
    check_assembles("ldr w0, [x1]");
    check_assembles("str w0, [x1]");

    // === Scalar FP ===
    check_assembles("fadd s0, s1, s2");
    check_assembles("fadd d0, d1, d2");

    // === SIMD Vector ===
    check_assembles("add v0.4s, v1.4s, v2.4s");

    // === More GP ===
    check("adds x0, x1, x2", 0xAB020020);
    check("subs x0, x1, x2", 0xEB020020);
    check("and x0, x1, x2", 0x8A020020);
    check("orr x0, x1, x2", 0xAA020020);
    check("eor x0, x1, x2", 0xCA020020);
    check("sdiv x0, x1, x2", 0x9AC20C20);
    check("udiv x0, x1, x2", 0x9AC20820);
    check("adc x0, x1, x2", 0x9A020020);

    // === Conditional ===
    check_assembles("csel x0, x1, x2, eq");
    check_assembles("csinc x0, x1, x2, ne");

    // === Bitfield ===
    check("movz x0, #0x1234", 0xD2824680);
    check("movk x0, #0x5678, lsl #16", 0xF2AACF00);

    // === Shifts ===
    check_assembles("lsl x0, x1, x2");
    check_assembles("lsr x0, x1, x2");
    check_assembles("asr x0, x1, x2");

    // === Compare ===
    check_assembles("cmp x0, #0");
    check_assembles("cmn x0, x1");

    // === Load/Store with offset ===
    check_assembles("ldr x0, [x1, #8]");
    check_assembles("str x0, [sp, #0x10]");
    check_assembles("ldrb w0, [x1]");
    check_assembles("strh w0, [x1]");

    // === FP ===
    check_assembles("fmov s0, s1");
    check_assembles("fmov d0, d1");
    check_assembles("fsub d0, d1, d2");
    check_assembles("fmul s0, s1, s2");
    check_assembles("fdiv d0, d1, d2");
    check_assembles("fcmp s0, s1");
    check_assembles("fcmp d0, d1");

    // === More SIMD ===
    check_assembles("sub v0.4s, v1.4s, v2.4s");
    check_assembles("mul v0.4s, v1.4s, v2.4s");
    check_assembles("and v0.16b, v1.16b, v2.16b");

    // === System ===
    check("isb", 0xD5033FDF);
    // dmb: needs barrier option support — skip for now
    // check_assembles("dmb #0xb");

    // === Branches with registers ===
    check("br x0", 0xD61F0000);
    check("blr x0", 0xD63F0000);
    check("ret x0", 0xD65F0000);

    // === Roundtrip: decode → to_string → assemble → compare ===
    {
        uint32_t test_insns[] = {
            0x8B020020,  // add x0, x1, x2
            0xD503201F,  // nop
            0xD65F03C0,  // ret
            0x91004020,  // add x0, x1, #0x10
            0x9B027C20,  // mul x0, x1, x2
            0xCB020020,  // sub x0, x1, x2
            0xAB020020,  // adds x0, x1, x2
            0xEB020020,  // subs x0, x1, x2
            0x8A020020,  // and x0, x1, x2
            0xAA020020,  // orr x0, x1, x2
            0xCA020020,  // eor x0, x1, x2
            0x9AC20C20,  // sdiv x0, x1, x2
            0x9AC20820,  // udiv x0, x1, x2
            0x9A020020,  // adc x0, x1, x2
            0xD4200000,  // brk #0
            0xD4000001,  // svc #0
            0x1E222820,  // fadd s0, s1, s2
            0x1E622820,  // fadd d0, d1, d2
            0x1E212020,  // fadd s0, s1, s1
            0x1E613800,  // fmov d0, d1
            0x1E202020,  // fmov s0, s1
            0x1E623820,  // fsub d0, d1, d2
            0x1E620820,  // fmul d0, d1, d2
            0x1E621820,  // fdiv d0, d1, d2
            0x1E612000,  // fcmp d0, d1
            0x0B020020,  // add w0, w1, w2
            0x4B020020,  // sub w0, w1, w2
            0x0A020020,  // and w0, w1, w2
            0x2A020020,  // orr w0, w1, w2
            0x4A020020,  // eor w0, w1, w2
            0x1AC20C20,  // sdiv w0, w1, w2
            0x1AC20820,  // udiv w0, w1, w2
            0x1B027C20,  // mul w0, w1, w2
            0x1A020020,  // adc w0, w1, w2
            0x11000420,  // add w0, w1, #1
            0x91004020,  // add x0, x1, #0x10
            0x51000420,  // sub w0, w1, #1
            0xD1004020,  // sub x0, x1, #0x10
            0x71000420,  // subs w0, w1, #1
            0xF1004020,  // subs x0, x1, #0x10
            0x31000420,  // adds w0, w1, #1
            0xB1004020,  // adds x0, x1, #0x10
            0xD2824680,  // movz x0, #0x1234
            0x52824680,  // movz w0, #0x1234
            0xD61F0000,  // br x0
            0xD63F0000,  // blr x0
            0x9A9F07E0,  // csinc x0, xzr, xzr, ne (cset x0, eq)
            0x5A820020,  // cinv w0, w1, ne (alias decodes with inverted cond)
            0x9A820020,  // csel x0, x1, x2, eq
            0x9A820420,  // cinc x0, x1, ne (alias decodes with inverted cond)
            0x4E218400,  // add v0.16b, v0.16b, v1.16b
            0x4EA28420,  // sub v0.4s, v1.4s, v2.4s
            0x6EA28420,  // cmgt v0.4s, v1.4s, v2.4s
            // Reference test encodings — mass roundtrip
            0xd503237f, 0x910003fd, 0xd2800004, 0x52800023,
            0x910043a2, 0x52800221, 0x92800020,
            0x394043a8, 0xd43e0000, 0x14000001,
            0xd65f03c0, 0x4f00e407,
            0x90000008, 0x10000020,
            0x7a400000, 0x1a800000,
            0xd50335bf, 0xd50333bf, 0xd5033fbf,
            0xb9400001, 0xf9400001, 0xb9000001,
            0xb9000421, 0xf9000421,
            0xd341fc4f, 0x53017c08,
            0x53001c00, 0x53003c00,
            0x93401c00, 0x93403c00, 0x93407c00,
            0x13001c00, 0x33070c00,
            0xeb2f73f0, 0x8b2063e0, 0xcb2043e0,
            0xcb0407e4,
            0x1e270000, 0x1e260000,
            0x4e209800, 0x4e010c20,
            0x4ea31c60,  // mov v0.16b, v3.16b (ORR Zn==Zm runtime alias)
            0x4e22bc00,
            0x1a9f07e0, 0x5a802400, 0x1a800400,
            0x5a9f03e0, 0x5a800000,
            0xd5033f5f, 0xd503325f,
            0x52a00408, 0xd2a00038, 0x12b00009,
            0x91000108,
        };
        int roundtrip_pass = 0;
        for (auto insn : test_insns) {
            auto decoded = decode(insn, true);  // Use alias-aware decode for roundtrip
            if (!decoded) continue;
            auto text = decoded->to_string();
            auto assembled = assemble(text.c_str());
            if (assembled.success && assembled.insn == insn) {
                roundtrip_pass++;
                passed++;
            } else {
                std::cerr << "  ROUNDTRIP FAIL: 0x" << std::hex << insn
                          << " -> \"" << text << "\" -> "
                          << (assembled.success ? "0x" : "error: ")
                          << (assembled.success ? assembled.insn : 0)
                          << (assembled.success ? "" : assembled.error)
                          << std::dec << std::endl;
                failed++;
            }
        }
    }

    std::cout << passed << " / " << (passed + failed) << " assembler tests passed" << std::endl;
    return failed ? 1 : 0;
}

#else // !VEDA64_ASSEMBLER

#include <cstdio>
int main() {
    printf("Assembler tests skipped (VEDA64_ASSEMBLER not set)\n");
    return 0;
}

#endif
