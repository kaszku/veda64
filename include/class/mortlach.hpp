#pragma once

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace Mortlach {

// Encode functions
uint32_t encode_addha_za_pp_z_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm);
uint32_t encode_addha_za_pp_z_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm);
uint32_t encode_addspl_r_ri_(uint32_t Rd, uint32_t imm6, uint32_t Rn);
uint32_t encode_addsvl_r_ri_(uint32_t Rd, uint32_t imm6, uint32_t Rn);
uint32_t encode_addva_za_pp_z_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm);
uint32_t encode_addva_za_pp_z_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm);
uint32_t encode_bfmopa_za32_pp_zz_(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_bfmops_za32_pp_zz_(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmopa_za32_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmops_za32_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_ld1b_za_p_rrr_(uint32_t off4, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_ld1d_za_p_rrr_(uint32_t o1, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_ld1h_za_p_rrr_(uint32_t off3, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_ld1q_za_p_rrr_(uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_ld1w_za_p_rrr_(uint32_t off2, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_ldr_za_ri_(uint32_t off4, uint32_t Rn, uint32_t Rv);
uint32_t encode_mov_z_p_rza_b_mova_z_p_rza_b(uint32_t Zd, uint32_t off4, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_z_p_rza_h_mova_z_p_rza_h(uint32_t Zd, uint32_t off3, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_z_p_rza_w_mova_z_p_rza_w(uint32_t Zd, uint32_t off2, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_z_p_rza_d_mova_z_p_rza_d(uint32_t Zd, uint32_t o1, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_z_p_rza_q_mova_z_p_rza_q(uint32_t Zd, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_za_p_rz_b_mova_za_p_rz_b(uint32_t off4, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_za_p_rz_h_mova_za_p_rz_h(uint32_t off3, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_za_p_rz_w_mova_za_p_rz_w(uint32_t off2, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_za_p_rz_d_mova_za_p_rz_d(uint32_t o1, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mov_za_p_rz_q_mova_za_p_rz_q(uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_z_p_rza_b(uint32_t Zd, uint32_t off4, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_z_p_rza_h(uint32_t Zd, uint32_t off3, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_z_p_rza_w(uint32_t Zd, uint32_t off2, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_z_p_rza_d(uint32_t Zd, uint32_t o1, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_z_p_rza_q(uint32_t Zd, uint32_t ZAn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_za_p_rz_b(uint32_t off4, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_za_p_rz_h(uint32_t off3, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_za_p_rz_w(uint32_t off2, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_za_p_rz_d(uint32_t o1, uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_mova_za_p_rz_q(uint32_t ZAd, uint32_t Zn, uint32_t Pg, uint32_t Rs, uint32_t V);
uint32_t encode_rdsvl_r_i_(uint32_t Rd, uint32_t imm6);
uint32_t encode_smopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_smopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_smops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_smops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_st1b_za_p_rrr_(uint32_t off4, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_st1d_za_p_rrr_(uint32_t o1, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_st1h_za_p_rrr_(uint32_t off3, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_st1q_za_p_rrr_(uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_st1w_za_p_rrr_(uint32_t off2, uint32_t ZAt, uint32_t Rn, uint32_t Pg, uint32_t Rs, uint32_t V, uint32_t Rm);
uint32_t encode_str_za_ri_(uint32_t off4, uint32_t Rn, uint32_t Rv);
uint32_t encode_sumopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_sumopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_sumops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_sumops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_umopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_umopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_umops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_umops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_usmopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_usmopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_usmops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_usmops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_zero_za_i_(uint32_t imm8);

// Decode function
// Decode a mortlach instruction
std::optional<Instruction> decode_mortlach(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_mortlach(const uint8_t* bytes) {
    return decode_mortlach(from_bytes(bytes));
}

} // namespace Mortlach
} // namespace veda64
