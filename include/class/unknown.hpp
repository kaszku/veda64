#pragma once

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace Unknown {

// Encode functions
uint32_t encode_autia_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autiza_64z_dp_1src(uint32_t Rd);
uint32_t encode_autia1716_hi_hints();
uint32_t encode_autiasp_hi_hints();
uint32_t encode_autiaz_hi_hints();
uint32_t encode_autib_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autizb_64z_dp_1src(uint32_t Rd);
uint32_t encode_autib1716_hi_hints();
uint32_t encode_autibsp_hi_hints();
uint32_t encode_autibz_hi_hints();
uint32_t encode_fmopa_za_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmopa_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmopa_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmops_za_pp_zz_16(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmops_za_pp_zz_32(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_fmops_za_pp_zz_64(uint32_t ZAda, uint32_t Zn, uint32_t Pn, uint32_t Pm, uint32_t Zm);
uint32_t encode_ld1d_z_p_bi_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_ld1d_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_ld1d_z_p_br_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_ld1d_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_ld1w_z_p_bi_u32(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_ld1w_z_p_bi_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_ld1w_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_ld1w_z_p_br_u32(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_ld1w_z_p_br_u64(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_ld1w_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_ldraa_64_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S);
uint32_t encode_ldraa_64w_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S);
uint32_t encode_ldrab_64_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S);
uint32_t encode_ldrab_64w_ldst_pac(uint32_t Rt, uint32_t Rn, int32_t imm9, uint32_t S);
uint32_t encode_pacia_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_paciza_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacia1716_hi_hints();
uint32_t encode_paciasp_hi_hints();
uint32_t encode_paciaz_hi_hints();
uint32_t encode_pacib_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_pacizb_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacib1716_hi_hints();
uint32_t encode_pacibsp_hi_hints();
uint32_t encode_pacibz_hi_hints();
uint32_t encode_st1d_z_p_bi_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_st1d_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_st1d_z_p_br_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_st1d_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_st1w_z_p_bi_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4, uint32_t sz);
uint32_t encode_st1w_z_p_bi_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t imm4);
uint32_t encode_st1w_z_p_br_(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm, uint32_t sz);
uint32_t encode_st1w_z_p_br_u128(uint32_t Zt, uint32_t Rn, uint32_t Pg, uint32_t Rm);
uint32_t encode_tbl_z_zz_1(uint32_t Zd, uint32_t Zn, uint32_t Zm, uint32_t size);
uint32_t encode_tbl_z_zz_2(uint32_t Zd, uint32_t Zn, uint32_t Zm, uint32_t size);
uint32_t encode_xpacd_64z_dp_1src(uint32_t Rd);
uint32_t encode_xpaci_64z_dp_1src(uint32_t Rd);
uint32_t encode_xpaclri_hi_hints();

// Decode function
// Decode a unknown instruction
std::optional<Instruction> decode_unknown(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_unknown(const uint8_t* bytes) {
    return decode_unknown(from_bytes(bytes));
}

} // namespace Unknown
} // namespace veda64
