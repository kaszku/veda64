#include "class/fpsimd.hpp"

namespace veda64 {
namespace Fpsimd {

// Internal encoding structures
// LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
// Encoding: LDAPUR_B_ldapstl_simd
// Template: LDAPUR  <Bt>, [<Xn|SP>{, #<simm>}]
struct LdapurBLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
// Encoding: LDAPUR_H_ldapstl_simd
// Template: LDAPUR  <Ht>, [<Xn|SP>{, #<simm>}]
struct LdapurHLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
// Encoding: LDAPUR_S_ldapstl_simd
// Template: LDAPUR  <St>, [<Xn|SP>{, #<simm>}]
struct LdapurSLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
// Encoding: LDAPUR_D_ldapstl_simd
// Template: LDAPUR  <Dt>, [<Xn|SP>{, #<simm>}]
struct LdapurDLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDAPUR: Load-acquire RCpc SIMD&FP register (unscaled offset)
// Encoding: LDAPUR_Q_ldapstl_simd
// Template: LDAPUR  <Qt>, [<Xn|SP>{, #<simm>}]
struct LdapurQLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDNP: Load pair of SIMD&FP registers, with non-temporal hint
// Encoding: LDNP_S_ldstnapair_offs
// Template: LDNP  <St1>, <St2>, [<Xn|SP>{, #<imm>}]
struct LdnpSLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// LDNP: Load pair of SIMD&FP registers, with non-temporal hint
// Encoding: LDNP_D_ldstnapair_offs
// Template: LDNP  <Dt1>, <Dt2>, [<Xn|SP>{, #<imm>}]
struct LdnpDLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// LDNP: Load pair of SIMD&FP registers, with non-temporal hint
// Encoding: LDNP_Q_ldstnapair_offs
// Template: LDNP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct LdnpQLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_S_ldstpair_post
// Template: LDP  <St1>, <St2>, [<Xn|SP>], #<imm>
struct LdpSLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_D_ldstpair_post
// Template: LDP  <Dt1>, <Dt2>, [<Xn|SP>], #<imm>
struct LdpDLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_Q_ldstpair_post
// Template: LDP  <Qt1>, <Qt2>, [<Xn|SP>], #<imm>
struct LdpQLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_S_ldstpair_pre
// Template: LDP  <St1>, <St2>, [<Xn|SP>, #<imm>]!
struct LdpSLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_D_ldstpair_pre
// Template: LDP  <Dt1>, <Dt2>, [<Xn|SP>, #<imm>]!
struct LdpDLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_Q_ldstpair_pre
// Template: LDP  <Qt1>, <Qt2>, [<Xn|SP>, #<imm>]!
struct LdpQLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_S_ldstpair_off
// Template: LDP  <St1>, <St2>, [<Xn|SP>{, #<imm>}]
struct LdpSLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_D_ldstpair_off
// Template: LDP  <Dt1>, <Dt2>, [<Xn|SP>{, #<imm>}]
struct LdpDLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// LDP: Load pair of SIMD&FP registers
// Encoding: LDP_Q_ldstpair_off
// Template: LDP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct LdpQLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_B_ldst_immpost
// Template: LDR  <Bt>, [<Xn|SP>], #<simm>
struct LdrBLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_H_ldst_immpost
// Template: LDR  <Ht>, [<Xn|SP>], #<simm>
struct LdrHLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_S_ldst_immpost
// Template: LDR  <St>, [<Xn|SP>], #<simm>
struct LdrSLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_D_ldst_immpost
// Template: LDR  <Dt>, [<Xn|SP>], #<simm>
struct LdrDLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_Q_ldst_immpost
// Template: LDR  <Qt>, [<Xn|SP>], #<simm>
struct LdrQLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_B_ldst_immpre
// Template: LDR  <Bt>, [<Xn|SP>, #<simm>]!
struct LdrBLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_H_ldst_immpre
// Template: LDR  <Ht>, [<Xn|SP>, #<simm>]!
struct LdrHLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_S_ldst_immpre
// Template: LDR  <St>, [<Xn|SP>, #<simm>]!
struct LdrSLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_D_ldst_immpre
// Template: LDR  <Dt>, [<Xn|SP>, #<simm>]!
struct LdrDLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_Q_ldst_immpre
// Template: LDR  <Qt>, [<Xn|SP>, #<simm>]!
struct LdrQLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_B_ldst_pos
// Template: LDR  <Bt>, [<Xn|SP>{, #<pimm>}]
struct LdrBLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_H_ldst_pos
// Template: LDR  <Ht>, [<Xn|SP>{, #<pimm>}]
struct LdrHLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_S_ldst_pos
// Template: LDR  <St>, [<Xn|SP>{, #<pimm>}]
struct LdrSLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_D_ldst_pos
// Template: LDR  <Dt>, [<Xn|SP>{, #<pimm>}]
struct LdrDLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDR: Load SIMD&FP register (immediate offset)
// Encoding: LDR_Q_ldst_pos
// Template: LDR  <Qt>, [<Xn|SP>{, #<pimm>}]
struct LdrQLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (PC-relative literal)
// Encoding: LDR_S_loadlit
// Template: LDR  <St>, <label>
struct LdrSLoadlit {
    uint32_t Rt : 5;
    int32_t imm19 : 19;
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (PC-relative literal)
// Encoding: LDR_D_loadlit
// Template: LDR  <Dt>, <label>
struct LdrDLoadlit {
    uint32_t Rt : 5;
    int32_t imm19 : 19;
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// LDR: Load SIMD&FP register (PC-relative literal)
// Encoding: LDR_Q_loadlit
// Template: LDR  <Qt>, <label>
struct LdrQLoadlit {
    uint32_t Rt : 5;
    int32_t imm19 : 19;
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_B_ldst_regoff
// Template: LDR  <Bt>, [<Xn|SP>, (<Wm>|<Xm>), <extend> {<amount>}]
struct LdrBLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_BL_ldst_regoff
// Template: LDR  <Bt>, [<Xn|SP>, <Xm>{, LSL <amount>}]
struct LdrBlLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;  // fixed: 0b011 (0x3)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_H_ldst_regoff
// Template: LDR  <Ht>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct LdrHLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_S_ldst_regoff
// Template: LDR  <St>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct LdrSLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_D_ldst_regoff
// Template: LDR  <Dt>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct LdrDLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDR: Load SIMD&FP register (register offset)
// Encoding: LDR_Q_ldst_regoff
// Template: LDR  <Qt>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct LdrQLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDTNP: Load unprivileged pair of SIMD&FP registers, with non-temporal hint
// Encoding: LDTNP_Q_ldstnapair_offs
// Template: LDTNP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct LdtnpQLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// LDTP: Load unprivileged pair of SIMD&FP registers
// Encoding: LDTP_Q_ldstpair_post
// Template: LDTP  <Qt1>, <Qt2>, [<Xn|SP>], #<imm>
struct LdtpQLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// LDTP: Load unprivileged pair of SIMD&FP registers
// Encoding: LDTP_Q_ldstpair_pre
// Template: LDTP  <Qt1>, <Qt2>, [<Xn|SP>, #<imm>]!
struct LdtpQLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// LDTP: Load unprivileged pair of SIMD&FP registers
// Encoding: LDTP_Q_ldstpair_off
// Template: LDTP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct LdtpQLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// LDUR: Load SIMD&FP register (unscaled offset)
// Encoding: LDUR_B_ldst_unscaled
// Template: LDUR  <Bt>, [<Xn|SP>{, #<simm>}]
struct LdurBLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// LDUR: Load SIMD&FP register (unscaled offset)
// Encoding: LDUR_H_ldst_unscaled
// Template: LDUR  <Ht>, [<Xn|SP>{, #<simm>}]
struct LdurHLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// LDUR: Load SIMD&FP register (unscaled offset)
// Encoding: LDUR_S_ldst_unscaled
// Template: LDUR  <St>, [<Xn|SP>{, #<simm>}]
struct LdurSLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// LDUR: Load SIMD&FP register (unscaled offset)
// Encoding: LDUR_D_ldst_unscaled
// Template: LDUR  <Dt>, [<Xn|SP>{, #<simm>}]
struct LdurDLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// LDUR: Load SIMD&FP register (unscaled offset)
// Encoding: LDUR_Q_ldst_unscaled
// Template: LDUR  <Qt>, [<Xn|SP>{, #<simm>}]
struct LdurQLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STLUR: Store-release SIMD&FP register (unscaled offset)
// Encoding: STLUR_B_ldapstl_simd
// Template: STLUR  <Bt>, [<Xn|SP>{, #<simm>}]
struct StlurBLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STLUR: Store-release SIMD&FP register (unscaled offset)
// Encoding: STLUR_H_ldapstl_simd
// Template: STLUR  <Ht>, [<Xn|SP>{, #<simm>}]
struct StlurHLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STLUR: Store-release SIMD&FP register (unscaled offset)
// Encoding: STLUR_S_ldapstl_simd
// Template: STLUR  <St>, [<Xn|SP>{, #<simm>}]
struct StlurSLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STLUR: Store-release SIMD&FP register (unscaled offset)
// Encoding: STLUR_D_ldapstl_simd
// Template: STLUR  <Dt>, [<Xn|SP>{, #<simm>}]
struct StlurDLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STLUR: Store-release SIMD&FP register (unscaled offset)
// Encoding: STLUR_Q_ldapstl_simd
// Template: STLUR  <Qt>, [<Xn|SP>{, #<simm>}]
struct StlurQLdapstlSimd {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_2 : 2;  // fixed: 0b10 (0x2)
    int32_t imm9 : 9;
    uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_0 : 6;  // fixed: 0b011101 (0x1D)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STNP: Store pair of SIMD&FP registers, with non-temporal hint
// Encoding: STNP_S_ldstnapair_offs
// Template: STNP  <St1>, <St2>, [<Xn|SP>{, #<imm>}]
struct StnpSLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// STNP: Store pair of SIMD&FP registers, with non-temporal hint
// Encoding: STNP_D_ldstnapair_offs
// Template: STNP  <Dt1>, <Dt2>, [<Xn|SP>{, #<imm>}]
struct StnpDLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// STNP: Store pair of SIMD&FP registers, with non-temporal hint
// Encoding: STNP_Q_ldstnapair_offs
// Template: STNP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct StnpQLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b000 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_S_ldstpair_post
// Template: STP  <St1>, <St2>, [<Xn|SP>], #<imm>
struct StpSLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_D_ldstpair_post
// Template: STP  <Dt1>, <Dt2>, [<Xn|SP>], #<imm>
struct StpDLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_Q_ldstpair_post
// Template: STP  <Qt1>, <Qt2>, [<Xn|SP>], #<imm>
struct StpQLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b001 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_S_ldstpair_pre
// Template: STP  <St1>, <St2>, [<Xn|SP>, #<imm>]!
struct StpSLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_D_ldstpair_pre
// Template: STP  <Dt1>, <Dt2>, [<Xn|SP>, #<imm>]!
struct StpDLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_Q_ldstpair_pre
// Template: STP  <Qt1>, <Qt2>, [<Xn|SP>, #<imm>]!
struct StpQLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b011 (0x3)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_S_ldstpair_off
// Template: STP  <St1>, <St2>, [<Xn|SP>{, #<imm>}]
struct StpSLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_D_ldstpair_off
// Template: STP  <Dt1>, <Dt2>, [<Xn|SP>{, #<imm>}]
struct StpDLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b01 (0x1)
};


// STP: Store pair of SIMD&FP registers
// Encoding: STP_Q_ldstpair_off
// Template: STP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct StpQLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_1 : 3;  // fixed: 0b010 (0x2)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b101 (0x5)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_B_ldst_immpost
// Template: STR  <Bt>, [<Xn|SP>], #<simm>
struct StrBLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_H_ldst_immpost
// Template: STR  <Ht>, [<Xn|SP>], #<simm>
struct StrHLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_S_ldst_immpost
// Template: STR  <St>, [<Xn|SP>], #<simm>
struct StrSLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_D_ldst_immpost
// Template: STR  <Dt>, [<Xn|SP>], #<simm>
struct StrDLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_Q_ldst_immpost
// Template: STR  <Qt>, [<Xn|SP>], #<simm>
struct StrQLdstImmpost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_B_ldst_immpre
// Template: STR  <Bt>, [<Xn|SP>, #<simm>]!
struct StrBLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_H_ldst_immpre
// Template: STR  <Ht>, [<Xn|SP>, #<simm>]!
struct StrHLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_S_ldst_immpre
// Template: STR  <St>, [<Xn|SP>, #<simm>]!
struct StrSLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_D_ldst_immpre
// Template: STR  <Dt>, [<Xn|SP>, #<simm>]!
struct StrDLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_Q_ldst_immpre
// Template: STR  <Qt>, [<Xn|SP>, #<simm>]!
struct StrQLdstImmpre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_B_ldst_pos
// Template: STR  <Bt>, [<Xn|SP>{, #<pimm>}]
struct StrBLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_H_ldst_pos
// Template: STR  <Ht>, [<Xn|SP>{, #<pimm>}]
struct StrHLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_S_ldst_pos
// Template: STR  <St>, [<Xn|SP>{, #<pimm>}]
struct StrSLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_D_ldst_pos
// Template: STR  <Dt>, [<Xn|SP>{, #<pimm>}]
struct StrDLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STR: Store SIMD&FP register (immediate offset)
// Encoding: STR_Q_ldst_pos
// Template: STR  <Qt>, [<Xn|SP>{, #<pimm>}]
struct StrQLdstPos {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t imm12 : 12;
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 2;  // fixed: 0b01 (0x1)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_B_ldst_regoff
// Template: STR  <Bt>, [<Xn|SP>, (<Wm>|<Xm>), <extend> {<amount>}]
struct StrBLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_BL_ldst_regoff
// Template: STR  <Bt>, [<Xn|SP>, <Xm>{, LSL <amount>}]
struct StrBlLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;  // fixed: 0b011 (0x3)
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_H_ldst_regoff
// Template: STR  <Ht>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct StrHLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_S_ldst_regoff
// Template: STR  <St>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct StrSLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_D_ldst_regoff
// Template: STR  <Dt>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct StrDLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STR: Store SIMD&FP register (register offset)
// Encoding: STR_Q_ldst_regoff
// Template: STR  <Qt>, [<Xn|SP>, (<Wm>|<Xm>){, <extend> {<amount>}}]
struct StrQLdstRegoff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t S : 1;
    uint32_t option : 3;
    uint32_t Rm : 5;
    uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STTNP: Store unprivileged pair of SIMD&FP registers, with non-temporal hint
// Encoding: STTNP_Q_ldstnapair_offs
// Template: STTNP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct SttnpQLdstnapairOffs {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// STTP: Store unprivileged pair of SIMD&FP registers
// Encoding: STTP_Q_ldstpair_post
// Template: STTP  <Qt1>, <Qt2>, [<Xn|SP>], #<imm>
struct SttpQLdstpairPost {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// STTP: Store unprivileged pair of SIMD&FP registers
// Encoding: STTP_Q_ldstpair_pre
// Template: STTP  <Qt1>, <Qt2>, [<Xn|SP>, #<imm>]!
struct SttpQLdstpairPre {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// STTP: Store unprivileged pair of SIMD&FP registers
// Encoding: STTP_Q_ldstpair_off
// Template: STTP  <Qt1>, <Qt2>, [<Xn|SP>{, #<imm>}]
struct SttpQLdstpairOff {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t Rt2 : 5;
    uint32_t imm7 : 7;
    uint32_t L : 1;  // fixed: 0b0 (0x0)
    uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 2;  // fixed: 0b10 (0x2)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
};


// STUR: Store SIMD&FP register (unscaled offset)
// Encoding: STUR_B_ldst_unscaled
// Template: STUR  <Bt>, [<Xn|SP>{, #<simm>}]
struct SturBLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// STUR: Store SIMD&FP register (unscaled offset)
// Encoding: STUR_H_ldst_unscaled
// Template: STUR  <Ht>, [<Xn|SP>{, #<simm>}]
struct SturHLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b01 (0x1)
};


// STUR: Store SIMD&FP register (unscaled offset)
// Encoding: STUR_S_ldst_unscaled
// Template: STUR  <St>, [<Xn|SP>{, #<simm>}]
struct SturSLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b10 (0x2)
};


// STUR: Store SIMD&FP register (unscaled offset)
// Encoding: STUR_D_ldst_unscaled
// Template: STUR  <Dt>, [<Xn|SP>{, #<simm>}]
struct SturDLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b00 (0x0)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b11 (0x3)
};


// STUR: Store SIMD&FP register (unscaled offset)
// Encoding: STUR_Q_ldst_unscaled
// Template: STUR  <Qt>, [<Xn|SP>{, #<simm>}]
struct SturQLdstUnscaled {
    uint32_t Rt : 5;
    uint32_t Rn : 5;
    uint32_t _unnamed_3 : 2;  // fixed: 0b00 (0x0)
    int32_t imm9 : 9;
    uint32_t _unnamed_2 : 1;  // fixed: 0b0 (0x0)
    uint32_t opc : 2;  // fixed: 0b10 (0x2)
    uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
    uint32_t VR : 1;  // fixed: 0b1 (0x1)
    uint32_t _unnamed_0 : 3;  // fixed: 0b111 (0x7)
    uint32_t size : 2;  // fixed: 0b00 (0x0)
};


// Union for fpsimd instruction class
union FpsimdEncoding {
    LdapurBLdapstlSimd ldapur_bldapstl_simd;
    LdapurHLdapstlSimd ldapur_hldapstl_simd;
    LdapurSLdapstlSimd ldapur_sldapstl_simd;
    LdapurDLdapstlSimd ldapur_dldapstl_simd;
    LdapurQLdapstlSimd ldapur_qldapstl_simd;
    LdnpSLdstnapairOffs ldnp_sldstnapair_offs;
    LdnpDLdstnapairOffs ldnp_dldstnapair_offs;
    LdnpQLdstnapairOffs ldnp_qldstnapair_offs;
    LdpSLdstpairPost ldp_sldstpair_post;
    LdpDLdstpairPost ldp_dldstpair_post;
    LdpQLdstpairPost ldp_qldstpair_post;
    LdpSLdstpairPre ldp_sldstpair_pre;
    LdpDLdstpairPre ldp_dldstpair_pre;
    LdpQLdstpairPre ldp_qldstpair_pre;
    LdpSLdstpairOff ldp_sldstpair_off;
    LdpDLdstpairOff ldp_dldstpair_off;
    LdpQLdstpairOff ldp_qldstpair_off;
    LdrBLdstImmpost ldr_bldst_immpost;
    LdrHLdstImmpost ldr_hldst_immpost;
    LdrSLdstImmpost ldr_sldst_immpost;
    LdrDLdstImmpost ldr_dldst_immpost;
    LdrQLdstImmpost ldr_qldst_immpost;
    LdrBLdstImmpre ldr_bldst_immpre;
    LdrHLdstImmpre ldr_hldst_immpre;
    LdrSLdstImmpre ldr_sldst_immpre;
    LdrDLdstImmpre ldr_dldst_immpre;
    LdrQLdstImmpre ldr_qldst_immpre;
    LdrBLdstPos ldr_bldst_pos;
    LdrHLdstPos ldr_hldst_pos;
    LdrSLdstPos ldr_sldst_pos;
    LdrDLdstPos ldr_dldst_pos;
    LdrQLdstPos ldr_qldst_pos;
    LdrSLoadlit ldr_sloadlit;
    LdrDLoadlit ldr_dloadlit;
    LdrQLoadlit ldr_qloadlit;
    LdrBLdstRegoff ldr_bldst_regoff;
    LdrBlLdstRegoff ldr_bl_ldst_regoff;
    LdrHLdstRegoff ldr_hldst_regoff;
    LdrSLdstRegoff ldr_sldst_regoff;
    LdrDLdstRegoff ldr_dldst_regoff;
    LdrQLdstRegoff ldr_qldst_regoff;
    LdtnpQLdstnapairOffs ldtnp_qldstnapair_offs;
    LdtpQLdstpairPost ldtp_qldstpair_post;
    LdtpQLdstpairPre ldtp_qldstpair_pre;
    LdtpQLdstpairOff ldtp_qldstpair_off;
    LdurBLdstUnscaled ldur_bldst_unscaled;
    LdurHLdstUnscaled ldur_hldst_unscaled;
    LdurSLdstUnscaled ldur_sldst_unscaled;
    LdurDLdstUnscaled ldur_dldst_unscaled;
    LdurQLdstUnscaled ldur_qldst_unscaled;
    StlurBLdapstlSimd stlur_bldapstl_simd;
    StlurHLdapstlSimd stlur_hldapstl_simd;
    StlurSLdapstlSimd stlur_sldapstl_simd;
    StlurDLdapstlSimd stlur_dldapstl_simd;
    StlurQLdapstlSimd stlur_qldapstl_simd;
    StnpSLdstnapairOffs stnp_sldstnapair_offs;
    StnpDLdstnapairOffs stnp_dldstnapair_offs;
    StnpQLdstnapairOffs stnp_qldstnapair_offs;
    StpSLdstpairPost stp_sldstpair_post;
    StpDLdstpairPost stp_dldstpair_post;
    StpQLdstpairPost stp_qldstpair_post;
    StpSLdstpairPre stp_sldstpair_pre;
    StpDLdstpairPre stp_dldstpair_pre;
    StpQLdstpairPre stp_qldstpair_pre;
    StpSLdstpairOff stp_sldstpair_off;
    StpDLdstpairOff stp_dldstpair_off;
    StpQLdstpairOff stp_qldstpair_off;
    StrBLdstImmpost str_bldst_immpost;
    StrHLdstImmpost str_hldst_immpost;
    StrSLdstImmpost str_sldst_immpost;
    StrDLdstImmpost str_dldst_immpost;
    StrQLdstImmpost str_qldst_immpost;
    StrBLdstImmpre str_bldst_immpre;
    StrHLdstImmpre str_hldst_immpre;
    StrSLdstImmpre str_sldst_immpre;
    StrDLdstImmpre str_dldst_immpre;
    StrQLdstImmpre str_qldst_immpre;
    StrBLdstPos str_bldst_pos;
    StrHLdstPos str_hldst_pos;
    StrSLdstPos str_sldst_pos;
    StrDLdstPos str_dldst_pos;
    StrQLdstPos str_qldst_pos;
    StrBLdstRegoff str_bldst_regoff;
    StrBlLdstRegoff str_bl_ldst_regoff;
    StrHLdstRegoff str_hldst_regoff;
    StrSLdstRegoff str_sldst_regoff;
    StrDLdstRegoff str_dldst_regoff;
    StrQLdstRegoff str_qldst_regoff;
    SttnpQLdstnapairOffs sttnp_qldstnapair_offs;
    SttpQLdstpairPost sttp_qldstpair_post;
    SttpQLdstpairPre sttp_qldstpair_pre;
    SttpQLdstpairOff sttp_qldstpair_off;
    SturBLdstUnscaled stur_bldst_unscaled;
    SturHLdstUnscaled stur_hldst_unscaled;
    SturSLdstUnscaled stur_sldst_unscaled;
    SturDLdstUnscaled stur_dldst_unscaled;
    SturQLdstUnscaled stur_qldst_unscaled;
    uint32_t raw;
};
static_assert(sizeof(FpsimdEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_ldapur_b_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldapur_bldapstl_simd.Rt = Rt;
    insn.ldapur_bldapstl_simd.Rn = Rn;
    insn.ldapur_bldapstl_simd._unnamed_2 = 0b10;
    insn.ldapur_bldapstl_simd.imm9 = imm9;
    insn.ldapur_bldapstl_simd._unnamed_1 = 0b0;
    insn.ldapur_bldapstl_simd.opc = 0b01;
    insn.ldapur_bldapstl_simd._unnamed_0 = 0b011101;
    insn.ldapur_bldapstl_simd.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldapur_h_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldapur_hldapstl_simd.Rt = Rt;
    insn.ldapur_hldapstl_simd.Rn = Rn;
    insn.ldapur_hldapstl_simd._unnamed_2 = 0b10;
    insn.ldapur_hldapstl_simd.imm9 = imm9;
    insn.ldapur_hldapstl_simd._unnamed_1 = 0b0;
    insn.ldapur_hldapstl_simd.opc = 0b01;
    insn.ldapur_hldapstl_simd._unnamed_0 = 0b011101;
    insn.ldapur_hldapstl_simd.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldapur_s_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldapur_sldapstl_simd.Rt = Rt;
    insn.ldapur_sldapstl_simd.Rn = Rn;
    insn.ldapur_sldapstl_simd._unnamed_2 = 0b10;
    insn.ldapur_sldapstl_simd.imm9 = imm9;
    insn.ldapur_sldapstl_simd._unnamed_1 = 0b0;
    insn.ldapur_sldapstl_simd.opc = 0b01;
    insn.ldapur_sldapstl_simd._unnamed_0 = 0b011101;
    insn.ldapur_sldapstl_simd.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldapur_d_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldapur_dldapstl_simd.Rt = Rt;
    insn.ldapur_dldapstl_simd.Rn = Rn;
    insn.ldapur_dldapstl_simd._unnamed_2 = 0b10;
    insn.ldapur_dldapstl_simd.imm9 = imm9;
    insn.ldapur_dldapstl_simd._unnamed_1 = 0b0;
    insn.ldapur_dldapstl_simd.opc = 0b01;
    insn.ldapur_dldapstl_simd._unnamed_0 = 0b011101;
    insn.ldapur_dldapstl_simd.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldapur_q_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldapur_qldapstl_simd.Rt = Rt;
    insn.ldapur_qldapstl_simd.Rn = Rn;
    insn.ldapur_qldapstl_simd._unnamed_2 = 0b10;
    insn.ldapur_qldapstl_simd.imm9 = imm9;
    insn.ldapur_qldapstl_simd._unnamed_1 = 0b0;
    insn.ldapur_qldapstl_simd.opc = 0b11;
    insn.ldapur_qldapstl_simd._unnamed_0 = 0b011101;
    insn.ldapur_qldapstl_simd.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldnp_s_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldnp_sldstnapair_offs.Rt = Rt;
    insn.ldnp_sldstnapair_offs.Rn = Rn;
    insn.ldnp_sldstnapair_offs.Rt2 = Rt2;
    insn.ldnp_sldstnapair_offs.imm7 = imm7;
    insn.ldnp_sldstnapair_offs.L = 0b1;
    insn.ldnp_sldstnapair_offs._unnamed_1 = 0b000;
    insn.ldnp_sldstnapair_offs.VR = 0b1;
    insn.ldnp_sldstnapair_offs._unnamed_0 = 0b101;
    insn.ldnp_sldstnapair_offs.opc = 0b00;
    return insn.raw;
}

uint32_t encode_ldnp_d_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldnp_dldstnapair_offs.Rt = Rt;
    insn.ldnp_dldstnapair_offs.Rn = Rn;
    insn.ldnp_dldstnapair_offs.Rt2 = Rt2;
    insn.ldnp_dldstnapair_offs.imm7 = imm7;
    insn.ldnp_dldstnapair_offs.L = 0b1;
    insn.ldnp_dldstnapair_offs._unnamed_1 = 0b000;
    insn.ldnp_dldstnapair_offs.VR = 0b1;
    insn.ldnp_dldstnapair_offs._unnamed_0 = 0b101;
    insn.ldnp_dldstnapair_offs.opc = 0b01;
    return insn.raw;
}

uint32_t encode_ldnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldnp_qldstnapair_offs.Rt = Rt;
    insn.ldnp_qldstnapair_offs.Rn = Rn;
    insn.ldnp_qldstnapair_offs.Rt2 = Rt2;
    insn.ldnp_qldstnapair_offs.imm7 = imm7;
    insn.ldnp_qldstnapair_offs.L = 0b1;
    insn.ldnp_qldstnapair_offs._unnamed_1 = 0b000;
    insn.ldnp_qldstnapair_offs.VR = 0b1;
    insn.ldnp_qldstnapair_offs._unnamed_0 = 0b101;
    insn.ldnp_qldstnapair_offs.opc = 0b10;
    return insn.raw;
}

uint32_t encode_ldp_s_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_sldstpair_post.Rt = Rt;
    insn.ldp_sldstpair_post.Rn = Rn;
    insn.ldp_sldstpair_post.Rt2 = Rt2;
    insn.ldp_sldstpair_post.imm7 = imm7;
    insn.ldp_sldstpair_post.L = 0b1;
    insn.ldp_sldstpair_post._unnamed_1 = 0b001;
    insn.ldp_sldstpair_post.VR = 0b1;
    insn.ldp_sldstpair_post._unnamed_0 = 0b101;
    insn.ldp_sldstpair_post.opc = 0b00;
    return insn.raw;
}

uint32_t encode_ldp_d_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_dldstpair_post.Rt = Rt;
    insn.ldp_dldstpair_post.Rn = Rn;
    insn.ldp_dldstpair_post.Rt2 = Rt2;
    insn.ldp_dldstpair_post.imm7 = imm7;
    insn.ldp_dldstpair_post.L = 0b1;
    insn.ldp_dldstpair_post._unnamed_1 = 0b001;
    insn.ldp_dldstpair_post.VR = 0b1;
    insn.ldp_dldstpair_post._unnamed_0 = 0b101;
    insn.ldp_dldstpair_post.opc = 0b01;
    return insn.raw;
}

uint32_t encode_ldp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_qldstpair_post.Rt = Rt;
    insn.ldp_qldstpair_post.Rn = Rn;
    insn.ldp_qldstpair_post.Rt2 = Rt2;
    insn.ldp_qldstpair_post.imm7 = imm7;
    insn.ldp_qldstpair_post.L = 0b1;
    insn.ldp_qldstpair_post._unnamed_1 = 0b001;
    insn.ldp_qldstpair_post.VR = 0b1;
    insn.ldp_qldstpair_post._unnamed_0 = 0b101;
    insn.ldp_qldstpair_post.opc = 0b10;
    return insn.raw;
}

uint32_t encode_ldp_s_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_sldstpair_pre.Rt = Rt;
    insn.ldp_sldstpair_pre.Rn = Rn;
    insn.ldp_sldstpair_pre.Rt2 = Rt2;
    insn.ldp_sldstpair_pre.imm7 = imm7;
    insn.ldp_sldstpair_pre.L = 0b1;
    insn.ldp_sldstpair_pre._unnamed_1 = 0b011;
    insn.ldp_sldstpair_pre.VR = 0b1;
    insn.ldp_sldstpair_pre._unnamed_0 = 0b101;
    insn.ldp_sldstpair_pre.opc = 0b00;
    return insn.raw;
}

