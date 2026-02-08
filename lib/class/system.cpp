#include "class/system.hpp"

namespace veda64 {
namespace System {

// Internal encoding structures
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


// AXFLAG: Convert floating-point condition flags from Arm to external format
// Encoding: AXFLAG_M_pstate
// Template: AXFLAG
struct AxflagMPstate {
    uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b010 (0x2)
    uint32_t CRm : 4;  // partial: (0)(0)(0)(0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
    uint32_t op1 : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
    uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
};


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


// CFINV: Invert carry flag
// Encoding: CFINV_M_pstate
// Template: CFINV
struct CfinvMPstate {
    uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b000 (0x0)
    uint32_t CRm : 4;  // partial: (0)(0)(0)(0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
    uint32_t op1 : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
    uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
};


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


// SB: Speculation barrier
// Encoding: SB_only_barriers
// Template: SB
struct SbOnlyBarriers {
    uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
    uint32_t opc : 2;  // fixed: 0b11 (0x3)
    uint32_t _unnamed_3 : 1;  // fixed: 0b1 (0x1)
    uint32_t CRm : 4;  // partial: (0)(0)(0)(0)
    uint32_t _unnamed_2 : 14;  // fixed: 0b01000000110011 (0x1033)
    uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
};


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


// XAFLAG: Convert floating-point condition flags from external format to Arm format
// Encoding: XAFLAG_M_pstate
// Template: XAFLAG
struct XaflagMPstate {
    uint32_t Rt : 5;  // fixed: 0b11111 (0x1F)
    uint32_t op2 : 3;  // fixed: 0b001 (0x1)
    uint32_t CRm : 4;  // partial: (0)(0)(0)(0)
    uint32_t _unnamed_3 : 4;  // fixed: 0b0100 (0x4)
    uint32_t op1 : 3;  // fixed: 0b000 (0x0)
    uint32_t _unnamed_2 : 7;  // fixed: 0b0100000 (0x20)
    uint32_t _unnamed_1 : 3;  // fixed: 0b101 (0x5)
    uint32_t _unnamed_0 : 3;  // fixed: 0b110 (0x6)
};


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


// Union for system instruction class
union SystemEncoding {
    ApasSysCrSysteminstrs apas_sys_cr_systeminstrs;
    AtSysCrSysteminstrs at_sys_cr_systeminstrs;
    AxflagMPstate axflag_mpstate;
    BrbSysCrSysteminstrs brb_sys_cr_systeminstrs;
    BrkExException brk_ex_exception;
    BtiHbHints bti_hb_hints;
    CfinvMPstate cfinv_mpstate;
    CfpSysCrSysteminstrs cfp_sys_cr_systeminstrs;
    ChkfeatHfHints chkfeat_hf_hints;
    ClrbhbHiHints clrbhb_hi_hints;
    ClrexBnBarriers clrex_bn_barriers;
    CospSysCrSysteminstrs cosp_sys_cr_systeminstrs;
    CppSysCrSysteminstrs cpp_sys_cr_systeminstrs;
    CsdbHiHints csdb_hi_hints;
    DcSysCrSysteminstrs dc_sys_cr_systeminstrs;
    Dcps1DcException dcps1dc_exception;
    Dcps2DcException dcps2dc_exception;
    Dcps3DcException dcps3dc_exception;
    DghHiHints dgh_hi_hints;
    DmbBoBarriers dmb_bo_barriers;
    Drps64eBranchReg drps64e_branch_reg;
    DsbBoBarriers dsb_bo_barriers;
    DsbBonBarriers dsb_bon_barriers;
    DvpSysCrSysteminstrs dvp_sys_cr_systeminstrs;
    Eret64eBranchReg eret64e_branch_reg;
    EsbHiHints esb_hi_hints;
    GcsbHdHints gcsb_hd_hints;
    GcspopcxSysCrSysteminstrs gcspopcx_sys_cr_systeminstrs;
    GcspopmSyslRcSysteminstrs gcspopm_sysl_rc_systeminstrs;
    GcspopxSysCrSysteminstrs gcspopx_sys_cr_systeminstrs;
    GcspushmSysCrSysteminstrs gcspushm_sys_cr_systeminstrs;
    GcspushxSysCrSysteminstrs gcspushx_sys_cr_systeminstrs;
    Gcsss1SysCrSysteminstrs gcsss1sys_cr_systeminstrs;
    Gcsss2SyslRcSysteminstrs gcsss2sysl_rc_systeminstrs;
    GicSysCrSysteminstrs gic_sys_cr_systeminstrs;
    GicrSyslRcSysteminstrs gicr_sysl_rc_systeminstrs;
    GsbSysCrSysteminstrs gsb_sys_cr_systeminstrs;
    HintHmHints hint_hm_hints;
    HltExException hlt_ex_exception;
    HvcExException hvc_ex_exception;
    IcSysCrSysteminstrs ic_sys_cr_systeminstrs;
    IsbBiBarriers isb_bi_barriers;
    MlbiSysCrSysteminstrs mlbi_sys_cr_systeminstrs;
    MrrsRsSystemmovepr mrrs_rs_systemmovepr;
    MrsRsSystemmove mrs_rs_systemmove;
    MsrSiPstate msr_si_pstate;
    MsrSrSystemmove msr_sr_systemmove;
    MsrrSrSystemmovepr msrr_sr_systemmovepr;
    NopHiHints nop_hi_hints;
    PacmHiHints pacm_hi_hints;
    PsbHcHints psb_hc_hints;
    PssbbDsbBoBarriers pssbb_dsb_bo_barriers;
    SbOnlyBarriers sb_only_barriers;
    SevHiHints sev_hi_hints;
    SevlHiHints sevl_hi_hints;
    ShuhHiHints shuh_hi_hints;
    SmcExException smc_ex_exception;
    SmstartMsrSiPstate smstart_msr_si_pstate;
    SmstopMsrSiPstate smstop_msr_si_pstate;
    SsbbDsbBoBarriers ssbb_dsb_bo_barriers;
    StcphHiHints stcph_hi_hints;
    StshhHiHints stshh_hi_hints;
    SvcExException svc_ex_exception;
    SysCrSysteminstrs sys_cr_systeminstrs;
    SyslRcSysteminstrs sysl_rc_systeminstrs;
    SyspCrSyspairinstrs sysp_cr_syspairinstrs;
    TlbiSysCrSysteminstrs tlbi_sys_cr_systeminstrs;
    TlbipSyspCrSyspairinstrs tlbip_sysp_cr_syspairinstrs;
    TrcitSysCrSysteminstrs trcit_sys_cr_systeminstrs;
    TsbHcHints tsb_hc_hints;
    WfeHiHints wfe_hi_hints;
    WfetOnlySysteminstrswithreg wfet_only_systeminstrswithreg;
    WfiHiHints wfi_hi_hints;
    WfitOnlySysteminstrswithreg wfit_only_systeminstrswithreg;
    XaflagMPstate xaflag_mpstate;
    YieldHiHints yield_hi_hints;
    uint32_t raw;
};
static_assert(sizeof(SystemEncoding) == 4, "Encoding union must be 32 bits");

// Encode function implementations
uint32_t encode_apas_sys_cr_systeminstrs(uint32_t Rt) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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

uint32_t encode_axflag_m_pstate(uint32_t CRm) {
    SystemEncoding insn = {};
    insn.axflag_mpstate.Rt = 0b11111;
    insn.axflag_mpstate.op2 = 0b010;
    insn.axflag_mpstate.CRm = CRm;
    insn.axflag_mpstate._unnamed_3 = 0b0100;
    insn.axflag_mpstate.op1 = 0b000;
    insn.axflag_mpstate._unnamed_2 = 0b0100000;
    insn.axflag_mpstate._unnamed_1 = 0b101;
    insn.axflag_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_brb_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.bti_hb_hints._unnamed_3 = 0b11111;
    insn.bti_hb_hints.op2 = op2;
    insn.bti_hb_hints.CRm = 0b0100;
    insn.bti_hb_hints._unnamed_2 = 0b01000000110010;
    insn.bti_hb_hints._unnamed_1 = 0b101;
    insn.bti_hb_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cfinv_m_pstate(uint32_t CRm) {
    SystemEncoding insn = {};
    insn.cfinv_mpstate.Rt = 0b11111;
    insn.cfinv_mpstate.op2 = 0b000;
    insn.cfinv_mpstate.CRm = CRm;
    insn.cfinv_mpstate._unnamed_3 = 0b0100;
    insn.cfinv_mpstate.op1 = 0b000;
    insn.cfinv_mpstate._unnamed_2 = 0b0100000;
    insn.cfinv_mpstate._unnamed_1 = 0b101;
    insn.cfinv_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cfp_sys_cr_systeminstrs(uint32_t Rt) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.chkfeat_hf_hints._unnamed_3 = 0b11111;
    insn.chkfeat_hf_hints.op2 = 0b000;
    insn.chkfeat_hf_hints.CRm = 0b0101;
    insn.chkfeat_hf_hints._unnamed_2 = 0b01000000110010;
    insn.chkfeat_hf_hints._unnamed_1 = 0b101;
    insn.chkfeat_hf_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_clrbhb_hi_hints() {
    SystemEncoding insn = {};
    insn.clrbhb_hi_hints._unnamed_3 = 0b11111;
    insn.clrbhb_hi_hints.op2 = 0b110;
    insn.clrbhb_hi_hints.CRm = 0b0010;
    insn.clrbhb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.clrbhb_hi_hints._unnamed_1 = 0b101;
    insn.clrbhb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_clrex_bn_barriers(uint32_t CRm) {
    SystemEncoding insn = {};
    insn.clrex_bn_barriers.Rt = 0b11111;
    insn.clrex_bn_barriers.op2 = 0b010;
    insn.clrex_bn_barriers.CRm = CRm;
    insn.clrex_bn_barriers._unnamed_2 = 0b01000000110011;
    insn.clrex_bn_barriers._unnamed_1 = 0b101;
    insn.clrex_bn_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_cosp_sys_cr_systeminstrs(uint32_t Rt) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.csdb_hi_hints._unnamed_3 = 0b11111;
    insn.csdb_hi_hints.op2 = 0b100;
    insn.csdb_hi_hints.CRm = 0b0010;
    insn.csdb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.csdb_hi_hints._unnamed_1 = 0b101;
    insn.csdb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dc_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t op1) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.dgh_hi_hints._unnamed_3 = 0b11111;
    insn.dgh_hi_hints.op2 = 0b110;
    insn.dgh_hi_hints.CRm = 0b0000;
    insn.dgh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.dgh_hi_hints._unnamed_1 = 0b101;
    insn.dgh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_dmb_bo_barriers(uint32_t CRm) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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

uint32_t encode_esb_hi_hints() {
    SystemEncoding insn = {};
    insn.esb_hi_hints._unnamed_3 = 0b11111;
    insn.esb_hi_hints.op2 = 0b000;
    insn.esb_hi_hints.CRm = 0b0010;
    insn.esb_hi_hints._unnamed_2 = 0b01000000110010;
    insn.esb_hi_hints._unnamed_1 = 0b101;
    insn.esb_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcsb_hd_hints() {
    SystemEncoding insn = {};
    insn.gcsb_hd_hints._unnamed_3 = 0b11111;
    insn.gcsb_hd_hints.op2 = 0b011;
    insn.gcsb_hd_hints.CRm = 0b0010;
    insn.gcsb_hd_hints._unnamed_2 = 0b01000000110010;
    insn.gcsb_hd_hints._unnamed_1 = 0b101;
    insn.gcsb_hd_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_gcspopcx_sys_cr_systeminstrs(uint32_t Rt) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.hint_hm_hints._unnamed_3 = 0b11111;
    insn.hint_hm_hints.op2 = op2;
    insn.hint_hm_hints.CRm = CRm;
    insn.hint_hm_hints._unnamed_2 = 0b01000000110010;
    insn.hint_hm_hints._unnamed_1 = 0b101;
    insn.hint_hm_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_hlt_ex_exception(uint32_t imm16) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.nop_hi_hints._unnamed_3 = 0b11111;
    insn.nop_hi_hints.op2 = 0b000;
    insn.nop_hi_hints.CRm = 0b0000;
    insn.nop_hi_hints._unnamed_2 = 0b01000000110010;
    insn.nop_hi_hints._unnamed_1 = 0b101;
    insn.nop_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_pacm_hi_hints() {
    SystemEncoding insn = {};
    insn.pacm_hi_hints._unnamed_3 = 0b11111;
    insn.pacm_hi_hints.op2 = 0b111;
    insn.pacm_hi_hints.CRm = 0b0100;
    insn.pacm_hi_hints._unnamed_2 = 0b01000000110010;
    insn.pacm_hi_hints._unnamed_1 = 0b101;
    insn.pacm_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_psb_hc_hints() {
    SystemEncoding insn = {};
    insn.psb_hc_hints._unnamed_3 = 0b11111;
    insn.psb_hc_hints.op2 = 0b001;
    insn.psb_hc_hints.CRm = 0b0010;
    insn.psb_hc_hints._unnamed_2 = 0b01000000110010;
    insn.psb_hc_hints._unnamed_1 = 0b101;
    insn.psb_hc_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_pssbb_dsb_bo_barriers() {
    SystemEncoding insn = {};
    insn.pssbb_dsb_bo_barriers.Rt = 0b11111;
    insn.pssbb_dsb_bo_barriers.opc = 0b00;
    insn.pssbb_dsb_bo_barriers._unnamed_3 = 0b1;
    insn.pssbb_dsb_bo_barriers.CRm = 0b0100;
    insn.pssbb_dsb_bo_barriers._unnamed_2 = 0b01000000110011;
    insn.pssbb_dsb_bo_barriers._unnamed_1 = 0b101;
    insn.pssbb_dsb_bo_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sb_only_barriers(uint32_t CRm) {
    SystemEncoding insn = {};
    insn.sb_only_barriers.Rt = 0b11111;
    insn.sb_only_barriers.opc = 0b11;
    insn.sb_only_barriers._unnamed_3 = 0b1;
    insn.sb_only_barriers.CRm = CRm;
    insn.sb_only_barriers._unnamed_2 = 0b01000000110011;
    insn.sb_only_barriers._unnamed_1 = 0b101;
    insn.sb_only_barriers._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sev_hi_hints() {
    SystemEncoding insn = {};
    insn.sev_hi_hints._unnamed_3 = 0b11111;
    insn.sev_hi_hints.op2 = 0b100;
    insn.sev_hi_hints.CRm = 0b0000;
    insn.sev_hi_hints._unnamed_2 = 0b01000000110010;
    insn.sev_hi_hints._unnamed_1 = 0b101;
    insn.sev_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_sevl_hi_hints() {
    SystemEncoding insn = {};
    insn.sevl_hi_hints._unnamed_3 = 0b11111;
    insn.sevl_hi_hints.op2 = 0b101;
    insn.sevl_hi_hints.CRm = 0b0000;
    insn.sevl_hi_hints._unnamed_2 = 0b01000000110010;
    insn.sevl_hi_hints._unnamed_1 = 0b101;
    insn.sevl_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_shuh_hi_hints(uint32_t op2) {
    SystemEncoding insn = {};
    insn.shuh_hi_hints._unnamed_3 = 0b11111;
    insn.shuh_hi_hints.op2 = op2;
    insn.shuh_hi_hints.CRm = 0b0110;
    insn.shuh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.shuh_hi_hints._unnamed_1 = 0b101;
    insn.shuh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_smc_ex_exception(uint32_t imm16) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.stcph_hi_hints._unnamed_3 = 0b11111;
    insn.stcph_hi_hints.op2 = 0b100;
    insn.stcph_hi_hints.CRm = 0b0110;
    insn.stcph_hi_hints._unnamed_2 = 0b01000000110010;
    insn.stcph_hi_hints._unnamed_1 = 0b101;
    insn.stcph_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_stshh_hi_hints(uint32_t op2) {
    SystemEncoding insn = {};
    insn.stshh_hi_hints._unnamed_3 = 0b11111;
    insn.stshh_hi_hints.op2 = op2;
    insn.stshh_hi_hints.CRm = 0b0110;
    insn.stshh_hi_hints._unnamed_2 = 0b01000000110010;
    insn.stshh_hi_hints._unnamed_1 = 0b101;
    insn.stshh_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_svc_ex_exception(uint32_t imm16) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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

uint32_t encode_tlbi_sys_cr_systeminstrs(uint32_t Rt, uint32_t op2, uint32_t CRm, uint32_t CRn, uint32_t op1) {
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
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
    SystemEncoding insn = {};
    insn.tsb_hc_hints._unnamed_3 = 0b11111;
    insn.tsb_hc_hints.op2 = 0b010;
    insn.tsb_hc_hints.CRm = 0b0010;
    insn.tsb_hc_hints._unnamed_2 = 0b01000000110010;
    insn.tsb_hc_hints._unnamed_1 = 0b101;
    insn.tsb_hc_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfe_hi_hints() {
    SystemEncoding insn = {};
    insn.wfe_hi_hints._unnamed_3 = 0b11111;
    insn.wfe_hi_hints.op2 = 0b010;
    insn.wfe_hi_hints.CRm = 0b0000;
    insn.wfe_hi_hints._unnamed_2 = 0b01000000110010;
    insn.wfe_hi_hints._unnamed_1 = 0b101;
    insn.wfe_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfet_only_systeminstrswithreg(uint32_t Rd) {
    SystemEncoding insn = {};
    insn.wfet_only_systeminstrswithreg.Rd = Rd;
    insn.wfet_only_systeminstrswithreg.op2 = 0b000;
    insn.wfet_only_systeminstrswithreg.CRm = 0b0000;
    insn.wfet_only_systeminstrswithreg._unnamed_2 = 0b01000000110001;
    insn.wfet_only_systeminstrswithreg._unnamed_1 = 0b101;
    insn.wfet_only_systeminstrswithreg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfi_hi_hints() {
    SystemEncoding insn = {};
    insn.wfi_hi_hints._unnamed_3 = 0b11111;
    insn.wfi_hi_hints.op2 = 0b011;
    insn.wfi_hi_hints.CRm = 0b0000;
    insn.wfi_hi_hints._unnamed_2 = 0b01000000110010;
    insn.wfi_hi_hints._unnamed_1 = 0b101;
    insn.wfi_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_wfit_only_systeminstrswithreg(uint32_t Rd) {
    SystemEncoding insn = {};
    insn.wfit_only_systeminstrswithreg.Rd = Rd;
    insn.wfit_only_systeminstrswithreg.op2 = 0b001;
    insn.wfit_only_systeminstrswithreg.CRm = 0b0000;
    insn.wfit_only_systeminstrswithreg._unnamed_2 = 0b01000000110001;
    insn.wfit_only_systeminstrswithreg._unnamed_1 = 0b101;
    insn.wfit_only_systeminstrswithreg._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_xaflag_m_pstate(uint32_t CRm) {
    SystemEncoding insn = {};
    insn.xaflag_mpstate.Rt = 0b11111;
    insn.xaflag_mpstate.op2 = 0b001;
    insn.xaflag_mpstate.CRm = CRm;
    insn.xaflag_mpstate._unnamed_3 = 0b0100;
    insn.xaflag_mpstate.op1 = 0b000;
    insn.xaflag_mpstate._unnamed_2 = 0b0100000;
    insn.xaflag_mpstate._unnamed_1 = 0b101;
    insn.xaflag_mpstate._unnamed_0 = 0b110;
    return insn.raw;
}

uint32_t encode_yield_hi_hints() {
    SystemEncoding insn = {};
    insn.yield_hi_hints._unnamed_3 = 0b11111;
    insn.yield_hi_hints.op2 = 0b001;
    insn.yield_hi_hints.CRm = 0b0000;
    insn.yield_hi_hints._unnamed_2 = 0b01000000110010;
    insn.yield_hi_hints._unnamed_1 = 0b101;
    insn.yield_hi_hints._unnamed_0 = 0b110;
    return insn.raw;
}

// Decode function implementation
// Decode a system instruction
// Input is in native ARM64 format (as read from memory)
std::optional<Instruction> decode_system(uint32_t insn) {
    // Switch for mask 0xFFFFFFFFu (20 patterns, 20 encodings)
    switch (insn & 0xFFFFFFFFu) {
        case 0xD503201Fu: { // NOP_HI_hints
                        Instruction result(Mnemonic::NOP, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503203Fu: { // YIELD_HI_hints
                        Instruction result(Mnemonic::YIELD, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503205Fu: { // WFE_HI_hints
                        Instruction result(Mnemonic::WFE, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503207Fu: { // WFI_HI_hints
                        Instruction result(Mnemonic::WFI, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503209Fu: { // SEV_HI_hints
                        Instruction result(Mnemonic::SEV, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50320BFu: { // SEVL_HI_hints
                        Instruction result(Mnemonic::SEVL, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50320DFu: { // DGH_HI_hints
                        Instruction result(Mnemonic::DGH, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503221Fu: { // ESB_HI_hints
                        Instruction result(Mnemonic::ESB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503223Fu: { // PSB_HC_hints
                        Instruction result(Mnemonic::PSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503225Fu: { // TSB_HC_hints
                        Instruction result(Mnemonic::TSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503227Fu: { // GCSB_HD_hints
                        Instruction result(Mnemonic::GCSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503229Fu: { // CSDB_HI_hints
                        Instruction result(Mnemonic::CSDB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50322DFu: { // CLRBHB_HI_hints
                        Instruction result(Mnemonic::CLRBHB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50324FFu: { // PACM_HI_hints
                        Instruction result(Mnemonic::PACM, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503251Fu: { // CHKFEAT_HF_hints
                        Instruction result(Mnemonic::CHKFEAT, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503269Fu: { // STCPH_HI_hints
                        Instruction result(Mnemonic::STCPH, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503309Fu: { // SSBB_DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503349Fu: { // PSSBB_DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD69F03E0u: { // ERET_64E_branch_reg
                        Instruction result(Mnemonic::ERET, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD6BF03E0u: { // DRPS_64E_branch_reg
                        Instruction result(Mnemonic::DRPS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFE0u (15 patterns, 15 encodings)
    switch (insn & 0xFFFFFFE0u) {
        case 0xD5031000u: { // WFET_only_systeminstrswithreg
                        Instruction result(Mnemonic::WFET, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.wfet_only_systeminstrswithreg.Rd, is_64bit));
                        return result;
        }
        case 0xD5031020u: { // WFIT_only_systeminstrswithreg
                        Instruction result(Mnemonic::WFIT, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.wfit_only_systeminstrswithreg.Rd, is_64bit));
                        return result;
        }
        case 0xD5087780u: { // GCSPUSHX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspushx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50877A0u: { // GCSPOPCX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopcx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50877C0u: { // GCSPOPX_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopx_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B72E0u: { // TRCIT_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.trcit_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7380u: { // CFP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cfp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73A0u: { // DVP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.dvp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73C0u: { // COSP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cosp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B73E0u: { // CPP_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.cpp_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7700u: { // GCSPUSHM_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspushm_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50B7740u: { // GCSSS1_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcsss1sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD50E7000u: { // APAS_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.apas_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD52B7720u: { // GCSPOPM_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcspopm_sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD52B7760u: { // GCSSS2_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gcsss2sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFFDFu (2 patterns, 2 encodings)
    switch (insn & 0xFFFFFFDFu) {
        case 0xD503261Fu: { // STSHH_HI_hints
                        Instruction result(Mnemonic::STSHH, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503265Fu: { // SHUH_HI_hints
                        Instruction result(Mnemonic::SHUH, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFF80u (1 pattern, 1 encoding)
    switch (insn & 0xFFFFFF80u) {
        case 0xD50C7080u: { // MLBI_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFFF00u (3 patterns, 3 encodings)
    switch (insn & 0xFFFFFF00u) {
        case 0xD508C000u: { // GSB_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gsb_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5097200u: { // BRB_SYS_CR_systeminstrs
                        Instruction result(Mnemonic::SYS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.brb_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD528C300u: { // GICR_SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.gic_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF9FFu (2 patterns, 2 encodings)
    switch (insn & 0xFFFFF9FFu) {
        case 0xD503407Fu: { // SMSTOP_MSR_SI_pstate
                        Instruction result(Mnemonic::MSR, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503417Fu: { // SMSTART_MSR_SI_pstate
                        Instruction result(Mnemonic::MSR, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF3FFu (1 pattern, 1 encoding)
    switch (insn & 0xFFFFF3FFu) {
        case 0xD503323Fu: { // DSB_BOn_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dsb_bon_barriers.imm2, true));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF2FFu (4 patterns, 4 encodings)
    switch (insn & 0xFFFFF2FFu) {
        case 0xD500401Fu: { // CFINV_M_pstate
                        Instruction result(Mnemonic::CFINV, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD500403Fu: { // XAFLAG_M_pstate
                        Instruction result(Mnemonic::XAFLAG, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD500405Fu: { // AXFLAG_M_pstate
                        Instruction result(Mnemonic::AXFLAG, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50330FFu: { // SB_only_barriers
                        Instruction result(Mnemonic::SB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFFFF0FFu (4 patterns, 4 encodings)
    switch (insn & 0xFFFFF0FFu) {
        case 0xD503305Fu: { // CLREX_BN_barriers
                        Instruction result(Mnemonic::CLREX, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD503309Fu: { // DSB_BO_barriers
                        Instruction result(Mnemonic::DSB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50330BFu: { // DMB_BO_barriers
                        Instruction result(Mnemonic::DMB, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        return result;
        }
        case 0xD50330DFu: { // ISB_BI_barriers
                        Instruction result(Mnemonic::ISB, insn);
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.tlbi_sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5488000u: { // TLBIP_SYSP_CR_syspairinstrs
                        Instruction result(Mnemonic::SYSP, insn);
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sys_cr_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5280000u: { // SYSL_RC_systeminstrs
                        Instruction result(Mnemonic::SYSL, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.sysl_rc_systeminstrs.Rt, is_64bit));
                        return result;
        }
        case 0xD5480000u: { // SYSP_CR_syspairinstrs
                        Instruction result(Mnemonic::SYSP, insn);
                        SystemEncoding enc = {};
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
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.msr_sr_systemmove.Rt, is_64bit));
                        return result;
        }
        case 0xD5300000u: { // MRS_RS_systemmove
                        Instruction result(Mnemonic::MRS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mrs_rs_systemmove.Rt, is_64bit));
                        return result;
        }
        case 0xD5500000u: { // MSRR_SR_systemmovepr
                        Instruction result(Mnemonic::MSRR, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.msrr_sr_systemmovepr.Rt, is_64bit));
                        return result;
        }
        case 0xD5700000u: { // MRRS_RS_systemmovepr
                        Instruction result(Mnemonic::MRRS, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        bool is_64bit = false;
                        result.operands.push_back(Operand(OperandType::Register, enc.mrrs_rs_systemmovepr.Rt, is_64bit));
                        return result;
        }
        default: break;
    }

    // Switch for mask 0xFFE0001Fu (8 patterns, 8 encodings)
    switch (insn & 0xFFE0001Fu) {
        case 0xD4000001u: { // SVC_EX_exception
                        Instruction result(Mnemonic::SVC, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.svc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4000002u: { // HVC_EX_exception
                        Instruction result(Mnemonic::HVC, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.hvc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4000003u: { // SMC_EX_exception
                        Instruction result(Mnemonic::SMC, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.smc_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4200000u: { // BRK_EX_exception
                        Instruction result(Mnemonic::BRK, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.brk_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4400000u: { // HLT_EX_exception
                        Instruction result(Mnemonic::HLT, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.hlt_ex_exception.imm16, true));
                        return result;
        }
        case 0xD4A00001u: { // DCPS1_DC_exception
                        Instruction result(Mnemonic::DCPS1, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps1dc_exception.imm16, true));
                        return result;
        }
        case 0xD4A00002u: { // DCPS2_DC_exception
                        Instruction result(Mnemonic::DCPS2, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps2dc_exception.imm16, true));
                        return result;
        }
        case 0xD4A00003u: { // DCPS3_DC_exception
                        Instruction result(Mnemonic::DCPS3, insn);
                        SystemEncoding enc = {};
                        enc.raw = insn;
                        result.operands.push_back(Operand(OperandType::Immediate, enc.dcps3dc_exception.imm16, true));
                        return result;
        }
        default: break;
    }

    // No matching encoding found
    return std::nullopt;
}

} // namespace System
} // namespace veda64
