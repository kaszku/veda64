#include "class/unknown.hpp"

namespace veda64 {
namespace Unknown {

// Internal encoding structures
// : Authenticate instruction address, using key A
// Encoding: AUTIA_64P_dp_1src
// Template: AUTIA  <Xd>, <Xn|SP>
struct Autia64pDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t Z : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Authenticate instruction address, using key A
// Encoding: AUTIZA_64Z_dp_1src
// Template: AUTIZA  <Xd>
struct Autiza64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t Z : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Authenticate instruction address, using key A
// Encoding: AUTIA1716_HI_hints
// Template: AUTIA1716
struct Autia1716HiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b100 (0x4)
    uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Authenticate instruction address, using key A
// Encoding: AUTIASP_HI_hints
// Template: AUTIASP
struct AutiaspHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b101 (0x5)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Authenticate instruction address, using key A
// Encoding: AUTIAZ_HI_hints
// Template: AUTIAZ
struct AutiazHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b100 (0x4)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Authenticate instruction address, using key B
// Encoding: AUTIB_64P_dp_1src
// Template: AUTIB  <Xd>, <Xn|SP>
struct Autib64pDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
    uint32_t Z : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Authenticate instruction address, using key B
// Encoding: AUTIZB_64Z_dp_1src
// Template: AUTIZB  <Xd>
struct Autizb64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
    uint32_t Z : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Authenticate instruction address, using key B
// Encoding: AUTIB1716_HI_hints
// Template: AUTIB1716
struct Autib1716HiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b110 (0x6)
    uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Authenticate instruction address, using key B
// Encoding: AUTIBSP_HI_hints
// Template: AUTIBSP
struct AutibspHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b111 (0x7)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Authenticate instruction address, using key B
// Encoding: AUTIBZ_HI_hints
// Template: AUTIBZ
struct AutibzHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b110 (0x6)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// FMOPA: Floating-point outer product, accumulating
// Encoding: fmopa_za_pp_zz_16
// Template: FMOPA  <ZAda>.H, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct FmopaZaPpZz16 {
    uint32_t ZAda : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPA: Floating-point outer product, accumulating
// Encoding: fmopa_za_pp_zz_32
// Template: FMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.S, <Zm>.S
struct FmopaZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPA: Floating-point outer product, accumulating
// Encoding: fmopa_za_pp_zz_64
// Template: FMOPA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.D, <Zm>.D
struct FmopaZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPS: Floating-point outer product, subtracting
// Encoding: fmops_za_pp_zz_16
// Template: FMOPS  <ZAda>.H, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct FmopsZaPpZz16 {
    uint32_t ZAda : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPS: Floating-point outer product, subtracting
// Encoding: fmops_za_pp_zz_32
// Template: FMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.S, <Zm>.S
struct FmopsZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPS: Floating-point outer product, subtracting
// Encoding: fmops_za_pp_zz_64
// Template: FMOPS  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.D, <Zm>.D
struct FmopsZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1D: Contiguous load unsigned doublewords to vector (immediate index)
// Encoding: ld1d_z_p_bi_u64
// Template: LD1D  { <Zt>.D }, <Pg>/Z, [<Xn|SP>{, #<imm>, MUL VL}]
struct Ld1dZPBiU64 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t dtype : 4;  // fixed: 0b1111 (0xF)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1D: Contiguous load unsigned doublewords to vector (immediate index)
// Encoding: ld1d_z_p_bi_u128
// Template: LD1D  { <Zt>.Q }, <Pg>/Z, [<Xn|SP>{, #<imm>, MUL VL}]
struct Ld1dZPBiU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 3;  // fixed: 0b001 (0x1)
    uint32_t imm4 : 4;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t dtype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1D: Contiguous load unsigned doublewords to vector (scalar index)
// Encoding: ld1d_z_p_br_u64
// Template: LD1D  { <Zt>.D }, <Pg>/Z, [<Xn|SP>, <Xm>, LSL #3]
struct Ld1dZPBrU64 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t dtype : 4;  // fixed: 0b1111 (0xF)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1D: Contiguous load unsigned doublewords to vector (scalar index)
// Encoding: ld1d_z_p_br_u128
// Template: LD1D  { <Zt>.Q }, <Pg>/Z, [<Xn|SP>, <Xm>, LSL #3]
struct Ld1dZPBrU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t dtype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (immediate index)
// Encoding: ld1w_z_p_bi_u32
// Template: LD1W  { <Zt>.S }, <Pg>/Z, [<Xn|SP>{, #<imm>, MUL VL}]
struct Ld1wZPBiU32 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t dtype : 4;  // fixed: 0b1010 (0xA)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (immediate index)
// Encoding: ld1w_z_p_bi_u64
// Template: LD1W  { <Zt>.D }, <Pg>/Z, [<Xn|SP>{, #<imm>, MUL VL}]
struct Ld1wZPBiU64 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b101 (0x5)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t dtype : 4;  // fixed: 0b1011 (0xB)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (immediate index)
// Encoding: ld1w_z_p_bi_u128
// Template: LD1W  { <Zt>.Q }, <Pg>/Z, [<Xn|SP>{, #<imm>, MUL VL}]
struct Ld1wZPBiU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 3;  // fixed: 0b001 (0x1)
    uint32_t imm4 : 4;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t dtype : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (scalar index)
// Encoding: ld1w_z_p_br_u32
// Template: LD1W  { <Zt>.S }, <Pg>/Z, [<Xn|SP>, <Xm>, LSL #2]
struct Ld1wZPBrU32 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t dtype : 4;  // fixed: 0b1010 (0xA)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (scalar index)
// Encoding: ld1w_z_p_br_u64
// Template: LD1W  { <Zt>.D }, <Pg>/Z, [<Xn|SP>, <Xm>, LSL #2]
struct Ld1wZPBrU64 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_2 : 3;  // fixed: 0b010 (0x2)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t dtype : 4;  // fixed: 0b1011 (0xB)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// LD1W: Contiguous load unsigned words to vector (scalar index)
// Encoding: ld1w_z_p_br_u128
// Template: LD1W  { <Zt>.Q }, <Pg>/Z, [<Xn|SP>, <Xm>, LSL #2]
struct Ld1wZPBrU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t dtype : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
};


// : Load register, with pointer authentication
// Encoding: LDRAA_64_ldst_pac
// Template: LDRAA  <Xt>, [<Xn|SP>{, #<simm>}]
struct Ldraa64LdstPac {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t W : 1;  // fixed: 0b0 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;
    uint32_t M : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// : Load register, with pointer authentication
// Encoding: LDRAA_64W_ldst_pac
// Template: LDRAA  <Xt>, [<Xn|SP>{, #<simm>}]!
struct Ldraa64wLdstPac {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t W : 1;  // fixed: 0b1 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;
    uint32_t M : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// : Load register, with pointer authentication
// Encoding: LDRAB_64_ldst_pac
// Template: LDRAB  <Xt>, [<Xn|SP>{, #<simm>}]
struct Ldrab64LdstPac {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t W : 1;  // fixed: 0b0 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;
    uint32_t M : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// : Load register, with pointer authentication
// Encoding: LDRAB_64W_ldst_pac
// Template: LDRAB  <Xt>, [<Xn|SP>{, #<simm>}]!
struct Ldrab64wLdstPac {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t W : 1;  // fixed: 0b1 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;
    uint32_t M : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// : Pointer Authentication Code for instruction address, using key A
// Encoding: PACIA_64P_dp_1src
// Template: PACIA  <Xd>, <Xn|SP>
struct Pacia64pDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 3;  // fixed: 0b000 (0x0)
    uint32_t Z : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Pointer Authentication Code for instruction address, using key A
// Encoding: PACIZA_64Z_dp_1src
// Template: PACIZA  <Xd>
struct Paciza64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t _unnamed_3 : 3;  // fixed: 0b000 (0x0)
    uint32_t Z : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Pointer Authentication Code for instruction address, using key A
// Encoding: PACIA1716_HI_hints
// Template: PACIA1716
struct Pacia1716HiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b000 (0x0)
    uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Pointer Authentication Code for instruction address, using key A
// Encoding: PACIASP_HI_hints
// Template: PACIASP
struct PaciaspHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b001 (0x1)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Pointer Authentication Code for instruction address, using key A
// Encoding: PACIAZ_HI_hints
// Template: PACIAZ
struct PaciazHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b000 (0x0)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Pointer Authentication Code for instruction address, using key B
// Encoding: PACIB_64P_dp_1src
// Template: PACIB  <Xd>, <Xn|SP>
struct Pacib64pDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Z : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Pointer Authentication Code for instruction address, using key B
// Encoding: PACIZB_64Z_dp_1src
// Template: PACIZB  <Xd>
struct Pacizb64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Z : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Pointer Authentication Code for instruction address, using key B
// Encoding: PACIB1716_HI_hints
// Template: PACIB1716
struct Pacib1716HiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b010 (0x2)
    uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Pointer Authentication Code for instruction address, using key B
// Encoding: PACIBSP_HI_hints
// Template: PACIBSP
struct PacibspHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b011 (0x3)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// : Pointer Authentication Code for instruction address, using key B
// Encoding: PACIBZ_HI_hints
// Template: PACIBZ
struct PacibzHiHints {
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b010 (0x2)
    uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
    uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
};


// ST1D: Contiguous store doublewords from vector (immediate index)
// Encoding: st1d_z_p_bi_
// Template: ST1D  { <Zt>.D }, <Pg>, [<Xn|SP>{, #<imm>, MUL VL}]
struct St1dZPBi {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b111 (0x7)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t msz : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1D: Contiguous store doublewords from vector (immediate index)
// Encoding: st1d_z_p_bi_u128
// Template: ST1D  { <Zt>.Q }, <Pg>, [<Xn|SP>{, #<imm>, MUL VL}]
struct St1dZPBiU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b111 (0x7)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t msz : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1D: Contiguous store doublewords from vector (scalar index)
// Encoding: st1d_z_p_br_
// Template: ST1D  { <Zt>.D }, <Pg>, [<Xn|SP>, <Xm>, LSL #3]
struct St1dZPBr {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t o2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1D: Contiguous store doublewords from vector (scalar index)
// Encoding: st1d_z_p_br_u128
// Template: ST1D  { <Zt>.Q }, <Pg>, [<Xn|SP>, <Xm>, LSL #3]
struct St1dZPBrU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t o2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1W: Contiguous store words from vector (immediate index)
// Encoding: st1w_z_p_bi_
// Template: ST1W  { <Zt>.<T> }, <Pg>, [<Xn|SP>{, #<imm>, MUL VL}]
struct St1wZPBi {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 3;  // fixed: 0b111 (0x7)
    uint32_t imm4 : 4;
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t sz : 1;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t msz : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1W: Contiguous store words from vector (immediate index)
// Encoding: st1w_z_p_bi_u128
// Template: ST1W  { <Zt>.Q }, <Pg>, [<Xn|SP>{, #<imm>, MUL VL}]
struct St1wZPBiU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_3 : 3;  // fixed: 0b111 (0x7)
    uint32_t imm4 : 4;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t msz : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1W: Contiguous store words from vector (scalar index)
// Encoding: st1w_z_p_br_
// Template: ST1W  { <Zt>.<T> }, <Pg>, [<Xn|SP>, <Xm>, LSL #2]
struct St1wZPBr {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t sz : 1;
    uint32_t opc : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// ST1W: Contiguous store words from vector (scalar index)
// Encoding: st1w_z_p_br_u128
// Template: ST1W  { <Zt>.Q }, <Pg>, [<Xn|SP>, <Xm>, LSL #2]
struct St1wZPBrU128 {
    uint32_t Zt : 5;
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;  // partial: != 11111
    uint32_t o2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
};


// TBL: Programmable table lookup in one or two vector table (zeroing)
// Encoding: tbl_z_zz_1
// Template: TBL  <Zd>.<T>, { <Zn>.<T> }, <Zm>.<T>
struct TblZZz1 {
    uint32_t Zd : 5;
    uint32_t Zn : 5;
    uint32_t _unnamed_4 : 6;  // fixed: 0b001100 (0xC)
    uint32_t Zm : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t size : 2;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b000 (0x0)
};


// TBL: Programmable table lookup in one or two vector table (zeroing)
// Encoding: tbl_z_zz_2
// Template: TBL  <Zd>.<T>, { <Zn1>.<T>, <Zn2>.<T> }, <Zm>.<T>
struct TblZZz2 {
    uint32_t Zd : 5;
    uint32_t Zn : 5;
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 5;  // fixed: 0b00101 (0x5)
    uint32_t Zm : 5;
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t size : 2;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b000 (0x0)
};


// : Strip Pointer Authentication Code
// Encoding: XPACD_64Z_dp_1src
// Template: XPACD  <Xd>
struct Xpacd64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t D : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b01000 (0x8)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Strip Pointer Authentication Code
// Encoding: XPACI_64Z_dp_1src
// Template: XPACI  <Xd>
struct Xpaci64zDp1src {
    uint32_t Rd : 5;
    uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
    uint32_t D : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b01000 (0x8)
    uint32_t opcode2 : 5;  // fixed: 0b00001 (0x1)
    uint32_t _unnamed_1 : 8;  // fixed: 0b11010110 (0xD6)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// : Strip Pointer Authentication Code
// Encoding: XPACLRI_HI_hints
// Template: XPACLRI
struct XpaclriHiHints {
    uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b111 (0x7)
    uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
    uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
};


// Union for unknown instruction class
union UnknownEncoding {
    Autia64pDp1src autia64p_dp1src;
    Autiza64zDp1src autiza64z_dp1src;
    Autia1716HiHints autia1716hi_hints;
    AutiaspHiHints autiasp_hi_hints;
    AutiazHiHints autiaz_hi_hints;
    Autib64pDp1src autib64p_dp1src;
    Autizb64zDp1src autizb64z_dp1src;
    Autib1716HiHints autib1716hi_hints;
    AutibspHiHints autibsp_hi_hints;
    AutibzHiHints autibz_hi_hints;
    FmopaZaPpZz16 fmopa_za_pp_zz16;
    FmopaZaPpZz32 fmopa_za_pp_zz32;
    FmopaZaPpZz64 fmopa_za_pp_zz64;
    FmopsZaPpZz16 fmops_za_pp_zz16;
    FmopsZaPpZz32 fmops_za_pp_zz32;
    FmopsZaPpZz64 fmops_za_pp_zz64;
    Ld1dZPBiU64 ld1d_zpbi_u64;
    Ld1dZPBiU128 ld1d_zpbi_u128;
    Ld1dZPBrU64 ld1d_zpbr_u64;
    Ld1dZPBrU128 ld1d_zpbr_u128;
    Ld1wZPBiU32 ld1w_zpbi_u32;
    Ld1wZPBiU64 ld1w_zpbi_u64;
    Ld1wZPBiU128 ld1w_zpbi_u128;
    Ld1wZPBrU32 ld1w_zpbr_u32;
    Ld1wZPBrU64 ld1w_zpbr_u64;
    Ld1wZPBrU128 ld1w_zpbr_u128;
    Ldraa64LdstPac ldraa64ldst_pac;
    Ldraa64wLdstPac ldraa64w_ldst_pac;
    Ldrab64LdstPac ldrab64ldst_pac;
    Ldrab64wLdstPac ldrab64w_ldst_pac;
    Pacia64pDp1src pacia64p_dp1src;
    Paciza64zDp1src paciza64z_dp1src;
    Pacia1716HiHints pacia1716hi_hints;
    PaciaspHiHints paciasp_hi_hints;
    PaciazHiHints paciaz_hi_hints;
    Pacib64pDp1src pacib64p_dp1src;
    Pacizb64zDp1src pacizb64z_dp1src;
    Pacib1716HiHints pacib1716hi_hints;
    PacibspHiHints pacibsp_hi_hints;
    PacibzHiHints pacibz_hi_hints;
    St1dZPBi st1d_zpbi;
    St1dZPBiU128 st1d_zpbi_u128;
    St1dZPBr st1d_zpbr;
    St1dZPBrU128 st1d_zpbr_u128;
    St1wZPBi st1w_zpbi;
    St1wZPBiU128 st1w_zpbi_u128;
    St1wZPBr st1w_zpbr;
    St1wZPBrU128 st1w_zpbr_u128;
    TblZZz1 tbl_zzz1;
    TblZZz2 tbl_zzz2;
    Xpacd64zDp1src xpacd64z_dp1src;
    Xpaci64zDp1src xpaci64z_dp1src;
    XpaclriHiHints xpaclri_hi_hints;
    uint32_t raw;
};
static_assert(sizeof(UnknownEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_autia_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    UnknownEncoding insn = {};
    insn.autia64p_dp1src.Rd = Rd;
    insn.autia64p_dp1src.Rn = Rn;
    insn.autia64p_dp1src._unnamed_3 = 0b100;
    insn.autia64p_dp1src.Z = 0b0;
    insn.autia64p_dp1src._unnamed_2 = 0b00;
    insn.autia64p_dp1src.opcode2 = 0b00001;
    insn.autia64p_dp1src._unnamed_1 = 0b11010110;
    insn.autia64p_dp1src.S = 0b0;
    insn.autia64p_dp1src._unnamed_0 = 0b1;
    insn.autia64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autiza_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.autiza64z_dp1src.Rd = Rd;
    insn.autiza64z_dp1src.Rn = 0b11111;
    insn.autiza64z_dp1src._unnamed_3 = 0b100;
    insn.autiza64z_dp1src.Z = 0b1;
    insn.autiza64z_dp1src._unnamed_2 = 0b00;
    insn.autiza64z_dp1src.opcode2 = 0b00001;
    insn.autiza64z_dp1src._unnamed_1 = 0b11010110;
    insn.autiza64z_dp1src.S = 0b0;
    insn.autiza64z_dp1src._unnamed_0 = 0b1;
    insn.autiza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autia1716_hi_hints() {
    UnknownEncoding insn = {};
    insn.autia1716hi_hints._unnamed_1 = 0b11111;
    insn.autia1716hi_hints.op2 = 0b100;
    insn.autia1716hi_hints.CRm = 0b0001;
    insn.autia1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autiasp_hi_hints() {
    UnknownEncoding insn = {};
    insn.autiasp_hi_hints._unnamed_1 = 0b11111;
    insn.autiasp_hi_hints.op2 = 0b101;
    insn.autiasp_hi_hints.CRm = 0b0011;
    insn.autiasp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autiaz_hi_hints() {
    UnknownEncoding insn = {};
    insn.autiaz_hi_hints._unnamed_1 = 0b11111;
    insn.autiaz_hi_hints.op2 = 0b100;
    insn.autiaz_hi_hints.CRm = 0b0011;
    insn.autiaz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autib_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    UnknownEncoding insn = {};
    insn.autib64p_dp1src.Rd = Rd;
    insn.autib64p_dp1src.Rn = Rn;
    insn.autib64p_dp1src._unnamed_3 = 0b101;
    insn.autib64p_dp1src.Z = 0b0;
    insn.autib64p_dp1src._unnamed_2 = 0b00;
    insn.autib64p_dp1src.opcode2 = 0b00001;
    insn.autib64p_dp1src._unnamed_1 = 0b11010110;
    insn.autib64p_dp1src.S = 0b0;
    insn.autib64p_dp1src._unnamed_0 = 0b1;
    insn.autib64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autizb_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.autizb64z_dp1src.Rd = Rd;
    insn.autizb64z_dp1src.Rn = 0b11111;
    insn.autizb64z_dp1src._unnamed_3 = 0b101;
    insn.autizb64z_dp1src.Z = 0b1;
    insn.autizb64z_dp1src._unnamed_2 = 0b00;
    insn.autizb64z_dp1src.opcode2 = 0b00001;
    insn.autizb64z_dp1src._unnamed_1 = 0b11010110;
    insn.autizb64z_dp1src.S = 0b0;
    insn.autizb64z_dp1src._unnamed_0 = 0b1;
    insn.autizb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_autib1716_hi_hints() {
    UnknownEncoding insn = {};
    insn.autib1716hi_hints._unnamed_1 = 0b11111;
    insn.autib1716hi_hints.op2 = 0b110;
    insn.autib1716hi_hints.CRm = 0b0001;
    insn.autib1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autibsp_hi_hints() {
    UnknownEncoding insn = {};
    insn.autibsp_hi_hints._unnamed_1 = 0b11111;
    insn.autibsp_hi_hints.op2 = 0b111;
    insn.autibsp_hi_hints.CRm = 0b0011;
    insn.autibsp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autibz_hi_hints() {
    UnknownEncoding insn = {};
    insn.autibz_hi_hints._unnamed_1 = 0b11111;
    insn.autibz_hi_hints.op2 = 0b110;
    insn.autibz_hi_hints.CRm = 0b0011;
    insn.autibz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_fmopa_za_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmopa_za_pp_zz16.ZAda = ZAda;
    insn.fmopa_za_pp_zz16._unnamed_7 = 0b0;
    insn.fmopa_za_pp_zz16._unnamed_6 = 0b10;
    insn.fmopa_za_pp_zz16.S = 0b0;
    insn.fmopa_za_pp_zz16.Zn = Zn;
    insn.fmopa_za_pp_zz16.Pn = Pn;
    insn.fmopa_za_pp_zz16.Pm = Pm;
    insn.fmopa_za_pp_zz16.Zm = Zm;
    insn.fmopa_za_pp_zz16._unnamed_5 = 0b0;
    insn.fmopa_za_pp_zz16._unnamed_4 = 0b10;
    insn.fmopa_za_pp_zz16._unnamed_3 = 0b1;
    insn.fmopa_za_pp_zz16._unnamed_2 = 0b0000;
    insn.fmopa_za_pp_zz16._unnamed_1 = 0b00;
    insn.fmopa_za_pp_zz16._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmopa_za_pp_zz32.ZAda = ZAda;
    insn.fmopa_za_pp_zz32._unnamed_6 = 0b00;
    insn.fmopa_za_pp_zz32.S = 0b0;
    insn.fmopa_za_pp_zz32.Zn = Zn;
    insn.fmopa_za_pp_zz32.Pn = Pn;
    insn.fmopa_za_pp_zz32.Pm = Pm;
    insn.fmopa_za_pp_zz32.Zm = Zm;
    insn.fmopa_za_pp_zz32._unnamed_5 = 0b0;
    insn.fmopa_za_pp_zz32._unnamed_4 = 0b10;
    insn.fmopa_za_pp_zz32._unnamed_3 = 0b0;
    insn.fmopa_za_pp_zz32._unnamed_2 = 0b0000;
    insn.fmopa_za_pp_zz32._unnamed_1 = 0b00;
    insn.fmopa_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmopa_za_pp_zz64.ZAda = ZAda;
    insn.fmopa_za_pp_zz64._unnamed_7 = 0b0;
    insn.fmopa_za_pp_zz64.S = 0b0;
    insn.fmopa_za_pp_zz64.Zn = Zn;
    insn.fmopa_za_pp_zz64.Pn = Pn;
    insn.fmopa_za_pp_zz64.Pm = Pm;
    insn.fmopa_za_pp_zz64.Zm = Zm;
    insn.fmopa_za_pp_zz64._unnamed_6 = 0b0;
    insn.fmopa_za_pp_zz64._unnamed_5 = 0b11;
    insn.fmopa_za_pp_zz64._unnamed_4 = 0b0;
    insn.fmopa_za_pp_zz64._unnamed_3 = 0b0000;
    insn.fmopa_za_pp_zz64._unnamed_2 = 0b0;
    insn.fmopa_za_pp_zz64._unnamed_1 = 0b0;
    insn.fmopa_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmops_za_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmops_za_pp_zz16.ZAda = ZAda;
    insn.fmops_za_pp_zz16._unnamed_7 = 0b0;
    insn.fmops_za_pp_zz16._unnamed_6 = 0b10;
    insn.fmops_za_pp_zz16.S = 0b1;
    insn.fmops_za_pp_zz16.Zn = Zn;
    insn.fmops_za_pp_zz16.Pn = Pn;
    insn.fmops_za_pp_zz16.Pm = Pm;
    insn.fmops_za_pp_zz16.Zm = Zm;
    insn.fmops_za_pp_zz16._unnamed_5 = 0b0;
    insn.fmops_za_pp_zz16._unnamed_4 = 0b10;
    insn.fmops_za_pp_zz16._unnamed_3 = 0b1;
    insn.fmops_za_pp_zz16._unnamed_2 = 0b0000;
    insn.fmops_za_pp_zz16._unnamed_1 = 0b00;
    insn.fmops_za_pp_zz16._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmops_za_pp_zz32.ZAda = ZAda;
    insn.fmops_za_pp_zz32._unnamed_6 = 0b00;
    insn.fmops_za_pp_zz32.S = 0b1;
    insn.fmops_za_pp_zz32.Zn = Zn;
    insn.fmops_za_pp_zz32.Pn = Pn;
    insn.fmops_za_pp_zz32.Pm = Pm;
    insn.fmops_za_pp_zz32.Zm = Zm;
    insn.fmops_za_pp_zz32._unnamed_5 = 0b0;
    insn.fmops_za_pp_zz32._unnamed_4 = 0b10;
    insn.fmops_za_pp_zz32._unnamed_3 = 0b0;
    insn.fmops_za_pp_zz32._unnamed_2 = 0b0000;
    insn.fmops_za_pp_zz32._unnamed_1 = 0b00;
    insn.fmops_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    UnknownEncoding insn = {};
    insn.fmops_za_pp_zz64.ZAda = ZAda;
    insn.fmops_za_pp_zz64._unnamed_7 = 0b0;
    insn.fmops_za_pp_zz64.S = 0b1;
    insn.fmops_za_pp_zz64.Zn = Zn;
    insn.fmops_za_pp_zz64.Pn = Pn;
    insn.fmops_za_pp_zz64.Pm = Pm;
    insn.fmops_za_pp_zz64.Zm = Zm;
    insn.fmops_za_pp_zz64._unnamed_6 = 0b0;
    insn.fmops_za_pp_zz64._unnamed_5 = 0b11;
    insn.fmops_za_pp_zz64._unnamed_4 = 0b0;
    insn.fmops_za_pp_zz64._unnamed_3 = 0b0000;
    insn.fmops_za_pp_zz64._unnamed_2 = 0b0;
    insn.fmops_za_pp_zz64._unnamed_1 = 0b0;
    insn.fmops_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1d_z_p_bi_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.ld1d_zpbi_u64.Zt = Zt;
    insn.ld1d_zpbi_u64.Rn = Rn;
    insn.ld1d_zpbi_u64.Pg = Pg;
    insn.ld1d_zpbi_u64._unnamed_3 = 0b101;
    insn.ld1d_zpbi_u64.imm4 = imm4;
    insn.ld1d_zpbi_u64._unnamed_2 = 0b0;
    insn.ld1d_zpbi_u64.dtype = 0b1111;
    insn.ld1d_zpbi_u64._unnamed_1 = 0b0010;
    insn.ld1d_zpbi_u64._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1d_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.ld1d_zpbi_u128.Zt = Zt;
    insn.ld1d_zpbi_u128.Rn = Rn;
    insn.ld1d_zpbi_u128.Pg = Pg;
    insn.ld1d_zpbi_u128._unnamed_4 = 0b001;
    insn.ld1d_zpbi_u128.imm4 = imm4;
    insn.ld1d_zpbi_u128._unnamed_3 = 0b1;
    insn.ld1d_zpbi_u128._unnamed_2 = 0b00;
    insn.ld1d_zpbi_u128.dtype = 0b11;
    insn.ld1d_zpbi_u128._unnamed_1 = 0b0010;
    insn.ld1d_zpbi_u128._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1d_z_p_br_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.ld1d_zpbr_u64.Zt = Zt;
    insn.ld1d_zpbr_u64.Rn = Rn;
    insn.ld1d_zpbr_u64.Pg = Pg;
    insn.ld1d_zpbr_u64._unnamed_2 = 0b010;
    insn.ld1d_zpbr_u64.Rm = Rm;
    insn.ld1d_zpbr_u64.dtype = 0b1111;
    insn.ld1d_zpbr_u64._unnamed_1 = 0b0010;
    insn.ld1d_zpbr_u64._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1d_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.ld1d_zpbr_u128.Zt = Zt;
    insn.ld1d_zpbr_u128.Rn = Rn;
    insn.ld1d_zpbr_u128.Pg = Pg;
    insn.ld1d_zpbr_u128._unnamed_3 = 0b100;
    insn.ld1d_zpbr_u128.Rm = Rm;
    insn.ld1d_zpbr_u128._unnamed_2 = 0b00;
    insn.ld1d_zpbr_u128.dtype = 0b11;
    insn.ld1d_zpbr_u128._unnamed_1 = 0b0010;
    insn.ld1d_zpbr_u128._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_bi_u32(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbi_u32.Zt = Zt;
    insn.ld1w_zpbi_u32.Rn = Rn;
    insn.ld1w_zpbi_u32.Pg = Pg;
    insn.ld1w_zpbi_u32._unnamed_3 = 0b101;
    insn.ld1w_zpbi_u32.imm4 = imm4;
    insn.ld1w_zpbi_u32._unnamed_2 = 0b0;
    insn.ld1w_zpbi_u32.dtype = 0b1010;
    insn.ld1w_zpbi_u32._unnamed_1 = 0b0010;
    insn.ld1w_zpbi_u32._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_bi_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbi_u64.Zt = Zt;
    insn.ld1w_zpbi_u64.Rn = Rn;
    insn.ld1w_zpbi_u64.Pg = Pg;
    insn.ld1w_zpbi_u64._unnamed_3 = 0b101;
    insn.ld1w_zpbi_u64.imm4 = imm4;
    insn.ld1w_zpbi_u64._unnamed_2 = 0b0;
    insn.ld1w_zpbi_u64.dtype = 0b1011;
    insn.ld1w_zpbi_u64._unnamed_1 = 0b0010;
    insn.ld1w_zpbi_u64._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbi_u128.Zt = Zt;
    insn.ld1w_zpbi_u128.Rn = Rn;
    insn.ld1w_zpbi_u128.Pg = Pg;
    insn.ld1w_zpbi_u128._unnamed_4 = 0b001;
    insn.ld1w_zpbi_u128.imm4 = imm4;
    insn.ld1w_zpbi_u128._unnamed_3 = 0b1;
    insn.ld1w_zpbi_u128._unnamed_2 = 0b00;
    insn.ld1w_zpbi_u128.dtype = 0b10;
    insn.ld1w_zpbi_u128._unnamed_1 = 0b0010;
    insn.ld1w_zpbi_u128._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_br_u32(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbr_u32.Zt = Zt;
    insn.ld1w_zpbr_u32.Rn = Rn;
    insn.ld1w_zpbr_u32.Pg = Pg;
    insn.ld1w_zpbr_u32._unnamed_2 = 0b010;
    insn.ld1w_zpbr_u32.Rm = Rm;
    insn.ld1w_zpbr_u32.dtype = 0b1010;
    insn.ld1w_zpbr_u32._unnamed_1 = 0b0010;
    insn.ld1w_zpbr_u32._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_br_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbr_u64.Zt = Zt;
    insn.ld1w_zpbr_u64.Rn = Rn;
    insn.ld1w_zpbr_u64.Pg = Pg;
    insn.ld1w_zpbr_u64._unnamed_2 = 0b010;
    insn.ld1w_zpbr_u64.Rm = Rm;
    insn.ld1w_zpbr_u64.dtype = 0b1011;
    insn.ld1w_zpbr_u64._unnamed_1 = 0b0010;
    insn.ld1w_zpbr_u64._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ld1w_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.ld1w_zpbr_u128.Zt = Zt;
    insn.ld1w_zpbr_u128.Rn = Rn;
    insn.ld1w_zpbr_u128.Pg = Pg;
    insn.ld1w_zpbr_u128._unnamed_3 = 0b100;
    insn.ld1w_zpbr_u128.Rm = Rm;
    insn.ld1w_zpbr_u128._unnamed_2 = 0b00;
    insn.ld1w_zpbr_u128.dtype = 0b10;
    insn.ld1w_zpbr_u128._unnamed_1 = 0b0010;
    insn.ld1w_zpbr_u128._unnamed_0 = 0b101;
    return insn.raw;
}

uint32_t encode_ldraa_64_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S) {
    UnknownEncoding insn = {};
    insn.ldraa64ldst_pac.Rt = Rt;
    insn.ldraa64ldst_pac.Rn = Rn;
    insn.ldraa64ldst_pac._unnamed_3 = 0b1;
    insn.ldraa64ldst_pac.W = 0b0;
    insn.ldraa64ldst_pac.imm9 = imm9;
    insn.ldraa64ldst_pac._unnamed_2 = 0b1;
    insn.ldraa64ldst_pac.S = S;
    insn.ldraa64ldst_pac.M = 0b0;
    insn.ldraa64ldst_pac._unnamed_1 = 0b00;
    insn.ldraa64ldst_pac.VR = 0b0;
    insn.ldraa64ldst_pac._unnamed_0 = 0b111;
    insn.ldraa64ldst_pac.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldraa_64w_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S) {
    UnknownEncoding insn = {};
    insn.ldraa64w_ldst_pac.Rt = Rt;
    insn.ldraa64w_ldst_pac.Rn = Rn;
    insn.ldraa64w_ldst_pac._unnamed_3 = 0b1;
    insn.ldraa64w_ldst_pac.W = 0b1;
    insn.ldraa64w_ldst_pac.imm9 = imm9;
    insn.ldraa64w_ldst_pac._unnamed_2 = 0b1;
    insn.ldraa64w_ldst_pac.S = S;
    insn.ldraa64w_ldst_pac.M = 0b0;
    insn.ldraa64w_ldst_pac._unnamed_1 = 0b00;
    insn.ldraa64w_ldst_pac.VR = 0b0;
    insn.ldraa64w_ldst_pac._unnamed_0 = 0b111;
    insn.ldraa64w_ldst_pac.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldrab_64_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S) {
    UnknownEncoding insn = {};
    insn.ldrab64ldst_pac.Rt = Rt;
    insn.ldrab64ldst_pac.Rn = Rn;
    insn.ldrab64ldst_pac._unnamed_3 = 0b1;
    insn.ldrab64ldst_pac.W = 0b0;
    insn.ldrab64ldst_pac.imm9 = imm9;
    insn.ldrab64ldst_pac._unnamed_2 = 0b1;
    insn.ldrab64ldst_pac.S = S;
    insn.ldrab64ldst_pac.M = 0b1;
    insn.ldrab64ldst_pac._unnamed_1 = 0b00;
    insn.ldrab64ldst_pac.VR = 0b0;
    insn.ldrab64ldst_pac._unnamed_0 = 0b111;
    insn.ldrab64ldst_pac.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldrab_64w_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S) {
    UnknownEncoding insn = {};
    insn.ldrab64w_ldst_pac.Rt = Rt;
    insn.ldrab64w_ldst_pac.Rn = Rn;
    insn.ldrab64w_ldst_pac._unnamed_3 = 0b1;
    insn.ldrab64w_ldst_pac.W = 0b1;
    insn.ldrab64w_ldst_pac.imm9 = imm9;
    insn.ldrab64w_ldst_pac._unnamed_2 = 0b1;
    insn.ldrab64w_ldst_pac.S = S;
    insn.ldrab64w_ldst_pac.M = 0b1;
    insn.ldrab64w_ldst_pac._unnamed_1 = 0b00;
    insn.ldrab64w_ldst_pac.VR = 0b0;
    insn.ldrab64w_ldst_pac._unnamed_0 = 0b111;
    insn.ldrab64w_ldst_pac.size = 0b11;
    return insn.raw;
}

uint32_t encode_pacia_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    UnknownEncoding insn = {};
    insn.pacia64p_dp1src.Rd = Rd;
    insn.pacia64p_dp1src.Rn = Rn;
    insn.pacia64p_dp1src._unnamed_3 = 0b000;
    insn.pacia64p_dp1src.Z = 0b0;
    insn.pacia64p_dp1src._unnamed_2 = 0b00;
    insn.pacia64p_dp1src.opcode2 = 0b00001;
    insn.pacia64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacia64p_dp1src.S = 0b0;
    insn.pacia64p_dp1src._unnamed_0 = 0b1;
    insn.pacia64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_paciza_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.paciza64z_dp1src.Rd = Rd;
    insn.paciza64z_dp1src.Rn = 0b11111;
    insn.paciza64z_dp1src._unnamed_3 = 0b000;
    insn.paciza64z_dp1src.Z = 0b1;
    insn.paciza64z_dp1src._unnamed_2 = 0b00;
    insn.paciza64z_dp1src.opcode2 = 0b00001;
    insn.paciza64z_dp1src._unnamed_1 = 0b11010110;
    insn.paciza64z_dp1src.S = 0b0;
    insn.paciza64z_dp1src._unnamed_0 = 0b1;
    insn.paciza64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacia1716_hi_hints() {
    UnknownEncoding insn = {};
    insn.pacia1716hi_hints._unnamed_1 = 0b11111;
    insn.pacia1716hi_hints.op2 = 0b000;
    insn.pacia1716hi_hints.CRm = 0b0001;
    insn.pacia1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_paciasp_hi_hints() {
    UnknownEncoding insn = {};
    insn.paciasp_hi_hints._unnamed_1 = 0b11111;
    insn.paciasp_hi_hints.op2 = 0b001;
    insn.paciasp_hi_hints.CRm = 0b0011;
    insn.paciasp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_paciaz_hi_hints() {
    UnknownEncoding insn = {};
    insn.paciaz_hi_hints._unnamed_1 = 0b11111;
    insn.paciaz_hi_hints.op2 = 0b000;
    insn.paciaz_hi_hints.CRm = 0b0011;
    insn.paciaz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacib_64p_dp_1src(uint32_t Rd, uint32_t Rn) {
    UnknownEncoding insn = {};
    insn.pacib64p_dp1src.Rd = Rd;
    insn.pacib64p_dp1src.Rn = Rn;
    insn.pacib64p_dp1src._unnamed_3 = 0b001;
    insn.pacib64p_dp1src.Z = 0b0;
    insn.pacib64p_dp1src._unnamed_2 = 0b00;
    insn.pacib64p_dp1src.opcode2 = 0b00001;
    insn.pacib64p_dp1src._unnamed_1 = 0b11010110;
    insn.pacib64p_dp1src.S = 0b0;
    insn.pacib64p_dp1src._unnamed_0 = 0b1;
    insn.pacib64p_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacizb_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.pacizb64z_dp1src.Rd = Rd;
    insn.pacizb64z_dp1src.Rn = 0b11111;
    insn.pacizb64z_dp1src._unnamed_3 = 0b001;
    insn.pacizb64z_dp1src.Z = 0b1;
    insn.pacizb64z_dp1src._unnamed_2 = 0b00;
    insn.pacizb64z_dp1src.opcode2 = 0b00001;
    insn.pacizb64z_dp1src._unnamed_1 = 0b11010110;
    insn.pacizb64z_dp1src.S = 0b0;
    insn.pacizb64z_dp1src._unnamed_0 = 0b1;
    insn.pacizb64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_pacib1716_hi_hints() {
    UnknownEncoding insn = {};
    insn.pacib1716hi_hints._unnamed_1 = 0b11111;
    insn.pacib1716hi_hints.op2 = 0b010;
    insn.pacib1716hi_hints.CRm = 0b0001;
    insn.pacib1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacibsp_hi_hints() {
    UnknownEncoding insn = {};
    insn.pacibsp_hi_hints._unnamed_1 = 0b11111;
    insn.pacibsp_hi_hints.op2 = 0b011;
    insn.pacibsp_hi_hints.CRm = 0b0011;
    insn.pacibsp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacibz_hi_hints() {
    UnknownEncoding insn = {};
    insn.pacibz_hi_hints._unnamed_1 = 0b11111;
    insn.pacibz_hi_hints.op2 = 0b010;
    insn.pacibz_hi_hints.CRm = 0b0011;
    insn.pacibz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_st1d_z_p_bi_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.st1d_zpbi.Zt = Zt;
    insn.st1d_zpbi.Rn = Rn;
    insn.st1d_zpbi.Pg = Pg;
    insn.st1d_zpbi._unnamed_3 = 0b111;
    insn.st1d_zpbi.imm4 = imm4;
    insn.st1d_zpbi._unnamed_2 = 0b0;
    insn.st1d_zpbi.opc = 0b11;
    insn.st1d_zpbi.msz = 0b11;
    insn.st1d_zpbi._unnamed_1 = 0b0010;
    insn.st1d_zpbi._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1d_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.st1d_zpbi_u128.Zt = Zt;
    insn.st1d_zpbi_u128.Rn = Rn;
    insn.st1d_zpbi_u128.Pg = Pg;
    insn.st1d_zpbi_u128._unnamed_3 = 0b111;
    insn.st1d_zpbi_u128.imm4 = imm4;
    insn.st1d_zpbi_u128._unnamed_2 = 0b0;
    insn.st1d_zpbi_u128.opc = 0b10;
    insn.st1d_zpbi_u128.msz = 0b11;
    insn.st1d_zpbi_u128._unnamed_1 = 0b0010;
    insn.st1d_zpbi_u128._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1d_z_p_br_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.st1d_zpbr.Zt = Zt;
    insn.st1d_zpbr.Rn = Rn;
    insn.st1d_zpbr.Pg = Pg;
    insn.st1d_zpbr._unnamed_4 = 0b0;
    insn.st1d_zpbr._unnamed_3 = 0b1;
    insn.st1d_zpbr._unnamed_2 = 0b0;
    insn.st1d_zpbr.Rm = Rm;
    insn.st1d_zpbr.o2 = 0b1;
    insn.st1d_zpbr.opc = 0b111;
    insn.st1d_zpbr._unnamed_1 = 0b0010;
    insn.st1d_zpbr._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1d_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.st1d_zpbr_u128.Zt = Zt;
    insn.st1d_zpbr_u128.Rn = Rn;
    insn.st1d_zpbr_u128.Pg = Pg;
    insn.st1d_zpbr_u128._unnamed_4 = 0b0;
    insn.st1d_zpbr_u128._unnamed_3 = 0b1;
    insn.st1d_zpbr_u128._unnamed_2 = 0b0;
    insn.st1d_zpbr_u128.Rm = Rm;
    insn.st1d_zpbr_u128.o2 = 0b0;
    insn.st1d_zpbr_u128.opc = 0b111;
    insn.st1d_zpbr_u128._unnamed_1 = 0b0010;
    insn.st1d_zpbr_u128._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1w_z_p_bi_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4, uint32_t sz) {
    UnknownEncoding insn = {};
    insn.st1w_zpbi.Zt = Zt;
    insn.st1w_zpbi.Rn = Rn;
    insn.st1w_zpbi.Pg = Pg;
    insn.st1w_zpbi._unnamed_4 = 0b111;
    insn.st1w_zpbi.imm4 = imm4;
    insn.st1w_zpbi._unnamed_3 = 0b0;
    insn.st1w_zpbi.sz = sz;
    insn.st1w_zpbi._unnamed_2 = 0b1;
    insn.st1w_zpbi.msz = 0b10;
    insn.st1w_zpbi._unnamed_1 = 0b0010;
    insn.st1w_zpbi._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1w_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4) {
    UnknownEncoding insn = {};
    insn.st1w_zpbi_u128.Zt = Zt;
    insn.st1w_zpbi_u128.Rn = Rn;
    insn.st1w_zpbi_u128.Pg = Pg;
    insn.st1w_zpbi_u128._unnamed_3 = 0b111;
    insn.st1w_zpbi_u128.imm4 = imm4;
    insn.st1w_zpbi_u128._unnamed_2 = 0b0;
    insn.st1w_zpbi_u128.opc = 0b00;
    insn.st1w_zpbi_u128.msz = 0b10;
    insn.st1w_zpbi_u128._unnamed_1 = 0b0010;
    insn.st1w_zpbi_u128._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1w_z_p_br_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm, uint32_t sz) {
    UnknownEncoding insn = {};
    insn.st1w_zpbr.Zt = Zt;
    insn.st1w_zpbr.Rn = Rn;
    insn.st1w_zpbr.Pg = Pg;
    insn.st1w_zpbr._unnamed_4 = 0b0;
    insn.st1w_zpbr._unnamed_3 = 0b1;
    insn.st1w_zpbr._unnamed_2 = 0b0;
    insn.st1w_zpbr.Rm = Rm;
    insn.st1w_zpbr.sz = sz;
    insn.st1w_zpbr.opc = 0b101;
    insn.st1w_zpbr._unnamed_1 = 0b0010;
    insn.st1w_zpbr._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_st1w_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm) {
    UnknownEncoding insn = {};
    insn.st1w_zpbr_u128.Zt = Zt;
    insn.st1w_zpbr_u128.Rn = Rn;
    insn.st1w_zpbr_u128.Pg = Pg;
    insn.st1w_zpbr_u128._unnamed_4 = 0b0;
    insn.st1w_zpbr_u128._unnamed_3 = 0b1;
    insn.st1w_zpbr_u128._unnamed_2 = 0b0;
    insn.st1w_zpbr_u128.Rm = Rm;
    insn.st1w_zpbr_u128.o2 = 0b0;
    insn.st1w_zpbr_u128.opc = 0b100;
    insn.st1w_zpbr_u128._unnamed_1 = 0b0010;
    insn.st1w_zpbr_u128._unnamed_0 = 0b111;
    return insn.raw;
}

uint32_t encode_tbl_z_zz_1(uint32_t Zd, uint32_t Zn, uint32_t Zm, uint32_t size) {
    UnknownEncoding insn = {};
    insn.tbl_zzz1.Zd = Zd;
    insn.tbl_zzz1.Zn = Zn;
    insn.tbl_zzz1._unnamed_4 = 0b001100;
    insn.tbl_zzz1.Zm = Zm;
    insn.tbl_zzz1._unnamed_3 = 0b1;
    insn.tbl_zzz1.size = size;
    insn.tbl_zzz1._unnamed_2 = 0b1;
    insn.tbl_zzz1._unnamed_1 = 0b0010;
    insn.tbl_zzz1._unnamed_0 = 0b000;
    return insn.raw;
}

uint32_t encode_tbl_z_zz_2(uint32_t Zd, uint32_t Zn, uint32_t Zm, uint32_t size) {
    UnknownEncoding insn = {};
    insn.tbl_zzz2.Zd = Zd;
    insn.tbl_zzz2.Zn = Zn;
    insn.tbl_zzz2.op = 0b0;
    insn.tbl_zzz2._unnamed_4 = 0b00101;
    insn.tbl_zzz2.Zm = Zm;
    insn.tbl_zzz2._unnamed_3 = 0b1;
    insn.tbl_zzz2.size = size;
    insn.tbl_zzz2._unnamed_2 = 0b1;
    insn.tbl_zzz2._unnamed_1 = 0b0010;
    insn.tbl_zzz2._unnamed_0 = 0b000;
    return insn.raw;
}

uint32_t encode_xpacd_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.xpacd64z_dp1src.Rd = Rd;
    insn.xpacd64z_dp1src.Rn = 0b11111;
    insn.xpacd64z_dp1src.D = 0b1;
    insn.xpacd64z_dp1src._unnamed_2 = 0b01000;
    insn.xpacd64z_dp1src.opcode2 = 0b00001;
    insn.xpacd64z_dp1src._unnamed_1 = 0b11010110;
    insn.xpacd64z_dp1src.S = 0b0;
    insn.xpacd64z_dp1src._unnamed_0 = 0b1;
    insn.xpacd64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_xpaci_64z_dp_1src(uint32_t Rd) {
    UnknownEncoding insn = {};
    insn.xpaci64z_dp1src.Rd = Rd;
    insn.xpaci64z_dp1src.Rn = 0b11111;
    insn.xpaci64z_dp1src.D = 0b0;
    insn.xpaci64z_dp1src._unnamed_2 = 0b01000;
    insn.xpaci64z_dp1src.opcode2 = 0b00001;
    insn.xpaci64z_dp1src._unnamed_1 = 0b11010110;
    insn.xpaci64z_dp1src.S = 0b0;
    insn.xpaci64z_dp1src._unnamed_0 = 0b1;
    insn.xpaci64z_dp1src.sf = 0b1;
    return insn.raw;
}

uint32_t encode_xpaclri_hi_hints() {
    UnknownEncoding insn = {};
    insn.xpaclri_hi_hints._unnamed_3 = 0b11111;
    insn.xpaclri_hi_hints.op2 = 0b111;
    insn.xpaclri_hi_hints.CRm = 0b0000;
    insn.xpaclri_hi_hints._unnamed_2 = 0b01000000110010;
    insn.xpaclri_hi_hints._unnamed_1 = 0b101;
    insn.xpaclri_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

// Decode function implementation
// Decode a unknown instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_unknown(uint32_t insn) {
    // Switch for mask 0xFFFFFFFFu (13 patterns, 13 encodings)
    switch (insn & 0xFFFFFFFFu) {
        case 0xD50320FFu: { // XPACLRI_HI_hints
                        Instruction result(Mnemonic::XPACLRI, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503211Fu: { // PACIA1716_HI_hints
                        Instruction result(Mnemonic::PACIA1716, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503215Fu: { // PACIB1716_HI_hints
                        Instruction result(Mnemonic::PACIB1716, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503219Fu: { // AUTIA1716_HI_hints
                        Instruction result(Mnemonic::AUTIA1716, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD50321DFu: { // AUTIB1716_HI_hints
                        Instruction result(Mnemonic::AUTIB1716, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503231Fu: { // PACIAZ_HI_hints
                        Instruction result(Mnemonic::PACIAZ, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503233Fu: { // PACIASP_HI_hints
                        Instruction result(Mnemonic::PACIASP, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503235Fu: { // PACIBZ_HI_hints
                        Instruction result(Mnemonic::PACIBZ, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503237Fu: { // PACIBSP_HI_hints
                        Instruction result(Mnemonic::PACIBSP, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD503239Fu: { // AUTIAZ_HI_hints
                        Instruction result(Mnemonic::AUTIAZ, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD50323BFu: { // AUTIASP_HI_hints
                        Instruction result(Mnemonic::AUTIASP, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD50323DFu: { // AUTIBZ_HI_hints
                        Instruction result(Mnemonic::AUTIBZ, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0xD50323FFu: { // AUTIBSP_HI_hints
                        Instruction result(Mnemonic::AUTIBSP, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFE0u (6 patterns, 6 encodings)
    switch (insn & 0xFFFFFFE0u) {
        case 0xDAC123E0u: { // PACIZA_64Z_dp_1src
                        Instruction result(Mnemonic::PACIZA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.paciza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC127E0u: { // PACIZB_64Z_dp_1src
                        Instruction result(Mnemonic::PACIZB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacizb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC133E0u: { // AUTIZA_64Z_dp_1src
                        Instruction result(Mnemonic::AUTIZA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autiza64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC137E0u: { // AUTIZB_64Z_dp_1src
                        Instruction result(Mnemonic::AUTIZB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autizb64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC143E0u: { // XPACI_64Z_dp_1src
                        Instruction result(Mnemonic::XPACI, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.xpaci64z_dp1src.Rd, is_64bit));
                        return result;
        }
        case 0xDAC147E0u: { // XPACD_64Z_dp_1src
                        Instruction result(Mnemonic::XPACD, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.xpacd64z_dp1src.Rd, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFC00u (4 patterns, 4 encodings)
    switch (insn & 0xFFFFFC00u) {
        case 0xDAC10000u: { // PACIA_64P_dp_1src
                        Instruction result(Mnemonic::PACIA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacia64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacia64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC10400u: { // PACIB_64P_dp_1src
                        Instruction result(Mnemonic::PACIB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.pacib64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.pacib64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11000u: { // AUTIA_64P_dp_1src
                        Instruction result(Mnemonic::AUTIA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autia64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autia64p_dp1src.Rn, is_64bit));
                        return result;
        }
        case 0xDAC11400u: { // AUTIB_64P_dp_1src
                        Instruction result(Mnemonic::AUTIB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.autib64p_dp1src.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.autib64p_dp1src.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFE000u (8 patterns, 8 encodings)
    switch (insn & 0xFFFFE000u) {
        case 0xA51F8000u: { // ld1w_z_p_br_u128
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u128.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u128.Rm, is_64bit));
                        return result;
        }
        case 0xA55F4000u: { // ld1w_z_p_br_u32
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u32.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u32.Rm, is_64bit));
                        return result;
        }
        case 0xA57F4000u: { // ld1w_z_p_br_u64
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u64.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbr_u64.Rm, is_64bit));
                        return result;
        }
        case 0xA59F8000u: { // ld1d_z_p_br_u128
                        Instruction result(Mnemonic::LD1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbr_u128.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbr_u128.Rm, is_64bit));
                        return result;
        }
        case 0xA5FF4000u: { // ld1d_z_p_br_u64
                        Instruction result(Mnemonic::LD1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbr_u64.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbr_u64.Rm, is_64bit));
                        return result;
        }
        case 0xE51F4000u: { // st1w_z_p_br_u128
                        Instruction result(Mnemonic::ST1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbr_u128.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbr_u128.Rm, is_64bit));
                        return result;
        }
        case 0xE5DF4000u: { // st1d_z_p_br_u128
                        Instruction result(Mnemonic::ST1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbr_u128.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbr_u128.Rm, is_64bit));
                        return result;
        }
        case 0xE5FF4000u: { // st1d_z_p_br_
                        Instruction result(Mnemonic::ST1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbr.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF0E000u (8 patterns, 8 encodings)
    switch (insn & 0xFFF0E000u) {
        case 0xA5102000u: { // ld1w_z_p_bi_u128
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbi_u128.Rn, is_64bit));
                        return result;
        }
        case 0xA540A000u: { // ld1w_z_p_bi_u32
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbi_u32.Rn, is_64bit));
                        return result;
        }
        case 0xA560A000u: { // ld1w_z_p_bi_u64
                        Instruction result(Mnemonic::LD1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_zpbi_u64.Rn, is_64bit));
                        return result;
        }
        case 0xA5902000u: { // ld1d_z_p_bi_u128
                        Instruction result(Mnemonic::LD1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbi_u128.Rn, is_64bit));
                        return result;
        }
        case 0xA5E0A000u: { // ld1d_z_p_bi_u64
                        Instruction result(Mnemonic::LD1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_zpbi_u64.Rn, is_64bit));
                        return result;
        }
        case 0xE500E000u: { // st1w_z_p_bi_u128
                        Instruction result(Mnemonic::ST1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbi_u128.Rn, is_64bit));
                        return result;
        }
        case 0xE5C0E000u: { // st1d_z_p_bi_u128
                        Instruction result(Mnemonic::ST1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbi_u128.Rn, is_64bit));
                        return result;
        }
        case 0xE5E0E000u: { // st1d_z_p_bi_
                        Instruction result(Mnemonic::ST1D, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_zpbi.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C00u (4 patterns, 4 encodings)
    switch (insn & 0xFFE00C00u) {
        case 0xF8200400u: { // LDRAA_64_ldst_pac
                        Instruction result(Mnemonic::LDRAA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldraa64ldst_pac.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldraa64ldst_pac.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldraa64ldst_pac.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF8200C00u: { // LDRAA_64W_ldst_pac
                        Instruction result(Mnemonic::LDRAA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldraa64w_ldst_pac.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldraa64w_ldst_pac.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldraa64w_ldst_pac.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF8A00400u: { // LDRAB_64_ldst_pac
                        Instruction result(Mnemonic::LDRAB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldrab64ldst_pac.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldrab64ldst_pac.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldrab64ldst_pac.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF8A00C00u: { // LDRAB_64W_ldst_pac
                        Instruction result(Mnemonic::LDRAB, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldrab64w_ldst_pac.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldrab64w_ldst_pac.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldrab64w_ldst_pac.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Eu (2 patterns, 2 encodings)
    switch (insn & 0xFFE0001Eu) {
        case 0x81800008u: { // fmopa_za_pp_zz_16
                        Instruction result(Mnemonic::FMOPA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0x81800018u: { // fmops_za_pp_zz_16
                        Instruction result(Mnemonic::FMOPS, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Cu (2 patterns, 2 encodings)
    switch (insn & 0xFFE0001Cu) {
        case 0x80800000u: { // fmopa_za_pp_zz_32
                        Instruction result(Mnemonic::FMOPA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0x80800010u: { // fmops_za_pp_zz_32
                        Instruction result(Mnemonic::FMOPS, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00018u (2 patterns, 2 encodings)
    switch (insn & 0xFFE00018u) {
        case 0x80C00000u: { // fmopa_za_pp_zz_64
                        Instruction result(Mnemonic::FMOPA, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0x80C00010u: { // fmops_za_pp_zz_64
                        Instruction result(Mnemonic::FMOPS, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFDFE000u (1 pattern, 1 encoding)
    switch (insn & 0xFFDFE000u) {
        case 0xE55F4000u: { // st1w_z_p_br_
                        Instruction result(Mnemonic::ST1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbr.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFD0E000u (1 pattern, 1 encoding)
    switch (insn & 0xFFD0E000u) {
        case 0xE540E000u: { // st1w_z_p_bi_
                        Instruction result(Mnemonic::ST1W, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_zpbi.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF20FC00u (2 patterns, 2 encodings)
    switch (insn & 0xFF20FC00u) {
        case 0x05202800u: { // tbl_z_zz_2
                        Instruction result(Mnemonic::TBL, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        case 0x05203000u: { // tbl_z_zz_1
                        Instruction result(Mnemonic::TBL, insn);
                        UnknownEncoding enc = {};
                        enc.raw = insn;
                        (void)enc;  // Suppress unused warning
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace Unknown
} // namespace veda64
