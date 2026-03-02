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
    V0 = 226,  // V with None arrangement
    V1 = 227,  // V with None arrangement
    V2 = 228,  // V with None arrangement
    V3 = 229,  // V with None arrangement
    V4 = 230,  // V with None arrangement
    V5 = 231,  // V with None arrangement
    V6 = 232,  // V with None arrangement
    V7 = 233,  // V with None arrangement
    V8 = 234,  // V with None arrangement
    V9 = 235,  // V with None arrangement
    V10 = 236,  // V with None arrangement
    V11 = 237,  // V with None arrangement
    V12 = 238,  // V with None arrangement
    V13 = 239,  // V with None arrangement
    V14 = 240,  // V with None arrangement
    V15 = 241,  // V with None arrangement
    V16 = 242,  // V with None arrangement
    V17 = 243,  // V with None arrangement
    V18 = 244,  // V with None arrangement
    V19 = 245,  // V with None arrangement
    V20 = 246,  // V with None arrangement
    V21 = 247,  // V with None arrangement
    V22 = 248,  // V with None arrangement
    V23 = 249,  // V with None arrangement
    V24 = 250,  // V with None arrangement
    V25 = 251,  // V with None arrangement
    V26 = 252,  // V with None arrangement
    V27 = 253,  // V with None arrangement
    V28 = 254,  // V with None arrangement
    V29 = 255,  // V with None arrangement
    V30 = 256,  // V with None arrangement
    V31 = 257,  // V with None arrangement
    // V registers with arrangements: 226 + arr_index*32 + num (arr 0-17, num 0-31)
    Z0 = 802,  // Z with None arrangement
    Z1 = 803,  // Z with None arrangement
    Z2 = 804,  // Z with None arrangement
    Z3 = 805,  // Z with None arrangement
    Z4 = 806,  // Z with None arrangement
    Z5 = 807,  // Z with None arrangement
    Z6 = 808,  // Z with None arrangement
    Z7 = 809,  // Z with None arrangement
    Z8 = 810,  // Z with None arrangement
    Z9 = 811,  // Z with None arrangement
    Z10 = 812,  // Z with None arrangement
    Z11 = 813,  // Z with None arrangement
    Z12 = 814,  // Z with None arrangement
    Z13 = 815,  // Z with None arrangement
    Z14 = 816,  // Z with None arrangement
    Z15 = 817,  // Z with None arrangement
    Z16 = 818,  // Z with None arrangement
    Z17 = 819,  // Z with None arrangement
    Z18 = 820,  // Z with None arrangement
    Z19 = 821,  // Z with None arrangement
    Z20 = 822,  // Z with None arrangement
    Z21 = 823,  // Z with None arrangement
    Z22 = 824,  // Z with None arrangement
    Z23 = 825,  // Z with None arrangement
    Z24 = 826,  // Z with None arrangement
    Z25 = 827,  // Z with None arrangement
    Z26 = 828,  // Z with None arrangement
    Z27 = 829,  // Z with None arrangement
    Z28 = 830,  // Z with None arrangement
    Z29 = 831,  // Z with None arrangement
    Z30 = 832,  // Z with None arrangement
    Z31 = 833,  // Z with None arrangement
    // Z registers with arrangements: 802 + arr_z*32 + num (arr_z 0-5, num 0-31)
    P0 = 994,  // P with None arrangement
    P1 = 995,  // P with None arrangement
    P2 = 996,  // P with None arrangement
    P3 = 997,  // P with None arrangement
    P4 = 998,  // P with None arrangement
    P5 = 999,  // P with None arrangement
    P6 = 1000,  // P with None arrangement
    P7 = 1001,  // P with None arrangement
    P8 = 1002,  // P with None arrangement
    P9 = 1003,  // P with None arrangement
    P10 = 1004,  // P with None arrangement
    P11 = 1005,  // P with None arrangement
    P12 = 1006,  // P with None arrangement
    P13 = 1007,  // P with None arrangement
    P14 = 1008,  // P with None arrangement
    P15 = 1009,  // P with None arrangement
    // P registers with arrangements: 994 + arr_p*16 + num (arr_p 0-4, num 0-15)
    PN0 = 1074,  // PN with None arrangement
    PN1 = 1075,  // PN with None arrangement
    PN2 = 1076,  // PN with None arrangement
    PN3 = 1077,  // PN with None arrangement
    PN4 = 1078,  // PN with None arrangement
    PN5 = 1079,  // PN with None arrangement
    PN6 = 1080,  // PN with None arrangement
    PN7 = 1081,  // PN with None arrangement
    PN8 = 1082,  // PN with None arrangement
    PN9 = 1083,  // PN with None arrangement
    PN10 = 1084,  // PN with None arrangement
    PN11 = 1085,  // PN with None arrangement
    PN12 = 1086,  // PN with None arrangement
    PN13 = 1087,  // PN with None arrangement
    PN14 = 1088,  // PN with None arrangement
    PN15 = 1089,  // PN with None arrangement
    // PN registers with arrangements: 1074 + arr_p*16 + num (arr_p 0-4, num 0-15)
    ZA0 = 1154,  // ZA tile with None arrangement
    ZA1 = 1155,  // ZA tile with None arrangement
    ZA2 = 1156,  // ZA tile with None arrangement
    ZA3 = 1157,  // ZA tile with None arrangement
    ZA4 = 1158,  // ZA tile with None arrangement
    ZA5 = 1159,  // ZA tile with None arrangement
    ZA6 = 1160,  // ZA tile with None arrangement
    ZA7 = 1161,  // ZA tile with None arrangement
    ZA = 1162,  // Generic ZA with None arrangement
    // ZA registers with arrangements: 1154 + arr_za*9 + num (arr_za 0-5, num 0-7, 8=generic ZA)
    ZT0 = 1208,
};

