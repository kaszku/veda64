#include "class/mortlach.hpp"

namespace veda64 {
namespace Mortlach {

// Internal encoding structures
// ADDHA: Add horizontally vector elements to ZA tile
// Encoding: addha_za_pp_z_32
// Template: ADDHA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.S
struct AddhaZaPpZ32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_9 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_8 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t V : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_5 : 3;  // fixed: 0b010 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ADDHA: Add horizontally vector elements to ZA tile
// Encoding: addha_za_pp_z_64
// Template: ADDHA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.D
struct AddhaZaPpZ64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_8 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t V : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_5 : 3;  // fixed: 0b010 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ADDSPL: Add multiple of Streaming SVE predicate register size to scalar register
// Encoding: addspl_r_ri_
// Template: ADDSPL  <Xd|SP>, <Xn|SP>, #<imm>
struct AddsplRRi {
    uint32_t Rd : 5;
    uint32_t imm6 : 6;
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 4;  // fixed: 0b0101 (0x5)
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b000 (0x0)
};


// ADDSVL: Add multiple of Streaming SVE vector register size to scalar register
// Encoding: addsvl_r_ri_
// Template: ADDSVL  <Xd|SP>, <Xn|SP>, #<imm>
struct AddsvlRRi {
    uint32_t Rd : 5;
    uint32_t imm6 : 6;
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 4;  // fixed: 0b0101 (0x5)
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b000 (0x0)
};


// ADDVA: Add vertically vector elements to ZA tile
// Encoding: addva_za_pp_z_32
// Template: ADDVA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.S
struct AddvaZaPpZ32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_9 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_8 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t V : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_5 : 3;  // fixed: 0b010 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ADDVA: Add vertically vector elements to ZA tile
// Encoding: addva_za_pp_z_64
// Template: ADDVA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.D
struct AddvaZaPpZ64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_8 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t V : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_5 : 3;  // fixed: 0b010 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// BFMOPA: BFloat16 sum of outer products to single-precision, accumulating
// Encoding: bfmopa_za32_pp_zz_
// Template: BFMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct BfmopaZa32PpZz {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
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


// BFMOPS: BFloat16 sum of outer products to single-precision, subtracting
// Encoding: bfmops_za32_pp_zz_
// Template: BFMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct BfmopsZa32PpZz {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
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


// FMOPA: Half-precision sum of outer products to single-precision, accumulating
// Encoding: fmopa_za32_pp_zz_16
// Template: FMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct FmopaZa32PpZz16 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// FMOPS: Half-precision sum of outer products to single-precision, subtracting
// Encoding: fmops_za32_pp_zz_16
// Template: FMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct FmopsZa32PpZz16 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_6 : 2;  // fixed: 0b00 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t _unnamed_5 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1B: Contiguous load of bytes to 8-bit element ZA tile slice
// Encoding: ld1b_za_p_rrr_
// Template: LD1B  { ZA0<HV>.B[<Ws>, <offs>] }, <Pg>/Z, [<Xn|SP>{, <Xm>}]
struct Ld1bZaPRrr {
    uint32_t off4 : 4;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t msz : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1D: Contiguous load of doublewords to 64-bit element ZA tile slice
// Encoding: ld1d_za_p_rrr_
// Template: LD1D  { <ZAt><HV>.D[<Ws>, <offs>] }, <Pg>/Z, [<Xn|SP>{, <Xm>, LSL #3}]
struct Ld1dZaPRrr {
    uint32_t o1 : 1;
    uint32_t ZAt : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t msz : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1H: Contiguous load of halfwords to 16-bit element ZA tile slice
// Encoding: ld1h_za_p_rrr_
// Template: LD1H  { <ZAt><HV>.H[<Ws>, <offs>] }, <Pg>/Z, [<Xn|SP>{, <Xm>, LSL #1}]
struct Ld1hZaPRrr {
    uint32_t off3 : 3;
    uint32_t ZAt : 1;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t msz : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1Q: Contiguous load of quadwords to 128-bit element ZA tile slice
// Encoding: ld1q_za_p_rrr_
// Template: LD1Q  { <ZAt><HV>.Q[<Ws>, <offs>] }, <Pg>/Z, [<Xn|SP>{, <Xm>, LSL #4}]
struct Ld1qZaPRrr {
    uint32_t ZAt : 4;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1110 (0xE)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LD1W: Contiguous load of words to 32-bit element ZA tile slice
// Encoding: ld1w_za_p_rrr_
// Template: LD1W  { <ZAt><HV>.S[<Ws>, <offs>] }, <Pg>/Z, [<Xn|SP>{, <Xm>, LSL #2}]
struct Ld1wZaPRrr {
    uint32_t off2 : 2;
    uint32_t ZAt : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t msz : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// LDR: Load ZA array vector
// Encoding: ldr_za_ri_
// Template: LDR  ZA[<Wv>, <offs>], [<Xn|SP>{, #<offs>, MUL VL}]
struct LdrZaRi {
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_6 : 3;  // fixed: 0b000 (0x0)
    uint32_t Rv : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 5;  // fixed: 0b00000 (0x0)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mov_z_p_rza_b_mova_z_p_rza_b
// Template: MOV  <Zd>.B, <Pg>/M, ZA0<HV>.B[<Ws>, <offs>]
struct MovZPRzaBMovaZPRzaB {
    uint32_t Zd : 5;
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mov_z_p_rza_h_mova_z_p_rza_h
// Template: MOV  <Zd>.H, <Pg>/M, <ZAn><HV>.H[<Ws>, <offs>]
struct MovZPRzaHMovaZPRzaH {
    uint32_t Zd : 5;
    uint32_t off3 : 3;
    uint32_t ZAn : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mov_z_p_rza_w_mova_z_p_rza_w
// Template: MOV  <Zd>.S, <Pg>/M, <ZAn><HV>.S[<Ws>, <offs>]
struct MovZPRzaWMovaZPRzaW {
    uint32_t Zd : 5;
    uint32_t off2 : 2;
    uint32_t ZAn : 2;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mov_z_p_rza_d_mova_z_p_rza_d
// Template: MOV  <Zd>.D, <Pg>/M, <ZAn><HV>.D[<Ws>, <offs>]
struct MovZPRzaDMovaZPRzaD {
    uint32_t Zd : 5;
    uint32_t o1 : 1;
    uint32_t ZAn : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mov_z_p_rza_q_mova_z_p_rza_q
// Template: MOV  <Zd>.Q, <Pg>/M, <ZAn><HV>.Q[<Ws>, <offs>]
struct MovZPRzaQMovaZPRzaQ {
    uint32_t Zd : 5;
    uint32_t ZAn : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mov_za_p_rz_b_mova_za_p_rz_b
// Template: MOV  ZA0<HV>.B[<Ws>, <offs>], <Pg>/M, <Zn>.B
struct MovZaPRzBMovaZaPRzB {
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mov_za_p_rz_h_mova_za_p_rz_h
// Template: MOV  <ZAd><HV>.H[<Ws>, <offs>], <Pg>/M, <Zn>.H
struct MovZaPRzHMovaZaPRzH {
    uint32_t off3 : 3;
    uint32_t ZAd : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mov_za_p_rz_w_mova_za_p_rz_w
// Template: MOV  <ZAd><HV>.S[<Ws>, <offs>], <Pg>/M, <Zn>.S
struct MovZaPRzWMovaZaPRzW {
    uint32_t off2 : 2;
    uint32_t ZAd : 2;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mov_za_p_rz_d_mova_za_p_rz_d
// Template: MOV  <ZAd><HV>.D[<Ws>, <offs>], <Pg>/M, <Zn>.D
struct MovZaPRzDMovaZaPRzD {
    uint32_t o1 : 1;
    uint32_t ZAd : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mov_za_p_rz_q_mova_za_p_rz_q
// Template: MOV  <ZAd><HV>.Q[<Ws>, <offs>], <Pg>/M, <Zn>.Q
struct MovZaPRzQMovaZaPRzQ {
    uint32_t ZAd : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mova_z_p_rza_b
// Template: MOVA  <Zd>.B, <Pg>/M, ZA0<HV>.B[<Ws>, <offs>]
struct MovaZPRzaB {
    uint32_t Zd : 5;
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mova_z_p_rza_h
// Template: MOVA  <Zd>.H, <Pg>/M, <ZAn><HV>.H[<Ws>, <offs>]
struct MovaZPRzaH {
    uint32_t Zd : 5;
    uint32_t off3 : 3;
    uint32_t ZAn : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mova_z_p_rza_w
// Template: MOVA  <Zd>.S, <Pg>/M, <ZAn><HV>.S[<Ws>, <offs>]
struct MovaZPRzaW {
    uint32_t Zd : 5;
    uint32_t off2 : 2;
    uint32_t ZAn : 2;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mova_z_p_rza_d
// Template: MOVA  <Zd>.D, <Pg>/M, <ZAn><HV>.D[<Ws>, <offs>]
struct MovaZPRzaD {
    uint32_t Zd : 5;
    uint32_t o1 : 1;
    uint32_t ZAn : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move ZA tile slice to Z vector
// Encoding: mova_z_p_rza_q
// Template: MOVA  <Zd>.Q, <Pg>/M, <ZAn><HV>.Q[<Ws>, <offs>]
struct MovaZPRzaQ {
    uint32_t Zd : 5;
    uint32_t ZAn : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mova_za_p_rz_b
// Template: MOVA  ZA0<HV>.B[<Ws>, <offs>], <Pg>/M, <Zn>.B
struct MovaZaPRzB {
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mova_za_p_rz_h
// Template: MOVA  <ZAd><HV>.H[<Ws>, <offs>], <Pg>/M, <Zn>.H
struct MovaZaPRzH {
    uint32_t off3 : 3;
    uint32_t ZAd : 1;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mova_za_p_rz_w
// Template: MOVA  <ZAd><HV>.S[<Ws>, <offs>], <Pg>/M, <Zn>.S
struct MovaZaPRzW {
    uint32_t off2 : 2;
    uint32_t ZAd : 2;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mova_za_p_rz_d
// Template: MOVA  <ZAd><HV>.D[<Ws>, <offs>], <Pg>/M, <Zn>.D
struct MovaZaPRzD {
    uint32_t o1 : 1;
    uint32_t ZAd : 3;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// MOVA: Move Z vector to ZA tile slice
// Encoding: mova_za_p_rz_q
// Template: MOVA  <ZAd><HV>.Q[<Ws>, <offs>], <Pg>/M, <Zn>.Q
struct MovaZaPRzQ {
    uint32_t ZAd : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Q : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_6 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// RDSVL: Read multiple of Streaming SVE vector register size to scalar register
// Encoding: rdsvl_r_i_
// Template: RDSVL  <Xd>, #<imm>
struct RdsvlRI {
    uint32_t Rd : 5;
    uint32_t imm6 : 6;
    uint32_t _unnamed_6 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_5 : 4;  // fixed: 0b0101 (0x5)
    uint32_t opc2 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 4;  // fixed: 0b0010 (0x2)
    uint32_t _unnamed_0 : 3;  // fixed: 0b000 (0x0)
};


// SMOPA: Signed integer sum of outer products, accumulating
// Encoding: smopa_za_pp_zz_32
// Template: SMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct SmopaZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SMOPA: Signed integer sum of outer products, accumulating
// Encoding: smopa_za_pp_zz_64
// Template: SMOPA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct SmopaZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SMOPS: Signed integer sum of outer products, subtracting
// Encoding: smops_za_pp_zz_32
// Template: SMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct SmopsZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SMOPS: Signed integer sum of outer products, subtracting
// Encoding: smops_za_pp_zz_64
// Template: SMOPS  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct SmopsZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ST1B: Contiguous store of bytes from 8-bit element ZA tile slice
// Encoding: st1b_za_p_rrr_
// Template: ST1B  { ZA0<HV>.B[<Ws>, <offs>] }, <Pg>, [<Xn|SP>{, <Xm>}]
struct St1bZaPRrr {
    uint32_t off4 : 4;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t msz : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ST1D: Contiguous store of doublewords from 64-bit element ZA tile slice
// Encoding: st1d_za_p_rrr_
// Template: ST1D  { <ZAt><HV>.D[<Ws>, <offs>] }, <Pg>, [<Xn|SP>{, <Xm>, LSL #3}]
struct St1dZaPRrr {
    uint32_t o1 : 1;
    uint32_t ZAt : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t msz : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ST1H: Contiguous store of halfwords from 16-bit element ZA tile slice
// Encoding: st1h_za_p_rrr_
// Template: ST1H  { <ZAt><HV>.H[<Ws>, <offs>] }, <Pg>, [<Xn|SP>{, <Xm>, LSL #1}]
struct St1hZaPRrr {
    uint32_t off3 : 3;
    uint32_t ZAt : 1;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t msz : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ST1Q: Contiguous store of quadwords from 128-bit element ZA tile slice
// Encoding: st1q_za_p_rrr_
// Template: ST1Q  { <ZAt><HV>.Q[<Ws>, <offs>] }, <Pg>, [<Xn|SP>{, <Xm>, LSL #4}]
struct St1qZaPRrr {
    uint32_t ZAt : 4;
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1111 (0xF)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ST1W: Contiguous store of words from 32-bit element ZA tile slice
// Encoding: st1w_za_p_rrr_
// Template: ST1W  { <ZAt><HV>.S[<Ws>, <offs>] }, <Pg>, [<Xn|SP>{, <Xm>, LSL #2}]
struct St1wZaPRrr {
    uint32_t off2 : 2;
    uint32_t ZAt : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t Pg : 3;
    uint32_t Rs : 2;
    uint32_t V : 1;
    uint32_t Rm : 5;
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t msz : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// STR: Store ZA array vector
// Encoding: str_za_ri_
// Template: STR  ZA[<Wv>, <offs>], [<Xn|SP>{, #<offs>, MUL VL}]
struct StrZaRi {
    uint32_t off4 : 4;
    uint32_t _unnamed_7 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_6 : 3;  // fixed: 0b000 (0x0)
    uint32_t Rv : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 5;  // fixed: 0b00000 (0x0)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SUMOPA: Signed by unsigned integer sum of outer products, accumulating
// Encoding: sumopa_za_pp_zz_32
// Template: SUMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct SumopaZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SUMOPA: Signed by unsigned integer sum of outer products, accumulating
// Encoding: sumopa_za_pp_zz_64
// Template: SUMOPA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct SumopaZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SUMOPS: Signed by unsigned integer sum of outer products, subtracting
// Encoding: sumops_za_pp_zz_32
// Template: SUMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct SumopsZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// SUMOPS: Signed by unsigned integer sum of outer products, subtracting
// Encoding: sumops_za_pp_zz_64
// Template: SUMOPS  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct SumopsZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// UMOPA: Unsigned integer sum of outer products, accumulating
// Encoding: umopa_za_pp_zz_32
// Template: UMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct UmopaZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// UMOPA: Unsigned integer sum of outer products, accumulating
// Encoding: umopa_za_pp_zz_64
// Template: UMOPA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct UmopaZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// UMOPS: Unsigned integer sum of outer products, subtracting
// Encoding: umops_za_pp_zz_32
// Template: UMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct UmopsZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// UMOPS: Unsigned integer sum of outer products, subtracting
// Encoding: umops_za_pp_zz_64
// Template: UMOPS  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct UmopsZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// USMOPA: Unsigned by signed integer sum of outer products, accumulating
// Encoding: usmopa_za_pp_zz_32
// Template: USMOPA  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct UsmopaZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// USMOPA: Unsigned by signed integer sum of outer products, accumulating
// Encoding: usmopa_za_pp_zz_64
// Template: USMOPA  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct UsmopaZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// USMOPS: Unsigned by signed integer sum of outer products, subtracting
// Encoding: usmops_za_pp_zz_32
// Template: USMOPS  <ZAda>.S, <Pn>/M, <Pm>/M, <Zn>.B, <Zm>.B
struct UsmopsZaPpZz32 {
    uint32_t ZAda : 2;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// USMOPS: Unsigned by signed integer sum of outer products, subtracting
// Encoding: usmops_za_pp_zz_64
// Template: USMOPS  <ZAda>.D, <Pn>/M, <Pm>/M, <Zn>.H, <Zm>.H
struct UsmopsZaPpZz64 {
    uint32_t ZAda : 3;
    uint32_t _unnamed_5 : 1;  // fixed: 0b0 (0x0)
    uint32_t S : 1;  // fixed: 0b1 (0x1)
    uint32_t Zn : 5;
    uint32_t Pn : 3;
    uint32_t Pm : 3;
    uint32_t Zm : 5;
    uint32_t u1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_4 : 2;  // fixed: 0b11 (0x3)
    uint32_t u0 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// ZERO: Zero a list of 64-bit element ZA tiles
// Encoding: zero_za_i_
// Template: ZERO  { {<mask>} }
struct ZeroZaI {
    uint32_t imm8 : 8;
    uint32_t _unnamed_4 : 10;  // fixed: 0b0000000000 (0x0)
    uint32_t _unnamed_3 : 7;  // fixed: 0b0000010 (0x2)
    uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 1;  // fixed: 0b1 (0x1)
};


// Union for mortlach instruction class
union MortlachEncoding {
    AddhaZaPpZ32 addha_za_pp_z32;
    AddhaZaPpZ64 addha_za_pp_z64;
    AddsplRRi addspl_rri;
    AddsvlRRi addsvl_rri;
    AddvaZaPpZ32 addva_za_pp_z32;
    AddvaZaPpZ64 addva_za_pp_z64;
    BfmopaZa32PpZz bfmopa_za32pp_zz;
    BfmopsZa32PpZz bfmops_za32pp_zz;
    FmopaZa32PpZz16 fmopa_za32pp_zz16;
    FmopsZa32PpZz16 fmops_za32pp_zz16;
    Ld1bZaPRrr ld1b_za_prrr;
    Ld1dZaPRrr ld1d_za_prrr;
    Ld1hZaPRrr ld1h_za_prrr;
    Ld1qZaPRrr ld1q_za_prrr;
    Ld1wZaPRrr ld1w_za_prrr;
    LdrZaRi ldr_za_ri;
    MovZPRzaBMovaZPRzaB mov_zprza_bmova_zprza_b;
    MovZPRzaHMovaZPRzaH mov_zprza_hmova_zprza_h;
    MovZPRzaWMovaZPRzaW mov_zprza_wmova_zprza_w;
    MovZPRzaDMovaZPRzaD mov_zprza_dmova_zprza_d;
    MovZPRzaQMovaZPRzaQ mov_zprza_qmova_zprza_q;
    MovZaPRzBMovaZaPRzB mov_za_prz_bmova_za_prz_b;
    MovZaPRzHMovaZaPRzH mov_za_prz_hmova_za_prz_h;
    MovZaPRzWMovaZaPRzW mov_za_prz_wmova_za_prz_w;
    MovZaPRzDMovaZaPRzD mov_za_prz_dmova_za_prz_d;
    MovZaPRzQMovaZaPRzQ mov_za_prz_qmova_za_prz_q;
    MovaZPRzaB mova_zprza_b;
    MovaZPRzaH mova_zprza_h;
    MovaZPRzaW mova_zprza_w;
    MovaZPRzaD mova_zprza_d;
    MovaZPRzaQ mova_zprza_q;
    MovaZaPRzB mova_za_prz_b;
    MovaZaPRzH mova_za_prz_h;
    MovaZaPRzW mova_za_prz_w;
    MovaZaPRzD mova_za_prz_d;
    MovaZaPRzQ mova_za_prz_q;
    RdsvlRI rdsvl_ri;
    SmopaZaPpZz32 smopa_za_pp_zz32;
    SmopaZaPpZz64 smopa_za_pp_zz64;
    SmopsZaPpZz32 smops_za_pp_zz32;
    SmopsZaPpZz64 smops_za_pp_zz64;
    St1bZaPRrr st1b_za_prrr;
    St1dZaPRrr st1d_za_prrr;
    St1hZaPRrr st1h_za_prrr;
    St1qZaPRrr st1q_za_prrr;
    St1wZaPRrr st1w_za_prrr;
    StrZaRi str_za_ri;
    SumopaZaPpZz32 sumopa_za_pp_zz32;
    SumopaZaPpZz64 sumopa_za_pp_zz64;
    SumopsZaPpZz32 sumops_za_pp_zz32;
    SumopsZaPpZz64 sumops_za_pp_zz64;
    UmopaZaPpZz32 umopa_za_pp_zz32;
    UmopaZaPpZz64 umopa_za_pp_zz64;
    UmopsZaPpZz32 umops_za_pp_zz32;
    UmopsZaPpZz64 umops_za_pp_zz64;
    UsmopaZaPpZz32 usmopa_za_pp_zz32;
    UsmopaZaPpZz64 usmopa_za_pp_zz64;
    UsmopsZaPpZz32 usmops_za_pp_zz32;
    UsmopsZaPpZz64 usmops_za_pp_zz64;
    ZeroZaI zero_za_i;
    uint32_t raw;
};
static_assert(sizeof(MortlachEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_addha_za_pp_z_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm) {
    MortlachEncoding insn = {};
    insn.addha_za_pp_z32.ZAda = ZAda;
    insn.addha_za_pp_z32._unnamed_9 = 0b0;
    insn.addha_za_pp_z32._unnamed_8 = 0b0;
    insn.addha_za_pp_z32._unnamed_7 = 0b0;
    insn.addha_za_pp_z32.Zn = Zn;
    insn.addha_za_pp_z32.Pn = Pn;
    insn.addha_za_pp_z32.Pm = Pm;
    insn.addha_za_pp_z32.V = 0b0;
    insn.addha_za_pp_z32._unnamed_6 = 0b00;
    insn.addha_za_pp_z32._unnamed_5 = 0b010;
    insn.addha_za_pp_z32.op = 0b0;
    insn.addha_za_pp_z32._unnamed_4 = 0b1;
    insn.addha_za_pp_z32._unnamed_3 = 0b0;
    insn.addha_za_pp_z32._unnamed_2 = 0b0000;
    insn.addha_za_pp_z32._unnamed_1 = 0b10;
    insn.addha_za_pp_z32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_addha_za_pp_z_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm) {
    MortlachEncoding insn = {};
    insn.addha_za_pp_z64.ZAda = ZAda;
    insn.addha_za_pp_z64._unnamed_8 = 0b0;
    insn.addha_za_pp_z64._unnamed_7 = 0b0;
    insn.addha_za_pp_z64.Zn = Zn;
    insn.addha_za_pp_z64.Pn = Pn;
    insn.addha_za_pp_z64.Pm = Pm;
    insn.addha_za_pp_z64.V = 0b0;
    insn.addha_za_pp_z64._unnamed_6 = 0b00;
    insn.addha_za_pp_z64._unnamed_5 = 0b010;
    insn.addha_za_pp_z64.op = 0b1;
    insn.addha_za_pp_z64._unnamed_4 = 0b1;
    insn.addha_za_pp_z64._unnamed_3 = 0b0;
    insn.addha_za_pp_z64._unnamed_2 = 0b0000;
    insn.addha_za_pp_z64._unnamed_1 = 0b10;
    insn.addha_za_pp_z64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_addspl_r_ri_(uint32_t Rd, uint32_t imm6, uint32_t Rn) {
    MortlachEncoding insn = {};
    insn.addspl_rri.Rd = Rd;
    insn.addspl_rri.imm6 = imm6;
    insn.addspl_rri._unnamed_6 = 0b1;
    insn.addspl_rri._unnamed_5 = 0b0101;
    insn.addspl_rri.Rn = Rn;
    insn.addspl_rri._unnamed_4 = 0b1;
    insn.addspl_rri.op = 0b1;
    insn.addspl_rri._unnamed_3 = 0b0;
    insn.addspl_rri._unnamed_2 = 0b0;
    insn.addspl_rri._unnamed_1 = 0b0010;
    insn.addspl_rri._unnamed_0 = 0b000;
    return insn.raw;
}

uint32_t encode_addsvl_r_ri_(uint32_t Rd, uint32_t imm6, uint32_t Rn) {
    MortlachEncoding insn = {};
    insn.addsvl_rri.Rd = Rd;
    insn.addsvl_rri.imm6 = imm6;
    insn.addsvl_rri._unnamed_6 = 0b1;
    insn.addsvl_rri._unnamed_5 = 0b0101;
    insn.addsvl_rri.Rn = Rn;
    insn.addsvl_rri._unnamed_4 = 0b1;
    insn.addsvl_rri.op = 0b0;
    insn.addsvl_rri._unnamed_3 = 0b0;
    insn.addsvl_rri._unnamed_2 = 0b0;
    insn.addsvl_rri._unnamed_1 = 0b0010;
    insn.addsvl_rri._unnamed_0 = 0b000;
    return insn.raw;
}

uint32_t encode_addva_za_pp_z_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm) {
    MortlachEncoding insn = {};
    insn.addva_za_pp_z32.ZAda = ZAda;
    insn.addva_za_pp_z32._unnamed_9 = 0b0;
    insn.addva_za_pp_z32._unnamed_8 = 0b0;
    insn.addva_za_pp_z32._unnamed_7 = 0b0;
    insn.addva_za_pp_z32.Zn = Zn;
    insn.addva_za_pp_z32.Pn = Pn;
    insn.addva_za_pp_z32.Pm = Pm;
    insn.addva_za_pp_z32.V = 0b1;
    insn.addva_za_pp_z32._unnamed_6 = 0b00;
    insn.addva_za_pp_z32._unnamed_5 = 0b010;
    insn.addva_za_pp_z32.op = 0b0;
    insn.addva_za_pp_z32._unnamed_4 = 0b1;
    insn.addva_za_pp_z32._unnamed_3 = 0b0;
    insn.addva_za_pp_z32._unnamed_2 = 0b0000;
    insn.addva_za_pp_z32._unnamed_1 = 0b10;
    insn.addva_za_pp_z32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_addva_za_pp_z_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm) {
    MortlachEncoding insn = {};
    insn.addva_za_pp_z64.ZAda = ZAda;
    insn.addva_za_pp_z64._unnamed_8 = 0b0;
    insn.addva_za_pp_z64._unnamed_7 = 0b0;
    insn.addva_za_pp_z64.Zn = Zn;
    insn.addva_za_pp_z64.Pn = Pn;
    insn.addva_za_pp_z64.Pm = Pm;
    insn.addva_za_pp_z64.V = 0b1;
    insn.addva_za_pp_z64._unnamed_6 = 0b00;
    insn.addva_za_pp_z64._unnamed_5 = 0b010;
    insn.addva_za_pp_z64.op = 0b1;
    insn.addva_za_pp_z64._unnamed_4 = 0b1;
    insn.addva_za_pp_z64._unnamed_3 = 0b0;
    insn.addva_za_pp_z64._unnamed_2 = 0b0000;
    insn.addva_za_pp_z64._unnamed_1 = 0b10;
    insn.addva_za_pp_z64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_bfmopa_za32_pp_zz_(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.bfmopa_za32pp_zz.ZAda = ZAda;
    insn.bfmopa_za32pp_zz._unnamed_6 = 0b00;
    insn.bfmopa_za32pp_zz.S = 0b0;
    insn.bfmopa_za32pp_zz.Zn = Zn;
    insn.bfmopa_za32pp_zz.Pn = Pn;
    insn.bfmopa_za32pp_zz.Pm = Pm;
    insn.bfmopa_za32pp_zz.Zm = Zm;
    insn.bfmopa_za32pp_zz._unnamed_5 = 0b0;
    insn.bfmopa_za32pp_zz._unnamed_4 = 0b10;
    insn.bfmopa_za32pp_zz._unnamed_3 = 0b1;
    insn.bfmopa_za32pp_zz._unnamed_2 = 0b0000;
    insn.bfmopa_za32pp_zz._unnamed_1 = 0b00;
    insn.bfmopa_za32pp_zz._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_bfmops_za32_pp_zz_(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.bfmops_za32pp_zz.ZAda = ZAda;
    insn.bfmops_za32pp_zz._unnamed_6 = 0b00;
    insn.bfmops_za32pp_zz.S = 0b1;
    insn.bfmops_za32pp_zz.Zn = Zn;
    insn.bfmops_za32pp_zz.Pn = Pn;
    insn.bfmops_za32pp_zz.Pm = Pm;
    insn.bfmops_za32pp_zz.Zm = Zm;
    insn.bfmops_za32pp_zz._unnamed_5 = 0b0;
    insn.bfmops_za32pp_zz._unnamed_4 = 0b10;
    insn.bfmops_za32pp_zz._unnamed_3 = 0b1;
    insn.bfmops_za32pp_zz._unnamed_2 = 0b0000;
    insn.bfmops_za32pp_zz._unnamed_1 = 0b00;
    insn.bfmops_za32pp_zz._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmopa_za32_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.fmopa_za32pp_zz16.ZAda = ZAda;
    insn.fmopa_za32pp_zz16._unnamed_6 = 0b00;
    insn.fmopa_za32pp_zz16.S = 0b0;
    insn.fmopa_za32pp_zz16.Zn = Zn;
    insn.fmopa_za32pp_zz16.Pn = Pn;
    insn.fmopa_za32pp_zz16.Pm = Pm;
    insn.fmopa_za32pp_zz16.Zm = Zm;
    insn.fmopa_za32pp_zz16._unnamed_5 = 0b1;
    insn.fmopa_za32pp_zz16._unnamed_4 = 0b10;
    insn.fmopa_za32pp_zz16._unnamed_3 = 0b1;
    insn.fmopa_za32pp_zz16._unnamed_2 = 0b0000;
    insn.fmopa_za32pp_zz16._unnamed_1 = 0b00;
    insn.fmopa_za32pp_zz16._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_fmops_za32_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.fmops_za32pp_zz16.ZAda = ZAda;
    insn.fmops_za32pp_zz16._unnamed_6 = 0b00;
    insn.fmops_za32pp_zz16.S = 0b1;
    insn.fmops_za32pp_zz16.Zn = Zn;
    insn.fmops_za32pp_zz16.Pn = Pn;
    insn.fmops_za32pp_zz16.Pm = Pm;
    insn.fmops_za32pp_zz16.Zm = Zm;
    insn.fmops_za32pp_zz16._unnamed_5 = 0b1;
    insn.fmops_za32pp_zz16._unnamed_4 = 0b10;
    insn.fmops_za32pp_zz16._unnamed_3 = 0b1;
    insn.fmops_za32pp_zz16._unnamed_2 = 0b0000;
    insn.fmops_za32pp_zz16._unnamed_1 = 0b00;
    insn.fmops_za32pp_zz16._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1b_za_p_rrr_(uint32_t off4, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.ld1b_za_prrr.off4 = off4;
    insn.ld1b_za_prrr._unnamed_5 = 0b0;
    insn.ld1b_za_prrr.Rn = Rn;
    insn.ld1b_za_prrr.Pg = Pg;
    insn.ld1b_za_prrr.Rs = Rs;
    insn.ld1b_za_prrr.V = V;
    insn.ld1b_za_prrr.Rm = Rm;
    insn.ld1b_za_prrr._unnamed_4 = 0b0;
    insn.ld1b_za_prrr.msz = 0b00;
    insn.ld1b_za_prrr._unnamed_3 = 0b0;
    insn.ld1b_za_prrr._unnamed_2 = 0b0000;
    insn.ld1b_za_prrr._unnamed_1 = 0b11;
    insn.ld1b_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1d_za_p_rrr_(uint32_t o1, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.ld1d_za_prrr.o1 = o1;
    insn.ld1d_za_prrr.ZAt = ZAt;
    insn.ld1d_za_prrr._unnamed_5 = 0b0;
    insn.ld1d_za_prrr.Rn = Rn;
    insn.ld1d_za_prrr.Pg = Pg;
    insn.ld1d_za_prrr.Rs = Rs;
    insn.ld1d_za_prrr.V = V;
    insn.ld1d_za_prrr.Rm = Rm;
    insn.ld1d_za_prrr._unnamed_4 = 0b0;
    insn.ld1d_za_prrr.msz = 0b11;
    insn.ld1d_za_prrr._unnamed_3 = 0b0;
    insn.ld1d_za_prrr._unnamed_2 = 0b0000;
    insn.ld1d_za_prrr._unnamed_1 = 0b11;
    insn.ld1d_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1h_za_p_rrr_(uint32_t off3, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.ld1h_za_prrr.off3 = off3;
    insn.ld1h_za_prrr.ZAt = ZAt;
    insn.ld1h_za_prrr._unnamed_5 = 0b0;
    insn.ld1h_za_prrr.Rn = Rn;
    insn.ld1h_za_prrr.Pg = Pg;
    insn.ld1h_za_prrr.Rs = Rs;
    insn.ld1h_za_prrr.V = V;
    insn.ld1h_za_prrr.Rm = Rm;
    insn.ld1h_za_prrr._unnamed_4 = 0b0;
    insn.ld1h_za_prrr.msz = 0b01;
    insn.ld1h_za_prrr._unnamed_3 = 0b0;
    insn.ld1h_za_prrr._unnamed_2 = 0b0000;
    insn.ld1h_za_prrr._unnamed_1 = 0b11;
    insn.ld1h_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1q_za_p_rrr_(uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.ld1q_za_prrr.ZAt = ZAt;
    insn.ld1q_za_prrr._unnamed_4 = 0b0;
    insn.ld1q_za_prrr.Rn = Rn;
    insn.ld1q_za_prrr.Pg = Pg;
    insn.ld1q_za_prrr.Rs = Rs;
    insn.ld1q_za_prrr.V = V;
    insn.ld1q_za_prrr.Rm = Rm;
    insn.ld1q_za_prrr._unnamed_3 = 0b1110;
    insn.ld1q_za_prrr._unnamed_2 = 0b0000;
    insn.ld1q_za_prrr._unnamed_1 = 0b11;
    insn.ld1q_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ld1w_za_p_rrr_(uint32_t off2, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.ld1w_za_prrr.off2 = off2;
    insn.ld1w_za_prrr.ZAt = ZAt;
    insn.ld1w_za_prrr._unnamed_5 = 0b0;
    insn.ld1w_za_prrr.Rn = Rn;
    insn.ld1w_za_prrr.Pg = Pg;
    insn.ld1w_za_prrr.Rs = Rs;
    insn.ld1w_za_prrr.V = V;
    insn.ld1w_za_prrr.Rm = Rm;
    insn.ld1w_za_prrr._unnamed_4 = 0b0;
    insn.ld1w_za_prrr.msz = 0b10;
    insn.ld1w_za_prrr._unnamed_3 = 0b0;
    insn.ld1w_za_prrr._unnamed_2 = 0b0000;
    insn.ld1w_za_prrr._unnamed_1 = 0b11;
    insn.ld1w_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_ldr_za_ri_(uint32_t off4, uint32_t Rn, uint32_t Rv) {
    MortlachEncoding insn = {};
    insn.ldr_za_ri.off4 = off4;
    insn.ldr_za_ri._unnamed_7 = 0b0;
    insn.ldr_za_ri.Rn = Rn;
    insn.ldr_za_ri._unnamed_6 = 0b000;
    insn.ldr_za_ri.Rv = Rv;
    insn.ldr_za_ri._unnamed_5 = 0b0;
    insn.ldr_za_ri._unnamed_4 = 0b00000;
    insn.ldr_za_ri.op = 0b0;
    insn.ldr_za_ri._unnamed_3 = 0b100;
    insn.ldr_za_ri._unnamed_2 = 0b0000;
    insn.ldr_za_ri._unnamed_1 = 0b11;
    insn.ldr_za_ri._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_z_p_rza_b_mova_z_p_rza_b(uint32_t Zd, uint32_t off4, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_zprza_bmova_zprza_b.Zd = Zd;
    insn.mov_zprza_bmova_zprza_b.off4 = off4;
    insn.mov_zprza_bmova_zprza_b._unnamed_7 = 0b0;
    insn.mov_zprza_bmova_zprza_b.Pg = Pg;
    insn.mov_zprza_bmova_zprza_b.Rs = Rs;
    insn.mov_zprza_bmova_zprza_b.V = V;
    insn.mov_zprza_bmova_zprza_b.Q = 0b0;
    insn.mov_zprza_bmova_zprza_b._unnamed_6 = 0b1;
    insn.mov_zprza_bmova_zprza_b._unnamed_5 = 0b0;
    insn.mov_zprza_bmova_zprza_b._unnamed_4 = 0b000;
    insn.mov_zprza_bmova_zprza_b.size = 0b00;
    insn.mov_zprza_bmova_zprza_b._unnamed_3 = 0b0;
    insn.mov_zprza_bmova_zprza_b._unnamed_2 = 0b0000;
    insn.mov_zprza_bmova_zprza_b._unnamed_1 = 0b10;
    insn.mov_zprza_bmova_zprza_b._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_z_p_rza_h_mova_z_p_rza_h(uint32_t Zd, uint32_t off3, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_zprza_hmova_zprza_h.Zd = Zd;
    insn.mov_zprza_hmova_zprza_h.off3 = off3;
    insn.mov_zprza_hmova_zprza_h.ZAn = ZAn;
    insn.mov_zprza_hmova_zprza_h._unnamed_7 = 0b0;
    insn.mov_zprza_hmova_zprza_h.Pg = Pg;
    insn.mov_zprza_hmova_zprza_h.Rs = Rs;
    insn.mov_zprza_hmova_zprza_h.V = V;
    insn.mov_zprza_hmova_zprza_h.Q = 0b0;
    insn.mov_zprza_hmova_zprza_h._unnamed_6 = 0b1;
    insn.mov_zprza_hmova_zprza_h._unnamed_5 = 0b0;
    insn.mov_zprza_hmova_zprza_h._unnamed_4 = 0b000;
    insn.mov_zprza_hmova_zprza_h.size = 0b01;
    insn.mov_zprza_hmova_zprza_h._unnamed_3 = 0b0;
    insn.mov_zprza_hmova_zprza_h._unnamed_2 = 0b0000;
    insn.mov_zprza_hmova_zprza_h._unnamed_1 = 0b10;
    insn.mov_zprza_hmova_zprza_h._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_z_p_rza_w_mova_z_p_rza_w(uint32_t Zd, uint32_t off2, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_zprza_wmova_zprza_w.Zd = Zd;
    insn.mov_zprza_wmova_zprza_w.off2 = off2;
    insn.mov_zprza_wmova_zprza_w.ZAn = ZAn;
    insn.mov_zprza_wmova_zprza_w._unnamed_7 = 0b0;
    insn.mov_zprza_wmova_zprza_w.Pg = Pg;
    insn.mov_zprza_wmova_zprza_w.Rs = Rs;
    insn.mov_zprza_wmova_zprza_w.V = V;
    insn.mov_zprza_wmova_zprza_w.Q = 0b0;
    insn.mov_zprza_wmova_zprza_w._unnamed_6 = 0b1;
    insn.mov_zprza_wmova_zprza_w._unnamed_5 = 0b0;
    insn.mov_zprza_wmova_zprza_w._unnamed_4 = 0b000;
    insn.mov_zprza_wmova_zprza_w.size = 0b10;
    insn.mov_zprza_wmova_zprza_w._unnamed_3 = 0b0;
    insn.mov_zprza_wmova_zprza_w._unnamed_2 = 0b0000;
    insn.mov_zprza_wmova_zprza_w._unnamed_1 = 0b10;
    insn.mov_zprza_wmova_zprza_w._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_z_p_rza_d_mova_z_p_rza_d(uint32_t Zd, uint32_t o1, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_zprza_dmova_zprza_d.Zd = Zd;
    insn.mov_zprza_dmova_zprza_d.o1 = o1;
    insn.mov_zprza_dmova_zprza_d.ZAn = ZAn;
    insn.mov_zprza_dmova_zprza_d._unnamed_7 = 0b0;
    insn.mov_zprza_dmova_zprza_d.Pg = Pg;
    insn.mov_zprza_dmova_zprza_d.Rs = Rs;
    insn.mov_zprza_dmova_zprza_d.V = V;
    insn.mov_zprza_dmova_zprza_d.Q = 0b0;
    insn.mov_zprza_dmova_zprza_d._unnamed_6 = 0b1;
    insn.mov_zprza_dmova_zprza_d._unnamed_5 = 0b0;
    insn.mov_zprza_dmova_zprza_d._unnamed_4 = 0b000;
    insn.mov_zprza_dmova_zprza_d.size = 0b11;
    insn.mov_zprza_dmova_zprza_d._unnamed_3 = 0b0;
    insn.mov_zprza_dmova_zprza_d._unnamed_2 = 0b0000;
    insn.mov_zprza_dmova_zprza_d._unnamed_1 = 0b10;
    insn.mov_zprza_dmova_zprza_d._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_z_p_rza_q_mova_z_p_rza_q(uint32_t Zd, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_zprza_qmova_zprza_q.Zd = Zd;
    insn.mov_zprza_qmova_zprza_q.ZAn = ZAn;
    insn.mov_zprza_qmova_zprza_q._unnamed_7 = 0b0;
    insn.mov_zprza_qmova_zprza_q.Pg = Pg;
    insn.mov_zprza_qmova_zprza_q.Rs = Rs;
    insn.mov_zprza_qmova_zprza_q.V = V;
    insn.mov_zprza_qmova_zprza_q.Q = 0b1;
    insn.mov_zprza_qmova_zprza_q._unnamed_6 = 0b1;
    insn.mov_zprza_qmova_zprza_q._unnamed_5 = 0b0;
    insn.mov_zprza_qmova_zprza_q._unnamed_4 = 0b000;
    insn.mov_zprza_qmova_zprza_q.size = 0b11;
    insn.mov_zprza_qmova_zprza_q._unnamed_3 = 0b0;
    insn.mov_zprza_qmova_zprza_q._unnamed_2 = 0b0000;
    insn.mov_zprza_qmova_zprza_q._unnamed_1 = 0b10;
    insn.mov_zprza_qmova_zprza_q._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_za_p_rz_b_mova_za_p_rz_b(uint32_t off4, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_za_prz_bmova_za_prz_b.off4 = off4;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_7 = 0b0;
    insn.mov_za_prz_bmova_za_prz_b.Zn = Zn;
    insn.mov_za_prz_bmova_za_prz_b.Pg = Pg;
    insn.mov_za_prz_bmova_za_prz_b.Rs = Rs;
    insn.mov_za_prz_bmova_za_prz_b.V = V;
    insn.mov_za_prz_bmova_za_prz_b.Q = 0b0;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_6 = 0b0;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_5 = 0b0;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_4 = 0b000;
    insn.mov_za_prz_bmova_za_prz_b.size = 0b00;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_3 = 0b0;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_2 = 0b0000;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_1 = 0b10;
    insn.mov_za_prz_bmova_za_prz_b._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_za_p_rz_h_mova_za_p_rz_h(uint32_t off3, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_za_prz_hmova_za_prz_h.off3 = off3;
    insn.mov_za_prz_hmova_za_prz_h.ZAd = ZAd;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_7 = 0b0;
    insn.mov_za_prz_hmova_za_prz_h.Zn = Zn;
    insn.mov_za_prz_hmova_za_prz_h.Pg = Pg;
    insn.mov_za_prz_hmova_za_prz_h.Rs = Rs;
    insn.mov_za_prz_hmova_za_prz_h.V = V;
    insn.mov_za_prz_hmova_za_prz_h.Q = 0b0;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_6 = 0b0;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_5 = 0b0;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_4 = 0b000;
    insn.mov_za_prz_hmova_za_prz_h.size = 0b01;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_3 = 0b0;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_2 = 0b0000;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_1 = 0b10;
    insn.mov_za_prz_hmova_za_prz_h._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_za_p_rz_w_mova_za_p_rz_w(uint32_t off2, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_za_prz_wmova_za_prz_w.off2 = off2;
    insn.mov_za_prz_wmova_za_prz_w.ZAd = ZAd;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_7 = 0b0;
    insn.mov_za_prz_wmova_za_prz_w.Zn = Zn;
    insn.mov_za_prz_wmova_za_prz_w.Pg = Pg;
    insn.mov_za_prz_wmova_za_prz_w.Rs = Rs;
    insn.mov_za_prz_wmova_za_prz_w.V = V;
    insn.mov_za_prz_wmova_za_prz_w.Q = 0b0;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_6 = 0b0;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_5 = 0b0;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_4 = 0b000;
    insn.mov_za_prz_wmova_za_prz_w.size = 0b10;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_3 = 0b0;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_2 = 0b0000;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_1 = 0b10;
    insn.mov_za_prz_wmova_za_prz_w._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_za_p_rz_d_mova_za_p_rz_d(uint32_t o1, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_za_prz_dmova_za_prz_d.o1 = o1;
    insn.mov_za_prz_dmova_za_prz_d.ZAd = ZAd;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_7 = 0b0;
    insn.mov_za_prz_dmova_za_prz_d.Zn = Zn;
    insn.mov_za_prz_dmova_za_prz_d.Pg = Pg;
    insn.mov_za_prz_dmova_za_prz_d.Rs = Rs;
    insn.mov_za_prz_dmova_za_prz_d.V = V;
    insn.mov_za_prz_dmova_za_prz_d.Q = 0b0;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_6 = 0b0;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_5 = 0b0;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_4 = 0b000;
    insn.mov_za_prz_dmova_za_prz_d.size = 0b11;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_3 = 0b0;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_2 = 0b0000;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_1 = 0b10;
    insn.mov_za_prz_dmova_za_prz_d._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mov_za_p_rz_q_mova_za_p_rz_q(uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mov_za_prz_qmova_za_prz_q.ZAd = ZAd;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_7 = 0b0;
    insn.mov_za_prz_qmova_za_prz_q.Zn = Zn;
    insn.mov_za_prz_qmova_za_prz_q.Pg = Pg;
    insn.mov_za_prz_qmova_za_prz_q.Rs = Rs;
    insn.mov_za_prz_qmova_za_prz_q.V = V;
    insn.mov_za_prz_qmova_za_prz_q.Q = 0b1;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_6 = 0b0;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_5 = 0b0;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_4 = 0b000;
    insn.mov_za_prz_qmova_za_prz_q.size = 0b11;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_3 = 0b0;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_2 = 0b0000;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_1 = 0b10;
    insn.mov_za_prz_qmova_za_prz_q._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_z_p_rza_b(uint32_t Zd, uint32_t off4, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_zprza_b.Zd = Zd;
    insn.mova_zprza_b.off4 = off4;
    insn.mova_zprza_b._unnamed_7 = 0b0;
    insn.mova_zprza_b.Pg = Pg;
    insn.mova_zprza_b.Rs = Rs;
    insn.mova_zprza_b.V = V;
    insn.mova_zprza_b.Q = 0b0;
    insn.mova_zprza_b._unnamed_6 = 0b1;
    insn.mova_zprza_b._unnamed_5 = 0b0;
    insn.mova_zprza_b._unnamed_4 = 0b000;
    insn.mova_zprza_b.size = 0b00;
    insn.mova_zprza_b._unnamed_3 = 0b0;
    insn.mova_zprza_b._unnamed_2 = 0b0000;
    insn.mova_zprza_b._unnamed_1 = 0b10;
    insn.mova_zprza_b._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_z_p_rza_h(uint32_t Zd, uint32_t off3, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_zprza_h.Zd = Zd;
    insn.mova_zprza_h.off3 = off3;
    insn.mova_zprza_h.ZAn = ZAn;
    insn.mova_zprza_h._unnamed_7 = 0b0;
    insn.mova_zprza_h.Pg = Pg;
    insn.mova_zprza_h.Rs = Rs;
    insn.mova_zprza_h.V = V;
    insn.mova_zprza_h.Q = 0b0;
    insn.mova_zprza_h._unnamed_6 = 0b1;
    insn.mova_zprza_h._unnamed_5 = 0b0;
    insn.mova_zprza_h._unnamed_4 = 0b000;
    insn.mova_zprza_h.size = 0b01;
    insn.mova_zprza_h._unnamed_3 = 0b0;
    insn.mova_zprza_h._unnamed_2 = 0b0000;
    insn.mova_zprza_h._unnamed_1 = 0b10;
    insn.mova_zprza_h._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_z_p_rza_w(uint32_t Zd, uint32_t off2, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_zprza_w.Zd = Zd;
    insn.mova_zprza_w.off2 = off2;
    insn.mova_zprza_w.ZAn = ZAn;
    insn.mova_zprza_w._unnamed_7 = 0b0;
    insn.mova_zprza_w.Pg = Pg;
    insn.mova_zprza_w.Rs = Rs;
    insn.mova_zprza_w.V = V;
    insn.mova_zprza_w.Q = 0b0;
    insn.mova_zprza_w._unnamed_6 = 0b1;
    insn.mova_zprza_w._unnamed_5 = 0b0;
    insn.mova_zprza_w._unnamed_4 = 0b000;
    insn.mova_zprza_w.size = 0b10;
    insn.mova_zprza_w._unnamed_3 = 0b0;
    insn.mova_zprza_w._unnamed_2 = 0b0000;
    insn.mova_zprza_w._unnamed_1 = 0b10;
    insn.mova_zprza_w._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_z_p_rza_d(uint32_t Zd, uint32_t o1, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_zprza_d.Zd = Zd;
    insn.mova_zprza_d.o1 = o1;
    insn.mova_zprza_d.ZAn = ZAn;
    insn.mova_zprza_d._unnamed_7 = 0b0;
    insn.mova_zprza_d.Pg = Pg;
    insn.mova_zprza_d.Rs = Rs;
    insn.mova_zprza_d.V = V;
    insn.mova_zprza_d.Q = 0b0;
    insn.mova_zprza_d._unnamed_6 = 0b1;
    insn.mova_zprza_d._unnamed_5 = 0b0;
    insn.mova_zprza_d._unnamed_4 = 0b000;
    insn.mova_zprza_d.size = 0b11;
    insn.mova_zprza_d._unnamed_3 = 0b0;
    insn.mova_zprza_d._unnamed_2 = 0b0000;
    insn.mova_zprza_d._unnamed_1 = 0b10;
    insn.mova_zprza_d._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_z_p_rza_q(uint32_t Zd, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_zprza_q.Zd = Zd;
    insn.mova_zprza_q.ZAn = ZAn;
    insn.mova_zprza_q._unnamed_7 = 0b0;
    insn.mova_zprza_q.Pg = Pg;
    insn.mova_zprza_q.Rs = Rs;
    insn.mova_zprza_q.V = V;
    insn.mova_zprza_q.Q = 0b1;
    insn.mova_zprza_q._unnamed_6 = 0b1;
    insn.mova_zprza_q._unnamed_5 = 0b0;
    insn.mova_zprza_q._unnamed_4 = 0b000;
    insn.mova_zprza_q.size = 0b11;
    insn.mova_zprza_q._unnamed_3 = 0b0;
    insn.mova_zprza_q._unnamed_2 = 0b0000;
    insn.mova_zprza_q._unnamed_1 = 0b10;
    insn.mova_zprza_q._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_za_p_rz_b(uint32_t off4, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_za_prz_b.off4 = off4;
    insn.mova_za_prz_b._unnamed_7 = 0b0;
    insn.mova_za_prz_b.Zn = Zn;
    insn.mova_za_prz_b.Pg = Pg;
    insn.mova_za_prz_b.Rs = Rs;
    insn.mova_za_prz_b.V = V;
    insn.mova_za_prz_b.Q = 0b0;
    insn.mova_za_prz_b._unnamed_6 = 0b0;
    insn.mova_za_prz_b._unnamed_5 = 0b0;
    insn.mova_za_prz_b._unnamed_4 = 0b000;
    insn.mova_za_prz_b.size = 0b00;
    insn.mova_za_prz_b._unnamed_3 = 0b0;
    insn.mova_za_prz_b._unnamed_2 = 0b0000;
    insn.mova_za_prz_b._unnamed_1 = 0b10;
    insn.mova_za_prz_b._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_za_p_rz_h(uint32_t off3, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_za_prz_h.off3 = off3;
    insn.mova_za_prz_h.ZAd = ZAd;
    insn.mova_za_prz_h._unnamed_7 = 0b0;
    insn.mova_za_prz_h.Zn = Zn;
    insn.mova_za_prz_h.Pg = Pg;
    insn.mova_za_prz_h.Rs = Rs;
    insn.mova_za_prz_h.V = V;
    insn.mova_za_prz_h.Q = 0b0;
    insn.mova_za_prz_h._unnamed_6 = 0b0;
    insn.mova_za_prz_h._unnamed_5 = 0b0;
    insn.mova_za_prz_h._unnamed_4 = 0b000;
    insn.mova_za_prz_h.size = 0b01;
    insn.mova_za_prz_h._unnamed_3 = 0b0;
    insn.mova_za_prz_h._unnamed_2 = 0b0000;
    insn.mova_za_prz_h._unnamed_1 = 0b10;
    insn.mova_za_prz_h._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_za_p_rz_w(uint32_t off2, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_za_prz_w.off2 = off2;
    insn.mova_za_prz_w.ZAd = ZAd;
    insn.mova_za_prz_w._unnamed_7 = 0b0;
    insn.mova_za_prz_w.Zn = Zn;
    insn.mova_za_prz_w.Pg = Pg;
    insn.mova_za_prz_w.Rs = Rs;
    insn.mova_za_prz_w.V = V;
    insn.mova_za_prz_w.Q = 0b0;
    insn.mova_za_prz_w._unnamed_6 = 0b0;
    insn.mova_za_prz_w._unnamed_5 = 0b0;
    insn.mova_za_prz_w._unnamed_4 = 0b000;
    insn.mova_za_prz_w.size = 0b10;
    insn.mova_za_prz_w._unnamed_3 = 0b0;
    insn.mova_za_prz_w._unnamed_2 = 0b0000;
    insn.mova_za_prz_w._unnamed_1 = 0b10;
    insn.mova_za_prz_w._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_za_p_rz_d(uint32_t o1, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_za_prz_d.o1 = o1;
    insn.mova_za_prz_d.ZAd = ZAd;
    insn.mova_za_prz_d._unnamed_7 = 0b0;
    insn.mova_za_prz_d.Zn = Zn;
    insn.mova_za_prz_d.Pg = Pg;
    insn.mova_za_prz_d.Rs = Rs;
    insn.mova_za_prz_d.V = V;
    insn.mova_za_prz_d.Q = 0b0;
    insn.mova_za_prz_d._unnamed_6 = 0b0;
    insn.mova_za_prz_d._unnamed_5 = 0b0;
    insn.mova_za_prz_d._unnamed_4 = 0b000;
    insn.mova_za_prz_d.size = 0b11;
    insn.mova_za_prz_d._unnamed_3 = 0b0;
    insn.mova_za_prz_d._unnamed_2 = 0b0000;
    insn.mova_za_prz_d._unnamed_1 = 0b10;
    insn.mova_za_prz_d._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_mova_za_p_rz_q(uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V) {
    MortlachEncoding insn = {};
    insn.mova_za_prz_q.ZAd = ZAd;
    insn.mova_za_prz_q._unnamed_7 = 0b0;
    insn.mova_za_prz_q.Zn = Zn;
    insn.mova_za_prz_q.Pg = Pg;
    insn.mova_za_prz_q.Rs = Rs;
    insn.mova_za_prz_q.V = V;
    insn.mova_za_prz_q.Q = 0b1;
    insn.mova_za_prz_q._unnamed_6 = 0b0;
    insn.mova_za_prz_q._unnamed_5 = 0b0;
    insn.mova_za_prz_q._unnamed_4 = 0b000;
    insn.mova_za_prz_q.size = 0b11;
    insn.mova_za_prz_q._unnamed_3 = 0b0;
    insn.mova_za_prz_q._unnamed_2 = 0b0000;
    insn.mova_za_prz_q._unnamed_1 = 0b10;
    insn.mova_za_prz_q._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_rdsvl_r_i_(uint32_t Rd, uint32_t imm6) {
    MortlachEncoding insn = {};
    insn.rdsvl_ri.Rd = Rd;
    insn.rdsvl_ri.imm6 = imm6;
    insn.rdsvl_ri._unnamed_6 = 0b1;
    insn.rdsvl_ri._unnamed_5 = 0b0101;
    insn.rdsvl_ri.opc2 = 0b11111;
    insn.rdsvl_ri._unnamed_4 = 0b1;
    insn.rdsvl_ri.op = 0b0;
    insn.rdsvl_ri._unnamed_3 = 0b1;
    insn.rdsvl_ri._unnamed_2 = 0b0;
    insn.rdsvl_ri._unnamed_1 = 0b0010;
    insn.rdsvl_ri._unnamed_0 = 0b000;
    return insn.raw;
}

uint32_t encode_smopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.smopa_za_pp_zz32.ZAda = ZAda;
    insn.smopa_za_pp_zz32._unnamed_5 = 0b0;
    insn.smopa_za_pp_zz32._unnamed_4 = 0b0;
    insn.smopa_za_pp_zz32.S = 0b0;
    insn.smopa_za_pp_zz32.Zn = Zn;
    insn.smopa_za_pp_zz32.Pn = Pn;
    insn.smopa_za_pp_zz32.Pm = Pm;
    insn.smopa_za_pp_zz32.Zm = Zm;
    insn.smopa_za_pp_zz32.u1 = 0b0;
    insn.smopa_za_pp_zz32._unnamed_3 = 0b10;
    insn.smopa_za_pp_zz32.u0 = 0b0;
    insn.smopa_za_pp_zz32._unnamed_2 = 0b0000;
    insn.smopa_za_pp_zz32._unnamed_1 = 0b01;
    insn.smopa_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_smopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.smopa_za_pp_zz64.ZAda = ZAda;
    insn.smopa_za_pp_zz64._unnamed_5 = 0b0;
    insn.smopa_za_pp_zz64.S = 0b0;
    insn.smopa_za_pp_zz64.Zn = Zn;
    insn.smopa_za_pp_zz64.Pn = Pn;
    insn.smopa_za_pp_zz64.Pm = Pm;
    insn.smopa_za_pp_zz64.Zm = Zm;
    insn.smopa_za_pp_zz64.u1 = 0b0;
    insn.smopa_za_pp_zz64._unnamed_4 = 0b11;
    insn.smopa_za_pp_zz64.u0 = 0b0;
    insn.smopa_za_pp_zz64._unnamed_3 = 0b0000;
    insn.smopa_za_pp_zz64._unnamed_2 = 0b1;
    insn.smopa_za_pp_zz64._unnamed_1 = 0b0;
    insn.smopa_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_smops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.smops_za_pp_zz32.ZAda = ZAda;
    insn.smops_za_pp_zz32._unnamed_5 = 0b0;
    insn.smops_za_pp_zz32._unnamed_4 = 0b0;
    insn.smops_za_pp_zz32.S = 0b1;
    insn.smops_za_pp_zz32.Zn = Zn;
    insn.smops_za_pp_zz32.Pn = Pn;
    insn.smops_za_pp_zz32.Pm = Pm;
    insn.smops_za_pp_zz32.Zm = Zm;
    insn.smops_za_pp_zz32.u1 = 0b0;
    insn.smops_za_pp_zz32._unnamed_3 = 0b10;
    insn.smops_za_pp_zz32.u0 = 0b0;
    insn.smops_za_pp_zz32._unnamed_2 = 0b0000;
    insn.smops_za_pp_zz32._unnamed_1 = 0b01;
    insn.smops_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_smops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.smops_za_pp_zz64.ZAda = ZAda;
    insn.smops_za_pp_zz64._unnamed_5 = 0b0;
    insn.smops_za_pp_zz64.S = 0b1;
    insn.smops_za_pp_zz64.Zn = Zn;
    insn.smops_za_pp_zz64.Pn = Pn;
    insn.smops_za_pp_zz64.Pm = Pm;
    insn.smops_za_pp_zz64.Zm = Zm;
    insn.smops_za_pp_zz64.u1 = 0b0;
    insn.smops_za_pp_zz64._unnamed_4 = 0b11;
    insn.smops_za_pp_zz64.u0 = 0b0;
    insn.smops_za_pp_zz64._unnamed_3 = 0b0000;
    insn.smops_za_pp_zz64._unnamed_2 = 0b1;
    insn.smops_za_pp_zz64._unnamed_1 = 0b0;
    insn.smops_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_st1b_za_p_rrr_(uint32_t off4, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.st1b_za_prrr.off4 = off4;
    insn.st1b_za_prrr._unnamed_5 = 0b0;
    insn.st1b_za_prrr.Rn = Rn;
    insn.st1b_za_prrr.Pg = Pg;
    insn.st1b_za_prrr.Rs = Rs;
    insn.st1b_za_prrr.V = V;
    insn.st1b_za_prrr.Rm = Rm;
    insn.st1b_za_prrr._unnamed_4 = 0b1;
    insn.st1b_za_prrr.msz = 0b00;
    insn.st1b_za_prrr._unnamed_3 = 0b0;
    insn.st1b_za_prrr._unnamed_2 = 0b0000;
    insn.st1b_za_prrr._unnamed_1 = 0b11;
    insn.st1b_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_st1d_za_p_rrr_(uint32_t o1, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.st1d_za_prrr.o1 = o1;
    insn.st1d_za_prrr.ZAt = ZAt;
    insn.st1d_za_prrr._unnamed_5 = 0b0;
    insn.st1d_za_prrr.Rn = Rn;
    insn.st1d_za_prrr.Pg = Pg;
    insn.st1d_za_prrr.Rs = Rs;
    insn.st1d_za_prrr.V = V;
    insn.st1d_za_prrr.Rm = Rm;
    insn.st1d_za_prrr._unnamed_4 = 0b1;
    insn.st1d_za_prrr.msz = 0b11;
    insn.st1d_za_prrr._unnamed_3 = 0b0;
    insn.st1d_za_prrr._unnamed_2 = 0b0000;
    insn.st1d_za_prrr._unnamed_1 = 0b11;
    insn.st1d_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_st1h_za_p_rrr_(uint32_t off3, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.st1h_za_prrr.off3 = off3;
    insn.st1h_za_prrr.ZAt = ZAt;
    insn.st1h_za_prrr._unnamed_5 = 0b0;
    insn.st1h_za_prrr.Rn = Rn;
    insn.st1h_za_prrr.Pg = Pg;
    insn.st1h_za_prrr.Rs = Rs;
    insn.st1h_za_prrr.V = V;
    insn.st1h_za_prrr.Rm = Rm;
    insn.st1h_za_prrr._unnamed_4 = 0b1;
    insn.st1h_za_prrr.msz = 0b01;
    insn.st1h_za_prrr._unnamed_3 = 0b0;
    insn.st1h_za_prrr._unnamed_2 = 0b0000;
    insn.st1h_za_prrr._unnamed_1 = 0b11;
    insn.st1h_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_st1q_za_p_rrr_(uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.st1q_za_prrr.ZAt = ZAt;
    insn.st1q_za_prrr._unnamed_4 = 0b0;
    insn.st1q_za_prrr.Rn = Rn;
    insn.st1q_za_prrr.Pg = Pg;
    insn.st1q_za_prrr.Rs = Rs;
    insn.st1q_za_prrr.V = V;
    insn.st1q_za_prrr.Rm = Rm;
    insn.st1q_za_prrr._unnamed_3 = 0b1111;
    insn.st1q_za_prrr._unnamed_2 = 0b0000;
    insn.st1q_za_prrr._unnamed_1 = 0b11;
    insn.st1q_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_st1w_za_p_rrr_(uint32_t off2, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm) {
    MortlachEncoding insn = {};
    insn.st1w_za_prrr.off2 = off2;
    insn.st1w_za_prrr.ZAt = ZAt;
    insn.st1w_za_prrr._unnamed_5 = 0b0;
    insn.st1w_za_prrr.Rn = Rn;
    insn.st1w_za_prrr.Pg = Pg;
    insn.st1w_za_prrr.Rs = Rs;
    insn.st1w_za_prrr.V = V;
    insn.st1w_za_prrr.Rm = Rm;
    insn.st1w_za_prrr._unnamed_4 = 0b1;
    insn.st1w_za_prrr.msz = 0b10;
    insn.st1w_za_prrr._unnamed_3 = 0b0;
    insn.st1w_za_prrr._unnamed_2 = 0b0000;
    insn.st1w_za_prrr._unnamed_1 = 0b11;
    insn.st1w_za_prrr._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_str_za_ri_(uint32_t off4, uint32_t Rn, uint32_t Rv) {
    MortlachEncoding insn = {};
    insn.str_za_ri.off4 = off4;
    insn.str_za_ri._unnamed_7 = 0b0;
    insn.str_za_ri.Rn = Rn;
    insn.str_za_ri._unnamed_6 = 0b000;
    insn.str_za_ri.Rv = Rv;
    insn.str_za_ri._unnamed_5 = 0b0;
    insn.str_za_ri._unnamed_4 = 0b00000;
    insn.str_za_ri.op = 0b1;
    insn.str_za_ri._unnamed_3 = 0b100;
    insn.str_za_ri._unnamed_2 = 0b0000;
    insn.str_za_ri._unnamed_1 = 0b11;
    insn.str_za_ri._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_sumopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.sumopa_za_pp_zz32.ZAda = ZAda;
    insn.sumopa_za_pp_zz32._unnamed_5 = 0b0;
    insn.sumopa_za_pp_zz32._unnamed_4 = 0b0;
    insn.sumopa_za_pp_zz32.S = 0b0;
    insn.sumopa_za_pp_zz32.Zn = Zn;
    insn.sumopa_za_pp_zz32.Pn = Pn;
    insn.sumopa_za_pp_zz32.Pm = Pm;
    insn.sumopa_za_pp_zz32.Zm = Zm;
    insn.sumopa_za_pp_zz32.u1 = 0b1;
    insn.sumopa_za_pp_zz32._unnamed_3 = 0b10;
    insn.sumopa_za_pp_zz32.u0 = 0b0;
    insn.sumopa_za_pp_zz32._unnamed_2 = 0b0000;
    insn.sumopa_za_pp_zz32._unnamed_1 = 0b01;
    insn.sumopa_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_sumopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.sumopa_za_pp_zz64.ZAda = ZAda;
    insn.sumopa_za_pp_zz64._unnamed_5 = 0b0;
    insn.sumopa_za_pp_zz64.S = 0b0;
    insn.sumopa_za_pp_zz64.Zn = Zn;
    insn.sumopa_za_pp_zz64.Pn = Pn;
    insn.sumopa_za_pp_zz64.Pm = Pm;
    insn.sumopa_za_pp_zz64.Zm = Zm;
    insn.sumopa_za_pp_zz64.u1 = 0b1;
    insn.sumopa_za_pp_zz64._unnamed_4 = 0b11;
    insn.sumopa_za_pp_zz64.u0 = 0b0;
    insn.sumopa_za_pp_zz64._unnamed_3 = 0b0000;
    insn.sumopa_za_pp_zz64._unnamed_2 = 0b1;
    insn.sumopa_za_pp_zz64._unnamed_1 = 0b0;
    insn.sumopa_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_sumops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.sumops_za_pp_zz32.ZAda = ZAda;
    insn.sumops_za_pp_zz32._unnamed_5 = 0b0;
    insn.sumops_za_pp_zz32._unnamed_4 = 0b0;
    insn.sumops_za_pp_zz32.S = 0b1;
    insn.sumops_za_pp_zz32.Zn = Zn;
    insn.sumops_za_pp_zz32.Pn = Pn;
    insn.sumops_za_pp_zz32.Pm = Pm;
    insn.sumops_za_pp_zz32.Zm = Zm;
    insn.sumops_za_pp_zz32.u1 = 0b1;
    insn.sumops_za_pp_zz32._unnamed_3 = 0b10;
    insn.sumops_za_pp_zz32.u0 = 0b0;
    insn.sumops_za_pp_zz32._unnamed_2 = 0b0000;
    insn.sumops_za_pp_zz32._unnamed_1 = 0b01;
    insn.sumops_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_sumops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.sumops_za_pp_zz64.ZAda = ZAda;
    insn.sumops_za_pp_zz64._unnamed_5 = 0b0;
    insn.sumops_za_pp_zz64.S = 0b1;
    insn.sumops_za_pp_zz64.Zn = Zn;
    insn.sumops_za_pp_zz64.Pn = Pn;
    insn.sumops_za_pp_zz64.Pm = Pm;
    insn.sumops_za_pp_zz64.Zm = Zm;
    insn.sumops_za_pp_zz64.u1 = 0b1;
    insn.sumops_za_pp_zz64._unnamed_4 = 0b11;
    insn.sumops_za_pp_zz64.u0 = 0b0;
    insn.sumops_za_pp_zz64._unnamed_3 = 0b0000;
    insn.sumops_za_pp_zz64._unnamed_2 = 0b1;
    insn.sumops_za_pp_zz64._unnamed_1 = 0b0;
    insn.sumops_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_umopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.umopa_za_pp_zz32.ZAda = ZAda;
    insn.umopa_za_pp_zz32._unnamed_5 = 0b0;
    insn.umopa_za_pp_zz32._unnamed_4 = 0b0;
    insn.umopa_za_pp_zz32.S = 0b0;
    insn.umopa_za_pp_zz32.Zn = Zn;
    insn.umopa_za_pp_zz32.Pn = Pn;
    insn.umopa_za_pp_zz32.Pm = Pm;
    insn.umopa_za_pp_zz32.Zm = Zm;
    insn.umopa_za_pp_zz32.u1 = 0b1;
    insn.umopa_za_pp_zz32._unnamed_3 = 0b10;
    insn.umopa_za_pp_zz32.u0 = 0b1;
    insn.umopa_za_pp_zz32._unnamed_2 = 0b0000;
    insn.umopa_za_pp_zz32._unnamed_1 = 0b01;
    insn.umopa_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_umopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.umopa_za_pp_zz64.ZAda = ZAda;
    insn.umopa_za_pp_zz64._unnamed_5 = 0b0;
    insn.umopa_za_pp_zz64.S = 0b0;
    insn.umopa_za_pp_zz64.Zn = Zn;
    insn.umopa_za_pp_zz64.Pn = Pn;
    insn.umopa_za_pp_zz64.Pm = Pm;
    insn.umopa_za_pp_zz64.Zm = Zm;
    insn.umopa_za_pp_zz64.u1 = 0b1;
    insn.umopa_za_pp_zz64._unnamed_4 = 0b11;
    insn.umopa_za_pp_zz64.u0 = 0b1;
    insn.umopa_za_pp_zz64._unnamed_3 = 0b0000;
    insn.umopa_za_pp_zz64._unnamed_2 = 0b1;
    insn.umopa_za_pp_zz64._unnamed_1 = 0b0;
    insn.umopa_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_umops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.umops_za_pp_zz32.ZAda = ZAda;
    insn.umops_za_pp_zz32._unnamed_5 = 0b0;
    insn.umops_za_pp_zz32._unnamed_4 = 0b0;
    insn.umops_za_pp_zz32.S = 0b1;
    insn.umops_za_pp_zz32.Zn = Zn;
    insn.umops_za_pp_zz32.Pn = Pn;
    insn.umops_za_pp_zz32.Pm = Pm;
    insn.umops_za_pp_zz32.Zm = Zm;
    insn.umops_za_pp_zz32.u1 = 0b1;
    insn.umops_za_pp_zz32._unnamed_3 = 0b10;
    insn.umops_za_pp_zz32.u0 = 0b1;
    insn.umops_za_pp_zz32._unnamed_2 = 0b0000;
    insn.umops_za_pp_zz32._unnamed_1 = 0b01;
    insn.umops_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_umops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.umops_za_pp_zz64.ZAda = ZAda;
    insn.umops_za_pp_zz64._unnamed_5 = 0b0;
    insn.umops_za_pp_zz64.S = 0b1;
    insn.umops_za_pp_zz64.Zn = Zn;
    insn.umops_za_pp_zz64.Pn = Pn;
    insn.umops_za_pp_zz64.Pm = Pm;
    insn.umops_za_pp_zz64.Zm = Zm;
    insn.umops_za_pp_zz64.u1 = 0b1;
    insn.umops_za_pp_zz64._unnamed_4 = 0b11;
    insn.umops_za_pp_zz64.u0 = 0b1;
    insn.umops_za_pp_zz64._unnamed_3 = 0b0000;
    insn.umops_za_pp_zz64._unnamed_2 = 0b1;
    insn.umops_za_pp_zz64._unnamed_1 = 0b0;
    insn.umops_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_usmopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.usmopa_za_pp_zz32.ZAda = ZAda;
    insn.usmopa_za_pp_zz32._unnamed_5 = 0b0;
    insn.usmopa_za_pp_zz32._unnamed_4 = 0b0;
    insn.usmopa_za_pp_zz32.S = 0b0;
    insn.usmopa_za_pp_zz32.Zn = Zn;
    insn.usmopa_za_pp_zz32.Pn = Pn;
    insn.usmopa_za_pp_zz32.Pm = Pm;
    insn.usmopa_za_pp_zz32.Zm = Zm;
    insn.usmopa_za_pp_zz32.u1 = 0b0;
    insn.usmopa_za_pp_zz32._unnamed_3 = 0b10;
    insn.usmopa_za_pp_zz32.u0 = 0b1;
    insn.usmopa_za_pp_zz32._unnamed_2 = 0b0000;
    insn.usmopa_za_pp_zz32._unnamed_1 = 0b01;
    insn.usmopa_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_usmopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.usmopa_za_pp_zz64.ZAda = ZAda;
    insn.usmopa_za_pp_zz64._unnamed_5 = 0b0;
    insn.usmopa_za_pp_zz64.S = 0b0;
    insn.usmopa_za_pp_zz64.Zn = Zn;
    insn.usmopa_za_pp_zz64.Pn = Pn;
    insn.usmopa_za_pp_zz64.Pm = Pm;
    insn.usmopa_za_pp_zz64.Zm = Zm;
    insn.usmopa_za_pp_zz64.u1 = 0b0;
    insn.usmopa_za_pp_zz64._unnamed_4 = 0b11;
    insn.usmopa_za_pp_zz64.u0 = 0b1;
    insn.usmopa_za_pp_zz64._unnamed_3 = 0b0000;
    insn.usmopa_za_pp_zz64._unnamed_2 = 0b1;
    insn.usmopa_za_pp_zz64._unnamed_1 = 0b0;
    insn.usmopa_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_usmops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.usmops_za_pp_zz32.ZAda = ZAda;
    insn.usmops_za_pp_zz32._unnamed_5 = 0b0;
    insn.usmops_za_pp_zz32._unnamed_4 = 0b0;
    insn.usmops_za_pp_zz32.S = 0b1;
    insn.usmops_za_pp_zz32.Zn = Zn;
    insn.usmops_za_pp_zz32.Pn = Pn;
    insn.usmops_za_pp_zz32.Pm = Pm;
    insn.usmops_za_pp_zz32.Zm = Zm;
    insn.usmops_za_pp_zz32.u1 = 0b0;
    insn.usmops_za_pp_zz32._unnamed_3 = 0b10;
    insn.usmops_za_pp_zz32.u0 = 0b1;
    insn.usmops_za_pp_zz32._unnamed_2 = 0b0000;
    insn.usmops_za_pp_zz32._unnamed_1 = 0b01;
    insn.usmops_za_pp_zz32._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_usmops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm) {
    MortlachEncoding insn = {};
    insn.usmops_za_pp_zz64.ZAda = ZAda;
    insn.usmops_za_pp_zz64._unnamed_5 = 0b0;
    insn.usmops_za_pp_zz64.S = 0b1;
    insn.usmops_za_pp_zz64.Zn = Zn;
    insn.usmops_za_pp_zz64.Pn = Pn;
    insn.usmops_za_pp_zz64.Pm = Pm;
    insn.usmops_za_pp_zz64.Zm = Zm;
    insn.usmops_za_pp_zz64.u1 = 0b0;
    insn.usmops_za_pp_zz64._unnamed_4 = 0b11;
    insn.usmops_za_pp_zz64.u0 = 0b1;
    insn.usmops_za_pp_zz64._unnamed_3 = 0b0000;
    insn.usmops_za_pp_zz64._unnamed_2 = 0b1;
    insn.usmops_za_pp_zz64._unnamed_1 = 0b0;
    insn.usmops_za_pp_zz64._unnamed_0 = 0b1;
    return insn.raw;
}

uint32_t encode_zero_za_i_(uint32_t imm8) {
    MortlachEncoding insn = {};
    insn.zero_za_i.imm8 = imm8;
    insn.zero_za_i._unnamed_4 = 0b0000000000;
    insn.zero_za_i._unnamed_3 = 0b0000010;
    insn.zero_za_i._unnamed_2 = 0b0000;
    insn.zero_za_i._unnamed_1 = 0b10;
    insn.zero_za_i._unnamed_0 = 0b1;
    return insn.raw;
}

// Decode function implementation
// Decode a mortlach instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_mortlach(uint32_t insn) {
    // Switch for mask 0xFFFFFF00u (1 pattern, 1 encoding)
    switch (insn & 0xFFFFFF00u) {
        case 0xC0080000u: { // zero_za_i_
                        Instruction result(Mnemonic::ZERO, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.zero_za_i.imm8, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF800u (1 pattern, 1 encoding)
    switch (insn & 0xFFFFF800u) {
        case 0x04BF5800u: { // rdsvl_r_i_
                        Instruction result(Mnemonic::RDSVL, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.rdsvl_ri.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.rdsvl_ri.imm6, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF9C10u (2 patterns, 2 encodings)
    switch (insn & 0xFFFF9C10u) {
        case 0xE1000000u: { // ldr_za_ri_
                        Instruction result(Mnemonic::LDR, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_za_ri.Rn, is_64bit));
                        return result;
        }
        case 0xE1200000u: { // str_za_ri_
                        Instruction result(Mnemonic::STR, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_za_ri.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF0200u (5 patterns, 10 encodings)
    switch (insn & 0xFFFF0200u) {
        case 0xC0020000u: { // mov_z_p_rza_b_mova_z_p_rza_b
            // Also matches: mova_z_p_rza_b (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_zprza_bmova_zprza_b.Rs, is_64bit));
                        return result;
        }
        case 0xC0420000u: { // mov_z_p_rza_h_mova_z_p_rza_h
            // Also matches: mova_z_p_rza_h (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_zprza_hmova_zprza_h.Rs, is_64bit));
                        return result;
        }
        case 0xC0820000u: { // mov_z_p_rza_w_mova_z_p_rza_w
            // Also matches: mova_z_p_rza_w (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_zprza_wmova_zprza_w.Rs, is_64bit));
                        return result;
        }
        case 0xC0C20000u: { // mov_z_p_rza_d_mova_z_p_rza_d
            // Also matches: mova_z_p_rza_d (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_zprza_dmova_zprza_d.Rs, is_64bit));
                        return result;
        }
        case 0xC0C30000u: { // mov_z_p_rza_q_mova_z_p_rza_q
            // Also matches: mova_z_p_rza_q (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_zprza_qmova_zprza_q.Rs, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF001Cu (2 patterns, 2 encodings)
    switch (insn & 0xFFFF001Cu) {
        case 0xC0900000u: { // addha_za_pp_z_32
                        Instruction result(Mnemonic::ADDHA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xC0910000u: { // addva_za_pp_z_32
                        Instruction result(Mnemonic::ADDVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF0018u (2 patterns, 2 encodings)
    switch (insn & 0xFFFF0018u) {
        case 0xC0D00000u: { // addha_za_pp_z_64
                        Instruction result(Mnemonic::ADDHA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xC0D10000u: { // addva_za_pp_z_64
                        Instruction result(Mnemonic::ADDVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF0010u (5 patterns, 10 encodings)
    switch (insn & 0xFFFF0010u) {
        case 0xC0000000u: { // mov_za_p_rz_b_mova_za_p_rz_b
            // Also matches: mova_za_p_rz_b (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_za_prz_bmova_za_prz_b.Rs, is_64bit));
                        return result;
        }
        case 0xC0400000u: { // mov_za_p_rz_h_mova_za_p_rz_h
            // Also matches: mova_za_p_rz_h (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_za_prz_hmova_za_prz_h.Rs, is_64bit));
                        return result;
        }
        case 0xC0800000u: { // mov_za_p_rz_w_mova_za_p_rz_w
            // Also matches: mova_za_p_rz_w (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_za_prz_wmova_za_prz_w.Rs, is_64bit));
                        return result;
        }
        case 0xC0C00000u: { // mov_za_p_rz_d_mova_za_p_rz_d
            // Also matches: mova_za_p_rz_d (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_za_prz_dmova_za_prz_d.Rs, is_64bit));
                        return result;
        }
        case 0xC0C10000u: { // mov_za_p_rz_q_mova_za_p_rz_q
            // Also matches: mova_za_p_rz_q (MOVA)
                        Instruction result(Mnemonic::MOVA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mov_za_prz_qmova_za_prz_q.Rs, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0F800u (2 patterns, 2 encodings)
    switch (insn & 0xFFE0F800u) {
        case 0x04205800u: { // addsvl_r_ri_
                        Instruction result(Mnemonic::ADDSVL, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.addsvl_rri.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.addsvl_rri.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.addsvl_rri.imm6, true));
                        return result;
        }
        case 0x04605800u: { // addspl_r_ri_
                        Instruction result(Mnemonic::ADDSPL, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.addspl_rri.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.addspl_rri.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.addspl_rri.imm6, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Cu (12 patterns, 12 encodings)
    switch (insn & 0xFFE0001Cu) {
        case 0x81800000u: { // bfmopa_za32_pp_zz_
                        Instruction result(Mnemonic::BFMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0x81800010u: { // bfmops_za32_pp_zz_
                        Instruction result(Mnemonic::BFMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0x81A00000u: { // fmopa_za32_pp_zz_16
                        Instruction result(Mnemonic::FMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0x81A00010u: { // fmops_za32_pp_zz_16
                        Instruction result(Mnemonic::FMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0800000u: { // smopa_za_pp_zz_32
                        Instruction result(Mnemonic::SMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0800010u: { // smops_za_pp_zz_32
                        Instruction result(Mnemonic::SMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0A00000u: { // sumopa_za_pp_zz_32
                        Instruction result(Mnemonic::SUMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0A00010u: { // sumops_za_pp_zz_32
                        Instruction result(Mnemonic::SUMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1800000u: { // usmopa_za_pp_zz_32
                        Instruction result(Mnemonic::USMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1800010u: { // usmops_za_pp_zz_32
                        Instruction result(Mnemonic::USMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1A00000u: { // umopa_za_pp_zz_32
                        Instruction result(Mnemonic::UMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1A00010u: { // umops_za_pp_zz_32
                        Instruction result(Mnemonic::UMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00018u (8 patterns, 8 encodings)
    switch (insn & 0xFFE00018u) {
        case 0xA0C00000u: { // smopa_za_pp_zz_64
                        Instruction result(Mnemonic::SMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0C00010u: { // smops_za_pp_zz_64
                        Instruction result(Mnemonic::SMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0E00000u: { // sumopa_za_pp_zz_64
                        Instruction result(Mnemonic::SUMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA0E00010u: { // sumops_za_pp_zz_64
                        Instruction result(Mnemonic::SUMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1C00000u: { // usmopa_za_pp_zz_64
                        Instruction result(Mnemonic::USMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1C00010u: { // usmops_za_pp_zz_64
                        Instruction result(Mnemonic::USMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1E00000u: { // umopa_za_pp_zz_64
                        Instruction result(Mnemonic::UMOPA, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xA1E00010u: { // umops_za_pp_zz_64
                        Instruction result(Mnemonic::UMOPS, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00010u (10 patterns, 10 encodings)
    switch (insn & 0xFFE00010u) {
        case 0xE0000000u: { // ld1b_za_p_rrr_
                        Instruction result(Mnemonic::LD1B, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1b_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1b_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1b_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0200000u: { // st1b_za_p_rrr_
                        Instruction result(Mnemonic::ST1B, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1b_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1b_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1b_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0400000u: { // ld1h_za_p_rrr_
                        Instruction result(Mnemonic::LD1H, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1h_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1h_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1h_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0600000u: { // st1h_za_p_rrr_
                        Instruction result(Mnemonic::ST1H, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1h_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1h_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1h_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0800000u: { // ld1w_za_p_rrr_
                        Instruction result(Mnemonic::LD1W, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1w_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0A00000u: { // st1w_za_p_rrr_
                        Instruction result(Mnemonic::ST1W, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1w_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0C00000u: { // ld1d_za_p_rrr_
                        Instruction result(Mnemonic::LD1D, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1d_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE0E00000u: { // st1d_za_p_rrr_
                        Instruction result(Mnemonic::ST1D, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1d_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE1C00000u: { // ld1q_za_p_rrr_
                        Instruction result(Mnemonic::LD1Q, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1q_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1q_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ld1q_za_prrr.Rs, is_64bit));
                        return result;
        }
        case 0xE1E00000u: { // st1q_za_p_rrr_
                        Instruction result(Mnemonic::ST1Q, insn);
                        MortlachEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.st1q_za_prrr.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1q_za_prrr.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.st1q_za_prrr.Rs, is_64bit));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace Mortlach
} // namespace veda64
