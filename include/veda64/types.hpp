// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {

// ARM64 condition codes
enum class Condition : int8_t {
    None = -1,
    EQ = 0,   // Equal
    NE = 1,   // Not equal
    CS = 2,   // Carry set / unsigned higher or same (HS)
    CC = 3,   // Carry clear / unsigned lower (LO)
    MI = 4,   // Minus / negative
    PL = 5,   // Plus / positive or zero
    VS = 6,   // Overflow
    VC = 7,   // No overflow
    HI = 8,   // Unsigned higher
    LS = 9,   // Unsigned lower or same
    GE = 10,  // Signed greater than or equal
    LT = 11,  // Signed less than
    GT = 12,  // Signed greater than
    LE = 13,  // Signed less than or equal
    AL = 14,  // Always
    NV = 15   // Never (behaves like AL)
};

// Operand type enumeration
enum class OperandType : uint8_t {
    Register,           // Any register (GP, Vector, SVE, Predicate — distinguished by Register enum value)
    SMETileRegister,    // SME tile register (ZAn) — special display semantics
    Immediate,          // Immediate value
    SignedImmediate,    // Signed immediate value
    Memory,             // Memory operand [base{, #offset}] — mode in extend byte
    MemoryRegOffset,    // Memory operand [base, Rm{, extend {#amount}}]
    MemorySVEOffset,    // SVE gather memory [Zn.T, #offset]
    Label,              // Branch target label/offset
    Relative,          // PC-relative offset for branches
    SystemRegister,     // System register
    Shift,              // Shift specifier (LSL, LSR, ASR, ROR)
    Extend,             // Extend specifier (UXTB, SXTW, etc.)
    Index,              // Element index
    Pattern,            // SVE pattern specifier
    SVEMulImm,          // SVE mul multiplier (MUL #N where N=imm4+1)
    Prefetch,           // Prefetch operation
    Barrier,            // Barrier option
    FloatImmediate,     // Floating-point immediate (#0.0, etc.)
    RegisterList,       // Register list { Rt.T, Rt+1.T, ... } — first element type distinguishes V/Z/P
    PstateField,        // PSTATE field name for MSR/MRS immediate (SPSel, DAIFSet, etc.)
    FixedSym,           // Fixed symbolic operand (e.g. CSYNC, DSYNC)
    SysOp,              // SYS alias operation name (tlbi vmalle1 etc.)
    SVEVLxImm,          // SVE VL specifier (vlx2 or vlx4) for WHILE* pn_rr
    Unknown
};

// Memory addressing mode (stored in extend byte for OperandType::Memory)
enum class MemoryMode : uint8_t {
    Base = 0,      // [base]
    Offset = 1,    // [base, #offset]
    PreIndex = 2,  // [base, #offset]!
    PostIndex = 3, // [base], #offset
    MulVL = 4,     // [base, #offset, mul vl]
};

// Vector arrangement specifier
enum class Arrangement : uint8_t {
    None = 0,
    B, H, S, D, Q,           // Scalar element sizes
    B8, H4, S2, D1,           // 64-bit vector
    B16, H8, S4, D2,          // 128-bit vector
    Q1, B2, B4, H2,           // Special
};