uint32_t encode_ldp_d_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_dldstpair_pre.Rt = Rt;
    insn.ldp_dldstpair_pre.Rn = Rn;
    insn.ldp_dldstpair_pre.Rt2 = Rt2;
    insn.ldp_dldstpair_pre.imm7 = imm7;
    insn.ldp_dldstpair_pre.L = 0b1;
    insn.ldp_dldstpair_pre._unnamed_1 = 0b011;
    insn.ldp_dldstpair_pre.VR = 0b1;
    insn.ldp_dldstpair_pre._unnamed_0 = 0b101;
    insn.ldp_dldstpair_pre.opc = 0b01;
    return insn.raw;
}

uint32_t encode_ldp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_qldstpair_pre.Rt = Rt;
    insn.ldp_qldstpair_pre.Rn = Rn;
    insn.ldp_qldstpair_pre.Rt2 = Rt2;
    insn.ldp_qldstpair_pre.imm7 = imm7;
    insn.ldp_qldstpair_pre.L = 0b1;
    insn.ldp_qldstpair_pre._unnamed_1 = 0b011;
    insn.ldp_qldstpair_pre.VR = 0b1;
    insn.ldp_qldstpair_pre._unnamed_0 = 0b101;
    insn.ldp_qldstpair_pre.opc = 0b10;
    return insn.raw;
}

