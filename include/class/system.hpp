#pragma once

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace System {

// Encode functions
uint32_t encode_apas_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_at_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1);
uint32_t encode_axflag_m_pstate(uint32_t CRm);
uint32_t encode_brb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2);
uint32_t encode_brk_ex_exception(uint32_t imm16);
uint32_t encode_bti_hb_hints(uint32_t op2);
uint32_t encode_cfinv_m_pstate(uint32_t CRm);
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
uint32_t encode_pacm_hi_hints();
uint32_t encode_psb_hc_hints();
uint32_t encode_pssbb_dsb_bo_barriers();
uint32_t encode_sb_only_barriers(uint32_t CRm);
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
uint32_t encode_tlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_tlbip_sysp_cr_syspairinstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1);
uint32_t encode_trcit_sys_cr_systeminstrs(uint32_t Rt);
uint32_t encode_tsb_hc_hints();
uint32_t encode_wfe_hi_hints();
uint32_t encode_wfet_only_systeminstrswithreg(uint32_t Rd);
uint32_t encode_wfi_hi_hints();
uint32_t encode_wfit_only_systeminstrswithreg(uint32_t Rd);
uint32_t encode_xaflag_m_pstate(uint32_t CRm);
uint32_t encode_yield_hi_hints();

// Decode function
// Decode a system instruction
std::optional<Instruction> decode_system(uint32_t insn);

// Decode from 4 bytes in native ARM64 memory order
inline std::optional<Instruction> decode_system(const uint8_t* bytes) {
    return decode_system(from_bytes(bytes));
}

} // namespace System
} // namespace veda64