enum class Register : uint16_t {
    W0 = 0,
    W1 = 1,
    W2 = 2,
    W3 = 3,
    W4 = 4,
    W5 = 5,
    W6 = 6,
    W7 = 7,
    W8 = 8,
    W9 = 9,
    W10 = 10,
    W11 = 11,
    W12 = 12,
    W13 = 13,
    W14 = 14,
    W15 = 15,
    W16 = 16,
    W17 = 17,
    W18 = 18,
    W19 = 19,
    W20 = 20,
    W21 = 21,
    W22 = 22,
    W23 = 23,
    W24 = 24,
    W25 = 25,
    W26 = 26,
    W27 = 27,
    W28 = 28,
    W29 = 29,
    W30 = 30,
    WZR = 31, WSP = 32,
    X0 = 33,
    X1 = 34,
    X2 = 35,
    X3 = 36,
    X4 = 37,
    X5 = 38,
    X6 = 39,
    X7 = 40,
    X8 = 41,
    X9 = 42,
    X10 = 43,
    X11 = 44,
    X12 = 45,
    X13 = 46,
    X14 = 47,
    X15 = 48,
    X16 = 49,
    X17 = 50,
    X18 = 51,
    X19 = 52,
    X20 = 53,
    X21 = 54,
    X22 = 55,
    X23 = 56,
    X24 = 57,
    X25 = 58,
    X26 = 59,
    X27 = 60,
    X28 = 61,
    X29 = 62,
    X30 = 63,
    XZR = 64, SP = 65,
    B0 = 66,
    B1 = 67,
    B2 = 68,
    B3 = 69,
    B4 = 70,
    B5 = 71,
    B6 = 72,
    B7 = 73,
    B8 = 74,
    B9 = 75,
    B10 = 76,
    B11 = 77,
    B12 = 78,
    B13 = 79,
    B14 = 80,
    B15 = 81,
    B16 = 82,
    B17 = 83,
    B18 = 84,
    B19 = 85,
    B20 = 86,
    B21 = 87,
    B22 = 88,
    B23 = 89,
    B24 = 90,
    B25 = 91,
    B26 = 92,
    B27 = 93,
    B28 = 94,
    B29 = 95,
    B30 = 96,
    B31 = 97,
    H0 = 98,
    H1 = 99,
    H2 = 100,
    H3 = 101,
    H4 = 102,
    H5 = 103,
    H6 = 104,
    H7 = 105,
    H8 = 106,
    H9 = 107,
    H10 = 108,
    H11 = 109,
    H12 = 110,
    H13 = 111,
    H14 = 112,
    H15 = 113,
    H16 = 114,
    H17 = 115,
    H18 = 116,
    H19 = 117,
    H20 = 118,
    H21 = 119,
    H22 = 120,
    H23 = 121,
    H24 = 122,
    H25 = 123,
    H26 = 124,
    H27 = 125,
    H28 = 126,
    H29 = 127,
    H30 = 128,
    H31 = 129,
    S0 = 130,
    S1 = 131,
    S2 = 132,
    S3 = 133,
    S4 = 134,
    S5 = 135,
    S6 = 136,
    S7 = 137,
    S8 = 138,
    S9 = 139,
    S10 = 140,
    S11 = 141,
    S12 = 142,
    S13 = 143,
    S14 = 144,
    S15 = 145,
    S16 = 146,
    S17 = 147,
    S18 = 148,
    S19 = 149,
    S20 = 150,
    S21 = 151,
    S22 = 152,
    S23 = 153,
    S24 = 154,
    S25 = 155,
    S26 = 156,
    S27 = 157,
    S28 = 158,
    S29 = 159,
    S30 = 160,
    S31 = 161,
    D0 = 162,
    D1 = 163,
    D2 = 164,
    D3 = 165,
    D4 = 166,
    D5 = 167,
    D6 = 168,
    D7 = 169,
    D8 = 170,
    D9 = 171,
    D10 = 172,
    D11 = 173,
    D12 = 174,
    D13 = 175,
    D14 = 176,
    D15 = 177,
    D16 = 178,
    D17 = 179,
    D18 = 180,
    D19 = 181,
    D20 = 182,
    D21 = 183,
    D22 = 184,
    D23 = 185,
    D24 = 186,
    D25 = 187,
    D26 = 188,
    D27 = 189,
    D28 = 190,
    D29 = 191,
    D30 = 192,
    D31 = 193,
    Q0 = 194,
    Q1 = 195,
    Q2 = 196,
    Q3 = 197,
    Q4 = 198,
    Q5 = 199,
    Q6 = 200,
    Q7 = 201,
    Q8 = 202,
    Q9 = 203,
    Q10 = 204,
    Q11 = 205,
    Q12 = 206,
    Q13 = 207,
    Q14 = 208,
    Q15 = 209,
    Q16 = 210,
    Q17 = 211,
    Q18 = 212,
    Q19 = 213,
    Q20 = 214,
    Q21 = 215,
    Q22 = 216,
    Q23 = 217,
    Q24 = 218,
    Q25 = 219,
    Q26 = 220,
    Q27 = 221,
    Q28 = 222,
    Q29 = 223,
    Q30 = 224,
    Q31 = 225,
    V0 = 226,
    V1 = 227,
    V2 = 228,
    V3 = 229,
    V4 = 230,
    V5 = 231,
    V6 = 232,
    V7 = 233,
    V8 = 234,
    V9 = 235,
    V10 = 236,
    V11 = 237,
    V12 = 238,
    V13 = 239,
    V14 = 240,
    V15 = 241,
    V16 = 242,
    V17 = 243,
    V18 = 244,
    V19 = 245,
    V20 = 246,
    V21 = 247,
    V22 = 248,
    V23 = 249,
    V24 = 250,
    V25 = 251,
    V26 = 252,
    V27 = 253,
    V28 = 254,
    V29 = 255,
    V30 = 256,
    V31 = 257,
    Z0 = 258,
    Z1 = 259,
    Z2 = 260,
    Z3 = 261,
    Z4 = 262,
    Z5 = 263,
    Z6 = 264,
    Z7 = 265,
    Z8 = 266,
    Z9 = 267,
    Z10 = 268,
    Z11 = 269,
    Z12 = 270,
    Z13 = 271,
    Z14 = 272,
    Z15 = 273,
    Z16 = 274,
    Z17 = 275,
    Z18 = 276,
    Z19 = 277,
    Z20 = 278,
    Z21 = 279,
    Z22 = 280,
    Z23 = 281,
    Z24 = 282,
    Z25 = 283,
    Z26 = 284,
    Z27 = 285,
    Z28 = 286,
    Z29 = 287,
    Z30 = 288,
    Z31 = 289,
    P0 = 290,
    P1 = 291,
    P2 = 292,
    P3 = 293,
    P4 = 294,
    P5 = 295,
    P6 = 296,
    P7 = 297,
    P8 = 298,
    P9 = 299,
    P10 = 300,
    P11 = 301,
    P12 = 302,
    P13 = 303,
    P14 = 304,
    P15 = 305,
    PN0 = 306,
    PN1 = 307,
    PN2 = 308,
    PN3 = 309,
    PN4 = 310,
    PN5 = 311,
    PN6 = 312,
    PN7 = 313,
    PN8 = 314,
    PN9 = 315,
    PN10 = 316,
    PN11 = 317,
    PN12 = 318,
    PN13 = 319,
    PN14 = 320,
    PN15 = 321,
    ZA0 = 322,
    ZA1 = 323,
    ZA2 = 324,
    ZA3 = 325,
    ZA4 = 326,
    ZA5 = 327,
    ZA6 = 328,
    ZA7 = 329,
    ZA = 330, ZT0 = 331,
};