uint32_t encode_ldp_s_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_sldstpair_off.Rt = Rt;
    insn.ldp_sldstpair_off.Rn = Rn;
    insn.ldp_sldstpair_off.Rt2 = Rt2;
    insn.ldp_sldstpair_off.imm7 = imm7;
    insn.ldp_sldstpair_off.L = 0b1;
    insn.ldp_sldstpair_off._unnamed_1 = 0b010;
    insn.ldp_sldstpair_off.VR = 0b1;
    insn.ldp_sldstpair_off._unnamed_0 = 0b101;
    insn.ldp_sldstpair_off.opc = 0b00;
    return insn.raw;
}

uint32_t encode_ldp_d_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_dldstpair_off.Rt = Rt;
    insn.ldp_dldstpair_off.Rn = Rn;
    insn.ldp_dldstpair_off.Rt2 = Rt2;
    insn.ldp_dldstpair_off.imm7 = imm7;
    insn.ldp_dldstpair_off.L = 0b1;
    insn.ldp_dldstpair_off._unnamed_1 = 0b010;
    insn.ldp_dldstpair_off.VR = 0b1;
    insn.ldp_dldstpair_off._unnamed_0 = 0b101;
    insn.ldp_dldstpair_off.opc = 0b01;
    return insn.raw;
}

