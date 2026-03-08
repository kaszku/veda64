// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once

#include <cstdint>

namespace veda64 {
namespace codegen {

/// 64-bit GP register
struct XReg {
    uint8_t idx;
    constexpr bool is_sp() const { return idx == 31; }
    constexpr bool is_zr() const { return idx == 31; }
};

/// 32-bit GP register
struct WReg {
    uint8_t idx;
    constexpr bool is_sp() const { return idx == 31; }
    constexpr bool is_zr() const { return idx == 31; }
};

/// 128-bit SIMD register
struct VReg {
    uint8_t idx;
};

/// 8-bit SIMD scalar
struct BReg {
    uint8_t idx;
};

/// 16-bit SIMD scalar
struct HReg {
    uint8_t idx;
};

/// 32-bit SIMD scalar
struct SReg {
    uint8_t idx;
};

/// 64-bit SIMD scalar
struct DReg {
    uint8_t idx;
};

/// 128-bit SIMD scalar
struct QReg {
    uint8_t idx;
};

// Predeclared GP registers
inline constexpr XReg x0{0};
inline constexpr XReg x1{1};
inline constexpr XReg x2{2};
inline constexpr XReg x3{3};
inline constexpr XReg x4{4};
inline constexpr XReg x5{5};
inline constexpr XReg x6{6};
inline constexpr XReg x7{7};
inline constexpr XReg x8{8};
inline constexpr XReg x9{9};
inline constexpr XReg x10{10};
inline constexpr XReg x11{11};
inline constexpr XReg x12{12};
inline constexpr XReg x13{13};
inline constexpr XReg x14{14};
inline constexpr XReg x15{15};
inline constexpr XReg x16{16};
inline constexpr XReg x17{17};
inline constexpr XReg x18{18};
inline constexpr XReg x19{19};
inline constexpr XReg x20{20};
inline constexpr XReg x21{21};
inline constexpr XReg x22{22};
inline constexpr XReg x23{23};
inline constexpr XReg x24{24};
inline constexpr XReg x25{25};
inline constexpr XReg x26{26};
inline constexpr XReg x27{27};
inline constexpr XReg x28{28};
inline constexpr XReg x29{29};
inline constexpr XReg x30{30};  // LR
inline constexpr XReg xzr{31};
inline constexpr XReg sp{31};

inline constexpr WReg w0{0};
inline constexpr WReg w1{1};
inline constexpr WReg w2{2};
inline constexpr WReg w3{3};
inline constexpr WReg w4{4};
inline constexpr WReg w5{5};
inline constexpr WReg w6{6};
inline constexpr WReg w7{7};
inline constexpr WReg w8{8};
inline constexpr WReg w9{9};
inline constexpr WReg w10{10};
inline constexpr WReg w11{11};
inline constexpr WReg w12{12};
inline constexpr WReg w13{13};
inline constexpr WReg w14{14};
inline constexpr WReg w15{15};
inline constexpr WReg w16{16};
inline constexpr WReg w17{17};
inline constexpr WReg w18{18};
inline constexpr WReg w19{19};
inline constexpr WReg w20{20};
inline constexpr WReg w21{21};
inline constexpr WReg w22{22};
inline constexpr WReg w23{23};
inline constexpr WReg w24{24};
inline constexpr WReg w25{25};
inline constexpr WReg w26{26};
inline constexpr WReg w27{27};
inline constexpr WReg w28{28};
inline constexpr WReg w29{29};
inline constexpr WReg w30{30};
inline constexpr WReg wzr{31};
inline constexpr WReg wsp{31};

// Predeclared SIMD registers
inline constexpr VReg v0{0};
inline constexpr VReg v1{1};
inline constexpr VReg v2{2};
inline constexpr VReg v3{3};
inline constexpr VReg v4{4};
inline constexpr VReg v5{5};
inline constexpr VReg v6{6};
inline constexpr VReg v7{7};
inline constexpr VReg v8{8};
inline constexpr VReg v9{9};
inline constexpr VReg v10{10};
inline constexpr VReg v11{11};
inline constexpr VReg v12{12};
inline constexpr VReg v13{13};
inline constexpr VReg v14{14};
inline constexpr VReg v15{15};
inline constexpr VReg v16{16};
inline constexpr VReg v17{17};
inline constexpr VReg v18{18};
inline constexpr VReg v19{19};
inline constexpr VReg v20{20};
inline constexpr VReg v21{21};
inline constexpr VReg v22{22};
inline constexpr VReg v23{23};
inline constexpr VReg v24{24};
inline constexpr VReg v25{25};
inline constexpr VReg v26{26};
inline constexpr VReg v27{27};
inline constexpr VReg v28{28};
inline constexpr VReg v29{29};
inline constexpr VReg v30{30};
inline constexpr VReg v31{31};

inline constexpr BReg b0{0};
inline constexpr BReg b1{1};
inline constexpr BReg b2{2};
inline constexpr BReg b3{3};
inline constexpr BReg b4{4};
inline constexpr BReg b5{5};
inline constexpr BReg b6{6};
inline constexpr BReg b7{7};
inline constexpr BReg b8{8};
inline constexpr BReg b9{9};
inline constexpr BReg b10{10};
inline constexpr BReg b11{11};
inline constexpr BReg b12{12};
inline constexpr BReg b13{13};
inline constexpr BReg b14{14};
inline constexpr BReg b15{15};
inline constexpr BReg b16{16};
inline constexpr BReg b17{17};
inline constexpr BReg b18{18};
inline constexpr BReg b19{19};
inline constexpr BReg b20{20};
inline constexpr BReg b21{21};
inline constexpr BReg b22{22};
inline constexpr BReg b23{23};
inline constexpr BReg b24{24};
inline constexpr BReg b25{25};
inline constexpr BReg b26{26};
inline constexpr BReg b27{27};
inline constexpr BReg b28{28};
inline constexpr BReg b29{29};
inline constexpr BReg b30{30};
inline constexpr BReg b31{31};

inline constexpr HReg h0{0};
inline constexpr HReg h1{1};
inline constexpr HReg h2{2};
inline constexpr HReg h3{3};
inline constexpr HReg h4{4};
inline constexpr HReg h5{5};
inline constexpr HReg h6{6};
inline constexpr HReg h7{7};
inline constexpr HReg h8{8};
inline constexpr HReg h9{9};
inline constexpr HReg h10{10};
inline constexpr HReg h11{11};
inline constexpr HReg h12{12};
inline constexpr HReg h13{13};
inline constexpr HReg h14{14};
inline constexpr HReg h15{15};
inline constexpr HReg h16{16};
inline constexpr HReg h17{17};
inline constexpr HReg h18{18};
inline constexpr HReg h19{19};
inline constexpr HReg h20{20};
inline constexpr HReg h21{21};
inline constexpr HReg h22{22};
inline constexpr HReg h23{23};
inline constexpr HReg h24{24};
inline constexpr HReg h25{25};
inline constexpr HReg h26{26};
inline constexpr HReg h27{27};
inline constexpr HReg h28{28};
inline constexpr HReg h29{29};
inline constexpr HReg h30{30};
inline constexpr HReg h31{31};

inline constexpr SReg s0{0};
inline constexpr SReg s1{1};
inline constexpr SReg s2{2};
inline constexpr SReg s3{3};
inline constexpr SReg s4{4};
inline constexpr SReg s5{5};
inline constexpr SReg s6{6};
inline constexpr SReg s7{7};
inline constexpr SReg s8{8};
inline constexpr SReg s9{9};
inline constexpr SReg s10{10};
inline constexpr SReg s11{11};
inline constexpr SReg s12{12};
inline constexpr SReg s13{13};
inline constexpr SReg s14{14};
inline constexpr SReg s15{15};
inline constexpr SReg s16{16};
inline constexpr SReg s17{17};
inline constexpr SReg s18{18};
inline constexpr SReg s19{19};
inline constexpr SReg s20{20};
inline constexpr SReg s21{21};
inline constexpr SReg s22{22};
inline constexpr SReg s23{23};
inline constexpr SReg s24{24};
inline constexpr SReg s25{25};
inline constexpr SReg s26{26};
inline constexpr SReg s27{27};
inline constexpr SReg s28{28};
inline constexpr SReg s29{29};
inline constexpr SReg s30{30};
inline constexpr SReg s31{31};

inline constexpr DReg d0{0};
inline constexpr DReg d1{1};
inline constexpr DReg d2{2};
inline constexpr DReg d3{3};
inline constexpr DReg d4{4};
inline constexpr DReg d5{5};
inline constexpr DReg d6{6};
inline constexpr DReg d7{7};
inline constexpr DReg d8{8};
inline constexpr DReg d9{9};
inline constexpr DReg d10{10};
inline constexpr DReg d11{11};
inline constexpr DReg d12{12};
inline constexpr DReg d13{13};
inline constexpr DReg d14{14};
inline constexpr DReg d15{15};
inline constexpr DReg d16{16};
inline constexpr DReg d17{17};
inline constexpr DReg d18{18};
inline constexpr DReg d19{19};
inline constexpr DReg d20{20};
inline constexpr DReg d21{21};
inline constexpr DReg d22{22};
inline constexpr DReg d23{23};
inline constexpr DReg d24{24};
inline constexpr DReg d25{25};
inline constexpr DReg d26{26};
inline constexpr DReg d27{27};
inline constexpr DReg d28{28};
inline constexpr DReg d29{29};
inline constexpr DReg d30{30};
inline constexpr DReg d31{31};

inline constexpr QReg q0{0};
inline constexpr QReg q1{1};
inline constexpr QReg q2{2};
inline constexpr QReg q3{3};
inline constexpr QReg q4{4};
inline constexpr QReg q5{5};
inline constexpr QReg q6{6};
inline constexpr QReg q7{7};
inline constexpr QReg q8{8};
inline constexpr QReg q9{9};
inline constexpr QReg q10{10};
inline constexpr QReg q11{11};
inline constexpr QReg q12{12};
inline constexpr QReg q13{13};
inline constexpr QReg q14{14};
inline constexpr QReg q15{15};
inline constexpr QReg q16{16};
inline constexpr QReg q17{17};
inline constexpr QReg q18{18};
inline constexpr QReg q19{19};
inline constexpr QReg q20{20};
inline constexpr QReg q21{21};
inline constexpr QReg q22{22};
inline constexpr QReg q23{23};
inline constexpr QReg q24{24};
inline constexpr QReg q25{25};
inline constexpr QReg q26{26};
inline constexpr QReg q27{27};
inline constexpr QReg q28{28};
inline constexpr QReg q29{29};
inline constexpr QReg q30{30};
inline constexpr QReg q31{31};

} // namespace codegen
} // namespace veda64
