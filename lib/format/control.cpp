#include "format/control.hpp"

namespace veda64 {
namespace format {
namespace control {

// Encoding structures union
union ControlEncoding {
    uint32_t raw;
    // SYS: Associate physical address space
    // Encoding: APAS_SYS_CR_systeminstrs
    // Template: APAS  <Xt>
    struct ApasSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    ApasSysCrSysteminstrs apas_sys_cr_systeminstrs;

    // SYS: Address translate
    // Encoding: AT_SYS_CR_systeminstrs
    // Template: AT  <at_op>, <Xt>
    struct AtSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;  // partial: 100x
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    AtSysCrSysteminstrs at_sys_cr_systeminstrs;

    // : Authenticate instruction address, using key A
    // Encoding: AUTIA1716_HI_hints
    // Template: AUTIA1716
    struct Autia1716HiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    Autia1716HiHints autia1716hi_hints;

    // : Authenticate instruction address, using key A
    // Encoding: AUTIASP_HI_hints
    // Template: AUTIASP
    struct AutiaspHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b101 (0x5)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    AutiaspHiHints autiasp_hi_hints;

    // : Authenticate instruction address, using key A
    // Encoding: AUTIAZ_HI_hints
    // Template: AUTIAZ
    struct AutiazHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    AutiazHiHints autiaz_hi_hints;

    // : Authenticate instruction address, using key B
    // Encoding: AUTIB1716_HI_hints
    // Template: AUTIB1716
    struct Autib1716HiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    Autib1716HiHints autib1716hi_hints;

    // : Authenticate instruction address, using key B
    // Encoding: AUTIBSP_HI_hints
    // Template: AUTIBSP
    struct AutibspHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b111 (0x7)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    AutibspHiHints autibsp_hi_hints;

    // : Authenticate instruction address, using key B
    // Encoding: AUTIBZ_HI_hints
    // Template: AUTIBZ
    struct AutibzHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    AutibzHiHints autibz_hi_hints;

    // AXFLAG: Convert floating-point condition flags from Arm to external format
    // Encoding: AXFLAG_M_pstate
    // Template: AXFLAG
    struct AxflagMPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    AxflagMPstate axflag_mpstate;

    // B: Branch conditionally
    // Encoding: B_only_condbranch
    // Template: B.<cond>  <label>
    struct BOnlyCondbranch {
        uint32_t cond : 4;
        uint32_t o0 : 1;  // fixed: 0b0 (0x0)
        int32_t imm19 : 19;
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b010 (0x2)
    };

    BOnlyCondbranch bonly_condbranch;

    // B: Branch
    // Encoding: B_only_branch_imm
    // Template: B  <label>
    struct BOnlyBranchImm {
        int32_t imm26 : 26;
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 2;  // fixed: 0b00 (0x0)
        uint32_t op : 1;  // fixed: 0b0 (0x0)
    };

    BOnlyBranchImm bonly_branch_imm;

    // BC: Branch consistent conditionally
    // Encoding: BC_only_condbranch
    // Template: BC.<cond>  <label>
    struct BcOnlyCondbranch {
        uint32_t cond : 4;
        uint32_t o0 : 1;  // fixed: 0b1 (0x1)
        int32_t imm19 : 19;
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b010 (0x2)
    };

    BcOnlyCondbranch bc_only_condbranch;

    // BL: Branch with link
    // Encoding: BL_only_branch_imm
    // Template: BL  <label>
    struct BlOnlyBranchImm {
        int32_t imm26 : 26;
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 2;  // fixed: 0b00 (0x0)
        uint32_t op : 1;  // fixed: 0b1 (0x1)
    };

    BlOnlyBranchImm bl_only_branch_imm;

    // BLR: Branch with link to register
    // Encoding: BLR_64_branch_reg
    // Template: BLR  <Xn>
    struct Blr64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b00000 (0x0)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_4 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Blr64BranchReg blr64branch_reg;

    // : Branch with link to register, with pointer authentication
    // Encoding: BLRAA_64P_branch_reg
    // Template: BLRAA  <Xn>, <Xm|SP>
    struct Blraa64pBranchReg {
        uint32_t Rm : 5;
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Blraa64pBranchReg blraa64p_branch_reg;

    // : Branch with link to register, with pointer authentication
    // Encoding: BLRAAZ_64_branch_reg
    // Template: BLRAAZ  <Xn>
    struct Blraaz64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Blraaz64BranchReg blraaz64branch_reg;

    // : Branch with link to register, with pointer authentication
    // Encoding: BLRAB_64P_branch_reg
    // Template: BLRAB  <Xn>, <Xm|SP>
    struct Blrab64pBranchReg {
        uint32_t Rm : 5;
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Blrab64pBranchReg blrab64p_branch_reg;

    // : Branch with link to register, with pointer authentication
    // Encoding: BLRABZ_64_branch_reg
    // Template: BLRABZ  <Xn>
    struct Blrabz64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Blrabz64BranchReg blrabz64branch_reg;

    // BR: Branch to register
    // Encoding: BR_64_branch_reg
    // Template: BR  <Xn>
    struct Br64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b00000 (0x0)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_4 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Br64BranchReg br64branch_reg;

    // : Branch to register, with pointer authentication
    // Encoding: BRAA_64P_branch_reg
    // Template: BRAA  <Xn>, <Xm|SP>
    struct Braa64pBranchReg {
        uint32_t Rm : 5;
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Braa64pBranchReg braa64p_branch_reg;

    // : Branch to register, with pointer authentication
    // Encoding: BRAAZ_64_branch_reg
    // Template: BRAAZ  <Xn>
    struct Braaz64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Braaz64BranchReg braaz64branch_reg;

    // : Branch to register, with pointer authentication
    // Encoding: BRAB_64P_branch_reg
    // Template: BRAB  <Xn>, <Xm|SP>
    struct Brab64pBranchReg {
        uint32_t Rm : 5;
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Brab64pBranchReg brab64p_branch_reg;

    // : Branch to register, with pointer authentication
    // Encoding: BRABZ_64_branch_reg
    // Template: BRABZ  <Xn>
    struct Brabz64BranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Brabz64BranchReg brabz64branch_reg;

    // SYS: Branch record buffer
    // Encoding: BRB_SYS_CR_systeminstrs
    // Template: BRB  <brb_op>
    struct BrbSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    BrbSysCrSysteminstrs brb_sys_cr_systeminstrs;

    // BRK: Breakpoint instruction
    // Encoding: BRK_EX_exception
    // Template: BRK  #<imm>
    struct BrkExException {
        uint32_t LL : 2;  // fixed: 0b00 (0x0)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    BrkExException brk_ex_exception;

    // BTI: Branch target identification
    // Encoding: BTI_HB_hints
    // Template: BTI  {<targets>}
    struct BtiHbHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // partial: xx0
        uint32_t CRm : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    BtiHbHints bti_hb_hints;

    // : Compare bytes and branch
    // Encoding: CBBGT_8_regs
    // Template: CBBGT  <Wt>, <Wm>, <label>
    struct Cbbgt8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbgt8Regs cbbgt8regs;

    // : Compare bytes and branch
    // Encoding: CBBGE_8_regs
    // Template: CBBGE  <Wt>, <Wm>, <label>
    struct Cbbge8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbge8Regs cbbge8regs;

    // : Compare bytes and branch
    // Encoding: CBBHI_8_regs
    // Template: CBBHI  <Wt>, <Wm>, <label>
    struct Cbbhi8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbhi8Regs cbbhi8regs;

    // : Compare bytes and branch
    // Encoding: CBBHS_8_regs
    // Template: CBBHS  <Wt>, <Wm>, <label>
    struct Cbbhs8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbhs8Regs cbbhs8regs;

    // : Compare bytes and branch
    // Encoding: CBBEQ_8_regs
    // Template: CBBEQ  <Wt>, <Wm>, <label>
    struct Cbbeq8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbeq8Regs cbbeq8regs;

    // : Compare bytes and branch
    // Encoding: CBBNE_8_regs
    // Template: CBBNE  <Wt>, <Wm>, <label>
    struct Cbbne8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbbne8Regs cbbne8regs;

    // CBBGE: Compare signed less than or equal to bytes and branch
    // Encoding: CBBLE_CBBGE_8_regs
    // Template: CBBLE  <Wm>, <Wt>, <label>
    struct CbbleCbbge8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbbleCbbge8Regs cbble_cbbge8regs;

    // CBBHI: Compare unsigned lower than bytes and branch
    // Encoding: CBBLO_CBBHI_8_regs
    // Template: CBBLO  <Wm>, <Wt>, <label>
    struct CbbloCbbhi8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbbloCbbhi8Regs cbblo_cbbhi8regs;

    // CBBHS: Compare unsigned lower than or same as bytes and branch
    // Encoding: CBBLS_CBBHS_8_regs
    // Template: CBBLS  <Wm>, <Wt>, <label>
    struct CbblsCbbhs8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbblsCbbhs8Regs cbbls_cbbhs8regs;

    // CBBGT: Compare signed less than bytes and branch
    // Encoding: CBBLT_CBBGT_8_regs
    // Template: CBBLT  <Wm>, <Wt>, <label>
    struct CbbltCbbgt8Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbbltCbbgt8Regs cbblt_cbbgt8regs;

    // : Compare register with immediate and branch
    // Encoding: CBGT_32_imm
    // Template: CBGT  <Wt>, #<imm>, <label>
    struct Cbgt32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbgt32Imm cbgt32imm;

    // : Compare register with immediate and branch
    // Encoding: CBLT_32_imm
    // Template: CBLT  <Wt>, #<imm>, <label>
    struct Cblt32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cblt32Imm cblt32imm;

    // : Compare register with immediate and branch
    // Encoding: CBHI_32_imm
    // Template: CBHI  <Wt>, #<imm>, <label>
    struct Cbhi32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbhi32Imm cbhi32imm;

    // : Compare register with immediate and branch
    // Encoding: CBLO_32_imm
    // Template: CBLO  <Wt>, #<imm>, <label>
    struct Cblo32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cblo32Imm cblo32imm;

    // : Compare register with immediate and branch
    // Encoding: CBEQ_32_imm
    // Template: CBEQ  <Wt>, #<imm>, <label>
    struct Cbeq32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbeq32Imm cbeq32imm;

    // : Compare register with immediate and branch
    // Encoding: CBNE_32_imm
    // Template: CBNE  <Wt>, #<imm>, <label>
    struct Cbne32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbne32Imm cbne32imm;

    // : Compare register with immediate and branch
    // Encoding: CBGT_64_imm
    // Template: CBGT  <Xt>, #<imm>, <label>
    struct Cbgt64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbgt64Imm cbgt64imm;

    // : Compare register with immediate and branch
    // Encoding: CBLT_64_imm
    // Template: CBLT  <Xt>, #<imm>, <label>
    struct Cblt64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cblt64Imm cblt64imm;

    // : Compare register with immediate and branch
    // Encoding: CBHI_64_imm
    // Template: CBHI  <Xt>, #<imm>, <label>
    struct Cbhi64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbhi64Imm cbhi64imm;

    // : Compare register with immediate and branch
    // Encoding: CBLO_64_imm
    // Template: CBLO  <Xt>, #<imm>, <label>
    struct Cblo64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cblo64Imm cblo64imm;

    // : Compare register with immediate and branch
    // Encoding: CBEQ_64_imm
    // Template: CBEQ  <Xt>, #<imm>, <label>
    struct Cbeq64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbeq64Imm cbeq64imm;

    // : Compare register with immediate and branch
    // Encoding: CBNE_64_imm
    // Template: CBNE  <Xt>, #<imm>, <label>
    struct Cbne64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbne64Imm cbne64imm;

    // : Compare registers and branch
    // Encoding: CBGT_32_regs
    // Template: CBGT  <Wt>, <Wm>, <label>
    struct Cbgt32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbgt32Regs cbgt32regs;

    // : Compare registers and branch
    // Encoding: CBGE_32_regs
    // Template: CBGE  <Wt>, <Wm>, <label>
    struct Cbge32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbge32Regs cbge32regs;

    // : Compare registers and branch
    // Encoding: CBHI_32_regs
    // Template: CBHI  <Wt>, <Wm>, <label>
    struct Cbhi32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbhi32Regs cbhi32regs;

    // : Compare registers and branch
    // Encoding: CBHS_32_regs
    // Template: CBHS  <Wt>, <Wm>, <label>
    struct Cbhs32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbhs32Regs cbhs32regs;

    // : Compare registers and branch
    // Encoding: CBEQ_32_regs
    // Template: CBEQ  <Wt>, <Wm>, <label>
    struct Cbeq32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbeq32Regs cbeq32regs;

    // : Compare registers and branch
    // Encoding: CBNE_32_regs
    // Template: CBNE  <Wt>, <Wm>, <label>
    struct Cbne32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbne32Regs cbne32regs;

    // : Compare registers and branch
    // Encoding: CBGT_64_regs
    // Template: CBGT  <Xt>, <Xm>, <label>
    struct Cbgt64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbgt64Regs cbgt64regs;

    // : Compare registers and branch
    // Encoding: CBGE_64_regs
    // Template: CBGE  <Xt>, <Xm>, <label>
    struct Cbge64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbge64Regs cbge64regs;

    // : Compare registers and branch
    // Encoding: CBHI_64_regs
    // Template: CBHI  <Xt>, <Xm>, <label>
    struct Cbhi64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbhi64Regs cbhi64regs;

    // : Compare registers and branch
    // Encoding: CBHS_64_regs
    // Template: CBHS  <Xt>, <Xm>, <label>
    struct Cbhs64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbhs64Regs cbhs64regs;

    // : Compare registers and branch
    // Encoding: CBEQ_64_regs
    // Template: CBEQ  <Xt>, <Xm>, <label>
    struct Cbeq64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbeq64Regs cbeq64regs;

    // : Compare registers and branch
    // Encoding: CBNE_64_regs
    // Template: CBNE  <Xt>, <Xm>, <label>
    struct Cbne64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbne64Regs cbne64regs;

    // CBGT: Compare signed greater than or equal to immediate and branch
    // Encoding: CBGE_CBGT_32_imm
    // Template: CBGE  <Wt>, #<immp1>, <label>
    struct CbgeCbgt32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbgeCbgt32Imm cbge_cbgt32imm;

    // CBGT: Compare signed greater than or equal to immediate and branch
    // Encoding: CBGE_CBGT_64_imm
    // Template: CBGE  <Xt>, #<immp1>, <label>
    struct CbgeCbgt64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbgeCbgt64Imm cbge_cbgt64imm;

    // : Compare halfwords and branch
    // Encoding: CBHGT_16_regs
    // Template: CBHGT  <Wt>, <Wm>, <label>
    struct Cbhgt16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbhgt16Regs cbhgt16regs;

    // : Compare halfwords and branch
    // Encoding: CBHGE_16_regs
    // Template: CBHGE  <Wt>, <Wm>, <label>
    struct Cbhge16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbhge16Regs cbhge16regs;

    // : Compare halfwords and branch
    // Encoding: CBHHI_16_regs
    // Template: CBHHI  <Wt>, <Wm>, <label>
    struct Cbhhi16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbhhi16Regs cbhhi16regs;

    // : Compare halfwords and branch
    // Encoding: CBHHS_16_regs
    // Template: CBHHS  <Wt>, <Wm>, <label>
    struct Cbhhs16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbhhs16Regs cbhhs16regs;

    // : Compare halfwords and branch
    // Encoding: CBHEQ_16_regs
    // Template: CBHEQ  <Wt>, <Wm>, <label>
    struct Cbheq16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b110 (0x6)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbheq16Regs cbheq16regs;

    // : Compare halfwords and branch
    // Encoding: CBHNE_16_regs
    // Template: CBHNE  <Wt>, <Wm>, <label>
    struct Cbhne16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b111 (0x7)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01110100 (0x74)
    };

    Cbhne16Regs cbhne16regs;

    // CBHGE: Compare signed less than or equal to halfwords and branch
    // Encoding: CBHLE_CBHGE_16_regs
    // Template: CBHLE  <Wm>, <Wt>, <label>
    struct CbhleCbhge16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbhleCbhge16Regs cbhle_cbhge16regs;

    // CBHHI: Compare unsigned lower than halfwords and branch
    // Encoding: CBHLO_CBHHI_16_regs
    // Template: CBHLO  <Wm>, <Wt>, <label>
    struct CbhloCbhhi16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbhloCbhhi16Regs cbhlo_cbhhi16regs;

    // CBHHS: Compare unsigned lower than or same as halfwords and branch
    // Encoding: CBHLS_CBHHS_16_regs
    // Template: CBHLS  <Wm>, <Wt>, <label>
    struct CbhlsCbhhs16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbhlsCbhhs16Regs cbhls_cbhhs16regs;

    // CBHGT: Compare signed less than halfwords and branch
    // Encoding: CBHLT_CBHGT_16_regs
    // Template: CBHLT  <Wm>, <Wt>, <label>
    struct CbhltCbhgt16Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t H : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b011 (0x3)
    };

    CbhltCbhgt16Regs cbhlt_cbhgt16regs;

    // CBHI: Compare unsigned higher than or same as immediate and branch
    // Encoding: CBHS_CBHI_32_imm
    // Template: CBHS  <Wt>, #<immp1>, <label>
    struct CbhsCbhi32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbhsCbhi32Imm cbhs_cbhi32imm;

    // CBHI: Compare unsigned higher than or same as immediate and branch
    // Encoding: CBHS_CBHI_64_imm
    // Template: CBHS  <Xt>, #<immp1>, <label>
    struct CbhsCbhi64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbhsCbhi64Imm cbhs_cbhi64imm;

    // CBLT: Compare signed less than or equal to immediate and branch
    // Encoding: CBLE_CBLT_32_imm
    // Template: CBLE  <Wt>, #<imms1>, <label>
    struct CbleCblt32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbleCblt32Imm cble_cblt32imm;

    // CBLT: Compare signed less than or equal to immediate and branch
    // Encoding: CBLE_CBLT_64_imm
    // Template: CBLE  <Xt>, #<imms1>, <label>
    struct CbleCblt64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbleCblt64Imm cble_cblt64imm;

    // CBGE: Compare signed less than or equal to register and branch
    // Encoding: CBLE_CBGE_32_regs
    // Template: CBLE  <Wm>, <Wt>, <label>
    struct CbleCbge32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbleCbge32Regs cble_cbge32regs;

    // CBGE: Compare signed less than or equal to register and branch
    // Encoding: CBLE_CBGE_64_regs
    // Template: CBLE  <Xm>, <Xt>, <label>
    struct CbleCbge64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbleCbge64Regs cble_cbge64regs;

    // CBHI: Compare unsigned lower than register and branch
    // Encoding: CBLO_CBHI_32_regs
    // Template: CBLO  <Wm>, <Wt>, <label>
    struct CbloCbhi32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbloCbhi32Regs cblo_cbhi32regs;

    // CBHI: Compare unsigned lower than register and branch
    // Encoding: CBLO_CBHI_64_regs
    // Template: CBLO  <Xm>, <Xt>, <label>
    struct CbloCbhi64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbloCbhi64Regs cblo_cbhi64regs;

    // CBLO: Compare unsigned lower than or same as immediate and branch
    // Encoding: CBLS_CBLO_32_imm
    // Template: CBLS  <Wt>, #<imms1>, <label>
    struct CblsCblo32Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CblsCblo32Imm cbls_cblo32imm;

    // CBLO: Compare unsigned lower than or same as immediate and branch
    // Encoding: CBLS_CBLO_64_imm
    // Template: CBLS  <Xt>, #<imms1>, <label>
    struct CblsCblo64Imm {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t imm6 : 6;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110101 (0x75)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CblsCblo64Imm cbls_cblo64imm;

    // CBHS: Compare unsigned lower than or same as register and branch
    // Encoding: CBLS_CBHS_32_regs
    // Template: CBLS  <Wm>, <Wt>, <label>
    struct CblsCbhs32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CblsCbhs32Regs cbls_cbhs32regs;

