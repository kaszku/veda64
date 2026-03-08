// Example: Encoding ARM64 instructions
// Build: cmake -DVEDA64_STRINGS=ON .. && cmake --build .
// Run:   ./example_encode

#include "veda64.hpp"
#include <format/format.hpp>
#include <cstdio>

using namespace veda64;
using namespace veda64::format;

int main() {
    // --- Encode individual instructions from field values ---
    printf("=== Encoding instructions ===\n");

    // ADD X0, X1, X2 (64-bit shifted register, no shift)
    uint32_t add = dpreg::encode_add_64_addsub_shift(
        /*Rd=*/0, /*Rn=*/1, /*imm6=*/0, /*Rm=*/2, /*shift=*/0);
    printf("  ADD X0, X1, X2       = 0x%08X\n", add);

    // ADD X0, X1, #10 (64-bit immediate)
    uint32_t add_imm = dpimm::encode_add_64_addsub_imm(
        /*Rd=*/0, /*Rn=*/1, /*imm12=*/10, /*sh=*/0);
    printf("  ADD X0, X1, #10      = 0x%08X\n", add_imm);

    // SUB W3, W4, W5 (32-bit shifted register)
    uint32_t sub = dpreg::encode_sub_32_addsub_shift(
        /*Rd=*/3, /*Rn=*/4, /*imm6=*/0, /*Rm=*/5, /*shift=*/0);
    printf("  SUB W3, W4, W5       = 0x%08X\n", sub);

    // MOVZ X0, #0x1234, LSL #16
    uint32_t movz = dpimm::encode_movz_64_movewide(
        /*Rd=*/0, /*imm16=*/0x1234, /*hw=*/1);
    printf("  MOVZ X0, #0x1234, LSL #16 = 0x%08X\n", movz);

    // LDR X0, [X1, #8] (unsigned offset, scaled by 8)
    uint32_t ldr = ldst::encode_ldr_64_ldst_pos(
        /*Rt=*/0, /*Rn=*/1, /*imm12=*/1);  // 1 * 8 = offset 8
    printf("  LDR X0, [X1, #8]    = 0x%08X\n", ldr);

    // STR W2, [X3, #-16]! (pre-index)
    uint32_t str = ldst::encode_str_32_ldst_immpre(
        /*Rt=*/2, /*Rn=*/3, /*imm9=*/-16);
    printf("  STR W2, [X3, #-16]! = 0x%08X\n", str);

    // B #0 (placeholder, offset 0)
    uint32_t b = control::encode_b_only_branch_imm(/*imm26=*/0);
    printf("  B #0                 = 0x%08X\n", b);

    // B.EQ #12 (offset = 12/4 = 3 instructions)
    uint32_t beq = control::encode_b_only_condbranch(
        /*cond=*/0, /*imm19=*/3);
    printf("  B.EQ #+12            = 0x%08X\n", beq);

    // RET (Rn=X30)
    uint32_t ret = control::encode_ret_64r_branch_reg(/*Rn=*/30);
    printf("  RET                  = 0x%08X\n", ret);

    // NOP
    uint32_t nop = control::encode_nop_hi_hints();
    printf("  NOP                  = 0x%08X\n", nop);

    // FADD D0, D1, D2
    uint32_t fadd = simd_dp::encode_fadd_d_floatdp2(
        /*Rd=*/0, /*Rn=*/1, /*Rm=*/2);
    printf("  FADD D0, D1, D2     = 0x%08X\n", fadd);

    // STP X0, X1, [SP, #16] (signed offset, scaled by 8)
    uint32_t stp = ldst::encode_stp_64_ldstpair_off(
        /*Rt=*/0, /*Rn=*/31, /*Rt2=*/1, /*imm7=*/2);  // 2 * 8 = 16
    printf("  STP X0, X1, [SP, #16] = 0x%08X\n", stp);

    // --- Roundtrip: encode then decode ---
    printf("\n=== Encode/Decode roundtrip ===\n");
    uint32_t encoded[] = {add, add_imm, sub, movz, ldr, str, ret, nop, fadd};
    for (uint32_t insn : encoded) {
        auto result = decode(insn);
        if (result) {
#ifdef VEDA64_STRINGS
            printf("  0x%08X -> %s\n", insn, result->to_string().c_str());
#else
            printf("  0x%08X -> mnemonic=%d\n", insn, static_cast<int>(result->mnemonic));
#endif
        }
    }

    return 0;
}