uint32_t encode_ldp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldp_qldstpair_off.Rt = Rt;
    insn.ldp_qldstpair_off.Rn = Rn;
    insn.ldp_qldstpair_off.Rt2 = Rt2;
    insn.ldp_qldstpair_off.imm7 = imm7;
    insn.ldp_qldstpair_off.L = 0b1;
    insn.ldp_qldstpair_off._unnamed_1 = 0b010;
    insn.ldp_qldstpair_off.VR = 0b1;
    insn.ldp_qldstpair_off._unnamed_0 = 0b101;
    insn.ldp_qldstpair_off.opc = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_b_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_bldst_immpost.Rt = Rt;
    insn.ldr_bldst_immpost.Rn = Rn;
    insn.ldr_bldst_immpost._unnamed_3 = 0b01;
    insn.ldr_bldst_immpost.imm9 = imm9;
    insn.ldr_bldst_immpost._unnamed_2 = 0b0;
    insn.ldr_bldst_immpost.opc = 0b01;
    insn.ldr_bldst_immpost._unnamed_1 = 0b00;
    insn.ldr_bldst_immpost.VR = 0b1;
    insn.ldr_bldst_immpost._unnamed_0 = 0b111;
    insn.ldr_bldst_immpost.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_h_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_hldst_immpost.Rt = Rt;
    insn.ldr_hldst_immpost.Rn = Rn;
    insn.ldr_hldst_immpost._unnamed_3 = 0b01;
    insn.ldr_hldst_immpost.imm9 = imm9;
    insn.ldr_hldst_immpost._unnamed_2 = 0b0;
    insn.ldr_hldst_immpost.opc = 0b01;
    insn.ldr_hldst_immpost._unnamed_1 = 0b00;
    insn.ldr_hldst_immpost.VR = 0b1;
    insn.ldr_hldst_immpost._unnamed_0 = 0b111;
    insn.ldr_hldst_immpost.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldr_s_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_sldst_immpost.Rt = Rt;
    insn.ldr_sldst_immpost.Rn = Rn;
    insn.ldr_sldst_immpost._unnamed_3 = 0b01;
    insn.ldr_sldst_immpost.imm9 = imm9;
    insn.ldr_sldst_immpost._unnamed_2 = 0b0;
    insn.ldr_sldst_immpost.opc = 0b01;
    insn.ldr_sldst_immpost._unnamed_1 = 0b00;
    insn.ldr_sldst_immpost.VR = 0b1;
    insn.ldr_sldst_immpost._unnamed_0 = 0b111;
    insn.ldr_sldst_immpost.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_d_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_dldst_immpost.Rt = Rt;
    insn.ldr_dldst_immpost.Rn = Rn;
    insn.ldr_dldst_immpost._unnamed_3 = 0b01;
    insn.ldr_dldst_immpost.imm9 = imm9;
    insn.ldr_dldst_immpost._unnamed_2 = 0b0;
    insn.ldr_dldst_immpost.opc = 0b01;
    insn.ldr_dldst_immpost._unnamed_1 = 0b00;
    insn.ldr_dldst_immpost.VR = 0b1;
    insn.ldr_dldst_immpost._unnamed_0 = 0b111;
    insn.ldr_dldst_immpost.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldr_q_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_qldst_immpost.Rt = Rt;
    insn.ldr_qldst_immpost.Rn = Rn;
    insn.ldr_qldst_immpost._unnamed_3 = 0b01;
    insn.ldr_qldst_immpost.imm9 = imm9;
    insn.ldr_qldst_immpost._unnamed_2 = 0b0;
    insn.ldr_qldst_immpost.opc = 0b11;
    insn.ldr_qldst_immpost._unnamed_1 = 0b00;
    insn.ldr_qldst_immpost.VR = 0b1;
    insn.ldr_qldst_immpost._unnamed_0 = 0b111;
    insn.ldr_qldst_immpost.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_b_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_bldst_immpre.Rt = Rt;
    insn.ldr_bldst_immpre.Rn = Rn;
    insn.ldr_bldst_immpre._unnamed_3 = 0b11;
    insn.ldr_bldst_immpre.imm9 = imm9;
    insn.ldr_bldst_immpre._unnamed_2 = 0b0;
    insn.ldr_bldst_immpre.opc = 0b01;
    insn.ldr_bldst_immpre._unnamed_1 = 0b00;
    insn.ldr_bldst_immpre.VR = 0b1;
    insn.ldr_bldst_immpre._unnamed_0 = 0b111;
    insn.ldr_bldst_immpre.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_h_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_hldst_immpre.Rt = Rt;
    insn.ldr_hldst_immpre.Rn = Rn;
    insn.ldr_hldst_immpre._unnamed_3 = 0b11;
    insn.ldr_hldst_immpre.imm9 = imm9;
    insn.ldr_hldst_immpre._unnamed_2 = 0b0;
    insn.ldr_hldst_immpre.opc = 0b01;
    insn.ldr_hldst_immpre._unnamed_1 = 0b00;
    insn.ldr_hldst_immpre.VR = 0b1;
    insn.ldr_hldst_immpre._unnamed_0 = 0b111;
    insn.ldr_hldst_immpre.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldr_s_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_sldst_immpre.Rt = Rt;
    insn.ldr_sldst_immpre.Rn = Rn;
    insn.ldr_sldst_immpre._unnamed_3 = 0b11;
    insn.ldr_sldst_immpre.imm9 = imm9;
    insn.ldr_sldst_immpre._unnamed_2 = 0b0;
    insn.ldr_sldst_immpre.opc = 0b01;
    insn.ldr_sldst_immpre._unnamed_1 = 0b00;
    insn.ldr_sldst_immpre.VR = 0b1;
    insn.ldr_sldst_immpre._unnamed_0 = 0b111;
    insn.ldr_sldst_immpre.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_d_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_dldst_immpre.Rt = Rt;
    insn.ldr_dldst_immpre.Rn = Rn;
    insn.ldr_dldst_immpre._unnamed_3 = 0b11;
    insn.ldr_dldst_immpre.imm9 = imm9;
    insn.ldr_dldst_immpre._unnamed_2 = 0b0;
    insn.ldr_dldst_immpre.opc = 0b01;
    insn.ldr_dldst_immpre._unnamed_1 = 0b00;
    insn.ldr_dldst_immpre.VR = 0b1;
    insn.ldr_dldst_immpre._unnamed_0 = 0b111;
    insn.ldr_dldst_immpre.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldr_q_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldr_qldst_immpre.Rt = Rt;
    insn.ldr_qldst_immpre.Rn = Rn;
    insn.ldr_qldst_immpre._unnamed_3 = 0b11;
    insn.ldr_qldst_immpre.imm9 = imm9;
    insn.ldr_qldst_immpre._unnamed_2 = 0b0;
    insn.ldr_qldst_immpre.opc = 0b11;
    insn.ldr_qldst_immpre._unnamed_1 = 0b00;
    insn.ldr_qldst_immpre.VR = 0b1;
    insn.ldr_qldst_immpre._unnamed_0 = 0b111;
    insn.ldr_qldst_immpre.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_b_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.ldr_bldst_pos.Rt = Rt;
    insn.ldr_bldst_pos.Rn = Rn;
    insn.ldr_bldst_pos.imm12 = imm12;
    insn.ldr_bldst_pos.opc = 0b01;
    insn.ldr_bldst_pos._unnamed_1 = 0b01;
    insn.ldr_bldst_pos.VR = 0b1;
    insn.ldr_bldst_pos._unnamed_0 = 0b111;
    insn.ldr_bldst_pos.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_h_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.ldr_hldst_pos.Rt = Rt;
    insn.ldr_hldst_pos.Rn = Rn;
    insn.ldr_hldst_pos.imm12 = imm12;
    insn.ldr_hldst_pos.opc = 0b01;
    insn.ldr_hldst_pos._unnamed_1 = 0b01;
    insn.ldr_hldst_pos.VR = 0b1;
    insn.ldr_hldst_pos._unnamed_0 = 0b111;
    insn.ldr_hldst_pos.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldr_s_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.ldr_sldst_pos.Rt = Rt;
    insn.ldr_sldst_pos.Rn = Rn;
    insn.ldr_sldst_pos.imm12 = imm12;
    insn.ldr_sldst_pos.opc = 0b01;
    insn.ldr_sldst_pos._unnamed_1 = 0b01;
    insn.ldr_sldst_pos.VR = 0b1;
    insn.ldr_sldst_pos._unnamed_0 = 0b111;
    insn.ldr_sldst_pos.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_d_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.ldr_dldst_pos.Rt = Rt;
    insn.ldr_dldst_pos.Rn = Rn;
    insn.ldr_dldst_pos.imm12 = imm12;
    insn.ldr_dldst_pos.opc = 0b01;
    insn.ldr_dldst_pos._unnamed_1 = 0b01;
    insn.ldr_dldst_pos.VR = 0b1;
    insn.ldr_dldst_pos._unnamed_0 = 0b111;
    insn.ldr_dldst_pos.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldr_q_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.ldr_qldst_pos.Rt = Rt;
    insn.ldr_qldst_pos.Rn = Rn;
    insn.ldr_qldst_pos.imm12 = imm12;
    insn.ldr_qldst_pos.opc = 0b11;
    insn.ldr_qldst_pos._unnamed_1 = 0b01;
    insn.ldr_qldst_pos.VR = 0b1;
    insn.ldr_qldst_pos._unnamed_0 = 0b111;
    insn.ldr_qldst_pos.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_s_loadlit(uint32_t Rt, int32_t imm19) {
    FpsimdEncoding insn = {};
    insn.ldr_sloadlit.Rt = Rt;
    insn.ldr_sloadlit.imm19 = imm19;
    insn.ldr_sloadlit._unnamed_1 = 0b00;
    insn.ldr_sloadlit.VR = 0b1;
    insn.ldr_sloadlit._unnamed_0 = 0b011;
    insn.ldr_sloadlit.opc = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_d_loadlit(uint32_t Rt, int32_t imm19) {
    FpsimdEncoding insn = {};
    insn.ldr_dloadlit.Rt = Rt;
    insn.ldr_dloadlit.imm19 = imm19;
    insn.ldr_dloadlit._unnamed_1 = 0b00;
    insn.ldr_dloadlit.VR = 0b1;
    insn.ldr_dloadlit._unnamed_0 = 0b011;
    insn.ldr_dloadlit.opc = 0b01;
    return insn.raw;
}

uint32_t encode_ldr_q_loadlit(uint32_t Rt, int32_t imm19) {
    FpsimdEncoding insn = {};
    insn.ldr_qloadlit.Rt = Rt;
    insn.ldr_qloadlit.imm19 = imm19;
    insn.ldr_qloadlit._unnamed_1 = 0b00;
    insn.ldr_qloadlit.VR = 0b1;
    insn.ldr_qloadlit._unnamed_0 = 0b011;
    insn.ldr_qloadlit.opc = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_b_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_bldst_regoff.Rt = Rt;
    insn.ldr_bldst_regoff.Rn = Rn;
    insn.ldr_bldst_regoff._unnamed_3 = 0b10;
    insn.ldr_bldst_regoff.S = S;
    insn.ldr_bldst_regoff.option = option;
    insn.ldr_bldst_regoff.Rm = Rm;
    insn.ldr_bldst_regoff._unnamed_2 = 0b1;
    insn.ldr_bldst_regoff.opc = 0b01;
    insn.ldr_bldst_regoff._unnamed_1 = 0b00;
    insn.ldr_bldst_regoff.VR = 0b1;
    insn.ldr_bldst_regoff._unnamed_0 = 0b111;
    insn.ldr_bldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_bl_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_bl_ldst_regoff.Rt = Rt;
    insn.ldr_bl_ldst_regoff.Rn = Rn;
    insn.ldr_bl_ldst_regoff._unnamed_3 = 0b10;
    insn.ldr_bl_ldst_regoff.S = S;
    insn.ldr_bl_ldst_regoff.option = 0b011;
    insn.ldr_bl_ldst_regoff.Rm = Rm;
    insn.ldr_bl_ldst_regoff._unnamed_2 = 0b1;
    insn.ldr_bl_ldst_regoff.opc = 0b01;
    insn.ldr_bl_ldst_regoff._unnamed_1 = 0b00;
    insn.ldr_bl_ldst_regoff.VR = 0b1;
    insn.ldr_bl_ldst_regoff._unnamed_0 = 0b111;
    insn.ldr_bl_ldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldr_h_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_hldst_regoff.Rt = Rt;
    insn.ldr_hldst_regoff.Rn = Rn;
    insn.ldr_hldst_regoff._unnamed_3 = 0b10;
    insn.ldr_hldst_regoff.S = S;
    insn.ldr_hldst_regoff.option = option;
    insn.ldr_hldst_regoff.Rm = Rm;
    insn.ldr_hldst_regoff._unnamed_2 = 0b1;
    insn.ldr_hldst_regoff.opc = 0b01;
    insn.ldr_hldst_regoff._unnamed_1 = 0b00;
    insn.ldr_hldst_regoff.VR = 0b1;
    insn.ldr_hldst_regoff._unnamed_0 = 0b111;
    insn.ldr_hldst_regoff.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldr_s_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_sldst_regoff.Rt = Rt;
    insn.ldr_sldst_regoff.Rn = Rn;
    insn.ldr_sldst_regoff._unnamed_3 = 0b10;
    insn.ldr_sldst_regoff.S = S;
    insn.ldr_sldst_regoff.option = option;
    insn.ldr_sldst_regoff.Rm = Rm;
    insn.ldr_sldst_regoff._unnamed_2 = 0b1;
    insn.ldr_sldst_regoff.opc = 0b01;
    insn.ldr_sldst_regoff._unnamed_1 = 0b00;
    insn.ldr_sldst_regoff.VR = 0b1;
    insn.ldr_sldst_regoff._unnamed_0 = 0b111;
    insn.ldr_sldst_regoff.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldr_d_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_dldst_regoff.Rt = Rt;
    insn.ldr_dldst_regoff.Rn = Rn;
    insn.ldr_dldst_regoff._unnamed_3 = 0b10;
    insn.ldr_dldst_regoff.S = S;
    insn.ldr_dldst_regoff.option = option;
    insn.ldr_dldst_regoff.Rm = Rm;
    insn.ldr_dldst_regoff._unnamed_2 = 0b1;
    insn.ldr_dldst_regoff.opc = 0b01;
    insn.ldr_dldst_regoff._unnamed_1 = 0b00;
    insn.ldr_dldst_regoff.VR = 0b1;
    insn.ldr_dldst_regoff._unnamed_0 = 0b111;
    insn.ldr_dldst_regoff.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldr_q_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.ldr_qldst_regoff.Rt = Rt;
    insn.ldr_qldst_regoff.Rn = Rn;
    insn.ldr_qldst_regoff._unnamed_3 = 0b10;
    insn.ldr_qldst_regoff.S = S;
    insn.ldr_qldst_regoff.option = option;
    insn.ldr_qldst_regoff.Rm = Rm;
    insn.ldr_qldst_regoff._unnamed_2 = 0b1;
    insn.ldr_qldst_regoff.opc = 0b11;
    insn.ldr_qldst_regoff._unnamed_1 = 0b00;
    insn.ldr_qldst_regoff.VR = 0b1;
    insn.ldr_qldst_regoff._unnamed_0 = 0b111;
    insn.ldr_qldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldtnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldtnp_qldstnapair_offs.Rt = Rt;
    insn.ldtnp_qldstnapair_offs.Rn = Rn;
    insn.ldtnp_qldstnapair_offs.Rt2 = Rt2;
    insn.ldtnp_qldstnapair_offs.imm7 = imm7;
    insn.ldtnp_qldstnapair_offs.L = 0b1;
    insn.ldtnp_qldstnapair_offs._unnamed_3 = 0b00;
    insn.ldtnp_qldstnapair_offs._unnamed_2 = 0b0;
    insn.ldtnp_qldstnapair_offs.VR = 0b1;
    insn.ldtnp_qldstnapair_offs._unnamed_1 = 0b1;
    insn.ldtnp_qldstnapair_offs._unnamed_0 = 0b10;
    insn.ldtnp_qldstnapair_offs.opc = 0b11;
    return insn.raw;
}

uint32_t encode_ldtp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldtp_qldstpair_post.Rt = Rt;
    insn.ldtp_qldstpair_post.Rn = Rn;
    insn.ldtp_qldstpair_post.Rt2 = Rt2;
    insn.ldtp_qldstpair_post.imm7 = imm7;
    insn.ldtp_qldstpair_post.L = 0b1;
    insn.ldtp_qldstpair_post._unnamed_3 = 0b01;
    insn.ldtp_qldstpair_post._unnamed_2 = 0b0;
    insn.ldtp_qldstpair_post.VR = 0b1;
    insn.ldtp_qldstpair_post._unnamed_1 = 0b1;
    insn.ldtp_qldstpair_post._unnamed_0 = 0b10;
    insn.ldtp_qldstpair_post.opc = 0b11;
    return insn.raw;
}

uint32_t encode_ldtp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldtp_qldstpair_pre.Rt = Rt;
    insn.ldtp_qldstpair_pre.Rn = Rn;
    insn.ldtp_qldstpair_pre.Rt2 = Rt2;
    insn.ldtp_qldstpair_pre.imm7 = imm7;
    insn.ldtp_qldstpair_pre.L = 0b1;
    insn.ldtp_qldstpair_pre._unnamed_3 = 0b11;
    insn.ldtp_qldstpair_pre._unnamed_2 = 0b0;
    insn.ldtp_qldstpair_pre.VR = 0b1;
    insn.ldtp_qldstpair_pre._unnamed_1 = 0b1;
    insn.ldtp_qldstpair_pre._unnamed_0 = 0b10;
    insn.ldtp_qldstpair_pre.opc = 0b11;
    return insn.raw;
}

uint32_t encode_ldtp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.ldtp_qldstpair_off.Rt = Rt;
    insn.ldtp_qldstpair_off.Rn = Rn;
    insn.ldtp_qldstpair_off.Rt2 = Rt2;
    insn.ldtp_qldstpair_off.imm7 = imm7;
    insn.ldtp_qldstpair_off.L = 0b1;
    insn.ldtp_qldstpair_off._unnamed_3 = 0b10;
    insn.ldtp_qldstpair_off._unnamed_2 = 0b0;
    insn.ldtp_qldstpair_off.VR = 0b1;
    insn.ldtp_qldstpair_off._unnamed_1 = 0b1;
    insn.ldtp_qldstpair_off._unnamed_0 = 0b10;
    insn.ldtp_qldstpair_off.opc = 0b11;
    return insn.raw;
}

