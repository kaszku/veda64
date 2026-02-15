#pragma once
// ARM64 Decode Group: Data Processing -- Register
// 201 instruction encodings

#include <cstdint>
#include <optional>
#include "../veda64.hpp"

namespace veda64 {
namespace format {
namespace dpreg {

// Encode functions
uint32_t encode_abs_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_abs_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_adc_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_adc_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_adcs_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_adcs_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_add_32_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_add_64_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_add_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_add_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_addpt_64_addsub_pt(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t Rm);
uint32_t encode_adds_32s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_adds_64s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_adds_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_adds_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_and_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_and_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_ands_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_ands_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_asr_asrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_asr_asrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_asrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_asrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_autda_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autdza_64z_dp_1src(uint32_t Rd);
uint32_t encode_autdb_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autdzb_64z_dp_1src(uint32_t Rd);
uint32_t encode_autia_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autiza_64z_dp_1src(uint32_t Rd);
uint32_t encode_autia171615_64lr_dp_1src();
uint32_t encode_autiasppcr_64lrr_dp_1src(uint32_t Rn);
uint32_t encode_autib_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_autizb_64z_dp_1src(uint32_t Rd);
uint32_t encode_autib171615_64lr_dp_1src();
uint32_t encode_autibsppcr_64lrr_dp_1src(uint32_t Rn);
uint32_t encode_bic_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_bic_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_bics_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_bics_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_ccmn_32_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5);
uint32_t encode_ccmn_64_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5);
uint32_t encode_ccmn_32_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_ccmn_64_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_ccmp_32_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5);
uint32_t encode_ccmp_64_condcmp_imm(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t imm5);
uint32_t encode_ccmp_32_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_ccmp_64_condcmp_reg(uint32_t nzcv, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cinc_csinc_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cinc_csinc_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cinv_csinv_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cinv_csinv_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cls_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_cls_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_clz_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_clz_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_cmn_adds_32s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_cmn_adds_64s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_cmn_adds_32_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_cmn_adds_64_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_cmp_subs_32s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_cmp_subs_64s_addsub_ext(uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_cmp_subs_32_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_cmp_subs_64_addsub_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_cmpp_subps_64s_dp_2src(uint32_t Rn, uint32_t Rm);
uint32_t encode_cneg_csneg_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cneg_csneg_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cnt_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_cnt_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_crc32b_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32h_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32w_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32x_64c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32cb_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32ch_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32cw_32c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_crc32cx_64c_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_csel_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csel_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_cset_csinc_32_condsel(uint32_t Rd, uint32_t cond);
uint32_t encode_cset_csinc_64_condsel(uint32_t Rd, uint32_t cond);
uint32_t encode_csetm_csinv_32_condsel(uint32_t Rd, uint32_t cond);
uint32_t encode_csetm_csinv_64_condsel(uint32_t Rd, uint32_t cond);
uint32_t encode_csinc_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csinc_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csinv_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csinv_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csneg_32_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_csneg_64_condsel(uint32_t Rd, uint32_t Rn, uint32_t cond, uint32_t Rm);
uint32_t encode_ctz_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_ctz_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_eon_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_eon_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_eor_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_eor_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_gmi_64g_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_irg_64i_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsl_lslv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsl_lslv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lslv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lslv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsr_lsrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsr_lsrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsrv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_lsrv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_madd_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_madd_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_maddpt_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_mneg_msub_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_mneg_msub_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_mov_orr_32_log_shift(uint32_t Rd, uint32_t Rm);
uint32_t encode_mov_orr_64_log_shift(uint32_t Rd, uint32_t Rm);
uint32_t encode_msub_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_msub_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_msubpt_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_mul_madd_32a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_mul_madd_64a_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_mvn_orn_32_log_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_mvn_orn_64_log_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_neg_sub_32_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_neg_sub_64_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_negs_subs_32_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_negs_subs_64_addsub_shift(uint32_t Rd, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_ngc_sbc_32_addsub_carry(uint32_t Rd, uint32_t Rm);
uint32_t encode_ngc_sbc_64_addsub_carry(uint32_t Rd, uint32_t Rm);
uint32_t encode_ngcs_sbcs_32_addsub_carry(uint32_t Rd, uint32_t Rm);
uint32_t encode_ngcs_sbcs_64_addsub_carry(uint32_t Rd, uint32_t Rm);
uint32_t encode_orn_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_orn_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_orr_32_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_orr_64_log_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_pacda_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_pacdza_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacdb_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_pacdzb_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacga_64p_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_pacia_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_paciza_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacia171615_64lr_dp_1src();
uint32_t encode_paciasppc_64lr_dp_1src();
uint32_t encode_pacib_64p_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_pacizb_64z_dp_1src(uint32_t Rd);
uint32_t encode_pacib171615_64lr_dp_1src();
uint32_t encode_pacibsppc_64lr_dp_1src();
uint32_t encode_pacnbiasppc_64lr_dp_1src();
uint32_t encode_pacnbibsppc_64lr_dp_1src();
uint32_t encode_rbit_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rbit_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev16_32_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev16_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev32_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rev64_rev_64_dp_1src(uint32_t Rd, uint32_t Rn);
uint32_t encode_rmif_only_rmif(uint32_t mask, uint32_t Rn, uint32_t imm6);
uint32_t encode_ror_rorv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_ror_rorv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_rorv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_rorv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sbc_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sbc_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sbcs_32_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sbcs_64_addsub_carry(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sdiv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sdiv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_setf8_only_setf(uint32_t Rn);
uint32_t encode_setf16_only_setf(uint32_t Rn);
uint32_t encode_smaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_smax_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smax_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smin_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smin_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smnegl_smsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_smulh_64_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_smull_smaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_sub_32_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_sub_64_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_sub_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_sub_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_subp_64s_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_subps_64s_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_subpt_64_addsub_pt(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t Rm);
uint32_t encode_subs_32s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_subs_64s_addsub_ext(uint32_t Rd, uint32_t Rn, uint32_t imm3, uint32_t option, uint32_t Rm);
uint32_t encode_subs_32_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_subs_64_addsub_shift(uint32_t Rd, uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_tst_ands_32_log_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_tst_ands_64_log_shift(uint32_t Rn, uint32_t imm6, uint32_t Rm, uint32_t shift);
uint32_t encode_udiv_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_udiv_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_umax_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umax_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umin_32_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umin_64_dp_2src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umnegl_umsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umsubl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Ra, uint32_t Rm);
uint32_t encode_umulh_64_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_umull_umaddl_64wa_dp_3src(uint32_t Rd, uint32_t Rn, uint32_t Rm);
uint32_t encode_xpacd_64z_dp_1src(uint32_t Rd);
uint32_t encode_xpaci_64z_dp_1src(uint32_t Rd);

// Decode function
// Decode a dpreg instruction from a uint32_t
std::optional<Instruction> decode_dpreg(uint32_t insn);

// Decode a dpreg instruction from 4 bytes in memory (little-endian)
inline std::optional<Instruction> decode_dpreg(const uint8_t* bytes) {
    return decode_dpreg(from_bytes(bytes));
}

} // namespace dpreg
} // namespace format
} // namespace veda64
