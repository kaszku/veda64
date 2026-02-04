#pragma once

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace Fpsimd {

// Encode functions
uint32_t encode_ldapur_b_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldapur_h_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldapur_s_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldapur_d_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldapur_q_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldnp_s_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldnp_d_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_s_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_d_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_s_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_d_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_s_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_d_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldr_b_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_h_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_s_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_d_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_q_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_b_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_h_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_s_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_d_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_q_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldr_b_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_ldr_h_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_ldr_s_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_ldr_d_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_ldr_q_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_ldr_s_loadlit(uint32_t Rt, int32_t imm19);
uint32_t encode_ldr_d_loadlit(uint32_t Rt, int32_t imm19);
uint32_t encode_ldr_q_loadlit(uint32_t Rt, int32_t imm19);
uint32_t encode_ldr_b_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_ldr_bl_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t Rm);
uint32_t encode_ldr_h_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_ldr_s_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_ldr_d_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_ldr_q_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_ldtnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldtp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldtp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldtp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_ldur_b_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldur_h_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldur_s_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldur_d_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_ldur_q_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stlur_b_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stlur_h_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stlur_s_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stlur_d_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stlur_q_ldapstl_simd(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stnp_s_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stnp_d_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_s_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_d_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_s_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_d_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_s_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_d_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_str_b_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_h_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_s_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_d_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_q_ldst_immpost(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_b_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_h_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_s_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_d_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_q_ldst_immpre(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_str_b_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_str_h_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_str_s_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_str_d_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_str_q_ldst_pos(uint32_t Rt, uint32_t Rn, uint32_t imm12);
uint32_t encode_str_b_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_str_bl_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t Rm);
uint32_t encode_str_h_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_str_s_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_str_d_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_str_q_ldst_regoff(uint32_t Rt, uint32_t Rn, uint32_t S, uint32_t option, uint32_t Rm);
uint32_t encode_sttnp_q_ldstnapair_offs(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_sttp_q_ldstpair_post(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_sttp_q_ldstpair_pre(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_sttp_q_ldstpair_off(uint32_t Rt, uint32_t Rn, uint32_t Rt2, uint32_t imm7);
uint32_t encode_stur_b_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stur_h_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stur_s_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stur_d_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);
uint32_t encode_stur_q_ldst_unscaled(uint32_t Rt, uint32_t Rn, int32_t imm9);

// Decode function
// Decode a fpsimd instruction
std::optional<Instruction> decode_fpsimd(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_fpsimd(const uint8_t* bytes) {
    return decode_fpsimd(from_bytes(bytes));
}

} // namespace Fpsimd
} // namespace veda64
