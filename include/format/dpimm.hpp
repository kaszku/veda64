#pragma once
// ARM64 Decode Group: Data Processing -- Immediate
// 87 instruction encodings

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace Format {
namespace Dpimm {

// Encode functions
uint32_t encode_add_32_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_add_64_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_addg_64_addsub_immtags(uint32_t Rd, uint32_t Rn, uint32_t imm4, uint32_t op3, uint32_t imm6);
uint32_t encode_adds_32s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_adds_64s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_adr_only_pcreladdr(uint32_t Rd, int32_t immhi, int32_t immlo);
uint32_t encode_adrp_only_pcreladdr(uint32_t Rd, int32_t immhi, int32_t immlo);
uint32_t encode_and_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_and_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_ands_32s_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ands_64s_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_asr_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr);
uint32_t encode_asr_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr);
uint32_t encode_autiasppc_only_dp_1src_imm(uint32_t imm16);
uint32_t encode_autibsppc_only_dp_1src_imm(uint32_t imm16);
uint32_t encode_bfc_bfm_32m_bitfield(uint32_t Rd, uint32_t imms, uint32_t immr);
uint32_t encode_bfc_bfm_64m_bitfield(uint32_t Rd, uint32_t imms, uint32_t immr);
uint32_t encode_bfi_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_bfi_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_bfxil_bfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_bfxil_bfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_cmn_adds_32s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_cmn_adds_64s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_cmp_subs_32s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_cmp_subs_64s_addsub_imm(uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_eor_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_eor_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_extr_32_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm);
uint32_t encode_extr_64_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm);
uint32_t encode_lsl_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_lsl_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_lsr_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr);
uint32_t encode_lsr_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t immr);
uint32_t encode_mov_add_32_addsub_imm(uint32_t Rd, uint32_t Rn);
uint32_t encode_mov_add_64_addsub_imm(uint32_t Rd, uint32_t Rn);
uint32_t encode_mov_movn_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_mov_movn_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_mov_movz_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_mov_movz_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_mov_orr_32_log_imm(uint32_t Rd, uint32_t imms, uint32_t immr);
uint32_t encode_mov_orr_64_log_imm(uint32_t Rd, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_movk_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_movk_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_movn_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_movn_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_movz_32_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_movz_64_movewide(uint32_t Rd, uint32_t imm16, uint32_t hw);
uint32_t encode_orr_32_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_orr_64_log_imm(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_ror_extr_32_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm);
uint32_t encode_ror_extr_64_extract(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t Rm);
uint32_t encode_sbfiz_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_sbfiz_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_sbfx_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_sbfx_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_smax_32_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_smax_64_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_smin_32_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_smin_64_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_sub_32_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_sub_64_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_subg_64_addsub_immtags(uint32_t Rd, uint32_t Rn, uint32_t imm4, uint32_t op3, uint32_t imm6);
uint32_t encode_subs_32s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_subs_64s_addsub_imm(uint32_t Rd, uint32_t Rn, uint32_t imm12, uint32_t sh);
uint32_t encode_sxtb_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_sxtb_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_sxth_sbfm_32m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_sxth_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_sxtw_sbfm_64m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_tst_ands_32s_log_imm(uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_tst_ands_64s_log_imm(uint32_t Rn, uint32_t imms, uint32_t immr, uint32_t N);
uint32_t encode_ubfiz_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ubfiz_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ubfx_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_ubfx_ubfm_64m_bitfield(uint32_t Rd, uint32_t Rn, uint32_t imms, uint32_t immr);
uint32_t encode_umax_32u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_umax_64u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_umin_32u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_umin_64u_minmax_imm(uint32_t Rd, uint32_t Rn, uint32_t imm8);
uint32_t encode_uxtb_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn);
uint32_t encode_uxth_ubfm_32m_bitfield(uint32_t Rd, uint32_t Rn);

// Decode function
// Decode a dpimm instruction
std::optional<Instruction> decode_dpimm(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_dpimm(const uint8_t* bytes) {
    return decode_dpimm(from_bytes(bytes));
}

} // namespace Dpimm
} // namespace Format
} // namespace veda64
