// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Kevin Szkudlapski
// Auto-generated — do not edit

#pragma once
// ARM64 Decode Group: Branches, Exception Generating and System
// 178 instruction encodings

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace format {
namespace control {

// Encode functions
uint32_t encode_apas_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_at_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_autia1716_hi_hints();
uint32_t encode_autiasp_hi_hints();
uint32_t encode_autiaz_hi_hints();
uint32_t encode_autib1716_hi_hints();
uint32_t encode_autibsp_hi_hints();
uint32_t encode_autibz_hi_hints();
uint32_t encode_axflag_m_pstate();
uint32_t encode_b_only_condbranch(uint32_t cond, int32_t imm19);
uint32_t encode_b_only_branch_imm(int32_t imm26);
uint32_t encode_bc_only_condbranch(uint32_t cond, int32_t imm19);
uint32_t encode_bl_only_branch_imm(int32_t imm26);
uint32_t encode_blr_64_branch_reg(uint32_t Rn);
uint32_t encode_blraa_64p_branch_reg(uint32_t Rm, uint32_t Rn);
uint32_t encode_blraaz_64_branch_reg(uint32_t Rn);
uint32_t encode_blrab_64p_branch_reg(uint32_t Rm, uint32_t Rn);
uint32_t encode_blrabz_64_branch_reg(uint32_t Rn);
uint32_t encode_br_64_branch_reg(uint32_t Rn);
uint32_t encode_braa_64p_branch_reg(uint32_t Rm, uint32_t Rn);
uint32_t encode_braaz_64_branch_reg(uint32_t Rn);
uint32_t encode_brab_64p_branch_reg(uint32_t Rm, uint32_t Rn);
uint32_t encode_brabz_64_branch_reg(uint32_t Rn);
uint32_t encode_brb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2);
uint32_t encode_brk_ex_exception(uint32_t imm16);
uint32_t encode_bti_hb_hints(uint32_t op2);
uint32_t encode_cbbgt_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbge_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbhi_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbhs_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbeq_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbne_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbble_cbbge_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbblo_cbbhi_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbbls_cbbhs_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbblt_cbbgt_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbgt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cblt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbhi_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cblo_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbeq_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbne_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbgt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cblt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbhi_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cblo_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbeq_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbne_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbgt_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbge_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhi_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhs_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbeq_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbne_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbgt_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbge_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhi_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhs_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbeq_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbne_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbge_cbgt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbge_cbgt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbhgt_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhge_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhhi_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhhs_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbheq_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhne_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhle_cbhge_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhlo_cbhhi_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhls_cbhhs_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhlt_cbhgt_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbhs_cbhi_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbhs_cbhi_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cble_cblt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cble_cblt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cble_cbge_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cble_cbge_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cblo_cbhi_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cblo_cbhi_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbls_cblo_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbls_cblo_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6);
uint32_t encode_cbls_cbhs_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbls_cbhs_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cblt_cbgt_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cblt_cbgt_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm);
uint32_t encode_cbnz_32_compbranch(uint32_t Rt, int32_t imm19);
uint32_t encode_cbnz_64_compbranch(uint32_t Rt, int32_t imm19);
uint32_t encode_cbz_32_compbranch(uint32_t Rt, int32_t imm19);
uint32_t encode_cbz_64_compbranch(uint32_t Rt, int32_t imm19);
uint32_t encode_cfinv_m_pstate();
uint32_t encode_cfp_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_chkfeat_hf_hints();
uint32_t encode_clrbhb_hi_hints();
uint32_t encode_clrex_bn_barriers(uint32_t CRm);
uint32_t encode_cosp_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_cpp_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_csdb_hi_hints();
uint32_t encode_dc_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_dcps1_dc_exception(uint32_t imm16);
uint32_t encode_dcps2_dc_exception(uint32_t imm16);
uint32_t encode_dcps3_dc_exception(uint32_t imm16);
uint32_t encode_dgh_hi_hints();
uint32_t encode_dmb_bo_barriers(uint32_t CRm);
uint32_t encode_drps_64e_branch_reg();
uint32_t encode_dsb_bo_barriers(uint32_t CRm);
uint32_t encode_dsb_bon_barriers(uint32_t imm2);
uint32_t encode_dvp_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_eret_64e_branch_reg();
uint32_t encode_eretaa_64e_branch_reg();
uint32_t encode_eretab_64e_branch_reg();
uint32_t encode_esb_hi_hints();
uint32_t encode_gcsb_hd_hints();
uint32_t encode_gcspopcx_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_gcspopm_sysl_rc_systeminstrs(uint32_t Rt);
uint32_t encode_gcspopx_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_gcspushm_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_gcspushx_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_gcsss1_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_gcsss2_sysl_rc_systeminstrs(uint32_t Rt);
uint32_t encode_gic_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_gicr_sysl_rc_systeminstrs(uint32_t Rt, uint32_t op2);
uint32_t encode_gsb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2);
uint32_t encode_hint_hm_hints(uint32_t op2, uint32_t CRm);
uint32_t encode_hlt_ex_exception(uint32_t imm16);
uint32_t encode_hvc_ex_exception(uint32_t imm16);
uint32_t encode_ic_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_isb_bi_barriers(uint32_t CRm);
uint32_t encode_mlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2);
uint32_t encode_mrrs_rs_systemmovepr(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0);
uint32_t encode_mrs_rs_systemmove(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0);
uint32_t encode_msr_si_pstate(uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_msr_sr_systemmove(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0);
uint32_t encode_msrr_sr_systemmovepr(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0);
uint32_t encode_nop_hi_hints();
uint32_t encode_pacia1716_hi_hints();
uint32_t encode_paciasp_hi_hints();
uint32_t encode_paciaz_hi_hints();
uint32_t encode_pacib1716_hi_hints();
uint32_t encode_pacibsp_hi_hints();
uint32_t encode_pacibz_hi_hints();
uint32_t encode_pacm_hi_hints();
uint32_t encode_psb_hc_hints();
uint32_t encode_pssbb_dsb_bo_barriers();
uint32_t encode_ret_64r_branch_reg(uint32_t Rn);
uint32_t encode_retaa_64e_branch_reg();
uint32_t encode_retab_64e_branch_reg();
uint32_t encode_retaasppc_only_miscbranch(uint32_t imm16);
uint32_t encode_retabsppc_only_miscbranch(uint32_t imm16);
uint32_t encode_retaasppcr_64m_branch_reg(uint32_t Rm);
uint32_t encode_retabsppcr_64m_branch_reg(uint32_t Rm);
uint32_t encode_sb_only_barriers();
uint32_t encode_sev_hi_hints();
uint32_t encode_sevl_hi_hints();
uint32_t encode_shuh_hi_hints(uint32_t op2);
uint32_t encode_smc_ex_exception(uint32_t imm16);
uint32_t encode_smstart_msr_si_pstate(uint32_t CRm);
uint32_t encode_smstop_msr_si_pstate(uint32_t CRm);
uint32_t encode_ssbb_dsb_bo_barriers();
uint32_t encode_stcph_hi_hints();
uint32_t encode_stshh_hi_hints(uint32_t op2);
uint32_t encode_svc_ex_exception(uint32_t imm16);
uint32_t encode_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_sysl_rc_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_sysp_cr_syspairinstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_tbnz_only_testbranch(uint32_t Rt, int32_t imm14, uint32_t b40, uint32_t b5);
uint32_t encode_tbz_only_testbranch(uint32_t Rt, int32_t imm14, uint32_t b40, uint32_t b5);
uint32_t encode_tlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_tlbip_sysp_cr_syspairinstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_trcit_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_tsb_hc_hints();
uint32_t encode_wfe_hi_hints();
uint32_t encode_wfet_only_systeminstrswithreg(uint32_t Rd);
uint32_t encode_wfi_hi_hints();
uint32_t encode_wfit_only_systeminstrswithreg(uint32_t Rd);
uint32_t encode_xaflag_m_pstate();
uint32_t encode_xpaclri_hi_hints();
uint32_t encode_yield_hi_hints();

// Decode function
// Decode a control instruction from a uint32_t
std::optional<Instruction> decode_control(uint32_t insn);

// Decode a control instruction from 4 bytes in memory (little-endian)
inline std::optional<Instruction> decode_control(const uint8_t* bytes) {
    return decode_control(from_bytes(bytes));
}

} // namespace control
} // namespace format
} // namespace veda64
