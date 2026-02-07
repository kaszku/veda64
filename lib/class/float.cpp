#include "class/float.hpp"

namespace veda64 {
namespace Float {

// Internal encoding structures
// BFCVT: Single-precision convert to BFloat16 (scalar)
// Encoding: BFCVT_BS_floatdp1
// Template: BFCVT  <Hd>, <Sn>
struct BfcvtBsFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_5 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opcode : 6;  // fixed: 0b000110 (0x6)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FABS: Floating-point absolute value (scalar)
// Encoding: FABS_H_floatdp1
// Template: FABS  <Hd>, <Hn>
struct FabsHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FABS: Floating-point absolute value (scalar)
// Encoding: FABS_S_floatdp1
// Template: FABS  <Sd>, <Sn>
struct FabsSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FABS: Floating-point absolute value (scalar)
// Encoding: FABS_D_floatdp1
// Template: FABS  <Dd>, <Dn>
struct FabsDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FADD: Floating-point add (scalar)
// Encoding: FADD_H_floatdp2
// Template: FADD  <Hd>, <Hn>, <Hm>
struct FaddHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FADD: Floating-point add (scalar)
// Encoding: FADD_S_floatdp2
// Template: FADD  <Sd>, <Sn>, <Sm>
struct FaddSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FADD: Floating-point add (scalar)
// Encoding: FADD_D_floatdp2
// Template: FADD  <Dd>, <Dn>, <Dm>
struct FaddDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMP: Floating-point conditional quiet compare (scalar)
// Encoding: FCCMP_H_floatccmp
// Template: FCCMP  <Hn>, <Hm>, #<nzcv>, <cond>
struct FccmpHFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMP: Floating-point conditional quiet compare (scalar)
// Encoding: FCCMP_S_floatccmp
// Template: FCCMP  <Sn>, <Sm>, #<nzcv>, <cond>
struct FccmpSFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMP: Floating-point conditional quiet compare (scalar)
// Encoding: FCCMP_D_floatccmp
// Template: FCCMP  <Dn>, <Dm>, #<nzcv>, <cond>
struct FccmpDFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMPE: Floating-point conditional signaling compare (scalar)
// Encoding: FCCMPE_H_floatccmp
// Template: FCCMPE  <Hn>, <Hm>, #<nzcv>, <cond>
struct FccmpeHFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMPE: Floating-point conditional signaling compare (scalar)
// Encoding: FCCMPE_S_floatccmp
// Template: FCCMPE  <Sn>, <Sm>, #<nzcv>, <cond>
struct FccmpeSFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCCMPE: Floating-point conditional signaling compare (scalar)
// Encoding: FCCMPE_D_floatccmp
// Template: FCCMPE  <Dn>, <Dm>, #<nzcv>, <cond>
struct FccmpeDFloatccmp {
    uint32_t nzcv : 4;
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_H_floatcmp
// Template: FCMP  <Hn>, <Hm>
struct FcmpHFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_HZ_floatcmp
// Template: FCMP  <Hn>, #0.0
struct FcmpHzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_S_floatcmp
// Template: FCMP  <Sn>, <Sm>
struct FcmpSFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_SZ_floatcmp
// Template: FCMP  <Sn>, #0.0
struct FcmpSzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_D_floatcmp
// Template: FCMP  <Dn>, <Dm>
struct FcmpDFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMP: Floating-point quiet compare (scalar)
// Encoding: FCMP_DZ_floatcmp
// Template: FCMP  <Dn>, #0.0
struct FcmpDzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_H_floatcmp
// Template: FCMPE  <Hn>, <Hm>
struct FcmpeHFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_HZ_floatcmp
// Template: FCMPE  <Hn>, #0.0
struct FcmpeHzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_S_floatcmp
// Template: FCMPE  <Sn>, <Sm>
struct FcmpeSFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_SZ_floatcmp
// Template: FCMPE  <Sn>, #0.0
struct FcmpeSzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_D_floatcmp
// Template: FCMPE  <Dn>, <Dm>
struct FcmpeDFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCMPE: Floating-point signaling compare (scalar)
// Encoding: FCMPE_DZ_floatcmp
// Template: FCMPE  <Dn>, #0.0
struct FcmpeDzFloatcmp {
    uint32_t _unnamed_4 : 3;  // fixed: 0b000 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 4;  // fixed: 0b1000 (0x8)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCSEL: Floating-point conditional select (scalar)
// Encoding: FCSEL_H_floatsel
// Template: FCSEL  <Hd>, <Hn>, <Hm>, <cond>
struct FcselHFloatsel {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCSEL: Floating-point conditional select (scalar)
// Encoding: FCSEL_S_floatsel
// Template: FCSEL  <Sd>, <Sn>, <Sm>, <cond>
struct FcselSFloatsel {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCSEL: Floating-point conditional select (scalar)
// Encoding: FCSEL_D_floatsel
// Template: FCSEL  <Dd>, <Dn>, <Dm>, <cond>
struct FcselDFloatsel {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    uint32_t cond : 4;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_SH_floatdp1
// Template: FCVT  <Sd>, <Hn>
struct FcvtShFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_DH_floatdp1
// Template: FCVT  <Dd>, <Hn>
struct FcvtDhFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_HS_floatdp1
// Template: FCVT  <Hd>, <Sn>
struct FcvtHsFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_DS_floatdp1
// Template: FCVT  <Dd>, <Sn>
struct FcvtDsFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_HD_floatdp1
// Template: FCVT  <Hd>, <Dn>
struct FcvtHdFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVT: Floating-point convert precision (scalar)
// Encoding: FCVT_SD_floatdp1
// Template: FCVT  <Sd>, <Dn>
struct FcvtSdFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10001 (0x11)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_32H_float2int
// Template: FCVTAS  <Wd>, <Hn>
struct Fcvtas32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_64H_float2int
// Template: FCVTAS  <Xd>, <Hn>
struct Fcvtas64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_32S_float2int
// Template: FCVTAS  <Wd>, <Sn>
struct Fcvtas32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_64S_float2int
// Template: FCVTAS  <Xd>, <Sn>
struct Fcvtas64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_32D_float2int
// Template: FCVTAS  <Wd>, <Dn>
struct Fcvtas32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAS_64D_float2int
// Template: FCVTAS  <Xd>, <Dn>
struct Fcvtas64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAS_sisd_32H
// Template: FCVTAS  <Sd>, <Hn>
struct FcvtasSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAS_sisd_64H
// Template: FCVTAS  <Dd>, <Hn>
struct FcvtasSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAS_sisd_64S
// Template: FCVTAS  <Dd>, <Sn>
struct FcvtasSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAS: Floating-point convert to signed integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAS_sisd_32D
// Template: FCVTAS  <Sd>, <Dn>
struct FcvtasSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_32H_float2int
// Template: FCVTAU  <Wd>, <Hn>
struct Fcvtau32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_64H_float2int
// Template: FCVTAU  <Xd>, <Hn>
struct Fcvtau64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_32S_float2int
// Template: FCVTAU  <Wd>, <Sn>
struct Fcvtau32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_64S_float2int
// Template: FCVTAU  <Xd>, <Sn>
struct Fcvtau64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_32D_float2int
// Template: FCVTAU  <Wd>, <Dn>
struct Fcvtau32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar)
// Encoding: FCVTAU_64D_float2int
// Template: FCVTAU  <Xd>, <Dn>
struct Fcvtau64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAU_sisd_32H
// Template: FCVTAU  <Sd>, <Hn>
struct FcvtauSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAU_sisd_64H
// Template: FCVTAU  <Dd>, <Hn>
struct FcvtauSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAU_sisd_64S
// Template: FCVTAU  <Dd>, <Sn>
struct FcvtauSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTAU: Floating-point convert to unsigned integer, rounding to nearest with ties to away (scalar SIMD&FP)
// Encoding: FCVTAU_sisd_32D
// Template: FCVTAU  <Sd>, <Dn>
struct FcvtauSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_32H_float2int
// Template: FCVTMS  <Wd>, <Hn>
struct Fcvtms32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_64H_float2int
// Template: FCVTMS  <Xd>, <Hn>
struct Fcvtms64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_32S_float2int
// Template: FCVTMS  <Wd>, <Sn>
struct Fcvtms32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_64S_float2int
// Template: FCVTMS  <Xd>, <Sn>
struct Fcvtms64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_32D_float2int
// Template: FCVTMS  <Wd>, <Dn>
struct Fcvtms32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMS_64D_float2int
// Template: FCVTMS  <Xd>, <Dn>
struct Fcvtms64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMS_sisd_32H
// Template: FCVTMS  <Sd>, <Hn>
struct FcvtmsSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMS_sisd_64H
// Template: FCVTMS  <Dd>, <Hn>
struct FcvtmsSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMS_sisd_64S
// Template: FCVTMS  <Dd>, <Sn>
struct FcvtmsSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMS: Floating-point convert to signed integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMS_sisd_32D
// Template: FCVTMS  <Sd>, <Dn>
struct FcvtmsSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_32H_float2int
// Template: FCVTMU  <Wd>, <Hn>
struct Fcvtmu32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_64H_float2int
// Template: FCVTMU  <Xd>, <Hn>
struct Fcvtmu64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_32S_float2int
// Template: FCVTMU  <Wd>, <Sn>
struct Fcvtmu32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_64S_float2int
// Template: FCVTMU  <Xd>, <Sn>
struct Fcvtmu64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_32D_float2int
// Template: FCVTMU  <Wd>, <Dn>
struct Fcvtmu32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar)
// Encoding: FCVTMU_64D_float2int
// Template: FCVTMU  <Xd>, <Dn>
struct Fcvtmu64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMU_sisd_32H
// Template: FCVTMU  <Sd>, <Hn>
struct FcvtmuSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMU_sisd_64H
// Template: FCVTMU  <Dd>, <Hn>
struct FcvtmuSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMU_sisd_64S
// Template: FCVTMU  <Dd>, <Sn>
struct FcvtmuSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTMU: Floating-point convert to unsigned integer, rounding toward minus infinity (scalar SIMD&FP)
// Encoding: FCVTMU_sisd_32D
// Template: FCVTMU  <Sd>, <Dn>
struct FcvtmuSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_32H_float2int
// Template: FCVTNS  <Wd>, <Hn>
struct Fcvtns32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_64H_float2int
// Template: FCVTNS  <Xd>, <Hn>
struct Fcvtns64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_32S_float2int
// Template: FCVTNS  <Wd>, <Sn>
struct Fcvtns32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_64S_float2int
// Template: FCVTNS  <Xd>, <Sn>
struct Fcvtns64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_32D_float2int
// Template: FCVTNS  <Wd>, <Dn>
struct Fcvtns32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNS_64D_float2int
// Template: FCVTNS  <Xd>, <Dn>
struct Fcvtns64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNS_sisd_32H
// Template: FCVTNS  <Sd>, <Hn>
struct FcvtnsSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNS_sisd_64H
// Template: FCVTNS  <Dd>, <Hn>
struct FcvtnsSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNS_sisd_64S
// Template: FCVTNS  <Dd>, <Sn>
struct FcvtnsSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNS: Floating-point convert to signed integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNS_sisd_32D
// Template: FCVTNS  <Sd>, <Dn>
struct FcvtnsSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_32H_float2int
// Template: FCVTNU  <Wd>, <Hn>
struct Fcvtnu32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_64H_float2int
// Template: FCVTNU  <Xd>, <Hn>
struct Fcvtnu64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_32S_float2int
// Template: FCVTNU  <Wd>, <Sn>
struct Fcvtnu32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_64S_float2int
// Template: FCVTNU  <Xd>, <Sn>
struct Fcvtnu64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_32D_float2int
// Template: FCVTNU  <Wd>, <Dn>
struct Fcvtnu32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar)
// Encoding: FCVTNU_64D_float2int
// Template: FCVTNU  <Xd>, <Dn>
struct Fcvtnu64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNU_sisd_32H
// Template: FCVTNU  <Sd>, <Hn>
struct FcvtnuSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNU_sisd_64H
// Template: FCVTNU  <Dd>, <Hn>
struct FcvtnuSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNU_sisd_64S
// Template: FCVTNU  <Dd>, <Sn>
struct FcvtnuSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTNU: Floating-point convert to unsigned integer, rounding to nearest with ties to even (scalar SIMD&FP)
// Encoding: FCVTNU_sisd_32D
// Template: FCVTNU  <Sd>, <Dn>
struct FcvtnuSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_32H_float2int
// Template: FCVTPS  <Wd>, <Hn>
struct Fcvtps32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_64H_float2int
// Template: FCVTPS  <Xd>, <Hn>
struct Fcvtps64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_32S_float2int
// Template: FCVTPS  <Wd>, <Sn>
struct Fcvtps32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_64S_float2int
// Template: FCVTPS  <Xd>, <Sn>
struct Fcvtps64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_32D_float2int
// Template: FCVTPS  <Wd>, <Dn>
struct Fcvtps32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPS_64D_float2int
// Template: FCVTPS  <Xd>, <Dn>
struct Fcvtps64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPS_sisd_32H
// Template: FCVTPS  <Sd>, <Hn>
struct FcvtpsSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPS_sisd_64H
// Template: FCVTPS  <Dd>, <Hn>
struct FcvtpsSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPS_sisd_64S
// Template: FCVTPS  <Dd>, <Sn>
struct FcvtpsSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPS: Floating-point convert to signed integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPS_sisd_32D
// Template: FCVTPS  <Sd>, <Dn>
struct FcvtpsSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_32H_float2int
// Template: FCVTPU  <Wd>, <Hn>
struct Fcvtpu32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_64H_float2int
// Template: FCVTPU  <Xd>, <Hn>
struct Fcvtpu64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_32S_float2int
// Template: FCVTPU  <Wd>, <Sn>
struct Fcvtpu32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_64S_float2int
// Template: FCVTPU  <Xd>, <Sn>
struct Fcvtpu64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_32D_float2int
// Template: FCVTPU  <Wd>, <Dn>
struct Fcvtpu32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar)
// Encoding: FCVTPU_64D_float2int
// Template: FCVTPU  <Xd>, <Dn>
struct Fcvtpu64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPU_sisd_32H
// Template: FCVTPU  <Sd>, <Hn>
struct FcvtpuSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPU_sisd_64H
// Template: FCVTPU  <Dd>, <Hn>
struct FcvtpuSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPU_sisd_64S
// Template: FCVTPU  <Dd>, <Sn>
struct FcvtpuSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTPU: Floating-point convert to unsigned integer, rounding toward plus infinity (scalar SIMD&FP)
// Encoding: FCVTPU_sisd_32D
// Template: FCVTPU  <Sd>, <Dn>
struct FcvtpuSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_32H_float2fix
// Template: FCVTZS  <Wd>, <Hn>, #<fbits>
struct Fcvtzs32hFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_64H_float2fix
// Template: FCVTZS  <Xd>, <Hn>, #<fbits>
struct Fcvtzs64hFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_32S_float2fix
// Template: FCVTZS  <Wd>, <Sn>, #<fbits>
struct Fcvtzs32sFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_64S_float2fix
// Template: FCVTZS  <Xd>, <Sn>, #<fbits>
struct Fcvtzs64sFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_32D_float2fix
// Template: FCVTZS  <Wd>, <Dn>, #<fbits>
struct Fcvtzs32dFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZS_64D_float2fix
// Template: FCVTZS  <Xd>, <Dn>, #<fbits>
struct Fcvtzs64dFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_32H_float2int
// Template: FCVTZS  <Wd>, <Hn>
struct Fcvtzs32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_64H_float2int
// Template: FCVTZS  <Xd>, <Hn>
struct Fcvtzs64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_32S_float2int
// Template: FCVTZS  <Wd>, <Sn>
struct Fcvtzs32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_64S_float2int
// Template: FCVTZS  <Xd>, <Sn>
struct Fcvtzs64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_32D_float2int
// Template: FCVTZS  <Wd>, <Dn>
struct Fcvtzs32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar)
// Encoding: FCVTZS_64D_float2int
// Template: FCVTZS  <Xd>, <Dn>
struct Fcvtzs64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b000 (0x0)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZS_sisd_32H
// Template: FCVTZS  <Sd>, <Hn>
struct FcvtzsSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZS_sisd_64H
// Template: FCVTZS  <Dd>, <Hn>
struct FcvtzsSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZS_sisd_64S
// Template: FCVTZS  <Dd>, <Sn>
struct FcvtzsSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZS: Floating-point convert to signed integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZS_sisd_32D
// Template: FCVTZS  <Sd>, <Dn>
struct FcvtzsSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_32H_float2fix
// Template: FCVTZU  <Wd>, <Hn>, #<fbits>
struct Fcvtzu32hFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_64H_float2fix
// Template: FCVTZU  <Xd>, <Hn>, #<fbits>
struct Fcvtzu64hFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_32S_float2fix
// Template: FCVTZU  <Wd>, <Sn>, #<fbits>
struct Fcvtzu32sFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_64S_float2fix
// Template: FCVTZU  <Xd>, <Sn>, #<fbits>
struct Fcvtzu64sFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_32D_float2fix
// Template: FCVTZU  <Wd>, <Dn>, #<fbits>
struct Fcvtzu32dFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned fixed-point, rounding toward zero (scalar)
// Encoding: FCVTZU_64D_float2fix
// Template: FCVTZU  <Xd>, <Dn>, #<fbits>
struct Fcvtzu64dFloat2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_32H_float2int
// Template: FCVTZU  <Wd>, <Hn>
struct Fcvtzu32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_64H_float2int
// Template: FCVTZU  <Xd>, <Hn>
struct Fcvtzu64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_32S_float2int
// Template: FCVTZU  <Wd>, <Sn>
struct Fcvtzu32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_64S_float2int
// Template: FCVTZU  <Xd>, <Sn>
struct Fcvtzu64sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_32D_float2int
// Template: FCVTZU  <Wd>, <Dn>
struct Fcvtzu32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar)
// Encoding: FCVTZU_64D_float2int
// Template: FCVTZU  <Xd>, <Dn>
struct Fcvtzu64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b001 (0x1)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZU_sisd_32H
// Template: FCVTZU  <Sd>, <Hn>
struct FcvtzuSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZU_sisd_64H
// Template: FCVTZU  <Dd>, <Hn>
struct FcvtzuSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZU_sisd_64S
// Template: FCVTZU  <Dd>, <Sn>
struct FcvtzuSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FCVTZU: Floating-point convert to unsigned integer, rounding toward zero (scalar SIMD&FP)
// Encoding: FCVTZU_sisd_32D
// Template: FCVTZU  <Sd>, <Dn>
struct FcvtzuSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FDIV: Floating-point divide (scalar)
// Encoding: FDIV_H_floatdp2
// Template: FDIV  <Hd>, <Hn>, <Hm>
struct FdivHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t opcode : 4;  // fixed: 0b0001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FDIV: Floating-point divide (scalar)
// Encoding: FDIV_S_floatdp2
// Template: FDIV  <Sd>, <Sn>, <Sm>
struct FdivSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t opcode : 4;  // fixed: 0b0001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FDIV: Floating-point divide (scalar)
// Encoding: FDIV_D_floatdp2
// Template: FDIV  <Dd>, <Dn>, <Dm>
struct FdivDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t opcode : 4;  // fixed: 0b0001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FJCVTZS: Floating-point Javascript convert to signed fixed-point, rounding toward zero
// Encoding: FJCVTZS_32D_float2int
// Template: FJCVTZS  <Wd>, <Dn>
struct Fjcvtzs32dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_5 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_4 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_2 : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FMADD: Floating-point fused multiply-add (scalar)
// Encoding: FMADD_H_floatdp3
// Template: FMADD  <Hd>, <Hn>, <Hm>, <Ha>
struct FmaddHFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMADD: Floating-point fused multiply-add (scalar)
// Encoding: FMADD_S_floatdp3
// Template: FMADD  <Sd>, <Sn>, <Sm>, <Sa>
struct FmaddSFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMADD: Floating-point fused multiply-add (scalar)
// Encoding: FMADD_D_floatdp3
// Template: FMADD  <Dd>, <Dn>, <Dm>, <Da>
struct FmaddDFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAX: Floating-point maximum (scalar)
// Encoding: FMAX_H_floatdp2
// Template: FMAX  <Hd>, <Hn>, <Hm>
struct FmaxHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAX: Floating-point maximum (scalar)
// Encoding: FMAX_S_floatdp2
// Template: FMAX  <Sd>, <Sn>, <Sm>
struct FmaxSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAX: Floating-point maximum (scalar)
// Encoding: FMAX_D_floatdp2
// Template: FMAX  <Dd>, <Dn>, <Dm>
struct FmaxDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAXNM: Floating-point maximum number (scalar)
// Encoding: FMAXNM_H_floatdp2
// Template: FMAXNM  <Hd>, <Hn>, <Hm>
struct FmaxnmHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAXNM: Floating-point maximum number (scalar)
// Encoding: FMAXNM_S_floatdp2
// Template: FMAXNM  <Sd>, <Sn>, <Sm>
struct FmaxnmSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMAXNM: Floating-point maximum number (scalar)
// Encoding: FMAXNM_D_floatdp2
// Template: FMAXNM  <Dd>, <Dn>, <Dm>
struct FmaxnmDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMIN: Floating-point minimum (scalar)
// Encoding: FMIN_H_floatdp2
// Template: FMIN  <Hd>, <Hn>, <Hm>
struct FminHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMIN: Floating-point minimum (scalar)
// Encoding: FMIN_S_floatdp2
// Template: FMIN  <Sd>, <Sn>, <Sm>
struct FminSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMIN: Floating-point minimum (scalar)
// Encoding: FMIN_D_floatdp2
// Template: FMIN  <Dd>, <Dn>, <Dm>
struct FminDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMINNM: Floating-point minimum number (scalar)
// Encoding: FMINNM_H_floatdp2
// Template: FMINNM  <Hd>, <Hn>, <Hm>
struct FminnmHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMINNM: Floating-point minimum number (scalar)
// Encoding: FMINNM_S_floatdp2
// Template: FMINNM  <Sd>, <Sn>, <Sm>
struct FminnmSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMINNM: Floating-point minimum number (scalar)
// Encoding: FMINNM_D_floatdp2
// Template: FMINNM  <Dd>, <Dn>, <Dm>
struct FminnmDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move register without conversion
// Encoding: FMOV_H_floatdp1
// Template: FMOV  <Hd>, <Hn>
struct FmovHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move register without conversion
// Encoding: FMOV_S_floatdp1
// Template: FMOV  <Sd>, <Sn>
struct FmovSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move register without conversion
// Encoding: FMOV_D_floatdp1
// Template: FMOV  <Dd>, <Dn>
struct FmovDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_32H_float2int
// Template: FMOV  <Wd>, <Hn>
struct Fmov32hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_64H_float2int
// Template: FMOV  <Xd>, <Hn>
struct Fmov64hFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_H32_float2int
// Template: FMOV  <Hd>, <Wn>
struct FmovH32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_S32_float2int
// Template: FMOV  <Sd>, <Wn>
struct FmovS32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_32S_float2int
// Template: FMOV  <Wd>, <Sn>
struct Fmov32sFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_H64_float2int
// Template: FMOV  <Hd>, <Xn>
struct FmovH64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_D64_float2int
// Template: FMOV  <Dd>, <Xn>
struct FmovD64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_V64I_float2int
// Template: FMOV  <Vd>.D[1], <Xn>
struct FmovV64iFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b111 (0x7)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_64D_float2int
// Template: FMOV  <Xd>, <Dn>
struct Fmov64dFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move to or from general-purpose register without conversion
// Encoding: FMOV_64VX_float2int
// Template: FMOV  <Xd>, <Vn>.D[1]
struct Fmov64vxFloat2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b110 (0x6)
    uint32_t rmode : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// FMOV: Floating-point move immediate (scalar)
// Encoding: FMOV_H_floatimm
// Template: FMOV  <Hd>, #<imm>
struct FmovHFloatimm {
    uint32_t Rd : 5;
    uint32_t imm5 : 5;  // fixed: 0b00000 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t imm8 : 8;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move immediate (scalar)
// Encoding: FMOV_S_floatimm
// Template: FMOV  <Sd>, #<imm>
struct FmovSFloatimm {
    uint32_t Rd : 5;
    uint32_t imm5 : 5;  // fixed: 0b00000 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t imm8 : 8;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMOV: Floating-point move immediate (scalar)
// Encoding: FMOV_D_floatimm
// Template: FMOV  <Dd>, #<imm>
struct FmovDFloatimm {
    uint32_t Rd : 5;
    uint32_t imm5 : 5;  // fixed: 0b00000 (0x0)
    uint32_t _unnamed_3 : 3;  // fixed: 0b100 (0x4)
    uint32_t imm8 : 8;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMSUB: Floating-point fused multiply-subtract (scalar)
// Encoding: FMSUB_H_floatdp3
// Template: FMSUB  <Hd>, <Hn>, <Hm>, <Ha>
struct FmsubHFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMSUB: Floating-point fused multiply-subtract (scalar)
// Encoding: FMSUB_S_floatdp3
// Template: FMSUB  <Sd>, <Sn>, <Sm>, <Sa>
struct FmsubSFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMSUB: Floating-point fused multiply-subtract (scalar)
// Encoding: FMSUB_D_floatdp3
// Template: FMSUB  <Dd>, <Dn>, <Dm>, <Da>
struct FmsubDFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMUL: Floating-point multiply (scalar)
// Encoding: FMUL_H_floatdp2
// Template: FMUL  <Hd>, <Hn>, <Hm>
struct FmulHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMUL: Floating-point multiply (scalar)
// Encoding: FMUL_S_floatdp2
// Template: FMUL  <Sd>, <Sn>, <Sm>
struct FmulSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FMUL: Floating-point multiply (scalar)
// Encoding: FMUL_D_floatdp2
// Template: FMUL  <Dd>, <Dn>, <Dm>
struct FmulDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNEG: Floating-point negate (scalar)
// Encoding: FNEG_H_floatdp1
// Template: FNEG  <Hd>, <Hn>
struct FnegHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNEG: Floating-point negate (scalar)
// Encoding: FNEG_S_floatdp1
// Template: FNEG  <Sd>, <Sn>
struct FnegSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNEG: Floating-point negate (scalar)
// Encoding: FNEG_D_floatdp1
// Template: FNEG  <Dd>, <Dn>
struct FnegDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMADD: Floating-point negated fused multiply-add (scalar)
// Encoding: FNMADD_H_floatdp3
// Template: FNMADD  <Hd>, <Hn>, <Hm>, <Ha>
struct FnmaddHFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMADD: Floating-point negated fused multiply-add (scalar)
// Encoding: FNMADD_S_floatdp3
// Template: FNMADD  <Sd>, <Sn>, <Sm>, <Sa>
struct FnmaddSFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMADD: Floating-point negated fused multiply-add (scalar)
// Encoding: FNMADD_D_floatdp3
// Template: FNMADD  <Dd>, <Dn>, <Dm>, <Da>
struct FnmaddDFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b0 (0x0)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMSUB: Floating-point negated fused multiply-subtract (scalar)
// Encoding: FNMSUB_H_floatdp3
// Template: FNMSUB  <Hd>, <Hn>, <Hm>, <Ha>
struct FnmsubHFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMSUB: Floating-point negated fused multiply-subtract (scalar)
// Encoding: FNMSUB_S_floatdp3
// Template: FNMSUB  <Sd>, <Sn>, <Sm>, <Sa>
struct FnmsubSFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMSUB: Floating-point negated fused multiply-subtract (scalar)
// Encoding: FNMSUB_D_floatdp3
// Template: FNMSUB  <Dd>, <Dn>, <Dm>, <Da>
struct FnmsubDFloatdp3 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t Ra : 5;
    uint32_t o0 : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t o1 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMUL: Floating-point multiply-negate (scalar)
// Encoding: FNMUL_H_floatdp2
// Template: FNMUL  <Hd>, <Hn>, <Hm>
struct FnmulHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMUL: Floating-point multiply-negate (scalar)
// Encoding: FNMUL_S_floatdp2
// Template: FNMUL  <Sd>, <Sn>, <Sm>
struct FnmulSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FNMUL: Floating-point multiply-negate (scalar)
// Encoding: FNMUL_D_floatdp2
// Template: FNMUL  <Dd>, <Dn>, <Dm>
struct FnmulDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b00010 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT32X: Floating-point round to 32-bit integer, using current rounding mode (scalar)
// Encoding: FRINT32X_S_floatdp1
// Template: FRINT32X  <Sd>, <Sn>
struct Frint32xSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT32X: Floating-point round to 32-bit integer, using current rounding mode (scalar)
// Encoding: FRINT32X_D_floatdp1
// Template: FRINT32X  <Dd>, <Dn>
struct Frint32xDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT32Z: Floating-point round to 32-bit integer toward zero (scalar)
// Encoding: FRINT32Z_S_floatdp1
// Template: FRINT32Z  <Sd>, <Sn>
struct Frint32zSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT32Z: Floating-point round to 32-bit integer toward zero (scalar)
// Encoding: FRINT32Z_D_floatdp1
// Template: FRINT32Z  <Dd>, <Dn>
struct Frint32zDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT64X: Floating-point round to 64-bit integer, using current rounding mode (scalar)
// Encoding: FRINT64X_S_floatdp1
// Template: FRINT64X  <Sd>, <Sn>
struct Frint64xSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT64X: Floating-point round to 64-bit integer, using current rounding mode (scalar)
// Encoding: FRINT64X_D_floatdp1
// Template: FRINT64X  <Dd>, <Dn>
struct Frint64xDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT64Z: Floating-point round to 64-bit integer toward zero (scalar)
// Encoding: FRINT64Z_S_floatdp1
// Template: FRINT64Z  <Sd>, <Sn>
struct Frint64zSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINT64Z: Floating-point round to 64-bit integer toward zero (scalar)
// Encoding: FRINT64Z_D_floatdp1
// Template: FRINT64Z  <Dd>, <Dn>
struct Frint64zDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t op : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10100 (0x14)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTA: Floating-point round to integral, to nearest with ties to away (scalar)
// Encoding: FRINTA_H_floatdp1
// Template: FRINTA  <Hd>, <Hn>
struct FrintaHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTA: Floating-point round to integral, to nearest with ties to away (scalar)
// Encoding: FRINTA_S_floatdp1
// Template: FRINTA  <Sd>, <Sn>
struct FrintaSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTA: Floating-point round to integral, to nearest with ties to away (scalar)
// Encoding: FRINTA_D_floatdp1
// Template: FRINTA  <Dd>, <Dn>
struct FrintaDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b100 (0x4)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTI: Floating-point round to integral, using current rounding mode (scalar)
// Encoding: FRINTI_H_floatdp1
// Template: FRINTI  <Hd>, <Hn>
struct FrintiHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTI: Floating-point round to integral, using current rounding mode (scalar)
// Encoding: FRINTI_S_floatdp1
// Template: FRINTI  <Sd>, <Sn>
struct FrintiSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTI: Floating-point round to integral, using current rounding mode (scalar)
// Encoding: FRINTI_D_floatdp1
// Template: FRINTI  <Dd>, <Dn>
struct FrintiDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b111 (0x7)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTM: Floating-point round to integral, toward minus infinity (scalar)
// Encoding: FRINTM_H_floatdp1
// Template: FRINTM  <Hd>, <Hn>
struct FrintmHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b010 (0x2)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTM: Floating-point round to integral, toward minus infinity (scalar)
// Encoding: FRINTM_S_floatdp1
// Template: FRINTM  <Sd>, <Sn>
struct FrintmSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b010 (0x2)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTM: Floating-point round to integral, toward minus infinity (scalar)
// Encoding: FRINTM_D_floatdp1
// Template: FRINTM  <Dd>, <Dn>
struct FrintmDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b010 (0x2)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTN: Floating-point round to integral, to nearest with ties to even (scalar)
// Encoding: FRINTN_H_floatdp1
// Template: FRINTN  <Hd>, <Hn>
struct FrintnHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTN: Floating-point round to integral, to nearest with ties to even (scalar)
// Encoding: FRINTN_S_floatdp1
// Template: FRINTN  <Sd>, <Sn>
struct FrintnSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTN: Floating-point round to integral, to nearest with ties to even (scalar)
// Encoding: FRINTN_D_floatdp1
// Template: FRINTN  <Dd>, <Dn>
struct FrintnDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTP: Floating-point round to integral, toward plus infinity (scalar)
// Encoding: FRINTP_H_floatdp1
// Template: FRINTP  <Hd>, <Hn>
struct FrintpHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b001 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTP: Floating-point round to integral, toward plus infinity (scalar)
// Encoding: FRINTP_S_floatdp1
// Template: FRINTP  <Sd>, <Sn>
struct FrintpSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b001 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTP: Floating-point round to integral, toward plus infinity (scalar)
// Encoding: FRINTP_D_floatdp1
// Template: FRINTP  <Dd>, <Dn>
struct FrintpDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b001 (0x1)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTX: Floating-point round to integral exact, using current rounding mode (scalar)
// Encoding: FRINTX_H_floatdp1
// Template: FRINTX  <Hd>, <Hn>
struct FrintxHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b110 (0x6)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTX: Floating-point round to integral exact, using current rounding mode (scalar)
// Encoding: FRINTX_S_floatdp1
// Template: FRINTX  <Sd>, <Sn>
struct FrintxSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b110 (0x6)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTX: Floating-point round to integral exact, using current rounding mode (scalar)
// Encoding: FRINTX_D_floatdp1
// Template: FRINTX  <Dd>, <Dn>
struct FrintxDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b110 (0x6)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTZ: Floating-point round to integral, toward zero (scalar)
// Encoding: FRINTZ_H_floatdp1
// Template: FRINTZ  <Hd>, <Hn>
struct FrintzHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b011 (0x3)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTZ: Floating-point round to integral, toward zero (scalar)
// Encoding: FRINTZ_S_floatdp1
// Template: FRINTZ  <Sd>, <Sn>
struct FrintzSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b011 (0x3)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FRINTZ: Floating-point round to integral, toward zero (scalar)
// Encoding: FRINTZ_D_floatdp1
// Template: FRINTZ  <Dd>, <Dn>
struct FrintzDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t rmode : 3;  // fixed: 0b011 (0x3)
    uint32_t _unnamed_2 : 4;  // fixed: 0b1001 (0x9)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSQRT: Floating-point square root (scalar)
// Encoding: FSQRT_H_floatdp1
// Template: FSQRT  <Hd>, <Hn>
struct FsqrtHFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSQRT: Floating-point square root (scalar)
// Encoding: FSQRT_S_floatdp1
// Template: FSQRT  <Sd>, <Sn>
struct FsqrtSFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSQRT: Floating-point square root (scalar)
// Encoding: FSQRT_D_floatdp1
// Template: FSQRT  <Dd>, <Dn>
struct FsqrtDFloatdp1 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 5;  // fixed: 0b10000 (0x10)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 5;  // fixed: 0b10000 (0x10)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSUB: Floating-point subtract (scalar)
// Encoding: FSUB_H_floatdp2
// Template: FSUB  <Hd>, <Hn>, <Hm>
struct FsubHFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSUB: Floating-point subtract (scalar)
// Encoding: FSUB_S_floatdp2
// Template: FSUB  <Sd>, <Sn>, <Sm>
struct FsubSFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// FSUB: Floating-point subtract (scalar)
// Encoding: FSUB_D_floatdp2
// Template: FSUB  <Dd>, <Dn>, <Dm>
struct FsubDFloatdp2 {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_4 : 2;  // fixed: 0b10 (0x2)
    uint32_t op : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 3;  // fixed: 0b001 (0x1)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t M : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_H32_float2fix
// Template: SCVTF  <Hd>, <Wn>, #<fbits>
struct ScvtfH32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_H64_float2fix
// Template: SCVTF  <Hd>, <Xn>, #<fbits>
struct ScvtfH64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_S32_float2fix
// Template: SCVTF  <Sd>, <Wn>, #<fbits>
struct ScvtfS32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_S64_float2fix
// Template: SCVTF  <Sd>, <Xn>, #<fbits>
struct ScvtfS64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_D32_float2fix
// Template: SCVTF  <Dd>, <Wn>, #<fbits>
struct ScvtfD32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed fixed-point convert to floating-point (scalar)
// Encoding: SCVTF_D64_float2fix
// Template: SCVTF  <Dd>, <Xn>, #<fbits>
struct ScvtfD64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_H32_float2int
// Template: SCVTF  <Hd>, <Wn>
struct ScvtfH32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_S32_float2int
// Template: SCVTF  <Sd>, <Wn>
struct ScvtfS32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_D32_float2int
// Template: SCVTF  <Dd>, <Wn>
struct ScvtfD32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_H64_float2int
// Template: SCVTF  <Hd>, <Xn>
struct ScvtfH64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_S64_float2int
// Template: SCVTF  <Sd>, <Xn>
struct ScvtfS64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed integer convert to floating-point (scalar)
// Encoding: SCVTF_D64_float2int
// Template: SCVTF  <Dd>, <Xn>
struct ScvtfD64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b010 (0x2)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed integer convert to floating-point (scalar SIMD&FP)
// Encoding: SCVTF_sisd_32H
// Template: SCVTF  <Hd>, <Sn>
struct ScvtfSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed integer convert to floating-point (scalar SIMD&FP)
// Encoding: SCVTF_sisd_32D
// Template: SCVTF  <Dd>, <Sn>
struct ScvtfSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// SCVTF: Signed integer convert to floating-point (scalar SIMD&FP)
// Encoding: SCVTF_sisd_64H
// Template: SCVTF  <Hd>, <Dn>
struct ScvtfSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// SCVTF: Signed integer convert to floating-point (scalar SIMD&FP)
// Encoding: SCVTF_sisd_64S
// Template: SCVTF  <Sd>, <Dn>
struct ScvtfSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b100 (0x4)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_H32_float2fix
// Template: UCVTF  <Hd>, <Wn>, #<fbits>
struct UcvtfH32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_H64_float2fix
// Template: UCVTF  <Hd>, <Xn>, #<fbits>
struct UcvtfH64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_S32_float2fix
// Template: UCVTF  <Sd>, <Wn>, #<fbits>
struct UcvtfS32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_S64_float2fix
// Template: UCVTF  <Sd>, <Xn>, #<fbits>
struct UcvtfS64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_D32_float2fix
// Template: UCVTF  <Dd>, <Wn>, #<fbits>
struct UcvtfD32Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned fixed-point convert to floating-point (scalar)
// Encoding: UCVTF_D64_float2fix
// Template: UCVTF  <Dd>, <Xn>, #<fbits>
struct UcvtfD64Float2fix {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t scale : 6;
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_H32_float2int
// Template: UCVTF  <Hd>, <Wn>
struct UcvtfH32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_S32_float2int
// Template: UCVTF  <Sd>, <Wn>
struct UcvtfS32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_D32_float2int
// Template: UCVTF  <Dd>, <Wn>
struct UcvtfD32Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_H64_float2int
// Template: UCVTF  <Hd>, <Xn>
struct UcvtfH64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_S64_float2int
// Template: UCVTF  <Sd>, <Xn>
struct UcvtfS64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned integer convert to floating-point (scalar)
// Encoding: UCVTF_D64_float2int
// Template: UCVTF  <Dd>, <Xn>
struct UcvtfD64Float2int {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b011 (0x3)
    uint32_t rmode : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned integer convert to floating-point (scalar SIMD&FP)
// Encoding: UCVTF_sisd_32H
// Template: UCVTF  <Hd>, <Sn>
struct UcvtfSisd32h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned integer convert to floating-point (scalar SIMD&FP)
// Encoding: UCVTF_sisd_32D
// Template: UCVTF  <Dd>, <Sn>
struct UcvtfSisd32d {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b0 (0x0)
};


// UCVTF: Unsigned integer convert to floating-point (scalar SIMD&FP)
// Encoding: UCVTF_sisd_64H
// Template: UCVTF  <Hd>, <Dn>
struct UcvtfSisd64h {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// UCVTF: Unsigned integer convert to floating-point (scalar SIMD&FP)
// Encoding: UCVTF_sisd_64S
// Template: UCVTF  <Sd>, <Dn>
struct UcvtfSisd64s {
    uint32_t Rd : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 6;  // fixed: 0b000000 (0x0)
    uint32_t opcode : 3;  // fixed: 0b101 (0x5)
    uint32_t rmode : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t ftype : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 5;  // fixed: 0b11110 (0x1E)
    uint32_t S : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_0 : 1;  // fixed: 0b0 (0x0)
    uint32_t sf : 1;  // fixed: 0b1 (0x1)
};


// Union for float instruction class
union FloatEncoding {
    BfcvtBsFloatdp1 bfcvt_bs_floatdp1;
    FabsHFloatdp1 fabs_hfloatdp1;
    FabsSFloatdp1 fabs_sfloatdp1;
    FabsDFloatdp1 fabs_dfloatdp1;
    FaddHFloatdp2 fadd_hfloatdp2;
    FaddSFloatdp2 fadd_sfloatdp2;
    FaddDFloatdp2 fadd_dfloatdp2;
    FccmpHFloatccmp fccmp_hfloatccmp;
    FccmpSFloatccmp fccmp_sfloatccmp;
    FccmpDFloatccmp fccmp_dfloatccmp;
    FccmpeHFloatccmp fccmpe_hfloatccmp;
    FccmpeSFloatccmp fccmpe_sfloatccmp;
    FccmpeDFloatccmp fccmpe_dfloatccmp;
    FcmpHFloatcmp fcmp_hfloatcmp;
    FcmpHzFloatcmp fcmp_hz_floatcmp;
    FcmpSFloatcmp fcmp_sfloatcmp;
    FcmpSzFloatcmp fcmp_sz_floatcmp;
    FcmpDFloatcmp fcmp_dfloatcmp;
    FcmpDzFloatcmp fcmp_dz_floatcmp;
    FcmpeHFloatcmp fcmpe_hfloatcmp;
    FcmpeHzFloatcmp fcmpe_hz_floatcmp;
    FcmpeSFloatcmp fcmpe_sfloatcmp;
    FcmpeSzFloatcmp fcmpe_sz_floatcmp;
    FcmpeDFloatcmp fcmpe_dfloatcmp;
    FcmpeDzFloatcmp fcmpe_dz_floatcmp;
    FcselHFloatsel fcsel_hfloatsel;
    FcselSFloatsel fcsel_sfloatsel;
    FcselDFloatsel fcsel_dfloatsel;
    FcvtShFloatdp1 fcvt_sh_floatdp1;
    FcvtDhFloatdp1 fcvt_dh_floatdp1;
    FcvtHsFloatdp1 fcvt_hs_floatdp1;
    FcvtDsFloatdp1 fcvt_ds_floatdp1;
    FcvtHdFloatdp1 fcvt_hd_floatdp1;
    FcvtSdFloatdp1 fcvt_sd_floatdp1;
    Fcvtas32hFloat2int fcvtas32h_float2int;
    Fcvtas64hFloat2int fcvtas64h_float2int;
    Fcvtas32sFloat2int fcvtas32s_float2int;
    Fcvtas64sFloat2int fcvtas64s_float2int;
    Fcvtas32dFloat2int fcvtas32d_float2int;
    Fcvtas64dFloat2int fcvtas64d_float2int;
    FcvtasSisd32h fcvtas_sisd32h;
    FcvtasSisd64h fcvtas_sisd64h;
    FcvtasSisd64s fcvtas_sisd64s;
    FcvtasSisd32d fcvtas_sisd32d;
    Fcvtau32hFloat2int fcvtau32h_float2int;
    Fcvtau64hFloat2int fcvtau64h_float2int;
    Fcvtau32sFloat2int fcvtau32s_float2int;
    Fcvtau64sFloat2int fcvtau64s_float2int;
    Fcvtau32dFloat2int fcvtau32d_float2int;
    Fcvtau64dFloat2int fcvtau64d_float2int;
    FcvtauSisd32h fcvtau_sisd32h;
    FcvtauSisd64h fcvtau_sisd64h;
    FcvtauSisd64s fcvtau_sisd64s;
    FcvtauSisd32d fcvtau_sisd32d;
    Fcvtms32hFloat2int fcvtms32h_float2int;
    Fcvtms64hFloat2int fcvtms64h_float2int;
    Fcvtms32sFloat2int fcvtms32s_float2int;
    Fcvtms64sFloat2int fcvtms64s_float2int;
    Fcvtms32dFloat2int fcvtms32d_float2int;
    Fcvtms64dFloat2int fcvtms64d_float2int;
    FcvtmsSisd32h fcvtms_sisd32h;
    FcvtmsSisd64h fcvtms_sisd64h;
    FcvtmsSisd64s fcvtms_sisd64s;
    FcvtmsSisd32d fcvtms_sisd32d;
    Fcvtmu32hFloat2int fcvtmu32h_float2int;
    Fcvtmu64hFloat2int fcvtmu64h_float2int;
    Fcvtmu32sFloat2int fcvtmu32s_float2int;
    Fcvtmu64sFloat2int fcvtmu64s_float2int;
    Fcvtmu32dFloat2int fcvtmu32d_float2int;
    Fcvtmu64dFloat2int fcvtmu64d_float2int;
    FcvtmuSisd32h fcvtmu_sisd32h;
    FcvtmuSisd64h fcvtmu_sisd64h;
    FcvtmuSisd64s fcvtmu_sisd64s;
    FcvtmuSisd32d fcvtmu_sisd32d;
    Fcvtns32hFloat2int fcvtns32h_float2int;
    Fcvtns64hFloat2int fcvtns64h_float2int;
    Fcvtns32sFloat2int fcvtns32s_float2int;
    Fcvtns64sFloat2int fcvtns64s_float2int;
    Fcvtns32dFloat2int fcvtns32d_float2int;
    Fcvtns64dFloat2int fcvtns64d_float2int;
    FcvtnsSisd32h fcvtns_sisd32h;
    FcvtnsSisd64h fcvtns_sisd64h;
    FcvtnsSisd64s fcvtns_sisd64s;
    FcvtnsSisd32d fcvtns_sisd32d;
    Fcvtnu32hFloat2int fcvtnu32h_float2int;
    Fcvtnu64hFloat2int fcvtnu64h_float2int;
    Fcvtnu32sFloat2int fcvtnu32s_float2int;
    Fcvtnu64sFloat2int fcvtnu64s_float2int;
    Fcvtnu32dFloat2int fcvtnu32d_float2int;
    Fcvtnu64dFloat2int fcvtnu64d_float2int;
    FcvtnuSisd32h fcvtnu_sisd32h;
    FcvtnuSisd64h fcvtnu_sisd64h;
    FcvtnuSisd64s fcvtnu_sisd64s;
    FcvtnuSisd32d fcvtnu_sisd32d;
    Fcvtps32hFloat2int fcvtps32h_float2int;
    Fcvtps64hFloat2int fcvtps64h_float2int;
    Fcvtps32sFloat2int fcvtps32s_float2int;
    Fcvtps64sFloat2int fcvtps64s_float2int;
    Fcvtps32dFloat2int fcvtps32d_float2int;
    Fcvtps64dFloat2int fcvtps64d_float2int;
    FcvtpsSisd32h fcvtps_sisd32h;
    FcvtpsSisd64h fcvtps_sisd64h;
    FcvtpsSisd64s fcvtps_sisd64s;
    FcvtpsSisd32d fcvtps_sisd32d;
    Fcvtpu32hFloat2int fcvtpu32h_float2int;
    Fcvtpu64hFloat2int fcvtpu64h_float2int;
    Fcvtpu32sFloat2int fcvtpu32s_float2int;
    Fcvtpu64sFloat2int fcvtpu64s_float2int;
    Fcvtpu32dFloat2int fcvtpu32d_float2int;
    Fcvtpu64dFloat2int fcvtpu64d_float2int;
    FcvtpuSisd32h fcvtpu_sisd32h;
    FcvtpuSisd64h fcvtpu_sisd64h;
    FcvtpuSisd64s fcvtpu_sisd64s;
    FcvtpuSisd32d fcvtpu_sisd32d;
    Fcvtzs32hFloat2fix fcvtzs32h_float2fix;
    Fcvtzs64hFloat2fix fcvtzs64h_float2fix;
    Fcvtzs32sFloat2fix fcvtzs32s_float2fix;
    Fcvtzs64sFloat2fix fcvtzs64s_float2fix;
    Fcvtzs32dFloat2fix fcvtzs32d_float2fix;
    Fcvtzs64dFloat2fix fcvtzs64d_float2fix;
    Fcvtzs32hFloat2int fcvtzs32h_float2int;
    Fcvtzs64hFloat2int fcvtzs64h_float2int;
    Fcvtzs32sFloat2int fcvtzs32s_float2int;
    Fcvtzs64sFloat2int fcvtzs64s_float2int;
    Fcvtzs32dFloat2int fcvtzs32d_float2int;
    Fcvtzs64dFloat2int fcvtzs64d_float2int;
    FcvtzsSisd32h fcvtzs_sisd32h;
    FcvtzsSisd64h fcvtzs_sisd64h;
    FcvtzsSisd64s fcvtzs_sisd64s;
    FcvtzsSisd32d fcvtzs_sisd32d;
    Fcvtzu32hFloat2fix fcvtzu32h_float2fix;
    Fcvtzu64hFloat2fix fcvtzu64h_float2fix;
    Fcvtzu32sFloat2fix fcvtzu32s_float2fix;
    Fcvtzu64sFloat2fix fcvtzu64s_float2fix;
    Fcvtzu32dFloat2fix fcvtzu32d_float2fix;
    Fcvtzu64dFloat2fix fcvtzu64d_float2fix;
    Fcvtzu32hFloat2int fcvtzu32h_float2int;
    Fcvtzu64hFloat2int fcvtzu64h_float2int;
    Fcvtzu32sFloat2int fcvtzu32s_float2int;
    Fcvtzu64sFloat2int fcvtzu64s_float2int;
    Fcvtzu32dFloat2int fcvtzu32d_float2int;
    Fcvtzu64dFloat2int fcvtzu64d_float2int;
    FcvtzuSisd32h fcvtzu_sisd32h;
    FcvtzuSisd64h fcvtzu_sisd64h;
    FcvtzuSisd64s fcvtzu_sisd64s;
    FcvtzuSisd32d fcvtzu_sisd32d;
    FdivHFloatdp2 fdiv_hfloatdp2;
    FdivSFloatdp2 fdiv_sfloatdp2;
    FdivDFloatdp2 fdiv_dfloatdp2;
    Fjcvtzs32dFloat2int fjcvtzs32d_float2int;
    FmaddHFloatdp3 fmadd_hfloatdp3;
    FmaddSFloatdp3 fmadd_sfloatdp3;
    FmaddDFloatdp3 fmadd_dfloatdp3;
    FmaxHFloatdp2 fmax_hfloatdp2;
    FmaxSFloatdp2 fmax_sfloatdp2;
    FmaxDFloatdp2 fmax_dfloatdp2;
    FmaxnmHFloatdp2 fmaxnm_hfloatdp2;
    FmaxnmSFloatdp2 fmaxnm_sfloatdp2;
    FmaxnmDFloatdp2 fmaxnm_dfloatdp2;
    FminHFloatdp2 fmin_hfloatdp2;
    FminSFloatdp2 fmin_sfloatdp2;
    FminDFloatdp2 fmin_dfloatdp2;
    FminnmHFloatdp2 fminnm_hfloatdp2;
    FminnmSFloatdp2 fminnm_sfloatdp2;
    FminnmDFloatdp2 fminnm_dfloatdp2;
    FmovHFloatdp1 fmov_hfloatdp1;
    FmovSFloatdp1 fmov_sfloatdp1;
    FmovDFloatdp1 fmov_dfloatdp1;
    Fmov32hFloat2int fmov32h_float2int;
    Fmov64hFloat2int fmov64h_float2int;
    FmovH32Float2int fmov_h32float2int;
    FmovS32Float2int fmov_s32float2int;
    Fmov32sFloat2int fmov32s_float2int;
    FmovH64Float2int fmov_h64float2int;
    FmovD64Float2int fmov_d64float2int;
    FmovV64iFloat2int fmov_v64i_float2int;
    Fmov64dFloat2int fmov64d_float2int;
    Fmov64vxFloat2int fmov64vx_float2int;
    FmovHFloatimm fmov_hfloatimm;
    FmovSFloatimm fmov_sfloatimm;
    FmovDFloatimm fmov_dfloatimm;
    FmsubHFloatdp3 fmsub_hfloatdp3;
    FmsubSFloatdp3 fmsub_sfloatdp3;
    FmsubDFloatdp3 fmsub_dfloatdp3;
    FmulHFloatdp2 fmul_hfloatdp2;
    FmulSFloatdp2 fmul_sfloatdp2;
    FmulDFloatdp2 fmul_dfloatdp2;
    FnegHFloatdp1 fneg_hfloatdp1;
    FnegSFloatdp1 fneg_sfloatdp1;
    FnegDFloatdp1 fneg_dfloatdp1;
    FnmaddHFloatdp3 fnmadd_hfloatdp3;
    FnmaddSFloatdp3 fnmadd_sfloatdp3;
    FnmaddDFloatdp3 fnmadd_dfloatdp3;
    FnmsubHFloatdp3 fnmsub_hfloatdp3;
    FnmsubSFloatdp3 fnmsub_sfloatdp3;
    FnmsubDFloatdp3 fnmsub_dfloatdp3;
    FnmulHFloatdp2 fnmul_hfloatdp2;
    FnmulSFloatdp2 fnmul_sfloatdp2;
    FnmulDFloatdp2 fnmul_dfloatdp2;
    Frint32xSFloatdp1 frint32x_sfloatdp1;
    Frint32xDFloatdp1 frint32x_dfloatdp1;
    Frint32zSFloatdp1 frint32z_sfloatdp1;
    Frint32zDFloatdp1 frint32z_dfloatdp1;
    Frint64xSFloatdp1 frint64x_sfloatdp1;
    Frint64xDFloatdp1 frint64x_dfloatdp1;
    Frint64zSFloatdp1 frint64z_sfloatdp1;
    Frint64zDFloatdp1 frint64z_dfloatdp1;
    FrintaHFloatdp1 frinta_hfloatdp1;
    FrintaSFloatdp1 frinta_sfloatdp1;
    FrintaDFloatdp1 frinta_dfloatdp1;
    FrintiHFloatdp1 frinti_hfloatdp1;
    FrintiSFloatdp1 frinti_sfloatdp1;
    FrintiDFloatdp1 frinti_dfloatdp1;
    FrintmHFloatdp1 frintm_hfloatdp1;
    FrintmSFloatdp1 frintm_sfloatdp1;
    FrintmDFloatdp1 frintm_dfloatdp1;
    FrintnHFloatdp1 frintn_hfloatdp1;
    FrintnSFloatdp1 frintn_sfloatdp1;
    FrintnDFloatdp1 frintn_dfloatdp1;
    FrintpHFloatdp1 frintp_hfloatdp1;
    FrintpSFloatdp1 frintp_sfloatdp1;
    FrintpDFloatdp1 frintp_dfloatdp1;
    FrintxHFloatdp1 frintx_hfloatdp1;
    FrintxSFloatdp1 frintx_sfloatdp1;
    FrintxDFloatdp1 frintx_dfloatdp1;
    FrintzHFloatdp1 frintz_hfloatdp1;
    FrintzSFloatdp1 frintz_sfloatdp1;
    FrintzDFloatdp1 frintz_dfloatdp1;
    FsqrtHFloatdp1 fsqrt_hfloatdp1;
    FsqrtSFloatdp1 fsqrt_sfloatdp1;
    FsqrtDFloatdp1 fsqrt_dfloatdp1;
    FsubHFloatdp2 fsub_hfloatdp2;
    FsubSFloatdp2 fsub_sfloatdp2;
    FsubDFloatdp2 fsub_dfloatdp2;
    ScvtfH32Float2fix scvtf_h32float2fix;
    ScvtfH64Float2fix scvtf_h64float2fix;
    ScvtfS32Float2fix scvtf_s32float2fix;
    ScvtfS64Float2fix scvtf_s64float2fix;
    ScvtfD32Float2fix scvtf_d32float2fix;
    ScvtfD64Float2fix scvtf_d64float2fix;
    ScvtfH32Float2int scvtf_h32float2int;
    ScvtfS32Float2int scvtf_s32float2int;
    ScvtfD32Float2int scvtf_d32float2int;
    ScvtfH64Float2int scvtf_h64float2int;
    ScvtfS64Float2int scvtf_s64float2int;
    ScvtfD64Float2int scvtf_d64float2int;
    ScvtfSisd32h scvtf_sisd32h;
    ScvtfSisd32d scvtf_sisd32d;
    ScvtfSisd64h scvtf_sisd64h;
    ScvtfSisd64s scvtf_sisd64s;
    UcvtfH32Float2fix ucvtf_h32float2fix;
    UcvtfH64Float2fix ucvtf_h64float2fix;
    UcvtfS32Float2fix ucvtf_s32float2fix;
    UcvtfS64Float2fix ucvtf_s64float2fix;
    UcvtfD32Float2fix ucvtf_d32float2fix;
    UcvtfD64Float2fix ucvtf_d64float2fix;
    UcvtfH32Float2int ucvtf_h32float2int;
    UcvtfS32Float2int ucvtf_s32float2int;
    UcvtfD32Float2int ucvtf_d32float2int;
    UcvtfH64Float2int ucvtf_h64float2int;
    UcvtfS64Float2int ucvtf_s64float2int;
    UcvtfD64Float2int ucvtf_d64float2int;
    UcvtfSisd32h ucvtf_sisd32h;
    UcvtfSisd32d ucvtf_sisd32d;
    UcvtfSisd64h ucvtf_sisd64h;
    UcvtfSisd64s ucvtf_sisd64s;
    uint32_t raw;
};
static_assert(sizeof(FloatEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_bfcvt_bs_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.bfcvt_bs_floatdp1.Rd = Rd;
    insn.bfcvt_bs_floatdp1.Rn = Rn;
    insn.bfcvt_bs_floatdp1._unnamed_5 = 0b10000;
    insn.bfcvt_bs_floatdp1.opcode = 0b000110;
    insn.bfcvt_bs_floatdp1._unnamed_4 = 0b1;
    insn.bfcvt_bs_floatdp1.ftype = 0b01;
    insn.bfcvt_bs_floatdp1._unnamed_3 = 0b0;
    insn.bfcvt_bs_floatdp1._unnamed_2 = 0b111;
    insn.bfcvt_bs_floatdp1._unnamed_1 = 0b1;
    insn.bfcvt_bs_floatdp1.S = 0b0;
    insn.bfcvt_bs_floatdp1._unnamed_0 = 0b0;
    insn.bfcvt_bs_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fabs_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fabs_hfloatdp1.Rd = Rd;
    insn.fabs_hfloatdp1.Rn = Rn;
    insn.fabs_hfloatdp1._unnamed_3 = 0b10000;
    insn.fabs_hfloatdp1.opc = 0b01;
    insn.fabs_hfloatdp1._unnamed_2 = 0b10000;
    insn.fabs_hfloatdp1.ftype = 0b11;
    insn.fabs_hfloatdp1._unnamed_1 = 0b11110;
    insn.fabs_hfloatdp1.S = 0b0;
    insn.fabs_hfloatdp1._unnamed_0 = 0b0;
    insn.fabs_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fabs_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fabs_sfloatdp1.Rd = Rd;
    insn.fabs_sfloatdp1.Rn = Rn;
    insn.fabs_sfloatdp1._unnamed_3 = 0b10000;
    insn.fabs_sfloatdp1.opc = 0b01;
    insn.fabs_sfloatdp1._unnamed_2 = 0b10000;
    insn.fabs_sfloatdp1.ftype = 0b00;
    insn.fabs_sfloatdp1._unnamed_1 = 0b11110;
    insn.fabs_sfloatdp1.S = 0b0;
    insn.fabs_sfloatdp1._unnamed_0 = 0b0;
    insn.fabs_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fabs_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fabs_dfloatdp1.Rd = Rd;
    insn.fabs_dfloatdp1.Rn = Rn;
    insn.fabs_dfloatdp1._unnamed_3 = 0b10000;
    insn.fabs_dfloatdp1.opc = 0b01;
    insn.fabs_dfloatdp1._unnamed_2 = 0b10000;
    insn.fabs_dfloatdp1.ftype = 0b01;
    insn.fabs_dfloatdp1._unnamed_1 = 0b11110;
    insn.fabs_dfloatdp1.S = 0b0;
    insn.fabs_dfloatdp1._unnamed_0 = 0b0;
    insn.fabs_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fadd_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fadd_hfloatdp2.Rd = Rd;
    insn.fadd_hfloatdp2.Rn = Rn;
    insn.fadd_hfloatdp2._unnamed_4 = 0b10;
    insn.fadd_hfloatdp2.op = 0b0;
    insn.fadd_hfloatdp2._unnamed_3 = 0b001;
    insn.fadd_hfloatdp2.Rm = Rm;
    insn.fadd_hfloatdp2._unnamed_2 = 0b1;
    insn.fadd_hfloatdp2.ftype = 0b11;
    insn.fadd_hfloatdp2._unnamed_1 = 0b11110;
    insn.fadd_hfloatdp2.S = 0b0;
    insn.fadd_hfloatdp2._unnamed_0 = 0b0;
    insn.fadd_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fadd_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fadd_sfloatdp2.Rd = Rd;
    insn.fadd_sfloatdp2.Rn = Rn;
    insn.fadd_sfloatdp2._unnamed_4 = 0b10;
    insn.fadd_sfloatdp2.op = 0b0;
    insn.fadd_sfloatdp2._unnamed_3 = 0b001;
    insn.fadd_sfloatdp2.Rm = Rm;
    insn.fadd_sfloatdp2._unnamed_2 = 0b1;
    insn.fadd_sfloatdp2.ftype = 0b00;
    insn.fadd_sfloatdp2._unnamed_1 = 0b11110;
    insn.fadd_sfloatdp2.S = 0b0;
    insn.fadd_sfloatdp2._unnamed_0 = 0b0;
    insn.fadd_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fadd_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fadd_dfloatdp2.Rd = Rd;
    insn.fadd_dfloatdp2.Rn = Rn;
    insn.fadd_dfloatdp2._unnamed_4 = 0b10;
    insn.fadd_dfloatdp2.op = 0b0;
    insn.fadd_dfloatdp2._unnamed_3 = 0b001;
    insn.fadd_dfloatdp2.Rm = Rm;
    insn.fadd_dfloatdp2._unnamed_2 = 0b1;
    insn.fadd_dfloatdp2.ftype = 0b01;
    insn.fadd_dfloatdp2._unnamed_1 = 0b11110;
    insn.fadd_dfloatdp2.S = 0b0;
    insn.fadd_dfloatdp2._unnamed_0 = 0b0;
    insn.fadd_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmp_h_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmp_hfloatccmp.nzcv = nzcv;
    insn.fccmp_hfloatccmp.op = 0b0;
    insn.fccmp_hfloatccmp.Rn = Rn;
    insn.fccmp_hfloatccmp._unnamed_3 = 0b01;
    insn.fccmp_hfloatccmp.cond = cond;
    insn.fccmp_hfloatccmp.Rm = Rm;
    insn.fccmp_hfloatccmp._unnamed_2 = 0b1;
    insn.fccmp_hfloatccmp.ftype = 0b11;
    insn.fccmp_hfloatccmp._unnamed_1 = 0b11110;
    insn.fccmp_hfloatccmp.S = 0b0;
    insn.fccmp_hfloatccmp._unnamed_0 = 0b0;
    insn.fccmp_hfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmp_s_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmp_sfloatccmp.nzcv = nzcv;
    insn.fccmp_sfloatccmp.op = 0b0;
    insn.fccmp_sfloatccmp.Rn = Rn;
    insn.fccmp_sfloatccmp._unnamed_3 = 0b01;
    insn.fccmp_sfloatccmp.cond = cond;
    insn.fccmp_sfloatccmp.Rm = Rm;
    insn.fccmp_sfloatccmp._unnamed_2 = 0b1;
    insn.fccmp_sfloatccmp.ftype = 0b00;
    insn.fccmp_sfloatccmp._unnamed_1 = 0b11110;
    insn.fccmp_sfloatccmp.S = 0b0;
    insn.fccmp_sfloatccmp._unnamed_0 = 0b0;
    insn.fccmp_sfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmp_d_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmp_dfloatccmp.nzcv = nzcv;
    insn.fccmp_dfloatccmp.op = 0b0;
    insn.fccmp_dfloatccmp.Rn = Rn;
    insn.fccmp_dfloatccmp._unnamed_3 = 0b01;
    insn.fccmp_dfloatccmp.cond = cond;
    insn.fccmp_dfloatccmp.Rm = Rm;
    insn.fccmp_dfloatccmp._unnamed_2 = 0b1;
    insn.fccmp_dfloatccmp.ftype = 0b01;
    insn.fccmp_dfloatccmp._unnamed_1 = 0b11110;
    insn.fccmp_dfloatccmp.S = 0b0;
    insn.fccmp_dfloatccmp._unnamed_0 = 0b0;
    insn.fccmp_dfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmpe_h_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmpe_hfloatccmp.nzcv = nzcv;
    insn.fccmpe_hfloatccmp.op = 0b1;
    insn.fccmpe_hfloatccmp.Rn = Rn;
    insn.fccmpe_hfloatccmp._unnamed_3 = 0b01;
    insn.fccmpe_hfloatccmp.cond = cond;
    insn.fccmpe_hfloatccmp.Rm = Rm;
    insn.fccmpe_hfloatccmp._unnamed_2 = 0b1;
    insn.fccmpe_hfloatccmp.ftype = 0b11;
    insn.fccmpe_hfloatccmp._unnamed_1 = 0b11110;
    insn.fccmpe_hfloatccmp.S = 0b0;
    insn.fccmpe_hfloatccmp._unnamed_0 = 0b0;
    insn.fccmpe_hfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmpe_s_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmpe_sfloatccmp.nzcv = nzcv;
    insn.fccmpe_sfloatccmp.op = 0b1;
    insn.fccmpe_sfloatccmp.Rn = Rn;
    insn.fccmpe_sfloatccmp._unnamed_3 = 0b01;
    insn.fccmpe_sfloatccmp.cond = cond;
    insn.fccmpe_sfloatccmp.Rm = Rm;
    insn.fccmpe_sfloatccmp._unnamed_2 = 0b1;
    insn.fccmpe_sfloatccmp.ftype = 0b00;
    insn.fccmpe_sfloatccmp._unnamed_1 = 0b11110;
    insn.fccmpe_sfloatccmp.S = 0b0;
    insn.fccmpe_sfloatccmp._unnamed_0 = 0b0;
    insn.fccmpe_sfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fccmpe_d_floatccmp(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fccmpe_dfloatccmp.nzcv = nzcv;
    insn.fccmpe_dfloatccmp.op = 0b1;
    insn.fccmpe_dfloatccmp.Rn = Rn;
    insn.fccmpe_dfloatccmp._unnamed_3 = 0b01;
    insn.fccmpe_dfloatccmp.cond = cond;
    insn.fccmpe_dfloatccmp.Rm = Rm;
    insn.fccmpe_dfloatccmp._unnamed_2 = 0b1;
    insn.fccmpe_dfloatccmp.ftype = 0b01;
    insn.fccmpe_dfloatccmp._unnamed_1 = 0b11110;
    insn.fccmpe_dfloatccmp.S = 0b0;
    insn.fccmpe_dfloatccmp._unnamed_0 = 0b0;
    insn.fccmpe_dfloatccmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_h_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_hfloatcmp._unnamed_4 = 0b000;
    insn.fcmp_hfloatcmp.opc = 0b00;
    insn.fcmp_hfloatcmp.Rn = Rn;
    insn.fcmp_hfloatcmp._unnamed_3 = 0b1000;
    insn.fcmp_hfloatcmp.op = 0b00;
    insn.fcmp_hfloatcmp.Rm = Rm;
    insn.fcmp_hfloatcmp._unnamed_2 = 0b1;
    insn.fcmp_hfloatcmp.ftype = 0b11;
    insn.fcmp_hfloatcmp._unnamed_1 = 0b11110;
    insn.fcmp_hfloatcmp.S = 0b0;
    insn.fcmp_hfloatcmp._unnamed_0 = 0b0;
    insn.fcmp_hfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_hz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_hz_floatcmp._unnamed_4 = 0b000;
    insn.fcmp_hz_floatcmp.opc = 0b01;
    insn.fcmp_hz_floatcmp.Rn = Rn;
    insn.fcmp_hz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmp_hz_floatcmp.op = 0b00;
    insn.fcmp_hz_floatcmp.Rm = Rm;
    insn.fcmp_hz_floatcmp._unnamed_2 = 0b1;
    insn.fcmp_hz_floatcmp.ftype = 0b11;
    insn.fcmp_hz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmp_hz_floatcmp.S = 0b0;
    insn.fcmp_hz_floatcmp._unnamed_0 = 0b0;
    insn.fcmp_hz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_s_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_sfloatcmp._unnamed_4 = 0b000;
    insn.fcmp_sfloatcmp.opc = 0b00;
    insn.fcmp_sfloatcmp.Rn = Rn;
    insn.fcmp_sfloatcmp._unnamed_3 = 0b1000;
    insn.fcmp_sfloatcmp.op = 0b00;
    insn.fcmp_sfloatcmp.Rm = Rm;
    insn.fcmp_sfloatcmp._unnamed_2 = 0b1;
    insn.fcmp_sfloatcmp.ftype = 0b00;
    insn.fcmp_sfloatcmp._unnamed_1 = 0b11110;
    insn.fcmp_sfloatcmp.S = 0b0;
    insn.fcmp_sfloatcmp._unnamed_0 = 0b0;
    insn.fcmp_sfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_sz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_sz_floatcmp._unnamed_4 = 0b000;
    insn.fcmp_sz_floatcmp.opc = 0b01;
    insn.fcmp_sz_floatcmp.Rn = Rn;
    insn.fcmp_sz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmp_sz_floatcmp.op = 0b00;
    insn.fcmp_sz_floatcmp.Rm = Rm;
    insn.fcmp_sz_floatcmp._unnamed_2 = 0b1;
    insn.fcmp_sz_floatcmp.ftype = 0b00;
    insn.fcmp_sz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmp_sz_floatcmp.S = 0b0;
    insn.fcmp_sz_floatcmp._unnamed_0 = 0b0;
    insn.fcmp_sz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_d_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_dfloatcmp._unnamed_4 = 0b000;
    insn.fcmp_dfloatcmp.opc = 0b00;
    insn.fcmp_dfloatcmp.Rn = Rn;
    insn.fcmp_dfloatcmp._unnamed_3 = 0b1000;
    insn.fcmp_dfloatcmp.op = 0b00;
    insn.fcmp_dfloatcmp.Rm = Rm;
    insn.fcmp_dfloatcmp._unnamed_2 = 0b1;
    insn.fcmp_dfloatcmp.ftype = 0b01;
    insn.fcmp_dfloatcmp._unnamed_1 = 0b11110;
    insn.fcmp_dfloatcmp.S = 0b0;
    insn.fcmp_dfloatcmp._unnamed_0 = 0b0;
    insn.fcmp_dfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmp_dz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmp_dz_floatcmp._unnamed_4 = 0b000;
    insn.fcmp_dz_floatcmp.opc = 0b01;
    insn.fcmp_dz_floatcmp.Rn = Rn;
    insn.fcmp_dz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmp_dz_floatcmp.op = 0b00;
    insn.fcmp_dz_floatcmp.Rm = Rm;
    insn.fcmp_dz_floatcmp._unnamed_2 = 0b1;
    insn.fcmp_dz_floatcmp.ftype = 0b01;
    insn.fcmp_dz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmp_dz_floatcmp.S = 0b0;
    insn.fcmp_dz_floatcmp._unnamed_0 = 0b0;
    insn.fcmp_dz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_h_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_hfloatcmp._unnamed_4 = 0b000;
    insn.fcmpe_hfloatcmp.opc = 0b10;
    insn.fcmpe_hfloatcmp.Rn = Rn;
    insn.fcmpe_hfloatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_hfloatcmp.op = 0b00;
    insn.fcmpe_hfloatcmp.Rm = Rm;
    insn.fcmpe_hfloatcmp._unnamed_2 = 0b1;
    insn.fcmpe_hfloatcmp.ftype = 0b11;
    insn.fcmpe_hfloatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_hfloatcmp.S = 0b0;
    insn.fcmpe_hfloatcmp._unnamed_0 = 0b0;
    insn.fcmpe_hfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_hz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_hz_floatcmp._unnamed_4 = 0b000;
    insn.fcmpe_hz_floatcmp.opc = 0b11;
    insn.fcmpe_hz_floatcmp.Rn = Rn;
    insn.fcmpe_hz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_hz_floatcmp.op = 0b00;
    insn.fcmpe_hz_floatcmp.Rm = Rm;
    insn.fcmpe_hz_floatcmp._unnamed_2 = 0b1;
    insn.fcmpe_hz_floatcmp.ftype = 0b11;
    insn.fcmpe_hz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_hz_floatcmp.S = 0b0;
    insn.fcmpe_hz_floatcmp._unnamed_0 = 0b0;
    insn.fcmpe_hz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_s_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_sfloatcmp._unnamed_4 = 0b000;
    insn.fcmpe_sfloatcmp.opc = 0b10;
    insn.fcmpe_sfloatcmp.Rn = Rn;
    insn.fcmpe_sfloatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_sfloatcmp.op = 0b00;
    insn.fcmpe_sfloatcmp.Rm = Rm;
    insn.fcmpe_sfloatcmp._unnamed_2 = 0b1;
    insn.fcmpe_sfloatcmp.ftype = 0b00;
    insn.fcmpe_sfloatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_sfloatcmp.S = 0b0;
    insn.fcmpe_sfloatcmp._unnamed_0 = 0b0;
    insn.fcmpe_sfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_sz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_sz_floatcmp._unnamed_4 = 0b000;
    insn.fcmpe_sz_floatcmp.opc = 0b11;
    insn.fcmpe_sz_floatcmp.Rn = Rn;
    insn.fcmpe_sz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_sz_floatcmp.op = 0b00;
    insn.fcmpe_sz_floatcmp.Rm = Rm;
    insn.fcmpe_sz_floatcmp._unnamed_2 = 0b1;
    insn.fcmpe_sz_floatcmp.ftype = 0b00;
    insn.fcmpe_sz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_sz_floatcmp.S = 0b0;
    insn.fcmpe_sz_floatcmp._unnamed_0 = 0b0;
    insn.fcmpe_sz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_d_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_dfloatcmp._unnamed_4 = 0b000;
    insn.fcmpe_dfloatcmp.opc = 0b10;
    insn.fcmpe_dfloatcmp.Rn = Rn;
    insn.fcmpe_dfloatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_dfloatcmp.op = 0b00;
    insn.fcmpe_dfloatcmp.Rm = Rm;
    insn.fcmpe_dfloatcmp._unnamed_2 = 0b1;
    insn.fcmpe_dfloatcmp.ftype = 0b01;
    insn.fcmpe_dfloatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_dfloatcmp.S = 0b0;
    insn.fcmpe_dfloatcmp._unnamed_0 = 0b0;
    insn.fcmpe_dfloatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcmpe_dz_floatcmp(uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcmpe_dz_floatcmp._unnamed_4 = 0b000;
    insn.fcmpe_dz_floatcmp.opc = 0b11;
    insn.fcmpe_dz_floatcmp.Rn = Rn;
    insn.fcmpe_dz_floatcmp._unnamed_3 = 0b1000;
    insn.fcmpe_dz_floatcmp.op = 0b00;
    insn.fcmpe_dz_floatcmp.Rm = Rm;
    insn.fcmpe_dz_floatcmp._unnamed_2 = 0b1;
    insn.fcmpe_dz_floatcmp.ftype = 0b01;
    insn.fcmpe_dz_floatcmp._unnamed_1 = 0b11110;
    insn.fcmpe_dz_floatcmp.S = 0b0;
    insn.fcmpe_dz_floatcmp._unnamed_0 = 0b0;
    insn.fcmpe_dz_floatcmp.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcsel_h_floatsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcsel_hfloatsel.Rd = Rd;
    insn.fcsel_hfloatsel.Rn = Rn;
    insn.fcsel_hfloatsel._unnamed_3 = 0b11;
    insn.fcsel_hfloatsel.cond = cond;
    insn.fcsel_hfloatsel.Rm = Rm;
    insn.fcsel_hfloatsel._unnamed_2 = 0b1;
    insn.fcsel_hfloatsel.ftype = 0b11;
    insn.fcsel_hfloatsel._unnamed_1 = 0b11110;
    insn.fcsel_hfloatsel.S = 0b0;
    insn.fcsel_hfloatsel._unnamed_0 = 0b0;
    insn.fcsel_hfloatsel.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcsel_s_floatsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcsel_sfloatsel.Rd = Rd;
    insn.fcsel_sfloatsel.Rn = Rn;
    insn.fcsel_sfloatsel._unnamed_3 = 0b11;
    insn.fcsel_sfloatsel.cond = cond;
    insn.fcsel_sfloatsel.Rm = Rm;
    insn.fcsel_sfloatsel._unnamed_2 = 0b1;
    insn.fcsel_sfloatsel.ftype = 0b00;
    insn.fcsel_sfloatsel._unnamed_1 = 0b11110;
    insn.fcsel_sfloatsel.S = 0b0;
    insn.fcsel_sfloatsel._unnamed_0 = 0b0;
    insn.fcsel_sfloatsel.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcsel_d_floatsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fcsel_dfloatsel.Rd = Rd;
    insn.fcsel_dfloatsel.Rn = Rn;
    insn.fcsel_dfloatsel._unnamed_3 = 0b11;
    insn.fcsel_dfloatsel.cond = cond;
    insn.fcsel_dfloatsel.Rm = Rm;
    insn.fcsel_dfloatsel._unnamed_2 = 0b1;
    insn.fcsel_dfloatsel.ftype = 0b01;
    insn.fcsel_dfloatsel._unnamed_1 = 0b11110;
    insn.fcsel_dfloatsel.S = 0b0;
    insn.fcsel_dfloatsel._unnamed_0 = 0b0;
    insn.fcsel_dfloatsel.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_sh_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_sh_floatdp1.Rd = Rd;
    insn.fcvt_sh_floatdp1.Rn = Rn;
    insn.fcvt_sh_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_sh_floatdp1.opc = 0b00;
    insn.fcvt_sh_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_sh_floatdp1.ftype = 0b11;
    insn.fcvt_sh_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_sh_floatdp1.S = 0b0;
    insn.fcvt_sh_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_sh_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_dh_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_dh_floatdp1.Rd = Rd;
    insn.fcvt_dh_floatdp1.Rn = Rn;
    insn.fcvt_dh_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_dh_floatdp1.opc = 0b01;
    insn.fcvt_dh_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_dh_floatdp1.ftype = 0b11;
    insn.fcvt_dh_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_dh_floatdp1.S = 0b0;
    insn.fcvt_dh_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_dh_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_hs_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_hs_floatdp1.Rd = Rd;
    insn.fcvt_hs_floatdp1.Rn = Rn;
    insn.fcvt_hs_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_hs_floatdp1.opc = 0b11;
    insn.fcvt_hs_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_hs_floatdp1.ftype = 0b00;
    insn.fcvt_hs_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_hs_floatdp1.S = 0b0;
    insn.fcvt_hs_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_hs_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_ds_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_ds_floatdp1.Rd = Rd;
    insn.fcvt_ds_floatdp1.Rn = Rn;
    insn.fcvt_ds_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_ds_floatdp1.opc = 0b01;
    insn.fcvt_ds_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_ds_floatdp1.ftype = 0b00;
    insn.fcvt_ds_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_ds_floatdp1.S = 0b0;
    insn.fcvt_ds_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_ds_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_hd_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_hd_floatdp1.Rd = Rd;
    insn.fcvt_hd_floatdp1.Rn = Rn;
    insn.fcvt_hd_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_hd_floatdp1.opc = 0b11;
    insn.fcvt_hd_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_hd_floatdp1.ftype = 0b01;
    insn.fcvt_hd_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_hd_floatdp1.S = 0b0;
    insn.fcvt_hd_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_hd_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvt_sd_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvt_sd_floatdp1.Rd = Rd;
    insn.fcvt_sd_floatdp1.Rn = Rn;
    insn.fcvt_sd_floatdp1._unnamed_3 = 0b10000;
    insn.fcvt_sd_floatdp1.opc = 0b00;
    insn.fcvt_sd_floatdp1._unnamed_2 = 0b10001;
    insn.fcvt_sd_floatdp1.ftype = 0b01;
    insn.fcvt_sd_floatdp1._unnamed_1 = 0b11110;
    insn.fcvt_sd_floatdp1.S = 0b0;
    insn.fcvt_sd_floatdp1._unnamed_0 = 0b0;
    insn.fcvt_sd_floatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtas_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas32h_float2int.Rd = Rd;
    insn.fcvtas32h_float2int.Rn = Rn;
    insn.fcvtas32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtas32h_float2int.opcode = 0b100;
    insn.fcvtas32h_float2int.rmode = 0b00;
    insn.fcvtas32h_float2int._unnamed_2 = 0b1;
    insn.fcvtas32h_float2int.ftype = 0b11;
    insn.fcvtas32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtas32h_float2int.S = 0b0;
    insn.fcvtas32h_float2int._unnamed_0 = 0b0;
    insn.fcvtas32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtas_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas64h_float2int.Rd = Rd;
    insn.fcvtas64h_float2int.Rn = Rn;
    insn.fcvtas64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtas64h_float2int.opcode = 0b100;
    insn.fcvtas64h_float2int.rmode = 0b00;
    insn.fcvtas64h_float2int._unnamed_2 = 0b1;
    insn.fcvtas64h_float2int.ftype = 0b11;
    insn.fcvtas64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtas64h_float2int.S = 0b0;
    insn.fcvtas64h_float2int._unnamed_0 = 0b0;
    insn.fcvtas64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtas_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas32s_float2int.Rd = Rd;
    insn.fcvtas32s_float2int.Rn = Rn;
    insn.fcvtas32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtas32s_float2int.opcode = 0b100;
    insn.fcvtas32s_float2int.rmode = 0b00;
    insn.fcvtas32s_float2int._unnamed_2 = 0b1;
    insn.fcvtas32s_float2int.ftype = 0b00;
    insn.fcvtas32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtas32s_float2int.S = 0b0;
    insn.fcvtas32s_float2int._unnamed_0 = 0b0;
    insn.fcvtas32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtas_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas64s_float2int.Rd = Rd;
    insn.fcvtas64s_float2int.Rn = Rn;
    insn.fcvtas64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtas64s_float2int.opcode = 0b100;
    insn.fcvtas64s_float2int.rmode = 0b00;
    insn.fcvtas64s_float2int._unnamed_2 = 0b1;
    insn.fcvtas64s_float2int.ftype = 0b00;
    insn.fcvtas64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtas64s_float2int.S = 0b0;
    insn.fcvtas64s_float2int._unnamed_0 = 0b0;
    insn.fcvtas64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtas_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas32d_float2int.Rd = Rd;
    insn.fcvtas32d_float2int.Rn = Rn;
    insn.fcvtas32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtas32d_float2int.opcode = 0b100;
    insn.fcvtas32d_float2int.rmode = 0b00;
    insn.fcvtas32d_float2int._unnamed_2 = 0b1;
    insn.fcvtas32d_float2int.ftype = 0b01;
    insn.fcvtas32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtas32d_float2int.S = 0b0;
    insn.fcvtas32d_float2int._unnamed_0 = 0b0;
    insn.fcvtas32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtas_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas64d_float2int.Rd = Rd;
    insn.fcvtas64d_float2int.Rn = Rn;
    insn.fcvtas64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtas64d_float2int.opcode = 0b100;
    insn.fcvtas64d_float2int.rmode = 0b00;
    insn.fcvtas64d_float2int._unnamed_2 = 0b1;
    insn.fcvtas64d_float2int.ftype = 0b01;
    insn.fcvtas64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtas64d_float2int.S = 0b0;
    insn.fcvtas64d_float2int._unnamed_0 = 0b0;
    insn.fcvtas64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtas_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas_sisd32h.Rd = Rd;
    insn.fcvtas_sisd32h.Rn = Rn;
    insn.fcvtas_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtas_sisd32h.opcode = 0b010;
    insn.fcvtas_sisd32h.rmode = 0b11;
    insn.fcvtas_sisd32h._unnamed_2 = 0b1;
    insn.fcvtas_sisd32h.ftype = 0b11;
    insn.fcvtas_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtas_sisd32h.S = 0b0;
    insn.fcvtas_sisd32h._unnamed_0 = 0b0;
    insn.fcvtas_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtas_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas_sisd64h.Rd = Rd;
    insn.fcvtas_sisd64h.Rn = Rn;
    insn.fcvtas_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtas_sisd64h.opcode = 0b010;
    insn.fcvtas_sisd64h.rmode = 0b11;
    insn.fcvtas_sisd64h._unnamed_2 = 0b1;
    insn.fcvtas_sisd64h.ftype = 0b11;
    insn.fcvtas_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtas_sisd64h.S = 0b0;
    insn.fcvtas_sisd64h._unnamed_0 = 0b0;
    insn.fcvtas_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtas_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas_sisd64s.Rd = Rd;
    insn.fcvtas_sisd64s.Rn = Rn;
    insn.fcvtas_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtas_sisd64s.opcode = 0b010;
    insn.fcvtas_sisd64s.rmode = 0b11;
    insn.fcvtas_sisd64s._unnamed_2 = 0b1;
    insn.fcvtas_sisd64s.ftype = 0b00;
    insn.fcvtas_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtas_sisd64s.S = 0b0;
    insn.fcvtas_sisd64s._unnamed_0 = 0b0;
    insn.fcvtas_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtas_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtas_sisd32d.Rd = Rd;
    insn.fcvtas_sisd32d.Rn = Rn;
    insn.fcvtas_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtas_sisd32d.opcode = 0b010;
    insn.fcvtas_sisd32d.rmode = 0b11;
    insn.fcvtas_sisd32d._unnamed_2 = 0b1;
    insn.fcvtas_sisd32d.ftype = 0b01;
    insn.fcvtas_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtas_sisd32d.S = 0b0;
    insn.fcvtas_sisd32d._unnamed_0 = 0b0;
    insn.fcvtas_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtau_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau32h_float2int.Rd = Rd;
    insn.fcvtau32h_float2int.Rn = Rn;
    insn.fcvtau32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtau32h_float2int.opcode = 0b101;
    insn.fcvtau32h_float2int.rmode = 0b00;
    insn.fcvtau32h_float2int._unnamed_2 = 0b1;
    insn.fcvtau32h_float2int.ftype = 0b11;
    insn.fcvtau32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtau32h_float2int.S = 0b0;
    insn.fcvtau32h_float2int._unnamed_0 = 0b0;
    insn.fcvtau32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtau_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau64h_float2int.Rd = Rd;
    insn.fcvtau64h_float2int.Rn = Rn;
    insn.fcvtau64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtau64h_float2int.opcode = 0b101;
    insn.fcvtau64h_float2int.rmode = 0b00;
    insn.fcvtau64h_float2int._unnamed_2 = 0b1;
    insn.fcvtau64h_float2int.ftype = 0b11;
    insn.fcvtau64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtau64h_float2int.S = 0b0;
    insn.fcvtau64h_float2int._unnamed_0 = 0b0;
    insn.fcvtau64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtau_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau32s_float2int.Rd = Rd;
    insn.fcvtau32s_float2int.Rn = Rn;
    insn.fcvtau32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtau32s_float2int.opcode = 0b101;
    insn.fcvtau32s_float2int.rmode = 0b00;
    insn.fcvtau32s_float2int._unnamed_2 = 0b1;
    insn.fcvtau32s_float2int.ftype = 0b00;
    insn.fcvtau32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtau32s_float2int.S = 0b0;
    insn.fcvtau32s_float2int._unnamed_0 = 0b0;
    insn.fcvtau32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtau_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau64s_float2int.Rd = Rd;
    insn.fcvtau64s_float2int.Rn = Rn;
    insn.fcvtau64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtau64s_float2int.opcode = 0b101;
    insn.fcvtau64s_float2int.rmode = 0b00;
    insn.fcvtau64s_float2int._unnamed_2 = 0b1;
    insn.fcvtau64s_float2int.ftype = 0b00;
    insn.fcvtau64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtau64s_float2int.S = 0b0;
    insn.fcvtau64s_float2int._unnamed_0 = 0b0;
    insn.fcvtau64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtau_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau32d_float2int.Rd = Rd;
    insn.fcvtau32d_float2int.Rn = Rn;
    insn.fcvtau32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtau32d_float2int.opcode = 0b101;
    insn.fcvtau32d_float2int.rmode = 0b00;
    insn.fcvtau32d_float2int._unnamed_2 = 0b1;
    insn.fcvtau32d_float2int.ftype = 0b01;
    insn.fcvtau32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtau32d_float2int.S = 0b0;
    insn.fcvtau32d_float2int._unnamed_0 = 0b0;
    insn.fcvtau32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtau_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau64d_float2int.Rd = Rd;
    insn.fcvtau64d_float2int.Rn = Rn;
    insn.fcvtau64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtau64d_float2int.opcode = 0b101;
    insn.fcvtau64d_float2int.rmode = 0b00;
    insn.fcvtau64d_float2int._unnamed_2 = 0b1;
    insn.fcvtau64d_float2int.ftype = 0b01;
    insn.fcvtau64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtau64d_float2int.S = 0b0;
    insn.fcvtau64d_float2int._unnamed_0 = 0b0;
    insn.fcvtau64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtau_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau_sisd32h.Rd = Rd;
    insn.fcvtau_sisd32h.Rn = Rn;
    insn.fcvtau_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtau_sisd32h.opcode = 0b011;
    insn.fcvtau_sisd32h.rmode = 0b11;
    insn.fcvtau_sisd32h._unnamed_2 = 0b1;
    insn.fcvtau_sisd32h.ftype = 0b11;
    insn.fcvtau_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtau_sisd32h.S = 0b0;
    insn.fcvtau_sisd32h._unnamed_0 = 0b0;
    insn.fcvtau_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtau_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau_sisd64h.Rd = Rd;
    insn.fcvtau_sisd64h.Rn = Rn;
    insn.fcvtau_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtau_sisd64h.opcode = 0b011;
    insn.fcvtau_sisd64h.rmode = 0b11;
    insn.fcvtau_sisd64h._unnamed_2 = 0b1;
    insn.fcvtau_sisd64h.ftype = 0b11;
    insn.fcvtau_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtau_sisd64h.S = 0b0;
    insn.fcvtau_sisd64h._unnamed_0 = 0b0;
    insn.fcvtau_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtau_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau_sisd64s.Rd = Rd;
    insn.fcvtau_sisd64s.Rn = Rn;
    insn.fcvtau_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtau_sisd64s.opcode = 0b011;
    insn.fcvtau_sisd64s.rmode = 0b11;
    insn.fcvtau_sisd64s._unnamed_2 = 0b1;
    insn.fcvtau_sisd64s.ftype = 0b00;
    insn.fcvtau_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtau_sisd64s.S = 0b0;
    insn.fcvtau_sisd64s._unnamed_0 = 0b0;
    insn.fcvtau_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtau_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtau_sisd32d.Rd = Rd;
    insn.fcvtau_sisd32d.Rn = Rn;
    insn.fcvtau_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtau_sisd32d.opcode = 0b011;
    insn.fcvtau_sisd32d.rmode = 0b11;
    insn.fcvtau_sisd32d._unnamed_2 = 0b1;
    insn.fcvtau_sisd32d.ftype = 0b01;
    insn.fcvtau_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtau_sisd32d.S = 0b0;
    insn.fcvtau_sisd32d._unnamed_0 = 0b0;
    insn.fcvtau_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtms_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms32h_float2int.Rd = Rd;
    insn.fcvtms32h_float2int.Rn = Rn;
    insn.fcvtms32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtms32h_float2int.opcode = 0b000;
    insn.fcvtms32h_float2int.rmode = 0b10;
    insn.fcvtms32h_float2int._unnamed_2 = 0b1;
    insn.fcvtms32h_float2int.ftype = 0b11;
    insn.fcvtms32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtms32h_float2int.S = 0b0;
    insn.fcvtms32h_float2int._unnamed_0 = 0b0;
    insn.fcvtms32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtms_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms64h_float2int.Rd = Rd;
    insn.fcvtms64h_float2int.Rn = Rn;
    insn.fcvtms64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtms64h_float2int.opcode = 0b000;
    insn.fcvtms64h_float2int.rmode = 0b10;
    insn.fcvtms64h_float2int._unnamed_2 = 0b1;
    insn.fcvtms64h_float2int.ftype = 0b11;
    insn.fcvtms64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtms64h_float2int.S = 0b0;
    insn.fcvtms64h_float2int._unnamed_0 = 0b0;
    insn.fcvtms64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtms_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms32s_float2int.Rd = Rd;
    insn.fcvtms32s_float2int.Rn = Rn;
    insn.fcvtms32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtms32s_float2int.opcode = 0b000;
    insn.fcvtms32s_float2int.rmode = 0b10;
    insn.fcvtms32s_float2int._unnamed_2 = 0b1;
    insn.fcvtms32s_float2int.ftype = 0b00;
    insn.fcvtms32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtms32s_float2int.S = 0b0;
    insn.fcvtms32s_float2int._unnamed_0 = 0b0;
    insn.fcvtms32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtms_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms64s_float2int.Rd = Rd;
    insn.fcvtms64s_float2int.Rn = Rn;
    insn.fcvtms64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtms64s_float2int.opcode = 0b000;
    insn.fcvtms64s_float2int.rmode = 0b10;
    insn.fcvtms64s_float2int._unnamed_2 = 0b1;
    insn.fcvtms64s_float2int.ftype = 0b00;
    insn.fcvtms64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtms64s_float2int.S = 0b0;
    insn.fcvtms64s_float2int._unnamed_0 = 0b0;
    insn.fcvtms64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtms_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms32d_float2int.Rd = Rd;
    insn.fcvtms32d_float2int.Rn = Rn;
    insn.fcvtms32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtms32d_float2int.opcode = 0b000;
    insn.fcvtms32d_float2int.rmode = 0b10;
    insn.fcvtms32d_float2int._unnamed_2 = 0b1;
    insn.fcvtms32d_float2int.ftype = 0b01;
    insn.fcvtms32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtms32d_float2int.S = 0b0;
    insn.fcvtms32d_float2int._unnamed_0 = 0b0;
    insn.fcvtms32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtms_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms64d_float2int.Rd = Rd;
    insn.fcvtms64d_float2int.Rn = Rn;
    insn.fcvtms64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtms64d_float2int.opcode = 0b000;
    insn.fcvtms64d_float2int.rmode = 0b10;
    insn.fcvtms64d_float2int._unnamed_2 = 0b1;
    insn.fcvtms64d_float2int.ftype = 0b01;
    insn.fcvtms64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtms64d_float2int.S = 0b0;
    insn.fcvtms64d_float2int._unnamed_0 = 0b0;
    insn.fcvtms64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtms_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms_sisd32h.Rd = Rd;
    insn.fcvtms_sisd32h.Rn = Rn;
    insn.fcvtms_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtms_sisd32h.opcode = 0b100;
    insn.fcvtms_sisd32h.rmode = 0b10;
    insn.fcvtms_sisd32h._unnamed_2 = 0b1;
    insn.fcvtms_sisd32h.ftype = 0b11;
    insn.fcvtms_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtms_sisd32h.S = 0b0;
    insn.fcvtms_sisd32h._unnamed_0 = 0b0;
    insn.fcvtms_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtms_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms_sisd64h.Rd = Rd;
    insn.fcvtms_sisd64h.Rn = Rn;
    insn.fcvtms_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtms_sisd64h.opcode = 0b100;
    insn.fcvtms_sisd64h.rmode = 0b10;
    insn.fcvtms_sisd64h._unnamed_2 = 0b1;
    insn.fcvtms_sisd64h.ftype = 0b11;
    insn.fcvtms_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtms_sisd64h.S = 0b0;
    insn.fcvtms_sisd64h._unnamed_0 = 0b0;
    insn.fcvtms_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtms_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms_sisd64s.Rd = Rd;
    insn.fcvtms_sisd64s.Rn = Rn;
    insn.fcvtms_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtms_sisd64s.opcode = 0b100;
    insn.fcvtms_sisd64s.rmode = 0b10;
    insn.fcvtms_sisd64s._unnamed_2 = 0b1;
    insn.fcvtms_sisd64s.ftype = 0b00;
    insn.fcvtms_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtms_sisd64s.S = 0b0;
    insn.fcvtms_sisd64s._unnamed_0 = 0b0;
    insn.fcvtms_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtms_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtms_sisd32d.Rd = Rd;
    insn.fcvtms_sisd32d.Rn = Rn;
    insn.fcvtms_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtms_sisd32d.opcode = 0b100;
    insn.fcvtms_sisd32d.rmode = 0b10;
    insn.fcvtms_sisd32d._unnamed_2 = 0b1;
    insn.fcvtms_sisd32d.ftype = 0b01;
    insn.fcvtms_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtms_sisd32d.S = 0b0;
    insn.fcvtms_sisd32d._unnamed_0 = 0b0;
    insn.fcvtms_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtmu_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu32h_float2int.Rd = Rd;
    insn.fcvtmu32h_float2int.Rn = Rn;
    insn.fcvtmu32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu32h_float2int.opcode = 0b001;
    insn.fcvtmu32h_float2int.rmode = 0b10;
    insn.fcvtmu32h_float2int._unnamed_2 = 0b1;
    insn.fcvtmu32h_float2int.ftype = 0b11;
    insn.fcvtmu32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu32h_float2int.S = 0b0;
    insn.fcvtmu32h_float2int._unnamed_0 = 0b0;
    insn.fcvtmu32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtmu_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu64h_float2int.Rd = Rd;
    insn.fcvtmu64h_float2int.Rn = Rn;
    insn.fcvtmu64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu64h_float2int.opcode = 0b001;
    insn.fcvtmu64h_float2int.rmode = 0b10;
    insn.fcvtmu64h_float2int._unnamed_2 = 0b1;
    insn.fcvtmu64h_float2int.ftype = 0b11;
    insn.fcvtmu64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu64h_float2int.S = 0b0;
    insn.fcvtmu64h_float2int._unnamed_0 = 0b0;
    insn.fcvtmu64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtmu_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu32s_float2int.Rd = Rd;
    insn.fcvtmu32s_float2int.Rn = Rn;
    insn.fcvtmu32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu32s_float2int.opcode = 0b001;
    insn.fcvtmu32s_float2int.rmode = 0b10;
    insn.fcvtmu32s_float2int._unnamed_2 = 0b1;
    insn.fcvtmu32s_float2int.ftype = 0b00;
    insn.fcvtmu32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu32s_float2int.S = 0b0;
    insn.fcvtmu32s_float2int._unnamed_0 = 0b0;
    insn.fcvtmu32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtmu_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu64s_float2int.Rd = Rd;
    insn.fcvtmu64s_float2int.Rn = Rn;
    insn.fcvtmu64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu64s_float2int.opcode = 0b001;
    insn.fcvtmu64s_float2int.rmode = 0b10;
    insn.fcvtmu64s_float2int._unnamed_2 = 0b1;
    insn.fcvtmu64s_float2int.ftype = 0b00;
    insn.fcvtmu64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu64s_float2int.S = 0b0;
    insn.fcvtmu64s_float2int._unnamed_0 = 0b0;
    insn.fcvtmu64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtmu_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu32d_float2int.Rd = Rd;
    insn.fcvtmu32d_float2int.Rn = Rn;
    insn.fcvtmu32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu32d_float2int.opcode = 0b001;
    insn.fcvtmu32d_float2int.rmode = 0b10;
    insn.fcvtmu32d_float2int._unnamed_2 = 0b1;
    insn.fcvtmu32d_float2int.ftype = 0b01;
    insn.fcvtmu32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu32d_float2int.S = 0b0;
    insn.fcvtmu32d_float2int._unnamed_0 = 0b0;
    insn.fcvtmu32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtmu_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu64d_float2int.Rd = Rd;
    insn.fcvtmu64d_float2int.Rn = Rn;
    insn.fcvtmu64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtmu64d_float2int.opcode = 0b001;
    insn.fcvtmu64d_float2int.rmode = 0b10;
    insn.fcvtmu64d_float2int._unnamed_2 = 0b1;
    insn.fcvtmu64d_float2int.ftype = 0b01;
    insn.fcvtmu64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtmu64d_float2int.S = 0b0;
    insn.fcvtmu64d_float2int._unnamed_0 = 0b0;
    insn.fcvtmu64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtmu_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu_sisd32h.Rd = Rd;
    insn.fcvtmu_sisd32h.Rn = Rn;
    insn.fcvtmu_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtmu_sisd32h.opcode = 0b101;
    insn.fcvtmu_sisd32h.rmode = 0b10;
    insn.fcvtmu_sisd32h._unnamed_2 = 0b1;
    insn.fcvtmu_sisd32h.ftype = 0b11;
    insn.fcvtmu_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtmu_sisd32h.S = 0b0;
    insn.fcvtmu_sisd32h._unnamed_0 = 0b0;
    insn.fcvtmu_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtmu_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu_sisd64h.Rd = Rd;
    insn.fcvtmu_sisd64h.Rn = Rn;
    insn.fcvtmu_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtmu_sisd64h.opcode = 0b101;
    insn.fcvtmu_sisd64h.rmode = 0b10;
    insn.fcvtmu_sisd64h._unnamed_2 = 0b1;
    insn.fcvtmu_sisd64h.ftype = 0b11;
    insn.fcvtmu_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtmu_sisd64h.S = 0b0;
    insn.fcvtmu_sisd64h._unnamed_0 = 0b0;
    insn.fcvtmu_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtmu_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu_sisd64s.Rd = Rd;
    insn.fcvtmu_sisd64s.Rn = Rn;
    insn.fcvtmu_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtmu_sisd64s.opcode = 0b101;
    insn.fcvtmu_sisd64s.rmode = 0b10;
    insn.fcvtmu_sisd64s._unnamed_2 = 0b1;
    insn.fcvtmu_sisd64s.ftype = 0b00;
    insn.fcvtmu_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtmu_sisd64s.S = 0b0;
    insn.fcvtmu_sisd64s._unnamed_0 = 0b0;
    insn.fcvtmu_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtmu_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtmu_sisd32d.Rd = Rd;
    insn.fcvtmu_sisd32d.Rn = Rn;
    insn.fcvtmu_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtmu_sisd32d.opcode = 0b101;
    insn.fcvtmu_sisd32d.rmode = 0b10;
    insn.fcvtmu_sisd32d._unnamed_2 = 0b1;
    insn.fcvtmu_sisd32d.ftype = 0b01;
    insn.fcvtmu_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtmu_sisd32d.S = 0b0;
    insn.fcvtmu_sisd32d._unnamed_0 = 0b0;
    insn.fcvtmu_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtns_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns32h_float2int.Rd = Rd;
    insn.fcvtns32h_float2int.Rn = Rn;
    insn.fcvtns32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtns32h_float2int.opcode = 0b000;
    insn.fcvtns32h_float2int.rmode = 0b00;
    insn.fcvtns32h_float2int._unnamed_2 = 0b1;
    insn.fcvtns32h_float2int.ftype = 0b11;
    insn.fcvtns32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtns32h_float2int.S = 0b0;
    insn.fcvtns32h_float2int._unnamed_0 = 0b0;
    insn.fcvtns32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtns_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns64h_float2int.Rd = Rd;
    insn.fcvtns64h_float2int.Rn = Rn;
    insn.fcvtns64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtns64h_float2int.opcode = 0b000;
    insn.fcvtns64h_float2int.rmode = 0b00;
    insn.fcvtns64h_float2int._unnamed_2 = 0b1;
    insn.fcvtns64h_float2int.ftype = 0b11;
    insn.fcvtns64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtns64h_float2int.S = 0b0;
    insn.fcvtns64h_float2int._unnamed_0 = 0b0;
    insn.fcvtns64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtns_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns32s_float2int.Rd = Rd;
    insn.fcvtns32s_float2int.Rn = Rn;
    insn.fcvtns32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtns32s_float2int.opcode = 0b000;
    insn.fcvtns32s_float2int.rmode = 0b00;
    insn.fcvtns32s_float2int._unnamed_2 = 0b1;
    insn.fcvtns32s_float2int.ftype = 0b00;
    insn.fcvtns32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtns32s_float2int.S = 0b0;
    insn.fcvtns32s_float2int._unnamed_0 = 0b0;
    insn.fcvtns32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtns_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns64s_float2int.Rd = Rd;
    insn.fcvtns64s_float2int.Rn = Rn;
    insn.fcvtns64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtns64s_float2int.opcode = 0b000;
    insn.fcvtns64s_float2int.rmode = 0b00;
    insn.fcvtns64s_float2int._unnamed_2 = 0b1;
    insn.fcvtns64s_float2int.ftype = 0b00;
    insn.fcvtns64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtns64s_float2int.S = 0b0;
    insn.fcvtns64s_float2int._unnamed_0 = 0b0;
    insn.fcvtns64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtns_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns32d_float2int.Rd = Rd;
    insn.fcvtns32d_float2int.Rn = Rn;
    insn.fcvtns32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtns32d_float2int.opcode = 0b000;
    insn.fcvtns32d_float2int.rmode = 0b00;
    insn.fcvtns32d_float2int._unnamed_2 = 0b1;
    insn.fcvtns32d_float2int.ftype = 0b01;
    insn.fcvtns32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtns32d_float2int.S = 0b0;
    insn.fcvtns32d_float2int._unnamed_0 = 0b0;
    insn.fcvtns32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtns_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns64d_float2int.Rd = Rd;
    insn.fcvtns64d_float2int.Rn = Rn;
    insn.fcvtns64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtns64d_float2int.opcode = 0b000;
    insn.fcvtns64d_float2int.rmode = 0b00;
    insn.fcvtns64d_float2int._unnamed_2 = 0b1;
    insn.fcvtns64d_float2int.ftype = 0b01;
    insn.fcvtns64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtns64d_float2int.S = 0b0;
    insn.fcvtns64d_float2int._unnamed_0 = 0b0;
    insn.fcvtns64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtns_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns_sisd32h.Rd = Rd;
    insn.fcvtns_sisd32h.Rn = Rn;
    insn.fcvtns_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtns_sisd32h.opcode = 0b010;
    insn.fcvtns_sisd32h.rmode = 0b01;
    insn.fcvtns_sisd32h._unnamed_2 = 0b1;
    insn.fcvtns_sisd32h.ftype = 0b11;
    insn.fcvtns_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtns_sisd32h.S = 0b0;
    insn.fcvtns_sisd32h._unnamed_0 = 0b0;
    insn.fcvtns_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtns_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns_sisd64h.Rd = Rd;
    insn.fcvtns_sisd64h.Rn = Rn;
    insn.fcvtns_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtns_sisd64h.opcode = 0b010;
    insn.fcvtns_sisd64h.rmode = 0b01;
    insn.fcvtns_sisd64h._unnamed_2 = 0b1;
    insn.fcvtns_sisd64h.ftype = 0b11;
    insn.fcvtns_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtns_sisd64h.S = 0b0;
    insn.fcvtns_sisd64h._unnamed_0 = 0b0;
    insn.fcvtns_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtns_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns_sisd64s.Rd = Rd;
    insn.fcvtns_sisd64s.Rn = Rn;
    insn.fcvtns_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtns_sisd64s.opcode = 0b010;
    insn.fcvtns_sisd64s.rmode = 0b01;
    insn.fcvtns_sisd64s._unnamed_2 = 0b1;
    insn.fcvtns_sisd64s.ftype = 0b00;
    insn.fcvtns_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtns_sisd64s.S = 0b0;
    insn.fcvtns_sisd64s._unnamed_0 = 0b0;
    insn.fcvtns_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtns_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtns_sisd32d.Rd = Rd;
    insn.fcvtns_sisd32d.Rn = Rn;
    insn.fcvtns_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtns_sisd32d.opcode = 0b010;
    insn.fcvtns_sisd32d.rmode = 0b01;
    insn.fcvtns_sisd32d._unnamed_2 = 0b1;
    insn.fcvtns_sisd32d.ftype = 0b01;
    insn.fcvtns_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtns_sisd32d.S = 0b0;
    insn.fcvtns_sisd32d._unnamed_0 = 0b0;
    insn.fcvtns_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtnu_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu32h_float2int.Rd = Rd;
    insn.fcvtnu32h_float2int.Rn = Rn;
    insn.fcvtnu32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu32h_float2int.opcode = 0b001;
    insn.fcvtnu32h_float2int.rmode = 0b00;
    insn.fcvtnu32h_float2int._unnamed_2 = 0b1;
    insn.fcvtnu32h_float2int.ftype = 0b11;
    insn.fcvtnu32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu32h_float2int.S = 0b0;
    insn.fcvtnu32h_float2int._unnamed_0 = 0b0;
    insn.fcvtnu32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtnu_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu64h_float2int.Rd = Rd;
    insn.fcvtnu64h_float2int.Rn = Rn;
    insn.fcvtnu64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu64h_float2int.opcode = 0b001;
    insn.fcvtnu64h_float2int.rmode = 0b00;
    insn.fcvtnu64h_float2int._unnamed_2 = 0b1;
    insn.fcvtnu64h_float2int.ftype = 0b11;
    insn.fcvtnu64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu64h_float2int.S = 0b0;
    insn.fcvtnu64h_float2int._unnamed_0 = 0b0;
    insn.fcvtnu64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtnu_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu32s_float2int.Rd = Rd;
    insn.fcvtnu32s_float2int.Rn = Rn;
    insn.fcvtnu32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu32s_float2int.opcode = 0b001;
    insn.fcvtnu32s_float2int.rmode = 0b00;
    insn.fcvtnu32s_float2int._unnamed_2 = 0b1;
    insn.fcvtnu32s_float2int.ftype = 0b00;
    insn.fcvtnu32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu32s_float2int.S = 0b0;
    insn.fcvtnu32s_float2int._unnamed_0 = 0b0;
    insn.fcvtnu32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtnu_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu64s_float2int.Rd = Rd;
    insn.fcvtnu64s_float2int.Rn = Rn;
    insn.fcvtnu64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu64s_float2int.opcode = 0b001;
    insn.fcvtnu64s_float2int.rmode = 0b00;
    insn.fcvtnu64s_float2int._unnamed_2 = 0b1;
    insn.fcvtnu64s_float2int.ftype = 0b00;
    insn.fcvtnu64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu64s_float2int.S = 0b0;
    insn.fcvtnu64s_float2int._unnamed_0 = 0b0;
    insn.fcvtnu64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtnu_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu32d_float2int.Rd = Rd;
    insn.fcvtnu32d_float2int.Rn = Rn;
    insn.fcvtnu32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu32d_float2int.opcode = 0b001;
    insn.fcvtnu32d_float2int.rmode = 0b00;
    insn.fcvtnu32d_float2int._unnamed_2 = 0b1;
    insn.fcvtnu32d_float2int.ftype = 0b01;
    insn.fcvtnu32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu32d_float2int.S = 0b0;
    insn.fcvtnu32d_float2int._unnamed_0 = 0b0;
    insn.fcvtnu32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtnu_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu64d_float2int.Rd = Rd;
    insn.fcvtnu64d_float2int.Rn = Rn;
    insn.fcvtnu64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtnu64d_float2int.opcode = 0b001;
    insn.fcvtnu64d_float2int.rmode = 0b00;
    insn.fcvtnu64d_float2int._unnamed_2 = 0b1;
    insn.fcvtnu64d_float2int.ftype = 0b01;
    insn.fcvtnu64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtnu64d_float2int.S = 0b0;
    insn.fcvtnu64d_float2int._unnamed_0 = 0b0;
    insn.fcvtnu64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtnu_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu_sisd32h.Rd = Rd;
    insn.fcvtnu_sisd32h.Rn = Rn;
    insn.fcvtnu_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtnu_sisd32h.opcode = 0b011;
    insn.fcvtnu_sisd32h.rmode = 0b01;
    insn.fcvtnu_sisd32h._unnamed_2 = 0b1;
    insn.fcvtnu_sisd32h.ftype = 0b11;
    insn.fcvtnu_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtnu_sisd32h.S = 0b0;
    insn.fcvtnu_sisd32h._unnamed_0 = 0b0;
    insn.fcvtnu_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtnu_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu_sisd64h.Rd = Rd;
    insn.fcvtnu_sisd64h.Rn = Rn;
    insn.fcvtnu_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtnu_sisd64h.opcode = 0b011;
    insn.fcvtnu_sisd64h.rmode = 0b01;
    insn.fcvtnu_sisd64h._unnamed_2 = 0b1;
    insn.fcvtnu_sisd64h.ftype = 0b11;
    insn.fcvtnu_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtnu_sisd64h.S = 0b0;
    insn.fcvtnu_sisd64h._unnamed_0 = 0b0;
    insn.fcvtnu_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtnu_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu_sisd64s.Rd = Rd;
    insn.fcvtnu_sisd64s.Rn = Rn;
    insn.fcvtnu_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtnu_sisd64s.opcode = 0b011;
    insn.fcvtnu_sisd64s.rmode = 0b01;
    insn.fcvtnu_sisd64s._unnamed_2 = 0b1;
    insn.fcvtnu_sisd64s.ftype = 0b00;
    insn.fcvtnu_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtnu_sisd64s.S = 0b0;
    insn.fcvtnu_sisd64s._unnamed_0 = 0b0;
    insn.fcvtnu_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtnu_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtnu_sisd32d.Rd = Rd;
    insn.fcvtnu_sisd32d.Rn = Rn;
    insn.fcvtnu_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtnu_sisd32d.opcode = 0b011;
    insn.fcvtnu_sisd32d.rmode = 0b01;
    insn.fcvtnu_sisd32d._unnamed_2 = 0b1;
    insn.fcvtnu_sisd32d.ftype = 0b01;
    insn.fcvtnu_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtnu_sisd32d.S = 0b0;
    insn.fcvtnu_sisd32d._unnamed_0 = 0b0;
    insn.fcvtnu_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtps_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps32h_float2int.Rd = Rd;
    insn.fcvtps32h_float2int.Rn = Rn;
    insn.fcvtps32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtps32h_float2int.opcode = 0b000;
    insn.fcvtps32h_float2int.rmode = 0b01;
    insn.fcvtps32h_float2int._unnamed_2 = 0b1;
    insn.fcvtps32h_float2int.ftype = 0b11;
    insn.fcvtps32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtps32h_float2int.S = 0b0;
    insn.fcvtps32h_float2int._unnamed_0 = 0b0;
    insn.fcvtps32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtps_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps64h_float2int.Rd = Rd;
    insn.fcvtps64h_float2int.Rn = Rn;
    insn.fcvtps64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtps64h_float2int.opcode = 0b000;
    insn.fcvtps64h_float2int.rmode = 0b01;
    insn.fcvtps64h_float2int._unnamed_2 = 0b1;
    insn.fcvtps64h_float2int.ftype = 0b11;
    insn.fcvtps64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtps64h_float2int.S = 0b0;
    insn.fcvtps64h_float2int._unnamed_0 = 0b0;
    insn.fcvtps64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtps_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps32s_float2int.Rd = Rd;
    insn.fcvtps32s_float2int.Rn = Rn;
    insn.fcvtps32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtps32s_float2int.opcode = 0b000;
    insn.fcvtps32s_float2int.rmode = 0b01;
    insn.fcvtps32s_float2int._unnamed_2 = 0b1;
    insn.fcvtps32s_float2int.ftype = 0b00;
    insn.fcvtps32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtps32s_float2int.S = 0b0;
    insn.fcvtps32s_float2int._unnamed_0 = 0b0;
    insn.fcvtps32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtps_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps64s_float2int.Rd = Rd;
    insn.fcvtps64s_float2int.Rn = Rn;
    insn.fcvtps64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtps64s_float2int.opcode = 0b000;
    insn.fcvtps64s_float2int.rmode = 0b01;
    insn.fcvtps64s_float2int._unnamed_2 = 0b1;
    insn.fcvtps64s_float2int.ftype = 0b00;
    insn.fcvtps64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtps64s_float2int.S = 0b0;
    insn.fcvtps64s_float2int._unnamed_0 = 0b0;
    insn.fcvtps64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtps_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps32d_float2int.Rd = Rd;
    insn.fcvtps32d_float2int.Rn = Rn;
    insn.fcvtps32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtps32d_float2int.opcode = 0b000;
    insn.fcvtps32d_float2int.rmode = 0b01;
    insn.fcvtps32d_float2int._unnamed_2 = 0b1;
    insn.fcvtps32d_float2int.ftype = 0b01;
    insn.fcvtps32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtps32d_float2int.S = 0b0;
    insn.fcvtps32d_float2int._unnamed_0 = 0b0;
    insn.fcvtps32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtps_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps64d_float2int.Rd = Rd;
    insn.fcvtps64d_float2int.Rn = Rn;
    insn.fcvtps64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtps64d_float2int.opcode = 0b000;
    insn.fcvtps64d_float2int.rmode = 0b01;
    insn.fcvtps64d_float2int._unnamed_2 = 0b1;
    insn.fcvtps64d_float2int.ftype = 0b01;
    insn.fcvtps64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtps64d_float2int.S = 0b0;
    insn.fcvtps64d_float2int._unnamed_0 = 0b0;
    insn.fcvtps64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtps_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps_sisd32h.Rd = Rd;
    insn.fcvtps_sisd32h.Rn = Rn;
    insn.fcvtps_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtps_sisd32h.opcode = 0b010;
    insn.fcvtps_sisd32h.rmode = 0b10;
    insn.fcvtps_sisd32h._unnamed_2 = 0b1;
    insn.fcvtps_sisd32h.ftype = 0b11;
    insn.fcvtps_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtps_sisd32h.S = 0b0;
    insn.fcvtps_sisd32h._unnamed_0 = 0b0;
    insn.fcvtps_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtps_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps_sisd64h.Rd = Rd;
    insn.fcvtps_sisd64h.Rn = Rn;
    insn.fcvtps_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtps_sisd64h.opcode = 0b010;
    insn.fcvtps_sisd64h.rmode = 0b10;
    insn.fcvtps_sisd64h._unnamed_2 = 0b1;
    insn.fcvtps_sisd64h.ftype = 0b11;
    insn.fcvtps_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtps_sisd64h.S = 0b0;
    insn.fcvtps_sisd64h._unnamed_0 = 0b0;
    insn.fcvtps_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtps_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps_sisd64s.Rd = Rd;
    insn.fcvtps_sisd64s.Rn = Rn;
    insn.fcvtps_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtps_sisd64s.opcode = 0b010;
    insn.fcvtps_sisd64s.rmode = 0b10;
    insn.fcvtps_sisd64s._unnamed_2 = 0b1;
    insn.fcvtps_sisd64s.ftype = 0b00;
    insn.fcvtps_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtps_sisd64s.S = 0b0;
    insn.fcvtps_sisd64s._unnamed_0 = 0b0;
    insn.fcvtps_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtps_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtps_sisd32d.Rd = Rd;
    insn.fcvtps_sisd32d.Rn = Rn;
    insn.fcvtps_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtps_sisd32d.opcode = 0b010;
    insn.fcvtps_sisd32d.rmode = 0b10;
    insn.fcvtps_sisd32d._unnamed_2 = 0b1;
    insn.fcvtps_sisd32d.ftype = 0b01;
    insn.fcvtps_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtps_sisd32d.S = 0b0;
    insn.fcvtps_sisd32d._unnamed_0 = 0b0;
    insn.fcvtps_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtpu_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu32h_float2int.Rd = Rd;
    insn.fcvtpu32h_float2int.Rn = Rn;
    insn.fcvtpu32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu32h_float2int.opcode = 0b001;
    insn.fcvtpu32h_float2int.rmode = 0b01;
    insn.fcvtpu32h_float2int._unnamed_2 = 0b1;
    insn.fcvtpu32h_float2int.ftype = 0b11;
    insn.fcvtpu32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu32h_float2int.S = 0b0;
    insn.fcvtpu32h_float2int._unnamed_0 = 0b0;
    insn.fcvtpu32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtpu_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu64h_float2int.Rd = Rd;
    insn.fcvtpu64h_float2int.Rn = Rn;
    insn.fcvtpu64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu64h_float2int.opcode = 0b001;
    insn.fcvtpu64h_float2int.rmode = 0b01;
    insn.fcvtpu64h_float2int._unnamed_2 = 0b1;
    insn.fcvtpu64h_float2int.ftype = 0b11;
    insn.fcvtpu64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu64h_float2int.S = 0b0;
    insn.fcvtpu64h_float2int._unnamed_0 = 0b0;
    insn.fcvtpu64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtpu_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu32s_float2int.Rd = Rd;
    insn.fcvtpu32s_float2int.Rn = Rn;
    insn.fcvtpu32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu32s_float2int.opcode = 0b001;
    insn.fcvtpu32s_float2int.rmode = 0b01;
    insn.fcvtpu32s_float2int._unnamed_2 = 0b1;
    insn.fcvtpu32s_float2int.ftype = 0b00;
    insn.fcvtpu32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu32s_float2int.S = 0b0;
    insn.fcvtpu32s_float2int._unnamed_0 = 0b0;
    insn.fcvtpu32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtpu_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu64s_float2int.Rd = Rd;
    insn.fcvtpu64s_float2int.Rn = Rn;
    insn.fcvtpu64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu64s_float2int.opcode = 0b001;
    insn.fcvtpu64s_float2int.rmode = 0b01;
    insn.fcvtpu64s_float2int._unnamed_2 = 0b1;
    insn.fcvtpu64s_float2int.ftype = 0b00;
    insn.fcvtpu64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu64s_float2int.S = 0b0;
    insn.fcvtpu64s_float2int._unnamed_0 = 0b0;
    insn.fcvtpu64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtpu_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu32d_float2int.Rd = Rd;
    insn.fcvtpu32d_float2int.Rn = Rn;
    insn.fcvtpu32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu32d_float2int.opcode = 0b001;
    insn.fcvtpu32d_float2int.rmode = 0b01;
    insn.fcvtpu32d_float2int._unnamed_2 = 0b1;
    insn.fcvtpu32d_float2int.ftype = 0b01;
    insn.fcvtpu32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu32d_float2int.S = 0b0;
    insn.fcvtpu32d_float2int._unnamed_0 = 0b0;
    insn.fcvtpu32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtpu_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu64d_float2int.Rd = Rd;
    insn.fcvtpu64d_float2int.Rn = Rn;
    insn.fcvtpu64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtpu64d_float2int.opcode = 0b001;
    insn.fcvtpu64d_float2int.rmode = 0b01;
    insn.fcvtpu64d_float2int._unnamed_2 = 0b1;
    insn.fcvtpu64d_float2int.ftype = 0b01;
    insn.fcvtpu64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtpu64d_float2int.S = 0b0;
    insn.fcvtpu64d_float2int._unnamed_0 = 0b0;
    insn.fcvtpu64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtpu_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu_sisd32h.Rd = Rd;
    insn.fcvtpu_sisd32h.Rn = Rn;
    insn.fcvtpu_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtpu_sisd32h.opcode = 0b011;
    insn.fcvtpu_sisd32h.rmode = 0b10;
    insn.fcvtpu_sisd32h._unnamed_2 = 0b1;
    insn.fcvtpu_sisd32h.ftype = 0b11;
    insn.fcvtpu_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtpu_sisd32h.S = 0b0;
    insn.fcvtpu_sisd32h._unnamed_0 = 0b0;
    insn.fcvtpu_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtpu_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu_sisd64h.Rd = Rd;
    insn.fcvtpu_sisd64h.Rn = Rn;
    insn.fcvtpu_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtpu_sisd64h.opcode = 0b011;
    insn.fcvtpu_sisd64h.rmode = 0b10;
    insn.fcvtpu_sisd64h._unnamed_2 = 0b1;
    insn.fcvtpu_sisd64h.ftype = 0b11;
    insn.fcvtpu_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtpu_sisd64h.S = 0b0;
    insn.fcvtpu_sisd64h._unnamed_0 = 0b0;
    insn.fcvtpu_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtpu_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu_sisd64s.Rd = Rd;
    insn.fcvtpu_sisd64s.Rn = Rn;
    insn.fcvtpu_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtpu_sisd64s.opcode = 0b011;
    insn.fcvtpu_sisd64s.rmode = 0b10;
    insn.fcvtpu_sisd64s._unnamed_2 = 0b1;
    insn.fcvtpu_sisd64s.ftype = 0b00;
    insn.fcvtpu_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtpu_sisd64s.S = 0b0;
    insn.fcvtpu_sisd64s._unnamed_0 = 0b0;
    insn.fcvtpu_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtpu_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtpu_sisd32d.Rd = Rd;
    insn.fcvtpu_sisd32d.Rn = Rn;
    insn.fcvtpu_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtpu_sisd32d.opcode = 0b011;
    insn.fcvtpu_sisd32d.rmode = 0b10;
    insn.fcvtpu_sisd32d._unnamed_2 = 0b1;
    insn.fcvtpu_sisd32d.ftype = 0b01;
    insn.fcvtpu_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtpu_sisd32d.S = 0b0;
    insn.fcvtpu_sisd32d._unnamed_0 = 0b0;
    insn.fcvtpu_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_32h_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs32h_float2fix.Rd = Rd;
    insn.fcvtzs32h_float2fix.Rn = Rn;
    insn.fcvtzs32h_float2fix.scale = scale;
    insn.fcvtzs32h_float2fix.opcode = 0b000;
    insn.fcvtzs32h_float2fix.rmode = 0b11;
    insn.fcvtzs32h_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs32h_float2fix.ftype = 0b11;
    insn.fcvtzs32h_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs32h_float2fix.S = 0b0;
    insn.fcvtzs32h_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs32h_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64h_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs64h_float2fix.Rd = Rd;
    insn.fcvtzs64h_float2fix.Rn = Rn;
    insn.fcvtzs64h_float2fix.scale = scale;
    insn.fcvtzs64h_float2fix.opcode = 0b000;
    insn.fcvtzs64h_float2fix.rmode = 0b11;
    insn.fcvtzs64h_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs64h_float2fix.ftype = 0b11;
    insn.fcvtzs64h_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs64h_float2fix.S = 0b0;
    insn.fcvtzs64h_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs64h_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_32s_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs32s_float2fix.Rd = Rd;
    insn.fcvtzs32s_float2fix.Rn = Rn;
    insn.fcvtzs32s_float2fix.scale = scale;
    insn.fcvtzs32s_float2fix.opcode = 0b000;
    insn.fcvtzs32s_float2fix.rmode = 0b11;
    insn.fcvtzs32s_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs32s_float2fix.ftype = 0b00;
    insn.fcvtzs32s_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs32s_float2fix.S = 0b0;
    insn.fcvtzs32s_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs32s_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64s_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs64s_float2fix.Rd = Rd;
    insn.fcvtzs64s_float2fix.Rn = Rn;
    insn.fcvtzs64s_float2fix.scale = scale;
    insn.fcvtzs64s_float2fix.opcode = 0b000;
    insn.fcvtzs64s_float2fix.rmode = 0b11;
    insn.fcvtzs64s_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs64s_float2fix.ftype = 0b00;
    insn.fcvtzs64s_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs64s_float2fix.S = 0b0;
    insn.fcvtzs64s_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs64s_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_32d_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs32d_float2fix.Rd = Rd;
    insn.fcvtzs32d_float2fix.Rn = Rn;
    insn.fcvtzs32d_float2fix.scale = scale;
    insn.fcvtzs32d_float2fix.opcode = 0b000;
    insn.fcvtzs32d_float2fix.rmode = 0b11;
    insn.fcvtzs32d_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs32d_float2fix.ftype = 0b01;
    insn.fcvtzs32d_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs32d_float2fix.S = 0b0;
    insn.fcvtzs32d_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs32d_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64d_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzs64d_float2fix.Rd = Rd;
    insn.fcvtzs64d_float2fix.Rn = Rn;
    insn.fcvtzs64d_float2fix.scale = scale;
    insn.fcvtzs64d_float2fix.opcode = 0b000;
    insn.fcvtzs64d_float2fix.rmode = 0b11;
    insn.fcvtzs64d_float2fix._unnamed_2 = 0b0;
    insn.fcvtzs64d_float2fix.ftype = 0b01;
    insn.fcvtzs64d_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzs64d_float2fix.S = 0b0;
    insn.fcvtzs64d_float2fix._unnamed_0 = 0b0;
    insn.fcvtzs64d_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs32h_float2int.Rd = Rd;
    insn.fcvtzs32h_float2int.Rn = Rn;
    insn.fcvtzs32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs32h_float2int.opcode = 0b000;
    insn.fcvtzs32h_float2int.rmode = 0b11;
    insn.fcvtzs32h_float2int._unnamed_2 = 0b1;
    insn.fcvtzs32h_float2int.ftype = 0b11;
    insn.fcvtzs32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs32h_float2int.S = 0b0;
    insn.fcvtzs32h_float2int._unnamed_0 = 0b0;
    insn.fcvtzs32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs64h_float2int.Rd = Rd;
    insn.fcvtzs64h_float2int.Rn = Rn;
    insn.fcvtzs64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs64h_float2int.opcode = 0b000;
    insn.fcvtzs64h_float2int.rmode = 0b11;
    insn.fcvtzs64h_float2int._unnamed_2 = 0b1;
    insn.fcvtzs64h_float2int.ftype = 0b11;
    insn.fcvtzs64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs64h_float2int.S = 0b0;
    insn.fcvtzs64h_float2int._unnamed_0 = 0b0;
    insn.fcvtzs64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs32s_float2int.Rd = Rd;
    insn.fcvtzs32s_float2int.Rn = Rn;
    insn.fcvtzs32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs32s_float2int.opcode = 0b000;
    insn.fcvtzs32s_float2int.rmode = 0b11;
    insn.fcvtzs32s_float2int._unnamed_2 = 0b1;
    insn.fcvtzs32s_float2int.ftype = 0b00;
    insn.fcvtzs32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs32s_float2int.S = 0b0;
    insn.fcvtzs32s_float2int._unnamed_0 = 0b0;
    insn.fcvtzs32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs64s_float2int.Rd = Rd;
    insn.fcvtzs64s_float2int.Rn = Rn;
    insn.fcvtzs64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs64s_float2int.opcode = 0b000;
    insn.fcvtzs64s_float2int.rmode = 0b11;
    insn.fcvtzs64s_float2int._unnamed_2 = 0b1;
    insn.fcvtzs64s_float2int.ftype = 0b00;
    insn.fcvtzs64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs64s_float2int.S = 0b0;
    insn.fcvtzs64s_float2int._unnamed_0 = 0b0;
    insn.fcvtzs64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs32d_float2int.Rd = Rd;
    insn.fcvtzs32d_float2int.Rn = Rn;
    insn.fcvtzs32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs32d_float2int.opcode = 0b000;
    insn.fcvtzs32d_float2int.rmode = 0b11;
    insn.fcvtzs32d_float2int._unnamed_2 = 0b1;
    insn.fcvtzs32d_float2int.ftype = 0b01;
    insn.fcvtzs32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs32d_float2int.S = 0b0;
    insn.fcvtzs32d_float2int._unnamed_0 = 0b0;
    insn.fcvtzs32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs64d_float2int.Rd = Rd;
    insn.fcvtzs64d_float2int.Rn = Rn;
    insn.fcvtzs64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtzs64d_float2int.opcode = 0b000;
    insn.fcvtzs64d_float2int.rmode = 0b11;
    insn.fcvtzs64d_float2int._unnamed_2 = 0b1;
    insn.fcvtzs64d_float2int.ftype = 0b01;
    insn.fcvtzs64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtzs64d_float2int.S = 0b0;
    insn.fcvtzs64d_float2int._unnamed_0 = 0b0;
    insn.fcvtzs64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs_sisd32h.Rd = Rd;
    insn.fcvtzs_sisd32h.Rn = Rn;
    insn.fcvtzs_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtzs_sisd32h.opcode = 0b110;
    insn.fcvtzs_sisd32h.rmode = 0b10;
    insn.fcvtzs_sisd32h._unnamed_2 = 0b1;
    insn.fcvtzs_sisd32h.ftype = 0b11;
    insn.fcvtzs_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtzs_sisd32h.S = 0b0;
    insn.fcvtzs_sisd32h._unnamed_0 = 0b0;
    insn.fcvtzs_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzs_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs_sisd64h.Rd = Rd;
    insn.fcvtzs_sisd64h.Rn = Rn;
    insn.fcvtzs_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtzs_sisd64h.opcode = 0b110;
    insn.fcvtzs_sisd64h.rmode = 0b10;
    insn.fcvtzs_sisd64h._unnamed_2 = 0b1;
    insn.fcvtzs_sisd64h.ftype = 0b11;
    insn.fcvtzs_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtzs_sisd64h.S = 0b0;
    insn.fcvtzs_sisd64h._unnamed_0 = 0b0;
    insn.fcvtzs_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs_sisd64s.Rd = Rd;
    insn.fcvtzs_sisd64s.Rn = Rn;
    insn.fcvtzs_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtzs_sisd64s.opcode = 0b110;
    insn.fcvtzs_sisd64s.rmode = 0b10;
    insn.fcvtzs_sisd64s._unnamed_2 = 0b1;
    insn.fcvtzs_sisd64s.ftype = 0b00;
    insn.fcvtzs_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtzs_sisd64s.S = 0b0;
    insn.fcvtzs_sisd64s._unnamed_0 = 0b0;
    insn.fcvtzs_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzs_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzs_sisd32d.Rd = Rd;
    insn.fcvtzs_sisd32d.Rn = Rn;
    insn.fcvtzs_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtzs_sisd32d.opcode = 0b110;
    insn.fcvtzs_sisd32d.rmode = 0b10;
    insn.fcvtzs_sisd32d._unnamed_2 = 0b1;
    insn.fcvtzs_sisd32d.ftype = 0b01;
    insn.fcvtzs_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtzs_sisd32d.S = 0b0;
    insn.fcvtzs_sisd32d._unnamed_0 = 0b0;
    insn.fcvtzs_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_32h_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu32h_float2fix.Rd = Rd;
    insn.fcvtzu32h_float2fix.Rn = Rn;
    insn.fcvtzu32h_float2fix.scale = scale;
    insn.fcvtzu32h_float2fix.opcode = 0b001;
    insn.fcvtzu32h_float2fix.rmode = 0b11;
    insn.fcvtzu32h_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu32h_float2fix.ftype = 0b11;
    insn.fcvtzu32h_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu32h_float2fix.S = 0b0;
    insn.fcvtzu32h_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu32h_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64h_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu64h_float2fix.Rd = Rd;
    insn.fcvtzu64h_float2fix.Rn = Rn;
    insn.fcvtzu64h_float2fix.scale = scale;
    insn.fcvtzu64h_float2fix.opcode = 0b001;
    insn.fcvtzu64h_float2fix.rmode = 0b11;
    insn.fcvtzu64h_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu64h_float2fix.ftype = 0b11;
    insn.fcvtzu64h_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu64h_float2fix.S = 0b0;
    insn.fcvtzu64h_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu64h_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_32s_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu32s_float2fix.Rd = Rd;
    insn.fcvtzu32s_float2fix.Rn = Rn;
    insn.fcvtzu32s_float2fix.scale = scale;
    insn.fcvtzu32s_float2fix.opcode = 0b001;
    insn.fcvtzu32s_float2fix.rmode = 0b11;
    insn.fcvtzu32s_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu32s_float2fix.ftype = 0b00;
    insn.fcvtzu32s_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu32s_float2fix.S = 0b0;
    insn.fcvtzu32s_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu32s_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64s_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu64s_float2fix.Rd = Rd;
    insn.fcvtzu64s_float2fix.Rn = Rn;
    insn.fcvtzu64s_float2fix.scale = scale;
    insn.fcvtzu64s_float2fix.opcode = 0b001;
    insn.fcvtzu64s_float2fix.rmode = 0b11;
    insn.fcvtzu64s_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu64s_float2fix.ftype = 0b00;
    insn.fcvtzu64s_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu64s_float2fix.S = 0b0;
    insn.fcvtzu64s_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu64s_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_32d_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu32d_float2fix.Rd = Rd;
    insn.fcvtzu32d_float2fix.Rn = Rn;
    insn.fcvtzu32d_float2fix.scale = scale;
    insn.fcvtzu32d_float2fix.opcode = 0b001;
    insn.fcvtzu32d_float2fix.rmode = 0b11;
    insn.fcvtzu32d_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu32d_float2fix.ftype = 0b01;
    insn.fcvtzu32d_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu32d_float2fix.S = 0b0;
    insn.fcvtzu32d_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu32d_float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64d_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.fcvtzu64d_float2fix.Rd = Rd;
    insn.fcvtzu64d_float2fix.Rn = Rn;
    insn.fcvtzu64d_float2fix.scale = scale;
    insn.fcvtzu64d_float2fix.opcode = 0b001;
    insn.fcvtzu64d_float2fix.rmode = 0b11;
    insn.fcvtzu64d_float2fix._unnamed_2 = 0b0;
    insn.fcvtzu64d_float2fix.ftype = 0b01;
    insn.fcvtzu64d_float2fix._unnamed_1 = 0b11110;
    insn.fcvtzu64d_float2fix.S = 0b0;
    insn.fcvtzu64d_float2fix._unnamed_0 = 0b0;
    insn.fcvtzu64d_float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu32h_float2int.Rd = Rd;
    insn.fcvtzu32h_float2int.Rn = Rn;
    insn.fcvtzu32h_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu32h_float2int.opcode = 0b001;
    insn.fcvtzu32h_float2int.rmode = 0b11;
    insn.fcvtzu32h_float2int._unnamed_2 = 0b1;
    insn.fcvtzu32h_float2int.ftype = 0b11;
    insn.fcvtzu32h_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu32h_float2int.S = 0b0;
    insn.fcvtzu32h_float2int._unnamed_0 = 0b0;
    insn.fcvtzu32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu64h_float2int.Rd = Rd;
    insn.fcvtzu64h_float2int.Rn = Rn;
    insn.fcvtzu64h_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu64h_float2int.opcode = 0b001;
    insn.fcvtzu64h_float2int.rmode = 0b11;
    insn.fcvtzu64h_float2int._unnamed_2 = 0b1;
    insn.fcvtzu64h_float2int.ftype = 0b11;
    insn.fcvtzu64h_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu64h_float2int.S = 0b0;
    insn.fcvtzu64h_float2int._unnamed_0 = 0b0;
    insn.fcvtzu64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu32s_float2int.Rd = Rd;
    insn.fcvtzu32s_float2int.Rn = Rn;
    insn.fcvtzu32s_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu32s_float2int.opcode = 0b001;
    insn.fcvtzu32s_float2int.rmode = 0b11;
    insn.fcvtzu32s_float2int._unnamed_2 = 0b1;
    insn.fcvtzu32s_float2int.ftype = 0b00;
    insn.fcvtzu32s_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu32s_float2int.S = 0b0;
    insn.fcvtzu32s_float2int._unnamed_0 = 0b0;
    insn.fcvtzu32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu64s_float2int.Rd = Rd;
    insn.fcvtzu64s_float2int.Rn = Rn;
    insn.fcvtzu64s_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu64s_float2int.opcode = 0b001;
    insn.fcvtzu64s_float2int.rmode = 0b11;
    insn.fcvtzu64s_float2int._unnamed_2 = 0b1;
    insn.fcvtzu64s_float2int.ftype = 0b00;
    insn.fcvtzu64s_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu64s_float2int.S = 0b0;
    insn.fcvtzu64s_float2int._unnamed_0 = 0b0;
    insn.fcvtzu64s_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu32d_float2int.Rd = Rd;
    insn.fcvtzu32d_float2int.Rn = Rn;
    insn.fcvtzu32d_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu32d_float2int.opcode = 0b001;
    insn.fcvtzu32d_float2int.rmode = 0b11;
    insn.fcvtzu32d_float2int._unnamed_2 = 0b1;
    insn.fcvtzu32d_float2int.ftype = 0b01;
    insn.fcvtzu32d_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu32d_float2int.S = 0b0;
    insn.fcvtzu32d_float2int._unnamed_0 = 0b0;
    insn.fcvtzu32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu64d_float2int.Rd = Rd;
    insn.fcvtzu64d_float2int.Rn = Rn;
    insn.fcvtzu64d_float2int._unnamed_3 = 0b000000;
    insn.fcvtzu64d_float2int.opcode = 0b001;
    insn.fcvtzu64d_float2int.rmode = 0b11;
    insn.fcvtzu64d_float2int._unnamed_2 = 0b1;
    insn.fcvtzu64d_float2int.ftype = 0b01;
    insn.fcvtzu64d_float2int._unnamed_1 = 0b11110;
    insn.fcvtzu64d_float2int.S = 0b0;
    insn.fcvtzu64d_float2int._unnamed_0 = 0b0;
    insn.fcvtzu64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu_sisd32h.Rd = Rd;
    insn.fcvtzu_sisd32h.Rn = Rn;
    insn.fcvtzu_sisd32h._unnamed_3 = 0b000000;
    insn.fcvtzu_sisd32h.opcode = 0b111;
    insn.fcvtzu_sisd32h.rmode = 0b10;
    insn.fcvtzu_sisd32h._unnamed_2 = 0b1;
    insn.fcvtzu_sisd32h.ftype = 0b11;
    insn.fcvtzu_sisd32h._unnamed_1 = 0b11110;
    insn.fcvtzu_sisd32h.S = 0b0;
    insn.fcvtzu_sisd32h._unnamed_0 = 0b0;
    insn.fcvtzu_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fcvtzu_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu_sisd64h.Rd = Rd;
    insn.fcvtzu_sisd64h.Rn = Rn;
    insn.fcvtzu_sisd64h._unnamed_3 = 0b000000;
    insn.fcvtzu_sisd64h.opcode = 0b111;
    insn.fcvtzu_sisd64h.rmode = 0b10;
    insn.fcvtzu_sisd64h._unnamed_2 = 0b1;
    insn.fcvtzu_sisd64h.ftype = 0b11;
    insn.fcvtzu_sisd64h._unnamed_1 = 0b11110;
    insn.fcvtzu_sisd64h.S = 0b0;
    insn.fcvtzu_sisd64h._unnamed_0 = 0b0;
    insn.fcvtzu_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu_sisd64s.Rd = Rd;
    insn.fcvtzu_sisd64s.Rn = Rn;
    insn.fcvtzu_sisd64s._unnamed_3 = 0b000000;
    insn.fcvtzu_sisd64s.opcode = 0b111;
    insn.fcvtzu_sisd64s.rmode = 0b10;
    insn.fcvtzu_sisd64s._unnamed_2 = 0b1;
    insn.fcvtzu_sisd64s.ftype = 0b00;
    insn.fcvtzu_sisd64s._unnamed_1 = 0b11110;
    insn.fcvtzu_sisd64s.S = 0b0;
    insn.fcvtzu_sisd64s._unnamed_0 = 0b0;
    insn.fcvtzu_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fcvtzu_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fcvtzu_sisd32d.Rd = Rd;
    insn.fcvtzu_sisd32d.Rn = Rn;
    insn.fcvtzu_sisd32d._unnamed_3 = 0b000000;
    insn.fcvtzu_sisd32d.opcode = 0b111;
    insn.fcvtzu_sisd32d.rmode = 0b10;
    insn.fcvtzu_sisd32d._unnamed_2 = 0b1;
    insn.fcvtzu_sisd32d.ftype = 0b01;
    insn.fcvtzu_sisd32d._unnamed_1 = 0b11110;
    insn.fcvtzu_sisd32d.S = 0b0;
    insn.fcvtzu_sisd32d._unnamed_0 = 0b0;
    insn.fcvtzu_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fdiv_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fdiv_hfloatdp2.Rd = Rd;
    insn.fdiv_hfloatdp2.Rn = Rn;
    insn.fdiv_hfloatdp2._unnamed_3 = 0b10;
    insn.fdiv_hfloatdp2.opcode = 0b0001;
    insn.fdiv_hfloatdp2.Rm = Rm;
    insn.fdiv_hfloatdp2._unnamed_2 = 0b1;
    insn.fdiv_hfloatdp2.ftype = 0b11;
    insn.fdiv_hfloatdp2._unnamed_1 = 0b11110;
    insn.fdiv_hfloatdp2.S = 0b0;
    insn.fdiv_hfloatdp2._unnamed_0 = 0b0;
    insn.fdiv_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fdiv_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fdiv_sfloatdp2.Rd = Rd;
    insn.fdiv_sfloatdp2.Rn = Rn;
    insn.fdiv_sfloatdp2._unnamed_3 = 0b10;
    insn.fdiv_sfloatdp2.opcode = 0b0001;
    insn.fdiv_sfloatdp2.Rm = Rm;
    insn.fdiv_sfloatdp2._unnamed_2 = 0b1;
    insn.fdiv_sfloatdp2.ftype = 0b00;
    insn.fdiv_sfloatdp2._unnamed_1 = 0b11110;
    insn.fdiv_sfloatdp2.S = 0b0;
    insn.fdiv_sfloatdp2._unnamed_0 = 0b0;
    insn.fdiv_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fdiv_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fdiv_dfloatdp2.Rd = Rd;
    insn.fdiv_dfloatdp2.Rn = Rn;
    insn.fdiv_dfloatdp2._unnamed_3 = 0b10;
    insn.fdiv_dfloatdp2.opcode = 0b0001;
    insn.fdiv_dfloatdp2.Rm = Rm;
    insn.fdiv_dfloatdp2._unnamed_2 = 0b1;
    insn.fdiv_dfloatdp2.ftype = 0b01;
    insn.fdiv_dfloatdp2._unnamed_1 = 0b11110;
    insn.fdiv_dfloatdp2.S = 0b0;
    insn.fdiv_dfloatdp2._unnamed_0 = 0b0;
    insn.fdiv_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fjcvtzs_32d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fjcvtzs32d_float2int.Rd = Rd;
    insn.fjcvtzs32d_float2int.Rn = Rn;
    insn.fjcvtzs32d_float2int._unnamed_5 = 0b000000;
    insn.fjcvtzs32d_float2int.opcode = 0b110;
    insn.fjcvtzs32d_float2int.rmode = 0b11;
    insn.fjcvtzs32d_float2int._unnamed_4 = 0b1;
    insn.fjcvtzs32d_float2int.ftype = 0b01;
    insn.fjcvtzs32d_float2int._unnamed_3 = 0b0;
    insn.fjcvtzs32d_float2int._unnamed_2 = 0b111;
    insn.fjcvtzs32d_float2int._unnamed_1 = 0b1;
    insn.fjcvtzs32d_float2int.S = 0b0;
    insn.fjcvtzs32d_float2int._unnamed_0 = 0b0;
    insn.fjcvtzs32d_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fmadd_h_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmadd_hfloatdp3.Rd = Rd;
    insn.fmadd_hfloatdp3.Rn = Rn;
    insn.fmadd_hfloatdp3.Ra = Ra;
    insn.fmadd_hfloatdp3.o0 = 0b0;
    insn.fmadd_hfloatdp3.Rm = Rm;
    insn.fmadd_hfloatdp3.o1 = 0b0;
    insn.fmadd_hfloatdp3.ftype = 0b11;
    insn.fmadd_hfloatdp3._unnamed_1 = 0b11111;
    insn.fmadd_hfloatdp3.S = 0b0;
    insn.fmadd_hfloatdp3._unnamed_0 = 0b0;
    insn.fmadd_hfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmadd_s_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmadd_sfloatdp3.Rd = Rd;
    insn.fmadd_sfloatdp3.Rn = Rn;
    insn.fmadd_sfloatdp3.Ra = Ra;
    insn.fmadd_sfloatdp3.o0 = 0b0;
    insn.fmadd_sfloatdp3.Rm = Rm;
    insn.fmadd_sfloatdp3.o1 = 0b0;
    insn.fmadd_sfloatdp3.ftype = 0b00;
    insn.fmadd_sfloatdp3._unnamed_1 = 0b11111;
    insn.fmadd_sfloatdp3.S = 0b0;
    insn.fmadd_sfloatdp3._unnamed_0 = 0b0;
    insn.fmadd_sfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmadd_d_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmadd_dfloatdp3.Rd = Rd;
    insn.fmadd_dfloatdp3.Rn = Rn;
    insn.fmadd_dfloatdp3.Ra = Ra;
    insn.fmadd_dfloatdp3.o0 = 0b0;
    insn.fmadd_dfloatdp3.Rm = Rm;
    insn.fmadd_dfloatdp3.o1 = 0b0;
    insn.fmadd_dfloatdp3.ftype = 0b01;
    insn.fmadd_dfloatdp3._unnamed_1 = 0b11111;
    insn.fmadd_dfloatdp3.S = 0b0;
    insn.fmadd_dfloatdp3._unnamed_0 = 0b0;
    insn.fmadd_dfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmax_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmax_hfloatdp2.Rd = Rd;
    insn.fmax_hfloatdp2.Rn = Rn;
    insn.fmax_hfloatdp2._unnamed_4 = 0b10;
    insn.fmax_hfloatdp2.op = 0b00;
    insn.fmax_hfloatdp2._unnamed_3 = 0b01;
    insn.fmax_hfloatdp2.Rm = Rm;
    insn.fmax_hfloatdp2._unnamed_2 = 0b1;
    insn.fmax_hfloatdp2.ftype = 0b11;
    insn.fmax_hfloatdp2._unnamed_1 = 0b11110;
    insn.fmax_hfloatdp2.S = 0b0;
    insn.fmax_hfloatdp2._unnamed_0 = 0b0;
    insn.fmax_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmax_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmax_sfloatdp2.Rd = Rd;
    insn.fmax_sfloatdp2.Rn = Rn;
    insn.fmax_sfloatdp2._unnamed_4 = 0b10;
    insn.fmax_sfloatdp2.op = 0b00;
    insn.fmax_sfloatdp2._unnamed_3 = 0b01;
    insn.fmax_sfloatdp2.Rm = Rm;
    insn.fmax_sfloatdp2._unnamed_2 = 0b1;
    insn.fmax_sfloatdp2.ftype = 0b00;
    insn.fmax_sfloatdp2._unnamed_1 = 0b11110;
    insn.fmax_sfloatdp2.S = 0b0;
    insn.fmax_sfloatdp2._unnamed_0 = 0b0;
    insn.fmax_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmax_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmax_dfloatdp2.Rd = Rd;
    insn.fmax_dfloatdp2.Rn = Rn;
    insn.fmax_dfloatdp2._unnamed_4 = 0b10;
    insn.fmax_dfloatdp2.op = 0b00;
    insn.fmax_dfloatdp2._unnamed_3 = 0b01;
    insn.fmax_dfloatdp2.Rm = Rm;
    insn.fmax_dfloatdp2._unnamed_2 = 0b1;
    insn.fmax_dfloatdp2.ftype = 0b01;
    insn.fmax_dfloatdp2._unnamed_1 = 0b11110;
    insn.fmax_dfloatdp2.S = 0b0;
    insn.fmax_dfloatdp2._unnamed_0 = 0b0;
    insn.fmax_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmaxnm_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmaxnm_hfloatdp2.Rd = Rd;
    insn.fmaxnm_hfloatdp2.Rn = Rn;
    insn.fmaxnm_hfloatdp2._unnamed_4 = 0b10;
    insn.fmaxnm_hfloatdp2.op = 0b10;
    insn.fmaxnm_hfloatdp2._unnamed_3 = 0b01;
    insn.fmaxnm_hfloatdp2.Rm = Rm;
    insn.fmaxnm_hfloatdp2._unnamed_2 = 0b1;
    insn.fmaxnm_hfloatdp2.ftype = 0b11;
    insn.fmaxnm_hfloatdp2._unnamed_1 = 0b11110;
    insn.fmaxnm_hfloatdp2.S = 0b0;
    insn.fmaxnm_hfloatdp2._unnamed_0 = 0b0;
    insn.fmaxnm_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmaxnm_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmaxnm_sfloatdp2.Rd = Rd;
    insn.fmaxnm_sfloatdp2.Rn = Rn;
    insn.fmaxnm_sfloatdp2._unnamed_4 = 0b10;
    insn.fmaxnm_sfloatdp2.op = 0b10;
    insn.fmaxnm_sfloatdp2._unnamed_3 = 0b01;
    insn.fmaxnm_sfloatdp2.Rm = Rm;
    insn.fmaxnm_sfloatdp2._unnamed_2 = 0b1;
    insn.fmaxnm_sfloatdp2.ftype = 0b00;
    insn.fmaxnm_sfloatdp2._unnamed_1 = 0b11110;
    insn.fmaxnm_sfloatdp2.S = 0b0;
    insn.fmaxnm_sfloatdp2._unnamed_0 = 0b0;
    insn.fmaxnm_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmaxnm_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmaxnm_dfloatdp2.Rd = Rd;
    insn.fmaxnm_dfloatdp2.Rn = Rn;
    insn.fmaxnm_dfloatdp2._unnamed_4 = 0b10;
    insn.fmaxnm_dfloatdp2.op = 0b10;
    insn.fmaxnm_dfloatdp2._unnamed_3 = 0b01;
    insn.fmaxnm_dfloatdp2.Rm = Rm;
    insn.fmaxnm_dfloatdp2._unnamed_2 = 0b1;
    insn.fmaxnm_dfloatdp2.ftype = 0b01;
    insn.fmaxnm_dfloatdp2._unnamed_1 = 0b11110;
    insn.fmaxnm_dfloatdp2.S = 0b0;
    insn.fmaxnm_dfloatdp2._unnamed_0 = 0b0;
    insn.fmaxnm_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmin_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmin_hfloatdp2.Rd = Rd;
    insn.fmin_hfloatdp2.Rn = Rn;
    insn.fmin_hfloatdp2._unnamed_4 = 0b10;
    insn.fmin_hfloatdp2.op = 0b01;
    insn.fmin_hfloatdp2._unnamed_3 = 0b01;
    insn.fmin_hfloatdp2.Rm = Rm;
    insn.fmin_hfloatdp2._unnamed_2 = 0b1;
    insn.fmin_hfloatdp2.ftype = 0b11;
    insn.fmin_hfloatdp2._unnamed_1 = 0b11110;
    insn.fmin_hfloatdp2.S = 0b0;
    insn.fmin_hfloatdp2._unnamed_0 = 0b0;
    insn.fmin_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmin_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmin_sfloatdp2.Rd = Rd;
    insn.fmin_sfloatdp2.Rn = Rn;
    insn.fmin_sfloatdp2._unnamed_4 = 0b10;
    insn.fmin_sfloatdp2.op = 0b01;
    insn.fmin_sfloatdp2._unnamed_3 = 0b01;
    insn.fmin_sfloatdp2.Rm = Rm;
    insn.fmin_sfloatdp2._unnamed_2 = 0b1;
    insn.fmin_sfloatdp2.ftype = 0b00;
    insn.fmin_sfloatdp2._unnamed_1 = 0b11110;
    insn.fmin_sfloatdp2.S = 0b0;
    insn.fmin_sfloatdp2._unnamed_0 = 0b0;
    insn.fmin_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmin_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmin_dfloatdp2.Rd = Rd;
    insn.fmin_dfloatdp2.Rn = Rn;
    insn.fmin_dfloatdp2._unnamed_4 = 0b10;
    insn.fmin_dfloatdp2.op = 0b01;
    insn.fmin_dfloatdp2._unnamed_3 = 0b01;
    insn.fmin_dfloatdp2.Rm = Rm;
    insn.fmin_dfloatdp2._unnamed_2 = 0b1;
    insn.fmin_dfloatdp2.ftype = 0b01;
    insn.fmin_dfloatdp2._unnamed_1 = 0b11110;
    insn.fmin_dfloatdp2.S = 0b0;
    insn.fmin_dfloatdp2._unnamed_0 = 0b0;
    insn.fmin_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fminnm_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fminnm_hfloatdp2.Rd = Rd;
    insn.fminnm_hfloatdp2.Rn = Rn;
    insn.fminnm_hfloatdp2._unnamed_4 = 0b10;
    insn.fminnm_hfloatdp2.op = 0b11;
    insn.fminnm_hfloatdp2._unnamed_3 = 0b01;
    insn.fminnm_hfloatdp2.Rm = Rm;
    insn.fminnm_hfloatdp2._unnamed_2 = 0b1;
    insn.fminnm_hfloatdp2.ftype = 0b11;
    insn.fminnm_hfloatdp2._unnamed_1 = 0b11110;
    insn.fminnm_hfloatdp2.S = 0b0;
    insn.fminnm_hfloatdp2._unnamed_0 = 0b0;
    insn.fminnm_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fminnm_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fminnm_sfloatdp2.Rd = Rd;
    insn.fminnm_sfloatdp2.Rn = Rn;
    insn.fminnm_sfloatdp2._unnamed_4 = 0b10;
    insn.fminnm_sfloatdp2.op = 0b11;
    insn.fminnm_sfloatdp2._unnamed_3 = 0b01;
    insn.fminnm_sfloatdp2.Rm = Rm;
    insn.fminnm_sfloatdp2._unnamed_2 = 0b1;
    insn.fminnm_sfloatdp2.ftype = 0b00;
    insn.fminnm_sfloatdp2._unnamed_1 = 0b11110;
    insn.fminnm_sfloatdp2.S = 0b0;
    insn.fminnm_sfloatdp2._unnamed_0 = 0b0;
    insn.fminnm_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fminnm_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fminnm_dfloatdp2.Rd = Rd;
    insn.fminnm_dfloatdp2.Rn = Rn;
    insn.fminnm_dfloatdp2._unnamed_4 = 0b10;
    insn.fminnm_dfloatdp2.op = 0b11;
    insn.fminnm_dfloatdp2._unnamed_3 = 0b01;
    insn.fminnm_dfloatdp2.Rm = Rm;
    insn.fminnm_dfloatdp2._unnamed_2 = 0b1;
    insn.fminnm_dfloatdp2.ftype = 0b01;
    insn.fminnm_dfloatdp2._unnamed_1 = 0b11110;
    insn.fminnm_dfloatdp2.S = 0b0;
    insn.fminnm_dfloatdp2._unnamed_0 = 0b0;
    insn.fminnm_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_hfloatdp1.Rd = Rd;
    insn.fmov_hfloatdp1.Rn = Rn;
    insn.fmov_hfloatdp1._unnamed_3 = 0b10000;
    insn.fmov_hfloatdp1.opc = 0b00;
    insn.fmov_hfloatdp1._unnamed_2 = 0b10000;
    insn.fmov_hfloatdp1.ftype = 0b11;
    insn.fmov_hfloatdp1._unnamed_1 = 0b11110;
    insn.fmov_hfloatdp1.S = 0b0;
    insn.fmov_hfloatdp1._unnamed_0 = 0b0;
    insn.fmov_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_sfloatdp1.Rd = Rd;
    insn.fmov_sfloatdp1.Rn = Rn;
    insn.fmov_sfloatdp1._unnamed_3 = 0b10000;
    insn.fmov_sfloatdp1.opc = 0b00;
    insn.fmov_sfloatdp1._unnamed_2 = 0b10000;
    insn.fmov_sfloatdp1.ftype = 0b00;
    insn.fmov_sfloatdp1._unnamed_1 = 0b11110;
    insn.fmov_sfloatdp1.S = 0b0;
    insn.fmov_sfloatdp1._unnamed_0 = 0b0;
    insn.fmov_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_dfloatdp1.Rd = Rd;
    insn.fmov_dfloatdp1.Rn = Rn;
    insn.fmov_dfloatdp1._unnamed_3 = 0b10000;
    insn.fmov_dfloatdp1.opc = 0b00;
    insn.fmov_dfloatdp1._unnamed_2 = 0b10000;
    insn.fmov_dfloatdp1.ftype = 0b01;
    insn.fmov_dfloatdp1._unnamed_1 = 0b11110;
    insn.fmov_dfloatdp1.S = 0b0;
    insn.fmov_dfloatdp1._unnamed_0 = 0b0;
    insn.fmov_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_32h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov32h_float2int.Rd = Rd;
    insn.fmov32h_float2int.Rn = Rn;
    insn.fmov32h_float2int._unnamed_3 = 0b000000;
    insn.fmov32h_float2int.opcode = 0b110;
    insn.fmov32h_float2int.rmode = 0b00;
    insn.fmov32h_float2int._unnamed_2 = 0b1;
    insn.fmov32h_float2int.ftype = 0b11;
    insn.fmov32h_float2int._unnamed_1 = 0b11110;
    insn.fmov32h_float2int.S = 0b0;
    insn.fmov32h_float2int._unnamed_0 = 0b0;
    insn.fmov32h_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_64h_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov64h_float2int.Rd = Rd;
    insn.fmov64h_float2int.Rn = Rn;
    insn.fmov64h_float2int._unnamed_3 = 0b000000;
    insn.fmov64h_float2int.opcode = 0b110;
    insn.fmov64h_float2int.rmode = 0b00;
    insn.fmov64h_float2int._unnamed_2 = 0b1;
    insn.fmov64h_float2int.ftype = 0b11;
    insn.fmov64h_float2int._unnamed_1 = 0b11110;
    insn.fmov64h_float2int.S = 0b0;
    insn.fmov64h_float2int._unnamed_0 = 0b0;
    insn.fmov64h_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_h32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_h32float2int.Rd = Rd;
    insn.fmov_h32float2int.Rn = Rn;
    insn.fmov_h32float2int._unnamed_3 = 0b000000;
    insn.fmov_h32float2int.opcode = 0b111;
    insn.fmov_h32float2int.rmode = 0b00;
    insn.fmov_h32float2int._unnamed_2 = 0b1;
    insn.fmov_h32float2int.ftype = 0b11;
    insn.fmov_h32float2int._unnamed_1 = 0b11110;
    insn.fmov_h32float2int.S = 0b0;
    insn.fmov_h32float2int._unnamed_0 = 0b0;
    insn.fmov_h32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_s32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_s32float2int.Rd = Rd;
    insn.fmov_s32float2int.Rn = Rn;
    insn.fmov_s32float2int._unnamed_3 = 0b000000;
    insn.fmov_s32float2int.opcode = 0b111;
    insn.fmov_s32float2int.rmode = 0b00;
    insn.fmov_s32float2int._unnamed_2 = 0b1;
    insn.fmov_s32float2int.ftype = 0b00;
    insn.fmov_s32float2int._unnamed_1 = 0b11110;
    insn.fmov_s32float2int.S = 0b0;
    insn.fmov_s32float2int._unnamed_0 = 0b0;
    insn.fmov_s32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_32s_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov32s_float2int.Rd = Rd;
    insn.fmov32s_float2int.Rn = Rn;
    insn.fmov32s_float2int._unnamed_3 = 0b000000;
    insn.fmov32s_float2int.opcode = 0b110;
    insn.fmov32s_float2int.rmode = 0b00;
    insn.fmov32s_float2int._unnamed_2 = 0b1;
    insn.fmov32s_float2int.ftype = 0b00;
    insn.fmov32s_float2int._unnamed_1 = 0b11110;
    insn.fmov32s_float2int.S = 0b0;
    insn.fmov32s_float2int._unnamed_0 = 0b0;
    insn.fmov32s_float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_h64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_h64float2int.Rd = Rd;
    insn.fmov_h64float2int.Rn = Rn;
    insn.fmov_h64float2int._unnamed_3 = 0b000000;
    insn.fmov_h64float2int.opcode = 0b111;
    insn.fmov_h64float2int.rmode = 0b00;
    insn.fmov_h64float2int._unnamed_2 = 0b1;
    insn.fmov_h64float2int.ftype = 0b11;
    insn.fmov_h64float2int._unnamed_1 = 0b11110;
    insn.fmov_h64float2int.S = 0b0;
    insn.fmov_h64float2int._unnamed_0 = 0b0;
    insn.fmov_h64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_d64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_d64float2int.Rd = Rd;
    insn.fmov_d64float2int.Rn = Rn;
    insn.fmov_d64float2int._unnamed_3 = 0b000000;
    insn.fmov_d64float2int.opcode = 0b111;
    insn.fmov_d64float2int.rmode = 0b00;
    insn.fmov_d64float2int._unnamed_2 = 0b1;
    insn.fmov_d64float2int.ftype = 0b01;
    insn.fmov_d64float2int._unnamed_1 = 0b11110;
    insn.fmov_d64float2int.S = 0b0;
    insn.fmov_d64float2int._unnamed_0 = 0b0;
    insn.fmov_d64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_v64i_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov_v64i_float2int.Rd = Rd;
    insn.fmov_v64i_float2int.Rn = Rn;
    insn.fmov_v64i_float2int._unnamed_3 = 0b000000;
    insn.fmov_v64i_float2int.opcode = 0b111;
    insn.fmov_v64i_float2int.rmode = 0b01;
    insn.fmov_v64i_float2int._unnamed_2 = 0b1;
    insn.fmov_v64i_float2int.ftype = 0b10;
    insn.fmov_v64i_float2int._unnamed_1 = 0b11110;
    insn.fmov_v64i_float2int.S = 0b0;
    insn.fmov_v64i_float2int._unnamed_0 = 0b0;
    insn.fmov_v64i_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_64d_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov64d_float2int.Rd = Rd;
    insn.fmov64d_float2int.Rn = Rn;
    insn.fmov64d_float2int._unnamed_3 = 0b000000;
    insn.fmov64d_float2int.opcode = 0b110;
    insn.fmov64d_float2int.rmode = 0b00;
    insn.fmov64d_float2int._unnamed_2 = 0b1;
    insn.fmov64d_float2int.ftype = 0b01;
    insn.fmov64d_float2int._unnamed_1 = 0b11110;
    insn.fmov64d_float2int.S = 0b0;
    insn.fmov64d_float2int._unnamed_0 = 0b0;
    insn.fmov64d_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_64vx_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fmov64vx_float2int.Rd = Rd;
    insn.fmov64vx_float2int.Rn = Rn;
    insn.fmov64vx_float2int._unnamed_3 = 0b000000;
    insn.fmov64vx_float2int.opcode = 0b110;
    insn.fmov64vx_float2int.rmode = 0b01;
    insn.fmov64vx_float2int._unnamed_2 = 0b1;
    insn.fmov64vx_float2int.ftype = 0b10;
    insn.fmov64vx_float2int._unnamed_1 = 0b11110;
    insn.fmov64vx_float2int.S = 0b0;
    insn.fmov64vx_float2int._unnamed_0 = 0b0;
    insn.fmov64vx_float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_fmov_h_floatimm(uint32_t Rd, uint32_t imm8) {
    FloatEncoding insn = {};
    insn.fmov_hfloatimm.Rd = Rd;
    insn.fmov_hfloatimm.imm5 = 0b00000;
    insn.fmov_hfloatimm._unnamed_3 = 0b100;
    insn.fmov_hfloatimm.imm8 = imm8;
    insn.fmov_hfloatimm._unnamed_2 = 0b1;
    insn.fmov_hfloatimm.ftype = 0b11;
    insn.fmov_hfloatimm._unnamed_1 = 0b11110;
    insn.fmov_hfloatimm.S = 0b0;
    insn.fmov_hfloatimm._unnamed_0 = 0b0;
    insn.fmov_hfloatimm.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_s_floatimm(uint32_t Rd, uint32_t imm8) {
    FloatEncoding insn = {};
    insn.fmov_sfloatimm.Rd = Rd;
    insn.fmov_sfloatimm.imm5 = 0b00000;
    insn.fmov_sfloatimm._unnamed_3 = 0b100;
    insn.fmov_sfloatimm.imm8 = imm8;
    insn.fmov_sfloatimm._unnamed_2 = 0b1;
    insn.fmov_sfloatimm.ftype = 0b00;
    insn.fmov_sfloatimm._unnamed_1 = 0b11110;
    insn.fmov_sfloatimm.S = 0b0;
    insn.fmov_sfloatimm._unnamed_0 = 0b0;
    insn.fmov_sfloatimm.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmov_d_floatimm(uint32_t Rd, uint32_t imm8) {
    FloatEncoding insn = {};
    insn.fmov_dfloatimm.Rd = Rd;
    insn.fmov_dfloatimm.imm5 = 0b00000;
    insn.fmov_dfloatimm._unnamed_3 = 0b100;
    insn.fmov_dfloatimm.imm8 = imm8;
    insn.fmov_dfloatimm._unnamed_2 = 0b1;
    insn.fmov_dfloatimm.ftype = 0b01;
    insn.fmov_dfloatimm._unnamed_1 = 0b11110;
    insn.fmov_dfloatimm.S = 0b0;
    insn.fmov_dfloatimm._unnamed_0 = 0b0;
    insn.fmov_dfloatimm.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmsub_h_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmsub_hfloatdp3.Rd = Rd;
    insn.fmsub_hfloatdp3.Rn = Rn;
    insn.fmsub_hfloatdp3.Ra = Ra;
    insn.fmsub_hfloatdp3.o0 = 0b1;
    insn.fmsub_hfloatdp3.Rm = Rm;
    insn.fmsub_hfloatdp3.o1 = 0b0;
    insn.fmsub_hfloatdp3.ftype = 0b11;
    insn.fmsub_hfloatdp3._unnamed_1 = 0b11111;
    insn.fmsub_hfloatdp3.S = 0b0;
    insn.fmsub_hfloatdp3._unnamed_0 = 0b0;
    insn.fmsub_hfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmsub_s_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmsub_sfloatdp3.Rd = Rd;
    insn.fmsub_sfloatdp3.Rn = Rn;
    insn.fmsub_sfloatdp3.Ra = Ra;
    insn.fmsub_sfloatdp3.o0 = 0b1;
    insn.fmsub_sfloatdp3.Rm = Rm;
    insn.fmsub_sfloatdp3.o1 = 0b0;
    insn.fmsub_sfloatdp3.ftype = 0b00;
    insn.fmsub_sfloatdp3._unnamed_1 = 0b11111;
    insn.fmsub_sfloatdp3.S = 0b0;
    insn.fmsub_sfloatdp3._unnamed_0 = 0b0;
    insn.fmsub_sfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmsub_d_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmsub_dfloatdp3.Rd = Rd;
    insn.fmsub_dfloatdp3.Rn = Rn;
    insn.fmsub_dfloatdp3.Ra = Ra;
    insn.fmsub_dfloatdp3.o0 = 0b1;
    insn.fmsub_dfloatdp3.Rm = Rm;
    insn.fmsub_dfloatdp3.o1 = 0b0;
    insn.fmsub_dfloatdp3.ftype = 0b01;
    insn.fmsub_dfloatdp3._unnamed_1 = 0b11111;
    insn.fmsub_dfloatdp3.S = 0b0;
    insn.fmsub_dfloatdp3._unnamed_0 = 0b0;
    insn.fmsub_dfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmul_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmul_hfloatdp2.Rd = Rd;
    insn.fmul_hfloatdp2.Rn = Rn;
    insn.fmul_hfloatdp2._unnamed_3 = 0b00010;
    insn.fmul_hfloatdp2.op = 0b0;
    insn.fmul_hfloatdp2.Rm = Rm;
    insn.fmul_hfloatdp2._unnamed_2 = 0b1;
    insn.fmul_hfloatdp2.ftype = 0b11;
    insn.fmul_hfloatdp2._unnamed_1 = 0b11110;
    insn.fmul_hfloatdp2.S = 0b0;
    insn.fmul_hfloatdp2._unnamed_0 = 0b0;
    insn.fmul_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmul_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmul_sfloatdp2.Rd = Rd;
    insn.fmul_sfloatdp2.Rn = Rn;
    insn.fmul_sfloatdp2._unnamed_3 = 0b00010;
    insn.fmul_sfloatdp2.op = 0b0;
    insn.fmul_sfloatdp2.Rm = Rm;
    insn.fmul_sfloatdp2._unnamed_2 = 0b1;
    insn.fmul_sfloatdp2.ftype = 0b00;
    insn.fmul_sfloatdp2._unnamed_1 = 0b11110;
    insn.fmul_sfloatdp2.S = 0b0;
    insn.fmul_sfloatdp2._unnamed_0 = 0b0;
    insn.fmul_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fmul_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fmul_dfloatdp2.Rd = Rd;
    insn.fmul_dfloatdp2.Rn = Rn;
    insn.fmul_dfloatdp2._unnamed_3 = 0b00010;
    insn.fmul_dfloatdp2.op = 0b0;
    insn.fmul_dfloatdp2.Rm = Rm;
    insn.fmul_dfloatdp2._unnamed_2 = 0b1;
    insn.fmul_dfloatdp2.ftype = 0b01;
    insn.fmul_dfloatdp2._unnamed_1 = 0b11110;
    insn.fmul_dfloatdp2.S = 0b0;
    insn.fmul_dfloatdp2._unnamed_0 = 0b0;
    insn.fmul_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fneg_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fneg_hfloatdp1.Rd = Rd;
    insn.fneg_hfloatdp1.Rn = Rn;
    insn.fneg_hfloatdp1._unnamed_3 = 0b10000;
    insn.fneg_hfloatdp1.opc = 0b10;
    insn.fneg_hfloatdp1._unnamed_2 = 0b10000;
    insn.fneg_hfloatdp1.ftype = 0b11;
    insn.fneg_hfloatdp1._unnamed_1 = 0b11110;
    insn.fneg_hfloatdp1.S = 0b0;
    insn.fneg_hfloatdp1._unnamed_0 = 0b0;
    insn.fneg_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fneg_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fneg_sfloatdp1.Rd = Rd;
    insn.fneg_sfloatdp1.Rn = Rn;
    insn.fneg_sfloatdp1._unnamed_3 = 0b10000;
    insn.fneg_sfloatdp1.opc = 0b10;
    insn.fneg_sfloatdp1._unnamed_2 = 0b10000;
    insn.fneg_sfloatdp1.ftype = 0b00;
    insn.fneg_sfloatdp1._unnamed_1 = 0b11110;
    insn.fneg_sfloatdp1.S = 0b0;
    insn.fneg_sfloatdp1._unnamed_0 = 0b0;
    insn.fneg_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fneg_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fneg_dfloatdp1.Rd = Rd;
    insn.fneg_dfloatdp1.Rn = Rn;
    insn.fneg_dfloatdp1._unnamed_3 = 0b10000;
    insn.fneg_dfloatdp1.opc = 0b10;
    insn.fneg_dfloatdp1._unnamed_2 = 0b10000;
    insn.fneg_dfloatdp1.ftype = 0b01;
    insn.fneg_dfloatdp1._unnamed_1 = 0b11110;
    insn.fneg_dfloatdp1.S = 0b0;
    insn.fneg_dfloatdp1._unnamed_0 = 0b0;
    insn.fneg_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmadd_h_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmadd_hfloatdp3.Rd = Rd;
    insn.fnmadd_hfloatdp3.Rn = Rn;
    insn.fnmadd_hfloatdp3.Ra = Ra;
    insn.fnmadd_hfloatdp3.o0 = 0b0;
    insn.fnmadd_hfloatdp3.Rm = Rm;
    insn.fnmadd_hfloatdp3.o1 = 0b1;
    insn.fnmadd_hfloatdp3.ftype = 0b11;
    insn.fnmadd_hfloatdp3._unnamed_1 = 0b11111;
    insn.fnmadd_hfloatdp3.S = 0b0;
    insn.fnmadd_hfloatdp3._unnamed_0 = 0b0;
    insn.fnmadd_hfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmadd_s_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmadd_sfloatdp3.Rd = Rd;
    insn.fnmadd_sfloatdp3.Rn = Rn;
    insn.fnmadd_sfloatdp3.Ra = Ra;
    insn.fnmadd_sfloatdp3.o0 = 0b0;
    insn.fnmadd_sfloatdp3.Rm = Rm;
    insn.fnmadd_sfloatdp3.o1 = 0b1;
    insn.fnmadd_sfloatdp3.ftype = 0b00;
    insn.fnmadd_sfloatdp3._unnamed_1 = 0b11111;
    insn.fnmadd_sfloatdp3.S = 0b0;
    insn.fnmadd_sfloatdp3._unnamed_0 = 0b0;
    insn.fnmadd_sfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmadd_d_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmadd_dfloatdp3.Rd = Rd;
    insn.fnmadd_dfloatdp3.Rn = Rn;
    insn.fnmadd_dfloatdp3.Ra = Ra;
    insn.fnmadd_dfloatdp3.o0 = 0b0;
    insn.fnmadd_dfloatdp3.Rm = Rm;
    insn.fnmadd_dfloatdp3.o1 = 0b1;
    insn.fnmadd_dfloatdp3.ftype = 0b01;
    insn.fnmadd_dfloatdp3._unnamed_1 = 0b11111;
    insn.fnmadd_dfloatdp3.S = 0b0;
    insn.fnmadd_dfloatdp3._unnamed_0 = 0b0;
    insn.fnmadd_dfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmsub_h_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmsub_hfloatdp3.Rd = Rd;
    insn.fnmsub_hfloatdp3.Rn = Rn;
    insn.fnmsub_hfloatdp3.Ra = Ra;
    insn.fnmsub_hfloatdp3.o0 = 0b1;
    insn.fnmsub_hfloatdp3.Rm = Rm;
    insn.fnmsub_hfloatdp3.o1 = 0b1;
    insn.fnmsub_hfloatdp3.ftype = 0b11;
    insn.fnmsub_hfloatdp3._unnamed_1 = 0b11111;
    insn.fnmsub_hfloatdp3.S = 0b0;
    insn.fnmsub_hfloatdp3._unnamed_0 = 0b0;
    insn.fnmsub_hfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmsub_s_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmsub_sfloatdp3.Rd = Rd;
    insn.fnmsub_sfloatdp3.Rn = Rn;
    insn.fnmsub_sfloatdp3.Ra = Ra;
    insn.fnmsub_sfloatdp3.o0 = 0b1;
    insn.fnmsub_sfloatdp3.Rm = Rm;
    insn.fnmsub_sfloatdp3.o1 = 0b1;
    insn.fnmsub_sfloatdp3.ftype = 0b00;
    insn.fnmsub_sfloatdp3._unnamed_1 = 0b11111;
    insn.fnmsub_sfloatdp3.S = 0b0;
    insn.fnmsub_sfloatdp3._unnamed_0 = 0b0;
    insn.fnmsub_sfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmsub_d_floatdp3(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmsub_dfloatdp3.Rd = Rd;
    insn.fnmsub_dfloatdp3.Rn = Rn;
    insn.fnmsub_dfloatdp3.Ra = Ra;
    insn.fnmsub_dfloatdp3.o0 = 0b1;
    insn.fnmsub_dfloatdp3.Rm = Rm;
    insn.fnmsub_dfloatdp3.o1 = 0b1;
    insn.fnmsub_dfloatdp3.ftype = 0b01;
    insn.fnmsub_dfloatdp3._unnamed_1 = 0b11111;
    insn.fnmsub_dfloatdp3.S = 0b0;
    insn.fnmsub_dfloatdp3._unnamed_0 = 0b0;
    insn.fnmsub_dfloatdp3.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmul_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmul_hfloatdp2.Rd = Rd;
    insn.fnmul_hfloatdp2.Rn = Rn;
    insn.fnmul_hfloatdp2._unnamed_3 = 0b00010;
    insn.fnmul_hfloatdp2.op = 0b1;
    insn.fnmul_hfloatdp2.Rm = Rm;
    insn.fnmul_hfloatdp2._unnamed_2 = 0b1;
    insn.fnmul_hfloatdp2.ftype = 0b11;
    insn.fnmul_hfloatdp2._unnamed_1 = 0b11110;
    insn.fnmul_hfloatdp2.S = 0b0;
    insn.fnmul_hfloatdp2._unnamed_0 = 0b0;
    insn.fnmul_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmul_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmul_sfloatdp2.Rd = Rd;
    insn.fnmul_sfloatdp2.Rn = Rn;
    insn.fnmul_sfloatdp2._unnamed_3 = 0b00010;
    insn.fnmul_sfloatdp2.op = 0b1;
    insn.fnmul_sfloatdp2.Rm = Rm;
    insn.fnmul_sfloatdp2._unnamed_2 = 0b1;
    insn.fnmul_sfloatdp2.ftype = 0b00;
    insn.fnmul_sfloatdp2._unnamed_1 = 0b11110;
    insn.fnmul_sfloatdp2.S = 0b0;
    insn.fnmul_sfloatdp2._unnamed_0 = 0b0;
    insn.fnmul_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fnmul_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fnmul_dfloatdp2.Rd = Rd;
    insn.fnmul_dfloatdp2.Rn = Rn;
    insn.fnmul_dfloatdp2._unnamed_3 = 0b00010;
    insn.fnmul_dfloatdp2.op = 0b1;
    insn.fnmul_dfloatdp2.Rm = Rm;
    insn.fnmul_dfloatdp2._unnamed_2 = 0b1;
    insn.fnmul_dfloatdp2.ftype = 0b01;
    insn.fnmul_dfloatdp2._unnamed_1 = 0b11110;
    insn.fnmul_dfloatdp2.S = 0b0;
    insn.fnmul_dfloatdp2._unnamed_0 = 0b0;
    insn.fnmul_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint32x_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint32x_sfloatdp1.Rd = Rd;
    insn.frint32x_sfloatdp1.Rn = Rn;
    insn.frint32x_sfloatdp1._unnamed_3 = 0b10000;
    insn.frint32x_sfloatdp1.op = 0b01;
    insn.frint32x_sfloatdp1._unnamed_2 = 0b10100;
    insn.frint32x_sfloatdp1.ftype = 0b00;
    insn.frint32x_sfloatdp1._unnamed_1 = 0b11110;
    insn.frint32x_sfloatdp1.S = 0b0;
    insn.frint32x_sfloatdp1._unnamed_0 = 0b0;
    insn.frint32x_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint32x_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint32x_dfloatdp1.Rd = Rd;
    insn.frint32x_dfloatdp1.Rn = Rn;
    insn.frint32x_dfloatdp1._unnamed_3 = 0b10000;
    insn.frint32x_dfloatdp1.op = 0b01;
    insn.frint32x_dfloatdp1._unnamed_2 = 0b10100;
    insn.frint32x_dfloatdp1.ftype = 0b01;
    insn.frint32x_dfloatdp1._unnamed_1 = 0b11110;
    insn.frint32x_dfloatdp1.S = 0b0;
    insn.frint32x_dfloatdp1._unnamed_0 = 0b0;
    insn.frint32x_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint32z_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint32z_sfloatdp1.Rd = Rd;
    insn.frint32z_sfloatdp1.Rn = Rn;
    insn.frint32z_sfloatdp1._unnamed_3 = 0b10000;
    insn.frint32z_sfloatdp1.op = 0b00;
    insn.frint32z_sfloatdp1._unnamed_2 = 0b10100;
    insn.frint32z_sfloatdp1.ftype = 0b00;
    insn.frint32z_sfloatdp1._unnamed_1 = 0b11110;
    insn.frint32z_sfloatdp1.S = 0b0;
    insn.frint32z_sfloatdp1._unnamed_0 = 0b0;
    insn.frint32z_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint32z_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint32z_dfloatdp1.Rd = Rd;
    insn.frint32z_dfloatdp1.Rn = Rn;
    insn.frint32z_dfloatdp1._unnamed_3 = 0b10000;
    insn.frint32z_dfloatdp1.op = 0b00;
    insn.frint32z_dfloatdp1._unnamed_2 = 0b10100;
    insn.frint32z_dfloatdp1.ftype = 0b01;
    insn.frint32z_dfloatdp1._unnamed_1 = 0b11110;
    insn.frint32z_dfloatdp1.S = 0b0;
    insn.frint32z_dfloatdp1._unnamed_0 = 0b0;
    insn.frint32z_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint64x_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint64x_sfloatdp1.Rd = Rd;
    insn.frint64x_sfloatdp1.Rn = Rn;
    insn.frint64x_sfloatdp1._unnamed_3 = 0b10000;
    insn.frint64x_sfloatdp1.op = 0b11;
    insn.frint64x_sfloatdp1._unnamed_2 = 0b10100;
    insn.frint64x_sfloatdp1.ftype = 0b00;
    insn.frint64x_sfloatdp1._unnamed_1 = 0b11110;
    insn.frint64x_sfloatdp1.S = 0b0;
    insn.frint64x_sfloatdp1._unnamed_0 = 0b0;
    insn.frint64x_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint64x_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint64x_dfloatdp1.Rd = Rd;
    insn.frint64x_dfloatdp1.Rn = Rn;
    insn.frint64x_dfloatdp1._unnamed_3 = 0b10000;
    insn.frint64x_dfloatdp1.op = 0b11;
    insn.frint64x_dfloatdp1._unnamed_2 = 0b10100;
    insn.frint64x_dfloatdp1.ftype = 0b01;
    insn.frint64x_dfloatdp1._unnamed_1 = 0b11110;
    insn.frint64x_dfloatdp1.S = 0b0;
    insn.frint64x_dfloatdp1._unnamed_0 = 0b0;
    insn.frint64x_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint64z_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint64z_sfloatdp1.Rd = Rd;
    insn.frint64z_sfloatdp1.Rn = Rn;
    insn.frint64z_sfloatdp1._unnamed_3 = 0b10000;
    insn.frint64z_sfloatdp1.op = 0b10;
    insn.frint64z_sfloatdp1._unnamed_2 = 0b10100;
    insn.frint64z_sfloatdp1.ftype = 0b00;
    insn.frint64z_sfloatdp1._unnamed_1 = 0b11110;
    insn.frint64z_sfloatdp1.S = 0b0;
    insn.frint64z_sfloatdp1._unnamed_0 = 0b0;
    insn.frint64z_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frint64z_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frint64z_dfloatdp1.Rd = Rd;
    insn.frint64z_dfloatdp1.Rn = Rn;
    insn.frint64z_dfloatdp1._unnamed_3 = 0b10000;
    insn.frint64z_dfloatdp1.op = 0b10;
    insn.frint64z_dfloatdp1._unnamed_2 = 0b10100;
    insn.frint64z_dfloatdp1.ftype = 0b01;
    insn.frint64z_dfloatdp1._unnamed_1 = 0b11110;
    insn.frint64z_dfloatdp1.S = 0b0;
    insn.frint64z_dfloatdp1._unnamed_0 = 0b0;
    insn.frint64z_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinta_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinta_hfloatdp1.Rd = Rd;
    insn.frinta_hfloatdp1.Rn = Rn;
    insn.frinta_hfloatdp1._unnamed_3 = 0b10000;
    insn.frinta_hfloatdp1.rmode = 0b100;
    insn.frinta_hfloatdp1._unnamed_2 = 0b1001;
    insn.frinta_hfloatdp1.ftype = 0b11;
    insn.frinta_hfloatdp1._unnamed_1 = 0b11110;
    insn.frinta_hfloatdp1.S = 0b0;
    insn.frinta_hfloatdp1._unnamed_0 = 0b0;
    insn.frinta_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinta_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinta_sfloatdp1.Rd = Rd;
    insn.frinta_sfloatdp1.Rn = Rn;
    insn.frinta_sfloatdp1._unnamed_3 = 0b10000;
    insn.frinta_sfloatdp1.rmode = 0b100;
    insn.frinta_sfloatdp1._unnamed_2 = 0b1001;
    insn.frinta_sfloatdp1.ftype = 0b00;
    insn.frinta_sfloatdp1._unnamed_1 = 0b11110;
    insn.frinta_sfloatdp1.S = 0b0;
    insn.frinta_sfloatdp1._unnamed_0 = 0b0;
    insn.frinta_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinta_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinta_dfloatdp1.Rd = Rd;
    insn.frinta_dfloatdp1.Rn = Rn;
    insn.frinta_dfloatdp1._unnamed_3 = 0b10000;
    insn.frinta_dfloatdp1.rmode = 0b100;
    insn.frinta_dfloatdp1._unnamed_2 = 0b1001;
    insn.frinta_dfloatdp1.ftype = 0b01;
    insn.frinta_dfloatdp1._unnamed_1 = 0b11110;
    insn.frinta_dfloatdp1.S = 0b0;
    insn.frinta_dfloatdp1._unnamed_0 = 0b0;
    insn.frinta_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinti_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinti_hfloatdp1.Rd = Rd;
    insn.frinti_hfloatdp1.Rn = Rn;
    insn.frinti_hfloatdp1._unnamed_3 = 0b10000;
    insn.frinti_hfloatdp1.rmode = 0b111;
    insn.frinti_hfloatdp1._unnamed_2 = 0b1001;
    insn.frinti_hfloatdp1.ftype = 0b11;
    insn.frinti_hfloatdp1._unnamed_1 = 0b11110;
    insn.frinti_hfloatdp1.S = 0b0;
    insn.frinti_hfloatdp1._unnamed_0 = 0b0;
    insn.frinti_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinti_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinti_sfloatdp1.Rd = Rd;
    insn.frinti_sfloatdp1.Rn = Rn;
    insn.frinti_sfloatdp1._unnamed_3 = 0b10000;
    insn.frinti_sfloatdp1.rmode = 0b111;
    insn.frinti_sfloatdp1._unnamed_2 = 0b1001;
    insn.frinti_sfloatdp1.ftype = 0b00;
    insn.frinti_sfloatdp1._unnamed_1 = 0b11110;
    insn.frinti_sfloatdp1.S = 0b0;
    insn.frinti_sfloatdp1._unnamed_0 = 0b0;
    insn.frinti_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frinti_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frinti_dfloatdp1.Rd = Rd;
    insn.frinti_dfloatdp1.Rn = Rn;
    insn.frinti_dfloatdp1._unnamed_3 = 0b10000;
    insn.frinti_dfloatdp1.rmode = 0b111;
    insn.frinti_dfloatdp1._unnamed_2 = 0b1001;
    insn.frinti_dfloatdp1.ftype = 0b01;
    insn.frinti_dfloatdp1._unnamed_1 = 0b11110;
    insn.frinti_dfloatdp1.S = 0b0;
    insn.frinti_dfloatdp1._unnamed_0 = 0b0;
    insn.frinti_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintm_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintm_hfloatdp1.Rd = Rd;
    insn.frintm_hfloatdp1.Rn = Rn;
    insn.frintm_hfloatdp1._unnamed_3 = 0b10000;
    insn.frintm_hfloatdp1.rmode = 0b010;
    insn.frintm_hfloatdp1._unnamed_2 = 0b1001;
    insn.frintm_hfloatdp1.ftype = 0b11;
    insn.frintm_hfloatdp1._unnamed_1 = 0b11110;
    insn.frintm_hfloatdp1.S = 0b0;
    insn.frintm_hfloatdp1._unnamed_0 = 0b0;
    insn.frintm_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintm_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintm_sfloatdp1.Rd = Rd;
    insn.frintm_sfloatdp1.Rn = Rn;
    insn.frintm_sfloatdp1._unnamed_3 = 0b10000;
    insn.frintm_sfloatdp1.rmode = 0b010;
    insn.frintm_sfloatdp1._unnamed_2 = 0b1001;
    insn.frintm_sfloatdp1.ftype = 0b00;
    insn.frintm_sfloatdp1._unnamed_1 = 0b11110;
    insn.frintm_sfloatdp1.S = 0b0;
    insn.frintm_sfloatdp1._unnamed_0 = 0b0;
    insn.frintm_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintm_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintm_dfloatdp1.Rd = Rd;
    insn.frintm_dfloatdp1.Rn = Rn;
    insn.frintm_dfloatdp1._unnamed_3 = 0b10000;
    insn.frintm_dfloatdp1.rmode = 0b010;
    insn.frintm_dfloatdp1._unnamed_2 = 0b1001;
    insn.frintm_dfloatdp1.ftype = 0b01;
    insn.frintm_dfloatdp1._unnamed_1 = 0b11110;
    insn.frintm_dfloatdp1.S = 0b0;
    insn.frintm_dfloatdp1._unnamed_0 = 0b0;
    insn.frintm_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintn_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintn_hfloatdp1.Rd = Rd;
    insn.frintn_hfloatdp1.Rn = Rn;
    insn.frintn_hfloatdp1._unnamed_3 = 0b10000;
    insn.frintn_hfloatdp1.rmode = 0b000;
    insn.frintn_hfloatdp1._unnamed_2 = 0b1001;
    insn.frintn_hfloatdp1.ftype = 0b11;
    insn.frintn_hfloatdp1._unnamed_1 = 0b11110;
    insn.frintn_hfloatdp1.S = 0b0;
    insn.frintn_hfloatdp1._unnamed_0 = 0b0;
    insn.frintn_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintn_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintn_sfloatdp1.Rd = Rd;
    insn.frintn_sfloatdp1.Rn = Rn;
    insn.frintn_sfloatdp1._unnamed_3 = 0b10000;
    insn.frintn_sfloatdp1.rmode = 0b000;
    insn.frintn_sfloatdp1._unnamed_2 = 0b1001;
    insn.frintn_sfloatdp1.ftype = 0b00;
    insn.frintn_sfloatdp1._unnamed_1 = 0b11110;
    insn.frintn_sfloatdp1.S = 0b0;
    insn.frintn_sfloatdp1._unnamed_0 = 0b0;
    insn.frintn_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintn_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintn_dfloatdp1.Rd = Rd;
    insn.frintn_dfloatdp1.Rn = Rn;
    insn.frintn_dfloatdp1._unnamed_3 = 0b10000;
    insn.frintn_dfloatdp1.rmode = 0b000;
    insn.frintn_dfloatdp1._unnamed_2 = 0b1001;
    insn.frintn_dfloatdp1.ftype = 0b01;
    insn.frintn_dfloatdp1._unnamed_1 = 0b11110;
    insn.frintn_dfloatdp1.S = 0b0;
    insn.frintn_dfloatdp1._unnamed_0 = 0b0;
    insn.frintn_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintp_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintp_hfloatdp1.Rd = Rd;
    insn.frintp_hfloatdp1.Rn = Rn;
    insn.frintp_hfloatdp1._unnamed_3 = 0b10000;
    insn.frintp_hfloatdp1.rmode = 0b001;
    insn.frintp_hfloatdp1._unnamed_2 = 0b1001;
    insn.frintp_hfloatdp1.ftype = 0b11;
    insn.frintp_hfloatdp1._unnamed_1 = 0b11110;
    insn.frintp_hfloatdp1.S = 0b0;
    insn.frintp_hfloatdp1._unnamed_0 = 0b0;
    insn.frintp_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintp_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintp_sfloatdp1.Rd = Rd;
    insn.frintp_sfloatdp1.Rn = Rn;
    insn.frintp_sfloatdp1._unnamed_3 = 0b10000;
    insn.frintp_sfloatdp1.rmode = 0b001;
    insn.frintp_sfloatdp1._unnamed_2 = 0b1001;
    insn.frintp_sfloatdp1.ftype = 0b00;
    insn.frintp_sfloatdp1._unnamed_1 = 0b11110;
    insn.frintp_sfloatdp1.S = 0b0;
    insn.frintp_sfloatdp1._unnamed_0 = 0b0;
    insn.frintp_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintp_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintp_dfloatdp1.Rd = Rd;
    insn.frintp_dfloatdp1.Rn = Rn;
    insn.frintp_dfloatdp1._unnamed_3 = 0b10000;
    insn.frintp_dfloatdp1.rmode = 0b001;
    insn.frintp_dfloatdp1._unnamed_2 = 0b1001;
    insn.frintp_dfloatdp1.ftype = 0b01;
    insn.frintp_dfloatdp1._unnamed_1 = 0b11110;
    insn.frintp_dfloatdp1.S = 0b0;
    insn.frintp_dfloatdp1._unnamed_0 = 0b0;
    insn.frintp_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintx_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintx_hfloatdp1.Rd = Rd;
    insn.frintx_hfloatdp1.Rn = Rn;
    insn.frintx_hfloatdp1._unnamed_3 = 0b10000;
    insn.frintx_hfloatdp1.rmode = 0b110;
    insn.frintx_hfloatdp1._unnamed_2 = 0b1001;
    insn.frintx_hfloatdp1.ftype = 0b11;
    insn.frintx_hfloatdp1._unnamed_1 = 0b11110;
    insn.frintx_hfloatdp1.S = 0b0;
    insn.frintx_hfloatdp1._unnamed_0 = 0b0;
    insn.frintx_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintx_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintx_sfloatdp1.Rd = Rd;
    insn.frintx_sfloatdp1.Rn = Rn;
    insn.frintx_sfloatdp1._unnamed_3 = 0b10000;
    insn.frintx_sfloatdp1.rmode = 0b110;
    insn.frintx_sfloatdp1._unnamed_2 = 0b1001;
    insn.frintx_sfloatdp1.ftype = 0b00;
    insn.frintx_sfloatdp1._unnamed_1 = 0b11110;
    insn.frintx_sfloatdp1.S = 0b0;
    insn.frintx_sfloatdp1._unnamed_0 = 0b0;
    insn.frintx_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintx_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintx_dfloatdp1.Rd = Rd;
    insn.frintx_dfloatdp1.Rn = Rn;
    insn.frintx_dfloatdp1._unnamed_3 = 0b10000;
    insn.frintx_dfloatdp1.rmode = 0b110;
    insn.frintx_dfloatdp1._unnamed_2 = 0b1001;
    insn.frintx_dfloatdp1.ftype = 0b01;
    insn.frintx_dfloatdp1._unnamed_1 = 0b11110;
    insn.frintx_dfloatdp1.S = 0b0;
    insn.frintx_dfloatdp1._unnamed_0 = 0b0;
    insn.frintx_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintz_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintz_hfloatdp1.Rd = Rd;
    insn.frintz_hfloatdp1.Rn = Rn;
    insn.frintz_hfloatdp1._unnamed_3 = 0b10000;
    insn.frintz_hfloatdp1.rmode = 0b011;
    insn.frintz_hfloatdp1._unnamed_2 = 0b1001;
    insn.frintz_hfloatdp1.ftype = 0b11;
    insn.frintz_hfloatdp1._unnamed_1 = 0b11110;
    insn.frintz_hfloatdp1.S = 0b0;
    insn.frintz_hfloatdp1._unnamed_0 = 0b0;
    insn.frintz_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintz_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintz_sfloatdp1.Rd = Rd;
    insn.frintz_sfloatdp1.Rn = Rn;
    insn.frintz_sfloatdp1._unnamed_3 = 0b10000;
    insn.frintz_sfloatdp1.rmode = 0b011;
    insn.frintz_sfloatdp1._unnamed_2 = 0b1001;
    insn.frintz_sfloatdp1.ftype = 0b00;
    insn.frintz_sfloatdp1._unnamed_1 = 0b11110;
    insn.frintz_sfloatdp1.S = 0b0;
    insn.frintz_sfloatdp1._unnamed_0 = 0b0;
    insn.frintz_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_frintz_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.frintz_dfloatdp1.Rd = Rd;
    insn.frintz_dfloatdp1.Rn = Rn;
    insn.frintz_dfloatdp1._unnamed_3 = 0b10000;
    insn.frintz_dfloatdp1.rmode = 0b011;
    insn.frintz_dfloatdp1._unnamed_2 = 0b1001;
    insn.frintz_dfloatdp1.ftype = 0b01;
    insn.frintz_dfloatdp1._unnamed_1 = 0b11110;
    insn.frintz_dfloatdp1.S = 0b0;
    insn.frintz_dfloatdp1._unnamed_0 = 0b0;
    insn.frintz_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsqrt_h_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fsqrt_hfloatdp1.Rd = Rd;
    insn.fsqrt_hfloatdp1.Rn = Rn;
    insn.fsqrt_hfloatdp1._unnamed_3 = 0b10000;
    insn.fsqrt_hfloatdp1.opc = 0b11;
    insn.fsqrt_hfloatdp1._unnamed_2 = 0b10000;
    insn.fsqrt_hfloatdp1.ftype = 0b11;
    insn.fsqrt_hfloatdp1._unnamed_1 = 0b11110;
    insn.fsqrt_hfloatdp1.S = 0b0;
    insn.fsqrt_hfloatdp1._unnamed_0 = 0b0;
    insn.fsqrt_hfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsqrt_s_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fsqrt_sfloatdp1.Rd = Rd;
    insn.fsqrt_sfloatdp1.Rn = Rn;
    insn.fsqrt_sfloatdp1._unnamed_3 = 0b10000;
    insn.fsqrt_sfloatdp1.opc = 0b11;
    insn.fsqrt_sfloatdp1._unnamed_2 = 0b10000;
    insn.fsqrt_sfloatdp1.ftype = 0b00;
    insn.fsqrt_sfloatdp1._unnamed_1 = 0b11110;
    insn.fsqrt_sfloatdp1.S = 0b0;
    insn.fsqrt_sfloatdp1._unnamed_0 = 0b0;
    insn.fsqrt_sfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsqrt_d_floatdp1(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.fsqrt_dfloatdp1.Rd = Rd;
    insn.fsqrt_dfloatdp1.Rn = Rn;
    insn.fsqrt_dfloatdp1._unnamed_3 = 0b10000;
    insn.fsqrt_dfloatdp1.opc = 0b11;
    insn.fsqrt_dfloatdp1._unnamed_2 = 0b10000;
    insn.fsqrt_dfloatdp1.ftype = 0b01;
    insn.fsqrt_dfloatdp1._unnamed_1 = 0b11110;
    insn.fsqrt_dfloatdp1.S = 0b0;
    insn.fsqrt_dfloatdp1._unnamed_0 = 0b0;
    insn.fsqrt_dfloatdp1.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsub_h_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fsub_hfloatdp2.Rd = Rd;
    insn.fsub_hfloatdp2.Rn = Rn;
    insn.fsub_hfloatdp2._unnamed_4 = 0b10;
    insn.fsub_hfloatdp2.op = 0b1;
    insn.fsub_hfloatdp2._unnamed_3 = 0b001;
    insn.fsub_hfloatdp2.Rm = Rm;
    insn.fsub_hfloatdp2._unnamed_2 = 0b1;
    insn.fsub_hfloatdp2.ftype = 0b11;
    insn.fsub_hfloatdp2._unnamed_1 = 0b11110;
    insn.fsub_hfloatdp2.S = 0b0;
    insn.fsub_hfloatdp2._unnamed_0 = 0b0;
    insn.fsub_hfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsub_s_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fsub_sfloatdp2.Rd = Rd;
    insn.fsub_sfloatdp2.Rn = Rn;
    insn.fsub_sfloatdp2._unnamed_4 = 0b10;
    insn.fsub_sfloatdp2.op = 0b1;
    insn.fsub_sfloatdp2._unnamed_3 = 0b001;
    insn.fsub_sfloatdp2.Rm = Rm;
    insn.fsub_sfloatdp2._unnamed_2 = 0b1;
    insn.fsub_sfloatdp2.ftype = 0b00;
    insn.fsub_sfloatdp2._unnamed_1 = 0b11110;
    insn.fsub_sfloatdp2.S = 0b0;
    insn.fsub_sfloatdp2._unnamed_0 = 0b0;
    insn.fsub_sfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_fsub_d_floatdp2(uint32_t Rd, uint32_t Rn, uint32_t Rm) {
    FloatEncoding insn = {};
    insn.fsub_dfloatdp2.Rd = Rd;
    insn.fsub_dfloatdp2.Rn = Rn;
    insn.fsub_dfloatdp2._unnamed_4 = 0b10;
    insn.fsub_dfloatdp2.op = 0b1;
    insn.fsub_dfloatdp2._unnamed_3 = 0b001;
    insn.fsub_dfloatdp2.Rm = Rm;
    insn.fsub_dfloatdp2._unnamed_2 = 0b1;
    insn.fsub_dfloatdp2.ftype = 0b01;
    insn.fsub_dfloatdp2._unnamed_1 = 0b11110;
    insn.fsub_dfloatdp2.S = 0b0;
    insn.fsub_dfloatdp2._unnamed_0 = 0b0;
    insn.fsub_dfloatdp2.M = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_h32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_h32float2fix.Rd = Rd;
    insn.scvtf_h32float2fix.Rn = Rn;
    insn.scvtf_h32float2fix.scale = scale;
    insn.scvtf_h32float2fix.opcode = 0b010;
    insn.scvtf_h32float2fix.rmode = 0b00;
    insn.scvtf_h32float2fix._unnamed_2 = 0b0;
    insn.scvtf_h32float2fix.ftype = 0b11;
    insn.scvtf_h32float2fix._unnamed_1 = 0b11110;
    insn.scvtf_h32float2fix.S = 0b0;
    insn.scvtf_h32float2fix._unnamed_0 = 0b0;
    insn.scvtf_h32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_h64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_h64float2fix.Rd = Rd;
    insn.scvtf_h64float2fix.Rn = Rn;
    insn.scvtf_h64float2fix.scale = scale;
    insn.scvtf_h64float2fix.opcode = 0b010;
    insn.scvtf_h64float2fix.rmode = 0b00;
    insn.scvtf_h64float2fix._unnamed_2 = 0b0;
    insn.scvtf_h64float2fix.ftype = 0b11;
    insn.scvtf_h64float2fix._unnamed_1 = 0b11110;
    insn.scvtf_h64float2fix.S = 0b0;
    insn.scvtf_h64float2fix._unnamed_0 = 0b0;
    insn.scvtf_h64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_s32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_s32float2fix.Rd = Rd;
    insn.scvtf_s32float2fix.Rn = Rn;
    insn.scvtf_s32float2fix.scale = scale;
    insn.scvtf_s32float2fix.opcode = 0b010;
    insn.scvtf_s32float2fix.rmode = 0b00;
    insn.scvtf_s32float2fix._unnamed_2 = 0b0;
    insn.scvtf_s32float2fix.ftype = 0b00;
    insn.scvtf_s32float2fix._unnamed_1 = 0b11110;
    insn.scvtf_s32float2fix.S = 0b0;
    insn.scvtf_s32float2fix._unnamed_0 = 0b0;
    insn.scvtf_s32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_s64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_s64float2fix.Rd = Rd;
    insn.scvtf_s64float2fix.Rn = Rn;
    insn.scvtf_s64float2fix.scale = scale;
    insn.scvtf_s64float2fix.opcode = 0b010;
    insn.scvtf_s64float2fix.rmode = 0b00;
    insn.scvtf_s64float2fix._unnamed_2 = 0b0;
    insn.scvtf_s64float2fix.ftype = 0b00;
    insn.scvtf_s64float2fix._unnamed_1 = 0b11110;
    insn.scvtf_s64float2fix.S = 0b0;
    insn.scvtf_s64float2fix._unnamed_0 = 0b0;
    insn.scvtf_s64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_d32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_d32float2fix.Rd = Rd;
    insn.scvtf_d32float2fix.Rn = Rn;
    insn.scvtf_d32float2fix.scale = scale;
    insn.scvtf_d32float2fix.opcode = 0b010;
    insn.scvtf_d32float2fix.rmode = 0b00;
    insn.scvtf_d32float2fix._unnamed_2 = 0b0;
    insn.scvtf_d32float2fix.ftype = 0b01;
    insn.scvtf_d32float2fix._unnamed_1 = 0b11110;
    insn.scvtf_d32float2fix.S = 0b0;
    insn.scvtf_d32float2fix._unnamed_0 = 0b0;
    insn.scvtf_d32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_d64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.scvtf_d64float2fix.Rd = Rd;
    insn.scvtf_d64float2fix.Rn = Rn;
    insn.scvtf_d64float2fix.scale = scale;
    insn.scvtf_d64float2fix.opcode = 0b010;
    insn.scvtf_d64float2fix.rmode = 0b00;
    insn.scvtf_d64float2fix._unnamed_2 = 0b0;
    insn.scvtf_d64float2fix.ftype = 0b01;
    insn.scvtf_d64float2fix._unnamed_1 = 0b11110;
    insn.scvtf_d64float2fix.S = 0b0;
    insn.scvtf_d64float2fix._unnamed_0 = 0b0;
    insn.scvtf_d64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_h32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_h32float2int.Rd = Rd;
    insn.scvtf_h32float2int.Rn = Rn;
    insn.scvtf_h32float2int._unnamed_3 = 0b000000;
    insn.scvtf_h32float2int.opcode = 0b010;
    insn.scvtf_h32float2int.rmode = 0b00;
    insn.scvtf_h32float2int._unnamed_2 = 0b1;
    insn.scvtf_h32float2int.ftype = 0b11;
    insn.scvtf_h32float2int._unnamed_1 = 0b11110;
    insn.scvtf_h32float2int.S = 0b0;
    insn.scvtf_h32float2int._unnamed_0 = 0b0;
    insn.scvtf_h32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_s32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_s32float2int.Rd = Rd;
    insn.scvtf_s32float2int.Rn = Rn;
    insn.scvtf_s32float2int._unnamed_3 = 0b000000;
    insn.scvtf_s32float2int.opcode = 0b010;
    insn.scvtf_s32float2int.rmode = 0b00;
    insn.scvtf_s32float2int._unnamed_2 = 0b1;
    insn.scvtf_s32float2int.ftype = 0b00;
    insn.scvtf_s32float2int._unnamed_1 = 0b11110;
    insn.scvtf_s32float2int.S = 0b0;
    insn.scvtf_s32float2int._unnamed_0 = 0b0;
    insn.scvtf_s32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_d32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_d32float2int.Rd = Rd;
    insn.scvtf_d32float2int.Rn = Rn;
    insn.scvtf_d32float2int._unnamed_3 = 0b000000;
    insn.scvtf_d32float2int.opcode = 0b010;
    insn.scvtf_d32float2int.rmode = 0b00;
    insn.scvtf_d32float2int._unnamed_2 = 0b1;
    insn.scvtf_d32float2int.ftype = 0b01;
    insn.scvtf_d32float2int._unnamed_1 = 0b11110;
    insn.scvtf_d32float2int.S = 0b0;
    insn.scvtf_d32float2int._unnamed_0 = 0b0;
    insn.scvtf_d32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_h64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_h64float2int.Rd = Rd;
    insn.scvtf_h64float2int.Rn = Rn;
    insn.scvtf_h64float2int._unnamed_3 = 0b000000;
    insn.scvtf_h64float2int.opcode = 0b010;
    insn.scvtf_h64float2int.rmode = 0b00;
    insn.scvtf_h64float2int._unnamed_2 = 0b1;
    insn.scvtf_h64float2int.ftype = 0b11;
    insn.scvtf_h64float2int._unnamed_1 = 0b11110;
    insn.scvtf_h64float2int.S = 0b0;
    insn.scvtf_h64float2int._unnamed_0 = 0b0;
    insn.scvtf_h64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_s64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_s64float2int.Rd = Rd;
    insn.scvtf_s64float2int.Rn = Rn;
    insn.scvtf_s64float2int._unnamed_3 = 0b000000;
    insn.scvtf_s64float2int.opcode = 0b010;
    insn.scvtf_s64float2int.rmode = 0b00;
    insn.scvtf_s64float2int._unnamed_2 = 0b1;
    insn.scvtf_s64float2int.ftype = 0b00;
    insn.scvtf_s64float2int._unnamed_1 = 0b11110;
    insn.scvtf_s64float2int.S = 0b0;
    insn.scvtf_s64float2int._unnamed_0 = 0b0;
    insn.scvtf_s64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_d64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_d64float2int.Rd = Rd;
    insn.scvtf_d64float2int.Rn = Rn;
    insn.scvtf_d64float2int._unnamed_3 = 0b000000;
    insn.scvtf_d64float2int.opcode = 0b010;
    insn.scvtf_d64float2int.rmode = 0b00;
    insn.scvtf_d64float2int._unnamed_2 = 0b1;
    insn.scvtf_d64float2int.ftype = 0b01;
    insn.scvtf_d64float2int._unnamed_1 = 0b11110;
    insn.scvtf_d64float2int.S = 0b0;
    insn.scvtf_d64float2int._unnamed_0 = 0b0;
    insn.scvtf_d64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_sisd32h.Rd = Rd;
    insn.scvtf_sisd32h.Rn = Rn;
    insn.scvtf_sisd32h._unnamed_3 = 0b000000;
    insn.scvtf_sisd32h.opcode = 0b100;
    insn.scvtf_sisd32h.rmode = 0b11;
    insn.scvtf_sisd32h._unnamed_2 = 0b1;
    insn.scvtf_sisd32h.ftype = 0b11;
    insn.scvtf_sisd32h._unnamed_1 = 0b11110;
    insn.scvtf_sisd32h.S = 0b0;
    insn.scvtf_sisd32h._unnamed_0 = 0b0;
    insn.scvtf_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_sisd32d.Rd = Rd;
    insn.scvtf_sisd32d.Rn = Rn;
    insn.scvtf_sisd32d._unnamed_3 = 0b000000;
    insn.scvtf_sisd32d.opcode = 0b100;
    insn.scvtf_sisd32d.rmode = 0b11;
    insn.scvtf_sisd32d._unnamed_2 = 0b1;
    insn.scvtf_sisd32d.ftype = 0b01;
    insn.scvtf_sisd32d._unnamed_1 = 0b11110;
    insn.scvtf_sisd32d.S = 0b0;
    insn.scvtf_sisd32d._unnamed_0 = 0b0;
    insn.scvtf_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_scvtf_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_sisd64h.Rd = Rd;
    insn.scvtf_sisd64h.Rn = Rn;
    insn.scvtf_sisd64h._unnamed_3 = 0b000000;
    insn.scvtf_sisd64h.opcode = 0b100;
    insn.scvtf_sisd64h.rmode = 0b11;
    insn.scvtf_sisd64h._unnamed_2 = 0b1;
    insn.scvtf_sisd64h.ftype = 0b11;
    insn.scvtf_sisd64h._unnamed_1 = 0b11110;
    insn.scvtf_sisd64h.S = 0b0;
    insn.scvtf_sisd64h._unnamed_0 = 0b0;
    insn.scvtf_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_scvtf_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.scvtf_sisd64s.Rd = Rd;
    insn.scvtf_sisd64s.Rn = Rn;
    insn.scvtf_sisd64s._unnamed_3 = 0b000000;
    insn.scvtf_sisd64s.opcode = 0b100;
    insn.scvtf_sisd64s.rmode = 0b11;
    insn.scvtf_sisd64s._unnamed_2 = 0b1;
    insn.scvtf_sisd64s.ftype = 0b00;
    insn.scvtf_sisd64s._unnamed_1 = 0b11110;
    insn.scvtf_sisd64s.S = 0b0;
    insn.scvtf_sisd64s._unnamed_0 = 0b0;
    insn.scvtf_sisd64s.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_h32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_h32float2fix.Rd = Rd;
    insn.ucvtf_h32float2fix.Rn = Rn;
    insn.ucvtf_h32float2fix.scale = scale;
    insn.ucvtf_h32float2fix.opcode = 0b011;
    insn.ucvtf_h32float2fix.rmode = 0b00;
    insn.ucvtf_h32float2fix._unnamed_2 = 0b0;
    insn.ucvtf_h32float2fix.ftype = 0b11;
    insn.ucvtf_h32float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_h32float2fix.S = 0b0;
    insn.ucvtf_h32float2fix._unnamed_0 = 0b0;
    insn.ucvtf_h32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_h64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_h64float2fix.Rd = Rd;
    insn.ucvtf_h64float2fix.Rn = Rn;
    insn.ucvtf_h64float2fix.scale = scale;
    insn.ucvtf_h64float2fix.opcode = 0b011;
    insn.ucvtf_h64float2fix.rmode = 0b00;
    insn.ucvtf_h64float2fix._unnamed_2 = 0b0;
    insn.ucvtf_h64float2fix.ftype = 0b11;
    insn.ucvtf_h64float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_h64float2fix.S = 0b0;
    insn.ucvtf_h64float2fix._unnamed_0 = 0b0;
    insn.ucvtf_h64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_s32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_s32float2fix.Rd = Rd;
    insn.ucvtf_s32float2fix.Rn = Rn;
    insn.ucvtf_s32float2fix.scale = scale;
    insn.ucvtf_s32float2fix.opcode = 0b011;
    insn.ucvtf_s32float2fix.rmode = 0b00;
    insn.ucvtf_s32float2fix._unnamed_2 = 0b0;
    insn.ucvtf_s32float2fix.ftype = 0b00;
    insn.ucvtf_s32float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_s32float2fix.S = 0b0;
    insn.ucvtf_s32float2fix._unnamed_0 = 0b0;
    insn.ucvtf_s32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_s64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_s64float2fix.Rd = Rd;
    insn.ucvtf_s64float2fix.Rn = Rn;
    insn.ucvtf_s64float2fix.scale = scale;
    insn.ucvtf_s64float2fix.opcode = 0b011;
    insn.ucvtf_s64float2fix.rmode = 0b00;
    insn.ucvtf_s64float2fix._unnamed_2 = 0b0;
    insn.ucvtf_s64float2fix.ftype = 0b00;
    insn.ucvtf_s64float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_s64float2fix.S = 0b0;
    insn.ucvtf_s64float2fix._unnamed_0 = 0b0;
    insn.ucvtf_s64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_d32_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_d32float2fix.Rd = Rd;
    insn.ucvtf_d32float2fix.Rn = Rn;
    insn.ucvtf_d32float2fix.scale = scale;
    insn.ucvtf_d32float2fix.opcode = 0b011;
    insn.ucvtf_d32float2fix.rmode = 0b00;
    insn.ucvtf_d32float2fix._unnamed_2 = 0b0;
    insn.ucvtf_d32float2fix.ftype = 0b01;
    insn.ucvtf_d32float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_d32float2fix.S = 0b0;
    insn.ucvtf_d32float2fix._unnamed_0 = 0b0;
    insn.ucvtf_d32float2fix.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_d64_float2fix(uint32_t Rd, uint32_t Rn, uint32_t scale) {
    FloatEncoding insn = {};
    insn.ucvtf_d64float2fix.Rd = Rd;
    insn.ucvtf_d64float2fix.Rn = Rn;
    insn.ucvtf_d64float2fix.scale = scale;
    insn.ucvtf_d64float2fix.opcode = 0b011;
    insn.ucvtf_d64float2fix.rmode = 0b00;
    insn.ucvtf_d64float2fix._unnamed_2 = 0b0;
    insn.ucvtf_d64float2fix.ftype = 0b01;
    insn.ucvtf_d64float2fix._unnamed_1 = 0b11110;
    insn.ucvtf_d64float2fix.S = 0b0;
    insn.ucvtf_d64float2fix._unnamed_0 = 0b0;
    insn.ucvtf_d64float2fix.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_h32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_h32float2int.Rd = Rd;
    insn.ucvtf_h32float2int.Rn = Rn;
    insn.ucvtf_h32float2int._unnamed_3 = 0b000000;
    insn.ucvtf_h32float2int.opcode = 0b011;
    insn.ucvtf_h32float2int.rmode = 0b00;
    insn.ucvtf_h32float2int._unnamed_2 = 0b1;
    insn.ucvtf_h32float2int.ftype = 0b11;
    insn.ucvtf_h32float2int._unnamed_1 = 0b11110;
    insn.ucvtf_h32float2int.S = 0b0;
    insn.ucvtf_h32float2int._unnamed_0 = 0b0;
    insn.ucvtf_h32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_s32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_s32float2int.Rd = Rd;
    insn.ucvtf_s32float2int.Rn = Rn;
    insn.ucvtf_s32float2int._unnamed_3 = 0b000000;
    insn.ucvtf_s32float2int.opcode = 0b011;
    insn.ucvtf_s32float2int.rmode = 0b00;
    insn.ucvtf_s32float2int._unnamed_2 = 0b1;
    insn.ucvtf_s32float2int.ftype = 0b00;
    insn.ucvtf_s32float2int._unnamed_1 = 0b11110;
    insn.ucvtf_s32float2int.S = 0b0;
    insn.ucvtf_s32float2int._unnamed_0 = 0b0;
    insn.ucvtf_s32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_d32_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_d32float2int.Rd = Rd;
    insn.ucvtf_d32float2int.Rn = Rn;
    insn.ucvtf_d32float2int._unnamed_3 = 0b000000;
    insn.ucvtf_d32float2int.opcode = 0b011;
    insn.ucvtf_d32float2int.rmode = 0b00;
    insn.ucvtf_d32float2int._unnamed_2 = 0b1;
    insn.ucvtf_d32float2int.ftype = 0b01;
    insn.ucvtf_d32float2int._unnamed_1 = 0b11110;
    insn.ucvtf_d32float2int.S = 0b0;
    insn.ucvtf_d32float2int._unnamed_0 = 0b0;
    insn.ucvtf_d32float2int.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_h64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_h64float2int.Rd = Rd;
    insn.ucvtf_h64float2int.Rn = Rn;
    insn.ucvtf_h64float2int._unnamed_3 = 0b000000;
    insn.ucvtf_h64float2int.opcode = 0b011;
    insn.ucvtf_h64float2int.rmode = 0b00;
    insn.ucvtf_h64float2int._unnamed_2 = 0b1;
    insn.ucvtf_h64float2int.ftype = 0b11;
    insn.ucvtf_h64float2int._unnamed_1 = 0b11110;
    insn.ucvtf_h64float2int.S = 0b0;
    insn.ucvtf_h64float2int._unnamed_0 = 0b0;
    insn.ucvtf_h64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_s64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_s64float2int.Rd = Rd;
    insn.ucvtf_s64float2int.Rn = Rn;
    insn.ucvtf_s64float2int._unnamed_3 = 0b000000;
    insn.ucvtf_s64float2int.opcode = 0b011;
    insn.ucvtf_s64float2int.rmode = 0b00;
    insn.ucvtf_s64float2int._unnamed_2 = 0b1;
    insn.ucvtf_s64float2int.ftype = 0b00;
    insn.ucvtf_s64float2int._unnamed_1 = 0b11110;
    insn.ucvtf_s64float2int.S = 0b0;
    insn.ucvtf_s64float2int._unnamed_0 = 0b0;
    insn.ucvtf_s64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_d64_float2int(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_d64float2int.Rd = Rd;
    insn.ucvtf_d64float2int.Rn = Rn;
    insn.ucvtf_d64float2int._unnamed_3 = 0b000000;
    insn.ucvtf_d64float2int.opcode = 0b011;
    insn.ucvtf_d64float2int.rmode = 0b00;
    insn.ucvtf_d64float2int._unnamed_2 = 0b1;
    insn.ucvtf_d64float2int.ftype = 0b01;
    insn.ucvtf_d64float2int._unnamed_1 = 0b11110;
    insn.ucvtf_d64float2int.S = 0b0;
    insn.ucvtf_d64float2int._unnamed_0 = 0b0;
    insn.ucvtf_d64float2int.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_sisd_32h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_sisd32h.Rd = Rd;
    insn.ucvtf_sisd32h.Rn = Rn;
    insn.ucvtf_sisd32h._unnamed_3 = 0b000000;
    insn.ucvtf_sisd32h.opcode = 0b101;
    insn.ucvtf_sisd32h.rmode = 0b11;
    insn.ucvtf_sisd32h._unnamed_2 = 0b1;
    insn.ucvtf_sisd32h.ftype = 0b11;
    insn.ucvtf_sisd32h._unnamed_1 = 0b11110;
    insn.ucvtf_sisd32h.S = 0b0;
    insn.ucvtf_sisd32h._unnamed_0 = 0b0;
    insn.ucvtf_sisd32h.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_sisd_32d(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_sisd32d.Rd = Rd;
    insn.ucvtf_sisd32d.Rn = Rn;
    insn.ucvtf_sisd32d._unnamed_3 = 0b000000;
    insn.ucvtf_sisd32d.opcode = 0b101;
    insn.ucvtf_sisd32d.rmode = 0b11;
    insn.ucvtf_sisd32d._unnamed_2 = 0b1;
    insn.ucvtf_sisd32d.ftype = 0b01;
    insn.ucvtf_sisd32d._unnamed_1 = 0b11110;
    insn.ucvtf_sisd32d.S = 0b0;
    insn.ucvtf_sisd32d._unnamed_0 = 0b0;
    insn.ucvtf_sisd32d.sf = 0b0;
    return insn.raw;
}

uint32_t encode_ucvtf_sisd_64h(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_sisd64h.Rd = Rd;
    insn.ucvtf_sisd64h.Rn = Rn;
    insn.ucvtf_sisd64h._unnamed_3 = 0b000000;
    insn.ucvtf_sisd64h.opcode = 0b101;
    insn.ucvtf_sisd64h.rmode = 0b11;
    insn.ucvtf_sisd64h._unnamed_2 = 0b1;
    insn.ucvtf_sisd64h.ftype = 0b11;
    insn.ucvtf_sisd64h._unnamed_1 = 0b11110;
    insn.ucvtf_sisd64h.S = 0b0;
    insn.ucvtf_sisd64h._unnamed_0 = 0b0;
    insn.ucvtf_sisd64h.sf = 0b1;
    return insn.raw;
}

uint32_t encode_ucvtf_sisd_64s(uint32_t Rd, uint32_t Rn) {
    FloatEncoding insn = {};
    insn.ucvtf_sisd64s.Rd = Rd;
    insn.ucvtf_sisd64s.Rn = Rn;
    insn.ucvtf_sisd64s._unnamed_3 = 0b000000;
    insn.ucvtf_sisd64s.opcode = 0b101;
    insn.ucvtf_sisd64s.rmode = 0b11;
    insn.ucvtf_sisd64s._unnamed_2 = 0b1;
    insn.ucvtf_sisd64s.ftype = 0b00;
    insn.ucvtf_sisd64s._unnamed_1 = 0b11110;
    insn.ucvtf_sisd64s.S = 0b0;
    insn.ucvtf_sisd64s._unnamed_0 = 0b0;
    insn.ucvtf_sisd64s.sf = 0b1;
    return insn.raw;
}

// Decode function implementation
// Decode a float instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_float(uint32_t insn) {
    // Switch for mask 0xFFFFFC00u (179 patterns, 179 encodings)
    switch (insn & 0xFFFFFC00u) {
        case 0x1E200000u: { // FCVTNS_32S_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E204000u: { // FMOV_S_floatdp1
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E20C000u: { // FABS_S_floatdp1
                        Instruction result(Mnemonic::FABS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E210000u: { // FCVTNU_32S_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E214000u: { // FNEG_S_floatdp1
                        Instruction result(Mnemonic::FNEG, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E21C000u: { // FSQRT_S_floatdp1
                        Instruction result(Mnemonic::FSQRT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E220000u: { // SCVTF_S32_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E22C000u: { // FCVT_DS_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_ds_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_ds_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E230000u: { // UCVTF_S32_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E23C000u: { // FCVT_HS_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_hs_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_hs_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E240000u: { // FCVTAS_32S_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E244000u: { // FRINTN_S_floatdp1
                        Instruction result(Mnemonic::FRINTN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E24C000u: { // FRINTP_S_floatdp1
                        Instruction result(Mnemonic::FRINTP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E250000u: { // FCVTAU_32S_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E254000u: { // FRINTM_S_floatdp1
                        Instruction result(Mnemonic::FRINTM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E25C000u: { // FRINTZ_S_floatdp1
                        Instruction result(Mnemonic::FRINTZ, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E260000u: { // FMOV_32S_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E264000u: { // FRINTA_S_floatdp1
                        Instruction result(Mnemonic::FRINTA, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E270000u: { // FMOV_S32_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_s32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_s32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E274000u: { // FRINTX_S_floatdp1
                        Instruction result(Mnemonic::FRINTX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E27C000u: { // FRINTI_S_floatdp1
                        Instruction result(Mnemonic::FRINTI, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E280000u: { // FCVTPS_32S_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E284000u: { // FRINT32Z_S_floatdp1
                        Instruction result(Mnemonic::FRINT32Z, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32z_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32z_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E28C000u: { // FRINT32X_S_floatdp1
                        Instruction result(Mnemonic::FRINT32X, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32x_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32x_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E290000u: { // FCVTPU_32S_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E294000u: { // FRINT64Z_S_floatdp1
                        Instruction result(Mnemonic::FRINT64Z, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64z_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64z_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E29C000u: { // FRINT64X_S_floatdp1
                        Instruction result(Mnemonic::FRINT64X, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64x_sfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64x_sfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E300000u: { // FCVTMS_32S_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E310000u: { // FCVTMU_32S_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E380000u: { // FCVTZS_32S_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E390000u: { // FCVTZU_32S_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E600000u: { // FCVTNS_32D_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E604000u: { // FMOV_D_floatdp1
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E60C000u: { // FABS_D_floatdp1
                        Instruction result(Mnemonic::FABS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E610000u: { // FCVTNU_32D_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E614000u: { // FNEG_D_floatdp1
                        Instruction result(Mnemonic::FNEG, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E61C000u: { // FSQRT_D_floatdp1
                        Instruction result(Mnemonic::FSQRT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E620000u: { // SCVTF_D32_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E624000u: { // FCVT_SD_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_sd_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_sd_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E630000u: { // UCVTF_D32_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E634000u: { // BFCVT_BS_floatdp1
                        Instruction result(Mnemonic::BFCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.bfcvt_bs_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.bfcvt_bs_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E63C000u: { // FCVT_HD_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_hd_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_hd_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E640000u: { // FCVTAS_32D_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E644000u: { // FRINTN_D_floatdp1
                        Instruction result(Mnemonic::FRINTN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E64C000u: { // FRINTP_D_floatdp1
                        Instruction result(Mnemonic::FRINTP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E650000u: { // FCVTAU_32D_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E654000u: { // FRINTM_D_floatdp1
                        Instruction result(Mnemonic::FRINTM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E65C000u: { // FRINTZ_D_floatdp1
                        Instruction result(Mnemonic::FRINTZ, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E664000u: { // FRINTA_D_floatdp1
                        Instruction result(Mnemonic::FRINTA, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E674000u: { // FRINTX_D_floatdp1
                        Instruction result(Mnemonic::FRINTX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E67C000u: { // FRINTI_D_floatdp1
                        Instruction result(Mnemonic::FRINTI, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E680000u: { // FCVTPS_32D_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E684000u: { // FRINT32Z_D_floatdp1
                        Instruction result(Mnemonic::FRINT32Z, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32z_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32z_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E68C000u: { // FRINT32X_D_floatdp1
                        Instruction result(Mnemonic::FRINT32X, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32x_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint32x_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E690000u: { // FCVTPU_32D_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E694000u: { // FRINT64Z_D_floatdp1
                        Instruction result(Mnemonic::FRINT64Z, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64z_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64z_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E69C000u: { // FRINT64X_D_floatdp1
                        Instruction result(Mnemonic::FRINT64X, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64x_dfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frint64x_dfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1E6A0000u: { // FCVTNS_sisd_32D
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E6B0000u: { // FCVTNU_sisd_32D
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E700000u: { // FCVTMS_32D_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E710000u: { // FCVTMU_32D_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E720000u: { // FCVTPS_sisd_32D
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E730000u: { // FCVTPU_sisd_32D
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E740000u: { // FCVTMS_sisd_32D
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E750000u: { // FCVTMU_sisd_32D
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E760000u: { // FCVTZS_sisd_32D
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E770000u: { // FCVTZU_sisd_32D
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E780000u: { // FCVTZS_32D_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E790000u: { // FCVTZU_32D_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1E7A0000u: { // FCVTAS_sisd_32D
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E7B0000u: { // FCVTAU_sisd_32D
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E7C0000u: { // SCVTF_sisd_32D
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E7D0000u: { // UCVTF_sisd_32D
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd32d.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd32d.Rn, is_64bit));
                        return result;
        }
        case 0x1E7E0000u: { // FJCVTZS_32D_float2int
                        Instruction result(Mnemonic::FJCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fjcvtzs32d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fjcvtzs32d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE00000u: { // FCVTNS_32H_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE04000u: { // FMOV_H_floatdp1
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE0C000u: { // FABS_H_floatdp1
                        Instruction result(Mnemonic::FABS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fabs_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE10000u: { // FCVTNU_32H_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE14000u: { // FNEG_H_floatdp1
                        Instruction result(Mnemonic::FNEG, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fneg_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE1C000u: { // FSQRT_H_floatdp1
                        Instruction result(Mnemonic::FSQRT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsqrt_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE20000u: { // SCVTF_H32_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE24000u: { // FCVT_SH_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_sh_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_sh_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE2C000u: { // FCVT_DH_floatdp1
                        Instruction result(Mnemonic::FCVT, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_dh_floatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvt_dh_floatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE30000u: { // UCVTF_H32_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE40000u: { // FCVTAS_32H_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE44000u: { // FRINTN_H_floatdp1
                        Instruction result(Mnemonic::FRINTN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintn_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE4C000u: { // FRINTP_H_floatdp1
                        Instruction result(Mnemonic::FRINTP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintp_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE50000u: { // FCVTAU_32H_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE54000u: { // FRINTM_H_floatdp1
                        Instruction result(Mnemonic::FRINTM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintm_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE5C000u: { // FRINTZ_H_floatdp1
                        Instruction result(Mnemonic::FRINTZ, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintz_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE60000u: { // FMOV_32H_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE64000u: { // FRINTA_H_floatdp1
                        Instruction result(Mnemonic::FRINTA, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinta_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE70000u: { // FMOV_H32_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_h32float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_h32float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE74000u: { // FRINTX_H_floatdp1
                        Instruction result(Mnemonic::FRINTX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frintx_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE7C000u: { // FRINTI_H_floatdp1
                        Instruction result(Mnemonic::FRINTI, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_hfloatdp1.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.frinti_hfloatdp1.Rn, is_64bit));
                        return result;
        }
        case 0x1EE80000u: { // FCVTPS_32H_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EE90000u: { // FCVTPU_32H_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EEA0000u: { // FCVTNS_sisd_32H
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EEB0000u: { // FCVTNU_sisd_32H
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF00000u: { // FCVTMS_32H_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EF10000u: { // FCVTMU_32H_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EF20000u: { // FCVTPS_sisd_32H
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF30000u: { // FCVTPU_sisd_32H
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF40000u: { // FCVTMS_sisd_32H
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF50000u: { // FCVTMU_sisd_32H
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF60000u: { // FCVTZS_sisd_32H
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF70000u: { // FCVTZU_sisd_32H
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EF80000u: { // FCVTZS_32H_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EF90000u: { // FCVTZU_32H_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x1EFA0000u: { // FCVTAS_sisd_32H
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EFB0000u: { // FCVTAU_sisd_32H
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EFC0000u: { // SCVTF_sisd_32H
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x1EFD0000u: { // UCVTF_sisd_32H
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd32h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd32h.Rn, is_64bit));
                        return result;
        }
        case 0x9E200000u: { // FCVTNS_64S_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E210000u: { // FCVTNU_64S_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E220000u: { // SCVTF_S64_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E230000u: { // UCVTF_S64_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E240000u: { // FCVTAS_64S_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E250000u: { // FCVTAU_64S_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E280000u: { // FCVTPS_64S_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E290000u: { // FCVTPU_64S_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E2A0000u: { // FCVTNS_sisd_64S
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E2B0000u: { // FCVTNU_sisd_64S
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E300000u: { // FCVTMS_64S_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E310000u: { // FCVTMU_64S_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E320000u: { // FCVTPS_sisd_64S
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E330000u: { // FCVTPU_sisd_64S
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E340000u: { // FCVTMS_sisd_64S
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E350000u: { // FCVTMU_sisd_64S
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E360000u: { // FCVTZS_sisd_64S
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E370000u: { // FCVTZU_sisd_64S
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E380000u: { // FCVTZS_64S_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E390000u: { // FCVTZU_64S_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64s_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64s_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E3A0000u: { // FCVTAS_sisd_64S
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E3B0000u: { // FCVTAU_sisd_64S
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E3C0000u: { // SCVTF_sisd_64S
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E3D0000u: { // UCVTF_sisd_64S
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd64s.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd64s.Rn, is_64bit));
                        return result;
        }
        case 0x9E600000u: { // FCVTNS_64D_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E610000u: { // FCVTNU_64D_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E620000u: { // SCVTF_D64_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E630000u: { // UCVTF_D64_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E640000u: { // FCVTAS_64D_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E650000u: { // FCVTAU_64D_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E660000u: { // FMOV_64D_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E670000u: { // FMOV_D64_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_d64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_d64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E680000u: { // FCVTPS_64D_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E690000u: { // FCVTPU_64D_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E700000u: { // FCVTMS_64D_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E710000u: { // FCVTMU_64D_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E780000u: { // FCVTZS_64D_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9E790000u: { // FCVTZU_64D_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64d_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64d_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EAE0000u: { // FMOV_64VX_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64vx_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64vx_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EAF0000u: { // FMOV_V64I_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_v64i_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_v64i_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE00000u: { // FCVTNS_64H_float2int
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE10000u: { // FCVTNU_64H_float2int
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE20000u: { // SCVTF_H64_float2int
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE30000u: { // UCVTF_H64_float2int
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE40000u: { // FCVTAS_64H_float2int
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE50000u: { // FCVTAU_64H_float2int
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE60000u: { // FMOV_64H_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE70000u: { // FMOV_H64_float2int
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_h64float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_h64float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE80000u: { // FCVTPS_64H_float2int
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EE90000u: { // FCVTPU_64H_float2int
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EEA0000u: { // FCVTNS_sisd_64H
                        Instruction result(Mnemonic::FCVTNS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtns_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EEB0000u: { // FCVTNU_sisd_64H
                        Instruction result(Mnemonic::FCVTNU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtnu_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF00000u: { // FCVTMS_64H_float2int
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EF10000u: { // FCVTMU_64H_float2int
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EF20000u: { // FCVTPS_sisd_64H
                        Instruction result(Mnemonic::FCVTPS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtps_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF30000u: { // FCVTPU_sisd_64H
                        Instruction result(Mnemonic::FCVTPU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtpu_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF40000u: { // FCVTMS_sisd_64H
                        Instruction result(Mnemonic::FCVTMS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtms_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF50000u: { // FCVTMU_sisd_64H
                        Instruction result(Mnemonic::FCVTMU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtmu_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF60000u: { // FCVTZS_sisd_64H
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF70000u: { // FCVTZU_sisd_64H
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EF80000u: { // FCVTZS_64H_float2int
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EF90000u: { // FCVTZU_64H_float2int
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64h_float2int.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64h_float2int.Rn, is_64bit));
                        return result;
        }
        case 0x9EFA0000u: { // FCVTAS_sisd_64H
                        Instruction result(Mnemonic::FCVTAS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtas_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EFB0000u: { // FCVTAU_sisd_64H
                        Instruction result(Mnemonic::FCVTAU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtau_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EFC0000u: { // SCVTF_sisd_64H
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_sisd64h.Rn, is_64bit));
                        return result;
        }
        case 0x9EFD0000u: { // UCVTF_sisd_64H
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd64h.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_sisd64h.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFF0000u (24 patterns, 24 encodings)
    switch (insn & 0xFFFF0000u) {
        case 0x1E020000u: { // SCVTF_S32_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E030000u: { // UCVTF_S32_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E180000u: { // FCVTZS_32S_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32s_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32s_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E190000u: { // FCVTZU_32S_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32s_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32s_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E420000u: { // SCVTF_D32_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E430000u: { // UCVTF_D32_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E580000u: { // FCVTZS_32D_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32d_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32d_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1E590000u: { // FCVTZU_32D_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32d_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32d_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1EC20000u: { // SCVTF_H32_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1EC30000u: { // UCVTF_H32_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h32float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h32float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1ED80000u: { // FCVTZS_32H_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32h_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs32h_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x1ED90000u: { // FCVTZU_32H_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32h_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu32h_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E020000u: { // SCVTF_S64_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_s64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E030000u: { // UCVTF_S64_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_s64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E180000u: { // FCVTZS_64S_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64s_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64s_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E190000u: { // FCVTZU_64S_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64s_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64s_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E420000u: { // SCVTF_D64_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_d64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E430000u: { // UCVTF_D64_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_d64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E580000u: { // FCVTZS_64D_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64d_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64d_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9E590000u: { // FCVTZU_64D_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64d_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64d_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9EC20000u: { // SCVTF_H64_float2fix
                        Instruction result(Mnemonic::SCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.scvtf_h64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9EC30000u: { // UCVTF_H64_float2fix
                        Instruction result(Mnemonic::UCVTF, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h64float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ucvtf_h64float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9ED80000u: { // FCVTZS_64H_float2fix
                        Instruction result(Mnemonic::FCVTZS, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64h_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzs64h_float2fix.Rn, is_64bit));
                        return result;
        }
        case 0x9ED90000u: { // FCVTZU_64H_float2fix
                        Instruction result(Mnemonic::FCVTZU, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64h_float2fix.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcvtzu64h_float2fix.Rn, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0FC1Fu (12 patterns, 12 encodings)
    switch (insn & 0xFFE0FC1Fu) {
        case 0x1E202000u: { // FCMP_S_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_sfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_sfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E202008u: { // FCMP_SZ_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_sz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_sz_floatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E202010u: { // FCMPE_S_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_sfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_sfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E202018u: { // FCMPE_SZ_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_sz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_sz_floatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E602000u: { // FCMP_D_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_dfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_dfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E602008u: { // FCMP_DZ_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_dz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_dz_floatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E602010u: { // FCMPE_D_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_dfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_dfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1E602018u: { // FCMPE_DZ_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_dz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_dz_floatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1EE02000u: { // FCMP_H_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_hfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_hfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1EE02008u: { // FCMP_HZ_floatcmp
                        Instruction result(Mnemonic::FCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_hz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmp_hz_floatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1EE02010u: { // FCMPE_H_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_hfloatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_hfloatcmp.Rm, is_64bit));
                        return result;
        }
        case 0x1EE02018u: { // FCMPE_HZ_floatcmp
                        Instruction result(Mnemonic::FCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_hz_floatcmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcmpe_hz_floatcmp.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0FC00u (27 patterns, 27 encodings)
    switch (insn & 0xFFE0FC00u) {
        case 0x1E200800u: { // FMUL_S_floatdp2
                        Instruction result(Mnemonic::FMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E201800u: { // FDIV_S_floatdp2
                        Instruction result(Mnemonic::FDIV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E202800u: { // FADD_S_floatdp2
                        Instruction result(Mnemonic::FADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E203800u: { // FSUB_S_floatdp2
                        Instruction result(Mnemonic::FSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E204800u: { // FMAX_S_floatdp2
                        Instruction result(Mnemonic::FMAX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E205800u: { // FMIN_S_floatdp2
                        Instruction result(Mnemonic::FMIN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E206800u: { // FMAXNM_S_floatdp2
                        Instruction result(Mnemonic::FMAXNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E207800u: { // FMINNM_S_floatdp2
                        Instruction result(Mnemonic::FMINNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E208800u: { // FNMUL_S_floatdp2
                        Instruction result(Mnemonic::FNMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_sfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_sfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_sfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E600800u: { // FMUL_D_floatdp2
                        Instruction result(Mnemonic::FMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E601800u: { // FDIV_D_floatdp2
                        Instruction result(Mnemonic::FDIV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E602800u: { // FADD_D_floatdp2
                        Instruction result(Mnemonic::FADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E603800u: { // FSUB_D_floatdp2
                        Instruction result(Mnemonic::FSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E604800u: { // FMAX_D_floatdp2
                        Instruction result(Mnemonic::FMAX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E605800u: { // FMIN_D_floatdp2
                        Instruction result(Mnemonic::FMIN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E606800u: { // FMAXNM_D_floatdp2
                        Instruction result(Mnemonic::FMAXNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E607800u: { // FMINNM_D_floatdp2
                        Instruction result(Mnemonic::FMINNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1E608800u: { // FNMUL_D_floatdp2
                        Instruction result(Mnemonic::FNMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_dfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_dfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_dfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE00800u: { // FMUL_H_floatdp2
                        Instruction result(Mnemonic::FMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmul_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE01800u: { // FDIV_H_floatdp2
                        Instruction result(Mnemonic::FDIV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fdiv_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE02800u: { // FADD_H_floatdp2
                        Instruction result(Mnemonic::FADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fadd_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE03800u: { // FSUB_H_floatdp2
                        Instruction result(Mnemonic::FSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fsub_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE04800u: { // FMAX_H_floatdp2
                        Instruction result(Mnemonic::FMAX, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmax_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE05800u: { // FMIN_H_floatdp2
                        Instruction result(Mnemonic::FMIN, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmin_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE06800u: { // FMAXNM_H_floatdp2
                        Instruction result(Mnemonic::FMAXNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmaxnm_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE07800u: { // FMINNM_H_floatdp2
                        Instruction result(Mnemonic::FMINNM, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fminnm_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        case 0x1EE08800u: { // FNMUL_H_floatdp2
                        Instruction result(Mnemonic::FNMUL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_hfloatdp2.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_hfloatdp2.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmul_hfloatdp2.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE08000u (12 patterns, 12 encodings)
    switch (insn & 0xFFE08000u) {
        case 0x1F000000u: { // FMADD_S_floatdp3
                        Instruction result(Mnemonic::FMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_sfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_sfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_sfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_sfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F008000u: { // FMSUB_S_floatdp3
                        Instruction result(Mnemonic::FMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_sfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_sfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_sfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_sfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F200000u: { // FNMADD_S_floatdp3
                        Instruction result(Mnemonic::FNMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_sfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_sfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_sfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_sfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F208000u: { // FNMSUB_S_floatdp3
                        Instruction result(Mnemonic::FNMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_sfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_sfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_sfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_sfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F400000u: { // FMADD_D_floatdp3
                        Instruction result(Mnemonic::FMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_dfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_dfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_dfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_dfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F408000u: { // FMSUB_D_floatdp3
                        Instruction result(Mnemonic::FMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_dfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_dfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_dfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_dfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F600000u: { // FNMADD_D_floatdp3
                        Instruction result(Mnemonic::FNMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_dfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_dfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_dfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_dfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1F608000u: { // FNMSUB_D_floatdp3
                        Instruction result(Mnemonic::FNMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_dfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_dfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_dfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_dfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1FC00000u: { // FMADD_H_floatdp3
                        Instruction result(Mnemonic::FMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_hfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_hfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_hfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmadd_hfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1FC08000u: { // FMSUB_H_floatdp3
                        Instruction result(Mnemonic::FMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_hfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_hfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_hfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fmsub_hfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1FE00000u: { // FNMADD_H_floatdp3
                        Instruction result(Mnemonic::FNMADD, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_hfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_hfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_hfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmadd_hfloatdp3.Ra, is_64bit));
                        return result;
        }
        case 0x1FE08000u: { // FNMSUB_H_floatdp3
                        Instruction result(Mnemonic::FNMSUB, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_hfloatdp3.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_hfloatdp3.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_hfloatdp3.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fnmsub_hfloatdp3.Ra, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE01FE0u (3 patterns, 3 encodings)
    switch (insn & 0xFFE01FE0u) {
        case 0x1E201000u: { // FMOV_S_floatimm
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_sfloatimm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.fmov_sfloatimm.imm8, true));
                        return result;
        }
        case 0x1E601000u: { // FMOV_D_floatimm
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_dfloatimm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.fmov_dfloatimm.imm8, true));
                        return result;
        }
        case 0x1EE01000u: { // FMOV_H_floatimm
                        Instruction result(Mnemonic::FMOV, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fmov_hfloatimm.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.fmov_hfloatimm.imm8, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C10u (6 patterns, 6 encodings)
    switch (insn & 0xFFE00C10u) {
        case 0x1E200400u: { // FCCMP_S_floatccmp
                        Instruction result(Mnemonic::FCCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_sfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_sfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmp_sfloatccmp.cond, true));
                        return result;
        }
        case 0x1E200410u: { // FCCMPE_S_floatccmp
                        Instruction result(Mnemonic::FCCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_sfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_sfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmpe_sfloatccmp.cond, true));
                        return result;
        }
        case 0x1E600400u: { // FCCMP_D_floatccmp
                        Instruction result(Mnemonic::FCCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_dfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_dfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmp_dfloatccmp.cond, true));
                        return result;
        }
        case 0x1E600410u: { // FCCMPE_D_floatccmp
                        Instruction result(Mnemonic::FCCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_dfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_dfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmpe_dfloatccmp.cond, true));
                        return result;
        }
        case 0x1EE00400u: { // FCCMP_H_floatccmp
                        Instruction result(Mnemonic::FCCMP, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_hfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmp_hfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmp_hfloatccmp.cond, true));
                        return result;
        }
        case 0x1EE00410u: { // FCCMPE_H_floatccmp
                        Instruction result(Mnemonic::FCCMPE, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_hfloatccmp.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fccmpe_hfloatccmp.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fccmpe_hfloatccmp.cond, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C00u (3 patterns, 3 encodings)
    switch (insn & 0xFFE00C00u) {
        case 0x1E200C00u: { // FCSEL_S_floatsel
                        Instruction result(Mnemonic::FCSEL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_sfloatsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_sfloatsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_sfloatsel.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fcsel_sfloatsel.cond, true));
                        return result;
        }
        case 0x1E600C00u: { // FCSEL_D_floatsel
                        Instruction result(Mnemonic::FCSEL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_dfloatsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_dfloatsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_dfloatsel.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fcsel_dfloatsel.cond, true));
                        return result;
        }
        case 0x1EE00C00u: { // FCSEL_H_floatsel
                        Instruction result(Mnemonic::FCSEL, insn);
                        FloatEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_hfloatsel.Rd, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_hfloatsel.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.fcsel_hfloatsel.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Condition, enc.fcsel_hfloatsel.cond, true));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace Float
} // namespace veda64