uint32_t encode_ldur_b_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldur_bldst_unscaled.Rt = Rt;
    insn.ldur_bldst_unscaled.Rn = Rn;
    insn.ldur_bldst_unscaled._unnamed_3 = 0b00;
    insn.ldur_bldst_unscaled.imm9 = imm9;
    insn.ldur_bldst_unscaled._unnamed_2 = 0b0;
    insn.ldur_bldst_unscaled.opc = 0b01;
    insn.ldur_bldst_unscaled._unnamed_1 = 0b00;
    insn.ldur_bldst_unscaled.VR = 0b1;
    insn.ldur_bldst_unscaled._unnamed_0 = 0b111;
    insn.ldur_bldst_unscaled.size = 0b00;
    return insn.raw;
}

uint32_t encode_ldur_h_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldur_hldst_unscaled.Rt = Rt;
    insn.ldur_hldst_unscaled.Rn = Rn;
    insn.ldur_hldst_unscaled._unnamed_3 = 0b00;
    insn.ldur_hldst_unscaled.imm9 = imm9;
    insn.ldur_hldst_unscaled._unnamed_2 = 0b0;
    insn.ldur_hldst_unscaled.opc = 0b01;
    insn.ldur_hldst_unscaled._unnamed_1 = 0b00;
    insn.ldur_hldst_unscaled.VR = 0b1;
    insn.ldur_hldst_unscaled._unnamed_0 = 0b111;
    insn.ldur_hldst_unscaled.size = 0b01;
    return insn.raw;
}

uint32_t encode_ldur_s_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldur_sldst_unscaled.Rt = Rt;
    insn.ldur_sldst_unscaled.Rn = Rn;
    insn.ldur_sldst_unscaled._unnamed_3 = 0b00;
    insn.ldur_sldst_unscaled.imm9 = imm9;
    insn.ldur_sldst_unscaled._unnamed_2 = 0b0;
    insn.ldur_sldst_unscaled.opc = 0b01;
    insn.ldur_sldst_unscaled._unnamed_1 = 0b00;
    insn.ldur_sldst_unscaled.VR = 0b1;
    insn.ldur_sldst_unscaled._unnamed_0 = 0b111;
    insn.ldur_sldst_unscaled.size = 0b10;
    return insn.raw;
}

uint32_t encode_ldur_d_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldur_dldst_unscaled.Rt = Rt;
    insn.ldur_dldst_unscaled.Rn = Rn;
    insn.ldur_dldst_unscaled._unnamed_3 = 0b00;
    insn.ldur_dldst_unscaled.imm9 = imm9;
    insn.ldur_dldst_unscaled._unnamed_2 = 0b0;
    insn.ldur_dldst_unscaled.opc = 0b01;
    insn.ldur_dldst_unscaled._unnamed_1 = 0b00;
    insn.ldur_dldst_unscaled.VR = 0b1;
    insn.ldur_dldst_unscaled._unnamed_0 = 0b111;
    insn.ldur_dldst_unscaled.size = 0b11;
    return insn.raw;
}

uint32_t encode_ldur_q_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.ldur_qldst_unscaled.Rt = Rt;
    insn.ldur_qldst_unscaled.Rn = Rn;
    insn.ldur_qldst_unscaled._unnamed_3 = 0b00;
    insn.ldur_qldst_unscaled.imm9 = imm9;
    insn.ldur_qldst_unscaled._unnamed_2 = 0b0;
    insn.ldur_qldst_unscaled.opc = 0b11;
    insn.ldur_qldst_unscaled._unnamed_1 = 0b00;
    insn.ldur_qldst_unscaled.VR = 0b1;
    insn.ldur_qldst_unscaled._unnamed_0 = 0b111;
    insn.ldur_qldst_unscaled.size = 0b00;
    return insn.raw;
}

uint32_t encode_stlur_b_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stlur_bldapstl_simd.Rt = Rt;
    insn.stlur_bldapstl_simd.Rn = Rn;
    insn.stlur_bldapstl_simd._unnamed_2 = 0b10;
    insn.stlur_bldapstl_simd.imm9 = imm9;
    insn.stlur_bldapstl_simd._unnamed_1 = 0b0;
    insn.stlur_bldapstl_simd.opc = 0b00;
    insn.stlur_bldapstl_simd._unnamed_0 = 0b011101;
    insn.stlur_bldapstl_simd.size = 0b00;
    return insn.raw;
}

uint32_t encode_stlur_h_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stlur_hldapstl_simd.Rt = Rt;
    insn.stlur_hldapstl_simd.Rn = Rn;
    insn.stlur_hldapstl_simd._unnamed_2 = 0b10;
    insn.stlur_hldapstl_simd.imm9 = imm9;
    insn.stlur_hldapstl_simd._unnamed_1 = 0b0;
    insn.stlur_hldapstl_simd.opc = 0b00;
    insn.stlur_hldapstl_simd._unnamed_0 = 0b011101;
    insn.stlur_hldapstl_simd.size = 0b01;
    return insn.raw;
}

uint32_t encode_stlur_s_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stlur_sldapstl_simd.Rt = Rt;
    insn.stlur_sldapstl_simd.Rn = Rn;
    insn.stlur_sldapstl_simd._unnamed_2 = 0b10;
    insn.stlur_sldapstl_simd.imm9 = imm9;
    insn.stlur_sldapstl_simd._unnamed_1 = 0b0;
    insn.stlur_sldapstl_simd.opc = 0b00;
    insn.stlur_sldapstl_simd._unnamed_0 = 0b011101;
    insn.stlur_sldapstl_simd.size = 0b10;
    return insn.raw;
}

uint32_t encode_stlur_d_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stlur_dldapstl_simd.Rt = Rt;
    insn.stlur_dldapstl_simd.Rn = Rn;
    insn.stlur_dldapstl_simd._unnamed_2 = 0b10;
    insn.stlur_dldapstl_simd.imm9 = imm9;
    insn.stlur_dldapstl_simd._unnamed_1 = 0b0;
    insn.stlur_dldapstl_simd.opc = 0b00;
    insn.stlur_dldapstl_simd._unnamed_0 = 0b011101;
    insn.stlur_dldapstl_simd.size = 0b11;
    return insn.raw;
}

uint32_t encode_stlur_q_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stlur_qldapstl_simd.Rt = Rt;
    insn.stlur_qldapstl_simd.Rn = Rn;
    insn.stlur_qldapstl_simd._unnamed_2 = 0b10;
    insn.stlur_qldapstl_simd.imm9 = imm9;
    insn.stlur_qldapstl_simd._unnamed_1 = 0b0;
    insn.stlur_qldapstl_simd.opc = 0b10;
    insn.stlur_qldapstl_simd._unnamed_0 = 0b011101;
    insn.stlur_qldapstl_simd.size = 0b00;
    return insn.raw;
}

uint32_t encode_stnp_s_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stnp_sldstnapair_offs.Rt = Rt;
    insn.stnp_sldstnapair_offs.Rn = Rn;
    insn.stnp_sldstnapair_offs.Rt2 = Rt2;
    insn.stnp_sldstnapair_offs.imm7 = imm7;
    insn.stnp_sldstnapair_offs.L = 0b0;
    insn.stnp_sldstnapair_offs._unnamed_1 = 0b000;
    insn.stnp_sldstnapair_offs.VR = 0b1;
    insn.stnp_sldstnapair_offs._unnamed_0 = 0b101;
    insn.stnp_sldstnapair_offs.opc = 0b00;
    return insn.raw;
}

uint32_t encode_stnp_d_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stnp_dldstnapair_offs.Rt = Rt;
    insn.stnp_dldstnapair_offs.Rn = Rn;
    insn.stnp_dldstnapair_offs.Rt2 = Rt2;
    insn.stnp_dldstnapair_offs.imm7 = imm7;
    insn.stnp_dldstnapair_offs.L = 0b0;
    insn.stnp_dldstnapair_offs._unnamed_1 = 0b000;
    insn.stnp_dldstnapair_offs.VR = 0b1;
    insn.stnp_dldstnapair_offs._unnamed_0 = 0b101;
    insn.stnp_dldstnapair_offs.opc = 0b01;
    return insn.raw;
}

uint32_t encode_stnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stnp_qldstnapair_offs.Rt = Rt;
    insn.stnp_qldstnapair_offs.Rn = Rn;
    insn.stnp_qldstnapair_offs.Rt2 = Rt2;
    insn.stnp_qldstnapair_offs.imm7 = imm7;
    insn.stnp_qldstnapair_offs.L = 0b0;
    insn.stnp_qldstnapair_offs._unnamed_1 = 0b000;
    insn.stnp_qldstnapair_offs.VR = 0b1;
    insn.stnp_qldstnapair_offs._unnamed_0 = 0b101;
    insn.stnp_qldstnapair_offs.opc = 0b10;
    return insn.raw;
}

uint32_t encode_stp_s_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_sldstpair_post.Rt = Rt;
    insn.stp_sldstpair_post.Rn = Rn;
    insn.stp_sldstpair_post.Rt2 = Rt2;
    insn.stp_sldstpair_post.imm7 = imm7;
    insn.stp_sldstpair_post.L = 0b0;
    insn.stp_sldstpair_post._unnamed_1 = 0b001;
    insn.stp_sldstpair_post.VR = 0b1;
    insn.stp_sldstpair_post._unnamed_0 = 0b101;
    insn.stp_sldstpair_post.opc = 0b00;
    return insn.raw;
}

uint32_t encode_stp_d_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_dldstpair_post.Rt = Rt;
    insn.stp_dldstpair_post.Rn = Rn;
    insn.stp_dldstpair_post.Rt2 = Rt2;
    insn.stp_dldstpair_post.imm7 = imm7;
    insn.stp_dldstpair_post.L = 0b0;
    insn.stp_dldstpair_post._unnamed_1 = 0b001;
    insn.stp_dldstpair_post.VR = 0b1;
    insn.stp_dldstpair_post._unnamed_0 = 0b101;
    insn.stp_dldstpair_post.opc = 0b01;
    return insn.raw;
}

uint32_t encode_stp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_qldstpair_post.Rt = Rt;
    insn.stp_qldstpair_post.Rn = Rn;
    insn.stp_qldstpair_post.Rt2 = Rt2;
    insn.stp_qldstpair_post.imm7 = imm7;
    insn.stp_qldstpair_post.L = 0b0;
    insn.stp_qldstpair_post._unnamed_1 = 0b001;
    insn.stp_qldstpair_post.VR = 0b1;
    insn.stp_qldstpair_post._unnamed_0 = 0b101;
    insn.stp_qldstpair_post.opc = 0b10;
    return insn.raw;
}

uint32_t encode_stp_s_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_sldstpair_pre.Rt = Rt;
    insn.stp_sldstpair_pre.Rn = Rn;
    insn.stp_sldstpair_pre.Rt2 = Rt2;
    insn.stp_sldstpair_pre.imm7 = imm7;
    insn.stp_sldstpair_pre.L = 0b0;
    insn.stp_sldstpair_pre._unnamed_1 = 0b011;
    insn.stp_sldstpair_pre.VR = 0b1;
    insn.stp_sldstpair_pre._unnamed_0 = 0b101;
    insn.stp_sldstpair_pre.opc = 0b00;
    return insn.raw;
}

uint32_t encode_stp_d_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_dldstpair_pre.Rt = Rt;
    insn.stp_dldstpair_pre.Rn = Rn;
    insn.stp_dldstpair_pre.Rt2 = Rt2;
    insn.stp_dldstpair_pre.imm7 = imm7;
    insn.stp_dldstpair_pre.L = 0b0;
    insn.stp_dldstpair_pre._unnamed_1 = 0b011;
    insn.stp_dldstpair_pre.VR = 0b1;
    insn.stp_dldstpair_pre._unnamed_0 = 0b101;
    insn.stp_dldstpair_pre.opc = 0b01;
    return insn.raw;
}

uint32_t encode_stp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_qldstpair_pre.Rt = Rt;
    insn.stp_qldstpair_pre.Rn = Rn;
    insn.stp_qldstpair_pre.Rt2 = Rt2;
    insn.stp_qldstpair_pre.imm7 = imm7;
    insn.stp_qldstpair_pre.L = 0b0;
    insn.stp_qldstpair_pre._unnamed_1 = 0b011;
    insn.stp_qldstpair_pre.VR = 0b1;
    insn.stp_qldstpair_pre._unnamed_0 = 0b101;
    insn.stp_qldstpair_pre.opc = 0b10;
    return insn.raw;
}