inline constexpr uint16_t REG_V_BASE = 226;
inline constexpr uint16_t REG_Z_BASE = 802;
inline constexpr uint16_t REG_P_BASE = 994;
inline constexpr uint16_t REG_PN_BASE = 1074;
inline constexpr uint16_t REG_ZA_BASE = 1154;
inline constexpr uint16_t REG_ZT0 = 1208;

// Map Arrangement enum ordinal to block-specific index
inline constexpr uint8_t arr_to_v_index(Arrangement a) {
    return static_cast<uint8_t>(a);  // V uses all 18, direct mapping
}

inline constexpr uint8_t arr_to_z_index(Arrangement a) {
    // Z supports None(0), B(1), H(2), S(3), D(4), Q(5)
    auto v = static_cast<uint8_t>(a);
    return (v <= 5) ? v : 0;
}

inline constexpr uint8_t arr_to_p_index(Arrangement a) {
    // P/PN supports None(0), B(1), H(2), S(3), D(4)
    auto v = static_cast<uint8_t>(a);
    return (v <= 4) ? v : 0;
}

inline constexpr uint8_t arr_to_za_index(Arrangement a) {
    // ZA supports None(0), B(1), H(2), S(3), D(4), Q(5)
    auto v = static_cast<uint8_t>(a);
    return (v <= 5) ? v : 0;
}

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
    switch (size) {
        case Arrangement::B: return static_cast<Register>(66 + num);
        case Arrangement::H: return static_cast<Register>(98 + num);
        case Arrangement::S: return static_cast<Register>(130 + num);
        case Arrangement::D: return static_cast<Register>(162 + num);
        case Arrangement::Q: return static_cast<Register>(194 + num);
        default: return static_cast<Register>(num);
    }
}

inline constexpr Register make_vec_reg(uint32_t num, Arrangement arr = Arrangement::None) {
    return static_cast<Register>(226 + arr_to_v_index(arr) * 32 + num);
}

inline constexpr Register make_sve_reg(uint32_t num, Arrangement arr = Arrangement::None) {
    return static_cast<Register>(802 + arr_to_z_index(arr) * 32 + num);
}

inline constexpr Register make_pred_reg(uint32_t num, Arrangement arr = Arrangement::None) {
    return static_cast<Register>(994 + arr_to_p_index(arr) * 16 + num);
}

inline constexpr Register make_predn_reg(uint32_t num, Arrangement arr = Arrangement::None) {
    return static_cast<Register>(1074 + arr_to_p_index(arr) * 16 + num);
}

inline constexpr Register make_za_reg(uint32_t num, Arrangement arr = Arrangement::None) {
    // num: 0-7 for tiles, 8 for generic ZA
    return static_cast<Register>(1154 + arr_to_za_index(arr) * 9 + num);
}