inline constexpr Register make_gp_reg(uint32_t num, bool is_64, bool is_sp = false) {
    if (is_64) {
        if (num == 31) return is_sp ? Register::SP : Register::XZR;
        return static_cast<Register>(33 + num);
    } else {
        if (num == 31) return is_sp ? Register::WSP : Register::WZR;
        return static_cast<Register>(num);
    }
}

inline constexpr Register make_scalar_reg(uint32_t num, Arrangement size) {
    // size: B=1,H=2,S=3,D=4,Q=5
    switch (size) {
        case Arrangement::B: return static_cast<Register>(66 + num);
        case Arrangement::H: return static_cast<Register>(98 + num);
        case Arrangement::S: return static_cast<Register>(130 + num);
        case Arrangement::D: return static_cast<Register>(162 + num);
        case Arrangement::Q: return static_cast<Register>(194 + num);
        default: return static_cast<Register>(num);
    }
}

inline constexpr Register make_vec_reg(uint32_t num) {
    return static_cast<Register>(226 + num); // V0=226
}

inline constexpr Register make_sve_reg(uint32_t num) {
    return static_cast<Register>(258 + num); // Z0=258
}

inline constexpr Register make_pred_reg(uint32_t num) {
    return static_cast<Register>(290 + num); // P0=290
}

inline constexpr Register make_predn_reg(uint32_t num) {
    return static_cast<Register>(306 + num); // PN0=306
}

inline constexpr uint32_t register_num(Register r) {
    auto v = static_cast<uint16_t>(r);
    if (v <= 32) return (v <= 30) ? v : 31;
    if (v <= 65) return (v <= 63) ? v - 33 : 31;
    if (v <= 289) return (v - 66) % 32;
    if (v <= 321) return (v - 290) % 16;
    return 0;
}