uint32_t encode_stp_s_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_sldstpair_off.Rt = Rt;
    insn.stp_sldstpair_off.Rn = Rn;
    insn.stp_sldstpair_off.Rt2 = Rt2;
    insn.stp_sldstpair_off.imm7 = imm7;
    insn.stp_sldstpair_off.L = 0b0;
    insn.stp_sldstpair_off._unnamed_1 = 0b010;
    insn.stp_sldstpair_off.VR = 0b1;
    insn.stp_sldstpair_off._unnamed_0 = 0b101;
    insn.stp_sldstpair_off.opc = 0b00;
    return insn.raw;
}

uint32_t encode_stp_d_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_dldstpair_off.Rt = Rt;
    insn.stp_dldstpair_off.Rn = Rn;
    insn.stp_dldstpair_off.Rt2 = Rt2;
    insn.stp_dldstpair_off.imm7 = imm7;
    insn.stp_dldstpair_off.L = 0b0;
    insn.stp_dldstpair_off._unnamed_1 = 0b010;
    insn.stp_dldstpair_off.VR = 0b1;
    insn.stp_dldstpair_off._unnamed_0 = 0b101;
    insn.stp_dldstpair_off.opc = 0b01;
    return insn.raw;
}

uint32_t encode_stp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.stp_qldstpair_off.Rt = Rt;
    insn.stp_qldstpair_off.Rn = Rn;
    insn.stp_qldstpair_off.Rt2 = Rt2;
    insn.stp_qldstpair_off.imm7 = imm7;
    insn.stp_qldstpair_off.L = 0b0;
    insn.stp_qldstpair_off._unnamed_1 = 0b010;
    insn.stp_qldstpair_off.VR = 0b1;
    insn.stp_qldstpair_off._unnamed_0 = 0b101;
    insn.stp_qldstpair_off.opc = 0b10;
    return insn.raw;
}

uint32_t encode_str_b_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_bldst_immpost.Rt = Rt;
    insn.str_bldst_immpost.Rn = Rn;
    insn.str_bldst_immpost._unnamed_3 = 0b01;
    insn.str_bldst_immpost.imm9 = imm9;
    insn.str_bldst_immpost._unnamed_2 = 0b0;
    insn.str_bldst_immpost.opc = 0b00;
    insn.str_bldst_immpost._unnamed_1 = 0b00;
    insn.str_bldst_immpost.VR = 0b1;
    insn.str_bldst_immpost._unnamed_0 = 0b111;
    insn.str_bldst_immpost.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_h_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_hldst_immpost.Rt = Rt;
    insn.str_hldst_immpost.Rn = Rn;
    insn.str_hldst_immpost._unnamed_3 = 0b01;
    insn.str_hldst_immpost.imm9 = imm9;
    insn.str_hldst_immpost._unnamed_2 = 0b0;
    insn.str_hldst_immpost.opc = 0b00;
    insn.str_hldst_immpost._unnamed_1 = 0b00;
    insn.str_hldst_immpost.VR = 0b1;
    insn.str_hldst_immpost._unnamed_0 = 0b111;
    insn.str_hldst_immpost.size = 0b01;
    return insn.raw;
}

uint32_t encode_str_s_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_sldst_immpost.Rt = Rt;
    insn.str_sldst_immpost.Rn = Rn;
    insn.str_sldst_immpost._unnamed_3 = 0b01;
    insn.str_sldst_immpost.imm9 = imm9;
    insn.str_sldst_immpost._unnamed_2 = 0b0;
    insn.str_sldst_immpost.opc = 0b00;
    insn.str_sldst_immpost._unnamed_1 = 0b00;
    insn.str_sldst_immpost.VR = 0b1;
    insn.str_sldst_immpost._unnamed_0 = 0b111;
    insn.str_sldst_immpost.size = 0b10;
    return insn.raw;
}

uint32_t encode_str_d_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_dldst_immpost.Rt = Rt;
    insn.str_dldst_immpost.Rn = Rn;
    insn.str_dldst_immpost._unnamed_3 = 0b01;
    insn.str_dldst_immpost.imm9 = imm9;
    insn.str_dldst_immpost._unnamed_2 = 0b0;
    insn.str_dldst_immpost.opc = 0b00;
    insn.str_dldst_immpost._unnamed_1 = 0b00;
    insn.str_dldst_immpost.VR = 0b1;
    insn.str_dldst_immpost._unnamed_0 = 0b111;
    insn.str_dldst_immpost.size = 0b11;
    return insn.raw;
}

uint32_t encode_str_q_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_qldst_immpost.Rt = Rt;
    insn.str_qldst_immpost.Rn = Rn;
    insn.str_qldst_immpost._unnamed_3 = 0b01;
    insn.str_qldst_immpost.imm9 = imm9;
    insn.str_qldst_immpost._unnamed_2 = 0b0;
    insn.str_qldst_immpost.opc = 0b10;
    insn.str_qldst_immpost._unnamed_1 = 0b00;
    insn.str_qldst_immpost.VR = 0b1;
    insn.str_qldst_immpost._unnamed_0 = 0b111;
    insn.str_qldst_immpost.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_b_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_bldst_immpre.Rt = Rt;
    insn.str_bldst_immpre.Rn = Rn;
    insn.str_bldst_immpre._unnamed_3 = 0b11;
    insn.str_bldst_immpre.imm9 = imm9;
    insn.str_bldst_immpre._unnamed_2 = 0b0;
    insn.str_bldst_immpre.opc = 0b00;
    insn.str_bldst_immpre._unnamed_1 = 0b00;
    insn.str_bldst_immpre.VR = 0b1;
    insn.str_bldst_immpre._unnamed_0 = 0b111;
    insn.str_bldst_immpre.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_h_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_hldst_immpre.Rt = Rt;
    insn.str_hldst_immpre.Rn = Rn;
    insn.str_hldst_immpre._unnamed_3 = 0b11;
    insn.str_hldst_immpre.imm9 = imm9;
    insn.str_hldst_immpre._unnamed_2 = 0b0;
    insn.str_hldst_immpre.opc = 0b00;
    insn.str_hldst_immpre._unnamed_1 = 0b00;
    insn.str_hldst_immpre.VR = 0b1;
    insn.str_hldst_immpre._unnamed_0 = 0b111;
    insn.str_hldst_immpre.size = 0b01;
    return insn.raw;
}

uint32_t encode_str_s_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_sldst_immpre.Rt = Rt;
    insn.str_sldst_immpre.Rn = Rn;
    insn.str_sldst_immpre._unnamed_3 = 0b11;
    insn.str_sldst_immpre.imm9 = imm9;
    insn.str_sldst_immpre._unnamed_2 = 0b0;
    insn.str_sldst_immpre.opc = 0b00;
    insn.str_sldst_immpre._unnamed_1 = 0b00;
    insn.str_sldst_immpre.VR = 0b1;
    insn.str_sldst_immpre._unnamed_0 = 0b111;
    insn.str_sldst_immpre.size = 0b10;
    return insn.raw;
}

uint32_t encode_str_d_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_dldst_immpre.Rt = Rt;
    insn.str_dldst_immpre.Rn = Rn;
    insn.str_dldst_immpre._unnamed_3 = 0b11;
    insn.str_dldst_immpre.imm9 = imm9;
    insn.str_dldst_immpre._unnamed_2 = 0b0;
    insn.str_dldst_immpre.opc = 0b00;
    insn.str_dldst_immpre._unnamed_1 = 0b00;
    insn.str_dldst_immpre.VR = 0b1;
    insn.str_dldst_immpre._unnamed_0 = 0b111;
    insn.str_dldst_immpre.size = 0b11;
    return insn.raw;
}

uint32_t encode_str_q_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.str_qldst_immpre.Rt = Rt;
    insn.str_qldst_immpre.Rn = Rn;
    insn.str_qldst_immpre._unnamed_3 = 0b11;
    insn.str_qldst_immpre.imm9 = imm9;
    insn.str_qldst_immpre._unnamed_2 = 0b0;
    insn.str_qldst_immpre.opc = 0b10;
    insn.str_qldst_immpre._unnamed_1 = 0b00;
    insn.str_qldst_immpre.VR = 0b1;
    insn.str_qldst_immpre._unnamed_0 = 0b111;
    insn.str_qldst_immpre.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_b_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.str_bldst_pos.Rt = Rt;
    insn.str_bldst_pos.Rn = Rn;
    insn.str_bldst_pos.imm12 = imm12;
    insn.str_bldst_pos.opc = 0b00;
    insn.str_bldst_pos._unnamed_1 = 0b01;
    insn.str_bldst_pos.VR = 0b1;
    insn.str_bldst_pos._unnamed_0 = 0b111;
    insn.str_bldst_pos.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_h_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.str_hldst_pos.Rt = Rt;
    insn.str_hldst_pos.Rn = Rn;
    insn.str_hldst_pos.imm12 = imm12;
    insn.str_hldst_pos.opc = 0b00;
    insn.str_hldst_pos._unnamed_1 = 0b01;
    insn.str_hldst_pos.VR = 0b1;
    insn.str_hldst_pos._unnamed_0 = 0b111;
    insn.str_hldst_pos.size = 0b01;
    return insn.raw;
}

uint32_t encode_str_s_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.str_sldst_pos.Rt = Rt;
    insn.str_sldst_pos.Rn = Rn;
    insn.str_sldst_pos.imm12 = imm12;
    insn.str_sldst_pos.opc = 0b00;
    insn.str_sldst_pos._unnamed_1 = 0b01;
    insn.str_sldst_pos.VR = 0b1;
    insn.str_sldst_pos._unnamed_0 = 0b111;
    insn.str_sldst_pos.size = 0b10;
    return insn.raw;
}

uint32_t encode_str_d_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.str_dldst_pos.Rt = Rt;
    insn.str_dldst_pos.Rn = Rn;
    insn.str_dldst_pos.imm12 = imm12;
    insn.str_dldst_pos.opc = 0b00;
    insn.str_dldst_pos._unnamed_1 = 0b01;
    insn.str_dldst_pos.VR = 0b1;
    insn.str_dldst_pos._unnamed_0 = 0b111;
    insn.str_dldst_pos.size = 0b11;
    return insn.raw;
}

uint32_t encode_str_q_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12) {
    FpsimdEncoding insn = {};
    insn.str_qldst_pos.Rt = Rt;
    insn.str_qldst_pos.Rn = Rn;
    insn.str_qldst_pos.imm12 = imm12;
    insn.str_qldst_pos.opc = 0b10;
    insn.str_qldst_pos._unnamed_1 = 0b01;
    insn.str_qldst_pos.VR = 0b1;
    insn.str_qldst_pos._unnamed_0 = 0b111;
    insn.str_qldst_pos.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_b_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_bldst_regoff.Rt = Rt;
    insn.str_bldst_regoff.Rn = Rn;
    insn.str_bldst_regoff._unnamed_3 = 0b10;
    insn.str_bldst_regoff.S = S;
    insn.str_bldst_regoff.option = option;
    insn.str_bldst_regoff.Rm = Rm;
    insn.str_bldst_regoff._unnamed_2 = 0b1;
    insn.str_bldst_regoff.opc = 0b00;
    insn.str_bldst_regoff._unnamed_1 = 0b00;
    insn.str_bldst_regoff.VR = 0b1;
    insn.str_bldst_regoff._unnamed_0 = 0b111;
    insn.str_bldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_bl_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_bl_ldst_regoff.Rt = Rt;
    insn.str_bl_ldst_regoff.Rn = Rn;
    insn.str_bl_ldst_regoff._unnamed_3 = 0b10;
    insn.str_bl_ldst_regoff.S = S;
    insn.str_bl_ldst_regoff.option = 0b011;
    insn.str_bl_ldst_regoff.Rm = Rm;
    insn.str_bl_ldst_regoff._unnamed_2 = 0b1;
    insn.str_bl_ldst_regoff.opc = 0b00;
    insn.str_bl_ldst_regoff._unnamed_1 = 0b00;
    insn.str_bl_ldst_regoff.VR = 0b1;
    insn.str_bl_ldst_regoff._unnamed_0 = 0b111;
    insn.str_bl_ldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_str_h_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_hldst_regoff.Rt = Rt;
    insn.str_hldst_regoff.Rn = Rn;
    insn.str_hldst_regoff._unnamed_3 = 0b10;
    insn.str_hldst_regoff.S = S;
    insn.str_hldst_regoff.option = option;
    insn.str_hldst_regoff.Rm = Rm;
    insn.str_hldst_regoff._unnamed_2 = 0b1;
    insn.str_hldst_regoff.opc = 0b00;
    insn.str_hldst_regoff._unnamed_1 = 0b00;
    insn.str_hldst_regoff.VR = 0b1;
    insn.str_hldst_regoff._unnamed_0 = 0b111;
    insn.str_hldst_regoff.size = 0b01;
    return insn.raw;
}