inline constexpr uint32_t register_num(Register r) {
    auto v = static_cast<uint16_t>(r);
    if (v <= 32) return (v <= 30) ? v : 31;
    if (v <= 65) return (v <= 63) ? v - 33 : 31;
    if (v <= 225) return (v - 66) % 32;
    if (v <= 801) return (v - 226) % 32;
    if (v <= 993) return (v - 802) % 32;
    if (v <= 1073) return (v - 994) % 16;
    if (v <= 1153) return (v - 1074) % 16;
    if (v <= 1207) return (v - 1154) % 9;
    return 0;
}

inline constexpr Arrangement register_arrangement(Register r) {
    auto v = static_cast<uint16_t>(r);
    if (v < 226) return Arrangement::None;
    if (v <= 801) return static_cast<Arrangement>((v - 226) / 32u);
    if (v <= 993) {
        auto idx = static_cast<uint8_t>((v - 802) / 32u);
        static constexpr Arrangement z_arrs[] = {Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D, Arrangement::Q};
        return (idx < 6) ? z_arrs[idx] : Arrangement::None;
    }
    if (v <= 1073) {
        auto idx = static_cast<uint8_t>((v - 994) / 16u);
        static constexpr Arrangement p_arrs[] = {Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D};
        return (idx < 5) ? p_arrs[idx] : Arrangement::None;
    }
    if (v <= 1153) {
        auto idx = static_cast<uint8_t>((v - 1074) / 16u);
        static constexpr Arrangement p_arrs[] = {Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D};
        return (idx < 5) ? p_arrs[idx] : Arrangement::None;
    }
    if (v <= 1207) {
        auto idx = static_cast<uint8_t>((v - 1154) / 9u);
        static constexpr Arrangement za_arrs[] = {Arrangement::None, Arrangement::B, Arrangement::H, Arrangement::S, Arrangement::D, Arrangement::Q};
        return (idx < 6) ? za_arrs[idx] : Arrangement::None;
    }
    return Arrangement::None;
}

inline constexpr Register set_register_arrangement(Register r, Arrangement arr) {
    auto v = static_cast<uint16_t>(r);
    if (v < 226) return r;
    if (v <= 801) return make_vec_reg((v - 226) % 32, arr);
    if (v <= 993) return make_sve_reg((v - 802) % 32, arr);
    if (v <= 1073) return make_pred_reg((v - 994) % 16, arr);
    if (v <= 1153) return make_predn_reg((v - 1074) % 16, arr);
    if (v <= 1207) return make_za_reg((v - 1154) % 9, arr);
    return r;
}

inline constexpr bool register_is_64bit(Register r) {
    auto v = static_cast<uint16_t>(r);
    return v >= 33 && v <= 65;
}

inline constexpr bool register_is_sp(Register r) {
    return r == Register::SP || r == Register::WSP;
}

