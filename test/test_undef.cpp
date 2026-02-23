// Auto-generated - do not edit
// Tests that Decode_UNDEF conditions correctly reject invalid encodings
#include "veda64.hpp"
#include <cassert>
#include <iostream>

using namespace veda64;

void test_add_32_addsub_shift_shift_eq_11() {
    // ADD_32_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0x0BC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_add_64_addsub_shift_shift_eq_11() {
    // ADD_64_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0x8BC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_addhn_asimddiff_n_size_eq_11() {
    // ADDHN_asimddiff_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE04000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_addhnb_z_zz__size_eq_00() {
    // addhnb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45206000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_addhnt_z_zz__size_eq_00() {
    // addhnt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45206400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_adds_32_addsub_shift_shift_eq_11() {
    // ADDS_32_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0x2BC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_adds_64_addsub_shift_shift_eq_11() {
    // ADDS_64_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0xABC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_addv_asimdall_only_size_eq_11() {
    // ADDV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EF1B800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_asr_z_p_zw__size_eq_11() {
    // asr_z_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04D88000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_asr_z_zw__size_eq_11() {
    // asr_z_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04E08000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cls_asimdmisc_r_size_eq_11() {
    // CLS_asimdmisc_R: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE04800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_clz_asimdmisc_r_size_eq_11() {
    // CLZ_asimdmisc_R: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE04800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmpeq_p_p_zw__size_eq_11() {
    // cmpeq_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C02000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmpgt_p_p_zw__size_eq_11() {
    // cmpgt_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C04010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmpge_p_p_zw__size_eq_11() {
    // cmpge_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C04000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmphi_p_p_zw__size_eq_11() {
    // cmphi_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C0C010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmphs_p_p_zw__size_eq_11() {
    // cmphs_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C0C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmplt_p_p_zw__size_eq_11() {
    // cmplt_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C06000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmple_p_p_zw__size_eq_11() {
    // cmple_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C06010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmplo_p_p_zw__size_eq_11() {
    // cmplo_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C0E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmpls_p_p_zw__size_eq_11() {
    // cmpls_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C0E010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_cmpne_p_p_zw__size_eq_11() {
    // cmpne_p_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x24C02010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_decp_z_p_z__size_eq_00() {
    // decp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x252D8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_dup_z_zi__tsz_eq_00000() {
    // dup_z_zi_: tsz=='00000' should be UNDEFINED
    uint32_t insn = 0x05202000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_dupq_z_zi__tsz_eq_0000() {
    // dupq_z_zi_: tsz=='0000' should be UNDEFINED
    uint32_t insn = 0x05202400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fabd_z_p_zz__size_eq_00() {
    // fabd_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65088000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fabs_z_p_z_m_size_eq_00() {
    // fabs_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x041CA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fabs_z_p_z_z_size_eq_00() {
    // fabs_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x040CA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_facgt_p_p_zz__size_eq_00() {
    // facgt_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6500E010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_facge_p_p_zz__size_eq_00() {
    // facge_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6500C010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fadd_z_p_zs__size_eq_00() {
    // fadd_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65188000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fadda_v_p_z__size_eq_00() {
    // fadda_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65182000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_faddp_z_p_zz__size_eq_00() {
    // faddp_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64108000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_faddqv_z_p_z__size_eq_00() {
    // faddqv_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6410A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_faddv_v_p_z__size_eq_00() {
    // faddv_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65002000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famax_mz_zzw_2x2_size_eq_00() {
    // famax_mz_zzw_2x2: size=='00' should be UNDEFINED
    uint32_t insn = 0xC120B140u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famax_mz_zzw_4x4_size_eq_00() {
    // famax_mz_zzw_4x4: size=='00' should be UNDEFINED
    uint32_t insn = 0xC120B940u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famax_z_p_zz__size_eq_00() {
    // famax_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650E8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famin_mz_zzw_2x2_size_eq_00() {
    // famin_mz_zzw_2x2: size=='00' should be UNDEFINED
    uint32_t insn = 0xC120B141u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famin_mz_zzw_4x4_size_eq_00() {
    // famin_mz_zzw_4x4: size=='00' should be UNDEFINED
    uint32_t insn = 0xC120B941u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_famin_z_p_zz__size_eq_00() {
    // famin_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcadd_asimdsame2_c_size_eq_00() {
    // FCADD_asimdsame2_C: size=='00' should be UNDEFINED
    uint32_t insn = 0x2E00E400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcadd_z_p_zz__size_eq_00() {
    // fcadd_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64008000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmeq_p_p_z0__size_eq_00() {
    // fcmeq_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65122000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmgt_p_p_z0__size_eq_00() {
    // fcmgt_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65102010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmge_p_p_z0__size_eq_00() {
    // fcmge_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65102000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmlt_p_p_z0__size_eq_00() {
    // fcmlt_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65112000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmle_p_p_z0__size_eq_00() {
    // fcmle_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65112010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmne_p_p_z0__size_eq_00() {
    // fcmne_p_p_z0_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65132000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmeq_p_p_zz__size_eq_00() {
    // fcmeq_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65006000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmgt_p_p_zz__size_eq_00() {
    // fcmgt_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65004010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmge_p_p_zz__size_eq_00() {
    // fcmge_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65004000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmne_p_p_zz__size_eq_00() {
    // fcmne_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65006010u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmuo_p_p_zz__size_eq_00() {
    // fcmuo_p_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6500C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmla_asimdsame2_c_size_eq_00() {
    // FCMLA_asimdsame2_C: size=='00' should be UNDEFINED
    uint32_t insn = 0x2E00C400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcmla_z_p_zzz__size_eq_00() {
    // fcmla_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64000000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcpy_z_p_i__size_eq_00() {
    // fcpy_z_p_i_: size=='00' should be UNDEFINED
    uint32_t insn = 0x0510C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcvtzsn_z_mz2__size_eq_00() {
    // fcvtzsn_z_mz2_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650D3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fcvtzun_z_mz2__size_eq_00() {
    // fcvtzun_z_mz2_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650D3400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fdiv_z_p_zz__size_eq_00() {
    // fdiv_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650D8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fdivr_z_p_zz__size_eq_00() {
    // fdivr_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650C8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fdup_z_i__size_eq_00() {
    // fdup_z_i_: size=='00' should be UNDEFINED
    uint32_t insn = 0x2539C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fexpa_z_z__size_eq_00() {
    // fexpa_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x0420B800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_flogb_z_p_z_m_size_eq_00() {
    // flogb_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6518A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_flogb_z_p_z_z_size_eq_00() {
    // flogb_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x641E8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmad_z_p_zzz__size_eq_00() {
    // fmad_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65208000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmax_z_p_zs__size_eq_00() {
    // fmax_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651E8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxnm_z_p_zs__size_eq_00() {
    // fmaxnm_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651C8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxnmp_z_p_zz__size_eq_00() {
    // fmaxnmp_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64148000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxnmqv_z_p_z__size_eq_00() {
    // fmaxnmqv_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6414A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxnmv_v_p_z__size_eq_00() {
    // fmaxnmv_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65042000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxp_z_p_zz__size_eq_00() {
    // fmaxp_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64168000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxqv_z_p_z__size_eq_00() {
    // fmaxqv_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6416A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmaxv_v_p_z__size_eq_00() {
    // fmaxv_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65062000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmin_z_p_zs__size_eq_00() {
    // fmin_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminnm_z_p_zs__size_eq_00() {
    // fminnm_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651D8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminnmp_z_p_zz__size_eq_00() {
    // fminnmp_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64158000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminnmqv_z_p_z__size_eq_00() {
    // fminnmqv_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6415A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminnmv_v_p_z__size_eq_00() {
    // fminnmv_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65052000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminp_z_p_zz__size_eq_00() {
    // fminp_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x64178000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminqv_z_p_z__size_eq_00() {
    // fminqv_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6417A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fminv_v_p_z__size_eq_00() {
    // fminv_v_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65072000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmov_asimdimm_s_s_Q_eq_0() {
    // FMOV_asimdimm_S_s: Q=='0' should be UNDEFINED
    uint32_t insn = 0x0F00F400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmsb_z_p_zzz__size_eq_00() {
    // fmsb_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6520A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmul_z_p_zs__size_eq_00() {
    // fmul_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651A8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fmulx_z_p_zz__size_eq_00() {
    // fmulx_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650A8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fneg_z_p_z_m_size_eq_00() {
    // fneg_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x041DA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fneg_z_p_z_z_size_eq_00() {
    // fneg_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x040DA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fnmad_z_p_zzz__size_eq_00() {
    // fnmad_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6520C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fnmla_z_p_zzz__size_eq_00() {
    // fnmla_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65204000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fnmls_z_p_zzz__size_eq_00() {
    // fnmls_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65206000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fnmsb_z_p_zzz__size_eq_00() {
    // fnmsb_z_p_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x6520E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frecpe_z_z__size_eq_00() {
    // frecpe_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650E3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frecps_z_zz__size_eq_00() {
    // frecps_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65001800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frecpx_z_p_z_m_size_eq_00() {
    // frecpx_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x650CA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frecpx_z_p_z_z_size_eq_00() {
    // frecpx_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x641B8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintx_z_p_z_m_size_eq_00() {
    // frintx_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6506A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintx_z_p_z_z_size_eq_00() {
    // frintx_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x6419C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frinti_z_p_z_m_size_eq_00() {
    // frinti_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6507A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frinti_z_p_z_z_size_eq_00() {
    // frinti_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x6419E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frinta_z_p_z_m_size_eq_00() {
    // frinta_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6504A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frinta_z_p_z_z_size_eq_00() {
    // frinta_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x64198000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintn_z_p_z_m_size_eq_00() {
    // frintn_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6500A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintn_z_p_z_z_size_eq_00() {
    // frintn_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x64188000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintz_z_p_z_m_size_eq_00() {
    // frintz_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6503A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintz_z_p_z_z_size_eq_00() {
    // frintz_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x6418E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintm_z_p_z_m_size_eq_00() {
    // frintm_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6502A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintm_z_p_z_z_size_eq_00() {
    // frintm_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x6418C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintp_z_p_z_m_size_eq_00() {
    // frintp_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x6501A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frintp_z_p_z_z_size_eq_00() {
    // frintp_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x6418A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frsqrte_z_z__size_eq_00() {
    // frsqrte_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650F3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_frsqrts_z_zz__size_eq_00() {
    // frsqrts_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65001C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fsqrt_z_p_z_m_size_eq_00() {
    // fsqrt_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x650DA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fsqrt_z_p_z_z_size_eq_00() {
    // fsqrt_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x641BA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fsub_z_p_zs__size_eq_00() {
    // fsub_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65198000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fsubr_z_p_zs__size_eq_00() {
    // fsubr_z_p_zs_: size=='00' should be UNDEFINED
    uint32_t insn = 0x651B8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_fsubr_z_p_zz__size_eq_00() {
    // fsubr_z_p_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65038000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ftmad_z_zzi__size_eq_00() {
    // ftmad_z_zzi_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65108000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ftsmul_z_zz__size_eq_00() {
    // ftsmul_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x65000C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ftssel_z_zz__size_eq_00() {
    // ftssel_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x0420B000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_incp_z_p_z__size_eq_00() {
    // incp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x252C8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1b_z_p_br_u8_Rm_eq_11111() {
    // ld1b_z_p_br_u8: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA41F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1b_z_p_br_u16_Rm_eq_11111() {
    // ld1b_z_p_br_u16: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA43F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1b_z_p_br_u32_Rm_eq_11111() {
    // ld1b_z_p_br_u32: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA45F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1b_z_p_br_u64_Rm_eq_11111() {
    // ld1b_z_p_br_u64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA47F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1d_z_p_br_u64_Rm_eq_11111() {
    // ld1d_z_p_br_u64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5FF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1d_z_p_br_u128_Rm_eq_11111() {
    // ld1d_z_p_br_u128: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA59F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1h_z_p_br_u16_Rm_eq_11111() {
    // ld1h_z_p_br_u16: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4BF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1h_z_p_br_u32_Rm_eq_11111() {
    // ld1h_z_p_br_u32: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4DF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1h_z_p_br_u64_Rm_eq_11111() {
    // ld1h_z_p_br_u64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4FF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rob_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rob_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA43F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rod_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rod_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5BF0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1roh_z_p_br_contiguous_Rm_eq_11111() {
    // ld1roh_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4BF0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1row_z_p_br_contiguous_Rm_eq_11111() {
    // ld1row_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA53F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rqb_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rqb_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA41F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rqd_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rqd_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA59F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rqh_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rqh_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA49F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1rqw_z_p_br_contiguous_Rm_eq_11111() {
    // ld1rqw_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA51F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sb_z_p_br_s16_Rm_eq_11111() {
    // ld1sb_z_p_br_s16: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5DF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sb_z_p_br_s32_Rm_eq_11111() {
    // ld1sb_z_p_br_s32: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5BF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sb_z_p_br_s64_Rm_eq_11111() {
    // ld1sb_z_p_br_s64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA59F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sh_z_p_br_s32_Rm_eq_11111() {
    // ld1sh_z_p_br_s32: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA53F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sh_z_p_br_s64_Rm_eq_11111() {
    // ld1sh_z_p_br_s64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA51F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1sw_z_p_br_s64_Rm_eq_11111() {
    // ld1sw_z_p_br_s64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA49F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1w_z_p_br_u32_Rm_eq_11111() {
    // ld1w_z_p_br_u32: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA55F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1w_z_p_br_u64_Rm_eq_11111() {
    // ld1w_z_p_br_u64: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA57F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld1w_z_p_br_u128_Rm_eq_11111() {
    // ld1w_z_p_br_u128: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA51F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld2b_z_p_br_contiguous_Rm_eq_11111() {
    // ld2b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA43FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld2d_z_p_br_contiguous_Rm_eq_11111() {
    // ld2d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5BFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld2h_z_p_br_contiguous_Rm_eq_11111() {
    // ld2h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4BFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld2q_z_p_br_contiguous_Rm_eq_11111() {
    // ld2q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4BF8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld2w_z_p_br_contiguous_Rm_eq_11111() {
    // ld2w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA53FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld3b_z_p_br_contiguous_Rm_eq_11111() {
    // ld3b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA45FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld3d_z_p_br_contiguous_Rm_eq_11111() {
    // ld3d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5DFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld3h_z_p_br_contiguous_Rm_eq_11111() {
    // ld3h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4DFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld3q_z_p_br_contiguous_Rm_eq_11111() {
    // ld3q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA53F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld3w_z_p_br_contiguous_Rm_eq_11111() {
    // ld3w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA55FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld4b_z_p_br_contiguous_Rm_eq_11111() {
    // ld4b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA47FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld4d_z_p_br_contiguous_Rm_eq_11111() {
    // ld4d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5FFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld4h_z_p_br_contiguous_Rm_eq_11111() {
    // ld4h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA4FFC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld4q_z_p_br_contiguous_Rm_eq_11111() {
    // ld4q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA5BF8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ld4w_z_p_br_contiguous_Rm_eq_11111() {
    // ld4w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA57FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrp_128_memop_128_Rt_eq_11111() {
    // LDCLRP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920101Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrp_128_memop_128_Rt2_eq_11111() {
    // LDCLRP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193F1000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpa_128_memop_128_Rt_eq_11111() {
    // LDCLRPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0101Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpa_128_memop_128_Rt2_eq_11111() {
    // LDCLRPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BF1000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpal_128_memop_128_Rt_eq_11111() {
    // LDCLRPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0101Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpal_128_memop_128_Rt2_eq_11111() {
    // LDCLRPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FF1000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpl_128_memop_128_Rt_eq_11111() {
    // LDCLRPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960101Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldclrpl_128_memop_128_Rt2_eq_11111() {
    // LDCLRPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197F1000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldnt1b_z_p_br_contiguous_Rm_eq_11111() {
    // ldnt1b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA41FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldnt1d_z_p_br_contiguous_Rm_eq_11111() {
    // ldnt1d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA59FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldnt1h_z_p_br_contiguous_Rm_eq_11111() {
    // ldnt1h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA49FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldnt1w_z_p_br_contiguous_Rm_eq_11111() {
    // ldnt1w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xA51FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetp_128_memop_128_Rt_eq_11111() {
    // LDSETP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920301Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetp_128_memop_128_Rt2_eq_11111() {
    // LDSETP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193F3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpa_128_memop_128_Rt_eq_11111() {
    // LDSETPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0301Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpa_128_memop_128_Rt2_eq_11111() {
    // LDSETPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BF3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpal_128_memop_128_Rt_eq_11111() {
    // LDSETPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0301Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpal_128_memop_128_Rt2_eq_11111() {
    // LDSETPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FF3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpl_128_memop_128_Rt_eq_11111() {
    // LDSETPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960301Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ldsetpl_128_memop_128_Rt2_eq_11111() {
    // LDSETPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197F3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_lsl_z_p_zw__size_eq_11() {
    // lsl_z_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04DB8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_lsl_z_zw__size_eq_11() {
    // lsl_z_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04E08C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_lsr_z_p_zw__size_eq_11() {
    // lsr_z_p_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04D98000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_lsr_z_zw__size_eq_11() {
    // lsr_z_zw_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04E08400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_luti2_mz2_ztz_1_size_eq_11() {
    // luti2_mz2_ztz_1: size=='11' should be UNDEFINED
    uint32_t insn = 0xC08C7000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_luti2_mz4_ztz_1_size_eq_11() {
    // luti2_mz4_ztz_1: size=='11' should be UNDEFINED
    uint32_t insn = 0xC08CB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_luti2_z_ztz__size_eq_11() {
    // luti2_z_ztz_: size=='11' should be UNDEFINED
    uint32_t insn = 0xC0CC3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_luti4_mz2_ztz_1_size_eq_11() {
    // luti4_mz2_ztz_1: size=='11' should be UNDEFINED
    uint32_t insn = 0xC08A7000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_luti4_z_ztz__size_eq_11() {
    // luti4_z_ztz_: size=='11' should be UNDEFINED
    uint32_t insn = 0xC0CA3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_mla_asimdsame_only_size_eq_11() {
    // MLA_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE09400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_mls_asimdsame_only_size_eq_11() {
    // MLS_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE09400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_mul_asimdsame_only_size_eq_11() {
    // MUL_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE09C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_pmul_asimdsame_only_size_eq_11() {
    // PMUL_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE09C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_prfb_i_p_br_s_Rm_eq_11111() {
    // prfb_i_p_br_s: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0x841FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_prfd_i_p_br_s_Rm_eq_11111() {
    // prfd_i_p_br_s: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0x859FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_prfh_i_p_br_s_Rm_eq_11111() {
    // prfh_i_p_br_s: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0x849FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_prfw_i_p_br_s_Rm_eq_11111() {
    // prfw_i_p_br_s: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0x851FC000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_raddhn_asimddiff_n_size_eq_11() {
    // RADDHN_asimddiff_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE04000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_raddhnb_z_zz__size_eq_00() {
    // raddhnb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45206800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_raddhnt_z_zz__size_eq_00() {
    // raddhnt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45206C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrp_128_memop_128_Rt_eq_11111() {
    // RCWCLRP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrp_128_memop_128_Rt2_eq_11111() {
    // RCWCLRP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193F9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpa_128_memop_128_Rt_eq_11111() {
    // RCWCLRPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpa_128_memop_128_Rt2_eq_11111() {
    // RCWCLRPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BF9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpal_128_memop_128_Rt_eq_11111() {
    // RCWCLRPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpal_128_memop_128_Rt2_eq_11111() {
    // RCWCLRPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FF9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpl_128_memop_128_Rt_eq_11111() {
    // RCWCLRPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwclrpl_128_memop_128_Rt2_eq_11111() {
    // RCWCLRPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197F9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrp_128_memop_128_Rt_eq_11111() {
    // RCWSCLRP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5920901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrp_128_memop_128_Rt2_eq_11111() {
    // RCWSCLRP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x593F9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpa_128_memop_128_Rt_eq_11111() {
    // RCWSCLRPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59A0901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpa_128_memop_128_Rt2_eq_11111() {
    // RCWSCLRPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59BF9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpal_128_memop_128_Rt_eq_11111() {
    // RCWSCLRPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59E0901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpal_128_memop_128_Rt2_eq_11111() {
    // RCWSCLRPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59FF9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpl_128_memop_128_Rt_eq_11111() {
    // RCWSCLRPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5960901Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsclrpl_128_memop_128_Rt2_eq_11111() {
    // RCWSCLRPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x597F9000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetp_128_memop_128_Rt_eq_11111() {
    // RCWSETP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetp_128_memop_128_Rt2_eq_11111() {
    // RCWSETP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193FB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpa_128_memop_128_Rt_eq_11111() {
    // RCWSETPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpa_128_memop_128_Rt2_eq_11111() {
    // RCWSETPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BFB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpal_128_memop_128_Rt_eq_11111() {
    // RCWSETPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpal_128_memop_128_Rt2_eq_11111() {
    // RCWSETPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FFB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpl_128_memop_128_Rt_eq_11111() {
    // RCWSETPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsetpl_128_memop_128_Rt2_eq_11111() {
    // RCWSETPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197FB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetp_128_memop_128_Rt_eq_11111() {
    // RCWSSETP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5920B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetp_128_memop_128_Rt2_eq_11111() {
    // RCWSSETP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x593FB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpa_128_memop_128_Rt_eq_11111() {
    // RCWSSETPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59A0B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpa_128_memop_128_Rt2_eq_11111() {
    // RCWSSETPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59BFB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpal_128_memop_128_Rt_eq_11111() {
    // RCWSSETPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59E0B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpal_128_memop_128_Rt2_eq_11111() {
    // RCWSSETPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59FFB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpl_128_memop_128_Rt_eq_11111() {
    // RCWSSETPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5960B01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwssetpl_128_memop_128_Rt2_eq_11111() {
    // RCWSSETPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x597FB000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswpp_128_memop_128_Rt_eq_11111() {
    // RCWSSWPP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5920A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswpp_128_memop_128_Rt2_eq_11111() {
    // RCWSSWPP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x593FA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppa_128_memop_128_Rt_eq_11111() {
    // RCWSSWPPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59A0A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppa_128_memop_128_Rt2_eq_11111() {
    // RCWSSWPPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59BFA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppal_128_memop_128_Rt_eq_11111() {
    // RCWSSWPPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x59E0A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppal_128_memop_128_Rt2_eq_11111() {
    // RCWSSWPPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x59FFA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppl_128_memop_128_Rt_eq_11111() {
    // RCWSSWPPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x5960A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwsswppl_128_memop_128_Rt2_eq_11111() {
    // RCWSSWPPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x597FA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswpp_128_memop_128_Rt_eq_11111() {
    // RCWSWPP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswpp_128_memop_128_Rt2_eq_11111() {
    // RCWSWPP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193FA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppa_128_memop_128_Rt_eq_11111() {
    // RCWSWPPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppa_128_memop_128_Rt2_eq_11111() {
    // RCWSWPPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BFA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppal_128_memop_128_Rt_eq_11111() {
    // RCWSWPPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppal_128_memop_128_Rt2_eq_11111() {
    // RCWSWPPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FFA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppl_128_memop_128_Rt_eq_11111() {
    // RCWSWPPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960A01Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rcwswppl_128_memop_128_Rt2_eq_11111() {
    // RCWSWPPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197FA000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_revb_z_z_m_size_eq_00() {
    // revb_z_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x05248000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_revb_z_z_z_size_eq_00() {
    // revb_z_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x0524A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rsubhn_asimddiff_n_size_eq_11() {
    // RSUBHN_asimddiff_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE06000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rsubhnb_z_zz__size_eq_00() {
    // rsubhnb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45207800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_rsubhnt_z_zz__size_eq_00() {
    // rsubhnt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45207C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saba_asimdsame_only_size_eq_11() {
    // SABA_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE07C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabal_asimddiff_l_size_eq_11() {
    // SABAL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE05000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabal_z_zz__size_eq_00() {
    // sabal_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4400D400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabalb_z_zzz__size_eq_00() {
    // sabalb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4500C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabalt_z_zzz__size_eq_00() {
    // sabalt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4500C400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabd_asimdsame_only_size_eq_11() {
    // SABD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE07400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabdl_asimddiff_l_size_eq_11() {
    // SABDL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE07000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabdlb_z_zz__size_eq_00() {
    // sabdlb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45003000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sabdlt_z_zz__size_eq_00() {
    // sabdlt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45003400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sadalp_asimdmisc_p_size_eq_11() {
    // SADALP_asimdmisc_P: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE06800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sadalp_z_p_z__size_eq_00() {
    // sadalp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4404A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddl_asimddiff_l_size_eq_11() {
    // SADDL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddlb_z_zz__size_eq_00() {
    // saddlb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45000000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddlbt_z_zz__size_eq_00() {
    // saddlbt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45008000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddlp_asimdmisc_p_size_eq_11() {
    // SADDLP_asimdmisc_P: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE02800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddlt_z_zz__size_eq_00() {
    // saddlt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45000400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddlv_asimdall_only_size_eq_11() {
    // SADDLV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EF03800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddv_r_p_z__size_eq_11() {
    // saddv_r_p_z_: size=='11' should be UNDEFINED
    uint32_t insn = 0x04C02000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddw_asimddiff_w_size_eq_11() {
    // SADDW_asimddiff_W: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE01000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddwb_z_zz__size_eq_00() {
    // saddwb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45004000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_saddwt_z_zz__size_eq_00() {
    // saddwt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45004400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_scvtf_z_z__size_eq_00() {
    // scvtf_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650C3000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_scvtflt_z_z__size_eq_00() {
    // scvtflt_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650C3800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_shadd_asimdsame_only_size_eq_11() {
    // SHADD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE00400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_shll_asimdmisc_s_size_eq_11() {
    // SHLL_asimdmisc_S: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE13800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_shsub_asimdsame_only_size_eq_11() {
    // SHSUB_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE02400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smax_asimdsame_only_size_eq_11() {
    // SMAX_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE06400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smaxp_asimdsame_only_size_eq_11() {
    // SMAXP_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE0A400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smaxv_asimdall_only_size_eq_11() {
    // SMAXV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EF0A800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smin_asimdsame_only_size_eq_11() {
    // SMIN_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE06C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sminp_asimdsame_only_size_eq_11() {
    // SMINP_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE0AC00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sminv_asimdall_only_size_eq_11() {
    // SMINV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EF1A800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlal_asimddiff_l_size_eq_11() {
    // SMLAL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE08000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlalb_z_zzz__size_eq_00() {
    // smlalb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44004000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlalt_z_zzz__size_eq_00() {
    // smlalt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44004400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlsl_asimddiff_l_size_eq_11() {
    // SMLSL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE0A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlslb_z_zzz__size_eq_00() {
    // smlslb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44005000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smlslt_z_zzz__size_eq_00() {
    // smlslt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44005400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smull_asimddiff_l_size_eq_11() {
    // SMULL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE0C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smullb_z_zz__size_eq_00() {
    // smullb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45007000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_smullt_z_zz__size_eq_00() {
    // smullt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45007400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdecp_z_p_z__size_eq_00() {
    // sqdecp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x252A8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlalb_z_zzz__size_eq_00() {
    // sqdmlalb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44006000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlalbt_z_zzz__size_eq_00() {
    // sqdmlalbt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44000800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlalt_z_zzz__size_eq_00() {
    // sqdmlalt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44006400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlslb_z_zzz__size_eq_00() {
    // sqdmlslb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44006800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlslbt_z_zzz__size_eq_00() {
    // sqdmlslbt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44000C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmlslt_z_zzz__size_eq_00() {
    // sqdmlslt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44006C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmullb_z_zz__size_eq_00() {
    // sqdmullb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45006000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqdmullt_z_zz__size_eq_00() {
    // sqdmullt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45006400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqincp_z_p_z__size_eq_00() {
    // sqincp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x25288000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshr_z_mz4__tsize_eq_00() {
    // sqrshr_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120D800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshrn_asisdshf_n_immh_eq_0000() {
    // SQRSHRN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x5F009C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshrn_z_mz4__tsize_eq_00() {
    // sqrshrn_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120DC00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshru_z_mz4__tsize_eq_00() {
    // sqrshru_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120D840u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshrun_asisdshf_n_immh_eq_0000() {
    // SQRSHRUN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F008C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqrshrun_z_mz4__tsize_eq_00() {
    // sqrshrun_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120DC40u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshl_asisdshf_r_immh_eq_0000() {
    // SQSHL_asisdshf_R: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x5F007400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshlu_asisdshf_r_immh_eq_0000() {
    // SQSHLU_asisdshf_R: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F006400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshrn_asisdshf_n_immh_eq_0000() {
    // SQSHRN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x5F009400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshrn_z_mz2__tsize_eq_00() {
    // sqshrn_z_mz2_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0x45A00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshrun_asisdshf_n_immh_eq_0000() {
    // SQSHRUN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F008400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqshrun_z_mz2__tsize_eq_00() {
    // sqshrun_z_mz2_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0x45A02000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqxtn_asisdmisc_n_size_eq_11() {
    // SQXTN_asisdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x5EE14800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqxtn_asimdmisc_n_size_eq_11() {
    // SQXTN_asimdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE14800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqxtun_asisdmisc_n_size_eq_11() {
    // SQXTUN_asisdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x7EE12800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sqxtun_asimdmisc_n_size_eq_11() {
    // SQXTUN_asimdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE12800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_srhadd_asimdsame_only_size_eq_11() {
    // SRHADD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE01400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssubl_asimddiff_l_size_eq_11() {
    // SSUBL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE02000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssublb_z_zz__size_eq_00() {
    // ssublb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45001000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssublbt_z_zz__size_eq_00() {
    // ssublbt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45008800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssublt_z_zz__size_eq_00() {
    // ssublt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45001400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssubltb_z_zz__size_eq_00() {
    // ssubltb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45008C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssubw_asimddiff_w_size_eq_11() {
    // SSUBW_asimddiff_W: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE03000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssubwb_z_zz__size_eq_00() {
    // ssubwb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45005000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ssubwt_z_zz__size_eq_00() {
    // ssubwt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45005400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1b_z_p_br__Rm_eq_11111() {
    // st1b_z_p_br_: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE41F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1d_z_p_br__Rm_eq_11111() {
    // st1d_z_p_br_: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE5FF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1d_z_p_br_u128_Rm_eq_11111() {
    // st1d_z_p_br_u128: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE5DF4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1h_z_p_bi__size_eq_00() {
    // st1h_z_p_bi_: size=='00' should be UNDEFINED
    uint32_t insn = 0xE480E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1h_z_p_br__size_eq_00() {
    // st1h_z_p_br_: size=='00' should be UNDEFINED
    uint32_t insn = 0xE4804000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1h_z_p_br__Rm_eq_11111() {
    // st1h_z_p_br_: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE49F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1w_z_p_br__Rm_eq_11111() {
    // st1w_z_p_br_: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE55F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st1w_z_p_br_u128_Rm_eq_11111() {
    // st1w_z_p_br_u128: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE51F4000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st2b_z_p_br_contiguous_Rm_eq_11111() {
    // st2b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE43F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st2d_z_p_br_contiguous_Rm_eq_11111() {
    // st2d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE5BF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st2h_z_p_br_contiguous_Rm_eq_11111() {
    // st2h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE4BF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st2q_z_p_br_contiguous_Rm_eq_11111() {
    // st2q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE47F0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st2w_z_p_br_contiguous_Rm_eq_11111() {
    // st2w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE53F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st3b_z_p_br_contiguous_Rm_eq_11111() {
    // st3b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE45F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st3d_z_p_br_contiguous_Rm_eq_11111() {
    // st3d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE5DF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st3h_z_p_br_contiguous_Rm_eq_11111() {
    // st3h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE4DF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st3q_z_p_br_contiguous_Rm_eq_11111() {
    // st3q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE4BF0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st3w_z_p_br_contiguous_Rm_eq_11111() {
    // st3w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE55F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st4b_z_p_br_contiguous_Rm_eq_11111() {
    // st4b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE47F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st4d_z_p_br_contiguous_Rm_eq_11111() {
    // st4d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE5FF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st4h_z_p_br_contiguous_Rm_eq_11111() {
    // st4h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE4FF6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st4q_z_p_br_contiguous_Rm_eq_11111() {
    // st4q_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE4FF0000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_st4w_z_p_br_contiguous_Rm_eq_11111() {
    // st4w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE57F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_stnt1b_z_p_br_contiguous_Rm_eq_11111() {
    // stnt1b_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE41F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_stnt1d_z_p_br_contiguous_Rm_eq_11111() {
    // stnt1d_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE59F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_stnt1h_z_p_br_contiguous_Rm_eq_11111() {
    // stnt1h_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE49F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_stnt1w_z_p_br_contiguous_Rm_eq_11111() {
    // stnt1w_z_p_br_contiguous: Rm=='11111' should be UNDEFINED
    uint32_t insn = 0xE51F6000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sub_32_addsub_shift_shift_eq_11() {
    // SUB_32_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0x4BC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sub_64_addsub_shift_shift_eq_11() {
    // SUB_64_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0xCBC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_subhn_asimddiff_n_size_eq_11() {
    // SUBHN_asimddiff_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE06000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_subhnb_z_zz__size_eq_00() {
    // subhnb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45207000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_subhnt_z_zz__size_eq_00() {
    // subhnt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45207400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_subs_32_addsub_shift_shift_eq_11() {
    // SUBS_32_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0x6BC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_subs_64_addsub_shift_shift_eq_11() {
    // SUBS_64_addsub_shift: shift=='11' should be UNDEFINED
    uint32_t insn = 0xEBC00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sunpk_mz_z_2_size_eq_00() {
    // sunpk_mz_z_2: size=='00' should be UNDEFINED
    uint32_t insn = 0xC125E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sunpk_mz_z_4_size_eq_00() {
    // sunpk_mz_z_4: size=='00' should be UNDEFINED
    uint32_t insn = 0xC135E000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sunpkhi_z_z__size_eq_00() {
    // sunpkhi_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x05313800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sunpklo_z_z__size_eq_00() {
    // sunpklo_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x05303800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swpp_128_memop_128_Rt_eq_11111() {
    // SWPP_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1920801Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swpp_128_memop_128_Rt2_eq_11111() {
    // SWPP_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x193F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppa_128_memop_128_Rt_eq_11111() {
    // SWPPA_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19A0801Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppa_128_memop_128_Rt2_eq_11111() {
    // SWPPA_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19BF8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppal_128_memop_128_Rt_eq_11111() {
    // SWPPAL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x19E0801Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppal_128_memop_128_Rt2_eq_11111() {
    // SWPPAL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x19FF8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppl_128_memop_128_Rt_eq_11111() {
    // SWPPL_128_memop_128: Rt=='11111' should be UNDEFINED
    uint32_t insn = 0x1960801Fu;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_swppl_128_memop_128_Rt2_eq_11111() {
    // SWPPL_128_memop_128: Rt2=='11111' should be UNDEFINED
    uint32_t insn = 0x197F8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sxtb_z_p_z_m_size_eq_00() {
    // sxtb_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x0410A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_sxtb_z_p_z_z_size_eq_00() {
    // sxtb_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x0400A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaba_asimdsame_only_size_eq_11() {
    // UABA_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE07C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabal_asimddiff_l_size_eq_11() {
    // UABAL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE05000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabal_z_zz__size_eq_00() {
    // uabal_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4400DC00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabalb_z_zzz__size_eq_00() {
    // uabalb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4500C800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabalt_z_zzz__size_eq_00() {
    // uabalt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4500CC00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabd_asimdsame_only_size_eq_11() {
    // UABD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE07400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabdl_asimddiff_l_size_eq_11() {
    // UABDL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE07000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabdlb_z_zz__size_eq_00() {
    // uabdlb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45003800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uabdlt_z_zz__size_eq_00() {
    // uabdlt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45003C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uadalp_asimdmisc_p_size_eq_11() {
    // UADALP_asimdmisc_P: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE06800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uadalp_z_p_z__size_eq_00() {
    // uadalp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x4405A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddl_asimddiff_l_size_eq_11() {
    // UADDL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE00000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddlb_z_zz__size_eq_00() {
    // uaddlb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45000800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddlp_asimdmisc_p_size_eq_11() {
    // UADDLP_asimdmisc_P: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE02800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddlt_z_zz__size_eq_00() {
    // uaddlt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45000C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddlv_asimdall_only_size_eq_11() {
    // UADDLV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EF03800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddw_asimddiff_w_size_eq_11() {
    // UADDW_asimddiff_W: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE01000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddwb_z_zz__size_eq_00() {
    // uaddwb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45004800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uaddwt_z_zz__size_eq_00() {
    // uaddwt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45004C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ucvtf_z_z__size_eq_00() {
    // ucvtf_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650C3400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ucvtflt_z_z__size_eq_00() {
    // ucvtflt_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x650C3C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uhadd_asimdsame_only_size_eq_11() {
    // UHADD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE00400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uhsub_asimdsame_only_size_eq_11() {
    // UHSUB_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE02400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umax_asimdsame_only_size_eq_11() {
    // UMAX_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE06400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umaxp_asimdsame_only_size_eq_11() {
    // UMAXP_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE0A400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umaxv_asimdall_only_size_eq_11() {
    // UMAXV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EF0A800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umin_asimdsame_only_size_eq_11() {
    // UMIN_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE06C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uminp_asimdsame_only_size_eq_11() {
    // UMINP_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE0AC00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uminv_asimdall_only_size_eq_11() {
    // UMINV_asimdall_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EF1A800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlal_asimddiff_l_size_eq_11() {
    // UMLAL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE08000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlalb_z_zzz__size_eq_00() {
    // umlalb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44004800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlalt_z_zzz__size_eq_00() {
    // umlalt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44004C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlsl_asimddiff_l_size_eq_11() {
    // UMLSL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE0A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlslb_z_zzz__size_eq_00() {
    // umlslb_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44005800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umlslt_z_zzz__size_eq_00() {
    // umlslt_z_zzz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x44005C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umull_asimddiff_l_size_eq_11() {
    // UMULL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE0C000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umullb_z_zz__size_eq_00() {
    // umullb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45007800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_umullt_z_zz__size_eq_00() {
    // umullt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45007C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqdecp_z_p_z__size_eq_00() {
    // uqdecp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x252B8000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqincp_z_p_z__size_eq_00() {
    // uqincp_z_p_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x25298000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqrshr_z_mz4__tsize_eq_00() {
    // uqrshr_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120D820u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqrshrn_asisdshf_n_immh_eq_0000() {
    // UQRSHRN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F009C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqrshrn_z_mz4__tsize_eq_00() {
    // uqrshrn_z_mz4_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0xC120DC20u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqshl_asisdshf_r_immh_eq_0000() {
    // UQSHL_asisdshf_R: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F007400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqshrn_asisdshf_n_immh_eq_0000() {
    // UQSHRN_asisdshf_N: immh=='0000' should be UNDEFINED
    uint32_t insn = 0x7F009400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqshrn_z_mz2__tsize_eq_00() {
    // uqshrn_z_mz2_: tsize=='00' should be UNDEFINED
    uint32_t insn = 0x45A01000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqxtn_asisdmisc_n_size_eq_11() {
    // UQXTN_asisdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x7EE14800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uqxtn_asimdmisc_n_size_eq_11() {
    // UQXTN_asimdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE14800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_urecpe_asimdmisc_r_sz_eq_1() {
    // URECPE_asimdmisc_R: sz=='1' should be UNDEFINED
    uint32_t insn = 0x0EE1C800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_urhadd_asimdsame_only_size_eq_11() {
    // URHADD_asimdsame_only: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE01400u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_ursqrte_asimdmisc_r_sz_eq_1() {
    // URSQRTE_asimdmisc_R: sz=='1' should be UNDEFINED
    uint32_t insn = 0x2EE1C800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usubl_asimddiff_l_size_eq_11() {
    // USUBL_asimddiff_L: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE02000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usublb_z_zz__size_eq_00() {
    // usublb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45001800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usublt_z_zz__size_eq_00() {
    // usublt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45001C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usubw_asimddiff_w_size_eq_11() {
    // USUBW_asimddiff_W: size=='11' should be UNDEFINED
    uint32_t insn = 0x2EE03000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usubwb_z_zz__size_eq_00() {
    // usubwb_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45005800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_usubwt_z_zz__size_eq_00() {
    // usubwt_z_zz_: size=='00' should be UNDEFINED
    uint32_t insn = 0x45005C00u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uunpk_mz_z_2_size_eq_00() {
    // uunpk_mz_z_2: size=='00' should be UNDEFINED
    uint32_t insn = 0xC125E001u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uunpk_mz_z_4_size_eq_00() {
    // uunpk_mz_z_4: size=='00' should be UNDEFINED
    uint32_t insn = 0xC135E001u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uunpkhi_z_z__size_eq_00() {
    // uunpkhi_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x05333800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uunpklo_z_z__size_eq_00() {
    // uunpklo_z_z_: size=='00' should be UNDEFINED
    uint32_t insn = 0x05323800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uxtb_z_p_z_m_size_eq_00() {
    // uxtb_z_p_z_m: size=='00' should be UNDEFINED
    uint32_t insn = 0x0411A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_uxtb_z_p_z_z_size_eq_00() {
    // uxtb_z_p_z_z: size=='00' should be UNDEFINED
    uint32_t insn = 0x0401A000u;
    auto result = decode(insn);
    assert(!result.has_value());
}

void test_xtn_asimdmisc_n_size_eq_11() {
    // XTN_asimdmisc_N: size=='11' should be UNDEFINED
    uint32_t insn = 0x0EE12800u;
    auto result = decode(insn);
    assert(!result.has_value());
}

int main() {
    std::cout << "Running undef tests (443 cases)..." << std::endl;
    int failed = 0;

    try { test_add_32_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: add_32_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_add_64_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: add_64_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_addhn_asimddiff_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: addhn_asimddiff_n_size_eq_11" << std::endl; failed++; }
    try { test_addhnb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: addhnb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_addhnt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: addhnt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_adds_32_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: adds_32_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_adds_64_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: adds_64_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_addv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: addv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_asr_z_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: asr_z_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_asr_z_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: asr_z_zw__size_eq_11" << std::endl; failed++; }
    try { test_cls_asimdmisc_r_size_eq_11(); } catch (...) { std::cerr << "FAIL: cls_asimdmisc_r_size_eq_11" << std::endl; failed++; }
    try { test_clz_asimdmisc_r_size_eq_11(); } catch (...) { std::cerr << "FAIL: clz_asimdmisc_r_size_eq_11" << std::endl; failed++; }
    try { test_cmpeq_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmpeq_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmpgt_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmpgt_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmpge_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmpge_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmphi_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmphi_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmphs_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmphs_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmplt_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmplt_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmple_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmple_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmplo_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmplo_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmpls_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmpls_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_cmpne_p_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: cmpne_p_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_decp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: decp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_dup_z_zi__tsz_eq_00000(); } catch (...) { std::cerr << "FAIL: dup_z_zi__tsz_eq_00000" << std::endl; failed++; }
    try { test_dupq_z_zi__tsz_eq_0000(); } catch (...) { std::cerr << "FAIL: dupq_z_zi__tsz_eq_0000" << std::endl; failed++; }
    try { test_fabd_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fabd_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fabs_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: fabs_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_fabs_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: fabs_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_facgt_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: facgt_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_facge_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: facge_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fadd_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fadd_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fadda_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fadda_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_faddp_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: faddp_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_faddqv_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: faddqv_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_faddv_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: faddv_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_famax_mz_zzw_2x2_size_eq_00(); } catch (...) { std::cerr << "FAIL: famax_mz_zzw_2x2_size_eq_00" << std::endl; failed++; }
    try { test_famax_mz_zzw_4x4_size_eq_00(); } catch (...) { std::cerr << "FAIL: famax_mz_zzw_4x4_size_eq_00" << std::endl; failed++; }
    try { test_famax_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: famax_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_famin_mz_zzw_2x2_size_eq_00(); } catch (...) { std::cerr << "FAIL: famin_mz_zzw_2x2_size_eq_00" << std::endl; failed++; }
    try { test_famin_mz_zzw_4x4_size_eq_00(); } catch (...) { std::cerr << "FAIL: famin_mz_zzw_4x4_size_eq_00" << std::endl; failed++; }
    try { test_famin_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: famin_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcadd_asimdsame2_c_size_eq_00(); } catch (...) { std::cerr << "FAIL: fcadd_asimdsame2_c_size_eq_00" << std::endl; failed++; }
    try { test_fcadd_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcadd_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmeq_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmeq_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmgt_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmgt_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmge_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmge_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmlt_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmlt_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmle_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmle_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmne_p_p_z0__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmne_p_p_z0__size_eq_00" << std::endl; failed++; }
    try { test_fcmeq_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmeq_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmgt_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmgt_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmge_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmge_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmne_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmne_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmuo_p_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmuo_p_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fcmla_asimdsame2_c_size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmla_asimdsame2_c_size_eq_00" << std::endl; failed++; }
    try { test_fcmla_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcmla_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fcpy_z_p_i__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcpy_z_p_i__size_eq_00" << std::endl; failed++; }
    try { test_fcvtzsn_z_mz2__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcvtzsn_z_mz2__size_eq_00" << std::endl; failed++; }
    try { test_fcvtzun_z_mz2__size_eq_00(); } catch (...) { std::cerr << "FAIL: fcvtzun_z_mz2__size_eq_00" << std::endl; failed++; }
    try { test_fdiv_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fdiv_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fdivr_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fdivr_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fdup_z_i__size_eq_00(); } catch (...) { std::cerr << "FAIL: fdup_z_i__size_eq_00" << std::endl; failed++; }
    try { test_fexpa_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fexpa_z_z__size_eq_00" << std::endl; failed++; }
    try { test_flogb_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: flogb_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_flogb_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: flogb_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_fmad_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmad_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fmax_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmax_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fmaxnm_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxnm_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fmaxnmp_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxnmp_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fmaxnmqv_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxnmqv_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fmaxnmv_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxnmv_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fmaxp_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxp_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fmaxqv_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxqv_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fmaxv_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmaxv_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fmin_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmin_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fminnm_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminnm_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fminnmp_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminnmp_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fminnmqv_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminnmqv_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fminnmv_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminnmv_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fminp_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminp_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fminqv_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminqv_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fminv_v_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: fminv_v_p_z__size_eq_00" << std::endl; failed++; }
    try { test_fmov_asimdimm_s_s_Q_eq_0(); } catch (...) { std::cerr << "FAIL: fmov_asimdimm_s_s_Q_eq_0" << std::endl; failed++; }
    try { test_fmsb_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmsb_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fmul_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmul_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fmulx_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fmulx_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_fneg_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: fneg_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_fneg_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: fneg_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_fnmad_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fnmad_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fnmla_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fnmla_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fnmls_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fnmls_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_fnmsb_z_p_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fnmsb_z_p_zzz__size_eq_00" << std::endl; failed++; }
    try { test_frecpe_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: frecpe_z_z__size_eq_00" << std::endl; failed++; }
    try { test_frecps_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: frecps_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_frecpx_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frecpx_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frecpx_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frecpx_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frintx_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintx_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frintx_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintx_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frinti_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frinti_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frinti_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frinti_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frinta_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frinta_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frinta_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frinta_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frintn_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintn_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frintn_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintn_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frintz_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintz_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frintz_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintz_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frintm_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintm_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frintm_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintm_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frintp_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintp_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_frintp_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: frintp_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_frsqrte_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: frsqrte_z_z__size_eq_00" << std::endl; failed++; }
    try { test_frsqrts_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: frsqrts_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_fsqrt_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: fsqrt_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_fsqrt_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: fsqrt_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_fsub_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fsub_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fsubr_z_p_zs__size_eq_00(); } catch (...) { std::cerr << "FAIL: fsubr_z_p_zs__size_eq_00" << std::endl; failed++; }
    try { test_fsubr_z_p_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: fsubr_z_p_zz__size_eq_00" << std::endl; failed++; }
    try { test_ftmad_z_zzi__size_eq_00(); } catch (...) { std::cerr << "FAIL: ftmad_z_zzi__size_eq_00" << std::endl; failed++; }
    try { test_ftsmul_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ftsmul_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ftssel_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ftssel_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_incp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: incp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u8_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u8_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u16_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u16_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u32_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u32_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1b_z_p_br_u64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1b_z_p_br_u64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1d_z_p_br_u64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_br_u64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1d_z_p_br_u128_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1d_z_p_br_u128_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u16_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u16_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u32_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u32_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1h_z_p_br_u64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1h_z_p_br_u64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rob_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rob_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rod_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rod_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1roh_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1roh_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1row_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1row_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rqb_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rqb_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rqd_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rqd_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rqh_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rqh_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1rqw_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1rqw_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s16_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s16_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s32_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s32_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sb_z_p_br_s64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sb_z_p_br_s64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sh_z_p_br_s32_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_br_s32_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sh_z_p_br_s64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sh_z_p_br_s64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1sw_z_p_br_s64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1sw_z_p_br_s64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u32_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u32_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u64_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u64_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld1w_z_p_br_u128_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld1w_z_p_br_u128_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld2b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld2b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld2d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld2d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld2h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld2h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld2q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld2q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld2w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld2w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld3b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld3b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld3d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld3d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld3h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld3h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld3q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld3q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld3w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld3w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld4b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld4b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld4d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld4d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld4h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld4h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld4q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld4q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ld4w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ld4w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ldclrp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldclrp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldclrpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldclrpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldclrpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldclrpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldclrpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldclrpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldclrpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldnt1b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ldnt1b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ldnt1d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ldnt1d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ldnt1h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ldnt1h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ldnt1w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: ldnt1w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_ldsetp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldsetp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldsetpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldsetpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldsetpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldsetpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_ldsetpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_ldsetpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: ldsetpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_lsl_z_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: lsl_z_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_lsl_z_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: lsl_z_zw__size_eq_11" << std::endl; failed++; }
    try { test_lsr_z_p_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: lsr_z_p_zw__size_eq_11" << std::endl; failed++; }
    try { test_lsr_z_zw__size_eq_11(); } catch (...) { std::cerr << "FAIL: lsr_z_zw__size_eq_11" << std::endl; failed++; }
    try { test_luti2_mz2_ztz_1_size_eq_11(); } catch (...) { std::cerr << "FAIL: luti2_mz2_ztz_1_size_eq_11" << std::endl; failed++; }
    try { test_luti2_mz4_ztz_1_size_eq_11(); } catch (...) { std::cerr << "FAIL: luti2_mz4_ztz_1_size_eq_11" << std::endl; failed++; }
    try { test_luti2_z_ztz__size_eq_11(); } catch (...) { std::cerr << "FAIL: luti2_z_ztz__size_eq_11" << std::endl; failed++; }
    try { test_luti4_mz2_ztz_1_size_eq_11(); } catch (...) { std::cerr << "FAIL: luti4_mz2_ztz_1_size_eq_11" << std::endl; failed++; }
    try { test_luti4_z_ztz__size_eq_11(); } catch (...) { std::cerr << "FAIL: luti4_z_ztz__size_eq_11" << std::endl; failed++; }
    try { test_mla_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: mla_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_mls_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: mls_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_mul_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: mul_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_pmul_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: pmul_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_prfb_i_p_br_s_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: prfb_i_p_br_s_Rm_eq_11111" << std::endl; failed++; }
    try { test_prfd_i_p_br_s_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: prfd_i_p_br_s_Rm_eq_11111" << std::endl; failed++; }
    try { test_prfh_i_p_br_s_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: prfh_i_p_br_s_Rm_eq_11111" << std::endl; failed++; }
    try { test_prfw_i_p_br_s_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: prfw_i_p_br_s_Rm_eq_11111" << std::endl; failed++; }
    try { test_raddhn_asimddiff_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: raddhn_asimddiff_n_size_eq_11" << std::endl; failed++; }
    try { test_raddhnb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: raddhnb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_raddhnt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: raddhnt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_rcwclrp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwclrp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwclrpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwclrpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsclrpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsclrpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsetp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsetp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsetpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsetpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwssetp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwssetp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwssetpl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwssetpl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsswpp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswpp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsswpp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswpp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwsswppl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwsswppl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwswpp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswpp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwswpp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswpp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwswppa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwswppa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwswppal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwswppal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_rcwswppl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_rcwswppl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: rcwswppl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_revb_z_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: revb_z_z_m_size_eq_00" << std::endl; failed++; }
    try { test_revb_z_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: revb_z_z_z_size_eq_00" << std::endl; failed++; }
    try { test_rsubhn_asimddiff_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: rsubhn_asimddiff_n_size_eq_11" << std::endl; failed++; }
    try { test_rsubhnb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: rsubhnb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_rsubhnt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: rsubhnt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_saba_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: saba_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_sabal_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: sabal_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_sabal_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sabal_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sabalb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sabalb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sabalt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sabalt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sabd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: sabd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_sabdl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: sabdl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_sabdlb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sabdlb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sabdlt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sabdlt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sadalp_asimdmisc_p_size_eq_11(); } catch (...) { std::cerr << "FAIL: sadalp_asimdmisc_p_size_eq_11" << std::endl; failed++; }
    try { test_sadalp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: sadalp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_saddl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: saddl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_saddlb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: saddlb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_saddlbt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: saddlbt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_saddlp_asimdmisc_p_size_eq_11(); } catch (...) { std::cerr << "FAIL: saddlp_asimdmisc_p_size_eq_11" << std::endl; failed++; }
    try { test_saddlt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: saddlt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_saddlv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: saddlv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_saddv_r_p_z__size_eq_11(); } catch (...) { std::cerr << "FAIL: saddv_r_p_z__size_eq_11" << std::endl; failed++; }
    try { test_saddw_asimddiff_w_size_eq_11(); } catch (...) { std::cerr << "FAIL: saddw_asimddiff_w_size_eq_11" << std::endl; failed++; }
    try { test_saddwb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: saddwb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_saddwt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: saddwt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_scvtf_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: scvtf_z_z__size_eq_00" << std::endl; failed++; }
    try { test_scvtflt_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: scvtflt_z_z__size_eq_00" << std::endl; failed++; }
    try { test_shadd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: shadd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_shll_asimdmisc_s_size_eq_11(); } catch (...) { std::cerr << "FAIL: shll_asimdmisc_s_size_eq_11" << std::endl; failed++; }
    try { test_shsub_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: shsub_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_smax_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: smax_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_smaxp_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: smaxp_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_smaxv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: smaxv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_smin_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: smin_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_sminp_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: sminp_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_sminv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: sminv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_smlal_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: smlal_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_smlalb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smlalb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_smlalt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smlalt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_smlsl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: smlsl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_smlslb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smlslb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_smlslt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smlslt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_smull_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: smull_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_smullb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smullb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_smullt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: smullt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sqdecp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdecp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlalb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlalb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlalbt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlalbt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlalt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlalt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlslb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlslb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlslbt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlslbt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmlslt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmlslt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmullb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmullb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sqdmullt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqdmullt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_sqincp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: sqincp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_sqrshr_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqrshr_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_sqrshrn_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqrshrn_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_sqrshrn_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqrshrn_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_sqrshru_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqrshru_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_sqrshrun_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqrshrun_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_sqrshrun_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqrshrun_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_sqshl_asisdshf_r_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqshl_asisdshf_r_immh_eq_0000" << std::endl; failed++; }
    try { test_sqshlu_asisdshf_r_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqshlu_asisdshf_r_immh_eq_0000" << std::endl; failed++; }
    try { test_sqshrn_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqshrn_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_sqshrn_z_mz2__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqshrn_z_mz2__tsize_eq_00" << std::endl; failed++; }
    try { test_sqshrun_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: sqshrun_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_sqshrun_z_mz2__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: sqshrun_z_mz2__tsize_eq_00" << std::endl; failed++; }
    try { test_sqxtn_asisdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: sqxtn_asisdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_sqxtn_asimdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: sqxtn_asimdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_sqxtun_asisdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: sqxtun_asisdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_sqxtun_asimdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: sqxtun_asimdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_srhadd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: srhadd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_ssubl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: ssubl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_ssublb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssublb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ssublbt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssublbt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ssublt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssublt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ssubltb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssubltb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ssubw_asimddiff_w_size_eq_11(); } catch (...) { std::cerr << "FAIL: ssubw_asimddiff_w_size_eq_11" << std::endl; failed++; }
    try { test_ssubwb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssubwb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ssubwt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: ssubwt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_st1b_z_p_br__Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1b_z_p_br__Rm_eq_11111" << std::endl; failed++; }
    try { test_st1d_z_p_br__Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1d_z_p_br__Rm_eq_11111" << std::endl; failed++; }
    try { test_st1d_z_p_br_u128_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1d_z_p_br_u128_Rm_eq_11111" << std::endl; failed++; }
    try { test_st1h_z_p_bi__size_eq_00(); } catch (...) { std::cerr << "FAIL: st1h_z_p_bi__size_eq_00" << std::endl; failed++; }
    try { test_st1h_z_p_br__size_eq_00(); } catch (...) { std::cerr << "FAIL: st1h_z_p_br__size_eq_00" << std::endl; failed++; }
    try { test_st1h_z_p_br__Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1h_z_p_br__Rm_eq_11111" << std::endl; failed++; }
    try { test_st1w_z_p_br__Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1w_z_p_br__Rm_eq_11111" << std::endl; failed++; }
    try { test_st1w_z_p_br_u128_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st1w_z_p_br_u128_Rm_eq_11111" << std::endl; failed++; }
    try { test_st2b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st2b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st2d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st2d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st2h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st2h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st2q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st2q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st2w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st2w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st3b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st3b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st3d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st3d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st3h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st3h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st3q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st3q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st3w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st3w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st4b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st4b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st4d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st4d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st4h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st4h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st4q_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st4q_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_st4w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: st4w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_stnt1b_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: stnt1b_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_stnt1d_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: stnt1d_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_stnt1h_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: stnt1h_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_stnt1w_z_p_br_contiguous_Rm_eq_11111(); } catch (...) { std::cerr << "FAIL: stnt1w_z_p_br_contiguous_Rm_eq_11111" << std::endl; failed++; }
    try { test_sub_32_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: sub_32_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_sub_64_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: sub_64_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_subhn_asimddiff_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: subhn_asimddiff_n_size_eq_11" << std::endl; failed++; }
    try { test_subhnb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: subhnb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_subhnt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: subhnt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_subs_32_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: subs_32_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_subs_64_addsub_shift_shift_eq_11(); } catch (...) { std::cerr << "FAIL: subs_64_addsub_shift_shift_eq_11" << std::endl; failed++; }
    try { test_sunpk_mz_z_2_size_eq_00(); } catch (...) { std::cerr << "FAIL: sunpk_mz_z_2_size_eq_00" << std::endl; failed++; }
    try { test_sunpk_mz_z_4_size_eq_00(); } catch (...) { std::cerr << "FAIL: sunpk_mz_z_4_size_eq_00" << std::endl; failed++; }
    try { test_sunpkhi_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: sunpkhi_z_z__size_eq_00" << std::endl; failed++; }
    try { test_sunpklo_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: sunpklo_z_z__size_eq_00" << std::endl; failed++; }
    try { test_swpp_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: swpp_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_swpp_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: swpp_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_swppa_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: swppa_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_swppa_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: swppa_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_swppal_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: swppal_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_swppal_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: swppal_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_swppl_128_memop_128_Rt_eq_11111(); } catch (...) { std::cerr << "FAIL: swppl_128_memop_128_Rt_eq_11111" << std::endl; failed++; }
    try { test_swppl_128_memop_128_Rt2_eq_11111(); } catch (...) { std::cerr << "FAIL: swppl_128_memop_128_Rt2_eq_11111" << std::endl; failed++; }
    try { test_sxtb_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: sxtb_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_sxtb_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: sxtb_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_uaba_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uaba_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_uabal_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: uabal_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_uabal_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uabal_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uabalb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uabalb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_uabalt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uabalt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_uabd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uabd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_uabdl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: uabdl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_uabdlb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uabdlb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uabdlt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uabdlt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uadalp_asimdmisc_p_size_eq_11(); } catch (...) { std::cerr << "FAIL: uadalp_asimdmisc_p_size_eq_11" << std::endl; failed++; }
    try { test_uadalp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: uadalp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_uaddl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: uaddl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_uaddlb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uaddlb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uaddlp_asimdmisc_p_size_eq_11(); } catch (...) { std::cerr << "FAIL: uaddlp_asimdmisc_p_size_eq_11" << std::endl; failed++; }
    try { test_uaddlt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uaddlt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uaddlv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uaddlv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_uaddw_asimddiff_w_size_eq_11(); } catch (...) { std::cerr << "FAIL: uaddw_asimddiff_w_size_eq_11" << std::endl; failed++; }
    try { test_uaddwb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uaddwb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uaddwt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: uaddwt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_ucvtf_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: ucvtf_z_z__size_eq_00" << std::endl; failed++; }
    try { test_ucvtflt_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: ucvtflt_z_z__size_eq_00" << std::endl; failed++; }
    try { test_uhadd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uhadd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_uhsub_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uhsub_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_umax_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: umax_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_umaxp_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: umaxp_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_umaxv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: umaxv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_umin_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: umin_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_uminp_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uminp_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_uminv_asimdall_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: uminv_asimdall_only_size_eq_11" << std::endl; failed++; }
    try { test_umlal_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: umlal_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_umlalb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umlalb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_umlalt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umlalt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_umlsl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: umlsl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_umlslb_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umlslb_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_umlslt_z_zzz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umlslt_z_zzz__size_eq_00" << std::endl; failed++; }
    try { test_umull_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: umull_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_umullb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umullb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_umullt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: umullt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uqdecp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: uqdecp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_uqincp_z_p_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: uqincp_z_p_z__size_eq_00" << std::endl; failed++; }
    try { test_uqrshr_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: uqrshr_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_uqrshrn_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: uqrshrn_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_uqrshrn_z_mz4__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: uqrshrn_z_mz4__tsize_eq_00" << std::endl; failed++; }
    try { test_uqshl_asisdshf_r_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: uqshl_asisdshf_r_immh_eq_0000" << std::endl; failed++; }
    try { test_uqshrn_asisdshf_n_immh_eq_0000(); } catch (...) { std::cerr << "FAIL: uqshrn_asisdshf_n_immh_eq_0000" << std::endl; failed++; }
    try { test_uqshrn_z_mz2__tsize_eq_00(); } catch (...) { std::cerr << "FAIL: uqshrn_z_mz2__tsize_eq_00" << std::endl; failed++; }
    try { test_uqxtn_asisdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: uqxtn_asisdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_uqxtn_asimdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: uqxtn_asimdmisc_n_size_eq_11" << std::endl; failed++; }
    try { test_urecpe_asimdmisc_r_sz_eq_1(); } catch (...) { std::cerr << "FAIL: urecpe_asimdmisc_r_sz_eq_1" << std::endl; failed++; }
    try { test_urhadd_asimdsame_only_size_eq_11(); } catch (...) { std::cerr << "FAIL: urhadd_asimdsame_only_size_eq_11" << std::endl; failed++; }
    try { test_ursqrte_asimdmisc_r_sz_eq_1(); } catch (...) { std::cerr << "FAIL: ursqrte_asimdmisc_r_sz_eq_1" << std::endl; failed++; }
    try { test_usubl_asimddiff_l_size_eq_11(); } catch (...) { std::cerr << "FAIL: usubl_asimddiff_l_size_eq_11" << std::endl; failed++; }
    try { test_usublb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: usublb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_usublt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: usublt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_usubw_asimddiff_w_size_eq_11(); } catch (...) { std::cerr << "FAIL: usubw_asimddiff_w_size_eq_11" << std::endl; failed++; }
    try { test_usubwb_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: usubwb_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_usubwt_z_zz__size_eq_00(); } catch (...) { std::cerr << "FAIL: usubwt_z_zz__size_eq_00" << std::endl; failed++; }
    try { test_uunpk_mz_z_2_size_eq_00(); } catch (...) { std::cerr << "FAIL: uunpk_mz_z_2_size_eq_00" << std::endl; failed++; }
    try { test_uunpk_mz_z_4_size_eq_00(); } catch (...) { std::cerr << "FAIL: uunpk_mz_z_4_size_eq_00" << std::endl; failed++; }
    try { test_uunpkhi_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: uunpkhi_z_z__size_eq_00" << std::endl; failed++; }
    try { test_uunpklo_z_z__size_eq_00(); } catch (...) { std::cerr << "FAIL: uunpklo_z_z__size_eq_00" << std::endl; failed++; }
    try { test_uxtb_z_p_z_m_size_eq_00(); } catch (...) { std::cerr << "FAIL: uxtb_z_p_z_m_size_eq_00" << std::endl; failed++; }
    try { test_uxtb_z_p_z_z_size_eq_00(); } catch (...) { std::cerr << "FAIL: uxtb_z_p_z_z_size_eq_00" << std::endl; failed++; }
    try { test_xtn_asimdmisc_n_size_eq_11(); } catch (...) { std::cerr << "FAIL: xtn_asimdmisc_n_size_eq_11" << std::endl; failed++; }

    std::cout << (443 - failed) << " / 443 passed" << std::endl;
    return failed;
}