uint32_t encode_str_s_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_sldst_regoff.Rt = Rt;
    insn.str_sldst_regoff.Rn = Rn;
    insn.str_sldst_regoff._unnamed_3 = 0b10;
    insn.str_sldst_regoff.S = S;
    insn.str_sldst_regoff.option = option;
    insn.str_sldst_regoff.Rm = Rm;
    insn.str_sldst_regoff._unnamed_2 = 0b1;
    insn.str_sldst_regoff.opc = 0b00;
    insn.str_sldst_regoff._unnamed_1 = 0b00;
    insn.str_sldst_regoff.VR = 0b1;
    insn.str_sldst_regoff._unnamed_0 = 0b111;
    insn.str_sldst_regoff.size = 0b10;
    return insn.raw;
}

uint32_t encode_str_d_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_dldst_regoff.Rt = Rt;
    insn.str_dldst_regoff.Rn = Rn;
    insn.str_dldst_regoff._unnamed_3 = 0b10;
    insn.str_dldst_regoff.S = S;
    insn.str_dldst_regoff.option = option;
    insn.str_dldst_regoff.Rm = Rm;
    insn.str_dldst_regoff._unnamed_2 = 0b1;
    insn.str_dldst_regoff.opc = 0b00;
    insn.str_dldst_regoff._unnamed_1 = 0b00;
    insn.str_dldst_regoff.VR = 0b1;
    insn.str_dldst_regoff._unnamed_0 = 0b111;
    insn.str_dldst_regoff.size = 0b11;
    return insn.raw;
}

uint32_t encode_str_q_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm) {
    FpsimdEncoding insn = {};
    insn.str_qldst_regoff.Rt = Rt;
    insn.str_qldst_regoff.Rn = Rn;
    insn.str_qldst_regoff._unnamed_3 = 0b10;
    insn.str_qldst_regoff.S = S;
    insn.str_qldst_regoff.option = option;
    insn.str_qldst_regoff.Rm = Rm;
    insn.str_qldst_regoff._unnamed_2 = 0b1;
    insn.str_qldst_regoff.opc = 0b10;
    insn.str_qldst_regoff._unnamed_1 = 0b00;
    insn.str_qldst_regoff.VR = 0b1;
    insn.str_qldst_regoff._unnamed_0 = 0b111;
    insn.str_qldst_regoff.size = 0b00;
    return insn.raw;
}

uint32_t encode_sttnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.sttnp_qldstnapair_offs.Rt = Rt;
    insn.sttnp_qldstnapair_offs.Rn = Rn;
    insn.sttnp_qldstnapair_offs.Rt2 = Rt2;
    insn.sttnp_qldstnapair_offs.imm7 = imm7;
    insn.sttnp_qldstnapair_offs.L = 0b0;
    insn.sttnp_qldstnapair_offs._unnamed_3 = 0b00;
    insn.sttnp_qldstnapair_offs._unnamed_2 = 0b0;
    insn.sttnp_qldstnapair_offs.VR = 0b1;
    insn.sttnp_qldstnapair_offs._unnamed_1 = 0b1;
    insn.sttnp_qldstnapair_offs._unnamed_0 = 0b10;
    insn.sttnp_qldstnapair_offs.opc = 0b11;
    return insn.raw;
}

uint32_t encode_sttp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.sttp_qldstpair_post.Rt = Rt;
    insn.sttp_qldstpair_post.Rn = Rn;
    insn.sttp_qldstpair_post.Rt2 = Rt2;
    insn.sttp_qldstpair_post.imm7 = imm7;
    insn.sttp_qldstpair_post.L = 0b0;
    insn.sttp_qldstpair_post._unnamed_3 = 0b01;
    insn.sttp_qldstpair_post._unnamed_2 = 0b0;
    insn.sttp_qldstpair_post.VR = 0b1;
    insn.sttp_qldstpair_post._unnamed_1 = 0b1;
    insn.sttp_qldstpair_post._unnamed_0 = 0b10;
    insn.sttp_qldstpair_post.opc = 0b11;
    return insn.raw;
}

uint32_t encode_sttp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.sttp_qldstpair_pre.Rt = Rt;
    insn.sttp_qldstpair_pre.Rn = Rn;
    insn.sttp_qldstpair_pre.Rt2 = Rt2;
    insn.sttp_qldstpair_pre.imm7 = imm7;
    insn.sttp_qldstpair_pre.L = 0b0;
    insn.sttp_qldstpair_pre._unnamed_3 = 0b11;
    insn.sttp_qldstpair_pre._unnamed_2 = 0b0;
    insn.sttp_qldstpair_pre.VR = 0b1;
    insn.sttp_qldstpair_pre._unnamed_1 = 0b1;
    insn.sttp_qldstpair_pre._unnamed_0 = 0b10;
    insn.sttp_qldstpair_pre.opc = 0b11;
    return insn.raw;
}

uint32_t encode_sttp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7) {
    FpsimdEncoding insn = {};
    insn.sttp_qldstpair_off.Rt = Rt;
    insn.sttp_qldstpair_off.Rn = Rn;
    insn.sttp_qldstpair_off.Rt2 = Rt2;
    insn.sttp_qldstpair_off.imm7 = imm7;
    insn.sttp_qldstpair_off.L = 0b0;
    insn.sttp_qldstpair_off._unnamed_3 = 0b10;
    insn.sttp_qldstpair_off._unnamed_2 = 0b0;
    insn.sttp_qldstpair_off.VR = 0b1;
    insn.sttp_qldstpair_off._unnamed_1 = 0b1;
    insn.sttp_qldstpair_off._unnamed_0 = 0b10;
    insn.sttp_qldstpair_off.opc = 0b11;
    return insn.raw;
}

uint32_t encode_stur_b_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stur_bldst_unscaled.Rt = Rt;
    insn.stur_bldst_unscaled.Rn = Rn;
    insn.stur_bldst_unscaled._unnamed_3 = 0b00;
    insn.stur_bldst_unscaled.imm9 = imm9;
    insn.stur_bldst_unscaled._unnamed_2 = 0b0;
    insn.stur_bldst_unscaled.opc = 0b00;
    insn.stur_bldst_unscaled._unnamed_1 = 0b00;
    insn.stur_bldst_unscaled.VR = 0b1;
    insn.stur_bldst_unscaled._unnamed_0 = 0b111;
    insn.stur_bldst_unscaled.size = 0b00;
    return insn.raw;
}

uint32_t encode_stur_h_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stur_hldst_unscaled.Rt = Rt;
    insn.stur_hldst_unscaled.Rn = Rn;
    insn.stur_hldst_unscaled._unnamed_3 = 0b00;
    insn.stur_hldst_unscaled.imm9 = imm9;
    insn.stur_hldst_unscaled._unnamed_2 = 0b0;
    insn.stur_hldst_unscaled.opc = 0b00;
    insn.stur_hldst_unscaled._unnamed_1 = 0b00;
    insn.stur_hldst_unscaled.VR = 0b1;
    insn.stur_hldst_unscaled._unnamed_0 = 0b111;
    insn.stur_hldst_unscaled.size = 0b01;
    return insn.raw;
}

uint32_t encode_stur_s_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stur_sldst_unscaled.Rt = Rt;
    insn.stur_sldst_unscaled.Rn = Rn;
    insn.stur_sldst_unscaled._unnamed_3 = 0b00;
    insn.stur_sldst_unscaled.imm9 = imm9;
    insn.stur_sldst_unscaled._unnamed_2 = 0b0;
    insn.stur_sldst_unscaled.opc = 0b00;
    insn.stur_sldst_unscaled._unnamed_1 = 0b00;
    insn.stur_sldst_unscaled.VR = 0b1;
    insn.stur_sldst_unscaled._unnamed_0 = 0b111;
    insn.stur_sldst_unscaled.size = 0b10;
    return insn.raw;
}

uint32_t encode_stur_d_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stur_dldst_unscaled.Rt = Rt;
    insn.stur_dldst_unscaled.Rn = Rn;
    insn.stur_dldst_unscaled._unnamed_3 = 0b00;
    insn.stur_dldst_unscaled.imm9 = imm9;
    insn.stur_dldst_unscaled._unnamed_2 = 0b0;
    insn.stur_dldst_unscaled.opc = 0b00;
    insn.stur_dldst_unscaled._unnamed_1 = 0b00;
    insn.stur_dldst_unscaled.VR = 0b1;
    insn.stur_dldst_unscaled._unnamed_0 = 0b111;
    insn.stur_dldst_unscaled.size = 0b11;
    return insn.raw;
}

uint32_t encode_stur_q_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9) {
    FpsimdEncoding insn = {};
    insn.stur_qldst_unscaled.Rt = Rt;
    insn.stur_qldst_unscaled.Rn = Rn;
    insn.stur_qldst_unscaled._unnamed_3 = 0b00;
    insn.stur_qldst_unscaled.imm9 = imm9;
    insn.stur_qldst_unscaled._unnamed_2 = 0b0;
    insn.stur_qldst_unscaled.opc = 0b10;
    insn.stur_qldst_unscaled._unnamed_1 = 0b00;
    insn.stur_qldst_unscaled.VR = 0b1;
    insn.stur_qldst_unscaled._unnamed_0 = 0b111;
    insn.stur_qldst_unscaled.size = 0b00;
    return insn.raw;
}

