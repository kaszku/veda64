# AArch64 system register encoding table
# Key: (op0, op1, CRn, CRm, op2)
# Encoding formula: key_int = (op0 << 14) | (op1 << 11) | (CRn << 7) | (CRm << 3) | op2
#
# Sources:
#   - ARM Architecture Reference Manual DDI 0487 (authoritative)
#   - LLVM AArch64SystemOperands.td
#   - ARM Trusted Firmware arch.h
#   - Linux kernel arch/arm64/include/asm/sysreg.h
#   - binutils opcodes/aarch64-opc.c
#
# Notes:
#   - Where RO and WO registers share the same encoding (e.g. DBGDTRRX_EL0 / DBGDTRTX_EL0),
#     only one name is stored (the RO name takes priority).
#   - Trace registers with conflicting encodings use the most common LLVM/ARM-assigned name.

SYSREG_NAMES = {

    # =========================================================================
    # op0=2 — Debug, trace, and OS lock registers
    # =========================================================================

    # --- Debug breakpoint/watchpoint (op0=2, op1=0, CRn=0) ---
    (2,0,0,0,2):  "osdtrrx_el1",
    (2,0,0,0,4):  "dbgbvr0_el1",
    (2,0,0,0,5):  "dbgbcr0_el1",
    (2,0,0,0,6):  "dbgwvr0_el1",
    (2,0,0,0,7):  "dbgwcr0_el1",
    (2,0,0,1,4):  "dbgbvr1_el1",
    (2,0,0,1,5):  "dbgbcr1_el1",
    (2,0,0,1,6):  "dbgwvr1_el1",
    (2,0,0,1,7):  "dbgwcr1_el1",
    (2,0,0,2,0):  "mdccint_el1",
    (2,0,0,2,2):  "mdscr_el1",
    (2,0,0,2,4):  "dbgbvr2_el1",
    (2,0,0,2,5):  "dbgbcr2_el1",
    (2,0,0,2,6):  "dbgwvr2_el1",
    (2,0,0,2,7):  "dbgwcr2_el1",
    (2,0,0,3,2):  "osdtrtx_el1",
    (2,0,0,3,4):  "dbgbvr3_el1",
    (2,0,0,3,5):  "dbgbcr3_el1",
    (2,0,0,3,6):  "dbgwvr3_el1",
    (2,0,0,3,7):  "dbgwcr3_el1",
    (2,0,0,4,4):  "dbgbvr4_el1",
    (2,0,0,4,5):  "dbgbcr4_el1",
    (2,0,0,4,6):  "dbgwvr4_el1",
    (2,0,0,4,7):  "dbgwcr4_el1",
    (2,0,0,5,4):  "dbgbvr5_el1",
    (2,0,0,5,5):  "dbgbcr5_el1",
    (2,0,0,5,6):  "dbgwvr5_el1",
    (2,0,0,5,7):  "dbgwcr5_el1",
    (2,0,0,6,2):  "oseccr_el1",
    (2,0,0,6,4):  "dbgbvr6_el1",
    (2,0,0,6,5):  "dbgbcr6_el1",
    (2,0,0,6,6):  "dbgwvr6_el1",
    (2,0,0,6,7):  "dbgwcr6_el1",
    (2,0,0,7,4):  "dbgbvr7_el1",
    (2,0,0,7,5):  "dbgbcr7_el1",
    (2,0,0,7,6):  "dbgwvr7_el1",
    (2,0,0,7,7):  "dbgwcr7_el1",
    (2,0,0,8,4):  "dbgbvr8_el1",
    (2,0,0,8,5):  "dbgbcr8_el1",
    (2,0,0,8,6):  "dbgwvr8_el1",
    (2,0,0,8,7):  "dbgwcr8_el1",
    (2,0,0,9,4):  "dbgbvr9_el1",
    (2,0,0,9,5):  "dbgbcr9_el1",
    (2,0,0,9,6):  "dbgwvr9_el1",
    (2,0,0,9,7):  "dbgwcr9_el1",
    (2,0,0,10,4): "dbgbvr10_el1",
    (2,0,0,10,5): "dbgbcr10_el1",
    (2,0,0,10,6): "dbgwvr10_el1",
    (2,0,0,10,7): "dbgwcr10_el1",
    (2,0,0,11,4): "dbgbvr11_el1",
    (2,0,0,11,5): "dbgbcr11_el1",
    (2,0,0,11,6): "dbgwvr11_el1",
    (2,0,0,11,7): "dbgwcr11_el1",
    (2,0,0,12,4): "dbgbvr12_el1",
    (2,0,0,12,5): "dbgbcr12_el1",
    (2,0,0,12,6): "dbgwvr12_el1",
    (2,0,0,12,7): "dbgwcr12_el1",
    (2,0,0,13,4): "dbgbvr13_el1",
    (2,0,0,13,5): "dbgbcr13_el1",
    (2,0,0,13,6): "dbgwvr13_el1",
    (2,0,0,13,7): "dbgwcr13_el1",
    (2,0,0,14,4): "dbgbvr14_el1",
    (2,0,0,14,5): "dbgbcr14_el1",
    (2,0,0,14,6): "dbgwvr14_el1",
    (2,0,0,14,7): "dbgwcr14_el1",
    (2,0,0,15,4): "dbgbvr15_el1",
    (2,0,0,15,5): "dbgbcr15_el1",
    (2,0,0,15,6): "dbgwvr15_el1",
    (2,0,0,15,7): "dbgwcr15_el1",

    # --- Debug OS/lock/power (op0=2, op1=0, CRn=1) ---
    (2,0,1,0,0):  "mdrar_el1",
    (2,0,1,0,4):  "oslar_el1",
    (2,0,1,1,4):  "oslsr_el1",
    (2,0,1,3,4):  "osdlr_el1",
    (2,0,1,4,4):  "dbgprcr_el1",

    # --- Debug claim/auth (op0=2, op1=0, CRn=7) ---
    (2,0,7,8,6):  "dbgclaimset_el1",
    (2,0,7,9,6):  "dbgclaimclr_el1",
    (2,0,7,14,6): "dbgauthstatus_el1",

    # --- Jazelle (op0=2, op1=2) ---
    (2,2,0,0,0):  "teecr32_el1",
    (2,2,1,0,0):  "teehbr32_el1",

    # --- EL0 debug (op0=2, op1=3) ---
    (2,3,0,1,0):  "mdccsr_el0",
    (2,3,0,4,0):  "dbgdtr_el0",
    (2,3,0,5,0):  "dbgdtrrx_el0",   # RO; DBGDTRTX_EL0 (WO) shares same encoding

    # --- EL2 debug (op0=2, op1=4) ---
    (2,4,0,7,0):  "dbgvcr32_el2",

    # =========================================================================
    # Trace / ETM registers (op0=2, op1=1) — all CRn values
    # =========================================================================

    # CRn=0 — Programmer's model control registers
    (2,1,0,0,0):  "trcprgctlr",
    (2,1,0,0,1):  "trctraceidr",
    (2,1,0,0,2):  "trcvictlr",
    (2,1,0,0,4):  "trcseqevr0",
    (2,1,0,0,5):  "trccntrldvr0",
    (2,1,0,0,6):  "trcimspec0",
    (2,1,0,0,7):  "trcrsctlr2",
    (2,1,0,1,0):  "trcprocselr",
    (2,1,0,1,1):  "trcqctlr",
    (2,1,0,1,2):  "trcviiectlr",
    (2,1,0,1,4):  "trcseqevr1",
    (2,1,0,1,5):  "trccntrldvr1",
    (2,1,0,1,6):  "trcimspec1",
    (2,1,0,1,7):  "trcrsctlr3",
    (2,1,0,2,2):  "trcvissctlr",
    (2,1,0,2,4):  "trcseqevr2",
    (2,1,0,2,5):  "trccntrldvr2",
    (2,1,0,2,6):  "trcimspec2",
    (2,1,0,2,7):  "trcrsctlr4",
    (2,1,0,3,0):  "trcstatr",
    (2,1,0,3,2):  "trcvipcssctlr",
    (2,1,0,3,5):  "trccntrldvr3",
    (2,1,0,3,6):  "trcimspec3",
    (2,1,0,3,7):  "trcrsctlr5",
    (2,1,0,4,0):  "trcconfigr",
    (2,1,0,4,6):  "trcimspec4",
    (2,1,0,4,7):  "trcrsctlr6",
    (2,1,0,5,5):  "trccntctlr0",
    (2,1,0,5,6):  "trcimspec5",
    (2,1,0,5,7):  "trcrsctlr7",
    (2,1,0,6,0):  "trcauxctlr",
    (2,1,0,6,4):  "trcseqrstevr",
    (2,1,0,6,5):  "trccntctlr1",
    (2,1,0,6,6):  "trcimspec6",
    (2,1,0,6,7):  "trcrsctlr8",
    (2,1,0,7,4):  "trcseqstr",
    (2,1,0,7,5):  "trccntctlr2",
    (2,1,0,7,6):  "trcimspec7",
    (2,1,0,7,7):  "trcrsctlr9",
    (2,1,0,8,0):  "trceventctl0r",
    (2,1,0,8,2):  "trcvdctlr",
    (2,1,0,8,4):  "trcextinselr",
    (2,1,0,8,5):  "trccntctlr3",
    (2,1,0,8,6):  "trcidr8",
    (2,1,0,8,7):  "trcrsctlr10",
    (2,1,0,9,0):  "trceventctl1r",
    (2,1,0,9,2):  "trcvdsacctlr",
    (2,1,0,9,6):  "trcidr9",
    (2,1,0,9,7):  "trcrsctlr11",
    (2,1,0,10,2): "trcvdarcctlr",
    (2,1,0,10,6): "trcidr10",
    (2,1,0,10,7): "trcrsctlr12",
    (2,1,0,11,0): "trcstallctlr",
    (2,1,0,11,5): "trccntvr0",
    (2,1,0,11,6): "trcidr11",
    (2,1,0,11,7): "trcrsctlr13",
    (2,1,0,12,0): "trctsctlr",
    (2,1,0,12,5): "trccntvr1",
    (2,1,0,12,6): "trcidr12",
    (2,1,0,12,7): "trcrsctlr14",
    (2,1,0,13,0): "trcsyncpr",
    (2,1,0,13,5): "trccntvr2",
    (2,1,0,13,6): "trcidr13",
    (2,1,0,13,7): "trcrsctlr15",
    (2,1,0,14,0): "trcccctlr",
    (2,1,0,14,5): "trccntvr3",
    (2,1,0,15,0): "trcbbctlr",
    (2,1,0,15,7): "trcrsctlr1",
    # Note: TRCIDR0-7 share the same (op2=7) slots as TRCRSCTLR2-9 in the RW space.
    # Per the LLVM encoding, trcrsctlr entries take priority here (RW space).

    # CRn=1 — Resource/SS/PDCR
    (2,1,1,0,2):  "trcssccr0",
    (2,1,1,1,2):  "trcssccr1",
    (2,1,1,2,2):  "trcssccr2",
    (2,1,1,3,2):  "trcssccr3",
    (2,1,1,4,2):  "trcssccr4",
    (2,1,1,5,2):  "trcssccr5",
    (2,1,1,6,2):  "trcssccr6",
    (2,1,1,7,2):  "trcssccr7",
    (2,1,1,0,3):  "trcsscsr0",
    (2,1,1,1,3):  "trcsscsr1",
    (2,1,1,2,3):  "trcsscsr2",
    (2,1,1,3,3):  "trcsscsr3",
    (2,1,1,4,3):  "trcsscsr4",
    (2,1,1,5,3):  "trcsscsr5",
    (2,1,1,6,3):  "trcsscsr6",
    (2,1,1,7,3):  "trcsscsr7",
    (2,1,1,0,4):  "trcpdcr",     # TRCOSLAR (WO) shares this encoding; trcpdcr is the RW name
    (2,1,1,8,2):  "trcsspcicr0",
    (2,1,1,9,2):  "trcsspcicr1",
    (2,1,1,10,2): "trcsspcicr2",
    (2,1,1,11,2): "trcsspcicr3",
    (2,1,1,12,2): "trcsspcicr4",
    (2,1,1,13,2): "trcsspcicr5",
    (2,1,1,14,2): "trcsspcicr6",
    (2,1,1,15,2): "trcsspcicr7",
    # Resource selectors (TRCRSCTLR16-31)
    (2,1,1,0,7):  "trcrsctlr16",
    (2,1,1,1,7):  "trcrsctlr17",
    (2,1,1,2,7):  "trcrsctlr18",
    (2,1,1,3,7):  "trcrsctlr19",
    (2,1,1,4,7):  "trcrsctlr20",
    (2,1,1,5,7):  "trcrsctlr21",
    (2,1,1,6,7):  "trcrsctlr22",
    (2,1,1,7,7):  "trcrsctlr23",
    (2,1,1,8,7):  "trcrsctlr24",
    (2,1,1,9,7):  "trcrsctlr25",
    (2,1,1,10,7): "trcrsctlr26",
    (2,1,1,11,7): "trcrsctlr27",
    (2,1,1,12,7): "trcrsctlr28",
    (2,1,1,13,7): "trcrsctlr29",
    (2,1,1,14,7): "trcrsctlr30",
    (2,1,1,15,7): "trcrsctlr31",

    # CRn=2 — Address/data comparators
    (2,1,2,0,0):  "trcacvr0",
    (2,1,2,2,0):  "trcacvr1",
    (2,1,2,4,0):  "trcacvr2",
    (2,1,2,6,0):  "trcacvr3",
    (2,1,2,8,0):  "trcacvr4",
    (2,1,2,10,0): "trcacvr5",
    (2,1,2,12,0): "trcacvr6",
    (2,1,2,14,0): "trcacvr7",
    (2,1,2,1,0):  "trcacvr8",
    (2,1,2,3,0):  "trcacvr9",
    (2,1,2,5,0):  "trcacvr10",
    (2,1,2,7,0):  "trcacvr11",
    (2,1,2,9,0):  "trcacvr12",
    (2,1,2,11,0): "trcacvr13",
    (2,1,2,13,0): "trcacvr14",
    (2,1,2,15,0): "trcacvr15",
    (2,1,2,0,1):  "trcacatr0",
    (2,1,2,2,1):  "trcacatr1",
    (2,1,2,4,1):  "trcacatr2",
    (2,1,2,6,1):  "trcacatr3",
    (2,1,2,8,1):  "trcacatr4",
    (2,1,2,10,1): "trcacatr5",
    (2,1,2,12,1): "trcacatr6",
    (2,1,2,14,1): "trcacatr7",
    (2,1,2,1,1):  "trcacatr8",
    (2,1,2,3,1):  "trcacatr9",
    (2,1,2,5,1):  "trcacatr10",
    (2,1,2,7,1):  "trcacatr11",
    (2,1,2,9,1):  "trcacatr12",
    (2,1,2,11,1): "trcacatr13",
    (2,1,2,13,1): "trcacatr14",
    (2,1,2,15,1): "trcacatr15",
    (2,1,2,0,4):  "trcdvcvr0",
    (2,1,2,4,4):  "trcdvcvr1",
    (2,1,2,8,4):  "trcdvcvr2",
    (2,1,2,12,4): "trcdvcvr3",
    (2,1,2,2,4):  "trcdvcvr4",
    (2,1,2,6,4):  "trcdvcvr5",
    (2,1,2,10,4): "trcdvcvr6",
    (2,1,2,14,4): "trcdvcvr7",
    (2,1,2,0,5):  "trcdvcmr0",
    (2,1,2,4,5):  "trcdvcmr1",
    (2,1,2,8,5):  "trcdvcmr2",
    (2,1,2,12,5): "trcdvcmr3",
    (2,1,2,2,5):  "trcdvcmr4",
    (2,1,2,6,5):  "trcdvcmr5",
    (2,1,2,10,5): "trcdvcmr6",
    (2,1,2,14,5): "trcdvcmr7",

    # CRn=3 — Context/VMID comparators
    (2,1,3,0,0):  "trccidcvr0",
    (2,1,3,2,0):  "trccidcvr1",
    (2,1,3,4,0):  "trccidcvr2",
    (2,1,3,6,0):  "trccidcvr3",
    (2,1,3,8,0):  "trccidcvr4",
    (2,1,3,10,0): "trccidcvr5",
    (2,1,3,12,0): "trccidcvr6",
    (2,1,3,14,0): "trccidcvr7",
    (2,1,3,0,1):  "trcvmidcvr0",
    (2,1,3,2,1):  "trcvmidcvr1",
    (2,1,3,4,1):  "trcvmidcvr2",
    (2,1,3,6,1):  "trcvmidcvr3",
    (2,1,3,8,1):  "trcvmidcvr4",
    (2,1,3,10,1): "trcvmidcvr5",
    (2,1,3,12,1): "trcvmidcvr6",
    (2,1,3,14,1): "trcvmidcvr7",
    (2,1,3,0,2):  "trccidcctlr0",
    (2,1,3,1,2):  "trccidcctlr1",
    (2,1,3,2,2):  "trcvmidcctlr0",
    (2,1,3,3,2):  "trcvmidcctlr1",

    # CRn=7 — ROM/peripheral/component ID (RO) and instruction trace
    (2,1,7,0,4):  "trcitctrl",
    (2,1,7,8,6):  "trcclaimset",
    (2,1,7,9,6):  "trcclaimclr",
    (2,1,7,2,6):  "trcoslsr",
    (2,1,7,4,6):  "trcpdsr",
    (2,1,7,10,6): "trcdevid",
    (2,1,7,11,6): "trcdevtype",
    (2,1,7,12,6): "trclsr",       # TRCLAR (WO) has same encoding; use TRCLSR (RO)
    (2,1,7,13,6): "trcdevaff0",
    (2,1,7,14,6): "trcdevaff1",   # Note: TRCAUTHSTATUS also maps here in some docs; using TRCDEVAFF1
    (2,1,7,15,6): "trcdevarch",
    (2,1,7,4,7):  "trcpidr4",
    (2,1,7,5,7):  "trcpidr5",
    (2,1,7,6,7):  "trcpidr6",
    (2,1,7,7,7):  "trcpidr7",
    (2,1,7,0,7):  "trcpidr0",
    (2,1,7,1,7):  "trcpidr1",
    (2,1,7,2,7):  "trcpidr2",
    (2,1,7,3,7):  "trcpidr3",
    (2,1,7,8,7):  "trccidr0",
    (2,1,7,9,7):  "trccidr1",
    (2,1,7,10,7): "trccidr2",
    (2,1,7,11,7): "trccidr3",

    # =========================================================================
    # BRBE — Branch Record Buffer Extension (op0=2, op1=1, CRn=8..9)
    # =========================================================================

    # Control/status registers
    (2,1,9,0,0):  "brbcr_el1",
    (2,1,9,0,1):  "brbfcr_el1",
    (2,1,9,0,2):  "brbts_el1",
    (2,1,9,2,0):  "brbidr0_el1",
    (2,4,9,0,0):  "brbcr_el2",

    # BRBINF/BRBSRC/BRBTGT 0-15 (CRn=8, CRm=n, op2=0/1/2)
    (2,1,8,0,0):  "brbinf0_el1",
    (2,1,8,0,1):  "brbsrc0_el1",
    (2,1,8,0,2):  "brbtgt0_el1",
    (2,1,8,1,0):  "brbinf1_el1",
    (2,1,8,1,1):  "brbsrc1_el1",
    (2,1,8,1,2):  "brbtgt1_el1",
    (2,1,8,2,0):  "brbinf2_el1",
    (2,1,8,2,1):  "brbsrc2_el1",
    (2,1,8,2,2):  "brbtgt2_el1",
    (2,1,8,3,0):  "brbinf3_el1",
    (2,1,8,3,1):  "brbsrc3_el1",
    (2,1,8,3,2):  "brbtgt3_el1",
    (2,1,8,4,0):  "brbinf4_el1",
    (2,1,8,4,1):  "brbsrc4_el1",
    (2,1,8,4,2):  "brbtgt4_el1",
    (2,1,8,5,0):  "brbinf5_el1",
    (2,1,8,5,1):  "brbsrc5_el1",
    (2,1,8,5,2):  "brbtgt5_el1",
    (2,1,8,6,0):  "brbinf6_el1",
    (2,1,8,6,1):  "brbsrc6_el1",
    (2,1,8,6,2):  "brbtgt6_el1",
    (2,1,8,7,0):  "brbinf7_el1",
    (2,1,8,7,1):  "brbsrc7_el1",
    (2,1,8,7,2):  "brbtgt7_el1",
    (2,1,8,8,0):  "brbinf8_el1",
    (2,1,8,8,1):  "brbsrc8_el1",
    (2,1,8,8,2):  "brbtgt8_el1",
    (2,1,8,9,0):  "brbinf9_el1",
    (2,1,8,9,1):  "brbsrc9_el1",
    (2,1,8,9,2):  "brbtgt9_el1",
    (2,1,8,10,0): "brbinf10_el1",
    (2,1,8,10,1): "brbsrc10_el1",
    (2,1,8,10,2): "brbtgt10_el1",
    (2,1,8,11,0): "brbinf11_el1",
    (2,1,8,11,1): "brbsrc11_el1",
    (2,1,8,11,2): "brbtgt11_el1",
    (2,1,8,12,0): "brbinf12_el1",
    (2,1,8,12,1): "brbsrc12_el1",
    (2,1,8,12,2): "brbtgt12_el1",
    (2,1,8,13,0): "brbinf13_el1",
    (2,1,8,13,1): "brbsrc13_el1",
    (2,1,8,13,2): "brbtgt13_el1",
    (2,1,8,14,0): "brbinf14_el1",
    (2,1,8,14,1): "brbsrc14_el1",
    (2,1,8,14,2): "brbtgt14_el1",
    (2,1,8,15,0): "brbinf15_el1",
    (2,1,8,15,1): "brbsrc15_el1",
    (2,1,8,15,2): "brbtgt15_el1",
    # BRBINF/BRBSRC/BRBTGT 16-31 (CRm=n&15, op2 high bit set)
    (2,1,8,0,4):  "brbinf16_el1",
    (2,1,8,0,5):  "brbsrc16_el1",
    (2,1,8,0,6):  "brbtgt16_el1",
    (2,1,8,1,4):  "brbinf17_el1",
    (2,1,8,1,5):  "brbsrc17_el1",
    (2,1,8,1,6):  "brbtgt17_el1",
    (2,1,8,2,4):  "brbinf18_el1",
    (2,1,8,2,5):  "brbsrc18_el1",
    (2,1,8,2,6):  "brbtgt18_el1",
    (2,1,8,3,4):  "brbinf19_el1",
    (2,1,8,3,5):  "brbsrc19_el1",
    (2,1,8,3,6):  "brbtgt19_el1",
    (2,1,8,4,4):  "brbinf20_el1",
    (2,1,8,4,5):  "brbsrc20_el1",
    (2,1,8,4,6):  "brbtgt20_el1",
    (2,1,8,5,4):  "brbinf21_el1",
    (2,1,8,5,5):  "brbsrc21_el1",
    (2,1,8,5,6):  "brbtgt21_el1",
    (2,1,8,6,4):  "brbinf22_el1",
    (2,1,8,6,5):  "brbsrc22_el1",
    (2,1,8,6,6):  "brbtgt22_el1",
    (2,1,8,7,4):  "brbinf23_el1",
    (2,1,8,7,5):  "brbsrc23_el1",
    (2,1,8,7,6):  "brbtgt23_el1",
    (2,1,8,8,4):  "brbinf24_el1",
    (2,1,8,8,5):  "brbsrc24_el1",
    (2,1,8,8,6):  "brbtgt24_el1",
    (2,1,8,9,4):  "brbinf25_el1",
    (2,1,8,9,5):  "brbsrc25_el1",
    (2,1,8,9,6):  "brbtgt25_el1",
    (2,1,8,10,4): "brbinf26_el1",
    (2,1,8,10,5): "brbsrc26_el1",
    (2,1,8,10,6): "brbtgt26_el1",
    (2,1,8,11,4): "brbinf27_el1",
    (2,1,8,11,5): "brbsrc27_el1",
    (2,1,8,11,6): "brbtgt27_el1",
    (2,1,8,12,4): "brbinf28_el1",
    (2,1,8,12,5): "brbsrc28_el1",
    (2,1,8,12,6): "brbtgt28_el1",
    (2,1,8,13,4): "brbinf29_el1",
    (2,1,8,13,5): "brbsrc29_el1",
    (2,1,8,13,6): "brbtgt29_el1",
    (2,1,8,14,4): "brbinf30_el1",
    (2,1,8,14,5): "brbsrc30_el1",
    (2,1,8,14,6): "brbtgt30_el1",
    (2,1,8,15,4): "brbinf31_el1",
    (2,1,8,15,5): "brbsrc31_el1",
    (2,1,8,15,6): "brbtgt31_el1",

    # =========================================================================
    # op0=3 — Non-debug system registers
    # =========================================================================

    # -------------------------------------------------------------------------
    # CRn=0 — ID registers (all RO; op0=3, op1=0 unless noted)
    # -------------------------------------------------------------------------

    # op1=0 — AArch64 core ID registers
    (3,0,0,0,0):  "midr_el1",
    (3,0,0,0,5):  "mpidr_el1",
    (3,0,0,0,6):  "revidr_el1",

    # AArch32 feature ID registers (op1=0, CRm=1..3)
    (3,0,0,1,0):  "id_pfr0_el1",
    (3,0,0,1,1):  "id_pfr1_el1",
    (3,0,0,1,2):  "id_dfr0_el1",
    (3,0,0,1,3):  "id_afr0_el1",
    (3,0,0,1,4):  "id_mmfr0_el1",
    (3,0,0,1,5):  "id_mmfr1_el1",
    (3,0,0,1,6):  "id_mmfr2_el1",
    (3,0,0,1,7):  "id_mmfr3_el1",
    (3,0,0,2,0):  "id_isar0_el1",
    (3,0,0,2,1):  "id_isar1_el1",
    (3,0,0,2,2):  "id_isar2_el1",
    (3,0,0,2,3):  "id_isar3_el1",
    (3,0,0,2,4):  "id_isar4_el1",
    (3,0,0,2,5):  "id_isar5_el1",
    (3,0,0,2,6):  "id_mmfr4_el1",
    (3,0,0,2,7):  "id_isar6_el1",
    (3,0,0,3,0):  "mvfr0_el1",
    (3,0,0,3,1):  "mvfr1_el1",
    (3,0,0,3,2):  "mvfr2_el1",
    (3,0,0,3,3):  "id_pfr2_el1",
    (3,0,0,3,4):  "id_dfr1_el1",
    (3,0,0,3,6):  "id_mmfr5_el1",

    # AArch64 feature ID registers (op1=0, CRm=4..7)
    (3,0,0,4,0):  "id_aa64pfr0_el1",
    (3,0,0,4,1):  "id_aa64pfr1_el1",
    (3,0,0,4,2):  "id_aa64pfr2_el1",
    (3,0,0,4,4):  "id_aa64zfr0_el1",
    (3,0,0,4,5):  "id_aa64smfr0_el1",
    (3,0,0,5,0):  "id_aa64dfr0_el1",
    (3,0,0,5,1):  "id_aa64dfr1_el1",
    (3,0,0,5,2):  "id_aa64dfr2_el1",
    (3,0,0,5,4):  "id_aa64afr0_el1",
    (3,0,0,5,5):  "id_aa64afr1_el1",
    (3,0,0,6,0):  "id_aa64isar0_el1",
    (3,0,0,6,1):  "id_aa64isar1_el1",
    (3,0,0,6,2):  "id_aa64isar2_el1",
    (3,0,0,6,3):  "id_aa64isar3_el1",
    (3,0,0,7,0):  "id_aa64mmfr0_el1",
    (3,0,0,7,1):  "id_aa64mmfr1_el1",
    (3,0,0,7,2):  "id_aa64mmfr2_el1",
    (3,0,0,7,3):  "id_aa64mmfr3_el1",
    (3,0,0,7,4):  "id_aa64mmfr4_el1",

    # op1=1 — Cache level ID (EL1)
    (3,1,0,0,0):  "ccsidr_el1",
    (3,1,0,0,2):  "ccsidr2_el1",
    (3,1,0,0,1):  "clidr_el1",
    (3,1,0,0,4):  "gmid_el1",
    (3,1,0,0,7):  "aidr_el1",

    # op1=2 — Cache size selection
    (3,2,0,0,0):  "csselr_el1",

    # op1=3 — EL0 ID registers
    (3,3,0,0,1):  "ctr_el0",
    (3,3,0,0,7):  "dczid_el0",

    # op1=4 — EL2 virtual ID
    (3,4,0,0,0):  "vpidr_el2",
    (3,4,0,0,5):  "vmpidr_el2",

    # -------------------------------------------------------------------------
    # CRn=1 — System control registers
    # -------------------------------------------------------------------------

    # EL1 system control
    (3,0,1,0,0):  "sctlr_el1",
    (3,0,1,0,1):  "actlr_el1",
    (3,0,1,0,2):  "cpacr_el1",
    (3,0,1,0,3):  "sctlr2_el1",
    (3,0,1,0,5):  "rgsr_el1",
    (3,0,1,0,6):  "gcr_el1",
    (3,0,1,2,0):  "zcr_el1",
    (3,0,1,2,4):  "trfcr_el1",
    (3,0,1,2,6):  "smcr_el1",
    (3,0,1,2,7):  "smpri_el1",

    # EL2 system control
    (3,4,1,0,0):  "sctlr_el2",
    (3,4,1,0,1):  "actlr_el2",
    (3,4,1,0,2):  "cpacr_el2",
    (3,4,1,0,3):  "sctlr2_el2",
    (3,4,1,1,0):  "hcr_el2",
    (3,4,1,1,1):  "mdcr_el2",
    (3,4,1,1,2):  "cptr_el2",
    (3,4,1,1,3):  "hstr_el2",
    (3,4,1,1,4):  "hfgrtr_el2",
    (3,4,1,1,5):  "hfgwtr_el2",
    (3,4,1,1,6):  "hfgitr_el2",
    (3,4,1,1,7):  "hacr_el2",
    (3,4,1,2,0):  "zcr_el2",
    (3,4,1,2,4):  "trfcr_el2",
    (3,4,1,2,5):  "smprimap_el2",
    (3,4,1,2,6):  "smcr_el2",

    # EL1 viewed from EL2 (op1=5)
    (3,5,1,0,0):  "sctlr_el12",
    (3,5,1,2,0):  "zcr_el12",
    (3,5,1,2,4):  "trfcr_el12",
    (3,5,1,2,6):  "smcr_el12",

    # EL3 system control
    (3,6,1,0,0):  "sctlr_el3",
    (3,6,1,0,1):  "actlr_el3",
    (3,6,1,0,2):  "cptr_el3",
    (3,6,1,0,3):  "sctlr2_el3",
    (3,6,1,1,0):  "scr_el3",
    (3,6,1,1,1):  "sder32_el3",
    (3,6,1,2,0):  "zcr_el3",
    (3,6,1,2,6):  "smcr_el3",
    (3,6,1,3,1):  "mdcr_el3",

    # -------------------------------------------------------------------------
    # CRn=2 — Translation table base / TCR / pointer auth keys / GCS / RNDR
    # -------------------------------------------------------------------------

    # EL1 translation
    (3,0,2,0,0):  "ttbr0_el1",
    (3,0,2,0,1):  "ttbr1_el1",
    (3,0,2,0,2):  "tcr_el1",
    (3,0,2,0,3):  "tcr2_el1",

    # Pointer authentication keys (EL1, FEAT_PAuth)
    (3,0,2,1,0):  "apiakeylo_el1",
    (3,0,2,1,1):  "apiakeyhi_el1",
    (3,0,2,1,2):  "apibkeylo_el1",
    (3,0,2,1,3):  "apibkeyhi_el1",
    (3,0,2,2,0):  "apdakeylo_el1",
    (3,0,2,2,1):  "apdakeyhi_el1",
    (3,0,2,2,2):  "apdbkeylo_el1",
    (3,0,2,2,3):  "apdbkeyhi_el1",
    (3,0,2,3,0):  "apgakeylo_el1",
    (3,0,2,3,1):  "apgakeyhi_el1",

    # GCS — Guarded Control Stack (FEAT_GCS, EL1)
    (3,0,2,5,0):  "gcscr_el1",
    (3,0,2,5,1):  "gcspr_el1",
    (3,0,2,5,3):  "gcscre0_el1",

    # Random number (FEAT_RNG)
    (3,3,2,4,0):  "rndr",
    (3,3,2,4,1):  "rndrrs",

    # GCS — EL0
    (3,3,2,5,0):  "gcscr_el0",
    (3,3,2,5,1):  "gcspr_el0",

    # EL2 translation
    (3,4,2,0,0):  "ttbr0_el2",
    (3,4,2,0,1):  "ttbr1_el2",
    (3,4,2,0,2):  "tcr_el2",
    (3,4,2,0,3):  "tcr2_el2",
    (3,4,2,1,0):  "vttbr_el2",
    (3,4,2,1,2):  "vtcr_el2",
    (3,4,2,2,0):  "vncr_el2",
    (3,4,2,6,0):  "vsttbr_el2",
    (3,4,2,6,2):  "vstcr_el2",

    # GCS — EL2
    (3,4,2,5,0):  "gcscr_el2",
    (3,4,2,5,1):  "gcspr_el2",

    # EL1 from EL2 (op1=5)
    (3,5,2,0,0):  "ttbr0_el12",
    (3,5,2,0,1):  "ttbr1_el12",
    (3,5,2,0,2):  "tcr_el12",
    (3,5,2,0,3):  "tcr2_el12",
    (3,5,2,5,0):  "gcscr_el12",
    (3,5,2,5,1):  "gcspr_el12",

    # EL3 translation
    (3,6,2,0,0):  "ttbr0_el3",
    (3,6,2,0,2):  "tcr_el3",
    (3,6,2,5,0):  "gcscr_el3",
    (3,6,2,5,1):  "gcspr_el3",

    # -------------------------------------------------------------------------
    # CRn=3 — Hypervisor fine-grained traps (FEAT_FGT)
    # -------------------------------------------------------------------------

    (3,4,3,0,0):  "dacr32_el2",
    (3,4,3,1,0):  "hdfgrtr2_el2",
    (3,4,3,1,1):  "hdfgwtr2_el2",
    (3,4,3,1,2):  "hfgrtr2_el2",
    (3,4,3,1,3):  "hfgwtr2_el2",
    (3,4,3,1,4):  "hdfgrtr_el2",
    (3,4,3,1,5):  "hdfgwtr_el2",
    (3,4,3,1,6):  "hafgrtr_el2",
    (3,4,3,1,7):  "hfgitr2_el2",

    # -------------------------------------------------------------------------
    # CRn=4 — PSTATE / exception link / floating-point state
    # -------------------------------------------------------------------------

    # EL1 exception link and stack pointer
    (3,0,4,0,0):  "spsr_el1",
    (3,0,4,0,1):  "elr_el1",
    (3,0,4,1,0):  "sp_el0",
    (3,0,4,2,0):  "spsel",
    (3,0,4,2,2):  "currentel",
    (3,0,4,2,3):  "pan",
    (3,0,4,2,4):  "uao",
    (3,0,4,6,0):  "icc_pmr_el1",

    # EL0 PSTATE and FP state
    (3,3,4,2,0):  "nzcv",
    (3,3,4,2,1):  "daif",
    (3,3,4,2,6):  "ssbs",
    (3,3,4,2,7):  "tco",
    (3,3,4,4,0):  "fpcr",
    (3,3,4,4,1):  "fpsr",
    (3,3,4,5,0):  "dspsr_el0",
    (3,3,4,5,1):  "dlr_el0",

    # EL2 exception link
    (3,4,4,0,0):  "spsr_el2",
    (3,4,4,0,1):  "elr_el2",
    (3,4,4,1,0):  "sp_el1",
    (3,4,4,3,0):  "spsr_irq",
    (3,4,4,3,1):  "spsr_abt",
    (3,4,4,3,2):  "spsr_und",
    (3,4,4,3,3):  "spsr_fiq",

    # EL1 from EL2 (op1=5)
    (3,5,4,0,0):  "spsr_el12",
    (3,5,4,0,1):  "elr_el12",

    # EL3 exception link
    (3,6,4,0,0):  "spsr_el3",
    (3,6,4,0,1):  "elr_el3",
    (3,6,4,1,0):  "sp_el2",

    # -------------------------------------------------------------------------
    # CRn=5 — Fault status / exception syndrome / RAS
    # -------------------------------------------------------------------------

    # EL1
    (3,0,5,1,0):  "afsr0_el1",
    (3,0,5,1,1):  "afsr1_el1",
    (3,0,5,2,0):  "esr_el1",
    (3,0,5,3,0):  "erridr_el1",
    (3,0,5,3,1):  "errselr_el1",
    (3,0,5,4,0):  "erxfr_el1",
    (3,0,5,4,1):  "erxctlr_el1",
    (3,0,5,4,2):  "erxstatus_el1",
    (3,0,5,4,3):  "erxaddr_el1",
    (3,0,5,4,4):  "erxpfgf_el1",
    (3,0,5,4,5):  "erxpfgctl_el1",
    (3,0,5,4,6):  "erxpfgcdn_el1",
    (3,0,5,5,0):  "erxmisc0_el1",
    (3,0,5,5,1):  "erxmisc1_el1",
    (3,0,5,5,2):  "erxmisc2_el1",
    (3,0,5,5,3):  "erxmisc3_el1",
    (3,0,5,6,0):  "tfsr_el1",
    (3,0,5,6,1):  "tfsre0_el1",

    # EL2
    (3,4,5,0,1):  "ifsr32_el2",
    (3,4,5,1,0):  "afsr0_el2",
    (3,4,5,1,1):  "afsr1_el2",
    (3,4,5,2,0):  "esr_el2",
    (3,4,5,2,3):  "vsesr_el2",
    (3,4,5,3,0):  "fpexc32_el2",
    (3,4,5,6,0):  "tfsr_el2",

    # EL1 from EL2 (op1=5)
    (3,5,5,1,0):  "afsr0_el12",
    (3,5,5,1,1):  "afsr1_el12",
    (3,5,5,2,0):  "esr_el12",
    (3,5,5,6,0):  "tfsr_el12",

    # EL3
    (3,6,5,1,0):  "afsr0_el3",
    (3,6,5,1,1):  "afsr1_el3",
    (3,6,5,2,0):  "esr_el3",
    (3,6,5,6,0):  "tfsr_el3",

    # -------------------------------------------------------------------------
    # CRn=6 — Fault address
    # -------------------------------------------------------------------------

    (3,0,6,0,0):  "far_el1",
    (3,4,6,0,0):  "far_el2",
    (3,4,6,0,4):  "hpfar_el2",
    (3,5,6,0,0):  "far_el12",
    (3,6,6,0,0):  "far_el3",

    # -------------------------------------------------------------------------
    # CRn=7 — Cache maintenance / address translation / PAR
    # -------------------------------------------------------------------------

    (3,0,7,4,0):  "par_el1",

    # -------------------------------------------------------------------------
    # CRn=9 — PMU, SPE (FEAT_SPE), and TRBE (FEAT_TRBE)
    # -------------------------------------------------------------------------

    # SPE sampling configuration (EL1)
    (3,0,9,9,0):  "pmscr_el1",
    (3,0,9,9,2):  "pmsicr_el1",
    (3,0,9,9,3):  "pmsirr_el1",
    (3,0,9,9,4):  "pmsfcr_el1",
    (3,0,9,9,5):  "pmsevfr_el1",
    (3,0,9,9,6):  "pmslatfr_el1",
    (3,0,9,9,7):  "pmsidr_el1",

    # SPE buffer control (EL1)
    (3,0,9,10,0): "pmblimitr_el1",
    (3,0,9,10,1): "pmbptr_el1",
    (3,0,9,10,3): "pmbsr_el1",
    (3,0,9,10,7): "pmbidr_el1",

    # TRBE buffer control (EL1)
    (3,0,9,11,0): "trblimitr_el1",
    (3,0,9,11,1): "trbptr_el1",
    (3,0,9,11,2): "trbbaser_el1",
    (3,0,9,11,3): "trbsr_el1",
    (3,0,9,11,4): "trbmar_el1",
    (3,0,9,11,6): "trbtrg_el1",
    (3,0,9,11,7): "trbidr_el1",

    # PMU interrupt enable (EL1)
    (3,0,9,14,1): "pmintenset_el1",
    (3,0,9,14,2): "pmintenclr_el1",

    # SPE (EL2 and EL12)
    (3,4,9,9,0):  "pmscr_el2",
    (3,5,9,9,0):  "pmscr_el12",

    # PMU core counters (EL0)
    (3,3,9,12,0): "pmcr_el0",
    (3,3,9,12,1): "pmcntenset_el0",
    (3,3,9,12,2): "pmcntenclr_el0",
    (3,3,9,12,3): "pmovsclr_el0",
    (3,3,9,12,4): "pmswinc_el0",
    (3,3,9,12,5): "pmselr_el0",
    (3,3,9,12,6): "pmceid0_el0",
    (3,3,9,12,7): "pmceid1_el0",
    (3,3,9,13,0): "pmccntr_el0",
    (3,3,9,13,1): "pmxevtyper_el0",
    (3,3,9,13,2): "pmxevcntr_el0",
    (3,3,9,14,0): "pmuserenr_el0",
    (3,3,9,14,3): "pmovsset_el0",

    # PMU event counters PMEVCNTR0-30_EL0 (CRm=8..11, op2=0..7)
    (3,3,14,8,0):  "pmevcntr0_el0",
    (3,3,14,8,1):  "pmevcntr1_el0",
    (3,3,14,8,2):  "pmevcntr2_el0",
    (3,3,14,8,3):  "pmevcntr3_el0",
    (3,3,14,8,4):  "pmevcntr4_el0",
    (3,3,14,8,5):  "pmevcntr5_el0",
    (3,3,14,8,6):  "pmevcntr6_el0",
    (3,3,14,8,7):  "pmevcntr7_el0",
    (3,3,14,9,0):  "pmevcntr8_el0",
    (3,3,14,9,1):  "pmevcntr9_el0",
    (3,3,14,9,2):  "pmevcntr10_el0",
    (3,3,14,9,3):  "pmevcntr11_el0",
    (3,3,14,9,4):  "pmevcntr12_el0",
    (3,3,14,9,5):  "pmevcntr13_el0",
    (3,3,14,9,6):  "pmevcntr14_el0",
    (3,3,14,9,7):  "pmevcntr15_el0",
    (3,3,14,10,0): "pmevcntr16_el0",
    (3,3,14,10,1): "pmevcntr17_el0",
    (3,3,14,10,2): "pmevcntr18_el0",
    (3,3,14,10,3): "pmevcntr19_el0",
    (3,3,14,10,4): "pmevcntr20_el0",
    (3,3,14,10,5): "pmevcntr21_el0",
    (3,3,14,10,6): "pmevcntr22_el0",
    (3,3,14,10,7): "pmevcntr23_el0",
    (3,3,14,11,0): "pmevcntr24_el0",
    (3,3,14,11,1): "pmevcntr25_el0",
    (3,3,14,11,2): "pmevcntr26_el0",
    (3,3,14,11,3): "pmevcntr27_el0",
    (3,3,14,11,4): "pmevcntr28_el0",
    (3,3,14,11,5): "pmevcntr29_el0",
    (3,3,14,11,6): "pmevcntr30_el0",

    # PMU event type registers PMEVTYPER0-30_EL0 (CRm=12..15, op2=0..6/7)
    (3,3,14,12,0): "pmevtyper0_el0",
    (3,3,14,12,1): "pmevtyper1_el0",
    (3,3,14,12,2): "pmevtyper2_el0",
    (3,3,14,12,3): "pmevtyper3_el0",
    (3,3,14,12,4): "pmevtyper4_el0",
    (3,3,14,12,5): "pmevtyper5_el0",
    (3,3,14,12,6): "pmevtyper6_el0",
    (3,3,14,12,7): "pmevtyper7_el0",
    (3,3,14,13,0): "pmevtyper8_el0",
    (3,3,14,13,1): "pmevtyper9_el0",
    (3,3,14,13,2): "pmevtyper10_el0",
    (3,3,14,13,3): "pmevtyper11_el0",
    (3,3,14,13,4): "pmevtyper12_el0",
    (3,3,14,13,5): "pmevtyper13_el0",
    (3,3,14,13,6): "pmevtyper14_el0",
    (3,3,14,13,7): "pmevtyper15_el0",
    (3,3,14,14,0): "pmevtyper16_el0",
    (3,3,14,14,1): "pmevtyper17_el0",
    (3,3,14,14,2): "pmevtyper18_el0",
    (3,3,14,14,3): "pmevtyper19_el0",
    (3,3,14,14,4): "pmevtyper20_el0",
    (3,3,14,14,5): "pmevtyper21_el0",
    (3,3,14,14,6): "pmevtyper22_el0",
    (3,3,14,14,7): "pmevtyper23_el0",
    (3,3,14,15,0): "pmevtyper24_el0",
    (3,3,14,15,1): "pmevtyper25_el0",
    (3,3,14,15,2): "pmevtyper26_el0",
    (3,3,14,15,3): "pmevtyper27_el0",
    (3,3,14,15,4): "pmevtyper28_el0",
    (3,3,14,15,5): "pmevtyper29_el0",
    (3,3,14,15,6): "pmevtyper30_el0",
    (3,3,14,15,7): "pmccfiltr_el0",

    # -------------------------------------------------------------------------
    # CRn=10 — Memory attribute / LOR / MPAM / permission overlay
    # -------------------------------------------------------------------------

    # EL1 memory attributes
    (3,0,10,2,0):  "mair_el1",
    (3,0,10,2,2):  "pir_el1",
    (3,0,10,2,3):  "pire0_el1",
    (3,0,10,2,4):  "por_el1",
    (3,0,10,2,5):  "s2por_el1",
    (3,0,10,3,0):  "amair_el1",
    (3,0,10,3,1):  "amair2_el1",

    # LOR registers (FEAT_LOR)
    (3,0,10,4,0):  "lorsa_el1",
    (3,0,10,4,1):  "lorea_el1",
    (3,0,10,4,2):  "lorn_el1",
    (3,0,10,4,3):  "lorc_el1",
    (3,0,10,4,4):  "mpamidr_el1",
    (3,0,10,4,7):  "lorid_el1",

    # MPAM registers (FEAT_MPAM, EL1)
    (3,0,10,5,0):  "mpam1_el1",
    (3,0,10,5,1):  "mpam0_el1",

    # EL0 permission overlay
    (3,3,10,2,0):  "mair_el0",
    (3,3,10,2,4):  "por_el0",

    # EL2 memory attributes and MPAM
    (3,4,10,2,0):  "mair_el2",
    (3,4,10,2,4):  "por_el2",
    (3,4,10,3,0):  "amair_el2",
    (3,4,10,4,0):  "mpamhcr_el2",
    (3,4,10,4,1):  "mpamvpmv_el2",
    (3,4,10,4,2):  "mpam2_el2",
    (3,4,10,5,0):  "mpam2_el2",
    (3,4,10,6,0):  "mpamvpm0_el2",
    (3,4,10,6,1):  "mpamvpm1_el2",
    (3,4,10,6,2):  "mpamvpm2_el2",
    (3,4,10,6,3):  "mpamvpm3_el2",
    (3,4,10,6,4):  "mpamvpm4_el2",
    (3,4,10,6,5):  "mpamvpm5_el2",
    (3,4,10,6,6):  "mpamvpm6_el2",
    (3,4,10,6,7):  "mpamvpm7_el2",

    # EL1 from EL2 (op1=5)
    (3,5,10,2,0):  "mair_el12",
    (3,5,10,2,4):  "por_el12",
    (3,5,10,3,0):  "amair_el12",
    (3,5,10,5,0):  "mpam1_el12",

    # EL3 memory attributes and MPAM
    (3,6,10,2,0):  "mair_el3",
    (3,6,10,2,4):  "por_el3",
    (3,6,10,3,0):  "amair_el3",
    (3,6,10,5,0):  "mpam3_el3",

    # -------------------------------------------------------------------------
    # CRn=12 — Vector base address / interrupt controller
    # -------------------------------------------------------------------------

    # EL1 VBAR / ISR / GIC
    (3,0,12,0,0):  "vbar_el1",
    (3,0,12,0,1):  "rvbar_el1",
    (3,0,12,0,2):  "rmr_el1",
    (3,0,12,1,0):  "isr_el1",
    (3,0,12,1,1):  "disr_el1",

    # GICv3 EL1 RO
    (3,0,12,8,0):  "icc_iar0_el1",
    (3,0,12,8,2):  "icc_hppir0_el1",
    (3,0,12,12,0): "icc_iar1_el1",
    (3,0,12,12,2): "icc_hppir1_el1",
    (3,0,12,11,3): "icc_rpr_el1",

    # GICv3 EL1 WO
    (3,0,12,8,1):  "icc_eoir0_el1",
    (3,0,12,12,1): "icc_eoir1_el1",
    (3,0,12,11,1): "icc_dir_el1",
    (3,0,12,11,5): "icc_sgi1r_el1",
    (3,0,12,11,6): "icc_asgi1r_el1",
    (3,0,12,11,7): "icc_sgi0r_el1",

    # GICv3 EL1 RW
    (3,0,12,8,3):  "icc_bpr0_el1",
    (3,0,12,8,4):  "icc_ap0r0_el1",
    (3,0,12,8,5):  "icc_ap0r1_el1",
    (3,0,12,8,6):  "icc_ap0r2_el1",
    (3,0,12,8,7):  "icc_ap0r3_el1",
    (3,0,12,9,0):  "icc_ap1r0_el1",
    (3,0,12,9,1):  "icc_ap1r1_el1",
    (3,0,12,9,2):  "icc_ap1r2_el1",
    (3,0,12,9,3):  "icc_ap1r3_el1",
    (3,0,12,12,3): "icc_bpr1_el1",
    (3,0,12,12,4): "icc_ctlr_el1",
    (3,0,12,12,5): "icc_sre_el1",
    (3,0,12,12,6): "icc_igrpen0_el1",
    (3,0,12,12,7): "icc_igrpen1_el1",
    (3,0,12,13,0): "icc_seien_el1",

    # EL2 VBAR / ISR / GIC
    (3,4,12,0,0):  "vbar_el2",
    (3,4,12,0,1):  "rvbar_el2",
    (3,4,12,0,2):  "rmr_el2",
    (3,4,12,1,1):  "vdisr_el2",
    (3,4,12,8,0):  "ich_ap0r0_el2",
    (3,4,12,8,1):  "ich_ap0r1_el2",
    (3,4,12,8,2):  "ich_ap0r2_el2",
    (3,4,12,8,3):  "ich_ap0r3_el2",
    (3,4,12,9,0):  "ich_ap1r0_el2",
    (3,4,12,9,1):  "ich_ap1r1_el2",
    (3,4,12,9,2):  "ich_ap1r2_el2",
    (3,4,12,9,3):  "ich_ap1r3_el2",
    (3,4,12,9,4):  "ich_vseir_el2",
    (3,4,12,9,5):  "icc_sre_el2",
    (3,4,12,11,0): "ich_hcr_el2",
    (3,4,12,11,1): "ich_vtr_el2",
    (3,4,12,11,2): "ich_misr_el2",
    (3,4,12,11,3): "ich_eisr_el2",
    (3,4,12,11,5): "ich_elrsr_el2",
    (3,4,12,11,7): "ich_vmcr_el2",
    (3,4,12,12,0): "ich_lr0_el2",
    (3,4,12,12,1): "ich_lr1_el2",
    (3,4,12,12,2): "ich_lr2_el2",
    (3,4,12,12,3): "ich_lr3_el2",
    (3,4,12,12,4): "ich_lr4_el2",
    (3,4,12,12,5): "ich_lr5_el2",
    (3,4,12,12,6): "ich_lr6_el2",
    (3,4,12,12,7): "ich_lr7_el2",
    (3,4,12,13,0): "ich_lr8_el2",
    (3,4,12,13,1): "ich_lr9_el2",
    (3,4,12,13,2): "ich_lr10_el2",
    (3,4,12,13,3): "ich_lr11_el2",
    (3,4,12,13,4): "ich_lr12_el2",
    (3,4,12,13,5): "ich_lr13_el2",
    (3,4,12,13,6): "ich_lr14_el2",
    (3,4,12,13,7): "ich_lr15_el2",

    # EL3 VBAR / GIC
    (3,6,12,0,0):  "vbar_el3",
    (3,6,12,0,1):  "rvbar_el3",
    (3,6,12,0,2):  "rmr_el3",
    (3,6,12,12,4): "icc_ctlr_el3",
    (3,6,12,12,5): "icc_sre_el3",
    (3,6,12,12,7): "icc_igrpen1_el3",

    # -------------------------------------------------------------------------
    # CRn=13 — Thread/context ID / activity monitors
    # -------------------------------------------------------------------------

    # EL1 context/TPIDR
    (3,0,13,0,1):  "contextidr_el1",
    (3,0,13,0,4):  "tpidr_el1",
    (3,0,13,0,7):  "scxtnum_el1",

    # EL0 thread-pointer and SCXTNUM
    (3,3,13,0,2):  "tpidr_el0",
    (3,3,13,0,3):  "tpidrro_el0",
    (3,3,13,0,5):  "tpidr2_el0",
    (3,3,13,0,7):  "scxtnum_el0",

    # EL2 thread/context
    (3,4,13,0,1):  "contextidr_el2",
    (3,4,13,0,2):  "tpidr_el2",
    (3,4,13,0,7):  "scxtnum_el2",

    # EL1 from EL2 (op1=5)
    (3,5,13,0,1):  "contextidr_el12",
    (3,5,13,0,7):  "scxtnum_el12",

    # EL3
    (3,6,13,0,2):  "tpidr_el3",
    (3,6,13,0,7):  "scxtnum_el3",

    # Activity monitors (FEAT_AMUv1)
    (3,0,13,2,0):  "amcr_el0",
    (3,0,13,3,0):  "amcntenclr0_el1",
    (3,0,13,3,2):  "amcntenset0_el1",
    (3,0,13,3,4):  "amcntenclr1_el1",
    (3,0,13,3,6):  "amcntenset1_el1",
    (3,3,13,2,1):  "amcfgr_el0",
    (3,3,13,2,2):  "amcgcr_el0",
    (3,3,13,2,3):  "amuserenr_el0",
    (3,3,13,2,4):  "amcntenclr0_el0",
    (3,3,13,2,5):  "amcntenset0_el0",
    (3,3,13,2,6):  "amcntenclr1_el0",
    (3,3,13,2,7):  "amcntenset1_el0",
    # Activity monitor event/type counters (group 0 fixed)
    (3,3,13,4,0):  "amevcntr00_el0",
    (3,3,13,4,1):  "amevcntr01_el0",
    (3,3,13,4,2):  "amevcntr02_el0",
    (3,3,13,4,3):  "amevcntr03_el0",
    (3,3,13,6,0):  "amevtyper00_el0",
    (3,3,13,6,1):  "amevtyper01_el0",
    (3,3,13,6,2):  "amevtyper02_el0",
    (3,3,13,6,3):  "amevtyper03_el0",
    # Activity monitor event counters (group 1 aux, 0-15)
    (3,3,13,5,0):  "amevcntr10_el0",
    (3,3,13,5,1):  "amevcntr11_el0",
    (3,3,13,5,2):  "amevcntr12_el0",
    (3,3,13,5,3):  "amevcntr13_el0",
    (3,3,13,5,4):  "amevcntr14_el0",
    (3,3,13,5,5):  "amevcntr15_el0",
    (3,3,13,5,6):  "amevcntr16_el0",
    (3,3,13,5,7):  "amevcntr17_el0",
    (3,3,13,7,0):  "amevtyper10_el0",
    (3,3,13,7,1):  "amevtyper11_el0",
    (3,3,13,7,2):  "amevtyper12_el0",
    (3,3,13,7,3):  "amevtyper13_el0",
    (3,3,13,7,4):  "amevtyper14_el0",
    (3,3,13,7,5):  "amevtyper15_el0",
    (3,3,13,7,6):  "amevtyper16_el0",
    (3,3,13,7,7):  "amevtyper17_el0",

    # -------------------------------------------------------------------------
    # CRn=14 — Counter-timer
    # -------------------------------------------------------------------------

    # EL0 physical timer
    (3,3,14,0,0):  "cntfrq_el0",
    (3,3,14,0,1):  "cntpct_el0",
    (3,3,14,0,2):  "cntvct_el0",
    (3,3,14,0,5):  "cntpctss_el0",
    (3,3,14,0,6):  "cntvctss_el0",

    # EL1 timer control
    (3,0,14,1,0):  "cntkctl_el1",

    # EL2 timer
    (3,4,14,0,3):  "cntvoff_el2",
    (3,4,14,0,4):  "cntscale_el2",
    (3,4,14,0,5):  "cntiscale_el2",
    (3,4,14,0,6):  "cntpoff_el2",
    (3,4,14,0,7):  "cntvfrq_el2",
    (3,4,14,1,0):  "cnthctl_el2",

    # EL1 from EL2 (op1=5)
    (3,5,14,1,0):  "cntkctl_el12",

    # EL0 physical timer compare/control
    (3,3,14,2,0):  "cntp_tval_el0",
    (3,3,14,2,1):  "cntp_ctl_el0",
    (3,3,14,2,2):  "cntp_cval_el0",

    # EL0 virtual timer compare/control
    (3,3,14,3,0):  "cntv_tval_el0",
    (3,3,14,3,1):  "cntv_ctl_el0",
    (3,3,14,3,2):  "cntv_cval_el0",

    # EL2 hypervisor physical timer
    (3,4,14,2,0):  "cnthp_tval_el2",
    (3,4,14,2,1):  "cnthp_ctl_el2",
    (3,4,14,2,2):  "cnthp_cval_el2",

    # EL2 hypervisor virtual timer
    (3,4,14,3,0):  "cnthv_tval_el2",
    (3,4,14,3,1):  "cnthv_ctl_el2",
    (3,4,14,3,2):  "cnthv_cval_el2",

    # EL2 self-hosted timers (FEAT_ECV)
    (3,4,14,4,0):  "cnthvs_tval_el2",
    (3,4,14,4,1):  "cnthvs_ctl_el2",
    (3,4,14,4,2):  "cnthvs_cval_el2",
    (3,4,14,5,0):  "cnthps_tval_el2",
    (3,4,14,5,1):  "cnthps_ctl_el2",
    (3,4,14,5,2):  "cnthps_cval_el2",

    # EL3 secure physical timer (op1=7)
    (3,7,14,2,0):  "cntps_tval_el1",
    (3,7,14,2,1):  "cntps_ctl_el1",
    (3,7,14,2,2):  "cntps_cval_el1",

    # EL0 timers as seen from EL2 (op1=5)
    (3,5,14,2,0):  "cntp_tval_el02",
    (3,5,14,2,1):  "cntp_ctl_el02",
    (3,5,14,2,2):  "cntp_cval_el02",
    (3,5,14,3,0):  "cntv_tval_el02",
    (3,5,14,3,1):  "cntv_ctl_el02",
    (3,5,14,3,2):  "cntv_cval_el02",

    # Implementation defined
    (3,7,15,2,0):  "cpm_ioacc_ctl_el3",
}


def sysreg_name(op0: int, op1: int, crn: int, crm: int, op2: int) -> str:
    """Return the register name for the given (op0, op1, CRn, CRm, op2) encoding,
    or a generic S<op0>_<op1>_C<CRn>_C<CRm>_<op2> string if not known."""
    name = SYSREG_NAMES.get((op0, op1, crn, crm, op2))
    if name:
        return name
    return f"s{op0}_{op1}_c{crn}_c{crm}_{op2}"