    // CBHS: Compare unsigned lower than or same as register and branch
    // Encoding: CBLS_CBHS_64_regs
    // Template: CBLS  <Xm>, <Xt>, <label>
    struct CblsCbhs64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CblsCbhs64Regs cbls_cbhs64regs;

    // CBGT: Compare signed less than register and branch
    // Encoding: CBLT_CBGT_32_regs
    // Template: CBLT  <Wm>, <Wt>, <label>
    struct CbltCbgt32Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    CbltCbgt32Regs cblt_cbgt32regs;

    // CBGT: Compare signed less than register and branch
    // Encoding: CBLT_CBGT_64_regs
    // Template: CBLT  <Xm>, <Xt>, <label>
    struct CbltCbgt64Regs {
        uint32_t Rt : 5;
        int32_t imm9 : 9;
        uint32_t _unnamed_1 : 2;  // fixed: 0b00 (0x0)
        uint32_t Rm : 5;
        uint32_t cc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1110100 (0x74)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    CbltCbgt64Regs cblt_cbgt64regs;

    // CBNZ: Compare and branch on nonzero
    // Encoding: CBNZ_32_compbranch
    // Template: CBNZ  <Wt>, <label>
    struct Cbnz32Compbranch {
        uint32_t Rt : 5;
        int32_t imm19 : 19;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b011010 (0x1A)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbnz32Compbranch cbnz32compbranch;

    // CBNZ: Compare and branch on nonzero
    // Encoding: CBNZ_64_compbranch
    // Template: CBNZ  <Xt>, <label>
    struct Cbnz64Compbranch {
        uint32_t Rt : 5;
        int32_t imm19 : 19;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_0 : 6;  // fixed: 0b011010 (0x1A)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbnz64Compbranch cbnz64compbranch;

    // CBZ: Compare and branch on zero
    // Encoding: CBZ_32_compbranch
    // Template: CBZ  <Wt>, <label>
    struct Cbz32Compbranch {
        uint32_t Rt : 5;
        int32_t imm19 : 19;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b011010 (0x1A)
        uint32_t sf : 1;  // fixed: 0b0 (0x0)
    };

    Cbz32Compbranch cbz32compbranch;

    // CBZ: Compare and branch on zero
    // Encoding: CBZ_64_compbranch
    // Template: CBZ  <Xt>, <label>
    struct Cbz64Compbranch {
        uint32_t Rt : 5;
        int32_t imm19 : 19;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 6;  // fixed: 0b011010 (0x1A)
        uint32_t sf : 1;  // fixed: 0b1 (0x1)
    };

    Cbz64Compbranch cbz64compbranch;

    // CFINV: Invert carry flag
    // Encoding: CFINV_M_pstate
    // Template: CFINV
    struct CfinvMPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    CfinvMPstate cfinv_mpstate;

    // SYS: Control flow prediction restriction by context
    // Encoding: CFP_SYS_CR_systeminstrs
    // Template: CFP  RCTX, <Xt>
    struct CfpSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    CfpSysCrSysteminstrs cfp_sys_cr_systeminstrs;

    // CHKFEAT: Check feature status
    // Encoding: CHKFEAT_HF_hints
    // Template: CHKFEAT  X16
    struct ChkfeatHfHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    ChkfeatHfHints chkfeat_hf_hints;

    // CLRBHB: Clear branch history
    // Encoding: CLRBHB_HI_hints
    // Template: CLRBHB
    struct ClrbhbHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    ClrbhbHiHints clrbhb_hi_hints;

    // CLREX: Clear exclusive
    // Encoding: CLREX_BN_barriers
    // Template: CLREX  {#<imm>}
    struct ClrexBnBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    ClrexBnBarriers clrex_bn_barriers;

    // SYS: Clear other speculative prediction restriction by context
    // Encoding: COSP_SYS_CR_systeminstrs
    // Template: COSP  RCTX, <Xt>
    struct CospSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    CospSysCrSysteminstrs cosp_sys_cr_systeminstrs;

    // SYS: Cache prefetch prediction restriction by context
    // Encoding: CPP_SYS_CR_systeminstrs
    // Template: CPP  RCTX, <Xt>
    struct CppSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b111 (0x7)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    CppSysCrSysteminstrs cpp_sys_cr_systeminstrs;

    // CSDB: Consumption of speculative data barrier
    // Encoding: CSDB_HI_hints
    // Template: CSDB
    struct CsdbHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    CsdbHiHints csdb_hi_hints;

    // SYS: Data cache operation
    // Encoding: DC_SYS_CR_systeminstrs
    // Template: DC  <dc_op>, <Xt>
    struct DcSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DcSysCrSysteminstrs dc_sys_cr_systeminstrs;

    // DCPS1: Debug change PE state to EL1
    // Encoding: DCPS1_DC_exception
    // Template: DCPS1  {#<imm>}
    struct Dcps1DcException {
        uint32_t LL : 2;  // fixed: 0b01 (0x1)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Dcps1DcException dcps1dc_exception;

    // DCPS2: Debug change PE state to EL2
    // Encoding: DCPS2_DC_exception
    // Template: DCPS2  {#<imm>}
    struct Dcps2DcException {
        uint32_t LL : 2;  // fixed: 0b10 (0x2)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Dcps2DcException dcps2dc_exception;

    // DCPS3: Debug change PE state to EL3
    // Encoding: DCPS3_DC_exception
    // Template: DCPS3  {#<imm>}
    struct Dcps3DcException {
        uint32_t LL : 2;  // fixed: 0b11 (0x3)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Dcps3DcException dcps3dc_exception;

    // DGH: Data gathering hint
    // Encoding: DGH_HI_hints
    // Template: DGH
    struct DghHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DghHiHints dgh_hi_hints;

    // DMB: Data memory barrier
    // Encoding: DMB_BO_barriers
    // Template: DMB  (<option>|#<imm>)
    struct DmbBoBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b01 (0x1)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DmbBoBarriers dmb_bo_barriers;

    // DRPS: Debug restore PE state
    // Encoding: DRPS_64E_branch_reg
    // Template: DRPS
    struct Drps64eBranchReg {
        uint32_t op4 : 5;  // fixed: 0b00000 (0x0)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op3 : 6;  // fixed: 0b000000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Drps64eBranchReg drps64e_branch_reg;

    // DSB: Data synchronization barrier
    // Encoding: DSB_BO_barriers
    // Template: DSB  (<option>|#<imm>)
    struct DsbBoBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DsbBoBarriers dsb_bo_barriers;

    // DSB: Data synchronization barrier
    // Encoding: DSB_BOn_barriers
    // Template: DSB  <option>nXS
    struct DsbBonBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_3 : 2;  // fixed: 0b10 (0x2)
        uint32_t imm2 : 2;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DsbBonBarriers dsb_bon_barriers;

    // SYS: Data value prediction restriction by context
    // Encoding: DVP_SYS_CR_systeminstrs
    // Template: DVP  RCTX, <Xt>
    struct DvpSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b101 (0x5)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    DvpSysCrSysteminstrs dvp_sys_cr_systeminstrs;

    // ERET: Exception return
    // Encoding: ERET_64E_branch_reg
    // Template: ERET
    struct Eret64eBranchReg {
        uint32_t op4 : 5;  // fixed: 0b00000 (0x0)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Eret64eBranchReg eret64e_branch_reg;

    // : Exception return, with pointer authentication
    // Encoding: ERETAA_64E_branch_reg
    // Template: ERETAA
    struct Eretaa64eBranchReg {
        uint32_t op4 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Eretaa64eBranchReg eretaa64e_branch_reg;

    // : Exception return, with pointer authentication
    // Encoding: ERETAB_64E_branch_reg
    // Template: ERETAB
    struct Eretab64eBranchReg {
        uint32_t op4 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Eretab64eBranchReg eretab64e_branch_reg;

    // ESB: Error synchronization barrier
    // Encoding: ESB_HI_hints
    // Template: ESB
    struct EsbHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    EsbHiHints esb_hi_hints;

    // GCSB: Guarded Control Stack barrier
    // Encoding: GCSB_HD_hints
    // Template: GCSB  DSYNC
    struct GcsbHdHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcsbHdHints gcsb_hd_hints;

    // SYS: Guarded Control Stack pop and compare exception return record
    // Encoding: GCSPOPCX_SYS_CR_systeminstrs
    // Template: GCSPOPCX
    struct GcspopcxSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b101 (0x5)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcspopcxSysCrSysteminstrs gcspopcx_sys_cr_systeminstrs;

    // SYSL: Guarded Control Stack pop
    // Encoding: GCSPOPM_SYSL_RC_systeminstrs
    // Template: GCSPOPM    {<Xt>}
    struct GcspopmSyslRcSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcspopmSyslRcSysteminstrs gcspopm_sysl_rc_systeminstrs;

    // SYS: Guarded Control Stack pop exception return record
    // Encoding: GCSPOPX_SYS_CR_systeminstrs
    // Template: GCSPOPX
    struct GcspopxSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b110 (0x6)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcspopxSysCrSysteminstrs gcspopx_sys_cr_systeminstrs;

    // SYS: Guarded Control Stack push
    // Encoding: GCSPUSHM_SYS_CR_systeminstrs
    // Template: GCSPUSHM  <Xt>
    struct GcspushmSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcspushmSysCrSysteminstrs gcspushm_sys_cr_systeminstrs;

    // SYS: Guarded Control Stack push exception return record
    // Encoding: GCSPUSHX_SYS_CR_systeminstrs
    // Template: GCSPUSHX
    struct GcspushxSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GcspushxSysCrSysteminstrs gcspushx_sys_cr_systeminstrs;

    // SYS: Guarded Control Stack switch stack 1
    // Encoding: GCSSS1_SYS_CR_systeminstrs
    // Template: GCSSS1  <Xt>
    struct Gcsss1SysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Gcsss1SysCrSysteminstrs gcsss1sys_cr_systeminstrs;

    // SYSL: Guarded Control Stack switch stack 2
    // Encoding: GCSSS2_SYSL_RC_systeminstrs
    // Template: GCSSS2  <Xt>
    struct Gcsss2SyslRcSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // fixed: 0b0111 (0x7)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Gcsss2SyslRcSysteminstrs gcsss2sysl_rc_systeminstrs;

    // SYS: Generic Interrupt Controller
    // Encoding: GIC_SYS_CR_systeminstrs
    // Template: GIC  <gic_op>{, <Xt>}
    struct GicSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;  // partial: IN {0001, 0010}
        uint32_t CRn : 4;  // fixed: 0b1100 (0xC)
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GicSysCrSysteminstrs gic_sys_cr_systeminstrs;

    // SYSL: Generic Interrupt Controller with result
    // Encoding: GICR_SYSL_RC_systeminstrs
    // Template: GICR  <Xt>, <gicr_op>
    struct GicrSyslRcSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t CRn : 4;  // fixed: 0b1100 (0xC)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GicrSyslRcSysteminstrs gicr_sysl_rc_systeminstrs;

    // SYS: Generic Interrupt Controller synchronization barrier
    // Encoding: GSB_SYS_CR_systeminstrs
    // Template: GSB  <gsb_op>
    struct GsbSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t CRn : 4;  // fixed: 0b1100 (0xC)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    GsbSysCrSysteminstrs gsb_sys_cr_systeminstrs;

    // HINT: Hint instruction
    // Encoding: HINT_HM_hints
    // Template: HINT  #<imm>
    struct HintHmHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    HintHmHints hint_hm_hints;

    // HLT: Halt instruction
    // Encoding: HLT_EX_exception
    // Template: HLT  #<imm>
    struct HltExException {
        uint32_t LL : 2;  // fixed: 0b00 (0x0)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b010 (0x2)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    HltExException hlt_ex_exception;

    // HVC: Hypervisor call
    // Encoding: HVC_EX_exception
    // Template: HVC  #<imm>
    struct HvcExException {
        uint32_t LL : 2;  // fixed: 0b10 (0x2)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    HvcExException hvc_ex_exception;

    // SYS: Instruction cache operation
    // Encoding: IC_SYS_CR_systeminstrs
    // Template: IC  <ic_op>{, <Xt>}
    struct IcSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    IcSysCrSysteminstrs ic_sys_cr_systeminstrs;

    // ISB: Instruction synchronization barrier
    // Encoding: ISB_BI_barriers
    // Template: ISB  {<option>|#<imm>}
    struct IsbBiBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    IsbBiBarriers isb_bi_barriers;

    // SYS: MPAM lookaside buffer invalidate
    // Encoding: MLBI_SYS_CR_systeminstrs
    // Template: MLBI  <mlbi_op>{, <Xt>}
    struct MlbiSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // partial: 1xx
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b100 (0x4)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MlbiSysCrSysteminstrs mlbi_sys_cr_systeminstrs;

    // MRRS: Move System register to two adjacent general-purpose registers
    // Encoding: MRRS_RS_systemmovepr
    // Template: MRRS  <Xt>, <Xt+1>, (<systemreg>|S<op0>_<op1>_<Cn>_<Cm>_<op2>)
    struct MrrsRsSystemmovepr {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t o0 : 1;
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MrrsRsSystemmovepr mrrs_rs_systemmovepr;

    // MRS: Move System register to general-purpose register
    // Encoding: MRS_RS_systemmove
    // Template: MRS  <Xt>, (<systemreg>|S<op0>_<op1>_<Cn>_<Cm>_<op2>)
    struct MrsRsSystemmove {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t o0 : 1;
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MrsRsSystemmove mrs_rs_systemmove;

    // MSR: Move immediate value to special register
    // Encoding: MSR_SI_pstate
    // Template: MSR  <pstatefield>, #<imm>
    struct MsrSiPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MsrSiPstate msr_si_pstate;

    // MSR: Move general-purpose register to System register
    // Encoding: MSR_SR_systemmove
    // Template: MSR  (<systemreg>|S<op0>_<op1>_<Cn>_<Cm>_<op2>), <Xt>
    struct MsrSrSystemmove {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t o0 : 1;
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MsrSrSystemmove msr_sr_systemmove;

    // MSRR: Move two adjacent general-purpose registers to System register
    // Encoding: MSRR_SR_systemmovepr
    // Template: MSRR  (<systemreg>|S<op0>_<op1>_<Cn>_<Cm>_<op2>), <Xt>, <Xt+1>
    struct MsrrSrSystemmovepr {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t o0 : 1;
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    MsrrSrSystemmovepr msrr_sr_systemmovepr;

    // NOP: No operation
    // Encoding: NOP_HI_hints
    // Template: NOP
    struct NopHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    NopHiHints nop_hi_hints;

    // : Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIA1716_HI_hints
    // Template: PACIA1716
    struct Pacia1716HiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    Pacia1716HiHints pacia1716hi_hints;

    // : Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIASP_HI_hints
    // Template: PACIASP
    struct PaciaspHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    PaciaspHiHints paciasp_hi_hints;

    // : Pointer Authentication Code for instruction address, using key A
    // Encoding: PACIAZ_HI_hints
    // Template: PACIAZ
    struct PaciazHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    PaciazHiHints paciaz_hi_hints;

    // : Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIB1716_HI_hints
    // Template: PACIB1716
    struct Pacib1716HiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0001 (0x1)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    Pacib1716HiHints pacib1716hi_hints;

    // : Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIBSP_HI_hints
    // Template: PACIBSP
    struct PacibspHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    PacibspHiHints pacibsp_hi_hints;

    // : Pointer Authentication Code for instruction address, using key B
    // Encoding: PACIBZ_HI_hints
    // Template: PACIBZ
    struct PacibzHiHints {
        uint32_t _unnamed_1 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0011 (0x3)
        uint32_t _unnamed_0 : 20;  // fixed: 0b11010101000000110010 (0xD5032)
    };

    PacibzHiHints pacibz_hi_hints;

    // PACM: Pointer authentication modifier
    // Encoding: PACM_HI_hints
    // Template: PACM
    struct PacmHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b111 (0x7)
        uint32_t CRm : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    PacmHiHints pacm_hi_hints;

    // PSB: Profiling synchronization barrier
    // Encoding: PSB_HC_hints
    // Template: PSB  CSYNC
    struct PsbHcHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    PsbHcHints psb_hc_hints;

    // DSB: Physical speculative store bypass barrier
    // Encoding: PSSBB_DSB_BO_barriers
    // Template: PSSBB
    struct PssbbDsbBoBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    PssbbDsbBoBarriers pssbb_dsb_bo_barriers;

    // RET: Return from subroutine
    // Encoding: RET_64R_branch_reg
    // Template: RET  {<Xn>}
    struct Ret64rBranchReg {
        uint32_t Rm : 5;  // fixed: 0b00000 (0x0)
        uint32_t Rn : 5;
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_4 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_3 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    Ret64rBranchReg ret64r_branch_reg;

    // : Return from subroutine, with pointer authentication
    // Encoding: RETAA_64E_branch_reg
    // Template: RETAA
    struct Retaa64eBranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Retaa64eBranchReg retaa64e_branch_reg;

    // : Return from subroutine, with pointer authentication
    // Encoding: RETAB_64E_branch_reg
    // Template: RETAB
    struct Retab64eBranchReg {
        uint32_t Rm : 5;  // fixed: 0b11111 (0x1F)
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t A : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0000 (0x0)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op : 2;  // fixed: 0b10 (0x2)
        uint32_t _unnamed_1 : 1;  // fixed: 0b0 (0x0)
        uint32_t Z : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Retab64eBranchReg retab64e_branch_reg;

    // : Return from subroutine, with enhanced pointer authentication using an immediate offset
    // Encoding: RETAASPPC_only_miscbranch
    // Template: RETAASPPC  <label>
    struct RetaasppcOnlyMiscbranch {
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01010101 (0x55)
    };

    RetaasppcOnlyMiscbranch retaasppc_only_miscbranch;

    // : Return from subroutine, with enhanced pointer authentication using an immediate offset
    // Encoding: RETABSPPC_only_miscbranch
    // Template: RETABSPPC  <label>
    struct RetabsppcOnlyMiscbranch {
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b001 (0x1)
        uint32_t _unnamed_0 : 8;  // fixed: 0b01010101 (0x55)
    };

    RetabsppcOnlyMiscbranch retabsppc_only_miscbranch;

    // : Return from subroutine, with enhanced pointer authentication using a register
    // Encoding: RETAASPPCR_64M_branch_reg
    // Template: RETAASPPCR  <Xm>
    struct Retaasppcr64mBranchReg {
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_1 : 5;  // fixed: 0b00001 (0x1)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Retaasppcr64mBranchReg retaasppcr64m_branch_reg;

    // : Return from subroutine, with enhanced pointer authentication using a register
    // Encoding: RETABSPPCR_64M_branch_reg
    // Template: RETABSPPCR  <Xm>
    struct Retabsppcr64mBranchReg {
        uint32_t Rm : 5;  // partial: != 11111
        uint32_t Rn : 5;  // fixed: 0b11111 (0x1F)
        uint32_t M : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 5;  // fixed: 0b00001 (0x1)
        uint32_t op2 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_0 : 7;  // fixed: 0b1101011 (0x6B)
    };

    Retabsppcr64mBranchReg retabsppcr64m_branch_reg;

    // SB: Speculation barrier
    // Encoding: SB_only_barriers
    // Template: SB
    struct SbOnlyBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b11 (0x3)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SbOnlyBarriers sb_only_barriers;

    // SEV: Send event
    // Encoding: SEV_HI_hints
    // Template: SEV
    struct SevHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SevHiHints sev_hi_hints;

    // SEVL: Send event local
    // Encoding: SEVL_HI_hints
    // Template: SEVL
    struct SevlHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b101 (0x5)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SevlHiHints sevl_hi_hints;

    // SHUH: Shared update hint
    // Encoding: SHUH_HI_hints
    // Template: SHUH  {PH}
    struct ShuhHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // partial: 01x
        uint32_t CRm : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    ShuhHiHints shuh_hi_hints;

    // SMC: Secure monitor call
    // Encoding: SMC_EX_exception
    // Template: SMC  #<imm>
    struct SmcExException {
        uint32_t LL : 2;  // fixed: 0b11 (0x3)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SmcExException smc_ex_exception;