#ifndef VEDA64_NO_STRINGS
inline const char* register_to_string(Register r) {
    auto v = static_cast<uint16_t>(r);
    if (v <= 65) {
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
        default: return "?";
        }
    }
    if (v <= 225) {
        static const char* scalar_names[] = {
            "b0",
            "b1",
            "b2",
            "b3",
            "b4",
            "b5",
            "b6",
            "b7",
            "b8",
            "b9",
            "b10",
            "b11",
            "b12",
            "b13",
            "b14",
            "b15",
            "b16",
            "b17",
            "b18",
            "b19",
            "b20",
            "b21",
            "b22",
            "b23",
            "b24",
            "b25",
            "b26",
            "b27",
            "b28",
            "b29",
            "b30",
            "b31",
            "h0",
            "h1",
            "h2",
            "h3",
            "h4",
            "h5",
            "h6",
            "h7",
            "h8",
            "h9",
            "h10",
            "h11",
            "h12",
            "h13",
            "h14",
            "h15",
            "h16",
            "h17",
            "h18",
            "h19",
            "h20",
            "h21",
            "h22",
            "h23",
            "h24",
            "h25",
            "h26",
            "h27",
            "h28",
            "h29",
            "h30",
            "h31",
            "s0",
            "s1",
            "s2",
            "s3",
            "s4",
            "s5",
            "s6",
            "s7",
            "s8",
            "s9",
            "s10",
            "s11",
            "s12",
            "s13",
            "s14",
            "s15",
            "s16",
            "s17",
            "s18",
            "s19",
            "s20",
            "s21",
            "s22",
            "s23",
            "s24",
            "s25",
            "s26",
            "s27",
            "s28",
            "s29",
            "s30",
            "s31",
            "d0",
            "d1",
            "d2",
            "d3",
            "d4",
            "d5",
            "d6",
            "d7",
            "d8",
            "d9",
            "d10",
            "d11",
            "d12",
            "d13",
            "d14",
            "d15",
            "d16",
            "d17",
            "d18",
            "d19",
            "d20",
            "d21",
            "d22",
            "d23",
            "d24",
            "d25",
            "d26",
            "d27",
            "d28",
            "d29",
            "d30",
            "d31",
            "q0",
            "q1",
            "q2",
            "q3",
            "q4",
            "q5",
            "q6",
            "q7",
            "q8",
            "q9",
            "q10",
            "q11",
            "q12",
            "q13",
            "q14",
            "q15",
            "q16",
            "q17",
            "q18",
            "q19",
            "q20",
            "q21",
            "q22",
            "q23",
            "q24",
            "q25",
            "q26",
            "q27",
            "q28",
            "q29",
            "q30",
            "q31",
        };
        return scalar_names[v - 66];
    }
    if (v <= 801) {
        static const char* v_names[] = {
            "v0",
            "v1",
            "v2",
            "v3",
            "v4",
            "v5",
            "v6",
            "v7",
            "v8",
            "v9",
            "v10",
            "v11",
            "v12",
            "v13",
            "v14",
            "v15",
            "v16",
            "v17",
            "v18",
            "v19",
            "v20",
            "v21",
            "v22",
            "v23",
            "v24",
            "v25",
            "v26",
            "v27",
            "v28",
            "v29",
            "v30",
            "v31",
            "v0.b",
            "v1.b",
            "v2.b",
            "v3.b",
            "v4.b",
            "v5.b",
            "v6.b",
            "v7.b",
            "v8.b",
            "v9.b",
            "v10.b",
            "v11.b",
            "v12.b",
            "v13.b",
            "v14.b",
            "v15.b",
            "v16.b",
            "v17.b",
            "v18.b",
            "v19.b",
            "v20.b",
            "v21.b",
            "v22.b",
            "v23.b",
            "v24.b",
            "v25.b",
            "v26.b",
            "v27.b",
            "v28.b",
            "v29.b",
            "v30.b",
            "v31.b",
            "v0.h",
            "v1.h",
            "v2.h",
            "v3.h",
            "v4.h",
            "v5.h",
            "v6.h",
            "v7.h",
            "v8.h",
            "v9.h",
            "v10.h",
            "v11.h",
            "v12.h",
            "v13.h",
            "v14.h",
            "v15.h",
            "v16.h",
            "v17.h",
            "v18.h",
            "v19.h",
            "v20.h",
            "v21.h",
            "v22.h",
            "v23.h",
            "v24.h",
            "v25.h",
            "v26.h",
            "v27.h",
            "v28.h",
            "v29.h",
            "v30.h",
            "v31.h",
            "v0.s",
            "v1.s",
            "v2.s",
            "v3.s",
            "v4.s",
            "v5.s",
            "v6.s",
            "v7.s",
            "v8.s",
            "v9.s",
            "v10.s",
            "v11.s",
            "v12.s",
            "v13.s",
            "v14.s",
            "v15.s",
            "v16.s",
            "v17.s",
            "v18.s",
            "v19.s",
            "v20.s",
            "v21.s",
            "v22.s",
            "v23.s",
            "v24.s",
            "v25.s",
            "v26.s",
            "v27.s",
            "v28.s",
            "v29.s",
            "v30.s",
            "v31.s",
            "v0.d",
            "v1.d",
            "v2.d",
            "v3.d",
            "v4.d",
            "v5.d",
            "v6.d",
            "v7.d",
            "v8.d",
            "v9.d",
            "v10.d",
            "v11.d",
            "v12.d",
            "v13.d",
            "v14.d",
            "v15.d",
            "v16.d",
            "v17.d",
            "v18.d",
            "v19.d",
            "v20.d",
            "v21.d",
            "v22.d",
            "v23.d",
            "v24.d",
            "v25.d",
            "v26.d",
            "v27.d",
            "v28.d",
            "v29.d",
            "v30.d",
            "v31.d",
            "v0.q",
            "v1.q",
            "v2.q",
            "v3.q",
            "v4.q",
            "v5.q",
            "v6.q",
            "v7.q",
            "v8.q",
            "v9.q",
            "v10.q",
            "v11.q",
            "v12.q",
            "v13.q",
            "v14.q",
            "v15.q",
            "v16.q",
            "v17.q",
            "v18.q",
            "v19.q",
            "v20.q",
            "v21.q",
            "v22.q",
            "v23.q",
            "v24.q",
            "v25.q",
            "v26.q",
            "v27.q",
            "v28.q",
            "v29.q",
            "v30.q",
            "v31.q",
            "v0.8b",
            "v1.8b",
            "v2.8b",
            "v3.8b",
            "v4.8b",
            "v5.8b",
            "v6.8b",
            "v7.8b",
            "v8.8b",
            "v9.8b",
            "v10.8b",
            "v11.8b",
            "v12.8b",
            "v13.8b",
            "v14.8b",
            "v15.8b",
            "v16.8b",
            "v17.8b",
            "v18.8b",
            "v19.8b",
            "v20.8b",
            "v21.8b",
            "v22.8b",
            "v23.8b",
            "v24.8b",
            "v25.8b",
            "v26.8b",
            "v27.8b",
            "v28.8b",
            "v29.8b",
            "v30.8b",
            "v31.8b",
            "v0.4h",
            "v1.4h",
            "v2.4h",
            "v3.4h",
            "v4.4h",
            "v5.4h",
            "v6.4h",
            "v7.4h",
            "v8.4h",
            "v9.4h",
            "v10.4h",
            "v11.4h",
            "v12.4h",
            "v13.4h",
            "v14.4h",
            "v15.4h",
            "v16.4h",
            "v17.4h",
            "v18.4h",
            "v19.4h",
            "v20.4h",
            "v21.4h",
            "v22.4h",
            "v23.4h",
            "v24.4h",
            "v25.4h",
            "v26.4h",
            "v27.4h",
            "v28.4h",
            "v29.4h",
            "v30.4h",
            "v31.4h",
            "v0.2s",
            "v1.2s",
            "v2.2s",
            "v3.2s",
            "v4.2s",
            "v5.2s",
            "v6.2s",
            "v7.2s",
            "v8.2s",
            "v9.2s",
            "v10.2s",
            "v11.2s",
            "v12.2s",
            "v13.2s",
            "v14.2s",
            "v15.2s",
            "v16.2s",
            "v17.2s",
            "v18.2s",
            "v19.2s",
            "v20.2s",
            "v21.2s",
            "v22.2s",
            "v23.2s",
            "v24.2s",
            "v25.2s",
            "v26.2s",
            "v27.2s",
            "v28.2s",
            "v29.2s",
            "v30.2s",
            "v31.2s",
            "v0.1d",
            "v1.1d",
            "v2.1d",
            "v3.1d",
            "v4.1d",
            "v5.1d",
            "v6.1d",
            "v7.1d",
            "v8.1d",
            "v9.1d",
            "v10.1d",
            "v11.1d",
            "v12.1d",
            "v13.1d",
            "v14.1d",
            "v15.1d",
            "v16.1d",
            "v17.1d",
            "v18.1d",
            "v19.1d",
            "v20.1d",
            "v21.1d",
            "v22.1d",
            "v23.1d",
            "v24.1d",
            "v25.1d",
            "v26.1d",
            "v27.1d",
            "v28.1d",
            "v29.1d",
            "v30.1d",
            "v31.1d",
            "v0.16b",
            "v1.16b",
            "v2.16b",
            "v3.16b",
            "v4.16b",
            "v5.16b",
            "v6.16b",
            "v7.16b",
            "v8.16b",
            "v9.16b",
            "v10.16b",
            "v11.16b",
            "v12.16b",
            "v13.16b",
            "v14.16b",
            "v15.16b",
            "v16.16b",
            "v17.16b",
            "v18.16b",
            "v19.16b",
            "v20.16b",
            "v21.16b",
            "v22.16b",
            "v23.16b",
            "v24.16b",
            "v25.16b",
            "v26.16b",
            "v27.16b",
            "v28.16b",
            "v29.16b",
            "v30.16b",
            "v31.16b",
            "v0.8h",
            "v1.8h",
            "v2.8h",
            "v3.8h",
            "v4.8h",
            "v5.8h",
            "v6.8h",
            "v7.8h",
            "v8.8h",
            "v9.8h",
            "v10.8h",
            "v11.8h",
            "v12.8h",
            "v13.8h",
            "v14.8h",
            "v15.8h",
            "v16.8h",
            "v17.8h",
            "v18.8h",
            "v19.8h",
            "v20.8h",
            "v21.8h",
            "v22.8h",
            "v23.8h",
            "v24.8h",
            "v25.8h",
            "v26.8h",
            "v27.8h",
            "v28.8h",
            "v29.8h",
            "v30.8h",
            "v31.8h",
            "v0.4s",
            "v1.4s",
            "v2.4s",
            "v3.4s",
            "v4.4s",
            "v5.4s",
            "v6.4s",
            "v7.4s",
            "v8.4s",
            "v9.4s",
            "v10.4s",
            "v11.4s",
            "v12.4s",
            "v13.4s",
            "v14.4s",
            "v15.4s",
            "v16.4s",
            "v17.4s",
            "v18.4s",
            "v19.4s",
            "v20.4s",
            "v21.4s",
            "v22.4s",
            "v23.4s",
            "v24.4s",
            "v25.4s",
            "v26.4s",
            "v27.4s",
            "v28.4s",
            "v29.4s",
            "v30.4s",
            "v31.4s",
            "v0.2d",
            "v1.2d",
            "v2.2d",
            "v3.2d",
            "v4.2d",
            "v5.2d",
            "v6.2d",
            "v7.2d",
            "v8.2d",
            "v9.2d",
            "v10.2d",
            "v11.2d",
            "v12.2d",
            "v13.2d",
            "v14.2d",
            "v15.2d",
            "v16.2d",
            "v17.2d",
            "v18.2d",
            "v19.2d",
            "v20.2d",
            "v21.2d",
            "v22.2d",
            "v23.2d",
            "v24.2d",
            "v25.2d",
            "v26.2d",
            "v27.2d",
            "v28.2d",
            "v29.2d",
            "v30.2d",
            "v31.2d",
            "v0.1q",
            "v1.1q",
            "v2.1q",
            "v3.1q",
            "v4.1q",
            "v5.1q",
            "v6.1q",
            "v7.1q",
            "v8.1q",
            "v9.1q",
            "v10.1q",
            "v11.1q",
            "v12.1q",
            "v13.1q",
            "v14.1q",
            "v15.1q",
            "v16.1q",
            "v17.1q",
            "v18.1q",
            "v19.1q",
            "v20.1q",
            "v21.1q",
            "v22.1q",
            "v23.1q",
            "v24.1q",
            "v25.1q",
            "v26.1q",
            "v27.1q",
            "v28.1q",
            "v29.1q",
            "v30.1q",
            "v31.1q",
            "v0.2b",
            "v1.2b",
            "v2.2b",
            "v3.2b",
            "v4.2b",
            "v5.2b",
            "v6.2b",
            "v7.2b",
            "v8.2b",
            "v9.2b",
            "v10.2b",
            "v11.2b",
            "v12.2b",
            "v13.2b",
            "v14.2b",
            "v15.2b",
            "v16.2b",
            "v17.2b",
            "v18.2b",
            "v19.2b",
            "v20.2b",
            "v21.2b",
            "v22.2b",
            "v23.2b",
            "v24.2b",
            "v25.2b",
            "v26.2b",
            "v27.2b",
            "v28.2b",
            "v29.2b",
            "v30.2b",
            "v31.2b",
            "v0.4b",
            "v1.4b",
            "v2.4b",
            "v3.4b",
            "v4.4b",
            "v5.4b",
            "v6.4b",
            "v7.4b",
            "v8.4b",
            "v9.4b",
            "v10.4b",
            "v11.4b",
            "v12.4b",
            "v13.4b",
            "v14.4b",
            "v15.4b",
            "v16.4b",
            "v17.4b",
            "v18.4b",
            "v19.4b",
            "v20.4b",
            "v21.4b",
            "v22.4b",
            "v23.4b",
            "v24.4b",
            "v25.4b",
            "v26.4b",
            "v27.4b",
            "v28.4b",
            "v29.4b",
            "v30.4b",
            "v31.4b",
            "v0.2h",
            "v1.2h",
            "v2.2h",
            "v3.2h",
            "v4.2h",
            "v5.2h",
            "v6.2h",
            "v7.2h",
            "v8.2h",
            "v9.2h",
            "v10.2h",
            "v11.2h",
            "v12.2h",
            "v13.2h",
            "v14.2h",
            "v15.2h",
            "v16.2h",
            "v17.2h",
            "v18.2h",
            "v19.2h",
            "v20.2h",
            "v21.2h",
            "v22.2h",
            "v23.2h",
            "v24.2h",
            "v25.2h",
            "v26.2h",
            "v27.2h",
            "v28.2h",
            "v29.2h",
            "v30.2h",
            "v31.2h",
        };
        return v_names[v - 226];
    }
    if (v <= 993) {
        static const char* z_names[] = {
            "z0",
            "z1",
            "z2",
            "z3",
            "z4",
            "z5",
            "z6",
            "z7",
            "z8",
            "z9",
            "z10",
            "z11",
            "z12",
            "z13",
            "z14",
            "z15",
            "z16",
            "z17",
            "z18",
            "z19",
            "z20",
            "z21",
            "z22",
            "z23",
            "z24",
            "z25",
            "z26",
            "z27",
            "z28",
            "z29",
            "z30",
            "z31",
            "z0.b",
            "z1.b",
            "z2.b",
            "z3.b",
            "z4.b",
            "z5.b",
            "z6.b",
            "z7.b",
            "z8.b",
            "z9.b",
            "z10.b",
            "z11.b",
            "z12.b",
            "z13.b",
            "z14.b",
            "z15.b",
            "z16.b",
            "z17.b",
            "z18.b",
            "z19.b",
            "z20.b",
            "z21.b",
            "z22.b",
            "z23.b",
            "z24.b",
            "z25.b",
            "z26.b",
            "z27.b",
            "z28.b",
            "z29.b",
            "z30.b",
            "z31.b",
            "z0.h",
            "z1.h",
            "z2.h",
            "z3.h",
            "z4.h",
            "z5.h",
            "z6.h",
            "z7.h",
            "z8.h",
            "z9.h",
            "z10.h",
            "z11.h",
            "z12.h",
            "z13.h",
            "z14.h",
            "z15.h",
            "z16.h",
            "z17.h",
            "z18.h",
            "z19.h",
            "z20.h",
            "z21.h",
            "z22.h",
            "z23.h",
            "z24.h",
            "z25.h",
            "z26.h",
            "z27.h",
            "z28.h",
            "z29.h",
            "z30.h",
            "z31.h",
            "z0.s",
            "z1.s",
            "z2.s",
            "z3.s",
            "z4.s",
            "z5.s",
            "z6.s",
            "z7.s",
            "z8.s",
            "z9.s",
            "z10.s",
            "z11.s",
            "z12.s",
            "z13.s",
            "z14.s",
            "z15.s",
            "z16.s",
            "z17.s",
            "z18.s",
            "z19.s",
            "z20.s",
            "z21.s",
            "z22.s",
            "z23.s",
            "z24.s",
            "z25.s",
            "z26.s",
            "z27.s",
            "z28.s",
            "z29.s",
            "z30.s",
            "z31.s",
            "z0.d",
            "z1.d",
            "z2.d",
            "z3.d",
            "z4.d",
            "z5.d",
            "z6.d",
            "z7.d",
            "z8.d",
            "z9.d",
            "z10.d",
            "z11.d",
            "z12.d",
            "z13.d",
            "z14.d",
            "z15.d",
            "z16.d",
            "z17.d",
            "z18.d",
            "z19.d",
            "z20.d",
            "z21.d",
            "z22.d",
            "z23.d",
            "z24.d",
            "z25.d",
            "z26.d",
            "z27.d",
            "z28.d",
            "z29.d",
            "z30.d",
            "z31.d",
            "z0.q",
            "z1.q",
            "z2.q",
            "z3.q",
            "z4.q",
            "z5.q",
            "z6.q",
            "z7.q",
            "z8.q",
            "z9.q",
            "z10.q",
            "z11.q",
            "z12.q",
            "z13.q",
            "z14.q",
            "z15.q",
            "z16.q",
            "z17.q",
            "z18.q",
            "z19.q",
            "z20.q",
            "z21.q",
            "z22.q",
            "z23.q",
            "z24.q",
            "z25.q",
            "z26.q",
            "z27.q",
            "z28.q",
            "z29.q",
            "z30.q",
            "z31.q",
        };
        return z_names[v - 802];
    }
    if (v <= 1073) {
        static const char* p_names[] = {
            "p0",
            "p1",
            "p2",
            "p3",
            "p4",
            "p5",
            "p6",
            "p7",
            "p8",
            "p9",
            "p10",
            "p11",
            "p12",
            "p13",
            "p14",
            "p15",
            "p0.b",
            "p1.b",
            "p2.b",
            "p3.b",
            "p4.b",
            "p5.b",
            "p6.b",
            "p7.b",
            "p8.b",
            "p9.b",
            "p10.b",
            "p11.b",
            "p12.b",
            "p13.b",
            "p14.b",
            "p15.b",
            "p0.h",
            "p1.h",
            "p2.h",
            "p3.h",
            "p4.h",
            "p5.h",
            "p6.h",
            "p7.h",
            "p8.h",
            "p9.h",
            "p10.h",
            "p11.h",
            "p12.h",
            "p13.h",
            "p14.h",
            "p15.h",
            "p0.s",
            "p1.s",
            "p2.s",
            "p3.s",
            "p4.s",
            "p5.s",
            "p6.s",
            "p7.s",
            "p8.s",
            "p9.s",
            "p10.s",
            "p11.s",
            "p12.s",
            "p13.s",
            "p14.s",
            "p15.s",
            "p0.d",
            "p1.d",
            "p2.d",
            "p3.d",
            "p4.d",
            "p5.d",
            "p6.d",
            "p7.d",
            "p8.d",
            "p9.d",
            "p10.d",
            "p11.d",
            "p12.d",
            "p13.d",
            "p14.d",
            "p15.d",
        };
        return p_names[v - 994];
    }
    if (v <= 1153) {
        static const char* pn_names[] = {
            "pn0",
            "pn1",
            "pn2",
            "pn3",
            "pn4",
            "pn5",
            "pn6",
            "pn7",
            "pn8",
            "pn9",
            "pn10",
            "pn11",
            "pn12",
            "pn13",
            "pn14",
            "pn15",
            "pn0.b",
            "pn1.b",
            "pn2.b",
            "pn3.b",
            "pn4.b",
            "pn5.b",
            "pn6.b",
            "pn7.b",
            "pn8.b",
            "pn9.b",
            "pn10.b",
            "pn11.b",
            "pn12.b",
            "pn13.b",
            "pn14.b",
            "pn15.b",
            "pn0.h",
            "pn1.h",
            "pn2.h",
            "pn3.h",
            "pn4.h",
            "pn5.h",
            "pn6.h",
            "pn7.h",
            "pn8.h",
            "pn9.h",
            "pn10.h",
            "pn11.h",
            "pn12.h",
            "pn13.h",
            "pn14.h",
            "pn15.h",
            "pn0.s",
            "pn1.s",
            "pn2.s",
            "pn3.s",
            "pn4.s",
            "pn5.s",
            "pn6.s",
            "pn7.s",
            "pn8.s",
            "pn9.s",
            "pn10.s",
            "pn11.s",
            "pn12.s",
            "pn13.s",
            "pn14.s",
            "pn15.s",
            "pn0.d",
            "pn1.d",
            "pn2.d",
            "pn3.d",
            "pn4.d",
            "pn5.d",
            "pn6.d",
            "pn7.d",
            "pn8.d",
            "pn9.d",
            "pn10.d",
            "pn11.d",
            "pn12.d",
            "pn13.d",
            "pn14.d",
            "pn15.d",
        };
        return pn_names[v - 1074];
    }
    if (v <= 1207) {
        static const char* za_names[] = {
            "za0",
            "za1",
            "za2",
            "za3",
            "za4",
            "za5",
            "za6",
            "za7",
            "za",
            "za0.b",
            "za1.b",
            "za2.b",
            "za3.b",
            "za4.b",
            "za5.b",
            "za6.b",
            "za7.b",
            "za.b",
            "za0.h",
            "za1.h",
            "za2.h",
            "za3.h",
            "za4.h",
            "za5.h",
            "za6.h",
            "za7.h",
            "za.h",
            "za0.s",
            "za1.s",
            "za2.s",
            "za3.s",
            "za4.s",
            "za5.s",
            "za6.s",
            "za7.s",
            "za.s",
            "za0.d",
            "za1.d",
            "za2.d",
            "za3.d",
            "za4.d",
            "za5.d",
            "za6.d",
            "za7.d",
            "za.d",
            "za0.q",
            "za1.q",
            "za2.q",
            "za3.q",
            "za4.q",
            "za5.q",
            "za6.q",
            "za7.q",
            "za.q",
        };
        return za_names[v - 1154];
    }
    if (v == 1208) return "zt0";
    return "?";
}

inline const char* arrangement_to_string(Arrangement a) {
    static const char* names[] = {"", "b", "h", "s", "d", "q",
        "8b", "4h", "2s", "1d", "16b", "8h", "4s", "2d", "1q", "2b", "4b", "2h"};
    return names[static_cast<uint8_t>(a)];
}
#endif

} // namespace veda64