inline constexpr bool register_is_64bit(Register r) {
    auto v = static_cast<uint16_t>(r);
    return v >= 33 && v <= 65; // X0..XZR, SP
}

inline constexpr bool register_is_sp(Register r) {
    return r == Register::SP || r == Register::WSP;
}

#ifndef VEDA64_NO_STRINGS
inline const char* register_to_string(Register r) {
    switch (r) {
    case Register::W0: return "w0";
    case Register::W1: return "w1";
    case Register::W2: return "w2";
    case Register::W3: return "w3";
    case Register::W4: return "w4";
    case Register::W5: return "w5";
    case Register::W6: return "w6";
    case Register::W7: return "w7";
    case Register::W8: return "w8";
    case Register::W9: return "w9";
    case Register::W10: return "w10";
    case Register::W11: return "w11";
    case Register::W12: return "w12";
    case Register::W13: return "w13";
    case Register::W14: return "w14";
    case Register::W15: return "w15";
    case Register::W16: return "w16";
    case Register::W17: return "w17";
    case Register::W18: return "w18";
    case Register::W19: return "w19";
    case Register::W20: return "w20";
    case Register::W21: return "w21";
    case Register::W22: return "w22";
    case Register::W23: return "w23";
    case Register::W24: return "w24";
    case Register::W25: return "w25";
    case Register::W26: return "w26";
    case Register::W27: return "w27";
    case Register::W28: return "w28";
    case Register::W29: return "w29";
    case Register::W30: return "w30";
    case Register::WZR: return "wzr";
    case Register::WSP: return "wsp";
    case Register::X0: return "x0";
    case Register::X1: return "x1";
    case Register::X2: return "x2";
    case Register::X3: return "x3";
    case Register::X4: return "x4";
    case Register::X5: return "x5";
    case Register::X6: return "x6";
    case Register::X7: return "x7";
    case Register::X8: return "x8";
    case Register::X9: return "x9";
    case Register::X10: return "x10";
    case Register::X11: return "x11";
    case Register::X12: return "x12";
    case Register::X13: return "x13";
    case Register::X14: return "x14";
    case Register::X15: return "x15";
    case Register::X16: return "x16";
    case Register::X17: return "x17";
    case Register::X18: return "x18";
    case Register::X19: return "x19";
    case Register::X20: return "x20";
    case Register::X21: return "x21";
    case Register::X22: return "x22";
    case Register::X23: return "x23";
    case Register::X24: return "x24";
    case Register::X25: return "x25";
    case Register::X26: return "x26";
    case Register::X27: return "x27";
    case Register::X28: return "x28";
    case Register::X29: return "x29";
    case Register::X30: return "x30";
    case Register::XZR: return "xzr";
    case Register::SP: return "sp";
    case Register::B0: return "b0";
    case Register::B1: return "b1";
    case Register::B2: return "b2";
    case Register::B3: return "b3";
    case Register::B4: return "b4";
    case Register::B5: return "b5";
    case Register::B6: return "b6";
    case Register::B7: return "b7";
    case Register::B8: return "b8";
    case Register::B9: return "b9";
    case Register::B10: return "b10";
    case Register::B11: return "b11";
    case Register::B12: return "b12";
    case Register::B13: return "b13";
    case Register::B14: return "b14";
    case Register::B15: return "b15";
    case Register::B16: return "b16";
    case Register::B17: return "b17";
    case Register::B18: return "b18";
    case Register::B19: return "b19";
    case Register::B20: return "b20";
    case Register::B21: return "b21";
    case Register::B22: return "b22";
    case Register::B23: return "b23";
    case Register::B24: return "b24";
    case Register::B25: return "b25";
    case Register::B26: return "b26";
    case Register::B27: return "b27";
    case Register::B28: return "b28";
    case Register::B29: return "b29";
    case Register::B30: return "b30";
    case Register::B31: return "b31";
    case Register::H0: return "h0";
    case Register::H1: return "h1";
    case Register::H2: return "h2";
    case Register::H3: return "h3";
    case Register::H4: return "h4";
    case Register::H5: return "h5";
    case Register::H6: return "h6";
    case Register::H7: return "h7";
    case Register::H8: return "h8";
    case Register::H9: return "h9";
    case Register::H10: return "h10";
    case Register::H11: return "h11";
    case Register::H12: return "h12";
    case Register::H13: return "h13";
    case Register::H14: return "h14";
    case Register::H15: return "h15";
    case Register::H16: return "h16";
    case Register::H17: return "h17";
    case Register::H18: return "h18";
    case Register::H19: return "h19";
    case Register::H20: return "h20";
    case Register::H21: return "h21";
    case Register::H22: return "h22";
    case Register::H23: return "h23";
    case Register::H24: return "h24";
    case Register::H25: return "h25";
    case Register::H26: return "h26";
    case Register::H27: return "h27";
    case Register::H28: return "h28";
    case Register::H29: return "h29";
    case Register::H30: return "h30";
    case Register::H31: return "h31";
    case Register::S0: return "s0";
    case Register::S1: return "s1";
    case Register::S2: return "s2";
    case Register::S3: return "s3";
    case Register::S4: return "s4";
    case Register::S5: return "s5";
    case Register::S6: return "s6";
    case Register::S7: return "s7";
    case Register::S8: return "s8";
    case Register::S9: return "s9";
    case Register::S10: return "s10";
    case Register::S11: return "s11";
    case Register::S12: return "s12";
    case Register::S13: return "s13";
    case Register::S14: return "s14";
    case Register::S15: return "s15";
    case Register::S16: return "s16";
    case Register::S17: return "s17";
    case Register::S18: return "s18";
    case Register::S19: return "s19";
    case Register::S20: return "s20";
    case Register::S21: return "s21";
    case Register::S22: return "s22";
    case Register::S23: return "s23";
    case Register::S24: return "s24";
    case Register::S25: return "s25";
    case Register::S26: return "s26";
    case Register::S27: return "s27";
    case Register::S28: return "s28";
    case Register::S29: return "s29";
    case Register::S30: return "s30";
    case Register::S31: return "s31";
    case Register::D0: return "d0";
    case Register::D1: return "d1";
    case Register::D2: return "d2";
    case Register::D3: return "d3";
    case Register::D4: return "d4";
    case Register::D5: return "d5";
    case Register::D6: return "d6";
    case Register::D7: return "d7";
    case Register::D8: return "d8";
    case Register::D9: return "d9";
    case Register::D10: return "d10";
    case Register::D11: return "d11";
    case Register::D12: return "d12";
    case Register::D13: return "d13";
    case Register::D14: return "d14";
    case Register::D15: return "d15";
    case Register::D16: return "d16";
    case Register::D17: return "d17";
    case Register::D18: return "d18";
    case Register::D19: return "d19";
    case Register::D20: return "d20";
    case Register::D21: return "d21";
    case Register::D22: return "d22";
    case Register::D23: return "d23";
    case Register::D24: return "d24";
    case Register::D25: return "d25";
    case Register::D26: return "d26";
    case Register::D27: return "d27";
    case Register::D28: return "d28";
    case Register::D29: return "d29";
    case Register::D30: return "d30";
    case Register::D31: return "d31";
    case Register::Q0: return "q0";
    case Register::Q1: return "q1";
    case Register::Q2: return "q2";
    case Register::Q3: return "q3";
    case Register::Q4: return "q4";
    case Register::Q5: return "q5";
    case Register::Q6: return "q6";
    case Register::Q7: return "q7";
    case Register::Q8: return "q8";
    case Register::Q9: return "q9";
    case Register::Q10: return "q10";
    case Register::Q11: return "q11";
    case Register::Q12: return "q12";
    case Register::Q13: return "q13";
    case Register::Q14: return "q14";
    case Register::Q15: return "q15";
    case Register::Q16: return "q16";
    case Register::Q17: return "q17";
    case Register::Q18: return "q18";
    case Register::Q19: return "q19";
    case Register::Q20: return "q20";
    case Register::Q21: return "q21";
    case Register::Q22: return "q22";
    case Register::Q23: return "q23";
    case Register::Q24: return "q24";
    case Register::Q25: return "q25";
    case Register::Q26: return "q26";
    case Register::Q27: return "q27";
    case Register::Q28: return "q28";
    case Register::Q29: return "q29";
    case Register::Q30: return "q30";
    case Register::Q31: return "q31";
    case Register::V0: return "v0";
    case Register::V1: return "v1";
    case Register::V2: return "v2";
    case Register::V3: return "v3";
    case Register::V4: return "v4";
    case Register::V5: return "v5";
    case Register::V6: return "v6";
    case Register::V7: return "v7";
    case Register::V8: return "v8";
    case Register::V9: return "v9";
    case Register::V10: return "v10";
    case Register::V11: return "v11";
    case Register::V12: return "v12";
    case Register::V13: return "v13";
    case Register::V14: return "v14";
    case Register::V15: return "v15";
    case Register::V16: return "v16";
    case Register::V17: return "v17";
    case Register::V18: return "v18";
    case Register::V19: return "v19";
    case Register::V20: return "v20";
    case Register::V21: return "v21";
    case Register::V22: return "v22";
    case Register::V23: return "v23";
    case Register::V24: return "v24";
    case Register::V25: return "v25";
    case Register::V26: return "v26";
    case Register::V27: return "v27";
    case Register::V28: return "v28";
    case Register::V29: return "v29";
    case Register::V30: return "v30";
    case Register::V31: return "v31";
    case Register::Z0: return "z0";
    case Register::Z1: return "z1";
    case Register::Z2: return "z2";
    case Register::Z3: return "z3";
    case Register::Z4: return "z4";
    case Register::Z5: return "z5";
    case Register::Z6: return "z6";
    case Register::Z7: return "z7";
    case Register::Z8: return "z8";
    case Register::Z9: return "z9";
    case Register::Z10: return "z10";
    case Register::Z11: return "z11";
    case Register::Z12: return "z12";
    case Register::Z13: return "z13";
    case Register::Z14: return "z14";
    case Register::Z15: return "z15";
    case Register::Z16: return "z16";
    case Register::Z17: return "z17";
    case Register::Z18: return "z18";
    case Register::Z19: return "z19";
    case Register::Z20: return "z20";
    case Register::Z21: return "z21";
    case Register::Z22: return "z22";
    case Register::Z23: return "z23";
    case Register::Z24: return "z24";
    case Register::Z25: return "z25";
    case Register::Z26: return "z26";
    case Register::Z27: return "z27";
    case Register::Z28: return "z28";
    case Register::Z29: return "z29";
    case Register::Z30: return "z30";
    case Register::Z31: return "z31";
    case Register::P0: return "p0";
    case Register::P1: return "p1";
    case Register::P2: return "p2";
    case Register::P3: return "p3";
    case Register::P4: return "p4";
    case Register::P5: return "p5";
    case Register::P6: return "p6";
    case Register::P7: return "p7";
    case Register::P8: return "p8";
    case Register::P9: return "p9";
    case Register::P10: return "p10";
    case Register::P11: return "p11";
    case Register::P12: return "p12";
    case Register::P13: return "p13";
    case Register::P14: return "p14";
    case Register::P15: return "p15";
    case Register::PN0: return "pn0";
    case Register::PN1: return "pn1";
    case Register::PN2: return "pn2";
    case Register::PN3: return "pn3";
    case Register::PN4: return "pn4";
    case Register::PN5: return "pn5";
    case Register::PN6: return "pn6";
    case Register::PN7: return "pn7";
    case Register::PN8: return "pn8";
    case Register::PN9: return "pn9";
    case Register::PN10: return "pn10";
    case Register::PN11: return "pn11";
    case Register::PN12: return "pn12";
    case Register::PN13: return "pn13";
    case Register::PN14: return "pn14";
    case Register::PN15: return "pn15";
    case Register::ZA0: return "za0";
    case Register::ZA1: return "za1";
    case Register::ZA2: return "za2";
    case Register::ZA3: return "za3";
    case Register::ZA4: return "za4";
    case Register::ZA5: return "za5";
    case Register::ZA6: return "za6";
    case Register::ZA7: return "za7";
    case Register::ZA: return "za";
    case Register::ZT0: return "zt0";
    default: return "?";
    }
}
#endif

} // namespace veda64