// Decode function implementation
// Decode a fpsimd instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_fpsimd(uint32_t insn) {
    // Switch for mask 0xFFE0FC00u (2 patterns, 2 encodings)
    switch (insn & 0xFFE0FC00u) {
        case 0x3C206800u: { // STR_BL_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_bl_ldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_bl_ldst_regoff.Rn));
                        return result;
        }
        case 0x3C606800u: { // LDR_BL_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_bl_ldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_bl_ldst_regoff.Rn));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE01C00u (10 patterns, 10 encodings)
    switch (insn & 0xFFE01C00u) {
        case 0x3C200800u: { // STR_B_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_bldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_bldst_regoff.Rn));
                        return result;
        }
        case 0x3C600800u: { // LDR_B_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_bldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_bldst_regoff.Rn));
                        return result;
        }
        case 0x3CA00800u: { // STR_Q_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_qldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_qldst_regoff.Rn));
                        return result;
        }
        case 0x3CE00800u: { // LDR_Q_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_qldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_qldst_regoff.Rn));
                        return result;
        }
        case 0x7C200800u: { // STR_H_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_hldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_hldst_regoff.Rn));
                        return result;
        }
        case 0x7C600800u: { // LDR_H_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_hldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_hldst_regoff.Rn));
                        return result;
        }
        case 0xBC201800u: { // STR_S_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_sldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_sldst_regoff.Rn));
                        return result;
        }
        case 0xBC601800u: { // LDR_S_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_sldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_sldst_regoff.Rn));
                        return result;
        }
        case 0xFC200800u: { // STR_D_ldst_regoff
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_dldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.str_dldst_regoff.Rn));
                        return result;
        }
        case 0xFC600800u: { // LDR_D_ldst_regoff
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_dldst_regoff.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_base(enc.ldr_dldst_regoff.Rn));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE00C00u (40 patterns, 40 encodings)
    switch (insn & 0xFFE00C00u) {
        case 0x1D000800u: { // STLUR_B_ldapstl_simd
                        Instruction result(Mnemonic::STLUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_bldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_bldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.stlur_bldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x1D400800u: { // LDAPUR_B_ldapstl_simd
                        Instruction result(Mnemonic::LDAPUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_bldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_bldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldapur_bldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x1D800800u: { // STLUR_Q_ldapstl_simd
                        Instruction result(Mnemonic::STLUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_qldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_qldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.stlur_qldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x1DC00800u: { // LDAPUR_Q_ldapstl_simd
                        Instruction result(Mnemonic::LDAPUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_qldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_qldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldapur_qldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x3C000000u: { // STUR_B_ldst_unscaled
                        Instruction result(Mnemonic::STUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stur_bldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.stur_bldst_unscaled.Rn, enc.stur_bldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x3C000400u: { // STR_B_ldst_immpost
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_bldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_bldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.str_bldst_immpost.Rn, imm));
                        return result;
        }
        case 0x3C000C00u: { // STR_B_ldst_immpre
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_bldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_bldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.str_bldst_immpre.Rn, imm));
                        return result;
        }
        case 0x3C400000u: { // LDUR_B_ldst_unscaled
                        Instruction result(Mnemonic::LDUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldur_bldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldur_bldst_unscaled.Rn, enc.ldur_bldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x3C400400u: { // LDR_B_ldst_immpost
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_bldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_bldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.ldr_bldst_immpost.Rn, imm));
                        return result;
        }
        case 0x3C400C00u: { // LDR_B_ldst_immpre
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_bldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_bldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldr_bldst_immpre.Rn, imm));
                        return result;
        }
        case 0x3C800000u: { // STUR_Q_ldst_unscaled
                        Instruction result(Mnemonic::STUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stur_qldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.stur_qldst_unscaled.Rn, enc.stur_qldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x3C800400u: { // STR_Q_ldst_immpost
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_qldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_qldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.str_qldst_immpost.Rn, imm));
                        return result;
        }
        case 0x3C800C00u: { // STR_Q_ldst_immpre
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_qldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_qldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.str_qldst_immpre.Rn, imm));
                        return result;
        }
        case 0x3CC00000u: { // LDUR_Q_ldst_unscaled
                        Instruction result(Mnemonic::LDUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldur_qldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldur_qldst_unscaled.Rn, enc.ldur_qldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x3CC00400u: { // LDR_Q_ldst_immpost
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_qldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_qldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.ldr_qldst_immpost.Rn, imm));
                        return result;
        }
        case 0x3CC00C00u: { // LDR_Q_ldst_immpre
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_qldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_qldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldr_qldst_immpre.Rn, imm));
                        return result;
        }
        case 0x5D000800u: { // STLUR_H_ldapstl_simd
                        Instruction result(Mnemonic::STLUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_hldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_hldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.stlur_hldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x5D400800u: { // LDAPUR_H_ldapstl_simd
                        Instruction result(Mnemonic::LDAPUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_hldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_hldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldapur_hldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x7C000000u: { // STUR_H_ldst_unscaled
                        Instruction result(Mnemonic::STUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stur_hldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.stur_hldst_unscaled.Rn, enc.stur_hldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x7C000400u: { // STR_H_ldst_immpost
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_hldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_hldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.str_hldst_immpost.Rn, imm));
                        return result;
        }
        case 0x7C000C00u: { // STR_H_ldst_immpre
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_hldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_hldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.str_hldst_immpre.Rn, imm));
                        return result;
        }
        case 0x7C400000u: { // LDUR_H_ldst_unscaled
                        Instruction result(Mnemonic::LDUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldur_hldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldur_hldst_unscaled.Rn, enc.ldur_hldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0x7C400400u: { // LDR_H_ldst_immpost
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_hldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_hldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.ldr_hldst_immpost.Rn, imm));
                        return result;
        }
        case 0x7C400C00u: { // LDR_H_ldst_immpre
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_hldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_hldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldr_hldst_immpre.Rn, imm));
                        return result;
        }
        case 0x9D000800u: { // STLUR_S_ldapstl_simd
                        Instruction result(Mnemonic::STLUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_sldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_sldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.stlur_sldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x9D400800u: { // LDAPUR_S_ldapstl_simd
                        Instruction result(Mnemonic::LDAPUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_sldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_sldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldapur_sldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xBC000000u: { // STUR_S_ldst_unscaled
                        Instruction result(Mnemonic::STUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stur_sldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.stur_sldst_unscaled.Rn, enc.stur_sldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0xBC000400u: { // STR_S_ldst_immpost
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_sldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_sldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.str_sldst_immpost.Rn, imm));
                        return result;
        }
        case 0xBC000C00u: { // STR_S_ldst_immpre
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_sldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_sldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.str_sldst_immpre.Rn, imm));
                        return result;
        }
        case 0xBC400000u: { // LDUR_S_ldst_unscaled
                        Instruction result(Mnemonic::LDUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldur_sldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldur_sldst_unscaled.Rn, enc.ldur_sldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0xBC400400u: { // LDR_S_ldst_immpost
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_sldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_sldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.ldr_sldst_immpost.Rn, imm));
                        return result;
        }
        case 0xBC400C00u: { // LDR_S_ldst_immpre
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_sldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_sldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldr_sldst_immpre.Rn, imm));
                        return result;
        }
        case 0xDD000800u: { // STLUR_D_ldapstl_simd
                        Instruction result(Mnemonic::STLUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_dldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stlur_dldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.stlur_dldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xDD400800u: { // LDAPUR_D_ldapstl_simd
                        Instruction result(Mnemonic::LDAPUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_dldapstl_simd.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldapur_dldapstl_simd.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.ldapur_dldapstl_simd.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xFC000000u: { // STUR_D_ldst_unscaled
                        Instruction result(Mnemonic::STUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stur_dldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.stur_dldst_unscaled.Rn, enc.stur_dldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0xFC000400u: { // STR_D_ldst_immpost
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_dldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_dldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.str_dldst_immpost.Rn, imm));
                        return result;
        }
        case 0xFC000C00u: { // STR_D_ldst_immpre
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_dldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.str_dldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.str_dldst_immpre.Rn, imm));
                        return result;
        }
        case 0xFC400000u: { // LDUR_D_ldst_unscaled
                        Instruction result(Mnemonic::LDUR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldur_dldst_unscaled.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldur_dldst_unscaled.Rn, enc.ldur_dldst_unscaled.imm9 * scale));
                        return result;
        }
        case 0xFC400400u: { // LDR_D_ldst_immpost
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_dldst_immpost.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_dldst_immpost.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_post_index(enc.ldr_dldst_immpost.Rn, imm));
                        return result;
        }
        case 0xFC400C00u: { // LDR_D_ldst_immpre
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_dldst_immpre.Rt, is_64bit));
                        int32_t imm = (static_cast<int32_t>(enc.ldr_dldst_immpre.imm9) << 23) >> 23;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldr_dldst_immpre.Rn, imm));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFC00000u (42 patterns, 42 encodings)
    switch (insn & 0xFFC00000u) {
        case 0x2C000000u: { // STNP_S_ldstnapair_offs
                        Instruction result(Mnemonic::STNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_sldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_sldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_sldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.stnp_sldstnapair_offs.imm7, true));
                        return result;
        }
        case 0x2C400000u: { // LDNP_S_ldstnapair_offs
                        Instruction result(Mnemonic::LDNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_sldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_sldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_sldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ldnp_sldstnapair_offs.imm7, true));
                        return result;
        }
        case 0x2C800000u: { // STP_S_ldstpair_post
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_post.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_post.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.stp_sldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.stp_sldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0x2CC00000u: { // LDP_S_ldstpair_post
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_post.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_post.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_sldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.ldp_sldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0x2D000000u: { // STP_S_ldstpair_off
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_off.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_off.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.stp_sldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.stp_sldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0x2D400000u: { // LDP_S_ldstpair_off
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_off.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_off.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_sldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.ldp_sldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0x2D800000u: { // STP_S_ldstpair_pre
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_pre.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_sldstpair_pre.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.stp_sldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.stp_sldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0x2DC00000u: { // LDP_S_ldstpair_pre
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_pre.Rt, false));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_sldstpair_pre.Rt2, false));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_sldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldp_sldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0x3D000000u: { // STR_B_ldst_pos
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_bldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.str_bldst_pos.Rn, enc.str_bldst_pos.imm12 * scale));
                        return result;
        }
        case 0x3D400000u: { // LDR_B_ldst_pos
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_bldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldr_bldst_pos.Rn, enc.ldr_bldst_pos.imm12 * scale));
                        return result;
        }
        case 0x3D800000u: { // STR_Q_ldst_pos
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_qldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.str_qldst_pos.Rn, enc.str_qldst_pos.imm12 * scale));
                        return result;
        }
        case 0x3DC00000u: { // LDR_Q_ldst_pos
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_qldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldr_qldst_pos.Rn, enc.ldr_qldst_pos.imm12 * scale));
                        return result;
        }
        case 0x6C000000u: { // STNP_D_ldstnapair_offs
                        Instruction result(Mnemonic::STNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_dldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_dldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_dldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.stnp_dldstnapair_offs.imm7, true));
                        return result;
        }
        case 0x6C400000u: { // LDNP_D_ldstnapair_offs
                        Instruction result(Mnemonic::LDNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_dldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_dldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_dldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ldnp_dldstnapair_offs.imm7, true));
                        return result;
        }
        case 0x6C800000u: { // STP_D_ldstpair_post
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_dldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.stp_dldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0x6CC00000u: { // LDP_D_ldstpair_post
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_dldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.ldp_dldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0x6D000000u: { // STP_D_ldstpair_off
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_dldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.stp_dldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0x6D400000u: { // LDP_D_ldstpair_off
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_dldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.ldp_dldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0x6D800000u: { // STP_D_ldstpair_pre
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.stp_dldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_dldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.stp_dldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0x6DC00000u: { // LDP_D_ldstpair_pre
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 8;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldp_dldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_dldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldp_dldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0x7D000000u: { // STR_H_ldst_pos
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_hldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.str_hldst_pos.Rn, enc.str_hldst_pos.imm12 * scale));
                        return result;
        }
        case 0x7D400000u: { // LDR_H_ldst_pos
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_hldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldr_hldst_pos.Rn, enc.ldr_hldst_pos.imm12 * scale));
                        return result;
        }
        case 0xAC000000u: { // STNP_Q_ldstnapair_offs
                        Instruction result(Mnemonic::STNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_qldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_qldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.stnp_qldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.stnp_qldstnapair_offs.imm7, true));
                        return result;
        }
        case 0xAC400000u: { // LDNP_Q_ldstnapair_offs
                        Instruction result(Mnemonic::LDNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_qldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_qldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldnp_qldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ldnp_qldstnapair_offs.imm7, true));
                        return result;
        }
        case 0xAC800000u: { // STP_Q_ldstpair_post
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_qldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.stp_qldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0xACC00000u: { // LDP_Q_ldstpair_post
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_qldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.ldp_qldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0xAD000000u: { // STP_Q_ldstpair_off
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_qldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.stp_qldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0xAD400000u: { // LDP_Q_ldstpair_off
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_qldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.ldp_qldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0xAD800000u: { // STP_Q_ldstpair_pre
                        Instruction result(Mnemonic::STP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.stp_qldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.stp_qldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.stp_qldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0xADC00000u: { // LDP_Q_ldstpair_pre
                        Instruction result(Mnemonic::LDP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldp_qldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldp_qldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldp_qldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0xBD000000u: { // STR_S_ldst_pos
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_sldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.str_sldst_pos.Rn, enc.str_sldst_pos.imm12 * scale));
                        return result;
        }
        case 0xBD400000u: { // LDR_S_ldst_pos
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_sldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldr_sldst_pos.Rn, enc.ldr_sldst_pos.imm12 * scale));
                        return result;
        }
        case 0xEC000000u: { // STTNP_Q_ldstnapair_offs
                        Instruction result(Mnemonic::STTNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sttnp_qldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sttnp_qldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.sttnp_qldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.sttnp_qldstnapair_offs.imm7, true));
                        return result;
        }
        case 0xEC400000u: { // LDTNP_Q_ldstnapair_offs
                        Instruction result(Mnemonic::LDTNP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldtnp_qldstnapair_offs.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldtnp_qldstnapair_offs.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.ldtnp_qldstnapair_offs.Rt2, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.ldtnp_qldstnapair_offs.imm7, true));
                        return result;
        }
        case 0xEC800000u: { // STTP_Q_ldstpair_post
                        Instruction result(Mnemonic::STTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.sttp_qldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.sttp_qldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0xECC00000u: { // LDTP_Q_ldstpair_post
                        Instruction result(Mnemonic::LDTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_post.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_post.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldtp_qldstpair_post.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_post_index(enc.ldtp_qldstpair_post.Rn, imm * scale));
                        return result;
        }
        case 0xED000000u: { // STTP_Q_ldstpair_off
                        Instruction result(Mnemonic::STTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.sttp_qldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.sttp_qldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0xED400000u: { // LDTP_Q_ldstpair_off
                        Instruction result(Mnemonic::LDTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_off.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_off.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldtp_qldstpair_off.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_offset(enc.ldtp_qldstpair_off.Rn, imm * scale));
                        return result;
        }
        case 0xED800000u: { // STTP_Q_ldstpair_pre
                        Instruction result(Mnemonic::STTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.sttp_qldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.sttp_qldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.sttp_qldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0xEDC00000u: { // LDTP_Q_ldstpair_pre
                        Instruction result(Mnemonic::LDTP, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        int scale = 16;
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_pre.Rt, true));
                        result.operands.push_back(Operand(OperandType::VectorRegister, enc.ldtp_qldstpair_pre.Rt2, true));
                        int32_t imm = (static_cast<int32_t>(enc.ldtp_qldstpair_pre.imm7) << 25) >> 25;
                        result.operands.push_back(Operand::memory_pre_index(enc.ldtp_qldstpair_pre.Rn, imm * scale));
                        return result;
        }
        case 0xFD000000u: { // STR_D_ldst_pos
                        Instruction result(Mnemonic::STR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.str_dldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.str_dldst_pos.Rn, enc.str_dldst_pos.imm12 * scale));
                        return result;
        }
        case 0xFD400000u: { // LDR_D_ldst_pos
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        int scale = 4;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_dldst_pos.Rt, is_64bit));
                        result.operands.push_back(Operand::memory_offset(enc.ldr_dldst_pos.Rn, enc.ldr_dldst_pos.imm12 * scale));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF000000u (3 patterns, 3 encodings)
    switch (insn & 0xFF000000u) {
        case 0x1C000000u: { // LDR_S_loadlit
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_sloadlit.Rt, is_64bit));
                        return result;
        }
        case 0x5C000000u: { // LDR_D_loadlit
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_dloadlit.Rt, is_64bit));
                        return result;
        }
        case 0x9C000000u: { // LDR_Q_loadlit
                        Instruction result(Mnemonic::LDR, insn);
                        FpsimdEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.ldr_qloadlit.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace Fpsimd
} // namespace veda64