    // MSR: Enables access to Streaming SVE mode and SME architectural state
    // Encoding: SMSTART_MSR_SI_pstate
    // Template: SMSTART  {<option>}
    struct SmstartMsrSiPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // partial: 0xx1
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SmstartMsrSiPstate smstart_msr_si_pstate;

    // MSR: Disables access to Streaming SVE mode and SME architectural state
    // Encoding: SMSTOP_MSR_SI_pstate
    // Template: SMSTOP  {<option>}
    struct SmstopMsrSiPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // partial: 0xx0
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SmstopMsrSiPstate smstop_msr_si_pstate;

    // DSB: Speculative store bypass barrier
    // Encoding: SSBB_DSB_BO_barriers
    // Template: SSBB
    struct SsbbDsbBoBarriers {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t opc : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SsbbDsbBoBarriers ssbb_dsb_bo_barriers;

    // STCPH: Store concurrent priority hint
    // Encoding: STCPH_HI_hints
    // Template: STCPH
    struct StcphHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b100 (0x4)
        uint32_t CRm : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    StcphHiHints stcph_hi_hints;

    // STSHH: Store shared hint
    // Encoding: STSHH_HI_hints
    // Template: STSHH  <policy>
    struct StshhHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // partial: 00x
        uint32_t CRm : 4;  // fixed: 0b0110 (0x6)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    StshhHiHints stshh_hi_hints;

    // SVC: Supervisor call
    // Encoding: SVC_EX_exception
    // Template: SVC  #<imm>
    struct SvcExException {
        uint32_t LL : 2;  // fixed: 0b01 (0x1)
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t imm16 : 16;
        uint32_t opc : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 2;  // fixed: 0b00 (0x0)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SvcExException svc_ex_exception;

    // SYS: System instruction
    // Encoding: SYS_CR_systeminstrs
    // Template: SYS  #<op1>, <Cn>, <Cm>, #<op2>{, <Xt>}
    struct SysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SysCrSysteminstrs sys_cr_systeminstrs;

    // SYSL: System instruction with result
    // Encoding: SYSL_RC_systeminstrs
    // Template: SYSL  <Xt>, #<op1>, <Cn>, <Cm>, #<op2>
    struct SyslRcSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SyslRcSysteminstrs sysl_rc_systeminstrs;

    // SYSP: 128-bit system instruction
    // Encoding: SYSP_CR_syspairinstrs
    // Template: SYSP  #<op1>, <Cn>, <Cm>, #<op2>{, <Xt1>, <Xt2>}
    struct SyspCrSyspairinstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    SyspCrSyspairinstrs sysp_cr_syspairinstrs;

    // TBNZ: Test bit and branch if nonzero
    // Encoding: TBNZ_only_testbranch
    // Template: TBNZ  <R><t>, #<imm>, <label>
    struct TbnzOnlyTestbranch {
        uint32_t Rt : 5;
        int32_t imm14 : 14;
        uint32_t b40 : 5;
        uint32_t op : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 2;  // fixed: 0b01 (0x1)
        uint32_t b5 : 1;
    };

    TbnzOnlyTestbranch tbnz_only_testbranch;

    // TBZ: Test bit and branch if zero
    // Encoding: TBZ_only_testbranch
    // Template: TBZ  <R><t>, #<imm>, <label>
    struct TbzOnlyTestbranch {
        uint32_t Rt : 5;
        int32_t imm14 : 14;
        uint32_t b40 : 5;
        uint32_t op : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 1;  // fixed: 0b1 (0x1)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 2;  // fixed: 0b01 (0x1)
        uint32_t b5 : 1;
    };

    TbzOnlyTestbranch tbz_only_testbranch;

    // SYS: TLB invalidate operation
    // Encoding: TLBI_SYS_CR_systeminstrs
    // Template: TLBI  <tlbi_op>{, <Xt>}
    struct TlbiSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;  // partial: 100x
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    TlbiSysCrSysteminstrs tlbi_sys_cr_systeminstrs;

    // SYSP: TLB invalidate pair operation
    // Encoding: TLBIP_SYSP_CR_syspairinstrs
    // Template: TLBIP  <tlbip_op>{, <Xt1>, <Xt2>}
    struct TlbipSyspCrSyspairinstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;
        uint32_t CRm : 4;
        uint32_t CRn : 4;  // partial: 100x
        uint32_t op1 : 3;
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0101 (0x5)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    TlbipSyspCrSyspairinstrs tlbip_sysp_cr_syspairinstrs;

    // SYS: Trace instrumentation
    // Encoding: TRCIT_SYS_CR_systeminstrs
    // Template: TRCIT  <Xt>
    struct TrcitSysCrSysteminstrs {
        uint32_t Rt : 5;
        uint32_t op2 : 3;  // fixed: 0b111 (0x7)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t CRn : 4;  // fixed: 0b0111 (0x7)
        uint32_t op1 : 3;  // fixed: 0b011 (0x3)
        uint32_t _unnamed_3 : 2;  // fixed: 0b01 (0x1)
        uint32_t L : 1;  // fixed: 0b0 (0x0)
        uint32_t _unnamed_2 : 4;  // fixed: 0b0100 (0x4)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    TrcitSysCrSysteminstrs trcit_sys_cr_systeminstrs;

    // TSB: Trace synchronization barrier
    // Encoding: TSB_HC_hints
    // Template: TSB  CSYNC
    struct TsbHcHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0010 (0x2)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    TsbHcHints tsb_hc_hints;

    // WFE: Wait for event
    // Encoding: WFE_HI_hints
    // Template: WFE
    struct WfeHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b010 (0x2)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    WfeHiHints wfe_hi_hints;

    // WFET: Wait for event with timeout
    // Encoding: WFET_only_systeminstrswithreg
    // Template: WFET  <Xt>
    struct WfetOnlySysteminstrswithreg {
        uint32_t Rd : 5;
        uint32_t op2 : 3;  // fixed: 0b000 (0x0)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110001 (0x1031)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    WfetOnlySysteminstrswithreg wfet_only_systeminstrswithreg;

    // WFI: Wait for interrupt
    // Encoding: WFI_HI_hints
    // Template: WFI
    struct WfiHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b011 (0x3)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    WfiHiHints wfi_hi_hints;

    // WFIT: Wait for interrupt with timeout
    // Encoding: WFIT_only_systeminstrswithreg
    // Template: WFIT  <Xt>
    struct WfitOnlySysteminstrswithreg {
        uint32_t Rd : 5;
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110001 (0x1031)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    WfitOnlySysteminstrswithreg wfit_only_systeminstrswithreg;

    // XAFLAG: Convert floating-point condition flags from external format to Arm format
    // Encoding: XAFLAG_M_pstate
    // Template: XAFLAG
    struct XaflagMPstate {
        uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
        uint32_t op1 : 3;  // fixed: 0b000 (0x0)
        uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    XaflagMPstate xaflag_mpstate;

    // : Strip Pointer Authentication Code
    // Encoding: XPACLRI_HI_hints
    // Template: XPACLRI
    struct XpaclriHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b111 (0x7)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    XpaclriHiHints xpaclri_hi_hints;

    // YIELD: Yield
    // Encoding: YIELD_HI_hints
    // Template: YIELD
    struct YieldHiHints {
        uint32_t _unnamed_3 : 5;  // fixed: 0b11111 (0x1F)
        uint32_t op2 : 3;  // fixed: 0b001 (0x1)
        uint32_t CRm : 4;  // fixed: 0b0000 (0x0)
        uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110010 (0x1032)
        uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
        uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
    };

    YieldHiHints yield_hi_hints;

};
static_assert(sizeof(ControlEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_apas_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.apas_sys_cr_systeminstrs.Rt = Rt;
    insn.apas_sys_cr_systeminstrs.op2 = 0b000;
    insn.apas_sys_cr_systeminstrs.CRm = 0b0000;
    insn.apas_sys_cr_systeminstrs.CRn = 0b0111;
    insn.apas_sys_cr_systeminstrs.op1 = 0b110;
    insn.apas_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.apas_sys_cr_systeminstrs.L = 0b0;
    insn.apas_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.apas_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.apas_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_at_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1) {
    ControlEncoding insn = {};
    insn.at_sys_cr_systeminstrs.Rt = Rt;
    insn.at_sys_cr_systeminstrs.op2 = op2;
    insn.at_sys_cr_systeminstrs.CRm = CRm;
    insn.at_sys_cr_systeminstrs.CRn = 0b0111;
    insn.at_sys_cr_systeminstrs.op1 = op1;
    insn.at_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.at_sys_cr_systeminstrs.L = 0b0;
    insn.at_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.at_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.at_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_autia1716_hi_hints() {
    ControlEncoding insn = {};
    insn.autia1716hi_hints._unnamed_1 = 0b11111;
    insn.autia1716hi_hints.op2 = 0b100;
    insn.autia1716hi_hints.CRm = 0b0001;
    insn.autia1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autiasp_hi_hints() {
    ControlEncoding insn = {};
    insn.autiasp_hi_hints._unnamed_1 = 0b11111;
    insn.autiasp_hi_hints.op2 = 0b101;
    insn.autiasp_hi_hints.CRm = 0b0011;
    insn.autiasp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autiaz_hi_hints() {
    ControlEncoding insn = {};
    insn.autiaz_hi_hints._unnamed_1 = 0b11111;
    insn.autiaz_hi_hints.op2 = 0b100;
    insn.autiaz_hi_hints.CRm = 0b0011;
    insn.autiaz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autib1716_hi_hints() {
    ControlEncoding insn = {};
    insn.autib1716hi_hints._unnamed_1 = 0b11111;
    insn.autib1716hi_hints.op2 = 0b110;
    insn.autib1716hi_hints.CRm = 0b0001;
    insn.autib1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autibsp_hi_hints() {
    ControlEncoding insn = {};
    insn.autibsp_hi_hints._unnamed_1 = 0b11111;
    insn.autibsp_hi_hints.op2 = 0b111;
    insn.autibsp_hi_hints.CRm = 0b0011;
    insn.autibsp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_autibz_hi_hints() {
    ControlEncoding insn = {};
    insn.autibz_hi_hints._unnamed_1 = 0b11111;
    insn.autibz_hi_hints.op2 = 0b110;
    insn.autibz_hi_hints.CRm = 0b0011;
    insn.autibz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_axflag_m_pstate() {
    ControlEncoding insn = {};
    insn.axflag_mpstate.Rt = 0b11111;
    insn.axflag_mpstate.op2 = 0b010;
    insn.axflag_mpstate.CRm = 0b0000;
    insn.axflag_mpstate._unnamed_3 = 0b0100;
    insn.axflag_mpstate.op1 = 0b000;
    insn.axflag_mpstate._unnamed_2 = 0b0100000;
    insn.axflag_mpstate._unnamed_1 = 0b101;
    insn.axflag_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_b_only_condbranch(uint32_t cond, int32_t imm19) {
    ControlEncoding insn = {};
    insn.bonly_condbranch.cond = cond;
    insn.bonly_condbranch.o0 = 0b0;
    insn.bonly_condbranch.imm19 = imm19;
    insn.bonly_condbranch._unnamed_2 = 0b00;
    insn.bonly_condbranch._unnamed_1 = 0b101;
    insn.bonly_condbranch._unnamed_0 = 0b010;
    return insn.raw;
}

uint32_t encode_b_only_branch_imm(int32_t imm26) {
    ControlEncoding insn = {};
    insn.bonly_branch_imm.imm26 = imm26;
    insn.bonly_branch_imm._unnamed_1 = 0b101;
    insn.bonly_branch_imm._unnamed_0 = 0b00;
    insn.bonly_branch_imm.op = 0b0;
    return insn.raw;
}

uint32_t encode_bc_only_condbranch(uint32_t cond, int32_t imm19) {
    ControlEncoding insn = {};
    insn.bc_only_condbranch.cond = cond;
    insn.bc_only_condbranch.o0 = 0b1;
    insn.bc_only_condbranch.imm19 = imm19;
    insn.bc_only_condbranch._unnamed_2 = 0b00;
    insn.bc_only_condbranch._unnamed_1 = 0b101;
    insn.bc_only_condbranch._unnamed_0 = 0b010;
    return insn.raw;
}

uint32_t encode_bl_only_branch_imm(int32_t imm26) {
    ControlEncoding insn = {};
    insn.bl_only_branch_imm.imm26 = imm26;
    insn.bl_only_branch_imm._unnamed_1 = 0b101;
    insn.bl_only_branch_imm._unnamed_0 = 0b00;
    insn.bl_only_branch_imm.op = 0b1;
    return insn.raw;
}

uint32_t encode_blr_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.blr64branch_reg.Rm = 0b00000;
    insn.blr64branch_reg.Rn = Rn;
    insn.blr64branch_reg.M = 0b0;
    insn.blr64branch_reg.A = 0b0;
    insn.blr64branch_reg._unnamed_4 = 0b0000;
    insn.blr64branch_reg.op2 = 0b11111;
    insn.blr64branch_reg.op = 0b01;
    insn.blr64branch_reg._unnamed_3 = 0b0;
    insn.blr64branch_reg.Z = 0b0;
    insn.blr64branch_reg._unnamed_2 = 0b1;
    insn.blr64branch_reg._unnamed_1 = 0b101;
    insn.blr64branch_reg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_blraa_64p_branch_reg(uint32_t Rm, uint32_t Rn) {
    ControlEncoding insn = {};
    insn.blraa64p_branch_reg.Rm = Rm;
    insn.blraa64p_branch_reg.Rn = Rn;
    insn.blraa64p_branch_reg.M = 0b0;
    insn.blraa64p_branch_reg.A = 0b1;
    insn.blraa64p_branch_reg._unnamed_2 = 0b0000;
    insn.blraa64p_branch_reg.op2 = 0b11111;
    insn.blraa64p_branch_reg.op = 0b01;
    insn.blraa64p_branch_reg._unnamed_1 = 0b0;
    insn.blraa64p_branch_reg.Z = 0b1;
    insn.blraa64p_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_blraaz_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.blraaz64branch_reg.Rm = 0b11111;
    insn.blraaz64branch_reg.Rn = Rn;
    insn.blraaz64branch_reg.M = 0b0;
    insn.blraaz64branch_reg.A = 0b1;
    insn.blraaz64branch_reg._unnamed_2 = 0b0000;
    insn.blraaz64branch_reg.op2 = 0b11111;
    insn.blraaz64branch_reg.op = 0b01;
    insn.blraaz64branch_reg._unnamed_1 = 0b0;
    insn.blraaz64branch_reg.Z = 0b0;
    insn.blraaz64branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_blrab_64p_branch_reg(uint32_t Rm, uint32_t Rn) {
    ControlEncoding insn = {};
    insn.blrab64p_branch_reg.Rm = Rm;
    insn.blrab64p_branch_reg.Rn = Rn;
    insn.blrab64p_branch_reg.M = 0b1;
    insn.blrab64p_branch_reg.A = 0b1;
    insn.blrab64p_branch_reg._unnamed_2 = 0b0000;
    insn.blrab64p_branch_reg.op2 = 0b11111;
    insn.blrab64p_branch_reg.op = 0b01;
    insn.blrab64p_branch_reg._unnamed_1 = 0b0;
    insn.blrab64p_branch_reg.Z = 0b1;
    insn.blrab64p_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_blrabz_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.blrabz64branch_reg.Rm = 0b11111;
    insn.blrabz64branch_reg.Rn = Rn;
    insn.blrabz64branch_reg.M = 0b1;
    insn.blrabz64branch_reg.A = 0b1;
    insn.blrabz64branch_reg._unnamed_2 = 0b0000;
    insn.blrabz64branch_reg.op2 = 0b11111;
    insn.blrabz64branch_reg.op = 0b01;
    insn.blrabz64branch_reg._unnamed_1 = 0b0;
    insn.blrabz64branch_reg.Z = 0b0;
    insn.blrabz64branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_br_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.br64branch_reg.Rm = 0b00000;
    insn.br64branch_reg.Rn = Rn;
    insn.br64branch_reg.M = 0b0;
    insn.br64branch_reg.A = 0b0;
    insn.br64branch_reg._unnamed_4 = 0b0000;
    insn.br64branch_reg.op2 = 0b11111;
    insn.br64branch_reg.op = 0b00;
    insn.br64branch_reg._unnamed_3 = 0b0;
    insn.br64branch_reg.Z = 0b0;
    insn.br64branch_reg._unnamed_2 = 0b1;
    insn.br64branch_reg._unnamed_1 = 0b101;
    insn.br64branch_reg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_braa_64p_branch_reg(uint32_t Rm, uint32_t Rn) {
    ControlEncoding insn = {};
    insn.braa64p_branch_reg.Rm = Rm;
    insn.braa64p_branch_reg.Rn = Rn;
    insn.braa64p_branch_reg.M = 0b0;
    insn.braa64p_branch_reg.A = 0b1;
    insn.braa64p_branch_reg._unnamed_2 = 0b0000;
    insn.braa64p_branch_reg.op2 = 0b11111;
    insn.braa64p_branch_reg.op = 0b00;
    insn.braa64p_branch_reg._unnamed_1 = 0b0;
    insn.braa64p_branch_reg.Z = 0b1;
    insn.braa64p_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_braaz_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.braaz64branch_reg.Rm = 0b11111;
    insn.braaz64branch_reg.Rn = Rn;
    insn.braaz64branch_reg.M = 0b0;
    insn.braaz64branch_reg.A = 0b1;
    insn.braaz64branch_reg._unnamed_2 = 0b0000;
    insn.braaz64branch_reg.op2 = 0b11111;
    insn.braaz64branch_reg.op = 0b00;
    insn.braaz64branch_reg._unnamed_1 = 0b0;
    insn.braaz64branch_reg.Z = 0b0;
    insn.braaz64branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_brab_64p_branch_reg(uint32_t Rm, uint32_t Rn) {
    ControlEncoding insn = {};
    insn.brab64p_branch_reg.Rm = Rm;
    insn.brab64p_branch_reg.Rn = Rn;
    insn.brab64p_branch_reg.M = 0b1;
    insn.brab64p_branch_reg.A = 0b1;
    insn.brab64p_branch_reg._unnamed_2 = 0b0000;
    insn.brab64p_branch_reg.op2 = 0b11111;
    insn.brab64p_branch_reg.op = 0b00;
    insn.brab64p_branch_reg._unnamed_1 = 0b0;
    insn.brab64p_branch_reg.Z = 0b1;
    insn.brab64p_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_brabz_64_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.brabz64branch_reg.Rm = 0b11111;
    insn.brabz64branch_reg.Rn = Rn;
    insn.brabz64branch_reg.M = 0b1;
    insn.brabz64branch_reg.A = 0b1;
    insn.brabz64branch_reg._unnamed_2 = 0b0000;
    insn.brabz64branch_reg.op2 = 0b11111;
    insn.brabz64branch_reg.op = 0b00;
    insn.brabz64branch_reg._unnamed_1 = 0b0;
    insn.brabz64branch_reg.Z = 0b0;
    insn.brabz64branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_brb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2) {
    ControlEncoding insn = {};
    insn.brb_sys_cr_systeminstrs.Rt = Rt;
    insn.brb_sys_cr_systeminstrs.op2 = op2;
    insn.brb_sys_cr_systeminstrs.CRm = 0b0010;
    insn.brb_sys_cr_systeminstrs.CRn = 0b0111;
    insn.brb_sys_cr_systeminstrs.op1 = 0b001;
    insn.brb_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.brb_sys_cr_systeminstrs.L = 0b0;
    insn.brb_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.brb_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.brb_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_brk_ex_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.brk_ex_exception.LL = 0b00;
    insn.brk_ex_exception.op2 = 0b000;
    insn.brk_ex_exception.imm16 = imm16;
    insn.brk_ex_exception.opc = 0b001;
    insn.brk_ex_exception._unnamed_2 = 0b00;
    insn.brk_ex_exception._unnamed_1 = 0b101;
    insn.brk_ex_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_bti_hb_hints(uint32_t op2) {
    ControlEncoding insn = {};
    insn.bti_hb_hints._unnamed_3 = 0b11111;
    insn.bti_hb_hints.op2 = op2;
    insn.bti_hb_hints.CRm = 0b0100;
    insn.bti_hb_hints._unnamed_2 = 0b01000000110010;
    insn.bti_hb_hints._unnamed_1 = 0b101;
    insn.bti_hb_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cbbgt_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbgt8regs.Rt = Rt;
    insn.cbbgt8regs.imm9 = imm9;
    insn.cbbgt8regs.H = 0b0;
    insn.cbbgt8regs._unnamed_1 = 0b1;
    insn.cbbgt8regs.Rm = Rm;
    insn.cbbgt8regs.cc = 0b000;
    insn.cbbgt8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbbge_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbge8regs.Rt = Rt;
    insn.cbbge8regs.imm9 = imm9;
    insn.cbbge8regs.H = 0b0;
    insn.cbbge8regs._unnamed_1 = 0b1;
    insn.cbbge8regs.Rm = Rm;
    insn.cbbge8regs.cc = 0b001;
    insn.cbbge8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbbhi_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbhi8regs.Rt = Rt;
    insn.cbbhi8regs.imm9 = imm9;
    insn.cbbhi8regs.H = 0b0;
    insn.cbbhi8regs._unnamed_1 = 0b1;
    insn.cbbhi8regs.Rm = Rm;
    insn.cbbhi8regs.cc = 0b010;
    insn.cbbhi8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbbhs_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbhs8regs.Rt = Rt;
    insn.cbbhs8regs.imm9 = imm9;
    insn.cbbhs8regs.H = 0b0;
    insn.cbbhs8regs._unnamed_1 = 0b1;
    insn.cbbhs8regs.Rm = Rm;
    insn.cbbhs8regs.cc = 0b011;
    insn.cbbhs8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbbeq_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbeq8regs.Rt = Rt;
    insn.cbbeq8regs.imm9 = imm9;
    insn.cbbeq8regs.H = 0b0;
    insn.cbbeq8regs._unnamed_1 = 0b1;
    insn.cbbeq8regs.Rm = Rm;
    insn.cbbeq8regs.cc = 0b110;
    insn.cbbeq8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbbne_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbne8regs.Rt = Rt;
    insn.cbbne8regs.imm9 = imm9;
    insn.cbbne8regs.H = 0b0;
    insn.cbbne8regs._unnamed_1 = 0b1;
    insn.cbbne8regs.Rm = Rm;
    insn.cbbne8regs.cc = 0b111;
    insn.cbbne8regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbble_cbbge_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbble_cbbge8regs.Rt = Rt;
    insn.cbble_cbbge8regs.imm9 = imm9;
    insn.cbble_cbbge8regs.H = 0b0;
    insn.cbble_cbbge8regs._unnamed_3 = 0b1;
    insn.cbble_cbbge8regs.Rm = Rm;
    insn.cbble_cbbge8regs.cc = 0b001;
    insn.cbble_cbbge8regs._unnamed_2 = 0b00;
    insn.cbble_cbbge8regs._unnamed_1 = 0b101;
    insn.cbble_cbbge8regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbblo_cbbhi_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbblo_cbbhi8regs.Rt = Rt;
    insn.cbblo_cbbhi8regs.imm9 = imm9;
    insn.cbblo_cbbhi8regs.H = 0b0;
    insn.cbblo_cbbhi8regs._unnamed_3 = 0b1;
    insn.cbblo_cbbhi8regs.Rm = Rm;
    insn.cbblo_cbbhi8regs.cc = 0b010;
    insn.cbblo_cbbhi8regs._unnamed_2 = 0b00;
    insn.cbblo_cbbhi8regs._unnamed_1 = 0b101;
    insn.cbblo_cbbhi8regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbbls_cbbhs_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbbls_cbbhs8regs.Rt = Rt;
    insn.cbbls_cbbhs8regs.imm9 = imm9;
    insn.cbbls_cbbhs8regs.H = 0b0;
    insn.cbbls_cbbhs8regs._unnamed_3 = 0b1;
    insn.cbbls_cbbhs8regs.Rm = Rm;
    insn.cbbls_cbbhs8regs.cc = 0b011;
    insn.cbbls_cbbhs8regs._unnamed_2 = 0b00;
    insn.cbbls_cbbhs8regs._unnamed_1 = 0b101;
    insn.cbbls_cbbhs8regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbblt_cbbgt_8_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbblt_cbbgt8regs.Rt = Rt;
    insn.cbblt_cbbgt8regs.imm9 = imm9;
    insn.cbblt_cbbgt8regs.H = 0b0;
    insn.cbblt_cbbgt8regs._unnamed_3 = 0b1;
    insn.cbblt_cbbgt8regs.Rm = Rm;
    insn.cbblt_cbbgt8regs.cc = 0b000;
    insn.cbblt_cbbgt8regs._unnamed_2 = 0b00;
    insn.cbblt_cbbgt8regs._unnamed_1 = 0b101;
    insn.cbblt_cbbgt8regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbgt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbgt32imm.Rt = Rt;
    insn.cbgt32imm.imm9 = imm9;
    insn.cbgt32imm._unnamed_1 = 0b0;
    insn.cbgt32imm.imm6 = imm6;
    insn.cbgt32imm.cc = 0b000;
    insn.cbgt32imm._unnamed_0 = 0b1110101;
    insn.cbgt32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cblt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cblt32imm.Rt = Rt;
    insn.cblt32imm.imm9 = imm9;
    insn.cblt32imm._unnamed_1 = 0b0;
    insn.cblt32imm.imm6 = imm6;
    insn.cblt32imm.cc = 0b001;
    insn.cblt32imm._unnamed_0 = 0b1110101;
    insn.cblt32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbhi_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbhi32imm.Rt = Rt;
    insn.cbhi32imm.imm9 = imm9;
    insn.cbhi32imm._unnamed_1 = 0b0;
    insn.cbhi32imm.imm6 = imm6;
    insn.cbhi32imm.cc = 0b010;
    insn.cbhi32imm._unnamed_0 = 0b1110101;
    insn.cbhi32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cblo_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cblo32imm.Rt = Rt;
    insn.cblo32imm.imm9 = imm9;
    insn.cblo32imm._unnamed_1 = 0b0;
    insn.cblo32imm.imm6 = imm6;
    insn.cblo32imm.cc = 0b011;
    insn.cblo32imm._unnamed_0 = 0b1110101;
    insn.cblo32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbeq_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbeq32imm.Rt = Rt;
    insn.cbeq32imm.imm9 = imm9;
    insn.cbeq32imm._unnamed_1 = 0b0;
    insn.cbeq32imm.imm6 = imm6;
    insn.cbeq32imm.cc = 0b110;
    insn.cbeq32imm._unnamed_0 = 0b1110101;
    insn.cbeq32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbne_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbne32imm.Rt = Rt;
    insn.cbne32imm.imm9 = imm9;
    insn.cbne32imm._unnamed_1 = 0b0;
    insn.cbne32imm.imm6 = imm6;
    insn.cbne32imm.cc = 0b111;
    insn.cbne32imm._unnamed_0 = 0b1110101;
    insn.cbne32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbgt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbgt64imm.Rt = Rt;
    insn.cbgt64imm.imm9 = imm9;
    insn.cbgt64imm._unnamed_1 = 0b0;
    insn.cbgt64imm.imm6 = imm6;
    insn.cbgt64imm.cc = 0b000;
    insn.cbgt64imm._unnamed_0 = 0b1110101;
    insn.cbgt64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cblt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cblt64imm.Rt = Rt;
    insn.cblt64imm.imm9 = imm9;
    insn.cblt64imm._unnamed_1 = 0b0;
    insn.cblt64imm.imm6 = imm6;
    insn.cblt64imm.cc = 0b001;
    insn.cblt64imm._unnamed_0 = 0b1110101;
    insn.cblt64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbhi_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbhi64imm.Rt = Rt;
    insn.cbhi64imm.imm9 = imm9;
    insn.cbhi64imm._unnamed_1 = 0b0;
    insn.cbhi64imm.imm6 = imm6;
    insn.cbhi64imm.cc = 0b010;
    insn.cbhi64imm._unnamed_0 = 0b1110101;
    insn.cbhi64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cblo_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cblo64imm.Rt = Rt;
    insn.cblo64imm.imm9 = imm9;
    insn.cblo64imm._unnamed_1 = 0b0;
    insn.cblo64imm.imm6 = imm6;
    insn.cblo64imm.cc = 0b011;
    insn.cblo64imm._unnamed_0 = 0b1110101;
    insn.cblo64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbeq_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbeq64imm.Rt = Rt;
    insn.cbeq64imm.imm9 = imm9;
    insn.cbeq64imm._unnamed_1 = 0b0;
    insn.cbeq64imm.imm6 = imm6;
    insn.cbeq64imm.cc = 0b110;
    insn.cbeq64imm._unnamed_0 = 0b1110101;
    insn.cbeq64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbne_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbne64imm.Rt = Rt;
    insn.cbne64imm.imm9 = imm9;
    insn.cbne64imm._unnamed_1 = 0b0;
    insn.cbne64imm.imm6 = imm6;
    insn.cbne64imm.cc = 0b111;
    insn.cbne64imm._unnamed_0 = 0b1110101;
    insn.cbne64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbgt_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbgt32regs.Rt = Rt;
    insn.cbgt32regs.imm9 = imm9;
    insn.cbgt32regs._unnamed_1 = 0b00;
    insn.cbgt32regs.Rm = Rm;
    insn.cbgt32regs.cc = 0b000;
    insn.cbgt32regs._unnamed_0 = 0b1110100;
    insn.cbgt32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbge_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbge32regs.Rt = Rt;
    insn.cbge32regs.imm9 = imm9;
    insn.cbge32regs._unnamed_1 = 0b00;
    insn.cbge32regs.Rm = Rm;
    insn.cbge32regs.cc = 0b001;
    insn.cbge32regs._unnamed_0 = 0b1110100;
    insn.cbge32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbhi_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhi32regs.Rt = Rt;
    insn.cbhi32regs.imm9 = imm9;
    insn.cbhi32regs._unnamed_1 = 0b00;
    insn.cbhi32regs.Rm = Rm;
    insn.cbhi32regs.cc = 0b010;
    insn.cbhi32regs._unnamed_0 = 0b1110100;
    insn.cbhi32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbhs_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhs32regs.Rt = Rt;
    insn.cbhs32regs.imm9 = imm9;
    insn.cbhs32regs._unnamed_1 = 0b00;
    insn.cbhs32regs.Rm = Rm;
    insn.cbhs32regs.cc = 0b011;
    insn.cbhs32regs._unnamed_0 = 0b1110100;
    insn.cbhs32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbeq_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbeq32regs.Rt = Rt;
    insn.cbeq32regs.imm9 = imm9;
    insn.cbeq32regs._unnamed_1 = 0b00;
    insn.cbeq32regs.Rm = Rm;
    insn.cbeq32regs.cc = 0b110;
    insn.cbeq32regs._unnamed_0 = 0b1110100;
    insn.cbeq32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbne_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbne32regs.Rt = Rt;
    insn.cbne32regs.imm9 = imm9;
    insn.cbne32regs._unnamed_1 = 0b00;
    insn.cbne32regs.Rm = Rm;
    insn.cbne32regs.cc = 0b111;
    insn.cbne32regs._unnamed_0 = 0b1110100;
    insn.cbne32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbgt_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbgt64regs.Rt = Rt;
    insn.cbgt64regs.imm9 = imm9;
    insn.cbgt64regs._unnamed_1 = 0b00;
    insn.cbgt64regs.Rm = Rm;
    insn.cbgt64regs.cc = 0b000;
    insn.cbgt64regs._unnamed_0 = 0b1110100;
    insn.cbgt64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbge_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbge64regs.Rt = Rt;
    insn.cbge64regs.imm9 = imm9;
    insn.cbge64regs._unnamed_1 = 0b00;
    insn.cbge64regs.Rm = Rm;
    insn.cbge64regs.cc = 0b001;
    insn.cbge64regs._unnamed_0 = 0b1110100;
    insn.cbge64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbhi_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhi64regs.Rt = Rt;
    insn.cbhi64regs.imm9 = imm9;
    insn.cbhi64regs._unnamed_1 = 0b00;
    insn.cbhi64regs.Rm = Rm;
    insn.cbhi64regs.cc = 0b010;
    insn.cbhi64regs._unnamed_0 = 0b1110100;
    insn.cbhi64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbhs_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhs64regs.Rt = Rt;
    insn.cbhs64regs.imm9 = imm9;
    insn.cbhs64regs._unnamed_1 = 0b00;
    insn.cbhs64regs.Rm = Rm;
    insn.cbhs64regs.cc = 0b011;
    insn.cbhs64regs._unnamed_0 = 0b1110100;
    insn.cbhs64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbeq_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbeq64regs.Rt = Rt;
    insn.cbeq64regs.imm9 = imm9;
    insn.cbeq64regs._unnamed_1 = 0b00;
    insn.cbeq64regs.Rm = Rm;
    insn.cbeq64regs.cc = 0b110;
    insn.cbeq64regs._unnamed_0 = 0b1110100;
    insn.cbeq64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbne_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbne64regs.Rt = Rt;
    insn.cbne64regs.imm9 = imm9;
    insn.cbne64regs._unnamed_1 = 0b00;
    insn.cbne64regs.Rm = Rm;
    insn.cbne64regs.cc = 0b111;
    insn.cbne64regs._unnamed_0 = 0b1110100;
    insn.cbne64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbge_cbgt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbge_cbgt32imm.Rt = Rt;
    insn.cbge_cbgt32imm.imm9 = imm9;
    insn.cbge_cbgt32imm._unnamed_1 = 0b0;
    insn.cbge_cbgt32imm.imm6 = imm6;
    insn.cbge_cbgt32imm.cc = 0b000;
    insn.cbge_cbgt32imm._unnamed_0 = 0b1110101;
    insn.cbge_cbgt32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbge_cbgt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbge_cbgt64imm.Rt = Rt;
    insn.cbge_cbgt64imm.imm9 = imm9;
    insn.cbge_cbgt64imm._unnamed_1 = 0b0;
    insn.cbge_cbgt64imm.imm6 = imm6;
    insn.cbge_cbgt64imm.cc = 0b000;
    insn.cbge_cbgt64imm._unnamed_0 = 0b1110101;
    insn.cbge_cbgt64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbhgt_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhgt16regs.Rt = Rt;
    insn.cbhgt16regs.imm9 = imm9;
    insn.cbhgt16regs.H = 0b1;
    insn.cbhgt16regs._unnamed_1 = 0b1;
    insn.cbhgt16regs.Rm = Rm;
    insn.cbhgt16regs.cc = 0b000;
    insn.cbhgt16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbhge_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhge16regs.Rt = Rt;
    insn.cbhge16regs.imm9 = imm9;
    insn.cbhge16regs.H = 0b1;
    insn.cbhge16regs._unnamed_1 = 0b1;
    insn.cbhge16regs.Rm = Rm;
    insn.cbhge16regs.cc = 0b001;
    insn.cbhge16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbhhi_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhhi16regs.Rt = Rt;
    insn.cbhhi16regs.imm9 = imm9;
    insn.cbhhi16regs.H = 0b1;
    insn.cbhhi16regs._unnamed_1 = 0b1;
    insn.cbhhi16regs.Rm = Rm;
    insn.cbhhi16regs.cc = 0b010;
    insn.cbhhi16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbhhs_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhhs16regs.Rt = Rt;
    insn.cbhhs16regs.imm9 = imm9;
    insn.cbhhs16regs.H = 0b1;
    insn.cbhhs16regs._unnamed_1 = 0b1;
    insn.cbhhs16regs.Rm = Rm;
    insn.cbhhs16regs.cc = 0b011;
    insn.cbhhs16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbheq_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbheq16regs.Rt = Rt;
    insn.cbheq16regs.imm9 = imm9;
    insn.cbheq16regs.H = 0b1;
    insn.cbheq16regs._unnamed_1 = 0b1;
    insn.cbheq16regs.Rm = Rm;
    insn.cbheq16regs.cc = 0b110;
    insn.cbheq16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbhne_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhne16regs.Rt = Rt;
    insn.cbhne16regs.imm9 = imm9;
    insn.cbhne16regs.H = 0b1;
    insn.cbhne16regs._unnamed_1 = 0b1;
    insn.cbhne16regs.Rm = Rm;
    insn.cbhne16regs.cc = 0b111;
    insn.cbhne16regs._unnamed_0 = 0b01110100;
    return insn.raw;
}

uint32_t encode_cbhle_cbhge_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhle_cbhge16regs.Rt = Rt;
    insn.cbhle_cbhge16regs.imm9 = imm9;
    insn.cbhle_cbhge16regs.H = 0b1;
    insn.cbhle_cbhge16regs._unnamed_3 = 0b1;
    insn.cbhle_cbhge16regs.Rm = Rm;
    insn.cbhle_cbhge16regs.cc = 0b001;
    insn.cbhle_cbhge16regs._unnamed_2 = 0b00;
    insn.cbhle_cbhge16regs._unnamed_1 = 0b101;
    insn.cbhle_cbhge16regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbhlo_cbhhi_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhlo_cbhhi16regs.Rt = Rt;
    insn.cbhlo_cbhhi16regs.imm9 = imm9;
    insn.cbhlo_cbhhi16regs.H = 0b1;
    insn.cbhlo_cbhhi16regs._unnamed_3 = 0b1;
    insn.cbhlo_cbhhi16regs.Rm = Rm;
    insn.cbhlo_cbhhi16regs.cc = 0b010;
    insn.cbhlo_cbhhi16regs._unnamed_2 = 0b00;
    insn.cbhlo_cbhhi16regs._unnamed_1 = 0b101;
    insn.cbhlo_cbhhi16regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbhls_cbhhs_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhls_cbhhs16regs.Rt = Rt;
    insn.cbhls_cbhhs16regs.imm9 = imm9;
    insn.cbhls_cbhhs16regs.H = 0b1;
    insn.cbhls_cbhhs16regs._unnamed_3 = 0b1;
    insn.cbhls_cbhhs16regs.Rm = Rm;
    insn.cbhls_cbhhs16regs.cc = 0b011;
    insn.cbhls_cbhhs16regs._unnamed_2 = 0b00;
    insn.cbhls_cbhhs16regs._unnamed_1 = 0b101;
    insn.cbhls_cbhhs16regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbhlt_cbhgt_16_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbhlt_cbhgt16regs.Rt = Rt;
    insn.cbhlt_cbhgt16regs.imm9 = imm9;
    insn.cbhlt_cbhgt16regs.H = 0b1;
    insn.cbhlt_cbhgt16regs._unnamed_3 = 0b1;
    insn.cbhlt_cbhgt16regs.Rm = Rm;
    insn.cbhlt_cbhgt16regs.cc = 0b000;
    insn.cbhlt_cbhgt16regs._unnamed_2 = 0b00;
    insn.cbhlt_cbhgt16regs._unnamed_1 = 0b101;
    insn.cbhlt_cbhgt16regs._unnamed_0 = 0b011;
    return insn.raw;
}

uint32_t encode_cbhs_cbhi_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbhs_cbhi32imm.Rt = Rt;
    insn.cbhs_cbhi32imm.imm9 = imm9;
    insn.cbhs_cbhi32imm._unnamed_1 = 0b0;
    insn.cbhs_cbhi32imm.imm6 = imm6;
    insn.cbhs_cbhi32imm.cc = 0b010;
    insn.cbhs_cbhi32imm._unnamed_0 = 0b1110101;
    insn.cbhs_cbhi32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbhs_cbhi_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbhs_cbhi64imm.Rt = Rt;
    insn.cbhs_cbhi64imm.imm9 = imm9;
    insn.cbhs_cbhi64imm._unnamed_1 = 0b0;
    insn.cbhs_cbhi64imm.imm6 = imm6;
    insn.cbhs_cbhi64imm.cc = 0b010;
    insn.cbhs_cbhi64imm._unnamed_0 = 0b1110101;
    insn.cbhs_cbhi64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cble_cblt_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cble_cblt32imm.Rt = Rt;
    insn.cble_cblt32imm.imm9 = imm9;
    insn.cble_cblt32imm._unnamed_1 = 0b0;
    insn.cble_cblt32imm.imm6 = imm6;
    insn.cble_cblt32imm.cc = 0b001;
    insn.cble_cblt32imm._unnamed_0 = 0b1110101;
    insn.cble_cblt32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cble_cblt_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cble_cblt64imm.Rt = Rt;
    insn.cble_cblt64imm.imm9 = imm9;
    insn.cble_cblt64imm._unnamed_1 = 0b0;
    insn.cble_cblt64imm.imm6 = imm6;
    insn.cble_cblt64imm.cc = 0b001;
    insn.cble_cblt64imm._unnamed_0 = 0b1110101;
    insn.cble_cblt64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cble_cbge_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cble_cbge32regs.Rt = Rt;
    insn.cble_cbge32regs.imm9 = imm9;
    insn.cble_cbge32regs._unnamed_1 = 0b00;
    insn.cble_cbge32regs.Rm = Rm;
    insn.cble_cbge32regs.cc = 0b001;
    insn.cble_cbge32regs._unnamed_0 = 0b1110100;
    insn.cble_cbge32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cble_cbge_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cble_cbge64regs.Rt = Rt;
    insn.cble_cbge64regs.imm9 = imm9;
    insn.cble_cbge64regs._unnamed_1 = 0b00;
    insn.cble_cbge64regs.Rm = Rm;
    insn.cble_cbge64regs.cc = 0b001;
    insn.cble_cbge64regs._unnamed_0 = 0b1110100;
    insn.cble_cbge64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cblo_cbhi_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cblo_cbhi32regs.Rt = Rt;
    insn.cblo_cbhi32regs.imm9 = imm9;
    insn.cblo_cbhi32regs._unnamed_1 = 0b00;
    insn.cblo_cbhi32regs.Rm = Rm;
    insn.cblo_cbhi32regs.cc = 0b010;
    insn.cblo_cbhi32regs._unnamed_0 = 0b1110100;
    insn.cblo_cbhi32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cblo_cbhi_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cblo_cbhi64regs.Rt = Rt;
    insn.cblo_cbhi64regs.imm9 = imm9;
    insn.cblo_cbhi64regs._unnamed_1 = 0b00;
    insn.cblo_cbhi64regs.Rm = Rm;
    insn.cblo_cbhi64regs.cc = 0b010;
    insn.cblo_cbhi64regs._unnamed_0 = 0b1110100;
    insn.cblo_cbhi64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbls_cblo_32_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbls_cblo32imm.Rt = Rt;
    insn.cbls_cblo32imm.imm9 = imm9;
    insn.cbls_cblo32imm._unnamed_1 = 0b0;
    insn.cbls_cblo32imm.imm6 = imm6;
    insn.cbls_cblo32imm.cc = 0b011;
    insn.cbls_cblo32imm._unnamed_0 = 0b1110101;
    insn.cbls_cblo32imm.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbls_cblo_64_imm(uint32_t Rt, int32_t imm9, uint32_t imm6) {
    ControlEncoding insn = {};
    insn.cbls_cblo64imm.Rt = Rt;
    insn.cbls_cblo64imm.imm9 = imm9;
    insn.cbls_cblo64imm._unnamed_1 = 0b0;
    insn.cbls_cblo64imm.imm6 = imm6;
    insn.cbls_cblo64imm.cc = 0b011;
    insn.cbls_cblo64imm._unnamed_0 = 0b1110101;
    insn.cbls_cblo64imm.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbls_cbhs_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbls_cbhs32regs.Rt = Rt;
    insn.cbls_cbhs32regs.imm9 = imm9;
    insn.cbls_cbhs32regs._unnamed_1 = 0b00;
    insn.cbls_cbhs32regs.Rm = Rm;
    insn.cbls_cbhs32regs.cc = 0b011;
    insn.cbls_cbhs32regs._unnamed_0 = 0b1110100;
    insn.cbls_cbhs32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbls_cbhs_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cbls_cbhs64regs.Rt = Rt;
    insn.cbls_cbhs64regs.imm9 = imm9;
    insn.cbls_cbhs64regs._unnamed_1 = 0b00;
    insn.cbls_cbhs64regs.Rm = Rm;
    insn.cbls_cbhs64regs.cc = 0b011;
    insn.cbls_cbhs64regs._unnamed_0 = 0b1110100;
    insn.cbls_cbhs64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cblt_cbgt_32_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cblt_cbgt32regs.Rt = Rt;
    insn.cblt_cbgt32regs.imm9 = imm9;
    insn.cblt_cbgt32regs._unnamed_1 = 0b00;
    insn.cblt_cbgt32regs.Rm = Rm;
    insn.cblt_cbgt32regs.cc = 0b000;
    insn.cblt_cbgt32regs._unnamed_0 = 0b1110100;
    insn.cblt_cbgt32regs.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cblt_cbgt_64_regs(uint32_t Rt, int32_t imm9, uint32_t Rm) {
    ControlEncoding insn = {};
    insn.cblt_cbgt64regs.Rt = Rt;
    insn.cblt_cbgt64regs.imm9 = imm9;
    insn.cblt_cbgt64regs._unnamed_1 = 0b00;
    insn.cblt_cbgt64regs.Rm = Rm;
    insn.cblt_cbgt64regs.cc = 0b000;
    insn.cblt_cbgt64regs._unnamed_0 = 0b1110100;
    insn.cblt_cbgt64regs.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbnz_32_compbranch(uint32_t Rt, int32_t imm19) {
    ControlEncoding insn = {};
    insn.cbnz32compbranch.Rt = Rt;
    insn.cbnz32compbranch.imm19 = imm19;
    insn.cbnz32compbranch.op = 0b1;
    insn.cbnz32compbranch._unnamed_0 = 0b011010;
    insn.cbnz32compbranch.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbnz_64_compbranch(uint32_t Rt, int32_t imm19) {
    ControlEncoding insn = {};
    insn.cbnz64compbranch.Rt = Rt;
    insn.cbnz64compbranch.imm19 = imm19;
    insn.cbnz64compbranch.op = 0b1;
    insn.cbnz64compbranch._unnamed_0 = 0b011010;
    insn.cbnz64compbranch.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cbz_32_compbranch(uint32_t Rt, int32_t imm19) {
    ControlEncoding insn = {};
    insn.cbz32compbranch.Rt = Rt;
    insn.cbz32compbranch.imm19 = imm19;
    insn.cbz32compbranch.op = 0b0;
    insn.cbz32compbranch._unnamed_0 = 0b011010;
    insn.cbz32compbranch.sf = 0b0;
    return insn.raw;
}

uint32_t encode_cbz_64_compbranch(uint32_t Rt, int32_t imm19) {
    ControlEncoding insn = {};
    insn.cbz64compbranch.Rt = Rt;
    insn.cbz64compbranch.imm19 = imm19;
    insn.cbz64compbranch.op = 0b0;
    insn.cbz64compbranch._unnamed_0 = 0b011010;
    insn.cbz64compbranch.sf = 0b1;
    return insn.raw;
}

uint32_t encode_cfinv_m_pstate() {
    ControlEncoding insn = {};
    insn.cfinv_mpstate.Rt = 0b11111;
    insn.cfinv_mpstate.op2 = 0b000;
    insn.cfinv_mpstate.CRm = 0b0000;
    insn.cfinv_mpstate._unnamed_3 = 0b0100;
    insn.cfinv_mpstate.op1 = 0b000;
    insn.cfinv_mpstate._unnamed_2 = 0b0100000;
    insn.cfinv_mpstate._unnamed_1 = 0b101;
    insn.cfinv_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cfp_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.cfp_sys_cr_systeminstrs.Rt = Rt;
    insn.cfp_sys_cr_systeminstrs.op2 = 0b100;
    insn.cfp_sys_cr_systeminstrs.CRm = 0b0011;
    insn.cfp_sys_cr_systeminstrs.CRn = 0b0111;
    insn.cfp_sys_cr_systeminstrs.op1 = 0b011;
    insn.cfp_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.cfp_sys_cr_systeminstrs.L = 0b0;
    insn.cfp_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.cfp_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.cfp_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_chkfeat_hf_hints() {
    ControlEncoding insn = {};
    insn.chkfeat_hf_hints._unnamed_3 = 0b11111;
    insn.chkfeat_hf_hints.op2 = 0b000;
    insn.chkfeat_hf_hints.CRm = 0b0101;
    insn.chkfeat_hf_hints._unnamed_2 = 0b01000000110010;
    insn.chkfeat_hf_hints._unnamed_1 = 0b101;
    insn.chkfeat_hf_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_clrbhb_hi_hints() {
    ControlEncoding insn = {};
    insn.clrbhb_hi_hints._unnamed_3 = 0b11111;
    insn.clrbhb_hi_hints.op2 = 0b110;
    insn.clrbhb_hi_hints.CRm = 0b0010;
    insn.clrbhb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.clrbhb_hi_hints._unnamed_1 = 0b101;
    insn.clrbhb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_clrex_bn_barriers(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.clrex_bn_barriers.Rt = 0b11111;
    insn.clrex_bn_barriers.op2 = 0b010;
    insn.clrex_bn_barriers.CRm = CRm;
    insn.clrex_bn_barriers._unnamed_2 = 0b01000000110011;
    insn.clrex_bn_barriers._unnamed_1 = 0b101;
    insn.clrex_bn_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cosp_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.cosp_sys_cr_systeminstrs.Rt = Rt;
    insn.cosp_sys_cr_systeminstrs.op2 = 0b110;
    insn.cosp_sys_cr_systeminstrs.CRm = 0b0011;
    insn.cosp_sys_cr_systeminstrs.CRn = 0b0111;
    insn.cosp_sys_cr_systeminstrs.op1 = 0b011;
    insn.cosp_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.cosp_sys_cr_systeminstrs.L = 0b0;
    insn.cosp_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.cosp_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.cosp_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cpp_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.cpp_sys_cr_systeminstrs.Rt = Rt;
    insn.cpp_sys_cr_systeminstrs.op2 = 0b111;
    insn.cpp_sys_cr_systeminstrs.CRm = 0b0011;
    insn.cpp_sys_cr_systeminstrs.CRn = 0b0111;
    insn.cpp_sys_cr_systeminstrs.op1 = 0b011;
    insn.cpp_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.cpp_sys_cr_systeminstrs.L = 0b0;
    insn.cpp_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.cpp_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.cpp_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_csdb_hi_hints() {
    ControlEncoding insn = {};
    insn.csdb_hi_hints._unnamed_3 = 0b11111;
    insn.csdb_hi_hints.op2 = 0b100;
    insn.csdb_hi_hints.CRm = 0b0010;
    insn.csdb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.csdb_hi_hints._unnamed_1 = 0b101;
    insn.csdb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dc_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1) {
    ControlEncoding insn = {};
    insn.dc_sys_cr_systeminstrs.Rt = Rt;
    insn.dc_sys_cr_systeminstrs.op2 = op2;
    insn.dc_sys_cr_systeminstrs.CRm = CRm;
    insn.dc_sys_cr_systeminstrs.CRn = 0b0111;
    insn.dc_sys_cr_systeminstrs.op1 = op1;
    insn.dc_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.dc_sys_cr_systeminstrs.L = 0b0;
    insn.dc_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.dc_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.dc_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dcps1_dc_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.dcps1dc_exception.LL = 0b01;
    insn.dcps1dc_exception.op2 = 0b000;
    insn.dcps1dc_exception.imm16 = imm16;
    insn.dcps1dc_exception.opc = 0b101;
    insn.dcps1dc_exception._unnamed_2 = 0b00;
    insn.dcps1dc_exception._unnamed_1 = 0b101;
    insn.dcps1dc_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dcps2_dc_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.dcps2dc_exception.LL = 0b10;
    insn.dcps2dc_exception.op2 = 0b000;
    insn.dcps2dc_exception.imm16 = imm16;
    insn.dcps2dc_exception.opc = 0b101;
    insn.dcps2dc_exception._unnamed_2 = 0b00;
    insn.dcps2dc_exception._unnamed_1 = 0b101;
    insn.dcps2dc_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dcps3_dc_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.dcps3dc_exception.LL = 0b11;
    insn.dcps3dc_exception.op2 = 0b000;
    insn.dcps3dc_exception.imm16 = imm16;
    insn.dcps3dc_exception.opc = 0b101;
    insn.dcps3dc_exception._unnamed_2 = 0b00;
    insn.dcps3dc_exception._unnamed_1 = 0b101;
    insn.dcps3dc_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dgh_hi_hints() {
    ControlEncoding insn = {};
    insn.dgh_hi_hints._unnamed_3 = 0b11111;
    insn.dgh_hi_hints.op2 = 0b110;
    insn.dgh_hi_hints.CRm = 0b0000;
    insn.dgh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.dgh_hi_hints._unnamed_1 = 0b101;
    insn.dgh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dmb_bo_barriers(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.dmb_bo_barriers.Rt = 0b11111;
    insn.dmb_bo_barriers.opc = 0b01;
    insn.dmb_bo_barriers._unnamed_3 = 0b1;
    insn.dmb_bo_barriers.CRm = CRm;
    insn.dmb_bo_barriers._unnamed_2 = 0b01000000110011;
    insn.dmb_bo_barriers._unnamed_1 = 0b101;
    insn.dmb_bo_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_drps_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.drps64e_branch_reg.op4 = 0b00000;
    insn.drps64e_branch_reg.Rn = 0b11111;
    insn.drps64e_branch_reg.op3 = 0b000000;
    insn.drps64e_branch_reg.op2 = 0b11111;
    insn.drps64e_branch_reg.opc = 0b0101;
    insn.drps64e_branch_reg._unnamed_2 = 0b1;
    insn.drps64e_branch_reg._unnamed_1 = 0b101;
    insn.drps64e_branch_reg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dsb_bo_barriers(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.dsb_bo_barriers.Rt = 0b11111;
    insn.dsb_bo_barriers.opc = 0b00;
    insn.dsb_bo_barriers._unnamed_3 = 0b1;
    insn.dsb_bo_barriers.CRm = CRm;
    insn.dsb_bo_barriers._unnamed_2 = 0b01000000110011;
    insn.dsb_bo_barriers._unnamed_1 = 0b101;
    insn.dsb_bo_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dsb_bon_barriers(uint32_t imm2) {
    ControlEncoding insn = {};
    insn.dsb_bon_barriers.Rt = 0b11111;
    insn.dsb_bon_barriers.op2 = 0b001;
    insn.dsb_bon_barriers._unnamed_3 = 0b10;
    insn.dsb_bon_barriers.imm2 = imm2;
    insn.dsb_bon_barriers._unnamed_2 = 0b01000000110011;
    insn.dsb_bon_barriers._unnamed_1 = 0b101;
    insn.dsb_bon_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dvp_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.dvp_sys_cr_systeminstrs.Rt = Rt;
    insn.dvp_sys_cr_systeminstrs.op2 = 0b101;
    insn.dvp_sys_cr_systeminstrs.CRm = 0b0011;
    insn.dvp_sys_cr_systeminstrs.CRn = 0b0111;
    insn.dvp_sys_cr_systeminstrs.op1 = 0b011;
    insn.dvp_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.dvp_sys_cr_systeminstrs.L = 0b0;
    insn.dvp_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.dvp_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.dvp_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_eret_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.eret64e_branch_reg.op4 = 0b00000;
    insn.eret64e_branch_reg.Rn = 0b11111;
    insn.eret64e_branch_reg.M = 0b0;
    insn.eret64e_branch_reg.A = 0b0;
    insn.eret64e_branch_reg._unnamed_3 = 0b0000;
    insn.eret64e_branch_reg.op2 = 0b11111;
    insn.eret64e_branch_reg.opc = 0b0100;
    insn.eret64e_branch_reg._unnamed_2 = 0b1;
    insn.eret64e_branch_reg._unnamed_1 = 0b101;
    insn.eret64e_branch_reg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_eretaa_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.eretaa64e_branch_reg.op4 = 0b11111;
    insn.eretaa64e_branch_reg.Rn = 0b11111;
    insn.eretaa64e_branch_reg.M = 0b0;
    insn.eretaa64e_branch_reg.A = 0b1;
    insn.eretaa64e_branch_reg._unnamed_1 = 0b0000;
    insn.eretaa64e_branch_reg.op2 = 0b11111;
    insn.eretaa64e_branch_reg.opc = 0b0100;
    insn.eretaa64e_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_eretab_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.eretab64e_branch_reg.op4 = 0b11111;
    insn.eretab64e_branch_reg.Rn = 0b11111;
    insn.eretab64e_branch_reg.M = 0b1;
    insn.eretab64e_branch_reg.A = 0b1;
    insn.eretab64e_branch_reg._unnamed_1 = 0b0000;
    insn.eretab64e_branch_reg.op2 = 0b11111;
    insn.eretab64e_branch_reg.opc = 0b0100;
    insn.eretab64e_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_esb_hi_hints() {
    ControlEncoding insn = {};
    insn.esb_hi_hints._unnamed_3 = 0b11111;
    insn.esb_hi_hints.op2 = 0b000;
    insn.esb_hi_hints.CRm = 0b0010;
    insn.esb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.esb_hi_hints._unnamed_1 = 0b101;
    insn.esb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcsb_hd_hints() {
    ControlEncoding insn = {};
    insn.gcsb_hd_hints._unnamed_3 = 0b11111;
    insn.gcsb_hd_hints.op2 = 0b011;
    insn.gcsb_hd_hints.CRm = 0b0010;
    insn.gcsb_hd_hints._unnamed_2 = 0b01000000110010;
    insn.gcsb_hd_hints._unnamed_1 = 0b101;
    insn.gcsb_hd_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspopcx_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcspopcx_sys_cr_systeminstrs.Rt = Rt;
    insn.gcspopcx_sys_cr_systeminstrs.op2 = 0b101;
    insn.gcspopcx_sys_cr_systeminstrs.CRm = 0b0111;
    insn.gcspopcx_sys_cr_systeminstrs.CRn = 0b0111;
    insn.gcspopcx_sys_cr_systeminstrs.op1 = 0b000;
    insn.gcspopcx_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gcspopcx_sys_cr_systeminstrs.L = 0b0;
    insn.gcspopcx_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gcspopcx_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gcspopcx_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspopm_sysl_rc_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcspopm_sysl_rc_systeminstrs.Rt = Rt;
    insn.gcspopm_sysl_rc_systeminstrs.op2 = 0b001;
    insn.gcspopm_sysl_rc_systeminstrs.CRm = 0b0111;
    insn.gcspopm_sysl_rc_systeminstrs.CRn = 0b0111;
    insn.gcspopm_sysl_rc_systeminstrs.op1 = 0b011;
    insn.gcspopm_sysl_rc_systeminstrs._unnamed_3 = 0b01;
    insn.gcspopm_sysl_rc_systeminstrs.L = 0b1;
    insn.gcspopm_sysl_rc_systeminstrs._unnamed_2 = 0b0100;
    insn.gcspopm_sysl_rc_systeminstrs._unnamed_1 = 0b101;
    insn.gcspopm_sysl_rc_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspopx_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcspopx_sys_cr_systeminstrs.Rt = Rt;
    insn.gcspopx_sys_cr_systeminstrs.op2 = 0b110;
    insn.gcspopx_sys_cr_systeminstrs.CRm = 0b0111;
    insn.gcspopx_sys_cr_systeminstrs.CRn = 0b0111;
    insn.gcspopx_sys_cr_systeminstrs.op1 = 0b000;
    insn.gcspopx_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gcspopx_sys_cr_systeminstrs.L = 0b0;
    insn.gcspopx_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gcspopx_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gcspopx_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspushm_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcspushm_sys_cr_systeminstrs.Rt = Rt;
    insn.gcspushm_sys_cr_systeminstrs.op2 = 0b000;
    insn.gcspushm_sys_cr_systeminstrs.CRm = 0b0111;
    insn.gcspushm_sys_cr_systeminstrs.CRn = 0b0111;
    insn.gcspushm_sys_cr_systeminstrs.op1 = 0b011;
    insn.gcspushm_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gcspushm_sys_cr_systeminstrs.L = 0b0;
    insn.gcspushm_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gcspushm_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gcspushm_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspushx_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcspushx_sys_cr_systeminstrs.Rt = Rt;
    insn.gcspushx_sys_cr_systeminstrs.op2 = 0b100;
    insn.gcspushx_sys_cr_systeminstrs.CRm = 0b0111;
    insn.gcspushx_sys_cr_systeminstrs.CRn = 0b0111;
    insn.gcspushx_sys_cr_systeminstrs.op1 = 0b000;
    insn.gcspushx_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gcspushx_sys_cr_systeminstrs.L = 0b0;
    insn.gcspushx_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gcspushx_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gcspushx_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcsss1_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcsss1sys_cr_systeminstrs.Rt = Rt;
    insn.gcsss1sys_cr_systeminstrs.op2 = 0b010;
    insn.gcsss1sys_cr_systeminstrs.CRm = 0b0111;
    insn.gcsss1sys_cr_systeminstrs.CRn = 0b0111;
    insn.gcsss1sys_cr_systeminstrs.op1 = 0b011;
    insn.gcsss1sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gcsss1sys_cr_systeminstrs.L = 0b0;
    insn.gcsss1sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gcsss1sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gcsss1sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcsss2_sysl_rc_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.gcsss2sysl_rc_systeminstrs.Rt = Rt;
    insn.gcsss2sysl_rc_systeminstrs.op2 = 0b011;
    insn.gcsss2sysl_rc_systeminstrs.CRm = 0b0111;
    insn.gcsss2sysl_rc_systeminstrs.CRn = 0b0111;
    insn.gcsss2sysl_rc_systeminstrs.op1 = 0b011;
    insn.gcsss2sysl_rc_systeminstrs._unnamed_3 = 0b01;
    insn.gcsss2sysl_rc_systeminstrs.L = 0b1;
    insn.gcsss2sysl_rc_systeminstrs._unnamed_2 = 0b0100;
    insn.gcsss2sysl_rc_systeminstrs._unnamed_1 = 0b101;
    insn.gcsss2sysl_rc_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gic_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1) {
    ControlEncoding insn = {};
    insn.gic_sys_cr_systeminstrs.Rt = Rt;
    insn.gic_sys_cr_systeminstrs.op2 = op2;
    insn.gic_sys_cr_systeminstrs.CRm = CRm;
    insn.gic_sys_cr_systeminstrs.CRn = 0b1100;
    insn.gic_sys_cr_systeminstrs.op1 = op1;
    insn.gic_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gic_sys_cr_systeminstrs.L = 0b0;
    insn.gic_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gic_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gic_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gicr_sysl_rc_systeminstrs(uint32_t Rt, uint32_t op2) {
    ControlEncoding insn = {};
    insn.gicr_sysl_rc_systeminstrs.Rt = Rt;
    insn.gicr_sysl_rc_systeminstrs.op2 = op2;
    insn.gicr_sysl_rc_systeminstrs.CRm = 0b0011;
    insn.gicr_sysl_rc_systeminstrs.CRn = 0b1100;
    insn.gicr_sysl_rc_systeminstrs.op1 = 0b000;
    insn.gicr_sysl_rc_systeminstrs._unnamed_3 = 0b01;
    insn.gicr_sysl_rc_systeminstrs.L = 0b1;
    insn.gicr_sysl_rc_systeminstrs._unnamed_2 = 0b0100;
    insn.gicr_sysl_rc_systeminstrs._unnamed_1 = 0b101;
    insn.gicr_sysl_rc_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gsb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2) {
    ControlEncoding insn = {};
    insn.gsb_sys_cr_systeminstrs.Rt = Rt;
    insn.gsb_sys_cr_systeminstrs.op2 = op2;
    insn.gsb_sys_cr_systeminstrs.CRm = 0b0000;
    insn.gsb_sys_cr_systeminstrs.CRn = 0b1100;
    insn.gsb_sys_cr_systeminstrs.op1 = 0b000;
    insn.gsb_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.gsb_sys_cr_systeminstrs.L = 0b0;
    insn.gsb_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.gsb_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.gsb_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_hint_hm_hints(uint32_t op2, uint32_t CRm) {
    ControlEncoding insn = {};
    insn.hint_hm_hints._unnamed_3 = 0b11111;
    insn.hint_hm_hints.op2 = op2;
    insn.hint_hm_hints.CRm = CRm;
    insn.hint_hm_hints._unnamed_2 = 0b01000000110010;
    insn.hint_hm_hints._unnamed_1 = 0b101;
    insn.hint_hm_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_hlt_ex_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.hlt_ex_exception.LL = 0b00;
    insn.hlt_ex_exception.op2 = 0b000;
    insn.hlt_ex_exception.imm16 = imm16;
    insn.hlt_ex_exception.opc = 0b010;
    insn.hlt_ex_exception._unnamed_2 = 0b00;
    insn.hlt_ex_exception._unnamed_1 = 0b101;
    insn.hlt_ex_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_hvc_ex_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.hvc_ex_exception.LL = 0b10;
    insn.hvc_ex_exception.op2 = 0b000;
    insn.hvc_ex_exception.imm16 = imm16;
    insn.hvc_ex_exception.opc = 0b000;
    insn.hvc_ex_exception._unnamed_2 = 0b00;
    insn.hvc_ex_exception._unnamed_1 = 0b101;
    insn.hvc_ex_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_ic_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1) {
    ControlEncoding insn = {};
    insn.ic_sys_cr_systeminstrs.Rt = Rt;
    insn.ic_sys_cr_systeminstrs.op2 = op2;
    insn.ic_sys_cr_systeminstrs.CRm = CRm;
    insn.ic_sys_cr_systeminstrs.CRn = 0b0111;
    insn.ic_sys_cr_systeminstrs.op1 = op1;
    insn.ic_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.ic_sys_cr_systeminstrs.L = 0b0;
    insn.ic_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.ic_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.ic_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_isb_bi_barriers(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.isb_bi_barriers.Rt = 0b11111;
    insn.isb_bi_barriers.opc = 0b10;
    insn.isb_bi_barriers._unnamed_3 = 0b1;
    insn.isb_bi_barriers.CRm = CRm;
    insn.isb_bi_barriers._unnamed_2 = 0b01000000110011;
    insn.isb_bi_barriers._unnamed_1 = 0b101;
    insn.isb_bi_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_mlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2) {
    ControlEncoding insn = {};
    insn.mlbi_sys_cr_systeminstrs.Rt = Rt;
    insn.mlbi_sys_cr_systeminstrs.op2 = op2;
    insn.mlbi_sys_cr_systeminstrs.CRm = 0b0000;
    insn.mlbi_sys_cr_systeminstrs.CRn = 0b0111;
    insn.mlbi_sys_cr_systeminstrs.op1 = 0b100;
    insn.mlbi_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.mlbi_sys_cr_systeminstrs.L = 0b0;
    insn.mlbi_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.mlbi_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.mlbi_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_mrrs_rs_systemmovepr(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0) {
    ControlEncoding insn = {};
    insn.mrrs_rs_systemmovepr.Rt = Rt;
    insn.mrrs_rs_systemmovepr.op2 = op2;
    insn.mrrs_rs_systemmovepr.CRm = CRm;
    insn.mrrs_rs_systemmovepr.CRn = CRn;
    insn.mrrs_rs_systemmovepr.op1 = op1;
    insn.mrrs_rs_systemmovepr.o0 = o0;
    insn.mrrs_rs_systemmovepr._unnamed_3 = 0b1;
    insn.mrrs_rs_systemmovepr.L = 0b1;
    insn.mrrs_rs_systemmovepr._unnamed_2 = 0b0101;
    insn.mrrs_rs_systemmovepr._unnamed_1 = 0b101;
    insn.mrrs_rs_systemmovepr._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_mrs_rs_systemmove(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0) {
    ControlEncoding insn = {};
    insn.mrs_rs_systemmove.Rt = Rt;
    insn.mrs_rs_systemmove.op2 = op2;
    insn.mrs_rs_systemmove.CRm = CRm;
    insn.mrs_rs_systemmove.CRn = CRn;
    insn.mrs_rs_systemmove.op1 = op1;
    insn.mrs_rs_systemmove.o0 = o0;
    insn.mrs_rs_systemmove._unnamed_3 = 0b1;
    insn.mrs_rs_systemmove.L = 0b1;
    insn.mrs_rs_systemmove._unnamed_2 = 0b0100;
    insn.mrs_rs_systemmove._unnamed_1 = 0b101;
    insn.mrs_rs_systemmove._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_msr_si_pstate(uint32_t op2, uint32_t CRm, uint32_t op1) {
    ControlEncoding insn = {};
    insn.msr_si_pstate.Rt = 0b11111;
    insn.msr_si_pstate.op2 = op2;
    insn.msr_si_pstate.CRm = CRm;
    insn.msr_si_pstate._unnamed_3 = 0b0100;
    insn.msr_si_pstate.op1 = op1;
    insn.msr_si_pstate._unnamed_2 = 0b0100000;
    insn.msr_si_pstate._unnamed_1 = 0b101;
    insn.msr_si_pstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_msr_sr_systemmove(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0) {
    ControlEncoding insn = {};
    insn.msr_sr_systemmove.Rt = Rt;
    insn.msr_sr_systemmove.op2 = op2;
    insn.msr_sr_systemmove.CRm = CRm;
    insn.msr_sr_systemmove.CRn = CRn;
    insn.msr_sr_systemmove.op1 = op1;
    insn.msr_sr_systemmove.o0 = o0;
    insn.msr_sr_systemmove._unnamed_3 = 0b1;
    insn.msr_sr_systemmove.L = 0b0;
    insn.msr_sr_systemmove._unnamed_2 = 0b0100;
    insn.msr_sr_systemmove._unnamed_1 = 0b101;
    insn.msr_sr_systemmove._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_msrr_sr_systemmovepr(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1, uint32_t o0) {
    ControlEncoding insn = {};
    insn.msrr_sr_systemmovepr.Rt = Rt;
    insn.msrr_sr_systemmovepr.op2 = op2;
    insn.msrr_sr_systemmovepr.CRm = CRm;
    insn.msrr_sr_systemmovepr.CRn = CRn;
    insn.msrr_sr_systemmovepr.op1 = op1;
    insn.msrr_sr_systemmovepr.o0 = o0;
    insn.msrr_sr_systemmovepr._unnamed_3 = 0b1;
    insn.msrr_sr_systemmovepr.L = 0b0;
    insn.msrr_sr_systemmovepr._unnamed_2 = 0b0101;
    insn.msrr_sr_systemmovepr._unnamed_1 = 0b101;
    insn.msrr_sr_systemmovepr._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_nop_hi_hints() {
    ControlEncoding insn = {};
    insn.nop_hi_hints._unnamed_3 = 0b11111;
    insn.nop_hi_hints.op2 = 0b000;
    insn.nop_hi_hints.CRm = 0b0000;
    insn.nop_hi_hints._unnamed_2 = 0b01000000110010;
    insn.nop_hi_hints._unnamed_1 = 0b101;
    insn.nop_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_pacia1716_hi_hints() {
    ControlEncoding insn = {};
    insn.pacia1716hi_hints._unnamed_1 = 0b11111;
    insn.pacia1716hi_hints.op2 = 0b000;
    insn.pacia1716hi_hints.CRm = 0b0001;
    insn.pacia1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_paciasp_hi_hints() {
    ControlEncoding insn = {};
    insn.paciasp_hi_hints._unnamed_1 = 0b11111;
    insn.paciasp_hi_hints.op2 = 0b001;
    insn.paciasp_hi_hints.CRm = 0b0011;
    insn.paciasp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_paciaz_hi_hints() {
    ControlEncoding insn = {};
    insn.paciaz_hi_hints._unnamed_1 = 0b11111;
    insn.paciaz_hi_hints.op2 = 0b000;
    insn.paciaz_hi_hints.CRm = 0b0011;
    insn.paciaz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacib1716_hi_hints() {
    ControlEncoding insn = {};
    insn.pacib1716hi_hints._unnamed_1 = 0b11111;
    insn.pacib1716hi_hints.op2 = 0b010;
    insn.pacib1716hi_hints.CRm = 0b0001;
    insn.pacib1716hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacibsp_hi_hints() {
    ControlEncoding insn = {};
    insn.pacibsp_hi_hints._unnamed_1 = 0b11111;
    insn.pacibsp_hi_hints.op2 = 0b011;
    insn.pacibsp_hi_hints.CRm = 0b0011;
    insn.pacibsp_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacibz_hi_hints() {
    ControlEncoding insn = {};
    insn.pacibz_hi_hints._unnamed_1 = 0b11111;
    insn.pacibz_hi_hints.op2 = 0b010;
    insn.pacibz_hi_hints.CRm = 0b0011;
    insn.pacibz_hi_hints._unnamed_0 = 0b11010101000000110010;
    return insn.raw;
}

uint32_t encode_pacm_hi_hints() {
    ControlEncoding insn = {};
    insn.pacm_hi_hints._unnamed_3 = 0b11111;
    insn.pacm_hi_hints.op2 = 0b111;
    insn.pacm_hi_hints.CRm = 0b0100;
    insn.pacm_hi_hints._unnamed_2 = 0b01000000110010;
    insn.pacm_hi_hints._unnamed_1 = 0b101;
    insn.pacm_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_psb_hc_hints() {
    ControlEncoding insn = {};
    insn.psb_hc_hints._unnamed_3 = 0b11111;
    insn.psb_hc_hints.op2 = 0b001;
    insn.psb_hc_hints.CRm = 0b0010;
    insn.psb_hc_hints._unnamed_2 = 0b01000000110010;
    insn.psb_hc_hints._unnamed_1 = 0b101;
    insn.psb_hc_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_pssbb_dsb_bo_barriers() {
    ControlEncoding insn = {};
    insn.pssbb_dsb_bo_barriers.Rt = 0b11111;
    insn.pssbb_dsb_bo_barriers.opc = 0b00;
    insn.pssbb_dsb_bo_barriers._unnamed_3 = 0b1;
    insn.pssbb_dsb_bo_barriers.CRm = 0b0100;
    insn.pssbb_dsb_bo_barriers._unnamed_2 = 0b01000000110011;
    insn.pssbb_dsb_bo_barriers._unnamed_1 = 0b101;
    insn.pssbb_dsb_bo_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_ret_64r_branch_reg(uint32_t Rn) {
    ControlEncoding insn = {};
    insn.ret64r_branch_reg.Rm = 0b00000;
    insn.ret64r_branch_reg.Rn = Rn;
    insn.ret64r_branch_reg.M = 0b0;
    insn.ret64r_branch_reg.A = 0b0;
    insn.ret64r_branch_reg._unnamed_4 = 0b0000;
    insn.ret64r_branch_reg.op2 = 0b11111;
    insn.ret64r_branch_reg.op = 0b10;
    insn.ret64r_branch_reg._unnamed_3 = 0b0;
    insn.ret64r_branch_reg.Z = 0b0;
    insn.ret64r_branch_reg._unnamed_2 = 0b1;
    insn.ret64r_branch_reg._unnamed_1 = 0b101;
    insn.ret64r_branch_reg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_retaa_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.retaa64e_branch_reg.Rm = 0b11111;
    insn.retaa64e_branch_reg.Rn = 0b11111;
    insn.retaa64e_branch_reg.M = 0b0;
    insn.retaa64e_branch_reg.A = 0b1;
    insn.retaa64e_branch_reg._unnamed_2 = 0b0000;
    insn.retaa64e_branch_reg.op2 = 0b11111;
    insn.retaa64e_branch_reg.op = 0b10;
    insn.retaa64e_branch_reg._unnamed_1 = 0b0;
    insn.retaa64e_branch_reg.Z = 0b0;
    insn.retaa64e_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_retab_64e_branch_reg() {
    ControlEncoding insn = {};
    insn.retab64e_branch_reg.Rm = 0b11111;
    insn.retab64e_branch_reg.Rn = 0b11111;
    insn.retab64e_branch_reg.M = 0b1;
    insn.retab64e_branch_reg.A = 0b1;
    insn.retab64e_branch_reg._unnamed_2 = 0b0000;
    insn.retab64e_branch_reg.op2 = 0b11111;
    insn.retab64e_branch_reg.op = 0b10;
    insn.retab64e_branch_reg._unnamed_1 = 0b0;
    insn.retab64e_branch_reg.Z = 0b0;
    insn.retab64e_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_retaasppc_only_miscbranch(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.retaasppc_only_miscbranch.op2 = 0b11111;
    insn.retaasppc_only_miscbranch.imm16 = imm16;
    insn.retaasppc_only_miscbranch.opc = 0b000;
    insn.retaasppc_only_miscbranch._unnamed_0 = 0b01010101;
    return insn.raw;
}

uint32_t encode_retabsppc_only_miscbranch(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.retabsppc_only_miscbranch.op2 = 0b11111;
    insn.retabsppc_only_miscbranch.imm16 = imm16;
    insn.retabsppc_only_miscbranch.opc = 0b001;
    insn.retabsppc_only_miscbranch._unnamed_0 = 0b01010101;
    return insn.raw;
}

uint32_t encode_retaasppcr_64m_branch_reg(uint32_t Rm) {
    ControlEncoding insn = {};
    insn.retaasppcr64m_branch_reg.Rm = Rm;
    insn.retaasppcr64m_branch_reg.Rn = 0b11111;
    insn.retaasppcr64m_branch_reg.M = 0b0;
    insn.retaasppcr64m_branch_reg._unnamed_1 = 0b00001;
    insn.retaasppcr64m_branch_reg.op2 = 0b11111;
    insn.retaasppcr64m_branch_reg.opc = 0b0010;
    insn.retaasppcr64m_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_retabsppcr_64m_branch_reg(uint32_t Rm) {
    ControlEncoding insn = {};
    insn.retabsppcr64m_branch_reg.Rm = Rm;
    insn.retabsppcr64m_branch_reg.Rn = 0b11111;
    insn.retabsppcr64m_branch_reg.M = 0b1;
    insn.retabsppcr64m_branch_reg._unnamed_1 = 0b00001;
    insn.retabsppcr64m_branch_reg.op2 = 0b11111;
    insn.retabsppcr64m_branch_reg.opc = 0b0010;
    insn.retabsppcr64m_branch_reg._unnamed_0 = 0b1101011;
    return insn.raw;
}

uint32_t encode_sb_only_barriers() {
    ControlEncoding insn = {};
    insn.sb_only_barriers.Rt = 0b11111;
    insn.sb_only_barriers.opc = 0b11;
    insn.sb_only_barriers._unnamed_3 = 0b1;
    insn.sb_only_barriers.CRm = 0b0000;
    insn.sb_only_barriers._unnamed_2 = 0b01000000110011;
    insn.sb_only_barriers._unnamed_1 = 0b101;
    insn.sb_only_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sev_hi_hints() {
    ControlEncoding insn = {};
    insn.sev_hi_hints._unnamed_3 = 0b11111;
    insn.sev_hi_hints.op2 = 0b100;
    insn.sev_hi_hints.CRm = 0b0000;
    insn.sev_hi_hints._unnamed_2 = 0b01000000110010;
    insn.sev_hi_hints._unnamed_1 = 0b101;
    insn.sev_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sevl_hi_hints() {
    ControlEncoding insn = {};
    insn.sevl_hi_hints._unnamed_3 = 0b11111;
    insn.sevl_hi_hints.op2 = 0b101;
    insn.sevl_hi_hints.CRm = 0b0000;
    insn.sevl_hi_hints._unnamed_2 = 0b01000000110010;
    insn.sevl_hi_hints._unnamed_1 = 0b101;
    insn.sevl_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_shuh_hi_hints(uint32_t op2) {
    ControlEncoding insn = {};
    insn.shuh_hi_hints._unnamed_3 = 0b11111;
    insn.shuh_hi_hints.op2 = op2;
    insn.shuh_hi_hints.CRm = 0b0110;
    insn.shuh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.shuh_hi_hints._unnamed_1 = 0b101;
    insn.shuh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_smc_ex_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.smc_ex_exception.LL = 0b11;
    insn.smc_ex_exception.op2 = 0b000;
    insn.smc_ex_exception.imm16 = imm16;
    insn.smc_ex_exception.opc = 0b000;
    insn.smc_ex_exception._unnamed_2 = 0b00;
    insn.smc_ex_exception._unnamed_1 = 0b101;
    insn.smc_ex_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_smstart_msr_si_pstate(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.smstart_msr_si_pstate.Rt = 0b11111;
    insn.smstart_msr_si_pstate.op2 = 0b011;
    insn.smstart_msr_si_pstate.CRm = CRm;
    insn.smstart_msr_si_pstate._unnamed_3 = 0b0100;
    insn.smstart_msr_si_pstate.op1 = 0b011;
    insn.smstart_msr_si_pstate._unnamed_2 = 0b0100000;
    insn.smstart_msr_si_pstate._unnamed_1 = 0b101;
    insn.smstart_msr_si_pstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_smstop_msr_si_pstate(uint32_t CRm) {
    ControlEncoding insn = {};
    insn.smstop_msr_si_pstate.Rt = 0b11111;
    insn.smstop_msr_si_pstate.op2 = 0b011;
    insn.smstop_msr_si_pstate.CRm = CRm;
    insn.smstop_msr_si_pstate._unnamed_3 = 0b0100;
    insn.smstop_msr_si_pstate.op1 = 0b011;
    insn.smstop_msr_si_pstate._unnamed_2 = 0b0100000;
    insn.smstop_msr_si_pstate._unnamed_1 = 0b101;
    insn.smstop_msr_si_pstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_ssbb_dsb_bo_barriers() {
    ControlEncoding insn = {};
    insn.ssbb_dsb_bo_barriers.Rt = 0b11111;
    insn.ssbb_dsb_bo_barriers.opc = 0b00;
    insn.ssbb_dsb_bo_barriers._unnamed_3 = 0b1;
    insn.ssbb_dsb_bo_barriers.CRm = 0b0000;
    insn.ssbb_dsb_bo_barriers._unnamed_2 = 0b01000000110011;
    insn.ssbb_dsb_bo_barriers._unnamed_1 = 0b101;
    insn.ssbb_dsb_bo_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_stcph_hi_hints() {
    ControlEncoding insn = {};
    insn.stcph_hi_hints._unnamed_3 = 0b11111;
    insn.stcph_hi_hints.op2 = 0b100;
    insn.stcph_hi_hints.CRm = 0b0110;
    insn.stcph_hi_hints._unnamed_2 = 0b01000000110010;
    insn.stcph_hi_hints._unnamed_1 = 0b101;
    insn.stcph_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_stshh_hi_hints(uint32_t op2) {
    ControlEncoding insn = {};
    insn.stshh_hi_hints._unnamed_3 = 0b11111;
    insn.stshh_hi_hints.op2 = op2;
    insn.stshh_hi_hints.CRm = 0b0110;
    insn.stshh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.stshh_hi_hints._unnamed_1 = 0b101;
    insn.stshh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_svc_ex_exception(uint32_t imm16) {
    ControlEncoding insn = {};
    insn.svc_ex_exception.LL = 0b01;
    insn.svc_ex_exception.op2 = 0b000;
    insn.svc_ex_exception.imm16 = imm16;
    insn.svc_ex_exception.opc = 0b000;
    insn.svc_ex_exception._unnamed_2 = 0b00;
    insn.svc_ex_exception._unnamed_1 = 0b101;
    insn.svc_ex_exception._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    ControlEncoding insn = {};
    insn.sys_cr_systeminstrs.Rt = Rt;
    insn.sys_cr_systeminstrs.op2 = op2;
    insn.sys_cr_systeminstrs.CRm = CRm;
    insn.sys_cr_systeminstrs.CRn = CRn;
    insn.sys_cr_systeminstrs.op1 = op1;
    insn.sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.sys_cr_systeminstrs.L = 0b0;
    insn.sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sysl_rc_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    ControlEncoding insn = {};
    insn.sysl_rc_systeminstrs.Rt = Rt;
    insn.sysl_rc_systeminstrs.op2 = op2;
    insn.sysl_rc_systeminstrs.CRm = CRm;
    insn.sysl_rc_systeminstrs.CRn = CRn;
    insn.sysl_rc_systeminstrs.op1 = op1;
    insn.sysl_rc_systeminstrs._unnamed_3 = 0b01;
    insn.sysl_rc_systeminstrs.L = 0b1;
    insn.sysl_rc_systeminstrs._unnamed_2 = 0b0100;
    insn.sysl_rc_systeminstrs._unnamed_1 = 0b101;
    insn.sysl_rc_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sysp_cr_syspairinstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    ControlEncoding insn = {};
    insn.sysp_cr_syspairinstrs.Rt = Rt;
    insn.sysp_cr_syspairinstrs.op2 = op2;
    insn.sysp_cr_syspairinstrs.CRm = CRm;
    insn.sysp_cr_syspairinstrs.CRn = CRn;
    insn.sysp_cr_syspairinstrs.op1 = op1;
    insn.sysp_cr_syspairinstrs._unnamed_3 = 0b01;
    insn.sysp_cr_syspairinstrs.L = 0b0;
    insn.sysp_cr_syspairinstrs._unnamed_2 = 0b0101;
    insn.sysp_cr_syspairinstrs._unnamed_1 = 0b101;
    insn.sysp_cr_syspairinstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_tbnz_only_testbranch(uint32_t Rt, int32_t imm14, uint32_t b40, uint32_t b5) {
    ControlEncoding insn = {};
    insn.tbnz_only_testbranch.Rt = Rt;
    insn.tbnz_only_testbranch.imm14 = imm14;
    insn.tbnz_only_testbranch.b40 = b40;
    insn.tbnz_only_testbranch.op = 0b1;
    insn.tbnz_only_testbranch._unnamed_2 = 0b1;
    insn.tbnz_only_testbranch._unnamed_1 = 0b101;
    insn.tbnz_only_testbranch._unnamed_0 = 0b01;
    insn.tbnz_only_testbranch.b5 = b5;
    return insn.raw;
}

uint32_t encode_tbz_only_testbranch(uint32_t Rt, int32_t imm14, uint32_t b40, uint32_t b5) {
    ControlEncoding insn = {};
    insn.tbz_only_testbranch.Rt = Rt;
    insn.tbz_only_testbranch.imm14 = imm14;
    insn.tbz_only_testbranch.b40 = b40;
    insn.tbz_only_testbranch.op = 0b0;
    insn.tbz_only_testbranch._unnamed_2 = 0b1;
    insn.tbz_only_testbranch._unnamed_1 = 0b101;
    insn.tbz_only_testbranch._unnamed_0 = 0b01;
    insn.tbz_only_testbranch.b5 = b5;
    return insn.raw;
}

uint32_t encode_tlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    ControlEncoding insn = {};
    insn.tlbi_sys_cr_systeminstrs.Rt = Rt;
    insn.tlbi_sys_cr_systeminstrs.op2 = op2;
    insn.tlbi_sys_cr_systeminstrs.CRm = CRm;
    insn.tlbi_sys_cr_systeminstrs.CRn = CRn;
    insn.tlbi_sys_cr_systeminstrs.op1 = op1;
    insn.tlbi_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.tlbi_sys_cr_systeminstrs.L = 0b0;
    insn.tlbi_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.tlbi_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.tlbi_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_tlbip_sysp_cr_syspairinstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    ControlEncoding insn = {};
    insn.tlbip_sysp_cr_syspairinstrs.Rt = Rt;
    insn.tlbip_sysp_cr_syspairinstrs.op2 = op2;
    insn.tlbip_sysp_cr_syspairinstrs.CRm = CRm;
    insn.tlbip_sysp_cr_syspairinstrs.CRn = CRn;
    insn.tlbip_sysp_cr_syspairinstrs.op1 = op1;
    insn.tlbip_sysp_cr_syspairinstrs._unnamed_3 = 0b01;
    insn.tlbip_sysp_cr_syspairinstrs.L = 0b0;
    insn.tlbip_sysp_cr_syspairinstrs._unnamed_2 = 0b0101;
    insn.tlbip_sysp_cr_syspairinstrs._unnamed_1 = 0b101;
    insn.tlbip_sysp_cr_syspairinstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_trcit_sys_cr_systeminstrs(uint32_t Rt) {
    ControlEncoding insn = {};
    insn.trcit_sys_cr_systeminstrs.Rt = Rt;
    insn.trcit_sys_cr_systeminstrs.op2 = 0b111;
    insn.trcit_sys_cr_systeminstrs.CRm = 0b0010;
    insn.trcit_sys_cr_systeminstrs.CRn = 0b0111;
    insn.trcit_sys_cr_systeminstrs.op1 = 0b011;
    insn.trcit_sys_cr_systeminstrs._unnamed_3 = 0b01;
    insn.trcit_sys_cr_systeminstrs.L = 0b0;
    insn.trcit_sys_cr_systeminstrs._unnamed_2 = 0b0100;
    insn.trcit_sys_cr_systeminstrs._unnamed_1 = 0b101;
    insn.trcit_sys_cr_systeminstrs._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_tsb_hc_hints() {
    ControlEncoding insn = {};
    insn.tsb_hc_hints._unnamed_3 = 0b11111;
    insn.tsb_hc_hints.op2 = 0b010;
    insn.tsb_hc_hints.CRm = 0b0010;
    insn.tsb_hc_hints._unnamed_2 = 0b01000000110010;
    insn.tsb_hc_hints._unnamed_1 = 0b101;
    insn.tsb_hc_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfe_hi_hints() {
    ControlEncoding insn = {};
    insn.wfe_hi_hints._unnamed_3 = 0b11111;
    insn.wfe_hi_hints.op2 = 0b010;
    insn.wfe_hi_hints.CRm = 0b0000;
    insn.wfe_hi_hints._unnamed_2 = 0b01000000110010;
    insn.wfe_hi_hints._unnamed_1 = 0b101;
    insn.wfe_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfet_only_systeminstrswithreg(uint32_t Rd) {
    ControlEncoding insn = {};
    insn.wfet_only_systeminstrswithreg.Rd = Rd;
    insn.wfet_only_systeminstrswithreg.op2 = 0b000;
    insn.wfet_only_systeminstrswithreg.CRm = 0b0000;
    insn.wfet_only_systeminstrswithreg._unnamed_2 = 0b01000000110001;
    insn.wfet_only_systeminstrswithreg._unnamed_1 = 0b101;
    insn.wfet_only_systeminstrswithreg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfi_hi_hints() {
    ControlEncoding insn = {};
    insn.wfi_hi_hints._unnamed_3 = 0b11111;
    insn.wfi_hi_hints.op2 = 0b011;
    insn.wfi_hi_hints.CRm = 0b0000;
    insn.wfi_hi_hints._unnamed_2 = 0b01000000110010;
    insn.wfi_hi_hints._unnamed_1 = 0b101;
    insn.wfi_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfit_only_systeminstrswithreg(uint32_t Rd) {
    ControlEncoding insn = {};
    insn.wfit_only_systeminstrswithreg.Rd = Rd;
    insn.wfit_only_systeminstrswithreg.op2 = 0b001;
    insn.wfit_only_systeminstrswithreg.CRm = 0b0000;
    insn.wfit_only_systeminstrswithreg._unnamed_2 = 0b01000000110001;
    insn.wfit_only_systeminstrswithreg._unnamed_1 = 0b101;
    insn.wfit_only_systeminstrswithreg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_xaflag_m_pstate() {
    ControlEncoding insn = {};
    insn.xaflag_mpstate.Rt = 0b11111;
    insn.xaflag_mpstate.op2 = 0b001;
    insn.xaflag_mpstate.CRm = 0b0000;
    insn.xaflag_mpstate._unnamed_3 = 0b0100;
    insn.xaflag_mpstate.op1 = 0b000;
    insn.xaflag_mpstate._unnamed_2 = 0b0100000;
    insn.xaflag_mpstate._unnamed_1 = 0b101;
    insn.xaflag_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_xpaclri_hi_hints() {
    ControlEncoding insn = {};
    insn.xpaclri_hi_hints._unnamed_3 = 0b11111;
    insn.xpaclri_hi_hints.op2 = 0b111;
    insn.xpaclri_hi_hints.CRm = 0b0000;
    insn.xpaclri_hi_hints._unnamed_2 = 0b01000000110010;
    insn.xpaclri_hi_hints._unnamed_1 = 0b101;
    insn.xpaclri_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_yield_hi_hints() {
    ControlEncoding insn = {};
    insn.yield_hi_hints._unnamed_3 = 0b11111;
    insn.yield_hi_hints.op2 = 0b001;
    insn.yield_hi_hints.CRm = 0b0000;
    insn.yield_hi_hints._unnamed_2 = 0b01000000110010;
    insn.yield_hi_hints._unnamed_1 = 0b101;
    insn.yield_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

// Decode a control instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_control(uint32_t insn) {
    // Switch for mask 0xFFFFFFFFu (37 patterns, 37 encodings)
    switch (insn & 0xFFFFFFFFu) {
        case 0xD503201Fu: { // NOP_HI_hints
                        Instruction result(Mnemonic::NOP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503203Fu: { // YIELD_HI_hints
                        Instruction result(Mnemonic::YIELD, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503205Fu: { // WFE_HI_hints
                        Instruction result(Mnemonic::WFE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503207Fu: { // WFI_HI_hints
                        Instruction result(Mnemonic::WFI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503209Fu: { // SEV_HI_hints
                        Instruction result(Mnemonic::SEV, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50320BFu: { // SEVL_HI_hints
                        Instruction result(Mnemonic::SEVL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50320DFu: { // DGH_HI_hints
                        Instruction result(Mnemonic::DGH, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50320FFu: { // XPACLRI_HI_hints
                        Instruction result(Mnemonic::XPACLRI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503211Fu: { // PACIA1716_HI_hints
                        Instruction result(Mnemonic::PACIA1716, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503215Fu: { // PACIB1716_HI_hints
                        Instruction result(Mnemonic::PACIB1716, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503219Fu: { // AUTIA1716_HI_hints
                        Instruction result(Mnemonic::AUTIA1716, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50321DFu: { // AUTIB1716_HI_hints
                        Instruction result(Mnemonic::AUTIB1716, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503221Fu: { // ESB_HI_hints
                        Instruction result(Mnemonic::ESB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503223Fu: { // PSB_HC_hints
                        Instruction result(Mnemonic::PSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503225Fu: { // TSB_HC_hints
                        Instruction result(Mnemonic::TSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503227Fu: { // GCSB_HD_hints
                        Instruction result(Mnemonic::GCSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503229Fu: { // CSDB_HI_hints
                        Instruction result(Mnemonic::CSDB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50322DFu: { // CLRBHB_HI_hints
                        Instruction result(Mnemonic::CLRBHB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503231Fu: { // PACIAZ_HI_hints
                        Instruction result(Mnemonic::PACIAZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503233Fu: { // PACIASP_HI_hints
                        Instruction result(Mnemonic::PACIASP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503235Fu: { // PACIBZ_HI_hints
                        Instruction result(Mnemonic::PACIBZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503237Fu: { // PACIBSP_HI_hints
                        Instruction result(Mnemonic::PACIBSP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503239Fu: { // AUTIAZ_HI_hints
                        Instruction result(Mnemonic::AUTIAZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50323BFu: { // AUTIASP_HI_hints
                        Instruction result(Mnemonic::AUTIASP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50323DFu: { // AUTIBZ_HI_hints
                        Instruction result(Mnemonic::AUTIBZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50323FFu: { // AUTIBSP_HI_hints
                        Instruction result(Mnemonic::AUTIBSP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50324FFu: { // PACM_HI_hints
                        Instruction result(Mnemonic::PACM, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503251Fu: { // CHKFEAT_HF_hints
                        Instruction result(Mnemonic::CHKFEAT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503269Fu: { // STCPH_HI_hints
                        Instruction result(Mnemonic::STCPH, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503309Fu: { // SSBB_DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503349Fu: { // PSSBB_DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD65F0BFFu: { // RETAA_64E_branch_reg
                        Instruction result(Mnemonic::RETAA, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD65F0FFFu: { // RETAB_64E_branch_reg
                        Instruction result(Mnemonic::RETAB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD69F03E0u: { // ERET_64E_branch_reg
                        Instruction result(Mnemonic::ERET, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD69F0BFFu: { // ERETAA_64E_branch_reg
                        Instruction result(Mnemonic::ERETAA, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD69F0FFFu: { // ERETAB_64E_branch_reg
                        Instruction result(Mnemonic::ERETAB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD6BF03E0u: { // DRPS_64E_branch_reg
                        Instruction result(Mnemonic::DRPS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFE0u (17 patterns, 17 encodings)
    switch (insn & 0xFFFFFFE0u) {
        case 0xD5031000u: { // WFET_only_systeminstrswithreg
                        Instruction result(Mnemonic::WFET, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.wfet_only_systeminstrswithreg.Rd, is_64bit));
                        return result;
        }
        case 0xD5031020u: { // WFIT_only_systeminstrswithreg
                        Instruction result(Mnemonic::WFIT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.wfit_only_systeminstrswithreg.Rd, is_64bit));
                        return result;
        }
        case 0xD5087780u: { // GCSPUSHX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspushx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50877A0u: { // GCSPOPCX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopcx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50877C0u: { // GCSPOPX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B72E0u: { // TRCIT_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.trcit_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7380u: { // CFP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cfp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73A0u: { // DVP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.dvp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73C0u: { // COSP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cosp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73E0u: { // CPP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cpp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7700u: { // GCSPUSHM_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspushm_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7740u: { // GCSSS1_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcsss1sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50E7000u: { // APAS_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.apas_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD52B7720u: { // GCSPOPM_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopm_sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD52B7760u: { // GCSSS2_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcsss2sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD65F0BE0u: { // RETAASPPCR_64M_branch_reg
            if (((insn >> 0) & 0x1F) == 0x1F) break;
                        Instruction result(Mnemonic::RETAASPPCR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.retaasppcr64m_branch_reg.Rm, is_64bit));
                        return result;
        }
        case 0xD65F0FE0u: { // RETABSPPCR_64M_branch_reg
            if (((insn >> 0) & 0x1F) == 0x1F) break;
                        Instruction result(Mnemonic::RETABSPPCR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.retabsppcr64m_branch_reg.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFDFu (2 patterns, 2 encodings)
    switch (insn & 0xFFFFFFDFu) {
        case 0xD503261Fu: { // STSHH_HI_hints
                        Instruction result(Mnemonic::STSHH, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503265Fu: { // SHUH_HI_hints
                        Instruction result(Mnemonic::SHUH, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFF80u (1 pattern, 1 encoding)
    switch (insn & 0xFFFFFF80u) {
        case 0xD50C7080u: { // MLBI_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mlbi_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFF3Fu (1 pattern, 1 encoding)
    switch (insn & 0xFFFFFF3Fu) {
        case 0xD503241Fu: { // BTI_HB_hints
                        Instruction result(Mnemonic::BTI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFF00u (3 patterns, 3 encodings)
    switch (insn & 0xFFFFFF00u) {
        case 0xD508C000u: { // GSB_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gsb_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5097200u: { // BRB_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.brb_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD528C300u: { // GICR_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gicr_sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFE00u (1 pattern, 1 encoding)
    switch (insn & 0xFFFFFE00u) {
        case 0xD508C400u: { // GIC_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gic_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFC1Fu (7 patterns, 7 encodings)
    switch (insn & 0xFFFFFC1Fu) {
        case 0xD61F0000u: { // BR_64_branch_reg
                        Instruction result(Mnemonic::BR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.br64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD61F081Fu: { // BRAAZ_64_branch_reg
                        Instruction result(Mnemonic::BRAAZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.braaz64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD61F0C1Fu: { // BRABZ_64_branch_reg
                        Instruction result(Mnemonic::BRABZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.brabz64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD63F0000u: { // BLR_64_branch_reg
                        Instruction result(Mnemonic::BLR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.blr64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD63F081Fu: { // BLRAAZ_64_branch_reg
                        Instruction result(Mnemonic::BLRAAZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.blraaz64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD63F0C1Fu: { // BLRABZ_64_branch_reg
                        Instruction result(Mnemonic::BLRABZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.blrabz64branch_reg.Rn, is_64bit));
                        return result;
        }
        case 0xD65F0000u: { // RET_64R_branch_reg
                        Instruction result(Mnemonic::RET, insn);
                        // RET - X30 is implicit, no operands needed
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFC00u (4 patterns, 4 encodings)
    switch (insn & 0xFFFFFC00u) {
        case 0xD71F0800u: { // BRAA_64P_branch_reg
                        Instruction result(Mnemonic::BRAA, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.braa64p_branch_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.braa64p_branch_reg.Rm, is_64bit));
                        return result;
        }
        case 0xD71F0C00u: { // BRAB_64P_branch_reg
                        Instruction result(Mnemonic::BRAB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.brab64p_branch_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.brab64p_branch_reg.Rm, is_64bit));
                        return result;
        }
        case 0xD73F0800u: { // BLRAA_64P_branch_reg
                        Instruction result(Mnemonic::BLRAA, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.blraa64p_branch_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.blraa64p_branch_reg.Rm, is_64bit));
                        return result;
        }
        case 0xD73F0C00u: { // BLRAB_64P_branch_reg
                        Instruction result(Mnemonic::BLRAB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.blrab64p_branch_reg.Rn, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.blrab64p_branch_reg.Rm, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF9FFu (2 patterns, 2 encodings)
    switch (insn & 0xFFFFF9FFu) {
        case 0xD503407Fu: { // SMSTOP_MSR_SI_pstate
                        Instruction result(Mnemonic::MSR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503417Fu: { // SMSTART_MSR_SI_pstate
                        Instruction result(Mnemonic::MSR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF3FFu (1 pattern, 1 encoding)
    switch (insn & 0xFFFFF3FFu) {
        case 0xD503323Fu: { // DSB_BOn_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dsb_bon_barriers.imm2, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF0FFu (8 patterns, 8 encodings)
    switch (insn & 0xFFFFF0FFu) {
        case 0xD500401Fu: { // CFINV_M_pstate
                        Instruction result(Mnemonic::CFINV, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD500403Fu: { // XAFLAG_M_pstate
                        Instruction result(Mnemonic::XAFLAG, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD500405Fu: { // AXFLAG_M_pstate
                        Instruction result(Mnemonic::AXFLAG, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503305Fu: { // CLREX_BN_barriers
                        Instruction result(Mnemonic::CLREX, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503309Fu: { // DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Barrier, enc.dsb_bo_barriers.CRm, true));
                        return result;
        }
        case 0xD50330BFu: { // DMB_BO_barriers
                        Instruction result(Mnemonic::DMB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Barrier, enc.dmb_bo_barriers.CRm, true));
                        return result;
        }
        case 0xD50330DFu: { // ISB_BI_barriers
                        Instruction result(Mnemonic::ISB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Barrier, enc.isb_bi_barriers.CRm, true));
                        return result;
        }
        case 0xD50330FFu: { // SB_only_barriers
                        Instruction result(Mnemonic::SB, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF01Fu (1 pattern, 1 encoding)
    switch (insn & 0xFFFFF01Fu) {
        case 0xD503201Fu: { // HINT_HM_hints
                        Instruction result(Mnemonic::HINT, insn);
                        // HINT instruction - decode to alias based on CRm:op2
                        uint32_t CRm = (insn >> 8) & 0xF;
                        uint32_t op2 = (insn >> 5) & 0x7;
                        uint32_t imm7 = (CRm << 3) | op2;
                        switch (imm7) {
                            case 0: result.mnemonic = Mnemonic::NOP; break;
                            case 1: result.mnemonic = Mnemonic::YIELD; break;
                            case 2: result.mnemonic = Mnemonic::WFE; break;
                            case 3: result.mnemonic = Mnemonic::WFI; break;
                            case 4: result.mnemonic = Mnemonic::SEV; break;
                            case 5: result.mnemonic = Mnemonic::SEVL; break;
                            case 6: result.mnemonic = Mnemonic::DGH; break;
                            case 7: result.mnemonic = Mnemonic::XPACLRI; break;
                            case 8: result.mnemonic = Mnemonic::PACIA1716; break;
                            case 10: result.mnemonic = Mnemonic::PACIB1716; break;
                            case 12: result.mnemonic = Mnemonic::AUTIA1716; break;
                            case 14: result.mnemonic = Mnemonic::AUTIB1716; break;
                            case 16: result.mnemonic = Mnemonic::ESB; break;
                            case 17: result.mnemonic = Mnemonic::PSB; break;
                            case 18: result.mnemonic = Mnemonic::TSB; break;
                            case 19: result.mnemonic = Mnemonic::GCSB; break;
                            case 20: result.mnemonic = Mnemonic::CSDB; break;
                            case 22: result.mnemonic = Mnemonic::CLRBHB; break;
                            case 24: result.mnemonic = Mnemonic::PACIAZ; break;
                            case 25: result.mnemonic = Mnemonic::PACIASP; break;
                            case 26: result.mnemonic = Mnemonic::PACIBZ; break;
                            case 27: result.mnemonic = Mnemonic::PACIBSP; break;
                            case 28: result.mnemonic = Mnemonic::AUTIAZ; break;
                            case 29: result.mnemonic = Mnemonic::AUTIASP; break;
                            case 30: result.mnemonic = Mnemonic::AUTIBZ; break;
                            case 31: result.mnemonic = Mnemonic::AUTIBSP; break;
                            default: break; // Keep HINT mnemonic
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF8FE00u (1 pattern, 1 encoding)
    switch (insn & 0xFFF8FE00u) {
        case 0xD5087800u: { // AT_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.at_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF8F01Fu (1 pattern, 1 encoding)
    switch (insn & 0xFFF8F01Fu) {
        case 0xD500401Fu: { // MSR_SI_pstate
                        Instruction result(Mnemonic::MSR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF8F000u (1 pattern, 2 encodings)
    switch (insn & 0xFFF8F000u) {
        case 0xD5087000u: { // DC_SYS_CR_systeminstrs
            // Also matches: IC_SYS_CR_systeminstrs (SYS)
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.dc_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF8E000u (2 patterns, 2 encodings)
    switch (insn & 0xFFF8E000u) {
        case 0xD5088000u: { // TLBI_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tlbi_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5488000u: { // TLBIP_SYSP_CR_syspairinstrs
                        Instruction result(Mnemonic::SYSP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tlbip_sysp_cr_syspairinstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF80000u (3 patterns, 3 encodings)
    switch (insn & 0xFFF80000u) {
        case 0xD5080000u: { // SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5280000u: { // SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5480000u: { // SYSP_CR_syspairinstrs
                        Instruction result(Mnemonic::SYSP, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sysp_cr_syspairinstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFF00000u (4 patterns, 4 encodings)
    switch (insn & 0xFFF00000u) {
        case 0xD5100000u: { // MSR_SR_systemmove
                        Instruction result(Mnemonic::MSR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        uint32_t sysreg = (enc.msr_sr_systemmove.o0 << 14) | (enc.msr_sr_systemmove.op1 << 11) | (enc.msr_sr_systemmove.CRn << 7) | (enc.msr_sr_systemmove.CRm << 3) | enc.msr_sr_systemmove.op2;
                        result.operands.push_back(Operand(OperandType::SystemRegister, sysreg, true));
                        result.operands.push_back(Operand(OperandType::Register, enc.msr_sr_systemmove.Rt, true));
                        return result;
        }
        case 0xD5300000u: { // MRS_RS_systemmove
                        Instruction result(Mnemonic::MRS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.mrs_rs_systemmove.Rt, true));
                        uint32_t sysreg = (enc.mrs_rs_systemmove.o0 << 14) | (enc.mrs_rs_systemmove.op1 << 11) | (enc.mrs_rs_systemmove.CRn << 7) | (enc.mrs_rs_systemmove.CRm << 3) | enc.mrs_rs_systemmove.op2;
                        result.operands.push_back(Operand(OperandType::SystemRegister, sysreg, true));
                        return result;
        }
        case 0xD5500000u: { // MSRR_SR_systemmovepr
                        Instruction result(Mnemonic::MSRR, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.msrr_sr_systemmovepr.Rt, is_64bit));
                        return result;
        }
        case 0xD5700000u: { // MRRS_RS_systemmovepr
                        Instruction result(Mnemonic::MRRS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mrrs_rs_systemmovepr.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0C000u (24 patterns, 40 encodings)
    switch (insn & 0xFFE0C000u) {
        case 0x74000000u: { // CBGT_32_regs
            // Also matches: CBLT_CBGT_32_regs (CBGT)
                        Instruction result(Mnemonic::CBGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbgt32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74008000u: { // CBBGT_8_regs
            // Also matches: CBBLT_CBBGT_8_regs (CBBGT)
                        Instruction result(Mnemonic::CBBGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbgt8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbgt8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbgt8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x7400C000u: { // CBHGT_16_regs
            // Also matches: CBHLT_CBHGT_16_regs (CBHGT)
                        Instruction result(Mnemonic::CBHGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhgt16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhgt16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhgt16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74200000u: { // CBGE_32_regs
            // Also matches: CBLE_CBGE_32_regs (CBGE)
                        Instruction result(Mnemonic::CBGE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbge32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbge32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbge32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74208000u: { // CBBGE_8_regs
            // Also matches: CBBLE_CBBGE_8_regs (CBBGE)
                        Instruction result(Mnemonic::CBBGE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbge8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbge8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbge8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x7420C000u: { // CBHGE_16_regs
            // Also matches: CBHLE_CBHGE_16_regs (CBHGE)
                        Instruction result(Mnemonic::CBHGE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhge16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhge16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhge16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74400000u: { // CBHI_32_regs
            // Also matches: CBLO_CBHI_32_regs (CBHI)
                        Instruction result(Mnemonic::CBHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhi32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74408000u: { // CBBHI_8_regs
            // Also matches: CBBLO_CBBHI_8_regs (CBBHI)
                        Instruction result(Mnemonic::CBBHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbhi8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbhi8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbhi8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x7440C000u: { // CBHHI_16_regs
            // Also matches: CBHLO_CBHHI_16_regs (CBHHI)
                        Instruction result(Mnemonic::CBHHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhhi16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhhi16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhhi16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74600000u: { // CBHS_32_regs
            // Also matches: CBLS_CBHS_32_regs (CBHS)
                        Instruction result(Mnemonic::CBHS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhs32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhs32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhs32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74608000u: { // CBBHS_8_regs
            // Also matches: CBBLS_CBBHS_8_regs (CBBHS)
                        Instruction result(Mnemonic::CBBHS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbhs8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbhs8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbhs8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x7460C000u: { // CBHHS_16_regs
            // Also matches: CBHLS_CBHHS_16_regs (CBHHS)
                        Instruction result(Mnemonic::CBHHS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhhs16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhhs16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhhs16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74C00000u: { // CBEQ_32_regs
                        Instruction result(Mnemonic::CBEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbeq32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74C08000u: { // CBBEQ_8_regs
                        Instruction result(Mnemonic::CBBEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbeq8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbeq8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbeq8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74C0C000u: { // CBHEQ_16_regs
                        Instruction result(Mnemonic::CBHEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbheq16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbheq16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbheq16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74E00000u: { // CBNE_32_regs
                        Instruction result(Mnemonic::CBNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne32regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne32regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbne32regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74E08000u: { // CBBNE_8_regs
                        Instruction result(Mnemonic::CBBNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbne8regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbbne8regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbbne8regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x74E0C000u: { // CBHNE_16_regs
                        Instruction result(Mnemonic::CBHNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhne16regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhne16regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhne16regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4000000u: { // CBGT_64_regs
            // Also matches: CBLT_CBGT_64_regs (CBGT)
                        Instruction result(Mnemonic::CBGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbgt64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4200000u: { // CBGE_64_regs
            // Also matches: CBLE_CBGE_64_regs (CBGE)
                        Instruction result(Mnemonic::CBGE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbge64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbge64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbge64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4400000u: { // CBHI_64_regs
            // Also matches: CBLO_CBHI_64_regs (CBHI)
                        Instruction result(Mnemonic::CBHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhi64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4600000u: { // CBHS_64_regs
            // Also matches: CBLS_CBHS_64_regs (CBHS)
                        Instruction result(Mnemonic::CBHS, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhs64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhs64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhs64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4C00000u: { // CBEQ_64_regs
                        Instruction result(Mnemonic::CBEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbeq64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF4E00000u: { // CBNE_64_regs
                        Instruction result(Mnemonic::CBNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne64regs.Rm, is_64bit));
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne64regs.Rt, is_64bit));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbne64regs.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE04000u (12 patterns, 20 encodings)
    switch (insn & 0xFFE04000u) {
        case 0x75000000u: { // CBGT_32_imm
            // Also matches: CBGE_CBGT_32_imm (CBGT)
                        Instruction result(Mnemonic::CBGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbgt32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbgt32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x75200000u: { // CBLT_32_imm
            // Also matches: CBLE_CBLT_32_imm (CBLT)
                        Instruction result(Mnemonic::CBLT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cblt32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cblt32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cblt32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x75400000u: { // CBHI_32_imm
            // Also matches: CBHS_CBHI_32_imm (CBHI)
                        Instruction result(Mnemonic::CBHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbhi32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhi32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x75600000u: { // CBLO_32_imm
            // Also matches: CBLS_CBLO_32_imm (CBLO)
                        Instruction result(Mnemonic::CBLO, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cblo32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cblo32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cblo32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x75C00000u: { // CBEQ_32_imm
                        Instruction result(Mnemonic::CBEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbeq32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbeq32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0x75E00000u: { // CBNE_32_imm
                        Instruction result(Mnemonic::CBNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne32imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbne32imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbne32imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5000000u: { // CBGT_64_imm
            // Also matches: CBGE_CBGT_64_imm (CBGT)
                        Instruction result(Mnemonic::CBGT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbgt64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbgt64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbgt64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5200000u: { // CBLT_64_imm
            // Also matches: CBLE_CBLT_64_imm (CBLT)
                        Instruction result(Mnemonic::CBLT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cblt64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cblt64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cblt64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5400000u: { // CBHI_64_imm
            // Also matches: CBHS_CBHI_64_imm (CBHI)
                        Instruction result(Mnemonic::CBHI, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbhi64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbhi64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbhi64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5600000u: { // CBLO_64_imm
            // Also matches: CBLS_CBLO_64_imm (CBLO)
                        Instruction result(Mnemonic::CBLO, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cblo64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cblo64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cblo64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5C00000u: { // CBEQ_64_imm
                        Instruction result(Mnemonic::CBEQ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbeq64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbeq64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbeq64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        case 0xF5E00000u: { // CBNE_64_imm
                        Instruction result(Mnemonic::CBNE, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = true;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbne64imm.Rt, is_64bit));
                        result.operands.push_back(Operand(OperandType::Immediate, enc.cbne64imm.imm6, true));
                        {
                            int32_t val = static_cast<int32_t>(enc.cbne64imm.imm9 << 23) >> 23;
                            result.operands.push_back(Operand(OperandType::Immediate, static_cast<uint32_t>(val), true));
                        }
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Fu (10 patterns, 10 encodings)
    switch (insn & 0xFFE0001Fu) {
        case 0x5500001Fu: { // RETAASPPC_only_miscbranch
                        Instruction result(Mnemonic::RETAASPPC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.retaasppc_only_miscbranch.imm16, true));
                        return result;
        }
        case 0x5520001Fu: { // RETABSPPC_only_miscbranch
                        Instruction result(Mnemonic::RETABSPPC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.retabsppc_only_miscbranch.imm16, true));
                        return result;
        }
        case 0xD4000001u: { // SVC_EX_exception
                        Instruction result(Mnemonic::SVC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.svc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4000002u: { // HVC_EX_exception
                        Instruction result(Mnemonic::HVC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.hvc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4000003u: { // SMC_EX_exception
                        Instruction result(Mnemonic::SMC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4200000u: { // BRK_EX_exception
                        Instruction result(Mnemonic::BRK, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.brk_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4400000u: { // HLT_EX_exception
                        Instruction result(Mnemonic::HLT, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.hlt_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4A00001u: { // DCPS1_DC_exception
                        Instruction result(Mnemonic::DCPS1, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps1dc_exception.imm16, true));
                        return result;
        }
        case 0xD4A00002u: { // DCPS2_DC_exception
                        Instruction result(Mnemonic::DCPS2, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps2dc_exception.imm16, true));
                        return result;
        }
        case 0xD4A00003u: { // DCPS3_DC_exception
                        Instruction result(Mnemonic::DCPS3, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps3dc_exception.imm16, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF000010u (2 patterns, 2 encodings)
    switch (insn & 0xFF000010u) {
        case 0x54000000u: { // B_only_condbranch
                        Instruction result(Mnemonic::B, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.condition = static_cast<Condition>(enc.bonly_condbranch.cond);
                        int32_t offset = static_cast<int32_t>(enc.bonly_condbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0x54000010u: { // BC_only_condbranch
                        Instruction result(Mnemonic::BC, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.condition = static_cast<Condition>(enc.bc_only_condbranch.cond);
                        int32_t offset = static_cast<int32_t>(enc.bc_only_condbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFF000000u (4 patterns, 4 encodings)
    switch (insn & 0xFF000000u) {
        case 0x34000000u: { // CBZ_32_compbranch
                        Instruction result(Mnemonic::CBZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbz32compbranch.Rt, false));
                        int32_t offset = static_cast<int32_t>(enc.cbz32compbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0x35000000u: { // CBNZ_32_compbranch
                        Instruction result(Mnemonic::CBNZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbnz32compbranch.Rt, false));
                        int32_t offset = static_cast<int32_t>(enc.cbnz32compbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0xB4000000u: { // CBZ_64_compbranch
                        Instruction result(Mnemonic::CBZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbz64compbranch.Rt, true));
                        int32_t offset = static_cast<int32_t>(enc.cbz64compbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0xB5000000u: { // CBNZ_64_compbranch
                        Instruction result(Mnemonic::CBNZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.cbnz64compbranch.Rt, true));
                        int32_t offset = static_cast<int32_t>(enc.cbnz64compbranch.imm19 << 13) >> 13;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFC000000u (2 patterns, 2 encodings)
    switch (insn & 0xFC000000u) {
        case 0x14000000u: { // B_only_branch_imm
                        Instruction result(Mnemonic::B, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        int32_t offset = static_cast<int32_t>(enc.bonly_branch_imm.imm26 << 6) >> 6;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0x94000000u: { // BL_only_branch_imm
                        Instruction result(Mnemonic::BL, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        int32_t offset = static_cast<int32_t>(enc.bl_only_branch_imm.imm26 << 6) >> 6;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0x7F000000u (2 patterns, 2 encodings)
    switch (insn & 0x7F000000u) {
        case 0x36000000u: { // TBZ_only_testbranch
                        Instruction result(Mnemonic::TBZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.tbz_only_testbranch.Rt, true));
                        result.operands.push_back(Operand(OperandType::Immediate, (enc.tbz_only_testbranch.b5 << 5) | enc.tbz_only_testbranch.b40, true));
                        int32_t offset = static_cast<int32_t>(enc.tbz_only_testbranch.imm14 << 18) >> 18;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        case 0x37000000u: { // TBNZ_only_testbranch
                        Instruction result(Mnemonic::TBNZ, insn);
                        ControlEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Register, enc.tbnz_only_testbranch.Rt, true));
                        result.operands.push_back(Operand(OperandType::Immediate, (enc.tbnz_only_testbranch.b5 << 5) | enc.tbnz_only_testbranch.b40, true));
                        int32_t offset = static_cast<int32_t>(enc.tbnz_only_testbranch.imm14 << 18) >> 18;
                        offset *= 4;
                        result.operands.push_back(Operand(OperandType::Relative, static_cast<uint32_t>(offset), true));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace control
} // namespace format
} // namespace veda64
